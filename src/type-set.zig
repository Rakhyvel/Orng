const std = @import("std");
const ast_ = @import("ast.zig");

pub const Type_Set = struct {
    types: std.ArrayList(*DAG),

    pub fn init(allocator: std.mem.Allocator) Type_Set {
        return Type_Set{ .types = std.ArrayList(*DAG).init(allocator) };
    }

    pub fn deinit(self: *Type_Set) void {
        self.types.deinit();
    }

    pub fn add(self: *Type_Set, oldast_: *ast_.AST, allocator: std.mem.Allocator) ?*DAG {
        const ast = oldast_.expand_type(allocator);
        if (self.get(ast)) |dag| {
            // Type is already in the set, return DAG entry for it
            return dag;
        }
        switch (ast.*) {
            .function => {
                var dag = DAG.init(ast, self.types.items.len, allocator);
                self.types.append(dag) catch unreachable;
                if (self.add(ast.lhs(), allocator)) |domain| {
                    dag.dependencies.append(domain) catch unreachable;
                }
                if (self.add(ast.rhs(), allocator)) |codomain| {
                    dag.dependencies.append(codomain) catch unreachable;
                }
                return dag;
            },
            .product, .sum_type, .untagged_sum_type => {
                var dag = DAG.init(ast, self.types.items.len, allocator);
                self.types.append(dag) catch unreachable;
                for (ast.children().items) |term| {
                    if (self.add(term, allocator)) |dependency| {
                        if (term.* != .addr_of)
                            dag.dependencies.append(dependency) catch unreachable;
                    }
                }
                return dag;
            },
            .dyn_type => {
                const dag = DAG.init(ast, self.types.items.len, allocator);
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
                // Do not add to DAG
                return null;
            },
            else => {
                std.debug.panic("unknown: {}", .{ast});
                return null;
            },
        }
    }

    pub fn get(self: *Type_Set, oldast_: *ast_.AST) ?*DAG {
        const ast = oldast_;
        for (self.types.items) |dag| {
            if (dag.base.c_types_match(ast)) {
                return dag;
            }
        }
        return null;
    }

    pub fn print(self: *Type_Set) void {
        for (self.types.items) |dag| {
            dag.print();
        }
    }
};

pub const DAG = struct {
    base: *ast_.AST,
    uid: usize,
    dependencies: std.ArrayList(*DAG),
    visited: bool,

    fn init(base: *ast_.AST, uid: usize, allocator: std.mem.Allocator) *DAG {
        var retval = allocator.create(DAG) catch unreachable;
        retval.base = base;
        retval.uid = uid;
        retval.dependencies = std.ArrayList(*DAG).init(allocator);
        retval.visited = false;
        return retval;
    }

    fn print(self: *DAG) void {
        std.debug.print("{} <= ", .{self.uid});
        for (self.dependencies.items) |dag| {
            std.debug.print("{} ", .{dag.uid});
        }
        std.debug.print("\n", .{});
    }
};
