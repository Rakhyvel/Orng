// Performs local, *simple* expansions on AST nodes

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const primitives_ = @import("primitives.zig");
const token_ = @import("token.zig");

const Expand_Error = error{ParseError};

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
        => try expand(ast.expr(), errors, allocator),

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
                    errors.add_error(errs_.Error{
                        .sum_duplicate = .{ .span = term.token().span, .identifier = name, .first = _res.value.token().span },
                    });
                    return error.ParseError;
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
        .array_of => {
            try expand(ast.expr(), errors, allocator);
            try expand(ast.array_of.len, errors, allocator);
        },
        .sub_slice => {
            if (ast.sub_slice.lower == null) {
                ast.sub_slice.lower = ast_.AST.create_int(ast.token(), 0, allocator);
            }
            if (ast.sub_slice.upper == null) {
                const length = ast_.AST.create_field(token_.Token.init("length", null, "", "", 0, 0), allocator);
                ast.sub_slice.upper = ast_.AST.create_select(
                    ast.token(),
                    ast.sub_slice.super,
                    length,
                    allocator,
                );
            }

            try expand(ast.sub_slice.super, errors, allocator);
            try expand(ast.sub_slice.lower, errors, allocator);
            try expand(ast.sub_slice.upper, errors, allocator);
        },
        .annotation => {
            try expand(ast.annotation.type, errors, allocator);
            try expand(ast.annotation.predicate, errors, allocator);
            try expand(ast.annotation.init, errors, allocator);
        },

        .@"if" => {
            try expand(ast.@"if".let, errors, allocator);
            try expand(ast.@"if".condition, errors, allocator);
            try expand(ast.@"if".body_block, errors, allocator);
            try expand(ast.@"if".else_block, errors, allocator);
        },
        .match => {
            try expand(ast.match.let, errors, allocator);
            try expand(ast.expr(), errors, allocator);
            try expand_from_list(ast.children().*, errors, allocator);
        },
        .mapping => {
            try expand(ast.lhs(), errors, allocator);
            try expand(ast.rhs(), errors, allocator);
        },
        .@"while" => {
            try expand(ast.@"while".let, errors, allocator);
            try expand(ast.@"while".condition, errors, allocator);
            try expand(ast.@"while".post, errors, allocator);
            try expand(ast.@"while".body_block, errors, allocator);
            try expand(ast.@"while".else_block, errors, allocator);
        },
        .@"for" => {
            try expand(ast.@"for".let, errors, allocator);
            try expand(ast.@"for".elem, errors, allocator);
            try expand(ast.@"for".iterable, errors, allocator);
            try expand(ast.@"for".body_block, errors, allocator);
            try expand(ast.@"for".else_block, errors, allocator);
        },
        .block => {
            try expand_from_list(ast.children().*, errors, allocator);
            if (ast.block.final) |final| {
                try expand(final, errors, allocator);
            }
        },

        .@"return" => try expand(ast.@"return"._ret_expr, errors, allocator),
        .decl => {
            try expand(ast.decl.type, errors, allocator);
            try expand(ast.decl.init, errors, allocator);
        },
        .fn_decl => {
            try expand(ast.fn_decl.init, errors, allocator);
            try expand_from_list(ast.children().*, errors, allocator);
            try expand(ast.fn_decl.ret_type, errors, allocator);
        },
        .@"defer", .@"errdefer" => try expand(ast.statement(), errors, allocator),
    }
}

fn annot_from_ast(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST { // TODO: Uninfer error
    if (ast.* == .annotation) {
        return ast;
    } else if (ast.* == .identifier) {
        return ast_.AST.create_annotation(ast.token(), ast, primitives_.unit_type, null, null, allocator).assert_valid();
    } else {
        errors.add_error(errs_.Error{ .basic = .{
            .span = ast.token().span,
            .msg = "invalid sum expression, must be annotation or identifier",
        } });
        return error.ParseError;
    }
}
