//! This file contains the definition of a Control Flow Graph (Self) data structure.

const std = @import("std");
const Basic_Block = @import("../ir/basic-block.zig");
const Instruction = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const Span = @import("../util/span.zig");
const Symbol = @import("../symbol/symbol.zig");
const Symbol_Version = @import("symbol_version.zig");

const Self = @This();

// bp offset of a frame's retval address
pub const retval_offset: i64 = -3 * @sizeOf(i64);
pub const locals_starting_offset = 8;

/// Initial basic block in the basic block graph
block_graph_head: ?*Basic_Block,

/// Flat list of all basic blocks
basic_blocks: std.ArrayList(*Basic_Block),

/// All other functions called by this function
/// TODO: Remove for LCOM4
children: std.ArrayList(*Self),

/// All symbol versions that are parameters to the function this Self defines
/// TODO: Make this it's own type, in it's own file, with `put` and `get` methods
parameters: std.ArrayList(*Symbol_Version),

/// All symbol versions that are used. Should be filled in after optimizations.
/// TODO: Make this it's own type, in it's own file, with `put` and `get` methods
symbvers: std.ArrayList(*Symbol_Version),

/// The function that this Self represents
symbol: *Symbol,

/// The symbol that is used to store the return value of this function
return_symbol: *Symbol,

/// When true, Self is called from a runtime-context at least once, and should be generated
/// Set in the lowering stage when runtime access is needed
/// TODO: Remove for LCOM4
needed_at_runtime: bool,

/// Address in the first instruction of this Self
/// Used for Instruction interpretation
/// TODO: Remove for LCOM4
offset: ?Instruction.Index,

/// Number of bytes required in order to store the local variables of the function
/// TODO: Remove for LCOM4
locals_size: ?i64,

allocator: std.mem.Allocator,

/// Initializes a Self
pub fn init(
    symbol: *Symbol,
    caller: ?*Self,
    allocator: std.mem.Allocator,
) *Self {
    if (symbol.cfg) |cfg| {
        return cfg;
    }
    var retval = allocator.create(Self) catch unreachable;
    retval.block_graph_head = null;
    retval.basic_blocks = std.ArrayList(*Basic_Block).init(allocator);
    retval.children = std.ArrayList(*Self).init(allocator);
    retval.symbvers = std.ArrayList(*Symbol_Version).init(allocator);
    retval.parameters = std.ArrayList(*Symbol_Version).init(allocator);
    retval.symbol = symbol;
    retval.return_symbol = Symbol.init(
        symbol.scope,
        "$retval",
        Span.phony,
        symbol._type.rhs(),
        undefined,
        null,
        .mut,
        allocator,
    );
    retval.return_symbol.expanded_type = retval.return_symbol._type.expand_type(allocator);
    retval.needed_at_runtime = false;
    retval.offset = null;
    retval.locals_size = null;
    retval.allocator = allocator;
    symbol.cfg = retval;

    if (caller) |caller_node| {
        caller_node.children.append(retval) catch unreachable;
    }

    return retval;
}

/// Deinitializes a Self
pub fn deinit(self: *Self) void {
    for (self.basic_blocks.items) |bb| {
        bb.deinit();
    }
    self.basic_blocks.deinit();

    self.symbvers.deinit();

    for (self.parameters.items) |param| {
        param.deinit();
    }
    self.parameters.deinit();

    self.allocator.destroy(self);
}

/// Sets the `visited` flag for all basic-blocks in this Self to false.
///
/// BBs aren't trees, so `defer self.visited = false` won't work
/// Use this function instead
pub fn clear_visited_BBs(self: *Self) void {
    for (self.basic_blocks.items) |bb| {
        bb.visited = false;
    }
}

/// Fills in a the `symbvers` list with the symbol versions which are used in the Self
pub fn collect_generated_symbvers(self: *Self) void {
    for (self.basic_blocks.items) |bb| {
        for (bb.instructions.items) |instr| {
            if (instr.dest != null and
                instr.dest.?.extract_symbver().find_symbol_version_set(&self.parameters) == null)
            {
                _ = instr.dest.?.extract_symbver().put_symbol_version_set(&self.symbvers);
            }
        }
    }
}

/// Converts the list of Instruction to a web of BB's
///
/// ### Parameters
/// - `self`: The CFG to fill the basic blocks for
/// - `instructions`: The list of instructions to convert to basic blocks
/// - `start_index`: The index into the instructions list to start the basic block at
/// - `allocator`: The allocator to use for the basic blocks
pub fn basic_block_from_instructions(self: *Self, instructions: std.ArrayList(*Instruction), start_index: ?usize) ?*Basic_Block {
    if (instructions.items.len == 0 or start_index == null) {
        return null;
    } else if (instructions.items[start_index.?].in_block) |in_block| {
        return in_block;
    }

    // Create block without instructions yet
    var block = Basic_Block.init(self.allocator);
    self.basic_blocks.append(block) catch unreachable;

    // Identify the end of the block
    var end_index: usize = start_index.?;
    while (end_index < instructions.items.len) {
        const instr = instructions.items[end_index];
        end_index += 1;
        instr.in_block = block;
        if (instr.kind == .label) {
            // Fallthrough to next basic block
            const next_block = self.basic_block_from_instructions(instructions, end_index);
            block.terminator = .{ .unconditional = next_block };
            break;
        } else if (instr.kind == .jump) {
            // Unconditional jump to other block
            const branch_next = instr.data.branch;
            const bb_index = if (branch_next != null) std.mem.indexOfScalar(*Instruction, instructions.items, branch_next.?).? + 1 else null;
            const next_block = self.basic_block_from_instructions(instructions, bb_index);
            block.terminator = .{ .unconditional = next_block };
            break;
        } else if (instr.kind == .panic) {
            // Block ends in a panic
            end_index += 1; // panics are kept as an instruction because they store the error message
            block.terminator = .panic;
            break;
        } else if (instr.kind == .branch_if_false) {
            // Branch only if condition is false else fallthrough
            const branch_next = instr.data.branch;
            const false_target_index = if (branch_next != null) std.mem.indexOfScalar(*Instruction, instructions.items, branch_next.?).? + 1 else null;
            const next_block = self.basic_block_from_instructions(instructions, end_index);
            const branch_block = self.basic_block_from_instructions(instructions, false_target_index);
            block.terminator = .{ .conditional = .{
                .condition = instr.src1.?,
                .true_target = next_block,
                .false_target = branch_block,
            } };
            break;
        }
    }

    // Assign instructions to the block
    block.instructions.appendSlice(instructions.items[start_index.? .. end_index - 1]) catch unreachable;

    return block;
}

pub fn calculate_usage(self: *Self) void {
    // FIXME: High Cyclo
    if (self.symbol.decl.?.* == .fn_decl or self.symbol.decl.?.* == .method_decl) {
        const param_symbols = if (self.symbol.decl.?.* == .fn_decl) self.symbol.decl.?.fn_decl.param_symbols else self.symbol.decl.?.method_decl.param_symbols;
        for (param_symbols.items) |param_symbol| {
            param_symbol.uses = 0;
        }
    }

    for (self.basic_blocks.items) |bb| {
        // Clear all used flags
        for (bb.instructions.items) |instr| {
            if (instr.dest != null) {
                instr.dest.?.reset_usage();
            }
        }
    }

    for (self.basic_blocks.items) |bb| {
        // Go through and see if each symbol is used
        for (bb.instructions.items) |instr| {
            if (instr.dest != null and instr.dest.?.* != .symbver) {
                instr.dest.?.calculate_lval_usage();
            }
            if (instr.src1 != null) {
                instr.src1.?.calculate_lval_usage();
            }
            if (instr.src2 != null) {
                instr.src2.?.calculate_lval_usage();
            }
            if (instr.data == .lval_list) {
                for (instr.data.lval_list.items) |lval| {
                    lval.calculate_lval_usage();
                }
            }
            if (instr.data == .invoke) {
                if (instr.data.invoke.dyn_value != null) {
                    instr.data.invoke.dyn_value.?.calculate_lval_usage();
                }
                if (instr.data.invoke.method_decl_lval != null and !instr.data.invoke.method_decl.method_decl.is_virtual) {
                    instr.data.invoke.method_decl_lval.?.calculate_lval_usage();
                }
                for (instr.data.invoke.lval_list.items) |lval| {
                    lval.calculate_lval_usage();
                }
            }
        }

        // Conditions are used
        if (bb.terminator == .conditional) {
            bb.terminator.conditional.condition.extract_symbver().uses += 1;
            bb.terminator.conditional.condition.extract_symbver().symbol.uses += 1;
        }
    }
}

pub fn calculate_definitions(self: *Self) void {
    // FIXME: High Cyclo
    for (self.basic_blocks.items) |bb| {
        // Reset all reachable symbol verison counts to 0
        for (bb.instructions.items) |instr| {
            reset_defs(instr.dest);
            reset_defs(instr.src1);
            reset_defs(instr.src2);
            if (instr.data == .lval_list) {
                for (instr.data.lval_list.items) |lval| {
                    reset_defs(lval);
                }
            }
            if (instr.data == .invoke) {
                reset_defs(instr.data.invoke.dyn_value);
                reset_defs(instr.data.invoke.method_decl_lval);
                for (instr.data.invoke.lval_list.items) |lval| {
                    reset_defs(lval);
                }
            }
        }
        self.return_symbol.defs = 0;
    }

    for (self.basic_blocks.items) |bb| {
        // Go through sum up each definition
        for (bb.instructions.items) |instr| {
            if (instr.dest != null) {
                var symbver = instr.dest.?.extract_symbver();
                symbver.def = instr;
                symbver.symbol.defs += 1;
            }
            if (instr.dest != null) {
                instr.dest.?.extract_symbver().symbol.roots += 1;
            }
            if (instr.kind == .mut_addr_of) {
                instr.src1.?.extract_symbver().symbol.aliases += 1;
            }
        }
    }
}

pub fn reset_defs(maybe_lval: ?*lval_.L_Value) void {
    if (maybe_lval == null) {
        return;
    }

    switch (maybe_lval.?.*) {
        .symbver => {
            maybe_lval.?.symbver.symbol.defs = 0;
        },
        .dereference => reset_defs(maybe_lval.?.dereference.expr),
        .index => {
            reset_defs(maybe_lval.?.index.length);
            reset_defs(maybe_lval.?.index.lhs);
            reset_defs(maybe_lval.?.index.rhs);
        },
        .select => {
            reset_defs(maybe_lval.?.select.tag);
            reset_defs(maybe_lval.?.select.lhs);
        },
        .raw_address => std.debug.panic("compiler error: undefined reset_defs for raw_address", .{}),
    }
}

pub fn count_bb_predecessors(self: *Self) void {
    // Reset all basic block predecessors to 0
    for (self.basic_blocks.items) |bb| {
        bb.number_predecessors = 0;
    }
    self.clear_visited_BBs();
    if (self.block_graph_head) |head| {
        // start predecessor count walk at head
        head.count_predecessors();
    }
}

pub fn remove_basic_block(self: *Self, bb: *Basic_Block) void {
    _ = self.basic_blocks.swapRemove(self.index_of_basic_block(bb));
}

fn index_of_basic_block(self: *Self, bb: *Basic_Block) usize {
    for (0..self.basic_blocks.items.len) |i| {
        if (bb == self.basic_blocks.items[i]) {
            return i;
        }
    } else {
        unreachable;
    }
}

pub fn get_adjacent(self: *Self) []*Self {
    return self.children.items;
}
