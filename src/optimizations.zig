const _ir = @import("ir.zig");
const std = @import("std");

const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const IR = _ir.IR;
const SymbolVersion = _ir.SymbolVersion;

pub fn optimize(cfg: *CFG, allocator: std.mem.Allocator) !void {
    while (try propagate(cfg) or
        try bbOptimizations(cfg, allocator) or
        try removeUnusedDefs(cfg))
    {
        // cfg.block_graph_head.?.pprint();
        // std.debug.print("\n", .{});
    }
    cfg.clearVisitedBBs();
}

fn bbOptimizations(cfg: *CFG, allocator: std.mem.Allocator) !bool {
    var retval: bool = false;

    countPredecessors(cfg);
    try cfg.calculatePhiParamsAndArgs(allocator);
    calculateVersions(cfg);

    for (cfg.basic_blocks.items) |bb| {
        if (bb.number_predecessors == 0) {
            removeBasicBlock(cfg, bb, true);
            return true;
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        // Adopt basic blocks with only one incoming block
        if (bb.next != null and bb.ir_head != null and !bb.has_branch and bb.next.?.number_predecessors == 1) {
            var end: *IR = bb.ir_head.?.getTail();

            // Join next block at the end of this block
            for (bb.next_arguments.items) |argument| {
                if (argument.findSymbolVersionSet(&bb.next.?.parameters)) |parameter| {
                    if (parameter.version != argument.version) {
                        end = bb.appendInstruction(try IR.create(.copy, parameter, argument, null, allocator));
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
            bb.has_branch = false;
            if (bb.condition.?.def.?.data.int == 0) {
                bb.next = bb.branch;
                bb.next_arguments = bb.branch_arguments;
            }
            retval = true;
        }

        // Remove jump chains
        if (bb.next) |next| {
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
    }

    // Rebase block graph if jump chain
    if (cfg.block_graph_head) |head| {
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
    _countPredecessors(cfg.block_graph_head.?);
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

fn propagate(cfg: *CFG) !bool {
    var retval = false;

    calculateVersions(cfg);

    for (cfg.basic_blocks.items) |bb| {
        var maybe_def = bb.ir_head;
        while (maybe_def) |def| : (maybe_def = def.next) {
            switch (def.kind) {
                .copy => {
                    // Self-copy elimination
                    if (def.dest.?.symbol == def.src1.?.symbol and def.src1.?.def != null) {
                        // std.debug.print("{?}\n", .{def.src1.?.def});
                        def.kind = def.src1.?.def.?.kind;
                        def.data = def.src1.?.def.?.data;
                        def.dest = def.src1.?.def.?.dest;
                        def.src1 = def.src1.?.def.?.src1;
                        // def.src2 = def.src1.?.def.?.src2;
                        retval = true;
                    }
                    // Integer constant propagation
                    else if (def.src1.?.def != null and def.src1.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = def.src1.?.def.?.data;
                        def.src1 = null;
                        def.src2 = null;
                        def.dest.?.lvalue = false;
                        retval = true;
                    }
                    // Float constant propagation
                    else if (def.src1.?.def != null and def.src1.?.def.?.kind == .loadFloat) {
                        def.kind = .loadFloat;
                        def.data = def.src1.?.def.?.data;
                        def.src1 = null;
                        def.src2 = null;
                        def.dest.?.lvalue = false;
                        retval = true;
                    }
                    // Copy propagation
                    else if (def.src1.?.def != null and def.src1.?.def.?.kind == .copy and def.src1 != def.src1.?.def.?.src1.?) {
                        def.src1 = def.src1.?.def.?.src1;
                        retval = true;
                    } else {}
                },

                .not => {
                    // Known int value
                    if (def.src1.?.def != null and def.src1.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.int == 0) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .negate => {
                    // Known int value
                    if (def.src1.?.def != null and def.src1.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = -def.src1.?.def.?.data.int };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float value
                    else if (def.src1.?.def != null and def.src1.?.def.?.kind == .loadFloat) {
                        def.kind = .loadFloat;
                        def.data = _ir.IRData{ .float = -def.src1.?.def.?.data.float };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .equal => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.int == def.src2.?.def.?.data.int) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.float == def.src2.?.def.?.data.float) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .notEqual => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.int != def.src2.?.def.?.data.int) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.float != def.src2.?.def.?.data.float) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .greater => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.int > def.src2.?.def.?.data.int) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.float > def.src2.?.def.?.data.float) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .lesser => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.int < def.src2.?.def.?.data.int) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.float < def.src2.?.def.?.data.float) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .greaterEqual => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.int >= def.src2.?.def.?.data.int) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.float >= def.src2.?.def.?.data.float) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .lesserEqual => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.int <= def.src2.?.def.?.data.int) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.float <= def.src2.?.def.?.data.float) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .add => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = def.src1.?.def.?.data.int + def.src2.?.def.?.data.int };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .float = def.src1.?.def.?.data.float + def.src2.?.def.?.data.float };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .sub => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = def.src1.?.def.?.data.int - def.src2.?.def.?.data.int };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .float = def.src1.?.def.?.data.float - def.src2.?.def.?.data.float };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .mult => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = def.src1.?.def.?.data.int * def.src2.?.def.?.data.int };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .float = def.src1.?.def.?.data.float * def.src2.?.def.?.data.float };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .div => {
                    // TODO: Compile error if divide by 0
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = @divTrunc(def.src1.?.def.?.data.int, def.src2.?.def.?.data.int) };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .float = def.src1.?.def.?.data.float / def.src2.?.def.?.data.float };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .mod => {
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = @rem(def.src1.?.def.?.data.int, def.src2.?.def.?.data.int) };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                .exponent => {
                    // TODO: Compile error if divide by 0
                    // Known int, int value
                    if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadInt and def.src2.?.def.?.kind == .loadInt) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = std.math.pow(i128, def.src1.?.def.?.data.int, def.src2.?.def.?.data.int) };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .float = std.math.pow(f64, def.src1.?.def.?.data.float, def.src2.?.def.?.data.float) };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                    }
                },

                else => {},
            }
            if (def.src1 != null and def.src1.?.def == null and def.src1.?.symbol.versions == 1) {
                def.src1.?.def = findIR(bb, def.src1.?);
                retval = def.src1.?.def != null;
            }
        }
    }
    return retval;
}

fn removeUnusedDefs(cfg: *CFG) !bool {
    var retval = false;

    calculateUsage(cfg);
    calculateVersions(cfg);

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and !ir.removed and !ir.dest.?.used) {
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
                dest.used = false;
            }
        }

        // Arguments are default used
        for (bb.next_arguments.items) |symbver| {
            symbver.used = true;
        }
        for (bb.branch_arguments.items) |symbver| {
            symbver.used = true;
        }

        // Go through and see if each symbol is used
        maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and (ir.kind == .derefCopy or ir.dest.?.symbol == cfg.return_symbol)) {
                ir.dest.?.used = true;
            }
            if (ir.src1 != null) {
                ir.src1.?.used = true;
            }
            if (ir.src2 != null) {
                ir.src2.?.used = true;
            }
        }

        // Conditions are used
        if (bb.has_branch) {
            bb.condition.?.used = true;
        }
    }
}
