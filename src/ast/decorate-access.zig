//! This file represents a struct for an AST walk, and is used to decorate access ASTs with symbols they refer to.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const core_ = @import("../hierarchy/core.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const primitives_ = @import("../hierarchy/prelude.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const token_ = @import("../lexer/token.zig");
const walk_ = @import("../ast/walker.zig");
const Type_AST = @import("../types/type.zig").Type_AST;

scope: *Scope,
errors: *errs_.Errors,
compiler: *Compiler_Context,

const Self = @This();

pub fn new(scope: *Scope, errors: *errs_.Errors, compiler: *Compiler_Context) Self {
    return Self{ .scope = scope, .errors = errors, .compiler = compiler };
}

pub fn prefix(self: Self, ast: *ast_.AST) walk_.Error!?Self {
    switch (ast.*) {
        else => return self,

        .access => {
            _ = try self.resolve_symbol_from_ast(ast);
            return null;
        },
    }
}

pub fn postfix(self: Self, ast: *ast_.AST) walk_.Error!void {
    switch (ast.*) {
        else => {},

        .call => {
            if (ast.lhs().* == .enum_value) {
                // Enum value
                ast.lhs().enum_value.init = ast.children().items[0];
                ast.* = ast.lhs().*;
            } else if (ast.lhs().refers_to_type()) {
                // Struct value construction
                const struct_type = Type_AST.from_ast(ast.lhs(), self.compiler.allocator());
                const struct_value = ast_.AST.create_struct_value(
                    ast.lhs().token(),
                    struct_type,
                    ast.children().*,
                    self.compiler.allocator(),
                );
                ast.* = struct_value.*;
            }
        },

        .index => {
            var child = ast.lhs();
            if ((child.* == .identifier or child.* == .access) and child.symbol() != null and child.symbol().?.decl.?.* == .fn_decl and child.symbol().?.decl.?.generic_params().items.len > 0) {
                var types = std.array_list.Managed(*Type_AST).init(self.compiler.allocator());
                for (ast.children().items) |arg| {
                    types.append(Type_AST.from_ast(arg, self.compiler.allocator())) catch unreachable;
                }
                ast.* = ast_.AST.create_generic_apply(ast.token(), ast.lhs(), types, self.compiler.allocator()).*;
            }
        },
    }
}

pub fn prefix_type(self: Self, _type: *Type_AST) walk_.Error!?Self {
    switch (_type.*) {
        else => return self,

        .access => {
            _ = try self.resolve_symbol_from_ast(_type.access.inner_access);
            return null;
        },
    }
}

/// Takes in an a qualified-name AST and returns the symbol that it refers to. This requires looking up modules and packages, and so the
/// compiler instance is required.
fn resolve_symbol_from_ast(self: Self, ast: *ast_.AST) walk_.Error!*Symbol {
    switch (ast.*) {
        .access => return self.resolve_symbol_from_access(ast),
        .identifier, .pattern_symbol => return self.resolve_symbol_from_identlike(ast),
        else => std.debug.panic("compiler error: fell through {f}", .{ast}),
    }
}

/// Takes in an access-ast and resolves the symbol it refers to
fn resolve_symbol_from_access(self: Self, access_ast: *ast_.AST) walk_.Error!*Symbol {
    const stripped_lhs = if (access_ast.lhs().* == .addr_of) access_ast.lhs().expr() else access_ast.lhs();
    const expanded_lhs = try self.resolve_symbol_from_ast(stripped_lhs);
    const symbol = try self.resolve_access_symbol(expanded_lhs, access_ast.rhs(), access_ast.scope().?);
    access_ast.set_symbol(symbol);
    return symbol;
}

/// Takes in a identifier-like AST (such as an identifier or a pattern symbol) and returns the symbol it refers to
fn resolve_symbol_from_identlike(self: Self, identlike_ast: *ast_.AST) *Symbol {
    return if (identlike_ast.symbol().?.kind == .import)
        self.resolve_symbol_from_import_identlike(identlike_ast)
    else
        identlike_ast.symbol().?;
}

/// Takes in an identlike AST that refers to an import symbol, and returns the module symbol that it imports
fn resolve_symbol_from_import_identlike(self: Self, identlike_ast: *ast_.AST) *Symbol {
    const this_module = identlike_ast.symbol().?.scope.module.?;
    const curr_package_path = this_module.get_package_abs_path();
    var module_path_name = std.array_list.Managed(u8).init(self.compiler.allocator());
    defer module_path_name.deinit();
    module_path_name.print("{s}.orng", .{identlike_ast.token().data}) catch unreachable;
    const package_build_paths = [_][]const u8{ curr_package_path, module_path_name.items };
    const other_module_dir = std.fs.path.join(self.compiler.allocator(), &package_build_paths) catch unreachable;

    if (std.mem.eql(u8, identlike_ast.symbol().?.kind.import.real_name, "core")) {
        return core_.core_symbol.?;
    }

    // TODO: If these are both non-null, report the ambiguity
    //       If these are both null, report that the module was not found

    const local_module_lookup = self.compiler.lookup_module(other_module_dir);
    const foreign_module_lookup = self.compiler.lookup_package_root_module(curr_package_path, identlike_ast.symbol().?.kind.import.real_name);

    // TODO: This doesn't work when we do:
    //   import module::member
    return (local_module_lookup orelse foreign_module_lookup) orelse {
        std.debug.panic("couldn't find module {s} or package {s}", .{ other_module_dir, identlike_ast.symbol().?.kind.import.real_name });
    };
}

/// Takes in container symbol (lhs) and field ast (rhs), and returns the symbol that `lhs::rhs` refers to.
fn resolve_access_symbol(self: Self, lhs: *Symbol, rhs: *ast_.AST, scope: *Scope) walk_.Error!*Symbol {
    switch (lhs.kind) {
        .module => return self.resolve_access_module(lhs, rhs),

        .import => return self.resolve_access_import(lhs, rhs, scope),

        .import_inner => return try self.resolve_access_symbol(try self.resolve_symbol_from_ast(lhs.init_value().?), rhs, scope),

        .type => return self.resolve_access_const(lhs, rhs, scope),

        else => {
            self.compiler.errors.add_error(errs_.Error{
                .member_not_in_module = .{
                    .span = rhs.token().span,
                    .identifier = rhs.token().data,
                    .name = "symbol",
                    .module_name = lhs.name,
                },
            });
            return error.CompileError;
        },
    }
}

/// Resolves a symbol access from a module
fn resolve_access_module(self: Self, module_symbol: *Symbol, rhs: *ast_.AST) walk_.Error!*Symbol {
    const module_lookup_res = module_symbol.init_value().?.scope().?.lookup(
        rhs.token().data,
        .{},
    );
    const rhs_decl = switch (module_lookup_res) {
        .found => module_lookup_res.found.decl.?,
        else => {
            self.compiler.errors.add_error(errs_.Error{
                .member_not_in_module = .{
                    .span = rhs.token().span,
                    .identifier = rhs.token().data,
                    .name = "module",
                    .module_name = module_symbol.name,
                },
            });
            return error.CompileError;
        },
    };
    return extract_symbol_from_decl(rhs_decl);
}

/// Resolves a symbol access on an import symbol
/// This is gauranteed to work, since the import-module symbol connection is setup by the compiler itself
fn resolve_access_import(self: Self, import_symbol: *Symbol, rhs: *ast_.AST, scope: *Scope) walk_.Error!*Symbol {
    const referant_symbol = import_symbol.scope.parent.?.lookup(import_symbol.kind.import.real_name, .{ .allow_modules = true }).found;
    return try self.resolve_access_symbol(referant_symbol, rhs, scope);
}

/// Resolves a symbol access on a constant symbol, likely a trait lookup
fn resolve_access_const(self: Self, const_symbol: *Symbol, rhs: *ast_.AST, scope: *Scope) walk_.Error!*Symbol {
    var test_ident = Type_AST.create_identifier(token_.init_simple(const_symbol.name), self.compiler.allocator());
    test_ident.set_symbol(const_symbol);
    const rhs_decl = scope.lookup_impl_member(test_ident, rhs.token().data, self.compiler) catch return error.CompileError;
    if (rhs_decl == null) {
        self.compiler.errors.add_error(errs_.Error{
            .type_not_impl_method = .{
                .span = rhs.token().span,
                .method_name = rhs.token().data,
                ._type = test_ident,
            },
        });
        return error.CompileError;
    } else {
        return extract_symbol_from_decl(rhs_decl.?);
    }
}

/// Extracts the symbol that a decl-like AST decls
fn extract_symbol_from_decl(decl: *ast_.AST) *Symbol {
    if (decl.* == .decl) {
        return decl.decl.name.symbol().?;
    } else if (decl.* == .method_decl or decl.* == .fn_decl or decl.* == .trait or decl.* == .struct_decl or decl.* == .enum_decl or decl.* == .type_alias) {
        return decl.symbol().?;
    } else if (decl.* == .binding) {
        return decl.binding.pattern.symbol().?;
    } else {
        std.debug.panic("compiler error: unsupported access symbol resolution for decl-like AST: {s}", .{@tagName(decl.*)});
    }
}
