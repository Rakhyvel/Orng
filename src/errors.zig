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
    expected_basic_token: struct {
        expected: []const u8,
        got: token_.Token,
    },
    expected2token: struct {
        expected: token_.Token_Kind,
        got: token_.Token,
    },
    missing_close: struct {
        expected: token_.Token_Kind,
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
        context_span: ?span_.Span = null,
        name: []const u8,
        problem: []const u8,
        context_message: []const u8 = "",
    },
    discard_marked: struct {
        span: span_.Span,
        kind: symbol_.Symbol_Kind,
    },
    not_inside_loop: struct {
        span: span_.Span,
        name: []const u8,
    },
    not_inside_function: struct {
        span: span_.Span,
        name: []const u8,
    },

    // Typecheck
    unexpected_type: struct {
        span: span_.Span,
        expected: *ast_.AST,
        got: *ast_.AST,
    },
    expected_builtin_typeclass: struct {
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
    undeclared_identifier: struct {
        identifier: token_.Token,
        expected: ?*ast_.AST,
    },
    comptime_access_runtime: struct {
        identifier: token_.Token,
    },
    inner_fn_access_runtime: struct {
        identifier: token_.Token,
    },
    use_before_def: struct {
        identifier: token_.Token,
    },
    modify_immutable: struct {
        identifier: token_.Token,
    },
    not_indexable: struct {
        span: span_.Span,
        _type: *ast_.AST,
    },
    non_exhaustive_sum: struct {
        span: span_.Span,
        forgotten: std.ArrayList(*ast_.AST),
    },
    mismatch_call_arity: struct {
        span: span_.Span,
        takes: usize,
        given: usize,
    },
    mismatch_tuple_arity: struct {
        span: span_.Span,
        takes: usize,
        given: usize,
    },
    no_default: struct {
        span: span_.Span,
        _type: *ast_.AST,
    },
    wrong_coalesce_from: struct {
        span: span_.Span,
        operator: []const u8, // either "orelse" or "catch"
        from: []const u8, // either "optional" or "error"
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

    fn get_span(self: *const Error) ?span_.Span {
        switch (self.*) {
            .basic => return self.basic.span,

            .invalid_digit => return self.invalid_digit.span,
            .invalid_escape => return self.invalid_escape.span,

            .expected_basic_token => return self.expected_basic_token.got.span,
            .expected2token => return self.expected2token.got.span,
            .missing_close => return self.missing_close.got.span,
            .comptime_known => return self.comptime_known.span,
            .unrecognized_builtin => return self.unrecognized_builtin.span,

            .redefinition => return self.redefinition.redefined_span,
            .symbol_error => return self.symbol_error.span,
            .discard_marked => return self.discard_marked.span,
            .not_inside_loop => return self.not_inside_loop.span,
            .not_inside_function => return self.not_inside_function.span,

            .unexpected_type => return self.unexpected_type.span,
            .expected_builtin_typeclass => return self.expected_builtin_typeclass.span,
            .sum_duplicate => return self.sum_duplicate.span,
            .member_not_in => return self.member_not_in.span,
            .undeclared_identifier => return self.undeclared_identifier.identifier.span,
            .comptime_access_runtime => return self.comptime_access_runtime.identifier.span,
            .inner_fn_access_runtime => return self.inner_fn_access_runtime.identifier.span,
            .use_before_def => return self.use_before_def.identifier.span,
            .modify_immutable => return self.modify_immutable.identifier.span,
            .not_indexable => return self.not_indexable.span,
            .non_exhaustive_sum => return self.non_exhaustive_sum.span,
            .mismatch_call_arity => return self.mismatch_call_arity.span,
            .mismatch_tuple_arity => return self.mismatch_tuple_arity.span,
            .no_default => return self.no_default.span,
            .wrong_coalesce_from => return self.wrong_coalesce_from.span,

            .out_of_bounds => return self.out_of_bounds.span,
            .negative_index => return self.negative_index.span,
            .slice_lower_upper => return self.slice_lower_upper.span,
            .sum_select_inactive => return self.sum_select_inactive.span,
        }
    }
};

const out = std.io.getStdOut().writer();
const bold = term_.Attr{ .bold = true };
const not_bold = term_.Attr{ .bold = false };
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
    pub fn add_error(self: *Errors, err: Error) void {
        self.errors_list.append(err) catch unreachable;
        // unreachable; // uncomment if you want to see where errors come from
    }

    pub fn print_errors(self: *Errors) !void { // TODO: Uninfer error
        for (self.errors_list.items) |err| {
            try bold.dump(out);
            try print_label(err.get_span(), "error: ", .red);
            try bold.dump(out);
            try print_main_error(err, self.allocator);
            try not_bold.dump(out);
            try print_epilude(err.get_span());
            try print_extra_info(err);
        }
    }

    fn print_label(maybe_span: ?span_.Span, label: []const u8, color: term_.Color) !void { // TODO: Uninfer error
        if (maybe_span) |span| {
            if (span.line > 0 and span.col > 0) {
                try out.print("{s}:{}:{}: ", .{ span.filename, span.line, span.col });
            } else {
                try out.print("{s}: ", .{span.filename});
            }
        }
        try term_.outputColor(term_.Attr{ .fg = color, .bold = true }, label, out);
    }

    fn print_main_error(err: Error, allocator: std.mem.Allocator) !void { // TODO: Uninfer error
        _ = allocator;
        switch (err) {
            // General errors
            .basic => try out.print("{s}\n", .{err.basic.msg}),

            // Lexer errors
            .invalid_digit => try out.print("'{c}' is not a valid {s} digit\n", .{ err.invalid_digit.digit, err.invalid_digit.base }),
            .invalid_escape => try out.print("invalid escape sequence '\\{c}'\n", .{err.invalid_escape.digit}),

            // Parser errors
            .expected_basic_token => try out.print("expected {s}, got `{s}`\n", .{
                err.expected_basic_token.expected,
                err.expected_basic_token.got.kind.repr() orelse err.expected_basic_token.got.data,
            }),
            .expected2token => try out.print("expected `{s}`, got `{s}`\n", .{
                err.expected2token.expected.repr() orelse "identifier",
                err.expected2token.got.kind.repr() orelse err.expected2token.got.data,
            }),
            .missing_close => {
                try out.print("expected closing `{s}` to match opening `{s}` here, got `{s}`\n", .{
                    err.missing_close.expected.repr() orelse "",
                    err.missing_close.open.kind.repr() orelse err.missing_close.open.data,
                    err.missing_close.got.kind.repr() orelse err.missing_close.got.data,
                });
            },
            .comptime_known => try out.print("{s} must be compile-time known\n", .{err.comptime_known.what}),
            .unrecognized_builtin => try out.print("`@{s}` is not a recognized built-in function\n", .{err.unrecognized_builtin.what}),

            // Symbol
            .redefinition => try out.print("redefinition of symbol `{s}`\n", .{err.redefinition.name}),
            .symbol_error => try out.print("symbol `{s}` {s}\n", .{ err.symbol_error.name, err.symbol_error.problem }),
            .discard_marked => try out.print("discarded symbol marked as `{s}`\n", .{@tagName(err.discard_marked.kind)}),
            .not_inside_loop => try out.print("`{s}` is not inside a loop\n", .{err.not_inside_loop.name}),
            .not_inside_function => try out.print("`{s}` is not inside a function\n", .{err.not_inside_function.name}),

            // Typecheck
            .unexpected_type => {
                std.debug.assert(err.unexpected_type.expected.* != .poison);
                try out.print("expected a value of the type `", .{});
                try err.unexpected_type.expected.print_type(out);
                if (err.unexpected_type.got.* != .poison) {
                    try out.print("`, got a value of the type `", .{}); // Tiny TODO: if got is Void, print something else
                    try err.unexpected_type.got.print_type(out);
                }
                try out.print("`\n", .{});
            },
            .expected_builtin_typeclass => {
                // just so happens to work out that all builtin type classes start with a vowel :-)
                try out.print("expected a value of an {s} type, got `", .{err.expected_builtin_typeclass.expected});
                try err.expected_builtin_typeclass.got.print_type(out);
                try out.print("`\n", .{});
            },
            .sum_duplicate => try out.print("duplicate sum member `{s}`\n", .{err.sum_duplicate.identifier}),
            .member_not_in => try out.print("member `{s}` not in {s}\n", .{ err.member_not_in.identifier, err.member_not_in.group_name }),
            .undeclared_identifier => try out.print("use of undeclared identifier `{s}`\n", .{err.undeclared_identifier.identifier.data}),
            .comptime_access_runtime => try out.print("cannot access non-const variable `{s}` in a comptime context\n", .{
                err.comptime_access_runtime.identifier.data,
            }),
            .inner_fn_access_runtime => try out.print("cannot access non-const variable `{s}` from an inner-function\n", .{
                err.inner_fn_access_runtime.identifier.data,
            }),
            .use_before_def => try out.print("use of identifier `{s}` before its definition\n", .{err.use_before_def.identifier.data}),
            .modify_immutable => try out.print("cannot modify non-mutable symbol `{s}`\n", .{err.modify_immutable.identifier.data}),
            .not_indexable => {
                try out.print("the type `", .{});
                try err.not_indexable._type.print_type(out);
                try out.print("` is not indexable\n", .{});
            },
            .non_exhaustive_sum => try out.print("match over sum type is not exhaustive\n", .{}),
            .mismatch_call_arity => {
                try out.print("function takes {} parameter{s}, {} argument{s} given\n", .{
                    err.mismatch_call_arity.takes,
                    if (err.mismatch_call_arity.takes == 1) "" else "s",
                    err.mismatch_call_arity.given,
                    if (err.mismatch_call_arity.given == 1) "" else "s",
                });
            },
            .mismatch_tuple_arity => {
                try out.print("expected tuple of {} term{s}, got tuple of {} term{s}\n", .{
                    err.mismatch_tuple_arity.takes,
                    if (err.mismatch_tuple_arity.takes == 1) "" else "s",
                    err.mismatch_tuple_arity.given,
                    if (err.mismatch_tuple_arity.given == 1) "" else "s",
                });
            },
            .no_default => {
                try out.print("no default value for the type `", .{});
                try err.no_default._type.print_type(out);
                try out.print("`\n", .{});
            },
            .wrong_coalesce_from => {
                try out.print("left-hand side of `{s}` is not an `{s}` type\n", .{
                    err.wrong_coalesce_from.operator,
                    err.wrong_coalesce_from.from,
                });
            },

            // Optimizer
            .out_of_bounds => try out.print("index out of bounds; index {}, length {}\n", .{
                err.out_of_bounds.index,
                err.out_of_bounds.length,
            }),
            .negative_index => try out.print("index is negative; index {}\n", .{err.negative_index.index}),
            .slice_lower_upper => {
                try out.print("subslice lower bounds is greater than upper bound; lower {}, upper {}\n", .{
                    err.slice_lower_upper.lower,
                    err.slice_lower_upper.upper,
                });
            },
            .sum_select_inactive => {
                try out.print("access of sum field '{s}' while field '{s}' is active\n", .{
                    err.sum_select_inactive.inactive,
                    err.sum_select_inactive.active,
                });
            },
        }
    }

    fn print_epilude(maybe_span: ?span_.Span) !void { // TODO: Uninfer error
        if (maybe_span) |old_span| {
            const span = old_span;
            if (span.line == 0) {
                return;
            } else if (span.line_text.len > 0) {
                try out.print("{s}\n", .{span.line_text});
            }
            for (2..span.col) |_| {
                try out.print(" ", .{});
            }
            try term_.outputColor(term_.Attr{ .fg = .green, .bold = true }, "^\n", out);
        }
    }

    fn print_extra_info(err: Error) !void { // TODO: Uninfer error
        switch (err) {
            .missing_close => {
                try bold.dump(out);
                try print_note_label(err.missing_close.open.span);
                try bold.dump(out);
                try out.print("opening `{s}` here\n", .{err.missing_close.open.kind.repr() orelse err.missing_close.open.data});
                try not_bold.dump(out);
                try print_epilude(err.missing_close.open.span);
            },
            .comptime_known => {
                try bold.dump(out);
                try print_note_label(err.comptime_known.span);
                try bold.dump(out);
                try out.print("consider wrapping with `comptime`\n", .{});
                try not_bold.dump(out);
            },
            .redefinition => {
                if (err.redefinition.first_defined_span.line != 0) { // Don't print redefinitions for places that don't exist
                    try bold.dump(out);
                    try print_note_label(err.redefinition.first_defined_span);
                    try bold.dump(out);
                    try out.print("other definition of `{s}` here\n", .{err.redefinition.name});
                    try not_bold.dump(out);
                    try print_epilude(err.redefinition.first_defined_span);
                }
            },
            .symbol_error => {
                if (err.symbol_error.context_span != null) {
                    try bold.dump(out);
                    try print_note_label(err.symbol_error.context_span.?);
                    try bold.dump(out);
                    try out.print("{s}\n", .{err.symbol_error.context_message});
                    try not_bold.dump(out);
                    try print_epilude(err.symbol_error.context_span.?);
                }
            },
            .sum_duplicate => {
                try bold.dump(out);
                try print_note_label(err.sum_duplicate.first);
                try bold.dump(out);
                try out.print("other definition of sum member `{s}` here\n", .{err.sum_duplicate.identifier});
                try not_bold.dump(out);
                try print_epilude(err.sum_duplicate.first);
            },
            .non_exhaustive_sum => {
                for (err.non_exhaustive_sum.forgotten.items) |_type| {
                    try bold.dump(out);
                    try print_note_label(_type.token().span);
                    try bold.dump(out);
                    try out.print("term not handled: `{s}`\n", .{_type.annotation.pattern.token().data});
                    try not_bold.dump(out);
                    try print_epilude(_type.token().span);
                }
            },
            else => {},
        }
    }

    fn print_note_label(maybe_span: ?span_.Span) !void { // TODO: Uninfer error
        try print_label(maybe_span, "note: ", .cyan);
    }
};
