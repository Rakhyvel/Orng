const std = @import("std");

pub const Read_File = struct {
    const Self = @This();
    allocator: std.mem.Allocator,

    pub fn init(allocator: std.mem.Allocator) Self {
        return .{ .allocator = allocator };
    }

    pub fn run(self: Self, absolute_path: []const u8) error{ FileNotFound, CompileError }![]const u8 {
        // Open the file
        var file = std.fs.openFileAbsolute(absolute_path, .{}) catch |err| switch (err) {
            error.FileNotFound => return error.FileNotFound,
            else => return error.CompileError,
        };
        defer file.close();

        const stat = file.stat() catch return error.CompileError;
        const uid = stat.mtime;
        _ = uid;

        // Read in the contents of the file
        var buf_reader = std.io.bufferedReader(file.reader());
        var in_stream = buf_reader.reader();
        var contents_arraylist = std.ArrayList(u8).init(self.allocator);
        defer contents_arraylist.deinit();
        in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF) catch unreachable;
        const contents = contents_arraylist.toOwnedSlice() catch unreachable;

        return contents;
    }
};
