const _ir = @import("ir.zig");
const std = @import("std");

const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const IR = _ir.IR;

pub fn optimize(cfg: *CFG, allocator: std.mem.Allocator) !void {
    while (try propagate(cfg) or try bbOptimizations(cfg, allocator)) {
        cfg.block_graph_head.?.pprint();
        std.debug.print("\n", .{});
    }
    cfg.clearVisitedBBs();
}

fn bbOptimizations(cfg: *CFG, allocator: std.mem.Allocator) !bool {
    var retval: bool = false;

    countPredecessors(cfg);
    try cfg.calculatePhiParamsAndArgs(allocator);

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

        // Remove constant true/false branches
        if (bb.has_branch and bb.condition.?.def == null) {
            std.debug.print("BB{}\n", .{bb.uid});
        }
        if (bb.has_branch and bb.condition.?.def != null and bb.condition.?.def.?.kind == .loadInt) {
            bb.has_branch = false;
            if (bb.condition.?.def.?.data.int == 0) {
                bb.next = bb.branch; // TODO: Swap block args?
                bb.next_arguments = bb.branch_arguments;
            }
            std.debug.print("constant branch\n", .{});
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
    _ = wipeIR;
    var i: usize = 0;
    while (i < cfg.basic_blocks.items.len) : (i += 1) {
        if (bb == cfg.basic_blocks.items[i]) {
            break;
        }
    }
    _ = cfg.basic_blocks.orderedRemove(i);
}

fn propagate(cfg: *CFG) !bool {
    var retval = false;
    for (cfg.basic_blocks.items) |bb| {
        var maybe_def = bb.ir_head;
        while (maybe_def) |def| : (maybe_def = def.next) {
            switch (def.kind) {
                .copy => {
                    // Self-copy elimination
                    if (def.dest.?.symbol == def.src1.?.symbol) {
                        std.debug.print("SELF COPY!\n", .{});
                        break;
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
                    }
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
                        std.debug.print("SELF COPY!\n", .{});
                    }
                    // Known float, float value
                    else if (def.src1.?.def != null and def.src2.?.def != null and def.src1.?.def.?.kind == .loadFloat and def.src2.?.def.?.kind == .loadFloat) {
                        def.kind = .loadInt;
                        def.data = _ir.IRData{ .int = if (def.src1.?.def.?.data.float == def.src2.?.def.?.data.float) 1 else 0 };
                        def.src1 = null;
                        def.src2 = null;
                        retval = true;
                        std.debug.print("SELF COPY!\n", .{});
                    }
                },

                else => {},
            }
        }
    }
    return retval;
}
