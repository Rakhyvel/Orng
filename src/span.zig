const std = @import("std");
const String = @import("zig-string/zig-string.zig").String;

pub const c_format = "\"{s}:{}:{}:\\n{s}\\n{s}^\"";
pub const interpreter_format = "{s}:{}:{}:\n{s}\n{s}^\n";

pub const Span = struct {
    filename: []const u8,
    line_text: []const u8, // TODO: Rename this to `line`, and `line` to `line_number`
    line: usize,
    col: usize,

    /// Prints out a line string, with quotes and arrow.
    pub fn print_debug_line(self: Span, writer: anytype, comptime format: []const u8) !void {
        var spaces = String.init(std.heap.page_allocator);
        defer spaces.deinit();

        for (1..self.col - 1) |_| {
            try spaces.insert(" ", spaces.size);
        }
        try writer.print(format, .{
            self.filename,
            self.line,
            self.col,
            try sanitize_string(self.line_text, std.heap.page_allocator),
            spaces.str(),
        });
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
fn sanitize_string(str: []const u8, allocator: std.mem.Allocator) ![]const u8 {
    var builder = String.init(allocator);
    for (str) |byte| {
        if (byte == '\\' or byte == '"') {
            try builder.insert("\\", builder.len());
        }
        const insert_me_daddy: [1]u8 = .{byte};
        try builder.insert(&insert_me_daddy, builder.len());
    }
    return (try builder.toOwned()).?;
}
