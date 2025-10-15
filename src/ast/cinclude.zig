//! This file represents a struct for an AST walk, and walks over the top-level AST of a module and collects the
//! cincludes from it.

const std = @import("std");
const Ast_Id = @import("ast_store.zig").Ast_Id;
const ast_ = @import("../ast/ast.zig");
const module_ = @import("../hierarchy/module.zig");
const walker_ = @import("../ast/walker.zig");

cincludes: *std.array_list.Managed(Ast_Id),

const Self = @This();

/// Creates a new Cinclude walker
pub fn new(cincludes: *std.array_list.Managed(Ast_Id)) Self {
    return Self{ .cincludes = cincludes };
}

/// Walks the AST and collects cincludes into the module
pub fn flat(self: Self, ast_id: Ast_Id, asts: *std.array_list.Managed(Ast_Id), idx: usize) walker_.Error!usize {
    _ = asts;
    _ = idx;
    const ast = self.ctx.ast_store.get(ast_id);
    if (ast.* == .cinclude) {
        self.cincludes.append(ast.expr()) catch unreachable;
    }

    return 0;
}
