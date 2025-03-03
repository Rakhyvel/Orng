// This file defines the Basic_Block struct.

const std = @import("std");
const ir_ = @import("../ir/instruction.zig");
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
    uid: u64,
    instr_head: ?*ir_.Instruction,
    removed_instrs: std.ArrayList(*ir_.Instruction),
    has_branch: bool,
    has_panic: bool,
    parameters: std.ArrayList(*lval_.Symbol_Version),

    /// If null, jump to function end label
    next: ?*Basic_Block,
    next_arguments: std.ArrayList(*lval_.Symbol_Version),

    branch: ?*Basic_Block,
    condition: ?*lval_.L_Value,
    branch_arguments: std.ArrayList(*lval_.Symbol_Version),

    visited: bool,
    number_predecessors: usize,
    removed: bool,
    allocator: std.mem.Allocator,

    /// Address in the first instruction of this Basic_Block
    /// Used for Instruction interpretation
    offset: ?offsets_.Instruction_Idx,

    /// Initializes a basic-block
    pub fn init(allocator: std.mem.Allocator) *Basic_Block {
        var retval = allocator.create(Basic_Block) catch unreachable;
        retval.instr_head = null;
        retval.condition = null;
        retval.has_panic = false;
        retval.offset = null;
        retval.removed_instrs = std.ArrayList(*ir_.Instruction).init(allocator);
        retval.parameters = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.next = null;
        retval.next_arguments = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.branch = null;
        retval.branch_arguments = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.uid = uid;
        uid += 1;
        retval.allocator = allocator;
        return retval;
    }

    /// Deinitializes a basic-block
    pub fn deinit(self: *Basic_Block) void {
        for (self.parameters.items) |param| {
            param.deinit();
        }
        self.parameters.deinit();

        for (self.next_arguments.items) |arg| {
            arg.deinit();
        }
        self.next_arguments.deinit();

        for (self.branch_arguments.items) |arg| {
            arg.deinit();
        }
        self.branch_arguments.deinit();

        var maybe_instr: ?*ir_.Instruction = self.instr_head;
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
        Basic_Block.print_symbver_list(&self.parameters);
        std.debug.print(":\n", .{});
        var maybe_instr = self.instr_head;
        while (maybe_instr) |instr| : (maybe_instr = instr.next) {
            std.debug.print("{}", .{instr});
        }
        if (self.has_branch) {
            if (self.next) |next| {
                std.debug.print("    if ({}) jump BB{}", .{ self.condition.?, next.uid });
                Basic_Block.print_symbver_list(&self.next_arguments);
            } else {
                std.debug.print("    if ({}) return", .{self.condition.?});
            }
            std.debug.print(" ", .{});
            if (self.branch) |branch| {
                std.debug.print("else jump BB{}", .{branch.uid});
                Basic_Block.print_symbver_list(&self.branch_arguments);
            } else {
                std.debug.print("else return", .{});
            }
        } else {
            if (self.next) |next| {
                std.debug.print("    jump BB{}", .{next.uid});
                Basic_Block.print_symbver_list(&self.next_arguments);
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

    pub fn print_symbver_list(
        list: *std.ArrayList(*lval_.Symbol_Version),
    ) void {
        std.debug.print("(", .{});
        var i: usize = 0;
        while (i < list.items.len) : (i += 1) {
            const symbver = list.items[i];
            std.debug.print("{s}", .{symbver.symbol.name});
            if (i < list.items.len - 1) {
                std.debug.print(", ", .{});
            }
        }
        std.debug.print(")", .{});
    }

    /// Removes an instruction from a basic-block
    pub fn remove_instruction(bb: *Basic_Block, instr: *ir_.Instruction) void {
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
        stop_at_instr: ?*ir_.Instruction,
    ) ?*ir_.Instruction {
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
        var maybe_instr: ?*ir_.Instruction = bb.instr_head;
        while (maybe_instr) |instr| : (maybe_instr = instr.next) {
            instr.removed = true;
        }
    }
};
