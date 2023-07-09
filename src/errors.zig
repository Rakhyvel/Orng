const ast = @import("ast.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");
const term = @import("term.zig");
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
    expectedType: struct {
        span: Span,
        expected: *AST,
        stage: Stage,
    },
    undeclaredIdentifier: struct {
        identifier: Token,
        stage: Stage,
    },
    useBeforeDef: struct {
        identifier: Token,
        symbol: *_symbol.Symbol,
        stage: Stage,
    },
    modifyImmutable: struct {
        identifier: Token,
        symbol: *_symbol.Symbol,
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
            .expectedType => return self.expectedType.stage,
            .undeclaredIdentifier => return self.undeclaredIdentifier.stage,
            .useBeforeDef => return self.useBeforeDef.stage,
            .modifyImmutable => return self.modifyImmutable.stage,
        }
    }

    pub fn getSpan(self: *const Error) ?Span {
        switch (self.*) {
            .basic => return self.basic.span,
            .basicNoSpan => return null,
            .expectedBasicToken => return self.expectedBasicToken.got.span,
            .expected2Token => return self.expected2Token.got.span,
            .redefinition => return self.redefinition.redefined_span,
            .expected2Type => return self.expected2Type.span,
            .expectedType => return self.expectedType.span,
            .undeclaredIdentifier => return self.undeclaredIdentifier.identifier.span,
            .useBeforeDef => return self.useBeforeDef.identifier.span,
            .modifyImmutable => return self.modifyImmutable.identifier.span,
        }
    }
};

const out = std.io.getStdOut().writer();
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

    pub fn printErrors(self: *Errors, lines: *std.ArrayList([]const u8), filename: []const u8) !void {
        for (self.errors_list.items) |err| {
            try (term.Attr{ .bold = true }).dump(out);
            try printPrelude(err.getSpan(), filename);
            try (term.Attr{ .bold = true }).dump(out);
            switch (err) {
                .basic => try out.print("{s}\n", .{err.basic.msg}),
                .basicNoSpan => try out.print("{s}\n", .{err.basicNoSpan.msg}),
                .expectedBasicToken => try out.print("expected {s}, got `{s}`\n", .{
                    err.expectedBasicToken.expected,
                    token.reprFromTokenKind(err.expectedBasicToken.got.kind) orelse err.expectedBasicToken.got.data,
                }),
                .expected2Token => try out.print("expected `{s}`, got `{s}`\n", .{
                    token.reprFromTokenKind(err.expected2Token.expected) orelse "identifier",
                    token.reprFromTokenKind(err.expected2Token.got.kind) orelse err.expected2Token.got.data,
                }),
                .redefinition => try out.print("redefinition of symbol `{s}`\n", .{
                    err.redefinition.name,
                }),
                .expected2Type => {
                    try out.print("expected a value of the type `", .{});
                    try err.expected2Type.expected.printType(out);
                    try out.print("`, got a value of the type `", .{});
                    try err.expected2Type.got.printType(out);
                    try out.print("`\n", .{});
                },
                .expectedType => {
                    try out.print("expected a value of the type `", .{});
                    try err.expectedType.expected.printType(out);
                    try out.print("`, got a type-less statement\n", .{});
                },
                .undeclaredIdentifier => {
                    try out.print("use of undeclared identifier `{s}`\n", .{err.undeclaredIdentifier.identifier.data});
                },
                .useBeforeDef => {
                    try out.print("use of identifier `{s}` before its definition\n", .{err.useBeforeDef.identifier.data});
                },
                .modifyImmutable => {
                    try out.print("attempt to modify non-mutable symbol `{s}`\n", .{err.modifyImmutable.identifier.data});
                },
            }
            try (term.Attr{ .bold = false }).dump(out);
            try printEpilude(err.getSpan(), lines);
        }
    }

    fn printPrelude(maybe_span: ?Span, filename: []const u8) !void {
        if (maybe_span) |span| {
            try out.print("{s}:{}:{}: ", .{ filename, span.line, span.col });
        }
        try term.outputColor(term.Attr{ .fg = .red, .bold = true }, "error: ", out);
    }

    fn printEpilude(maybe_span: ?Span, lines: *std.ArrayList([]const u8)) !void {
        if (maybe_span) |span| {
            try out.print("{s}\n", .{lines.items[span.line - 1]});
            var i: usize = 2;
            while (i < span.col) : (i += 1) {
                try out.print(" ", .{});
            }
            try term.outputColor(term.Attr{ .fg = .green, .bold = true }, "^\n", out);
        }
    }
};
