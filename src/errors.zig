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
    // General errors
    basic: struct {
        span: Span,
        msg: []const u8,
        stage: Stage,
    },

    // Lexer errors
    invalid_digit: struct {
        span: Span,
        digit: u8,
        base: []const u8,
        stage: Stage,
    },
    invalid_escape: struct {
        span: Span,
        digit: u8,
        stage: Stage,
    },

    // Parse errors
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
    missing_close: struct {
        expected: TokenKind,
        got: Token,
        open: Token,
        stage: Stage,
    },

    // Symbol
    redefinition: struct {
        first_defined_span: Span,
        redefined_span: Span,
        name: []const u8,
        stage: Stage,
    },

    // Typecheck
    expected2Type: struct {
        span: Span,
        expected: *AST,
        got: *AST,
        stage: Stage,
    },
    expectedType: struct {
        span: Span,
        expected: *AST,
        got: *AST,
        stage: Stage,
    },
    sum_duplicate: struct {
        span: Span,
        identifier: []const u8,
        first: Span,
        stage: Stage,
    },
    member_not_in: struct {
        span: Span,
        identifier: []const u8,
        group_name: []const u8,
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

            .invalid_digit => return self.invalid_digit.stage,
            .invalid_escape => return self.invalid_escape.stage,

            .expectedBasicToken => return self.expectedBasicToken.stage,
            .expected2Token => return self.expected2Token.stage,
            .missing_close => return self.missing_close.stage,

            .redefinition => return self.redefinition.stage,
            .expected2Type => return self.expected2Type.stage,
            .expectedType => return self.expectedType.stage,
            .sum_duplicate => return self.sum_duplicate.stage,
            .member_not_in => return self.member_not_in.stage,
            .undeclaredIdentifier => return self.undeclaredIdentifier.stage,
            .useBeforeDef => return self.useBeforeDef.stage,
            .modifyImmutable => return self.modifyImmutable.stage,
        }
    }

    pub fn getSpan(self: *const Error) ?Span {
        switch (self.*) {
            .basic => return self.basic.span,

            .invalid_digit => return self.invalid_digit.span,
            .invalid_escape => return self.invalid_escape.span,

            .expectedBasicToken => return self.expectedBasicToken.got.span,
            .expected2Token => return self.expected2Token.got.span,
            .missing_close => return self.missing_close.got.span,

            .redefinition => return self.redefinition.redefined_span,
            .expected2Type => return self.expected2Type.span,
            .expectedType => return self.expectedType.span,
            .sum_duplicate => return self.sum_duplicate.span,
            .member_not_in => return self.member_not_in.span,
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
                // General errors
                .basic => try out.print("{s}\n", .{err.basic.msg}),

                // Lexer errors
                .invalid_digit => try out.print("'{c}' is not a valid {s} digit\n", .{ err.invalid_digit.digit, err.invalid_digit.base }),
                .invalid_escape => try out.print("invalid escape sequence '\\{c}'\n", .{err.invalid_escape.digit}),

                // Parser errors
                .expectedBasicToken => try out.print("expected {s}, got `{s}`\n", .{
                    err.expectedBasicToken.expected,
                    token.reprFromTokenKind(err.expectedBasicToken.got.kind) orelse err.expectedBasicToken.got.data,
                }),
                .expected2Token => try out.print("expected `{s}`, got `{s}`\n", .{
                    token.reprFromTokenKind(err.expected2Token.expected) orelse "identifier",
                    token.reprFromTokenKind(err.expected2Token.got.kind) orelse err.expected2Token.got.data,
                }),
                .missing_close => {
                    try out.print("expected closing `{s}` to match opening `{s}` here, got `{s}`\n", .{
                        token.reprFromTokenKind(err.missing_close.expected) orelse "",
                        token.reprFromTokenKind(err.missing_close.open.kind) orelse err.missing_close.open.data,
                        token.reprFromTokenKind(err.missing_close.got.kind) orelse err.missing_close.got.data,
                    });
                },

                // Symbol
                .redefinition => {
                    try out.print("redefinition of symbol `{s}`\n", .{err.redefinition.name});
                },

                // Typecheck
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
                    try out.print("`, got {s}\n", .{@tagName(err.expectedType.got.*)});
                },
                .sum_duplicate => {
                    try out.print("duplicate sum member `{s}`\n", .{err.sum_duplicate.identifier});
                },
                .member_not_in => {
                    try out.print("member `{s}` not in {s}\n", .{ err.member_not_in.identifier, err.member_not_in.group_name });
                },
                .undeclaredIdentifier => {
                    try out.print("use of undeclared identifier `{s}`\n", .{err.undeclaredIdentifier.identifier.data});
                },
                .useBeforeDef => {
                    try out.print("use of identifier `{s}` before its definition\n", .{err.useBeforeDef.identifier.data});
                },
                .modifyImmutable => {
                    try out.print("cannot modify non-mutable symbol `{s}`\n", .{err.modifyImmutable.identifier.data});
                },
            }
            try (term.Attr{ .bold = false }).dump(out);
            try printEpilude(err.getSpan(), lines);

            // Extra info
            switch (err) {
                .missing_close => {
                    try (term.Attr{ .bold = true }).dump(out);
                    try print_note_prelude(err.missing_close.open.span, filename);
                    try (term.Attr{ .bold = true }).dump(out);
                    try out.print("opening `{s}` here\n", .{token.reprFromTokenKind(err.missing_close.open.kind) orelse err.missing_close.open.data});
                    try (term.Attr{ .bold = false }).dump(out);
                    try printEpilude(err.missing_close.open.span, lines);
                },
                .redefinition => {
                    if (err.redefinition.first_defined_span.line != 0) { // Don't print redefinitions for placs that don't exist
                        try (term.Attr{ .bold = true }).dump(out);
                        try print_note_prelude(err.redefinition.first_defined_span, filename);
                        try (term.Attr{ .bold = true }).dump(out);
                        try out.print("other definition of `{s}` here\n", .{err.redefinition.name});
                        try (term.Attr{ .bold = false }).dump(out);
                        try printEpilude(err.redefinition.first_defined_span, lines);
                    }
                },
                .sum_duplicate => {
                    try (term.Attr{ .bold = true }).dump(out);
                    try print_note_prelude(err.sum_duplicate.first, filename);
                    try (term.Attr{ .bold = true }).dump(out);
                    try out.print("other definition of `{s}` here\n", .{err.sum_duplicate.identifier});
                    try (term.Attr{ .bold = false }).dump(out);
                    try printEpilude(err.sum_duplicate.first, lines);
                },
                else => {},
            }
        }
    }

    fn printPrelude(maybe_span: ?Span, filename: []const u8) !void {
        if (maybe_span) |span| {
            if (span.line > 0 and span.col > 0) {
                try out.print("{s}:{}:{}: ", .{ filename, span.line, span.col });
            } else {
                try out.print("{s}: ", .{filename});
            }
        }
        try term.outputColor(term.Attr{ .fg = .red, .bold = true }, "error: ", out);
    }

    fn print_note_prelude(maybe_span: ?Span, filename: []const u8) !void {
        if (maybe_span) |span| {
            try out.print("{s}:{}:{}: ", .{ filename, span.line, span.col });
        }
        try term.outputColor(term.Attr{ .fg = .cyan, .bold = true }, "note: ", out);
    }

    fn printEpilude(maybe_span: ?Span, lines: *std.ArrayList([]const u8)) !void {
        if (maybe_span) |old_span| {
            var span = old_span;
            if (span.line == 0) {
                return;
            } else if (lines.items.len + 1 > span.line) {
                try out.print("{s}\n", .{lines.items[span.line - 1]});
            } else {
                try out.print("{s}\n", .{lines.items[lines.items.len - 1]});
                span.col = lines.items[lines.items.len - 1].len + 1;
            }
            var i: usize = 2;
            while (i < span.col) : (i += 1) {
                try out.print(" ", .{});
            }
            try term.outputColor(term.Attr{ .fg = .green, .bold = true }, "^\n", out);
        }
    }
};
