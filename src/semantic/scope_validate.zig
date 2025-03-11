//! This file contains the semantic validation logic for scopes.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const validate_AST = @import("ast_validate.zig").validate_AST;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const typing_ = @import("typing.zig");
const validate_symbol_ = @import("symbol_validate.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

pub fn validate(scope: *Scope, compiler: *Compiler_Context) Validate_Error_Enum!void {
    for (scope.symbols.keys()) |key| {
        const symbol = scope.symbols.get(key).?;
        if (symbol.kind == .@"comptime") {
            continue;
        }
        try validate_symbol_.validate(symbol, compiler);
    }
    for (scope.children.items) |child| {
        try validate(child, compiler);
    }
    for (scope.impls.items) |impl| {
        try validate_impl(impl, compiler);
    }
}

// TODO: Split up into smaller functions
fn validate_impl(impl: *ast_.AST, compiler: *Compiler_Context) Validate_Error_Enum!void {
    if (impl.impl._type.* == .addr_of) {
        compiler.errors.add_error(errs_.Error{ .basic = .{
            .span = impl.impl._type.token().span,
            .msg = "cannot implement method for address types",
        } });
        return error.CompileError;
    }

    impl.impl._type = validate_AST(impl.impl._type, primitives_.type_type, compiler);

    const trait_symbol: *Symbol = impl.impl.trait.?.symbol().?;
    const trait_ast = trait_symbol.decl.?;

    // Check that the (trait, type) pair is unique for this scope
    const lookup_res = impl.scope().?.impl_trait_lookup(impl.impl._type, trait_symbol);
    if (lookup_res.count > 1) {
        // Check if there's already an implementation for the same trait and type
        compiler.errors.add_error(errs_.Error{ .reimpl = .{
            .first_defined_span = lookup_res.ast.?.token().span,
            .redefined_span = impl.token().span,
            .name = if (!impl.impl.impls_anon_trait) trait_symbol.name else null,
            ._type = impl.impl._type,
        } });
        return error.CompileError;
    }

    // Construct a map of all trait decls
    var trait_decls = std.StringArrayHashMap(*ast_.AST).init(compiler.allocator()); // Map name -> Method Decl
    defer trait_decls.deinit();
    for (trait_ast.trait.method_decls.items) |decl| {
        trait_decls.put(decl.method_decl.name.token().data, decl) catch unreachable;
    }

    // Subtract trait defs - impl decls
    for (impl.impl.method_defs.items) |def| {
        const def_key = def.method_decl.name.token().data;
        const trait_decl = trait_decls.get(def_key);

        // Check that the trait defines the method
        if (trait_decl == null) {
            compiler.errors.add_error(errs_.Error{ .method_not_in_trait = .{
                .method_span = def.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
            } });
            return error.CompileError;
        }

        // Check that receivers match
        if (!receivers_match(def.method_decl.receiver, trait_decl.?.method_decl.receiver)) {
            compiler.errors.add_error(errs_.Error{ .impl_receiver_mismatch = .{
                .receiver_span = if (def.method_decl.receiver != null) def.method_decl.receiver.?.token().span else def.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
                .trait_receiver = if (trait_decl.?.method_decl.receiver != null) trait_decl.?.method_decl.receiver.?.receiver.kind else null,
                .impl_receiver = if (def.method_decl.receiver != null) def.method_decl.receiver.?.receiver.kind else null,
            } });
            return error.CompileError;
        }

        // Check that paramter arity matches
        if (def.children().items.len != trait_decl.?.children().items.len) {
            compiler.errors.add_error(errs_.Error{ .mismatch_method_param_arity = .{
                .span = def.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
                .trait_arity = trait_decl.?.children().items.len + @intFromBool(trait_decl.?.method_decl.receiver != null),
                .impl_arity = def.children().items.len + @intFromBool(def.method_decl.receiver != null),
            } });
            return error.CompileError;
        }

        // Check that parameters match
        for (def.children().items, trait_decl.?.children().items) |impl_param, trait_param| {
            _ = try typing_.checked_types_match(trait_param.decl.type, primitives_.type_type, &compiler.errors);
            const impl_type = impl_param.decl.type;
            const trait_type = ast_.AST.convert_self_type(trait_param.decl.type, impl.impl._type, compiler.allocator());
            if (!try typing_.checked_types_match(impl_type, trait_type, &compiler.errors)) {
                compiler.errors.add_error(errs_.Error{ .mismatch_method_type = .{
                    .span = impl_param.decl.type.token().span,
                    .method_name = def.method_decl.name.token().data,
                    .trait_name = trait_ast.token().data,
                    .trait_type = trait_type,
                    .impl_type = impl_type,
                } });
                return error.CompileError;
            }
        }

        // Check that return type matches
        const trait_method_ret_type = ast_.AST.convert_self_type(trait_decl.?.method_decl.ret_type, impl.impl._type, compiler.allocator());
        if (!try typing_.checked_types_match(def.method_decl.ret_type, trait_method_ret_type, &compiler.errors)) {
            compiler.errors.add_error(errs_.Error{ .mismatch_method_type = .{
                .span = def.method_decl.ret_type.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
                .trait_type = trait_method_ret_type,
                .impl_type = def.method_decl.ret_type,
            } });
            return error.CompileError;
        }

        // Copy over the c_type from trait method decl
        def.method_decl.c_type = trait_decl.?.method_decl.c_type;

        // Verify that impl virtuality matches trait virtuality
        if (def.method_decl.is_virtual != trait_decl.?.method_decl.is_virtual) {
            compiler.errors.add_error(errs_.Error{ .mismatch_method_virtuality = .{
                .span = def.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
                .trait_method_is_virtual = trait_decl.?.method_decl.is_virtual,
                .impl_method_is_virtual = def.method_decl.is_virtual,
            } });
            return error.CompileError;
        }

        if (def.method_decl.is_virtual) {
            impl.impl.num_virtual_methods += 1;
        }

        // Subtract the method from the set
        _ = trait_decls.swapRemove(def_key);
    }

    var errant = false;
    for (trait_decls.keys()) |trait_key| {
        const trait_decl = trait_decls.get(trait_key).?;
        compiler.errors.add_error(errs_.Error{ .method_not_in_impl = .{
            .impl_span = impl.token().span,
            .method_span = trait_decl.token().span,
            .method_name = trait_decl.method_decl.name.token().data,
            .trait_name = trait_ast.token().data,
        } });
        errant = true;
    }
    if (errant) {
        return error.CompileError;
    }

    for (impl.impl.method_defs.items, 0..) |def, i| {
        impl.impl.method_defs.items[i] = validate_AST(def, null, compiler);
    }
}

fn receivers_match(a: ?*ast_.AST, b: ?*ast_.AST) bool {
    if (a == null and b != null) {
        return false;
    } else if (a != null and b == null) {
        return false;
    } else if (a == null and b == null) {
        return true;
    } else {
        return a.?.receiver.kind == b.?.receiver.kind;
    }
}
