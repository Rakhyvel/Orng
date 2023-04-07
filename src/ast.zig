const std = @import("std");

const tokens = @import("token.zig");

const Token = tokens.Token;
const TokenKind = tokens.TokenKind;

// These need to map to ASTData
// So many ASTKinds might use the same ASTData,
// but each ASTKind has a unique ASTData
pub const ASTKind = enum(u32) {
    DECLARATION, // .decl
    FN_DECLARATION, // .fnDecl
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
    decl: struct { introducer: TokenKind, pattern: *AST, type: ?*AST, init: ?*AST },
    fnDecl: struct { name: ?*AST, params: std.ArrayList(*AST), retType: *AST, init: *AST },
    identifier: struct { data: []const u8 },
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

    pub fn create(kind: ASTKind, token: Token, data: ASTData, allocator: std.mem.Allocator) *AST {
        var retval: *AST = allocator.create(AST) catch unreachable;
        retval.kind = kind;
        retval.token = token;
        retval.data = data;
        return retval;
    }

    pub fn createDecl(token: Token, introducer: TokenKind, pattern: *AST, _type: ?*AST, init: ?*AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .DECLARATION,
            token,
            ASTData{ .decl = .{
                .introducer = introducer,
                .pattern = pattern,
                .type = _type,
                .init = init,
            } },
            allocator,
        );
    }

    pub fn createFnDecl(token: Token, name: ?*AST, params: std.ArrayList(*AST), retType: *AST, init: *AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .FN_DECLARATION,
            token,
            ASTData{ .fnDecl = .{
                .name = name,
                .params = params,
                .retType = retType,
                .init = init,
            } },
            allocator,
        );
    }

    pub fn createIdent(token: Token, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .IDENTIFIER,
            token,
            ASTData{ .identifier = .{
                .data = token.data,
            } },
            allocator,
        );
    }
};
