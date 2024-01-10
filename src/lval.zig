const std = @import("std");
const ast_ = @import("ast.zig");
const ir_ = @import("ir.zig");
const symbol_ = @import("symbol.zig");
const String = @import("zig-string/zig-string.zig").String;

/// Represents different forms of l-values in an l-value tree.
pub const L_Value = union(enum) {
    /// L-Value is the address of the symbol
    symbver: *Symbol_Version,
    /// L-Value is lhs.
    dereference: struct {
        expr: *L_Value,
        size: i64,
        type: *ast_.AST,
        expanded_type: *ast_.AST,
        allocator: std.mem.Allocator,
    },
    /// L-Value is L-Value of lhs, + rhs * size
    index: struct {
        lhs: *L_Value,
        rhs: *L_Value,
        upper_bound: ?*L_Value, // Debug UB info
        size: i64,
        type: *ast_.AST,
        expanded_type: *ast_.AST,
        allocator: std.mem.Allocator,
    },
    /// L-Value is L-Value + offset
    select: struct {
        lhs: *L_Value,
        field: i128,
        offset: i64,
        type: *ast_.AST,
        expanded_type: *ast_.AST,
        tag: ?*L_Value, // Debug UB info
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

    pub fn create_dereference(lhs: *L_Value, size: i64, _type: *ast_.AST, expanded_type: *ast_.AST, allocator: std.mem.Allocator) *L_Value {
        const retval = allocator.create(L_Value) catch unreachable;
        retval.* = L_Value{ .dereference = .{
            .expr = lhs,
            .size = size,
            .type = _type,
            .expanded_type = expanded_type,
            .allocator = allocator,
        } };
        return retval;
    }

    pub fn create_index(
        lhs: *L_Value,
        rhs: *L_Value,
        upper_bound: ?*L_Value,
        size: i64,
        _type: *ast_.AST,
        expanded_type: *ast_.AST,
        allocator: std.mem.Allocator,
    ) *L_Value {
        const retval = allocator.create(L_Value) catch unreachable;
        retval.* = L_Value{ .index = .{
            .lhs = lhs,
            .rhs = rhs,
            .upper_bound = upper_bound,
            .size = size,
            .type = _type,
            .expanded_type = expanded_type,
            .allocator = allocator,
        } };
        return retval;
    }

    pub fn create_select(
        lhs: *L_Value,
        field: i128,
        offset: i64,
        _type: *ast_.AST,
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
                .type = _type,
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

    pub fn get_type(self: *L_Value) *ast_.AST {
        switch (self.*) {
            .symbver => return self.symbver.symbol._type,
            .dereference => return self.dereference.type,
            .index => return self.index.type,
            .select => return self.select.type,
        }
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
