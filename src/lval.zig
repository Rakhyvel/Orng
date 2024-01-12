const std = @import("std");
const ast_ = @import("ast.zig");
const ir_ = @import("ir.zig");
const symbol_ = @import("symbol.zig");
const String = @import("zig-string/zig-string.zig").String;

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

    fn create_symbver(symbver: *Symbol_Version, allocator: std.mem.Allocator) *L_Value {
        const retval = allocator.create(L_Value) catch unreachable;
        retval.* = L_Value{ .symbver = symbver };
        return retval;
    }

    pub fn create_unversioned_symbver(symbol: *symbol_.Symbol, allocator: std.mem.Allocator) *L_Value {
        const retval = L_Value.create_symbver(Symbol_Version.create_unversioned(symbol, allocator), allocator);
        return retval;
    }

    pub fn create_dereference(lhs: *L_Value, expanded_type: *ast_.AST, allocator: std.mem.Allocator) *L_Value {
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

    pub fn create_index(
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

    pub fn create_select(
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

    pub fn deinit(self: *L_Value) void {
        switch (self.*) {
            .symbver => self.symbver.deinit(),
            .dereference => self.dereference.allocator.destroy(self),
            .index => self.index.allocator.destroy(self),
            .select => self.select.allocator.destroy(self),
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

    pub fn extract_symbver(self: *L_Value) *Symbol_Version {
        return switch (self.*) {
            .symbver => self.symbver,
            .dereference => self.dereference.expr.extract_symbver(),
            .index => self.index.lhs.extract_symbver(),
            .select => self.select.lhs.extract_symbver(),
        };
    }

    pub fn sizeof(self: *L_Value) i64 {
        return self.get_expanded_type().sizeof();
    }

    pub fn alignof(self: *L_Value) i64 {
        return self.get_expanded_type().alignof();
    }

    pub fn get_expanded_type(self: *L_Value) *ast_.AST {
        switch (self.*) {
            .symbver => return self.symbver.symbol.expanded_type.?,
            .dereference => return self.dereference.expanded_type,
            .index => return self.index.expanded_type,
            .select => return self.select.expanded_type,
        }
    }

    pub fn precedence(self: *L_Value) i64 {
        return switch (self.*) {
            .symbver => ir_.Kind.precedence(ir_.Kind.load_symbol),
            .dereference => 2,
            .index => 2,
            .select => 1,
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
        }
    }

    pub fn calculate_usage(lval: *L_Value) void {
        switch (lval.*) {
            .symbver => {
                lval.symbver.uses += 1;
                lval.symbver.symbol.uses += 1;
            },
            .dereference => lval.dereference.expr.calculate_usage(),
            .index => {
                lval.index.lhs.calculate_usage();
                lval.index.rhs.calculate_usage();
                if (lval.index.length != null) {
                    lval.index.length.?.calculate_usage();
                }
            },
            .select => {
                lval.select.lhs.calculate_usage();
                if (lval.select.tag != null) {
                    lval.select.tag.?.calculate_usage();
                }
            },
        }
    }
};

pub const Symbol_Version = struct {
    symbol: *symbol_.Symbol,
    version: ?u64,
    def: ?*ir_.IR,

    uses: usize = 0,

    allocator: std.mem.Allocator,

    pub fn create_unversioned(symbol: *symbol_.Symbol, allocator: std.mem.Allocator) *Symbol_Version {
        var retval = allocator.create(Symbol_Version) catch unreachable;
        retval.symbol = symbol;
        retval.uses = 0;
        retval.version = null;
        retval.def = null;
        retval.allocator = allocator;
        return retval;
    }

    pub fn deinit(self: *Symbol_Version) void {
        _ = self;
        // self.allocator.destroy(self); // TODO: Bwuh?!
    }

    pub fn make_unique(self: *Symbol_Version) void {
        if (self.version == null) {
            self.version = self.symbol.versions;
            self.symbol.versions += 1;
        }
    }

    fn pprint(self: ?*Symbol_Version) void {
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

    pub fn format(self: Symbol_Version, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();
        var out = String.init(arena.allocator());
        defer out.deinit();

        writer.print("{s}_{?}", .{ self.symbol.name, self.version }) catch unreachable;
        // try writer.print("{s:<10}", .{out.str()});
    }

    /// Finds the last definition of a Symbol_Version in a given range of an IR linked-list
    pub fn find_version(self: *Symbol_Version, ir: ?*ir_.IR, stop: ?*ir_.IR) *Symbol_Version {
        var retval: *Symbol_Version = self;
        var maybe_ir = ir;
        // Go through IR linked-list, stop at `stop` IR, if it's not null.
        while (maybe_ir != null and maybe_ir != stop) : (maybe_ir = maybe_ir.?.next) {
            if (maybe_ir.?.dest != null and // ir dest exists
                maybe_ir.?.dest.?.* == .symbver and // ir dest is a symbver lvalue
                maybe_ir.?.dest.?.symbver.symbol == self.symbol // ir dest symbver symbol is this symbol
            ) {
                // remember this symbver, but keep looking to find the very latest until `stop`
                retval = maybe_ir.?.dest.?.symbver;
            }
        }
        return retval;
    }

    /// Finds a Symbol Version in a Symbol Version set, or null if not found.
    ///
    /// Two Symbol Versions are considered equivalent if they refer to the same Symbol.
    pub fn find_symbol_version_set(self: *Symbol_Version, set: *std.ArrayList(*Symbol_Version)) ?*Symbol_Version {
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
