const std = @import("std");
const ast_ = @import("ast.zig");
const basic_block_ = @import("basic-block.zig");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const lower_ = @import("lower.zig");
const lval_ = @import("lval.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;
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
    interned_strings: *std.ArrayList([]const u8),

    /// Whether or not this CFG is visited
    visited: bool,

    /// Address in the first instruction of this CFG
    /// Used for IR interpretation
    offset: ?i64,
    /// Number of bytes required in order to store the local variables of the function
    locals_size: ?i64,

    allocator: std.mem.Allocator,

    // BIG TODO: Dependency-inject errors and allocator, so that method calls don't need that explicit passed in (they do not change from method call to method call)
    pub fn create(symbol: *symbol_.Symbol, caller: ?*CFG, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors, allocator: std.mem.Allocator) !*CFG {
        if (symbol.cfg) |cfg| {
            return cfg;
        }
        var retval = try allocator.create(CFG);
        retval.ir_head = null;
        retval.ir_tail = null;
        retval.block_graph_head = null;
        retval.basic_blocks = std.ArrayList(*basic_block_.Basic_Block).init(allocator);
        retval.children = std.ArrayList(*CFG).init(allocator);
        retval.symbvers = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.parameters = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.symbol = symbol;
        retval.number_temps = 0;
        retval.return_symbol = try symbol_.Symbol.create(symbol.scope, "$retval", span_.Span{ .filename = "", .line_text = "", .col = 0, .line = 0 }, symbol._type.function.rhs, ast_.poisoned, null, .mut, allocator);
        retval.return_symbol.expanded_type = try retval.return_symbol._type.expand_type(errors, allocator);
        retval.visited = false;
        retval.interned_strings = interned_strings;
        retval.offset = null;
        retval.locals_size = null;
        retval.allocator = allocator;
        symbol.cfg = retval;

        if (caller) |caller_node| {
            try caller_node.children.append(retval);
        }

        const eval: ?*lval_.L_Value = try lower_.lower_AST(retval, symbol.init, null, null, null, null, errors, allocator);
        if (retval.symbol.decl.?.* == .fnDecl) {
            // `_comptime` symbols don't have parameters anyway
            for (retval.symbol.decl.?.fnDecl.param_symbols.items) |param| {
                try retval.parameters.append(try lval_.Symbol_Version.createUnversioned(param, allocator));
            }
        }
        const return_version = try lval_.L_Value.create_unversioned_symbver(retval.return_symbol, allocator);
        if (eval != null) {
            retval.appendInstruction(try ir_.IR.create_simple_copy(return_version, eval.?, symbol.span, allocator));
        }
        retval.appendInstruction(try ir_.IR.createJump(null, symbol.span, allocator));

        retval.block_graph_head = try retval.basicBlockFromIR(retval.ir_head, allocator);
        retval.removeBasicBlockLastInstruction();

        // for (retval.basic_blocks.items) |bb| {
        //     bb.pprint();
        // }
        // retval.clearVisitedBBs();

        try retval.calculatePhiParamsAndArgs(allocator);

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
    pub fn collect_generated_symbvers(self: *CFG) !void {
        for (self.basic_blocks.items) |bb| {
            var maybe_ir = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                if (ir.dest != null and
                    ir.dest.?.* == .symbver and
                    ir.dest.?.symbver.findSymbolVersionSet(&self.parameters) == null)
                {
                    _ = try ir.dest.?.symbver.putSymbolVersionSet(&self.symbvers);
                }
            }
        }
    }

    pub fn createTempSymbol(self: *CFG, _type: *ast_.AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*symbol_.Symbol {
        var buf = try String.init_with_contents(allocator, "t");
        try buf.writer().print("{}", .{self.number_temps});
        self.number_temps += 1;
        var temp_symbol = try symbol_.Symbol.create(self.symbol.scope, (try buf.toOwned()).?, span_.Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, _type, ast_.poisoned, null, .mut, allocator);
        temp_symbol.expanded_type = try _type.expand_type(errors, allocator);
        temp_symbol.is_temp = true;
        return temp_symbol;
    }

    pub fn createTempSymbolVersion(self: *CFG, _type: *ast_.AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*lval_.Symbol_Version {
        const temp_symbol = try self.createTempSymbol(_type, errors, allocator);
        const retval = try lval_.Symbol_Version.createUnversioned(temp_symbol, _type, allocator);
        return retval;
    }

    pub fn create_temp_lvalue(self: *CFG, _type: *ast_.AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*lval_.L_Value {
        const temp_symbol = try self.createTempSymbol(_type, errors, allocator);
        const retval = try lval_.L_Value.create_unversioned_symbver(temp_symbol, allocator);
        return retval;
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
    fn basicBlockFromIR(self: *CFG, maybe_ir: ?*ir_.IR, allocator: std.mem.Allocator) !?*basic_block_.Basic_Block {
        if (maybe_ir == null) {
            return null;
        } else if (maybe_ir.?.in_block) |in_block| {
            return in_block;
        } else {
            var retval: *basic_block_.Basic_Block = try basic_block_.Basic_Block.create(self, allocator);
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
                    retval.next = try self.basicBlockFromIR(ir.next, allocator);
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
                            retval.next = try self.basicBlockFromIR(branch.next, allocator);
                        } else {
                            retval.next = try self.basicBlockFromIR(null, allocator);
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
                    retval.next = try self.basicBlockFromIR(ir.next, allocator);
                    retval.branch = try self.basicBlockFromIR(branchNext, allocator);
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
    }

    fn removeBasicBlockLastInstruction(cfg: *CFG) void {
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
    pub fn calculatePhiParamsAndArgs(self: *CFG, allocator: std.mem.Allocator) !void {
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
                    try version_lvalue(ir.dest.?, bb, ir, &bb.parameters);
                }
                if (ir.src1 != null) {
                    // If src1 version is not null, and is not defined in this BB, request it as a parameter
                    try version_lvalue(ir.src1.?, bb, ir, &bb.parameters);
                }
                if (ir.src2 != null) {
                    // If src2 version is not null, and is not defined in this BB, request it as a parameter
                    try version_lvalue(ir.src2.?, bb, ir, &bb.parameters);
                }

                if (ir.data == .lval_list) {
                    // Do the same as above for each symbver in a symbver list, if there is one
                    for (ir.data.lval_list.items) |lval| {
                        try version_lvalue(lval, bb, ir, &bb.parameters);
                    }
                }
            }

            if (bb.has_branch) {
                // Do the same as above for the condition of a branch, if there is one
                try version_lvalue(bb.condition.?, bb, null, &bb.parameters);
            }
        }

        // Find phi arguments
        self.clearVisitedBBs();
        var i: usize = 0;
        while (try self.childrenArgPropagation(self.block_graph_head orelse return, allocator)) {
            self.clearVisitedBBs();
            i += 1;
        }
        self.clearVisitedBBs();
    }

    fn version_lvalue(lval: *lval_.L_Value, bb: *basic_block_.Basic_Block, ir: ?*ir_.IR, parameters: *std.ArrayList(*lval_.Symbol_Version)) !void {
        switch (lval.*) {
            .symbver => {
                var retval = lval.symbver.findVersion(bb.ir_head, ir);
                if (retval.version == null) {
                    _ = try retval.putSymbolVersionSet(parameters);
                }
                lval.symbver = retval;
            },
            .dereference => {
                try version_lvalue(lval.dereference.expr, bb, ir, parameters);
            },
            .index => {
                try version_lvalue(lval.index.rhs, bb, ir, parameters);
                try version_lvalue(lval.index.lhs, bb, ir, parameters);
                if (lval.index.upper_bound != null) {
                    try version_lvalue(lval.index.upper_bound.?, bb, ir, parameters);
                }
            },
            .select => {
                try version_lvalue(lval.select.lhs, bb, ir, parameters);
                if (lval.select.tag != null) {
                    try version_lvalue(lval.select.tag.?, bb, ir, parameters);
                }
            },
        }
    }

    /// Finds the phi *arguments* that each basic block needs to pass along, whereas calculatePhiParamsAndArgs finds the *parameters* it needs to include.
    fn childrenArgPropagation(self: *CFG, bb: *basic_block_.Basic_Block, allocator: std.mem.Allocator) !bool {
        var retval: bool = false;
        if (bb.visited) {
            return false;
        }
        bb.visited = true;

        if (bb.next) |next| {
            // Have the next block request parameters
            retval = try self.childrenArgPropagation(next, allocator) or retval;

            // Go through the parameters the next block requested, see if they exist in this block.
            // Request them if they do not.
            for (next.parameters.items) |param| {
                var symbver = param.findVersion(bb.ir_head, null);
                if (symbver == param) { // Could not find param def in this block, require it as a parameter for this own block
                    const myParam = param.findSymbolVersionSet(&bb.parameters);
                    if (myParam) |_myParam| {
                        symbver = _myParam;
                    } else {
                        symbver = try lval_.Symbol_Version.createUnversioned(param.symbol, allocator);
                        _ = try symbver.putSymbolVersionSet(&bb.parameters);
                    }
                } // else found in this block already, add it to the arguments
                retval = try symbver.putSymbolVersionSet(&bb.next_arguments) or retval;
            }
        }

        if (bb.has_branch) {
            if (bb.branch) |branch| {
                retval = try self.childrenArgPropagation(branch, allocator) or retval;
                for (branch.parameters.items) |param| { // go through branch BB's params
                    var symbver = param.findVersion(bb.ir_head, null); // look for definition of param in this block
                    if (symbver == param) {
                        // Could not find param def in this block, require it as a parameter for this own block
                        const myParam = param.findSymbolVersionSet(&bb.parameters); // see if param is already in block paramlist
                        if (myParam) |_myParam| {
                            symbver = _myParam; // if so, we will add param to arglist
                        } else {
                            // else, create a new param and add to paramlist. (will later be added to arglist too)
                            symbver = try lval_.Symbol_Version.createUnversioned(param.symbol, allocator);
                            _ = try symbver.putSymbolVersionSet(&bb.parameters);
                        }
                    } // else found in this block already, add it to the arguments
                    retval = try symbver.putSymbolVersionSet(&bb.branch_arguments) or retval;
                }
            }
        }

        return retval;
    }
};
