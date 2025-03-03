// TODO: Split up symbol version and lval, put them in the SSA namespace along with basic blocks

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const ir_ = @import("../ir/instruction.zig");
const symbol_ = @import("../symbol/symbol.zig");
const String = @import("../zig-string/zig-string.zig").String;

/// Represents different forms of l-values in an l-value tree.
///
/// The root of every L-Value tree is a symbol-version. If an L-Value tree represents a destination address, only the root symbol is modified.
/// Most nodes are unary, however, indices have two children.
pub const L_Value = union(enum) {
    /// Represents an SSA version of a symbol
    ///
    /// lval is the address of the symbol
    symbver: *Symbol_Version,

    /// Represents an address dereference
    ///
    /// lval is `expr`
    dereference: struct {
        /// Address to dereference
        expr: *L_Value,
        /// Dereference's resulting expanded type
        expanded_type: *ast_.AST,
        /// Allocator that allocated this lvalue
        allocator: std.mem.Allocator,
    },

    /// Represents a runtime array or slice index
    ///
    /// lval is `lhs + rhs * sizeof()`
    index: struct {
        /// The base of the array/slice.
        lhs: *L_Value,
        /// The element's index, which is multiplied by the element size to get the lval
        rhs: *L_Value,
        /// Debug UB info. Is the length of the array/slice. In debug mode, a panic is raised if rhs is greater-to-or-equal to this length.
        length: ?*L_Value,
        /// Index's resulting expanded type
        expanded_type: *ast_.AST,
        /// Allocator that allocated this lvalue
        allocator: std.mem.Allocator,
    },

    /// Represents a product selection based on a comptile-time known field and offset.
    ///
    /// lval is `lhs + offset`
    select: struct {
        /// The base lval that is being projected
        lhs: *L_Value,
        /// The id of the field that is being selected. Used by codegen.
        field: i128,
        /// The offset, in bytes, of the selection from the `lhs` address. Used by interpreter.
        offset: i64,
        /// Selection's resulting expanded type
        expanded_type: *ast_.AST,
        /// Debug UB info. Populated by a `get_tag` before selection.
        /// In debug mode, a panic is raised if this doesn't match `field` at runtime.
        tag: ?*L_Value,
        /// Allocator that allocated this lvalue
        allocator: std.mem.Allocator,
    },

    /// Represents a raw address. Only used internally by the interpreter.
    raw_address: struct {
        /// The raw address that this lvalue refers to
        adrs: i64,
        /// Allocator that allocated this lvalue
        allocator: std.mem.Allocator,
    },

    fn create_symbver(symbver: *Symbol_Version, allocator: std.mem.Allocator) *L_Value {
        const retval = allocator.create(L_Value) catch unreachable;
        retval.* = L_Value{ .symbver = symbver };
        return retval;
    }

    pub fn create_unversioned_symbver(symbol: *symbol_.Symbol, allocator: std.mem.Allocator) *L_Value {
        const retval = L_Value.create_symbver(Symbol_Version.create_unversioned(symbol, allocator), allocator);
        return retval;
    }

    pub fn create_dereference_lval(lhs: *L_Value, expanded_type: *ast_.AST, allocator: std.mem.Allocator) *L_Value {
        const retval = allocator.create(L_Value) catch unreachable;
        retval.* = L_Value{
            .dereference = .{
                .expr = lhs,
                .expanded_type = expanded_type,
                .allocator = allocator,
            },
        };
        return retval;
    }

    pub fn create_index_lval(
        lhs: *L_Value,
        rhs: *L_Value,
        length: ?*L_Value,
        expanded_type: *ast_.AST,
        allocator: std.mem.Allocator,
    ) *L_Value {
        const retval = allocator.create(L_Value) catch unreachable;
        retval.* = L_Value{ .index = .{
            .lhs = lhs,
            .rhs = rhs,
            .length = length,
            .expanded_type = expanded_type,
            .allocator = allocator,
        } };
        return retval;
    }

    pub fn create_select_lval(
        lhs: *L_Value,
        field: i128,
        offset: i64,
        expanded_type: *ast_.AST,
        tag: ?*L_Value,
        allocator: std.mem.Allocator,
    ) *L_Value {
        const retval = allocator.create(L_Value) catch unreachable;
        retval.* = L_Value{
            .select = .{
                .lhs = lhs,
                .field = field,
                .offset = offset,
                .expanded_type = expanded_type,
                .tag = tag,
                .allocator = allocator,
            },
        };
        return retval;
    }

    pub fn create_raw_address_lval(adrs: i64, allocator: std.mem.Allocator) *L_Value {
        const retval = allocator.create(L_Value) catch unreachable;
        retval.* = L_Value{
            .raw_address = .{ .adrs = adrs, .allocator = allocator },
        };
        return retval;
    }

    pub fn deinit(self: *L_Value) void {
        switch (self.*) {
            .symbver => self.symbver.deinit(),
            .dereference => self.dereference.allocator.destroy(self),
            .index => self.index.allocator.destroy(self),
            .select => self.select.allocator.destroy(self),
            .raw_address => self.raw_address.allocator.destroy(self),
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
            .raw_address => {
                try out.writer().print("0x{X}", .{self.raw_address.adrs});
            },
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: L_Value, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        // TODO: Generic pprinter that makes the arena and string and passes the writer to a pprint method
        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }

    pub fn extract_symbver(self: *L_Value) *Symbol_Version {
        return switch (self.*) {
            .symbver => self.symbver,
            .dereference => self.dereference.expr.extract_symbver(),
            .index => self.index.lhs.extract_symbver(),
            .select => self.select.lhs.extract_symbver(),
            .raw_address => std.debug.panic("compiler error: raw addresses do not have symbvers", .{}),
        };
    }

    pub fn expanded_type_sizeof(self: *L_Value) i64 {
        std.debug.assert(self.get_expanded_type().valid_type()); // This is it!
        return self.get_expanded_type().sizeof();
    }

    pub fn expanded_type_alignof(self: *L_Value) i64 {
        return self.get_expanded_type().alignof();
    }

    pub fn get_expanded_type(self: *L_Value) *ast_.AST {
        switch (self.*) {
            .symbver => return self.symbver.symbol.expanded_type.?,
            .dereference => return self.dereference.expanded_type,
            .index => return self.index.expanded_type,
            .select => return self.select.expanded_type,
            .raw_address => std.debug.panic("compiler error: raw addresses do not have types", .{}),
        }
    }

    pub fn lval_precedence(self: *L_Value) i64 {
        return switch (self.*) {
            .symbver => ir_.Kind.precedence(ir_.Kind.load_symbol),
            .dereference => 2,
            .index => 2,
            .select => 1,
            .raw_address => std.debug.panic("compiler error: raw addresses do not have precedence", .{}),
        };
    }

    pub fn reset_usage(lval: *L_Value) void {
        switch (lval.*) {
            .symbver => {
                lval.symbver.uses = 0;
                lval.symbver.symbol.uses = 0;
            },
            .dereference => lval.dereference.expr.reset_usage(),
            .index => {
                lval.index.lhs.reset_usage();
                lval.index.rhs.reset_usage();
                if (lval.index.length != null) {
                    lval.index.length.?.reset_usage();
                }
            },
            .select => {
                lval.select.lhs.reset_usage();
                if (lval.select.tag != null) {
                    lval.select.tag.?.reset_usage();
                }
            },
            .raw_address => std.debug.panic("compiler error: raw addresses do not have usage", .{}),
        }
    }

    pub fn calculate_lval_usage(lval: *L_Value) void {
        switch (lval.*) {
            .symbver => {
                lval.symbver.uses += 1;
                lval.symbver.symbol.uses += 1;
            },
            .dereference => lval.dereference.expr.calculate_lval_usage(),
            .index => {
                lval.index.lhs.calculate_lval_usage();
                lval.index.rhs.calculate_lval_usage();
                if (lval.index.length != null) {
                    lval.index.length.?.calculate_lval_usage();
                }
            },
            .select => {
                lval.select.lhs.calculate_lval_usage();
                if (lval.select.tag != null) {
                    lval.select.tag.?.calculate_lval_usage();
                }
            },
            .raw_address => std.debug.panic("compiler error: raw addresses do not have usage", .{}),
        }
    }
};

pub const Symbol_Version = struct {
    symbol: *symbol_.Symbol,
    def: ?*ir_.Instruction,

    uses: usize = 0,

    allocator: std.mem.Allocator,

    pub fn create_unversioned(symbol: *symbol_.Symbol, allocator: std.mem.Allocator) *Symbol_Version {
        var retval = allocator.create(Symbol_Version) catch unreachable;
        retval.symbol = symbol;
        retval.uses = 0;
        retval.def = null;
        retval.allocator = allocator;
        return retval;
    }

    pub fn deinit(self: *Symbol_Version) void {
        _ = self;
        // self.allocator.destroy(self); // TODO: Bwuh?!
    }

    fn pprint(self: ?*Symbol_Version) void {
        if (self) |symbver| {
            var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
            defer arena.deinit();
            var out = String.init(arena.allocator());
            defer out.deinit();

            out.writer().print("{s}", .{symbver.symbol.name}) catch unreachable;
            std.debug.print("{s:<10}", .{out.str()});
        } else {
            std.debug.print("<null>    ", .{});
        }
    }

    pub fn format(self: Symbol_Version, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();
        var out = String.init(arena.allocator());
        defer out.deinit();

        writer.print("{s}", .{self.symbol.name}) catch unreachable;
        // try writer.print("{s:<10}", .{out.str()});
    }

    /// Finds the last definition of a Symbol_Version in a given range of an Instruction linked-list
    pub fn find_version(self: *Symbol_Version, instr: ?*ir_.Instruction, stop: ?*ir_.Instruction) *Symbol_Version {
        var retval: *Symbol_Version = self;
        var maybe_instr = instr;
        // Go through Instruction linked-list, stop at `stop` Instruction, if it's not null.
        while (maybe_instr != null and maybe_instr != stop) : (maybe_instr = maybe_instr.?.next) {
            if (maybe_instr.?.dest != null and // instr dest exists
                maybe_instr.?.dest.?.* == .symbver and // instr dest is a symbver lvalue
                maybe_instr.?.dest.?.symbver.symbol == self.symbol // instr dest symbver symbol is this symbol
            ) {
                // remember this symbver, but keep looking to find the very latest until `stop`
                retval = maybe_instr.?.dest.?.symbver;
            }
        }
        return retval;
    }

    /// Finds a Symbol Version in a Symbol Version set, or null if not found.
    ///
    /// Two Symbol Versions are considered equivalent if they refer to the same Symbol.
    pub fn find_symbol_version_set(
        self: *Symbol_Version,
        set: *std.ArrayList(*Symbol_Version),
    ) ?*Symbol_Version {
        // Go through the set's symbvers
        for (set.items) |symbver| {
            if (symbver.symbol == self.symbol) {
                // Set element symbver has the same symbol as the symbver we're looking for
                // Return it
                return symbver;
            }
        }
        return null;
    }

    pub fn put_symbol_version_set(self: *Symbol_Version, set: *std.ArrayList(*Symbol_Version)) bool {
        for (set.items) |v| {
            if (v.symbol == self.symbol) {
                return false;
            }
        }
        set.append(self) catch unreachable;
        return true;
    }
};
