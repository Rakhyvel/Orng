//! This file represents a struct for an AST walk, and walks over the AST and performs simple, local expansions on
//! it.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Ast_Id = @import("ast_store.zig").Ast_Id;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const Token = @import("../lexer/token.zig");
const walk_ = @import("../ast/walker.zig");

ctx: *Compiler_Context,

const Self = @This();

pub fn new(ctx: *Compiler_Context) Self {
    return Self{ .ctx = ctx };
}

/// Expand ASTs before descending to further children
pub fn prefix(self: Self, ast_id: Ast_Id) walk_.Error!?Self {
    const ast = self.ctx.ast_store.get(ast_id);
    switch (ast.*) {
        else => {},

        // TOOD: A pass that ensures that there are no duplicate fields in product and sum types

        .sub_slice => self.expand_subslice(ast),
    }

    return self;
}

fn expand_subslice(self: Self, ast_id: Ast_Id) void {
    const ast = self.ctx.ast_store.get(ast_id);
    if (ast.sub_slice.lower == null) {
        ast.sub_slice.lower = self.ctx.ast_store.add(.{ .int = .{
            ._token = ast.token(),
            .data = 0,
        } });
    }
    if (ast.sub_slice.upper == null) {
        const length = self.ctx.ast_store.add(.{ .field = .{
            ._token = Token.init("length", null, "", "", 0, 0),
        } });
        ast.sub_slice.upper = self.ctx.ast_store.add(.{ .select = .{
            ._token = ast.token(),
            ._lhs = ast.sub_slice.super,
            ._rhs = length,
        } });
    }
}
