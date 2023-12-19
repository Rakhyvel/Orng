// Walks over AST and Symbol Tree, decorates identifier ASTs with the symbol they refer to.

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const primitives_ = @import("primitives.zig");

pub const Sum_Expand_Error = error{ OutOfMemory, parseError };

pub fn expand_sums_from_list(asts: std.ArrayList(*ast_.AST), errors: *errs_.Errors, allocator: std.mem.Allocator) Sum_Expand_Error!void {
    for (asts.items) |ast| {
        try expand_sums(ast, errors, allocator);
    }
}

fn expand_sums(maybe_ast: ?*ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) Sum_Expand_Error!void {
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
        .identifier,
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

        ._typeOf => try expand_sums(ast._typeOf.expr, errors, allocator),
        .default => try expand_sums(ast.default.expr, errors, allocator),
        .sizeOf => try expand_sums(ast.sizeOf.expr, errors, allocator),
        .not => try expand_sums(ast.not.expr, errors, allocator),
        .negate => try expand_sums(ast.negate.expr, errors, allocator),
        .dereference => try expand_sums(ast.dereference.expr, errors, allocator),
        ._try => try expand_sums(ast._try.expr, errors, allocator),
        .discard => try expand_sums(ast.discard.expr, errors, allocator),
        ._comptime => try expand_sums(ast._comptime.expr, errors, allocator),

        .assign => {
            try expand_sums(ast.assign.lhs, errors, allocator);
            try expand_sums(ast.assign.rhs, errors, allocator);
        },
        ._or => {
            try expand_sums(ast._or.lhs, errors, allocator);
            try expand_sums(ast._or.rhs, errors, allocator);
        },
        ._and => {
            try expand_sums(ast._and.lhs, errors, allocator);
            try expand_sums(ast._and.rhs, errors, allocator);
        },
        .add => {
            try expand_sums(ast.add.lhs, errors, allocator);
            try expand_sums(ast.add.rhs, errors, allocator);
        },
        .sub => {
            try expand_sums(ast.sub.lhs, errors, allocator);
            try expand_sums(ast.sub.rhs, errors, allocator);
        },
        .mult => {
            try expand_sums(ast.mult.lhs, errors, allocator);
            try expand_sums(ast.mult.rhs, errors, allocator);
        },
        .div => {
            try expand_sums(ast.div.lhs, errors, allocator);
            try expand_sums(ast.div.rhs, errors, allocator);
        },
        .mod => {
            try expand_sums(ast.mod.lhs, errors, allocator);
            try expand_sums(ast.mod.rhs, errors, allocator);
        },
        .equal => {
            try expand_sums(ast.equal.lhs, errors, allocator);
            try expand_sums(ast.equal.rhs, errors, allocator);
        },
        .not_equal => {
            try expand_sums(ast.not_equal.lhs, errors, allocator);
            try expand_sums(ast.not_equal.rhs, errors, allocator);
        },
        .greater => {
            try expand_sums(ast.greater.lhs, errors, allocator);
            try expand_sums(ast.greater.rhs, errors, allocator);
        },
        .lesser => {
            try expand_sums(ast.lesser.lhs, errors, allocator);
            try expand_sums(ast.lesser.rhs, errors, allocator);
        },
        .greater_equal => {
            try expand_sums(ast.greater_equal.lhs, errors, allocator);
            try expand_sums(ast.greater_equal.rhs, errors, allocator);
        },
        .lesser_equal => {
            try expand_sums(ast.lesser_equal.lhs, errors, allocator);
            try expand_sums(ast.lesser_equal.rhs, errors, allocator);
        },
        ._catch => {
            try expand_sums(ast._catch.lhs, errors, allocator);
            try expand_sums(ast._catch.rhs, errors, allocator);
        },
        ._orelse => {
            try expand_sums(ast._orelse.lhs, errors, allocator);
            try expand_sums(ast._orelse.rhs, errors, allocator);
        },
        .call => {
            try expand_sums(ast.call.lhs, errors, allocator);
            try expand_sums_from_list(ast.call.args, errors, allocator);
        },
        .index => {
            try expand_sums(ast.index.lhs, errors, allocator);
            try expand_sums(ast.index.rhs, errors, allocator);
        },
        .select => {
            try expand_sums(ast.select.lhs, errors, allocator);
            try expand_sums(ast.select.rhs, errors, allocator);
        },
        .function => {
            try expand_sums(ast.function.lhs, errors, allocator);
            try expand_sums(ast.function.rhs, errors, allocator);
        },
        .invoke => {
            try expand_sums(ast.invoke.lhs, errors, allocator);
            try expand_sums(ast.invoke.rhs, errors, allocator);
        },
        .sum => {
            var changed = false;
            var new_terms = std.ArrayList(*ast_.AST).init(allocator);
            var idents_seen = std.StringArrayHashMap(*ast_.AST).init(allocator);
            defer idents_seen.deinit();
            errdefer new_terms.deinit();

            for (ast.sum.terms.items) |term| {
                // Make sure identifiers aren't repeated
                var annotation: *ast_.AST = undefined;
                if (term.* == .annotation) {
                    annotation = term;
                } else if (term.* == .identifier) {
                    annotation = (try ast_.AST.createAnnotation(term.getToken(), term, primitives_.unit_type, null, null, allocator)).assert_valid();
                    changed = true;
                } else {
                    errors.addError(errs_.Error{ .basic = .{ .span = term.getToken().span, .msg = "invalid sum expression, must be annotation or identifier" } });
                    return error.parseError;
                }
                try new_terms.append(annotation);
                const name = annotation.annotation.pattern.getToken().data;
                const res = try idents_seen.fetchPut(name, annotation);
                if (res) |_res| {
                    errors.addError(errs_.Error{ .sum_duplicate = .{ .span = term.getToken().span, .identifier = name, .first = _res.value.getToken().span } });
                    return error.parseError;
                }
            }

            if (changed) {
                ast.sum.terms = new_terms;
            } else {
                new_terms.deinit();
            }

            try expand_sums_from_list(ast.sum.terms, errors, allocator);
        },
        .inferred_error => {
            try expand_sums_from_list(ast.inferred_error.terms, errors, allocator);
        },
        .inject => {
            try expand_sums(ast.inject.lhs, errors, allocator);
            try expand_sums(ast.inject.rhs, errors, allocator);
        },
        ._union => {
            try expand_sums(ast._union.lhs, errors, allocator);
            try expand_sums(ast._union.rhs, errors, allocator);
        },

        .product => {
            try expand_sums_from_list(ast.product.terms, errors, allocator);
        },
        .addrOf => try expand_sums(ast.addrOf.expr, errors, allocator),
        .sliceOf => {
            try expand_sums(ast.sliceOf.expr, errors, allocator);
            try expand_sums(ast.sliceOf.len, errors, allocator);
        },
        .subSlice => {
            try expand_sums(ast.subSlice.super, errors, allocator);
            try expand_sums(ast.subSlice.lower, errors, allocator);
            try expand_sums(ast.subSlice.upper, errors, allocator);
        },
        .annotation => {
            try expand_sums(ast.annotation.type, errors, allocator);
            try expand_sums(ast.annotation.predicate, errors, allocator);
            try expand_sums(ast.annotation.init, errors, allocator);
        },

        ._if => {
            try expand_sums(ast._if.let, errors, allocator);
            try expand_sums(ast._if.condition, errors, allocator);
            try expand_sums(ast._if.bodyBlock, errors, allocator);
            try expand_sums(ast._if.elseBlock, errors, allocator);
        },
        .match => {
            try expand_sums(ast.match.let, errors, allocator);
            try expand_sums(ast.match.expr, errors, allocator);
            try expand_sums_from_list(ast.match.mappings, errors, allocator);
        },
        .mapping => {
            try expand_sums(ast.mapping.lhs, errors, allocator);
            try expand_sums(ast.mapping.rhs, errors, allocator);
        },
        ._while => {
            try expand_sums(ast._while.let, errors, allocator);
            try expand_sums(ast._while.condition, errors, allocator);
            try expand_sums(ast._while.post, errors, allocator);
            try expand_sums(ast._while.bodyBlock, errors, allocator);
            try expand_sums(ast._while.elseBlock, errors, allocator);
        },
        ._for => {
            try expand_sums(ast._for.let, errors, allocator);
            try expand_sums(ast._for.elem, errors, allocator);
            try expand_sums(ast._for.iterable, errors, allocator);
            try expand_sums(ast._for.bodyBlock, errors, allocator);
            try expand_sums(ast._for.elseBlock, errors, allocator);
        },
        .block => {
            try expand_sums_from_list(ast.block.statements, errors, allocator);
            if (ast.block.final) |final| {
                try expand_sums(final, errors, allocator);
            }
        },

        ._return => try expand_sums(ast._return.expr, errors, allocator),
        .decl => {
            try expand_sums(ast.decl.type, errors, allocator);
            try expand_sums(ast.decl.init, errors, allocator);
        },
        .fnDecl => {
            try expand_sums(ast.fnDecl.init, errors, allocator);
            try expand_sums_from_list(ast.fnDecl.params, errors, allocator);
            try expand_sums(ast.fnDecl.retType, errors, allocator);
        },
        ._defer => try expand_sums(ast._defer.statement, errors, allocator),
        ._errdefer => try expand_sums(ast._errdefer.statement, errors, allocator),
    }
}
