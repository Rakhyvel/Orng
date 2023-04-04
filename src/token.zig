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
    INVALIDATE,
    INVALIDATES,
    LET,
    MUT,
    OR,
    ORELSE,
    RETURN,
    THROW,
    THROWS,
    TRY,
    UNREACHABLE,
    VALIDATE,
    WHERE,
    WHILE,

    // Equals
    D_GTR_EQUALS,
    D_LSR_EQUALS,
    D_EQUALS,
    EQUALS,
    MINUS_EQUALS,
    NOT_EQUALS,
    PERCENT_EQUALS,
    PLUS_EQUALS,
    SLASH_EQUALS,
    STAR_EQUALS,

    // Math
    BAR,
    CARET,
    D_PLUS,
    D_MINUS,
    DIAMOND,
    FAT_ARROW,
    GTR,
    GTE,
    LEFT_SHIFT,
    LSR,
    LTE,
    MINUS,
    PERCENT,
    PLUS,
    RIGHT_SHIFT,
    SKINNY_ARROW,
    SLASH,
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

    // Invented
    PERIOD_GTR,

    // Structure
    WHITESPACE,
    EOF,

    // HACK: Used to count how many constructors are in the enum
    len,
};

pub const Token = struct {
    // What kind of token this is
    kind: TokenKind,
    // Non-owning slice into the contents of the source file the text data for this token comes from
    data: []const u8,
    line: i64,
    col: i64,

    pub fn create(data: []const u8, kind: ?TokenKind, line: i64, col: i64) Token {
        return .{ .data = data, .kind = kind orelse kindFromString(data), .line = line, .col = col };
    }

    pub fn repr(self: *Token) []const u8 {
        return reprFromTokenKind(self.kind) orelse self.data;
    }
};

fn kindFromString(data: []const u8) TokenKind {
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
        .BIN_INTEGER => "<binary integer>", //
        .CHAR => "<character literal>",
        .DECIMAL_INTEGER => "<decimal integer>",
        .HEX_INTEGER => "<hexadecimal integer>",
        .IDENTIFIER => "<an identifier>",
        .OCT_INTEGER => "<octal integer>",
        .REAL => "<real number>",
        .STRING => "<string literal>",
        .WHITESPACE => "<new-line>",
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
        .INVALIDATE => "invalidate",
        .INVALIDATES => "invalidates",
        .LET => "let",
        .MUT => "mut",
        .OR => "or",
        .ORELSE => "orelse",
        .RETURN => "return",
        .THROW => "throw",
        .THROWS => "throws",
        .TRY => "try",
        .UNREACHABLE => "unreachable",
        .VALIDATE => "validate",
        .WHERE => "where",
        .WHILE => "while",

        // Equals
        .D_GTR_EQUALS => ">>=",
        .D_LSR_EQUALS => "<<=",
        .D_EQUALS => "==",
        .EQUALS => "=",
        .MINUS_EQUALS => "-=",
        .NOT_EQUALS => "!=",
        .PERCENT_EQUALS => "%=",
        .PLUS_EQUALS => "+=",
        .SLASH_EQUALS => "/=",
        .STAR_EQUALS => "*=",

        // Math
        .BAR => "|",
        .CARET => "^",
        .D_PLUS => "++",
        .D_MINUS => "--",
        .DIAMOND => "<>",
        .FAT_ARROW => "=>",
        .GTR => ">",
        .GTE => ">=",
        .LEFT_SHIFT => "<<",
        .LSR => "<",
        .LTE => "<=",
        .MINUS => "-",
        .PERCENT => "%",
        .PLUS => "+",
        .RIGHT_SHIFT => ">>",
        .SKINNY_ARROW => "->",
        .SLASH => "/",
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

        // Invented
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
