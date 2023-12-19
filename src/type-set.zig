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

    pub fn add(self: *Type_Set, oldast_: *ast_.AST, allocator: std.mem.Allocator) !?*DAG {
        const ast = oldast_;
        if (self.get(ast)) |dag| {
            // Type is already in the set, return DAG entry for it
            return dag;
        } else if (ast.* == .function) {
            var dag = try DAG.init(ast, self.types.items.len, allocator);
            try self.types.append(dag);
            if (try self.add(ast.function.lhs, allocator)) |domain| {
                try dag.dependencies.append(domain);
            }
            if (try self.add(ast.function.rhs, allocator)) |codomain| {
                try dag.dependencies.append(codomain);
            }
            return dag;
        } else if (ast.* == .product) {
            var dag = try DAG.init(ast, self.types.items.len, allocator);
            try self.types.append(dag);
            for (ast.product.terms.items) |term| {
                if (try self.add(term, allocator)) |dependency| {
                    try dag.dependencies.append(dependency);
                }
            }
            return dag;
        } else if (ast.* == .sum) {
            var dag = try DAG.init(ast, self.types.items.len, allocator);
            try self.types.append(dag);
            for (ast.sum.terms.items) |term| {
                if (try self.add(term, allocator)) |dependency| {
                    try dag.dependencies.append(dependency);
                }
            }
            return dag;
        } else if (ast.* == .annotation) {
            return try self.add(ast.annotation.type, allocator);
        } else if (ast.* == .addrOf) {
            return try self.add(ast.addrOf.expr, allocator);
        } else {
            return null;
        }
    }

    pub fn get(self: *Type_Set, oldast_: *ast_.AST) ?*DAG {
        const ast = oldast_;
        for (self.types.items) |dag| {
            if (dag.base.c_typesMatch(ast)) {
                return dag;
            }
        }
        return null;
    }
};

pub const DAG = struct {
    base: *ast_.AST,
    uid: usize,
    dependencies: std.ArrayList(*DAG),
    visited: bool,

    fn init(base: *ast_.AST, uid: usize, allocator: std.mem.Allocator) !*DAG {
        var retval = try allocator.create(DAG);
        retval.base = base;
        retval.uid = uid;
        retval.dependencies = std.ArrayList(*DAG).init(allocator);
        retval.visited = false;
        return retval;
    }
};
