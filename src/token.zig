const std = @import("std");
const Span = @import("span.zig").Span;

pub const TokenKind = enum(u32) {
    // Literals
    BIN_INTEGER,
    CHAR,
    DECIMAL_INTEGER,
    HEX_INTEGER,
    IDENTIFIER,
    OCT_INTEGER,
    REAL,
    STRING,

    // Keywords
    AND,
    BREAK,
    CASE,
    CATCH,
    COND,
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
    THROW,
    TRY,
    UNREACHABLE,
    WHERE,
    WHILE,

    // INVALIDATE,  // TODO: Reconsider
    // INVALIDATES,
    // VALIDATE,

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
    D_PLUS,
    D_MINUS,
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
    BACK_SLASH,
    STAR,

    // Punctuation
    AMPERSAND,
    COLON,
    COMMA,
    D_PERIOD,
    E_MARK,
    PERIOD,
    PERIOD_Q_MARK,
    Q_MARK,
    SEMICOLON,

    // Open/Close
    L_BRACE,
    L_PAREN,
    L_SQUARE,
    R_BRACE,
    R_PAREN,
    R_SQUARE,
    INDENT,
    DEDENT,

    // Function stuff
    DELTA,
    DIAMOND,
    PERIOD_GTR,

    // Whitespace
    NEWLINE,
    EOF,

    // HACK: Used to count how many constructors are in the enum
    len,
};

pub const binaryOperators = [_]TokenKind{
    .R_PAREN,
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
    .DIAMOND,
    .D_PLUS,
    .D_MINUS,
    .D_BAR,
    .D_STAR,
    .PERIOD_GTR,
    .PERIOD,
    .LEFT_SKINNY_ARROW,
    .WHERE,
    .BACK_SLASH,
};

pub const Token = struct {
    // What kind of token this is
    kind: TokenKind,
    // Non-owning slice into the contents of the source file the text data for this token comes from
    data: []const u8,
    span: Span,

    pub fn create(data: []const u8, kind: ?TokenKind, line: i64, col: i64) Token {
        return .{ .data = data, .kind = kind orelse kindFromString(data), .span = Span{ .line = line, .col = col } };
    }

    pub fn repr(self: *Token) []const u8 {
        return reprFromTokenKind(self.kind) orelse self.data;
    }

    pub fn pprint(self: *Token) void {
        std.debug.print("Token {{line: {:03}, kind: {s}, data: {s}}}\n", .{ self.span.line, self.repr(), self.data });
    }
};

pub fn kindFromString(data: []const u8) TokenKind {
    var ix: usize = 0;
    const num_ctors = @enumToInt(TokenKind.len);

    while (ix < num_ctors) : (ix += 1) {
        const kind: TokenKind = @intToEnum(TokenKind, ix);
        const reprKind: ?[]const u8 = reprFromTokenKind(kind);
        if (reprKind) |repr| {
            if (strEquals(data, repr)) {
                // Found the kind!
                return kind;
            }
        }
    }
    return TokenKind.IDENTIFIER;
}

pub fn reprFromTokenKind(kind: TokenKind) ?[]const u8 {
    return switch (kind) {
        .BIN_INTEGER => "<binary integer>",
        .CHAR => "<character literal>",
        .DECIMAL_INTEGER => "<decimal integer>",
        .HEX_INTEGER => "<hexadecimal integer>",
        .IDENTIFIER => "<an identifier>",
        .OCT_INTEGER => "<octal integer>",
        .REAL => "<real number>",
        .STRING => "<string literal>",
        .NEWLINE => "<new-line>",
        .INDENT => "<indent>",
        .DEDENT => "<dedent>",
        .len => null,

        .AND => "and",
        .BREAK => "break",
        .CASE => "case",
        .CATCH => "catch",
        .COND => "cond",
        .CONST => "const",
        .CONTINUE => "continue",
        .DEFER => "defer",
        .ELSE => "else",
        .ERRDEFER => "errdefer",
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
        .THROW => "throw",
        .TRY => "try",
        .UNREACHABLE => "unreachable",
        .WHERE => "where",
        .WHILE => "while",

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
        .D_PLUS => "++",
        .D_MINUS => "--",
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
        .BACK_SLASH => "\\",
        .STAR => "*",

        // Punctuation
        .AMPERSAND => "&",
        .COLON => ":",
        .COMMA => ",",
        .D_PERIOD => "..",
        .E_MARK => "!",
        .PERIOD => ".",
        .PERIOD_Q_MARK => ".?",
        .Q_MARK => "?",
        .SEMICOLON => ";",

        // Open/Close
        .L_BRACE => "{",
        .L_PAREN => "(",
        .L_SQUARE => "[",
        .R_BRACE => "}",
        .R_PAREN => ")",
        .R_SQUARE => "]",

        // Functional
        .DELTA => "|>",
        .DIAMOND => "<>",
        .PERIOD_GTR => ".>",

        // EOF
        .EOF => "(EOF)",
    };
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
