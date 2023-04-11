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
    MAPPING,
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
    SELECT,
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

pub const SliceKind = union(enum) {
    SLICE, // data ptr and len
    MUT, // mutable data ptr and len
    MULTIPTR, // c-style `*` pointer, no len
    ARRAY, // static homogenous tuple, compile-time len
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
    annotation: struct { pattern: *AST, type: *AST, predicate: ?*AST, init: ?*AST },
    unop: struct { expr: *AST },
    addr: struct { expr: *AST, mut: bool },
    sliceOf: struct { expr: *AST, len: ?*AST, kind: SliceKind },
    namedArg: struct { ident: *AST, init: *AST },
    inferredMember: struct { ident: *AST, init: ?*AST },
    slice: struct { super: *AST, lower: ?*AST, upper: ?*AST },
    block: struct { children: std.ArrayList(*AST) },
    _defer: struct { expr: *AST },
    assign: struct { lhs: *AST, rhs: *AST },
    _if: struct { let: ?*AST, condition: *AST, bodyBlock: *AST, elseBlock: ?*AST },
    cond: struct { let: ?*AST, mappings: std.ArrayList(*AST) },
    _case: struct { let: ?*AST, expr: *AST, mappings: std.ArrayList(*AST) },
    mapping: struct { lhs: ?*AST, rhs: ?*AST },
    _while: struct { let: ?*AST, condition: *AST, post: ?*AST, bodyBlock: *AST, elseBlock: ?*AST },
    _for: struct { let: ?*AST, elem: *AST, iterable: *AST, bodyBlock: *AST, elseBlock: ?*AST },
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

    pub fn createDefer(token: Token, expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .DEFER,
            token,
            ASTData{ ._defer = .{ .expr = expr } },
            allocator,
        );
    }

    pub fn createErrDefer(token: Token, expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .ERRDEFER,
            token,
            ASTData{ ._defer = .{ .expr = expr } },
            allocator,
        );
    }

    pub fn createAssign(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .ASSIGN,
            token,
            ASTData{ .assign = .{ .lhs = lhs, .rhs = rhs } },
            allocator,
        );
    }

    pub fn createCond(token: Token, let: ?*AST, mappings: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.create(
            .COND,
            token,
            ASTData{ .cond = .{ .let = let, .mappings = mappings } },
            allocator,
        );
    }

    pub fn createCase(token: Token, let: ?*AST, expr: *AST, mappings: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.create(
            .CASE,
            token,
            ASTData{ ._case = .{ .let = let, .expr = expr, .mappings = mappings } },
            allocator,
        );
    }

    pub fn createMapping(token: Token, lhs: ?*AST, rhs: ?*AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .MAPPING,
            token,
            ASTData{ .mapping = .{ .lhs = lhs, .rhs = rhs } },
            allocator,
        );
    }

    pub fn createBinop(token: Token, kind: ASTKind, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            kind,
            token,
            ASTData{ .binop = .{ .lhs = lhs, .rhs = rhs } },
            allocator,
        );
    }

    pub fn createAnnotation(token: Token, pattern: ASTKind, _type: *AST, predicate: ?*AST, init: ?*AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .ANNOTATION,
            token,
            ASTData{ .annotation = .{ .pattern = pattern, .type = _type, .predicate = predicate, .init = init } },
            allocator,
        );
    }

    pub fn createUnop(token: Token, kind: ASTKind, expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            kind,
            token,
            ASTData{ .unop = .{ .expr = expr } },
            allocator,
        );
    }

    pub fn createAddr(token: Token, expr: *AST, mut: bool, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .ADDROF,
            token,
            ASTData{ .addr = .{ .expr = expr, .mut = mut } },
            allocator,
        );
    }

    pub fn createSliceOf(token: Token, expr: *AST, len: ?*AST, sliceKind: SliceKind, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .SLICEOF,
            token,
            ASTData{ .sliceOf = .{ .expr = expr, .len = len, .kind = sliceKind } },
            allocator,
        );
    }

    pub fn createNamedArg(token: Token, ident: *AST, init: *AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .NAMED_ARG,
            token,
            ASTData{ .namedArg = .{ .ident = ident, .init = init } },
            allocator,
        );
    }

    pub fn createInferredMember(token: Token, ident: *AST, init: ?*AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .INFERRED_MEMBER,
            token,
            ASTData{ .inferredMember = .{ .ident = ident, .init = init } },
            allocator,
        );
    }

    pub fn createSubSlice(token: Token, super: *AST, lower: ?*AST, upper: ?*AST, allocator: std.mem.Allocator) *AST {
        return AST.create(
            .SLICE,
            token,
            ASTData{ .slice = .{ .super = super, .lower = lower, .upper = upper } },
            allocator,
        );
    }
};
