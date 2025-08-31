//! This file contains the semantic validation logic for symbols.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const validate_AST = @import("ast_validate.zig").validate_AST;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");
const typing_ = @import("typing.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

pub fn validate(symbol: *Symbol, compiler: *Compiler_Context) Validate_Error_Enum!void {
    // TODO: Bit long
    if (symbol.validation_state == .valid or symbol.validation_state == .validating) {
        return;
    }
    symbol.validation_state = .validating;
    symbol.init_validation_state = .validating;

    // std.debug.assert(symbol.init.* != .poison);
    // std.debug.print("validating type for: {s}\n", .{symbol.name});
    symbol._type = validate_AST(symbol._type, prelude_.type_type, compiler);
    // std.debug.print("type for: {s}: {}\n", .{ symbol.name, symbol._type });
    if (symbol._type.* != .poison) {
        _ = symbol.assert_symbol_valid();
        symbol.expanded_type = symbol._type.expand_type(compiler.allocator());
        // std.debug.print("expanded type for: {s}: {?}\n", .{ symbol.name, symbol.expanded_type });
        if (type_is_type_type(symbol.expanded_type.?)) {
            switch (symbol.kind) {
                .let, .mut => {
                    // let and mut cannot be Type typed
                    compiler.errors.add_error(errs_.Error{ .basic = .{
                        .span = symbol.span,
                        .msg = "non-constant variable with `Type` type",
                    } });
                    symbol.validation_state = .invalid;
                    symbol.init_validation_state = .invalid;
                    return error.CompileError;
                },
                // Allow these inits to be non-comptime, since they're interpreted at comptime anyway
                .@"fn", .@"comptime", .@"const", .@"test" => symbol.init_value.?.common().ok_for_comptime = true,
                else => {},
            }
        }
        const expected: ?*ast_.AST = if (symbol.kind == .@"fn" or symbol.kind == .@"comptime" or symbol.kind == .@"test") symbol._type.rhs() else symbol._type;
        // std.debug.print("validating init for: {s}\n", .{symbol.name});
        if (symbol.init_value) |init| {
            // might be null for parameters
            symbol.init_value = validate_AST(init, expected, compiler);
        }
        // std.debug.print("init for: {s}: {?}\n", .{ symbol.name, symbol.init });
        if (symbol.kind == .trait) {
            try validate_trait(symbol, compiler);
        } else if (symbol.init_value != null and symbol.init_value.?.* == .poison) {
            symbol.validation_state = .invalid;
            symbol.init_validation_state = .invalid;
            return error.CompileError;
            // unreachable;
        }
    } else {
        symbol.validation_state = .invalid;
        symbol.init_validation_state = .invalid;
        return error.CompileError;
    }

    // Symbol's name must be capitalized iff its type is Type
    if (symbol.expanded_type != null and !std.mem.eql(u8, symbol.name, "_") and symbol.kind != .trait and symbol.kind != .import_inner and symbol.name[0] != '$') {
        if (symbol.kind != .import and type_is_type_type(symbol.expanded_type.?) and !is_capitalized(symbol.name)) {
            compiler.errors.add_error(errs_.Error{ .symbol_error = .{
                .problem = "of type `Type` must start with an uppercase letter",
                .span = symbol.span,
                .name = symbol.name,
            } });
        } else if (!(symbol.kind != .import and type_is_type_type(symbol.expanded_type.?)) and is_capitalized(symbol.name) and symbol.kind != .template) {
            // TODO: Make it so that these rules apply to templates. I think we'll need to stamp first, of course. Are symbols re-validated when they're stamped? They probably should be
            compiler.errors.add_error(errs_.Error{ .symbol_error = .{
                .problem = "of type other than `Type` must start with a lowercase letter",
                .span = symbol.span,
                .name = symbol.name,
            } });
        }
    }
    if (symbol.kind == .@"extern") {
        if (symbol.kind.@"extern".c_name != null) {
            symbol.kind.@"extern".c_name = validate_AST(symbol.kind.@"extern".c_name.?, prelude_.string_type, compiler);
        } else {
            symbol.kind.@"extern".c_name = ast_.AST.create_string(Token.init_simple(symbol.name), symbol.name, compiler.allocator());
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

fn validate_trait(trait: *Symbol, compiler: *Compiler_Context) Validate_Error_Enum!void {
    var names = std.StringArrayHashMap(*ast_.AST).init(compiler.allocator());
    defer names.deinit();

    for (trait.decl.?.trait.method_decls.items) |decl| {
        if (names.get(decl.method_decl.name.token().data)) |other| {
            compiler.errors.add_error(errs_.Error{ .duplicate = .{
                .span = decl.token().span,
                .identifier = decl.method_decl.name.token().data,
                .first = other.token().span,
            } });
            return error.CompileError;
        } else {
            names.put(decl.method_decl.name.token().data, decl) catch unreachable;
        }

        for (decl.method_decl._params.items) |param| {
            param.decl.type = validate_AST(param.decl.type, prelude_.type_type, compiler);
        }
        decl.method_decl.ret_type = validate_AST(decl.method_decl.ret_type, prelude_.type_type, compiler);
        decl.method_decl.c_type = validate_AST(decl.method_decl.c_type.?, prelude_.type_type, compiler);

        if (decl.method_decl.is_virtual) {
            if (decl.method_decl.c_type.?.refers_to_self()) {
                compiler.errors.add_error(errs_.Error{ .trait_virtual_refers_to_self = .{
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
        if (should_be_upper and !std.ascii.isUpper(c) and c != '$') {
            return false;
        }
        should_be_upper = c == '_';
    }
    return true;
}
