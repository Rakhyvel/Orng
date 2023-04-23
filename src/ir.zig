const span = @import("span.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");

const AST = @import("ast.zig").AST;
const Scope = _symbol.Scope;
const Symbol = _symbol.Symbol;

pub const SymbolVersion = struct {
    symbol: *Symbol,
    version: ?u64,
    def: *IR,

    /// Type of the SymbolVersion. Temps use the same symbol, so can't use that for type info
    type: *AST,

    fn createUnversioned(symbol: *Symbol, _type: *AST, allocator: std.mem.Allocator) !*SymbolVersion {
        var retval = try allocator.create(SymbolVersion);
        retval.symbol = symbol;
        retval.version = null;
        retval.type = _type;
        return retval;
    }

    fn makeUnique(self: *SymbolVersion) void {
        if (self.version == null) {
            self.version = self.symbol.versions;
            self.symbol.versions += 1;
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

    // Diadic instruction
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
    subtract,
    multiply,
    divide,
    modulus,
    exponent,
    not,
    neg,
    bitNot,
    addrOf,
    sizeOf, //< For extern types that Orng can't do automatically
    deref,
    derefCopy,
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
    branch: *IR,
    int: i128,
    float: f64,
    string: []const u8,
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

    fn createString(dest: ?*SymbolVersion, string: []const u8, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadString, dest, null, null, allocator);
        retval.data = IRData{ .string = string };
        return retval;
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

    /// Whether or not this CFG is visited
    visited: bool,

    pub fn create(symbol: *Symbol, allocator: std.mem.Allocator) !*CFG {
        var retval = try allocator.create(CFG);
        retval.ir_head = null;
        retval.ir_tail = null;
        retval.block_graph_head = null;
        retval.basic_blocks = std.ArrayList(*BasicBlock).init(allocator);
        retval.leaves = std.ArrayList(*CFG).init(allocator);
        retval.symbol = symbol;
        retval.temp_symbol = try Symbol.create(symbol.scope, "$temp", span.Span{ .col = 0, .line = 0 }, null, null, allocator);
        retval.visited = false;

        var eval = try retval.flattenAST(symbol.scope, symbol.init.?, allocator);
        _ = eval;

        retval.block_graph_head = try retval.basicBlockFromIR(retval.ir_head, allocator);

        return retval;
    }

    fn createBasicBlock(self: *CFG, allocator: std.mem.Allocator) !*BasicBlock {
        var retval = try allocator.create(BasicBlock);
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

    fn flattenAST(self: *CFG, scope: *Scope, ast: *AST, allocator: std.mem.Allocator) !?*SymbolVersion {
        switch (ast.*) {
            .identifier => {
                var symbol = scope.lookup(ast.identifier.token.data).?;
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                return symbver;
            },
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
            .block => {
                if (ast.block.statements.items.len == 0 and ast.block.final == null) {
                    return null;
                } else {
                    var temp: ?*SymbolVersion = null;
                    for (ast.block.statements.items) |child| {
                        temp = try self.flattenAST(ast.block.scope.?, child, allocator);
                    }
                    if (ast.block.final) |final| {
                        return self.flattenAST(ast.block.scope.?, final, allocator);
                    } else {
                        return temp;
                    }
                }
            },
            else => {
                std.debug.print("Unimplemented flattenAST() for: AST.{s}\n", .{@tagName(ast.*)});
                return error.Unimplemented;
            },
        }
    }

    fn basicBlockFromIR(self: *CFG, maybe_ir: ?*IR, allocator: std.mem.Allocator) !?*BasicBlock {
        if (maybe_ir == null) {
            std.debug.print("Took the null ir route\n", .{});
            return null;
        } else if (maybe_ir.?.in_block) |in_block| {
            std.debug.print("Took the in block route\n", .{});
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
                        retval.next = try self.basicBlockFromIR(ir.data.branch.next, allocator);
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
                    var branchNext = ir.data.branch.next; // Since ir->branch->next may get nullifued by calling this function on ir->next
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
