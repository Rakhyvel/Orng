//! This file represents a struct for an AST walk, and walks over the top-level AST of a module and collects the
//! cincludes from it.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const module_ = @import("../hierarchy/module.zig");
const walker_ = @import("../ast/walker.zig");

module: *module_.Module,

const Self = @This();

/// Creates a new Cinclude walker
pub fn new(module: *module_.Module) Self {
    return Self{ .module = module };
}

/// Walks the AST and collects cincludes into the module
pub fn flat(self: Self, ast: *ast_.AST, asts: *std.ArrayList(*ast_.AST), idx: usize) walker_.Error!usize {
    _ = asts;
    _ = idx;
    if (ast.* == .cinclude) {
        self.module.cincludes.append(ast.expr()) catch unreachable;
    }

    return 0;
}
