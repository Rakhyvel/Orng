///! Handles interned strings. These are required mainly for the interpreter, since strings conceptually are a slice
/// referring to some piece of backing data. The interned string set per module is where the backing text data is
/// stored.
const std = @import("std");

const Self: type = @This();

pub const String_Idx: type = struct {
    module_uid: u32,
    string_idx: u32,
};

uid: u32,
interned_strings: std.ArrayList([]const u8),

pub fn init(uid: u32, allocator: std.mem.Allocator) Self {
    return Self{
        .uid = uid,
        .interned_strings = std.ArrayList([]const u8).init(allocator),
    };
}

pub fn add(self: *Self, str: []const u8, uid: u32) String_Idx {
    std.debug.assert(uid == self.uid);
    for (0..self.interned_strings.items.len) |i| {
        const item = self.interned_strings.items[i];
        if (std.mem.eql(u8, item, str)) {
            return .{ .module_uid = self.uid, .string_idx = @as(u32, @intCast(i)) };
        }
    }
    // sanitized_str must not be in set, add it
    const idx: u32 = @intCast(self.interned_strings.items.len);
    self.interned_strings.append(str) catch unreachable;
    return .{ .module_uid = self.uid, .string_idx = idx };
}

pub fn merge(self: *Self, other: *const Self) void {
    for (0..other.interned_strings.items) |i| {
        _ = self.add(other.interned_strings.items[i]);
    }
}

pub fn items(self: *const Self) []const []const u8 {
    return self.interned_strings.items;
}
