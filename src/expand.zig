// Performs local, *simple* expansions on AST nodes

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const primitives_ = @import("primitives.zig");

const Expand_Error = error{parseError};

pub fn expand_from_list(asts: std.ArrayList(*ast_.AST), errors: *errs_.Errors, allocator: std.mem.Allocator) Expand_Error!void {
    for (asts.items) |ast| {
        try expand(ast, errors, allocator);
    }
}

fn expand(maybe_ast: ?*ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) Expand_Error!void {
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
        .pattern_symbol,
        .domainOf,
        => {},

        ._typeOf,
        .default,
        .sizeOf,
        .not,
        .negate,
        .dereference,
        ._try,
        .discard,
        ._comptime,
        => try expand(ast.expr(), errors, allocator),

        .assign => {
            try expand(ast.assign.lhs, errors, allocator);
            try expand(ast.assign.rhs, errors, allocator);
        },
        ._or => {
            try expand(ast._or.lhs, errors, allocator);
            try expand(ast._or.rhs, errors, allocator);
        },
        ._and => {
            try expand(ast._and.lhs, errors, allocator);
            try expand(ast._and.rhs, errors, allocator);
        },
        .add => {
            try expand(ast.add.lhs, errors, allocator);
            try expand(ast.add.rhs, errors, allocator);
        },
        .sub => {
            try expand(ast.sub.lhs, errors, allocator);
            try expand(ast.sub.rhs, errors, allocator);
        },
        .mult => {
            try expand(ast.mult.lhs, errors, allocator);
            try expand(ast.mult.rhs, errors, allocator);
        },
        .div => {
            try expand(ast.div.lhs, errors, allocator);
            try expand(ast.div.rhs, errors, allocator);
        },
        .mod => {
            try expand(ast.mod.lhs, errors, allocator);
            try expand(ast.mod.rhs, errors, allocator);
        },
        .equal => {
            try expand(ast.equal.lhs, errors, allocator);
            try expand(ast.equal.rhs, errors, allocator);
        },
        .not_equal => {
            try expand(ast.not_equal.lhs, errors, allocator);
            try expand(ast.not_equal.rhs, errors, allocator);
        },
        .greater => {
            try expand(ast.greater.lhs, errors, allocator);
            try expand(ast.greater.rhs, errors, allocator);
        },
        .lesser => {
            try expand(ast.lesser.lhs, errors, allocator);
            try expand(ast.lesser.rhs, errors, allocator);
        },
        .greater_equal => {
            try expand(ast.greater_equal.lhs, errors, allocator);
            try expand(ast.greater_equal.rhs, errors, allocator);
        },
        .lesser_equal => {
            try expand(ast.lesser_equal.lhs, errors, allocator);
            try expand(ast.lesser_equal.rhs, errors, allocator);
        },
        ._catch => {
            try expand(ast._catch.lhs, errors, allocator);
            try expand(ast._catch.rhs, errors, allocator);
        },
        ._orelse => {
            try expand(ast._orelse.lhs, errors, allocator);
            try expand(ast._orelse.rhs, errors, allocator);
        },
        .call => {
            try expand(ast.call.lhs, errors, allocator);
            try expand_from_list(ast.call.args, errors, allocator);
        },
        .index => {
            try expand(ast.index.lhs, errors, allocator);
            try expand(ast.index.rhs, errors, allocator);
        },
        .select => {
            try expand(ast.select.lhs, errors, allocator);
            try expand(ast.select.rhs, errors, allocator);
        },
        .function => {
            try expand(ast.function.lhs, errors, allocator);
            try expand(ast.function.rhs, errors, allocator);
        },
        .invoke => {
            try expand(ast.invoke.lhs, errors, allocator);
            try expand(ast.invoke.rhs, errors, allocator);
        },
        .sum => {
            var changed = false;
            var new_terms = std.ArrayList(*ast_.AST).init(allocator);
            var idents_seen = std.StringArrayHashMap(*ast_.AST).init(allocator);
            defer idents_seen.deinit();
            errdefer new_terms.deinit();

            // Make sure identifiers aren't repeated
            for (ast.sum.terms.items) |term| {
                changed = changed or term.* == .identifier;
                var annotation: *ast_.AST = try annot_from_ast(term, errors, allocator);
                new_terms.append(annotation) catch unreachable;
                const name = annotation.annotation.pattern.getToken().data;
                const res = idents_seen.fetchPut(name, annotation) catch unreachable;
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

            try expand_from_list(ast.sum.terms, errors, allocator);
        },
        .inferred_error => {
            try expand_from_list(ast.inferred_error.terms, errors, allocator);
        },
        .inject => {
            try expand(ast.inject.lhs, errors, allocator);
            try expand(ast.inject.rhs, errors, allocator);
        },
        ._union => {
            try expand(ast._union.lhs, errors, allocator);
            try expand(ast._union.rhs, errors, allocator);
        },

        .product => {
            try expand_from_list(ast.product.terms, errors, allocator);
        },
        .addrOf => try expand(ast.expr(), errors, allocator),
        .sliceOf => {
            try expand(ast.expr(), errors, allocator);
        },
        .arrayOf => {
            try expand(ast.expr(), errors, allocator);
            try expand(ast.arrayOf.len, errors, allocator);
        },
        .subSlice => {
            try expand(ast.subSlice.super, errors, allocator);
            try expand(ast.subSlice.lower, errors, allocator);
            try expand(ast.subSlice.upper, errors, allocator);
        },
        .annotation => {
            try expand(ast.annotation.type, errors, allocator);
            try expand(ast.annotation.predicate, errors, allocator);
            try expand(ast.annotation.init, errors, allocator);
        },

        ._if => {
            try expand(ast._if.let, errors, allocator);
            try expand(ast._if.condition, errors, allocator);
            try expand(ast._if.bodyBlock, errors, allocator);
            try expand(ast._if.elseBlock, errors, allocator);
        },
        .match => {
            try expand(ast.match.let, errors, allocator);
            try expand(ast.expr(), errors, allocator);
            try expand_from_list(ast.match.mappings, errors, allocator);
        },
        .mapping => {
            try expand(ast.mapping.lhs, errors, allocator);
            try expand(ast.mapping.rhs, errors, allocator);
        },
        ._while => {
            try expand(ast._while.let, errors, allocator);
            try expand(ast._while.condition, errors, allocator);
            try expand(ast._while.post, errors, allocator);
            try expand(ast._while.bodyBlock, errors, allocator);
            try expand(ast._while.elseBlock, errors, allocator);
        },
        ._for => {
            try expand(ast._for.let, errors, allocator);
            try expand(ast._for.elem, errors, allocator);
            try expand(ast._for.iterable, errors, allocator);
            try expand(ast._for.bodyBlock, errors, allocator);
            try expand(ast._for.elseBlock, errors, allocator);
        },
        .block => {
            try expand_from_list(ast.block.statements, errors, allocator);
            if (ast.block.final) |final| {
                try expand(final, errors, allocator);
            }
        },

        ._return => try expand(ast._return._ret_expr, errors, allocator),
        .decl => {
            try expand(ast.decl.type, errors, allocator);
            try expand(ast.decl.init, errors, allocator);
        },
        .fnDecl => {
            try expand(ast.fnDecl.init, errors, allocator);
            try expand_from_list(ast.fnDecl.params, errors, allocator);
            try expand(ast.fnDecl.retType, errors, allocator);
        },
        ._defer, ._errdefer => try expand(ast.statement(), errors, allocator),
    }
}

fn annot_from_ast(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST {
    if (ast.* == .annotation) {
        return ast;
    } else if (ast.* == .identifier) {
        return ast_.AST.createAnnotation(ast.getToken(), ast, primitives_.unit_type, null, null, allocator).assert_valid();
    } else {
        errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "invalid sum expression, must be annotation or identifier" } });
        return error.parseError;
    }
}
