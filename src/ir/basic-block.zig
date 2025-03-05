// This file defines the Basic_Block struct.

const std = @import("std");
const instructions_ = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const offsets_ = @import("../hierarchy/offsets.zig");

/// Unique id for a basic-block.
var uid: u64 = 0;

/// Basic-blocks are contiguous chunks of Instruction instructions with one entry point and one exit point.
///
/// Basic-blocks use a parameter/argument system rather than the traditional phi-nodes. This means that
/// symbol-versions are passed to basic-blocks as parameters, like function parameters. This is
/// equivalently powerful to using phi-nodes, but more intuitive to reason about. Argument-parameter
/// copying can be optimized out.
pub const Basic_Block = struct {
    /// Unique id for this basic-block. Used by codegen for jump labels.
    uid: u64,
    /// Linked list of the instructions in this basic-block.
    /// TODO: Linked List type with `remove_instruction`, `get_latest_def`, and `mark_instructions_as_removed` methods
    instr_head: ?*instructions_.Instruction,
    /// List of the instructions that have been removed from this block, used for deinitialization.
    removed_instrs: std.ArrayList(*instructions_.Instruction),
    /// Whether or not this basic-block has a branch.
    has_branch: bool,
    /// Whether or not this basic-block has a panic (ie it doesn't return!)
    has_panic: bool,
    /// If null, jump to function end label
    next: ?*Basic_Block,
    /// The block to jump to if the condition is false. If null, jump to function end label.
    branch: ?*Basic_Block,
    /// The condition to use if this block has a branch.
    condition: ?*lval_.L_Value,
    /// Whether or not this block has been visited in a traversal.
    visited: bool,
    /// The number of blocks that jump to this block.
    number_predecessors: usize,
    /// The allocator used to allocate this basic-block.
    allocator: std.mem.Allocator,
    /// Address in the first instruction of this Basic_Block
    /// Used for Instruction interpretation
    offset: ?instructions_.Instruction_Idx,

    /// Initializes a basic-block
    pub fn init(allocator: std.mem.Allocator) *Basic_Block {
        var retval = allocator.create(Basic_Block) catch unreachable;
        retval.instr_head = null;
        retval.condition = null;
        retval.has_panic = false;
        retval.offset = null;
        retval.removed_instrs = std.ArrayList(*instructions_.Instruction).init(allocator);
        retval.next = null;
        retval.branch = null;
        retval.uid = uid;
        uid += 1;
        retval.allocator = allocator;
        return retval;
    }

    /// Deinitializes a basic-block
    pub fn deinit(self: *Basic_Block) void {
        var maybe_instr: ?*instructions_.Instruction = self.instr_head;
        while (maybe_instr) |instr| {
            maybe_instr = instr.next;
            instr.deinit();
        }

        for (self.removed_instrs.items) |instr| {
            instr.deinit();
        }

        self.allocator.destroy(self);
    }

    pub fn pprint(self: *Basic_Block) void {
        if (self.visited) {
            return;
        }
        self.visited = true;

        std.debug.print("BB{}", .{self.uid});
        std.debug.print(":\n", .{});
        var maybe_instr = self.instr_head;
        while (maybe_instr) |instr| : (maybe_instr = instr.next) {
            std.debug.print("{}", .{instr});
        }
        if (self.has_branch) {
            if (self.next) |next| {
                std.debug.print("    if ({}) jump BB{}", .{ self.condition.?, next.uid });
            } else {
                std.debug.print("    if ({}) return", .{self.condition.?});
            }
            std.debug.print(" ", .{});
            if (self.branch) |branch| {
                std.debug.print("else jump BB{}", .{branch.uid});
            } else {
                std.debug.print("else return", .{});
            }
        } else {
            if (self.next) |next| {
                std.debug.print("    jump BB{}", .{next.uid});
            } else {
                std.debug.print("    return", .{});
            }
        }
        std.debug.print("\n\n", .{});
        if (self.next) |next| {
            next.pprint();
        }
        if (self.branch) |branch| {
            branch.pprint();
        }
    }

    /// Removes an instruction from a basic-block
    pub fn remove_instruction(bb: *Basic_Block, instr: *instructions_.Instruction) void {
        std.debug.assert(instr.in_block == bb); // Can't remove instr from random blocks! It's gotta belong to this block!
        instr.removed = true;
        if (bb.instr_head != null and bb.instr_head == instr) {
            bb.instr_head = bb.instr_head.?.next;
        }
        if (instr.prev != null) {
            instr.prev.?.next = instr.next;
        }
        if (instr.next != null) {
            instr.next.?.prev = instr.prev;
        }
        bb.removed_instrs.append(instr) catch unreachable;
    }

    /// Gets the latest definition of an L_Value's symbol from the start of this basic-block to a stop-at Instruction. If
    /// the stop-at Instruction is `null`, will check entire block's instructions.
    ///
    /// This functions is O(n) where n is the number of instructions in the block.
    pub fn get_latest_def(
        bb: *Basic_Block,
        lval: *lval_.L_Value,
        stop_at_instr: ?*instructions_.Instruction,
    ) ?*instructions_.Instruction {
        if (lval.* != .symbver) {
            return null;
        }
        if (bb.instr_head == null) {
            return null;
        } else {
            return bb.instr_head.?.get_latest_def_after(lval.symbver.symbol, stop_at_instr);
        }
    }

    pub fn count_predecessors(bb: *Basic_Block) void {
        bb.number_predecessors += 1;
        if (bb.visited) {
            return;
        }
        bb.visited = true;
        if (bb.next) |next| {
            next.count_predecessors();
        }
        if (bb.has_branch) {
            if (bb.branch) |branch| {
                branch.count_predecessors();
            }
        }
    }

    pub fn mark_instructions_as_removed(
        bb: *Basic_Block,
    ) void {
        var maybe_instr: ?*instructions_.Instruction = bb.instr_head;
        while (maybe_instr) |instr| : (maybe_instr = instr.next) {
            instr.removed = true;
        }
    }
};
