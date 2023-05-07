const token_ = @import("token.zig");
const Token = token_.Token;
const span = @import("span.zig");
const Span = span.Span;
const std = @import("std");
const errs = @import("errors.zig");
const Error = errs.Error;

const LexerErrors = error{lexerError};

// Has to be done separately from the lexer, because the lexer might throw errors, which would need to be printed out
// However, we couldn't print out the line for the error if we did tokens and lines at the same time
// It's desirable to print the line, therefore lines must be done before tokens
pub fn getLines(contents: []const u8, lines: *std.ArrayList([]const u8)) !void {
    var start: usize = 0;
    var end: usize = 1;
    while (end < contents.len) : (end += 1) {
        if (contents[end] == '\n') {
            try lines.append(contents[start..end]);
            start = end + 1;
        }
    }
    try lines.append(contents[start..end]);
}

/// Will always end in an EOF on the first column of the next line
pub fn getTokens(contents: []const u8, errors: *errs.Errors, fuzz_tokens: bool, allocator: std.mem.Allocator) !std.ArrayList(Token) {
    const LexState = enum {
        none,
        whitespace,
        ident,
        string,
        escapedString,
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
        comment,
    };

    var tokens = std.ArrayList(Token).init(allocator);
    var slice_start: usize = 0;
    var ix: usize = 0;
    var state: LexState = .none;
    var line: usize = 1;
    var col: usize = 0;

    while (ix < contents.len + 1) {
        // It should be ok to not have a newline at the end of a file
        // DO NOT assume ix < contents.len. DO NOT do contents[ix] besides the following line
        const next_char = if (ix < contents.len) contents[ix] else '\n';

        switch (state) {
            .none => {
                if (std.ascii.isWhitespace(next_char)) {
                    state = .whitespace;
                    if (next_char == '\n') {
                        line += 1;
                        col = 0;
                    }
                } else if (std.ascii.isAlphabetic(next_char) or next_char == '_') {
                    state = .ident;
                } else if (std.ascii.isDigit(next_char)) {
                    state = .integer;
                } else if (next_char == '"') {
                    state = .string;
                } else if (next_char == '\'') {
                    state = .char;
                } else {
                    state = .symbol;
                }
                ix += 1;
                col += 1;
            },

            .whitespace => {
                if (ix == contents.len or !std.ascii.isWhitespace(next_char)) {
                    // If token doesn't contain a newline, just ignore it
                    // If it does, the data is from the newline all the way to the end
                    var maybe_last_newline_ix: ?usize = null;
                    var jx = slice_start;
                    while (jx < ix) : (jx += 1) {
                        if (contents[jx] == '\n') {
                            maybe_last_newline_ix = jx;
                        }
                    }
                    if (maybe_last_newline_ix) |last_newline_ix| {
                        try tokens.append(Token.create(contents[last_newline_ix..ix], .NEWLINE, line, col));
                    }

                    slice_start = ix;
                    state = .none;
                } else if (next_char == '\n') {
                    line += 1;
                    ix += 1;
                    col = 0;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .ident => {
                if (ix == contents.len or !std.ascii.isAlphanumeric(next_char) and next_char != '_' and next_char != '\'') {
                    var token = Token.create(contents[slice_start..ix], null, line, col);
                    if (fuzz_tokens) {
                        if (std.mem.eql(u8, token.data, "indent")) {
                            token.kind = .INDENT;
                        } else if (std.mem.eql(u8, token.data, "dedent")) {
                            token.kind = .DEDENT;
                        } else if (std.mem.eql(u8, token.data, "newline")) {
                            token.kind = .NEWLINE;
                        } else if (std.mem.eql(u8, token.data, "back_slash")) {
                            token.kind = .BACK_SLASH;
                        } else if (std.mem.eql(u8, token.data, "ident")) {
                            const RndGen = std.rand.DefaultPrng;
                            var rnd = RndGen.init(0);
                            var some_random_num = rnd.random().int(i32);
                            switch (@rem(some_random_num, 3)) {
                                0 => token.data = "main",
                                1 => token.data = "a",
                                2 => token.data = "b",
                                else => unreachable,
                            }
                        }
                        // TODO: Replace `ident`, `int`, `hex`, `octal`, `bin`, `float`, `char`, `string` with random values
                    }
                    try tokens.append(token);
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .string => {
                if (ix == contents.len) {
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "expected `\"`, got end-of-file", .stage = .tokenization } });
                    return LexerErrors.lexerError;
                } else switch (next_char) {
                    '"' => {
                        ix += 1;
                        col += 1;
                        try tokens.append(Token.create(contents[slice_start..ix], .STRING, line, col));
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "expected a character, got end-of-file", .stage = .tokenization } });
                    return LexerErrors.lexerError;
                } else {
                    ix += 1;
                    col += 1;
                    state = .string;
                }
            },

            .char => {
                if (ix == contents.len) {
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "expected a `'`, got end-of-file", .stage = .tokenization } });
                    return LexerErrors.lexerError;
                } else switch (next_char) {
                    '\'' => {
                        ix += 1;
                        col += 1;
                        try tokens.append(Token.create(contents[slice_start..ix], .CHAR, line, col));
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "expected a character, got end-of-file", .stage = .tokenization } });
                    return LexerErrors.lexerError;
                } else {
                    ix += 1;
                    col += 1;
                    state = .char;
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
                        return error.lexerError;
                    }
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'x') {
                    // hexadecimal
                    ix += 1;
                    col += 1;
                    state = .hexDigit;
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'o') {
                    // octal
                    ix += 1;
                    col += 1;
                    state = .octalDigit;
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'b') {
                    // binary
                    ix += 1;
                    col += 1;
                    state = .binaryDigit;
                } else if (next_char == '\'') {
                    ix += 1;
                    col += 1;
                    state = .integerDigit;
                } else if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                    try tokens.append(Token.create(contents[slice_start..ix], .DECIMAL_INTEGER, line, col));
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .integerDigit => {
                if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid integer literal", .stage = .tokenization } });
                    return error.lexerError;
                } else {
                    ix += 1;
                    col += 1;
                    state = .integer;
                }
            },

            .float => {
                if (next_char == '\'') {
                    ix += 1;
                    col += 1;
                    state = .floatDigit;
                } else if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                    try tokens.append(Token.create(contents[slice_start..ix], .FLOAT, line, col));
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .floatDigit => if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid floating point literal", .stage = .tokenization } });
                return error.lexerError;
            } else {
                ix += 1;
                col += 1;
                state = .float;
            },

            .hex => switch (next_char) {
                '\'' => {
                    ix += 1;
                    col += 1;
                    state = .hexDigit;
                },
                '0'...'9', 'a'...'f', 'A'...'F' => {
                    ix += 1;
                    col += 1;
                },
                else => {
                    try tokens.append(Token.create(contents[slice_start..ix], .HEX_INTEGER, line, col));
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid hexadecimal integer literal", .stage = .tokenization } });
                    return error.lexerError;
                },
            },

            .octal => switch (next_char) {
                '\'' => {
                    ix += 1;
                    col += 1;
                    state = .octalDigit;
                },
                '0'...'7' => {
                    ix += 1;
                    col += 1;
                },
                else => {
                    try tokens.append(Token.create(contents[slice_start..ix], .OCT_INTEGER, line, col));
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid octal integer literal", .stage = .tokenization } });
                    return error.lexerError;
                },
            },

            .binary => switch (next_char) {
                '\'' => {
                    ix += 1;
                    col += 1;
                    state = .binaryDigit;
                },
                '0'...'1' => {
                    ix += 1;
                    col += 1;
                },
                else => {
                    try tokens.append(Token.create(contents[slice_start..ix], .BIN_INTEGER, line, col));
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid binary integer literal", .stage = .tokenization } });
                    return error.lexerError;
                },
            },

            .symbol => {
                if (ix - slice_start > 0 and contents[slice_start] == '/' and next_char == '/') {
                    // comment (because of the maximal munch thing I think this isnt even needed...)
                    state = .comment;
                    ix += 1;
                    col += 1;
                } else if (ix == contents.len or token_.kindFromString(contents[slice_start .. ix + 1]) == .IDENTIFIER) { // Couldn't maximally munch, this must be the end of the token
                    var token = Token.create(contents[slice_start..ix], null, line, col);
                    try tokens.append(token);
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .comment => {
                if (next_char == '\n') {
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },
        }
    }

    try tokens.append(Token.create("EOF", .EOF, line, col));
    return tokens;
}

//////////////////////
// TESTS BEGIN HERE //
//////////////////////

test "whitespace" {
    const contents = "\n  \n    ";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();

    try std.testing.expectEqual(@as(usize, 2), tokens.items.len);
    try tokens.items[0].expectToken(.NEWLINE, "\n    ", 4, 3);
    try tokens.items[1].expectToken(.EOF, "EOF", 1, 4);
}

test "identifier" {
    const contents = "one _two three'";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();

    try std.testing.expectEqual(tokens.items.len, 4);
    try tokens.items[0].expectToken(.IDENTIFIER, "one", 3, 1);
    try tokens.items[1].expectToken(.IDENTIFIER, "_two", 8, 1);
    try tokens.items[2].expectToken(.IDENTIFIER, "three'", 15, 1);
    try tokens.items[3].expectToken(.EOF, "EOF", 1, 2);
}

test "numbers" {
    const contents = "10.0'0 0xAB'C 0o77'7 0b11'1 10'0";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();

    try std.testing.expectEqual(tokens.items.len, 6);
    try tokens.items[0].expectToken(.FLOAT, "10.0'0", 6, 1);
    try tokens.items[1].expectToken(.HEX_INTEGER, "0xAB'C", 13, 1);
    try tokens.items[2].expectToken(.OCT_INTEGER, "0o77'7", 20, 1);
    try tokens.items[3].expectToken(.BIN_INTEGER, "0b11'1", 27, 1);
    try tokens.items[4].expectToken(.DECIMAL_INTEGER, "10'0", 32, 1);
    try tokens.items[5].expectToken(.EOF, "EOF", 1, 2);
}

test "string" {
    const contents = "\"a \\\"string\\\"\"";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();

    try std.testing.expectEqual(tokens.items.len, 2);
    try tokens.items[0].expectToken(.STRING, "\"a \\\"string\\\"\"", 14, 1);
    try tokens.items[1].expectToken(.EOF, "EOF", 1, 2);
}

test "string-eof" {
    const contents = "\"this isn't a string- it's an error!";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokensOrErr = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(LexerErrors.lexerError, tokensOrErr);
    try std.testing.expectEqual(@as(usize, errors.errors_list.items.len), 1);
}

test "string-escape eof" {
    const contents = "\"this isn't a string- it's an error! \\";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokensOrErr = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(LexerErrors.lexerError, tokensOrErr);
    try std.testing.expectEqual(@as(usize, errors.errors_list.items.len), 1);
}

test "char" {
    const contents = "\'a \\\'character\\\'\'";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();

    try std.testing.expectEqual(tokens.items.len, 2);
    try tokens.items[0].expectToken(.CHAR, "\'a \\\'character\\\'\'", 17, 1);
    try tokens.items[1].expectToken(.EOF, "EOF", 1, 2);
}

test "char-eof" {
    const contents = "\'a \\\'character\\\'";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokensOrErr = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(LexerErrors.lexerError, tokensOrErr);
    try std.testing.expectEqual(@as(usize, errors.errors_list.items.len), 1);
}

test "char-escaped eof" {
    const contents = "\'a \\\'character\\";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokensOrErr = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(LexerErrors.lexerError, tokensOrErr);
    try std.testing.expectEqual(@as(usize, errors.errors_list.items.len), 1);
}

test "symbol" {
    const contents = "([{==<+}])";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();

    try std.testing.expectEqual(tokens.items.len, 10);
    try tokens.items[0].expectToken(.L_PAREN, "(", 1, 1);
    try tokens.items[1].expectToken(.L_SQUARE, "[", 2, 1);
    try tokens.items[2].expectToken(.L_BRACE, "{", 3, 1);
    try tokens.items[3].expectToken(.D_EQUALS, "==", 5, 1);
    try tokens.items[4].expectToken(.LSR, "<", 6, 1);
    try tokens.items[5].expectToken(.PLUS, "+", 7, 1);
    try tokens.items[6].expectToken(.R_BRACE, "}", 8, 1);
    try tokens.items[7].expectToken(.R_SQUARE, "]", 9, 1);
    try tokens.items[8].expectToken(.R_PAREN, ")", 10, 1);
    try tokens.items[9].expectToken(.EOF, "EOF", 1, 2);
}

test "comment" {
    const contents = "==// This is a comment! haha";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();

    try std.testing.expectEqual(tokens.items.len, 2);
    try tokens.items[0].expectToken(.D_EQUALS, "==", 2, 1);
    try tokens.items[1].expectToken(.EOF, "EOF", 1, 2);
}

test "integer-error" {
    const contents = "100'abc";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(error.lexerError, tokens);
}

test "float-eof" {
    const contents = "1.";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(error.lexerError, tokens);
}

test "float-error" {
    const contents = "1.a";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(error.lexerError, tokens);
}

test "hex-error" {
    const contents = "0xG";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(error.lexerError, tokens);
}

test "octal-error" {
    const contents = "0o9";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(error.lexerError, tokens);
}

test "binary-error" {
    const contents = "0b2";
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = getTokens(contents, &errors, std.testing.allocator);

    try std.testing.expectError(error.lexerError, tokens);
}
