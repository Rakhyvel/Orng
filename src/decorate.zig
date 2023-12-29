// Walks over AST and Symbol Tree, decorates identifier ASTs with the symbol they refer to.

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const symbol_ = @import("symbol.zig");

const Decorate_Error = error{SymbolError};

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

fn decorate_identifiers(
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
        .inferred_member,
        .poison,
        .pattern_symbol,
        .domain_of,
        => {},

        .identifier => {
            const res = scope.lookup(ast.token().data, false);
            switch (res) {
                // Found the symbol, decorate the identifier AST with it
                .found => ast.set_symbol(res.found),

                // Couldn't find the symbol
                .not_found => {
                    errors.addError(errs_.Error{ .undeclared_identifier = .{ .identifier = ast.token(), .expected = null } });
                    return error.SymbolError;
                },

                // Found the symbol, but must cross a comptime-boundary to access it, and it is not const
                .found_but_rt => {
                    errors.addError(errs_.Error{ .comptime_access_runtime = .{ .identifier = ast.token() } });
                    return error.SymbolError;
                },

                // Found the symbol, but must cross an inner-function boundary to access it, and it is not const
                .found_but_fn => {
                    errors.addError(errs_.Error{ .inner_fn_access_runtime = .{ .identifier = ast.token() } });
                    return error.SymbolError;
                },
            }
            if (!ast.symbol().?.defined) {
                errors.addError(errs_.Error{ .use_before_def = .{ .identifier = ast.token() } });
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
        .discard,
        .@"comptime",
        .addr_of,
        .slice_of,
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
        .invoke,
        .inject,
        .@"union",
        => {
            try decorate_identifiers(ast.lhs(), scope, errors, allocator);
            try decorate_identifiers(ast.rhs(), scope, errors, allocator);
        },
        .call => {
            try decorate_identifiers(ast.lhs(), scope, errors, allocator);
            try decorate_identifiers_from_list(ast.children().*, scope, errors, allocator);
        },
        .sum, .inferred_error, .product => try decorate_identifiers_from_list(ast.children().*, scope, errors, allocator),

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
            try decorate_identifiers(ast.@"if".body_block, ast.@"if".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"if".else_block, ast.@"if".scope.?, errors, allocator);
        },
        .match => {
            try decorate_identifiers(ast.match.let, scope, errors, allocator);
            try decorate_identifiers(ast.expr(), ast.match.scope.?, errors, allocator);
            try decorate_identifiers_from_list(ast.children().*, ast.match.scope.?, errors, allocator);
        },
        .mapping => {
            try decorate_identifiers(ast.mapping_lhs(), scope, errors, allocator);
            // non-else mappings have their own scope
            // else mappings use the surrounding match scope
            try decorate_identifiers(ast.rhs(), ast.mapping.scope orelse scope, errors, allocator);
        },
        .@"while" => {
            try decorate_identifiers(ast.@"while".let, scope, errors, allocator);
            try decorate_identifiers(ast.@"while".condition, ast.@"while".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"while".post, ast.@"while".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"while".body_block, ast.@"while".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"while".else_block, ast.@"while".scope.?, errors, allocator);
        },
        .@"for" => {
            try decorate_identifiers(ast.@"for".let, scope, errors, allocator);
            try decorate_identifiers(ast.@"for".elem, ast.@"for".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"for".iterable, ast.@"for".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"for".body_block, ast.@"for".scope.?, errors, allocator);
            try decorate_identifiers(ast.@"for".else_block, ast.@"for".scope.?, errors, allocator);
        },
        .block => {
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
        .@"defer", .@"errdefer" => try decorate_identifiers(ast.statement(), scope, errors, allocator),
    }
}
