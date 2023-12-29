const std = @import("std");
const errs_ = @import("errors.zig");
const span_ = @import("span.zig");
const token_ = @import("token.zig");

const Lexer_Errors = error{LexerError};
const Rnd_Gen = std.rand.DefaultPrng;
var rnd = Rnd_Gen.init(0);

// Has to be done separately from the lexer, because the lexer might throw errors, which would need to be printed out
// However, we couldn't print out the line for the error if we did tokens and lines at the same time
// It's desirable to print the line, therefore lines must be done before tokens
// TODO: Move to own file
pub fn get_lines(contents: []const u8, lines: *std.ArrayList([]const u8), errors: *errs_.Errors) !void { // TODO: Uninfer error
    var start: usize = 0;
    if (contents.len == 0) {
        errors.add_error(errs_.Error{ .basic = .{
            .span = span_.phony_span,
            .msg = "file is empty",
        } });
        return error.LexerError;
    }
    for (1..contents.len) |end| {
        if (contents[end] == '\n') {
            lines.append(contents[start..end]) catch unreachable;
            start = end + 1;
        }
    }
    lines.append(contents[start..contents.len]) catch unreachable;
}

// TODO: Make lexer into a class
const Lex_State = enum {
    none,
    whitespace,
    underscore, //           => uncapitalized | capitalized
    capitalized, //          => "_" | e | uncapitalized | all_caps
    all_caps, //             => "_" | e
    uncapitalized, //        => "_" | e
    string,
    escapedString,
    byte_string1,
    byte_string2,
    char,
    escapedChar,
    integer,
    integer_digit,
    float,
    float_digit,
    hex,
    hex_digit,
    octal,
    octal_digit,
    binary,
    binary_digit,
    symbol,
    multiline,
    comment,

    fn state_from_integer(c: u8) Lex_State {
        return switch (c) {
            'x' => .hex_digit,
            'o' => .octal_digit,
            'b' => .binary_digit,
            else => unreachable,
        };
    }
};

/// Will always end in an EOF on the first column of the next line
/// TODO: Make scanner a struct with member functions n shiet
pub fn get_tokens(
    lines: *std.ArrayList([]const u8),
    filename: []const u8,
    errors: *errs_.Errors,
    fuzz_tokens: bool,
    allocator: std.mem.Allocator,
) !std.ArrayList(token_.Token) { // TODO: Uninfer error
    var tokens = std.ArrayList(token_.Token).init(allocator);
    var line: usize = 0;
    var col: usize = 1;

    for (lines.items) |contents| {
        var slice_start: usize = 0;
        var ix: usize = 0;
        var state: Lex_State = .none;
        line += 1;
        col = 1;

        while (ix < contents.len + 1) {
            // It should be ok to not have a newline at the end of a file
            // DO NOT assume ix < contents.len. DO NOT do contents[ix] besides the following line
            const next_char = if (ix < contents.len) contents[ix] else '\n';

            switch (state) {
                .none => {
                    if (std.ascii.isWhitespace(next_char)) {
                        state = .whitespace;
                        ix += 1;
                        col += 1;
                    } else if (std.ascii.isLower(next_char)) {
                        state = .uncapitalized;
                        ix += 1;
                        col += 1;
                    } else if (std.ascii.isUpper(next_char)) {
                        state = .all_caps;
                        ix += 1;
                        col += 1;
                    } else if (std.ascii.isDigit(next_char)) {
                        state = .integer;
                        ix += 1;
                        col += 1;
                    } else if (next_char == '"') {
                        state = .string;
                        ix += 1;
                        col += 1;
                    } else if (next_char == '\'') {
                        state = .char;
                        ix += 1;
                        col += 1;
                    } else {
                        state = .symbol;
                        ix += 1;
                        col += 1;
                    }
                },

                .whitespace => {
                    if (ix == contents.len or !std.ascii.isWhitespace(next_char)) {
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },

                .underscore => { // _ A-Z a-z 0-9 $
                    if (next_char == '_') {
                        // => error on _
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .msg = "may not have more than one underscore in a row in an identifier",
                        } });
                        return Lexer_Errors.LexerError;
                    } else if (std.ascii.isUpper(next_char) or std.ascii.isDigit(next_char)) {
                        // => all caps on [A-Z0-9]
                        ix += 1;
                        col += 1;
                        state = .all_caps;
                    } else if (std.ascii.isLower(next_char)) {
                        // => uncaps on [a-z]
                        ix += 1;
                        col += 1;
                        state = .uncapitalized;
                    } else {
                        // => error on $
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "identifiers may not end in an underscore",
                        } });
                        return Lexer_Errors.LexerError;
                    }
                },

                .all_caps => { // _ A-Z a-z 0-9 $
                    if (next_char == '_') {
                        // => underscore on a-z
                        ix += 1;
                        col += 1;
                        state = .underscore;
                    } else if (std.ascii.isLower(next_char)) {
                        if (ix - slice_start > 1 and contents[ix - 2] != '_') {
                            // => error on $ if length is too long
                            errors.add_error(errs_.Error{ .basic = .{
                                .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                                .msg = "camelCase is not supported; consider spliting with an underscore",
                            } });
                            return Lexer_Errors.LexerError;
                        } else {
                            // => capitalized on a-z
                            ix += 1;
                            col += 1;
                            state = .capitalized;
                        }
                    } else if (ix == contents.len or !std.ascii.isAlphanumeric(next_char)) {
                        // Split on $
                        tokens.append(token_.Token.init(contents[slice_start..ix], null, filename, contents, line, col)) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        // Accept [A-Z0-9]
                        ix += 1;
                        col += 1;
                    }
                },

                .capitalized => { // _ A-Z a-z 0-9 $
                    if (next_char == '_') {
                        // => underscore on _
                        ix += 1;
                        col += 1;
                        state = .underscore;
                    } else if (std.ascii.isUpper(next_char)) {
                        // => error on [A-Z]
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "camelCase is not supported; consider spliting with an underscore",
                        } });
                        return Lexer_Errors.LexerError;
                    } else if (ix == contents.len or !std.ascii.isAlphanumeric(next_char)) {
                        // Split on $
                        tokens.append(token_.Token.init(contents[slice_start..ix], null, filename, contents, line, col)) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        // Accept on [a-z0-9]
                        ix += 1;
                        col += 1;
                    }
                },

                .uncapitalized => { // _ A-Z a-z 0-9 $
                    if (next_char == '_') {
                        // => underscore on _
                        ix += 1;
                        col += 1;
                        state = .underscore;
                    } else if (std.ascii.isUpper(next_char)) {
                        // => error on [A-Z]
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "camelCase is not supported",
                        } });
                        return Lexer_Errors.LexerError;
                    } else if (ix == contents.len or !std.ascii.isAlphanumeric(next_char)) {
                        // Split on $
                        var token = token_.Token.init(contents[slice_start..ix], null, filename, contents, line, col);
                        if (fuzz_tokens) {
                            fuzz_token(&token);
                        }
                        tokens.append(token) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        // Accept on [a-z0-9]
                        ix += 1;
                        col += 1;
                    }
                },

                .string => {
                    if (ix == contents.len) {
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "expected `\"`, got end-of-file",
                        } });
                        return Lexer_Errors.LexerError;
                    } else switch (next_char) {
                        '"' => {
                            ix += 1;
                            col += 1;
                            tokens.append(
                                token_.Token.init(contents[slice_start..ix], .string, filename, contents, line, col),
                            ) catch unreachable;
                            slice_start = ix;
                            state = .none;
                        },
                        '\\' => {
                            ix += 1;
                            col += 1;
                            state = .escapedString;
                        },
                        else => {
                            ix += 1;
                            col += 1;
                        },
                    }
                },

                .escapedString => {
                    if (ix == contents.len) {
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "expected a string, got end-of-file",
                        } });
                        return Lexer_Errors.LexerError;
                    } else if (next_char == 'n' or
                        next_char == 'r' or
                        next_char == 't' or
                        next_char == '\\' or
                        next_char == '\'' or
                        next_char == '"')
                    {
                        ix += 1;
                        col += 1;
                        state = .string;
                    } else if (next_char == 'x') {
                        ix += 1;
                        col += 1;
                        state = .byte_string1;
                    } else {
                        errors.add_error(errs_.Error{ .invalid_escape = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                        } });
                        return Lexer_Errors.LexerError;
                    }
                },

                .byte_string1 => {
                    if (std.ascii.isDigit(next_char) or
                        ('a' <= next_char and next_char <= 'f') or
                        ('A' <= next_char and next_char <= 'F'))
                    {
                        ix += 1;
                        col += 1;
                        state = .byte_string2;
                    } else {
                        errors.add_error(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "hexadecimal",
                        } });
                        return Lexer_Errors.LexerError;
                    }
                },

                .byte_string2 => {
                    if (std.ascii.isDigit(next_char) or
                        ('a' <= next_char and next_char <= 'f') or
                        ('A' <= next_char and next_char <= 'F'))
                    {
                        ix += 1;
                        col += 1;
                        state = .string;
                    } else {
                        errors.add_error(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "hexadecimal",
                        } });
                        return Lexer_Errors.LexerError;
                    }
                },

                .char => {
                    if (ix == contents.len) {
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "expected a `'`, got end-of-file",
                        } });
                        return Lexer_Errors.LexerError;
                    } else switch (next_char) {
                        '\'' => {
                            ix += 1;
                            col += 1;
                            const num_codepoints = try std.unicode.utf8CountCodepoints(contents[slice_start + 1 .. ix - 1]);
                            const escaped = contents[slice_start + 1] == '\\';
                            if ((!escaped and num_codepoints > 1) or (escaped and num_codepoints > 2)) {
                                errors.add_error(errs_.Error{ .basic = .{
                                    .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                                    .msg = "more than one codepoint specified in character literal",
                                } });
                                return Lexer_Errors.LexerError;
                            }
                            tokens.append(
                                token_.Token.init(contents[slice_start..ix], .char, filename, contents, line, col),
                            ) catch unreachable;
                            slice_start = ix;
                            state = .none;
                        },
                        '\\' => {
                            ix += 1;
                            col += 1;
                            state = .escapedChar;
                        },
                        else => {
                            ix += 1;
                            col += 1;
                        },
                    }
                },

                .escapedChar => {
                    if (ix == contents.len) {
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "expected a character, got end-of-file",
                        } });
                        return Lexer_Errors.LexerError;
                    } else if (next_char == 'n' or
                        next_char == 'r' or
                        next_char == 't' or
                        next_char == '\\' or
                        next_char == '\'' or
                        next_char == '"')
                    {
                        ix += 1;
                        col += 1;
                        state = .char;
                    } else {
                        errors.add_error(errs_.Error{ .invalid_escape = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                        } });
                        return Lexer_Errors.LexerError;
                    }
                },

                .integer => {
                    if (next_char == '.') {
                        if (ix + 1 < contents.len and std.ascii.isDigit(contents[ix + 1])) {
                            // floating-point
                            ix += 1;
                            col += 1;
                            state = .float;
                        } else {
                            tokens.append(
                                token_.Token.init(contents[slice_start..ix], .dec_int, filename, contents, line, col),
                            ) catch unreachable;
                            slice_start = ix;
                            state = .none;
                        }
                    } else if (ix - slice_start > 0 and contents[slice_start] == '0' and is_base_identifier(next_char)) {
                        // Base identifier
                        ix += 1;
                        col += 1;
                        state = Lex_State.state_from_integer(next_char);
                    } else if (next_char == '_') {
                        ix += 1;
                        col += 1;
                        state = .integer_digit;
                    } else if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .dec_int, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },

                .integer_digit => {
                    if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                        errors.add_error(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "decimal",
                        } });
                        return error.LexerError;
                    } else {
                        ix += 1;
                        col += 1;
                        state = .integer;
                    }
                },

                .float => {
                    if (next_char == '_') {
                        ix += 1;
                        col += 1;
                        state = .float_digit;
                    } else if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .float, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },

                .float_digit => if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                    errors.add_error(errs_.Error{ .invalid_digit = .{
                        .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                        .digit = next_char,
                        .base = "decimal",
                    } });
                    return error.LexerError;
                } else {
                    ix += 1;
                    col += 1;
                    state = .float;
                },

                .hex => switch (next_char) {
                    '_' => {
                        ix += 1;
                        col += 1;
                        state = .hex_digit;
                    },
                    '0'...'9', 'a'...'f', 'A'...'F' => {
                        ix += 1;
                        col += 1;
                    },
                    else => {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .hex_int, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    },
                },

                .hex_digit => switch (next_char) {
                    '0'...'9', 'a'...'f', 'A'...'F' => {
                        ix += 1;
                        col += 1;
                        state = .hex;
                    },
                    else => {
                        errors.add_error(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "hexadecimal",
                        } });
                        return error.LexerError;
                    },
                },

                .octal => switch (next_char) {
                    '_' => {
                        ix += 1;
                        col += 1;
                        state = .octal_digit;
                    },
                    '0'...'7' => {
                        ix += 1;
                        col += 1;
                    },
                    else => {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .oct_int, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    },
                },

                .octal_digit => switch (next_char) {
                    '0'...'7' => {
                        ix += 1;
                        col += 1;
                        state = .octal;
                    },
                    else => {
                        errors.add_error(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "octal",
                        } });
                        return error.LexerError;
                    },
                },

                .binary => switch (next_char) {
                    '_' => {
                        ix += 1;
                        col += 1;
                        state = .binary_digit;
                    },
                    '0'...'1' => {
                        ix += 1;
                        col += 1;
                    },
                    else => {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .bin_int, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    },
                },

                .binary_digit => switch (next_char) {
                    '0'...'1' => {
                        ix += 1;
                        col += 1;
                        state = .binary;
                    },
                    else => {
                        errors.add_error(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "binary",
                        } });
                        return error.LexerError;
                    },
                },

                .symbol => {
                    if (ix - slice_start > 0 and contents[slice_start] == '\\' and next_char == '\\') {
                        state = .multiline;
                        ix += 1;
                        col += 1;
                    } else if (ix - slice_start > 0 and contents[slice_start] == '/' and next_char == '/') {
                        // comment (because of the maximal munch thing I think this isnt even needed...)
                        state = .comment;
                        ix += 1;
                        col += 1;
                    } else if (ix == contents.len or token_.Token_Kind.from_string(contents[slice_start .. ix + 1]) == .identifier) {
                        // Couldn't maximally munch, this must be the end of the token
                        const token = token_.Token.init(contents[slice_start..ix], null, filename, contents, line, col);
                        tokens.append(token) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },

                .multiline => {
                    if (next_char == '\n') {
                        tokens.append(
                            token_.Token.init(contents[slice_start + 2 .. ix], .multi_line_string, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },

                .comment => {
                    if (next_char == '\n') {
                        tokens.append(token_.Token.init("", .comment, filename, contents, line, col)) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },
            }
        }

        tokens.append(token_.Token.init("\n", .newline, filename, contents, line, col)) catch unreachable;
    }

    tokens.append(token_.Token.init("EOF", .EOF, filename, "", line, col)) catch unreachable;
    return tokens;
}

fn fuzz_token(token: *token_.Token) void {
    if (std.mem.eql(u8, token.data, "newline")) {
        token.kind = .newline;
    } else if (std.mem.eql(u8, token.data, "eof")) {
        token.kind = .newline;
    } else if (std.mem.eql(u8, token.data, "int") or
        std.mem.eql(u8, token.data, "hex") or
        std.mem.eql(u8, token.data, "oct") or
        std.mem.eql(u8, token.data, "bin"))
    {
        const some_random_num = rnd.random().int(i32);
        token.kind = .dec_int;
        switch (@mod(some_random_num, 3)) {
            0 => token.data = "0",
            1 => token.data = "1",
            2 => token.data = "2",
            else => unreachable,
        }
    } else if (std.mem.eql(u8, token.data, "char")) {
        const some_random_num = rnd.random().int(i32);
        token.kind = .char;
        switch (@mod(some_random_num, 3)) {
            0 => token.data = "'0'",
            1 => token.data = "'1'",
            2 => token.data = "'2'",
            else => unreachable,
        }
    } else if (std.mem.eql(u8, token.data, "ident")) {
        const some_random_num = rnd.random().int(i69);
        switch (@mod(some_random_num, 2)) {
            0 => switch (@mod(@divTrunc(some_random_num, 2), 7)) {
                0 => token.data = "Bool",
                1 => token.data = "Byte",
                2 => token.data = "Char",
                3 => token.data = "Float",
                4 => token.data = "Int",
                5 => token.data = "String",
                else => token.data = "Type",
            },
            else => switch (@mod(@divTrunc(some_random_num, 2), 3)) {
                0 => token.data = "main",
                1 => token.data = "a",
                else => token.data = "b",
            },
        }
    }
}

fn is_base_identifier(c: u8) bool {
    return switch (c) {
        'x', 'o', 'b' => true,
        else => false,
    };
}
