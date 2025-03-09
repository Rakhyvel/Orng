//! Basic-blocks are contiguous chunks of Instruction instructions with one entry point and one exit point.
//!
//! Basic-blocks use a parameter/argument system rather than the traditional phi-nodes. This means that
//! symbol-versions are passed to basic-blocks as parameters, like function parameters. This is
//! equivalently powerful to using phi-nodes, but more intuitive to reason about. Argument-parameter
//! copying can be optimized out.

const std = @import("std");
const Instruction = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const Symbol = @import("../symbol/symbol.zig");

const Self = @This();

/// Static counter for unique basic-block ids.
var uid_counter: u64 = 0;

/// Unique id for this basic-block. Used by codegen for jump labels.
uid: u64,
/// Linked list of the instructions in this basic-block.
instructions: std.ArrayList(*Instruction),
/// The end-condition for this basic-block.
terminator: union(enum) {
    unconditional: ?*Self,
    conditional: struct {
        true_target: ?*Self,
        false_target: ?*Self,
        condition: *lval_.L_Value,
    },
    panic,
},
/// List of the instructions that have been removed from this block, used for deinitialization.
removed_instrs: std.ArrayList(*Instruction),
/// Whether or not this block has been visited in a traversal.
visited: bool,
/// The number of blocks that jump to this block.
number_predecessors: usize,
/// The allocator used to allocate this basic-block.
allocator: std.mem.Allocator,
/// Address in the first instruction of this Self
/// Used for Instruction interpretation
offset: ?Instruction.Index,

/// Initializes a basic-block
pub fn init(allocator: std.mem.Allocator) *Self {
    var retval = allocator.create(Self) catch unreachable;
    retval.instructions = std.ArrayList(*Instruction).init(allocator); // Starts off undefined, set by CFG's basic_block_from_instructions function
    retval.terminator = .panic;
    retval.offset = null;
    retval.removed_instrs = std.ArrayList(*Instruction).init(allocator);
    retval.uid = uid_counter;
    uid_counter += 1;
    retval.allocator = allocator;
    return retval;
}

/// Deinitializes a basic-block
pub fn deinit(self: *Self) void {
    for (self.instructions.items) |instr| {
        instr.deinit();
    }
    self.instructions.deinit();

    for (self.removed_instrs.items) |instr| {
        instr.deinit();
    }
    self.removed_instrs.deinit();

    self.allocator.destroy(self);
}

pub fn pprint(self: *Self) void {
    if (self.visited) {
        return;
    }
    self.visited = true;

    std.debug.print("BB{}", .{self.uid});
    std.debug.print(":\n", .{});
    for (self.instructions.items) |instr| {
        std.debug.print("{}", .{instr});
    }
    switch (self.terminator) {
        .unconditional => {
            if (self.terminator.unconditional) |next| {
                std.debug.print("    jump BB{}", .{next.uid});
            } else {
                std.debug.print("    return", .{});
            }
        },
        .conditional => {
            if (self.terminator.conditional.true_target) |next| {
                std.debug.print("    if ({}) jump BB{}", .{ self.terminator.conditional.condition, next.uid });
            } else {
                std.debug.print("    if ({}) return", .{self.terminator.conditional.condition});
            }
            std.debug.print(" ", .{});
            if (self.terminator.conditional.false_target) |branch| {
                std.debug.print("else jump BB{}", .{branch.uid});
            } else {
                std.debug.print("else return", .{});
            }
        },
        .panic => {
            std.debug.print("    panic", .{});
        },
    }
    std.debug.print("\n\n", .{});
    if (self.terminator == .unconditional and self.terminator.unconditional != null) {
        self.terminator.unconditional.?.pprint();
    }
    if (self.terminator == .conditional) {
        if (self.terminator.conditional.true_target) |next| {
            next.pprint();
        }
        if (self.terminator.conditional.false_target) |branch| {
            branch.pprint();
        }
    }
}

pub fn empty(self: *Self) bool {
    return self.instructions.items.len == 0;
}

pub fn first_instruction(self: *Self) *Instruction {
    return self.instructions.items[0];
}

pub fn remove_last_instruction(self: *Self) void {
    if (self.empty()) {
        return;
    }
    const last_instr = self.instructions.items[self.instructions.items.len - 1];
    self.remove_instruction(last_instr);
}

/// Removes an instruction from a basic-block
pub fn remove_instruction(self: *Self, instr: *Instruction) void {
    std.debug.assert(instr.in_block == self); // Can't remove instr from random blocks! It's gotta belong to this block!
    std.debug.assert(!instr.removed); // Can't remove an instruction twice!
    std.debug.assert(!self.empty()); // Can't remove an instruction from an empty block!

    instr.removed = true;
    const idx = std.mem.indexOfScalar(*Instruction, self.instructions.items, instr).?;
    _ = self.instructions.orderedRemove(idx);
}

pub fn remove_marked_instrs(self: *Self) void {
    var i: usize = 0;
    while (i < self.instructions.items.len) {
        const instr = self.instructions.items[i];
        if (instr.removed) {
            _ = self.instructions.orderedRemove(i);
        } else {
            i += 1;
        }
    }
}

/// Appends the instructions of the other basic block to this one, and copies the terminator. The other basic-block is
/// then deinitialized.
pub fn merge_with(self: *Self, other: *Self) void {
    for (other.instructions.items) |instr| {
        instr.in_block = self;
        self.instructions.append(instr) catch unreachable;
    }
    self.terminator = other.terminator;
}

// This function is O(n)
pub fn any_def_after(self: *Self, start_at_instr: *Instruction, symbol: *Symbol, stop_at_instr: ?*Instruction) ?*Instruction {
    const idx = std.mem.indexOfScalar(*Instruction, self.instructions.items, start_at_instr);
    if (idx == null) {
        return null;
    }
    // This loop searches for the next definition of the symbol after the start_at_instr
    for (self.instructions.items[idx.?..]) |instr| {
        if (instr == stop_at_instr) {
            break;
        }
        if (instr.dest != null and instr.dest.?.* == .select and instr.dest.?.extract_symbver().symbol == symbol) {
            return instr;
        } else if (instr.dest != null and instr.dest.?.* == .index and instr.dest.?.extract_symbver().symbol == symbol) {
            return instr;
        } else if (instr.kind == .mut_addr_of and instr.src1.?.extract_symbver().symbol == symbol) {
            return instr;
        } else if (instr.dest != null and instr.dest.?.* == .symbver and instr.dest.?.symbver.symbol == symbol) {
            return instr;
        }
    }
    return null;
}

/// Gets the latest definition of an L_Value's symbol from the start of this basic-block to a stop-at Instruction. If
/// the stop-at Instruction is `null`, will check entire block's instructions.
///
/// This functions is O(n) where n is the number of instructions in the block.
pub fn get_latest_def(
    self: *Self,
    lval: *lval_.L_Value,
    stop_at_instr: ?*Instruction,
) ?*Instruction {
    if (lval.* != .symbver) {
        return null;
    }
    if (self.empty()) {
        return null;
    } else {
        return self.get_latest_def_after(self.first_instruction(), lval.symbver.symbol, stop_at_instr);
    }
}

/// This function is O(n) in terms of Instruction between start and stop
pub fn get_latest_def_after(self: *Self, start_at_instr: *Instruction, symbol: *Symbol, stop_at_instr: ?*Instruction) ?*Instruction {
    var retval: ?*Instruction = null;
    const idx = std.mem.indexOfScalar(*Instruction, self.instructions.items, start_at_instr);
    if (idx == null) {
        return null;
    }
    for (self.instructions.items[idx.?..]) |instr| {
        if (instr == stop_at_instr) {
            break;
        }
        if (instr.dest != null and instr.dest.?.* == .select and instr.dest.?.extract_symbver().symbol == symbol) {
            return null;
        } else if (instr.dest != null and instr.dest.?.* == .index and instr.dest.?.extract_symbver().symbol == symbol) {
            return null;
        } else if (instr.dest != null and instr.dest.?.* == .symbver and instr.dest.?.symbver.symbol == symbol) {
            retval = instr;
        } else if (instr.kind == .mut_addr_of and instr.src1.?.extract_symbver().symbol == symbol) {
            retval = null;
        }
    }
    return retval;
}

pub fn count_predecessors(self: *Self) void {
    self.number_predecessors += 1;
    if (self.visited) {
        return;
    }
    self.visited = true;
    switch (self.terminator) {
        .unconditional => |uncond| {
            if (uncond) |next| {
                next.count_predecessors();
            }
        },
        .conditional => |cond| {
            if (cond.true_target) |true_target| {
                true_target.count_predecessors();
            }
            if (cond.false_target) |false_target| {
                false_target.count_predecessors();
            }
        },
        .panic => {},
    }
}

pub fn mark_instructions_as_removed(self: *Self) void {
    for (self.instructions.items) |instr| {
        instr.removed = true;
    }
}
