const std = @import("std");
const lexer = @import("lexer.zig");
const Token = @import("token.zig").Token;

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

    // Read in the file line by line
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var tokens = std.ArrayList(Token).init(allocator);
    var buf: [1024]u8 = undefined;
    while (try in_stream.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        _ = try lexer.getTokens(line, &tokens);
    }
    for (tokens.items) |*token| {
        std.debug.print("[{s}]:{s}\n", .{ token.data, token.repr() });
    }
}
