const ast = @import("ast.zig");
const std = @import("std");
const token = @import("token.zig");

const AST = ast.AST;
const TokenKind = token.TokenKind;
const Token = token.Token;
const Span = @import("span.zig").Span;

pub const Stage = enum {
    tokenization,
    layout,
    parsing,
    symbolTree,
    typecheck,
    ir,
    codegen,
};

pub const Error = union(enum) {
    basic: struct {
        span: Span,
        msg: []const u8,
        stage: Stage,
    },
    basicNoSpan: struct {
        msg: []const u8,
        stage: Stage,
    },
    expectedBasicToken: struct {
        expected: []const u8,
        got: Token,
        stage: Stage,
    },
    expected2Token: struct {
        expected: TokenKind,
        got: Token,
        stage: Stage,
    },
    redefinition: struct {
        first_defined_span: Span,
        redefined_span: Span,
        name: []const u8,
        stage: Stage,
    },
    expected2Type: struct {
        span: Span,
        expected: *AST,
        got: *AST,
        stage: Stage,
    },

    pub fn getStage(self: *const Error) Stage {
        switch (self.*) {
            .basic => return self.basic.stage,
            .basicNoSpan => return self.basicNoSpan.stage,
            .expectedBasicToken => return self.expectedBasicToken.stage,
            .expected2Token => return self.expected2Token.stage,
            .redefinition => return self.redefinition.stage,
            .expected2Type => return self.expected2Type.stage,
        }
    }
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
                .basicNoSpan => std.debug.print("error: {s}\n", .{err.basicNoSpan.msg}),
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
                .expected2Type => {
                    std.debug.print("{{TODO: ADD FILENAMES}}:{}:{} error: expected `", .{
                        err.expected2Type.span.line,
                        err.expected2Type.span.col,
                    });
                    err.expected2Type.expected.printType();
                    std.debug.print("`, got `", .{});
                    err.expected2Type.got.printType();
                    std.debug.print("`\n", .{});
                },
            }
        }
    }
};
