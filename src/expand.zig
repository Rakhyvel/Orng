// Performs local, *simple* expansions on AST nodes

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const primitives_ = @import("primitives.zig");
const token_ = @import("token.zig");

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
        .addrOf,
        .sliceOf,
        => try expand(ast.expr(), errors, allocator),

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
        .@"catch",
        .@"orelse",
        .index,
        .select,
        .function,
        .invoke,
        .inject,
        ._union,
        => {
            try expand(ast.lhs(), errors, allocator);
            try expand(ast.rhs(), errors, allocator);
        },
        .call => {
            try expand(ast.lhs(), errors, allocator);
            try expand_from_list(ast.children().*, errors, allocator);
        },
        .sum => {
            var changed = false;
            var new_terms = std.ArrayList(*ast_.AST).init(allocator);
            var idents_seen = std.StringArrayHashMap(*ast_.AST).init(allocator);
            defer idents_seen.deinit();
            errdefer new_terms.deinit();

            // Make sure identifiers aren't repeated
            for (ast.children().items) |term| {
                changed = changed or term.* == .identifier;
                var annotation: *ast_.AST = try annot_from_ast(term, errors, allocator);
                new_terms.append(annotation) catch unreachable;
                const name = annotation.annotation.pattern.token().data;
                const res = idents_seen.fetchPut(name, annotation) catch unreachable;
                if (res) |_res| {
                    errors.addError(errs_.Error{
                        .sum_duplicate = .{ .span = term.token().span, .identifier = name, .first = _res.value.token().span },
                    });
                    return error.parseError;
                }
            }

            if (changed) {
                ast.set_children(new_terms);
            } else {
                new_terms.deinit();
            }

            try expand_from_list(ast.children().*, errors, allocator);
        },
        .inferred_error, .product => try expand_from_list(ast.children().*, errors, allocator),
        .arrayOf => {
            try expand(ast.expr(), errors, allocator);
            try expand(ast.arrayOf.len, errors, allocator);
        },
        .subSlice => {
            if (ast.subSlice.lower == null) {
                ast.subSlice.lower = ast_.AST.createInt(ast.token(), 0, allocator);
            }
            if (ast.subSlice.upper == null) {
                const length = ast_.AST.createField(token_.Token.init("length", null, "", "", 0, 0), allocator);
                ast.subSlice.upper = ast_.AST.createSelect(
                    ast.token(),
                    ast.subSlice.super,
                    length,
                    allocator,
                );
            }

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
            try expand_from_list(ast.children().*, errors, allocator);
        },
        .mapping => {
            try expand(ast.mapping_lhs(), errors, allocator);
            try expand(ast.rhs(), errors, allocator);
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
            try expand_from_list(ast.children().*, errors, allocator);
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
            try expand_from_list(ast.children().*, errors, allocator);
            try expand(ast.fnDecl.retType, errors, allocator);
        },
        ._defer, ._errdefer => try expand(ast.statement(), errors, allocator),
    }
}

fn annot_from_ast(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST {
    if (ast.* == .annotation) {
        return ast;
    } else if (ast.* == .identifier) {
        return ast_.AST.createAnnotation(ast.token(), ast, primitives_.unit_type, null, null, allocator).assert_valid();
    } else {
        errors.addError(errs_.Error{ .basic = .{
            .span = ast.token().span,
            .msg = "invalid sum expression, must be annotation or identifier",
        } });
        return error.parseError;
    }
}
