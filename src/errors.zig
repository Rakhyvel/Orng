const std = @import("std");
const ast_ = @import("ast.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");
const term_ = @import("term.zig");
const token_ = @import("token.zig");

const Error_Error_Sum = std.fs.File.WriteError;

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

    // Traits
    reimpl: struct {
        first_defined_span: span_.Span,
        redefined_span: span_.Span,
        name: ?[]const u8,
        _type: *ast_.AST,
    },
    type_not_impl_method: struct {
        span: span_.Span,
        method_name: []const u8,
        _type: *ast_.AST,
    },
    type_not_impl_trait: struct {
        span: span_.Span,
        trait_name: []const u8,
        _type: *ast_.AST,
    },
    method_not_in_trait: struct {
        method_span: span_.Span,
        method_name: []const u8,
        trait_name: []const u8,
    },
    method_not_in_impl: struct {
        impl_span: span_.Span,
        method_span: span_.Span,
        method_name: []const u8,
        trait_name: []const u8,
    },
    receiver_mismatch: struct {
        receiver_span: span_.Span,
        impl_receiver: ?ast_.Receiver_Kind,
        trait_receiver: ?ast_.Receiver_Kind,
        method_name: []const u8,
        trait_name: []const u8,
    },
    mismatch_method_param_arity: struct {
        span: span_.Span,
        trait_arity: usize,
        impl_arity: usize,
        method_name: []const u8,
        trait_name: []const u8,
    },
    mismatch_method_type: struct {
        span: span_.Span,
        trait_type: *ast_.AST,
        impl_type: *ast_.AST,
        method_name: []const u8,
        trait_name: []const u8,
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
    duplicate: struct {
        span: span_.Span,
        identifier: []const u8,
        first: ?span_.Span, // printed out as extra information
    },
    member_not_in: struct {
        span: span_.Span,
        identifier: []const u8,
        name: []const u8,
        group: *ast_.AST,
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
    wrong_from: struct {
        span: span_.Span,
        operator: []const u8, // either "orelse" or "catch"
        from: []const u8, // either "optional" or "error"
        got: *ast_.AST, // What the type actually was
    },
    integer_out_of_bounds: struct {
        span: span_.Span,
        expected: *ast_.AST,
        value: i128,
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
    integer_overflow: struct {
        span: span_.Span,
        lhs: i128,
        rhs: i128,
        name: []const u8,
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

            .reimpl => return self.reimpl.redefined_span,
            .type_not_impl_method => return self.type_not_impl_method.span,
            .type_not_impl_trait => return self.type_not_impl_trait.span,
            .method_not_in_trait => return self.method_not_in_trait.method_span,
            .method_not_in_impl => return self.method_not_in_impl.impl_span,
            .receiver_mismatch => return self.receiver_mismatch.receiver_span,
            .mismatch_method_param_arity => return self.mismatch_method_param_arity.span,
            .mismatch_method_type => return self.mismatch_method_type.span,

            .unexpected_type => return self.unexpected_type.span,
            .expected_builtin_typeclass => return self.expected_builtin_typeclass.span,
            .duplicate => return self.duplicate.span,
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
            .wrong_from => return self.wrong_from.span,
            .integer_out_of_bounds => return self.integer_out_of_bounds.span,

            .out_of_bounds => return self.out_of_bounds.span,
            .negative_index => return self.negative_index.span,
            .slice_lower_upper => return self.slice_lower_upper.span,
            .sum_select_inactive => return self.sum_select_inactive.span,
            .integer_overflow => return self.integer_overflow.span,
        }
    }
};

const out = std.io.getStdOut().writer();
const bold = term_.Attr{ .bold = true };
const not_bold = term_.Attr{ .bold = false };
pub const Errors = struct {
    errors_list: std.ArrayList(Error),

    pub fn init(allocator: std.mem.Allocator) Errors {
        return .{
            .errors_list = std.ArrayList(Error).init(allocator),
        };
    }

    pub fn deinit(self: *Errors) void {
        self.errors_list.deinit();
    }

    pub fn add_error(self: *Errors, err: Error) void {
        self.errors_list.append(err) catch unreachable;
        peek_error(err) catch unreachable; // uncomment if you want to see where errors come from
    }

    fn peek_error(err: Error) !void {
        try bold.dump(out);
        try print_label(err.get_span(), "error: ", .red);
        try bold.dump(out);
        try print_main_error(err);
        try not_bold.dump(out);
        try print_epilude(err.get_span());
        try print_extra_info(err);
        unreachable;
    }

    pub fn print_errors(self: *Errors) Error_Error_Sum!void {
        for (self.errors_list.items) |err| {
            try bold.dump(out);
            try print_label(err.get_span(), "error: ", .red);
            try bold.dump(out);
            try print_main_error(err);
            try not_bold.dump(out);
            try print_epilude(err.get_span());
            try print_extra_info(err);
        }
    }

    fn print_label(maybe_span: ?span_.Span, label: []const u8, color: term_.Color) Error_Error_Sum!void {
        if (maybe_span) |span| {
            if (span.line_number > 0 and span.col > 0) {
                try out.print("{s}:{}:{}: ", .{ span.filename, span.line_number, span.col });
            } else {
                try out.print("{s}: ", .{span.filename});
            }
        }
        try term_.outputColor(term_.Attr{ .fg = color, .bold = true }, label, out);
    }

    fn print_main_error(err: Error) Error_Error_Sum!void {
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

            // Traits
            .reimpl => if (err.reimpl.name != null) {
                try out.print("duplicate implementation of trait `{s}` for the type `", .{err.reimpl.name.?});
                try err.reimpl._type.print_type(out);
                try out.print("`\n", .{});
            } else {
                try out.print("duplicate implementation for the type `", .{});
                try err.reimpl._type.print_type(out);
                try out.print("`\n", .{});
            },
            .type_not_impl_method => {
                try out.print("the type `", .{});
                try err.type_not_impl_method._type.print_type(out);
                try out.print("` does not implement the method `{s}`\n", .{err.type_not_impl_method.method_name});
            },
            .type_not_impl_trait => {
                try out.print("the type `", .{});
                try err.type_not_impl_trait._type.print_type(out);
                try out.print("` does not implement the trait `{s}`\n", .{err.type_not_impl_trait.trait_name});
            },
            .method_not_in_trait => try out.print("method `{s}` is not in trait `{s}`\n", .{
                err.method_not_in_trait.method_name,
                err.method_not_in_trait.trait_name,
            }),
            .method_not_in_impl => try out.print("missing implementation of method `{s}` from trait `{s}`\n", .{
                err.method_not_in_impl.method_name,
                err.method_not_in_impl.trait_name,
            }),
            .receiver_mismatch => if (err.receiver_mismatch.trait_receiver != null and err.receiver_mismatch.impl_receiver != null) {
                try out.print("trait `{s}` specifies receiver `{s}` for method `{s}`, got receiver `{s}`\n", .{
                    err.receiver_mismatch.trait_name,
                    err.receiver_mismatch.trait_receiver.?.to_string(),
                    err.receiver_mismatch.method_name,
                    err.receiver_mismatch.impl_receiver.?.to_string(),
                });
            } else if (err.receiver_mismatch.trait_receiver == null and err.receiver_mismatch.impl_receiver != null) {
                try out.print("trait `{s}` does not specify a receiver for method `{s}`, got receiver `{s}`\n", .{
                    err.receiver_mismatch.trait_name,
                    err.receiver_mismatch.method_name,
                    err.receiver_mismatch.impl_receiver.?.to_string(),
                });
            } else if (err.receiver_mismatch.trait_receiver != null and err.receiver_mismatch.impl_receiver == null) {
                try out.print("trait `{s}` specifies receiver `{s}` for method `{s}`\n", .{
                    err.receiver_mismatch.trait_name,
                    err.receiver_mismatch.trait_receiver.?.to_string(),
                    err.receiver_mismatch.method_name,
                });
            },
            .mismatch_method_param_arity => try out.print("trait `{s}` specifies {} parameter{s} for method `{s}`, got {}\n", .{
                err.mismatch_method_param_arity.trait_name,
                err.mismatch_method_param_arity.trait_arity,
                if (err.mismatch_method_param_arity.trait_arity != 1) "s" else "",
                err.mismatch_method_param_arity.method_name,
                err.mismatch_method_param_arity.impl_arity,
            }),
            .mismatch_method_type => {
                try out.print("trait `{s}` specifies type `", .{err.mismatch_method_type.trait_name});
                try err.mismatch_method_type.trait_type.print_type(out);
                try out.print("` for method `{s}`, got `", .{err.mismatch_method_type.method_name});
                try err.mismatch_method_type.impl_type.print_type(out);
                try out.print("`\n", .{});
            },

            // Typecheck
            .unexpected_type => if (err.unexpected_type.expected.* == .identifier and std.mem.eql(u8, err.unexpected_type.expected.token().data, "Void")) {
                std.debug.assert(err.unexpected_type.expected.* != .poison);
                try out.print("cannot assign a value of type `", .{});
                try err.unexpected_type.got.print_type(out);
                try out.print("` to type `Void`\n", .{});
            } else {
                std.debug.assert(err.unexpected_type.expected.* != .poison);
                try out.print("expected a value of type `", .{});
                try err.unexpected_type.expected.print_type(out);
                if (err.unexpected_type.got.* != .poison) {
                    try out.print("`, got a value of type `", .{});
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
            .duplicate => try out.print("duplicate item `{s}`\n", .{err.duplicate.identifier}),
            .member_not_in => {
                try out.print("member `{s}` not in {s}: `", .{ err.member_not_in.identifier, err.member_not_in.name });
                try err.member_not_in.group.print_type(out);
                try out.print("`\n", .{});
            },
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
                try out.print("no default value for type `", .{});
                try err.no_default._type.print_type(out);
                try out.print("`\n", .{});
            },
            .wrong_from => {
                try out.print("expected {s} type for {s}, got `", .{
                    err.wrong_from.from,
                    err.wrong_from.operator,
                });
                try err.wrong_from.got.print_type(out);
                try out.print("`\n", .{});
            },
            .integer_out_of_bounds => {
                try out.print("error: integer is out of bounds for type `", .{});
                try err.integer_out_of_bounds.expected.print_type(out);
                try out.print("`; value={}\n", .{err.integer_out_of_bounds.value});
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
            .integer_overflow => {
                try out.print("integer {s} overflow with arguments: {}, {}\n", .{
                    err.integer_overflow.name,
                    err.integer_overflow.lhs,
                    err.integer_overflow.rhs,
                });
            },
        }
    }

    fn print_epilude(maybe_span: ?span_.Span) Error_Error_Sum!void {
        if (maybe_span) |old_span| {
            const span = old_span;
            if (span.line_number == 0) {
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

    fn print_extra_info(err: Error) Error_Error_Sum!void {
        switch (err) {
            .missing_close => {
                try bold.dump(out);
                try print_note_label(err.missing_close.open.span);
                try bold.dump(out);
                try out.print("opening `{s}` here:\n", .{err.missing_close.open.kind.repr() orelse err.missing_close.open.data});
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
                if (err.redefinition.first_defined_span.line_number != 0) { // Don't print redefinitions for places that don't exist
                    try bold.dump(out);
                    try print_note_label(err.redefinition.first_defined_span);
                    try bold.dump(out);
                    try out.print("other definition of `{s}` here:\n", .{err.redefinition.name});
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
            .duplicate => if (err.duplicate.first != null) {
                try bold.dump(out);
                try print_note_label(err.duplicate.first);
                try bold.dump(out);
                try out.print("other definition of `{s}` here:\n", .{err.duplicate.identifier});
                try not_bold.dump(out);
                try print_epilude(err.duplicate.first);
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
            .reimpl => {
                if (err.reimpl.first_defined_span.line_number != 0) { // Don't print reimpls for places that don't exist!
                    try bold.dump(out);
                    try print_note_label(err.reimpl.first_defined_span);
                    try bold.dump(out);
                    if (err.reimpl.name != null) {
                        try out.print("other implementation of `{s}` here:\n", .{err.reimpl.name.?});
                    } else {
                        try out.print("other implementation here:\n", .{});
                    }
                    try not_bold.dump(out);
                    try print_epilude(err.reimpl.first_defined_span);
                }
            },
            .method_not_in_impl => {
                try bold.dump(out);
                try print_note_label(err.method_not_in_impl.method_span);
                try bold.dump(out);
                try out.print("method specification here:\n", .{});
                try not_bold.dump(out);
                try print_epilude(err.method_not_in_impl.method_span);
            },
            else => {},
        }
    }

    fn print_note_label(maybe_span: ?span_.Span) Error_Error_Sum!void {
        try print_label(maybe_span, "note: ", .cyan);
    }
};
