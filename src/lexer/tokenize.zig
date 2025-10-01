const std = @import("std");
const Token = @import("token.zig");
const errs_ = @import("../util/errors.zig");
const Span = @import("../util/span.zig");

const Self: type = @This();

const Lexer_Errors = error{LexerError};

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

tokens: *std.array_list.Managed(Token),
filename: []const u8,
errors: *errs_.Errors,
fuzz_tokens: bool,
allocator: std.mem.Allocator,
line_number: usize,
col: usize,
slice_start: usize,
ix: usize,
state: Lex_State,

/// Will always end in an EOF on the first column of the next line
pub fn init(
    filename: []const u8,
    errors: *errs_.Errors,
    fuzz_tokens: bool,
    allocator: std.mem.Allocator,
) Self {
    const retval = Self{
        .tokens = allocator.create(std.array_list.Managed(Token)) catch unreachable,
        .filename = filename,
        .errors = errors,
        .fuzz_tokens = fuzz_tokens,
        .allocator = allocator,
        .line_number = 0,
        .col = 1,
        .slice_start = 0,
        .ix = 0,
        .state = .none,
    };
    retval.tokens.* = std.array_list.Managed(Token).init(allocator);
    return retval;
}

pub fn run(self: *Self, lines: std.array_list.Managed([]const u8)) Lexer_Errors!*std.array_list.Managed(Token) {
    for (lines.items) |line| {
        self.slice_start = 0;
        self.ix = 0;
        self.state = .none;
        self.line_number += 1;
        self.col = 1;

        while (self.ix < line.len + 1) {
            // It should be ok to not have a newline at the end of a file
            // DO NOT assume ix < line.len. DO NOT do line[ix] besides the following line
            const next_char = if (self.ix < line.len) line[self.ix] else '\n';
            try self.state_machine(next_char, line);
        }
        self.tokens.append(Token.init("\n", .newline, self.filename, line, self.line_number, self.col)) catch unreachable;
    }

    self.tokens.append(Token.init("EOF", .EOF, self.filename, "", self.line_number, self.col)) catch unreachable;
    return self.tokens;
}

fn advance_ix(self: *Self, state: Lex_State) void {
    self.ix += 1;
    self.col += 1;
    self.state = state;
}

fn state_machine(self: *Self, next_char: u8, line: []const u8) Lexer_Errors!void {
    switch (self.state) {
        .none => if (std.ascii.isWhitespace(next_char)) {
            self.advance_ix(.whitespace);
        } else if (std.ascii.isLower(next_char)) {
            self.advance_ix(.uncapitalized);
        } else if (std.ascii.isUpper(next_char)) {
            self.advance_ix(.all_caps);
        } else if (std.ascii.isDigit(next_char)) {
            self.advance_ix(.integer);
        } else if (next_char == '"') {
            self.advance_ix(.string);
        } else if (next_char == '\'') {
            self.advance_ix(.char);
        } else {
            self.advance_ix(.symbol);
        },

        .whitespace => if (self.ix == line.len or !std.ascii.isWhitespace(next_char)) {
            self.slice_start = self.ix;
            self.state = .none;
        } else {
            self.advance_ix(self.state);
        },

        .underscore => if (next_char == '_') { // _ A-Z a-z 0-9 $
            // => error on _
            self.advance_ix(self.state);
            return self.throw_basic_error(line, "may not have more than one underscore in a row in an identifier");
        } else if (std.ascii.isUpper(next_char) or std.ascii.isDigit(next_char)) {
            // => all caps on [A-Z0-9]
            self.advance_ix(.all_caps);
        } else if (std.ascii.isLower(next_char)) {
            // => uncaps on [a-z]
            self.advance_ix(.uncapitalized);
        } else {
            // => error on $
            return self.throw_basic_error(line, "identifiers may not end in an underscore");
        },

        .all_caps => if (std.ascii.isLower(next_char)) {
            if (self.ix - self.slice_start > 1 and line[self.ix - 2] != '_') {
                // => error on $ if length is too long
                return self.throw_camel_case_unsupported(line);
            } else {
                // => capitalized on a-z
                self.advance_ix(.capitalized);
            }
        } else {
            self.identifier(line, next_char);
        },

        .capitalized => if (std.ascii.isUpper(next_char)) {
            // => error on [A-Z]
            return self.throw_camel_case_unsupported(line);
        } else {
            self.identifier(line, next_char);
        },

        .uncapitalized => if (std.ascii.isUpper(next_char)) {
            // => error on [A-Z]
            return self.throw_camel_case_unsupported(line);
        } else {
            self.identifier(line, next_char);
        },

        .string => if (self.ix == line.len) {
            return self.throw_basic_error(line, "expected `\"`, got end-of-file");
        } else switch (next_char) {
            '"' => {
                self.advance_ix(.none);
                self.tokens.append(self.create_token(line, .string)) catch unreachable;
                self.slice_start = self.ix;
            },
            '\\' => {
                self.advance_ix(.escapedString);
            },
            else => {
                self.advance_ix(self.state);
            },
        },

        .escapedString => if (self.ix == line.len) {
            return self.throw_basic_error(line, "expected a string, got end-of-file");
        } else if (is_escape(next_char)) {
            self.advance_ix(.string);
        } else if (next_char == 'x') {
            self.advance_ix(.byte_string1);
        } else {
            return self.throw_invalid_escape(line, next_char);
        },

        .byte_string1 => if (is_hex_digit(next_char)) {
            self.advance_ix(.byte_string2);
        } else {
            return self.throw_invalid_decimal(line, next_char, "hexadecimal");
        },

        .byte_string2 => if (is_hex_digit(next_char)) {
            self.advance_ix(.string);
        } else {
            return self.throw_invalid_decimal(line, next_char, "hexadecimal");
        },

        .char => if (self.ix == line.len) {
            return self.throw_basic_error(line, "expected a `'`, got end-of-file");
        } else switch (next_char) {
            '\'' => {
                self.advance_ix(.none);
                const num_codepoints = std.unicode.utf8CountCodepoints(line[self.slice_start + 1 .. self.ix - 1]) catch unreachable;
                const escaped = line[self.slice_start + 1] == '\\';
                if ((!escaped and num_codepoints > 1) or (escaped and num_codepoints > 2)) {
                    return self.throw_basic_error(line, "more than one codepoint specified in character literal");
                }
                self.tokens.append(self.create_token(line, .char)) catch unreachable;
                self.slice_start = self.ix;
            },
            '\\' => {
                self.advance_ix(.escapedChar);
            },
            else => {
                self.advance_ix(self.state);
            },
        },

        .escapedChar => if (self.ix == line.len) {
            return self.throw_basic_error(line, "expected a character, got end-of-file");
        } else if (is_escape(next_char)) {
            self.advance_ix(.char);
        } else {
            return self.throw_invalid_escape(line, next_char);
        },

        .integer => if (next_char == '.') {
            if (self.ix + 1 < line.len and std.ascii.isDigit(line[self.ix + 1])) {
                self.advance_ix(.float);
            } else {
                self.tokens.append(self.create_token(line, .dec_int)) catch unreachable;
                self.slice_start = self.ix;
                self.state = .none;
            }
        } else if (self.ix - self.slice_start > 0 and line[self.slice_start] == '0' and is_base_identifier(next_char)) {
            // Base identifier
            self.advance_ix(Lex_State.state_from_integer(next_char));
        } else if (next_char == '_') {
            self.advance_ix(.integer_digit);
        } else if (self.ix == line.len or !std.ascii.isDigit(next_char)) {
            self.tokens.append(self.create_token(line, .dec_int)) catch unreachable;
            self.slice_start = self.ix;
            self.state = .none;
        } else {
            self.advance_ix(self.state);
        },

        .integer_digit => if (self.ix == line.len or !std.ascii.isDigit(next_char)) {
            return self.throw_invalid_decimal(line, next_char, "decimal");
        } else {
            self.advance_ix(.integer);
        },

        .float => if (next_char == '_') {
            self.advance_ix(.float_digit);
        } else if (self.ix == line.len or !std.ascii.isDigit(next_char)) {
            self.tokens.append(self.create_token(line, .float)) catch unreachable;
            self.slice_start = self.ix;
            self.state = .none;
        } else {
            self.advance_ix(self.state);
        },

        .float_digit => if (self.ix == line.len or !std.ascii.isDigit(next_char)) {
            return self.throw_invalid_decimal(line, next_char, "decimal");
        } else {
            self.advance_ix(.float);
        },

        .hex => switch (next_char) {
            '_' => {
                self.advance_ix(.hex_digit);
            },
            '0'...'9', 'a'...'f', 'A'...'F' => {
                self.advance_ix(self.state);
            },
            else => {
                self.tokens.append(self.create_token(line, .hex_int)) catch unreachable;
                self.slice_start = self.ix;
                self.state = .none;
            },
        },

        .hex_digit => switch (next_char) {
            '0'...'9', 'a'...'f', 'A'...'F' => {
                self.advance_ix(.hex);
            },
            else => {
                return self.throw_invalid_decimal(line, next_char, "hexadecimal");
            },
        },

        .octal => switch (next_char) {
            '_' => {
                self.advance_ix(.octal_digit);
            },
            '0'...'7' => {
                self.advance_ix(self.state);
            },
            else => {
                self.tokens.append(self.create_token(line, .oct_int)) catch unreachable;
                self.slice_start = self.ix;
                self.state = .none;
            },
        },

        .octal_digit => switch (next_char) {
            '0'...'7' => {
                self.advance_ix(.octal);
            },
            else => {
                return self.throw_invalid_decimal(line, next_char, "octal");
            },
        },

        .binary => switch (next_char) {
            '_' => {
                self.advance_ix(.binary_digit);
            },
            '0'...'1' => {
                self.advance_ix(self.state);
            },
            else => {
                self.tokens.append(self.create_token(line, .bin_int)) catch unreachable;
                self.slice_start = self.ix;
                self.state = .none;
            },
        },

        .binary_digit => switch (next_char) {
            '0'...'1' => {
                self.advance_ix(.binary);
            },
            else => {
                return self.throw_invalid_decimal(line, next_char, "binary");
            },
        },

        .symbol => if (self.ix - self.slice_start > 0 and line[self.slice_start] == '\\' and next_char == '\\') {
            self.advance_ix(.multiline);
        } else if (self.ix - self.slice_start > 0 and line[self.slice_start] == '/' and next_char == '/') {
            // comment (because of the maximal munch thing I think this isnt even needed...)
            self.advance_ix(.comment);
        } else if (self.ix == line.len or Token.Kind.from_string(line[self.slice_start .. self.ix + 1]) == .identifier) {
            // Couldn't maximally munch, this must be the end of the token
            const token = self.create_token(line, null);
            self.tokens.append(token) catch unreachable;
            self.slice_start = self.ix;
            self.state = .none;
        } else {
            self.advance_ix(self.state);
        },

        .multiline => if (next_char == '\n') {
            self.tokens.append(
                Token.init(line[self.slice_start + 2 .. self.ix], .multi_line_string, self.filename, line, self.line_number, self.col),
            ) catch unreachable;
            self.slice_start = self.ix;
            self.state = .none;
        } else {
            self.advance_ix(self.state);
        },

        .comment => if (next_char == '\n') {
            self.tokens.append(Token.init("", .comment, self.filename, line, self.line_number, self.col)) catch unreachable;
            self.slice_start = self.ix;
            self.state = .none;
        } else {
            self.advance_ix(self.state);
        },
    }
}

fn get_span(self: *Self, line: []const u8, offset: usize) Span {
    return Span{ .filename = self.filename, .line_text = line, .col = self.col + offset, .line_number = self.line_number };
}

fn throw_invalid_decimal(self: *Self, line: []const u8, digit: u8, base: []const u8) Lexer_Errors {
    self.errors.add_error(errs_.Error{ .invalid_digit = .{
        .span = self.get_span(line, 1),
        .digit = digit,
        .base = base,
    } });
    return Lexer_Errors.LexerError;
}

fn throw_camel_case_unsupported(self: *Self, line: []const u8) Lexer_Errors {
    return self.throw_basic_error(line, "camelCase is not supported");
}

fn throw_invalid_escape(self: *Self, line: []const u8, next_char: u8) Lexer_Errors {
    self.errors.add_error(errs_.Error{ .invalid_escape = .{
        .span = self.get_span(line, 1),
        .digit = next_char,
    } });
    return Lexer_Errors.LexerError;
}

fn throw_basic_error(self: *Self, line: []const u8, msg: []const u8) Lexer_Errors {
    self.errors.add_error(errs_.Error{ .basic = .{
        .span = self.get_span(line, 0),
        .msg = msg,
    } });
    return Lexer_Errors.LexerError;
}

fn identifier(self: *Self, line: []const u8, next_char: u8) void {
    if (next_char == '_') {
        // => underscore on _
        self.advance_ix(.underscore);
    } else if (self.ix == line.len or !std.ascii.isAlphanumeric(next_char)) {
        // Split on $
        var token = self.create_token(line, null);
        if (self.fuzz_tokens) {
            if (std.mem.eql(u8, token.data, "newline") or std.mem.eql(u8, token.data, "eof")) {
                token.kind = .newline;
            }
        }
        self.tokens.append(token) catch unreachable;
        self.slice_start = self.ix;
        self.state = .none;
    } else {
        // Accept alphanum
        self.advance_ix(self.state);
    }
}

/// Creates a token from the Self's line and col and filename
fn create_token(self: *Self, line: []const u8, kind: ?Token.Kind) Token {
    return Token.init(
        line[self.slice_start..self.ix],
        kind,
        self.filename,
        line,
        self.line_number,
        self.col,
    );
}

fn is_base_identifier(c: u8) bool {
    return switch (c) {
        'x', 'o', 'b' => true,
        else => false,
    };
}

fn is_escape(c: u8) bool {
    return switch (c) {
        'n', 'r', 't', '\\', '\'', '"' => true,
        else => false,
    };
}

fn is_hex_digit(c: u8) bool {
    return std.ascii.isDigit(c) or
        ('a' <= c and c <= 'f') or
        ('A' <= c and c <= 'F');
}
