const std = @import("std");
const _symbol = @import("symbol.zig");
const tokens = @import("token.zig");

const Scope = _symbol.Scope;
const Span = @import("span.zig").Span;
const String = @import("zig-string/zig-string.zig").String;
const Symbol = _symbol.Symbol;
const Token = tokens.Token;
const TokenKind = tokens.TokenKind;

pub var typesInited = false;
pub var boolType: *AST = undefined;
pub var charType: *AST = undefined;
pub var floatType: *AST = undefined;
pub var intType: *AST = undefined;
pub var voidType: *AST = undefined;

pub fn initTypes() !void {
    if (!typesInited) {
        boolType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Bool", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        charType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Char", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        floatType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Float", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        intType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Int", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        voidType = try AST.createUnit(Token{ .kind = .L_PAREN, .data = "(", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        typesInited = true;
    }
}

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
    // Literals
    unit: struct { token: Token },
    int: struct { token: Token, data: i128 },
    char: struct { token: Token, data: u8 }, // TODO: Represent a UTF-8 codepoint AKA a rune
    float: struct { token: Token, data: f64 },
    string: struct { token: Token },
    identifier: struct { token: Token },
    _true: struct { token: Token },
    _false: struct { token: Token },

    // Unary operators
    not: struct { token: Token, expr: *AST },
    negate: struct { token: Token, expr: *AST },
    dereference: struct { token: Token, expr: *AST },
    _try: struct { token: Token, expr: *AST },
    optional: struct { token: Token, expr: *AST },
    fromOptional: struct { token: Token, expr: *AST },
    inferredError: struct { token: Token, expr: *AST },

    // Binary operators
    assign: struct { token: Token, lhs: *AST, rhs: *AST },
    _or: struct { token: Token, lhs: *AST, rhs: *AST },
    _and: struct { token: Token, lhs: *AST, rhs: *AST },
    notEqual: struct { token: Token, lhs: *AST, rhs: *AST },
    add: struct { token: Token, lhs: *AST, rhs: *AST },
    sub: struct { token: Token, lhs: *AST, rhs: *AST },
    mult: struct { token: Token, lhs: *AST, rhs: *AST },
    div: struct { token: Token, lhs: *AST, rhs: *AST },
    mod: struct { token: Token, lhs: *AST, rhs: *AST },
    exponent: struct { token: Token, terms: std.ArrayList(*AST) },
    _catch: struct { token: Token, lhs: *AST, rhs: *AST },
    _orelse: struct { token: Token, lhs: *AST, rhs: *AST },
    call: struct { token: Token, lhs: *AST, rhs: *AST },
    index: struct { token: Token, lhs: *AST, rhs: *AST },
    select: struct { token: Token, lhs: *AST, rhs: *AST },
    function: struct { token: Token, lhs: *AST, rhs: *AST },
    delta: struct { token: Token, lhs: *AST, rhs: *AST },
    composition: struct { token: Token, lhs: *AST, rhs: *AST },
    prepend: struct { token: Token, lhs: *AST, rhs: *AST },
    sum: struct { token: Token, lhs: *AST, rhs: *AST },
    _error: struct { token: Token, lhs: *AST, rhs: *AST },
    product: struct { token: Token, terms: std.ArrayList(*AST) },
    diff: struct { token: Token, lhs: *AST, rhs: *AST },
    concat: struct { token: Token, lhs: *AST, rhs: *AST },
    _union: struct { token: Token, lhs: *AST, rhs: *AST },

    // Fancy operators
    conditional: struct { tokens: std.ArrayList(Token), exprs: std.ArrayList(*AST) },
    addrOf: struct { token: Token, expr: *AST, mut: bool },
    sliceOf: struct { token: Token, expr: *AST, len: ?*AST, kind: SliceKind },
    namedArg: struct { token: Token, ident: *AST, init: *AST },
    subSlice: struct { token: Token, super: *AST, lower: ?*AST, upper: ?*AST },
    annotation: struct { token: Token, pattern: *AST, type: *AST, predicate: ?*AST, init: ?*AST },
    inferredMember: struct { token: Token, ident: *AST, init: ?*AST },

    // Control-flow expressions
    _if: struct {
        token: Token,
        scope: ?*Scope,
        let: ?*AST,
        condition: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    cond: struct {
        token: Token,
        scope: ?*Scope,
        let: ?*AST,
        mappings: std.ArrayList(*AST),
    },
    case: struct {
        token: Token,
        scope: ?*Scope,
        let: ?*AST,
        expr: *AST,
        mappings: std.ArrayList(*AST),
    },
    mapping: struct {
        token: Token,
        lhs: ?*AST,
        rhs: ?*AST,
    },
    _while: struct {
        token: Token,
        scope: ?*Scope,
        let: ?*AST,
        condition: *AST,
        post: ?*AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    _for: struct {
        token: Token,
        scope: ?*Scope,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    block: struct {
        token: Token,
        scope: ?*Scope,
        statements: std.ArrayList(*AST),
        final: ?*AST,
    },

    // Control-flow statements
    _break: struct { token: Token },
    _continue: struct { token: Token },
    _unreachable: struct { token: Token },
    throw: struct { token: Token, expr: *AST },
    _return: struct { token: Token, expr: ?*AST },
    decl: struct {
        token: Token,
        symbol: ?*Symbol,
        pattern: *AST,
        type: ?*AST,
        init: ?*AST,
    },
    fnDecl: struct {
        token: Token,
        name: ?*AST,
        params: std.ArrayList(*AST),
        retType: *AST,
        refinement: ?*AST,
        init: *AST,
    },
    _defer: struct { token: Token, expr: *AST },

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
            ._true => return self._true.token,
            ._false => return self._false.token,

            .not => return self.not.token,
            .negate => return self.negate.token,
            .dereference => return self.dereference.token,
            ._try => return self._try.token,
            .optional => return self.optional.token,
            .fromOptional => return self.fromOptional.token,
            .inferredError => return self.inferredError.token,

            .assign => return self.assign.token,
            ._or => return self._or.token,
            ._and => return self._and.token,
            .notEqual => return self.notEqual.token,
            .conditional => return self.conditional.tokens.items[0],
            .add => return self.add.token,
            .sub => return self.sub.token,
            .mult => return self.mult.token,
            .div => return self.div.token,
            .mod => return self.mod.token,
            .exponent => return self.exponent.token,
            ._catch => return self._catch.token,
            ._orelse => return self._orelse.token,
            .call => return self.call.token,
            .index => return self.index.token,
            .select => return self.select.token,
            .function => return self.function.token,
            .delta => return self.delta.token,
            .composition => return self.composition.token,
            .prepend => return self.prepend.token,
            .sum => return self.sum.token,
            ._error => return self._error.token,
            .product => return self.product.token,
            .diff => return self.diff.token,
            .concat => return self.concat.token,
            ._union => return self._union.token,

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

    pub fn createTrue(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._true = .{ .token = token } }, allocator);
    }

    pub fn createFalse(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._false = .{ .token = token } }, allocator);
    }

    pub fn createNot(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .not = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createNegate(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .negate = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createDereference(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .dereference = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createTry(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._try = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createOptional(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .optional = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createFromOptional(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .fromOptional = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createInferredError(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .inferredError = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn createAssign(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .assign = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createOr(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._or = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createAnd(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._and = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createNotEqual(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .notEqual = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createConditional(_tokens: std.ArrayList(Token), exprs: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .conditional = .{ .tokens = _tokens, .exprs = exprs } }, allocator);
    }

    pub fn createAdd(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .add = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createSub(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .sub = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createMult(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .mult = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createDiv(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .div = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createMod(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .mod = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createExponent(token: Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .exponent = .{ .token = token, .terms = terms } }, allocator);
    }

    pub fn createCatch(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._catch = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createOrelse(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._orelse = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createCall(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .call = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createIndex(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .index = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createSelect(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .select = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createSum(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .sum = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createFunction(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .function = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createDelta(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .delta = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createComposition(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .composition = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createPrepend(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .prepend = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createError(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._error = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createProduct(token: Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        std.debug.assert(terms.items.len >= 2);
        return try AST.box(AST{ .product = .{ .token = token, .terms = terms } }, allocator);
    }

    pub fn createDiff(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .diff = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createConcat(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .concat = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createUnion(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._union = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
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
        return try AST.box(AST{ ._if = .{ .token = token, .scope = null, .let = let, .condition = condition, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createCond(token: Token, let: ?*AST, mappings: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .cond = .{ .token = token, .scope = null, .let = let, .mappings = mappings } }, allocator);
    }

    pub fn createCase(token: Token, let: ?*AST, expr: *AST, mappings: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .case = .{ .token = token, .scope = null, .let = let, .expr = expr, .mappings = mappings } }, allocator);
    }

    pub fn createMapping(token: Token, lhs: ?*AST, rhs: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .mapping = .{ .token = token, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createWhile(token: Token, let: ?*AST, condition: *AST, post: ?*AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._while = .{ .token = token, .scope = null, .let = let, .condition = condition, .post = post, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createFor(token: Token, let: ?*AST, elem: *AST, iterable: *AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._for = .{ .token = token, .scope = null, .let = let, .elem = elem, .iterable = iterable, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
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
        return try AST.box(AST{ .decl = .{ .token = token, .symbol = null, .pattern = pattern, .type = _type, .init = init } }, allocator);
    }

    pub fn createFnDecl(token: Token, name: ?*AST, params: std.ArrayList(*AST), retType: *AST, refinement: ?*AST, init: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .fnDecl = .{ .token = token, .name = name, .params = params, .retType = retType, .refinement = refinement, .init = init } }, allocator);
    }

    pub fn createDefer(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._defer = .{ .token = token, .expr = expr } }, allocator);
    }

    pub fn printType(self: *AST) void {
        switch (self.*) {
            .unit => {
                std.debug.print("()", .{});
            },
            .identifier => {
                std.debug.print("{s}", .{self.identifier.token.data});
            },
            .dereference => {
                self.dereference.expr.printType();
                std.debug.print("^", .{});
            },
            .optional => {
                std.debug.print("?", .{});
                self.optional.expr.printType();
            },
            .inferredError => {
                std.debug.print("!", .{});
                self.inferredError.expr.printType();
            },
            .function => {
                self.function.lhs.printType();
                std.debug.print("->", .{});
                self.function.lhs.printType();
            },
            else => {
                std.debug.print("Unimplemented or not a type: {?}\n", .{self.*});
                unreachable;
            },
        }
    }

    pub fn typeof(self: *AST) *AST {
        return self;
    }

    pub fn typesMatch(self: *AST, other: *AST) bool {
        switch (self.*) {
            .identifier => {
                if (other.* != .identifier) {
                    return false;
                } else {
                    return std.mem.eql(u8, self.identifier.token.data, other.identifier.token.data);
                }
            },
            else => {
                return true;
            },
        }
    }
};
