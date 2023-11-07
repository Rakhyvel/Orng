const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");
const Span = @import("span.zig").Span;

const AST = _ast.AST;
const CFG = ir_.CFG;
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

/// This structure represents the entire program being compiled.
pub const Program = struct {
    // A unique identifier for this Orng program
    uid: i128,

    // A graph of type dependencies
    types: std.ArrayList(*DAG),

    // Flat list of instructions
    instructions: std.ArrayList(*ir_.IR),

    // Interned strings
    interned_strings: *std.ArrayList([]const u8),

    // The prelude scope node
    prelude: *Scope,

    // Errors, used as context
    errors: *errs.Errors,

    // Allocator for the program
    allocator: std.mem.Allocator,

    pub fn init(uid: i128, interned_strings: *std.ArrayList([]const u8), prelude: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !*Program {
        var retval = try allocator.create(Program);
        retval.uid = uid;
        retval.interned_strings = interned_strings;
        retval.prelude = prelude;
        retval.errors = errors;
        retval.allocator = allocator;
        retval.instructions = std.ArrayList(*ir_.IR).init(allocator);
        retval.types = std.ArrayList(*DAG).init(allocator);
        return retval;
    }

    pub fn append_instructions(self: *Program, cfg: *CFG) !i128 {
        if (cfg.offset != null) {
            return cfg.offset.?;
        }
        cfg.offset = try self.append_basic_block(cfg.block_graph_head.?);
        for (cfg.children.items) |child| {
            _ = try self.append_instructions(child);
        }
        return cfg.offset.?;
    }

    /// Appends the instructions in a BasicBlock to the program's instructions.
    /// Returns the offset of the basic block
    fn append_basic_block(self: *Program, first_bb: *ir_.BasicBlock) !i128 {
        var work_queue = std.ArrayList(*ir_.BasicBlock).init(self.allocator);
        defer work_queue.deinit();
        try work_queue.append(first_bb);

        while (work_queue.items.len > 0) {
            var bb = work_queue.orderedRemove(0); // Youch!

            if (bb.offset != null) {
                continue;
            }

            bb.offset = self.instructions.items.len;
            var label = try ir_.IR.createLabel(bb.uid, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator);
            label.uid = bb.uid;
            try self.instructions.append(label);

            var maybe_ir = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                try self.instructions.append(ir);
            }

            if (bb.has_branch) {
                if (bb.next) |next| {
                    try work_queue.append(next);
                }
                if (bb.branch) |branch| {
                    try work_queue.append(branch);
                }
                try self.instructions.append(try ir_.IR.create_branch_addr(bb.condition.?, bb.next, bb.branch, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator));
            } else {
                if (bb.next) |next| {
                    try work_queue.append(next);
                }
                try self.instructions.append(try ir_.IR.create_jump_addr(bb.next, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator));
            }
        }
        return first_bb.offset.?;
    }

    fn create_jump_addr_uid(self: *Program, bb: ?*ir_.BasicBlock) error{OutOfMemory}!struct { addr: ?i128, uid: ?u64 } {
        var addr: ?i128 = undefined;
        var uid: ?u64 = undefined;
        if (bb != null) {
            addr = try self.append_basic_block(bb.?);
            uid = bb.?.uid;
        } else {
            addr = null;
            uid = null;
        }
        return .{ .addr = addr, .uid = uid };
    }

    pub fn print_instructions(self: *Program) void {
        for (self.instructions.items) |ir| {
            std.debug.print("{}", .{ir});
        }
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
