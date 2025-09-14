//! This file represents a struct for an AST walk, and walks over the AST and performs simple, local expansions on
//! it.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const Token = @import("../lexer/token.zig");
const walk_ = @import("../ast/walker.zig");

errors: *errs_.Errors,
allocator: std.mem.Allocator,

const Self = @This();

pub fn new(errors: *errs_.Errors, allocator: std.mem.Allocator) Self {
    return Self{
        .errors = errors,
        .allocator = allocator,
    };
}

/// Expand ASTs before descending to further children
pub fn prefix(self: Self, ast: *ast_.AST) walk_.Error!?Self {
    switch (ast.*) {
        else => {},

        // TOOD: A pass that ensures that there are no duplicate fields in product and sum types

        .sub_slice => self.expand_subslice(ast),
    }

    return self;
}

fn expand_subslice(self: Self, ast: *ast_.AST) void {
    if (ast.sub_slice.lower == null) {
        ast.sub_slice.lower = ast_.AST.create_int(ast.token(), 0, self.allocator);
    }
    if (ast.sub_slice.upper == null) {
        const length = ast_.AST.create_field(Token.init("length", null, "", "", 0, 0), self.allocator);
        ast.sub_slice.upper = ast_.AST.create_select(
            ast.token(),
            ast.sub_slice.super,
            length,
            self.allocator,
        );
    }
}

fn annot_from_ast(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) walk_.Error!*ast_.AST {
    if (ast.* == .annotation) {
        return ast;
    } else if (ast.* == .identifier) {
        return ast_.AST.create_annotation(ast.token(), ast, prelude_.unit_type, null, null, allocator).assert_ast_valid();
    } else {
        errors.add_error(errs_.Error{ .basic = .{
            .span = ast.token().span,
            .msg = "invalid sum expression, must be annotation or identifier",
        } });
        return error.CompileError;
    }
}
