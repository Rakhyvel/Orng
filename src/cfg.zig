const std = @import("std");
const basic_block_ = @import("basic-block.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");

pub const CFG = struct {
    /// Temporary, flat instruction list before the BBs are created
    ir_head: ?*ir_.IR,
    ir_tail: ?*ir_.IR,

    /// Initial basic block in the basic block graph
    block_graph_head: ?*basic_block_.Basic_Block,

    /// Flat list of all basic blocks
    basic_blocks: std.ArrayList(*basic_block_.Basic_Block),

    /// All other functions called by this function
    children: std.ArrayList(*CFG),

    /// All symbol versions that are parameters to the function this CFG defines
    parameters: std.ArrayList(*lval_.Symbol_Version),

    /// All symbol versions that are used. Should be filled in after optimizations.
    symbvers: std.ArrayList(*lval_.Symbol_Version),

    /// The function that this CFG represents
    symbol: *symbol_.Symbol,

    number_temps: usize,

    return_symbol: *symbol_.Symbol,

    /// Non-owning pointer to set of interned string literals
    /// Provided by main, global to all CFGs.
    interned_strings: *std.StringArrayHashMap(usize),

    /// Whether or not this CFG is visited
    visited: bool,

    /// Address in the first instruction of this CFG
    /// Used for IR interpretation
    offset: ?i64,
    /// Number of bytes required in order to store the local variables of the function
    locals_size: ?i64,

    allocator: std.mem.Allocator,

    /// Initializes a CFG
    pub fn init(
        symbol: *symbol_.Symbol,
        caller: ?*CFG,
        interned_strings: *std.StringArrayHashMap(usize),
        allocator: std.mem.Allocator,
    ) *CFG {
        if (symbol.cfg) |cfg| {
            return cfg;
        }
        var retval = allocator.create(CFG) catch unreachable;
        retval.ir_head = null;
        retval.ir_tail = null;
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
        retval.interned_strings = interned_strings;
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
    pub fn clear_visited_BBs(self: *CFG) void {
        for (self.basic_blocks.items) |bb| {
            bb.visited = false;
        }
    }

    /// Fills in a the `symbvers` list with the symbol versions which are used in the CFG
    pub fn collect_generated_symbvers(self: *CFG) void {
        for (self.basic_blocks.items) |bb| {
            var maybe_ir = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                if (ir.dest != null and
                    ir.dest.?.* == .symbver and
                    ir.dest.?.symbver.find_symbol_version_set(&self.parameters) == null)
                {
                    _ = ir.dest.?.symbver.put_symbol_version_set(&self.symbvers);
                }
            }
        }
    }

    /// Appends an IR instruction to the end of a CFG's temporary instruction list
    pub fn append_instruction(self: *CFG, ir: *ir_.IR) void {
        if (self.ir_head == null) {
            self.ir_head = ir;
        } else if (self.ir_tail == null) {
            self.ir_head.?.next = ir;
            self.ir_tail = ir;
            self.ir_tail.?.prev = self.ir_head;
        } else {
            self.ir_tail.?.next = ir;
            ir.prev = self.ir_tail;
            self.ir_tail = ir;
        }
    }

    /// Converts the list of IR to a web of BB's
    /// Also versions IR dest's if they are symbvers. This versioning should persist and should not be wiped.
    pub fn basic_block_from_IR(self: *CFG, maybe_ir: ?*ir_.IR, allocator: std.mem.Allocator) ?*basic_block_.Basic_Block {
        if (maybe_ir == null) {
            return null;
        } else if (maybe_ir.?.in_block) |in_block| {
            return in_block;
        }
        var retval: *basic_block_.Basic_Block = basic_block_.Basic_Block.init(allocator);
        self.basic_blocks.append(retval) catch unreachable;
        retval.ir_head = maybe_ir;
        var _maybe_ir = maybe_ir;
        while (_maybe_ir) |ir| : (_maybe_ir = ir.next) {
            ir.in_block = retval;

            if (ir.dest != null and ir.dest.?.* == .symbver) {
                ir.dest.?.symbver.make_unique();
            }

            if (ir.kind == .label) {
                // If you find a label declaration, end this block and jump to new block
                retval.has_branch = false;
                retval.next = self.basic_block_from_IR(ir.next, allocator);
                ir.snip();
                break;
            } else if (ir.kind == .jump) {
                // If you find a jump, end this block and start new block
                retval.has_branch = false;
                if (ir.data == .branch) {
                    if (ir.data.branch) |branch| {
                        retval.next = self.basic_block_from_IR(branch.next, allocator);
                    } else {
                        retval.next = self.basic_block_from_IR(null, allocator);
                    }
                } else {
                    retval.next = null;
                }
                ir.snip();
                break;
            } else if (ir.kind == .panic) {
                // If you find a panic, end this block with null jump and start new block
                retval.has_branch = false;
                retval.next = null;
                retval.has_panic = true;
                if (ir.next != null and ir.next.?.next != null) {
                    ir.next.?.next.?.prev = null;
                    ir.next.?.next = null;
                }
                break;
            } else if (ir.kind == .branch_if_false) {
                // If you find a branch, end this block, start both blocks
                retval.has_branch = true;
                var branch_next: ?*ir_.IR = null; // = ir.data.branch.next;
                // Since ir->branch->next may get nullifued by calling this function on ir->next
                if (ir.data.branch) |branch| {
                    branch_next = branch.next;
                } else {
                    branch_next = null;
                }
                retval.next = self.basic_block_from_IR(ir.next, allocator);
                retval.branch = self.basic_block_from_IR(branch_next, allocator);
                retval.condition = ir.src1;
                ir.snip();
                break;
            }
        }
        return retval;
    }

    /// Removes the last instruction from each basic-block of a CFG.
    pub fn remove_last_instruction(cfg: *CFG) void {
        for (cfg.basic_blocks.items) |bb| {
            if (bb.ir_head == null) {
                continue;
            } else if (bb.ir_head.?.next == null) {
                bb.ir_head = null;
            } else {
                var maybe_ir: ?*ir_.IR = bb.ir_head;
                while (maybe_ir.?.next != null) : (maybe_ir = maybe_ir.?.next) {}
                maybe_ir.?.prev.?.next = null;
            }
        }
    }

    /// Calculates phi parameters and arguments for each basic block in the CFG.
    ///
    /// Determines the symbol versions that:
    /// - Need to be requested as phi parameters,
    /// - Need to be passed to children basic-blocks as phi arguments
    pub fn calculate_phi_params_and_args(self: *CFG, allocator: std.mem.Allocator) void {
        // clear arguments
        for (self.basic_blocks.items) |bb| {
            bb.parameters.clearRetainingCapacity();
            bb.next_arguments.clearRetainingCapacity();
            bb.branch_arguments.clearRetainingCapacity();

            // Parameters are symbols used by IR without a definition for the symbol before the IR
            var maybe_ir: ?*ir_.IR = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                if (ir.dest != null and ir.dest.?.* != .symbver) {
                    // Recursively version L_Value symbvers, if they are not a leaf symbver.
                    version_lvalue(ir.dest.?, bb, ir, &bb.parameters);
                }
                if (ir.src1 != null) {
                    // If src1 version is not null, and is not defined in this BB, request it as a parameter
                    version_lvalue(ir.src1.?, bb, ir, &bb.parameters);
                }
                if (ir.src2 != null) {
                    // If src2 version is not null, and is not defined in this BB, request it as a parameter
                    version_lvalue(ir.src2.?, bb, ir, &bb.parameters);
                }
                if (ir.data == .lval_list) {
                    // Do the same as above for each symbver in a symbver list, if there is one
                    for (ir.data.lval_list.items) |lval| {
                        version_lvalue(lval, bb, ir, &bb.parameters);
                    }
                }
            }

            if (bb.has_branch) {
                // Do the same as above for the condition of a branch, if there is one
                version_lvalue(bb.condition.?, bb, null, &bb.parameters);
            }
        }

        // Find phi arguments
        self.clear_visited_BBs();
        var i: usize = 0;
        while (self.children_arg_propagation(self.block_graph_head orelse return, allocator)) {
            self.clear_visited_BBs();
            i += 1;
        }
        self.clear_visited_BBs();
    }

    /// Recursively versions an L_Value in a basic-block. If no version can be found, adds symbol-version to
    /// the basic-block's requested phi parameters.
    fn version_lvalue(
        lval: *lval_.L_Value,
        bb: *basic_block_.Basic_Block,
        ir: ?*ir_.IR,
        parameters: *std.ArrayList(*lval_.Symbol_Version),
    ) void {
        switch (lval.*) {
            .symbver => {
                var retval = lval.symbver.find_version(bb.ir_head, ir);
                if (retval.version == null) {
                    // symbver symbol isn't defined in this basic-block
                    // request it as a parameter
                    _ = retval.put_symbol_version_set(parameters);
                }
                lval.symbver = retval;
            },
            .dereference => version_lvalue(lval.dereference.expr, bb, ir, parameters),
            .index => {
                version_lvalue(lval.index.rhs, bb, ir, parameters);
                version_lvalue(lval.index.lhs, bb, ir, parameters);
                if (lval.index.upper_bound != null) { // index is bounded, version bound lval
                    version_lvalue(lval.index.upper_bound.?, bb, ir, parameters);
                }
            },
            .select => {
                version_lvalue(lval.select.lhs, bb, ir, parameters);
                if (lval.select.tag != null) { // select is a sum-select, version expected tag
                    version_lvalue(lval.select.tag.?, bb, ir, parameters);
                }
            },
        }
    }

    /// Propagates children basic-block phi parameters up to their parent's arguments sets. Also checks that
    /// arguments are defined in parent basic-blocks, and if not, bubbles the arguments up to the parent's
    /// parameter set, too.
    fn propagate_arguments(self: *CFG, bb: *basic_block_.Basic_Block, allocator: std.mem.Allocator) bool {
        var retval: bool = false;
        if (bb.visited) {
            return false;
        }
        bb.visited = true;

        if (bb.next) |next| { // Have the next block request parameters
            retval = self.propagate_arguments(next, allocator) or
                request_undefined_args(next, bb, allocator) or
                fill_parent_args(next, bb, &bb.branch_arguments) or
                retval;
        }
        if (bb.has_branch and bb.branch != null) { // Have the branch block request parameters
            retval = self.propagate_arguments(bb.branch.?, allocator) or
                request_undefined_args(bb.branch.?, bb, allocator) or
                fill_parent_args(bb.branch.?, bb, &bb.branch_arguments) or
                retval;
        }

        return retval;
    }

    /// Checks each parameter symbver of the child basic-block. If the symbver is not defined in the parent
    /// basic-block, requests symbver as a parameter for the parent basic-block.
    fn request_undefined_args(
        child_bb: *basic_block_.Basic_Block,
        parent_bb: *basic_block_.Basic_Block,
        allocator: std.mem.Allocator,
    ) bool {
        for (child_bb.parameters.items) |parameter| {
            var symbver = parameter.find_version(parent_bb.ir_head, null); // search the entire parent bb for the last definition of `parameter`

            if (symbver == parameter) {
                // Could not find parameter def in the parent block, require it as a parameter for the parent block
                const parent_param = parameter.find_symbol_version_set(&parent_bb.parameters);
                if (parent_param != null) {
                    // was already in parent block's parameters
                    // still make sure to add `symbver` to args set later on
                    //
                    // DO NOT try to simplify this logic by adding symbver to the parameter set no matter what
                    // we need to add an BRAND NEW UNVERSIONED symbver to the parameter set, adding it no mater what would be wasteful
                    symbver = parent_param.?;
                } else {
                    // was not already in parent block's parameters
                    // add the symbver to the parent block's parameters
                    symbver = lval_.Symbol_Version.create_unversioned(parameter.symbol, allocator);
                    _ = symbver.put_symbol_version_set(&parent_bb.parameters);
                }
            } // else found in this block already, no need to request as parameter
        }
        return false;
    }

    /// Fills the parent basic-block's argument set based on the child-block's parameters
    fn fill_parent_args(
        child_bb: *basic_block_.Basic_Block,
        parent_bb: *basic_block_.Basic_Block,
        parent_args: *std.ArrayList(*lval_.Symbol_Version), // This is separate from parent_bb because it could either be `branch` or `child` args
    ) bool {
        var retval = false;

        // Add each parameter symbver of the child basic-block's parameter set to the parent basic-block's arguments
        for (child_bb.parameters.items) |parameter| {
            var symbver = parameter.find_version(parent_bb.ir_head, null); // search the entire parent bb for the last definition of `parameter`
            retval = symbver.put_symbol_version_set(parent_args) or retval;
        }

        return retval;
    }
};
