const std = @import("std");
const ast_ = @import("ast.zig");

pub const Error = error{CompileError};

pub fn Pass(comptime ctx: type) type {
    return *const fn (*ast_.AST, ctx) Error!ctx;
}

pub fn walk_asts(asts: std.ArrayList(*ast_.AST), context: anytype) Error!void {
    for (asts.items) |ast| {
        try walk_ast(ast, context);
    }
}

pub fn walk_asts_flat(asts: *std.ArrayList(*ast_.AST), context: anytype) Error!void {
    var i: usize = 0;
    while (i < asts.items.len) : (i += 1) {
        const ast = asts.items[i];
        i += try context.flat(ast, asts, i);
    }
}

// A function that walks over an AST, applying prefix, postfix's function to each one
pub fn walk_ast(maybe_ast: ?*ast_.AST, context: anytype) Error!void {
    if (maybe_ast == null) {
        return;
    }
    const ast = maybe_ast.?;

    var new_context = context;
    if (@hasDecl(@TypeOf(context), "prefix")) {
        const maybe_new_context = try context.prefix(ast);
        if (maybe_new_context == null) {
            return;
        } else {
            new_context = maybe_new_context.?;
        }
    }

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
        .identifier,
        .import,
        => {},

        .module => std.debug.panic("compiler error: walking over modules not implemented!\n", .{}),

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
        => try walk_ast(ast.expr(), new_context),

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
            try walk_ast(ast.lhs(), new_context);
            try walk_ast(ast.rhs(), new_context);
        },
        .invoke => {
            try walk_ast(ast.lhs(), new_context);
            try walk_ast(ast.rhs(), new_context);
            try walk_asts(ast.children().*, new_context);
        },
        .call => {
            try walk_ast(ast.lhs(), new_context);
            try walk_asts(ast.children().*, new_context);
        },
        .sum_type, .product => try walk_asts(ast.children().*, new_context),
        .sum_value => {
            try walk_ast(ast.sum_value.init, new_context);
            try walk_ast(ast.sum_value.base, new_context);
        },
        .array_of => {
            try walk_ast(ast.expr(), new_context);
            try walk_ast(ast.array_of.len, new_context);
        },
        .sub_slice => {
            try walk_ast(ast.sub_slice.super, new_context);
            try walk_ast(ast.sub_slice.lower, new_context);
            try walk_ast(ast.sub_slice.upper, new_context);
        },
        .annotation => {
            try walk_ast(ast.annotation.type, new_context);
            try walk_ast(ast.annotation.predicate, new_context);
            try walk_ast(ast.annotation.init, new_context);
        },
        .@"if" => {
            try walk_ast(ast.@"if".let, context);
            try walk_ast(ast.@"if".condition, context);
            try walk_ast(ast.body_block(), new_context);
            try walk_ast(ast.else_block(), new_context);
        },
        .match => {
            try walk_ast(ast.match.let, context);
            try walk_ast(ast.expr(), new_context);
            try walk_asts(ast.children().*, new_context);
        },
        .mapping => {
            try walk_ast(ast.lhs(), new_context);
            try walk_ast(ast.rhs(), new_context);
        },
        .@"while" => {
            try walk_ast(ast.@"while".let, new_context);
            try walk_ast(ast.@"while".condition, new_context);
            try walk_ast(ast.@"while".post, new_context);
            try walk_ast(ast.body_block(), new_context);
            try walk_ast(ast.else_block(), new_context);
        },
        .@"for" => {
            try walk_ast(ast.@"for".let, new_context);
            try walk_ast(ast.@"for".elem, new_context);
            try walk_ast(ast.@"for".iterable, new_context);
            try walk_ast(ast.body_block(), new_context);
            try walk_ast(ast.else_block(), new_context);
        },
        .block => {
            try walk_asts(ast.children().*, new_context);
            if (ast.block.final) |final| {
                try walk_ast(final, new_context);
            }
        },
        .@"return" => try walk_ast(ast.@"return"._ret_expr, new_context),
        .decl => {
            try walk_ast(ast.decl.type, new_context);
            try walk_ast(ast.decl.init, new_context);
        },
        .fn_decl => {
            try walk_ast(ast.fn_decl.init, new_context);
            try walk_asts(ast.children().*, new_context);
            try walk_ast(ast.fn_decl.ret_type, new_context);
        },
        .trait => {
            try walk_asts(ast.trait.method_decls, new_context);
            try walk_asts(ast.trait.const_decls, new_context);
        },
        .impl => {
            try walk_ast(ast.impl._type, new_context);
            try walk_ast(ast.impl.trait, context);
            try walk_asts(ast.impl.method_defs, new_context);
            try walk_asts(ast.impl.const_defs, new_context);
        },
        .method_decl => {
            try walk_ast(ast.method_decl.init, new_context);
            try walk_asts(ast.children().*, new_context);
            try walk_ast(ast.method_decl.ret_type, new_context);
        },
        .@"defer", .@"errdefer" => try walk_ast(ast.statement(), new_context),
    }

    if (@hasDecl(@TypeOf(context), "postfix")) {
        try context.postfix(ast);
    }
}
