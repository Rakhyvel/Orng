const std = @import("std");
const ast_ = @import("ast.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");
const term_ = @import("term.zig");
const token_ = @import("token.zig");

pub const Error = union(enum) {
    // General errors
    basic: struct {
        span: span_.Span,
        msg: []const u8,
    },

    // Lexer errors
    invalid_digit: struct {
        span: span_.Span,
        digit: u8,
        base: []const u8,
    },
    invalid_escape: struct {
        span: span_.Span,
        digit: u8,
    },

    // Parse errors
    expectedBasicToken: struct {
        expected: []const u8,
        got: token_.Token,
    },
    expected2Token: struct {
        expected: token_.TokenKind,
        got: token_.Token,
    },
    missing_close: struct {
        expected: token_.TokenKind,
        got: token_.Token,
        open: token_.Token,
    },
    comptime_known: struct {
        span: span_.Span,
        what: []const u8, // what must be compile-time known?
    },
    unrecognized_builtin: struct {
        span: span_.Span,
        what: []const u8, // what's unrecognized?
    },

    // Symbol
    redefinition: struct {
        first_defined_span: span_.Span,
        redefined_span: span_.Span,
        name: []const u8,
    },
    symbol_error: struct {
        span: span_.Span,
        context_span: ?span_.Span,
        name: []const u8,
        problem: []const u8,
        context_message: []const u8,
    },
    discard_marked: struct {
        span: span_.Span,
        kind: symbol_.SymbolKind,
    },

    // Typecheck
    expected2Type: struct {
        span: span_.Span,
        expected: *ast_.AST,
        got: *ast_.AST,
    },
    expectedType: struct {
        span: span_.Span,
        expected: *ast_.AST,
        got: *ast_.AST,
    },
    expectedGotString: struct {
        span: span_.Span,
        expected: *ast_.AST,
        got: []const u8,
    },
    expectedBuiltinTypeclass: struct {
        span: span_.Span,
        expected: []const u8, // name of the type class
        got: *ast_.AST,
    },
    sum_duplicate: struct {
        span: span_.Span,
        identifier: []const u8,
        first: span_.Span,
    },
    member_not_in: struct {
        span: span_.Span,
        identifier: []const u8,
        group_name: []const u8,
    },
    undeclaredIdentifier: struct {
        identifier: token_.Token,
        expected: ?*ast_.AST,
    },
    comptime_access_runtime: struct {
        identifier: token_.Token,
    },
    inner_fn_access_runtime: struct {
        identifier: token_.Token,
    },
    useBeforeDef: struct {
        identifier: token_.Token,
    },
    modifyImmutable: struct {
        identifier: token_.Token,
    },
    notIndexable: struct {
        span: span_.Span,
        _type: *ast_.AST,
    },
    nonExhaustiveSum: struct {
        span: span_.Span,
        forgotten: std.ArrayList(*ast_.AST),
    },
    mismatchCallArity: struct {
        span: span_.Span,
        takes: usize,
        given: usize,
    },
    mismatchTupleArity: struct {
        span: span_.Span,
        takes: usize,
        given: usize,
    },
    no_default: struct {
        span: span_.Span,
        _type: *ast_.AST,
    },

    // Optimizer
    out_of_bounds: struct {
        span: span_.Span,
        index: i128,
        length: usize,
    },
    negative_index: struct {
        span: span_.Span,
        index: i128,
    },
    slice_lower_upper: struct {
        span: span_.Span,
        lower: i128,
        upper: i128,
    },
    sum_select_inactive: struct {
        span: span_.Span,
        active: []const u8,
        inactive: []const u8,
    },

    pub fn getSpan(self: *const Error) ?span_.Span {
        switch (self.*) {
            .basic => return self.basic.span,

            .invalid_digit => return self.invalid_digit.span,
            .invalid_escape => return self.invalid_escape.span,

            .expectedBasicToken => return self.expectedBasicToken.got.span,
            .expected2Token => return self.expected2Token.got.span,
            .missing_close => return self.missing_close.got.span,
            .comptime_known => return self.comptime_known.span,
            .unrecognized_builtin => return self.unrecognized_builtin.span,

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
            .comptime_access_runtime => return self.comptime_access_runtime.identifier.span,
            .inner_fn_access_runtime => return self.inner_fn_access_runtime.identifier.span,
            .useBeforeDef => return self.useBeforeDef.identifier.span,
            .modifyImmutable => return self.modifyImmutable.identifier.span,
            .notIndexable => return self.notIndexable.span,
            .nonExhaustiveSum => return self.nonExhaustiveSum.span,
            .mismatchCallArity => return self.mismatchCallArity.span,
            .mismatchTupleArity => return self.mismatchTupleArity.span,
            .no_default => return self.no_default.span,

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
        // unreachable; // uncomment if you want to see where errors come from
    }

    pub fn printErrors(self: *Errors) !void {
        for (self.errors_list.items) |err| {
            try (term_.Attr{ .bold = true }).dump(out);
            try printPrelude(err.getSpan());
            try (term_.Attr{ .bold = true }).dump(out);
            try print_main_error(err, self.allocator);
            try (term_.Attr{ .bold = false }).dump(out);
            try printEpilude(err.getSpan());
            try print_extra_info(err);
        }
    }

    fn print_main_error(err: Error, allocator: std.mem.Allocator) !void {
        _ = allocator;
        switch (err) {
            // General errors
            .basic => try out.print("{s}\n", .{err.basic.msg}),

            // Lexer errors
            .invalid_digit => try out.print("'{c}' is not a valid {s} digit\n", .{ err.invalid_digit.digit, err.invalid_digit.base }),
            .invalid_escape => try out.print("invalid escape sequence '\\{c}'\n", .{err.invalid_escape.digit}),

            // Parser errors
            .expectedBasicToken => try out.print("expected {s}, got `{s}`\n", .{
                err.expectedBasicToken.expected,
                err.expectedBasicToken.got.kind.repr() orelse err.expectedBasicToken.got.data,
            }),
            .expected2Token => try out.print("expected `{s}`, got `{s}`\n", .{
                err.expected2Token.expected.repr() orelse "identifier",
                err.expected2Token.got.kind.repr() orelse err.expected2Token.got.data,
            }),
            .missing_close => {
                try out.print("expected closing `{s}` to match opening `{s}` here, got `{s}`\n", .{
                    err.missing_close.expected.repr() orelse "",
                    err.missing_close.open.kind.repr() orelse err.missing_close.open.data,
                    err.missing_close.got.kind.repr() orelse err.missing_close.got.data,
                });
            },
            .comptime_known => {
                try out.print("{s} must be compile-time known\n", .{err.comptime_known.what});
            },
            .unrecognized_builtin => {
                try out.print("`@{s}` is not a recognized built-in function\n", .{err.unrecognized_builtin.what});
            },

            // Symbol
            .redefinition => {
                try out.print("redefinition of symbol `{s}`\n", .{err.redefinition.name});
            },
            .symbol_error => {
                try out.print("symbol `{s}` {s}\n", .{ err.symbol_error.name, err.symbol_error.problem });
            },
            .discard_marked => {
                try out.print("discarded symbol marked as `{s}`\n", .{symbol_.SymbolKind.to_string(err.discard_marked.kind)});
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
                try out.print("use of undeclared identifier `{s}`\n", .{err.undeclaredIdentifier.identifier.data});
            },
            .comptime_access_runtime => {
                try out.print("cannot access non-const variable `{s}` in a comptime context\n", .{err.comptime_access_runtime.identifier.data});
            },
            .inner_fn_access_runtime => {
                try out.print("cannot access non-const variable `{s}` from an inner-function\n", .{err.inner_fn_access_runtime.identifier.data});
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
            .no_default => {
                try out.print("no default value for the type `", .{});
                try err.expectedBuiltinTypeclass.got.printType(out);
                try out.print("`\n", .{});
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
    }

    fn print_extra_info(err: Error) !void {
        switch (err) {
            .missing_close => {
                try (term_.Attr{ .bold = true }).dump(out);
                try print_note_prelude(err.missing_close.open.span);
                try (term_.Attr{ .bold = true }).dump(out);
                try out.print("opening `{s}` here\n", .{err.missing_close.open.kind.repr() orelse err.missing_close.open.data});
                try (term_.Attr{ .bold = false }).dump(out);
                try printEpilude(err.missing_close.open.span);
            },
            .comptime_known => {
                try (term_.Attr{ .bold = true }).dump(out);
                try print_note_prelude(err.comptime_known.span);
                try (term_.Attr{ .bold = true }).dump(out);
                try out.print("consider wrapping with `comptime`\n", .{});
                try (term_.Attr{ .bold = false }).dump(out);
            },
            .redefinition => {
                if (err.redefinition.first_defined_span.line != 0) { // Don't print redefinitions for placs that don't exist
                    try (term_.Attr{ .bold = true }).dump(out);
                    try print_note_prelude(err.redefinition.first_defined_span);
                    try (term_.Attr{ .bold = true }).dump(out);
                    try out.print("other definition of `{s}` here\n", .{err.redefinition.name});
                    try (term_.Attr{ .bold = false }).dump(out);
                    try printEpilude(err.redefinition.first_defined_span);
                }
            },
            .symbol_error => {
                if (err.symbol_error.context_span != null) {
                    try (term_.Attr{ .bold = true }).dump(out);
                    try print_note_prelude(err.symbol_error.context_span.?);
                    try (term_.Attr{ .bold = true }).dump(out);
                    try out.print("{s}\n", .{err.symbol_error.context_message});
                    try (term_.Attr{ .bold = false }).dump(out);
                    try printEpilude(err.symbol_error.context_span.?);
                }
            },
            .sum_duplicate => {
                try (term_.Attr{ .bold = true }).dump(out);
                try print_note_prelude(err.sum_duplicate.first);
                try (term_.Attr{ .bold = true }).dump(out);
                try out.print("other definition of `{s}` here\n", .{err.sum_duplicate.identifier});
                try (term_.Attr{ .bold = false }).dump(out);
                try printEpilude(err.sum_duplicate.first);
            },
            .nonExhaustiveSum => {
                for (err.nonExhaustiveSum.forgotten.items) |_type| {
                    try (term_.Attr{ .bold = true }).dump(out);
                    try print_note_prelude(_type.getToken().span);
                    try (term_.Attr{ .bold = true }).dump(out);
                    try out.print("term not handled: `{s}`\n", .{_type.annotation.pattern.getToken().data});
                    try (term_.Attr{ .bold = false }).dump(out);
                    try printEpilude(_type.getToken().span);
                }
            },
            else => {},
        }
    }

    fn printPrelude(maybe_span: ?span_.Span) !void {
        if (maybe_span) |span| {
            if (span.line > 0 and span.col > 0) {
                try out.print("{s}:{}:{}: ", .{ span.filename, span.line, span.col });
            } else {
                try out.print("{s}: ", .{span.filename});
            }
        }
        try term_.outputColor(term_.Attr{ .fg = .red, .bold = true }, "error: ", out);
    }

    fn print_note_prelude(maybe_span: ?span_.Span) !void {
        if (maybe_span) |span| {
            try out.print("{s}:{}:{}: ", .{ span.filename, span.line, span.col });
        }
        try term_.outputColor(term_.Attr{ .fg = .cyan, .bold = true }, "note: ", out);
    }

    fn printEpilude(maybe_span: ?span_.Span) !void {
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
            try term_.outputColor(term_.Attr{ .fg = .green, .bold = true }, "^\n", out);
        }
    }
};
