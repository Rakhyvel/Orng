const errs = @import("errors.zig");
const _ir = @import("ir.zig");
const std = @import("std");

const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const Error = errs.Error;
const IR = _ir.IR;
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

    while (try propagate(cfg, interned_strings, errors) or
        try bbOptimizations(cfg, allocator) or
        removeUnusedDefs(cfg))
    {}
    cfg.clearVisitedBBs();

    log_optimization_pass("final", cfg);

    for (cfg.children.items) |child| {
        try optimize(child, errors, interned_strings, allocator);
    }
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
            return true;
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
            var latest_condition = bb.get_latest_def(bb.condition.?.symbol, null);
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

fn findIR(bb: *BasicBlock, symbver: *SymbolVersion) ?*IR {
    var maybe_ir = bb.ir_head;
    while (maybe_ir) |ir| : (maybe_ir = ir.next) {
        if (ir.dest != null and ir.dest.?.symbol == symbver.symbol) {
            return ir;
        }
    }
    return null;
}

fn propagate(cfg: *CFG, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors) !bool {
    var retval = false;

    calculateVersions(cfg);
    calculateUsage(cfg);

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            retval = try propagateIR(ir, interned_strings, errors) or retval;
        }
        if (bb.has_branch) {
            var cond_def = bb.get_latest_def(bb.condition.?.symbol, null);
            if (cond_def != null and cond_def.?.kind == .copy) {
                bb.condition = cond_def.?.src1;
                retval = true;
            }
        }
    }

    return retval;
}

fn propagateIR(ir: *IR, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors) !bool {
    var retval = false;
    var src1_def = if (ir.src1 != null) ir.in_block.?.get_latest_def(ir.src1.?.symbol, ir) else null;
    var src2_def = if (ir.src2 != null) ir.in_block.?.get_latest_def(ir.src2.?.symbol, ir) else null;

    switch (ir.kind) {
        .copy => {
            // Unit-copy elimination
            if (ir.src1 == null) {
                log("unit-copy elimination");
                ir.in_block.?.removeInstruction(ir);
            }
            // Self-copy elimination
            else if (ir.dest.?.symbol == ir.src1.?.symbol and src1_def != null and ir.dest.?.version == ir.src1.?.version) {
                log("self-copy elimination");
                ir.in_block.?.removeInstruction(ir);
                retval = true;
            }
            // Integer constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadInt) {
                log("integer constant propagation");
                ir.kind = .loadInt;
                ir.data = src1_def.?.data;
                ir.src1 = null;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Float constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadFloat) {
                log("float constant propagation");
                ir.kind = .loadFloat;
                ir.data = src1_def.?.data;
                ir.src1 = null;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // String constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadString) {
                log("string constant propagation");
                ir.kind = .loadString;
                ir.data = src1_def.?.data;
                ir.src1 = null;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Struct constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadStruct and ir.src1.?.uses == 1) {
                log("struct constant propagation");
                ir.kind = .loadStruct;
                ir.data = src1_def.?.data;
                ir.src1 = null;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Union constant propagation
            else if (src1_def != null and src1_def.?.kind == .loadUnion) {
                log("union constant propagation");
                ir.kind = .loadUnion;
                ir.data = src1_def.?.data;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Load symbol propagation
            else if (src1_def != null and src1_def.?.kind == .loadSymbol) {
                log("symbol constant propagation");
                ir.kind = .loadSymbol;
                ir.data = src1_def.?.data;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Copy propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .copy and ir.src1 != src1_def.?.src1.?) {
                log("copy propagation");
                ir.src1 = src1_def.?.src1;
                ir.dest.?.lvalue = src1_def.?.dest.?.lvalue;
                retval = true;
            }
            // Addrof propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .addrOf) {
                log("addrof propagation");
                ir.kind = .addrOf;
                ir.data = src1_def.?.data;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Dereference propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .dereference) {
                log("dereference propagation");
                ir.kind = .dereference;
                ir.data = src1_def.?.data;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Add propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .add) {
                log("add propagation");
                ir.kind = .add;
                ir.data = src1_def.?.data;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Sub propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .sub) {
                log("sub propagation");
                ir.kind = .sub;
                ir.data = src1_def.?.data;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Mult propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .mult) {
                log("mult propagation");
                ir.kind = .mult;
                ir.data = src1_def.?.data;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Div propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .div) {
                log("div propagation");
                ir.kind = .div;
                ir.data = src1_def.?.data;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Mod propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .mod) {
                log("mod propagation");
                ir.kind = .mod;
                ir.data = src1_def.?.data;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Exponent propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .exponent) {
                log("exponent");
                ir.kind = .exponent;
                ir.data = src1_def.?.data;
                ir.src2 = src1_def.?.src2;
                ir.src1 = src1_def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Select propagation
            else if (ir.src1.?.symbol.versions == 1 and src1_def != null and src1_def.?.kind == .select) {
                log("select");
                ir.kind = .select;
                ir.dest.?.lvalue = src1_def.?.dest.?.lvalue;
                ir.data = src1_def.?.data;
                ir.src2 = src1_def.?.src2;
                ir.safe = src1_def.?.safe;
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
            // Call propagation // Not the greatest... ?
            // else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .call) {
            //     ir.kind = .call;
            //     ir.data = ir.src1.?.def.?.data;
            //     ir.src1 = ir.src1.?.def.?.src1;
            //     ir.src2 = null;
            //     ir.dest.?.lvalue = false;
            //     retval = true;
            // }
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

        .negate => {
            // Known int value
            if (src1_def != null and src1_def.?.kind == .loadInt) {
                log("negate; known int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = -src1_def.?.data.int };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float value
            else if (src1_def != null and src1_def.?.kind == .loadFloat) {
                log("negate; known float value");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = -src1_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .derefCopy => {
            // Copy propagation
            if (src1_def != null and src1_def.?.kind == .copy and ir.src1 != src1_def.?.src1.?) {
                log("deref-copy propagation");
                ir.src1 = src1_def.?.src1;
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
            // `0 == x` => `!x`
            else if (src1_def != null and src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("equal; lhs 0");
                ir.kind = .not;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // `x == 0` => `!x`
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                log("equal; rhs 0");
                ir.kind = .not;
                ir.data = _ir.IRData.none;
                // ir.src1 is already ir.src1
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
        },

        .notEqual => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("notEqual; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int != src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // `0 != x` => `x`
            else if (src1_def != null and src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("notEqual; lhs 0");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // `x != 0` => `x`
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                log("notEqual; rhs 0");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                // ir.src1 is already ir.src1
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("notEqual; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float != src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .greater => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("greater; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int > src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("greater; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float > src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .lesser => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("lesser; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int < src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("lesser; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float < src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .greaterEqual => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("greaterEqual; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int >= src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("greaterEqual; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float >= src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .lesserEqual => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("lesserEqual; known int,int value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.int <= src2_def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("lesserEqual; known float,float value");
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (src1_def.?.data.float <= src2_def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .add => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                log("add; known int,int value");
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
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("add; known float,float value");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = src1_def.?.data.float + src2_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Add 0 lhs
            else if (src1_def != null and ((src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) or (src1_def.?.kind == .loadFloat and src1_def.?.data.float == 0.0))) {
                log("add; add 0 lhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Add 0 rhs
            else if (src2_def != null and ((src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) or (src2_def.?.kind == .loadFloat and src2_def.?.data.float == 0.0))) {
                log("add; add 0 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .sub => {
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
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                log("sub; known float,float value");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = src1_def.?.data.float - src2_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Sub 0 lhs
            else if (src1_def != null and ((src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) or (src1_def.?.kind == .loadFloat and src1_def.?.data.float == 0.0))) {
                log("sub; sub 0 lhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Sub 0 rhs
            else if (src2_def != null and ((src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) or (src2_def.?.kind == .loadFloat and src2_def.?.data.float == 0.0))) {
                log("sub; sub 0 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .mult => {
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
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = src1_def.?.data.float * src2_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Mult 1 lhs
            else if (src1_def != null and ((src1_def.?.kind == .loadInt and src1_def.?.data.int == 1) or (src1_def.?.kind == .loadFloat and src1_def.?.data.float == 1.0))) {
                log("mult; mult 1 lhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Mult 1 rhs
            else if (src2_def != null and ((src2_def.?.kind == .loadInt and src2_def.?.data.int == 1) or (src2_def.?.kind == .loadFloat and src2_def.?.data.float == 1.0))) {
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
            // Mult 0 lhs float
            else if (src1_def != null and src1_def.?.kind == .loadFloat and src1_def.?.data.float == 0.0) {
                log("mult; mult 0 lhs float");
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = 0.0 };
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

        .div => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                if (src2_def.?.data.int == 0) {
                    errors.addError(Error{ .basic = .{
                        .span = src2_def.?.span,
                        .msg = "divide by 0",
                    } });
                    return error.typeError;
                }
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = @divTrunc(src1_def.?.data.int, src2_def.?.data.int) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                if (src2_def.?.data.float == 0.0) {
                    errors.addError(Error{ .basic = .{
                        .span = src2_def.?.span,
                        .msg = "divide by 0",
                    } });
                    return error.typeError;
                }
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = src1_def.?.data.float / src2_def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Div 1 rhs
            else if (src2_def != null and ((src2_def.?.kind == .loadInt and src2_def.?.data.int == 1) or (src2_def.?.kind == .loadFloat and src2_def.?.data.float == 1.0))) {
                log("div; div 1 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .mod => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                if (src2_def.?.data.int == 0) {
                    errors.addError(Error{ .basic = .{
                        .span = src2_def.?.span,
                        .msg = "divide by 0",
                    } });
                    return error.typeError;
                }
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = @rem(src1_def.?.data.int, src2_def.?.data.int) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Mod 0 lhs
            else if (src1_def != null and src1_def.?.kind == .loadInt and src1_def.?.data.int == 0) {
                log("mod; mod 0 lhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src2;
                ir.src2 = null;
                retval = true;
            }
            // Mod 1 rhs
            else if (src2_def != null and src2_def.?.kind == .loadInt and src2_def.?.data.int == 0) {
                log("mod; mod 1 rhs");
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1;
                ir.src2 = null;
                retval = true;
            }
        },

        .exponent => {
            // Known int, int value
            if (src1_def != null and src2_def != null and src1_def.?.kind == .loadInt and src2_def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{
                    .int = if (std.math.powi(i128, src1_def.?.data.int, src2_def.?.data.int)) |res| res else |_| {
                        errors.addError(Error{ .basic = .{
                            .span = src2_def.?.span,
                            .msg = "exponent is undefined",
                        } });
                        return error.typeError;
                    },
                };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (src1_def != null and src2_def != null and src1_def.?.kind == .loadFloat and src2_def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .float = std.math.pow(f64, src1_def.?.data.float, src2_def.?.data.float) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .index => {
            // Statically check if index is within bounds
            if (src2_def != null and src2_def.?.kind == .loadInt) {
                log("index btw");
                if (ir.src1.?.symbol._type.?.* == .product and !ir.src1.?.symbol._type.?.product.was_slice) {
                    var index = src2_def.?.data.int;
                    var length = ir.src1.?.symbol._type.?.product.terms.items.len;
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
                            .length = length,
                        } });
                        return error.typeError;
                    }
                }
            }
        },

        .indexCopy => {
            // Statically check if index is within bounds
            if (src2_def != null and src2_def.?.kind == .loadInt) {
                if (ir.src1.?.symbol._type.?.* == .product and !ir.src1.?.symbol._type.?.product.was_slice) {
                    var index = src2_def.?.data.int;
                    var length = ir.src1.?.symbol._type.?.product.terms.items.len;
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
                            .length = length,
                        } });
                        return error.typeError;
                    }
                }
            }
        },

        .select => {
            // Known loadUnion value
            if (src1_def != null and ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and src1_def.?.kind == .loadUnion) {
                log("select; known loadUnion value");
                if (ir.data.int != src1_def.?.data.int and !ir.safe) {
                    errors.addError(Error{ .sum_select_inactive = .{
                        .span = ir.span,
                        .inactive = ir.src1.?.type.sum.terms.items[@as(usize, @intCast(ir.data.int))].annotation.pattern.getToken().data,
                        .active = ir.src1.?.type.sum.terms.items[@as(usize, @intCast(src1_def.?.data.int))].annotation.pattern.getToken().data,
                    } });
                    return error.typeError;
                }
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = src1_def.?.src1;
                ir.src2 = null;
                retval = true;
            }
            // Known loadStruct value
            else if (src1_def != null and !ir.dest.?.lvalue and src1_def.?.kind == .loadStruct) {
                // IR is of the form `dest = src1._{data.int}`, where src1_def is of the form: `src1 = {data.symbverList}`
                // `field = src1.data.symbverList[data.int]`; however, field may be updated after src1_def
                // make sure that `latest_def(field.symbol) == field` (in other words, field.symbol was not assigned to after src1_def)
                var field: *SymbolVersion = src1_def.?.data.symbverList.items[@as(usize, @intCast(ir.data.int))];
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
                    ir.data = _ir.IRData{ .int = interned_strings.items[src1_def.?.data.string_id].len - 1 };
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

    if (!retval) {
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

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and !ir.removed and !ir.dest.?.symbol.is_temp) {
                if (ir.dest.?.symbol.discards > 1) {
                    errors.addError(Error{ .symbol_error = .{
                        .span = ir.dest.?.symbol.discard_span.?,
                        .context_span = ir.dest.?.symbol.span,
                        .name = ir.dest.?.symbol.name,
                        .problem = "is discarded more than once",
                        .context_message = "defined here",
                    } });
                    return error.typeError;
                } else if (ir.dest.?.symbol.discards == 1 and ir.dest.?.symbol.uses > 1) {
                    errors.addError(Error{ .symbol_error = .{
                        .span = ir.dest.?.symbol.discard_span.?,
                        .context_span = ir.dest.?.symbol.span,
                        .name = ir.dest.?.symbol.name,
                        .problem = "is discarded when it is used",
                        .context_message = "defined here",
                    } });
                    return error.typeError;
                } else if (ir.dest.?.symbol.discards == 0 and ir.dest.?.symbol.uses == 0) {
                    errors.addError(Error{ .symbol_error = .{
                        .span = ir.dest.?.symbol.span,
                        .context_span = null,
                        .name = ir.dest.?.symbol.name,
                        .problem = "is never used",
                        .context_message = "",
                    } });
                    return error.typeError;
                }
            }
        }
    }
}

fn removeUnusedDefs(cfg: *CFG) bool {
    var retval = false;

    calculateUsage(cfg);
    calculateVersions(cfg);

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and !ir.removed and ir.dest.?.uses == 0) {
                if (debug) {
                    std.debug.print("removing {s}\n", .{ir.dest.?.symbol.name});
                }
                bb.removeInstruction(ir);
                retval = true;
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
            if (ir.dest) |dest| {
                dest.symbol.versions = 0;
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
            if (ir.dest) |dest| {
                dest.def = ir;
                if (dest.lvalue) {
                    continue;
                }
                dest.symbol.versions += 1;
            }
        }
    }
}

fn calculateUsage(cfg: *CFG) void {
    for (cfg.basic_blocks.items) |bb| {
        // Clear all used flags
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest) |dest| {
                dest.uses = 0;
                dest.symbol.uses = 0;
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
            if (ir.dest != null and (ir.kind == .derefCopy or ir.dest.?.symbol == cfg.return_symbol or ir.kind == .call)) {
                // dest aren't USUALLY considered a usage, but they are for derefCopy and call IRs
                ir.dest.?.uses += 1;
                ir.dest.?.symbol.uses += 1;
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
            }
        }

        // Conditions are used
        if (bb.has_branch) {
            bb.condition.?.uses += 1;
            bb.condition.?.symbol.uses += 1;
        }
    }
}
