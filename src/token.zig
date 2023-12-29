const std = @import("std");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;

pub const TokenKind = enum(u32) {
    // Literals
    IDENTIFIER,
    DECIMAL_INTEGER,
    HEX_INTEGER,
    OCT_INTEGER,
    BIN_INTEGER,
    FLOAT,
    CHAR,
    STRING,
    TRUE,
    FALSE,
    MULTI_LINE,

    // Keywords
    AND,
    BREAK,
    MATCH,
    CATCH,
    CASE,
    COMPTIME,
    CONST,
    CONTINUE,
    DEFER,
    ELSE,
    ERRDEFER,
    FN,
    FOR,
    IF,
    IN,
    LET,
    MUT,
    NOT,
    OR,
    ORELSE,
    RETURN,
    TRY,
    UNREACHABLE,
    WHERE,
    WHILE,
    TYPEOF,
    DEFAULT,
    SIZEOF,

    // Equals
    D_EQUALS,
    EQUALS,
    MINUS_EQUALS,
    NOT_EQUALS,
    PERCENT_EQUALS,
    PLUS_EQUALS,
    SLASH_EQUALS,
    STAR_EQUALS,
    D_STAR_EQUALS,

    // Math
    BAR,
    CARET,
    D_BAR,
    D_STAR,
    RIGHT_FAT_ARROW,
    GTR,
    GTE,
    LSR,
    LTE,
    MINUS,
    PERCENT,
    PLUS,
    LEFT_SKINNY_ARROW,
    RIGHT_SKINNY_ARROW,
    SLASH,
    BACKSLASH,
    STAR,

    // Punctuation
    AMPERSAND,
    COLON,
    COMMA,
    D_PERIOD,
    E_MARK,
    PERIOD,
    Q_MARK,
    SEMICOLON,
    AT,

    // Open/Close
    L_BRACE,
    L_PAREN,
    L_SQUARE,
    R_BRACE,
    R_PAREN,
    R_SQUARE,
    INDENT,
    DEDENT,

    // Trait stuff
    INVOKE,

    // Whitespace
    COMMENT,
    NEWLINE,
    EOF,

    // HACK: Used to count how many constructors are in the enum
    // (yes, this is needed in Zig)
    len,

    pub fn is_binop(self: TokenKind) bool {
        for (binaryOperators) |binop_kind| {
            if (self == binop_kind) {
                return true;
            }
        }
        return false;
    }

    pub fn is_end_token(self: TokenKind) bool {
        for (end_tokens) |kind| {
            if (self == kind) {
                return true;
            }
        }
        return false;
    }

    pub fn repr(kind: TokenKind) ?[]const u8 {
        return switch (kind) {
            .BIN_INTEGER,
            .CHAR,
            .DECIMAL_INTEGER,
            .HEX_INTEGER,
            .IDENTIFIER,
            .OCT_INTEGER,
            .FLOAT,
            .STRING,
            .len,
            => null,

            .COMMENT => "<a comment>",
            .NEWLINE => "<a newline>",
            .INDENT => "<indentation>",
            .DEDENT => "<dedentation>",

            .AND => "and",
            .BREAK => "break",
            .MATCH => "match",
            .CATCH => "catch",
            .CASE => "case",
            .COMPTIME => "comptime",
            .CONST => "const",
            .CONTINUE => "continue",
            .DEFER => "defer",
            .ELSE => "else",
            .ERRDEFER => "errdefer",
            .FALSE => "false",
            .FN => "fn",
            .FOR => "for",
            .IF => "if",
            .IN => "in",
            .LET => "let",
            .MUT => "mut",
            .NOT => "not",
            .OR => "or",
            .ORELSE => "orelse",
            .RETURN => "return",
            .TRUE => "true",
            .TRY => "try",
            .UNREACHABLE => "unreachable",
            .WHERE => "where",
            .WHILE => "while",
            .TYPEOF => "typeof",
            .DEFAULT => "default",
            .SIZEOF => "sizeof",

            // Equals
            .D_EQUALS => "==",
            .EQUALS => "=",
            .MINUS_EQUALS => "-=",
            .NOT_EQUALS => "!=",
            .PERCENT_EQUALS => "%=",
            .PLUS_EQUALS => "+=",
            .SLASH_EQUALS => "/=",
            .STAR_EQUALS => "*=",
            .D_STAR_EQUALS => "**=",

            // Math
            .LEFT_SKINNY_ARROW => "<-",
            .BAR => "|",
            .CARET => "^",
            .D_BAR => "||",
            .D_STAR => "**",
            .RIGHT_FAT_ARROW => "=>",
            .GTR => ">",
            .GTE => ">=",
            .LSR => "<",
            .LTE => "<=",
            .MINUS => "-",
            .PERCENT => "%",
            .PLUS => "+",
            .RIGHT_SKINNY_ARROW => "->",
            .SLASH => "/",
            .BACKSLASH => "\\",
            .STAR => "*",

            // Punctuation
            .AMPERSAND => "&",
            .COLON => ":",
            .COMMA => ",",
            .D_PERIOD => "..",
            .E_MARK => "!",
            .PERIOD => ".",
            .Q_MARK => "?",
            .SEMICOLON => ";",
            .MULTI_LINE => "<multi-line>",
            .AT => "@",

            // Open/Close
            .L_BRACE => "{",
            .L_PAREN => "(",
            .L_SQUARE => "[",
            .R_BRACE => "}",
            .R_PAREN => ")",
            .R_SQUARE => "]",

            // Functional
            .INVOKE => ".>",

            // EOF
            .EOF => "(EOF)",
        };
    }
};

pub const unaryOperators = [_]TokenKind{
    .NOT,
    .E_MARK,
    .MINUS,
    .AMPERSAND,
    .L_SQUARE,
    .Q_MARK,
    .TRY,
    .CARET,
};

pub const binaryOperators = [_]TokenKind{
    // .R_PAREN,
    .EQUALS,
    .PLUS_EQUALS,
    .MINUS_EQUALS,
    .STAR_EQUALS,
    .SLASH_EQUALS,
    .PERCENT_EQUALS,
    .D_STAR_EQUALS,
    .BAR,
    .COMMA,
    .COLON,
    .RIGHT_SKINNY_ARROW,
    .AND,
    .OR,
    .NOT_EQUALS,
    .D_EQUALS,
    .GTR,
    .GTE,
    .LSR,
    .LTE,
    .ORELSE,
    .CATCH,
    .PLUS,
    .MINUS,
    .E_MARK,
    .STAR,
    .SLASH,
    .PERCENT,
    .D_BAR,
    .D_STAR,
    .INVOKE,
    // .PERIOD,
    .LEFT_SKINNY_ARROW,
    .WHERE,
};

pub const end_tokens = [_]TokenKind{
    .IDENTIFIER,
    .DECIMAL_INTEGER,
    .HEX_INTEGER,
    .OCT_INTEGER,
    .BIN_INTEGER,
    .FLOAT,
    .CHAR,
    .STRING,
    .UNREACHABLE,
    .BREAK,
    .CONTINUE,
    .RETURN,
    .R_PAREN,
    .R_SQUARE,
    .R_BRACE,
    .TRUE,
    .FALSE,
    .CARET,
};

pub const Token = struct {
    // What kind of token this is
    kind: TokenKind,
    // Non-owning slice into the contents of the source file the text data for this token comes from
    data: []const u8,
    span: span_.Span,

    pub fn init(data: []const u8, kind: ?TokenKind, filename: []const u8, line_text: []const u8, line: usize, col: usize) Token {
        return .{ .data = data, .kind = kind orelse kindFromString(data), .span = span_.Span{
            .filename = filename,
            .line_text = line_text,
            .line = line,
            .col = col,
        } };
    }

    // Used to create a simple, anonymous identifier token
    pub fn init_simple(data: []const u8) Token {
        return Token.init(data, .IDENTIFIER, "", "", 0, 0);
    }

    pub fn repr(self: *Token) []const u8 {
        return self.kind.repr() orelse self.data;
    }

    pub fn pprint(self: *Token) void {
        std.debug.print("Token {{line: {:03}, kind: {s}, data: {s}}}\n", .{ self.span.line, self.repr(), self.data });
    }
};

pub fn kindFromString(data: []const u8) TokenKind {
    var ix: usize = 0;
    const num_ctors = @intFromEnum(TokenKind.len);

    while (ix < num_ctors) : (ix += 1) {
        const kind: TokenKind = @enumFromInt(ix);
        const reprKind: ?[]const u8 = kind.repr();
        if (reprKind) |repr| {
            if (strEquals(data, repr)) {
                // Found the kind!
                return kind;
            }
        }
    }
    return TokenKind.IDENTIFIER;
}

fn strEquals(a: []const u8, b: []const u8) bool {
    if (a.len != b.len) {
        return false;
    } else {
        var i: usize = 0;
        while (i < a.len) : (i += 1) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
}
