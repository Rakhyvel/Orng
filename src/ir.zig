const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const program = @import("program.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");
const _string = @import("zig-string/zig-string.zig");
const validate = @import("validate.zig");

const AST = _ast.AST;
const Error = errs.Error;
const Scope = _symbol.Scope;
const Span = @import("span.zig").Span;
const Symbol = _symbol.Symbol;
const Token = @import("token.zig").Token;

pub const SymbolVersion = struct {
    symbol: *Symbol,
    version: ?u64,
    def: ?*IR,

    lvalue: bool,
    uses: usize = 0,

    /// Type of the SymbolVersion. Temps use the same symbol, so can't use that for type info
    type: *AST,

    fn createUnversioned(symbol: *Symbol, _type: *AST, allocator: std.mem.Allocator) !*SymbolVersion {
        var retval = try allocator.create(SymbolVersion);
        retval.symbol = symbol;
        retval.uses = 0;
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
            var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
            defer arena.deinit();
            var out = _string.String.init(arena.allocator());
            defer out.deinit();

            if (symbver.lvalue) {
                out.concat("L") catch unreachable;
            } else {
                out.concat(" ") catch unreachable;
            }
            out.writer().print("{s}_{?}", .{ symbver.symbol.name, symbver.version }) catch unreachable;
            std.debug.print("{s:<10}", .{out.str()});
        } else {
            std.debug.print("<null>    ", .{});
        }
    }

    pub fn format(self: SymbolVersion, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();
        var out = _string.String.init(arena.allocator());
        defer out.deinit();

        if (self.lvalue) {
            out.concat("L") catch unreachable;
        } else {
            out.concat(" ") catch unreachable;
        }
        out.writer().print("{s}_{?}", .{ self.symbol.name, self.version }) catch unreachable;
        try writer.print("{s:<10}", .{out.str()});
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
    loadStruct,
    loadUnion, // src1 is init, data.int is tag id
    loadString,
    decl,

    // Monadic instructions
    copy,
    not,
    negate,
    // bitNot,
    addrOf,
    sizeOf, //< For extern types that Orng can't do automatically
    dereference,
    derefCopy,

    // Diadic instructions
    // bitOr,
    // bitXor,
    // bitAnd,
    equal,
    notEqual,
    greater,
    lesser,
    greaterEqual,
    lesserEqual,
    // leftShift,
    // rightShift,
    add,
    sub,
    mult,
    div,
    mod,
    exponent,
    index, // dest = src1[src2]
    indexCopy, // src1[src2] = data.symbver
    select, // dest = src1._${data.int}
    selectCopy,
    get_tag, // dest = src1.tag
    cast,

    // Control-flow
    label,
    jump,
    branchIfFalse,
    call,

    // Non-Code Generating
    discard, // Marks that a symbol isn't used, but that's OK

    // Errors
    pushStackTrace, // Pushes a static span/code to the lines array if debug mode is on
    popStackTrace, // Pops a message off the stack after a function is successfully called
    panic, // if debug mode is on, panics with a message, unrolls lines stack, exits
};

pub const IRData = union(enum) {
    branch: ?*IR,
    int: i128,
    float: f64,
    string_id: usize,
    string: []const u8,
    symbver: *SymbolVersion, // Used by index-copy, since it needs an extra symbver to hold index-rhs
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
    span: Span,

    removed: bool,

    safe: bool, // Disables static UB checks for this IR. Used for IR generated by `match`'s

    pub fn create(kind: IRKind, dest: ?*SymbolVersion, src1: ?*SymbolVersion, src2: ?*SymbolVersion, span: Span, allocator: std.mem.Allocator) !*IR {
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
        retval.span = span;
        ir_uid += 1;
        return retval;
    }

    fn createInt(dest: *SymbolVersion, int: i128, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadInt, dest, null, null, span, allocator);
        retval.data = IRData{ .int = int };
        return retval;
    }

    fn createFloat(dest: *SymbolVersion, float: f64, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadFloat, dest, null, null, span, allocator);
        retval.data = IRData{ .float = float };
        return retval;
    }

    fn createString(dest: *SymbolVersion, id: usize, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadString, dest, null, null, span, allocator);
        retval.data = IRData{ .string_id = id };
        return retval;
    }

    fn createLabel(span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.label, null, null, null, span, allocator);
        return retval;
    }

    fn createBranch(condition: *SymbolVersion, label: ?*IR, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.branchIfFalse, null, condition, null, span, allocator);
        retval.data = IRData{ .branch = label };
        return retval;
    }

    fn createJump(label: ?*IR, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.jump, null, null, null, span, allocator);
        retval.data = IRData{ .branch = label };
        return retval;
    }

    fn createCall(dest: *SymbolVersion, src1: *SymbolVersion, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.call, dest, src1, null, span, allocator);
        retval.data = IRData{ .symbverList = std.ArrayList(*SymbolVersion).init(allocator) };
        return retval;
    }

    fn createLoadStruct(dest: *SymbolVersion, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadStruct, dest, null, null, span, allocator);
        retval.data = IRData{ .symbverList = std.ArrayList(*SymbolVersion).init(allocator) };
        return retval;
    }

    fn createSelect(dest: *SymbolVersion, src1: *SymbolVersion, field_pos: i128, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.select, dest, src1, null, span, allocator);
        retval.data = IRData{ .int = field_pos };
        return retval;
    }

    fn createGetTag(dest: *SymbolVersion, src1: *SymbolVersion, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.get_tag, dest, src1, null, span, allocator);
        return retval;
    }

    fn createUnion(dest: *SymbolVersion, init: ?*SymbolVersion, tag: i128, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadUnion, dest, init, null, span, allocator);
        retval.data = IRData{ .int = tag };
        return retval;
    }

    fn createIndex(dest: *SymbolVersion, src1: *SymbolVersion, src2: *SymbolVersion, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.index, dest, src1, src2, span, allocator);
        retval.data = IRData.none;
        return retval;
    }

    fn createDiscard(src1: *SymbolVersion, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.discard, null, src1, null, span, allocator);
        retval.data = IRData.none;
        return retval;
    }

    fn createStackPush(span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.pushStackTrace, null, null, null, span, allocator);
        retval.data = IRData.none;
        return retval;
    }

    fn createStackPop(span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.popStackTrace, null, null, null, span, allocator);
        retval.data = IRData.none;
        return retval;
    }

    fn createPanic(message: []const u8, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.panic, null, null, null, span, allocator);
        retval.data = IRData{ .string = message };
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
            std.debug.print("    {:<3}\t{s:<12}", .{ self.uid, kind_name });
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
                .symbol => {
                    std.debug.print("\tsymbol:{s}", .{self.data.symbol.name});
                },
                .symbver => {
                    std.debug.print("\tsymbver:", .{});
                    self.data.symbver.pprint();
                },
                .symbverList => {
                    std.debug.print("\tsymbverList:[", .{});
                    for (self.data.symbverList.items, 1..) |symbver, i| {
                        symbver.pprint();
                        if (i < self.data.symbverList.items.len) {
                            std.debug.print(", ", .{});
                        }
                    }
                    std.debug.print("]", .{});
                },
                else => {},
            }
            std.debug.print("\n", .{});
        }
    }

    pub fn format(self: IR, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        if (self.kind == .label) {
            try writer.print("BB{}:\n", .{self.uid});
        } else {
            const kind_name = @tagName(self.kind);
            try writer.print("    {:<3}\t{s:<12}", .{ self.uid, kind_name });
            if (self.dest) |dest| {
                try SymbolVersion.format(dest.*, fmt, options, writer);
            } else {
                try writer.print("<null>    ", .{});
            }
            if (self.src1) |src1| {
                try SymbolVersion.format(src1.*, fmt, options, writer);
            } else {
                try writer.print("<null>    ", .{});
            }
            if (self.src2) |src2| {
                try SymbolVersion.format(src2.*, fmt, options, writer);
            } else {
                try writer.print("<null>    ", .{});
            }
            switch (self.data) {
                .branch => {
                    if (self.data.branch) |branch| {
                        try writer.print("\tBB{}", .{branch.uid});
                    }
                },
                .int => {
                    try writer.print("\tint:{}", .{self.data.int});
                },
                .float => {
                    try writer.print("\tfloat:{}", .{self.data.float});
                },
                .symbol => {
                    try writer.print("\tsymbol:{s}", .{self.data.symbol.name});
                },
                .symbverList => {
                    try writer.print("\tsymbverList:[", .{});
                    for (self.data.symbverList.items, 1..) |symbver, i| {
                        try symbver.format(fmt, options, writer);
                        if (i < self.data.symbverList.items.len) {
                            try writer.print(", ", .{});
                        }
                    }
                    try writer.print("]", .{});
                },
                else => {},
            }
            try writer.print("\n", .{});
        }
    }

    pub fn precedence(self: *IR) i64 {
        return switch (self.kind) {
            .loadSymbol,
            .loadExtern,
            .loadInt,
            .loadFloat,
            .loadStruct,
            .loadUnion,
            .loadString,
            .copy,
            => 0,

            .call,
            .exponent, // implemented as call to powf
            .index,
            .select,
            .get_tag,
            => 1,

            .negate,
            .not,
            .dereference,
            .addrOf,
            .sizeOf,
            => 2,

            .mult,
            .div,
            .mod,
            => 3,

            .add,
            .sub,
            => 4,

            // No bitshift operators, would be precedence 5

            .greater,
            .lesser,
            .greaterEqual,
            .lesserEqual,
            => 6,

            .equal,
            .notEqual,
            => 7,

            else => {
                std.debug.print("Unimplemented precedence for kind {s}\n", .{@tagName(self.kind)});
                unreachable;
            },
        };
    }
};

pub const BasicBlock = struct {
    uid: u64,
    ir_head: ?*IR,
    has_branch: bool,
    has_panic: bool,
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

        std.debug.print("BB{}", .{self.uid});
        BasicBlock.printSymbverList(&self.parameters);
        std.debug.print(":\n", .{});
        var maybe_ir = self.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            ir.pprint();
        }
        if (self.has_branch) {
            if (self.next) |next| {
                std.debug.print("    branch {s}_{?}, BB{}", .{ self.condition.?.symbol.name, self.condition.?.version, next.uid });
                BasicBlock.printSymbverList(&self.branch_arguments);
            } else {
                std.debug.print("    branch {s}_{?}, <END>", .{ self.condition.?.symbol.name, self.condition.?.version });
                BasicBlock.printSymbverList(&self.branch_arguments);
            }
            std.debug.print(", ", .{});
            if (self.branch) |branch| {
                std.debug.print("BB{}", .{branch.uid});
                BasicBlock.printSymbverList(&self.next_arguments);
            } else {
                std.debug.print("<END>", .{});
                BasicBlock.printSymbverList(&self.next_arguments);
            }
        } else {
            if (self.next) |next| {
                std.debug.print("    jump BB{}", .{next.uid});
                BasicBlock.printSymbverList(&self.next_arguments);
            } else {
                std.debug.print("    jump <END>", .{});
                BasicBlock.printSymbverList(&self.next_arguments);
            }
        }
        std.debug.print("\n\n", .{});
        if (self.next) |next| {
            next.pprint();
        }
        if (self.branch) |branch| {
            branch.pprint();
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
        std.debug.print(")", .{});
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

    pub fn findInstruction(bb: *BasicBlock, symbol: *Symbol) ?*IR {
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest.?.symbol == symbol) {
                return ir;
            }
        }
        return null;
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
    children: std.ArrayList(*CFG),

    /// The function that this CFG represents
    symbol: *Symbol,

    number_temps: usize,

    return_symbol: *Symbol,

    /// Non-owning pointer to set of interned string literals
    /// Provided by main, global to all CFGs.
    interned_strings: *std.ArrayList([]const u8),

    /// Whether or not this CFG is visited
    visited: bool,

    // BIG TODO: 'Contextualize' errors and allocator, so that method calls don't need that explicit passed in (they do not change from method call to method call)
    pub fn create(symbol: *Symbol, caller: ?*CFG, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors, allocator: std.mem.Allocator) !*CFG {
        if (symbol.cfg) |cfg| {
            return cfg;
        }
        var retval = try allocator.create(CFG);
        retval.ir_head = null;
        retval.ir_tail = null;
        retval.block_graph_head = null;
        retval.basic_blocks = std.ArrayList(*BasicBlock).init(allocator);
        retval.children = std.ArrayList(*CFG).init(allocator);
        retval.symbol = symbol;
        retval.number_temps = 0;
        retval.return_symbol = try Symbol.create(symbol.scope, "$retval", Span{ .filename = "", .col = 0, .line = 0 }, symbol._type.?.function.rhs, null, null, .mut, allocator);
        retval.visited = false;
        retval.interned_strings = interned_strings;
        symbol.cfg = retval;

        if (caller) |caller_node| {
            try caller_node.children.append(retval);
        }

        var eval: ?*SymbolVersion = try retval.flattenAST(symbol.scope, symbol.init.?, null, null, null, null, false, errors, allocator);
        var return_version = try SymbolVersion.createUnversioned(retval.return_symbol, symbol._type.?.function.rhs, allocator);
        retval.appendInstruction(try IR.create(.copy, return_version, eval, null, symbol.span, allocator));
        retval.appendInstruction(try IR.createJump(null, symbol.span, allocator));

        retval.block_graph_head = try retval.basicBlockFromIR(retval.ir_head, allocator);
        retval.removeBasicBlockLastInstruction();

        // for (retval.basic_blocks.items) |bb| {
        //     bb.pprint();
        // }
        // retval.clearVisitedBBs();
        try retval.calculatePhiParamsAndArgs(allocator);

        return retval;
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

    fn createBasicBlock(self: *CFG, allocator: std.mem.Allocator) !*BasicBlock {
        var retval = try allocator.create(BasicBlock);
        retval.ir_head = null;
        retval.condition = null;
        retval.has_panic = false;
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
        var temp_symbol = try Symbol.create(self.symbol.scope, (try buf.toOwned()).?, Span{ .filename = "", .line = 0, .col = 0 }, _type, null, null, .mut, allocator);
        temp_symbol.is_temp = true;
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

    fn flattenAST(self: *CFG, scope: *Scope, ast: *AST, return_label: ?*IR, break_label: ?*IR, continue_label: ?*IR, error_label: ?*IR, lvalue: bool, errors: *errs.Errors, allocator: std.mem.Allocator) error{
        typeError,
        OutOfMemory,
        NotAnLValue,
        Unimplemented,
        InvalidRange,
        Utf8ExpectedContinuation,
        Utf8OverlongEncoding,
        Utf8EncodesSurrogateHalf,
        Utf8CodepointTooLarge,
    }!?*SymbolVersion {
        switch (ast.*) {
            // Literals
            .unit => return null,
            .int => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var ir = try IR.createInt(temp, ast.int.data, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .char => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var codepoint: u21 = undefined;
                switch (ast.getToken().data[1]) {
                    '\\' => switch (ast.getToken().data[2]) {
                        'n' => codepoint = 0x0A,
                        'r' => codepoint = 0x0D,
                        't' => codepoint = 0x09,
                        '\\' => codepoint = 0x5C,
                        '\'' => codepoint = 0x27,
                        '"' => codepoint = 0x22,
                        else => unreachable,
                    },
                    else => {
                        var num_bytes = std.unicode.utf8ByteSequenceLength(ast.getToken().data[1]) catch return error.typeError;
                        codepoint = try std.unicode.utf8Decode(ast.getToken().data[1 .. num_bytes + 1]);
                    },
                }
                var ir = try IR.createInt(temp, codepoint, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .float => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var ir = try IR.createFloat(temp, ast.float.data, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .string => {
                try program.interned_string_set_add(ast.getToken().data, self.interned_strings);
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var ir = try IR.createString(temp, self.interned_strings.items.len - 1, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .identifier => {
                var symbol = scope.lookup(ast.getToken().data, false).?;
                if (symbol.kind == ._fn) {
                    _ = try create(symbol, self, self.interned_strings, errors, allocator);
                }
                var src = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                return src;
            },
            ._true => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var ir = try IR.createInt(temp, 1, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            ._false => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var ir = try IR.createInt(temp, 0, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },

            // Unary operators
            .not => {
                var expr = try self.flattenAST(scope, ast.not.expr, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (expr == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.create(.not, temp, expr, null, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .negate => {
                var expr = try self.flattenAST(scope, ast.negate.expr, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (expr == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.create(.negate, temp, expr, null, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .dereference => {
                var expr = try self.flattenAST(scope, ast.dereference.expr, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (expr == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                temp.lvalue = lvalue;

                var ir = try IR.create(.dereference, temp, expr, null, ast.getToken().span, allocator);
                temp.def = ir;
                temp.lvalue = lvalue;
                self.appendInstruction(ir);
                return temp;
            },
            ._try => {
                var expr = (try self.flattenAST(scope, ast._try.expr, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;

                var end = try IR.createLabel(ast.getToken().span, allocator);
                var err = try IR.createLabel(ast.getToken().span, allocator);

                var expanded_expr_type = try expr.type.exapnd_type(scope, errors, allocator);
                // Trying error sum, runtime check if error, branch to error path
                var condition = try createTempSymbolVersion(self, _ast.boolType, allocator);
                var load_tag = try IR.createGetTag(condition, expr, ast.getToken().span, allocator); // Assumes `ok` tag is nonzero, `err` tag is zero
                condition.def = load_tag;
                self.appendInstruction(load_tag);
                self.appendInstruction(try IR.createBranch(condition, err, ast.getToken().span, allocator));

                // Unwrap the `.ok` value
                var ok_symbver = try self.createTempSymbolVersion(expanded_expr_type.sum.terms.items[1], allocator);
                var unwrap_ok = try IR.createSelect(ok_symbver, expr, 1, ast.getToken().span, allocator);
                ok_symbver.def = unwrap_ok;
                self.appendInstruction(unwrap_ok);
                self.appendInstruction(try IR.createJump(end, ast.getToken().span, allocator));

                // Else, store the error in retval, return through error
                self.appendInstruction(err);
                var retval_symbver = try SymbolVersion.createUnversioned(self.return_symbol, self.symbol._type.?.function.rhs, allocator);
                var retval_copy = try IR.create(.copy, retval_symbver, expr, null, ast.getToken().span, allocator);
                retval_symbver.def = retval_copy;
                self.appendInstruction(retval_copy);
                self.appendInstruction(try IR.createJump(error_label, ast.getToken().span, allocator));

                self.appendInstruction(end);
                return ok_symbver;
            },
            .discard => {
                var expr = try self.flattenAST(scope, ast.discard.expr, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (expr == null) {
                    return null;
                }
                expr.?.symbol.discard_span = ast.getToken().span;
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.createDiscard(expr.?, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },

            // Binary operators
            .assign => {
                var rhs = try self.flattenAST(scope, ast.assign.rhs, return_label, break_label, continue_label, error_label, false, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                return try self.generate_assign(scope, ast.assign.lhs, rhs.?, return_label, break_label, continue_label, error_label, errors, allocator);
            },
            ._or => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // Labels used
                var else_label = try IR.createLabel(ast.getToken().span, allocator);
                var end_label = try IR.createLabel(ast.getToken().span, allocator);

                // Test lhs, branch
                var lhs = (try self.flattenAST(scope, ast._or.lhs, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                var branch = try IR.createBranch(lhs, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, store `true` in symbver
                var load_true_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var load_true = try IR.createInt(load_true_symbver, 1, ast.getToken().span, allocator);
                load_true_symbver.def = load_true;
                self.appendInstruction(load_true);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, recurse to rhs, store in symbver
                self.appendInstruction(else_label);
                var rhs = try self.flattenAST(scope, ast._or.rhs, return_label, break_label, continue_label, error_label, false, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                var copy_right_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var copy_right = try IR.create(.copy, copy_right_symbver, rhs, null, ast.getToken().span, allocator);
                copy_right_symbver.def = copy_right;
                self.appendInstruction(copy_right);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },
            ._and => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // Labels used
                var else_label = try IR.createLabel(ast.getToken().span, allocator);
                var end_label = try IR.createLabel(ast.getToken().span, allocator);

                // Test lhs, branch
                var lhs = (try self.flattenAST(scope, ast._and.lhs, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                var branch = try IR.createBranch(lhs, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in symbver
                var rhs = try self.flattenAST(scope, ast._and.rhs, return_label, break_label, continue_label, error_label, false, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                var copy_right_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var copy_right = try IR.create(.copy, copy_right_symbver, rhs, null, ast.getToken().span, allocator);
                copy_right_symbver.def = copy_right;
                self.appendInstruction(copy_right);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, store `false` in symbver
                self.appendInstruction(else_label);
                var load_false_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var load_false = try IR.createInt(load_false_symbver, 0, ast.getToken().span, allocator);
                load_false_symbver.def = load_false;
                self.appendInstruction(load_false);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },
            .add => {
                var lhs = try self.flattenAST(scope, ast.add.lhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                var rhs = try self.flattenAST(scope, ast.add.rhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.create(.add, temp, lhs, rhs, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .sub => {
                var lhs = try self.flattenAST(scope, ast.sub.lhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                var rhs = try self.flattenAST(scope, ast.sub.rhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.create(.sub, temp, lhs, rhs, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .mult => {
                var lhs = try self.flattenAST(scope, ast.mult.lhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                var rhs = try self.flattenAST(scope, ast.mult.rhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.create(.mult, temp, lhs, rhs, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .div => {
                var lhs = try self.flattenAST(scope, ast.div.lhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                var rhs = try self.flattenAST(scope, ast.div.rhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.create(.div, temp, lhs, rhs, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .mod => {
                var lhs = try self.flattenAST(scope, ast.mod.lhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                var rhs = try self.flattenAST(scope, ast.mod.rhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.create(.mod, temp, lhs, rhs, ast.getToken().span, allocator);
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

                rhs = (try self.flattenAST(scope, ast.exponent.terms.items[terms_len - 1], return_label, break_label, continue_label, error_label, lvalue, errors, allocator)).?;
                var i: usize = ast.exponent.terms.items.len - 1;
                while (i > 0) : (i -= 1) {
                    lhs = (try self.flattenAST(scope, ast.exponent.terms.items[i - 1], return_label, break_label, continue_label, error_label, lvalue, errors, allocator)).?;
                    temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                    var ir = try IR.create(.exponent, temp, lhs, rhs, ast.getToken().span, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    rhs = temp;
                }
                return temp;
            },
            ._catch => {
                // Create the result symbol.
                // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator); // Not actually assigned directly, just so that optimizations can capture the version

                var lhs = (try self.flattenAST(scope, ast._catch.lhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator)).?;

                // Labels used
                var else_label = try IR.createLabel(ast.getToken().span, allocator);
                var end_label = try IR.createLabel(ast.getToken().span, allocator);

                // Test if lhs tag is 1 (some)
                var condition = try createTempSymbolVersion(self, _ast.boolType, allocator);
                var load_tag = try IR.createGetTag(condition, lhs, ast.getToken().span, allocator); // Assumes `ok` tag is nonzero, `err` tag is zero
                condition.def = load_tag;
                self.appendInstruction(load_tag);

                var branch = try IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // tag was `.ok`, store lhs.some in symbver
                var val = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var ir_select = try IR.createSelect(val, lhs, 1, ast.getToken().span, allocator);
                val.def = ir_select;
                self.appendInstruction(ir_select);
                var some_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                self.appendInstruction(try IR.create(.copy, some_symbver, val, null, ast.getToken().span, allocator));
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                self.appendInstruction(else_label);

                // tag was `.err`, store rhs in symbver
                var rhs = (try self.flattenAST(scope, ast._catch.rhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator)).?;

                var rhs_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                self.appendInstruction(try IR.create(.copy, rhs_symbver, rhs, null, ast.getToken().span, allocator));

                self.appendInstruction(end_label);
                return symbver;
            },
            ._orelse => {
                // Create the result symbol.
                // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator); // Not actually assigned directly, just so that optimizations can capture the version

                var lhs = (try self.flattenAST(scope, ast._orelse.lhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator)).?;

                // Labels used
                var else_label = try IR.createLabel(ast.getToken().span, allocator);
                var end_label = try IR.createLabel(ast.getToken().span, allocator);

                // Test if lhs tag is 1 (some)
                var condition = try createTempSymbolVersion(self, _ast.boolType, allocator);
                var load_tag = try IR.createGetTag(condition, lhs, ast.getToken().span, allocator); // Assumes `some` tag is nonzero, `none` tag is zero
                condition.def = load_tag;
                self.appendInstruction(load_tag);

                var branch = try IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // tag was `.some`, store lhs.some in symbver
                var val = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var ir_select = try IR.createSelect(val, lhs, 1, ast.getToken().span, allocator);
                val.def = ir_select;
                self.appendInstruction(ir_select);
                var some_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                self.appendInstruction(try IR.create(.copy, some_symbver, val, null, ast.getToken().span, allocator));
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                self.appendInstruction(else_label);

                // tag was `.none`, store rhs in symbver
                var rhs = (try self.flattenAST(scope, ast._orelse.rhs, return_label, break_label, continue_label, error_label, lvalue, errors, allocator)).?;

                var rhs_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                self.appendInstruction(try IR.create(.copy, rhs_symbver, rhs, null, ast.getToken().span, allocator));

                self.appendInstruction(end_label);
                return symbver;
            },
            .call => {
                var lhs = (try self.flattenAST(scope, ast.call.lhs, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                temp.symbol.span = ast.getToken().span;

                var ir = try IR.createCall(temp, lhs, ast.getToken().span, allocator);
                switch (ast.call.rhs.*) {
                    .unit => {},
                    .product => for (ast.call.rhs.product.terms.items) |term| {
                        try ir.data.symbverList.append((try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, false, errors, allocator)).?);
                    },
                    else => try ir.data.symbverList.append((try self.flattenAST(scope, ast.call.rhs, return_label, break_label, continue_label, error_label, false, errors, allocator)).?),
                }
                temp.def = ir;
                self.appendInstruction(try IR.createStackPush(ast.getToken().span, allocator));
                self.appendInstruction(ir);
                self.appendInstruction(try IR.createStackPop(ast.getToken().span, allocator));
                return temp;
            },
            .index => {
                var lhs = (try self.flattenAST(scope, ast.index.lhs, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                var rhs = (try self.flattenAST(scope, ast.index.rhs, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                temp.lvalue = lvalue;

                try self.generate_bounds_check(scope, ast, lhs, rhs, errors, allocator);

                var new_lhs = try SymbolVersion.createUnversioned(lhs.symbol, lhs.type, allocator);
                var new_rhs = try SymbolVersion.createUnversioned(rhs.symbol, rhs.type, allocator);
                var ir = try IR.createIndex(temp, new_lhs, new_rhs, ast.getToken().span, allocator);
                ir.span = ast.getToken().span;
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .select => {
                var do_check = (try ast.select.lhs.typeof(scope, errors, allocator)).* == .sum;
                var lhs = (try self.flattenAST(scope, ast.select.lhs, return_label, break_label, continue_label, error_label, !do_check, errors, allocator)).?;
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                temp.lvalue = lvalue;

                if (do_check) {
                    var all_good_label = try IR.createLabel(ast.getToken().span, allocator);
                    var sel = try self.createTempSymbolVersion(_ast.intType, allocator);
                    var sel_ir = try IR.createInt(sel, ast.select.pos.?, ast.getToken().span, allocator);
                    sel.def = sel_ir;
                    self.appendInstruction(sel_ir);
                    var tag = try self.createTempSymbolVersion(_ast.intType, allocator);
                    var tag_ir = try IR.createGetTag(tag, lhs, ast.getToken().span, allocator);
                    tag.def = tag_ir;
                    self.appendInstruction(tag_ir);
                    var neql = try self.createTempSymbolVersion(_ast.boolType, allocator);
                    var neql_ir = try IR.create(.notEqual, neql, tag, sel, ast.getToken().span, allocator);
                    neql.def = neql_ir;
                    self.appendInstruction(neql_ir);
                    var branch = try IR.createBranch(neql, all_good_label, ast.getToken().span, allocator);
                    self.appendInstruction(branch);
                    self.appendInstruction(try IR.createStackPush(ast.select.rhs.getToken().span, allocator));
                    self.appendInstruction(try IR.createPanic("access of inactive sum field", ast.select.rhs.getToken().span, allocator));
                    self.appendInstruction(all_good_label);
                }

                var new_lhs = try SymbolVersion.createUnversioned(lhs.symbol, lhs.type, allocator);
                var ir = try IR.createSelect(temp, new_lhs, ast.select.pos.?, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .product => {
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var ir = try IR.createLoadStruct(temp, ast.getToken().span, allocator);
                for (ast.product.terms.items) |term| {
                    try ir.data.symbverList.append((try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, false, errors, allocator)).?);
                }
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },

            // Fancy Operators
            .addrOf => {
                var expr = try self.flattenAST(scope, ast.addrOf.expr, return_label, break_label, continue_label, error_label, true, errors, allocator);
                if (expr == null) {
                    return null;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.create(.addrOf, temp, expr, null, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .subSlice => {
                var arr = (try self.flattenAST(scope, ast.subSlice.super, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                var lower = (try self.flattenAST(scope, ast.subSlice.lower.?, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                var upper = (try self.flattenAST(scope, ast.subSlice.upper.?, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;

                // Statically confirm that lower <= upper
                if (lower.def.?.kind == .loadInt and upper.def.?.kind == .loadInt and lower.def.?.data.int > upper.def.?.data.int) {
                    errors.addError(Error{ .slice_lower_upper = .{
                        .span = lower.def.?.span,
                        .lower = lower.def.?.data.int,
                        .upper = upper.def.?.data.int,
                    } });
                    return error.typeError;
                } else { // Dynamically confirm that lower <= upper
                    var end_label = try IR.createLabel(ast.getToken().span, allocator);
                    var compare = try self.createTempSymbolVersion(_ast.boolType, allocator);
                    var ir = try IR.create(.greater, compare, lower, upper, ast.getToken().span, allocator);
                    compare.def = ir;
                    self.appendInstruction(ir);
                    var branch = try IR.createBranch(compare, end_label, ast.getToken().span, allocator);
                    self.appendInstruction(branch);
                    self.appendInstruction(try IR.createStackPush(ast.getToken().span, allocator));
                    self.appendInstruction(try IR.createPanic("subslice lower bound is greater than upper bound", ast.getToken().span, allocator));
                    self.appendInstruction(end_label);
                }

                var new_size = try self.createTempSymbolVersion(_ast.intType, allocator);
                var new_size_ir = try IR.create(.sub, new_size, upper, lower, ast.getToken().span, allocator);
                new_size.def = new_size_ir;
                self.appendInstruction(new_size_ir);

                var slice_type = try ast.typeof(scope, errors, allocator);
                var data_type = slice_type.product.terms.items[0];
                var data_ptr = try self.createTempSymbolVersion(data_type, allocator);
                var data_ptr_ir = try IR.createSelect(data_ptr, arr, 0, ast.getToken().span, allocator);
                data_ptr.def = data_ptr_ir;
                self.appendInstruction(data_ptr_ir);

                var new_data_ptr = try self.createTempSymbolVersion(data_type, allocator);
                var new_data_ptr_ir = try IR.create(.add, new_data_ptr, data_ptr, lower, ast.getToken().span, allocator);
                new_data_ptr.def = new_data_ptr_ir;
                self.appendInstruction(new_data_ptr_ir);

                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);
                var load_struct = try IR.createLoadStruct(temp, ast.getToken().span, allocator);
                try load_struct.data.symbverList.append(new_data_ptr);
                try load_struct.data.symbverList.append(new_size);
                temp.def = load_struct;
                self.appendInstruction(load_struct);
                return temp;
            },
            .inferredMember => {
                var init: ?*SymbolVersion = null;
                var pos: i128 = ast.inferredMember.pos.?;
                var proper_term: *AST = (try ast.typeof(scope, errors, allocator)).sum.terms.items[@as(usize, @intCast(pos))];
                if (ast.inferredMember.init) |_init| {
                    init = try self.flattenAST(scope, _init, return_label, break_label, continue_label, error_label, true, errors, allocator);
                } else if (proper_term.annotation.init == null and proper_term.annotation.type.* != .unit) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "no value provided, and no default value available" } });
                    return error.typeError;
                }
                var temp = try self.createTempSymbolVersion(try ast.typeof(scope, errors, allocator), allocator);

                var ir = try IR.createUnion(temp, init, ast.inferredMember.pos.?, ast.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .conditional => {
                std.debug.assert(ast.conditional.exprs.items.len == ast.conditional.tokens.items.len + 1);

                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                var end_label = try IR.createLabel(ast.getToken().span, allocator);
                var else_label = try IR.createLabel(ast.getToken().span, allocator);

                var i: usize = 0;
                var lhs = (try self.flattenAST(scope, ast.conditional.exprs.items[0], return_label, break_label, continue_label, error_label, false, errors, allocator));
                while (i < ast.conditional.tokens.items.len) : (i += 1) {
                    // Test lhs, branch
                    var rhs = try self.flattenAST(scope, ast.conditional.exprs.items[i + 1], return_label, break_label, continue_label, error_label, false, errors, allocator);
                    if (rhs == null) {
                        return null;
                    }
                    var token = ast.conditional.tokens.items[i];
                    var ir_kind: IRKind = undefined;
                    switch (token.kind) {
                        .D_EQUALS => {
                            ir_kind = .equal;
                        },
                        .NOT_EQUALS => {
                            ir_kind = .notEqual;
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
                    var ir = try IR.create(ir_kind, temp, lhs, rhs, ast.getToken().span, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    var branch = try IR.createBranch(temp, else_label, ast.getToken().span, allocator);
                    self.appendInstruction(branch);
                    lhs = rhs;
                }
                // all tests passed, store `true` in symbver
                var load_true_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var load_true = try IR.createInt(load_true_symbver, 1, ast.getToken().span, allocator);
                load_true_symbver.def = load_true;
                self.appendInstruction(load_true);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                // at least one test failed, store `false` in symbver
                self.appendInstruction(else_label);
                var load_false_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                var load_false = try IR.createInt(load_false_symbver, 0, ast.getToken().span, allocator);
                load_false_symbver.def = load_false;
                self.appendInstruction(load_false);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(end_label);
                return symbver;
            },

            // Control-flow expressions
            ._if => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // If there's a let, then do it, dumby!
                if (ast._if.let) |let| {
                    _ = try self.flattenAST(ast._if.scope.?, let, return_label, break_label, continue_label, error_label, false, errors, allocator);
                }

                // Labels used
                var else_label = try IR.createLabel(ast.getToken().span, allocator);
                var end_label = try IR.createLabel(ast.getToken().span, allocator);

                // Test lhs, branch
                var condition = (try self.flattenAST(ast._if.scope.?, ast._if.condition, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                var branch = try IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in symbver
                if (try self.flattenAST(ast._if.scope.?, ast._if.bodyBlock, return_label, break_label, continue_label, error_label, false, errors, allocator)) |block_symbver| {
                    var block_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    var block_copy: *IR = undefined;
                    if (ast._if.elseBlock == null) {
                        // no else block => if is optional, coerce up to `.some <- block`
                        block_copy = try IR.createUnion(block_copy_symbver, block_symbver, 1, ast.getToken().span, allocator);
                    } else {
                        // regular if-else => copy block
                        block_copy = try IR.create(.copy, block_copy_symbver, block_symbver, null, ast.getToken().span, allocator);
                    }
                    block_copy_symbver.def = block_copy;
                    self.appendInstruction(block_copy);
                }
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, store `false` in symbver
                self.appendInstruction(else_label);
                if (ast._if.elseBlock) |elseBlock| {
                    if (try self.flattenAST(ast._if.scope.?, elseBlock, return_label, break_label, continue_label, error_label, false, errors, allocator)) |else_symbver| {
                        var else_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                        var else_copy = try IR.create(.copy, else_copy_symbver, else_symbver, null, ast.getToken().span, allocator);
                        else_copy_symbver.def = else_copy;
                        self.appendInstruction(else_copy);
                    }
                    self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                } else {
                    // no else block => if is optional, store null
                    var else_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    var else_copy = try IR.createUnion(else_copy_symbver, null, 0, ast.getToken().span, allocator);
                    else_copy_symbver.def = else_copy;
                    self.appendInstruction(else_copy);
                }
                self.appendInstruction(end_label);
                return symbver;
            },
            .match => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // Exit label of match
                var end_label = try IR.createLabel(ast.getToken().span, allocator);
                // Label jumped to if all tests fail and no `else` mapping
                var none_label = try IR.createLabel(ast.getToken().span, allocator);
                // List of labels to branch to on an unsuccessful test (ie "next pattern")
                var lhs_label_list = std.ArrayList(*IR).init(allocator);
                defer lhs_label_list.deinit();
                // List of labels to branch to on a successful test (ie "code for the mapping")
                var rhs_label_list = std.ArrayList(*IR).init(allocator);
                defer rhs_label_list.deinit();
                for (ast.match.mappings.items) |_| {
                    try lhs_label_list.append(try IR.createLabel(ast.getToken().span, allocator));
                    try rhs_label_list.append(try IR.createLabel(ast.getToken().span, allocator));
                }
                std.debug.assert(lhs_label_list.items.len == ast.match.mappings.items.len);

                // If there's a let, then do it, dumby!
                if (ast.match.let) |let| {
                    _ = try self.flattenAST(ast.match.scope.?, let, return_label, break_label, continue_label, error_label, false, errors, allocator);
                }

                var expr = try self.flattenAST(scope, ast.match.expr, return_label, break_label, continue_label, error_label, false, errors, allocator);
                if (expr == null) {
                    return null;
                }

                var label_index: usize = 0;
                for (ast.match.mappings.items) |mapping| {
                    var lhs_label = lhs_label_list.items[label_index];
                    self.appendInstruction(lhs_label);
                    if (mapping.mapping.lhs) |lhs| {
                        var next_label = if (label_index < lhs_label_list.items.len - 1)
                            lhs_label_list.items[label_index + 1]
                        else
                            none_label;
                        try self.generate_match_pattern_check(ast.match.scope.?, lhs, expr.?, next_label, return_label, break_label, continue_label, error_label, errors, allocator);
                    }
                    self.appendInstruction(try IR.createJump(rhs_label_list.items[label_index], mapping.getToken().span, allocator));
                    label_index += 1;
                }

                if (!ast.match.has_else) { // All tests failed, no `else` mapping. Store `.none` as result
                    self.appendInstruction(none_label);
                    var else_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    var else_copy = try IR.createUnion(else_copy_symbver, null, 0, ast.getToken().span, allocator);
                    else_copy_symbver.def = else_copy;
                    self.appendInstruction(else_copy);
                    self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                }

                // Write the labels and the rhs of the mappings
                label_index = 0;
                for (ast.match.mappings.items) |mapping| {
                    self.appendInstruction(rhs_label_list.items[label_index]);
                    if (mapping.mapping.lhs) |lhs| {
                        // Generate initialization for patterns before the rhs
                        try self.generate_pattern(ast.match.scope.?, lhs, expr.?.type, expr.?, errors, allocator);
                    }

                    // Generate the rhs, copy result to symbver
                    var mapping_scope = if (mapping.mapping.scope != null) mapping.mapping.scope.? else ast.match.scope.?;
                    if (try self.flattenAST(mapping_scope, mapping.mapping.rhs.?, return_label, break_label, continue_label, error_label, false, errors, allocator)) |rhs_symbver| {
                        var rhs_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                        var rhs_copy: *IR = undefined;
                        if (ast.match.has_else) {
                            rhs_copy = try IR.create(.copy, rhs_copy_symbver, rhs_symbver, null, ast.getToken().span, allocator);
                        } else {
                            rhs_copy = try IR.createUnion(rhs_copy_symbver, rhs_symbver, 1, ast.getToken().span, allocator);
                        }
                        rhs_copy_symbver.def = rhs_copy;
                        self.appendInstruction(rhs_copy);
                    }
                    self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                    label_index += 1;
                }
                self.appendInstruction(end_label);

                return symbver;
            },
            ._while => {
                // Create the result symbol and IR
                var symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), allocator);
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);

                // Labels used
                var cond_label = try IR.createLabel(ast.getToken().span, allocator);
                var current_continue_label = try IR.createLabel(ast.getToken().span, allocator);
                var else_label = try IR.createLabel(ast.getToken().span, allocator);
                var end_label = try IR.createLabel(ast.getToken().span, allocator);

                // If there's a let, then do it, dumby!
                if (ast._while.let) |let| {
                    _ = try self.flattenAST(ast._while.scope.?, let, return_label, break_label, continue_label, error_label, false, errors, allocator);
                }

                // Test condition, branch to either body or else block
                self.appendInstruction(cond_label);
                var condition = (try self.flattenAST(ast._while.scope.?, ast._while.condition, return_label, end_label, current_continue_label, error_label, false, errors, allocator)).?;
                var branch = try IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // Body block
                if (try self.flattenAST(ast._while.scope.?, ast._while.bodyBlock, return_label, end_label, current_continue_label, error_label, false, errors, allocator)) |block_symbver| {
                    var block_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    var block_copy: *IR = undefined;
                    if (ast._while.elseBlock == null) {
                        // no else block => while is optional, coerce up to `.some <- block`
                        block_copy = try IR.createUnion(block_copy_symbver, block_symbver, 1, ast.getToken().span, allocator);
                    } else {
                        // regular while-else => copy block
                        block_copy = try IR.create(.copy, block_copy_symbver, block_symbver, null, ast.getToken().span, allocator);
                    }
                    self.appendInstruction(block_copy);
                    block_copy_symbver.def = block_copy;
                }

                // Post-condition, jump to condition test
                self.appendInstruction(current_continue_label);
                if (ast._while.post) |post| {
                    _ = try self.flattenAST(ast._while.scope.?, post, return_label, end_label, continue_label, error_label, false, errors, allocator);
                }
                self.appendInstruction(try IR.createJump(cond_label, ast.getToken().span, allocator));

                // Else block
                self.appendInstruction(else_label);
                if (ast._while.elseBlock) |elseBlock| {
                    if (try self.flattenAST(ast._while.scope.?, elseBlock, return_label, break_label, continue_label, error_label, false, errors, allocator)) |elseSymbver| {
                        var elseCopy = try IR.create(.copy, symbver, elseSymbver, null, ast.getToken().span, allocator);
                        self.appendInstruction(elseCopy);
                    }
                    self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                } else {
                    // no else block => while is optional, store null
                    var else_copy_symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                    var else_copy = try IR.createUnion(else_copy_symbver, null, 0, ast.getToken().span, allocator);
                    else_copy_symbver.def = else_copy;
                    self.appendInstruction(else_copy);
                }
                self.appendInstruction(end_label);
                return symbver;
            },
            .block => {
                if (ast.block.statements.items.len == 0 and ast.block.final == null) {
                    return null;
                } else {
                    var continue_labels = std.ArrayList(*IR).init(allocator);
                    defer continue_labels.deinit();
                    var break_labels = std.ArrayList(*IR).init(allocator);
                    defer break_labels.deinit();
                    var return_labels = std.ArrayList(*IR).init(allocator);
                    defer return_labels.deinit();
                    var error_labels = std.ArrayList(*IR).init(allocator);
                    defer error_labels.deinit();
                    for (ast.block.scope.?.defers.items) |_| {
                        try continue_labels.append(try IR.createLabel(ast.getToken().span, allocator));
                        try break_labels.append(try IR.createLabel(ast.getToken().span, allocator));
                        try return_labels.append(try IR.createLabel(ast.getToken().span, allocator));
                    }
                    for (ast.block.scope.?.errdefers.items) |_| {
                        try error_labels.append(try IR.createLabel(ast.getToken().span, allocator));
                    }
                    var end = try IR.createLabel(ast.getToken().span, allocator);

                    // These are the labels to go to on each final statement. These are updated to point to different places in the defer chain at the end of this block.
                    var current_continue_label = if (continue_label != null) continue_label else end;
                    var current_break_label = break_label;
                    var current_return_label = return_label;
                    var current_error_label = error_label;
                    var defer_label_index: usize = 0;
                    var errdefer_label_index: usize = 0;

                    var temp: ?*SymbolVersion = null;
                    for (ast.block.statements.items) |child| {
                        temp = try self.flattenAST(ast.block.scope.?, child, current_return_label, current_break_label, current_continue_label, current_error_label, lvalue, errors, allocator);
                        if (child.* == ._defer) {
                            current_continue_label = continue_labels.items[defer_label_index];
                            current_break_label = break_labels.items[defer_label_index];
                            current_return_label = return_labels.items[defer_label_index];
                            defer_label_index += 1;
                        } else if (child.* == ._errdefer) {
                            current_error_label = error_labels.items[errdefer_label_index];
                            errdefer_label_index += 1;
                        }
                    }
                    if (ast.block.final) |final| {
                        temp = try self.flattenAST(ast.block.scope.?, final, current_return_label, current_break_label, current_continue_label, current_error_label, lvalue, errors, allocator);
                    } else if (temp) |_temp| {
                        var expanded_temp_type = try _temp.type.exapnd_type(scope, errors, allocator);
                        if (current_error_label != null and expanded_temp_type.* == .sum and expanded_temp_type.sum.was_error) {
                            // Returning error sum, runtime check if error, branch to error path
                            var condition = try createTempSymbolVersion(self, _ast.boolType, allocator);
                            var load_tag = try IR.createGetTag(condition, _temp, ast.getToken().span, allocator); // Assumes `ok` tag is nonzero, `err` tag is zero
                            condition.def = load_tag;
                            self.appendInstruction(load_tag);
                            self.appendInstruction(try IR.createBranch(condition, current_error_label, ast.getToken().span, allocator));
                        }
                    }

                    try self.generateDefers(&ast.block.scope.?.defers, &continue_labels, ast.block.scope.?, errors, allocator);
                    self.appendInstruction(try IR.createJump(end, ast.getToken().span, allocator));

                    try self.generateDefers(&ast.block.scope.?.defers, &break_labels, ast.block.scope.?, errors, allocator);
                    self.appendInstruction(try IR.createJump(break_label, ast.getToken().span, allocator));

                    try self.generateDefers(&ast.block.scope.?.defers, &return_labels, ast.block.scope.?, errors, allocator);
                    self.appendInstruction(try IR.createJump(return_label, ast.getToken().span, allocator));

                    try self.generateDefers(&ast.block.scope.?.errdefers, &error_labels, ast.block.scope.?, errors, allocator);
                    self.appendInstruction(try IR.createJump(error_label, ast.getToken().span, allocator));

                    self.appendInstruction(end);

                    return temp;
                }
            },

            // Control-flow statements
            .decl => {
                var def: ?*SymbolVersion = null;
                if (ast.decl.init) |init| {
                    def = try self.flattenAST(scope, init, return_label, break_label, continue_label, error_label, false, errors, allocator);
                } else {
                    def = try self.generate_default(scope, ast.decl.type.?, errors, allocator);
                }
                if (def == null) {
                    return null;
                }
                try self.generate_pattern(scope, ast.decl.pattern, try ast.decl.type.?.exapnd_type(scope, errors, allocator), def.?, errors, allocator);
                return null;
            },
            .fnDecl => {
                _ = try create(ast.fnDecl.symbol.?, self, self.interned_strings, errors, allocator);
                var symbver = try self.createTempSymbolVersion(ast.fnDecl.symbol.?._type.?, allocator);
                var ir = try IR.create(.loadSymbol, symbver, null, null, ast.getToken().span, allocator);
                ir.data = IRData{ .symbol = ast.fnDecl.symbol.? };
                symbver.def = ir;
                self.appendInstruction(ir);
                return symbver;
            },
            ._errdefer, ._defer => {
                return null;
            },
            ._continue => {
                self.appendInstruction(try IR.createJump(continue_label, ast.getToken().span, allocator));
                return null;
            },
            ._unreachable => {
                self.appendInstruction(try IR.createStackPush(ast.getToken().span, allocator));
                self.appendInstruction(try IR.createPanic("reached unreachable code", ast.getToken().span, allocator));
                return null;
            },
            ._break => {
                self.appendInstruction(try IR.createJump(break_label, ast.getToken().span, allocator));
                return null;
            },
            ._return => {
                if (ast._return.expr) |expr| {
                    // Copy expr to retval
                    var retval = (try self.flattenAST(scope, expr, return_label, break_label, continue_label, error_label, false, errors, allocator)).?;
                    var retval_symbver = try SymbolVersion.createUnversioned(self.return_symbol, self.symbol._type.?.function.rhs, allocator);
                    var retval_copy = try IR.create(.copy, retval_symbver, retval, null, ast.getToken().span, allocator);
                    retval_symbver.def = retval_copy;
                    self.appendInstruction(retval_copy);

                    var expanded_expr_type = try (try expr.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);
                    if (expanded_expr_type.* == .sum and expanded_expr_type.sum.was_error) {
                        // Returning error sum, runtime check if error, branch to error path
                        var condition = try createTempSymbolVersion(self, _ast.boolType, allocator);
                        var load_tag = try IR.createGetTag(condition, retval, ast.getToken().span, allocator); // Assumes `ok` tag is nonzero, `err` tag is zero
                        condition.def = load_tag;
                        self.appendInstruction(load_tag);
                        self.appendInstruction(try IR.createBranch(condition, error_label.?, ast.getToken().span, allocator));
                    }
                    self.appendInstruction(try IR.createJump(return_label, ast.getToken().span, allocator));
                } else {
                    // Jump to return_label
                    self.appendInstruction(try IR.createJump(return_label, ast.getToken().span, allocator));
                }
                return null;
            },

            // Types?
            .sum => return null,

            else => {
                std.debug.print("Unimplemented flattenAST() for: AST.{s}\n", .{@tagName(ast.*)});
                return error.Unimplemented;
            },
        }
    }

    /// Takes in a type, generates the code to create the default value for that type, returns SymbolVersion
    fn generate_default(self: *CFG, scope: *Scope, _type: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) error{
        typeError,
        OutOfMemory,
        NotAnLValue,
        Unimplemented,
        InvalidRange,
        Utf8ExpectedContinuation,
        Utf8OverlongEncoding,
        Utf8EncodesSurrogateHalf,
        Utf8CodepointTooLarge,
    }!?*SymbolVersion {
        switch (_type.*) {
            .identifier => {
                if (std.mem.eql(u8, _type.getToken().data, "Bool")) {
                    // default is false
                    var temp = try self.createTempSymbolVersion(_type, allocator);
                    var ir = try IR.createInt(temp, 0, _type.getToken().span, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    return temp;
                } else if (std.mem.eql(u8, _type.getToken().data, "Byte")) {
                    var temp = try self.createTempSymbolVersion(_type, allocator);
                    var ir = try IR.createInt(temp, 0, _type.getToken().span, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    return temp;
                } else if (std.mem.eql(u8, _type.getToken().data, "Int")) {
                    var temp = try self.createTempSymbolVersion(_type, allocator);
                    var ir = try IR.createInt(temp, 0, _type.getToken().span, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    return temp;
                } else if (std.mem.eql(u8, _type.getToken().data, "Float")) {
                    var temp = try self.createTempSymbolVersion(_type, allocator);
                    var ir = try IR.createFloat(temp, 0, _type.getToken().span, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    return temp;
                } else if (std.mem.eql(u8, _type.getToken().data, "Char")) {
                    var temp = try self.createTempSymbolVersion(_type, allocator);
                    var ir = try IR.createInt(temp, 0, _type.getToken().span, allocator);
                    temp.def = ir;
                    self.appendInstruction(ir);
                    return temp;
                } else {
                    return self.generate_default(scope, _type.getCommon().expanded_type.?, errors, allocator);
                }
            },
            .addrOf,
            .function,
            => {
                var temp = try self.createTempSymbolVersion(_type, allocator);
                var ir = try IR.createInt(temp, 0, _type.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .sum => {
                var index: usize = if (_type.sum.was_error) 1 else 0; // For errors, default value is the `ok` value, which is the 1th tag
                var proper_term: *AST = _type.sum.terms.items[index];
                var init: ?*SymbolVersion = try self.generate_default(scope, proper_term, errors, allocator);
                var temp = try self.createTempSymbolVersion(_type, allocator);

                var ir = try IR.createUnion(temp, init, index, _type.getToken().span, allocator);
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .product => {
                var temp = try self.createTempSymbolVersion(_type, allocator);
                var ir = try IR.createLoadStruct(temp, _type.getToken().span, allocator);
                for (_type.product.terms.items) |term| {
                    var term_symb_ver = try self.generate_default(scope, term, errors, allocator);
                    if (term_symb_ver) |_| {
                        try ir.data.symbverList.append(term_symb_ver.?);
                    } else {
                        var temp2 = try self.createTempSymbolVersion(_ast.intType, allocator);
                        var ir2 = try IR.createInt(temp2, 0, _type.getToken().span, allocator);
                        temp2.def = ir2;
                        self.appendInstruction(ir2);
                        try ir.data.symbverList.append(temp2);
                    }
                }
                temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .unit => return null,
            .annotation => if (_type.annotation.init != null) {
                return self.flattenAST(scope, _type.annotation.init.?, null, null, null, null, false, errors, allocator);
            } else {
                return self.generate_default(scope, _type.annotation.type, errors, allocator);
            },
            else => {
                std.debug.print("Unimplemented generate_default() for: AST.{s}\n", .{@tagName(_type.*)});
                return error.Unimplemented;
            },
        }
    }

    fn generate_assign(self: *CFG, scope: *Scope, lhs: *AST, rhs: *SymbolVersion, return_label: ?*IR, break_label: ?*IR, continue_label: ?*IR, error_label: ?*IR, errors: *errs.Errors, allocator: std.mem.Allocator) error{
        typeError,
        OutOfMemory,
        NotAnLValue,
        Unimplemented,
        InvalidRange,
        Utf8ExpectedContinuation,
        Utf8OverlongEncoding,
        Utf8EncodesSurrogateHalf,
        Utf8CodepointTooLarge,
    }!?*SymbolVersion {
        switch (lhs.*) {
            .identifier => {
                // Lookup identifier's symbol, create a new version and assign rhs to it
                var symbol = scope.lookup(lhs.getToken().data, false).?;
                var symbver = try SymbolVersion.createUnversioned(symbol, symbol._type.?, allocator);
                symbver.lvalue = true;
                var ir = try IR.create(.copy, symbver, rhs, null, lhs.getToken().span, allocator);
                symbver.def = ir;
                self.appendInstruction(ir);
                return symbver;
            },
            .dereference => {
                var deref_lhs = try self.flattenAST(scope, lhs.dereference.expr, return_label, break_label, continue_label, error_label, true, errors, allocator);
                if (deref_lhs == null) {
                    return null;
                }
                var ir = try IR.create(.derefCopy, null, deref_lhs, rhs, lhs.getToken().span, allocator);
                self.appendInstruction(ir);
                return null;
            },
            .index => {
                var index_lhs = try self.flattenAST(scope, lhs.index.lhs, return_label, break_label, continue_label, error_label, false, errors, allocator);
                var index_rhs = try self.flattenAST(scope, lhs.index.rhs, return_label, break_label, continue_label, error_label, false, errors, allocator);
                if (index_lhs == null or index_rhs == null) {
                    return null;
                }

                try self.generate_bounds_check(scope, lhs, index_lhs.?, index_rhs.?, errors, allocator);

                var new_lhs = try SymbolVersion.createUnversioned(index_lhs.?.symbol, index_lhs.?.type, allocator);
                var new_rhs = try SymbolVersion.createUnversioned(index_rhs.?.symbol, index_rhs.?.type, allocator);

                var ir = try IR.create(.indexCopy, null, new_lhs, new_rhs, lhs.getToken().span, allocator);
                ir.data = IRData{ .symbver = rhs };
                self.appendInstruction(ir);
                return null;
            },
            .product => {
                for (lhs.product.terms.items, 0..) |term, i| {
                    var product_lhs = try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, true, errors, allocator);
                    if (product_lhs == null) {
                        continue;
                    }
                    product_lhs.?.lvalue = true;
                    var select = try self.createTempSymbolVersion(rhs.type.product.terms.items[i], allocator);
                    var ir = try IR.createSelect(select, rhs, i, lhs.getToken().span, allocator);
                    ir.safe = true;
                    select.def = ir;
                    self.appendInstruction(ir);
                    _ = try self.generate_assign(scope, term, select, return_label, break_label, continue_label, error_label, errors, allocator);
                }
                return null;
            },
            .select => {
                var select_lhs = try self.flattenAST(scope, lhs.select.lhs, return_label, break_label, continue_label, error_label, true, errors, allocator);
                if (select_lhs == null) {
                    return null;
                }
                select_lhs.?.lvalue = true;
                var ir = try IR.create(.selectCopy, null, select_lhs, rhs, lhs.getToken().span, allocator);
                ir.data = IRData{ .int = lhs.select.pos.? };
                self.appendInstruction(ir);
                return null;
            },
            else => return error.NotAnLValue,
        }
    }

    fn generate_pattern(self: *CFG, scope: *Scope, pattern: *AST, _type: *AST, def: *SymbolVersion, errors: *errs.Errors, allocator: std.mem.Allocator) error{
        typeError,
        OutOfMemory,
        NotAnLValue,
        Unimplemented,
        InvalidRange,
        Utf8ExpectedContinuation,
        Utf8OverlongEncoding,
        Utf8EncodesSurrogateHalf,
        Utf8CodepointTooLarge,
    }!void {
        if (pattern.* == .symbol) {
            if (!std.mem.eql(u8, pattern.symbol.name, "_")) {
                var symbver = try SymbolVersion.createUnversioned(pattern.symbol.symbol, pattern.symbol.symbol._type.?, allocator);
                var ir = try IR.create(.copy, symbver, def, null, pattern.getToken().span, allocator);
                symbver.def = ir;
                self.appendInstruction(ir);
            }
        } else if (pattern.* == .product) {
            for (pattern.product.terms.items, 0..) |term, i| {
                var subscript_type = _type.product.terms.items[i];
                var symbver = try self.createTempSymbolVersion(subscript_type, allocator);
                var ir = try IR.createSelect(symbver, def, i, term.getToken().span, allocator);
                ir.safe = true;
                symbver.def = ir;
                symbver.lvalue = term.* != .symbol;
                self.appendInstruction(ir);
                try self.generate_pattern(scope, term, subscript_type, symbver, errors, allocator);
            }
        } else if (pattern.* == .inject) {
            var lhs_type = try pattern.inject.lhs.typeof(scope, errors, allocator);
            var domain = try validate.domainof(pattern, lhs_type, scope, errors, allocator);

            var symbver = try self.createTempSymbolVersion(domain, allocator);
            var ir = try IR.createSelect(symbver, def, 0, pattern.getToken().span, allocator);
            ir.safe = true;
            symbver.def = ir;
            self.appendInstruction(ir);
            try self.generate_pattern(scope, pattern.inject.rhs, domain, symbver, errors, allocator);
        }
    }

    /// Generates the code which checks if the pattern matches the match expression
    fn generate_match_pattern_check(self: *CFG, scope: *Scope, pattern: ?*AST, expr: *SymbolVersion, next_pattern: *IR, return_label: ?*IR, break_label: ?*IR, continue_label: ?*IR, error_label: ?*IR, errors: *errs.Errors, allocator: std.mem.Allocator) error{
        typeError,
        OutOfMemory,
        NotAnLValue,
        Unimplemented,
        InvalidRange,
        Utf8ExpectedContinuation,
        Utf8OverlongEncoding,
        Utf8EncodesSurrogateHalf,
        Utf8CodepointTooLarge,
    }!void {
        if (pattern == null) {
            // Implies `else` branch, infallible.
            return;
        }
        var new_expr = try SymbolVersion.createUnversioned(expr.symbol, expr.type, allocator);
        switch (pattern.?.*) {
            .int,
            .float,
            ._true,
            ._false,
            .char,
            .string,
            .block,
            => {
                var value = try self.flattenAST(scope, pattern.?, return_label, break_label, continue_label, error_label, false, errors, allocator);
                var condition = try self.createTempSymbolVersion(_ast.boolType, allocator);
                var condition_ir = try IR.create(.equal, condition, new_expr, value.?, pattern.?.getToken().span, allocator);
                condition.def = condition_ir;
                self.appendInstruction(condition_ir);
                var branch = try IR.createBranch(condition, next_pattern, pattern.?.getToken().span, allocator);
                self.appendInstruction(branch);
            },
            .symbol => {
                // Infallible check, do not branch to next pattern
            },
            .product => {
                for (pattern.?.product.terms.items, 0..) |term, i| {
                    var subscript_type = new_expr.type.product.terms.items[i];
                    var symbver = try self.createTempSymbolVersion(subscript_type, allocator);
                    var ir = try IR.createSelect(symbver, new_expr, i, term.getToken().span, allocator);
                    ir.safe = true;
                    symbver.def = ir;
                    symbver.lvalue = false;
                    self.appendInstruction(ir);
                    try self.generate_match_pattern_check(scope, term, symbver, next_pattern, return_label, break_label, continue_label, error_label, errors, allocator);
                }
            },
            .select => {
                // Get tag of pattern
                var sel = try self.createTempSymbolVersion(_ast.intType, allocator);
                var sel_ir = try IR.createInt(sel, pattern.?.select.pos.?, pattern.?.getToken().span, allocator);
                sel.def = sel_ir;
                self.appendInstruction(sel_ir);

                // Get tag of expr
                var tag = try self.createTempSymbolVersion(_ast.intType, allocator);
                var tag_ir = try IR.createGetTag(tag, expr, pattern.?.getToken().span, allocator);
                tag.def = tag_ir;
                self.appendInstruction(tag_ir);

                // Compare them, jump to next pattern if they are not equal
                var neql = try self.createTempSymbolVersion(_ast.boolType, allocator);
                var neql_ir = try IR.create(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
                neql.def = neql_ir;
                self.appendInstruction(neql_ir);
                var branch = try IR.createBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
                self.appendInstruction(branch);
            },
            .inferredMember => {
                // Get tag of pattern
                var sel = try self.createTempSymbolVersion(_ast.intType, allocator);
                var sel_ir = try IR.createInt(sel, pattern.?.inferredMember.pos.?, pattern.?.getToken().span, allocator);
                sel.def = sel_ir;
                self.appendInstruction(sel_ir);

                // Get tag of expr
                var tag = try self.createTempSymbolVersion(_ast.intType, allocator);
                var tag_ir = try IR.createGetTag(tag, expr, pattern.?.getToken().span, allocator);
                tag.def = tag_ir;
                self.appendInstruction(tag_ir);

                // Compare them, jump to next pattern if they are not equal
                var neql = try self.createTempSymbolVersion(_ast.boolType, allocator);
                var neql_ir = try IR.create(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
                neql.def = neql_ir;
                self.appendInstruction(neql_ir);
                var branch = try IR.createBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
                self.appendInstruction(branch);
            },
            .inject => {
                try self.generate_match_pattern_check(scope, pattern.?.inject.lhs, expr, next_pattern, return_label, break_label, continue_label, error_label, errors, allocator);
            },
            else => {
                std.debug.print("Unimplemented generate_match_pattern_check() for {s}\n", .{@tagName(pattern.?.*)});
                unreachable;
            },
        }
    }

    /// \param ast The index AST
    fn generate_bounds_check(self: *CFG, scope: *Scope, ast: *AST, lhs: *SymbolVersion, rhs: *SymbolVersion, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
        var upper_label = try IR.createLabel(ast.getToken().span, allocator);
        var end_label = try IR.createLabel(ast.getToken().span, allocator);
        var new_rhs = try SymbolVersion.createUnversioned(rhs.symbol, rhs.type, allocator);

        { // Test that index is positive
            var zero = try self.createTempSymbolVersion(_ast.intType, allocator);
            var zero_ir = try IR.createInt(zero, 0, ast.getToken().span, allocator);
            zero.def = zero_ir;
            self.appendInstruction(zero_ir);

            var compare = try self.createTempSymbolVersion(_ast.boolType, allocator);
            var ir = try IR.create(.lesser, compare, new_rhs, zero, ast.getToken().span, allocator);
            compare.def = ir;
            self.appendInstruction(ir);
            var branch = try IR.createBranch(compare, upper_label, ast.getToken().span, allocator);
            self.appendInstruction(branch);
            self.appendInstruction(try IR.createStackPush(ast.getToken().span, allocator));
            self.appendInstruction(try IR.createPanic("index is negative", ast.getToken().span, allocator));
        }

        self.appendInstruction(upper_label);

        var length: *SymbolVersion = try self.createTempSymbolVersion(_ast.intType, allocator);
        var lhs_type = try lhs.type.exapnd_type(scope, errors, allocator);
        { // Get the length
            if (lhs_type.* == .product and lhs_type.product.was_slice) {
                var ir = try IR.createSelect(length, lhs, 1, ast.index.lhs.getToken().span, allocator);
                length.def = ir;
                self.appendInstruction(ir);
            } else if (lhs_type.* == .product and !lhs_type.product.was_slice) {
                var ir = try IR.createInt(length, lhs_type.product.terms.items.len, ast.getToken().span, allocator);
                length.def = ir;
                self.appendInstruction(ir);
            } else {
                unreachable;
            }
        }
        { // Test that index is less than length
            var compare = try self.createTempSymbolVersion(_ast.boolType, allocator);
            var ir = try IR.create(.greaterEqual, compare, new_rhs, length, ast.getToken().span, allocator);
            compare.def = ir;
            self.appendInstruction(ir);
            var branch = try IR.createBranch(compare, end_label, ast.getToken().span, allocator);
            self.appendInstruction(branch);
            self.appendInstruction(try IR.createStackPush(ast.getToken().span, allocator));
            self.appendInstruction(try IR.createPanic("index is greater than length", ast.index.lhs.getToken().span, allocator));
        }

        self.appendInstruction(end_label);
    }

    fn generateDefers(self: *CFG, defers: *std.ArrayList(*AST), deferLabels: *std.ArrayList(*IR), scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) error{ InvalidRange, NotAnLValue, OutOfMemory, Unimplemented, typeError, Utf8ExpectedContinuation, Utf8OverlongEncoding, Utf8EncodesSurrogateHalf, Utf8CodepointTooLarge }!void {
        var i: usize = defers.items.len;
        while (i > 0) : (i -= 1) {
            self.appendInstruction(deferLabels.items[i - 1]);
            _ = try self.flattenAST(scope, defers.items[i - 1], null, null, null, null, false, errors, allocator);
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
                if (ir.src1 != null) {
                    // If src1 version is not null, and is not defined in this BB, request it as a parameter
                    ir.src1 = ir.src1.?.findVersion(bb.ir_head, ir);
                    if (ir.src1.?.version == null) {
                        _ = try ir.src1.?.putSymbolVersionSet(&bb.parameters);
                    }
                }
                if (ir.src2 != null) {
                    // If src2 version is not null, and is not defined in this BB, request it as a parameter
                    ir.src2 = ir.src2.?.findVersion(bb.ir_head, ir);
                    if (ir.src2.?.version == null) {
                        _ = try ir.src2.?.putSymbolVersionSet(&bb.parameters);
                    }
                }

                if (ir.data == .symbver) {
                    ir.data.symbver = ir.data.symbver.findVersion(bb.ir_head, ir);
                    if (ir.data.symbver.version == null) {
                        _ = try ir.data.symbver.putSymbolVersionSet(&bb.parameters);
                    }
                } else if (ir.data == .symbverList) {
                    // Do the same as above for each symbver in a symbver list, if there is one
                    for (ir.data.symbverList.items, 0..) |symbver, i| {
                        var symbol_find = symbver.findVersion(bb.ir_head, ir);
                        var slice: [1]*SymbolVersion = undefined;
                        slice[0] = symbol_find;
                        try ir.data.symbverList.replaceRange(i, 1, &slice);
                        if (symbol_find.version == null) {
                            _ = try symbol_find.putSymbolVersionSet(&bb.parameters);
                        }
                    }
                }
            }

            if (bb.has_branch) {
                // Do the same as above for the condition of a branch, if there is one
                bb.condition = bb.condition.?.findVersion(bb.ir_head, null);
                if (bb.condition.?.version == null) {
                    _ = try bb.condition.?.putSymbolVersionSet(&bb.parameters);
                }
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

    /// Finds the phi *arguments* that each basic block needs to pass along, whereas calculatePhiParamsAndArgs finds the *parameters*.
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
                for (branch.parameters.items) |param| { // go through branch BB's params
                    var symbver = param.findVersion(bb.ir_head, null); // look for definition of param in this block
                    if (symbver == param) {
                        // Could not find param def in this block, require it as a parameter for this own block
                        var myParam = param.findSymbolVersionSet(&bb.parameters); // see if param is already in block paramlist
                        if (myParam) |_myParam| {
                            symbver = _myParam; // if so, we will add param to arglist
                        } else {
                            // else, create a new param and add to paramlist. (will later be added to arglist too)
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
