const std = @import("std");
const basic_block_ = @import("basic-block.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");

pub const CFG = struct {
    /// Temporary, flat instruction list before the BBs are created
    /// TODO: Maybe create a different structure for this, and CFG when creating the BBs
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

    // BIG TODO: Dependency-inject errors and allocator, so that method calls don't need that explicit passed in (they do not change from method call to method call)
    pub fn init(symbol: *symbol_.Symbol, caller: ?*CFG, interned_strings: *std.StringArrayHashMap(usize), allocator: std.mem.Allocator) !*CFG {
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
        retval.return_symbol = symbol_.Symbol.init(symbol.scope, "$retval", span_.Span{ .filename = "", .line_text = "", .col = 0, .line = 0 }, symbol._type.function.rhs, undefined, null, .mut, allocator);
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

    // BBs aren't trees, so `defer self.visited = false` won't work
    // Use this function instead
    pub fn clearVisitedBBs(self: *CFG) void {
        for (self.basic_blocks.items) |bb| {
            bb.visited = false;
        }
    }

    pub fn clearVisited(self: *CFG) void {
        self.visited = false;
        for (self.children.items) |child| {
            if (child.visited) {
                child.clearVisited();
            }
        }
    }

    // Fills in a passed in list with symbol versions which are used in the CFG
    pub fn collect_generated_symbvers(self: *CFG) void {
        for (self.basic_blocks.items) |bb| {
            var maybe_ir = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                if (ir.dest != null and
                    ir.dest.?.* == .symbver and
                    ir.dest.?.symbver.findSymbolVersionSet(&self.parameters) == null)
                {
                    _ = ir.dest.?.symbver.putSymbolVersionSet(&self.symbvers);
                }
            }
        }
    }

    pub fn appendInstruction(self: *CFG, ir: *ir_.IR) void {
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
    pub fn basicBlockFromIR(self: *CFG, maybe_ir: ?*ir_.IR, allocator: std.mem.Allocator) ?*basic_block_.Basic_Block {
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
                ir.dest.?.symbver.makeUnique();
            }

            if (ir.kind == .label) {
                // If you find a label declaration, end this block and jump to new block
                retval.has_branch = false;
                retval.next = self.basicBlockFromIR(ir.next, allocator);
                if (ir.next) |_| {
                    ir.next.?.prev = null;
                    ir.next = null;
                }
                break;
            } else if (ir.kind == .jump) {
                // If you find a jump, end this block and start new block
                retval.has_branch = false;
                if (ir.data == .branch) {
                    if (ir.data.branch) |branch| {
                        retval.next = self.basicBlockFromIR(branch.next, allocator);
                    } else {
                        retval.next = self.basicBlockFromIR(null, allocator);
                    }
                } else {
                    retval.next = null;
                }
                if (ir.next) |_| {
                    ir.next.?.prev = null;
                    ir.next = null;
                }
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
            } else if (ir.kind == .branchIfFalse) {
                // If you find a branch, end this block, start both blocks
                retval.has_branch = true;
                var branchNext: ?*ir_.IR = null; // = ir.data.branch.next; // Since ir->branch->next may get nullifued by calling this function on ir->next
                if (ir.data.branch) |branch| {
                    branchNext = branch.next;
                } else {
                    branchNext = null;
                }
                retval.next = self.basicBlockFromIR(ir.next, allocator);
                retval.branch = self.basicBlockFromIR(branchNext, allocator);
                retval.condition = ir.src1;
                if (ir.next) |_| {
                    ir.next.?.prev = null;
                    ir.next = null;
                }
                break;
            }
        }
        return retval;
    }

    pub fn removeBasicBlockLastInstruction(cfg: *CFG) void {
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

    // Determines which symbol versions need to be requested as phi parameters, and which need to be passed to children basic-blocks as phi arguments
    pub fn calculatePhiParamsAndArgs(self: *CFG, allocator: std.mem.Allocator) void {
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
        self.clearVisitedBBs();
        var i: usize = 0;
        while (self.childrenArgPropagation(self.block_graph_head orelse return, allocator)) {
            self.clearVisitedBBs();
            i += 1;
        }
        self.clearVisitedBBs();
    }

    fn version_lvalue(lval: *lval_.L_Value, bb: *basic_block_.Basic_Block, ir: ?*ir_.IR, parameters: *std.ArrayList(*lval_.Symbol_Version)) void {
        switch (lval.*) {
            .symbver => {
                var retval = lval.symbver.findVersion(bb.ir_head, ir);
                if (retval.version == null) {
                    _ = retval.putSymbolVersionSet(parameters);
                }
                lval.symbver = retval;
            },
            .dereference => {
                version_lvalue(lval.dereference.expr, bb, ir, parameters);
            },
            .index => {
                version_lvalue(lval.index.rhs, bb, ir, parameters);
                version_lvalue(lval.index.lhs, bb, ir, parameters);
                if (lval.index.upper_bound != null) {
                    version_lvalue(lval.index.upper_bound.?, bb, ir, parameters);
                }
            },
            .select => {
                version_lvalue(lval.select.lhs, bb, ir, parameters);
                if (lval.select.tag != null) {
                    version_lvalue(lval.select.tag.?, bb, ir, parameters);
                }
            },
        }
    }

    /// Finds the phi *arguments* that each basic block needs to pass along, whereas calculatePhiParamsAndArgs finds the *parameters* it needs to include.
    fn childrenArgPropagation(self: *CFG, bb: *basic_block_.Basic_Block, allocator: std.mem.Allocator) bool {
        var retval: bool = false;
        if (bb.visited) {
            return false;
        }
        bb.visited = true;

        if (bb.next) |next| {
            // Have the next block request parameters
            retval = self.childrenArgPropagation(next, allocator) or retval;

            // Go through the parameters the next block requested, see if they exist in this block.
            // Request them if they do not.
            for (next.parameters.items) |param| {
                var symbver = param.findVersion(bb.ir_head, null);
                if (symbver == param) { // Could not find param def in this block, require it as a parameter for this own block
                    const myParam = param.findSymbolVersionSet(&bb.parameters);
                    if (myParam) |_myParam| {
                        symbver = _myParam;
                    } else {
                        symbver = lval_.Symbol_Version.createUnversioned(param.symbol, allocator);
                        _ = symbver.putSymbolVersionSet(&bb.parameters);
                    }
                } // else found in this block already, add it to the arguments
                retval = symbver.putSymbolVersionSet(&bb.next_arguments) or retval;
            }
        }

        if (bb.has_branch) {
            if (bb.branch) |branch| {
                retval = self.childrenArgPropagation(branch, allocator) or retval;
                for (branch.parameters.items) |param| { // go through branch BB's params
                    var symbver = param.findVersion(bb.ir_head, null); // look for definition of param in this block
                    if (symbver == param) {
                        // Could not find param def in this block, require it as a parameter for this own block
                        const myParam = param.findSymbolVersionSet(&bb.parameters); // see if param is already in block paramlist
                        if (myParam) |_myParam| {
                            symbver = _myParam; // if so, we will add param to arglist
                        } else {
                            // else, create a new param and add to paramlist. (will later be added to arglist too)
                            symbver = lval_.Symbol_Version.createUnversioned(param.symbol, allocator);
                            _ = symbver.putSymbolVersionSet(&bb.parameters);
                        }
                    } // else found in this block already, add it to the arguments
                    retval = symbver.putSymbolVersionSet(&bb.branch_arguments) or retval;
                }
            }
        }

        return retval;
    }
};
