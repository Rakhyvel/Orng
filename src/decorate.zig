// Walks over AST and Symbol Tree, decorates identifier ASTs with the symbol they refer to.

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const symbol_ = @import("symbol.zig");

const Decorate_Error = error{symbolError};

pub fn decorate_identifiers_from_list(asts: std.ArrayList(*ast_.AST), scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) Decorate_Error!void {
    for (asts.items) |ast| {
        try decorate_identifiers(ast, scope, errors, allocator);
    }
}

fn decorate_identifiers(maybe_ast: ?*ast_.AST, scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) Decorate_Error!void {
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
        ._unreachable,
        ._true,
        ._false,
        ._break,
        ._continue,
        .inferredMember,
        .poison,
        .pattern_symbol,
        .domainOf,
        => {},

        .identifier => {
            const res = scope.lookup(ast.getToken().data, false);
            switch (res) {
                // Found the symbol, decorate the identifier AST with it
                .found => ast.set_symbol(res.found),

                // Couldn't find the symbol
                .not_found => {
                    errors.addError(errs_.Error{ .undeclaredIdentifier = .{ .identifier = ast.getToken(), .expected = null } });
                    return error.symbolError;
                },

                // Found the symbol, but must cross a comptime-boundary to access it, and it is not const
                .found_but_rt => {
                    errors.addError(errs_.Error{ .comptime_access_runtime = .{ .identifier = ast.getToken() } });
                    return error.symbolError;
                },

                // Found the symbol, but must cross an inner-function boundary to access it, and it is not const
                .found_but_fn => {
                    errors.addError(errs_.Error{ .inner_fn_access_runtime = .{ .identifier = ast.getToken() } });
                    return error.symbolError;
                },
            }
            if (!ast.symbol().?.defined) {
                errors.addError(errs_.Error{ .useBeforeDef = .{ .identifier = ast.getToken() } });
                return error.symbolError;
            }
        },

        ._typeOf,
        .default,
        .sizeOf,
        .not,
        .negate,
        .dereference,
        ._try,
        .discard,
        ._comptime,
        .addrOf,
        .sliceOf,
        => try decorate_identifiers(ast.expr(), scope, errors, allocator),

        .assign,
        ._or,
        ._and,
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
        ._catch,
        ._orelse,
        .index,
        .select,
        .function,
        .invoke,
        .inject,
        ._union,
        => {
            try decorate_identifiers(ast.lhs(), scope, errors, allocator);
            try decorate_identifiers(ast.rhs(), scope, errors, allocator);
        },
        .call => {
            try decorate_identifiers(ast.lhs(), scope, errors, allocator);
            try decorate_identifiers_from_list(ast.call.args, scope, errors, allocator);
        },
        .sum => {
            try decorate_identifiers_from_list(ast.sum.terms, scope, errors, allocator);
        },
        .inferred_error => {
            try decorate_identifiers_from_list(ast.inferred_error.terms, scope, errors, allocator);
        },

        .product => {
            try decorate_identifiers_from_list(ast.product.terms, scope, errors, allocator);
        },
        .arrayOf => {
            try decorate_identifiers(ast.expr(), scope, errors, allocator);
            try decorate_identifiers(ast.arrayOf.len, scope, errors, allocator);
        },
        .subSlice => {
            try decorate_identifiers(ast.subSlice.super, scope, errors, allocator);
            try decorate_identifiers(ast.subSlice.lower, scope, errors, allocator);
            try decorate_identifiers(ast.subSlice.upper, scope, errors, allocator);
        },
        .annotation => {
            try decorate_identifiers(ast.annotation.type, scope, errors, allocator);
            try decorate_identifiers(ast.annotation.predicate, scope, errors, allocator);
            try decorate_identifiers(ast.annotation.init, scope, errors, allocator);
        },

        ._if => {
            try decorate_identifiers(ast._if.let, scope, errors, allocator);
            try decorate_identifiers(ast._if.condition, ast._if.scope.?, errors, allocator);
            try decorate_identifiers(ast._if.bodyBlock, ast._if.scope.?, errors, allocator);
            try decorate_identifiers(ast._if.elseBlock, ast._if.scope.?, errors, allocator);
        },
        .match => {
            try decorate_identifiers(ast.match.let, scope, errors, allocator);
            try decorate_identifiers(ast.expr(), ast.match.scope.?, errors, allocator);
            try decorate_identifiers_from_list(ast.match.mappings, ast.match.scope.?, errors, allocator);
        },
        .mapping => {
            try decorate_identifiers(ast.mapping_lhs(), scope, errors, allocator);
            // non-else mappings have their own scope
            // else mappings use the surrounding match scope
            try decorate_identifiers(ast.rhs(), ast.mapping.scope orelse scope, errors, allocator);
        },
        ._while => {
            try decorate_identifiers(ast._while.let, scope, errors, allocator);
            try decorate_identifiers(ast._while.condition, ast._while.scope.?, errors, allocator);
            try decorate_identifiers(ast._while.post, ast._while.scope.?, errors, allocator);
            try decorate_identifiers(ast._while.bodyBlock, ast._while.scope.?, errors, allocator);
            try decorate_identifiers(ast._while.elseBlock, ast._while.scope.?, errors, allocator);
        },
        ._for => {
            try decorate_identifiers(ast._for.let, scope, errors, allocator);
            try decorate_identifiers(ast._for.elem, ast._for.scope.?, errors, allocator);
            try decorate_identifiers(ast._for.iterable, ast._for.scope.?, errors, allocator);
            try decorate_identifiers(ast._for.bodyBlock, ast._for.scope.?, errors, allocator);
            try decorate_identifiers(ast._for.elseBlock, ast._for.scope.?, errors, allocator);
        },
        .block => {
            try decorate_identifiers_from_list(ast.block.statements, ast.block.scope.?, errors, allocator);
            if (ast.block.final) |final| {
                try decorate_identifiers(final, ast.block.scope.?, errors, allocator);
            }
        },

        ._return => try decorate_identifiers(ast._return._ret_expr, scope, errors, allocator),
        .decl => {
            try decorate_identifiers(ast.decl.type, scope, errors, allocator);
            try decorate_identifiers(ast.decl.init, scope, errors, allocator);
            for (ast.decl.symbols.items) |symbol| {
                symbol.defined = true;
            }
        },
        .fnDecl => {
            try decorate_identifiers(ast.fnDecl.init, ast.symbol().?.scope, errors, allocator);
            try decorate_identifiers_from_list(ast.fnDecl.params, ast.symbol().?.scope, errors, allocator);
            try decorate_identifiers(ast.fnDecl.retType, ast.symbol().?.scope, errors, allocator);
        },
        ._defer, ._errdefer => try decorate_identifiers(ast.statement(), scope, errors, allocator),
    }
}
