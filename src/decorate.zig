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
        .symbol,
        .domainOf,
        => {},

        .identifier => {
            const res = scope.lookup(ast.getToken().data, false);
            switch (res) {
                // Found the symbol, decorate the identifier AST with it
                .found => ast.identifier.symbol = res.found,

                // Couldn't find the symbol
                .not_found => {
                    errors.addError(errs_.Error{ .undeclaredIdentifier = .{ .identifier = ast.getToken(), .scope = scope, .expected = null } });
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
            if (!ast.identifier.symbol.?.defined) {
                errors.addError(errs_.Error{ .useBeforeDef = .{ .identifier = ast.getToken() } });
                return error.symbolError;
            }
        },

        ._typeOf => try decorate_identifiers(ast._typeOf.expr, scope, errors, allocator),
        .default => try decorate_identifiers(ast.default.expr, scope, errors, allocator),
        .sizeOf => try decorate_identifiers(ast.sizeOf.expr, scope, errors, allocator),
        .not => try decorate_identifiers(ast.not.expr, scope, errors, allocator),
        .negate => try decorate_identifiers(ast.negate.expr, scope, errors, allocator),
        .dereference => try decorate_identifiers(ast.dereference.expr, scope, errors, allocator),
        ._try => try decorate_identifiers(ast._try.expr, scope, errors, allocator),
        .discard => try decorate_identifiers(ast.discard.expr, scope, errors, allocator),
        ._comptime => try decorate_identifiers(ast._comptime.expr, scope, errors, allocator),

        .assign => {
            try decorate_identifiers(ast.assign.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.assign.rhs, scope, errors, allocator);
        },
        ._or => {
            try decorate_identifiers(ast._or.lhs, scope, errors, allocator);
            try decorate_identifiers(ast._or.rhs, scope, errors, allocator);
        },
        ._and => {
            try decorate_identifiers(ast._and.lhs, scope, errors, allocator);
            try decorate_identifiers(ast._and.rhs, scope, errors, allocator);
        },
        .add => {
            try decorate_identifiers(ast.add.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.add.rhs, scope, errors, allocator);
        },
        .sub => {
            try decorate_identifiers(ast.sub.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.sub.rhs, scope, errors, allocator);
        },
        .mult => {
            try decorate_identifiers(ast.mult.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.mult.rhs, scope, errors, allocator);
        },
        .div => {
            try decorate_identifiers(ast.div.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.div.rhs, scope, errors, allocator);
        },
        .mod => {
            try decorate_identifiers(ast.mod.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.mod.rhs, scope, errors, allocator);
        },
        .equal => {
            try decorate_identifiers(ast.equal.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.equal.rhs, scope, errors, allocator);
        },
        .not_equal => {
            try decorate_identifiers(ast.not_equal.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.not_equal.rhs, scope, errors, allocator);
        },
        .greater => {
            try decorate_identifiers(ast.greater.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.greater.rhs, scope, errors, allocator);
        },
        .lesser => {
            try decorate_identifiers(ast.lesser.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.lesser.rhs, scope, errors, allocator);
        },
        .greater_equal => {
            try decorate_identifiers(ast.greater_equal.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.greater_equal.rhs, scope, errors, allocator);
        },
        .lesser_equal => {
            try decorate_identifiers(ast.lesser_equal.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.lesser_equal.rhs, scope, errors, allocator);
        },
        ._catch => {
            try decorate_identifiers(ast._catch.lhs, scope, errors, allocator);
            try decorate_identifiers(ast._catch.rhs, scope, errors, allocator);
        },
        ._orelse => {
            try decorate_identifiers(ast._orelse.lhs, scope, errors, allocator);
            try decorate_identifiers(ast._orelse.rhs, scope, errors, allocator);
        },
        .call => {
            try decorate_identifiers(ast.call.lhs, scope, errors, allocator);
            try decorate_identifiers_from_list(ast.call.args, scope, errors, allocator);
        },
        .index => {
            try decorate_identifiers(ast.index.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.index.rhs, scope, errors, allocator);
        },
        .select => {
            try decorate_identifiers(ast.select.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.select.rhs, scope, errors, allocator);
        },
        .function => {
            try decorate_identifiers(ast.function.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.function.rhs, scope, errors, allocator);
        },
        .invoke => {
            try decorate_identifiers(ast.invoke.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.invoke.rhs, scope, errors, allocator);
        },
        .sum => {
            try decorate_identifiers_from_list(ast.sum.terms, scope, errors, allocator);
        },
        .inferred_error => {
            try decorate_identifiers_from_list(ast.inferred_error.terms, scope, errors, allocator);
        },
        .inject => {
            try decorate_identifiers(ast.inject.lhs, scope, errors, allocator);
            try decorate_identifiers(ast.inject.rhs, scope, errors, allocator);
        },
        ._union => {
            try decorate_identifiers(ast._union.lhs, scope, errors, allocator);
            try decorate_identifiers(ast._union.rhs, scope, errors, allocator);
        },

        .product => {
            try decorate_identifiers_from_list(ast.product.terms, scope, errors, allocator);
        },
        .addrOf => try decorate_identifiers(ast.addrOf.expr, scope, errors, allocator),
        .sliceOf => {
            try decorate_identifiers(ast.sliceOf.expr, scope, errors, allocator);
        },
        .arrayOf => {
            try decorate_identifiers(ast.arrayOf.expr, scope, errors, allocator);
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
            try decorate_identifiers(ast.match.expr, ast.match.scope.?, errors, allocator);
            try decorate_identifiers_from_list(ast.match.mappings, ast.match.scope.?, errors, allocator);
        },
        .mapping => {
            try decorate_identifiers(ast.mapping.lhs, scope, errors, allocator);
            if (ast.mapping.scope) |lhs_scope| {
                // non-else mappings have their own scope
                try decorate_identifiers(ast.mapping.rhs, lhs_scope, errors, allocator);
            } else {
                // else mappings use the surrounding match scope
                try decorate_identifiers(ast.mapping.rhs, scope, errors, allocator);
            }
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

        ._return => try decorate_identifiers(ast._return.expr, scope, errors, allocator),
        .decl => {
            try decorate_identifiers(ast.decl.type, scope, errors, allocator);
            try decorate_identifiers(ast.decl.init, scope, errors, allocator);
            for (ast.decl.symbols.items) |symbol| {
                symbol.defined = true;
            }
        },
        .fnDecl => {
            try decorate_identifiers(ast.fnDecl.init, ast.fnDecl.symbol.?.scope, errors, allocator);
            try decorate_identifiers_from_list(ast.fnDecl.params, ast.fnDecl.symbol.?.scope, errors, allocator);
            try decorate_identifiers(ast.fnDecl.retType, ast.fnDecl.symbol.?.scope, errors, allocator);
        },
        ._defer => try decorate_identifiers(ast._defer.statement, scope, errors, allocator),
        ._errdefer => try decorate_identifiers(ast._errdefer.statement, scope, errors, allocator),
    }
}
