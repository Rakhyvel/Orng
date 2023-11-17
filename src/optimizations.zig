const errs = @import("errors.zig");
const _ir = @import("ir.zig");
const std = @import("std");

const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const Error = errs.Error;
const IR = _ir.IR;
const L_Value = _ir.L_Value;
const String = @import("zig-string/zig-string.zig").String;
const Symbol = @import("symbol.zig").Symbol;
const SymbolVersion = _ir.SymbolVersion;

const debug = false;

fn log(msg: []const u8) void {
    if (debug) {
        std.debug.print("{s}\n", .{msg});
    }
}

fn log_optimization_pass(msg: []const u8, cfg: *CFG) void {
    if (debug) {
        std.debug.print("[OPTIMIZATION] {s}\n", .{msg});
        if (cfg.block_graph_head) |block_head| {
            block_head.pprint();
            cfg.clearVisitedBBs();
            log("\n\n");
        } else {
            std.debug.print("[WARNING] block head for CFG: {s} is null\n", .{cfg.symbol.name});
        }
    }
}

pub fn optimize(cfg: *CFG, errors: *errs.Errors, interned_strings: *std.ArrayList([]const u8), allocator: std.mem.Allocator) !void {
    if (debug) {
        std.debug.print("[  CFG  ]: {s}\n", .{cfg.symbol.name});
        cfg.block_graph_head.?.pprint();
        log("\n\n");
    }

    try findUnused(cfg, errors);

    while (try propagate(cfg, interned_strings, errors, allocator) or
        try removeUnusedDefs(cfg, errors) or
        try bbOptimizations(cfg, allocator) or
        try removeUnusedDefs(cfg, errors))
    {}
    cfg.clearVisitedBBs();

    log_optimization_pass("final", cfg);

    try cfg.collect_generated_symbvers();
}

fn bbOptimizations(cfg: *CFG, allocator: std.mem.Allocator) !bool {
    var retval: bool = false;

    countPredecessors(cfg);
    try cfg.calculatePhiParamsAndArgs(allocator);
    calculateVersions(cfg);

    for (cfg.basic_blocks.items) |bb| {
        if (bb.number_predecessors == 0) {
            defer log_optimization_pass("remove unused block", cfg);
            removeBasicBlock(cfg, bb, true);
            return true; // Perhaps mark these and remove them in a sweep pass?
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        // Adopt basic blocks with only one incoming block
        if (bb.next != null and bb.ir_head != null and !bb.has_branch and bb.next.?.number_predecessors == 1) {
            var log_msg = String.init(allocator);
            defer log_msg.deinit();
            try log_msg.writer().print("adopt BB{} into BB{}", .{ bb.next.?.uid, bb.uid });
            defer log_optimization_pass(log_msg.str(), cfg);
            var end: *IR = bb.ir_head.?.getTail();

            // Join next block at the end of this block
            end.next = bb.next.?.ir_head;
            if (bb.next.?.ir_head != null) {
                bb.next.?.ir_head.?.prev = end;
            }

            // Copy basic block end conditions
            bb.has_branch = bb.next.?.has_branch;
            bb.branch = bb.next.?.branch;
            bb.condition = bb.next.?.condition;
            bb.next_arguments = bb.next.?.next_arguments;
            bb.branch_arguments = bb.next.?.branch_arguments;

            var maybe_child: ?*IR = bb.next.?.ir_head;
            while (maybe_child) |child| : (maybe_child = child.next) {
                child.in_block = bb;
            }

            // Remove the next block
            removeBasicBlock(cfg, bb.next.?, false);
            bb.next = bb.next.?.next;
            retval = true;
            break;
        }

        if (bb.has_branch) {
            var latest_condition = bb.condition.?.def; // This is set by propagate
            // Convert constant true/false branches to jumps
            if (latest_condition != null and latest_condition.?.kind == .loadInt) {
                defer log_optimization_pass("convert constant true/false to jumps", cfg);
                bb.has_branch = false;
                if (bb.condition.?.def.?.data.int == 0) {
                    bb.next = bb.branch;
                    bb.next_arguments = bb.branch_arguments;
                }
                retval = true;
            }
            // Flip labels if branch condition is negation, plunge negation
            else if (latest_condition != null and latest_condition.?.kind == .not) {
                defer log_optimization_pass("flip not condition", cfg);
                var old_branch = bb.branch.?;
                bb.branch = bb.next;
                bb.next = old_branch;
                bb.condition = latest_condition.?.src1;
                retval = true;
            }
        }

        // Remove jump chains
        if (bb.next) |next| {
            if (next.ir_head == null and !next.has_branch) {
                var s = String.init(allocator);
                try s.writer().print("remove jump chain BB{}", .{next.uid});
                defer s.deinit();
                defer log_optimization_pass(s.str(), cfg);
                bb.next = next.next;
                retval = true;
            }
        }

        if (bb.branch) |branch| {
            if (branch.ir_head == null and !branch.has_branch) {
                bb.branch = branch.next;
                retval = true;
            }
        }

        if (bb.has_branch and bb.branch == bb.next) {
            bb.has_branch = false;
            retval = true;
        }

        // If next is a branch that depends on a known arugment
        if (bb.next) |next| {
            if (next.has_branch and next.ir_head == null) {
                defer log_optimization_pass("next depends on known argument", cfg);
                var def = bb.get_latest_def(next.condition.?.symbol, null);
                if (def != null and def.?.kind == .loadInt) {
                    if (def.?.data.int == 0) {
                        bb.next = next.branch;
                    } else {
                        bb.next = next.next;
                    }
                }
            }
        }

        // If branch is a branch that depends on a known arugment
        if (bb.has_branch and bb.branch != null and bb.branch.?.has_branch and bb.branch.?.ir_head == null) {
            defer log_optimization_pass("branch depends on known argument", cfg);
            var def = bb.get_latest_def(bb.branch.?.condition.?.symbol, null);
            if (def != null and def.?.kind == .loadInt) {
                if (def.?.data.int == 0) {
                    bb.branch = bb.branch.?.branch;
                } else {
                    bb.branch = bb.branch.?.next;
                }
            }
        }
    }

    // Rebase block graph if jump chain
    if (cfg.block_graph_head) |head| {
        if (head.ir_head == null and !head.has_branch) {
            defer log_optimization_pass("rebase block", cfg);
            cfg.block_graph_head = head.next;
            retval = true;
        }
    }

    if (retval) {
        try cfg.calculatePhiParamsAndArgs(allocator);
    }

    return retval;
}

fn countPredecessors(cfg: *CFG) void {
    for (cfg.basic_blocks.items) |bb| {
        bb.number_predecessors = 0;
    }
    cfg.clearVisitedBBs();
    _countPredecessors(cfg.block_graph_head orelse return);
}

fn _countPredecessors(bb: *BasicBlock) void {
    bb.number_predecessors += 1;
    if (bb.visited) {
        return;
    }
    bb.visited = true;
    if (bb.next) |next| {
        _countPredecessors(next);
    }
    if (bb.has_branch) {
        if (bb.branch) |branch| {
            _countPredecessors(branch);
        }
    }
}

fn removeBasicBlock(cfg: *CFG, bb: *BasicBlock, wipeIR: bool) void {
    var i: usize = 0;
    while (i < cfg.basic_blocks.items.len) : (i += 1) {
        if (bb == cfg.basic_blocks.items[i]) {
            break;
        }
    }
    _ = cfg.basic_blocks.swapRemove(i);
    if (wipeIR) {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            ir.removed = true;
        }
    }
    bb.removed = true;
}

fn propagate(cfg: *CFG, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors, allocator: std.mem.Allocator) !bool {
    var retval = false;

    calculateVersions(cfg);
    calculateUsage(cfg);

    for (cfg.basic_blocks.items) |bb| {
        // For each BB, keep a map of symbol versions and their definitions
        var def_map = std.AutoArrayHashMap(*SymbolVersion, ?*IR).init(allocator);
        defer def_map.deinit();

        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            // Walk through IR in BB, update map of src1 and src2 defs
            var src1_def: ?*IR = if (ir.src1) |src1| def_map.get(src1) orelse null else null;
            var src2_def: ?*IR = if (ir.src2) |src2| def_map.get(src2) orelse null else null;
            retval = try propagateIR(ir, src1_def, src2_def, interned_strings, errors) or retval;

            if (ir.dest != null and ir.dest.?.* != .symbver) {
                try def_map.put(ir.dest.?.extract_symbver(), null);
            } else if (ir.kind == .addrOf) {
                try def_map.put(ir.data.lval.extract_symbver(), null);
            }
            if (ir.dest != null and ir.dest.?.* == .symbver) {
                try def_map.put(ir.dest.?.symbver, ir);
            }
        }
        if (bb.has_branch) {
            var cond_def: ?*IR = def_map.get(bb.condition.?) orelse null;
            bb.condition.?.def = cond_def;
            if (cond_def != null and cond_def.?.kind == .copy) {
                bb.condition = cond_def.?.src1;
                retval = true;
            }
        }
    }

    return retval;
}

fn propagateIR(ir: *IR, src1_def: ?*IR, src2_def: ?*IR, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors) !bool {
    var retval = false;

    switch (ir.kind) {
        .copy => {
            // Unit-copy elimination
            if (ir.src1 == null) {
                log("unit-copy elimination");
                ir.in_block.?.removeInstruction(ir);
            }
            // Self-copy elimination
            else if (ir.dest.?.* == .symbver and ir.dest.?.symbver.symbol == ir.src1.?.symbol and src1_def != null and ir.dest.?.symbver.version == ir.src1.?.version) {
                log("self-copy elimination");
                ir.in_block.?.removeInstruction(ir);
                retval = true;
            }
            // Integer constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadInt) {
                log("integer constant propagation");
                ir.kind = .loadInt;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Float constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadFloat) {
                log("float constant propagation");
                ir.kind = .loadFloat;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // String constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadString) {
                log("string constant propagation");
                ir.kind = .loadString;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Struct constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadStruct and ir.src1.?.uses == 1) {
                log("struct constant propagation");
                ir.kind = .loadStruct;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Union constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadUnion) {
                log("union constant propagation");
                ir.kind = .loadUnion;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                retval = true;
            }
            // Load symbol propagation
            else if (src1_def != null and src1_def.?.kind == .loadSymbol) {
                log("symbol constant propagation");
                ir.kind = .loadSymbol;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                retval = true;
            }
            // Copy propagation
            else if (src1_def != null and src1_def.?.kind == .copy and ir.src1 != src1_def.?.src1.?) {
                log("copy propagation");
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Addrof propagation
            else if (src1_def != null and src1_def.?.kind == .addrOf) {
                log("addrof propagation");
                ir.kind = .addrOf;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                retval = true;
            }
            // Dereference propagation
            else if (src1_def != null and src1_def.?.kind == .dereference) {
                log("dereference propagation");
                ir.kind = .dereference;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                retval = true;
            }
            // Add propagation
            else if (src1_def != null and src1_def.?.kind == .add_int) {
                log("add propagation");
                ir.kind = .add_int;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Add propagation
            else if (src1_def != null and src1_def.?.kind == .add_float) {
                log("add propagation");
                ir.kind = .add_float;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Sub propagation
            else if (src1_def != null and src1_def.?.kind == .sub_int) {
                log("sub propagation");
                ir.kind = .sub_int;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Sub propagation
            else if (src1_def != null and src1_def.?.kind == .sub_float) {
                log("sub propagation");
                ir.kind = .sub_float;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Mult propagation
            else if (src1_def != null and src1_def.?.kind == .mult_int) {
                log("mult propagation");
                ir.kind = .mult_int;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Mult propagation
            else if (src1_def != null and src1_def.?.kind == .mult_float) {
                log("mult propagation");
                ir.kind = .mult_float;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Div propagation
            else if (src1_def != null and src1_def.?.kind == .div_int) {
                log("div propagation");
                ir.kind = .div_int;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Div propagation
            else if (src1_def != null and src1_def.?.kind == .div_float) {
                log("div propagation");
                ir.kind = .div_float;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Mod propagation
            else if (src1_def != null and src1_def.?.kind == .mod) {
                log("mod propagation");
                ir.kind = .mod;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Select propagation
            else if (src1_def != null and src1_def.?.kind == .select) {
                log("select");
                ir.kind = .select;
                ir.data = src1_def.?.data;
                ir.meta = src1_def.?.meta;
                ir.span = src1_def.?.span;
                ir.src2 = src1_def.?.src2;
                ir.safe = src1_def.?.safe;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // DO NOT IMPLEMENT .call => propagation
        },

        .not => {
            // Known int value
            if (src1_def != null and src1_def.?.kind == .loadInt) {
                log("not; known int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int == 0) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .negate_int => {
            // Known int value
            if (src1_def != null and src1_def.?.kind == .loadInt) {
                log("negate_int; known value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = -src1_def.?.data.int };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .negate_float => {
            // Known float value
            if (src1_def != null and src1_def.?.kind == .loadFloat) {
                log("negate_float; known value");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = -src1_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .equal => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("equal; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int == src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("equal; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float == src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `0 == x` => `!x`
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("equal; lhs 0");
                ir.kind = .not;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // `x == 0` => `!x`
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                log("equal; rhs 0");
                ir.kind = .not;
                ir.data = _ir.IRData.none;
                // ir.src1 is already ir.src1
                ir.src2 = null;
                retval = true;
            }
            // `x == x` => `true`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("equal; self equality");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 1 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .not_equal => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("not_equal; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int != src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("not_equal; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float != src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `0 != x` => `x`
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("not_equal; lhs 0");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // `x != 0` => `x`
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                log("not_equal; rhs 0");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                // ir.src1 is already ir.src1
                ir.src2 = null;
                retval = true;
            }
            // `x != x` => `false`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("not_equal; self inequality");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .greater_int => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("greater_int; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int > src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `x > x` => `false`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("greater_int; self compare");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .greater_float => {
            // Known float, float value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("greater_float; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float > src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `x > x` => `false`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("greater_float; self compare");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .lesser_int => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("lesser_int; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int < src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `x < x` => `false`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("lesser_int; self compare");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .lesser_float => {
            // Known float, float value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("lesser_float; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float < src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `x < x` => `false`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("lesser_float; self compare");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .greater_equal_int => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("greater_equal_int; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int >= src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `x >= x` => `true`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("greater_equal_int; self compare");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 1 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .greater_equal_float => {
            // Known float, float value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("greater_equal_float; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float >= src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `x >= x` => `true`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("greater_equal_float; self compare");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 1 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .lesser_equal_int => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("lesser_equal_int; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int <= src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `x <= x` => `true`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("lesser_equal_int; self compare");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 1 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .lesser_equal_float => {
            // Known float, float value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("lesser_equal_float; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float <= src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `x <= x` => `true`
            else if (ir.src1.?.symbol == ir.src2.?.symbol) {
                log("lesser_equal_float; self compare");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 1 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .add_int => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("add_int; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{
                    .int = if (std.math.add(i64, @intCast(src1_def.?.data.int), @intCast(src2_def.?.data.int))) |res| res else |_| {
                        errors.addError(Error{ .basic = .{
                            .span = ir.span,
                            .msg = "addition integer overflow",
                        } });
                        return error.typeError;
                    },
                };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Add 0 lhs
            else if (src1_def != null and src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("add_int; add 0 lhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Add 0 rhs
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                log("add_int; add 0 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .add_float => {
            // Known float, float value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("add_float; known float,float value");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = src1_def.?.data.float + src2_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Add 0 lhs
            else if (src1_def != null and src1_def.?.kind == .loadFloat and src1_def.?.data.float == 0.0) {
                log("add_float; add 0 lhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Add 0 rhs
            else if (src2_def != null and src2_def.?.kind == .loadFloat and src2_def.?.data.float == 0.0) {
                log("add_float; add 0 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .sub_int => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("sub; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{
                    .int = if (std.math.sub(i64, @intCast(src1_def.?.data.int), @intCast(src2_def.?.data.int))) |res| res else |_| {
                        errors.addError(Error{ .basic = .{
                            .span = ir.span,
                            .msg = "subtraction integer overflow",
                        } });
                        return error.typeError;
                    },
                };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Sub 0 lhs
            else if (src1_def != null and src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("sub; sub 0 lhs");
                ir.kind = .negate_int;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Sub 0 rhs
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                log("sub; sub 0 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .sub_float => {
            // Known float, float value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("sub; known float,float value");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = src1_def.?.data.float - src2_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Sub 0 lhs
            else if (src1_def != null and src1_def.?.kind == .loadFloat and src1_def.?.data.float == 0.0) {
                log("sub; sub 0 lhs");
                ir.kind = .negate_float;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Sub 0 rhs
            else if (src2_def != null and src2_def.?.kind == .loadFloat and src2_def.?.data.float == 0.0) {
                log("sub; sub 0 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .mult_int => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{
                    .int = if (std.math.mul(i64, @intCast(src1_def.?.data.int), @intCast(src2_def.?.data.int))) |res| res else |_| {
                        errors.addError(Error{ .basic = .{
                            .span = ir.span,
                            .msg = "multiplication integer overflow",
                        } });
                        return error.typeError;
                    },
                };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Mult 1 lhs int
            else if (src1_def != null and src1_def.?.kind == .loadInt and src1_def.?.data.int == 1) {
                log("mult; mult 1 lhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Mult 1 rhs int
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 1) {
                log("mult; mult 1 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
            // Mult 0 lhs int
            else if (src1_def != null and src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("mult; mult 0 lhs int");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Mult 0 rhs int
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                log("mult; mult 0 rhs int");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .mult_float => {
            // Known float, float value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = src1_def.?.data.float * src2_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Mult 1 lhs int
            else if (src1_def != null and src1_def.?.kind == .loadFloat and src1_def.?.data.float == 1.0) {
                log("mult; mult 1 lhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Mult 1 rhs int
            else if (src2_def != null and src2_def.?.kind == .loadFloat and src2_def.?.data.float == 1.0) {
                log("mult; mult 1 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
            // Mult 0 lhs float
            else if (src1_def != null and src1_def.?.kind == .loadFloat and src1_def.?.data.float == 0.0) {
                log("mult; mult 0 lhs float");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = 0.0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Mult 0 rhs float
            else if (src2_def != null and src2_def.?.kind == .loadFloat and src2_def.?.data.float == 0.0) {
                log("mult; mult 0 rhs float");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = 0.0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .div_int => {
            // Static check; divide by 0
            if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                errors.addError(Error{ .basic = .{
                    .span = src2_def.?.span,
                    .msg = "divide by 0",
                } });
                return error.typeError;
            }
            // Known int, int value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = @divTrunc(src1_def.?.data.int, src2_def.?.data.int) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Div 1 rhs
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 1) {
                log("div; div 1 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .div_float => {
            // Static check; divide by 0.0
            if (src2_def != null and src2_def.?.kind == .loadFloat and src2_def.?.data.float == 0) {
                errors.addError(Error{ .basic = .{
                    .span = src2_def.?.span,
                    .msg = "divide by 0",
                } });
                return error.typeError;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = src1_def.?.data.float / src2_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Div 1 rhs
            else if (src2_def != null and src2_def.?.kind == .loadFloat and src2_def.?.data.float == 1.0) {
                log("div; div 1 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .mod => {
            // Static check; divide by zero
            if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                errors.addError(Error{ .basic = .{
                    .span = src2_def.?.span,
                    .msg = "divide by 0",
                } });
                return error.typeError;
            }
            // Known int, int value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = @rem(src1_def.?.data.int, src2_def.?.data.int) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Mod 0 lhs
            else if (src1_def != null and src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("mod; mod 0 lhs");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Mod 1 rhs
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 1) {
                log("mod; mod 1 rhs");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = 0 };
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .index => {
            // Statically check if index is within bounds
            if (src2_def != null and src2_def.?.kind == .loadInt and ir.meta == .bounds_check and ir.meta.bounds_check.length.def.?.kind == .loadInt) {
                var index = src2_def.?.data.int;
                var length = ir.meta.bounds_check.length.def.?.data.int;
                if (index < 0) {
                    errors.addError(Error{ .negative_index = .{
                        .span = src2_def.?.span,
                        .index = index,
                    } });
                    return error.typeError;
                } else if (index >= length) {
                    errors.addError(Error{ .out_of_bounds = .{
                        .span = src2_def.?.span,
                        .index = index,
                        .length = @as(usize, @intCast(length)),
                    } });
                    return error.typeError;
                } else {
                    // Confirmed within bounds, remove bounds check
                    ir.meta = .none;
                }
            }
        },

        .select => {
            if (ir.meta == .active_field_check and ir.meta.active_field_check.tag.def.?.kind == .loadInt) {
                if (ir.data.select.field != ir.meta.active_field_check.tag.def.?.data.int and !ir.safe) {
                    errors.addError(Error{ .sum_select_inactive = .{
                        .span = ir.span,
                        .inactive = ir.src1.?.type.sum.terms.items[@as(usize, @intCast(ir.data.int))].annotation.pattern.getToken().data,
                        .active = ir.src1.?.type.sum.terms.items[@as(usize, @intCast(src1_def.?.data.int))].annotation.pattern.getToken().data,
                    } });
                    return error.typeError;
                } else {
                    ir.meta = .none;
                    retval = true;
                }
            }
            // Known loadUnion value
            if (src1_def != null and src1_def.?.kind == .loadUnion) {
                log("select; known loadUnion value");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                retval = true;
            }
            // Known loadStruct value
            else if (src1_def != null and src1_def.?.kind == .loadStruct) {
                // IR is of the form `dest = src1._{data.int}`, where src1_def is of the form: `src1 = {data.symbverList}`
                // `field = src1.data.symbverList[data.int]`; however, field may be updated after src1_def
                // make sure that `latest_def(field.symbol) == field` (in other words, field.symbol was not assigned to after src1_def)
                // std.debug.print("{}{?}", .{ ir, src1_def });
                var field: *SymbolVersion = src1_def.?.data.symbverList.items[@as(usize, @intCast(ir.data.select.field))];
                var field_def = src1_def.?.any_def_after(field.symbol, ir);
                if (field_def == null and field.def.?.kind != .index) {
                    log("select; known loadStruct value");
                    ir.kind = .copy;
                    ir.src1 = field;
                    ir.src2 = null;
                    ir.data = _ir.IRData.none;
                    retval = true;
                }
            }
            // Known loadString value
            else if (src1_def != null and src1_def.?.kind == .loadString) {
                if (ir.data.int == 1) {
                    ir.kind = .loadInt;
                    ir.data = _ir.IRData{ .int = interned_strings.items[src1_def.?.data.string_id].len };
                    ir.src1 = null;
                    ir.src2 = null;
                    retval = true;
                }
            }
        },

        .get_tag => {
            // Known loadUnion value
            if (src1_def != null and src1_def.?.kind == .loadUnion) {
                ir.kind = .loadInt;
                ir.data = src1_def.?.data; // Copy the src's tag (in data.int)
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .call => {
            for (ir.data.symbverList.items, 0..) |symbver, i| {
                if (symbver.def != null and symbver.def.?.kind == .copy) {
                    ir.data.symbverList.items[i] = symbver.def.?.src1.?;
                    retval = true;
                }
            }
        },

        else => {},
    }

    if (!retval and ir.dest == null or ir.dest.?.* == .symbver) {
        // Need to make sure src1_def.dest is not assigned to in between src1_def and ir.
        //   srcn_def:        dest = ?
        //             ...
        //   recent_srcn_def: dest = ? // If this exists, then srcn_def is NOT the most up to date
        //             ...
        //   ir:              ...
        if (src1_def != null and src1_def.?.kind == .copy) {
            // src1 copy propagation
            var recent_src1_def = src1_def.?.next.?.any_def_after(src1_def.?.src1.?.symbol, ir);
            if (recent_src1_def == null) {
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
        } else if (src2_def != null and src2_def.?.kind == .copy) {
            // src2 copy propagation
            var recent_src2_def = src2_def.?.next.?.any_def_after(src2_def.?.src1.?.symbol, ir);
            if (recent_src2_def == null) {
                ir.src2 = src2_def.?.src1;
                retval = true;
            }
        }
    }

    return retval;
}

fn findUnused(cfg: *CFG, errors: *errs.Errors) !void {
    calculateUsage(cfg);
    for (cfg.symbol.decl.?.fnDecl.param_symbols.items) |param_symbol| {
        try err_if_unused(param_symbol, errors);
    }

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and !ir.removed and ir.dest.?.* == .symbver and !ir.dest.?.symbver.symbol.is_temp and ir.dest.?.symbver.symbol != cfg.return_symbol) {
                try err_if_unused(ir.dest.?.symbver.symbol, errors);
            }
        }
    }
}

fn err_if_unused(symbol: *Symbol, errors: *errs.Errors) !void {
    if (symbol.discards > 1) {
        errors.addError(Error{ .symbol_error = .{
            .span = symbol.discard_span.?,
            .context_span = symbol.span,
            .name = symbol.name,
            .problem = "is discarded more than once",
            .context_message = "defined here",
        } });
        return error.typeError;
    } else if (symbol.discards == 1 and symbol.uses > 1) {
        errors.addError(Error{ .symbol_error = .{
            .span = symbol.discard_span.?,
            .context_span = symbol.span,
            .name = symbol.name,
            .problem = "is discarded when it is used",
            .context_message = "defined here",
        } });
        return error.typeError;
    } else if (symbol.discards == 0 and symbol.uses == 0) {
        errors.addError(Error{ .symbol_error = .{
            .span = symbol.span,
            .context_span = null,
            .name = symbol.name,
            .problem = "is never used",
            .context_message = "",
        } });
        return error.typeError;
    }
}

fn removeUnusedDefs(cfg: *CFG, errors: *errs.Errors) !bool {
    var retval = false;

    calculateUsage(cfg);
    calculateVersions(cfg);

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.kind == .discard) {
                continue;
            }
            if (ir.dest != null and !ir.removed and ir.dest.?.* == .symbver and ir.dest.?.symbver.uses == 0 and ir.dest.?.symbver.symbol.uses == 0 and ir.dest.?.symbver.symbol != cfg.return_symbol) {
                if (debug) {
                    std.debug.print("removing: {}", .{ir});
                }
                if (ir.kind == .call) {
                    if (ir.src1.?.symbol.expanded_type.?.function.rhs.* != .unit) {
                        // It is an error for the return val of a non-unit-returning function to not be used
                        // DO NOT remove an unused call for a unit function
                        errors.addError(Error{ .basic = .{
                            .span = ir.span,
                            .msg = "value of call is never used",
                        } });
                        return error.typeError;
                    }
                } else {
                    bb.removeInstruction(ir);
                    retval = true;
                }
            }
        }
    }

    return retval;
}

fn calculateVersions(cfg: *CFG) void {
    for (cfg.basic_blocks.items) |bb| {
        // Reset all reachable symbol verison counts to 0
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and ir.dest.?.* == .symbver) {
                ir.dest.?.symbver.symbol.versions = 0;
            }
            if (ir.src1) |src1| {
                src1.symbol.versions = 0;
            }
            if (ir.src2) |src2| {
                src2.symbol.versions = 0;
            }
        }
        cfg.return_symbol.versions = 0;
    }

    for (cfg.basic_blocks.items) |bb| {
        // Parameters define symbol versions
        for (bb.next_arguments.items) |symbver| {
            symbver.symbol.versions += 1;
        }

        // Go through sum up each definition
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and ir.dest.?.* == .symbver) {
                ir.dest.?.symbver.def = ir;
                ir.dest.?.symbver.symbol.versions += 1;
            }
        }
    }
}

fn calculateUsage(cfg: *CFG) void {
    for (cfg.symbol.decl.?.fnDecl.param_symbols.items) |param_symbol| {
        param_symbol.uses = 0;
    }

    for (cfg.basic_blocks.items) |bb| {
        // Clear all used flags
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null) {
                reset_usage_lval(ir.dest.?);
            }
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        // Arguments are default used
        for (bb.next_arguments.items) |symbver| {
            symbver.uses += 1;
        }
        for (bb.branch_arguments.items) |symbver| {
            symbver.uses += 1;
        }

        // Go through and see if each symbol is used
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.kind == .discard) {
                ir.src1.?.symbol.discards += 1;
            }
            if (ir.dest != null and ir.dest.?.* != .symbver) {
                calculate_usage_lval(ir.dest.?);
            }
            if (ir.src1 != null) {
                ir.src1.?.uses += 1;
                ir.src1.?.symbol.uses += 1;
            }
            if (ir.src2 != null) {
                ir.src2.?.uses += 1;
                ir.src2.?.symbol.uses += 1;
            }

            if (ir.data == .symbver) {
                ir.data.symbver.uses += 1;
                ir.data.symbver.symbol.uses += 1;
            } else if (ir.data == .symbverList) {
                for (ir.data.symbverList.items) |item| {
                    item.uses += 1;
                    item.symbol.uses += 1;
                }
            } else if (ir.data == .lval) {
                calculate_usage_lval(ir.data.lval);
            }

            if (ir.meta == .bounds_check) {
                ir.meta.bounds_check.length.uses += 1;
                ir.meta.bounds_check.length.symbol.uses += 1;
            } else if (ir.meta == .active_field_check) {
                ir.meta.active_field_check.tag.uses += 1;
                ir.meta.active_field_check.tag.symbol.uses += 1;
            }
        }

        // Conditions are used
        if (bb.has_branch) {
            bb.condition.?.uses += 1;
            bb.condition.?.symbol.uses += 1;
        }
    }
}

fn reset_usage_lval(lval: *L_Value) void {
    switch (lval.*) {
        .symbver => {
            lval.symbver.uses = 0;
            lval.symbver.symbol.uses = 0;
        },
        .dereference => {
            lval.dereference.uses = 0;
            lval.dereference.symbol.uses = 0;
        },
        .index_slice => {
            lval.index_slice.lhs.uses = 0;
            lval.index_slice.lhs.symbol.uses = 0;
            lval.index_slice.field.uses = 0;
            lval.index_slice.field.symbol.uses = 0;
        },
        .index => {
            reset_usage_lval(lval.index.lhs);
            lval.index.field.uses = 0;
            lval.index.field.symbol.uses = 0;
        },
        .select => {
            reset_usage_lval(lval.select.lhs);
        },
    }
}

fn calculate_usage_lval(lval: *L_Value) void {
    switch (lval.*) {
        .symbver => {
            lval.symbver.uses += 1;
            lval.symbver.symbol.uses += 1;
        },
        .dereference => {
            lval.dereference.uses += 1;
            lval.dereference.symbol.uses += 1;
        },
        .index_slice => {
            lval.index_slice.lhs.uses += 1;
            lval.index_slice.lhs.symbol.uses += 1;
            lval.index_slice.field.uses += 1;
            lval.index_slice.field.symbol.uses += 1;
        },
        .index => {
            calculate_usage_lval(lval.index.lhs);
            lval.index.field.uses += 1;
            lval.index.field.symbol.uses += 1;
        },
        .select => {
            calculate_usage_lval(lval.select.lhs);
        },
    }
}
