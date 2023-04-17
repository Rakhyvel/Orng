const token_ = @import("token.zig");
const Token = token_.Token;
const span = @import("span.zig");
const Span = span.Span;
const std = @import("std");
const errors = @import("errors.zig");
const Error = errors.Error;

const LexerErrors = error{lexerError};

pub fn getTokens(contents: []const u8, allocator: std.mem.Allocator) !std.ArrayList(Token) {
    const LexState = enum { //
        none,
        whitespace,
        ident,
        string,
        escapedString,
        char,
        escapedChar,
        integer,
        integerDigit,
        real,
        realDigit,
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
    var line: i64 = 1;
    var col: i64 = 0;

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
                if (!std.ascii.isWhitespace(next_char)) {
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
                if (!std.ascii.isAlphanumeric(next_char) and next_char != '_' and next_char != '\'') {
                    try tokens.append(Token.create(contents[slice_start..ix], null, line, col));
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .string => switch (next_char) {
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
            },

            .escapedString => {
                ix += 1;
                col += 1;
                state = .string;
            },

            .char => switch (next_char) {
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
            },

            .escapedChar => {
                ix += 1;
                col += 1;
                state = .char;
            },

            .integer => {
                if (next_char == '.' and std.ascii.isDigit(contents[ix + 1])) {
                    // real number
                    ix += 1;
                    col += 1;
                    state = .real;
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'x') {
                    // hexadecimal
                    ix += 1;
                    col += 1;
                    state = .hex;
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'o') {
                    // octal
                    ix += 1;
                    col += 1;
                    state = .octal;
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'b') {
                    // binary
                    ix += 1;
                    col += 1;
                    state = .binary;
                } else if (next_char == '\'') {
                    ix += 1;
                    col += 1;
                    state = .integerDigit;
                } else if (!std.ascii.isDigit(next_char)) {
                    try tokens.append(Token.create(contents[slice_start..ix], .DECIMAL_INTEGER, line, col));
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .integerDigit => {
                if (!std.ascii.isDigit(next_char)) {
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid integer literal" } });
                    return error.lexerError;
                } else {
                    ix += 1;
                    col += 1;
                    state = .integer;
                }
            },

            .real => {
                if (next_char == '\'') {
                    ix += 1;
                    col += 1;
                    state = .realDigit;
                } else if (!std.ascii.isDigit(next_char)) {
                    try tokens.append(Token.create(contents[slice_start..ix], .REAL, line, col));
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                    col += 1;
                }
            },

            .realDigit => if (!std.ascii.isDigit(next_char)) {
                errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid floating point literal" } });
                return error.lexerError;
            } else {
                ix += 1;
                col += 1;
                state = .real;
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid hexadecimal integer literal" } });
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid octal integer literal" } });
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
                    errors.addError(Error{ .basic = .{ .span = span.Span{ .col = col, .line = line }, .msg = "invalid binary integer literal" } });
                    return error.lexerError;
                },
            },

            .symbol => {
                if (ix - slice_start > 0 and contents[slice_start] == '/' and next_char == '/') {
                    // comment
                    state = .comment;
                    ix += 1;
                    col += 1;
                } else if (ix == contents.len or token_.kindFromString(contents[slice_start .. ix + 1]) == .IDENTIFIER) { // Couldn't maximally munch, this must be the end of the token
                    try tokens.append(Token.create(contents[slice_start..ix], null, line, col));
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

// TESTS BEGIN HERE (its *literally impossible* to put them in separate files... thanks Andrew!)

test "whitespace" {}

test "identifier" {
    const contents = "one two three";
    var tokens = try getTokens(contents, std.testing.allocator);
    defer tokens.deinit();

    try std.testing.expectEqual(tokens.items.len, 4);
    try std.testing.expectEqual(tokens.items[0].kind, .IDENTIFIER);
    try std.testing.expectEqual(tokens.items[1].kind, .IDENTIFIER);
    try std.testing.expectEqual(tokens.items[2].kind, .IDENTIFIER);
    try std.testing.expectEqual(tokens.items[3].kind, .EOF);
}

test "integer" {}

test "string" {}

test "char" {}

test "symbol" {}
