const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const primitives = @import("primitives.zig");
const module_ = @import("module.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");
const _string = @import("zig-string/zig-string.zig");
const validate = @import("validate.zig");

const AST = _ast.AST;
const Error = errs.Error;
const Scope = _symbol.Scope;
const Span = @import("span.zig").Span;
const String = @import("zig-string/zig-string.zig").String;
const Symbol = _symbol.Symbol;
const Token = @import("token.zig").Token;

pub const SymbolVersion = struct {
    symbol: *Symbol,
    version: ?u64,
    def: ?*IR,

    uses: usize = 0,

    /// Type of the SymbolVersion. Temps use the same symbol, so can't use that for type info
    type: *AST,

    allocator: std.mem.Allocator,

    fn createUnversioned(symbol: *Symbol, _type: *AST, allocator: std.mem.Allocator) !*SymbolVersion {
        var retval = try allocator.create(SymbolVersion);
        retval.symbol = symbol;
        retval.uses = 0;
        retval.version = null;
        retval.type = _type;
        retval.def = null;
        retval.allocator = allocator;
        return retval;
    }

    pub fn deinit(self: *SymbolVersion) void {
        self.allocator.destroy(self);
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
            var out = String.init(arena.allocator());
            defer out.deinit();

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
        var out = String.init(arena.allocator());
        defer out.deinit();

        writer.print("{s}_{?}", .{ self.symbol.name, self.version }) catch unreachable;
        // try writer.print("{s:<10}", .{out.str()});
    }

    fn findVersion(self: *SymbolVersion, ir: ?*IR, stop: ?*IR) *SymbolVersion {
        var retval: *SymbolVersion = self;
        var maybe_ir = ir;
        while (maybe_ir != null and maybe_ir != stop) : (maybe_ir = maybe_ir.?.next) {
            if (maybe_ir.?.dest != null and maybe_ir.?.dest.?.* == .symbver and maybe_ir.?.dest.?.symbver.symbol == self.symbol) {
                retval = maybe_ir.?.dest.?.symbver;
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

    pub fn hide_temporary(symbver: *SymbolVersion) bool {
        if (symbver.def == null) {
            // parameters do not have defs; they should never be hidden
            return false;
        } else if (symbver.symbol.discards > 0) {
            return true;
        }
        return symbver.symbol.is_temp and
            symbver.uses == 1 and
            symbver.symbol.versions == 1 and
            symbver.def.?.kind != .call and
            symbver.type.* == .identifier;
    }
};

var ir_uid: u64 = 0;
pub const IRKind = enum {
    // nullary instructions
    loadSymbol,
    loadExtern,
    loadInt,
    loadFloat,
    loadStruct, // TODO: Rename to load_tuple
    loadUnion, // src1 is init, data.int is tag id // TODO: Rename to load_sum
    loadString,
    loadAST,

    // Monadic instructions
    copy,
    not,
    negate_int,
    negate_float,
    sizeOf, //< For extern types that Orng can't do automatically
    addrOf,

    // Diadic instructions
    equal,
    not_equal,
    greater_int,
    greater_float,
    lesser_int,
    lesser_float,
    greater_equal_int,
    greater_equal_float,
    lesser_equal_int,
    lesser_equal_float,
    add_int,
    add_float,
    sub_int,
    sub_float,
    mult_int,
    mult_float,
    div_int,
    div_float,
    mod,
    get_tag, // dest = src1.tag
    cast,

    // Control-flow
    label,
    jump, // jump to BB{uid} if codegen, ip := {addr} if interpreting
    branchIfFalse,
    call, // dest = src1(symbver_list...)

    // Non-Code Generating
    discard, // Marks that a symbol isn't used, but that's OK

    // Errors
    pushStackTrace, // Pushes a static span/code to the lines array if debug mode is on
    popStackTrace, // Pops a message off the stack after a function is successfully called
    panic, // if debug mode is on, panics with a message, unrolls lines stack, exits

    pub fn precedence(self: IRKind) i64 {
        return switch (self) {
            .loadSymbol,
            .loadExtern,
            .loadInt,
            .loadFloat,
            .loadStruct,
            .loadUnion,
            .loadString,
            => 0,

            .call,
            .get_tag,
            => 1,

            .negate_int,
            .negate_float,
            .not,
            .sizeOf,
            .cast,
            .addrOf,
            => 2,

            .mult_int,
            .mult_float,
            .div_int,
            .div_float,
            .mod,
            => 3,

            .add_int,
            .add_float,
            .sub_int,
            .sub_float,
            => 4,

            // No bitshift operators, would be precedence 5

            .greater_int,
            .greater_float,
            .lesser_int,
            .lesser_float,
            .greater_equal_int,
            .greater_equal_float,
            .lesser_equal_int,
            .lesser_equal_float,
            => 6,

            .equal,
            .not_equal,
            => 7,

            .copy => 14,

            else => {
                std.debug.print("Unimplemented precedence for kind {s}\n", .{@tagName(self)});
                unreachable;
            },
        };
    }
};

pub const IRData = union(enum) {
    branch: ?*IR,
    jump_bb: struct { next: ?*BasicBlock },
    branch_bb: struct { next: ?*BasicBlock, branch: ?*BasicBlock },
    int: i128,
    float: f64,
    string_id: usize,
    bb_id: u64,
    string: []const u8,
    symbol: *Symbol,
    lval_list: std.ArrayList(*L_Value),
    // lval: *L_Value,
    select: struct { offset: i128, field: i128 },
    ast: *AST,
    none,

    pub fn to_ast(self: IRData, token: Token, allocator: std.mem.Allocator) !*AST {
        switch (self) {
            .int => {
                return try AST.createInt(token, self.int, allocator);
            },
            .float => {
                return try AST.createFloat(token, self.float, allocator);
            },
            .none => {
                return try AST.createUnit(token, allocator);
            },
            .ast => {
                return self.ast;
            },
            else => {
                std.debug.print("Unknown IRData->AST conversion for {s}\n", .{@tagName(self)});
                unreachable;
            },
        }
    }

    pub fn pprint(self: IRData, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        switch (self) {
            .int => {
                try out.writer().print("{}", .{self.int});
            },
            .float => {
                try out.writer().print("{d:.6}", .{self.float});
            },
            .none => {
                try out.writer().print("none", .{});
            },
            .symbol => {
                try out.writer().print("{s}", .{self.symbol.name});
            },
            .string_id => {
                try out.writer().print("<interned string:{}>", .{self.string_id});
            },
            else => {
                try out.writer().print("??? ({s})", .{@tagName(self)});
            },
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: IRData, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }

    pub fn equals(self: IRData, other: IRData) bool {
        if (self == .branch and other == .branch) {
            return self.branch == other.branch;
        } else if (self == .int and other == .int) {
            return self.int == other.int;
        } else if (self == .float and other == .float) {
            return self.float == other.float;
        } else if (self == .int and other == .float) {
            return self.int == @as(i128, @intFromFloat(other.float)); // These will crash if float is not representable by i128
        } else if (self == .float and other == .int) { //                This should not be a problem with user-generated code, since it's type-checked
            return @as(i128, @intFromFloat(self.float)) == other.int; // But keep it in mind for compiler-generated code generated after type-checking, such as defaults
        } else if (self == .string_id and other == .string_id) {
            return self.string_id == other.string_id;
        } else if (self == .string and other == .string) {
            return std.mem.eql(u8, self.string, other.string);
        } else if (self == .symbol and other == .symbol) {
            return self.symbol == other.symbol;
        } else {
            return false; // tags are mismatched
        }
    }
};

/// Represents different forms of l-values in an l-value tree.
pub const L_Value = union(enum) {
    /// L-Value is the address of the symbol
    symbver: *SymbolVersion,
    /// L-Value is lhs.
    dereference: struct {
        expr: *L_Value,
        slots: i128,
        type: *AST,
        expanded_type: *AST,
        allocator: std.mem.Allocator,
    },
    /// L-Value is L-Value of lhs, + rhs * slots
    index: struct {
        lhs: *L_Value,
        rhs: *L_Value, // TODO: Rename to rhs
        slots: i128,
        type: *AST,
        expanded_type: *AST,
        allocator: std.mem.Allocator,
    },
    /// L-Value is L-Value + offset
    select: struct {
        lhs: *L_Value,
        field: i128,
        offset: i128,
        slots: i128,
        type: *AST,
        expanded_type: *AST,
        allocator: std.mem.Allocator,
    },

    fn create_symbver(symbver: *SymbolVersion, allocator: std.mem.Allocator) !*L_Value {
        const retval = try allocator.create(L_Value);
        retval.* = L_Value{ .symbver = symbver };
        return retval;
    }

    fn create_unversioned_symbver(symbol: *Symbol, _type: *AST, allocator: std.mem.Allocator) !*L_Value {
        const retval = try L_Value.create_symbver(try SymbolVersion.createUnversioned(symbol, _type, allocator), allocator);
        return retval;
    }

    fn create_dereference(lhs: *L_Value, slots: i128, _type: *AST, expanded_type: *AST, allocator: std.mem.Allocator) !*L_Value {
        const retval = try allocator.create(L_Value);
        retval.* = L_Value{ .dereference = .{ .expr = lhs, .slots = slots, .type = _type, .expanded_type = expanded_type, .allocator = allocator } };
        return retval;
    }

    fn create_index(lhs: *L_Value, rhs: *L_Value, slots: i128, _type: *AST, expanded_type: *AST, allocator: std.mem.Allocator) !*L_Value {
        const retval = try allocator.create(L_Value);
        retval.* = L_Value{ .index = .{ .lhs = lhs, .rhs = rhs, .slots = slots, .type = _type, .expanded_type = expanded_type, .allocator = allocator } };
        return retval;
    }

    fn create_select(lhs: *L_Value, field: i128, offset: i128, slots: i128, _type: *AST, expanded_type: *AST, allocator: std.mem.Allocator) !*L_Value {
        const retval = try allocator.create(L_Value);
        retval.* = L_Value{ .select = .{ .lhs = lhs, .field = field, .offset = offset, .slots = slots, .type = _type, .expanded_type = expanded_type, .allocator = allocator } };
        return retval;
    }

    pub fn deinit(self: *L_Value) void {
        switch (self.*) {
            .symbver => {
                self.symbver.deinit();
            },
            .dereference => {
                self.dereference.allocator.destroy(self);
            },
            .index => {
                self.index.allocator.destroy(self);
            },
            .select => {
                self.select.allocator.destroy(self);
            },
        }
    }

    pub fn pprint(self: L_Value, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        switch (self) {
            .symbver => {
                try out.writer().print("{}", .{self.symbver});
            },
            .dereference => {
                try out.writer().print("{}^", .{self.dereference.expr});
            },
            .index => {
                try out.writer().print("{}[{}]", .{ self.index.lhs, self.index.rhs });
            },
            .select => {
                try out.writer().print("{}._{}", .{ self.select.lhs, self.select.field });
            },
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: L_Value, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }

    pub fn extract_symbver(self: *L_Value) *SymbolVersion {
        switch (self.*) {
            .symbver => {
                return self.symbver;
            },
            .dereference => {
                return self.dereference.expr.extract_symbver();
            },
            .index => {
                return self.index.lhs.extract_symbver();
            },
            .select => {
                return self.select.lhs.extract_symbver();
            },
        }
    }

    pub fn get_slots(self: *L_Value) i128 {
        switch (self.*) {
            .symbver => {
                return self.symbver.symbol.expanded_type.?.get_slots();
            },
            .dereference => {
                return self.dereference.slots;
            },
            .index => {
                return self.index.slots;
            },
            .select => {
                return self.select.slots;
            },
        }
    }

    pub fn get_type(self: *L_Value) *AST {
        switch (self.*) {
            .symbver => return self.symbver.type,
            .dereference => return self.dereference.type,
            .index => return self.index.type,
            .select => return self.select.type,
        }
    }

    pub fn get_expanded_type(self: *L_Value) *AST {
        switch (self.*) {
            .symbver => return self.symbver.symbol.expanded_type.?,
            .dereference => return self.dereference.expanded_type,
            .index => return self.index.expanded_type,
            .select => return self.select.expanded_type,
        }
    }

    pub fn precedence(self: *L_Value) i64 {
        return switch (self.*) {
            .symbver => IRKind.precedence(IRKind.loadSymbol),
            .dereference => 2,
            .index => 2,
            .select => 1,
        };
    }
};

pub const IRMeta = union(enum) {
    bounds_check: struct {
        length: *L_Value, // lower bounds is always 0
    },
    active_field_check: struct {
        tag: *L_Value,
        selection: usize,
    },

    none,

    pub fn pprint(self: IRMeta, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        switch (self) {
            .bounds_check => {
                try out.writer().print("// bounds_check: {}", .{self.bounds_check.length});
            },

            .active_field_check => {
                try out.writer().print("// active_field_check: {{tag:{} selection:{}}}", .{ self.active_field_check.tag, self.active_field_check.selection });
            },

            .none => return "",
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: IRMeta, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }
};

pub const IR = struct {
    uid: u64,
    kind: IRKind,
    dest: ?*L_Value,
    src1: ?*L_Value,
    src2: ?*L_Value,

    data: IRData,
    meta: IRMeta,
    next: ?*IR,
    prev: ?*IR,

    in_block: ?*BasicBlock,
    span: Span,

    removed: bool,
    allocator: std.mem.Allocator,

    safe: bool, // Disables static UB checks for this IR. Used for IR generated by `match`'s

    pub fn create(kind: IRKind, dest: ?*L_Value, src1: ?*L_Value, src2: ?*L_Value, span: Span, allocator: std.mem.Allocator) !*IR {
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
        retval.meta = IRMeta.none;
        retval.span = span;
        retval.allocator = allocator;
        ir_uid += 1;
        return retval;
    }

    fn createInt(dest: *L_Value, int: i128, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadInt, dest, null, null, span, allocator);
        retval.data = IRData{ .int = int };
        return retval;
    }

    fn createFloat(dest: *L_Value, float: f64, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadFloat, dest, null, null, span, allocator);
        retval.data = IRData{ .float = float };
        return retval;
    }

    fn createString(dest: *L_Value, id: usize, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadString, dest, null, null, span, allocator);
        retval.data = IRData{ .string_id = id };
        return retval;
    }

    fn create_ast(dest: *L_Value, ast: *AST, span: Span, allocator: std.mem.Allocator) !*IR {
        const retval = try IR.create(.loadAST, dest, null, null, span, allocator);
        retval.data = IRData{ .ast = ast };
        return retval;
    }

    fn create_simple_copy(dest: *L_Value, src: *L_Value, span: Span, allocator: std.mem.Allocator) !*IR {
        const ir = try IR.create(.copy, dest, src, null, span, allocator);
        return ir;
    }

    pub fn createLabel(id: ?u64, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.label, null, null, null, span, allocator);
        retval.data = if (id != null) IRData{ .bb_id = id.? } else IRData.none;
        return retval;
    }

    // TODO: Rename create_branch_ir, rename IR kind as well
    fn createBranch(condition: *L_Value, label: ?*IR, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.branchIfFalse, null, condition, null, span, allocator);
        retval.data = IRData{ .branch = label };
        return retval;
    }

    // TODO: Rename create_jump_ir, rename IR kind as well
    fn createJump(label: ?*IR, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.jump, null, null, null, span, allocator);
        retval.data = IRData{ .branch = label };
        return retval;
    }

    pub fn create_jump_addr(next: ?*BasicBlock, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.jump, null, null, null, span, allocator);
        retval.data = IRData{ .jump_bb = .{ .next = next } };
        return retval;
    }

    pub fn create_branch_addr(condition: *L_Value, next: ?*BasicBlock, branch: ?*BasicBlock, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.branchIfFalse, null, condition, null, span, allocator);
        retval.data = IRData{ .branch_bb = .{ .next = next, .branch = branch } };
        return retval;
    }

    fn createCall(dest: *L_Value, src1: *L_Value, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.call, dest, src1, null, span, allocator);
        retval.data = IRData{ .lval_list = std.ArrayList(*L_Value).init(allocator) };
        return retval;
    }

    fn createLoadStruct(dest: *L_Value, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadStruct, dest, null, null, span, allocator);
        retval.data = IRData{ .lval_list = std.ArrayList(*L_Value).init(allocator) };
        return retval;
    }

    fn createGetTag(dest: *L_Value, src1: *L_Value, span: Span, allocator: std.mem.Allocator) !*IR {
        const retval = try IR.create(.get_tag, dest, src1, null, span, allocator);
        return retval;
    }

    fn createUnion(dest: *L_Value, init: ?*L_Value, tag: i128, span: Span, allocator: std.mem.Allocator) !*IR {
        var retval = try IR.create(.loadUnion, dest, init, null, span, allocator);
        retval.data = IRData{ .int = tag };
        return retval;
    }

    fn createDiscard(src1: *L_Value, span: Span, allocator: std.mem.Allocator) !*IR {
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

    fn create_int_float_kind(
        int_kind: IRKind,
        float_kind: IRKind,
        dest: ?*L_Value,
        src1: ?*L_Value,
        src2: ?*L_Value,
        span: Span,
        scope: *Scope,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) !*IR {
        if (try src1.?.get_type().can_represent_float(scope, errors, allocator)) {
            return try create(float_kind, dest, src1, src2, span, allocator);
        } else {
            return try create(int_kind, dest, src1, src2, span, allocator);
        }
    }

    pub fn deinit(self: *IR) void {
        if (self.dest != null) {
            self.dest.?.deinit();
        }
        self.allocator.destroy(self);
    }

    pub fn getTail(self: *IR) *IR {
        var mut_self: *IR = self;
        while (mut_self.next != null) : (mut_self = mut_self.next.?) {}
        return mut_self;
    }

    pub fn pprint(self: IR, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        switch (self.kind) {
            .label => try out.writer().print("BB{}:\n", .{self.uid}),

            .loadInt => {
                try out.writer().print("    {} := {}\n", .{ self.dest.?, self.data.int });
            },
            .loadFloat => {
                try out.writer().print("    {} := {}\n", .{ self.dest.?, self.data.float });
            },
            .loadSymbol => {
                try out.writer().print("    {} := {s}\n", .{ self.dest.?, self.data.symbol.name });
            },
            .loadStruct => {
                try out.writer().print("    {} := {{", .{self.dest.?});
                var i: usize = 0;
                while (i < self.data.lval_list.items.len) : (i += 1) {
                    const lval = self.data.lval_list.items[i];
                    try out.writer().print("{}", .{lval});
                    if (i < self.data.lval_list.items.len - 1) {
                        try out.writer().print(", ", .{});
                    }
                }
                try out.writer().print("}}\n", .{});
            },
            .loadUnion => {
                // init may be null, if it is unit
                try out.writer().print("    {} := {{init={?}, tag={}}}\n", .{ self.dest.?, self.src1, self.data.int });
            },
            .loadString => {
                try out.writer().print("    {} := <interned string:{}>\n", .{ self.dest.?, self.data.string_id });
            },

            .copy => {
                try out.writer().print("    {} := {?}\n", .{ self.dest.?, self.src1 });
            },
            .not => {
                try out.writer().print("    {} := !{}\n", .{ self.dest.?, self.src1.? });
            },
            .negate_int => {
                try out.writer().print("    {} := -{}\n", .{ self.dest.?, self.src1.? });
            },
            .negate_float => {
                try out.writer().print("    {} := -.{}\n", .{ self.dest.?, self.src1.? });
            },
            .sizeOf => {
                try out.writer().print("    {} := sizeof({})\n", .{ self.dest.?, self.src1.? });
            },
            .addrOf => {
                try out.writer().print("    {} := &{}\n", .{ self.dest.?, self.src1.? });
            },

            .equal => {
                try out.writer().print("    {} := {} == {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .not_equal => {
                try out.writer().print("    {} := {} != {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .greater_int => {
                try out.writer().print("    {} := {} > {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .greater_float => {
                try out.writer().print("    {} := {} >. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .lesser_int => {
                try out.writer().print("    {} := {} < {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .lesser_float => {
                try out.writer().print("    {} := {} <. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .greater_equal_int => {
                try out.writer().print("    {} := {} >= {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .greater_equal_float => {
                try out.writer().print("    {} := {} >=. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .lesser_equal_int => {
                try out.writer().print("    {} := {} <= {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .lesser_equal_float => {
                try out.writer().print("    {} := {} <=. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .add_int => {
                try out.writer().print("    {} := {} + {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .add_float => {
                try out.writer().print("    {} := {} +. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .sub_int => {
                try out.writer().print("    {} := {} - {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .sub_float => {
                try out.writer().print("    {} := {} -. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .mult_int => {
                try out.writer().print("    {} := {} * {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .mult_float => {
                try out.writer().print("    {} := {} *. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .div_int => {
                try out.writer().print("    {} := {} / {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .div_float => {
                try out.writer().print("    {} := {} /. {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },
            .mod => {
                try out.writer().print("    {} := {} % {}\n", .{ self.dest.?, self.src1.?, self.src2.? });
            },

            .get_tag => {
                try out.writer().print("    {} := {}.tag\n", .{ self.dest.?, self.src1.? });
            },

            .jump => {
                if (self.data.jump_bb.next) |next| {
                    try out.writer().print("    jump BB{}\n", .{next.uid});
                } else {
                    try out.writer().print("    ret\n", .{});
                }
            },
            .branchIfFalse => {
                if (self.data.branch_bb.next) |next| {
                    try out.writer().print("    if ({}) jump BB{}", .{ self.src1.?, next.uid });
                } else {
                    try out.writer().print("    if ({}) ret", .{self.src1.?});
                }
                try out.writer().print(" ", .{});
                if (self.data.branch_bb.branch) |branch| {
                    try out.writer().print("else jump BB{}\n", .{branch.uid});
                } else {
                    try out.writer().print("else ret\n", .{});
                }
            },
            .call => {
                try out.writer().print("    {} := {}(", .{ self.dest.?, self.src1.? });
                var i: usize = 0;
                while (i < self.data.lval_list.items.len) : (i += 1) {
                    const lval = self.data.lval_list.items[i];
                    try out.writer().print("{}", .{lval});
                    if (i < self.data.lval_list.items.len - 1) {
                        try out.writer().print(", ", .{});
                    }
                }
                try out.writer().print(")\n", .{});
            },

            .discard => {
                try out.writer().print("    _ := {}\n", .{self.src1.?});
            },
            .pushStackTrace => {
                try out.writer().print("    push-stack-trace\n", .{});
            },
            .popStackTrace => {
                try out.writer().print("    pop-stack-trace\n", .{});
            },
            .panic => {
                try out.writer().print("    panic\n", .{});
            },

            else => {
                try out.writer().print("<TODO: {s}>\n", .{@tagName(self.kind)});
            },
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: IR, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }

    /// This function is O(n) in terms of IR between start and stop
    pub fn get_latest_def_after(start_at_ir: *IR, symbol: *Symbol, stop_at_ir: ?*IR) ?*IR {
        var maybe_ir: ?*IR = start_at_ir;
        var retval: ?*IR = null;
        while (maybe_ir != null and maybe_ir != stop_at_ir) : (maybe_ir = maybe_ir.?.next) {
            var ir: *IR = maybe_ir.?;
            if (ir.dest != null and ir.dest.?.* == .select and ir.dest.?.extract_symbver().symbol == symbol) {
                return null;
            } else if (ir.dest != null and ir.dest.?.* == .index and ir.dest.?.extract_symbver().symbol == symbol) {
                return null;
            } else if (ir.dest != null and ir.dest.?.* == .symbver and ir.dest.?.symbver.symbol == symbol) {
                retval = ir;
            } else if (ir.kind == .addrOf and ir.src1.?.extract_symbver().symbol == symbol) {
                retval = null;
            }
        }
        return retval;
    }

    // This function is O(n)
    pub fn any_def_after(start_at_ir: *IR, symbol: *Symbol, stop_at_ir: ?*IR) ?*IR {
        var maybe_ir: ?*IR = start_at_ir;
        while (maybe_ir != null and maybe_ir != stop_at_ir) : (maybe_ir = maybe_ir.?.next) {
            var ir: *IR = maybe_ir.?;
            if (ir.dest != null and ir.dest.?.* == .select and ir.dest.?.extract_symbver().symbol == symbol) {
                return ir;
            } else if (ir.dest != null and ir.dest.?.* == .index and ir.dest.?.extract_symbver().symbol == symbol) {
                return ir;
            } else if (ir.kind == .addrOf and ir.src1.?.extract_symbver().symbol == symbol) {
                return ir;
            } else if (ir.dest != null and ir.dest.?.* == .symbver and ir.dest.?.symbver.symbol == symbol) {
                return ir;
            }
        }
        return null;
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
    condition: ?*L_Value,
    branch_arguments: std.ArrayList(*SymbolVersion),

    visited: bool,
    number_predecessors: usize,
    removed: bool,
    allocator: std.mem.Allocator,

    /// Address in the first instruction of this BasicBlock
    /// Used for IR interpretation
    offset: ?i128,

    pub fn deinit(self: *BasicBlock) void {
        for (self.parameters.items) |param| {
            param.deinit();
        }
        self.parameters.deinit();

        for (self.next_arguments.items) |arg| {
            arg.deinit();
        }
        self.next_arguments.deinit();

        for (self.branch_arguments.items) |arg| {
            arg.deinit();
        }
        self.branch_arguments.deinit();

        var maybe_ir: ?*IR = self.ir_head;
        while (maybe_ir) |ir| {
            maybe_ir = ir.next;
            ir.deinit();
        }

        self.allocator.destroy(self);
    }

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
            std.debug.print("{}", .{ir});
        }
        if (self.has_branch) {
            if (self.next) |next| {
                std.debug.print("    if ({}) jump BB{}", .{ self.condition.?, next.uid });
                BasicBlock.printSymbverList(&self.next_arguments);
            } else {
                std.debug.print("    if ({}) return", .{self.condition.?});
            }
            std.debug.print(" ", .{});
            if (self.branch) |branch| {
                std.debug.print("else jump BB{}", .{branch.uid});
                BasicBlock.printSymbverList(&self.branch_arguments);
            } else {
                std.debug.print("else return", .{});
            }
        } else {
            if (self.next) |next| {
                std.debug.print("    jump BB{}", .{next.uid});
                BasicBlock.printSymbverList(&self.next_arguments);
            } else {
                std.debug.print("    return", .{});
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

    pub fn printSymbverList(list: *std.ArrayList(*SymbolVersion)) void {
        std.debug.print("(", .{});
        var i: usize = 0;
        while (i < list.items.len) : (i += 1) {
            const symbver = list.items[i];
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
        if (ir.prev != null) {
            ir.prev.?.next = ir.next;
        }
        if (ir.next != null) {
            ir.next.?.prev = ir.prev;
        }
        ir.deinit();
    }

    /// This functions is O(n)
    pub fn get_latest_def(bb: *BasicBlock, symbol: *Symbol, stop_at_ir: ?*IR) ?*IR {
        if (bb.ir_head == null) {
            return null;
        } else {
            return bb.ir_head.?.get_latest_def_after(symbol, stop_at_ir);
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
    children: std.ArrayList(*CFG),

    /// All symbol versions that are parameters to the function this CFG defines
    parameters: std.ArrayList(*SymbolVersion),

    /// All symbol versions that are used. Should be filled in after optimizations.
    symbvers: std.ArrayList(*SymbolVersion),

    /// The function that this CFG represents
    symbol: *Symbol,

    number_temps: usize,

    return_symbol: *Symbol,

    /// Non-owning pointer to set of interned string literals
    /// Provided by main, global to all CFGs.
    interned_strings: *std.ArrayList([]const u8),

    /// Whether or not this CFG is visited
    visited: bool,

    /// Address in the first instruction of this CFG
    /// Used for IR interpretation
    offset: ?i128,
    /// Number of slots required in order to store the local variables of the function
    slots: ?i128,

    allocator: std.mem.Allocator,

    // BIG TODO: Dependency-inject errors and allocator, so that method calls don't need that explicit passed in (they do not change from method call to method call)
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
        retval.symbvers = std.ArrayList(*SymbolVersion).init(allocator);
        retval.parameters = std.ArrayList(*SymbolVersion).init(allocator);
        retval.symbol = symbol;
        retval.number_temps = 0;
        retval.return_symbol = try Symbol.create(symbol.scope, "$retval", Span{ .filename = "", .line_text = "", .col = 0, .line = 0 }, symbol._type.?.function.rhs, null, null, .mut, allocator);
        retval.return_symbol.expanded_type = try retval.return_symbol._type.?.expand_type(symbol.scope, errors, allocator);
        retval.visited = false;
        retval.interned_strings = interned_strings;
        retval.offset = null;
        retval.slots = null;
        retval.allocator = allocator;
        symbol.cfg = retval;

        if (caller) |caller_node| {
            try caller_node.children.append(retval);
        }

        const eval: ?*L_Value = try retval.flattenAST(symbol.scope, symbol.init.?, null, null, null, null, errors, allocator);
        if (retval.symbol.decl.?.* == .fnDecl) {
            // `_comptime` symbols don't have parameters anyway
            for (retval.symbol.decl.?.fnDecl.param_symbols.items) |param| {
                try retval.parameters.append(try SymbolVersion.createUnversioned(param, param._type.?, allocator));
            }
        }
        const return_version = try L_Value.create_unversioned_symbver(retval.return_symbol, symbol._type.?.function.rhs, allocator);
        if (eval != null) {
            retval.appendInstruction(try IR.create_simple_copy(return_version, eval.?, symbol.span, allocator));
        }
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
                    ir.dest.?.symbver.symbol.expanded_type.?.* != .unit and
                    ir.dest.?.symbver.findSymbolVersionSet(&self.parameters) == null)
                {
                    _ = try ir.dest.?.symbver.putSymbolVersionSet(&self.symbvers);
                }
            }
        }
    }

    fn createBasicBlock(self: *CFG, allocator: std.mem.Allocator) !*BasicBlock {
        var retval = try allocator.create(BasicBlock);
        retval.ir_head = null;
        retval.condition = null;
        retval.has_panic = false;
        retval.offset = null;
        retval.parameters = std.ArrayList(*SymbolVersion).init(allocator);
        retval.next = null;
        retval.next_arguments = std.ArrayList(*SymbolVersion).init(allocator);
        retval.branch = null;
        retval.branch_arguments = std.ArrayList(*SymbolVersion).init(allocator);
        retval.uid = self.basic_blocks.items.len;
        retval.allocator = allocator;
        try self.basic_blocks.append(retval);
        return retval;
    }

    fn createTempSymbol(self: *CFG, _type: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*Symbol {
        var buf = try String.init_with_contents(allocator, "t");
        try buf.writer().print("{}", .{self.number_temps});
        self.number_temps += 1;
        var temp_symbol = try Symbol.create(self.symbol.scope, (try buf.toOwned()).?, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, _type, null, null, .mut, allocator);
        temp_symbol.expanded_type = try _type.expand_type(self.symbol.scope, errors, allocator);
        temp_symbol.is_temp = true;
        return temp_symbol;
    }

    fn createTempSymbolVersion(self: *CFG, _type: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*SymbolVersion {
        const temp_symbol = try self.createTempSymbol(_type, errors, allocator);
        const retval = try SymbolVersion.createUnversioned(temp_symbol, _type, allocator);
        return retval;
    }

    fn create_temp_lvalue(self: *CFG, _type: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*L_Value {
        const temp_symbol = try self.createTempSymbol(_type, errors, allocator);
        const retval = try L_Value.create_unversioned_symbver(temp_symbol, _type, allocator);
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

    const FlattenASTError = error{
        typeError,
        OutOfMemory,
        NotAnLValue,
        Unimplemented,
        InvalidRange,
        // Utf8ExpectedContinuation,
        // Utf8OverlongEncoding,
        // Utf8EncodesSurrogateHalf,
        // Utf8CodepointTooLarge,
    };

    fn flattenAST(
        self: *CFG,
        scope: *Scope,
        ast: *AST,
        return_label: ?*IR,
        break_label: ?*IR,
        continue_label: ?*IR,
        error_label: ?*IR,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!?*L_Value {
        switch (ast.*) {
            // Literals
            .unit => return null,
            .int => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try IR.createInt(temp, ast.int.data, ast.getToken().span, allocator);
                // temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .char => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                // Convert the character inside to a codepoint
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
                        const num_bytes = std.unicode.utf8ByteSequenceLength(ast.getToken().data[1]) catch return error.typeError;
                        codepoint = std.unicode.utf8Decode(ast.getToken().data[1 .. num_bytes + 1]) catch return error.typeError; // TODO: Add actual error diagnostics here
                    },
                }
                const ir = try IR.createInt(temp, codepoint, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .float => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try IR.createFloat(temp, ast.float.data, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .string => {
                try module_.interned_string_set_add(ast.string.data, self.interned_strings);
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try IR.createString(temp, self.interned_strings.items.len - 1, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .identifier => {
                var symbol = scope.lookup(ast.getToken().data, false).?;
                if (symbol.kind == ._fn) {
                    _ = try symbol.get_cfg(self, self.interned_strings, errors, allocator);
                    const lval = try self.create_temp_lvalue(symbol._type.?, errors, allocator);
                    var ir = try IR.create(.loadSymbol, lval, null, null, ast.getToken().span, allocator);
                    ir.data = IRData{ .symbol = symbol };
                    self.appendInstruction(ir);
                    return lval;
                } else if (try symbol.expanded_type.?.typesMatch(primitives.type_type, scope, errors, allocator)) {
                    const lval = try self.create_temp_lvalue(symbol._type.?, errors, allocator);
                    self.appendInstruction(try IR.create_ast(lval, ast, ast.getToken().span, allocator));
                    return lval;
                } else {
                    const src = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                    return src;
                }
            },
            ._true => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try IR.createInt(temp, 1, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            ._false => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try IR.createInt(temp, 0, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },

            // Unary operators
            .not => {
                const expr = try self.flattenAST(scope, ast.not.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create(.not, temp, expr, null, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .negate => {
                const expr = try self.flattenAST(scope, ast.negate.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }
                var temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create(if (try temp.get_type().can_represent_float(scope, errors, allocator)) .negate_float else .negate_int, temp, expr, null, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .dereference => {
                const expr = try self.flattenAST(scope, ast.dereference.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }
                const _type = try ast.typeof(scope, errors, allocator);
                const slots = (try _type.expand_type(scope, errors, allocator)).get_slots();
                const temp = try L_Value.create_dereference(expr.?, slots, _type, try _type.expand_type(scope, errors, allocator), allocator);
                return temp;
            },
            ._try => {
                var expr = (try self.flattenAST(scope, ast._try.expr, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                const end = try IR.createLabel(null, ast.getToken().span, allocator);
                const err = try IR.createLabel(null, ast.getToken().span, allocator);

                var expanded_expr_type = try expr.get_type().expand_type(scope, errors, allocator);
                // Trying error sum, runtime check if error, branch to error path
                const condition = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
                self.appendInstruction(try IR.createGetTag(condition, expr, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                self.appendInstruction(try IR.createBranch(condition, err, ast.getToken().span, allocator));

                // Unwrap the `.ok` value
                const retval_lval = try L_Value.create_unversioned_symbver(self.return_symbol, self.symbol._type.?.function.rhs, allocator);
                self.appendInstruction(try IR.create_simple_copy(retval_lval, expr, ast.getToken().span, allocator));
                self.appendInstruction(try IR.createJump(error_label, ast.getToken().span, allocator));

                // Else, store the error in retval, return through error
                self.appendInstruction(err);

                const ok_lval = try L_Value.create_select(expr, 0, 0, expanded_expr_type.get_ok_type().get_slots(), expanded_expr_type.get_ok_type(), try expanded_expr_type.get_ok_type().expand_type(scope, errors, allocator), allocator);
                self.appendInstruction(try IR.createJump(end, ast.getToken().span, allocator));
                self.appendInstruction(end);

                return ok_lval;
            },
            .discard => {
                var expr = try self.flattenAST(scope, ast.discard.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }
                expr.?.extract_symbver().symbol.discard_span = ast.getToken().span;
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.createDiscard(expr.?, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },

            // Binary operators
            .assign => {
                const rhs = try self.flattenAST(scope, ast.assign.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                // If product, recursively generate a series of assignments
                // Else, create a *single* copy IR with an L_Value tree
                return try self.generate_assign(scope, ast.assign.lhs, rhs.?, return_label, break_label, continue_label, error_label, errors, allocator);
            },
            ._or => {
                // Create the result symbol and IR
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);

                // Labels used
                const else_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const end_label = try IR.createLabel(null, ast.getToken().span, allocator);

                // Test lhs, branch
                const lhs = (try self.flattenAST(scope, ast._or.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const branch = try IR.createBranch(lhs, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, store `true` in temp
                const load_true_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                const load_true = try IR.createInt(load_true_lval, 1, ast.getToken().span, allocator);
                self.appendInstruction(load_true);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, recurse to rhs, store in temp
                self.appendInstruction(else_label);
                const rhs = try self.flattenAST(scope, ast._or.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                const copy_right_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                const copy_right = try IR.create_simple_copy(copy_right_lval, rhs.?, ast.getToken().span, allocator);
                self.appendInstruction(copy_right);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(end_label);
                return temp;
            },
            ._and => {
                // Create the result symbol and IR
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);

                // Labels used
                const else_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const end_label = try IR.createLabel(null, ast.getToken().span, allocator);

                // Test lhs, branch
                const lhs = (try self.flattenAST(scope, ast._and.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const branch = try IR.createBranch(lhs, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in temp
                const rhs = try self.flattenAST(scope, ast._and.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                const copy_right_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                const copy_right = try IR.create_simple_copy(copy_right_lval, rhs.?, ast.getToken().span, allocator);
                self.appendInstruction(copy_right);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, store `false` in temp
                self.appendInstruction(else_label);
                const load_false_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                const load_false = try IR.createInt(load_false_lval, 0, ast.getToken().span, allocator);
                self.appendInstruction(load_false);
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(end_label);
                return temp;
            },
            .add => {
                const lhs = try self.flattenAST(scope, ast.add.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.add.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create_int_float_kind(.add_int, .add_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .sub => {
                const lhs = try self.flattenAST(scope, ast.sub.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.sub.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create_int_float_kind(.sub_int, .sub_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .mult => {
                const lhs = try self.flattenAST(scope, ast.mult.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.mult.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create_int_float_kind(.mult_int, .mult_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .div => {
                const lhs = try self.flattenAST(scope, ast.div.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.div.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create_int_float_kind(.div_int, .div_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .mod => {
                const lhs = try self.flattenAST(scope, ast.mod.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.mod.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create(.mod, temp, lhs, rhs, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .equal => {
                const lhs = try self.flattenAST(scope, ast.equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                // Labels used
                const fail_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const end_label = try IR.createLabel(null, ast.getToken().span, allocator);

                try self.generate_tuple_equality(scope, lhs.?, rhs.?, fail_label, errors, allocator);

                self.appendInstruction(try IR.createInt(temp, 1, ast.getToken().span, allocator));
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(fail_label);
                self.appendInstruction(try IR.createInt(temp, 0, ast.getToken().span, allocator));
                self.appendInstruction(end_label);

                return temp;
            },
            .not_equal => {
                const lhs = try self.flattenAST(scope, ast.not_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.not_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const lhs_type = try (try ast.not_equal.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                if (lhs_type.* == .sum) {
                    const lhs_tag = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
                    const rhs_tag = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
                    self.appendInstruction(try IR.createGetTag(lhs_tag, lhs.?, ast.getToken().span, allocator));
                    self.appendInstruction(try IR.createGetTag(rhs_tag, rhs.?, ast.getToken().span, allocator));
                    self.appendInstruction(try IR.create(.not_equal, temp, lhs_tag, rhs_tag, ast.getToken().span, allocator));
                } else {
                    self.appendInstruction(try IR.create(.not_equal, temp, lhs, rhs, ast.getToken().span, allocator));
                }
                return temp;
            },
            .greater => {
                const lhs = try self.flattenAST(scope, ast.greater.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.greater.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create_int_float_kind(.greater_int, .greater_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .lesser => {
                const lhs = try self.flattenAST(scope, ast.lesser.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.lesser.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create_int_float_kind(.lesser_int, .lesser_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .greater_equal => {
                const lhs = try self.flattenAST(scope, ast.greater_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.greater_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create_int_float_kind(.greater_equal_int, .greater_equal_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .lesser_equal => {
                const lhs = try self.flattenAST(scope, ast.lesser_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.lesser_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.create_int_float_kind(.lesser_equal_int, .lesser_equal_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            ._catch => {
                // Create the result symbol.
                // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator); // Not actually assigned directly, just so that optimizations can capture the version

                const lhs = (try self.flattenAST(scope, ast._catch.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                // Labels used
                const else_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const end_label = try IR.createLabel(null, ast.getToken().span, allocator);

                // Test if lhs tag is 0 (ok)
                const condition = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
                self.appendInstruction(try IR.createGetTag(condition, lhs, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                self.appendInstruction(try IR.createBranch(condition, else_label, ast.getToken().span, allocator));

                // tag was an error, store rhs in temp
                const rhs = (try self.flattenAST(scope, ast._catch.rhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const rhs_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                self.appendInstruction(try IR.create_simple_copy(rhs_lval, rhs, ast.getToken().span, allocator));

                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(else_label);

                // tag was `.ok`, store lhs.some in temp
                const _type = try ast.typeof(scope, errors, allocator);
                const slots = (try _type.expand_type(scope, errors, allocator)).get_slots();
                const val = try L_Value.create_select(lhs, 0, 0, slots, _type, try _type.expand_type(scope, errors, allocator), allocator);
                const some_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                self.appendInstruction(try IR.create_simple_copy(some_lval, val, ast.getToken().span, allocator));

                self.appendInstruction(end_label);
                return temp;
            },
            ._orelse => {
                // Create the result symbol.
                // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator); // Not actually assigned directly, just so that optimizations can capture the version

                var lhs = (try self.flattenAST(scope, ast._orelse.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                // Labels used
                const else_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const end_label = try IR.createLabel(null, ast.getToken().span, allocator);

                // Test if lhs tag is 1 (some)
                const condition = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
                const load_tag = try IR.createGetTag(condition, lhs, ast.getToken().span, allocator); // Assumes `some` tag is nonzero, `none` tag is zero
                self.appendInstruction(load_tag);

                const branch = try IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // tag was `.some`, store lhs.some in temp
                const _type = try ast.typeof(scope, errors, allocator);
                const slots = (try _type.expand_type(scope, errors, allocator)).get_slots();
                const offset = try (try lhs.get_type().expand_type(scope, errors, allocator)).sum.get_offset(1, scope, errors, allocator);
                const val = try L_Value.create_select(lhs, 1, offset, slots, _type, try _type.expand_type(scope, errors, allocator), allocator);
                const some_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                self.appendInstruction(try IR.create_simple_copy(some_lval, val, ast.getToken().span, allocator));
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                self.appendInstruction(else_label);

                // tag was `.none`, store rhs in temp
                const rhs = (try self.flattenAST(scope, ast._orelse.rhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                const rhs_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                self.appendInstruction(try IR.create_simple_copy(rhs_lval, rhs, ast.getToken().span, allocator));

                self.appendInstruction(end_label);
                return temp;
            },
            .call => {
                const lhs = (try self.flattenAST(scope, ast.call.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                var temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                temp.extract_symbver().symbol.span = ast.getToken().span;

                var ir = try IR.createCall(temp, lhs, ast.getToken().span, allocator);
                for (ast.call.args.items) |term| {
                    try ir.data.lval_list.append((try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, errors, allocator)) orelse continue);
                }
                self.appendInstruction(try IR.createStackPush(ast.getToken().span, allocator));
                self.appendInstruction(ir);
                self.appendInstruction(try IR.createStackPop(ast.getToken().span, allocator));
                return temp;
            },
            .function => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                self.appendInstruction(try IR.create_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            },
            .index => {
                const _type = try ast.typeof(scope, errors, allocator);
                const slots = (try _type.expand_type(scope, errors, allocator)).get_slots();

                // Get the type of the index ast. This will determine if this is an array index or a slice index
                const ast_expanded_type = try (try ast.index.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);

                // Flatten index expr
                const rhs = try self.flattenAST(scope, ast.index.rhs, return_label, break_label, continue_label, error_label, errors, allocator);

                // Recursively get index's ast L_Value node
                var ast_lval = try self.flattenAST(scope, ast.index.lhs, return_label, break_label, continue_label, error_label, errors, allocator);

                if (ast_expanded_type.product.was_slice) {
                    // Indexing a slice; retval := lhs._0^[rhs]
                    const addr_type = ast_expanded_type.product.terms.items[0];
                    const addr_slots = (try _type.expand_type(scope, errors, allocator)).get_slots();
                    ast_lval = try L_Value.create_select(ast_lval.?, 0, 0, addr_slots, addr_type, try _type.expand_type(scope, errors, allocator), allocator);
                    ast_lval = try L_Value.create_dereference(ast_lval.?, addr_slots, addr_type, try _type.expand_type(scope, errors, allocator), allocator);
                }
                // Surround with L_Value node
                return try L_Value.create_index(ast_lval.?, rhs.?, slots, _type, try _type.expand_type(scope, errors, allocator), allocator);
            },
            .select => {
                // Recursively get select's ast L_Value node
                const ast_lval = try self.flattenAST(scope, ast.select.lhs, return_label, break_label, continue_label, error_label, errors, allocator);

                // Get the offset into the struct that this select does
                var ast_expanded_type = try (try ast.select.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                const offset = if (ast_expanded_type.* == .product)
                    try ast_expanded_type.product.get_offset(ast.select.pos.?, scope, errors, allocator)
                else
                    try ast_expanded_type.sum.get_offset(ast.select.pos.?, scope, errors, allocator);

                // Surround with L_Value node
                const _type = try ast.typeof(scope, errors, allocator);
                return try L_Value.create_select(ast_lval.?, ast.select.pos.?, offset, try ast.select.offset_at(scope, errors, allocator), _type, try _type.expand_type(scope, errors, allocator), allocator);
            },
            .product => {
                if (try (try ast.product.terms.items[0].typeof(scope, errors, allocator)).typesMatch(primitives.type_type, scope, errors, allocator)) {
                    const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                    self.appendInstruction(try IR.create_ast(temp, ast, ast.getToken().span, allocator));
                    return temp;
                } else {
                    const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                    var ir = try IR.createLoadStruct(temp, ast.getToken().span, allocator);
                    for (ast.product.terms.items) |term| {
                        try ir.data.lval_list.append((try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null);
                    }
                    self.appendInstruction(ir);
                    return temp;
                }
            },
            .sum => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                self.appendInstruction(try IR.create_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            },

            // Fancy Operators
            .addrOf => {
                if (try (try ast.typeof(scope, errors, allocator)).typesMatch(primitives.type_type, scope, errors, allocator)) {
                    const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                    self.appendInstruction(try IR.create_ast(temp, ast, ast.getToken().span, allocator));
                    return temp;
                } else {
                    const expr = try self.flattenAST(scope, ast.addrOf.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                    const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                    const ir = try IR.create(.addrOf, temp, expr, null, ast.getToken().span, allocator);
                    self.appendInstruction(ir);
                    return temp;
                }
            },
            .subSlice => {
                const arr = (try self.flattenAST(scope, ast.subSlice.super, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const lower = (try self.flattenAST(scope, ast.subSlice.lower.?, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const upper = (try self.flattenAST(scope, ast.subSlice.upper.?, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                // Statically confirm that lower <= upper
                // if (lower.def.?.kind == .loadInt and upper.def.?.kind == .loadInt and lower.def.?.data.int > upper.def.?.data.int) {
                //     errors.addError(Error{ .slice_lower_upper = .{
                //         .span = lower.def.?.span,
                //         .lower = lower.def.?.data.int,
                //         .upper = upper.def.?.data.int,
                //     } });
                //     return error.typeError;
                // } else
                { // Dynamically confirm that lower <= upper
                    const end_label = try IR.createLabel(null, ast.getToken().span, allocator);
                    const compare = try self.create_temp_lvalue(primitives.bool_type, errors, allocator);
                    const ir = try IR.create(.greater_int, compare, lower, upper, ast.getToken().span, allocator);
                    self.appendInstruction(ir);
                    const branch = try IR.createBranch(compare, end_label, ast.getToken().span, allocator);
                    self.appendInstruction(branch);
                    self.appendInstruction(try IR.createStackPush(ast.getToken().span, allocator));
                    self.appendInstruction(try IR.createPanic("subslice lower bound is greater than upper bound", ast.getToken().span, allocator));
                    self.appendInstruction(end_label);
                }

                const new_size = try self.create_temp_lvalue(primitives.int_type, errors, allocator);
                const new_size_ir = try IR.create(.sub_int, new_size, upper, lower, ast.getToken().span, allocator);
                self.appendInstruction(new_size_ir);

                const slice_type = try ast.typeof(scope, errors, allocator);
                const data_type = slice_type.product.terms.items[0];
                const slots = (try data_type.expand_type(scope, errors, allocator)).get_slots();
                const data_ptr = try L_Value.create_select(arr, 0, 0, slots, data_type, try data_type.expand_type(scope, errors, allocator), allocator);

                const new_data_ptr = try self.create_temp_lvalue(data_type, errors, allocator);
                const new_data_ptr_ir = try IR.create(.add_int, new_data_ptr, data_ptr, lower, ast.getToken().span, allocator);
                self.appendInstruction(new_data_ptr_ir);

                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                var load_struct = try IR.createLoadStruct(temp, ast.getToken().span, allocator);
                try load_struct.data.lval_list.append(new_data_ptr);
                try load_struct.data.lval_list.append(new_size);
                self.appendInstruction(load_struct);
                return temp;
            },
            .annotation => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                self.appendInstruction(try IR.create_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            },
            .inferredMember => {
                var init: ?*L_Value = null;
                const pos: i128 = ast.inferredMember.pos.?;
                const proper_term: *AST = (try ast.typeof(scope, errors, allocator)).sum.terms.items[@as(usize, @intCast(pos))];
                if (ast.inferredMember.init) |_init| {
                    init = try self.flattenAST(scope, _init, return_label, break_label, continue_label, error_label, errors, allocator);
                } else if (proper_term.annotation.init == null and proper_term.annotation.type.* != .unit) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "no value provided, and no default value available" } });
                    return error.typeError;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try IR.createUnion(temp, init, ast.inferredMember.pos.?, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },

            // Control-flow expressions
            ._if => {
                // Create the result symbol and IR
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);

                // If there's a let, then do it, dumby!
                if (ast._if.let) |let| {
                    _ = try self.flattenAST(ast._if.scope.?, let, return_label, break_label, continue_label, error_label, errors, allocator);
                }

                // Labels used
                const else_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const end_label = try IR.createLabel(null, ast.getToken().span, allocator);

                // Test lhs, branch
                const condition = (try self.flattenAST(ast._if.scope.?, ast._if.condition, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const branch = try IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in temp
                if (try self.flattenAST(ast._if.scope.?, ast._if.bodyBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |block_lval| {
                    const block_copy_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                    var block_copy: *IR = undefined;
                    if (ast._if.elseBlock == null) {
                        // no else block => if is optional, coerce up to `.some <- block`
                        block_copy = try IR.createUnion(block_copy_lval, block_lval, 1, ast.getToken().span, allocator);
                    } else {
                        // regular if-else => copy block
                        block_copy = try IR.create_simple_copy(block_copy_lval, block_lval, ast.getToken().span, allocator);
                    }
                    self.appendInstruction(block_copy);
                }
                self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, store `false` in temp
                self.appendInstruction(else_label);
                if (ast._if.elseBlock) |elseBlock| {
                    if (try self.flattenAST(ast._if.scope.?, elseBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |else_lval| {
                        const else_copy_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                        const else_copy = try IR.create_simple_copy(else_copy_lval, else_lval, ast.getToken().span, allocator);
                        self.appendInstruction(else_copy);
                    }
                    self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                } else {
                    // no else block => if is optional, store null
                    const else_copy_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                    const else_copy = try IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                    self.appendInstruction(else_copy);
                }
                self.appendInstruction(end_label);
                return temp;
            },
            .match => {
                // Create the result symbol and IR
                const symbol_type = if (ast.match.has_else)
                    // Match has an else, type of the mappings should be the type of the match
                    try ast.typeof(scope, errors, allocator)
                else
                    // Match has no else, type of the mappings should be wrapped in an optional type
                    try AST.create_optional_type(try ast.typeof(scope, errors, allocator), allocator);
                const symbol = try self.createTempSymbol(symbol_type, errors, allocator);
                const temp = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);

                // Exit label of match
                const end_label = try IR.createLabel(null, ast.getToken().span, allocator);
                // Label jumped to if all tests fail and no `else` mapping
                const none_label = try IR.createLabel(null, ast.getToken().span, allocator);
                // List of labels to branch to on an unsuccessful test (ie "next pattern")
                var lhs_label_list = std.ArrayList(*IR).init(allocator);
                defer lhs_label_list.deinit();
                // List of labels to branch to on a successful test (ie "code for the mapping")
                var rhs_label_list = std.ArrayList(*IR).init(allocator);
                defer rhs_label_list.deinit();
                for (ast.match.mappings.items) |_| {
                    try lhs_label_list.append(try IR.createLabel(null, ast.getToken().span, allocator));
                    try rhs_label_list.append(try IR.createLabel(null, ast.getToken().span, allocator));
                }
                std.debug.assert(lhs_label_list.items.len == ast.match.mappings.items.len);

                // If there's a let, then do it, dumby!
                if (ast.match.let) |let| {
                    _ = try self.flattenAST(ast.match.scope.?, let, return_label, break_label, continue_label, error_label, errors, allocator);
                }

                const expr = try self.flattenAST(scope, ast.match.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }

                // Generate the lhs of the mappings
                var label_index: usize = 0;
                for (ast.match.mappings.items) |mapping| {
                    const lhs_label = lhs_label_list.items[label_index];
                    self.appendInstruction(lhs_label);
                    if (mapping.mapping.lhs) |lhs| {
                        const next_label = if (label_index < lhs_label_list.items.len - 1)
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
                    const else_copy_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                    const else_copy = try IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                    self.appendInstruction(else_copy);
                    self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                }

                // Write the labels and the rhs of the mappings
                label_index = 0;
                for (ast.match.mappings.items) |mapping| {
                    self.appendInstruction(rhs_label_list.items[label_index]);
                    if (mapping.mapping.lhs) |lhs| {
                        // Generate initialization for patterns before the rhs
                        try self.generate_pattern(ast.match.scope.?, lhs, expr.?.get_type(), expr.?, errors, allocator);
                    }

                    // Generate the rhs, copy result to temp
                    const mapping_scope = if (mapping.mapping.scope != null) mapping.mapping.scope.? else ast.match.scope.?;
                    if (try self.flattenAST(mapping_scope, mapping.mapping.rhs.?, return_label, break_label, continue_label, error_label, errors, allocator)) |rhs_lval| {
                        const rhs_copy_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                        var rhs_copy: *IR = undefined;
                        if (ast.match.has_else) {
                            rhs_copy = try IR.create_simple_copy(rhs_copy_lval, rhs_lval, ast.getToken().span, allocator);
                        } else {
                            rhs_copy = try IR.createUnion(rhs_copy_lval, rhs_lval, 1, ast.getToken().span, allocator);
                        }
                        self.appendInstruction(rhs_copy);
                    }
                    self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                    label_index += 1;
                }
                self.appendInstruction(end_label);

                return temp;
            },
            ._while => {
                // Create the result symbol and IR
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);

                // Labels used
                const cond_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const current_continue_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const else_label = try IR.createLabel(null, ast.getToken().span, allocator);
                const end_label = try IR.createLabel(null, ast.getToken().span, allocator);

                // If there's a let, then do it, dumby!
                if (ast._while.let) |let| {
                    _ = try self.flattenAST(ast._while.scope.?, let, return_label, break_label, continue_label, error_label, errors, allocator);
                }

                // Test condition, branch to either body or else block
                self.appendInstruction(cond_label);
                const condition = (try self.flattenAST(ast._while.scope.?, ast._while.condition, return_label, end_label, current_continue_label, error_label, errors, allocator)) orelse return null;
                const branch = try IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // Body block
                if (try self.flattenAST(ast._while.scope.?, ast._while.bodyBlock, return_label, end_label, current_continue_label, error_label, errors, allocator)) |block_lval| {
                    const block_copy_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                    var block_copy: *IR = undefined;
                    if (ast._while.elseBlock == null) {
                        // no else block => while is optional, coerce up to `.some <- block`
                        block_copy = try IR.createUnion(block_copy_lval, block_lval, 1, ast.getToken().span, allocator);
                    } else {
                        // regular while-else => copy block
                        block_copy = try IR.create_simple_copy(block_copy_lval, block_lval, ast.getToken().span, allocator);
                    }
                    self.appendInstruction(block_copy);
                }

                // Post-condition, jump to condition test
                self.appendInstruction(current_continue_label);
                if (ast._while.post) |post| {
                    _ = try self.flattenAST(ast._while.scope.?, post, return_label, end_label, continue_label, error_label, errors, allocator);
                }
                self.appendInstruction(try IR.createJump(cond_label, ast.getToken().span, allocator));

                // Else block
                self.appendInstruction(else_label);
                if (ast._while.elseBlock) |elseBlock| {
                    if (try self.flattenAST(ast._while.scope.?, elseBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |else_lval| {
                        const elseCopy = try IR.create_simple_copy(temp, else_lval, ast.getToken().span, allocator);
                        self.appendInstruction(elseCopy);
                    }
                    self.appendInstruction(try IR.createJump(end_label, ast.getToken().span, allocator));
                } else {
                    // no else block => while is optional, store null
                    const else_copy_lval = try L_Value.create_unversioned_symbver(symbol, symbol._type.?, allocator);
                    const else_copy = try IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                    self.appendInstruction(else_copy);
                }
                self.appendInstruction(end_label);
                return temp;
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
                        try continue_labels.append(try IR.createLabel(null, ast.getToken().span, allocator));
                        try break_labels.append(try IR.createLabel(null, ast.getToken().span, allocator));
                        try return_labels.append(try IR.createLabel(null, ast.getToken().span, allocator));
                    }
                    for (ast.block.scope.?.errdefers.items) |_| {
                        try error_labels.append(try IR.createLabel(null, ast.getToken().span, allocator));
                    }
                    const end = try IR.createLabel(null, ast.getToken().span, allocator);

                    // These are the labels to go to on each final statement. These are updated to point to different places in the defer chain at the end of this block.
                    var current_continue_label = if (continue_label != null) continue_label else end;
                    var current_break_label = break_label;
                    var current_return_label = return_label;
                    var current_error_label = error_label;
                    var defer_label_index: usize = 0;
                    var errdefer_label_index: usize = 0;

                    var temp: ?*L_Value = null;
                    for (ast.block.statements.items) |child| {
                        temp = try self.flattenAST(ast.block.scope.?, child, current_return_label, current_break_label, current_continue_label, current_error_label, errors, allocator);
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
                        temp = try self.flattenAST(ast.block.scope.?, final, current_return_label, current_break_label, current_continue_label, current_error_label, errors, allocator);
                    } else if (temp) |_temp| {
                        const expanded_temp_type = try _temp.get_type().expand_type(scope, errors, allocator);
                        if (current_error_label != null and expanded_temp_type.* == .sum and expanded_temp_type.sum.was_error) {
                            // Returning error sum, runtime check if error, branch to error path
                            const condition = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
                            self.appendInstruction(try IR.createGetTag(condition, _temp, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                            const not_condition = try create_temp_lvalue(self, primitives.bool_type, errors, allocator);
                            self.appendInstruction(try IR.create(.not, not_condition, condition, null, ast.getToken().span, allocator));
                            self.appendInstruction(try IR.createBranch(not_condition, current_error_label, ast.getToken().span, allocator));
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
                var def: ?*L_Value = null;
                if (ast.decl.init) |init| {
                    def = try self.flattenAST(scope, init, return_label, break_label, continue_label, error_label, errors, allocator);
                } else {
                    def = try self.generate_default(scope, ast.decl.type.?, errors, allocator);
                }
                if (def == null) {
                    return null;
                }
                try self.generate_pattern(scope, ast.decl.pattern, try ast.decl.type.?.expand_type(scope, errors, allocator), def.?, errors, allocator);
                return null;
            },
            .fnDecl => {
                _ = try ast.fnDecl.symbol.?.get_cfg(self, self.interned_strings, errors, allocator);
                const temp = try self.create_temp_lvalue(ast.fnDecl.symbol.?._type.?, errors, allocator);
                var ir = try IR.create(.loadSymbol, temp, null, null, ast.getToken().span, allocator);
                ir.data = IRData{ .symbol = ast.fnDecl.symbol.? };
                self.appendInstruction(ir);
                return temp;
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
                    const retval = (try self.flattenAST(scope, expr, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                    const retval_lval = try L_Value.create_unversioned_symbver(self.return_symbol, self.symbol._type.?.function.rhs, allocator);
                    const retval_copy = try IR.create_simple_copy(retval_lval, retval, ast.getToken().span, allocator);
                    self.appendInstruction(retval_copy);

                    const expanded_expr_type = try (try expr.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                    if (expanded_expr_type.* == .sum and expanded_expr_type.sum.was_error) {
                        // Returning error sum, runtime check if error, branch to error path
                        const condition = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
                        self.appendInstruction(try IR.createGetTag(condition, retval, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                        const not_condition = try create_temp_lvalue(self, primitives.bool_type, errors, allocator);
                        self.appendInstruction(try IR.create(.not, not_condition, condition, null, ast.getToken().span, allocator));
                        self.appendInstruction(try IR.createBranch(not_condition, error_label, ast.getToken().span, allocator));
                    }
                    self.appendInstruction(try IR.createJump(return_label, ast.getToken().span, allocator));
                } else {
                    // Jump to return_label
                    self.appendInstruction(try IR.createJump(return_label, ast.getToken().span, allocator));
                }
                return null;
            },

            else => {
                std.debug.print("Unimplemented flattenAST() for: AST.{s}\n", .{@tagName(ast.*)});
                return error.Unimplemented;
            },
        }
    }

    fn generate_tuple_equality(
        self: *CFG,
        scope: *Scope,
        lhs: *L_Value,
        rhs: *L_Value,
        fail_label: *IR,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!void {
        const new_lhs = lhs; // try L_Value.create_unversioned_symbver(lhs.symbol, lhs.symbol._type.?, allocator);
        const new_rhs = rhs; // try L_Value.create_unversioned_symbver(rhs.symbol, rhs.symbol._type.?, allocator);
        const temp = try self.create_temp_lvalue(primitives.bool_type, errors, allocator);
        var lhs_type = try lhs.get_type().expand_type(scope, errors, allocator);
        if (lhs_type.* == .product) {
            for (0..lhs_type.product.terms.items.len) |i| {
                const _type = lhs_type.product.terms.items[i];
                const slots = (try _type.expand_type(scope, errors, allocator)).get_slots();
                const lhs_select = try L_Value.create_select(new_lhs, i, try lhs_type.product.get_offset(i, scope, errors, allocator), slots, _type, try _type.expand_type(scope, errors, allocator), allocator);
                const rhs_select = try L_Value.create_select(new_rhs, i, try lhs_type.product.get_offset(i, scope, errors, allocator), slots, _type, try _type.expand_type(scope, errors, allocator), allocator);
                try self.generate_tuple_equality(scope, lhs_select, rhs_select, fail_label, errors, allocator);
            }
        } else if (lhs_type.* == .sum) {
            const lhs_tag = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
            const rhs_tag = try create_temp_lvalue(self, primitives.word64_type, errors, allocator);
            self.appendInstruction(try IR.createGetTag(lhs_tag, new_lhs, lhs.extract_symbver().symbol.span, allocator));
            self.appendInstruction(try IR.createGetTag(rhs_tag, new_rhs, lhs.extract_symbver().symbol.span, allocator));
            self.appendInstruction(try IR.create(.equal, temp, lhs_tag, rhs_tag, lhs.extract_symbver().symbol.span, allocator));
            self.appendInstruction(try IR.createBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
        } else {
            self.appendInstruction(try IR.create(.equal, temp, new_lhs, rhs, lhs.extract_symbver().symbol.span, allocator));
            self.appendInstruction(try IR.createBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
        }
    }

    /// Takes in a type, generates the code to create the default value for that type, returns SymbolVersion
    fn generate_default(self: *CFG, scope: *Scope, _type: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) FlattenASTError!?*L_Value {
        switch (_type.*) {
            .identifier => {
                if (_type.getCommon().expanded_type.? == _type) {
                    const temp = try self.create_temp_lvalue(_type, errors, allocator);
                    const ir = try IR.createInt(temp, 0, _type.getToken().span, allocator);
                    self.appendInstruction(ir);
                    return temp;
                } else {
                    return self.generate_default(scope, _type.getCommon().expanded_type.?, errors, allocator);
                }
            },
            .addrOf,
            .function,
            => {
                const temp = try self.create_temp_lvalue(_type, errors, allocator);
                const ir = try IR.createInt(temp, 0, _type.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .sum => {
                const index: usize = 0;
                const proper_term: *AST = _type.sum.terms.items[index];
                const init: ?*L_Value = try self.generate_default(scope, proper_term, errors, allocator);
                const temp = try self.create_temp_lvalue(_type, errors, allocator);

                const ir = try IR.createUnion(temp, init, index, _type.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .product => {
                const temp = try self.create_temp_lvalue(_type, errors, allocator);
                var ir = try IR.createLoadStruct(temp, _type.getToken().span, allocator);
                for (_type.product.terms.items) |term| {
                    const term_symb_ver = try self.generate_default(scope, term, errors, allocator);
                    if (term_symb_ver) |_| {
                        try ir.data.lval_list.append(term_symb_ver.?);
                    } else {
                        const temp2 = try self.create_temp_lvalue(primitives.unit_type, errors, allocator);
                        const ir2 = try IR.createInt(temp2, 0, _type.getToken().span, allocator);
                        self.appendInstruction(ir2);
                        try ir.data.lval_list.append(temp2);
                    }
                }
                self.appendInstruction(ir);
                return temp;
            },
            .unit => return null,
            .annotation => if (_type.annotation.init != null) {
                return self.flattenAST(scope, _type.annotation.init.?, null, null, null, null, errors, allocator);
            } else {
                return self.generate_default(scope, _type.annotation.type, errors, allocator);
            },
            else => {
                std.debug.print("Unimplemented generate_default() for: AST.{s}\n", .{@tagName(_type.*)});
                return error.Unimplemented;
            },
        }
    }

    fn generate_assign(
        self: *CFG, // Current control-flow-graph
        scope: *Scope, // Scope node to use for symbol-tree lookups
        lhs: *AST, // AST node for the LHS of the `=`
        rhs: *L_Value, // L_Value which holds the value to assign
        return_label: ?*IR,
        break_label: ?*IR,
        continue_label: ?*IR,
        error_label: ?*IR,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!?*L_Value // If assign is to a single symbver, returns the symbver
    {
        if (lhs.* == .product) {
            // Recursively call `generate_assign` for each term in the product.
            // product-assigns may be nested, for example:
            //     ((x, y), (a, b)) = get_tuple()
            // So it's important that this is recursive
            var lhs_expanded_type = try (try lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            for (lhs.product.terms.items, 0..) |term, i| {
                const product_lhs = try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, errors, allocator);
                if (product_lhs == null) {
                    continue;
                }
                const _type = rhs.get_type().product.terms.items[i];
                const slots = (try _type.expand_type(scope, errors, allocator)).get_slots();
                const select = try L_Value.create_select(rhs, i, try lhs_expanded_type.product.get_offset(i, scope, errors, allocator), slots, _type, try _type.expand_type(scope, errors, allocator), allocator);
                _ = try self.generate_assign(scope, term, select, return_label, break_label, continue_label, error_label, errors, allocator);
            }
            return null;
        } else {
            // Get L_Value tree, create a `copy` IR of L_Value tree and rhs
            const lval = try self.flattenAST(scope, lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            var ir = try IR.create(.copy, null, rhs, null, lhs.getToken().span, allocator);
            ir.dest = lval;
            ir.safe = true;
            self.appendInstruction(ir);
            return null;
        }
    }

    fn generate_pattern(
        self: *CFG,
        scope: *Scope,
        pattern: *AST,
        _type: *AST,
        def: *L_Value,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!void {
        if (pattern.* == .symbol) {
            if (!std.mem.eql(u8, pattern.symbol.name, "_")) {
                const symbver = try L_Value.create_unversioned_symbver(pattern.symbol.symbol, pattern.symbol.symbol._type.?, allocator);
                const ir = try IR.create_simple_copy(symbver, def, pattern.getToken().span, allocator);
                self.appendInstruction(ir);
            }
        } else if (pattern.* == .product) {
            for (pattern.product.terms.items, 0..) |term, i| {
                const subscript_type = _type.product.terms.items[i];
                const slots = (try subscript_type.expand_type(scope, errors, allocator)).get_slots();
                const offset = try pattern.product.get_offset(i, scope, errors, allocator);
                const lval = try L_Value.create_select(def, i, offset, slots, subscript_type, try subscript_type.expand_type(scope, errors, allocator), allocator);
                try self.generate_pattern(scope, term, subscript_type, lval, errors, allocator);
            }
        } else if (pattern.* == .inject) {
            const lhs_type = try pattern.inject.lhs.typeof(scope, errors, allocator);
            const domain = try validate.domainof(pattern, lhs_type, scope, errors, allocator);
            const slots = (try domain.expand_type(scope, errors, allocator)).get_slots();
            const lval = try L_Value.create_select(def, pattern.inject.lhs.inferredMember.pos.?, 0, slots, domain, try domain.expand_type(scope, errors, allocator), allocator);
            try self.generate_pattern(scope, pattern.inject.rhs, domain, lval, errors, allocator);
        }
    }

    /// Generates the code which checks if the pattern matches the match expression
    fn generate_match_pattern_check(
        self: *CFG,
        scope: *Scope,
        pattern: ?*AST,
        expr: *L_Value,
        next_pattern: *IR,
        return_label: ?*IR,
        break_label: ?*IR,
        continue_label: ?*IR,
        error_label: ?*IR,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!void {
        if (pattern == null) {
            // Implies `else` branch, infallible.
            return;
        }
        const new_expr = expr; // try L_Value.create_unversioned_symbver(expr.symbol, expr.type, allocator);
        switch (pattern.?.*) {
            .int,
            .float,
            ._true,
            ._false,
            .char,
            .string,
            .block,
            => {
                const value = try self.flattenAST(scope, pattern.?, return_label, break_label, continue_label, error_label, errors, allocator);
                const condition = try self.create_temp_lvalue(primitives.bool_type, errors, allocator);
                const condition_ir = try IR.create(.equal, condition, new_expr, value.?, pattern.?.getToken().span, allocator);
                self.appendInstruction(condition_ir);
                const branch = try IR.createBranch(condition, next_pattern, pattern.?.getToken().span, allocator);
                self.appendInstruction(branch);
            },
            .symbol => {
                // Infallible check, do not branch to next pattern
            },
            .product => {
                for (pattern.?.product.terms.items, 0..) |term, i| {
                    const subscript_type = new_expr.get_type().product.terms.items[i];
                    const slots = (try subscript_type.expand_type(scope, errors, allocator)).get_slots();
                    const offset = try pattern.?.product.get_offset(i, scope, errors, allocator);
                    const lval = try L_Value.create_select(new_expr, i, offset, slots, subscript_type, try subscript_type.expand_type(scope, errors, allocator), allocator);
                    try self.generate_match_pattern_check(scope, term, lval, next_pattern, return_label, break_label, continue_label, error_label, errors, allocator);
                }
            },
            .select => {
                // Get tag of pattern
                const sel = try self.create_temp_lvalue(primitives.word64_type, errors, allocator);
                const sel_ir = try IR.createInt(sel, pattern.?.select.pos.?, pattern.?.getToken().span, allocator);
                self.appendInstruction(sel_ir);

                // Get tag of expr
                const tag = try self.create_temp_lvalue(primitives.word64_type, errors, allocator);
                const tag_ir = try IR.createGetTag(tag, expr, pattern.?.getToken().span, allocator);
                self.appendInstruction(tag_ir);

                // Compare them, jump to next pattern if they are not equal
                const neql = try self.create_temp_lvalue(primitives.bool_type, errors, allocator);
                const neql_ir = try IR.create(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
                self.appendInstruction(neql_ir);
                const branch = try IR.createBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
                self.appendInstruction(branch);
            },
            .inferredMember => {
                // Get tag of pattern
                const sel = try self.create_temp_lvalue(primitives.word64_type, errors, allocator);
                const sel_ir = try IR.createInt(sel, pattern.?.inferredMember.pos.?, pattern.?.getToken().span, allocator);
                self.appendInstruction(sel_ir);

                // Get tag of expr
                const tag = try self.create_temp_lvalue(primitives.word64_type, errors, allocator);
                const tag_ir = try IR.createGetTag(tag, expr, pattern.?.getToken().span, allocator);
                self.appendInstruction(tag_ir);

                // Compare them, jump to next pattern if they are not equal
                const neql = try self.create_temp_lvalue(primitives.bool_type, errors, allocator);
                const neql_ir = try IR.create(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
                self.appendInstruction(neql_ir);
                const branch = try IR.createBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
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
    fn generate_bounds_check(self: *CFG, scope: *Scope, ast: *AST, lhs: *SymbolVersion, errors: *errs.Errors, allocator: std.mem.Allocator) !IRMeta {
        const length: *SymbolVersion = try self.create_temp_lvalue(primitives.int_type, errors, allocator);
        var lhs_type = try lhs.type.expand_type(scope, errors, allocator);
        if (lhs_type.* == .product and lhs_type.product.was_slice) {
            const ir = try IR.createSelect(length, lhs, 1, try lhs_type.product.get_offset(1, scope, errors, allocator), ast.index.lhs.getToken().span, allocator);
            self.appendInstruction(ir);
        } else if (lhs_type.* == .product and !lhs_type.product.was_slice) {
            const ir = try IR.createInt(length, lhs_type.product.terms.items.len, ast.getToken().span, allocator);
            self.appendInstruction(ir);
        } else {
            unreachable;
        }
        return IRMeta{ .bounds_check = .{ .length = length } };
    }

    fn generateDefers(self: *CFG, defers: *std.ArrayList(*AST), deferLabels: *std.ArrayList(*IR), scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) FlattenASTError!void {
        var i: usize = defers.items.len;
        while (i > 0) : (i -= 1) {
            self.appendInstruction(deferLabels.items[i - 1]);
            _ = try self.flattenAST(scope, defers.items[i - 1], null, null, null, null, errors, allocator);
        }
    }

    /// Converts the list of IR to a web of BB's
    /// Also versions IR dest's if they are symbvers. This versioning should persist and should not be wiped.
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

    fn version_lvalue(lval: *L_Value, bb: *BasicBlock, ir: ?*IR, parameters: *std.ArrayList(*SymbolVersion)) !void {
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
            },
            .select => {
                try version_lvalue(lval.select.lhs, bb, ir, parameters);
            },
        }
    }

    /// Finds the phi *arguments* that each basic block needs to pass along, whereas calculatePhiParamsAndArgs finds the *parameters* it needs to include.
    fn childrenArgPropagation(self: *CFG, bb: *BasicBlock, allocator: std.mem.Allocator) !bool {
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
                        const myParam = param.findSymbolVersionSet(&bb.parameters); // see if param is already in block paramlist
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
