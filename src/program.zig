const _ast = @import("ast.zig");
const std = @import("std");

const AST = _ast.AST;
const CFG = @import("ir.zig").CFG;

pub const DAG = struct {
    base: *AST,
    uid: usize,
    dependencies: std.ArrayList(*DAG),
    visited: bool,

    fn init(base: *AST, uid: usize, allocator: std.mem.Allocator) !*DAG {
        var retval = try allocator.create(DAG);
        retval.base = base;
        retval.uid = uid;
        retval.dependencies = std.ArrayList(*DAG).init(allocator);
        retval.visited = false;
        return retval;
    }
};

/// This structure represents the entire program being compiled
pub const Program = struct {
    // CFG node of entry program point
    callGraph: *CFG,

    // A unique identifier for the event of compiling this Orng program
    uid: i64,

    // A graph of type dependencies
    types: std.ArrayList(*DAG),

    // A map of includes (key? Or is it really a set)

    // A map of filenames to lists of lines

    pub fn init(callGraph: *CFG, allocator: std.mem.Allocator) !*Program {
        var retval = try allocator.create(Program);
        retval.callGraph = callGraph;
        retval.uid = std.time.timestamp();
        retval.types = std.ArrayList(*DAG).init(allocator);
        return retval;
    }
};

pub fn collectTypes(callGraph: *CFG, set: *std.ArrayList(*DAG), allocator: std.mem.Allocator) !void {
    if (callGraph.visited) {
        return;
    }
    callGraph.visited = true;
    _ = try typeSetAppend(callGraph.symbol._type.?, set, allocator);
    for (callGraph.basic_blocks.items) |bb| {
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and ir.dest.?.symbol._type != null) {
                _ = try typeSetAppend(ir.dest.?.symbol._type.?, set, allocator);
            }
        }
    }
    for (callGraph.children.items) |child| {
        try collectTypes(child, set, allocator);
    }
}

fn typeSetAppend(ast: *AST, set: *std.ArrayList(*DAG), allocator: std.mem.Allocator) !?*DAG {
    if (typeSetGet(ast, set)) |dag| {
        return dag;
    } else {
        var dag = try DAG.init(ast, set.items.len, allocator);
        try set.append(dag);

        if (ast.* == .function) {
            if (try typeSetAppend(ast.function.lhs, set, allocator)) |domain| {
                try dag.dependencies.append(domain);
            }
            if (try typeSetAppend(ast.function.rhs, set, allocator)) |codomain| {
                try dag.dependencies.append(codomain);
            }
        } else if (ast.* == .product) {
            for (ast.product.terms.items) |term| {
                if (try typeSetAppend(term, set, allocator)) |dependency| {
                    try dag.dependencies.append(dependency);
                }
            }
        }
        return dag;
    }
}

pub fn typeSetGet(ast: *AST, set: *std.ArrayList(*DAG)) ?*DAG {
    for (set.items) |dag| {
        if (dag.base.typesMatch(ast)) {
            return dag;
        }
    }
    return null;
}
