const std = @import("std");
const String = @import("zig-string/zig-string.zig").String;

pub const c_format = "\"{s}:{}:{}:\\n{s}\\n{s}^\"";
pub const interpreter_format = "{s}:{}:{}:\n{s}\n{s}^\n";

pub const phony_span = Span{ .filename = "", .line_text = "", .line = 0, .col = 0 };

pub const Span = struct {
    filename: []const u8,
    line_text: []const u8, // TODO: Rename this to `line`, and `line` to `line_number`
    line: usize,
    col: usize,

    /// Prints out a line string, with quotes and arrow.
    pub fn print_debug_line(self: Span, writer: anytype, comptime span_format: []const u8) !void {
        var spaces = String.init(std.heap.page_allocator);
        defer spaces.deinit();

        for (1..self.col - 1) |_| {
            spaces.insert(" ", spaces.size) catch unreachable;
        }
        try writer.print(span_format, .{
            self.filename,
            self.line,
            self.col,
            sanitize_string(self.line_text, std.heap.page_allocator),
            spaces.str(),
        });
    }

    pub fn pprint(self: Span, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        try out.writer().print("{s}:{}:{}", .{ self.filename, self.line, self.col });

        return (try out.toOwned()).?;
    }

    pub fn format(self: Span, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }
};

/// Sanitizes a string, escaping proper characters.
///
/// This is needed so that string escapes in Orng do not escape in the generate C source.
///
/// For example:
///     let str = some_function("You better \n sanitize me!")
///
/// Would produce an error diagnostic in debug mode, which needs to escape the `\` correctly so
/// that the error shown to the user is identical to the text in the file.
fn sanitize_string(str: []const u8, allocator: std.mem.Allocator) []const u8 {
    var builder = String.init(allocator);
    for (str) |byte| {
        if (byte == '\\' or byte == '"') {
            builder.insert("\\", builder.len()) catch unreachable;
        }
        const insert_me_daddy: [1]u8 = .{byte};
        builder.insert(&insert_me_daddy, builder.len()) catch unreachable;
    }
    return (builder.toOwned() catch unreachable).?;
}
