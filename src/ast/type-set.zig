//! This file defines type sets and directed acyclic graphs (Dependency_Nodes) for types. The type set is used to store types based
//! on their C-equivalence.

const std = @import("std");
const Dependency_Node = @import("dependency_node.zig");
const Type_AST = @import("../types/type.zig").Type_AST;

const Self = @This();

types: std.array_list.Managed(*Dependency_Node),
allocator: std.mem.Allocator,

pub fn init(allocator: std.mem.Allocator) Self {
    return Self{ .types = std.array_list.Managed(*Dependency_Node).init(allocator), .allocator = allocator };
}

pub fn deinit(self: *Self) void {
    self.types.deinit();
}

/// Adds a type to the type set. Returns the dependency node for the corresponding type
pub fn add(self: *Self, oldast_: *Type_AST) ?*Dependency_Node {
    const ast = oldast_.expand_identifier();
    if (ast.* == .identifier and ast.symbol().?.decl.?.* == .type_param_decl) {
        unreachable;
    }
    if (self.get(ast)) |dag| {
        // Type is already in the set, return Dependency_Node entry for it
        return dag;
    }

    // Type wasn't in the set, so we'll need to create a Dependency_Node for it and its children
    switch (ast.*) {
        .function => return self.add_function(ast),
        .struct_type, .tuple_type, .enum_type, .untagged_sum_type => return self.add_aggregate(ast),
        .dyn_type => return self.add_dependency_node(ast),
        .annotation => return self.add(ast.child()),
        .addr_of => {
            _ = self.add(ast.child()); // Add child to set, but do not create a node for addrs
            return null;
        },
        .array_of => return self.add_array(ast),
        .identifier, .unit_type, .anyptr_type => return null, // Do not add to Dependency_Node
        else => std.debug.panic("unknown: {f}", .{ast}),
    }
}

/// Adds a function type to the type set
fn add_function(self: *Self, function_type_ast: *Type_AST) ?*Dependency_Node {
    var dag = self.add_dependency_node(function_type_ast);
    if (self.add(function_type_ast.lhs())) |domain| {
        dag.add_dependency(domain);
    }
    if (self.add(function_type_ast.rhs())) |codomain| {
        dag.add_dependency(codomain);
    }
    return dag;
}

/// Adds an aggregate type (product, sum) to the type set
fn add_aggregate(self: *Self, aggregate_ast: *Type_AST) ?*Dependency_Node {
    var dag = self.add_dependency_node(aggregate_ast);
    for (aggregate_ast.children().items) |term| {
        if (self.add(term)) |dependency| {
            if (term.* != .addr_of)
                dag.add_dependency(dependency);
        }
    }
    return dag;
}

/// Adds a function type to the type set
fn add_array(self: *Self, array_type_ast: *Type_AST) ?*Dependency_Node {
    var dag = self.add_dependency_node(array_type_ast);
    if (self.add(array_type_ast.child())) |domain| {
        dag.add_dependency(domain);
    }
    return dag;
}

/// Retrieves the dependency node from the type set given a type
pub fn get(self: *const Self, oldast_: *Type_AST) ?*Dependency_Node {
    std.debug.print("find {f} ... ", .{oldast_});
    const ast = oldast_.expand_identifier();
    for (self.types.items) |dag| {
        if (dag.base.c_types_match(ast)) {
            std.debug.print("FOUND!\n", .{});
            return dag;
        }
    }
    std.debug.print("NOT FOUND!\n", .{});
    return null;
}

/// Debug function to print out the type set
pub fn print(self: *Self) void {
    for (self.types.items) |dag| {
        dag.print();
    }
}

fn add_dependency_node(self: *Self, ast: *Type_AST) *Dependency_Node {
    const dag = Dependency_Node.init(ast, self.types.items.len, self.allocator);
    self.types.append(dag) catch unreachable;
    return dag;
}

pub fn len(self: *const Self) usize {
    return self.types.items.len;
}
