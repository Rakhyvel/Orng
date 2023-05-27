const errs = @import("errors.zig");
const span = @import("span.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");
const _string = @import("zig-string/zig-string.zig");

const AST = @import("ast.zig").AST;
const Error = errs.Error;
const Scope = _symbol.Scope;
const Symbol = _symbol.Symbol;

pub const SymbolVersion = struct {
    symbol: *Symbol,
    version: ?u64,
    def: ?*IR,

    lvalue: bool,
    used: bool,

    /// Type of the SymbolVersion. Temps use the same symbol, so can't use that for type info
    type: *AST,

    fn createUnversioned(symbol: *Symbol, _type: *AST, allocator: std.mem.Allocator) !*SymbolVersion {
        var retval = try allocator.create(SymbolVersion);
        retval.symbol = symbol;
        retval.version = null;
        retval.type = _type;
        retval.lvalue = false;
        retval.def = null;
        return retval;
    }

    pub fn makeUnique(self: *SymbolVersion) void {
        if (self.version == null) {
            self.version = self.symbol.versions;
            self.symbol.versions += 1;
        }
    }

    fn pprint(self: ?*SymbolVersion) void {
        if (self) |symbver| {
            if (symbver.lvalue) {
                std.debug.print("L", .{});
            }
            std.debug.print("{s}_{?}\t", .{ symbver.symbol.name, symbver.version });
        } else {
            std.debug.print("<null>\t", .{});
        }
    }

    fn findVersion(self: *SymbolVersion, ir: ?*IR, stop: ?*IR) *SymbolVersion {
        var retval: *SymbolVersion = self;
        var maybe_ir = ir;
        while (maybe_ir != null and maybe_ir != stop) : (maybe_ir = maybe_ir.?.next) {
            if (maybe_ir.?.dest != null and maybe_ir.?.dest.?.symbol == self.symbol) {
                retval = maybe_ir.?.dest.?;
            }
        }
        return retval;
    }

    pub fn findSymbolVersionSet(self: *SymbolVersion, set: *std.ArrayList(*SymbolVersion)) ?*SymbolVersion {
        for (set.items) |symbver| {
            if (symbver.symbol == self.symbol) {
                return symbver;
            }
        }
        return null;
    }

    fn putSymbolVersionSet(self: *SymbolVersion, set: *std.ArrayList(*SymbolVersion)) !bool {
        for (set.items) |v| {
            if (v.symbol == self.symbol) {
                return false;
            }
        }
        try set.append(self);
        return true;
    }
};

var ir_uid: u64 = 0;
pub const IRKind = enum {
    // nullary instructions
    loadSymbol,
    loadExtern,
    loadInt,
    loadFloat,
    loadArglist, // TODO: ?
    loadArrayLiteral, // TODO: ?
    loadDefaultArray, // TODO: ?
    loadString, // TODO: ?
    decl,

    // Monadic instructions
    copy,
    not,
    negate,
    bitNot,
    addrOf,
    sizeOf, //< For extern types that Orng can't do automatically
    dereference,
    derefCopy,

    // Diadic instructions
    bitOr,
    bitXor,
    bitAnd,
    equal,
    notEqual,
    greater,
    lesser,
    greaterEqual,
    lesserEqual,
    leftShift,
    rightShift,
    add,
    sub,
    mult,
    div,
    mod,
    exponent,
    index,
    indexCopy,
    subSlice,
    select,
    selectCopy,
    cast,

    // Control-flow
    label,
    jump,
    branchIfFalse,
    call,

    // Errors
    pushStackTrace,
    clearStackTrace,
    throw,
};

pub const IRData = union(enum) {
    branch: ?*IR,
    int: i128,
    float: f64,
    string: []const u8,
    symbol: *Symbol,
    irList: std.ArrayList(*IR),
    symbverList: std.ArrayList(*SymbolVersion),

    none,
};

pub const IR = struct {
    uid: u64,
    kind: IRKind,
    dest: ?*SymbolVersion,
    src1: ?*SymbolVersion,
    src2: ?*SymbolVersion,

    data: IRData,
    next: ?*IR,
    prev: ?*IR,

    in_block: ?*BasicBlock,

    removed: bool,

    pub fn create(kind: IRKind, dest: ?*SymbolVersion, src1: ?*SymbolVersion, src2: ?*SymbolVersion, allocator: std.mem.Allocator) !*IR {
        var retval = try allocator.create(IR);
        retval.kind = kind;
        retval.dest = dest;
        retval.src1 = src1;
        retval.src2 = src2;
        retval.uid = ir_uid;
        retval.in_block = null;
        retval.prev = null;
        retval.next = null;
        retval.data = IRData.none;
        ir_uid += 1;
        return retval;
    }

    fn createDecl(dest: *SymbolVersion, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.decl, dest, null, null, allocator);
        return retval;
    }

    fn createInt(dest: *SymbolVersion, int: i128, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadInt, dest, null, null, allocator);
        retval.data = IRData{ .int = int };
        return retval;
    }

    fn createFloat(dest: *SymbolVersion, float: f64, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadFloat, dest, null, null, allocator);
        retval.data = IRData{ .float = float };
        return retval;
    }

    fn createString(dest: *SymbolVersion, string: []const u8, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadString, dest, null, null, allocator);
        retval.data = IRData{ .string = string };
        return retval;
    }

    fn createLabel(allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.label, null, null, null, allocator);
        return retval;
    }

    fn createBranch(condition: *SymbolVersion, label: *IR, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.branchIfFalse, null, condition, null, allocator);
        retval.data = IRData{ .branch = label };
        return retval;
    }

    fn createJump(label: ?*IR, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.jump, null, null, null, allocator);
        retval.data = IRData{ .branch = label };
        return retval;
    }

    fn createCall(dest: *SymbolVersion, src1: *SymbolVersion, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.call, dest, src1, null, allocator);
        retval.data = IRData{ .symbverList = std.ArrayList(*SymbolVersion).init(allocator) };
        return retval;
    }

    pub fn getTail(self: *IR) *IR {
        var mut_self: *IR = self;
        while (mut_self.next != null) : (mut_self = mut_self.next.?) {}
        return mut_self;
    }

    pub fn pprint(self: *IR) void {
        if (self.kind == .label) {
            std.debug.print("BB{}:\n", .{self.uid});
        } else {
            const kind_name = @tagName(self.kind);
            std.debug.print("{}\t{s}", .{ self.uid, kind_name });
            var i: u64 = 17 - kind_name.len;
            while (i > 0) : (i -= 1) {
                std.debug.print(" ", .{});
            }
            SymbolVersion.pprint(self.dest);
            SymbolVersion.pprint(self.src1);
            SymbolVersion.pprint(self.src2);
            switch (self.data) {
                .branch => {
                    if (self.data.branch) |branch| {
                        std.debug.print("\tBB{}", .{branch.uid});
                    }
                },
                .int => {
                    std.debug.print("\tint:{}", .{self.data.int});
                },
                .float => {
                    std.debug.print("\tfloat:{}", .{self.data.float});
                },
                .string => {
                    std.debug.print("\tstring:{s}", .{self.data.string});
                },
                .symbol => {
                    std.debug.print("\tsymbol:{s}", .{self.data.symbol.name});
                },
                else => {},
            }
            std.debug.print("\n", .{});
        }
    }
};

pub const BasicBlock = struct {
    uid: u64,
    ir_head: ?*IR,
    has_branch: bool,
    parameters: std.ArrayList(*SymbolVersion),

    /// If null, jump to function end label
    next: ?*BasicBlock,
    next_arguments: std.ArrayList(*SymbolVersion),

    branch: ?*BasicBlock,
    condition: ?*SymbolVersion,
    branch_arguments: std.ArrayList(*SymbolVersion),

    visited: bool,
    number_predecessors: usize,

    pub fn pprint(self: *BasicBlock) void {
        if (self.visited) {
            return;
        }
        self.visited = true;

        std.debug.print("Basic Block BB{}", .{self.uid});
        BasicBlock.printSymbverList(&self.parameters);
        var maybe_ir = self.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            ir.pprint();
        }
        if (self.has_branch) {
            if (self.branch) |branch| {
                std.debug.print("if (!{s}_{?}) goto {}", .{ self.condition.?.symbol.name, self.condition.?.version, branch.uid });
                BasicBlock.printSymbverList(&self.branch_arguments);
            } else {
                std.debug.print("if (!{s}_{?}) goto <END>", .{ self.condition.?.symbol.name, self.condition.?.version });
                BasicBlock.printSymbverList(&self.branch_arguments);
            }
        }
        if (self.next) |next| {
            std.debug.print("goto {}", .{next.uid});
            BasicBlock.printSymbverList(&self.next_arguments);
        } else {
            std.debug.print("goto <END>", .{});
            BasicBlock.printSymbverList(&self.next_arguments);
        }
        if (self.branch) |branch| {
            branch.pprint();
        }
        if (self.next) |next| {
            next.pprint();
        }
    }

    fn printSymbverList(list: *std.ArrayList(*SymbolVersion)) void {
        std.debug.print("(", .{});
        var i: usize = 0;
        while (i < list.items.len) : (i += 1) {
            var symbver = list.items[i];
            std.debug.print("{s}_{?}", .{ symbver.symbol.name, symbver.version });
            if (i < list.items.len - 1) {
                std.debug.print(", ", .{});
            }
        }
        std.debug.print(")\n", .{});
    }

    pub fn appendInstruction(self: *BasicBlock, ir: *IR) *IR {
        if (self.ir_head == null) {
            self.ir_head = ir;
        } else {
            ir.in_block = self;
            var elem = self.ir_head.?.getTail();
            elem.next = ir;
            ir.prev = elem;
        }
        return ir;
    }

    pub fn removeInstruction(bb: *BasicBlock, ir: *IR) void {
        ir.removed = true;
        if (bb.ir_head != null and bb.ir_head == ir) {
            bb.ir_head = bb.ir_head.?.next;
        }
        if (ir.prev) |prev| {
            prev.next = ir.next;
        }
        if (ir.next) |next| {
            next.prev = ir.prev;
        }
    }
};

pub const CFG = struct {
    /// Temporary, flat instruction list before the BBs are created
    ir_head: ?*IR,
    ir_tail: ?*IR,

    /// Initial basic block in the basic block graph
    block_graph_head: ?*BasicBlock,

    /// Flat list of all basic blocks
    basic_blocks: std.ArrayList(*BasicBlock),

    /// All other functions called by this function
    leaves: std.ArrayList(*CFG),

    /// The function that this CFG represents
    symbol: *Symbol,

    number_temps: usize,

    return_symbol: *Symbol,

    /// Whether or not this CFG is visited
    visited: bool,

    pub fn create(symbol: *Symbol, caller: ?*CFG, errors: *errs.Errors, allocator: std.mem.Allocator) !*CFG {
        var retval = try allocator.create(CFG);
        retval.ir_head = null;
        retval.ir_tail = null;
        retval.block_graph_head = null;
        retval.basic_blocks = std.ArrayList(*BasicBlock).init(allocator);
        retval.leaves = std.ArrayList(*CFG).init(allocator);
        retval.symbol = symbol;
        retval.number_temps = 0;
        retval.return_symbol = try Symbol.create(symbol.scope, "$retval", span.Span{ .col = 0, .line = 0 }, null, null, .mut, allocator);
        retval.visited = false;

        if (caller) |caller_node| {
            try caller_node.leaves.append(retval);
        }

        var eval = try retval.flattenAST(symbol.scope, symbol.init.?, null, null, null, false, errors, allocator);
        var return_version = try SymbolVersion.createUnversioned(retval.return_symbol, symbol._type.?.function.rhs, allocator);
        retval.appendInstruction(try IR.create(.copy, return_version, eval, null, allocator));
        retval.appendInstruction(try IR.createJump(null, allocator));

        retval.block_graph_head = try retval.basicBlockFromIR(retval.ir_head, allocator);
        retval.removeBasicBlockLastInstruction();

        // for (retval.basic_blocks.items) |bb| {
        //     bb.pprint();
        // }
        // retval.clearVisitedBBs();
        try retval.calculatePhiParamsAndArgs(allocator);

        // Phi parameters and arguments are un-versioned by design up to this point. Version them now.
        for (retval.basic_blocks.items) |bb| {
            for (bb.parameters.items) |symbver| {
                symbver.makeUnique();
            }
            for (bb.next_arguments.items) |symbver| {
                symbver.makeUnique();
            }
            for (bb.branch_arguments.items) |symbver| {
                symbver.makeUnique();
            }
        }

        // Symbol versions dependent on phi parameters will have null versions. Assign the versions here.
        for (retval.basic_blocks.items) |bb| {
            var maybe_ir: ?*IR = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                if (ir.src1 != null and ir.src1.?.version == null) {
                    ir.src1 = ir.src1.?.findSymbolVersionSet(&bb.parameters);
                    std.debug.assert(ir.src1 != null);
                    std.debug.assert(ir.src1.?.version != null);
                }
                if (ir.src2 != null and ir.src2.?.version == null) {
                    ir.src2 = ir.src2.?.findSymbolVersionSet(&bb.parameters);
                    std.debug.assert(ir.src2 != null);
                    std.debug.assert(ir.src2.?.version != null);
                }
            }
        }

        return retval;
    }

    // BBs aren't trees, so `defer self.visited = false` won't work
    // Use this function instead
    pub fn clearVisitedBBs(self: *CFG) void {
        for (self.basic_blocks.items) |bb| {
            bb.visited = false;
        }
    }

    fn createBasicBlock(self: *CFG, allocator: std.mem.Allocator) !*BasicBlock {
        var retval = try allocator.create(BasicBlock);
        retval.ir_head = null;
        retval.condition = null;
        retval.parameters = std.ArrayList(*SymbolVersion).init(allocator);
        retval.next = null;
        retval.next_arguments = std.ArrayList(*SymbolVersion).init(allocator);
        retval.branch = null;
        retval.branch_arguments = std.ArrayList(*SymbolVersion).init(allocator);
        retval.uid = self.basic_blocks.items.len;
        try self.basic_blocks.append(retval);
        return retval;
    }

    fn createTempSymbol(self: *CFG, _type: *AST, allocator: std.mem.Allocator) !*Symbol {
        var buf = try _string.String.init_with_contents(allocator, "t");
        try buf.writer().print("{}", .{self.number_temps});
        self.number_temps += 1;
        var temp_symbol = try Symbol.create(self.symbol.scope, (try buf.toOwned()).?, span.Span{ .line = 0, .col = 0 }, _type, null, .mut, allocator);
        return temp_symbol;
    }

    fn createTempSymbolVersion(self: *CFG, _type: *AST, allocator: std.mem.Allocator) !*SymbolVersion {
        var temp_symbol = try self.createTempSymbol(_type, allocator);
        var retval = try SymbolVersion.createUnversioned(temp_symbol, _type, allocator);
        return retval;
    }

    fn appendInstruction(self: *CFG, ir: *IR) void {
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

    fn flattenAST(self: *CFG, scope: *Scope, ast: *AST, return_label: ?*IR, break_label: ?*IR, continue_label: ?*IR, lvalue: bool, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, OutOfMemory, NotAnLValue, Unimplemented, InvalidRange }!?*SymbolVersion {
        switch (ast.*) {
            // Literals
            .unit => return null,
            .int => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);
                var ir = try IR.createInt(temp, ast.int.data, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .char => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);
                var ir = try IR.createInt(temp, ast.char.data, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .float => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);
                var ir = try IR.createFloat(temp, ast.float.data, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .string => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);
                var ir = try IR.createString(temp, ast.string.common.token.data, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .identifier => {
                var symbol = scope.lookup(ast.identifier.common.token.data).?;
                if (symbol.kind == ._fn) {
                    _ = try create(symbol, self, errors, allocator);
                    var symbver = try self.createTempSymbolVersion(symbol._type.?, allocator);

                    var ir = try IR.create(.loadSymbol, symbver, null, null, allocator);
                    ir.data = IRData{ .symbol = symbol };
                    symbver.def = ir;
                    self.appendInstruction(ir);
                    return symbver;
                } else {
                    var symbver = try self.createTempSymbolVersion(symbol._type.?, allocator);
                    var src = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    var ir = try IR.create(.copy, symbver, src, null, allocator);
                    ir.data = IRData{ .symbol = symbol };
                    symbver.def = ir;
                    self.appendInstruction(ir);
                    return symbver;
                }
            },
            ._true => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);
                var ir = try IR.createInt(temp, 1, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            ._false => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);
                var ir = try IR.createInt(temp, 0, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },

            // Unary operators
            .not => {
                var expr = try self.flattenAST(scope, ast.not.expr, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(expr != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.not, temp, expr, null, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .negate => {
                var expr = try self.flattenAST(scope, ast.negate.expr, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(expr != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.negate, temp, expr, null, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .dereference => {
                var expr = try self.flattenAST(scope, ast.dereference.expr, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(expr != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.dereference, temp, expr, null, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },

            // Binary operators
            .assign => {
                if (ast.assign.lhs.* == .identifier) {
                    var symbol = scope.lookup(ast.assign.lhs.identifier.common.token.data).?;
                    var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    symbver.lvalue = true;
                    var rhs = try self.flattenAST(scope, ast.assign.rhs, return_label, break_label, continue_label, false, errors, allocator);
                    std.debug.assert(rhs != null);
                    var ir = try IR.create(.copy, symbver, rhs, null, allocator);
                    symbver.def = ir;
                    self.appendInstruction(ir);
                    return symbver;
                } else if (ast.assign.lhs.* == .dereference) {
                    var lhs = try self.flattenAST(scope, ast.assign.lhs.dereference.expr, return_label, break_label, continue_label, true, errors, allocator);
                    std.debug.assert(lhs != null);
                    lhs.?.lvalue = true;
                    var rhs = try self.flattenAST(scope, ast.assign.rhs, return_label, break_label, continue_label, false, errors, allocator);
                    std.debug.assert(rhs != null);
                    var ir = try IR.create(.derefCopy, null, lhs, rhs, allocator);
                    self.appendInstruction(ir);
                    return null;
                } else {
                    return error.NotAnLValue;
                }
            },
            ._or => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // Labels used
                var else_label = try IR.createLabel(allocator);
                var end_label = try IR.createLabel(allocator);

                // Test lhs, branch
                var lhs = (try self.flattenAST(scope, ast._or.lhs, return_label, break_label, continue_label, false, errors, allocator)).?;
                var branch = try IR.createBranch(lhs, else_label, allocator);
                self.appendInstruction(branch);

                // lhs was true, store `true` in symbver
                var load_true_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var load_true = try IR.createInt(load_true_symbver, 1, allocator);
                load_true_symbver.def = load_true;
                self.appendInstruction(load_true);
                self.appendInstruction(try IR.createJump(end_label, allocator));

                // lhs was false, recurse to rhs, store in symbver
                self.appendInstruction(else_label);
                var rhs = try self.flattenAST(scope, ast._or.rhs, return_label, break_label, continue_label, false, errors, allocator);
                std.debug.assert(rhs != null);
                var copy_right_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var copy_right = try IR.create(.copy, copy_right_symbver, rhs, null, allocator);
                copy_right_symbver.def = copy_right;
                self.appendInstruction(copy_right);
                self.appendInstruction(try IR.createJump(end_label, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },
            ._and => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // Labels used
                var else_label = try IR.createLabel(allocator);
                var end_label = try IR.createLabel(allocator);

                // Test lhs, branch
                var lhs = (try self.flattenAST(scope, ast._and.lhs, return_label, break_label, continue_label, false, errors, allocator)).?;
                var branch = try IR.createBranch(lhs, else_label, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in symbver
                var rhs = try self.flattenAST(scope, ast._and.rhs, return_label, break_label, continue_label, false, errors, allocator);
                std.debug.assert(rhs != null);
                var copy_right_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var copy_right = try IR.create(.copy, copy_right_symbver, rhs, null, allocator);
                copy_right_symbver.def = copy_right;
                self.appendInstruction(copy_right);
                self.appendInstruction(try IR.createJump(end_label, allocator));

                // lhs was false, store `false` in symbver
                self.appendInstruction(else_label);
                var load_false_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var load_false = try IR.createInt(load_false_symbver, 0, allocator);
                load_false_symbver.def = load_false;
                self.appendInstruction(load_false);
                self.appendInstruction(try IR.createJump(end_label, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },
            .notEqual => {
                var lhs = try self.flattenAST(scope, ast.notEqual.lhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(lhs != null);
                var rhs = try self.flattenAST(scope, ast.notEqual.rhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(rhs != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.notEqual, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .add => {
                var lhs = try self.flattenAST(scope, ast.add.lhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(lhs != null);
                var rhs = try self.flattenAST(scope, ast.add.rhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(rhs != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.add, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .sub => {
                var lhs = try self.flattenAST(scope, ast.sub.lhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(lhs != null);
                var rhs = try self.flattenAST(scope, ast.sub.rhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(rhs != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.sub, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .mult => {
                var lhs = try self.flattenAST(scope, ast.mult.lhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(lhs != null);
                var rhs = try self.flattenAST(scope, ast.mult.rhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(rhs != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.mult, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .div => {
                var lhs = try self.flattenAST(scope, ast.div.lhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(lhs != null);
                var rhs = try self.flattenAST(scope, ast.div.rhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(rhs != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.div, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .mod => {
                var lhs = try self.flattenAST(scope, ast.mod.lhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(lhs != null);
                var rhs = try self.flattenAST(scope, ast.mod.rhs, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(rhs != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.mod, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .exponent => {
                std.debug.assert(ast.exponent.terms.items.len >= 2);
                var lhs: *SymbolVersion = undefined;
                var rhs: *SymbolVersion = undefined;
                var temp: *SymbolVersion = undefined;
                var terms_len = ast.exponent.terms.items.len;

                rhs = (try self.flattenAST(scope, ast.exponent.terms.items[terms_len - 1], return_label, break_label, continue_label, lvalue, errors, allocator)).?;
                var i: usize = ast.exponent.terms.items.len - 1;
                while (i > 0) : (i -= 1) {
                    lhs = (try self.flattenAST(scope, ast.exponent.terms.items[i - 1], return_label, break_label, continue_label, lvalue, errors, allocator)).?;
                    temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                    var ir = try IR.create(.exponent, temp, lhs, rhs, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    rhs = temp;
                }
                return temp;
            },
            .call => {
                var lhs = (try self.flattenAST(scope, ast.call.lhs, return_label, break_label, continue_label, false, errors, allocator)).?;
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.createCall(temp, lhs, allocator);
                switch (ast.call.rhs.*) {
                    .unit => {},
                    .product => for (ast.call.rhs.product.terms.items) |term| {
                        try ir.data.symbverList.append((try self.flattenAST(scope, term, return_label, break_label, continue_label, false, errors, allocator)).?);
                    },
                    else => try ir.data.symbverList.append((try self.flattenAST(scope, ast.call.rhs, return_label, break_label, continue_label, false, errors, allocator)).?),
                }
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },

            // Fancy Operators
            .addrOf => {
                var expr = try self.flattenAST(scope, ast.addrOf.expr, return_label, break_label, continue_label, lvalue, errors, allocator);
                std.debug.assert(expr != null);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                var ir = try IR.create(.addrOf, temp, expr, null, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .conditional => {
                std.debug.assert(ast.conditional.exprs.items.len == ast.conditional.tokens.items.len + 1);

                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                var end_label = try IR.createLabel(allocator);
                var else_label = try IR.createLabel(allocator);

                var i: usize = 0;
                var lhs = (try self.flattenAST(scope, ast.conditional.exprs.items[0], return_label, break_label, continue_label, false, errors, allocator));
                while (i < ast.conditional.tokens.items.len) : (i += 1) {
                    // Test lhs, branch
                    var rhs = try self.flattenAST(scope, ast.conditional.exprs.items[i + 1], return_label, break_label, continue_label, false, errors, allocator);
                    std.debug.assert(rhs != null);
                    var token = ast.conditional.tokens.items[i];
                    var ir_kind: IRKind = undefined;
                    switch (token.kind) {
                        .D_EQUALS => {
                            ir_kind = .equal;
                        },
                        .GTR => {
                            ir_kind = .greater;
                        },
                        .GTE => {
                            ir_kind = .greaterEqual;
                        },
                        .LSR => {
                            ir_kind = .lesser;
                        },
                        .LTE => {
                            ir_kind = .lesserEqual;
                        },
                        else => unreachable,
                    }
                    var temp = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    var ir = try IR.create(ir_kind, temp, lhs, rhs, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    var branch = try IR.createBranch(temp, else_label, allocator);
                    self.appendInstruction(branch);
                    lhs = rhs;
                }
                // all tests passed, store `true` in symbver
                var load_true_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var load_true = try IR.createInt(load_true_symbver, 1, allocator);
                load_true_symbver.def = load_true;
                self.appendInstruction(load_true);
                self.appendInstruction(try IR.createJump(end_label, allocator));
                // at least one test failed, store `false` in symbver
                self.appendInstruction(else_label);
                var load_false_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var load_false = try IR.createInt(load_false_symbver, 0, allocator);
                load_false_symbver.def = load_false;
                self.appendInstruction(load_false);
                self.appendInstruction(try IR.createJump(end_label, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },

            // Control-flow expressions
            ._if => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // If there's a let, then do it, dumby!
                if (ast._if.let) |let| {
                    _ = try self.flattenAST(ast._if.scope.?, let, return_label, break_label, continue_label, false, errors, allocator);
                }

                // Labels used
                var else_label = try IR.createLabel(allocator);
                var end_label = try IR.createLabel(allocator);

                // Test lhs, branch
                var condition = (try self.flattenAST(ast._if.scope.?, ast._if.condition, return_label, break_label, continue_label, false, errors, allocator)).?;
                var branch = try IR.createBranch(condition, else_label, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in symbver
                if (try self.flattenAST(ast._if.scope.?, ast._if.bodyBlock, return_label, break_label, continue_label, false, errors, allocator)) |block_symbver| {
                    var block_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    var block_copy = try IR.create(.copy, block_copy_symbver, block_symbver, null, allocator);
                    block_copy_symbver.def = block_copy;
                    self.appendInstruction(block_copy);
                }
                self.appendInstruction(try IR.createJump(end_label, allocator));

                // lhs was false, store `false` in symbver
                self.appendInstruction(else_label);
                if (ast._if.elseBlock) |elseBlock| {
                    if (try self.flattenAST(ast._if.scope.?, elseBlock, return_label, break_label, continue_label, false, errors, allocator)) |else_symbver| {
                        var else_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                        var else_copy = try IR.create(.copy, else_copy_symbver, else_symbver, null, allocator);
                        else_copy_symbver.def = else_copy;
                        self.appendInstruction(else_copy);
                    }
                    self.appendInstruction(try IR.createJump(end_label, allocator));
                }
                self.appendInstruction(end_label);
                return symbver;
            },
            .cond => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // If there's a let, then do it, dumby!
                if (ast.cond.let) |let| {
                    _ = try self.flattenAST(ast.cond.scope.?, let, return_label, break_label, continue_label, false, errors, allocator);
                }

                // Exit label of cond
                var end_label = try IR.createLabel(allocator);
                // List of labels to branch to on an unsuccessful test ("next test")
                var lhs_label_list = std.ArrayList(*IR).init(allocator);
                defer lhs_label_list.deinit();
                // List of labels to branch to on a successful test
                var rhs_label_list = std.ArrayList(*IR).init(allocator);
                defer rhs_label_list.deinit();
                for (ast.cond.mappings.items) |mapping| {
                    try lhs_label_list.append(try IR.createLabel(allocator));
                    if (mapping.mapping.rhs != null) {
                        try rhs_label_list.append(try IR.createLabel(allocator));
                    }
                }
                std.debug.assert(lhs_label_list.items.len == ast.cond.mappings.items.len);

                var lhs_label_index: usize = 0;
                var rhs_label_index: usize = 0;
                for (ast.cond.mappings.items) |mapping| {
                    var lhs_label = lhs_label_list.items[lhs_label_index];
                    self.appendInstruction(lhs_label);
                    if (mapping.mapping.lhs) |lhs| {
                        var condition = (try self.flattenAST(ast.cond.scope.?, lhs, return_label, break_label, continue_label, false, errors, allocator)).?;
                        // std.debug.assert(condition.def != null);
                        if (lhs_label_index < lhs_label_list.items.len - 1) {
                            var branch = try IR.createBranch(condition, lhs_label_list.items[lhs_label_index + 1], allocator);
                            self.appendInstruction(branch);
                        }
                    }
                    var rhs_label = rhs_label_list.items[rhs_label_index];
                    self.appendInstruction(try IR.createJump(rhs_label, allocator));
                    if (mapping.mapping.rhs != null) {
                        rhs_label_index += 1;
                    }
                    lhs_label_index += 1;
                }

                // Write the labels and the mappings exprs
                rhs_label_index = 0;
                for (ast.cond.mappings.items) |mapping| {
                    if (mapping.mapping.rhs) |rhs| {
                        self.appendInstruction(rhs_label_list.items[rhs_label_index]);
                        if (try self.flattenAST(ast.cond.scope.?, rhs, return_label, break_label, continue_label, false, errors, allocator)) |rhs_symbver| {
                            var rhs_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                            var rhs_copy = try IR.create(.copy, rhs_copy_symbver, rhs_symbver, null, allocator);
                            rhs_copy_symbver.def = rhs_copy;
                            self.appendInstruction(rhs_copy);
                        }
                        self.appendInstruction(try IR.createJump(end_label, allocator));
                        rhs_label_index += 1;
                    }
                }
                self.appendInstruction(end_label);

                return symbver;
            },
            ._while => {
                // Create the result symbol and IR
                var symbver = try self.createTempSymbolVersion(try ast.typeof(scope, errors), allocator);

                // Labels used
                var cond_label = try IR.createLabel(allocator);
                var else_label = try IR.createLabel(allocator);
                var end_label = try IR.createLabel(allocator);

                // If there's a let, then do it, dumby!
                if (ast._while.let) |let| {
                    _ = try self.flattenAST(ast._while.scope.?, let, return_label, break_label, continue_label, false, errors, allocator);
                }

                // Test lhs, branch
                self.appendInstruction(cond_label);
                var condition = (try self.flattenAST(ast._while.scope.?, ast._while.condition, return_label, break_label, continue_label, false, errors, allocator)).?;
                var branch = try IR.createBranch(condition, else_label, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in symbver
                if (try self.flattenAST(ast._while.scope.?, ast._while.bodyBlock, return_label, break_label, continue_label, false, errors, allocator)) |blockSymbver| {
                    var blockCopy = try IR.create(.copy, symbver, blockSymbver, null, allocator);
                    self.appendInstruction(blockCopy);
                }

                // Post-condition
                if (ast._while.post) |post| {
                    _ = try self.flattenAST(ast._while.scope.?, post, return_label, break_label, continue_label, false, errors, allocator);
                }

                self.appendInstruction(try IR.createJump(cond_label, allocator));

                // lhs was false, store `false` in symbver
                self.appendInstruction(else_label);
                if (ast._while.elseBlock) |elseBlock| {
                    if (try self.flattenAST(ast._while.scope.?, elseBlock, return_label, break_label, continue_label, false, errors, allocator)) |elseSymbver| {
                        var elseCopy = try IR.create(.copy, symbver, elseSymbver, null, allocator);
                        self.appendInstruction(elseCopy);
                    }
                    self.appendInstruction(try IR.createJump(end_label, allocator));
                }
                self.appendInstruction(end_label);
                return symbver;
            },
            .block => {
                if (ast.block.statements.items.len == 0 and ast.block.final == null) {
                    return null;
                } else {
                    var temp: ?*SymbolVersion = null;
                    for (ast.block.statements.items) |child| {
                        temp = try self.flattenAST(ast.block.scope.?, child, return_label, break_label, continue_label, lvalue, errors, allocator);
                    }
                    if (ast.block.final) |final| {
                        return self.flattenAST(ast.block.scope.?, final, return_label, break_label, continue_label, lvalue, errors, allocator);
                    } else {
                        return temp;
                    }
                }
            },

            // Control-flow statements
            .decl => {
                var symbver = try SymbolVersion.createUnversioned(ast.decl.symbol.?, ast.decl.symbol.?._type.?, allocator);
                var def: ?*SymbolVersion = null;
                if (ast.decl.symbol.?.init) |init| {
                    def = try self.flattenAST(ast.decl.symbol.?.scope, init, return_label, break_label, continue_label, false, errors, allocator);
                    std.debug.assert(def != null);
                } else {
                    // self.defaultValue(ast.decl.symbol.type)
                }
                var ir = try IR.create(.copy, symbver, def, null, allocator);
                symbver.def = ir;
                self.appendInstruction(ir);
                return null;
            },
            ._defer => {
                return null;
            },
            else => {
                std.debug.print("Unimplemented flattenAST() for: AST.{s}\n", .{@tagName(ast.*)});
                return error.Unimplemented;
            },
        }
    }

    fn basicBlockFromIR(self: *CFG, maybe_ir: ?*IR, allocator: std.mem.Allocator) !?*BasicBlock {
        if (maybe_ir == null) {
            return null;
        } else if (maybe_ir.?.in_block) |in_block| {
            return in_block;
        } else {
            var retval: *BasicBlock = try self.createBasicBlock(allocator);
            retval.ir_head = maybe_ir;
            var _maybe_ir = maybe_ir;
            while (_maybe_ir) |ir| : (_maybe_ir = ir.next) {
                ir.in_block = retval;

                if (ir.dest) |dest| {
                    dest.makeUnique();
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
                } else if (ir.kind == .branchIfFalse) {
                    // If you find a branch, end this block, start both blocks
                    retval.has_branch = true;
                    var branchNext: ?*IR = null; // = ir.data.branch.next; // Since ir->branch->next may get nullifued by calling this function on ir->next
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
                var maybe_ir: ?*IR = bb.ir_head;
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
            var maybe_ir: ?*IR = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                // If src1 version is null, and is not defined in this BB, request it as a parameter
                if (ir.src1 != null and ir.src1.?.version == null) {
                    ir.src1 = ir.src1.?.findVersion(bb.ir_head, ir);
                    if (ir.src1.?.version == null) {
                        _ = try ir.src1.?.putSymbolVersionSet(&bb.parameters);
                    }
                }
                // If src2 version is null, and is not defined in this BB, request it as a parameter
                if (ir.src2 != null and ir.src2.?.version == null) {
                    ir.src2 = ir.src2.?.findVersion(bb.ir_head, ir);
                    if (ir.src2.?.version == null) {
                        _ = try ir.src2.?.putSymbolVersionSet(&bb.parameters);
                    }
                }
            }
            // Do the same for the condition of a branch, if there is one
            if (bb.has_branch and bb.condition != null) {
                bb.condition = bb.condition.?.findVersion(bb.ir_head, null);
                if (bb.condition.?.version == null) {
                    _ = try bb.condition.?.putSymbolVersionSet(&bb.parameters);
                }
            }
        }
        // Add function parameters as basic block symbol version parameters
        // TODO: When functions

        // Find phi arguments
        self.clearVisitedBBs();
        var i: usize = 0;
        while (try self.childrenArgPropagation(self.block_graph_head.?, allocator)) {
            self.clearVisitedBBs();
            i += 1;
        }
        self.clearVisitedBBs();
    }

    fn childrenArgPropagation(self: *CFG, bb: *BasicBlock, allocator: std.mem.Allocator) !bool {
        var retval: bool = false;
        if (bb.visited) {
            return false;
        }
        bb.visited = true;

        if (bb.next) |next| {
            retval = try self.childrenArgPropagation(next, allocator) or retval;
            for (next.parameters.items) |param| {
                var symbver = param.findVersion(bb.ir_head, null);
                if (symbver == param) { // Could not find param def in this block, require it as a parameter for this own block
                    var myParam = param.findSymbolVersionSet(&bb.parameters);
                    if (myParam) |_myParam| {
                        symbver = _myParam;
                    } else {
                        symbver = try SymbolVersion.createUnversioned(param.symbol, param.type, allocator);
                        _ = try symbver.putSymbolVersionSet(&bb.parameters);
                    }
                } // else found in this block already, add it to the arguments
                retval = try symbver.putSymbolVersionSet(&bb.next_arguments) or retval;
            }
        }

        if (bb.has_branch) {
            if (bb.branch) |branch| {
                retval = try self.childrenArgPropagation(branch, allocator) or retval;
                for (branch.parameters.items) |param| {
                    var symbver = param.findVersion(bb.ir_head, null);
                    if (symbver == param) { // Could not find param def in this block, require it as a parameter for this own block
                        var myParam = param.findSymbolVersionSet(&bb.parameters);
                        if (myParam) |_myParam| {
                            symbver = _myParam;
                        } else {
                            symbver = try SymbolVersion.createUnversioned(param.symbol, param.type, allocator);
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
