//! This file contains the semantic validation logic for symbols.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Const_Eval = @import("const_eval.zig");
const typecheck_AST = @import("typecheck.zig").typecheck_AST;
const errs_ = @import("../util/errors.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");
const typing_ = @import("typing.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const type_validate_ = @import("../types/type_validate.zig");
const walk_ = @import("../ast/walker.zig");

const Validate_Error_Enum = error{CompileError};

const Self: type = @This();

ctx: *Compiler_Context,

pub fn init(ctx: *Compiler_Context) Self {
    return Self{ .ctx = ctx };
}

pub fn validate(self: *Self, symbol: *Symbol) Validate_Error_Enum!void {
    // TODO: Bit long
    if (symbol.validation_state == .valid or symbol.validation_state == .validating) {
        return;
    }
    symbol.validation_state = .validating;
    symbol.init_validation_state = .validating;

    // std.debug.assert(symbol.init.* != .poison);
    // std.debug.print("validating type for: {s}\n", .{symbol.name});
    // symbol._type = try typecheck_AST(symbol._type, prelude_.type_type, compiler);

    _ = symbol.assert_symbol_valid();
    // symbol.expanded_type = symbol._type.expand_type(allocator);
    // std.debug.print("expanded type for: {s}: {?}\n", .{ symbol.name, symbol.expanded_type });
    const expected: ?*Type_AST = switch (symbol.kind) {
        .@"fn", .@"test" => symbol.type().rhs(),
        .type => null,
        else => symbol.type(),
    };
    if (expected) |expected_type| {
        try self.ctx.validate_type.validate(expected_type);
        if (self.ctx.validate_type.detect_cycle(expected_type)) {
            self.ctx.errors.add_error(errs_.Error{ .symbol_error = .{
                .problem = "cyclic type detected",
                .span = symbol.span(),
                .name = symbol.name,
            } });
            return error.CompileError;
        }
    }
    // std.debug.print("type for: {s}: {?}\n", .{ symbol.name, expected });
    // std.debug.print("validating init for: {s}: {?}\n", .{ symbol.name, expected });
    if (symbol.init_value()) |_init| {
        // might be null for parameters
        _ = self.ctx.typecheck.typecheck_AST(_init, expected) catch |e| switch (e) {
            error.CompileError => return error.CompileError,
            error.UnexpectedTypeType => {
                self.ctx.errors.add_error(errs_.Error{ .unexpected_type_type = .{ .expected = expected, .span = _init.token().span } });
                return error.CompileError;
            },
        };
        if (_init.* != .module) {
            try walk_.walk_ast(_init, Const_Eval.new(self.ctx));
        }
    } else if (symbol.kind == .type and symbol.init_typedef() != null) {
        try self.ctx.validate_type.validate(symbol.init_typedef().?);
        if (self.ctx.validate_type.detect_cycle(symbol.init_typedef().?)) {
            self.ctx.errors.add_error(errs_.Error{ .basic = .{
                .msg = "cyclic type detected",
                .span = symbol.span(),
            } });
            return error.CompileError;
        }
    }

    // std.debug.print("init for: {s}: {?}\n", .{ symbol.name, symbol.init_value });
    if (symbol.kind == .trait) {
        try self.validate_trait(symbol);
    } else if (symbol.init_value() != null and symbol.init_value().?.* == .poison) {
        symbol.validation_state = .invalid;
        symbol.init_validation_state = .invalid;
        return error.CompileError;
        // unreachable;
    }

    // Symbol's name must be capitalized iff its type is Type
    if (symbol.refers_to_type() or symbol.kind == .trait) {
        if (!is_capitalized(symbol.name)) {
            self.ctx.errors.add_error(errs_.Error{ .symbol_error = .{
                .problem = "must start with an uppercase letter",
                .span = symbol.span(),
                .name = symbol.name,
            } });
            return error.CompileError;
        }
    } else {
        if (is_capitalized(symbol.name)) {
            self.ctx.errors.add_error(errs_.Error{ .symbol_error = .{
                .problem = "must start with an lowercase letter",
                .span = symbol.span(),
                .name = symbol.name,
            } });
            return error.CompileError;
        }
    }

    if (symbol.storage == .@"extern") {
        if (symbol.storage.@"extern".c_name != null) {
            _ = self.ctx.typecheck.typecheck_AST(symbol.storage.@"extern".c_name.?, prelude_.string_type) catch return error.CompileError;
        } else {
            symbol.storage.@"extern".c_name = ast_.AST.create_string(Token.init_simple(symbol.name), symbol.name, self.ctx.allocator());
        }
    }
    _ = symbol.assert_init_valid();
}

fn type_is_type_type(ast: *ast_.AST) bool {
    if (ast.* == .function) {
        return type_is_type_type_atom(ast.rhs());
    } else {
        return type_is_type_type_atom(ast);
    }
}

fn type_is_type_type_atom(ast: *ast_.AST) bool {
    return ast.* == .identifier and std.mem.eql(u8, ast.token().data, "Type");
}

fn validate_trait(self: *Self, trait: *Symbol) Validate_Error_Enum!void {
    var names = std.StringArrayHashMap(*ast_.AST).init(self.ctx.allocator());
    defer names.deinit();

    for (trait.decl.?.trait.method_decls.items) |decl| {
        if (names.get(decl.method_decl.name.token().data)) |other| {
            self.ctx.errors.add_error(errs_.Error{ .duplicate = .{
                .span = decl.token().span,
                .identifier = decl.method_decl.name.token().data,
                .first = other.token().span,
            } });
            return error.CompileError;
        } else {
            names.put(decl.method_decl.name.token().data, decl) catch unreachable;
        }

        for (decl.method_decl._params.items) |param| {
            try self.ctx.validate_type.validate(param.binding.type);
        }
        try self.ctx.validate_type.validate(decl.method_decl.ret_type);
        try self.ctx.validate_type.validate(decl.method_decl.c_type.?);

        if (decl.method_decl.is_virtual) {
            if (decl.method_decl.c_type.?.refers_to_self()) {
                self.ctx.errors.add_error(errs_.Error{ .trait_virtual_refers_to_self = .{
                    .span = decl.token().span,
                    .method_name = decl.method_decl.name.token().data,
                    .trait_name = trait.name,
                } });
                return error.CompileError;
            }
            trait.decl.?.trait.num_virtual_methods += 1;
        }
    }
}

fn is_capitalized(name: []const u8) bool {
    var should_be_upper = true;
    for (name) |c| {
        if (should_be_upper and std.ascii.isLower(c)) {
            return false;
        }
        should_be_upper = c == '_';
    }
    return true;
}
