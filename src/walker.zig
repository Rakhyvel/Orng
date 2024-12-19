const std = @import("std");
const ast_ = @import("ast.zig");

pub const Error = error{CompileError};

pub fn Pass(comptime ctx: type) type {
    return *const fn (*ast_.AST, ctx) Error!ctx;
}

pub fn walk_asts(asts: std.ArrayList(*ast_.AST), context: anytype, pass: Pass(@TypeOf(context))) Error!void {
    for (asts.items) |ast| {
        try walk_ast(ast, context, pass);
    }
}

// A function that walks over an AST, applying pass's function to each one
pub fn walk_ast(maybe_ast: ?*ast_.AST, context: anytype, pass: Pass(@TypeOf(context))) Error!void {
    if (maybe_ast == null) {
        return;
    }
    const ast = maybe_ast.?;
    const new_context = try pass(ast, context);

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
        => {},

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
        => try walk_ast(ast.expr(), new_context, pass),

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
            try walk_ast(ast.lhs(), new_context, pass);
            try walk_ast(ast.rhs(), new_context, pass);
        },
        .invoke => {
            try walk_ast(ast.lhs(), new_context, pass);
            try walk_ast(ast.rhs(), new_context, pass);
            try walk_asts(ast.children().*, new_context, pass);
        },
        .call => {
            try walk_ast(ast.lhs(), new_context, pass);
            try walk_asts(ast.children().*, new_context, pass);
        },
        .sum_type, .product => try walk_asts(ast.children().*, new_context, pass),
        .sum_value => {
            try walk_ast(ast.sum_value.init, new_context, pass);
            try walk_ast(ast.sum_value.base, new_context, pass);
        },
        .array_of => {
            try walk_ast(ast.expr(), new_context, pass);
            try walk_ast(ast.array_of.len, new_context, pass);
        },
        .sub_slice => {
            try walk_ast(ast.sub_slice.super, new_context, pass);
            try walk_ast(ast.sub_slice.lower, new_context, pass);
            try walk_ast(ast.sub_slice.upper, new_context, pass);
        },
        .annotation => {
            try walk_ast(ast.annotation.type, new_context, pass);
            try walk_ast(ast.annotation.predicate, new_context, pass);
            try walk_ast(ast.annotation.init, new_context, pass);
        },
        .@"if" => {
            try walk_ast(ast.@"if".let, new_context, pass);
            try walk_ast(ast.@"if".condition, new_context, pass);
            try walk_ast(ast.body_block(), new_context, pass);
            try walk_ast(ast.else_block(), new_context, pass);
        },
        .match => {
            try walk_ast(ast.match.let, new_context, pass);
            try walk_ast(ast.expr(), new_context, pass);
            try walk_asts(ast.children().*, new_context, pass);
        },
        .mapping => {
            try walk_ast(ast.lhs(), new_context, pass);
            try walk_ast(ast.rhs(), new_context, pass);
        },
        .@"while" => {
            try walk_ast(ast.@"while".let, new_context, pass);
            try walk_ast(ast.@"while".condition, new_context, pass);
            try walk_ast(ast.@"while".post, new_context, pass);
            try walk_ast(ast.body_block(), new_context, pass);
            try walk_ast(ast.else_block(), new_context, pass);
        },
        .@"for" => {
            try walk_ast(ast.@"for".let, new_context, pass);
            try walk_ast(ast.@"for".elem, new_context, pass);
            try walk_ast(ast.@"for".iterable, new_context, pass);
            try walk_ast(ast.body_block(), new_context, pass);
            try walk_ast(ast.else_block(), new_context, pass);
        },
        .block => {
            // std.debug.print("{}\n", .{ast.token().span}, pass);
            try walk_asts(ast.children().*, new_context, pass);
            if (ast.block.final) |final| {
                try walk_ast(final, new_context, pass);
            }
        },
        .@"return" => try walk_ast(ast.@"return"._ret_expr, new_context, pass),
        .decl => {
            try walk_ast(ast.decl.type, new_context, pass);
            try walk_ast(ast.decl.init, new_context, pass);
            for (ast.decl.symbols.items) |symbol| {
                symbol.defined = true;
            }
        },
        .fn_decl => {
            try walk_ast(ast.fn_decl.init, new_context, pass);
            try walk_asts(ast.children().*, new_context, pass);
            try walk_ast(ast.fn_decl.ret_type, new_context, pass);
        },
        .trait => {
            try walk_asts(ast.trait.method_decls, new_context, pass);
            try walk_asts(ast.trait.const_decls, new_context, pass);
        },
        .impl => {
            try walk_ast(ast.impl._type, new_context, pass);
            try walk_ast(ast.impl.trait, new_context, pass);
            try walk_asts(ast.impl.method_defs, new_context, pass);
            try walk_asts(ast.impl.const_defs, new_context, pass);
        },
        .method_decl => {
            try walk_ast(ast.method_decl.init, new_context, pass);
            try walk_asts(ast.children().*, new_context, pass);
            try walk_ast(ast.method_decl.ret_type, new_context, pass);
        },
        .@"defer", .@"errdefer" => try walk_ast(ast.statement(), new_context, pass),
    }
}
