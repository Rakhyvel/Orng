const std = @import("std");
const lexer = @import("lexer.zig");
const Token = @import("token.zig").Token;
const Parser = @import("parser.zig").Parser;

pub fn main() !void {
    // Get second command line argument
    const allocator = std.heap.page_allocator;
    var args = try std.process.ArgIterator.initWithAllocator(allocator);
    _ = args.next() orelse unreachable;
    var arg = args.next() orelse {
        std.debug.print("{s}\n", .{"Usage: zig build run -- <markdown-filename>"});
        return;
    };

    // Get the path
    var path_buffer: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    const path: []u8 = try std.fs.realpath(arg, &path_buffer);

    // Open the file
    var file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    // Read in the contents of the file
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    try in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF);
    var contents = try contents_arraylist.toOwnedSlice();

    var parser = try Parser.create(contents, allocator);
    parser.parse();
    for (parser.errors.items) |err| {
        std.debug.print("file:{} error: {s}\n", .{ err.line, err.msg.str() });
    }
}
