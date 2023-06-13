const errs = @import("errors.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");
const tokens = @import("token.zig");
const _validate = @import("validate.zig");

const Error = errs.Error;
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
pub var typeType: *AST = undefined;
pub var unitType: *AST = undefined;
pub var voidType: *AST = undefined;

pub fn initTypes() !void {
    if (!typesInited) {
        boolType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Bool", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        charType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Char", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        floatType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Float", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        intType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Int", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        typeType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Type", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        unitType = try AST.createUnit(Token{ .kind = .L_PAREN, .data = "(", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
        voidType = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Void", .span = Span{ .line = 0, .col = 0 } }, std.heap.page_allocator);
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

pub const MappingKind = enum {
    match,
    cond,
};

const Errors = error{ InvalidRange, OutOfMemory };

const ASTCommon = struct {
    token: Token,
    _type: ?*AST,
};

pub const AST = union(enum) {
    // Literals
    unit: struct { common: ASTCommon },
    int: struct { common: ASTCommon, data: i128 },
    char: struct { common: ASTCommon, data: u8 }, // TODO: Represent a UTF-8 codepoint AKA a rune
    float: struct { common: ASTCommon, data: f64 },
    string: struct { common: ASTCommon },
    identifier: struct { common: ASTCommon },
    _true: struct { common: ASTCommon },
    _false: struct { common: ASTCommon },

    // Unary operators
    not: struct { common: ASTCommon, expr: *AST },
    negate: struct { common: ASTCommon, expr: *AST },
    dereference: struct { common: ASTCommon, expr: *AST },
    _try: struct { common: ASTCommon, expr: *AST },
    optional: struct { common: ASTCommon, expr: *AST },
    fromOptional: struct { common: ASTCommon, expr: *AST },
    inferredError: struct { common: ASTCommon, expr: *AST },

    // Binary operators
    assign: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _or: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _and: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    notEqual: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    add: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    sub: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    mult: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    div: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    mod: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    exponent: struct { common: ASTCommon, terms: std.ArrayList(*AST) },
    _catch: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _orelse: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    call: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    index: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    select: struct { common: ASTCommon, lhs: *AST, rhs: *AST, pos: ?usize },
    function: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    delta: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    composition: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    prepend: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    sum: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _error: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    product: struct { common: ASTCommon, terms: std.ArrayList(*AST) },
    diff: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    concat: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _union: struct { common: ASTCommon, lhs: *AST, rhs: *AST },

    // Fancy operators
    conditional: struct { common: ASTCommon, tokens: std.ArrayList(Token), exprs: std.ArrayList(*AST) },
    addrOf: struct { common: ASTCommon, expr: *AST, mut: bool },
    sliceOf: struct { common: ASTCommon, expr: *AST, len: ?*AST, kind: SliceKind },
    namedArg: struct { common: ASTCommon, ident: *AST, init: *AST },
    subSlice: struct { common: ASTCommon, super: *AST, lower: ?*AST, upper: ?*AST },
    annotation: struct { common: ASTCommon, pattern: *AST, type: *AST, predicate: ?*AST, init: ?*AST },
    inferredMember: struct { common: ASTCommon, ident: *AST, init: ?*AST },

    // Control-flow expressions
    _if: struct {
        common: ASTCommon,
        scope: ?*Scope,
        let: ?*AST,
        condition: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    cond: struct {
        common: ASTCommon,
        scope: ?*Scope,
        let: ?*AST,
        mappings: std.ArrayList(*AST),
    },
    match: struct {
        common: ASTCommon,
        scope: ?*Scope,
        let: ?*AST,
        expr: *AST,
        mappings: std.ArrayList(*AST),
    },
    mapping: struct {
        common: ASTCommon,
        kind: MappingKind,
        lhs: ?*AST,
        rhs: ?*AST,
    },
    _while: struct {
        common: ASTCommon,
        scope: ?*Scope,
        let: ?*AST,
        condition: *AST,
        post: ?*AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    _for: struct {
        common: ASTCommon,
        scope: ?*Scope,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    block: struct {
        common: ASTCommon,
        scope: ?*Scope,
        statements: std.ArrayList(*AST),
        final: ?*AST,
    },

    // Control-flow statements
    _break: struct { common: ASTCommon },
    _continue: struct { common: ASTCommon },
    _unreachable: struct { common: ASTCommon },
    throw: struct { common: ASTCommon, expr: *AST },
    _return: struct { common: ASTCommon, expr: ?*AST },
    decl: struct {
        common: ASTCommon,
        symbol: ?*Symbol,
        pattern: *AST,
        type: ?*AST,
        init: ?*AST,
    },
    fnDecl: struct {
        common: ASTCommon,
        name: ?*AST,
        params: std.ArrayList(*AST),
        retType: *AST,
        refinement: ?*AST,
        init: *AST,
        symbol: ?*Symbol = null,
    },
    _defer: struct { common: ASTCommon, statement: *AST },

    fn box(ast: AST, alloc: std.mem.Allocator) error{OutOfMemory}!*AST {
        var retval = try alloc.create(AST);
        retval.* = ast;
        return retval;
    }

    pub fn getCommon(self: *AST) *ASTCommon {
        switch (self.*) {
            .unit => return &self.unit.common,
            .int => return &self.int.common,
            .char => return &self.char.common,
            .float => return &self.float.common,
            .string => return &self.string.common,
            .identifier => return &self.identifier.common,
            ._unreachable => return &self._unreachable.common,
            ._true => return &self._true.common,
            ._false => return &self._false.common,

            .not => return &self.not.common,
            .negate => return &self.negate.common,
            .dereference => return &self.dereference.common,
            ._try => return &self._try.common,
            .optional => return &self.optional.common,
            .fromOptional => return &self.fromOptional.common,
            .inferredError => return &self.inferredError.common,

            .assign => return &self.assign.common,
            ._or => return &self._or.common,
            ._and => return &self._and.common,
            .notEqual => return &self.notEqual.common,
            .conditional => return &self.conditional.common,
            .add => return &self.add.common,
            .sub => return &self.sub.common,
            .mult => return &self.mult.common,
            .div => return &self.div.common,
            .mod => return &self.mod.common,
            .exponent => return &self.exponent.common,
            ._catch => return &self._catch.common,
            ._orelse => return &self._orelse.common,
            .call => return &self.call.common,
            .index => return &self.index.common,
            .select => return &self.select.common,
            .function => return &self.function.common,
            .delta => return &self.delta.common,
            .composition => return &self.composition.common,
            .prepend => return &self.prepend.common,
            .sum => return &self.sum.common,
            ._error => return &self._error.common,
            .product => return &self.product.common,
            .diff => return &self.diff.common,
            .concat => return &self.concat.common,
            ._union => return &self._union.common,

            .addrOf => return &self.addrOf.common,
            .sliceOf => return &self.sliceOf.common,
            .namedArg => return &self.namedArg.common,
            .subSlice => return &self.subSlice.common,
            .annotation => return &self.annotation.common,
            .inferredMember => return &self.inferredMember.common,

            ._if => return &self._if.common,
            .cond => return &self.cond.common,
            .match => return &self.match.common,
            .mapping => return &self.mapping.common,
            ._while => return &self._while.common,
            ._for => return &self._for.common,
            .block => return &self.block.common,
            ._break => return &self._break.common,
            ._continue => return &self._continue.common,
            .throw => return &self.throw.common,
            ._return => return &self._return.common,
            .decl => return &self.decl.common,
            .fnDecl => return &self.fnDecl.common,
            ._defer => return &self._defer.common,
        }
    }

    pub fn getToken(self: *AST) Token {
        return self.getCommon().token;
    }

    pub fn createUnit(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .unit = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createInt(token: Token, data: i128, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .int = .{ .common = ASTCommon{ .token = token, ._type = null }, .data = data } }, allocator);
    }

    pub fn createChar(token: Token, data: u8, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .char = .{ .common = ASTCommon{ .token = token, ._type = null }, .data = data } }, allocator);
    }

    pub fn createFloat(token: Token, data: f64, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .float = .{ .common = ASTCommon{ .token = token, ._type = null }, .data = data } }, allocator);
    }

    pub fn createString(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .string = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createIdentifier(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .identifier = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createUnreachable(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._unreachable = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createTrue(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._true = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createFalse(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._false = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createNot(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .not = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createNegate(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .negate = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createDereference(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .dereference = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createTry(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._try = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createOptional(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .optional = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createFromOptional(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .fromOptional = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createInferredError(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .inferredError = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createAssign(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .assign = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createOr(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._or = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createAnd(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._and = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createNotEqual(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .notEqual = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createConditional(_tokens: std.ArrayList(Token), exprs: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        std.debug.assert(_tokens.items.len > 0);
        return try AST.box(AST{ .conditional = .{ .common = ASTCommon{ .token = _tokens.items[0], ._type = null }, .tokens = _tokens, .exprs = exprs } }, allocator);
    }

    pub fn createAdd(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .add = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createSub(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .sub = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createMult(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .mult = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createDiv(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .div = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createMod(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .mod = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createExponent(token: Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .exponent = .{ .common = ASTCommon{ .token = token, ._type = null }, .terms = terms } }, allocator);
    }

    pub fn createCatch(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._catch = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createOrelse(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._orelse = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createCall(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .call = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createIndex(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .index = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createSelect(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .select = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs, .pos = null } }, allocator);
    }

    pub fn createSum(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .sum = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createFunction(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .function = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createDelta(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .delta = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createComposition(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .composition = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createPrepend(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .prepend = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createError(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._error = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createProduct(token: Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        std.debug.assert(terms.items.len >= 2);
        return try AST.box(AST{ .product = .{ .common = ASTCommon{ .token = token, ._type = null }, .terms = terms } }, allocator);
    }

    pub fn createDiff(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .diff = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createConcat(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .concat = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createUnion(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._union = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createAddrOf(token: Token, expr: *AST, mut: bool, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .addrOf = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr, .mut = mut } }, allocator);
    }

    pub fn createSliceOf(token: Token, expr: *AST, len: ?*AST, kind: SliceKind, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .sliceOf = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr, .len = len, .kind = kind } }, allocator);
    }

    pub fn createNamedArg(token: Token, ident: *AST, init: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .namedArg = .{ .common = ASTCommon{ .token = token, ._type = null }, .ident = ident, .init = init } }, allocator);
    }

    pub fn createSubSlice(token: Token, super: *AST, lower: ?*AST, upper: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .subSlice = .{ .common = ASTCommon{ .token = token, ._type = null }, .super = super, .lower = lower, .upper = upper } }, allocator);
    }

    pub fn createAnnotation(token: Token, pattern: *AST, _type: *AST, predicate: ?*AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .annotation = .{ .common = ASTCommon{ .token = token, ._type = null }, .pattern = pattern, .type = _type, .predicate = predicate, .init = init } }, allocator);
    }

    pub fn createInferredMember(token: Token, ident: *AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .inferredMember = .{ .common = ASTCommon{ .token = token, ._type = null }, .ident = ident, .init = init } }, allocator);
    }

    pub fn createIf(token: Token, let: ?*AST, condition: *AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._if = .{ .common = ASTCommon{ .token = token, ._type = null }, .scope = null, .let = let, .condition = condition, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createCond(token: Token, let: ?*AST, mappings: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .cond = .{ .common = ASTCommon{ .token = token, ._type = null }, .scope = null, .let = let, .mappings = mappings } }, allocator);
    }

    pub fn createMatch(token: Token, let: ?*AST, expr: *AST, mappings: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .match = .{ .common = ASTCommon{ .token = token, ._type = null }, .scope = null, .let = let, .expr = expr, .mappings = mappings } }, allocator);
    }

    pub fn createMapping(token: Token, kind: MappingKind, lhs: ?*AST, rhs: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .mapping = .{ .common = ASTCommon{ .token = token, ._type = null }, .kind = kind, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createWhile(token: Token, let: ?*AST, condition: *AST, post: ?*AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._while = .{ .common = ASTCommon{ .token = token, ._type = null }, .scope = null, .let = let, .condition = condition, .post = post, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createFor(token: Token, let: ?*AST, elem: *AST, iterable: *AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._for = .{ .common = ASTCommon{ .token = token, ._type = null }, .scope = null, .let = let, .elem = elem, .iterable = iterable, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createBlock(token: Token, statements: std.ArrayList(*AST), final: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .block = .{ .common = ASTCommon{ .token = token, ._type = null }, .scope = null, .statements = statements, .final = final } }, allocator);
    }

    pub fn createBreak(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._break = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createContinue(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._continue = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createThrow(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .throw = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createReturn(token: Token, expr: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._return = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createDecl(token: Token, pattern: *AST, _type: ?*AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .decl = .{ .common = ASTCommon{ .token = token, ._type = null }, .symbol = null, .pattern = pattern, .type = _type, .init = init } }, allocator);
    }

    pub fn createFnDecl(token: Token, name: ?*AST, params: std.ArrayList(*AST), retType: *AST, refinement: ?*AST, init: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .fnDecl = .{ .common = ASTCommon{ .token = token, ._type = null }, .name = name, .params = params, .retType = retType, .refinement = refinement, .init = init } }, allocator);
    }

    pub fn createDefer(token: Token, statement: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._defer = .{ .common = ASTCommon{ .token = token, ._type = null }, .statement = statement } }, allocator);
    }

    pub fn createBinop(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        switch (token.kind) {
            .PLUS_EQUALS => return createAdd(token, lhs, rhs, allocator),
            .MINUS_EQUALS => return createSub(token, lhs, rhs, allocator),
            .STAR_EQUALS => return createMult(token, lhs, rhs, allocator),
            .SLASH_EQUALS => return createDiv(token, lhs, rhs, allocator),
            .PERCENT_EQUALS => return createMod(token, lhs, rhs, allocator),
            .D_STAR_EQUALS => {
                var terms = std.ArrayList(*AST).init(allocator);
                try terms.append(lhs);
                try terms.append(rhs);
                return createExponent(token, terms, allocator);
            },
            else => {
                std.debug.print("not a operator-assign token\n", .{});
                unreachable;
            },
        }
    }

    pub fn printType(self: *AST, out: anytype) !void {
        switch (self.*) {
            .unit => {
                try out.print("()", .{});
            },
            .identifier => {
                try out.print("{s}", .{self.identifier.common.token.data});
            },
            .addrOf => {
                try out.print("&", .{});
                if (self.addrOf.mut) {
                    try out.print("mut ", .{});
                }
                try self.addrOf.expr.printType(out);
            },
            .optional => {
                try out.print("?", .{});
                try self.optional.expr.printType(out);
            },
            .inferredError => {
                try out.print("!", .{});
                try self.inferredError.expr.printType(out);
            },
            .function => {
                try out.print("(", .{});
                try self.function.lhs.printType(out);
                try out.print(")->", .{});
                try self.function.rhs.printType(out);
            },
            .product => {
                try out.print("(", .{});
                for (self.product.terms.items, 0..) |term, i| {
                    try term.printType(out);
                    if (i + 1 != self.product.terms.items.len) {
                        try out.print(", ", .{});
                    }
                }
                try out.print(")", .{});
            },
            .annotation => {
                try out.print("{s}: ", .{self.annotation.pattern.identifier.common.token.data});
                try self.annotation.type.printType(out);
            },
            else => {
                try out.print("Unimplemented or not a type: {?}\n", .{self.*});
                unreachable;
            },
        }
    }

    // Must always return a valid type!
    pub fn typeof(self: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !*AST {
        if (self.getCommon()._type) |_type| {
            return _type;
        }
        var retval: *AST = undefined;
        switch (self.*) {
            // Bool type
            ._true,
            ._false,
            .not,
            ._or,
            ._and,
            .notEqual,
            .conditional,
            => retval = boolType,

            // Char type
            .char => retval = charType,

            // Float64 type
            .float => retval = floatType,

            // Int64 type
            .int => retval = intType,

            // Type type
            .unit => retval = typeType,

            // Unit type
            .assign => retval = unitType,

            // Void type
            ._continue => retval = voidType,
            ._break => retval = voidType,
            ._return => retval = voidType,

            .product => {
                if ((try self.product.terms.items[0].typeof(scope, errors, allocator)).typesMatch(typeType)) {
                    retval = typeType;
                } else {
                    var terms = std.ArrayList(*AST).init(allocator);
                    for (self.product.terms.items) |term| {
                        try terms.append(try term.typeof(scope, errors, allocator));
                    }
                    retval = try AST.createProduct(self.getToken(), terms, allocator);
                }
            },

            .select => {
                var select_lhs_type = try self.select.lhs.typeof(scope, errors, allocator);
                switch (select_lhs_type.*) {
                    .annotation => {
                        if (std.mem.eql(u8, select_lhs_type.annotation.pattern.identifier.common.token.data, self.select.rhs.identifier.common.token.data)) {
                            self.select.pos = 0;
                            retval = select_lhs_type.annotation.type;
                        } else {
                            errors.addError(Error{ .basic = .{
                                .span = self.getToken().span,
                                .msg = "left-hand-side of select does not contain field",
                                .stage = .typecheck,
                            } });
                            return error.typeError;
                        }
                    },

                    .product => {
                        for (select_lhs_type.product.terms.items, 0..) |term, i| {
                            if (std.mem.eql(u8, term.annotation.pattern.identifier.common.token.data, self.select.rhs.identifier.common.token.data)) {
                                self.select.pos = i;
                                retval = term.annotation.type;
                                break;
                            }
                        } else {
                            errors.addError(Error{ .basic = .{
                                .span = self.getToken().span,
                                .msg = "left-hand-side of select does not contain field",
                                .stage = .typecheck,
                            } });
                            return error.typeError;
                        }
                    },

                    else => unreachable,
                }
            },

            // Identifier
            .identifier => {
                var symbol = scope.lookup(self.identifier.common.token.data, false) orelse {
                    errors.addError(Error{ .undeclaredIdentifier = .{ .identifier = self.identifier.common.token, .stage = .typecheck } });
                    return error.typeError;
                };
                try _validate.validateSymbol(symbol, errors, allocator);
                retval = symbol._type.?;
            },

            // Unary Operators (TODO: Make polymorphic)
            .negate => retval = try self.negate.expr.typeof(scope, errors, allocator),
            .dereference => retval = (try self.dereference.expr.typeof(scope, errors, allocator)).addrOf.expr,
            .addrOf => {
                var child_type = try self.addrOf.expr.typeof(scope, errors, allocator);
                if (child_type.typesMatch(typeType)) {
                    retval = typeType;
                } else {
                    retval = try createAddrOf(self.addrOf.common.token, child_type, self.addrOf.mut, std.heap.page_allocator);
                }
            },

            // Binary operators (TODO: Make polymorphic)
            .add => retval = try self.add.lhs.typeof(scope, errors, allocator),
            .sub => retval = try self.sub.lhs.typeof(scope, errors, allocator),
            .mult => retval = try self.mult.lhs.typeof(scope, errors, allocator),
            .div => retval = try self.div.lhs.typeof(scope, errors, allocator),
            .mod => retval = try self.mod.lhs.typeof(scope, errors, allocator),
            .exponent => retval = try self.exponent.terms.items[0].typeof(scope, errors, allocator),

            // Control-flow expressions
            ._if => retval = try self._if.bodyBlock.typeof(scope, errors, allocator),
            .cond => retval = try self.cond.mappings.items[0].typeof(scope, errors, allocator),
            .mapping => if (self.mapping.rhs) |rhs| {
                retval = try rhs.typeof(scope, errors, allocator);
            } else {
                retval = unitType;
            },
            ._while => retval = try self._while.bodyBlock.typeof(scope, errors, allocator),
            .block => if (self.block.final) |_| {
                retval = unitType;
            } else if (self.block.statements.items.len == 0) {
                retval = unitType;
            } else {
                retval = try self.block.statements.items[self.block.statements.items.len - 1].typeof(self.block.scope.?, errors, allocator);
            },
            .call => {
                var fn_type: *AST = try self.call.lhs.typeof(scope, errors, allocator);
                retval = fn_type.function.rhs;
            },
            .fnDecl => {
                retval = self.fnDecl.symbol.?._type.?;
            },

            else => {
                std.debug.print("Unimplemented typeof() for: AST.{s}\n", .{@tagName(self.*)});
                return error.Unimplemented;
            },
        }
        self.getCommon()._type = retval;
        return retval;
    }

    pub fn typesMatch(self: *AST, other: *AST) bool {
        if (self.* == .annotation) {
            return typesMatch(self.annotation.type, other);
        } else if (other.* == .annotation) {
            return typesMatch(self, other.annotation.type);
        }

        switch (self.*) {
            .identifier => {
                if (other.* != .identifier) {
                    return false;
                } else if (std.mem.eql(u8, "Float", self.identifier.common.token.data) and std.mem.eql(u8, "Int", other.identifier.common.token.data)) {
                    return true;
                } else {
                    return std.mem.eql(u8, self.identifier.common.token.data, other.identifier.common.token.data);
                }
            },
            .addrOf => {
                if (other.* != .addrOf) {
                    return false;
                } else {
                    return (self.addrOf.mut == false or self.addrOf.mut == other.addrOf.mut) and typesMatch(self.addrOf.expr, other.addrOf.expr);
                }
            },
            .annotation => unreachable,

            .unit => {
                return other.* == .unit;
            },
            .product => {
                if (other.* != .product) {
                    return false;
                } else {
                    var retval = true;
                    for (self.product.terms.items, other.product.terms.items) |term, other_term| {
                        retval = retval and term.typesMatch(other_term);
                    }
                    return retval;
                }
            },
            .function => {
                if (other.* != .function) {
                    return false;
                } else {
                    return self.function.lhs.typesMatch(other.function.lhs) and self.function.rhs.typesMatch(other.function.rhs);
                }
            },
            else => {
                std.debug.print("Unimplemented for {s}\n", .{@tagName(self.*)});
                unreachable;
            },
        }
    }
};
