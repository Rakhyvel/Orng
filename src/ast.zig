const std = @import("std");
const offsets_ = @import("offsets.zig");
const primitives_ = @import("primitives.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const token_ = @import("token.zig");
const validation_state_ = @import("validation_state.zig");

pub const AST_Validation_State = validation_state_.Validation_State(*AST);

pub var poisoned: *AST = undefined;
var inited: bool = false;

/// Initializes internal structures if they are not already initialized.
pub fn init_structures() void {
    if (!inited) {
        poisoned = AST.createPoison(token_.Token.init_simple("LMAO GET POISONED!"), std.heap.page_allocator);
        _ = poisoned.enpoison();
        inited = true;
    }
}

/// Represents the kind of a slice.
pub const SliceKind = union(enum) {
    SLICE, // data ptr and len
    MUT, // mutable data ptr and len
    MULTIPTR, // c-style `*` pointer, no len
    ARRAY, // static homogenous tuple, compile-time len
};

pub const Sum_From = enum {
    optional,
    @"error",
    none,
};

/// Contains common properties of all AST nodes
const ASTCommon = struct {
    /// Token that defined the AST node in text.
    _token: token_.Token,

    /// The AST's type.
    /// Memoized, use `typeof()`.
    /// TODO: Postfix with _ to signify private
    _type: ?*AST = null,

    /// The result of expanding the `_type` field.
    /// Memoized, use `expanded_type()`.
    /// TODO: Postfix with _ to signify private
    expanded_type: ?*AST = null,

    /// The number of bytes a value in an AST type takes up.
    /// Memoized, use `sizeof()`.
    /// TODO: Postfix with _ to signify private
    size: ?i64 = null,

    /// The alignment for values of this type.
    /// In general it is *NOT* true that size == alignof, especially for products and sums.
    alignof: ?i64 = null,

    /// The AST's validation status.
    validation_state: AST_Validation_State = .unvalidated,
};

/// Represents an Abstract Syntax Tree.
pub const AST = union(enum) {
    /// Not generated for correct programs, used to represent incorrect ASTs
    poison: struct { common: ASTCommon },
    /// Unit type
    unit_type: struct { common: ASTCommon },
    /// Unit value
    unit_value: struct { common: ASTCommon },
    /// Integer constant
    int: struct {
        common: ASTCommon,
        data: i128,
        _represents: *AST, //< Type that this constant represents. Set on validation.
    },
    /// Floating-point constant
    float: struct {
        common: ASTCommon,
        data: f64,
        _represents: *AST, //< Type that this constant represents. Set on validation.
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
    /// Field
    /// This tag is used for the right-hand-side of selects. They do not refer to symbols.
    field: struct { common: ASTCommon },
    /// Identifier
    identifier: struct { common: ASTCommon, _symbol: ?*symbol_.Symbol = null },

    not: struct { common: ASTCommon, _expr: *AST },
    negate: struct { common: ASTCommon, _expr: *AST },
    dereference: struct { common: ASTCommon, _expr: *AST },
    _try: struct {
        common: ASTCommon,
        _expr: *AST,
        _symbol: ?*symbol_.Symbol, // `try`'s must be in functions. This is the function's symbol.
    },
    discard: struct { common: ASTCommon, _expr: *AST },
    _comptime: struct {
        common: ASTCommon,
        _expr: *AST,
        name: ?*AST = null,
        _symbol: ?*symbol_.Symbol = null,
    },

    // Binary operators
    assign: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    _or: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    _and: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    add: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    sub: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    mult: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    div: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    mod: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    equal: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    not_equal: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    greater: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    lesser: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    greater_equal: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    lesser_equal: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    @"catch": struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    @"orelse": struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    call: struct { common: ASTCommon, _lhs: *AST, _args: std.ArrayList(*AST) },
    index: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    select: struct {
        common: ASTCommon,
        _lhs: *AST,
        _rhs: *AST,
        _pos: ?usize,

        pub fn offsets_at(self: *@This(), allocator: std.mem.Allocator) i64 {
            var lhs_expanded_type = self.lhs.typeof(allocator).expand_type(allocator);
            if (lhs_expanded_type.* == .product) {
                return lhs_expanded_type.product.get_offset(self.pos.?, allocator);
            } else if (lhs_expanded_type.* == .sum) {
                return lhs_expanded_type.sum.get_offset(self.pos.?, allocator);
            } else {
                std.debug.print("{s}\n", .{@tagName(lhs_expanded_type.*)});
                unreachable;
            }
        }
    },
    function: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    invoke: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },
    sum: struct {
        common: ASTCommon,
        _terms: std.ArrayList(*AST),
        from: Sum_From = .none,
        all_unit: ?bool = null,
        pub fn is_all_unit(self: *@This()) bool {
            if (self.all_unit) |all_unit| {
                return all_unit;
            }
            var res = true;
            for (self._terms.items) |term| {
                res = res and term.c_typesMatch(primitives_.unit_type);
            }
            self.all_unit = res;
            return res;
        }
    },
    inferred_error: struct {
        common: ASTCommon,
        _terms: std.ArrayList(*AST),
    },
    inject: struct {
        common: ASTCommon,
        _lhs: *AST,
        _rhs: *AST,
        domain: ?*AST, // Filled by validate
    },
    product: struct {
        common: ASTCommon,
        _terms: std.ArrayList(*AST),
        homotypical: ?bool = null,
        was_slice: bool = false,

        pub fn is_homotypical(self: *@This()) bool {
            if (self.homotypical) |homotypical| {
                return homotypical;
            }
            var first_type = self._terms.items[0];
            for (self._terms.items, 0..) |term, i| {
                if (i == 0) {
                    continue;
                }
                if (!first_type.typesMatch(term)) {
                    self.homotypical = false;
                    return false;
                }
            }
            self.homotypical = true;
            return true;
        }

        pub fn get_offset(self: *@This(), field: usize, allocator: std.mem.Allocator) i64 {
            var offset: i64 = 0;
            for (0..field) |i| {
                var item = self._terms.items[i].expand_type(allocator);
                offset += item.sizeof();
                offset = offsets_.next_alignment(offset, self._terms.items[i + 1].alignof());
            }
            return offset;
        }
    },
    _union: struct { common: ASTCommon, _lhs: *AST, _rhs: *AST },

    // Fancy operators
    addrOf: struct { common: ASTCommon, _expr: *AST, mut: bool },
    sliceOf: struct { common: ASTCommon, _expr: *AST, kind: SliceKind },
    arrayOf: struct { common: ASTCommon, _expr: *AST, len: *AST },
    subSlice: struct { common: ASTCommon, super: *AST, lower: ?*AST, upper: ?*AST },
    annotation: struct { common: ASTCommon, pattern: *AST, type: *AST, predicate: ?*AST, init: ?*AST },
    inferredMember: struct {
        common: ASTCommon,
        ident: *AST,
        init: ?*AST = null,
        base: ?*AST = null, // This should ideally be kept in unexpanded form. use `typeof(inferredMember)` for expanded form
        _pos: ?usize = null,
    },
    _typeOf: struct {
        common: ASTCommon,
        _expr: *AST,
    },
    default: struct {
        common: ASTCommon,
        _expr: *AST,
    },
    sizeOf: struct {
        common: ASTCommon,
        _expr: *AST,
    },
    domainOf: struct {
        common: ASTCommon,
        sum_expr: *AST,
        _expr: *AST,
    },

    // Control-flow expressions
    _if: struct {
        common: ASTCommon,
        scope: ?*symbol_.Scope,
        let: ?*AST,
        condition: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    match: struct {
        common: ASTCommon,
        scope: ?*symbol_.Scope,
        let: ?*AST,
        _expr: *AST,
        _mappings: std.ArrayList(*AST),
        has_else: bool,
    },
    mapping: struct {
        common: ASTCommon,
        _mapping_lhs: ?*AST,
        _rhs: *AST,
        scope: ?*symbol_.Scope, // Scope used for `match` mappings, rooted in `match`'s scope. Captures, rhs live in this scope
    },
    _while: struct {
        common: ASTCommon,
        scope: ?*symbol_.Scope,
        let: ?*AST,
        condition: *AST,
        post: ?*AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    _for: struct {
        common: ASTCommon,
        scope: ?*symbol_.Scope,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
    },
    block: struct {
        common: ASTCommon,
        scope: ?*symbol_.Scope,
        _statements: std.ArrayList(*AST),
        final: ?*AST, // either `return`, `continue`, or `break`
    },

    // Control-flow statements
    _break: struct { common: ASTCommon },
    _continue: struct { common: ASTCommon },
    _unreachable: struct { common: ASTCommon },
    _return: struct {
        common: ASTCommon,
        _ret_expr: ?*AST,
        _symbol: ?*symbol_.Symbol, // `retrun`'s must be in functions. This is the function's symbol.
    },
    /// This type is a special version of an identifier. It is needed to encapsulate information about a
    /// symbol declaration that is needed before the symbol is even constructed. An identifier AST cannot be
    /// used for this purpose, because it refers to a symbol _after_ symbol decoration.
    pattern_symbol: struct {
        common: ASTCommon,
        name: []const u8,
        kind: symbol_.SymbolKind,
        _symbol: ?*symbol_.Symbol = undefined,
    },
    decl: struct {
        common: ASTCommon,
        symbols: std.ArrayList(*symbol_.Symbol), // List of symbols that are defined with this statement
        pattern: *AST, // Structure of ASTs. Has to be structured to allow tree patterns like `let ((a, b), (c, d)) = blah`
        type: *AST,
        init: *AST,
        top_level: bool,
    },
    fnDecl: struct {
        common: ASTCommon,
        name: ?*AST,
        _params: std.ArrayList(*AST), // Parameters' decl ASTs
        param_symbols: std.ArrayList(*symbol_.Symbol), // Parameters' symbols
        retType: *AST,
        refinement: ?*AST,
        init: *AST,
        _symbol: ?*symbol_.Symbol = null,
        infer_error: bool,
    },
    _defer: struct { common: ASTCommon, _statement: *AST },
    _errdefer: struct { common: ASTCommon, _statement: *AST },

    /// Boxes an AST value into an allocator.
    fn box(ast: AST, alloc: std.mem.Allocator) *AST {
        const retval = alloc.create(AST) catch unreachable;
        retval.* = ast;
        return retval;
    }

    /// Retrieves the size in bytes of an AST node.
    pub fn sizeof(self: *AST) i64 {
        if (self.common().size == null) {
            self.common().size = self.sizeof_internal(); // memoize call
        }

        return self.common().size.?;
    }

    fn sizeof_internal(self: *AST) i64 {
        switch (self.*) {
            .identifier => return primitives_.get(self.token().data).size,

            .product => {
                var total_size: i64 = 0;
                for (self.children().items) |child| {
                    total_size = offsets_.next_alignment(total_size, child.alignof());
                    total_size += child.sizeof();
                }
                return total_size;
            },

            .sum => {
                var max_size: i64 = 0;
                for (self.children().items) |child| {
                    max_size = @max(max_size, child.sizeof());
                }
                return offsets_.next_alignment(max_size, 8) + 8;
            },

            .function, .addrOf => return 8,

            .unit_type => return 0,

            .annotation => return self.annotation.type.sizeof(),

            else => {
                std.debug.print("Unimplemented sizeof for {}\n", .{self});
                unreachable;
            },
        }
    }

    pub fn alignof(self: *AST) i64 {
        if (self.common().alignof == null) {
            self.common().alignof = self.alignof_internal(); // memoize call
        }

        return self.common().alignof.?;
    }

    fn alignof_internal(self: *AST) i64 {
        switch (self.*) {
            .identifier => return primitives_.get(self.token().data).size,

            .product => {
                var max_align: i64 = 0;
                for (self.children().items) |child| {
                    max_align = @max(max_align, child.alignof());
                }
                return max_align;
            },

            .sum, // this pains me :-( but has to be this way for the tag
            .function,
            .addrOf,
            => return 8,

            .unit_type => return 1, // fogedda bout it

            .annotation => return self.annotation.type.alignof(),

            else => {
                std.debug.print("Unimplemented alignof for {}\n", .{self});
                unreachable;
            },
        }
    }

    pub fn createPoison(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .poison = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createUnitType(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .unit_type = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createUnitValue(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .unit_value = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createInt(_token: token_.Token, data: i128, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .int = .{ .common = _common, .data = data, ._represents = primitives_.int_type } }, allocator);
    }

    pub fn createChar(
        _token: token_.Token, // `token.data` should of course encompass the `'` used for character delimination. This is unlike strings. TODO: Maybe make it like strings?
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .char = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createFloat(_token: token_.Token, data: f64, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .float = .{ .common = _common, .data = data, ._represents = primitives_.float_type } }, allocator);
    }

    pub fn createString(
        _token: token_.Token,
        data: []const u8, // The string's raw utf8 bytes, not containing `"`'s, with escapes escaped
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .string = .{ .common = ASTCommon{ ._token = _token, ._type = null }, .data = data } }, allocator);
    }

    pub fn createField(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .field = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createIdentifier(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .identifier = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createUnreachable(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._unreachable = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createTrue(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._true = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createFalse(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._false = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createNot(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .not = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn createNegate(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .negate = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn createDereference(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .dereference = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn createTry(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ ._try = .{ .common = _common, ._expr = _expr, ._symbol = null } }, allocator);
    }

    pub fn createDiscard(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .discard = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn createComptime(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ ._comptime = .{ .common = _common, ._expr = _expr, .name = null, ._symbol = null } }, allocator);
    }

    pub fn createTypeOf(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._typeOf = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn createDefault(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .default = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn createSizeOf(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .sizeOf = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn createDomainOf(_token: token_.Token, sum_expr: *AST, _expr: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .domainOf = .{ .common = _common, .sum_expr = sum_expr, ._expr = _expr } }, allocator);
    }

    pub fn createAssign(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .assign = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createOr(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._or = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createAnd(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._and = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createEqual(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .equal = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createNotEqual(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .not_equal = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createGreater(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .greater = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createLesser(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .lesser = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createGreaterEqual(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .greater_equal = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createLesserEqual(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .lesser_equal = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createAdd(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .add = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createSub(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .sub = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createMult(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .mult = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createDiv(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .div = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createMod(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .mod = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createCatch(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .@"catch" = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createOrelse(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .@"orelse" = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createCall(_token: token_.Token, _lhs: *AST, args: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .call = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._args = args } }, allocator);
    }

    pub fn createIndex(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .index = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createSelect(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .select = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs, ._pos = null } }, allocator);
    }

    pub fn createSum(_token: token_.Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .sum = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._terms = terms } }, allocator);
    }

    pub fn createInferredError(_token: token_.Token, ok: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        var retval: AST = AST{ .inferred_error = .{ .common = _common, ._terms = std.ArrayList(*AST).init(allocator) } };
        const ok_ident = AST.createIdentifier(token_.Token.init_simple("ok"), allocator);
        const ok_annot = createAnnotation(_token, ok_ident, ok, null, null, allocator);
        retval.children().append(ok_annot) catch unreachable;

        return AST.box(retval, allocator);
    }

    pub fn createInject(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .inject = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs, .domain = null } }, allocator);
    }

    pub fn createFunction(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .function = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createInvoke(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .invoke = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createProduct(_token: token_.Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .product = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._terms = terms } }, allocator);
    }

    pub fn createUnion(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ ._union = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn createAddrOf(_token: token_.Token, _expr: *AST, mut: bool, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .addrOf = .{ .common = _common, ._expr = _expr, .mut = mut } }, allocator);
    }

    pub fn createSliceOf(_token: token_.Token, _expr: *AST, kind: SliceKind, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .sliceOf = .{ .common = _common, ._expr = _expr, .kind = kind } }, allocator);
    }

    pub fn createArrayOf(_token: token_.Token, _expr: *AST, len: *AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .arrayOf = .{ .common = _common, ._expr = _expr, .len = len } }, allocator);
    }

    pub fn createSubSlice(_token: token_.Token, super: *AST, lower: ?*AST, upper: ?*AST, allocator: std.mem.Allocator) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(AST{ .subSlice = .{ .common = _common, .super = super, .lower = lower, .upper = upper } }, allocator);
    }

    pub fn createAnnotation(
        _token: token_.Token,
        pattern: *AST,
        _type: *AST,
        predicate: ?*AST,
        init: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(
            AST{ .annotation = .{ .common = _common, .pattern = pattern, .type = _type, .predicate = predicate, .init = init } },
            allocator,
        );
    }

    pub fn createInferredMember(_token: token_.Token, ident: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .inferredMember = .{ .common = ASTCommon{ ._token = _token, ._type = null }, .ident = ident } }, allocator);
    }

    pub fn createIf(
        _token: token_.Token,
        let: ?*AST,
        condition: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        const _common: ASTCommon = .{ ._token = _token };
        return AST.box(
            AST{ ._if = .{
                .common = _common,
                .scope = null,
                .let = let,
                .condition = condition,
                .bodyBlock = bodyBlock,
                .elseBlock = elseBlock,
            } },
            allocator,
        );
    }

    pub fn createMatch(
        _token: token_.Token,
        let: ?*AST,
        _expr: *AST,
        mappings: std.ArrayList(*AST),
        has_else: bool,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .match = .{
                .common = ASTCommon{ ._token = _token, ._type = null },
                .scope = null,
                .let = let,
                ._expr = _expr,
                ._mappings = mappings,
                .has_else = has_else,
            } },
            allocator,
        );
    }

    pub fn createMapping(_token: token_.Token, _lhs: ?*AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .mapping = .{
                .common = ASTCommon{ ._token = _token, ._type = null },
                ._mapping_lhs = _lhs,
                ._rhs = _rhs,
                .scope = null,
            } },
            allocator,
        );
    }

    pub fn createWhile(
        _token: token_.Token,
        let: ?*AST,
        condition: *AST,
        post: ?*AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ ._while = .{
                .common = ASTCommon{ ._token = _token, ._type = null },
                .scope = null,
                .let = let,
                .condition = condition,
                .post = post,
                .bodyBlock = bodyBlock,
                .elseBlock = elseBlock,
            } },
            allocator,
        );
    }

    pub fn createFor(
        _token: token_.Token,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        bodyBlock: *AST,
        elseBlock: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ ._for = .{
                .common = ASTCommon{ ._token = _token, ._type = null },
                .scope = null,
                .let = let,
                .elem = elem,
                .iterable = iterable,
                .bodyBlock = bodyBlock,
                .elseBlock = elseBlock,
            } },
            allocator,
        );
    }

    pub fn createBlock(_token: token_.Token, statements: std.ArrayList(*AST), final: ?*AST, allocator: std.mem.Allocator) *AST {
        if (final) |_final| {
            std.debug.assert(_final.* == ._return or _final.* == ._continue or _final.* == ._break);
        }
        return AST.box(
            AST{ .block = .{
                .common = ASTCommon{ ._token = _token, ._type = null },
                .scope = null,
                ._statements = statements,
                .final = final,
            } },
            allocator,
        );
    }

    pub fn createBreak(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._break = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createContinue(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._continue = .{ .common = ASTCommon{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn createReturn(_token: token_.Token, _ret_expr: ?*AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ ._return = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._ret_expr = _ret_expr, ._symbol = null } },
            allocator,
        );
    }

    pub fn createSymbol(_token: token_.Token, kind: symbol_.SymbolKind, name: []const u8, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .pattern_symbol = .{ .common = ASTCommon{ ._token = _token, ._type = null }, .kind = kind, .name = name } },
            allocator,
        );
    }

    pub fn createDecl(_token: token_.Token, pattern: *AST, _type: *AST, init: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .decl = .{
                .common = ASTCommon{ ._token = _token, ._type = null },
                .symbols = std.ArrayList(*symbol_.Symbol).init(allocator),
                .pattern = pattern,
                .type = _type,
                .init = init,
                .top_level = false,
            } },
            allocator,
        );
    }

    pub fn createFnDecl(
        _token: token_.Token,
        name: ?*AST,
        params: std.ArrayList(*AST),
        retType: *AST,
        refinement: ?*AST,
        init: *AST,
        infer_error: bool,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .fnDecl = .{
            .common = ASTCommon{ ._token = _token, ._type = null },
            .name = name,
            ._params = params,
            .param_symbols = std.ArrayList(*symbol_.Symbol).init(allocator),
            .retType = retType,
            .refinement = refinement,
            .init = init,
            .infer_error = infer_error,
        } }, allocator);
    }

    pub fn createDefer(_token: token_.Token, _statement: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ ._defer = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._statement = _statement } }, allocator);
    }

    pub fn createErrDefer(_token: token_.Token, _statement: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ ._errdefer = .{ .common = ASTCommon{ ._token = _token, ._type = null }, ._statement = _statement } },
            allocator,
        );
    }

    fn Unwrapped(comptime Union: type, comptime field: []const u8) type {
        return inline for (std.meta.fields(Union)) |variant| {
            const Struct = variant.type;
            const s: Struct = undefined;
            if (@hasField(Struct, field)) break @TypeOf(@field(s, field));
        } else @compileError("No such field in any of the variants!");
    }

    fn get_field(u: anytype, comptime field: []const u8) Unwrapped(@TypeOf(u), field) {
        return switch (u) {
            inline else => |v| if (@hasField(@TypeOf(v), field)) @field(v, field) else error.NoField,
        } catch {
            std.debug.print("`{s}` does not have field `{s}` {}\n", .{ @tagName(u), field, Unwrapped(@TypeOf(u), field) });
            unreachable;
        };
    }

    fn get_field_ref(u: anytype, comptime field: []const u8) *Unwrapped(@TypeOf(u.*), field) {
        return switch (u.*) {
            inline else => |*v| &@field(v, field),
        };
    }

    fn set_field(u: anytype, comptime field: []const u8, val: Unwrapped(@TypeOf(u.*), field)) void {
        switch (u.*) {
            inline else => |*v| if (@hasField(@TypeOf(v.*), field)) {
                @field(v, field) = val;
            } else {
                std.debug.print("`{s}` does not have field `{s}`\n", .{ @tagName(u.*), field });
                unreachable;
            },
        }
    }

    pub fn common(self: *AST) *ASTCommon {
        return get_field_ref(self, "common");
    }

    pub fn token(self: *AST) token_.Token {
        return self.common()._token;
    }

    pub fn represents(self: AST) *AST {
        return get_field(self, "_represents");
    }

    pub fn set_represents(self: *AST, val: *AST) void {
        set_field(self, "_represents", val);
    }

    pub fn expr(self: AST) *AST {
        return get_field(self, "_expr");
    }

    pub fn set_expr(self: *AST, val: *AST) void {
        set_field(self, "_expr", val);
    }

    pub fn symbol(self: AST) ?*symbol_.Symbol {
        return get_field(self, "_symbol");
    }

    pub fn set_symbol(self: *AST, val: ?*symbol_.Symbol) void {
        set_field(self, "_symbol", val);
    }

    pub fn lhs(self: AST) *AST {
        return get_field(self, "_lhs");
    }

    pub fn set_lhs(self: *AST, val: *AST) void {
        set_field(self, "_lhs", val);
    }

    pub fn mapping_lhs(self: AST) ?*AST { // TODO: Don't allow `else` in `match`
        return get_field(self, "_mapping_lhs");
    }

    pub fn set_mapping_lhs(self: *AST, val: ?*AST) void {
        set_field(self, "_mapping_lhs", val);
    }

    pub fn rhs(self: AST) *AST {
        return get_field(self, "_rhs");
    }

    pub fn set_rhs(self: *AST, val: *AST) void {
        set_field(self, "_rhs", val);
    }

    pub fn children(self: *AST) *std.ArrayList(*AST) {
        return switch (self.*) {
            .call => &self.call._args,
            .sum => &self.sum._terms,
            .inferred_error => &self.inferred_error._terms,
            .product => &self.product._terms,
            .match => &self.match._mappings,
            .block => &self.block._statements,
            .fnDecl => &self.fnDecl._params,
            else => unreachable,
        };
    }

    pub fn set_children(self: *AST, val: std.ArrayList(*AST)) void {
        switch (self.*) {
            .call => self.call._args = val,
            .sum => self.sum._terms = val,
            .inferred_error => self.inferred_error._terms = val,
            .product => self.product._terms = val,
            .match => self.match._mappings = val,
            .block => self.block._statements = val,
            .fnDecl => self.fnDecl._params = val,
            else => unreachable,
        }
    }

    pub fn pos(self: AST) ?usize {
        return get_field(self, "_pos");
    }

    pub fn get_pos(self: *AST, field_name: []const u8) ?usize {
        for (self.children().items, 0..) |term, i| {
            if (std.mem.eql(u8, term.annotation.pattern.token().data, field_name)) {
                return i;
            }
        }
        return null;
    }

    pub fn set_pos(self: *AST, val: ?usize) void {
        set_field(self, "_pos", val);
    }

    pub fn statement(self: AST) *AST {
        return get_field(self, "_statement");
    }

    pub fn set_statement(self: *AST, val: *AST) void {
        set_field(self, "_statement", val);
    }

    pub fn create_array_type(len: *AST, of: *AST, allocator: std.mem.Allocator) *AST {
        // Inflate an array-of to a product with `len` `of`'s
        var new_terms = std.ArrayList(*AST).init(allocator);
        std.debug.assert(len.int.data >= 0);
        for (0..@as(usize, @intCast(len.int.data))) |_| {
            new_terms.append(of) catch unreachable;
        }
        return AST.createProduct(of.token(), new_terms, allocator);
    }

    pub fn create_slice_type(of: *AST, mut: bool, allocator: std.mem.Allocator) *AST {
        var term_types = std.ArrayList(*AST).init(allocator);
        const data_type = AST.createAddrOf(
            of.token(),
            of,
            mut,
            allocator,
        ).assert_valid();
        const annot_type = AST.createAnnotation(
            of.token(),
            AST.createIdentifier(token_.Token.init("data", null, "", "", 0, 0), allocator),
            data_type,
            null,
            null,
            allocator,
        ).assert_valid();
        term_types.append(annot_type) catch unreachable;
        term_types.append(AST.createAnnotation(
            of.token(),
            AST.createIdentifier(token_.Token.init("length", null, "", "", 0, 0), allocator),
            primitives_.int_type,
            null,
            null,
            allocator,
        )) catch unreachable;
        var retval = AST.createProduct(of.token(), term_types, allocator).assert_valid();
        retval.product.was_slice = true;
        return retval;
    }

    // Expr must be a product value of length `l`. Slice value is `(&expr[0], l)`.
    pub fn create_slice_value(_expr: *AST, mut: bool, expr_type: *AST, allocator: std.mem.Allocator) *AST {
        var new_terms = std.ArrayList(*AST).init(allocator);
        const zero = (AST.createInt(_expr.token(), 0, allocator)).assert_valid();
        const index = (AST.createIndex(
            _expr.token(),
            _expr,
            zero,
            allocator,
        )).assert_valid();
        const addr = (AST.createAddrOf(
            _expr.token(),
            index,
            mut,
            allocator,
        )).assert_valid();
        new_terms.append(addr) catch unreachable;

        const length = (AST.createInt(_expr.token(), expr_type.children().items.len, allocator)).assert_valid();
        new_terms.append(length) catch unreachable;

        var retval = AST.createProduct(_expr.token(), new_terms, allocator);
        retval.product.was_slice = true;
        return retval;
    }

    pub fn create_optional_type(of_type: *AST, allocator: std.mem.Allocator) *AST {
        var term_types = std.ArrayList(*AST).init(allocator);

        const some_type = AST.createAnnotation(
            of_type.token(),
            AST.createIdentifier(token_.Token.init("some", null, "", "", 0, 0), allocator),
            of_type,
            null,
            null,
            allocator,
        );
        term_types.append(some_type) catch unreachable;

        const none_type = AST.createAnnotation(
            of_type.token(),
            AST.createIdentifier(token_.Token.init_simple("none"), allocator),
            primitives_.unit_type,
            null,
            AST.createUnitValue(token_.Token.init_simple("none init"), allocator),
            allocator,
        );
        term_types.append(none_type) catch unreachable;

        var retval = AST.createSum(of_type.token(), term_types, allocator);
        retval.sum.from = .optional;
        return retval;
    }

    pub fn create_some_value(opt_type: *AST, value: *AST, allocator: std.mem.Allocator) *AST {
        const member = createInferredMember(value.token(), AST.createIdentifier(token_.Token.init_simple("some"), allocator), allocator);
        member.inferredMember.base = opt_type;
        member.inferredMember.init = value;
        member.set_pos(opt_type.get_pos("some"));
        return member.assert_valid();
    }

    pub fn create_none_value(opt_type: *AST, allocator: std.mem.Allocator) *AST {
        const member = createInferredMember(
            token_.Token.init_simple("none"),
            AST.createIdentifier(token_.Token.init_simple("none"), allocator),
            allocator,
        );
        member.inferredMember.base = opt_type;
        member.set_pos(opt_type.get_pos("none"));
        return member.assert_valid();
    }

    pub fn create_error_type(err_type: *AST, ok_type: *AST, allocator: std.mem.Allocator) *AST {
        const ok_annot = AST.createAnnotation(
            ok_type.token(),
            AST.createIdentifier(token_.Token.init("ok", null, "", "", 0, 0), allocator),
            ok_type,
            null,
            null,
            allocator,
        );
        var ok_sum_terms = std.ArrayList(*AST).init(allocator);
        ok_sum_terms.append(ok_annot) catch unreachable;
        var ok_sum = AST.createSum(ok_type.token(), ok_sum_terms, allocator);
        ok_sum.sum.from = .@"error";

        // Err!Ok => (ok:Ok|) || Err
        // This is done so that `ok` has an invariant tag of `0`, and errors have a non-zero tag.
        const retval = AST.createUnion(err_type.token(), ok_sum, err_type, allocator);
        return retval;
    }

    /// Retrieves either the `ok` or `some` type from either an optional type or an error type
    pub fn get_nominal_type(opt_or_error_sum: *AST) *AST {
        std.debug.assert(opt_or_error_sum.sum.from == .optional or opt_or_error_sum.sum.from == .@"error");
        return opt_or_error_sum.children().items[0];
    }

    pub fn get_some_type(opt_sum: *AST) *AST {
        std.debug.assert(opt_sum.sum.from == .optional);
        return opt_sum.children().items[0];
    }

    pub fn get_none_type(opt_sum: *AST) *AST {
        std.debug.assert(opt_sum.sum.from == .optional);
        return opt_sum.children().items[1];
    }

    pub fn get_ok_type(err_union: *AST) *AST {
        std.debug.assert(err_union.sum.from == .@"error");
        return err_union.children().items[0];
    }

    pub fn expand_type(self: *AST, allocator: std.mem.Allocator) *AST {
        if (self.common().expanded_type) |expaned_type| {
            return expaned_type;
        }
        const retval = expand_type_internal(self, allocator).assert_valid();
        self.common().expanded_type = retval;
        return retval;
    }

    fn expand_type_internal(self: *AST, allocator: std.mem.Allocator) *AST {
        switch (self.*) {
            .identifier => {
                const _symbol = self.symbol().?;
                if (_symbol.init == self) {
                    return self;
                } else {
                    return _symbol.init.expand_type(allocator);
                }
            },
            .product => {
                if (expand_type_list(self.children())) |new_terms| {
                    var retval = AST.createProduct(self.token(), new_terms, allocator);
                    retval.product.was_slice = self.product.was_slice;
                    return retval;
                } else {
                    return self;
                }
            },
            .sum => {
                if (expand_type_list(self.children())) |new_terms| {
                    var retval = AST.createSum(self.token(), new_terms, allocator);
                    retval.sum.from = self.sum.from;
                    return retval;
                } else {
                    return self;
                }
            },
            .addrOf => {
                const _expr = self.expr().expand_type(allocator);
                return AST.createAddrOf(self.token(), _expr, self.addrOf.mut, allocator);
            },
            .function => {
                const _lhs = self.lhs().expand_type(allocator);
                const _rhs = self.rhs().expand_type(allocator);
                return AST.createFunction(self.token(), _lhs, _rhs, allocator);
            },
            .annotation => {
                const _expr = self.annotation.type.expand_type(allocator);
                return AST.createAnnotation(
                    self.token(),
                    self.annotation.pattern,
                    _expr,
                    self.annotation.predicate,
                    self.annotation.init,
                    allocator,
                );
            },
            .index => {
                const _expr = self.lhs().expand_type(allocator);
                return _expr.children().items[@as(usize, @intCast(self.rhs().int.data))];
            },
            .poison, .unit_type => return self,

            else => return self,
        }
    }

    fn expand_type_list(asts: *std.ArrayList(*AST), allocator: std.mem.Allocator) ?std.ArrayList(*AST) {
        var terms = std.ArrayList(*AST).init(allocator);
        var change = false;
        for (asts.items) |term| {
            const new_term = term.expand_type(allocator);
            terms.append(new_term) catch unreachable;
            change = new_term != term or change;
        }
        if (change) {
            return terms;
        } else {
            terms.deinit();
            return null;
        }
    }

    pub fn createBinop(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        switch (_token.kind) {
            .PLUS_EQUALS => return createAdd(_token, _lhs, _rhs, allocator),
            .MINUS_EQUALS => return createSub(_token, _lhs, _rhs, allocator),
            .STAR_EQUALS => return createMult(_token, _lhs, _rhs, allocator),
            .SLASH_EQUALS => return createDiv(_token, _lhs, _rhs, allocator),
            .PERCENT_EQUALS => return createMod(_token, _lhs, _rhs, allocator),
            else => {
                std.debug.print("not a operator-assign token\n", .{});
                unreachable;
            },
        }
    }

    pub fn printType(self: *AST, out: anytype) !void {
        switch (self.*) {
            .unit_type => try out.print("()", .{}),
            .identifier => try out.print("{s}", .{self.token().data}),
            .addrOf => {
                try out.print("&", .{});
                if (self.addrOf.mut) {
                    try out.print("mut ", .{});
                }
                try self.expr().printType(out);
            },
            .sliceOf => {
                try out.print("[", .{});
                switch (self.sliceOf.kind) {
                    .MUT => try out.print("mut", .{}),
                    .MULTIPTR => try out.print("*", .{}),
                    .SLICE => {},
                    .ARRAY => unreachable,
                }
                try out.print("]", .{});
                try self.expr().printType(out);
            },
            .arrayOf => {
                try out.print("[", .{});
                try self.arrayOf.len.printType(out);
                try out.print("]", .{});
                try self.expr().printType(out);
            },
            .function => {
                try out.print("(", .{});
                try self.lhs().printType(out);
                try out.print(")->", .{});
                try self.rhs().printType(out);
            },
            .product => if (self.product.homotypical != null and self.product.homotypical.?) {
                try out.print("[{}]", .{self.children().items.len});
                try self.children().items[0].printType(out);
            } else if (self.product.was_slice) {
                try out.print("[]", .{});
                try self.children().items[0].printType(out);
            } else if (self.children().items.len == 0) {
                try out.print("()", .{});
            } else {
                try out.print("(", .{});
                for (self.children().items, 0..self.children().items.len) |term, _| {
                    try term.printType(out);
                    try out.print(", ", .{});
                }
                try self.children().items[self.children().items.len - 1].printType(out);
                try out.print(")", .{});
            },
            .sum => if (self.sum.from == .optional) {
                try out.print("?", .{});
                try self.get_some_type().annotation.type.printType(out);
            } else {
                try out.print("(", .{});
                for (self.sum._terms.items, 0..) |term, i| {
                    try term.printType(out);
                    if (self.sum._terms.items.len == 1 or i + 1 != self.sum._terms.items.len) {
                        try out.print(" | ", .{});
                    }
                }
                try out.print(")", .{});
            },
            .inferred_error => {
                try out.print("!", .{});
                try self.inferred_error._terms.items[0].annotation.type.printType(out);
            },
            ._union => {
                try self.lhs().printType(out);
                try out.print("||", .{});
                try self.rhs().printType(out);
            },
            .annotation => {
                try out.print("{s}: ", .{self.annotation.pattern.token().data});
                try self.annotation.type.printType(out);
            },

            // Not necessarily types, but may appear in a type definition
            .int => try out.print("{}", .{self.int.data}),
            .block => {
                try out.print("{{", .{});
                for (self.block._statements.items, 0..) |_statement, i| {
                    try _statement.printType(out);
                    if (self.block.final != null or i > self.block._statements.items.len - 1) {
                        try out.print("; ", .{});
                    }
                }
                if (self.block.final) |final| {
                    try final.printType(out);
                }
                try out.print("}}", .{});
            },
            .index => {
                try self.lhs().printType(out);
                try out.print("[", .{});
                try self.rhs().printType(out);
                try out.print("]", .{});
            },
            ._unreachable => try out.print("unreachable", .{}),
            .poison => try out.print("<error>", .{}),
            else => {
                try out.print("\nprintTypes(): Unimplemented or not a type: {s}\n", .{@tagName(self.*)});
                unreachable;
            },
        }
    }

    // Must always return a valid type!
    pub fn typeof(self: *AST, allocator: std.mem.Allocator) *AST {
        // std.debug.assert(self.common().validation_state != .unvalidated);
        if (self.common()._type) |_type| {
            return _type;
        }
        const retval: *AST = self.typeof_internal(allocator).assert_valid();
        self.common()._type = retval;
        return retval;
    }

    fn typeof_internal(self: *AST, allocator: std.mem.Allocator) *AST {
        switch (self.*) {
            // Poisoned type
            .poison => return poisoned,

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
            => return primitives_.bool_type,

            // Char type
            .char => return primitives_.char_type,

            // Int/Float constant type
            .int, .float => return self.represents(),

            // String type
            .string => return primitives_.string_type,

            // Type type
            .unit_type,
            .annotation,
            .sum,
            .inferred_error,
            ._union,
            .function,
            ._typeOf,
            => return primitives_.type_type,

            // Unit type
            .unit_value,
            .decl,
            .assign,
            ._defer,
            ._errdefer,
            .discard,
            => return primitives_.unit_type,

            // Void type
            ._continue,
            ._break,
            ._return,
            ._unreachable,
            => return primitives_.void_type,

            // Binary operators
            .add,
            .sub,
            .mult,
            .div,
            .mod,
            => return self.lhs().typeof(allocator),
            .@"catch",
            .@"orelse",
            .mapping,
            => return self.rhs().typeof(allocator),

            .product => {
                var first_type = self.children().items[0].typeof(allocator);
                if (first_type.typesMatch(primitives_.type_type)) {
                    // typeof product type is Type
                    return primitives_.type_type;
                } else if (self.product.was_slice) {
                    var addr: *AST = self.children().items[0];
                    var retval = create_slice_type(addr.expr().typeof(allocator), addr.addrOf.mut, allocator);
                    retval.product.was_slice = true;
                    return retval;
                } else {
                    var terms = std.ArrayList(*AST).init(allocator);
                    for (self.children().items) |term| {
                        const term_type = term.typeof(allocator);
                        terms.append(term_type) catch unreachable;
                    }
                    var retval = AST.createProduct(self.token(), terms, allocator);
                    retval.product.was_slice = self.product.was_slice;
                    return retval;
                }
            },

            .index => {
                var lhs_type = self.lhs().typeof(allocator).expand_type(allocator);
                if (lhs_type.typesMatch(primitives_.type_type) and self.lhs().* == .product) {
                    return self.lhs().children().items[0];
                } else if (lhs_type.* == .product) { // TODO: Replace with if the type implements Indexable or something
                    if (lhs_type.product.was_slice) {
                        return lhs_type.children().items[0].annotation.type.expr();
                    } else {
                        return lhs_type.children().items[0];
                    }
                } else if (lhs_type.* == .identifier and std.mem.eql(u8, lhs_type.token().data, "String")) {
                    return primitives_.byte_type;
                } else if (lhs_type.* == .poison) {
                    return poisoned;
                } else {
                    std.debug.print("{s} is not indexable\n", .{@tagName(lhs_type.*)});
                    unreachable;
                }
            },

            .select => {
                var select_lhs_type = self.lhs().typeof(allocator).expand_identifier();
                var retval = select_lhs_type.children().items[self.pos().?];
                while (retval.* == .annotation) {
                    retval = retval.annotation.type;
                }
                return retval;
            },

            // Identifier
            .identifier => if (std.mem.eql(u8, self.token().data, "_")) {
                return primitives_.unit_type;
            } else {
                return self.symbol().?._type;
            },

            // Unary Operators
            ._comptime, .negate => return self.expr().typeof(allocator),
            .dereference => {
                const _type = self.expr().typeof(allocator).expand_type(allocator);
                return _type.expr();
            },
            .addrOf => {
                var child_type = self.expr().typeof(allocator);
                if (child_type.typesMatch(primitives_.type_type)) {
                    return primitives_.type_type;
                } else {
                    return createAddrOf(self.token(), child_type, self.addrOf.mut, std.heap.page_allocator);
                }
            },
            .sliceOf => {
                var expr_type = self.expr().typeof(allocator);
                if (expr_type.* != .product or !expr_type.product.is_homotypical()) {
                    return poisoned;
                } else {
                    var child_type = expr_type.children().items[0];
                    if (child_type.typesMatch(primitives_.type_type)) {
                        return primitives_.type_type;
                    } else {
                        return create_slice_type(expr_type.children().items[0], self.sliceOf.kind == .MUT, allocator);
                    }
                }
            },
            .subSlice => return self.subSlice.super.typeof(allocator),
            .inferredMember => return self.inferredMember.base.?.expand_type(allocator),
            ._try => return self.expr().typeof(allocator).get_ok_type(),
            .default => return self.expr(),

            // Control-flow expressions
            ._if => {
                const body_type = self._if.bodyBlock.typeof(allocator);
                if (self._if.elseBlock) |_| {
                    return body_type;
                } else {
                    return create_optional_type(body_type, allocator);
                }
            },
            .match => return self.children().items[0].typeof(allocator),
            ._while => {
                const body_type = self._while.bodyBlock.typeof(allocator);
                if (self._while.elseBlock) |_| {
                    return body_type;
                } else {
                    return create_optional_type(body_type, allocator);
                }
            },
            .block => if (self.block.final) |_| {
                return primitives_.void_type;
            } else if (self.children().items.len == 0) {
                return primitives_.unit_type;
            } else {
                return self.children().items[self.children().items.len - 1].typeof(allocator);
            },
            .call => {
                const fn_type: *AST = self.lhs().typeof(allocator).expand_identifier();
                return fn_type.rhs();
            },
            .fnDecl => return self.symbol().?._type,
            .pattern_symbol => return self.symbol().?._type,
            .inject => return self.lhs().typeof(allocator),

            else => {
                std.debug.print("Unimplemented typeof() for: AST.{s}\n", .{@tagName(self.*)});
                unreachable;
            },
        }
    }

    // Expands an ast one level if it is an identifier
    pub fn expand_identifier(self: *AST) *AST {
        if (self.* == .identifier) {
            return self.symbol().?.init;
        } else {
            return self;
        }
    }

    /// For two types `A` and `B`, we say `A <: B` iff for every value `a` belonging to the type `A`, then
    /// `a` belongs to the type `B`.
    ///
    /// Another way to view this is if `(a: A) <: (b: B)`, then the assignment `b = a` is permissible, since
    /// `a: B`.
    ///
    /// Since the type `Void` has no values, it is vacuously true that `Void <: X` where `X` is any type.
    /// Thus, `let x: Void = y` is never type-sound, since there is no value `y` can be, and
    /// `let x: T = void_typed_expression` is always type-sound.
    ///
    /// The unit type (`()`) acts like the top type. This means `X <: ()` where `X` is any type. Thus,
    /// `let x: T = unit_typed_expression` is type-sound only if `T == ()`, and `let x: () = y` is always
    /// type-sound.
    ///
    /// Thus, we have the following type map:
    ///                        ( )
    ///       /     /     /     |    \      \     \
    ///     Bool  Byte  Char  Float  Int  String  ...
    ///       \     \     \     |    /      /     /
    ///                       Void
    ///
    /// Also, `&mut T <: &T`, because for every `t: &mut T`, `t: &T`. Thus, `let x: &T = mut_expression` is
    /// always type-sound.
    ///
    /// Also, (x: T,) == T == (x: T,)
    pub fn typesMatch(A: *AST, B: *AST) bool {
        // std.debug.print("{} == {}\n", .{ A, B });
        if (A.* == .annotation) {
            return typesMatch(A.annotation.type, B);
        } else if (B.* == .annotation) {
            return typesMatch(A, B.annotation.type);
        }
        if (A.* == .identifier and B.* != .identifier and A != A.expand_identifier()) {
            // If only A is an identifier, and A isn't an atom type, dive
            return typesMatch(A.expand_identifier(), B);
        } else if (A.* != .identifier and B.* == .identifier and B != B.expand_identifier()) {
            // If only B is an identifier, and B isn't an atom type, dive
            return typesMatch(A, B.expand_identifier());
        }
        if (A.* == .poison or B.* == .poison) {
            return true; // Whatever
        }
        if (B.* == .unit_type) {
            return true; // Top type - vacuously true
        }
        if (A.* == .identifier and std.mem.eql(u8, "Void", A.token().data)) {
            return true; // Bottom type - vacuously true
        }
        std.debug.assert(A.common().validation_state == .valid);
        std.debug.assert(B.common().validation_state == .valid);

        if (@intFromEnum(A.*) != @intFromEnum(B.*)) {
            return false;
        }

        switch (A.*) {
            .identifier => return std.mem.eql(u8, A.token().data, B.token().data),
            .addrOf => return (B.addrOf.mut == false or B.addrOf.mut == A.addrOf.mut) and typesMatch(A.expr(), B.expr()),
            .sliceOf => return (B.sliceOf.kind != .MUT or
                @intFromEnum(B.sliceOf.kind) == @intFromEnum(A.sliceOf.kind)) and
                typesMatch(A.expr(), B.expr()),
            .unit_type => return true,
            .product => {
                if (B.children().items.len != A.children().items.len) {
                    return false;
                }
                var retval = true;
                for (A.children().items, B.children().items) |term, B_term| {
                    retval = retval and term.typesMatch(B_term);
                }
                return retval;
            },
            .sum => {
                if (B.children().items.len != A.children().items.len) {
                    return false;
                }
                var retval = true;
                for (A.children().items, B.children().items) |term, B_term| {
                    const this_name = term.annotation.pattern.token().data;
                    const B_name = B_term.annotation.pattern.token().data;
                    retval = retval and std.mem.eql(u8, this_name, B_name) and term.typesMatch(B_term);
                }
                return retval;
            },
            .function => return A.lhs().typesMatch(B.lhs()) and A.rhs().typesMatch(B.rhs()),
            .inferred_error => return A == B,
            else => {
                // TODO: May need to evaluate types, possibly done somewhere else though
                std.debug.print("typesMatch(): Unimplemented for {s}\n", .{@tagName(A.*)});
                unreachable;
            },
        }
    }

    /// Determines if a given integer type can represent a given integer value.
    pub fn can_represent_integer(self: *AST, value: i128) bool {
        var expanded = self.expand_identifier();
        while (expanded.* == .annotation) {
            expanded = expanded.annotation.type;
        }
        if (expanded.* == .unit_type) {
            // Top type
            return true;
        } else if (expanded.* != .identifier) {
            // Clearly not an integer type
            return false;
        }
        for (primitives_.keys()) |key| {
            const info = primitives_.get(key);
            if (std.mem.eql(u8, info.name, expanded.token().data) and
                info.bounds != null and
                value >= info.bounds.?.lower and
                value <= info.bounds.?.upper)
            {
                return true;
            }
        }
        return false;
    }

    pub fn can_represent_float(self: *AST) bool {
        return can_expanded_represent_float(self.expand_identifier());
    }

    pub fn can_expanded_represent_float(self: *AST) bool {
        var expanded = self;
        while (expanded.* == .annotation) {
            expanded = expanded.annotation.type;
        }
        if (expanded.* == .unit_type) {
            // Top type
            return true;
        } else if (expanded.* != .identifier) {
            // Clearly not a float type
            return false;
        }
        const info = primitives_.get(expanded.token().data);
        return info.type_kind == .floating_point;
    }

    pub fn is_eq_type(self: *AST) bool {
        var expanded = self.expand_identifier();
        while (expanded.* == .annotation) {
            expanded = expanded.annotation.type;
        }
        if (expanded.* == .addrOf) {
            return true;
        } else if (expanded.* == .product) {
            for (expanded.children().items) |term| {
                if (!term.is_eq_type()) {
                    return false;
                }
            }
            return true;
        } else if (expanded.* == .sum) {
            return true;
        } else if (expanded.* != .identifier) {
            return false;
        }
        return primitives_.from_ast(expanded).is_eq();
    }

    /// Ord <: Eq
    pub fn is_ord_type(self: *AST) bool {
        var expanded = self.expand_identifier();
        while (expanded.* == .annotation) {
            expanded = expanded.annotation.type;
        }
        if (expanded.* != .identifier) {
            return false;
        }
        return primitives_.from_ast(expanded).is_ord();
    }

    /// Num <: Ord
    pub fn is_num_type(self: *AST) bool {
        var expanded = self.expand_identifier();
        while (expanded.* == .annotation) {
            expanded = expanded.annotation.type;
        }
        if (expanded.* != .identifier) {
            return false;
        }
        return primitives_.from_ast(expanded).is_num();
    }

    /// Int <: Num
    pub fn is_int_type(self: *AST) bool {
        var expanded = self.expand_identifier();
        while (expanded.* == .annotation) {
            expanded = expanded.annotation.type;
        }
        if (expanded.* != .identifier) {
            return false;
        }
        return primitives_.from_ast(expanded).is_int();
    }

    pub fn is_comptime_expr(self: *AST) bool {
        // It's easier to list all the ASTs that AREN'T comptime! :-)
        return !(self.* == ._try or
            self.* == .block or
            self.* == .call);
        // AST kinds like `and` and `or` are technically control-flow, but conceptually, they terminate and
        // are pure.
        // `try` breaks normal control-flow. `block` allows for unpure statements like `continue`, `break`,
        // `return`, and `try`. `call` is non-comptime because functions are not pure in Orng.
        // Kinds like `and`, `or`, `orelse`, `catch`, `if`, `match`, and `while` are in a way "purer", and it
        // would be annoying to have to wrap these in comptime.
    }

    // Used to poison an AST node. Marks as valid, so any attempt to validate is memoized to return poison.
    pub fn enpoison(self: *AST) *AST {
        self.common().validation_state = .invalid;
        return poisoned;
    }

    pub fn assert_valid(self: *AST) *AST {
        self.common().validation_state = AST_Validation_State{ .valid = .{ .valid_form = self } };
        return self;
    }

    pub fn c_typesMatch(self: *AST, other: *AST) bool {
        if (self.* == .annotation) {
            return c_typesMatch(self.annotation.type, other);
        } else if (other.* == .annotation) {
            return c_typesMatch(self, other.annotation.type);
        }
        std.debug.assert(self.common().validation_state == .valid);
        std.debug.assert(other.common().validation_state == .valid);

        if (@intFromEnum(self.*) != @intFromEnum(other.*)) {
            return false;
        }

        switch (self.*) {
            .identifier => return std.mem.eql(u8, self.token().data, other.token().data),
            .addrOf => return c_typesMatch(self.expr(), other.expr()),
            .unit_type => return other.* == .unit_type,
            .product, .sum => {
                if (other.children().items.len != self.children().items.len) {
                    return false;
                }
                var retval = true;
                for (self.children().items, other.children().items) |term, other_term| {
                    retval = retval and term.c_typesMatch(other_term);
                }
                return retval;
            },
            .function => return self.lhs().c_typesMatch(other.lhs()) and self.rhs().c_typesMatch(other.rhs()),
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
            .unit_type => try out.writer().print("unit_type", .{}),
            .unit_value => try out.writer().print("unit_value", .{}),
            .int => try out.writer().print("int({})", .{self.int.data}),
            .char => try out.writer().print("char()", .{}),
            .float => try out.writer().print("float()", .{}),
            .string => try out.writer().print("string()", .{}),
            .field => try out.writer().print("field(\"{s}\")", .{self.field.common._token.data}),
            .identifier => try out.writer().print("identifier(\"{s}\")", .{self.identifier.common._token.data}),
            ._unreachable => try out.writer().print("unreachable", .{}),
            ._true => try out.writer().print("true", .{}),
            ._false => try out.writer().print("false", .{}),

            .not => try out.writer().print("not()", .{}),
            .negate => try out.writer().print("negate({})", .{self.expr()}),
            .dereference => try out.writer().print("dereference()", .{}),
            ._try => try out.writer().print("try()", .{}),
            .discard => try out.writer().print("discard()", .{}),
            ._typeOf => try out.writer().print("typeof({})", .{self.expr()}),
            .default => try out.writer().print("default({})", .{self.expr()}),
            .sizeOf => try out.writer().print("sizeOf({})", .{self.expr()}),
            .domainOf => try out.writer().print("domainof()", .{}),
            ._comptime => try out.writer().print("comptime({})", .{self.expr()}),

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
            .@"catch" => try out.writer().print("catch()", .{}),
            .@"orelse" => try out.writer().print("orelse()", .{}),
            .call => try out.writer().print("call()", .{}),
            .index => try out.writer().print("index()", .{}),
            .select => try out.writer().print("select()", .{}),
            .function => try out.writer().print("function({},{})", .{ self.lhs(), self.rhs() }),
            .invoke => try out.writer().print("invoke()", .{}),
            .sum => {
                try out.writer().print("sum(", .{});
                for (self.sum._terms.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.sum._terms.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },
            .inferred_error => try out.writer().print("inferred_error()", .{}),
            .inject => try out.writer().print("inject()", .{}),
            .product => {
                try out.writer().print("product(", .{});
                for (self.product._terms.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.product._terms.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },
            ._union => try out.writer().print("union()", .{}),

            .addrOf => try out.writer().print("addrOf({})", .{self.expr()}),
            .sliceOf => try out.writer().print("sliceOf()", .{}),
            .arrayOf => try out.writer().print("arrayOf()", .{}),
            .subSlice => try out.writer().print("subSlice()", .{}),
            .annotation => try out.writer().print("annotation(.field={}, .type={},.init={?})", .{
                self.annotation.pattern,
                self.annotation.type,
                self.annotation.init,
            }),
            .inferredMember => try out.writer().print("inferredMember(.ident={s})", .{self.inferredMember.ident.token().data}),

            ._if => try out.writer().print("if()", .{}),
            .match => try out.writer().print("match()", .{}),
            .mapping => try out.writer().print("mapping()", .{}),
            ._while => try out.writer().print("while()", .{}),
            ._for => try out.writer().print("for()", .{}),
            .block => try out.writer().print("block()", .{}),
            ._break => try out.writer().print("break", .{}),
            ._continue => try out.writer().print("continue", .{}),
            ._return => try out.writer().print("return()", .{}),
            .pattern_symbol => try out.writer().print("pattern_symbol({s})", .{self.pattern_symbol.name}),
            .decl => {
                try out.writer().print("decl(\n", .{});
                try out.writer().print("    .pattern = {},\n", .{self.decl.pattern});
                try out.writer().print("    .type = {?},\n", .{self.decl.type});
                try out.writer().print("    .init = {?},\n", .{self.decl.init});
                try out.writer().print(")", .{});
            },
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
