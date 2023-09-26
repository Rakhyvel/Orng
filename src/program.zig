const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");

const AST = _ast.AST;
const CFG = @import("ir.zig").CFG;
const Scope = _symbol.Scope;

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

    // A unique identifier for this Orng program
    uid: i128,

    // A graph of type dependencies
    types: std.ArrayList(*DAG),

    // TODO: Make this a map from filename -> lines
    lines: *std.ArrayList([]const u8),

    // Interned strings
    interned_strings: *std.ArrayList([]const u8),

    // The prelude scope node
    prelude: *Scope,

    // Errors, used as context
    errors: *errs.Errors,

    // Allocator for the program
    allocator: std.mem.Allocator,

    pub fn init(callGraph: *CFG, uid: i128, interned_strings: *std.ArrayList([]const u8), prelude: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !*Program {
        var retval = try allocator.create(Program);
        retval.callGraph = callGraph;
        retval.uid = uid;
        retval.interned_strings = interned_strings;
        retval.prelude = prelude;
        retval.errors = errors;
        retval.allocator = allocator;
        retval.types = std.ArrayList(*DAG).init(allocator);
        return retval;
    }
};

pub fn collectTypes(callGraph: *CFG, set: *std.ArrayList(*DAG), scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    if (callGraph.visited) {
        return;
    }
    callGraph.visited = true;

    // Add parameter types to type set
    if (callGraph.symbol._type.?.function.lhs.* == .product) {
        // Function has more than one parameter, add types of product terms
        for (callGraph.symbol._type.?.function.lhs.product.terms.items) |param_type| {
            _ = try typeSetAppend(param_type, set, scope, errors, allocator);
        }
    } else {
        // Function has one parameter, add it's type
        _ = try typeSetAppend(callGraph.symbol._type.?.function.lhs, set, scope, errors, allocator);
    }

    for (callGraph.basic_blocks.items) |bb| {
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and ir.dest.?.symbol._type != null) {
                _ = try typeSetAppend(ir.dest.?.symbol._type.?, set, scope, errors, allocator);
            }
        }
    }
    for (callGraph.children.items) |child| {
        try collectTypes(child, set, scope, errors, allocator);
    }
}

fn typeSetAppend(old_ast: *AST, set: *std.ArrayList(*DAG), scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !?*DAG {
    var ast = try old_ast.expand_type(scope, errors, allocator);
    if (try typeSetGet(ast, set, scope, errors, allocator)) |dag| {
        // Type is already in the set, return DAG entry for it
        return dag;
    } else if (ast.* == .function) {
        var dag = try DAG.init(ast, set.items.len, allocator);
        try set.append(dag);
        if (try typeSetAppend(ast.function.lhs, set, scope, errors, allocator)) |domain| {
            try dag.dependencies.append(domain);
        }
        if (try typeSetAppend(ast.function.rhs, set, scope, errors, allocator)) |codomain| {
            try dag.dependencies.append(codomain);
        }
        return dag;
    } else if (ast.* == .product) {
        var dag = try DAG.init(ast, set.items.len, allocator);
        try set.append(dag);
        for (ast.product.terms.items) |term| {
            if (try typeSetAppend(term, set, scope, errors, allocator)) |dependency| {
                try dag.dependencies.append(dependency);
            }
        }
        return dag;
    } else if (ast.* == .sum) {
        var dag = try DAG.init(ast, set.items.len, allocator);
        try set.append(dag);
        for (ast.sum.terms.items) |term| {
            if (try typeSetAppend(term, set, scope, errors, allocator)) |dependency| {
                try dag.dependencies.append(dependency);
            }
        }
        return dag;
    } else if (ast.* == .annotation) {
        return try typeSetAppend(ast.annotation.type, set, scope, errors, allocator);
    } else {
        return null;
    }
}

pub fn typeSetGet(old_ast: *AST, set: *std.ArrayList(*DAG), scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !?*DAG {
    var ast = try old_ast.expand_type(scope, errors, allocator);
    for (set.items) |dag| {
        if (dag.base.c_typesMatch(ast)) {
            return dag;
        }
    }
    return null;
}

pub fn interned_string_set_add(str: []const u8, set: *std.ArrayList([]const u8)) !void {
    for (set.items) |item| {
        if (std.mem.eql(u8, item, str)) {
            return;
        }
    }
    // sanitized_str must not be in set, add it
    try set.append(str);
}
