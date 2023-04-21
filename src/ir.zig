const std = @import("std");
const _symbol = @import("symbol.zig");

const AST = @import("ast.zig").AST;
const Scope = _symbol.Scope;
const Symbol = _symbol.Symbol;

const SymbolVersion = struct {
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
};

const IR = struct {
    uid: u64,
    dest: *SymbolVersion,
    src1: *SymbolVersion,
    src2: *SymbolVersion,
};

const BasicBlock = struct {
    uid: u64,
    instructions: std.ArrayList(*IR),
    has_branch: bool,

    next: *BasicBlock,

    branch: *BasicBlock,
};

pub const CFG = struct {
    /// Temporary, flat instruction list before the BBs are created
    instruction_list: std.ArrayList(*IR),

    /// Initial basic block in the basic block graph
    block_graph_head: *BasicBlock,

    /// Flat list of all basic blocks
    basic_blocks: std.ArrayList(*BasicBlock),

    /// All other functions called by this function
    leaves: std.ArrayList(*CFG),

    /// The function that this CFG represents
    symbol: *Symbol,

    pub fn create(symbol: *Symbol, allocator: std.mem.Allocator) !*CFG {
        var retval = try allocator.create(CFG);
        retval.instruction_list = std.ArrayList(*IR).init(allocator);
        retval.basic_blocks = std.ArrayList(*BasicBlock).init(allocator);
        retval.leaves = std.ArrayList(*CFG).init(allocator);

        var eval = try retval.flattenAST(symbol.scope, symbol.init.?, allocator);
        _ = eval;

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
};
