const std = @import("std");
const errs_ = @import("errors.zig");
const span_ = @import("span.zig");
const token_ = @import("token.zig");

const LexerErrors = error{lexerError};
const RndGen = std.rand.DefaultPrng;
var rnd = RndGen.init(0);

// Has to be done separately from the lexer, because the lexer might throw errors, which would need to be printed out
// However, we couldn't print out the line for the error if we did tokens and lines at the same time
// It's desirable to print the line, therefore lines must be done before tokens
// TODO: Move to own file
pub fn getLines(contents: []const u8, lines: *std.ArrayList([]const u8), errors: *errs_.Errors) !void {
    var start: usize = 0;
    var end: usize = 1;
    if (contents.len == 0) {
        errors.addError(errs_.Error{ .basic = .{
            .span = span_.Span{ .filename = "", .line_text = "", .line = 0, .col = 0 },
            .msg = "file is empty",
        } });
        return error.lexerError;
    }
    while (end < contents.len) : (end += 1) {
        if (contents[end] == '\n') {
            lines.append(contents[start..end]) catch unreachable;
            start = end + 1;
        }
    }
    lines.append(contents[start..end]) catch unreachable;
}

const LexState = enum {
    none,
    whitespace,
    underscore, //           => uncapitalized | capitalized
    capitalized, //          => "_" | e | uncapitalized | all_caps
    all_caps, //             => "_" | e
    uncapitalized, //        => "_" | e
    string,
    escapedString,
    byteString1,
    byteString2,
    char,
    escapedChar,
    integer,
    integerDigit,
    float,
    floatDigit,
    hex,
    hexDigit,
    octal,
    octalDigit,
    binary,
    binaryDigit,
    symbol,
    multiline,
    comment,

    fn state_from_integer(c: u8) LexState {
        return switch (c) {
            'x' => .hexDigit,
            'o' => .octalDigit,
            'b' => .binaryDigit,
            else => unreachable,
        };
    }
};

/// Will always end in an EOF on the first column of the next line
/// TODO: Make scanner a struct with member functions n shiet
pub fn getTokens(
    lines: *std.ArrayList([]const u8),
    filename: []const u8,
    errors: *errs_.Errors,
    fuzz_tokens: bool,
    allocator: std.mem.Allocator,
) !std.ArrayList(token_.Token) {
    var tokens = std.ArrayList(token_.Token).init(allocator);
    var line: usize = 0;
    var col: usize = 1;

    for (lines.items) |contents| {
        var slice_start: usize = 0;
        var ix: usize = 0;
        var state: LexState = .none;
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
                        errors.addError(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .msg = "may not have more than one underscore in a row in an identifier",
                        } });
                        return LexerErrors.lexerError;
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
                        errors.addError(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "identifiers may not end in an underscore",
                        } });
                        return LexerErrors.lexerError;
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
                            errors.addError(errs_.Error{ .basic = .{
                                .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                                .msg = "camelCase is not supported; consider spliting with an underscore",
                            } });
                            return LexerErrors.lexerError;
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
                        errors.addError(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "camelCase is not supported; consider spliting with an underscore",
                        } });
                        return LexerErrors.lexerError;
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
                        errors.addError(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "camelCase is not supported",
                        } });
                        return LexerErrors.lexerError;
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
                        errors.addError(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "expected `\"`, got end-of-file",
                        } });
                        return LexerErrors.lexerError;
                    } else switch (next_char) {
                        '"' => {
                            ix += 1;
                            col += 1;
                            tokens.append(
                                token_.Token.init(contents[slice_start..ix], .STRING, filename, contents, line, col),
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
                        errors.addError(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "expected a string, got end-of-file",
                        } });
                        return LexerErrors.lexerError;
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
                        state = .byteString1;
                    } else {
                        errors.addError(errs_.Error{ .invalid_escape = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                        } });
                        return LexerErrors.lexerError;
                    }
                },

                .byteString1 => {
                    if (std.ascii.isDigit(next_char) or
                        ('a' <= next_char and next_char <= 'f') or
                        ('A' <= next_char and next_char <= 'F'))
                    {
                        ix += 1;
                        col += 1;
                        state = .byteString2;
                    } else {
                        errors.addError(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "hexadecimal",
                        } });
                        return LexerErrors.lexerError;
                    }
                },

                .byteString2 => {
                    if (std.ascii.isDigit(next_char) or
                        ('a' <= next_char and next_char <= 'f') or
                        ('A' <= next_char and next_char <= 'F'))
                    {
                        ix += 1;
                        col += 1;
                        state = .string;
                    } else {
                        errors.addError(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "hexadecimal",
                        } });
                        return LexerErrors.lexerError;
                    }
                },

                .char => {
                    if (ix == contents.len) {
                        errors.addError(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "expected a `'`, got end-of-file",
                        } });
                        return LexerErrors.lexerError;
                    } else switch (next_char) {
                        '\'' => {
                            ix += 1;
                            col += 1;
                            const num_codepoints = try std.unicode.utf8CountCodepoints(contents[slice_start + 1 .. ix - 1]);
                            const escaped = contents[slice_start + 1] == '\\';
                            if ((!escaped and num_codepoints > 1) or (escaped and num_codepoints > 2)) {
                                errors.addError(errs_.Error{ .basic = .{
                                    .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                                    .msg = "more than one codepoint specified in character literal",
                                } });
                                return LexerErrors.lexerError;
                            }
                            tokens.append(
                                token_.Token.init(contents[slice_start..ix], .CHAR, filename, contents, line, col),
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
                        errors.addError(errs_.Error{ .basic = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col, .line = line },
                            .msg = "expected a character, got end-of-file",
                        } });
                        return LexerErrors.lexerError;
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
                        errors.addError(errs_.Error{ .invalid_escape = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                        } });
                        return LexerErrors.lexerError;
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
                                token_.Token.init(contents[slice_start..ix], .DECIMAL_INTEGER, filename, contents, line, col),
                            ) catch unreachable;
                            slice_start = ix;
                            state = .none;
                        }
                    } else if (ix - slice_start > 0 and contents[slice_start] == '0' and is_base_identifier(next_char)) {
                        // Base identifier
                        ix += 1;
                        col += 1;
                        state = LexState.state_from_integer(next_char);
                    } else if (next_char == '_') {
                        ix += 1;
                        col += 1;
                        state = .integerDigit;
                    } else if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .DECIMAL_INTEGER, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },

                .integerDigit => {
                    if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                        errors.addError(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "decimal",
                        } });
                        return error.lexerError;
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
                        state = .floatDigit;
                    } else if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .FLOAT, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },

                .floatDigit => if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                    errors.addError(errs_.Error{ .invalid_digit = .{
                        .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                        .digit = next_char,
                        .base = "decimal",
                    } });
                    return error.lexerError;
                } else {
                    ix += 1;
                    col += 1;
                    state = .float;
                },

                .hex => switch (next_char) {
                    '_' => {
                        ix += 1;
                        col += 1;
                        state = .hexDigit;
                    },
                    '0'...'9', 'a'...'f', 'A'...'F' => {
                        ix += 1;
                        col += 1;
                    },
                    else => {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .HEX_INTEGER, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    },
                },

                .hexDigit => switch (next_char) {
                    '0'...'9', 'a'...'f', 'A'...'F' => {
                        ix += 1;
                        col += 1;
                        state = .hex;
                    },
                    else => {
                        errors.addError(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "hexadecimal",
                        } });
                        return error.lexerError;
                    },
                },

                .octal => switch (next_char) {
                    '_' => {
                        ix += 1;
                        col += 1;
                        state = .octalDigit;
                    },
                    '0'...'7' => {
                        ix += 1;
                        col += 1;
                    },
                    else => {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .OCT_INTEGER, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    },
                },

                .octalDigit => switch (next_char) {
                    '0'...'7' => {
                        ix += 1;
                        col += 1;
                        state = .octal;
                    },
                    else => {
                        errors.addError(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "octal",
                        } });
                        return error.lexerError;
                    },
                },

                .binary => switch (next_char) {
                    '_' => {
                        ix += 1;
                        col += 1;
                        state = .binaryDigit;
                    },
                    '0'...'1' => {
                        ix += 1;
                        col += 1;
                    },
                    else => {
                        tokens.append(
                            token_.Token.init(contents[slice_start..ix], .BIN_INTEGER, filename, contents, line, col),
                        ) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    },
                },

                .binaryDigit => switch (next_char) {
                    '0'...'1' => {
                        ix += 1;
                        col += 1;
                        state = .binary;
                    },
                    else => {
                        errors.addError(errs_.Error{ .invalid_digit = .{
                            .span = span_.Span{ .filename = filename, .line_text = contents, .col = col + 1, .line = line },
                            .digit = next_char,
                            .base = "binary",
                        } });
                        return error.lexerError;
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
                    } else if (ix == contents.len or token_.kindFromString(contents[slice_start .. ix + 1]) == .IDENTIFIER) {
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
                            token_.Token.init(contents[slice_start + 2 .. ix], .MULTI_LINE, filename, contents, line, col),
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
                        tokens.append(token_.Token.init("", .COMMENT, filename, contents, line, col)) catch unreachable;
                        slice_start = ix;
                        state = .none;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                },
            }
        }

        tokens.append(token_.Token.init("\n", .NEWLINE, filename, contents, line, col)) catch unreachable;
    }

    tokens.append(token_.Token.init("EOF", .EOF, filename, "", line, col)) catch unreachable;
    return tokens;
}

fn fuzz_token(token: *token_.Token) void {
    if (std.mem.eql(u8, token.data, "indent")) {
        token.kind = .INDENT;
    } else if (std.mem.eql(u8, token.data, "dedent")) {
        token.kind = .DEDENT;
    } else if (std.mem.eql(u8, token.data, "newline")) {
        token.kind = .NEWLINE;
    } else if (std.mem.eql(u8, token.data, "eof")) {
        token.kind = .NEWLINE;
    } else if (std.mem.eql(u8, token.data, "int") or
        std.mem.eql(u8, token.data, "hex") or
        std.mem.eql(u8, token.data, "oct") or
        std.mem.eql(u8, token.data, "bin"))
    {
        const some_random_num = rnd.random().int(i32);
        token.kind = .DECIMAL_INTEGER;
        switch (@mod(some_random_num, 3)) {
            0 => token.data = "0",
            1 => token.data = "1",
            2 => token.data = "2",
            else => unreachable,
        }
    } else if (std.mem.eql(u8, token.data, "char")) {
        const some_random_num = rnd.random().int(i32);
        token.kind = .CHAR;
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
