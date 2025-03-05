//! This file defines the type depenency node struct, which is used to represent a type in a type set. The
//! Dependency_Node is used to store the dependencies between types, and is used to generate a topological sort of the
//! types. This is used to generate types in C in a way that doesn't require forward declarations.

const std = @import("std");
const ast_ = @import("ast.zig");

const Self = @This();

base: *ast_.AST,
uid: usize,
dependencies: std.ArrayList(*Self),
visited: bool,

pub fn init(base: *ast_.AST, uid: usize, allocator: std.mem.Allocator) *Self {
    var retval = allocator.create(Self) catch unreachable;
    retval.base = base;
    retval.uid = uid;
    retval.dependencies = std.ArrayList(*Self).init(allocator);
    retval.visited = false;
    return retval;
}

pub fn add_dependency(self: *Self, dependency: *Self) void {
    self.dependencies.append(dependency) catch unreachable;
}

pub fn mark_visited(self: *Self) void {
    self.visited = true;
}

fn print(self: *Self) void {
    std.debug.print("{} <= ", .{self.uid});
    for (self.dependencies.items) |dep| {
        std.debug.print("{} ", .{dep.uid});
    }
    std.debug.print("\n", .{});
}
