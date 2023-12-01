const ast = @import("ast.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");
const term = @import("term.zig");
const token = @import("token.zig");

const AST = ast.AST;
const TokenKind = token.TokenKind;
const Token = token.Token;
const Span = @import("span.zig").Span;

pub const Error = union(enum) {
    // General errors
    basic: struct {
        span: Span,
        msg: []const u8,
    },

    // Lexer errors
    invalid_digit: struct {
        span: Span,
        digit: u8,
        base: []const u8,
    },
    invalid_escape: struct {
        span: Span,
        digit: u8,
    },

    // Parse errors
    expectedBasicToken: struct {
        expected: []const u8,
        got: Token,
    },
    expected2Token: struct {
        expected: TokenKind,
        got: Token,
    },
    missing_close: struct {
        expected: TokenKind,
        got: Token,
        open: Token,
    },
    comptime_known: struct {
        span: Span,
        what: []const u8, // what must be compile-time known?
    },

    // Symbol
    redefinition: struct {
        first_defined_span: Span,
        redefined_span: Span,
        name: []const u8,
    },
    symbol_error: struct {
        span: Span,
        context_span: ?Span,
        name: []const u8,
        problem: []const u8,
        context_message: []const u8,
    },
    discard_marked: struct {
        span: Span,
        kind: _symbol.SymbolKind,
    },

    // Typecheck
    expected2Type: struct {
        span: Span,
        expected: *AST,
        got: *AST,
    },
    expectedType: struct {
        span: Span,
        expected: *AST,
        got: *AST,
    },
    expectedGotString: struct {
        span: Span,
        expected: *AST,
        got: []const u8,
    },
    expectedBuiltinTypeclass: struct {
        span: Span,
        expected: []const u8, // name of the type class
        got: *AST,
    },
    sum_duplicate: struct {
        span: Span,
        identifier: []const u8,
        first: Span,
    },
    member_not_in: struct {
        span: Span,
        identifier: []const u8,
        group_name: []const u8,
    },
    undeclaredIdentifier: struct {
        identifier: Token,
        scope: *_symbol.Scope,
        expected: ?*AST,
    },
    useBeforeDef: struct {
        identifier: Token,
        symbol: *_symbol.Symbol,
    },
    modifyImmutable: struct {
        identifier: Token,
        symbol: *_symbol.Symbol,
    },
    notIndexable: struct {
        span: Span,
        _type: *AST,
    },
    nonExhaustiveSum: struct {
        span: Span,
        forgotten: std.ArrayList(*AST),
    },
    mismatchCallArity: struct {
        span: Span,
        takes: usize,
        given: usize,
    },
    mismatchTupleArity: struct {
        span: Span,
        takes: usize,
        given: usize,
    },

    // Optimizer
    out_of_bounds: struct {
        span: Span,
        index: i128,
        length: usize,
    },
    negative_index: struct {
        span: Span,
        index: i128,
    },
    slice_lower_upper: struct {
        span: Span,
        lower: i128,
        upper: i128,
    },
    sum_select_inactive: struct {
        span: Span,
        active: []const u8,
        inactive: []const u8,
    },

    pub fn getSpan(self: *const Error) ?Span {
        switch (self.*) {
            .basic => return self.basic.span,

            .invalid_digit => return self.invalid_digit.span,
            .invalid_escape => return self.invalid_escape.span,

            .expectedBasicToken => return self.expectedBasicToken.got.span,
            .expected2Token => return self.expected2Token.got.span,
            .missing_close => return self.missing_close.got.span,
            .comptime_known => return self.comptime_known.span,

            .redefinition => return self.redefinition.redefined_span,
            .symbol_error => return self.symbol_error.span,
            .discard_marked => return self.discard_marked.span,

            .expected2Type => return self.expected2Type.span,
            .expectedType => return self.expectedType.span,
            .expectedBuiltinTypeclass => return self.expectedBuiltinTypeclass.span,
            .expectedGotString => return self.expectedGotString.span,
            .sum_duplicate => return self.sum_duplicate.span,
            .member_not_in => return self.member_not_in.span,
            .undeclaredIdentifier => return self.undeclaredIdentifier.identifier.span,
            .useBeforeDef => return self.useBeforeDef.identifier.span,
            .modifyImmutable => return self.modifyImmutable.identifier.span,
            .notIndexable => return self.notIndexable.span,
            .nonExhaustiveSum => return self.nonExhaustiveSum.span,
            .mismatchCallArity => return self.mismatchCallArity.span,
            .mismatchTupleArity => return self.mismatchTupleArity.span,

            .out_of_bounds => return self.out_of_bounds.span,
            .negative_index => return self.negative_index.span,
            .slice_lower_upper => return self.slice_lower_upper.span,
            .sum_select_inactive => return self.sum_select_inactive.span,
        }
    }
};

const out = std.io.getStdOut().writer();
pub const Errors = struct {
    errors_list: std.ArrayList(Error),
    allocator: std.mem.Allocator,

    pub fn init(allocator: std.mem.Allocator) Errors {
        return .{
            .errors_list = std.ArrayList(Error).init(allocator),
            .allocator = allocator,
        };
    }

    pub fn deinit(self: *Errors) void {
        self.errors_list.deinit();
    }
    pub fn addError(self: *Errors, err: Error) void {
        self.errors_list.append(err) catch unreachable;
        unreachable; // uncomment if you want to see where errors come from
    }

    pub fn printErrors(self: *Errors) !void {
        for (self.errors_list.items) |err| {
            try (term.Attr{ .bold = true }).dump(out);
            try printPrelude(err.getSpan());
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
                .comptime_known => {
                    try out.print("{s} must be compile-time known\n", .{err.comptime_known.what});
                },

                // Symbol
                .redefinition => {
                    try out.print("redefinition of symbol `{s}`\n", .{err.redefinition.name});
                },
                .symbol_error => {
                    try out.print("symbol `{s}` {s}\n", .{ err.symbol_error.name, err.symbol_error.problem });
                },
                .discard_marked => {
                    try out.print("discarded symbol marked as `{s}`\n", .{_symbol.SymbolKind.to_string(err.discard_marked.kind)});
                },

                // Typecheck
                .expected2Type => {
                    std.debug.assert(err.expected2Type.expected.* != .poison);
                    if (err.expected2Type.got.* != .poison) {
                        try out.print("expected a value of the type `", .{});
                        try err.expected2Type.expected.printType(out);
                        try out.print("`, got a value of the type `", .{}); // Tiny TODO: if got is Void, print something else
                        try err.expected2Type.got.printType(out);
                        try out.print("`\n", .{});
                    } else {
                        try out.print("expected a value of the type `", .{});
                        try err.expected2Type.expected.printType(out);
                        try out.print("`\n", .{});
                    }
                },
                .expectedType => {
                    try out.print("expected a value of the type `", .{});
                    try err.expectedType.expected.printType(out);
                    try out.print("`, got {s}\n", .{@tagName(err.expectedType.got.*)});
                },
                .expectedBuiltinTypeclass => {
                    try out.print("expected a value of an {s} type, got `", .{err.expectedBuiltinTypeclass.expected}); // just so happens to work out that all builtin type classes start with a vowel
                    try err.expectedBuiltinTypeclass.got.printType(out);
                    try out.print("`\n", .{});
                },
                .expectedGotString => {
                    std.debug.assert(err.expectedGotString.expected.* != .poison);
                    try out.print("expected a value of the type `", .{});
                    try err.expectedGotString.expected.printType(out);
                    try out.print("`, got {s}\n", .{err.expectedGotString.got});
                },
                .sum_duplicate => {
                    try out.print("duplicate sum member `{s}`\n", .{err.sum_duplicate.identifier});
                },
                .member_not_in => {
                    try out.print("member `{s}` not in {s}\n", .{ err.member_not_in.identifier, err.member_not_in.group_name });
                },
                .undeclaredIdentifier => {
                    try out.print("use of undeclared identifier `{s}`", .{err.undeclaredIdentifier.identifier.data});

                    var similar = std.ArrayList([]const u8).init(self.allocator);
                    defer similar.deinit();

                    try err.undeclaredIdentifier.scope.collect_similar(err.undeclaredIdentifier.identifier.data, &similar, err.undeclaredIdentifier.expected, self.allocator);

                    if (similar.items.len == 0) {
                        try out.print("\n", .{});
                    } else {
                        try out.print("; did you mean ", .{});
                        for (similar.items, 0..) |item, i| {
                            if (i == similar.items.len - 1) {
                                try out.print("`{s}`", .{item});
                            } else if (i < similar.items.len - 2) {
                                try out.print("`{s}`, ", .{item});
                            } else {
                                try out.print("`{s}`, or ", .{item});
                            }
                        }
                        try out.print("?\n", .{});
                    }
                },
                .useBeforeDef => {
                    try out.print("use of identifier `{s}` before its definition\n", .{err.useBeforeDef.identifier.data});
                },
                .modifyImmutable => {
                    try out.print("cannot modify non-mutable symbol `{s}`\n", .{err.modifyImmutable.identifier.data});
                },
                .notIndexable => {
                    try out.print("the type `", .{});
                    try err.notIndexable._type.printType(out);
                    try out.print("` is not indexable\n", .{});
                },
                .nonExhaustiveSum => {
                    try out.print("match over sum type is not exhaustive\n", .{});
                },
                .mismatchCallArity => {
                    try out.print("function takes {} parameter{s}, {} argument{s} given\n", .{
                        err.mismatchCallArity.takes,
                        if (err.mismatchCallArity.takes == 1) "" else "s",
                        err.mismatchCallArity.given,
                        if (err.mismatchCallArity.given == 1) "" else "s",
                    });
                },
                .mismatchTupleArity => {
                    try out.print("expected tuple of {} term{s}, got tuple of {} term{s}\n", .{
                        err.mismatchTupleArity.takes,
                        if (err.mismatchTupleArity.takes == 1) "" else "s",
                        err.mismatchTupleArity.given,
                        if (err.mismatchTupleArity.given == 1) "" else "s",
                    });
                },

                // Optimizer
                .out_of_bounds => {
                    try out.print("index out of bounds; index {}, length {}\n", .{ err.out_of_bounds.index, err.out_of_bounds.length });
                },
                .negative_index => {
                    try out.print("index is negative; index {}\n", .{err.negative_index.index});
                },
                .slice_lower_upper => {
                    try out.print("subslice lower bounds is greater than upper bound; lower {}, upper {}\n", .{ err.slice_lower_upper.lower, err.slice_lower_upper.upper });
                },
                .sum_select_inactive => {
                    try out.print("access of sum field '{s}' while field '{s}' is active\n", .{ err.sum_select_inactive.inactive, err.sum_select_inactive.active });
                },
            }
            try (term.Attr{ .bold = false }).dump(out);
            try printEpilude(err.getSpan());

            // Extra info
            switch (err) {
                .missing_close => {
                    try (term.Attr{ .bold = true }).dump(out);
                    try print_note_prelude(err.missing_close.open.span);
                    try (term.Attr{ .bold = true }).dump(out);
                    try out.print("opening `{s}` here\n", .{token.reprFromTokenKind(err.missing_close.open.kind) orelse err.missing_close.open.data});
                    try (term.Attr{ .bold = false }).dump(out);
                    try printEpilude(err.missing_close.open.span);
                },
                .comptime_known => {
                    try (term.Attr{ .bold = true }).dump(out);
                    try print_note_prelude(err.comptime_known.span);
                    try (term.Attr{ .bold = true }).dump(out);
                    try out.print("consider wrapping with `comptime`\n", .{});
                    try (term.Attr{ .bold = false }).dump(out);
                },
                .redefinition => {
                    if (err.redefinition.first_defined_span.line != 0) { // Don't print redefinitions for placs that don't exist
                        try (term.Attr{ .bold = true }).dump(out);
                        try print_note_prelude(err.redefinition.first_defined_span);
                        try (term.Attr{ .bold = true }).dump(out);
                        try out.print("other definition of `{s}` here\n", .{err.redefinition.name});
                        try (term.Attr{ .bold = false }).dump(out);
                        try printEpilude(err.redefinition.first_defined_span);
                    }
                },
                .symbol_error => {
                    if (err.symbol_error.context_span != null) {
                        try (term.Attr{ .bold = true }).dump(out);
                        try print_note_prelude(err.symbol_error.context_span.?);
                        try (term.Attr{ .bold = true }).dump(out);
                        try out.print("{s}\n", .{err.symbol_error.context_message});
                        try (term.Attr{ .bold = false }).dump(out);
                        try printEpilude(err.symbol_error.context_span.?);
                    }
                },
                .sum_duplicate => {
                    try (term.Attr{ .bold = true }).dump(out);
                    try print_note_prelude(err.sum_duplicate.first);
                    try (term.Attr{ .bold = true }).dump(out);
                    try out.print("other definition of `{s}` here\n", .{err.sum_duplicate.identifier});
                    try (term.Attr{ .bold = false }).dump(out);
                    try printEpilude(err.sum_duplicate.first);
                },
                .nonExhaustiveSum => {
                    for (err.nonExhaustiveSum.forgotten.items) |_type| {
                        try (term.Attr{ .bold = true }).dump(out);
                        try print_note_prelude(_type.getToken().span);
                        try (term.Attr{ .bold = true }).dump(out);
                        try out.print("term not handled: `{s}`\n", .{_type.annotation.pattern.getToken().data});
                        try (term.Attr{ .bold = false }).dump(out);
                        try printEpilude(_type.getToken().span);
                    }
                },
                else => {},
            }
        }
    }

    fn printPrelude(maybe_span: ?Span) !void {
        if (maybe_span) |span| {
            if (span.line > 0 and span.col > 0) {
                try out.print("{s}:{}:{}: ", .{ span.filename, span.line, span.col });
            } else {
                try out.print("{s}: ", .{span.filename});
            }
        }
        try term.outputColor(term.Attr{ .fg = .red, .bold = true }, "error: ", out);
    }

    fn print_note_prelude(maybe_span: ?Span) !void {
        if (maybe_span) |span| {
            try out.print("{s}:{}:{}: ", .{ span.filename, span.line, span.col });
        }
        try term.outputColor(term.Attr{ .fg = .cyan, .bold = true }, "note: ", out);
    }

    fn printEpilude(maybe_span: ?Span) !void {
        if (maybe_span) |old_span| {
            const span = old_span;
            if (span.line == 0) {
                return;
            } else if (span.line_text.len > 0) {
                try out.print("{s}\n", .{span.line_text});
            }
            var i: usize = 2;
            while (i < span.col) : (i += 1) {
                try out.print(" ", .{});
            }
            try term.outputColor(term.Attr{ .fg = .green, .bold = true }, "^\n", out);
        }
    }
};
