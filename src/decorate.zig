// Walks over AST and Symbol Tree, decorates identifier ASTs with the symbol they refer to.

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const symbol_ = @import("symbol.zig");

const Decorate_Error = error{SymbolError};

/// Recursively decorates the identifiers in the given ASTs with the symbols they refer to.
///
/// ## Parameters:
/// - `asts`: List of ASTs to recursively decorate
/// - `scope`: Shared scope of all the ASTs
/// - `errors`: Error manager
/// - `allocator`: Allocator to use
///
/// ## Errors:
/// Errors out if symbols cannot be looked up. Error messages are added to the error manager.
pub fn decorate_identifiers_from_list(
    asts: std.ArrayList(*ast_.AST), // TODO: Accept slice
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Decorate_Error!void {
    for (asts.items) |ast| {
        try decorate_identifiers(ast, scope, errors, allocator);
    }
}

/// Recursively decorates the identifiers in the given AST with the symbols they refer to.
///
/// ## Parameters:
/// - `ast`: AST to recursively decorate with symbols
/// - `scope`: Scope of the AST
/// - `errors`: Error manager
/// - `allocator`: Allocator to use
///
/// ## Errors:
/// Errors out if symbols cannot be looked up. Error messages are added to the error manager.
pub fn decorate_identifiers(
    maybe_ast: ?*ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Decorate_Error!void {
    if (maybe_ast == null) {
        return;
    }
    const ast = maybe_ast.?;
    switch (ast.*) {
        .anyptr_type,
        .unit_type,
        .unit_value,
        .int,
        .char,
        .float,
        .string,
        .field,
        .@"unreachable",
        .true,
        .false,
        .@"break",
        .@"continue",
        .poison,
        .pattern_symbol,
        .domain_of,
        .receiver,
        .template,
        => {},

        .identifier => {
            const res = scope.lookup(ast.token().data, false);
            switch (res) {
                // Found the symbol, decorate the identifier AST with it
                .found => ast.set_symbol(res.found),

                // Couldn't find the symbol
                .not_found => {
                    errors.add_error(errs_.Error{ .undeclared_identifier = .{ .identifier = ast.token(), .expected = null } });
                    return error.SymbolError;
                },

                // Found the symbol, but must cross a comptime-boundary to access it, and it is not const
                .found_but_rt => {
                    errors.add_error(errs_.Error{ .comptime_access_runtime = .{ .identifier = ast.token() } });
                    return error.SymbolError;
                },

                // Found the symbol, but must cross an inner-function boundary to access it, and it is not const
                .found_but_fn => {
                    errors.add_error(errs_.Error{ .inner_fn_access_runtime = .{ .identifier = ast.token() } });
                    return error.SymbolError;
                },
            }
            if (!ast.symbol().?.defined) {
                errors.add_error(errs_.Error{ .use_before_def = .{ .identifier = ast.token() } });
                return error.SymbolError;
            }
        },

        .type_of,
        .default,
        .size_of,
        .not,
        .negate,
        .dereference,
        .@"try",
        .@"comptime",
        .addr_of,
        .slice_of,
        .dyn_type,
        .dyn_value,
        => try decorate_identifiers(ast.expr(), scope, errors, allocator),

        .assign,
        .@"or",
        .@"and",
        .add,
        .sub,
        .mult,
        .div,
        .mod,
        .equal,
        .not_equal,
        .greater,
        .lesser,
        .greater_equal,
        .lesser_equal,
        .@"catch",
        .@"orelse",
        .index,
        .select,
        .function,
        .@"union",
        => {
            try decorate_identifiers(ast.lhs(), scope, errors, allocator);
            try decorate_identifiers(ast.rhs(), scope, errors, allocator);
        },
        .invoke => {
            try decorate_identifiers(ast.lhs(), scope, errors, allocator);
            try decorate_identifiers(ast.rhs(), scope, errors, allocator);
            try decorate_identifiers_from_list(ast.children().*, scope, errors, allocator);
        },
        .call => {
            try decorate_identifiers(ast.lhs(), scope, errors, allocator);
            try decorate_identifiers_from_list(ast.children().*, scope, errors, allocator);
        },
        .sum_type, .product => try decorate_identifiers_from_list(ast.children().*, scope, errors, allocator),

        .sum_value => {
            try decorate_identifiers(ast.sum_value.init, scope, errors, allocator);
            try decorate_identifiers(ast.sum_value.base, scope, errors, allocator);
        },

        .array_of => {
            try decorate_identifiers(ast.expr(), scope, errors, allocator);
            try decorate_identifiers(ast.array_of.len, scope, errors, allocator);
        },
        .sub_slice => {
            try decorate_identifiers(ast.sub_slice.super, scope, errors, allocator);
            try decorate_identifiers(ast.sub_slice.lower, scope, errors, allocator);
            try decorate_identifiers(ast.sub_slice.upper, scope, errors, allocator);
        },
        .annotation => {
            try decorate_identifiers(ast.annotation.type, scope, errors, allocator);
            try decorate_identifiers(ast.annotation.predicate, scope, errors, allocator);
            try decorate_identifiers(ast.annotation.init, scope, errors, allocator);
        },

        .@"if" => {
            try decorate_identifiers(ast.@"if".let, scope, errors, allocator);
            try decorate_identifiers(ast.@"if".condition, ast.@"if".scope.?, errors, allocator);
            try decorate_identifiers(ast.body_block(), ast.@"if".scope.?, errors, allocator);
            try decorate_identifiers(ast.else_block(), ast.@"if".scope.?, errors, allocator);
        },
        .match => {
            try decorate_identifiers(ast.match.let, scope, errors, allocator);
            try decorate_identifiers(ast.expr(), ast.match.scope.?, errors, allocator);
            try decorate_identifiers_from_list(ast.children().*, ast.match.scope.?, errors, allocator);
        },
        .mapping => {
            try decorate_identifiers(ast.lhs(), scope, errors, allocator);
            // non-else mappings have their own scope
            // else mappings use the surrounding match scope
            try decorate_identifiers(ast.rhs(), ast.mapping.scope orelse scope, errors, allocator);
        },
        .@"while" => {
            try decorate_identifiers(ast.@"while".let, scope, errors, allocator);
            try decorate_identifiers(ast.@"while".condition, ast.@"while".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"while".post, ast.@"while".scope.?, errors, allocator);
            try decorate_identifiers(ast.body_block(), ast.@"while".scope.?, errors, allocator);
            try decorate_identifiers(ast.else_block(), ast.@"while".scope.?, errors, allocator);
        },
        .@"for" => {
            try decorate_identifiers(ast.@"for".let, scope, errors, allocator);
            try decorate_identifiers(ast.@"for".elem, ast.@"for".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"for".iterable, ast.@"for".scope.?, errors, allocator);
            try decorate_identifiers(ast.body_block(), ast.@"for".scope.?, errors, allocator);
            try decorate_identifiers(ast.else_block(), ast.@"for".scope.?, errors, allocator);
        },
        .block => {
            // std.debug.print("{}\n", .{ast.token().span});
            try decorate_identifiers_from_list(ast.children().*, ast.block.scope.?, errors, allocator);
            if (ast.block.final) |final| {
                try decorate_identifiers(final, ast.block.scope.?, errors, allocator);
            }
        },

        .@"return" => try decorate_identifiers(ast.@"return"._ret_expr, scope, errors, allocator),
        .decl => {
            try decorate_identifiers(ast.decl.type, scope, errors, allocator);
            try decorate_identifiers(ast.decl.init, scope, errors, allocator);
            for (ast.decl.symbols.items) |symbol| {
                symbol.defined = true;
            }
        },
        .fn_decl => {
            try decorate_identifiers(ast.fn_decl.init, ast.symbol().?.scope, errors, allocator);
            try decorate_identifiers_from_list(ast.children().*, ast.symbol().?.scope, errors, allocator);
            try decorate_identifiers(ast.fn_decl.ret_type, ast.symbol().?.scope, errors, allocator);
        },
        .trait => {
            try decorate_identifiers_from_list(ast.children().*, ast.trait.scope.?, errors, allocator);
            scope.traits.append(ast) catch unreachable;
        },
        .impl => {
            try decorate_identifiers(ast.impl._type, scope, errors, allocator);
            try decorate_identifiers(ast.impl.trait, ast.impl.scope.?, errors, allocator);
            try decorate_identifiers_from_list(ast.children().*, ast.impl.scope.?, errors, allocator);

            // Determine the impl's trait's symbol, if it exists
            const trait_symbol: *symbol_.Symbol = ast.impl.trait.?.symbol().?;
            if (scope.impl_trait_lookup(ast.impl._type, trait_symbol)) |other_impl| {
                // Check if there's already an implementation for the same trait and type
                errors.add_error(errs_.Error{ .reimpl = .{
                    .first_defined_span = other_impl.token().span,
                    .redefined_span = ast.token().span,
                    .name = if (!ast.impl.impls_anon_trait) trait_symbol.name else null,
                    ._type = ast.impl._type,
                } });
                return error.SymbolError;
            }

            // No duplicate impls found, add this impl to scope's list of impls
            scope.impls.append(ast) catch unreachable;
        },
        .method_decl => {
            try decorate_identifiers(ast.method_decl.init, scope, errors, allocator);
            try decorate_identifiers_from_list(ast.children().*, scope, errors, allocator);
            try decorate_identifiers(ast.method_decl.ret_type, scope, errors, allocator);
        },
        .@"defer", .@"errdefer" => try decorate_identifiers(ast.statement(), scope, errors, allocator),
    }
}
