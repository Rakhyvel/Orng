//! This file defines type sets and directed acyclic graphs (Dependency_Nodes) for types. The type set is used to store types based
//! on their C-equivalence.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Dependency_Node = @import("dependency_node.zig");

const Self = @This();

types: std.ArrayList(*Dependency_Node),

pub fn init(allocator: std.mem.Allocator) Self {
    return Self{ .types = std.ArrayList(*Dependency_Node).init(allocator) };
}

pub fn deinit(self: *Self) void {
    self.types.deinit();
}

pub fn add(self: *Self, oldast_: *ast_.AST, allocator: std.mem.Allocator) ?*Dependency_Node {
    const ast = oldast_.expand_type(allocator);
    if (self.get(ast)) |dag| {
        // Type is already in the set, return Dependency_Node entry for it
        return dag;
    }
    switch (ast.*) {
        .function => {
            var dag = Dependency_Node.init(ast, self.types.items.len, allocator);
            self.types.append(dag) catch unreachable;
            if (self.add(ast.lhs(), allocator)) |domain| {
                dag.add_dependency(domain);
            }
            if (self.add(ast.rhs(), allocator)) |codomain| {
                dag.add_dependency(codomain);
            }
            return dag;
        },
        .product, .sum_type, .untagged_sum_type => {
            var dag = Dependency_Node.init(ast, self.types.items.len, allocator);
            self.types.append(dag) catch unreachable;
            for (ast.children().items) |term| {
                if (self.add(term, allocator)) |dependency| {
                    if (term.* != .addr_of)
                        dag.add_dependency(dependency);
                }
            }
            return dag;
        },
        .dyn_type => {
            const dag = Dependency_Node.init(ast, self.types.items.len, allocator);
            self.types.append(dag) catch unreachable;
            return dag;
        },
        .annotation => {
            return self.add(ast.annotation.type, allocator);
        },
        .addr_of => {
            // return self.add(ast.expr(), allocator);
            return null;
        },
        .identifier, .unit_type, .anyptr_type => {
            // Do not add to Dependency_Node
            return null;
        },
        else => {
            std.debug.panic("unknown: {}", .{ast});
            return null;
        },
    }
}

pub fn get(self: *Self, oldast_: *ast_.AST) ?*Dependency_Node {
    const ast = oldast_;
    for (self.types.items) |dag| {
        if (dag.base.c_types_match(ast)) {
            return dag;
        }
    }
    return null;
}

pub fn print(self: *Self) void {
    for (self.types.items) |dag| {
        dag.print();
    }
}
