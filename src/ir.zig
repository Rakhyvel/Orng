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
        if (self.version != null) {
            self.version = self.symbol.versions;
            self.symbol.versions += 1;
        }
    }
};

pub const IR = struct {
    uid: u64,
    kind: enum {
        // nullary instructions
        loadSymbol,
        loadExtern,
        loadInt,
        loadReal,
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
    },
    dest: ?*SymbolVersion,
    src1: ?*SymbolVersion,
    src2: ?*SymbolVersion,

    data: union(enum) {
        branch: *IR,
    },

    next: ?*IR,
    prev: ?*IR,

    in_block: ?*BasicBlock,
};

pub const BasicBlock = struct {
    uid: u64,
    instructions: ?*IR,
    has_branch: bool,

    /// If null, jump to function end label
    next: ?*BasicBlock,

    branch: ?*BasicBlock,
    condition: ?*SymbolVersion,

    visited: bool,
};

pub const CFG = struct {
    /// Temporary, flat instruction list before the BBs are created
    instructions: ?*IR,

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
        retval.instructions = null;
        retval.block_graph_head = null;
        retval.basic_blocks = std.ArrayList(*BasicBlock).init(allocator);
        retval.leaves = std.ArrayList(*CFG).init(allocator);
        retval.symbol = symbol;
        retval.visited = false;

        var eval = try retval.flattenAST(symbol.scope, symbol.init.?, allocator);
        _ = eval;

        retval.block_graph_head = try retval.basicBlockFromIR(retval.instructions, allocator);

        return retval;
    }

    fn createBasicBlock(self: *CFG, allocator: std.mem.Allocator) !*BasicBlock {
        var retval = try allocator.create(BasicBlock);
        retval.uid = self.basic_blocks.items.len;
        try self.basic_blocks.append(retval);
        return retval;
    }

    fn flattenAST(self: *CFG, scope: *Scope, ast: *AST, allocator: std.mem.Allocator) !*SymbolVersion {
        _ = self;
        switch (ast.*) {
            .identifier => {
                var symbol = scope.lookup(ast.identifier.token.data).?;
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                return symbver;
            },
            else => {
                std.debug.print("Unimplemented flattenAST() for: AST.{s}\n", .{@tagName(ast.*)});
                return error.OutOfMemory;
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
            retval.instructions = maybe_ir;
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
