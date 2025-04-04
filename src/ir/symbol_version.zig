const std = @import("std");
const AST = @import("../ast/ast.zig").AST;
const Symbol = @import("../symbol/symbol.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Instruction = @import("../ir/instruction.zig");

const Self = @This();

symbol: *Symbol,
def: ?*Instruction,

uses: usize = 0,

allocator: std.mem.Allocator,

pub fn create_unversioned(symbol: *Symbol, allocator: std.mem.Allocator) *Self {
    var retval = allocator.create(Self) catch unreachable;
    retval.symbol = symbol;
    retval.uses = 0;
    retval.def = null;
    retval.allocator = allocator;
    return retval;
}

pub fn deinit(self: *Self) void {
    _ = self;
    // self.allocator.destroy(self); // TODO: Bwuh?!
}

fn pprint(self: ?*Self) void {
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

pub fn format(self: Self, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
    _ = options;
    _ = fmt;
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    var out = String.init(arena.allocator());
    defer out.deinit();

    writer.print("{s}", .{self.symbol.name}) catch unreachable;
    // try writer.print("{s:<10}", .{out.str()});
}

pub fn set_def(self: *Self, def: ?*Instruction) void {
    self.def = def;
    if (def) |_| {
        self.symbol.defs += 1;
    }
}

pub fn get_expanded_type(self: *Self) *AST {
    return self.symbol.expanded_type.?;
}

pub fn reset_usage(self: *Self) void {
    self.uses = 0;
    self.symbol.uses = 0;
}

pub fn increment_usage(self: *Self) void {
    self.uses += 1;
    self.symbol.uses += 1;
}

/// Finds a Symbol Version in a Symbol Version set, or null if not found.
///
/// Two Symbol Versions are considered equivalent if they refer to the same Symbol.
pub fn find_symbol_version_set(
    self: *Self,
    set: *std.ArrayList(*Self),
) ?*Self {
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

pub fn put_symbol_version_set(self: *Self, set: *std.ArrayList(*Self)) bool {
    for (set.items) |v| {
        if (v.symbol == self.symbol) {
            return false;
        }
    }
    set.append(self) catch unreachable;
    return true;
}
