const TokenKind = enum {
    IDENTIFIER,
    INTEGER,
};

pub const Token = struct { kind: TokenKind, data: []u8 };
