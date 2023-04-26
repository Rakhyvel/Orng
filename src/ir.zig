const span = @import("span.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");

const AST = @import("ast.zig").AST;
const Scope = _symbol.Scope;
const Symbol = _symbol.Symbol;

pub const SymbolVersion = struct {
    symbol: *Symbol,
    version: ?u64,
    def: ?*IR,

    lvalue: bool,

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

    fn makeUnique(self: *SymbolVersion) void {
        if (self.version == null) {
            self.version = self.symbol.versions;
            self.symbol.versions += 1;
        }
    }

    fn pprint(self: ?*SymbolVersion) void {
        if (self) |symbver| {
            std.debug.print("{s}_{?}\t", .{ symbver.symbol.name, symbver.version });
        } else {
            std.debug.print("<null>\t", .{});
        }
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
    phony,

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

const IRData = union(enum) {
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

    fn create(kind: IRKind, dest: ?*SymbolVersion, src1: ?*SymbolVersion, src2: ?*SymbolVersion, allocator: std.mem.Allocator) !*IR {
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

    fn createPhony(dest: *SymbolVersion, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.phony, dest, null, null, allocator);
        retval.data = IRData{ .irList = std.ArrayList(*IR).init(allocator) };
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

    fn pprint(self: *IR) void {
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

    /// If null, jump to function end label
    next: ?*BasicBlock,

    branch: ?*BasicBlock,
    condition: ?*SymbolVersion,

    visited: bool,

    pub fn pprint(self: *BasicBlock) void {
        if (self.visited) {
            return;
        }
        self.visited = true;

        std.debug.print("Basic Block BB{}\n", .{self.uid});
        var maybe_ir = self.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            ir.pprint();
        }
        if (self.has_branch) {
            if (self.branch) |branch| {
                std.debug.print("if (!{s}_{?}) goto {}\n", .{ self.condition.?.symbol.name, self.condition.?.version, branch.uid });
            } else {
                std.debug.print("if (!{s}_{?}) goto <END>\n", .{ self.condition.?.symbol.name, self.condition.?.version });
            }
        }
        if (self.next) |next| {
            std.debug.print("goto {}\n", .{next.uid});
        } else {
            std.debug.print("goto <END>\n", .{});
        }
        if (self.branch) |branch| {
            branch.pprint();
        }
        if (self.next) |next| {
            next.pprint();
        }
    }

    // BBs aren't trees, so `defer self.visited = false` won't work
    // Use this function instead
    pub fn clearVisited(self: *BasicBlock) void {
        self.visited = false;
        if (self.branch) |branch| {
            branch.clearVisited();
        }
        if (self.next) |next| {
            next.clearVisited();
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

    temp_symbol: *Symbol,

    return_symbol: *Symbol,

    /// Whether or not this CFG is visited
    visited: bool,

    pub fn create(symbol: *Symbol, caller: ?*CFG, allocator: std.mem.Allocator) !*CFG {
        var retval = try allocator.create(CFG);
        retval.ir_head = null;
        retval.ir_tail = null;
        retval.block_graph_head = null;
        retval.basic_blocks = std.ArrayList(*BasicBlock).init(allocator);
        retval.leaves = std.ArrayList(*CFG).init(allocator);
        retval.symbol = symbol;
        retval.temp_symbol = try Symbol.create(symbol.scope, "$temp", span.Span{ .col = 0, .line = 0 }, null, null, .mut, allocator);
        retval.return_symbol = try Symbol.create(symbol.scope, "$retval", span.Span{ .col = 0, .line = 0 }, null, null, .mut, allocator);
        retval.visited = false;

        if (caller) |caller_node| {
            try caller_node.leaves.append(retval);
        }

        var eval = try retval.flattenAST(symbol.scope, symbol.init.?, false, allocator);
        var return_version = try SymbolVersion.createUnversioned(retval.return_symbol, symbol._type.?.function.rhs, allocator);
        retval.appendInstruction(try IR.create(.copy, return_version, eval, null, allocator));
        retval.appendInstruction(try IR.createJump(null, allocator));

        retval.block_graph_head = try retval.basicBlockFromIR(retval.ir_head, allocator);

        if (retval.block_graph_head) |graph| {
            graph.pprint();
            graph.clearVisited();
        }

        return retval;
    }

    fn createBasicBlock(self: *CFG, allocator: std.mem.Allocator) !*BasicBlock {
        var retval = try allocator.create(BasicBlock);
        retval.ir_head = null;
        retval.condition = null;
        retval.next = null;
        retval.branch = null;
        retval.uid = self.basic_blocks.items.len;
        try self.basic_blocks.append(retval);
        return retval;
    }

    fn createTempSymbolVersion(self: *CFG, _type: *AST, allocator: std.mem.Allocator) !*SymbolVersion {
        var retval = try SymbolVersion.createUnversioned(self.temp_symbol, _type, allocator);
        retval.makeUnique();
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

    fn flattenAST(self: *CFG, scope: *Scope, ast: *AST, lvalue: bool, allocator: std.mem.Allocator) error{ OutOfMemory, NotAnLValue, Unimplemented }!?*SymbolVersion {
        switch (ast.*) {
            // Literals
            .unit => return null,
            .int => {
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);
                var ir = try IR.createInt(temp, ast.int.data, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .char => {
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);
                var ir = try IR.createInt(temp, ast.char.data, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .float => {
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);
                var ir = try IR.createFloat(temp, ast.float.data, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .string => {
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);
                var ir = try IR.createString(temp, ast.string.token.data, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .identifier => {
                var symbol = scope.lookup(ast.identifier.token.data).?;
                if (symbol.kind == ._fn) {
                    _ = try create(symbol, self, allocator);
                    var symbver = try self.createTempSymbolVersion(symbol._type.?, allocator);

                    var ir = try IR.create(.loadSymbol, symbver, null, null, allocator);
                    ir.data = IRData{ .symbol = symbol };
                    symbver.def = ir;
                    self.appendInstruction(ir);
                    return symbver;
                } else {
                    var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    symbver.lvalue = lvalue;
                    return symbver;
                }
            },

            // Unary operators
            .not => {
                var expr = try self.flattenAST(scope, ast.not.expr, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.not, temp, expr, null, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .negate => {
                var expr = try self.flattenAST(scope, ast.negate.expr, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.negate, temp, expr, null, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .dereference => {
                var expr = try self.flattenAST(scope, ast.dereference.expr, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.dereference, temp, expr, null, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },

            // Binary operators
            .assign => {
                if (ast.assign.lhs.* == .identifier) {
                    var symbol = scope.lookup(ast.assign.lhs.identifier.token.data).?;
                    var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    symbver.lvalue = true;
                    var rhs = try self.flattenAST(scope, ast.assign.rhs, false, allocator);
                    var ir = try IR.create(.copy, symbver, rhs, null, allocator);
                    symbver.def = ir;
                    self.appendInstruction(ir);
                    return null;
                } else if (ast.assign.lhs.* == .dereference) {
                    var lhs = try self.flattenAST(scope, ast.assign.lhs.dereference.expr, true, allocator);
                    lhs.?.lvalue = true;
                    var rhs = try self.flattenAST(scope, ast.assign.rhs, false, allocator);
                    var ir = try IR.create(.derefCopy, null, lhs, rhs, allocator);
                    self.appendInstruction(ir);
                    return null;
                } else {
                    return error.NotAnLValue;
                }
            },
            ._or => {
                // Create the result symbol and IR
                var symbver = try self.createTempSymbolVersion(ast.typeof(), allocator);
                var phony = try IR.createPhony(symbver, allocator);
                symbver.def = phony;
                self.appendInstruction(phony);

                // Labels used
                var else_label = try IR.createLabel(allocator);
                var end_label = try IR.createLabel(allocator);

                // Test lhs, branch
                var lhs = (try self.flattenAST(scope, ast._or.lhs, false, allocator)).?;
                var branch = try IR.createBranch(lhs, else_label, allocator);
                self.appendInstruction(branch);

                // lhs was true, store `true` in symbver
                var load_true = try IR.createInt(symbver, 1, allocator);
                try phony.data.irList.append(load_true);
                self.appendInstruction(load_true);
                self.appendInstruction(try IR.createJump(end_label, allocator));

                // lhs was false, recurse to rhs, store in symbver
                self.appendInstruction(else_label);
                var rhs = try self.flattenAST(scope, ast._or.rhs, false, allocator);
                var copy_right = try IR.create(.copy, symbver, rhs, null, allocator);
                try phony.data.irList.append(copy_right);
                self.appendInstruction(copy_right);
                self.appendInstruction(try IR.createJump(end_label, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },
            ._and => {
                // Create the result symbol and IR
                var symbver = try self.createTempSymbolVersion(ast.typeof(), allocator);
                var phony = try IR.createPhony(symbver, allocator);
                symbver.def = phony;
                self.appendInstruction(phony);

                // Labels used
                var else_label = try IR.createLabel(allocator);
                var end_label = try IR.createLabel(allocator);

                // Test lhs, branch
                var lhs = (try self.flattenAST(scope, ast._and.lhs, false, allocator)).?;
                var branch = try IR.createBranch(lhs, else_label, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in symbver
                var rhs = try self.flattenAST(scope, ast._and.rhs, false, allocator);
                var copy_right = try IR.create(.copy, symbver, rhs, null, allocator);
                try phony.data.irList.append(copy_right);
                self.appendInstruction(copy_right);
                self.appendInstruction(try IR.createJump(end_label, allocator));

                // lhs was false, store `false` in symbver
                self.appendInstruction(else_label);
                var load_false = try IR.createInt(symbver, 0, allocator);
                try phony.data.irList.append(load_false);
                self.appendInstruction(load_false);
                self.appendInstruction(try IR.createJump(end_label, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },
            .notEqual => {
                var lhs = try self.flattenAST(scope, ast.notEqual.lhs, lvalue, allocator);
                var rhs = try self.flattenAST(scope, ast.notEqual.rhs, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.notEqual, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .add => {
                var lhs = try self.flattenAST(scope, ast.add.lhs, lvalue, allocator);
                var rhs = try self.flattenAST(scope, ast.add.rhs, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.add, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .sub => {
                var lhs = try self.flattenAST(scope, ast.sub.lhs, lvalue, allocator);
                var rhs = try self.flattenAST(scope, ast.sub.rhs, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.sub, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .mult => {
                var lhs = try self.flattenAST(scope, ast.mult.lhs, lvalue, allocator);
                var rhs = try self.flattenAST(scope, ast.mult.rhs, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.mult, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .div => {
                var lhs = try self.flattenAST(scope, ast.div.lhs, lvalue, allocator);
                var rhs = try self.flattenAST(scope, ast.div.rhs, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.div, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .mod => {
                var lhs = try self.flattenAST(scope, ast.mod.lhs, lvalue, allocator);
                var rhs = try self.flattenAST(scope, ast.mod.rhs, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.mod, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .exponent => {
                var lhs = try self.flattenAST(scope, ast.exponent.lhs, lvalue, allocator);
                var rhs = try self.flattenAST(scope, ast.exponent.rhs, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.exponent, temp, lhs, rhs, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .call => {
                var lhs = (try self.flattenAST(scope, ast.call.lhs, false, allocator)).?;
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.createCall(temp, lhs, allocator);
                switch (ast.call.rhs.*) {
                    .unit => {},
                    .product => for (ast.call.rhs.product.terms.items) |term| {
                        try ir.data.symbverList.append((try self.flattenAST(scope, term, false, allocator)).?);
                    },
                    else => try ir.data.symbverList.append((try self.flattenAST(scope, ast.call.rhs, false, allocator)).?),
                }
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },

            // Fancy Operators
            .addrOf => {
                var expr = try self.flattenAST(scope, ast.addrOf.expr, lvalue, allocator);
                var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);

                var ir = try IR.create(.addrOf, temp, expr, null, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .conditional => {
                std.debug.assert(ast.conditional.exprs.items.len == ast.conditional.tokens.items.len + 1);

                // Create the result symbol and IR
                var symbver = try self.createTempSymbolVersion(ast.typeof(), allocator);
                var phony = try IR.createPhony(symbver, allocator);
                symbver.def = phony;
                self.appendInstruction(phony);

                var end_label = try IR.createLabel(allocator);
                var else_label = try IR.createLabel(allocator);

                var i: usize = 0;
                var lhs = (try self.flattenAST(scope, ast.conditional.exprs.items[0], false, allocator));
                while (i < ast.conditional.tokens.items.len) : (i += 1) {
                    // Test lhs, branch
                    var rhs = try self.flattenAST(scope, ast.conditional.exprs.items[i + 1], false, allocator);
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
                    var temp = try self.createTempSymbolVersion(ast.typeof(), allocator);
                    var ir = try IR.create(ir_kind, temp, lhs, rhs, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    var branch = try IR.createBranch(temp, else_label, allocator);
                    self.appendInstruction(branch);
                    lhs = rhs;
                }
                // all tests passed, store `true` in symbver
                var load_true = try IR.createInt(symbver, 1, allocator);
                try phony.data.irList.append(load_true);
                self.appendInstruction(load_true);
                self.appendInstruction(try IR.createJump(end_label, allocator));
                // at least one test failed, store `false` in symbver
                self.appendInstruction(else_label);
                var load_false = try IR.createInt(symbver, 0, allocator);
                try phony.data.irList.append(load_false);
                self.appendInstruction(load_false);
                self.appendInstruction(try IR.createJump(end_label, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },

            // Control-flow expressions
            ._if => {
                // Create the result symbol and IR
                var symbver = try self.createTempSymbolVersion(ast.typeof(), allocator);
                var phony = try IR.createPhony(symbver, allocator);
                symbver.def = phony;
                self.appendInstruction(phony);

                // Labels used
                var else_label = try IR.createLabel(allocator);
                var end_label = try IR.createLabel(allocator);

                // Test lhs, branch
                var condition = (try self.flattenAST(scope, ast._if.condition, false, allocator)).?;
                var branch = try IR.createBranch(condition, else_label, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in symbver
                var blockSymbver = (try self.flattenAST(scope, ast._if.bodyBlock, false, allocator)).?;
                var blockCopy = try IR.create(.copy, symbver, blockSymbver, null, allocator);
                try phony.data.irList.append(blockCopy);
                self.appendInstruction(blockCopy);
                self.appendInstruction(try IR.createJump(end_label, allocator));

                // lhs was false, store `false` in symbver
                self.appendInstruction(else_label);
                if (ast._if.elseBlock) |elseBlock| {
                    var elseSymbver = (try self.flattenAST(scope, elseBlock, false, allocator)).?;
                    var elseCopy = try IR.create(.copy, symbver, elseSymbver, null, allocator);
                    try phony.data.irList.append(elseCopy);
                    self.appendInstruction(elseCopy);
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
                        temp = try self.flattenAST(ast.block.scope.?, child, lvalue, allocator);
                    }
                    if (ast.block.final) |final| {
                        return self.flattenAST(ast.block.scope.?, final, lvalue, allocator);
                    } else {
                        return temp;
                    }
                }
            },

            // Control-flow statements
            .decl => {
                var symbver = try SymbolVersion.createUnversioned(ast.decl.symbol.?, ast.decl.type.?, allocator);
                var def: ?*SymbolVersion = null;
                if (ast.decl.symbol.?.init) |init| {
                    def = try self.flattenAST(ast.decl.symbol.?.scope, init, false, allocator);
                } else {
                    // self.defaultValue(ast.decl.symbol.type)
                }
                var ir = try IR.create(.copy, symbver, def, null, allocator);
                symbver.def = ir;
                self.appendInstruction(ir);
                return symbver;
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
                    if (dest.symbol != self.temp_symbol) {
                        dest.makeUnique();
                    }
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
};
