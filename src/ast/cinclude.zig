//! This file represents a struct for an AST walk, and walks over the top-level AST of a module and collects the
//! cincludes from it.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const module_ = @import("../hierarchy/module.zig");
const walker_ = @import("../ast/walker.zig");

cincludes: *std.ArrayList(*ast_.AST),

const Self = @This();

/// Creates a new Cinclude walker
pub fn new(cincludes: *std.ArrayList(*ast_.AST)) Self {
    return Self{ .cincludes = cincludes };
}

/// Walks the AST and collects cincludes into the module
pub fn flat(self: Self, ast: *ast_.AST, asts: *std.ArrayList(*ast_.AST), idx: usize) walker_.Error!usize {
    _ = asts;
    _ = idx;
    if (ast.* == .cinclude) {
        self.cincludes.append(ast.expr()) catch unreachable;
    }

    return 0;
}
