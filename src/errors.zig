const std = @import("std");
const token = @import("token.zig");

const TokenKind = token.TokenKind;
const Token = token.Token;
const Span = @import("span.zig").Span;

pub const Error = union(enum) {
    basic: struct {
        span: Span,
        msg: []const u8,
    },
    expectedBasicToken: struct {
        expected: []const u8,
        got: Token,
    },
    expected2Token: struct {
        expected: TokenKind,
        got: Token,
    },
    redefinition: struct {
        first_defined_span: Span,
        redefined_span: Span,
        name: []const u8,
    },
};

pub const Errors = struct {
    errors_list: std.ArrayList(Error),

    pub fn init(allocator: std.mem.Allocator) Errors {
        return .{ .errors_list = std.ArrayList(Error).init(allocator) };
    }

    pub fn deinit(self: *Errors) void {
        self.errors_list.deinit();
    }
    pub fn addError(self: *Errors, err: Error) void {
        self.errors_list.append(err) catch unreachable; // TODO: Should this try?
    }

    pub fn printErrors(self: *Errors) void {
        for (self.errors_list.items) |err| {
            // TODO: When the line map is implemented, print out line where span occurs. Do this for all spans.
            switch (err) {
                .basic => std.debug.print("{{TODO: ADD FILENAMES}}:{}:{} error: {s}\n", .{ err.basic.span.line, err.basic.span.col, err.basic.msg }),
                .expectedBasicToken => std.debug.print("{{TODO: ADD FILENAMES}}:{}:{} error: expected {s}, got `{s}`\n", .{
                    err.expectedBasicToken.got.span.line,
                    err.expectedBasicToken.got.span.col,
                    err.expectedBasicToken.expected,
                    token.reprFromTokenKind(err.expectedBasicToken.got.kind) orelse err.expectedBasicToken.got.data,
                }),
                .expected2Token => std.debug.print("{{TODO: ADD FILENAMES}}:{}:{} error: expected `{s}`, got `{s}`\n", .{
                    err.expected2Token.got.span.line,
                    err.expected2Token.got.span.col,
                    token.reprFromTokenKind(err.expected2Token.expected) orelse "identifier",
                    token.reprFromTokenKind(err.expected2Token.got.kind) orelse err.expected2Token.got.data,
                }),
                .redefinition => std.debug.print("{{TODO: ADD FILENAMES}}:{}:{} error: redefinition of symbol `{s}`\n", .{
                    err.redefinition.redefined_span.line,
                    err.redefinition.redefined_span.col,
                    err.redefinition.name,
                }),
            }
        }
    }
};
