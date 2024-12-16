// Walks over AST and Symbol Tree, decorates identifier ASTs with the symbol they refer to.

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const symbol_ = @import("symbol.zig");

const Decorate_Error = error{CompileError};

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
    asts: std.ArrayList(*ast_.AST),
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Decorate_Error!void {
    for (asts.items) |ast| {
        try decorate_identifiers(ast, scope, errors, allocator);
    }
}

// TODO:
//
// // A struct to contain a generic pass
// fn Pass(comptime ctx: type) type {
//     return struct {
//         run: *const fn(ast_.AST, ctx) Pass_Error!void
//     };
// }
//
// // A function that walks over an AST, applying pass's function to each one
// fn walk_ast(ast: *ast_.AST, context: anytype, pass: comptime{Pass(@TypeOf(context))}) Pass_Error!void {
//     try pass.run(ast, context);
//     switch (ast.*) {
//         .add, sub, mul, div, .mod => {
//             try walk_ast(ast.lhs(), context);
//             try walk_ast(ast.rhs(), context);
//         }
//     }
// }
//
// const Decorate_Context = struct {scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator};
// fn decorate(ast: *ast_.AST, ctx: Decorate_Context) Pass_Error!void {
//     if (ast.* == .identifier) {
//         // decorate the identifier
//     } // That's it!
// }

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
                    return error.CompileError;
                },

                // Found the symbol, but must cross a comptime-boundary to access it, and it is not const
                .found_but_rt => {
                    errors.add_error(errs_.Error{ .comptime_access_runtime = .{ .identifier = ast.token() } });
                    return error.CompileError;
                },

                // Found the symbol, but must cross an inner-function boundary to access it, and it is not const
                .found_but_fn => {
                    errors.add_error(errs_.Error{ .inner_fn_access_runtime = .{ .identifier = ast.token() } });
                    return error.CompileError;
                },
            }
            if (!ast.symbol().?.defined) {
                errors.add_error(errs_.Error{ .use_before_def = .{ .identifier = ast.token() } });
                return error.CompileError;
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
        .access,
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
            try decorate_identifiers_from_list(ast.trait.method_decls, ast.trait.scope.?, errors, allocator);
            try decorate_identifiers_from_list(ast.trait.const_decls, ast.trait.scope.?, errors, allocator);
            scope.traits.append(ast) catch unreachable;
        },
        .impl => {
            try decorate_identifiers(ast.impl._type, scope, errors, allocator);
            try decorate_identifiers(ast.impl.trait, ast.impl.scope.?, errors, allocator);
            try decorate_identifiers_from_list(ast.impl.method_defs, ast.impl.scope.?, errors, allocator);
            try decorate_identifiers_from_list(ast.impl.const_defs, ast.impl.scope.?, errors, allocator);
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
