const Token = @import("token.zig").Token;
const std = @import("std");

const LexerErrors = error{lexerError};

pub fn getTokens(contents: []u8, allocator: std.mem.Allocator) !std.ArrayList(Token) {
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

    var retval = std.ArrayList(Token).init(allocator);
    var slice_start: usize = 0;
    var ix: usize = 0;
    var state: LexState = .none;

    while (ix < contents.len + 1) {
        // It should be ok to not have a newline at the end of a file
        // DO NOT assume ix < contents.len. DO NOT do contents[ix] besides the following line
        const next_char = if (ix < contents.len) contents[ix] else '\n';

        switch (state) {
            .none => {
                if (std.ascii.isWhitespace(next_char)) {
                    state = .whitespace;
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
            },

            .whitespace => {
                if (!std.ascii.isWhitespace(next_char)) {
                    std.debug.print("whitespace: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                }
            },

            .ident => {
                if (!std.ascii.isAlphanumeric(next_char) and next_char != '_' and next_char != '\'') {
                    std.debug.print("identifier: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                }
            },

            .string => {
                if (next_char == '"') {
                    ix += 1;
                    std.debug.print("string: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                }
            },

            .escapedString => {},

            .char => {
                if (next_char == '\'') {
                    ix += 1;
                    std.debug.print("char: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                }
            },

            .escapedChar => {},

            .integer => {
                if (next_char == '.') {
                    // real number
                    ix += 1;
                    state = .real;
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'x') {
                    // hexadecimal
                    ix += 1;
                    state = .hex;
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'o') {
                    // octal
                    ix += 1;
                    state = .octal;
                } else if (ix - slice_start > 0 and contents[slice_start] == '0' and next_char == 'b') {
                    // binary
                    ix += 1;
                    state = .binary;
                } else if (next_char == '\'') {
                    ix += 1;
                    state = .integerDigit;
                } else if (!std.ascii.isDigit(next_char)) {
                    std.debug.print("integer: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                }
            },

            .integerDigit => {
                if (!std.ascii.isDigit(next_char)) {
                    return error.lexerError;
                } else {
                    ix += 1;
                    state = .integer;
                }
            },

            .real => {
                if (next_char == '\'') {
                    ix += 1;
                    state = .realDigit;
                } else if (!std.ascii.isDigit(next_char)) {
                    std.debug.print("real: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                }
            },

            .realDigit => if (!std.ascii.isDigit(next_char)) {
                return error.lexerError;
            } else {
                ix += 1;
                state = .real;
            },

            .hex => switch (next_char) {
                '\'' => {
                    ix += 1;
                    state = .hexDigit;
                },
                '0'...'9', 'a'...'f', 'A'...'F' => {
                    ix += 1;
                },
                else => {
                    std.debug.print("hex: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                },
            },

            .hexDigit => switch (next_char) {
                '0'...'9', 'a'...'f', 'A'...'F' => {
                    ix += 1;
                    state = .hex;
                },
                else => {
                    return error.lexerError;
                },
            },

            .octal => switch (next_char) {
                '\'' => {
                    ix += 1;
                    state = .octalDigit;
                },
                '0'...'7' => {
                    ix += 1;
                },
                else => {
                    std.debug.print("octal: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                },
            },

            .octalDigit => switch (next_char) {
                '0'...'7' => {
                    ix += 1;
                    state = .octal;
                },
                else => {
                    return error.lexerError;
                },
            },

            .binary => switch (next_char) {
                '\'' => {
                    ix += 1;
                    state = .binaryDigit;
                },
                '0'...'1' => {
                    ix += 1;
                },
                else => {
                    std.debug.print("octal: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                },
            },

            .binaryDigit => switch (next_char) {
                '0'...'1' => {
                    ix += 1;
                    state = .binary;
                },
                else => {
                    std.debug.print("octal: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                },
            },

            .symbol => {
                if (ix - slice_start > 0 and contents[slice_start] == '/' and next_char == '/') {
                    // comment
                    state = .comment;
                    ix += 1;
                } else if (contents[slice_start] == '(' //
                or contents[slice_start] == ')' //
                or contents[slice_start] == '[' //
                or contents[slice_start] == ']' //
                or contents[slice_start] == '{' //
                or contents[slice_start] == '}' //
                or std.ascii.isWhitespace(next_char) or std.ascii.isAlphanumeric(next_char)) {
                    std.debug.print("symbol: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                }
            },

            .comment => {
                if (next_char == '\n') {
                    std.debug.print("comment: {s}\n", .{contents[slice_start..ix]});
                    slice_start = ix;
                    state = .none;
                } else {
                    ix += 1;
                }
            },
        }
    }

    return retval;
}
