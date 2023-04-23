const std = @import("std");
const _symbol = @import("symbol.zig");
const tokens = @import("token.zig");

const Scope = _symbol.Scope;
const String = @import("zig-string/zig-string.zig").String;
const Token = tokens.Token;
const TokenKind = tokens.TokenKind;

pub const SliceKind = union(enum) {
    SLICE, // data ptr and len
    MUT, // mutable data ptr and len
    MULTIPTR, // c-style `*` pointer, no len
    ARRAY, // static homogenous tuple, compile-time len

    pub fn serialize(self: SliceKind, out: *String) !void {
        switch (self) {
            .SLICE => {
                try out.insert("SLICE", out.len());
            },
            .MUT => {
                try out.insert("MUT", out.len());
            },
            .MULTIPTR => {
                try out.insert("MULTIPTR", out.len());
            },
            .ARRAY => {
                try out.insert("ARRAY", out.len());
            },
        }
    }
};

const Errors = error{ InvalidRange, OutOfMemory };

pub const AST = union(enum) {
    unit: struct { token: Token },
    int: struct { token: Token, data: i128 },
    char: struct { token: Token, data: u8 }, // TODO: Represent a UTF-8 codepoint AKA a rune
    float: struct { token: Token, data: f64 },
    string: struct { token: Token },
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

    _if: struct {
        token: Token,
        let: ?*AST,
        condition: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    cond: struct { token: Token, let: ?*AST, mappings: std.ArrayList(*AST) },
    case: struct { token: Token, let: ?*AST, expr: *AST, mappings: std.ArrayList(*AST) },
    mapping: struct { token: Token, lhs: ?*AST, rhs: ?*AST },
    _while: struct { token: Token, let: ?*AST, condition: *AST, post: ?*AST, bodyBlock: *AST, elseBlock: ?*AST },
    _for: struct {
        token: Token,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },

    block: struct { token: Token, scope: ?*Scope, statements: std.ArrayList(*AST), final: ?*AST },
    _break: struct { token: Token },
    _continue: struct { token: Token },
    throw: struct { token: Token, expr: *AST },
    _return: struct { token: Token, expr: ?*AST },
    decl: struct { token: Token, pattern: *AST, type: ?*AST, init: ?*AST },
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
            .string => return self.string.token,
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

    pub fn createChar(token: Token, data: u8, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .char = .{ .token = token, .data = data } }, allocator);
    }

    pub fn createFloat(token: Token, data: f64, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .float = .{ .token = token, .data = data } }, allocator);
    }

    pub fn createString(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .string = .{ .token = token } }, allocator);
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
        return try AST.box(AST{ .block = .{ .token = token, .scope = null, .statements = statements, .final = final } }, allocator);
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

    pub fn createDecl(token: Token, pattern: *AST, _type: ?*AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .decl = .{ .token = token, .pattern = pattern, .type = _type, .init = init } }, allocator);
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

    pub fn typeEqual(self: *AST, other: *AST) bool {
        // Assert self and other are type (likely are)
        switch (self.*) {
            .unit => other == AST.unit,
        }
    }

    pub fn typeof(self: *AST) *AST {
        return self; // TODO: Lol, lmao
    }

    pub fn serializeOptional(self: ?*AST, out: *String) Errors!void {
        if (self) |s| {
            try s.serialize(out);
        } else {
            try out.insert("null", out.len());
        }
    }

    pub fn serializeList(list: *const std.ArrayList(*AST), out: *String) Errors!void {
        try out.insert("[", out.len());
        var i: usize = 0;
        while (i < list.items.len) : (i += 1) {
            var ast = list.items[i];
            try ast.serialize(out);
            if (i < list.items.len - 1) {
                try out.insert(", ", out.len());
            }
        }
        try out.insert("]", out.len());
    }

    pub fn serialize(self: AST, out: *String) !void {
        switch (self) {
            .unit => {}, //

            .int => {
                try out.insert("AST.int{token: ", out.len());
                try self.int.token.serialize(out);
                try out.insert(", data: ", out.len());
                try std.fmt.format(out.writer(), "{}", .{self.int.data});
                try out.insert("}", out.len());
            },

            .char => {
                try out.insert("AST.char{token: ", out.len());
                try self.char.token.serialize(out);
                try out.insert(", data: ", out.len());
                try std.fmt.format(out.writer(), "{}", .{self.char.data});
                try out.insert("}", out.len());
            },

            .float => {
                try out.insert("AST.float{token: ", out.len());
                try self.float.token.serialize(out);
                try out.insert(", data: ", out.len());
                try std.fmt.format(out.writer(), "{d}", .{self.float.data});
                try out.insert("}", out.len());
            },

            .string => {},

            .identifier => {
                try out.insert("AST.identifier{token: ", out.len());
                try self.identifier.token.serialize(out);
                try out.insert("}", out.len());
            },

            ._unreachable, .unop => {},

            .binop => {
                try out.insert("AST.binop{token: ", out.len());
                try self.binop.token.serialize(out);

                try out.insert(", lhs: ", out.len());
                try self.binop.lhs.serialize(out);

                try out.insert(", rhs: ", out.len());
                try self.binop.rhs.serialize(out);

                try out.insert("}", out.len());
            },

            .call, .addrOf => {},

            .sliceOf => {
                try out.insert("AST.sliceOf{token: ", out.len());
                try self.sliceOf.token.serialize(out);

                try out.insert(", expr: ", out.len());
                try self.sliceOf.expr.serialize(out);

                try out.insert(", len: ", out.len());
                try serializeOptional(self.sliceOf.len, out);

                try out.insert(", kind: ", out.len());
                try self.sliceOf.kind.serialize(out);

                try out.insert("}", out.len());
            },

            .namedArg => {},

            .subSlice => {
                try out.insert("AST.subSlice{token: ", out.len());
                try self.subSlice.token.serialize(out);

                try out.insert(", super: ", out.len());
                try self.subSlice.super.serialize(out);

                try out.insert(", lower: ", out.len());
                try serializeOptional(self.subSlice.lower, out);

                try out.insert(", upper: ", out.len());
                try serializeOptional(self.subSlice.upper, out);

                try out.insert("}", out.len());
            },

            .annotation => {
                try out.insert("AST.annotation{token: ", out.len());
                try self.annotation.token.serialize(out);

                try out.insert(", pattern: ", out.len());
                try self.annotation.pattern.serialize(out);

                try out.insert(", type: ", out.len());
                try self.annotation.type.serialize(out);

                try out.insert(", predicate: ", out.len());
                try serializeOptional(self.annotation.predicate, out);

                try out.insert(", init: ", out.len());
                try serializeOptional(self.annotation.init, out);

                try out.insert("}", out.len());
            },

            .inferredMember => {},

            ._if => {
                try out.insert("AST.if{token: ", out.len());
                try self._if.token.serialize(out);

                try out.insert(", let: ", out.len());
                try serializeOptional(self._if.let, out);

                try out.insert(", condition: ", out.len());
                try self._if.condition.serialize(out);

                try out.insert(", bodyBlock: ", out.len());
                try self._if.bodyBlock.serialize(out);

                try out.insert(", elseBlock: ", out.len());
                try serializeOptional(self._if.elseBlock, out);

                try out.insert("}", out.len());
            },

            .cond => {
                try out.insert("AST.cond{token: ", out.len());
                try self.cond.token.serialize(out);

                try out.insert(", let: ", out.len());
                try serializeOptional(self.cond.let, out);

                try out.insert(", mappings: ", out.len());
                try serializeList(&self.cond.mappings, out);

                try out.insert("}", out.len());
            },

            .case => {
                try out.insert("AST.case{token: ", out.len());
                try self.case.token.serialize(out);

                try out.insert(", let: ", out.len());
                try serializeOptional(self.case.let, out);

                try out.insert(", expr: ", out.len());
                try self.case.expr.serialize(out);

                try out.insert(", mappings: ", out.len());
                try serializeList(&self.case.mappings, out);

                try out.insert("}", out.len());
            },

            .mapping => {
                try out.insert("AST.mapping{token: ", out.len());
                try self.mapping.token.serialize(out);

                try out.insert(", lhs: ", out.len());
                try serializeOptional(self.mapping.lhs, out);

                try out.insert(", rhs: ", out.len());
                try serializeOptional(self.mapping.rhs, out);

                try out.insert("}", out.len());
            },

            ._while => {
                try out.insert("AST.while{token: ", out.len());
                try self._while.token.serialize(out);

                try out.insert(", let: ", out.len());
                try serializeOptional(self._while.let, out);

                try out.insert(", condition: ", out.len());
                try self._while.condition.serialize(out);

                try out.insert(", post: ", out.len());
                try serializeOptional(self._while.post, out);

                try out.insert(", bodyBlock: ", out.len());
                try self._while.bodyBlock.serialize(out);

                try out.insert(", elseBlock: ", out.len());
                try serializeOptional(self._while.elseBlock, out);

                try out.insert("}", out.len());
            },

            ._for => {
                try out.insert("AST.for{token: ", out.len());
                try self._for.token.serialize(out);

                try out.insert(", let: ", out.len());
                try serializeOptional(self._for.let, out);

                try out.insert(", elem: ", out.len());
                try self._for.elem.serialize(out);

                try out.insert(", iterable: ", out.len());
                try self._for.iterable.serialize(out);

                try out.insert(", bodyBlock: ", out.len());
                try self._for.bodyBlock.serialize(out);

                try out.insert(", elseBlock: ", out.len());
                try serializeOptional(self._for.elseBlock, out);

                try out.insert("}", out.len());
            },

            .block => {
                try out.insert("AST.block{token: ", out.len());
                try self.block.token.serialize(out);

                try out.insert(", statements: ", out.len());
                try serializeList(&self.block.statements, out);

                try out.insert(", final: ", out.len());
                try serializeOptional(self.block.final, out);

                try out.insert("}", out.len());
            },

            ._break,
            ._continue,
            .throw,
            ._return,
            => {},

            .decl => {
                try out.insert("AST.decl{token: ", out.len());
                try self.decl.token.serialize(out);
                try out.insert(", pattern: ", out.len());
                try self.decl.pattern.serialize(out);
                try out.insert(", type: ", out.len());
                try serializeOptional(self.decl.type, out);
                try out.insert(", init: ", out.len());
                try serializeOptional(self.decl.init, out);
                try out.insert("}", out.len());
            },

            .fnDecl => {
                try out.insert("AST.fnDecl{token: ", out.len());
                try self.fnDecl.token.serialize(out);

                try out.insert(", name: ", out.len());
                try serializeOptional(self.fnDecl.name, out);

                try out.insert(", params: ", out.len());
                try serializeList(&self.fnDecl.params, out);

                try out.insert(", retType: ", out.len());
                try self.fnDecl.retType.serialize(out);

                try out.insert(", refinement: ", out.len());
                try serializeOptional(self.fnDecl.refinement, out);

                try out.insert(", init: ", out.len());
                try self.fnDecl.init.serialize(out);

                try out.insert("}", out.len());
            },

            ._defer,
            .assign,
            => {},
        }
    }
};
