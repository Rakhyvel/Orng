const std = @import("std");

pub fn List_Printer(Elem: type) type {
    return struct {
        list: *const std.array_list.Managed(*Elem),
        pub fn format(self: *const @This(), writer: *std.io.Writer) !void {
            try writer.print("[", .{});
            for (self.list.items, 0..) |item, i| {
                try writer.print("{f}", .{item});
                if (i < self.list.items.len -| 1) {
                    try writer.print(", ", .{});
                }
            }
            try writer.print("]", .{});
        }
    };
}
