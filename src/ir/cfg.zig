// This file contains the definition of a Control Flow Graph (CFG) data structure.
// TODO: Create Instruction list, which gets converted to a BB graph
//   * `pub using namespace @import("ssa.zig");` for ['propagate_arguments', 'collect_generated_symbvers', 'count_bb_predecessors', 'fill_parent_args', 'calculate_phi_params_and_args', 'clear_visited_BBs']
//   * `pub using namespace @import("use-def-analysis.zig");` for ['calculate_versions', 'calculate_usage']

const std = @import("std");
const basic_block_ = @import("../ir/basic-block.zig");
const ir_ = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const module_ = @import("../hierarchy/module.zig");
const offsets_ = @import("../hierarchy/offsets.zig");
const span_ = @import("../util/span.zig");
const symbol_ = @import("../symbol/symbol.zig");

pub const CFG = struct {
    /// Temporary, flat instruction list before the BBs are created
    /// TODO: Linked Instruction list
    instr_head: ?*ir_.Instruction,
    instr_tail: ?*ir_.Instruction,

    /// Initial basic block in the basic block graph
    block_graph_head: ?*basic_block_.Basic_Block,

    /// Flat list of all basic blocks
    basic_blocks: std.ArrayList(*basic_block_.Basic_Block),

    /// All other functions called by this function
    children: std.ArrayList(*CFG),

    /// All symbol versions that are parameters to the function this CFG defines
    /// TODO: Make this it's own type, in it's own file, with `put` and `get` methods
    parameters: std.ArrayList(*lval_.Symbol_Version),

    /// All symbol versions that are used. Should be filled in after optimizations.
    /// TODO: Make this it's own type, in it's own file, with `put` and `get` methods
    symbvers: std.ArrayList(*lval_.Symbol_Version),

    /// The function that this CFG represents
    symbol: *symbol_.Symbol,

    /// The module that this CFG belongs to
    module: *module_.Module,

    number_temps: usize,

    return_symbol: *symbol_.Symbol,

    /// Whether or not this CFG is visited
    visited: bool,

    /// When true, CFG is called from a runtime-context at least once, and should be generated
    /// Set in the lowering stage when runtime access is needed
    needed_at_runtime: bool,

    /// Address in the first instruction of this CFG
    /// Used for Instruction interpretation
    offset: ?offsets_.Instruction_Idx,
    /// Number of bytes required in order to store the local variables of the function
    locals_size: ?i64,

    allocator: std.mem.Allocator,

    /// Initializes a CFG
    pub fn init(
        symbol: *symbol_.Symbol,
        caller: ?*CFG,
        allocator: std.mem.Allocator,
    ) *CFG {
        if (symbol.cfg) |cfg| {
            return cfg;
        }
        var retval = allocator.create(CFG) catch unreachable;
        retval.instr_head = null;
        retval.instr_tail = null;
        retval.block_graph_head = null;
        retval.basic_blocks = std.ArrayList(*basic_block_.Basic_Block).init(allocator);
        retval.children = std.ArrayList(*CFG).init(allocator);
        retval.symbvers = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.parameters = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.symbol = symbol;
        retval.number_temps = 0;
        retval.return_symbol = symbol_.Symbol.init(
            symbol.scope,
            "$retval",
            span_.phony_span,
            symbol._type.rhs(),
            undefined,
            null,
            .mut,
            allocator,
        );
        retval.return_symbol.expanded_type = retval.return_symbol._type.expand_type(allocator);
        retval.visited = false;
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

    /// Deinitializes a CFG
    pub fn deinit(self: *CFG) void {
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

    /// Sets the `visited` flag for all basic-blocks in this CFG to false.
    ///
    /// BBs aren't trees, so `defer self.visited = false` won't work
    /// Use this function instead
    pub fn clear_visited_BBs(
        self: *CFG,
    ) void {
        for (self.basic_blocks.items) |bb| {
            bb.visited = false;
        }
    }

    /// Fills in a the `symbvers` list with the symbol versions which are used in the CFG
    pub fn collect_generated_symbvers(self: *CFG) void {
        for (self.basic_blocks.items) |bb| {
            var maybe_instr = bb.instr_head;
            while (maybe_instr) |instr| : (maybe_instr = instr.next) {
                if (instr.dest != null and
                    instr.dest.?.extract_symbver().find_symbol_version_set(&self.parameters) == null)
                {
                    _ = instr.dest.?.extract_symbver().put_symbol_version_set(&self.symbvers);
                }
            }
        }
    }

    /// Appends an Instruction instruction to the end of a CFG's temporary instruction list
    pub fn append_instruction(self: *CFG, instr: *ir_.Instruction) void {
        if (self.instr_head == null) {
            self.instr_head = instr;
        } else if (self.instr_tail == null) {
            self.instr_head.?.next = instr;
            self.instr_tail = instr;
            self.instr_tail.?.prev = self.instr_head;
        } else {
            self.instr_tail.?.next = instr;
            instr.prev = self.instr_tail;
            self.instr_tail = instr;
        }
    }

    /// Converts the list of Instruction to a web of BB's
    /// Also versions Instruction dest's if they are symbvers. This versioning should persist and should not be wiped.
    pub fn basic_block_from_instructions(self: *CFG, maybe_instr: ?*ir_.Instruction, allocator: std.mem.Allocator) ?*basic_block_.Basic_Block {
        // FIXME: High Cyclo
        if (maybe_instr == null) {
            return null;
        } else if (maybe_instr.?.in_block) |in_block| {
            return in_block;
        }
        var retval: *basic_block_.Basic_Block = basic_block_.Basic_Block.init(allocator);
        self.basic_blocks.append(retval) catch unreachable; // TODO: If you just accept a list, you don't even need this function to be in CFG!
        retval.instr_head = maybe_instr;
        var _maybe_instr = maybe_instr;
        while (_maybe_instr) |instr| : (_maybe_instr = instr.next) {
            // TODO: Too long
            instr.in_block = retval;

            if (instr.kind == .label) {
                // If you find a label declaration, end this block and jump to new block
                retval.has_branch = false;
                retval.next = self.basic_block_from_instructions(instr.next, allocator);
                instr.snip();
                break;
            } else if (instr.kind == .jump) {
                // If you find a jump, end this block and start new block
                retval.has_branch = false;
                if (instr.data == .branch) {
                    if (instr.data.branch) |branch| {
                        retval.next = self.basic_block_from_instructions(branch.next, allocator);
                    } else {
                        retval.next = self.basic_block_from_instructions(null, allocator);
                    }
                } else {
                    retval.next = null;
                }
                instr.snip();
                break;
            } else if (instr.kind == .panic) {
                // If you find a panic, end this block with null jump and start new block
                retval.has_branch = false;
                retval.next = null;
                retval.has_panic = true;
                if (instr.next != null and instr.next.?.next != null) {
                    instr.next.?.next.?.prev = null;
                    instr.next.?.next = null;
                }
                break;
            } else if (instr.kind == .branch_if_false) {
                // If you find a branch, end this block, start both blocks
                retval.has_branch = true;
                var branch_next: ?*ir_.Instruction = null; // = instr.data.branch.next;
                // Since instr->branch->next may get nullifued by calling this function on instr->next
                if (instr.data.branch) |branch| {
                    branch_next = branch.next;
                } else {
                    branch_next = null;
                }
                retval.next = self.basic_block_from_instructions(instr.next, allocator);
                retval.branch = self.basic_block_from_instructions(branch_next, allocator);
                retval.condition = instr.src1;
                instr.snip();
                break;
            }
        }
        return retval;
    }

    /// Removes the last instruction from each basic-block of a CFG.
    pub fn remove_last_instruction(
        cfg: *CFG,
    ) void {
        for (cfg.basic_blocks.items) |bb| {
            if (bb.instr_head == null) {
                continue;
            } else if (bb.instr_head.?.next == null) {
                bb.instr_head = null;
            } else {
                var maybe_instr: ?*ir_.Instruction = bb.instr_head;
                while (maybe_instr.?.next != null) : (maybe_instr = maybe_instr.?.next) {}
                maybe_instr.?.prev.?.next = null;
            }
        }
    }

    pub fn calculate_usage(cfg: *CFG) void {
        // FIXME: High Cyclo
        if (cfg.symbol.decl.?.* == .fn_decl or cfg.symbol.decl.?.* == .method_decl) {
            const param_symbols = if (cfg.symbol.decl.?.* == .fn_decl) cfg.symbol.decl.?.fn_decl.param_symbols else cfg.symbol.decl.?.method_decl.param_symbols;
            for (param_symbols.items) |param_symbol| {
                param_symbol.uses = 0;
            }
        }

        for (cfg.basic_blocks.items) |bb| {
            // Clear all used flags
            var maybe_instr: ?*ir_.Instruction = bb.instr_head;
            while (maybe_instr) |instr| : (maybe_instr = instr.next) {
                if (instr.dest != null) {
                    instr.dest.?.reset_usage();
                }
            }
        }

        for (cfg.basic_blocks.items) |bb| {
            // Go through and see if each symbol is used
            var maybe_instr = bb.instr_head;
            while (maybe_instr) |instr| : (maybe_instr = instr.next) {
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
            if (bb.has_branch) {
                bb.condition.?.extract_symbver().uses += 1;
                bb.condition.?.extract_symbver().symbol.uses += 1;
            }
        }
    }

    pub fn calculate_definitions(cfg: *CFG) void {
        // FIXME: High Cyclo
        for (cfg.basic_blocks.items) |bb| {
            // Reset all reachable symbol verison counts to 0
            var maybe_instr: ?*ir_.Instruction = bb.instr_head;
            while (maybe_instr) |instr| : (maybe_instr = instr.next) {
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
            cfg.return_symbol.defs = 0;
        }

        for (cfg.basic_blocks.items) |bb| {
            // Go through sum up each definition
            var maybe_instr: ?*ir_.Instruction = bb.instr_head;
            while (maybe_instr) |instr| : (maybe_instr = instr.next) {
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

    pub fn count_bb_predecessors(cfg: *CFG) void {
        // Reset all basic block predecessors to 0
        for (cfg.basic_blocks.items) |bb| {
            bb.number_predecessors = 0;
        }
        cfg.clear_visited_BBs();
        if (cfg.block_graph_head) |head| {
            // start predecessor count walk at head
            head.count_predecessors();
        }
    }

    pub fn remove_basic_block(cfg: *CFG, bb: *basic_block_.Basic_Block) void {
        _ = cfg.basic_blocks.swapRemove(cfg.index_of_basic_block(bb));
    }

    fn index_of_basic_block(
        cfg: *CFG,
        bb: *basic_block_.Basic_Block,
    ) usize {
        for (0..cfg.basic_blocks.items.len) |i| {
            if (bb == cfg.basic_blocks.items[i]) {
                return i;
            }
        } else {
            unreachable;
        }
    }
};
