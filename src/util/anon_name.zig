const std = @import("std");

var num_anons: usize = 0;
pub fn next_anon_name(class: []const u8, allocator: std.mem.Allocator) []const u8 {
    defer num_anons += 1;
    var out = std.array_list.Managed(u8).init(allocator);
    defer out.deinit();
    out.print("{s}__{}", .{ class, num_anons }) catch unreachable;
    return out.toOwnedSlice() catch unreachable;
}
