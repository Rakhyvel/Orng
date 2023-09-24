const token_ = @import("token.zig");
const Token = token_.Token;
const span = @import("span.zig");
const Span = span.Span;
const std = @import("std");
const errs = @import("errors.zig");
const Error = errs.Error;

const LexerErrors = error{lexerError};
const RndGen = std.rand.DefaultPrng;
var rnd = RndGen.init(0);

// Has to be done separately from the lexer, because the lexer might throw errors, which would need to be printed out
// However, we couldn't print out the line for the error if we did tokens and lines at the same time
// It's desirable to print the line, therefore lines must be done before tokens
pub fn getLines(contents: []const u8, lines: *std.ArrayList([]const u8), errors: *errs.Errors) !void {
    var start: usize = 0;
    var end: usize = 1;
    if (contents.len == 0) {
        errors.addError(errs.Error{ .basic = .{ .span = Span{ .filename = "", .line = 0, .col = 0 }, .msg = "file is empty" } });
        return error.lexerError;
    }
    while (end < contents.len) : (end += 1) {
        if (contents[end] == '\n') {
            try lines.append(contents[start..end]);
            start = end + 1;
        }
    }
    try lines.append(contents[start..end]);
}

/// Will always end in an EOF on the first column of the next line
pub fn getTokens(contents: []const u8, filename: []const u8, errors: *errs.Errors, fuzz_tokens: bool, allocator: std.mem.Allocator) !std.ArrayList(Token) {
    const LexState = enum {
        none,
        whitespace,
        ident,
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
        comment,
    };

    var tokens = std.ArrayList(Token).init(allocator);
    var slice_start: usize = 0;
    var ix: usize = 0;
    var state: LexState = .none;
    var line: usize = 1;
    var col: usize = 1;

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
                        ix += 1;
                        col = 1;
                    } else {
                        ix += 1;
                        col += 1;
                    }
                } else if (std.ascii.isAlphabetic(next_char) or next_char == '_') {
                    state = .ident;
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
                        try tokens.append(Token.create(contents[last_newline_ix..ix], .NEWLINE, filename, line, col));
                    }

                    slice_start = ix;
                    state = .none;
                } else if (next_char == '\n') {
                    line += 1;
                    ix += 1;
                    col = 1;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .ident => {
                if (ix == contents.len or !std.ascii.isAlphanumeric(next_char) and next_char != '_') {
                    var token = Token.create(contents[slice_start..ix], null, filename, line, col);
                    if (fuzz_tokens) {
                        if (std.mem.eql(u8, token.data, "indent")) {
                            token.kind = .INDENT;
                        } else if (std.mem.eql(u8, token.data, "dedent")) {
                            token.kind = .DEDENT;
                        } else if (std.mem.eql(u8, token.data, "newline")) {
                            token.kind = .NEWLINE;
                        } else if (std.mem.eql(u8, token.data, "eof")) {
                            token.kind = .NEWLINE;
                        } else if (std.mem.eql(u8, token.data, "int") or std.mem.eql(u8, token.data, "hex") or std.mem.eql(u8, token.data, "oct") or std.mem.eql(u8, token.data, "bin")) {
                            var some_random_num = rnd.random().int(i32);
                            token.kind = .DECIMAL_INTEGER;
                            switch (@mod(some_random_num, 3)) {
                                0 => token.data = "0",
                                1 => token.data = "1",
                                2 => token.data = "2",
                                else => unreachable,
                            }
                        } else if (std.mem.eql(u8, token.data, "char")) {
                            var some_random_num = rnd.random().int(i32);
                            token.kind = .CHAR;
                            switch (@mod(some_random_num, 3)) {
                                0 => token.data = "'0'",
                                1 => token.data = "'1'",
                                2 => token.data = "'2'",
                                else => unreachable,
                            }
                        } else if (std.mem.eql(u8, token.data, "ident")) {
                            var some_random_num = rnd.random().int(i69);
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .msg = "expected `\"`, got end-of-file" } });
                    return LexerErrors.lexerError;
                } else switch (next_char) {
                    '"' => {
                        ix += 1;
                        col += 1;
                        try tokens.append(Token.create(contents[slice_start..ix], .STRING, filename, line, col));
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .msg = "expected a character, got end-of-file" } });
                    return LexerErrors.lexerError;
                } else if (next_char == 'n' or next_char == 'r' or next_char == 't' or next_char == '\\' or next_char == '\'' or next_char == '"') {
                    ix += 1;
                    col += 1;
                    state = .string;
                } else if (next_char == 'x') {
                    ix += 1;
                    col += 1;
                    state = .byteString1;
                } else {
                    errors.addError(Error{ .invalid_escape = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .digit = next_char } });
                    return LexerErrors.lexerError;
                }
            },

            .byteString1 => {
                if (std.ascii.isDigit(next_char) or ('a' <= next_char and next_char <= 'f') or ('A' <= next_char and next_char <= 'F')) {
                    ix += 1;
                    col += 1;
                    state = .byteString2;
                } else {
                    errors.addError(Error{ .invalid_digit = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .digit = next_char, .base = "hexadecimal" } });
                    return LexerErrors.lexerError;
                }
            },

            .byteString2 => {
                if (std.ascii.isDigit(next_char) or ('a' <= next_char and next_char <= 'f') or ('A' <= next_char and next_char <= 'F')) {
                    ix += 1;
                    col += 1;
                    state = .string;
                } else {
                    errors.addError(Error{ .invalid_digit = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .digit = next_char, .base = "hexadecimal" } });
                    return LexerErrors.lexerError;
                }
            },

            .char => {
                if (ix == contents.len) {
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .msg = "expected a `'`, got end-of-file" } });
                    return LexerErrors.lexerError;
                } else switch (next_char) {
                    '\'' => {
                        ix += 1;
                        col += 1;
                        var num_codepoints = try std.unicode.utf8CountCodepoints(contents[slice_start + 1 .. ix - 1]);
                        var escaped = contents[slice_start + 1] == '\\';
                        if ((!escaped and num_codepoints > 1) or (escaped and num_codepoints > 2)) {
                            errors.addError(Error{ .basic = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .msg = "more than one codepoint specified in character literal" } });
                            return LexerErrors.lexerError;
                        }
                        try tokens.append(Token.create(contents[slice_start..ix], .CHAR, filename, line, col));
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .msg = "expected a character, got end-of-file" } });
                    return LexerErrors.lexerError;
                } else if (next_char == 'n' or next_char == 'r' or next_char == 't' or next_char == '\\' or next_char == '\'' or next_char == '"') {
                    ix += 1;
                    col += 1;
                    state = .char;
                } else {
                    errors.addError(Error{ .invalid_escape = .{ .span = span.Span{ .filename = filename, .col = col, .line = line }, .digit = next_char } });
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
                        try tokens.append(Token.create(contents[slice_start..ix], .DECIMAL_INTEGER, filename, line, col));
                        slice_start = ix;
                        state = .none;
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
                } else if (next_char == '_') {
                    ix += 1;
                    col += 1;
                    state = .integerDigit;
                } else if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                    try tokens.append(Token.create(contents[slice_start..ix], .DECIMAL_INTEGER, filename, line, col));
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .integerDigit => {
                if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                    errors.addError(Error{ .invalid_digit = .{ .span = span.Span{ .filename = filename, .col = col + 1, .line = line }, .digit = next_char, .base = "decimal" } });
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
                    try tokens.append(Token.create(contents[slice_start..ix], .FLOAT, filename, line, col));
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .floatDigit => if (ix == contents.len or !std.ascii.isDigit(next_char)) {
                errors.addError(Error{ .invalid_digit = .{ .span = span.Span{ .filename = filename, .col = col + 1, .line = line }, .digit = next_char, .base = "decimal" } });
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
                    try tokens.append(Token.create(contents[slice_start..ix], .HEX_INTEGER, filename, line, col));
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
                    errors.addError(Error{ .invalid_digit = .{ .span = span.Span{ .filename = filename, .col = col + 1, .line = line }, .digit = next_char, .base = "hexadecimal" } });
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
                    try tokens.append(Token.create(contents[slice_start..ix], .OCT_INTEGER, filename, line, col));
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
                    errors.addError(Error{ .invalid_digit = .{ .span = span.Span{ .filename = filename, .col = col + 1, .line = line }, .digit = next_char, .base = "octal" } });
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
                    try tokens.append(Token.create(contents[slice_start..ix], .BIN_INTEGER, filename, line, col));
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
                    errors.addError(Error{ .invalid_digit = .{ .span = span.Span{ .filename = filename, .col = col + 1, .line = line }, .digit = next_char, .base = "binary" } });
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
                    var token = Token.create(contents[slice_start..ix], null, filename, line, col);
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
                    try tokens.append(Token.create("", .COMMENT, filename, line, col));
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },
        }
    }

    try tokens.append(Token.create("EOF", .EOF, filename, line, col));
    return tokens;
}
