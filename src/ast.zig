const std = @import("std");

const tokens = @import("token.zig");

const Token = tokens.Token;

pub const ASTKind = enum(u32) {
    DECLARATION,
    DEFER,
    ERRDEFER,
    ASSIGN,
    ADD_ASSIGN,
    SUB_ASSIGN,
    MULT_ASSIGN,
    DIV_ASSIGN,
    MOD_ASSIGN,
    POW_ASSIGN,
    COND,
    CASE,
    SUM,
    PRODUCT,
    ANNOTATION,
    ARROW,
    AND,
    OR,
    NOT_EQUALS,
    EQUALS,
    GREATER_THAN,
    GREATER_EQUALS,
    LESSER_THAN,
    LESSER_EQUALS,
    DELTA,
    ORELSE,
    CATCH,
    ADD,
    SUB,
    ERROR_UNION,
    MULT,
    DIV,
    MOD,
    COMPOSITION,
    TUPLE_CONCAT,
    TUPLE_DIFF,
    SUM_UNION,
    POW,
    NOT,
    NEG,
    ADDROF,
    SLICEOF,
    OPTIONAL,
    TRY,
    INFERRED_MEMBER,
    NAMED_ARG,
    UFCS,
    CALL,
    INDEX,
    TO_SLICE,
    SELECTOR,
    FROM_OPTIONAL,
    DEREFERENCE,
    IDENTIFIER,
    INTEGER,
    FLOATING_POINT,
    CHARACTER,
    STRING,
    BLOCK,
    IF,
    WHILE,
    FOR,
    UNREACHABLE,
    THROW,
    RETURN,
    CONTINUE,
    BREAK,
};

pub const ASTData = union(enum) {
    identifier,
    int: struct { data: i128 },
    _string,
    char,
    float: struct { data: f64 },
    binop: struct { left: *AST, right: *AST },
    unop: struct { expr: *AST },
    namedArg: struct { expr: *AST },
    slice: struct { arrayExpr: *AST, lowerBound: ?*AST, upperBound: ?*AST },
    block: struct { children: std.ArrayList(*AST) },
    _defer: struct { statement: *AST },
    _if: struct { condition: *AST, bodyBlock: *AST, elseBlock: ?*AST },
    _cond: struct { mappings: std.ArrayList(*AST) },
    _while: struct { pre: ?*AST, condition: *AST, post: ?*AST, bodyBlock: *AST, elseBlock: ?*AST },
    _for: struct { elem: *AST, iterable: *AST, bodyBlock: *AST, elseBlock: ?*AST },
    _case: struct { expr: *AST, mappings: std.ArrayList(*AST) },
};

pub const AST = struct {
    kind: ASTKind,
    token: Token,
    data: ASTData,

    fn create(kind: ASTKind, token: Token, data: ASTData, allocator: std.mem.Allocator) *AST {
        var retval: *AST = allocator.create(AST, 1) catch unreachable;
        retval.kind = kind;
        retval.token = token;
        retval.data = data;
        return retval;
    }
};
