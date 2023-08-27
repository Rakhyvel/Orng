const errs = @import("errors.zig");
const _ir = @import("ir.zig");
const std = @import("std");

const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const Error = errs.Error;
const IR = _ir.IR;
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
            log("\n\n");
        } else {
            std.debug.print("[WARNING] block head for CFG: {s} is null\n", .{cfg.symbol.name});
        }
    }
}

pub fn optimize(cfg: *CFG, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    if (debug) {
        std.debug.print("[  CFG  ]: {s}\n", .{cfg.symbol.name});
        cfg.block_graph_head.?.pprint();
        log("\n\n");
    }

    try findUnused(cfg, errors);

    while (try propagate(cfg, errors) or
        try bbOptimizations(cfg, allocator) or
        removeUnusedDefs(cfg))
    {}
    cfg.clearVisitedBBs();

    for (cfg.children.items) |child| {
        try optimize(child, errors, allocator);
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
            defer log_optimization_pass("adopt block", cfg);
            var end: *IR = bb.ir_head.?.getTail();

            // Join next block at the end of this block
            for (bb.next_arguments.items) |argument| {
                if (argument.findSymbolVersionSet(&bb.next.?.parameters)) |parameter| {
                    if (parameter.version != argument.version) {
                        end = bb.appendInstruction(try IR.create(.copy, parameter, argument, null, end.span, allocator));
                        parameter.def = end;
                        parameter.makeUnique();
                    }
                }
            }
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

        // Convert constant true/false branches to jumps
        if (bb.has_branch and bb.condition.?.def != null and bb.condition.?.def.?.kind == .loadInt) {
            defer log_optimization_pass("convert constant true/false to jumps", cfg);
            bb.has_branch = false;
            if (bb.condition.?.def.?.data.int == 0) {
                bb.next = bb.branch;
                bb.next_arguments = bb.branch_arguments;
            }
            retval = true;
        }

        // Remove jump chains
        if (bb.next) |next| {
            defer log_optimization_pass("remove jump chains", cfg);
            if (next.ir_head == null and !next.has_branch) {
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
            defer log_optimization_pass("next depends on known argument", cfg);
            if (next.has_branch and next.ir_head == null) {
                var def = bb.findInstruction(next.condition.?.symbol);
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
            var def = bb.findInstruction(bb.branch.?.condition.?.symbol);
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
        defer log_optimization_pass("rebase block", cfg);
        if (head.ir_head == null and !head.has_branch) {
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
    _ = cfg.basic_blocks.orderedRemove(i);
    if (wipeIR) {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            ir.removed = true;
        }
    }
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

fn propagate(cfg: *CFG, errors: *errs.Errors) !bool {
    var retval = false;

    calculateVersions(cfg);
    calculateUsage(cfg);

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            retval = try propagateIR(ir, errors) or retval;
            if (ir.src1 != null and ir.src1.?.def == null) {
                ir.src1.?.def = findIR(bb, ir.src1.?);
                retval = ir.src1.?.def != null;
            }
        }
        if (bb.has_branch and bb.condition.?.def != null and bb.condition.?.def.?.kind == .copy) {
            bb.condition = bb.condition.?.def.?.src1;
            retval = true;
        }
    }

    return retval;
}

fn propagateIR(ir: *IR, errors: *errs.Errors) !bool {
    var retval = false;

    switch (ir.kind) {
        .copy => {
            // Unit-copy elimination
            if (ir.src1 == null) {
                ir.in_block.?.removeInstruction(ir);
            }
            // Self-copy elimination
            else if (ir.dest.?.symbol == ir.src1.?.symbol and ir.src1.?.def != null) {
                ir.in_block.?.removeInstruction(ir);
            }
            // Integer constant propagation
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = ir.src1.?.def.?.data;
                ir.src1 = null;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Float constant propagation
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .loadFloat) {
                ir.kind = .loadFloat;
                ir.data = ir.src1.?.def.?.data;
                ir.src1 = null;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // String constant propagation
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .loadString) {
                ir.kind = .loadString;
                ir.data = ir.src1.?.def.?.data;
                ir.src1 = null;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Struct constant propagation
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .loadStruct) {
                ir.kind = .loadStruct;
                ir.data = ir.src1.?.def.?.data;
                ir.src1 = null;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Union constant propagation
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .loadUnion) {
                ir.kind = .loadUnion;
                ir.data = ir.src1.?.def.?.data;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Copy propagation
            else if (ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy and ir.src1 != ir.src1.?.def.?.src1.?) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Addrof propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .addrOf) {
                ir.kind = .addrOf;
                ir.data = ir.src1.?.def.?.data;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Dereference propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .dereference) {
                ir.kind = .dereference;
                ir.data = ir.src1.?.def.?.data;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.src2 = null;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Add propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .add) {
                ir.kind = .add;
                ir.data = ir.src1.?.def.?.data;
                ir.src2 = ir.src1.?.def.?.src2;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Sub propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .sub) {
                ir.kind = .sub;
                ir.data = ir.src1.?.def.?.data;
                ir.src2 = ir.src1.?.def.?.src2;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Mult propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .mult) {
                ir.kind = .mult;
                ir.data = ir.src1.?.def.?.data;
                ir.src2 = ir.src1.?.def.?.src2;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Div propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .div) {
                ir.kind = .div;
                ir.data = ir.src1.?.def.?.data;
                ir.src2 = ir.src1.?.def.?.src2;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Mod propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .mod) {
                ir.kind = .mod;
                ir.data = ir.src1.?.def.?.data;
                ir.src2 = ir.src1.?.def.?.src2;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Exponent propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .exponent) {
                ir.kind = .exponent;
                ir.data = ir.src1.?.def.?.data;
                ir.src2 = ir.src1.?.def.?.src2;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.dest.?.lvalue = false;
                retval = true;
            }
            // Select propagation
            else if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .select) {
                ir.kind = .select;
                ir.dest.?.lvalue = ir.src1.?.def.?.dest.?.lvalue;
                ir.data = ir.src1.?.def.?.data;
                ir.src2 = ir.src1.?.def.?.src2;
                ir.src1 = ir.src1.?.def.?.src1;
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
            if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.int == 0) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
        },

        .negate => {
            // Known int value
            if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = -ir.src1.?.def.?.data.int };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float value
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .loadFloat) {
                ir.kind = .loadFloat;
                ir.data = _ir.IRData{ .float = -ir.src1.?.def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .dereference => {
            // Short-circuit src1 copy
            if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
        },

        .derefCopy => {
            // Copy propagation
            if (ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy and ir.src1 != ir.src1.?.def.?.src1.?) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
        },

        .equal => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.int == ir.src2.?.def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.float == ir.src2.?.def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .notEqual => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.int != ir.src2.?.def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.float != ir.src2.?.def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .greater => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.int > ir.src2.?.def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.float > ir.src2.?.def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .lesser => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.int < ir.src2.?.def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.float < ir.src2.?.def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .greaterEqual => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.int >= ir.src2.?.def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.float >= ir.src2.?.def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .lesserEqual => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.int <= ir.src2.?.def.?.data.int) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = if (ir.src1.?.def.?.data.float <= ir.src2.?.def.?.data.float) 1 else 0 };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .add => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = ir.src1.?.def.?.data.int + ir.src2.?.def.?.data.int };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .float = ir.src1.?.def.?.data.float + ir.src2.?.def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .sub => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = ir.src1.?.def.?.data.int - ir.src2.?.def.?.data.int };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .float = ir.src1.?.def.?.data.float - ir.src2.?.def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .mult => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = ir.src1.?.def.?.data.int * ir.src2.?.def.?.data.int };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .float = ir.src1.?.def.?.data.float * ir.src2.?.def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .div => {
            // TODO: Compile error if divide by 0
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = @divTrunc(ir.src1.?.def.?.data.int, ir.src2.?.def.?.data.int) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .float = ir.src1.?.def.?.data.float / ir.src2.?.def.?.data.float };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .mod => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = @rem(ir.src1.?.def.?.data.int, ir.src2.?.def.?.data.int) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .exponent => {
            // Known int, int value
            if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.uses == 1 and ir.src2.?.uses == 1 and ir.src1.?.def.?.kind == .loadInt and ir.src2.?.def.?.kind == .loadInt) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .int = std.math.pow(i128, ir.src1.?.def.?.data.int, ir.src2.?.def.?.data.int) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Known float, float value
            else if (ir.src1.?.def != null and ir.src2.?.def != null and ir.src1.?.def.?.kind == .loadFloat and ir.src2.?.def.?.kind == .loadFloat) {
                ir.kind = .loadInt;
                ir.data = _ir.IRData{ .float = std.math.pow(f64, ir.src1.?.def.?.data.float, ir.src2.?.def.?.data.float) };
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
            // Short-circuit src1 copy
            else if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            // Short-circuit src2 copy
            else if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .copy) {
                ir.src2 = ir.src2.?.def.?.src1;
                retval = true;
            }
        },

        .index => {
            // Statically check if index is within bounds
            if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .loadInt) {
                if (ir.src1.?.symbol._type.?.* == .product and !ir.src1.?.symbol._type.?.product.was_slice) {
                    var index = ir.src2.?.def.?.data.int;
                    var length = ir.src1.?.symbol._type.?.product.terms.items.len;
                    if (index < 0) {
                        errors.addError(Error{ .negative_index = .{
                            .span = ir.src2.?.def.?.span,
                            .index = index,
                        } });
                        return error.typeError;
                    } else if (index >= length) {
                        errors.addError(Error{ .out_of_bounds = .{
                            .span = ir.src2.?.def.?.span,
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
            if (ir.src2.?.def != null and ir.src2.?.def.?.kind == .loadInt) {
                if (ir.src1.?.symbol._type.?.* == .product and !ir.src1.?.symbol._type.?.product.was_slice) {
                    var index = ir.src2.?.def.?.data.int;
                    var length = ir.src1.?.symbol._type.?.product.terms.items.len;
                    if (index < 0) {
                        errors.addError(Error{ .negative_index = .{
                            .span = ir.src2.?.def.?.span,
                            .index = index,
                        } });
                        return error.typeError;
                    } else if (index >= length) {
                        errors.addError(Error{ .out_of_bounds = .{
                            .span = ir.src2.?.def.?.span,
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
            if (ir.src1.?.def != null and ir.src1.?.symbol.versions == 1 and ir.src1.?.uses == 1 and ir.src1.?.def.?.kind == .loadUnion) {
                ir.kind = .copy;
                ir.data = _ir.IRData.none;
                ir.src1 = ir.src1.?.def.?.src1;
                ir.src2 = null;
                retval = true;
            }
            // Known loadStruct value
            else if (ir.src1.?.def != null and ir.src1.?.uses == 1 and ir.src1.?.def.?.kind == .loadStruct) {
                var field = ir.src1.?.def.?.data.symbverList.items[@as(usize, @intCast(ir.data.int))]; // TODO: This should really be a check that the symbol version hasn't updated out from underneathe us
                if (field.symbol.versions == 1) {
                    ir.kind = .copy;
                    ir.src1 = field;
                    ir.src2 = null;
                    ir.data = _ir.IRData.none;
                    retval = true;
                }
            }
        },

        .get_tag => {
            // Known loadUnion value
            if (ir.src1.?.def != null and ir.src1.?.uses == 1 and ir.src1.?.def.?.kind == .loadUnion) {
                ir.kind = .loadInt;
                ir.data = ir.src1.?.def.?.data; // Copy the src's tag (in data.int)
                ir.src1 = null;
                ir.src2 = null;
                retval = true;
            }
        },

        .call => {
            // Short-circuit src1 copy
            if (ir.src1.?.def != null and ir.src1.?.def.?.kind == .copy) {
                ir.src1 = ir.src1.?.def.?.src1;
                retval = true;
            }
            for (ir.data.symbverList.items, 0..) |symbver, i| {
                if (symbver.def != null and symbver.def.?.kind == .copy) {
                    ir.data.symbverList.items[i] = symbver.def.?.src1.?;
                    retval = true;
                }
            }
        },

        else => {},
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
        }
    }
}
