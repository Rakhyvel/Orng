const errs = @import("errors.zig");
const primitives = @import("primitives.zig");
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

pub var poisoned: *AST = undefined;
var inited: bool = false;

/// Initializes internal structures if they are not already initialized.
pub fn init_structures() !void {
    if (!inited) {
        poisoned = try AST.createPoison(Token{ .kind = .L_PAREN, .data = "LMAO GET POISONED", .span = Span{ .filename = "", .line_text = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        poisoned.getCommon().validation_state = .invalid;
        inited = true;
    }
}

/// Represents the kind of a slice.
pub const SliceKind = union(enum) {
    SLICE, // data ptr and len
    MUT, // mutable data ptr and len
    MULTIPTR, // c-style `*` pointer, no len
    ARRAY, // static homogenous tuple, compile-time len

    /// Serializes a `SliceKind` variant into a string representation.
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

/// Represents different validation states of an AST.
pub const Validation_State = union(enum) {
    /// Validation has not been done, undetermined state.
    unvalidated,

    /// Validation is currently in progress, undetermined state.
    validating,

    /// Validation completed successfully.
    valid: struct {
        /// The valid form of the AST.
        valid_form: *AST,
    },

    /// Validation completed unsuccessfully.
    invalid,
};

/// Contains common properties of all AST nodes
const ASTCommon = struct {
    /// Token that defined the AST node in text.
    token: Token,

    /// The type of the AST as an expression.
    /// Memoized, use `typeof()`.
    /// TODO: Postfix with _ to signify private
    _type: ?*AST,

    /// The expanded version of the `_type` field.
    /// Memoized, use `expanded_type()`.
    /// TODO: Postfix with _ to signify private
    expanded_type: ?*AST = null,

    /// How many slots a value of the type of the AST takes up.
    /// Memoized, use `get_slots()`.
    /// TODO: Postfix with _ to signify private
    slots: ?i64 = null,

    /// The validation status of the AST
    validation_state: Validation_State = .unvalidated,
};

/// Represents an Abstract Syntax Tree.
pub const AST = union(enum) {
    /// Not generated for correct programs, used to represent incorrect ASTs
    poison: struct { common: ASTCommon },
    /// Unit type
    unit: struct { common: ASTCommon },
    /// Integer constant
    int: struct {
        common: ASTCommon,
        data: i128,
        represents: *AST, //< Type that this constant represents. Set on validation.
    },
    /// Floating-point constant
    float: struct {
        common: ASTCommon,
        data: f64,
        represents: *AST, //< Type that this constant represents. Set on validation.
    },
    /// Character constant
    char: struct { common: ASTCommon },
    /// String constant
    string: struct {
        common: ASTCommon,
        data: []const u8,
    },
    /// True constant
    _true: struct { common: ASTCommon },
    /// False constant
    _false: struct { common: ASTCommon },
    /// Identifier
    identifier: struct { common: ASTCommon },

    not: struct { common: ASTCommon, expr: *AST },
    negate: struct { common: ASTCommon, expr: *AST },
    dereference: struct { common: ASTCommon, expr: *AST },
    _try: struct { common: ASTCommon, expr: *AST },
    discard: struct { common: ASTCommon, expr: *AST },
    _comptime: struct {
        common: ASTCommon,
        expr: *AST,
        name: ?*AST = null,
        symbol: ?*Symbol = null,
    },

    // Binary operators
    assign: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _or: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _and: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    add: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    sub: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    mult: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    div: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    mod: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    equal: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    not_equal: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    greater: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    lesser: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    greater_equal: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    lesser_equal: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _catch: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    _orelse: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    call: struct { common: ASTCommon, lhs: *AST, args: std.ArrayList(*AST) },
    index: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    select: struct {
        common: ASTCommon,
        lhs: *AST,
        rhs: *AST,
        pos: ?usize,

        pub fn offset_at(self: *@This(), scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !i128 {
            var lhs_expanded_type = try (try self.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            if (lhs_expanded_type.* == .product) {
                return try lhs_expanded_type.product.get_offset(self.pos.?, scope, errors, allocator);
            } else if (lhs_expanded_type.* == .sum) {
                return try lhs_expanded_type.sum.get_offset(self.pos.?, scope, errors, allocator);
            } else {
                std.debug.print("{s}\n", .{@tagName(lhs_expanded_type.*)});
                unreachable;
            }
        }
    },
    function: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    invoke: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    sum: struct {
        common: ASTCommon,
        terms: std.ArrayList(*AST),
        was_optional: bool = false,
        was_error: bool = false,
        all_unit: ?bool = null,
        pub fn is_all_unit(self: *@This()) bool {
            if (self.all_unit) |all_unit| {
                return all_unit;
            }
            var res = true;
            for (self.terms.items) |term| {
                res = res and term.c_typesMatch(primitives.unit_type);
            }
            self.all_unit = res;
            return res;
        }

        // TODO: Duck type this with product/sum
        pub fn get_offset(self: *@This(), field: usize, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !i128 {
            var offset: i128 = 0;
            for (0..field) |i| {
                var item = self.terms.items[i];
                offset += (try item.expand_type(scope, errors, allocator)).get_slots(); // TODO: Is it necessary to expand here?
            }
            return offset;
        }
    },
    inferred_error: struct {
        common: ASTCommon,
        terms: std.ArrayList(*AST),

        pub fn add_term(self: *@This(), addend: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
            std.debug.assert(addend.* == .annotation);
            for (self.terms.items) |term| {
                if (std.mem.eql(u8, term.annotation.pattern.getToken().data, addend.annotation.pattern.getToken().data)) {
                    if (!try term.annotation.type.typesMatch(term, scope, errors, allocator)) {
                        errors.addError(Error{ .sum_duplicate = .{ .span = self.common.token.span, .identifier = term.annotation.pattern.getToken().data, .first = term.getToken().span } });
                        return error.typeError;
                    } else {
                        // Duplicate found, types match. OK!
                        return;
                    }
                }
            }
            // No duplicate found, add to inferred error set
            try self.terms.append(addend);
        }
    },
    inject: struct { common: ASTCommon, lhs: *AST, rhs: *AST },
    product: struct {
        common: ASTCommon,
        terms: std.ArrayList(*AST),
        homotypical: ?bool = null,
        was_slice: bool = false,

        pub fn is_homotypical(self: *@This(), scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !bool {
            if (self.homotypical) |homotypical| {
                return homotypical;
            }
            var first_type = self.terms.items[0];
            for (self.terms.items, 0..) |term, i| {
                if (i == 0) {
                    continue;
                }
                if (!try first_type.typesMatch(term, scope, errors, allocator)) {
                    self.homotypical = false;
                    return false;
                }
            }
            self.homotypical = true;
            return true;
        }

        pub fn get_offset(self: *@This(), field: usize, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !i128 {
            var offset: i128 = 0;
            for (0..field) |i| {
                var item = self.terms.items[i];
                offset += (try item.expand_type(scope, errors, allocator)).get_slots(); // TODO: Is it necessary to expand here?
            }
            return offset;
        }
    },
    _union: struct { common: ASTCommon, lhs: *AST, rhs: *AST },

    // Fancy operators
    addrOf: struct { common: ASTCommon, expr: *AST, mut: bool },
    sliceOf: struct { common: ASTCommon, expr: *AST, len: ?*AST, kind: SliceKind },
    subSlice: struct { common: ASTCommon, super: *AST, lower: ?*AST, upper: ?*AST },
    annotation: struct { common: ASTCommon, pattern: *AST, type: *AST, predicate: ?*AST, init: ?*AST },
    inferredMember: struct {
        common: ASTCommon,
        ident: *AST,
        init: ?*AST = null,
        base: ?*AST = null, // This should ideally be kept in unexpanded form. typeof(inferredMember) returns inferredMember.base.?.expand_type()
        pos: ?i128 = null,
    },
    _typeOf: struct {
        common: ASTCommon,
        expr: *AST,
    },
    domainOf: struct {
        common: ASTCommon,
        sum_expr: *AST,
        expr: *AST,
    },

    // Control-flow expressions
    _if: struct {
        common: ASTCommon,
        scope: ?*Scope,
        let: ?*AST,
        condition: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    match: struct {
        common: ASTCommon,
        scope: ?*Scope,
        let: ?*AST,
        expr: *AST,
        mappings: std.ArrayList(*AST),
        has_else: bool,
    },
    mapping: struct {
        common: ASTCommon,
        lhs: ?*AST,
        rhs: ?*AST,
        scope: ?*Scope, // Scope used for `match` mappings. Captures live in this scope, rhs of mapping lives in this scope. Lives in `match`'s scope
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
    _return: struct { common: ASTCommon, expr: ?*AST },
    symbol: struct {
        common: ASTCommon,
        name: []const u8,
        kind: _symbol.SymbolKind,
        symbol: *Symbol = undefined,
    },
    decl: struct {
        common: ASTCommon,
        symbols: std.ArrayList(*Symbol), // List of symbols that are defined with this statement
        pattern: *AST, // Structure of ASTs. Has to be structured to allow tree patterns like `let ((a, b), (c, d)) = blah`
        type: ?*AST,
        init: ?*AST,
        top_level: bool,
    },
    fnDecl: struct {
        common: ASTCommon,
        name: ?*AST,
        params: std.ArrayList(*AST), // List of the AST declarations for the parameters
        param_symbols: std.ArrayList(*Symbol), // List of the actual symbols for the parameters
        retType: *AST,
        refinement: ?*AST,
        init: *AST,
        symbol: ?*Symbol = null,
        infer_error: bool,
    },
    _defer: struct { common: ASTCommon, statement: *AST },
    _errdefer: struct { common: ASTCommon, statement: *AST },

    /// Boxes an AST value into an allocator.
    fn box(ast: AST, alloc: std.mem.Allocator) error{OutOfMemory}!*AST {
        const retval = try alloc.create(AST);
        retval.* = ast;
        return retval;
    }

    /// Retrieve the common field of an AST node
    pub fn getCommon(self: *AST) *ASTCommon {
        switch (self.*) {
            .poison => return &self.poison.common,
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
            .discard => return &self.discard.common,
            ._typeOf => return &self._typeOf.common,
            .domainOf => return &self.domainOf.common,
            ._comptime => return &self._comptime.common,

            .assign => return &self.assign.common,
            ._or => return &self._or.common,
            ._and => return &self._and.common,
            .add => return &self.add.common,
            .sub => return &self.sub.common,
            .mult => return &self.mult.common,
            .div => return &self.div.common,
            .mod => return &self.mod.common,
            .equal => return &self.equal.common,
            .not_equal => return &self.not_equal.common,
            .greater => return &self.greater.common,
            .lesser => return &self.lesser.common,
            .greater_equal => return &self.greater_equal.common,
            .lesser_equal => return &self.lesser_equal.common,
            ._catch => return &self._catch.common,
            ._orelse => return &self._orelse.common,
            .call => return &self.call.common,
            .index => return &self.index.common,
            .select => return &self.select.common,
            .function => return &self.function.common,
            .invoke => return &self.invoke.common,
            .sum => return &self.sum.common,
            .inferred_error => return &self.inferred_error.common,
            .inject => return &self.inject.common,
            .product => return &self.product.common,
            ._union => return &self._union.common,

            .addrOf => return &self.addrOf.common,
            .sliceOf => return &self.sliceOf.common,
            .subSlice => return &self.subSlice.common,
            .annotation => return &self.annotation.common,
            .inferredMember => return &self.inferredMember.common,

            ._if => return &self._if.common,
            .match => return &self.match.common,
            .mapping => return &self.mapping.common,
            ._while => return &self._while.common,
            ._for => return &self._for.common,
            .block => return &self.block.common,
            ._break => return &self._break.common,
            ._continue => return &self._continue.common,
            ._return => return &self._return.common,
            .symbol => return &self.symbol.common,
            .decl => return &self.decl.common,
            .fnDecl => return &self.fnDecl.common,
            ._defer => return &self._defer.common,
            ._errdefer => return &self._errdefer.common,
        }
    }

    /// Retrieves the token of an AST node
    pub fn getToken(self: *AST) Token {
        return self.getCommon().token;
    }

    /// Retrieves the slots of an AST node.
    pub fn get_slots(self: *AST) i64 {
        if (self.getCommon().slots == null) {
            switch (self.*) {
                .product => {
                    var total_slots: i64 = 0;
                    for (self.product.terms.items) |child| {
                        total_slots += child.get_slots();
                    }
                    self.getCommon().slots = total_slots;
                },

                .sum => {
                    var max_slots: i64 = 0;
                    for (self.sum.terms.items) |child| {
                        const child_slots = child.get_slots();
                        if (max_slots < child_slots) {
                            max_slots = child_slots;
                        }
                    }
                    self.getCommon().slots = 1 + max_slots;
                },

                .unit => {
                    self.getCommon().slots = 0;
                },

                .annotation => {
                    self.getCommon().slots = self.annotation.type.get_slots();
                },

                else => {
                    self.getCommon().slots = 1;
                },
            }
        }

        return self.getCommon().slots.?;
    }

    pub fn createPoison(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .poison = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createUnit(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .unit = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createInt(token: Token, data: i128, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .int = .{ .common = ASTCommon{ .token = token, ._type = null }, .data = data, .represents = primitives.int_type } }, allocator);
    }

    pub fn createChar(token: Token, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .char = .{ .common = ASTCommon{ .token = token, ._type = null } } }, allocator);
    }

    pub fn createFloat(token: Token, data: f64, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .float = .{ .common = ASTCommon{ .token = token, ._type = null }, .data = data, .represents = primitives.float_type } }, allocator);
    }

    pub fn createString(token: Token, data: []const u8, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .string = .{ .common = ASTCommon{ .token = token, ._type = null }, .data = data } }, allocator);
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

    pub fn createDiscard(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .discard = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createComptime(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._comptime = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr, .name = null, .symbol = null } }, allocator);
    }

    pub fn createTypeOf(token: Token, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._typeOf = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createDomainOf(token: Token, sum_expr: *AST, expr: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .domainOf = .{ .common = ASTCommon{ .token = token, ._type = null }, .sum_expr = sum_expr, .expr = expr } }, allocator);
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

    pub fn createEqual(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .equal = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createNotEqual(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .not_equal = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createGreater(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .greater = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createLesser(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .lesser = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createGreaterEqual(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .greater_equal = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createLesserEqual(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .lesser_equal = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
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

    pub fn createCatch(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._catch = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createOrelse(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._orelse = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createCall(token: Token, lhs: *AST, args: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .call = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .args = args } }, allocator);
    }

    pub fn createIndex(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .index = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createSelect(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .select = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs, .pos = null } }, allocator);
    }

    pub fn createSum(token: Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .sum = .{ .common = ASTCommon{ .token = token, ._type = null }, .terms = terms } }, allocator);
    }

    pub fn createInferredError(token: Token, ok: *AST, allocator: std.mem.Allocator) !*AST {
        var retval: AST = AST{ .inferred_error = .{ .common = ASTCommon{ .token = token, ._type = null }, .terms = std.ArrayList(*AST).init(allocator) } };
        const ok_annot = try createAnnotation(token, try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "ok", .span = Span{ .filename = "", .line_text = "", .line = 0, .col = 0 } }, allocator), ok, null, null, allocator);
        try retval.inferred_error.terms.append(ok_annot);

        return try AST.box(retval, allocator);
    }

    pub fn createInject(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) error{OutOfMemory}!*AST {
        return try AST.box(AST{ .inject = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createFunction(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .function = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createInvoke(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .invoke = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs } }, allocator);
    }

    pub fn createProduct(token: Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) !*AST {
        // std.debug.assert(terms.items.len >= 2);
        return try AST.box(AST{ .product = .{ .common = ASTCommon{ .token = token, ._type = null }, .terms = terms } }, allocator);
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

    pub fn createSubSlice(token: Token, super: *AST, lower: ?*AST, upper: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .subSlice = .{ .common = ASTCommon{ .token = token, ._type = null }, .super = super, .lower = lower, .upper = upper } }, allocator);
    }

    pub fn createAnnotation(token: Token, pattern: *AST, _type: *AST, predicate: ?*AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .annotation = .{ .common = ASTCommon{ .token = token, ._type = null }, .pattern = pattern, .type = _type, .predicate = predicate, .init = init } }, allocator);
    }

    pub fn createInferredMember(token: Token, ident: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .inferredMember = .{ .common = ASTCommon{ .token = token, ._type = null }, .ident = ident } }, allocator);
    }

    pub fn createIf(token: Token, let: ?*AST, condition: *AST, bodyBlock: *AST, elseBlock: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._if = .{ .common = ASTCommon{ .token = token, ._type = null }, .scope = null, .let = let, .condition = condition, .bodyBlock = bodyBlock, .elseBlock = elseBlock } }, allocator);
    }

    pub fn createMatch(token: Token, let: ?*AST, expr: *AST, mappings: std.ArrayList(*AST), has_else: bool, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .match = .{ .common = ASTCommon{ .token = token, ._type = null }, .scope = null, .let = let, .expr = expr, .mappings = mappings, .has_else = has_else } }, allocator);
    }

    pub fn createMapping(token: Token, lhs: ?*AST, rhs: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .mapping = .{ .common = ASTCommon{ .token = token, ._type = null }, .lhs = lhs, .rhs = rhs, .scope = null } }, allocator);
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

    pub fn createReturn(token: Token, expr: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._return = .{ .common = ASTCommon{ .token = token, ._type = null }, .expr = expr } }, allocator);
    }

    pub fn createSymbol(token: Token, kind: _symbol.SymbolKind, name: []const u8, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .symbol = .{ .common = ASTCommon{ .token = token, ._type = null }, .kind = kind, .name = name } }, allocator);
    }

    pub fn createDecl(token: Token, pattern: *AST, _type: ?*AST, init: ?*AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .decl = .{ .common = ASTCommon{ .token = token, ._type = null }, .symbols = std.ArrayList(*Symbol).init(allocator), .pattern = pattern, .type = _type, .init = init, .top_level = false } }, allocator);
    }

    pub fn createFnDecl(token: Token, name: ?*AST, params: std.ArrayList(*AST), retType: *AST, refinement: ?*AST, init: *AST, infer_error: bool, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ .fnDecl = .{
            .common = ASTCommon{ .token = token, ._type = null },
            .name = name,
            .params = params,
            .param_symbols = std.ArrayList(*Symbol).init(allocator),
            .retType = retType,
            .refinement = refinement,
            .init = init,
            .infer_error = infer_error,
        } }, allocator);
    }

    pub fn createDefer(token: Token, statement: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._defer = .{ .common = ASTCommon{ .token = token, ._type = null }, .statement = statement } }, allocator);
    }

    pub fn createErrDefer(token: Token, statement: *AST, allocator: std.mem.Allocator) !*AST {
        return try AST.box(AST{ ._errdefer = .{ .common = ASTCommon{ .token = token, ._type = null }, .statement = statement } }, allocator);
    }

    pub fn create_slice_type(of: *AST, mut: bool, allocator: std.mem.Allocator) !*AST {
        var term_types = std.ArrayList(*AST).init(allocator);
        var data_type = try AST.createAddrOf(
            of.getToken(),
            of,
            mut,
            allocator,
        );
        var annot_type = try AST.createAnnotation(of.getToken(), try AST.createIdentifier(Token.create("data", null, "", "", 0, 0), allocator), data_type, null, null, allocator);
        data_type.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = data_type } };
        annot_type.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = annot_type } };
        try term_types.append(annot_type);
        try term_types.append(try AST.createAnnotation(
            of.getToken(),
            try AST.createIdentifier(Token.create("length", null, "", "", 0, 0), allocator),
            primitives.int_type,
            null,
            null,
            allocator,
        ));
        var retval = try AST.createProduct(of.getToken(), term_types, allocator);
        retval.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = retval } };
        retval.product.was_slice = true;
        return retval;
    }

    // Expr must be a product value of length `l`. Slice value is `(&expr[0], l)`.
    pub fn create_slice_value(expr: *AST, mut: bool, expr_type: *AST, allocator: std.mem.Allocator) !*AST {
        var new_terms = std.ArrayList(*AST).init(allocator);
        var zero = try AST.createInt(expr.getToken(), 0, allocator);
        zero.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = zero } };
        var index = try AST.createIndex(
            expr.getToken(),
            expr,
            zero,
            allocator,
        );
        index.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = index } };
        var addr = try AST.createAddrOf(
            expr.getToken(),
            index,
            mut,
            allocator,
        );
        addr.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = addr } };
        try new_terms.append(addr);

        var length = try AST.createInt(expr.getToken(), expr_type.product.terms.items.len, allocator);
        length.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = length } };
        try new_terms.append(length);

        var retval = try AST.createProduct(expr.getToken(), new_terms, allocator);
        retval.product.was_slice = true;
        return retval;
    }

    pub fn create_optional_type(of_type: *AST, allocator: std.mem.Allocator) !*AST {
        var term_types = std.ArrayList(*AST).init(allocator);

        const none_type = try AST.createAnnotation(of_type.getToken(), try AST.createIdentifier(Token.create("none", null, "", "", 0, 0), allocator), primitives.unit_type, null, primitives.unit_type, allocator);
        try term_types.append(none_type);

        const some_type = try AST.createAnnotation(of_type.getToken(), try AST.createIdentifier(Token.create("some", null, "", "", 0, 0), allocator), of_type, null, null, allocator);
        try term_types.append(some_type);

        var retval = try AST.createSum(of_type.getToken(), term_types, allocator);
        retval.sum.was_optional = true;
        return retval;
    }

    pub fn create_error_type(err_type: *AST, ok_type: *AST, allocator: std.mem.Allocator) !*AST {
        const ok_annot = try AST.createAnnotation(ok_type.getToken(), try AST.createIdentifier(Token.create("ok", null, "", "", 0, 0), allocator), ok_type, null, null, allocator);
        var ok_sum_terms = std.ArrayList(*AST).init(allocator);
        try ok_sum_terms.append(ok_annot);
        var ok_sum = try AST.createSum(ok_type.getToken(), ok_sum_terms, allocator);
        ok_sum.sum.was_error = true;

        // Err!Ok => (ok:Ok|) || Err
        // This is done so that `ok` has an invariant tag of `0`, and errors have a non-zero tag.
        const retval = try AST.createUnion(err_type.getToken(), ok_sum, err_type, allocator);
        return retval;
    }

    pub fn get_none_type(opt_sum: *AST) *AST {
        std.debug.assert(opt_sum.sum.was_optional);
        return opt_sum.sum.terms.items[0];
    }

    pub fn get_some_type(opt_sum: *AST) *AST {
        std.debug.assert(opt_sum.sum.was_optional);
        return opt_sum.sum.terms.items[1];
    }

    pub fn get_ok_type(err_union: *AST) *AST {
        std.debug.assert(err_union.sum.was_error);
        return err_union.sum.terms.items[0];
    }

    pub fn expand_type(self: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !*AST {
        if (self.getCommon().expanded_type) |expaned_type| {
            return expaned_type;
        }

        var retval: *AST = undefined;
        switch (self.*) {
            .identifier => {
                const symbol = scope.lookup(self.getToken().data, false) orelse {
                    errors.addError(Error{ .undeclaredIdentifier = .{ .identifier = self.getToken(), .scope = scope, .expected = null } });
                    return error.typeError;
                };
                try _validate.validateSymbol(symbol, errors, allocator);
                if (symbol.init) |init| {
                    retval = try init.expand_type(scope, errors, allocator);
                } else {
                    retval = self;
                }
            },
            .product => {
                var terms = std.ArrayList(*AST).init(allocator);
                var change = false;
                for (self.product.terms.items) |term| {
                    const new_term = try term.expand_type(scope, errors, allocator);
                    try terms.append(new_term);
                    change = new_term != term or change;
                }
                if (change) {
                    retval = try AST.createProduct(self.getToken(), terms, allocator);
                    retval.product.was_slice = self.product.was_slice;
                } else {
                    terms.deinit();
                    retval = self;
                }
            },
            .sum => {
                var terms = std.ArrayList(*AST).init(allocator);
                var change = false;
                for (self.sum.terms.items) |term| {
                    const new_term = try term.expand_type(scope, errors, allocator);
                    try terms.append(new_term);
                    change = new_term != term or change;
                }
                if (change) {
                    retval = try AST.createSum(self.getToken(), terms, allocator);
                    retval.sum.was_error = self.sum.was_error;
                    retval.sum.was_optional = self.sum.was_optional;
                } else {
                    terms.deinit();
                    retval = self;
                }
            },
            .addrOf => {
                const expr = try self.addrOf.expr.expand_type(scope, errors, allocator);
                retval = try AST.createAddrOf(self.getToken(), expr, self.addrOf.mut, allocator);
            },
            .function => {
                const lhs = try self.function.lhs.expand_type(scope, errors, allocator);
                const rhs = try self.function.rhs.expand_type(scope, errors, allocator);
                retval = try AST.createFunction(self.getToken(), lhs, rhs, allocator);
            },
            .annotation => {
                const expr = try self.annotation.type.expand_type(scope, errors, allocator);
                retval = try AST.createAnnotation(self.getToken(), self.annotation.pattern, expr, self.annotation.predicate, self.annotation.init, allocator);
            },
            .index => {
                var expr = try self.index.lhs.expand_type(scope, errors, allocator);
                if (expr.* == .identifier) {
                    std.debug.print("{s}\n", .{expr.getToken().data});
                }
                retval = expr.product.terms.items[@as(usize, @intCast(self.index.rhs.int.data))];
            },
            .poison,
            .unit,
            => retval = self,

            else => retval = self,
        }
        retval.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = retval } };
        self.getCommon().expanded_type = retval;
        return retval;
    }

    pub fn createBinop(token: Token, lhs: *AST, rhs: *AST, allocator: std.mem.Allocator) !*AST {
        switch (token.kind) {
            .PLUS_EQUALS => return createAdd(token, lhs, rhs, allocator),
            .MINUS_EQUALS => return createSub(token, lhs, rhs, allocator),
            .STAR_EQUALS => return createMult(token, lhs, rhs, allocator),
            .SLASH_EQUALS => return createDiv(token, lhs, rhs, allocator),
            .PERCENT_EQUALS => return createMod(token, lhs, rhs, allocator),
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
                try out.print("{s}", .{self.getToken().data});
            },
            .addrOf => {
                try out.print("&", .{});
                if (self.addrOf.mut) {
                    try out.print("mut ", .{});
                }
                try self.addrOf.expr.printType(out);
            },
            .sliceOf => {
                try out.print("[", .{});
                switch (self.sliceOf.kind) {
                    .MUT => try out.print("mut", .{}),
                    .MULTIPTR => try out.print("*", .{}),
                    .ARRAY => try self.sliceOf.len.?.printType(out),
                    .SLICE => {},
                }
                try out.print("]", .{});
                try self.sliceOf.expr.printType(out);
            },
            .function => {
                try out.print("(", .{});
                try self.function.lhs.printType(out);
                try out.print(")->", .{});
                try self.function.rhs.printType(out);
            },
            .product => if (self.product.homotypical != null and self.product.homotypical.?) {
                try out.print("[{}]", .{self.product.terms.items.len});
                try self.product.terms.items[0].printType(out);
            } else if (self.product.was_slice) {
                try out.print("[]", .{});
                try self.product.terms.items[0].printType(out);
            } else {
                try out.print("(", .{});
                for (self.product.terms.items, 0..) |term, i| {
                    try term.printType(out);
                    if (i + 1 != self.product.terms.items.len) {
                        try out.print(", ", .{});
                    }
                }
                try out.print(")", .{});
            },
            .sum => if (self.sum.was_optional) {
                try out.print("?", .{});
                try self.get_some_type().annotation.type.printType(out);
            } else {
                try out.print("(", .{});
                for (self.sum.terms.items, 0..) |term, i| {
                    try term.printType(out);
                    if (self.sum.terms.items.len == 1 or i + 1 != self.sum.terms.items.len) {
                        try out.print(" | ", .{});
                    }
                }
                try out.print(")", .{});
            },
            .inferred_error => {
                try out.print("!", .{});
                try self.inferred_error.terms.items[0].annotation.type.printType(out);
            },
            ._union => {
                try self._union.lhs.printType(out);
                try out.print("||", .{});
                try self._union.rhs.printType(out);
            },
            .annotation => {
                try out.print("{s}: ", .{self.annotation.pattern.getToken().data});
                try self.annotation.type.printType(out);
            },

            // Not necessarily types, but may appear in a type definition
            .int => try out.print("{}", .{self.int.data}),
            .block => {
                try out.print("{{", .{});
                for (self.block.statements.items, 0..) |statement, i| {
                    try statement.printType(out);
                    if (self.block.final != null or i > self.block.statements.items.len - 1) {
                        try out.print("; ", .{});
                    }
                }
                if (self.block.final) |final| {
                    try final.printType(out);
                }
                try out.print("}}", .{});
            },
            .index => {
                try self.index.lhs.printType(out);
                try out.print("[", .{});
                try self.index.rhs.printType(out);
                try out.print("]", .{});
            },
            ._unreachable => {
                try out.print("unreachable", .{});
            },
            .poison => try out.print("<error>", .{}),
            else => {
                try out.print("\nprintTypes(): Unimplemented or not a type: {s}\n", .{@tagName(self.*)});
                unreachable;
            },
        }
    }

    // Must always return a valid type!
    pub fn typeof(self: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !*AST {
        std.debug.assert(self.getCommon().validation_state != .unvalidated);
        if (self.getCommon()._type) |_type| {
            return _type;
        }
        var retval: *AST = undefined;
        switch (self.*) {
            // Poisoned type
            .poison => retval = poisoned,

            // Bool type
            ._true,
            ._false,
            .not,
            ._or,
            ._and,
            .equal,
            .not_equal,
            .greater,
            .lesser,
            .greater_equal,
            .lesser_equal,
            => retval = primitives.bool_type,

            // Char type
            .char => retval = primitives.char_type,

            // Float constant type
            .float => retval = self.float.represents,

            // Int constant type
            .int => retval = self.int.represents,

            // String type
            .string => retval = primitives.string_type,

            // Type type
            .unit,
            .annotation,
            .sum,
            .inferred_error,
            ._union,
            .function,
            => retval = primitives.type_type,

            // Unit type
            .decl,
            .assign,
            ._defer,
            ._errdefer,
            .discard,
            => retval = primitives.unit_type,

            // Void type
            ._continue,
            ._break,
            ._return,
            ._unreachable,
            => retval = primitives.void_type,

            // Binary operators
            .add => retval = try self.add.lhs.typeof(scope, errors, allocator),
            .sub => retval = try self.sub.lhs.typeof(scope, errors, allocator),
            .mult => retval = try self.mult.lhs.typeof(scope, errors, allocator),
            .div => retval = try self.div.lhs.typeof(scope, errors, allocator),
            .mod => retval = try self.mod.lhs.typeof(scope, errors, allocator),
            ._catch => retval = try self._catch.rhs.typeof(scope, errors, allocator),
            ._orelse => retval = try self._orelse.rhs.typeof(scope, errors, allocator),

            .product => {
                var first_type = try self.product.terms.items[0].typeof(scope, errors, allocator);
                if (try first_type.typesMatch(primitives.type_type, scope, errors, allocator)) {
                    // typeof product type is Type
                    retval = primitives.type_type;
                } else if (self.product.was_slice) {
                    var addr: *AST = self.product.terms.items[0];
                    retval = try create_slice_type(try addr.addrOf.expr.typeof(scope, errors, allocator), addr.addrOf.mut, allocator);
                    retval.product.was_slice = true;
                } else {
                    var terms = std.ArrayList(*AST).init(allocator);
                    for (self.product.terms.items) |term| {
                        const term_type = try term.typeof(scope, errors, allocator);
                        try terms.append(term_type);
                    }
                    retval = try AST.createProduct(self.getToken(), terms, allocator);
                    retval.product.was_slice = self.product.was_slice;
                }
            },

            .index => {
                var lhs_type = try self.index.lhs.typeof(scope, errors, allocator);
                if (try lhs_type.typesMatch(primitives.type_type, scope, errors, allocator) and self.index.lhs.* == .product) {
                    retval = self.index.lhs.product.terms.items[0];
                } else if (lhs_type.* == .product) { // TODO: Replace with if the type implements Indexable or something
                    if (lhs_type.product.was_slice) {
                        retval = lhs_type.product.terms.items[0].annotation.type.addrOf.expr;
                    } else {
                        retval = lhs_type.product.terms.items[0];
                    }
                } else if (lhs_type.* == .identifier and std.mem.eql(u8, lhs_type.getToken().data, "String")) {
                    retval = primitives.byte_type;
                } else if (lhs_type.* == .poison) {
                    retval = poisoned;
                } else {
                    std.debug.print("{s} is not indexable\n", .{@tagName(lhs_type.*)});
                    unreachable;
                }
            },

            .select => {
                var select_lhs_type = try (try self.select.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                var annot_list: *std.ArrayList(*AST) = undefined;
                if (select_lhs_type.* == .product) {
                    annot_list = &select_lhs_type.product.terms;
                } else if (select_lhs_type.* == .sum) {
                    annot_list = &select_lhs_type.sum.terms;
                } else {
                    unreachable;
                }
                for (annot_list.items, 0..) |term, i| {
                    if (term.* != .annotation) {
                        errors.addError(Error{ .basic = .{
                            .span = self.getToken().span,
                            .msg = "left-hand-side of select is not selectable",
                        } });
                        return error.typeError;
                    }
                    if (std.mem.eql(u8, term.annotation.pattern.getToken().data, self.select.rhs.getToken().data)) {
                        self.select.pos = i;
                        retval = term.annotation.type;
                        break;
                    }
                } else {
                    errors.addError(Error{ .member_not_in = .{
                        .span = self.getToken().span,
                        .identifier = self.select.rhs.getToken().data,
                        .group_name = "tuple",
                    } });
                    return error.typeError;
                }
            },

            // Identifier
            .identifier => if (std.mem.eql(u8, self.getToken().data, "_")) {
                retval = primitives.unit_type;
            } else {
                const symbol = try _validate.findSymbol(self, null, scope, errors);
                try _validate.validateSymbol(symbol, errors, allocator);
                retval = symbol._type orelse {
                    errors.addError(Error{ .basic = .{ .span = self.getToken().span, .msg = "recursive definition detected" } });
                    return poisoned;
                };
            },

            // Unary Operators
            .negate => retval = try self.negate.expr.typeof(scope, errors, allocator),
            .dereference => {
                const _type = try self.dereference.expr.typeof(scope, errors, allocator);
                retval = _type.addrOf.expr;
            },
            .addrOf => {
                var child_type = try self.addrOf.expr.typeof(scope, errors, allocator);
                if (try child_type.typesMatch(primitives.type_type, scope, errors, allocator)) {
                    retval = primitives.type_type;
                } else {
                    retval = try createAddrOf(self.getToken(), child_type, self.addrOf.mut, std.heap.page_allocator);
                }
            },
            .sliceOf => {
                var expr_type = try self.sliceOf.expr.typeof(scope, errors, allocator);
                if (expr_type.* != .product or !try expr_type.product.is_homotypical(scope, errors, allocator)) {
                    retval = poisoned;
                } else {
                    var child_type = expr_type.product.terms.items[0];
                    if (try child_type.typesMatch(primitives.type_type, scope, errors, allocator)) {
                        retval = primitives.type_type;
                    } else {
                        retval = try create_slice_type(expr_type.product.terms.items[0], self.sliceOf.kind == .MUT, allocator);
                    }
                }
            },
            .subSlice => retval = try self.subSlice.super.typeof(scope, errors, allocator),
            .inferredMember => retval = try self.inferredMember.base.?.expand_type(scope, errors, allocator),
            ._try => retval = (try self._try.expr.typeof(scope, errors, allocator)).get_ok_type(),
            ._comptime => retval = try self._comptime.expr.typeof(scope, errors, allocator),

            // Control-flow expressions
            ._if => {
                const body_type = try self._if.bodyBlock.typeof(self._if.scope.?, errors, allocator);
                if (self._if.elseBlock) |_| {
                    retval = body_type;
                } else {
                    retval = try create_optional_type(body_type, allocator);
                }
            },
            .match => retval = try self.match.mappings.items[0].typeof(self.match.scope.?, errors, allocator),
            .mapping => if (self.mapping.rhs) |rhs| {
                if (self.mapping.scope) |new_scope| {
                    retval = try rhs.typeof(new_scope, errors, allocator);
                } else {
                    retval = try rhs.typeof(scope, errors, allocator);
                }
            } else {
                retval = primitives.unit_type;
            },
            ._while => {
                const body_type = try self._while.bodyBlock.typeof(self._while.scope.?, errors, allocator);
                if (self._while.elseBlock) |_| {
                    retval = body_type;
                } else {
                    retval = try create_optional_type(body_type, allocator);
                }
            },
            .block => if (self.block.final) |_| {
                retval = primitives.void_type;
            } else if (self.block.statements.items.len == 0) {
                retval = primitives.unit_type;
            } else {
                retval = try self.block.statements.items[self.block.statements.items.len - 1].typeof(self.block.scope.?, errors, allocator);
            },
            .call => {
                const fn_type: *AST = try self.call.lhs.typeof(scope, errors, allocator);
                retval = fn_type.function.rhs;
            },
            .fnDecl => {
                retval = self.fnDecl.symbol.?._type.?;
            },

            else => {
                std.debug.print("Unimplemented typeof() for: AST.{s}\n", .{@tagName(self.*)});
                unreachable;
            },
        }
        self.getCommon()._type = retval;
        self.getCommon()._type.?.getCommon().validation_state = Validation_State{ .valid = .{ .valid_form = retval } };
        return retval;
    }

    /// For two types `A` and `B`, we say `A <: B` iff for every value `a` belonging to
    /// the type `A`, then `a` belongs to the type `B`.
    ///
    /// Another way to view this is if `(a: A) <: (b: B)`, then the assignment `b = a`
    /// is permissible, since `a: B`.
    ///
    /// Since the type `Void` has no values, it is vacuously true that `Void <: X` where
    /// `X` is any type.
    ///
    /// The unit type (`()`) acts like the top type. This means `X <: ()` where `X` is
    /// any type.
    ///
    /// Thus, we have the following type map:
    ///                        ( )
    ///       /     /     /     |    \      \     \
    ///     Bool  Byte  Char  Float  Int  String  ...
    ///       \     \     \     |    /      /     /
    ///                       Void
    ///
    /// Also, `&mut T <: &T`, because for every `t: &mut T`, `t: &T`.
    ///
    /// Also, (x: T,) == T == (x: T,)
    pub fn typesMatch(A: *AST, B: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !bool {
        if (A.* == .annotation) {
            return try typesMatch(A.annotation.type, B, scope, errors, allocator);
        } else if (B.* == .annotation) {
            return try typesMatch(A, B.annotation.type, scope, errors, allocator);
        }
        if (A.* == .identifier and B.* != .identifier and A != try A.expand_type(scope, errors, allocator)) {
            // If only A is an identifier, and A isn't an atom type, dive
            return try typesMatch(try A.expand_type(scope, errors, allocator), B, scope, errors, allocator);
        } else if (A.* != .identifier and B.* == .identifier and B != try B.expand_type(scope, errors, allocator)) {
            // If only B is an identifier, and B isn't an atom type, dive
            return try typesMatch(A, try B.expand_type(scope, errors, allocator), scope, errors, allocator);
        }
        // if (A.* == .product and B.* != .product and A.product.terms.items.len == 1) {
        //     return try typesMatch(A.product.terms.items[0], B, scope, errors, allocator);
        // } else if (B.* == .product and A.* != .product and B.product.terms.items.len == 1) {
        //     return try typesMatch(A, B.product.terms.items[0], scope, errors, allocator);
        // }
        if (A.* == .poison or B.* == .poison) {
            return true; // Whatever
        }
        if (B.* == .unit) {
            return true; // Top type - vacuously true
        }
        if (A.* == .identifier and std.mem.eql(u8, "Void", A.getToken().data)) {
            return true; // Bottom type - vacuously true
        }
        std.debug.assert(A.getCommon().validation_state == .valid);
        std.debug.assert(B.getCommon().validation_state == .valid);

        switch (A.*) {
            .identifier => {
                if (B.* != .identifier) {
                    return false;
                } else {
                    return std.mem.eql(u8, A.getToken().data, B.getToken().data);
                }
            },
            .addrOf => {
                if (B.* != .addrOf) {
                    return false;
                } else {
                    return (B.addrOf.mut == false or B.addrOf.mut == A.addrOf.mut) and try typesMatch(A.addrOf.expr, B.addrOf.expr, scope, errors, allocator);
                }
            },
            .sliceOf => {
                if (B.* != .sliceOf) {
                    return false;
                } else {
                    return (B.sliceOf.kind != .MUT or @intFromEnum(B.sliceOf.kind) == @intFromEnum(A.sliceOf.kind)) and try typesMatch(A.sliceOf.expr, B.sliceOf.expr, scope, errors, allocator);
                }
            },
            .annotation => unreachable,

            .unit => {
                return B.* == .unit;
            },
            .product => {
                if (B.* != .product) {
                    return false;
                } else {
                    if (B.product.terms.items.len != A.product.terms.items.len) {
                        return false;
                    }
                    var retval = true;
                    for (A.product.terms.items, B.product.terms.items) |term, B_term| {
                        retval = retval and try term.typesMatch(B_term, scope, errors, allocator);
                    }
                    return retval;
                }
            },
            .sum => {
                if (B.* != .sum) {
                    return false;
                } else {
                    if (B.sum.terms.items.len != A.sum.terms.items.len) {
                        return false;
                    }
                    var retval = true;
                    for (A.sum.terms.items, B.sum.terms.items) |term, B_term| {
                        const this_name = term.annotation.pattern.getToken().data;
                        const B_name = B_term.annotation.pattern.getToken().data;
                        retval = retval and std.mem.eql(u8, this_name, B_name) and try term.typesMatch(B_term, scope, errors, allocator);
                    }
                    return retval;
                }
            },
            .function => {
                if (B.* != .function) {
                    return false;
                } else {
                    return try A.function.lhs.typesMatch(B.function.lhs, scope, errors, allocator) and try A.function.rhs.typesMatch(B.function.rhs, scope, errors, allocator);
                }
            },
            .inferred_error => {
                return A == B;
            },
            else => {
                // TODO: May need to evaluate types, possibly done somewhere else though
                std.debug.print("typesMatch(): Unimplemented for {s}\n", .{@tagName(A.*)});
                unreachable;
            },
        }
    }

    /// Determines if a given integer type can represent a given integer value.
    pub fn can_represent_integer(self: *AST, value: i128, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !bool {
        const expanded = try self.expand_type(scope, errors, allocator);
        if (expanded.* == .unit) {
            // Top type
            return true;
        } else if (expanded.* != .identifier) {
            // Clearly not an integer type
            return false;
        }
        for (primitives.keys()) |key| {
            const info = primitives.get(key);
            if (std.mem.eql(u8, info.name, self.getToken().data) and
                info.bounds != null and
                value >= info.bounds.?.lower and
                value <= info.bounds.?.upper)
            {
                return true;
            }
        }
        return false;
    }

    const float_types = [_][]const u8{ "Float", "Float32", "Float64" };
    pub fn can_represent_float(self: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !bool {
        const expanded = try self.expand_type(scope, errors, allocator);
        if (expanded.* == .unit) {
            // Top type
            return true;
        } else if (expanded.* != .identifier) {
            // Clearly not a float type
            return false;
        }
        for (float_types) |name| {
            if (std.mem.eql(u8, name, self.getToken().data)) {
                return true;
            }
        }
        return false;
    }

    pub fn is_eq_type(self: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !bool {
        const expanded = try self.expand_type(scope, errors, allocator);
        if (expanded.* == .addrOf) {
            return true;
        } else if (expanded.* == .product) {
            for (expanded.product.terms.items) |term| {
                if (!try term.is_eq_type(scope, errors, allocator)) {
                    return false;
                }
            }
            return true;
        } else if (expanded.* == .sum) {
            return true;
        } else if (expanded.* != .identifier) {
            return false;
        }
        return primitives.from_ast(expanded).is_eq();
    }

    /// Ord <: Eq
    pub fn is_ord_type(self: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !bool {
        const expanded = try self.expand_type(scope, errors, allocator);
        if (expanded.* != .identifier) {
            return false;
        }
        return primitives.from_ast(expanded).is_ord();
    }

    /// Num <: Ord
    pub fn is_num_type(self: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !bool {
        const expanded = try self.expand_type(scope, errors, allocator);
        if (expanded.* != .identifier) {
            return false;
        }
        return primitives.from_ast(expanded).is_num();
    }

    // Used to poison an AST node. Marks as valid, so any attempt to validate is memoized to return poison.
    pub fn enpoison(self: *AST) *AST {
        self.getCommon().validation_state = .invalid;
        return poisoned;
    }

    pub fn c_typesMatch(self: *AST, other: *AST) bool {
        if (self.* == .annotation) {
            return c_typesMatch(self.annotation.type, other);
        } else if (other.* == .annotation) {
            return c_typesMatch(self, other.annotation.type);
        }
        std.debug.assert(self.getCommon().validation_state == .valid);
        std.debug.assert(other.getCommon().validation_state == .valid);

        switch (self.*) {
            .identifier => {
                if (other.* != .identifier) {
                    return false;
                } else {
                    return std.mem.eql(u8, self.getToken().data, other.getToken().data);
                }
            },
            .addrOf => {
                if (other.* != .addrOf) {
                    return false;
                } else {
                    return c_typesMatch(self.addrOf.expr, other.addrOf.expr);
                }
            },
            .sliceOf => {
                if (other.* != .sliceOf) {
                    return false;
                } else {
                    return c_typesMatch(self.sliceOf.expr, other.sliceOf.expr);
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
                    if (other.product.terms.items.len != self.product.terms.items.len) {
                        return false;
                    }
                    var retval = true;
                    for (self.product.terms.items, other.product.terms.items) |term, other_term| {
                        retval = retval and term.c_typesMatch(other_term);
                    }
                    return retval;
                }
            },
            .sum => {
                if (other.* != .sum) {
                    return false;
                } else {
                    if (other.sum.terms.items.len != self.sum.terms.items.len) {
                        return false;
                    }
                    var retval = true;
                    for (self.sum.terms.items, other.sum.terms.items) |term, other_term| {
                        retval = retval and term.c_typesMatch(other_term);
                    }
                    return retval;
                }
            },
            .function => {
                if (other.* != .function) {
                    return false;
                } else {
                    return self.function.lhs.c_typesMatch(other.function.lhs) and self.function.rhs.c_typesMatch(other.function.rhs);
                }
            },
            else => {
                std.debug.print("typesMatch(): Unimplemented for {s}\n", .{@tagName(self.*)});
                unreachable;
            },
        }
    }

    pub fn pprint(self: AST, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        switch (self) {
            .poison => try out.writer().print("poison", .{}),
            .unit => try out.writer().print("unit", .{}),
            .int => try out.writer().print("int()", .{}),
            .char => try out.writer().print("char()", .{}),
            .float => try out.writer().print("float()", .{}),
            .string => try out.writer().print("string()", .{}),
            .identifier => try out.writer().print("identifier(\"{s}\")", .{self.identifier.common.token.data}),
            ._unreachable => try out.writer().print("unreachable", .{}),
            ._true => try out.writer().print("true", .{}),
            ._false => try out.writer().print("false", .{}),

            .not => try out.writer().print("not()", .{}),
            .negate => try out.writer().print("negate()", .{}),
            .dereference => try out.writer().print("dereference()", .{}),
            ._try => try out.writer().print("try()", .{}),
            .discard => try out.writer().print("discard()", .{}),
            ._typeOf => try out.writer().print("typeof()", .{}),
            .domainOf => try out.writer().print("domainof()", .{}),
            ._comptime => try out.writer().print("comptime()", .{}),

            .assign => try out.writer().print("assign()", .{}),
            ._or => try out.writer().print("or()", .{}),
            ._and => try out.writer().print("and()", .{}),
            .add => try out.writer().print("add()", .{}),
            .sub => try out.writer().print("sub()", .{}),
            .mult => try out.writer().print("mult()", .{}),
            .div => try out.writer().print("div()", .{}),
            .mod => try out.writer().print("mod()", .{}),
            .equal => try out.writer().print("equal()", .{}),
            .not_equal => try out.writer().print("not_equal()", .{}),
            .greater => try out.writer().print("greater()", .{}),
            .lesser => try out.writer().print("lesser()", .{}),
            .greater_equal => try out.writer().print("greater_equal()", .{}),
            .lesser_equal => try out.writer().print("lesser_equal()", .{}),
            ._catch => try out.writer().print("catch()", .{}),
            ._orelse => try out.writer().print("orelse()", .{}),
            .call => try out.writer().print("call()", .{}),
            .index => try out.writer().print("index()", .{}),
            .select => try out.writer().print("select()", .{}),
            .function => try out.writer().print("function()", .{}),
            .invoke => try out.writer().print("invoke()", .{}),
            .sum => try out.writer().print("sum()", .{}),
            .inferred_error => try out.writer().print("inferred_error()", .{}),
            .inject => try out.writer().print("inject()", .{}),
            .product => {
                try out.writer().print("product(", .{});
                for (self.product.terms.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.product.terms.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },
            ._union => try out.writer().print("union()", .{}),

            .addrOf => try out.writer().print("addrOf({})", .{self.addrOf.expr}),
            .sliceOf => try out.writer().print("sliceOf()", .{}),
            .subSlice => try out.writer().print("subSlice()", .{}),
            .annotation => try out.writer().print("annotation()", .{}),
            .inferredMember => try out.writer().print("inferredMember()", .{}),

            ._if => try out.writer().print("if()", .{}),
            .match => try out.writer().print("match()", .{}),
            .mapping => try out.writer().print("mapping()", .{}),
            ._while => try out.writer().print("while()", .{}),
            ._for => try out.writer().print("for()", .{}),
            .block => try out.writer().print("block()", .{}),
            ._break => try out.writer().print("break", .{}),
            ._continue => try out.writer().print("continue", .{}),
            ._return => try out.writer().print("return()", .{}),
            .symbol => try out.writer().print("symbol()", .{}),
            .decl => try out.writer().print("decl()", .{}),
            .fnDecl => try out.writer().print("fnDecl()", .{}),
            ._defer => try out.writer().print("defer()", .{}),
            ._errdefer => try out.writer().print("errdefer()", .{}),
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: AST, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
        defer arena.deinit();

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }
};
