const _ir = @import("ir.zig");
const std = @import("std");

const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const IR = _ir.IR;

pub fn optimize(cfg: *CFG, allocator: std.mem.Allocator) !void {
    while (try bbOptimizations(cfg, allocator)) {}
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
            _ = end;

            // Join next block at the end of this block

            // Copy basic block end conditions

            // Remove the next block
            std.debug.print("viable!\n", .{});
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
