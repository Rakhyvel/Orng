const std = @import("std");

const Self = @This();
allocator: std.mem.Allocator,

pub fn init(allocator: std.mem.Allocator) Self {
    return .{ .allocator = allocator };
}

pub fn run(self: Self, absolute_path: []const u8) error{FileNotFound}![]const u8 {
    std.debug.print("{s}\n", .{absolute_path});
    var file = std.fs.openFileAbsolute(absolute_path, .{}) catch return error.FileNotFound;
    defer file.close();

    const stat = file.stat() catch unreachable;
    const contents = file.readToEndAlloc(self.allocator, stat.size) catch unreachable;
    return contents;
}
