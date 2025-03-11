const std = @import("std");
const errs_ = @import("../util/errors.zig");
const Span = @import("../util/span.zig");

const Self: type = @This();
lines: std.ArrayList([]const u8),
errors: *errs_.Errors,

pub fn init(errors: *errs_.Errors, allocator: std.mem.Allocator) Self {
    return Self{
        .lines = std.ArrayList([]const u8).init(allocator),
        .errors = errors,
    };
}

// Has to be done separately from the lexer, because the lexer might throw errors, which would need to be printed out
// However, we couldn't print out the line for the error if we did tokens and lines at the same time
// It's desirable to print the line, therefore lines must be done before tokens
pub fn run(self: *Self, contents: []const u8) error{LexerError}!std.ArrayList([]const u8) {
    var start: usize = 0;
    if (contents.len == 0) {
        self.errors.add_error(errs_.Error{ .basic = .{
            .span = Span.phony,
            .msg = "file is empty",
        } });
        return error.LexerError;
    }
    for (1..contents.len) |end| {
        if (contents[end] == '\n') {
            self.lines.append(contents[start..end]) catch unreachable;
            start = end + 1;
        }
    }
    self.lines.append(contents[start..contents.len]) catch unreachable;
    return self.lines;
}
