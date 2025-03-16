// TODO: Separate `Errors` and `Error` to their own file

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Span = @import("../util/span.zig");
const Symbol = @import("../symbol/symbol.zig");
const term_ = @import("term.zig");
const Token = @import("../lexer/token.zig");

pub const Error = union(enum) {
    // General errors
    basic: struct { // TODO: Add a fmt'd constructor for one of these in the Error struct
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
    expected_basic_token: struct {
        expected: []const u8,
        got: Token,
    },
    expected2token: struct {
        expected: Token.Kind,
        got: Token,
    },
    missing_close: struct {
        expected: Token.Kind,
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
        context_span: ?Span = null,
        name: []const u8,
        problem: []const u8,
        context_message: []const u8 = "",
    },
    discard_marked: struct {
        span: Span,
        kind: Symbol.Kind,
    },
    not_inside_loop: struct {
        span: Span,
        name: []const u8,
    },
    not_inside_function: struct {
        span: Span,
        name: []const u8,
    },
    import_file_not_found: struct {
        span: Span,
        filename: []const u8,
    },

    // Traits
    reimpl: struct {
        first_defined_span: Span,
        redefined_span: Span,
        name: ?[]const u8,
        _type: *ast_.AST,
    },
    type_not_impl_method: struct { // TODO: This should take in an enum to determine if the name is of a method or of a member
        span: Span,
        method_name: []const u8,
        _type: *ast_.AST,
    },
    type_not_impl_trait: struct {
        span: Span,
        trait_name: []const u8,
        _type: *ast_.AST,
    },
    method_not_in_trait: struct {
        method_span: Span,
        method_name: []const u8,
        trait_name: []const u8,
    },
    method_not_in_impl: struct {
        impl_span: Span,
        method_span: Span,
        method_name: []const u8,
        trait_name: []const u8,
    },
    impl_receiver_mismatch: struct {
        receiver_span: Span,
        impl_receiver: ?ast_.Receiver_Kind,
        trait_receiver: ?ast_.Receiver_Kind,
        method_name: []const u8,
        trait_name: []const u8,
    },
    invoke_receiver_mismatch: struct {
        receiver_span: Span,
        method_receiver: ast_.Receiver_Kind,
        method_name: []const u8,
        lhs_type: *ast_.AST,
    },
    mismatch_method_param_arity: struct {
        span: Span,
        trait_arity: usize,
        impl_arity: usize,
        method_name: []const u8,
        trait_name: []const u8,
    },
    mismatch_method_type: struct {
        span: Span,
        trait_type: *ast_.AST,
        impl_type: *ast_.AST,
        method_name: []const u8,
        trait_name: []const u8,
    },
    mismatch_method_virtuality: struct {
        span: Span,
        trait_method_is_virtual: bool,
        impl_method_is_virtual: bool,
        method_name: []const u8,
        trait_name: []const u8,
    },
    trait_virtual_refers_to_self: struct {
        span: Span,
        method_name: []const u8,
        trait_name: []const u8,
    },

    // Typecheck
    unexpected_type: struct {
        span: Span,
        expected: *ast_.AST,
        got: *ast_.AST,
    },
    expected_builtin_typeclass: struct {
        span: Span,
        expected: []const u8, // name of the type class
        got: *ast_.AST,
    },
    duplicate: struct {
        span: Span,
        identifier: []const u8,
        first: ?Span, // printed get_std_err() as extra information
    },
    member_not_in: struct {
        span: Span,
        identifier: []const u8,
        name: []const u8,
        group: *ast_.AST,
    },
    undeclared_identifier: struct {
        identifier: Token,
        expected: ?*ast_.AST,
    },
    comptime_access_runtime: struct {
        identifier: Token,
    },
    inner_fn_access_runtime: struct {
        identifier: Token,
    },
    use_before_def: struct {
        identifier: Token,
    },
    modify_immutable: struct {
        identifier: Token,
    },
    not_indexable: struct {
        span: Span,
        _type: *ast_.AST,
    },
    non_exhaustive_sum: struct {
        span: Span,
        forgotten: std.ArrayList(*ast_.AST),
    },
    mismatch_arity: struct {
        span: Span,
        takes: usize,
        given: usize,
        thing_name: []const u8,
        takes_name: []const u8,
        given_name: []const u8,
    },
    no_default: struct {
        span: Span,
        _type: *ast_.AST,
    },
    wrong_from: struct {
        span: Span,
        operator: []const u8, // either "orelse" or "catch"
        from: []const u8, // either "optional" or "error"
        got: *ast_.AST, // What the type actually was
    },
    integer_out_of_bounds: struct {
        span: Span,
        expected: *ast_.AST,
        value: i128,
    },
    invalid_type: struct {
        span: Span,
        got: *ast_.AST,
    },
    recursive_definition: struct {
        span: Span,
        symbol_name: ?[]const u8,
    },

    // TODO: Add span() and get field like for AST
    fn get_span(self: *const Error) ?Span {
        switch (self.*) {
            .basic => return self.basic.span,

            .invalid_digit => return self.invalid_digit.span,
            .invalid_escape => return self.invalid_escape.span,

            .expected_basic_token => return self.expected_basic_token.got.span,
            .expected2token => return self.expected2token.got.span,
            .missing_close => return self.missing_close.got.span,
            .comptime_known => return self.comptime_known.span,

            .redefinition => return self.redefinition.redefined_span,
            .symbol_error => return self.symbol_error.span,
            .discard_marked => return self.discard_marked.span,
            .not_inside_loop => return self.not_inside_loop.span,
            .not_inside_function => return self.not_inside_function.span,
            .import_file_not_found => return self.import_file_not_found.span,

            .reimpl => return self.reimpl.redefined_span,
            .type_not_impl_method => return self.type_not_impl_method.span,
            .type_not_impl_trait => return self.type_not_impl_trait.span,
            .method_not_in_trait => return self.method_not_in_trait.method_span,
            .method_not_in_impl => return self.method_not_in_impl.impl_span,
            .impl_receiver_mismatch => return self.impl_receiver_mismatch.receiver_span,
            .invoke_receiver_mismatch => return self.invoke_receiver_mismatch.receiver_span,
            .mismatch_method_param_arity => return self.mismatch_method_param_arity.span,
            .mismatch_method_type => return self.mismatch_method_type.span,
            .mismatch_method_virtuality => return self.mismatch_method_virtuality.span,
            .trait_virtual_refers_to_self => return self.trait_virtual_refers_to_self.span,

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
            .mismatch_arity => return self.mismatch_arity.span,
            .no_default => return self.no_default.span,
            .wrong_from => return self.wrong_from.span,
            .integer_out_of_bounds => return self.integer_out_of_bounds.span,
            .invalid_type => return self.invalid_type.span,
            .recursive_definition => return self.recursive_definition.span,
        }
    }

    pub fn fatal_error(self: Error) noreturn {
        self.print_error();
        std.process.exit(1);
    }

    pub fn print_error(self: Error) void {
        bold.dump(get_std_err()) catch unreachable;
        print_label(self.get_span(), "error: ", .red);
        self.print_msg();
        not_bold.dump(get_std_err()) catch unreachable;
        print_epilude(self.get_span());
        self.print_extra_info();
    }

    fn print_msg(err: Error) void {
        switch (err) {
            // General errors
            .basic => get_std_err().print("{s}\n", .{err.basic.msg}) catch unreachable,

            // Lexer errors
            .invalid_digit => get_std_err().print("'{c}' is not a valid {s} digit\n", .{ err.invalid_digit.digit, err.invalid_digit.base }) catch unreachable,
            .invalid_escape => get_std_err().print("invalid escape sequence '\\{c}'\n", .{err.invalid_escape.digit}) catch unreachable,

            // Parser errors
            .expected_basic_token => get_std_err().print("expected {s}, got `{s}`\n", .{
                err.expected_basic_token.expected,
                err.expected_basic_token.got.kind.repr() orelse err.expected_basic_token.got.data,
            }) catch unreachable,
            .expected2token => get_std_err().print("expected `{s}`, got `{s}`\n", .{
                err.expected2token.expected.repr() orelse "identifier",
                err.expected2token.got.kind.repr() orelse err.expected2token.got.data,
            }) catch unreachable,
            .missing_close => {
                get_std_err().print("expected closing `{s}` to match opening `{s}` here, got `{s}`\n", .{
                    err.missing_close.expected.repr() orelse "",
                    err.missing_close.open.kind.repr() orelse err.missing_close.open.data,
                    err.missing_close.got.kind.repr() orelse err.missing_close.got.data,
                }) catch unreachable;
            },
            .comptime_known => get_std_err().print("{s} must be compile-time known\n", .{err.comptime_known.what}) catch unreachable,

            // Symbol
            .redefinition => get_std_err().print("redefinition of symbol `{s}`\n", .{err.redefinition.name}) catch unreachable,
            .symbol_error => get_std_err().print("symbol `{s}` {s}\n", .{ err.symbol_error.name, err.symbol_error.problem }) catch unreachable,
            .discard_marked => get_std_err().print("discarded symbol marked as `{s}`\n", .{@tagName(err.discard_marked.kind)}) catch unreachable,
            .not_inside_loop => get_std_err().print("`{s}` is not inside a loop\n", .{err.not_inside_loop.name}) catch unreachable,
            .not_inside_function => get_std_err().print("`{s}` is not inside a function\n", .{err.not_inside_function.name}) catch unreachable,
            .import_file_not_found => get_std_err().print("file `{s}.orng` not found\n", .{err.import_file_not_found.filename}) catch unreachable,

            // Traits
            .reimpl => if (err.reimpl.name != null) {
                get_std_err().print("duplicate implementation of trait `{s}` for the type `", .{err.reimpl.name.?}) catch unreachable;
                err.reimpl._type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`\n", .{}) catch unreachable;
            } else {
                get_std_err().print("duplicate implementation for the type `", .{}) catch unreachable;
                err.reimpl._type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`\n", .{}) catch unreachable;
            },
            .type_not_impl_method => {
                get_std_err().print("the type `", .{}) catch unreachable;
                err.type_not_impl_method._type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("` does not implement the method `{s}`\n", .{err.type_not_impl_method.method_name}) catch unreachable;
            },
            .type_not_impl_trait => {
                get_std_err().print("the type `", .{}) catch unreachable;
                err.type_not_impl_trait._type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("` does not implement the trait `{s}`\n", .{err.type_not_impl_trait.trait_name}) catch unreachable;
            },
            .method_not_in_trait => get_std_err().print("method `{s}` is not in trait `{s}`\n", .{
                err.method_not_in_trait.method_name,
                err.method_not_in_trait.trait_name,
            }) catch unreachable,
            .method_not_in_impl => get_std_err().print("missing implementation of method `{s}` from trait `{s}`\n", .{
                err.method_not_in_impl.method_name,
                err.method_not_in_impl.trait_name,
            }) catch unreachable,
            .impl_receiver_mismatch => if (err.impl_receiver_mismatch.trait_receiver != null and err.impl_receiver_mismatch.impl_receiver != null) {
                get_std_err().print("trait `{s}` specifies receiver `{s}` for method `{s}`, got receiver `{s}`\n", .{
                    err.impl_receiver_mismatch.trait_name,
                    err.impl_receiver_mismatch.trait_receiver.?.to_string(),
                    err.impl_receiver_mismatch.method_name,
                    err.impl_receiver_mismatch.impl_receiver.?.to_string(),
                }) catch unreachable;
            } else if (err.impl_receiver_mismatch.trait_receiver == null and err.impl_receiver_mismatch.impl_receiver != null) {
                get_std_err().print("trait `{s}` does not specify a receiver for method `{s}`, got receiver `{s}`\n", .{
                    err.impl_receiver_mismatch.trait_name,
                    err.impl_receiver_mismatch.method_name,
                    err.impl_receiver_mismatch.impl_receiver.?.to_string(),
                }) catch unreachable;
            } else if (err.impl_receiver_mismatch.trait_receiver != null and err.impl_receiver_mismatch.impl_receiver == null) {
                get_std_err().print("trait `{s}` specifies receiver `{s}` for method `{s}`\n", .{
                    err.impl_receiver_mismatch.trait_name,
                    err.impl_receiver_mismatch.trait_receiver.?.to_string(),
                    err.impl_receiver_mismatch.method_name,
                }) catch unreachable;
            },
            .invoke_receiver_mismatch => {
                get_std_err().print("receiver `{s}` of method `{s}` incompatible with type `", .{
                    err.invoke_receiver_mismatch.method_receiver.to_string(),
                    err.invoke_receiver_mismatch.method_name,
                }) catch unreachable;
                err.invoke_receiver_mismatch.lhs_type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`\n", .{}) catch unreachable;
            },
            .mismatch_method_param_arity => get_std_err().print("trait `{s}` specifies {} parameter{s} for method `{s}`, got {}\n", .{
                err.mismatch_method_param_arity.trait_name,
                err.mismatch_method_param_arity.trait_arity,
                if (err.mismatch_method_param_arity.trait_arity != 1) "s" else "",
                err.mismatch_method_param_arity.method_name,
                err.mismatch_method_param_arity.impl_arity,
            }) catch unreachable,
            .mismatch_method_type => {
                get_std_err().print("trait `{s}` specifies type `", .{err.mismatch_method_type.trait_name}) catch unreachable;
                err.mismatch_method_type.trait_type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("` for method `{s}`, got `", .{err.mismatch_method_type.method_name}) catch unreachable;
                err.mismatch_method_type.impl_type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`\n", .{}) catch unreachable;
            },
            .mismatch_method_virtuality => {
                get_std_err().print("trait `{s}` specifies the method `{s}` as {s}, got {s}\n", .{
                    err.mismatch_method_virtuality.trait_name,
                    err.mismatch_method_virtuality.method_name,
                    if (err.mismatch_method_virtuality.trait_method_is_virtual) "virtual" else "non-virtual",
                    if (err.mismatch_method_virtuality.impl_method_is_virtual) "virtual" else "non-virtual",
                }) catch unreachable;
            },
            .trait_virtual_refers_to_self => {
                get_std_err().print("virtual method `{s}` of trait `{s}` refers to `Self` type\n", .{
                    err.trait_virtual_refers_to_self.method_name,
                    err.trait_virtual_refers_to_self.trait_name,
                }) catch unreachable;
            },

            // Typecheck
            .unexpected_type => if (err.unexpected_type.expected.* == .identifier and std.mem.eql(u8, err.unexpected_type.expected.token().data, "Void")) {
                std.debug.assert(err.unexpected_type.expected.* != .poison);
                get_std_err().print("cannot assign a value of type `", .{}) catch unreachable;
                err.unexpected_type.got.print_type(get_std_err()) catch unreachable;
                get_std_err().print("` to type `Void`\n", .{}) catch unreachable;
            } else {
                std.debug.assert(err.unexpected_type.expected.* != .poison);
                get_std_err().print("expected a value of type `", .{}) catch unreachable;
                err.unexpected_type.expected.print_type(get_std_err()) catch unreachable;
                if (err.unexpected_type.got.* != .poison) {
                    get_std_err().print("`, got a value of type `", .{}) catch unreachable;
                    err.unexpected_type.got.print_type(get_std_err()) catch unreachable;
                }
                get_std_err().print("`\n", .{}) catch unreachable;
            },
            .expected_builtin_typeclass => {
                get_std_err().print("expected a value of a(n) {s} type, got `", .{err.expected_builtin_typeclass.expected}) catch unreachable;
                err.expected_builtin_typeclass.got.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`\n", .{}) catch unreachable;
            },
            .duplicate => get_std_err().print("duplicate item `{s}`\n", .{err.duplicate.identifier}) catch unreachable,
            .member_not_in => {
                get_std_err().print("member `{s}` not in {s}: `", .{ err.member_not_in.identifier, err.member_not_in.name }) catch unreachable;
                err.member_not_in.group.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`\n", .{}) catch unreachable;
            },
            .undeclared_identifier => get_std_err().print("use of undeclared identifier `{s}`\n", .{err.undeclared_identifier.identifier.data}) catch unreachable,
            .comptime_access_runtime => get_std_err().print("cannot access non-const variable `{s}` in a comptime context\n", .{
                err.comptime_access_runtime.identifier.data,
            }) catch unreachable,
            .inner_fn_access_runtime => get_std_err().print("cannot access non-const variable `{s}` from an inner-function\n", .{
                err.inner_fn_access_runtime.identifier.data,
            }) catch unreachable,
            .use_before_def => get_std_err().print("use of identifier `{s}` before its definition\n", .{err.use_before_def.identifier.data}) catch unreachable,
            .modify_immutable => get_std_err().print("cannot modify non-mutable symbol `{s}`\n", .{err.modify_immutable.identifier.data}) catch unreachable,
            .not_indexable => {
                get_std_err().print("the type `", .{}) catch unreachable;
                err.not_indexable._type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("` is not indexable\n", .{}) catch unreachable;
            },
            .non_exhaustive_sum => get_std_err().print("match over sum type is not exhaustive\n", .{}) catch unreachable,
            .mismatch_arity => {
                get_std_err().print("{s} takes {} {s}{s}, {} {s}{s} given\n", .{
                    err.mismatch_arity.thing_name,
                    err.mismatch_arity.takes,
                    err.mismatch_arity.takes_name,
                    if (err.mismatch_arity.takes == 1) "" else "s",
                    err.mismatch_arity.given,
                    err.mismatch_arity.given_name,
                    if (err.mismatch_arity.given == 1) "" else "s",
                }) catch unreachable;
            },
            .no_default => {
                get_std_err().print("no default value for type `", .{}) catch unreachable;
                err.no_default._type.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`\n", .{}) catch unreachable;
            },
            .wrong_from => {
                get_std_err().print("expected {s} type for {s}, got `", .{
                    err.wrong_from.from,
                    err.wrong_from.operator,
                }) catch unreachable;
                err.wrong_from.got.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`\n", .{}) catch unreachable;
            },
            .integer_out_of_bounds => {
                get_std_err().print("error: integer is out of bounds for type `", .{}) catch unreachable;
                err.integer_out_of_bounds.expected.print_type(get_std_err()) catch unreachable;
                get_std_err().print("`; value={}\n", .{err.integer_out_of_bounds.value}) catch unreachable;
            },
            .invalid_type => {
                get_std_err().print("error: expected a compile-time constant type, got {s}\n", .{@tagName(err.invalid_type.got.*)}) catch unreachable;
            },
            .recursive_definition => if (err.recursive_definition.symbol_name) |symbol_name| {
                get_std_err().print("error: recursive definition of symbol `{s}` detected\n", .{symbol_name}) catch unreachable;
            } else {
                get_std_err().print("error: recursive definition detected\n", .{}) catch unreachable;
            },
        }
    }

    fn print_extra_info(self: Error) void {
        // FIXME: High Cyclo
        switch (self) {
            .missing_close => {
                bold.dump(get_std_err()) catch unreachable;
                print_note_label(self.missing_close.open.span);
                bold.dump(get_std_err()) catch unreachable;
                get_std_err().print("opening `{s}` here:\n", .{self.missing_close.open.kind.repr() orelse self.missing_close.open.data}) catch unreachable;
                not_bold.dump(get_std_err()) catch unreachable;
                print_epilude(self.missing_close.open.span);
            },
            .comptime_known => {
                bold.dump(get_std_err()) catch unreachable;
                print_note_label(self.comptime_known.span);
                bold.dump(get_std_err()) catch unreachable;
                get_std_err().print("consider wrapping with `comptime`\n", .{}) catch unreachable;
                not_bold.dump(get_std_err()) catch unreachable;
            },
            .redefinition => {
                if (self.redefinition.first_defined_span.line_number != 0) { // Don't print redefinitions for places that don't exist
                    bold.dump(get_std_err()) catch unreachable;
                    print_note_label(self.redefinition.first_defined_span);
                    bold.dump(get_std_err()) catch unreachable;
                    get_std_err().print("other definition of `{s}` here:\n", .{self.redefinition.name}) catch unreachable;
                    not_bold.dump(get_std_err()) catch unreachable;
                    print_epilude(self.redefinition.first_defined_span);
                }
            },
            .symbol_error => {
                if (self.symbol_error.context_span != null) {
                    bold.dump(get_std_err()) catch unreachable;
                    print_note_label(self.symbol_error.context_span.?);
                    bold.dump(get_std_err()) catch unreachable;
                    get_std_err().print("{s}\n", .{self.symbol_error.context_message}) catch unreachable;
                    not_bold.dump(get_std_err()) catch unreachable;
                    print_epilude(self.symbol_error.context_span.?);
                }
            },
            .duplicate => if (self.duplicate.first != null) {
                bold.dump(get_std_err()) catch unreachable;
                print_note_label(self.duplicate.first);
                bold.dump(get_std_err()) catch unreachable;
                get_std_err().print("other definition of `{s}` here:\n", .{self.duplicate.identifier}) catch unreachable;
                not_bold.dump(get_std_err()) catch unreachable;
                print_epilude(self.duplicate.first);
            },
            .non_exhaustive_sum => {
                for (self.non_exhaustive_sum.forgotten.items) |_type| {
                    bold.dump(get_std_err()) catch unreachable;
                    print_note_label(_type.token().span);
                    bold.dump(get_std_err()) catch unreachable;
                    get_std_err().print("term not handled: `{s}`\n", .{_type.annotation.pattern.token().data}) catch unreachable;
                    not_bold.dump(get_std_err()) catch unreachable;
                    print_epilude(_type.token().span);
                }
            },
            .reimpl => {
                if (self.reimpl.first_defined_span.line_number != 0) { // Don't print reimpls for places that don't exist!
                    bold.dump(get_std_err()) catch unreachable;
                    print_note_label(self.reimpl.first_defined_span);
                    bold.dump(get_std_err()) catch unreachable;
                    if (self.reimpl.name != null) {
                        get_std_err().print("other implementation of `{s}` here:\n", .{self.reimpl.name.?}) catch unreachable;
                    } else {
                        get_std_err().print("other implementation here:\n", .{}) catch unreachable;
                    }
                    not_bold.dump(get_std_err()) catch unreachable;
                    print_epilude(self.reimpl.first_defined_span);
                }
            },
            .method_not_in_impl => {
                bold.dump(get_std_err()) catch unreachable;
                print_note_label(self.method_not_in_impl.method_span);
                bold.dump(get_std_err()) catch unreachable;
                get_std_err().print("method specification here:\n", .{}) catch unreachable;
                not_bold.dump(get_std_err()) catch unreachable;
                print_epilude(self.method_not_in_impl.method_span);
            },
            else => {},
        }
    }

    fn peek_error(err: Error) void {
        err.print_error();
        unreachable;
    }
};

// This is for compatability with Windows, since stdout for Windows isn't known at compile-time
fn get_std_err() std.fs.File.Writer {
    return std.io.getStdErr().writer();
}

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
        err.peek_error(); // uncomment if you want to see where errors come from TODO: Make this a cmd line flag
    }

    pub fn print_errors(self: *Errors) void {
        for (self.errors_list.items) |err| {
            err.print_error();
        }
    }
};

fn print_note_label(maybe_span: ?Span) void {
    print_label(maybe_span, "note: ", .cyan);
}

fn print_epilude(maybe_span: ?Span) void {
    if (maybe_span) |old_span| {
        const span = old_span;
        if (span.line_number == 0) {
            return;
        } else if (span.line_text.len > 0) {
            not_bold.dump(get_std_err()) catch unreachable;
            get_std_err().print("{s}\n", .{span.line_text}) catch unreachable;
        }
        for (2..span.col) |_| {
            get_std_err().print(" ", .{}) catch unreachable;
        }
        term_.outputColor(term_.Attr{ .fg = .green, .bold = true }, "^\n", get_std_err()) catch unreachable;
    }
}

fn print_label(maybe_span: ?Span, label: []const u8, color: term_.Color) void {
    if (maybe_span) |span| {
        if (span.line_number > 0 and span.col > 0) {
            get_std_err().print("{s}:{}:{}: ", .{ span.filename, span.line_number, span.col }) catch unreachable;
        } else if (span.filename.len > 0) {
            get_std_err().print("{s}: ", .{span.filename}) catch unreachable;
        }
    }
    term_.outputColor(term_.Attr{ .fg = color, .bold = true }, label, get_std_err()) catch unreachable;
}
