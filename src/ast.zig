const std = @import("std");

const tokens = @import("token.zig");
const String = @import("zig-string/zig-string.zig").String;

const Token = tokens.Token;
const TokenKind = tokens.TokenKind;

pub const SliceKind = union(enum) {
    SLICE, // data ptr and len
    MUT, // mutable data ptr and len
    MULTIPTR, // c-style `*` pointer, no len
    ARRAY, // static homogenous tuple, compile-time len
};

pub const AST = union(enum) {
    unit: struct { token: Token },
    int: struct { token: Token, data: i128 },
    char: struct { token: Token, data: u32 },
    float: struct { token: Token, data: f64 },
    _string: struct { token: Token },
    identifier: struct { token: Token },
    _unreachable: struct { token: Token },

    unop: struct { token: Token, expr: *AST },
    binop: struct { token: Token, lhs: *AST, rhs: *AST },
    call: struct { token: Token, lhs: *AST, rhs: *AST },
    addrOf: struct { token: Token, expr: *AST, mut: bool },
    sliceOf: struct { token: Token, expr: *AST, len: ?*AST, kind: SliceKind },
    namedArg: struct { token: Token, ident: *AST, init: *AST },
    subSlice: struct { token: Token, super: *AST, lower: ?*AST, upper: ?*AST },
    annotation: struct { token: Token, pattern: *AST, type: *AST, predicate: ?*AST, init: ?*AST },
    inferredMember: struct { token: Token, ident: *AST, init: ?*AST },

    _if: struct { token: Token, let: ?*AST, condition: *AST, bodyBlock: *AST, elseBlock: ?*AST },
    cond: struct { token: Token, let: ?*AST, mappings: std.ArrayList(*AST) },
    case: struct { token: Token, let: ?*AST, expr: *AST, mappings: std.ArrayList(*AST) },
    mapping: struct { token: Token, lhs: ?*AST, rhs: ?*AST },
    _while: struct { token: Token, let: ?*AST, condition: *AST, post: ?*AST, bodyBlock: *AST, elseBlock: ?*AST },
    _for: struct { token: Token, let: ?*AST, elem: *AST, iterable: *AST, bodyBlock: *AST, elseBlock: ?*AST },

    block: struct { token: Token, statements: std.ArrayList(*AST), final: ?*AST },
    _break: struct { token: Token },
    _continue: struct { token: Token },
    throw: struct { token: Token, expr: *AST },
    _return: struct { token: Token, expr: ?*AST },
    decl: struct { token: Token, introducer: TokenKind, pattern: *AST, type: ?*AST, init: ?*AST },
    fnDecl: struct { token: Token, name: ?*AST, params: std.ArrayList(*AST), retType: *AST, refinement: ?*AST, init: *AST },
    _defer: struct { token: Token, expr: *AST },
    assign: struct { token: Token, lhs: *AST, rhs: *AST },

    fn box(ast: AST, alloc: std.mem.Allocator) !*AST {
        var retval = try alloc.create(AST);
        retval.* = ast;
        return retval;
    }

    pub fn getToken(self: AST) Token {
        switch (self) {
            .unit => return self.unit.token,
            .int => return self.int.token,
            .char => return self.char.token,
            .float => return self.float.token,
            ._string => return self._string.token,
            .identifier => return self.identifier.token,
            ._unreachable => return self._unreachable.token,

            .unop => return self.unop.token,
            .binop => return self.binop.token,
            .call => return self.call.token,
            .addrOf => return self.addrOf.token,
            .sliceOf => return self.sliceOf.token,
            .namedArg => return self.namedArg.token,
            .subSlice => return self.subSlice.token,
            .annotation => return self.annotation.token,
            .inferredMember => return self.inferredMember.token,

            ._if => return self._if.token,
            .cond => return self.cond.token,
            .case => return self.case.token,
            .mapping => return self.mapping.token,
            ._while => return self._while.token,
            ._for => return self._for.token,
            .block => return self.block.token,
            ._break => return self._break.token,
            ._continue => return self._continue.token,
            .throw => return self.throw.token,
            ._return => return self._return.token,
            .decl => return self.decl.token,
            .fnDecl => return self.fnDecl.token,
            ._defer => return self._defer.token,
            .assign => return self.assign.token,
        }
    }

    pub fn createUnit(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .unit = .{ .token = token } }, allocator);
    }

    pub fn createInt(token: Token, data: i128, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .int = .{ .token = token, .data = data } }, allocator);
    }

    pub fn createChar(token: Token, data: u32, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .char = .{ .token = token, .data = data } }, allocator);
    }

    pub fn createFloat(token: Token, data: f64, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .float = .{ .token = token, .data = data } }, allocator);
    }

    pub fn createString(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._string = .{ .token = token } }, allocator);
    }

    pub fn createIdentifier(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .identifier = .{ .token = token } }, allocator);
    }

    pub fn createUnreachable(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._unreachable = .{ .token = token } }, allocator);
    }

    pub fn createUnop(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .unop = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createBinop(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .binop = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createCall(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .call = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createAddrOf(token: Token, expr: *AST, mut: bool, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .addrOf = .{ .token = token, .expr = expr, .mut = mut } }, allocator);
    }

    pub fn createSliceOf(token: Token, expr: *AST, len: ?*AST, kind: SliceKind, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .sliceOf = .{ .token = token, .expr = expr, .len = len, .kind = kind } }, allocator);
    }

    pub fn createNamedArg(token: Token, ident: *AST, init: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .namedArg = .{ .token = token, .ident = ident, .init = init } }, allocator);
    }

    pub fn createSubSlice(token: Token, super: *AST, lower: ?*AST, upper: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .subSlice = .{ .token = token, .super = super, .lower = lower, .upper = upper } }, allocator);
    }

    pub fn createAnnotation(token: Token, pattern: *AST, _type: *AST, predicate: ?*AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .annotation = .{ .token = token, .pattern = pattern, .type = _type, .predicate = predicate, .init = init } }, allocator);
    }

    pub fn createInferredMember(token: Token, ident: *AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .inferredMember = .{ .token = token, .ident = ident, .init = init } }, allocator);
    }

    pub fn createIf(token: Token, let: ?*AST, condition: *AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._if = .{ .token = token, .let = let, .condition = condition, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createCond(token: Token, let: ?*AST, mappings: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .cond = .{ .token = token, .let = let, .mappings = mappings } }, allocator);
    }

    pub fn createCase(token: Token, let: ?*AST, expr: *AST, mappings: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .case = .{ .token = token, .let = let, .expr = expr, .mappings = mappings } }, allocator);
    }

    pub fn createMapping(token: Token, lhs: ?*AST, rhs: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .mapping = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createWhile(token: Token, let: ?*AST, condition: *AST, post: ?*AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._while = .{ .token = token, .let = let, .condition = condition, .post = post, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createFor(token: Token, let: ?*AST, elem: *AST, iterable: *AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._for = .{ .token = token, .let = let, .elem = elem, .iterable = iterable, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createBlock(token: Token, statements: std.ArrayList(*AST), final: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .block = .{ .token = token, .statements = statements, .final = final } }, allocator);
    }

    pub fn createBreak(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._break = .{ .token = token } }, allocator);
    }

    pub fn createContinue(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._break = .{ .token = token } }, allocator);
    }

    pub fn createThrow(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .throw = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createReturn(token: Token, expr: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._return = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createDecl(token: Token, introducer: TokenKind, pattern: *AST, _type: ?*AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .decl = .{ .token = token, .introducer = introducer, .pattern = pattern, .type = _type, .init = init } }, allocator);
    }

    pub fn createFnDecl(token: Token, name: ?*AST, params: std.ArrayList(*AST), retType: *AST, refinement: ?*AST, init: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .fnDecl = .{ .token = token, .name = name, .params = params, .retType = retType, .refinement = refinement, .init = init } }, allocator);
    }

    pub fn createDefer(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._defer = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createAssign(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .assign = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn serialize(self: *AST, out: *String) void {
        _ = out;
        _ = self;
    }
};
