const std = @import("std");
const errs_ = @import("errors.zig");
const span_ = @import("span.zig");

// Has to be done separately from the lexer, because the lexer might throw errors, which would need to be printed out
// However, we couldn't print out the line for the error if we did tokens and lines at the same time
// It's desirable to print the line, therefore lines must be done before tokens
pub fn get_lines(contents: []const u8, lines: *std.ArrayList([]const u8), errors: *errs_.Errors) error{LexerError}!void {
    var start: usize = 0;
    if (contents.len == 0) {
        errors.add_error(errs_.Error{ .basic = .{
            .span = span_.phony_span,
            .msg = "file is empty",
        } });
        return error.LexerError;
    }
    for (1..contents.len) |end| {
        if (contents[end] == '\n') {
            lines.append(contents[start..end]) catch unreachable;
            start = end + 1;
        }
    }
    lines.append(contents[start..contents.len]) catch unreachable;
}
