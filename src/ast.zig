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
        poisoned = AST.create_poison(token_.Token.init_simple("LMAO GET POISONED!"), std.heap.page_allocator);
        _ = poisoned.enpoison();
        inited = true;
    }
}

/// Represents the kind of a slice.
pub const Slice_Kind = union(enum) {
    slice, // data ptr and len
    mut, // mutable data ptr and len
    multiptr, // c-style `*` pointer, no len
    array, // static homogenous tuple, compile-time len
};

pub const Sum_From = enum {
    optional,
    @"error",
    none,
};

/// Contains common properties of all AST nodes
const AST_Common = struct {
    /// Token that defined the AST node in text.
    _token: token_.Token,

    /// The AST's type.
    /// Memoized, use `typeof()`.
    _type: ?*AST = null,

    /// The result of expanding the `_type` field.
    /// Memoized, use `expanded_type()`.
    _expanded_type: ?*AST = null,

    /// The number of bytes a value in an AST type takes up.
    /// Memoized, use `sizeof()`.
    _size: ?i64 = null,

    /// The alignment for values of this type.
    /// In general it is *NOT* true that size == alignof, especially for products and sums.
    _alignof: ?i64 = null,

    /// The AST's validation status.
    validation_state: AST_Validation_State = .unvalidated,
};

/// Represents an Abstract Syntax Tree.
pub const AST = union(enum) {
    /// Not generated for correct programs, used to represent incorrect ASTs
    poison: struct { common: AST_Common },
    /// Unit type
    unit_type: struct { common: AST_Common },
    /// Unit value
    unit_value: struct { common: AST_Common },
    /// Integer constant
    int: struct {
        common: AST_Common,
        data: i128,
        _represents: *AST, //< Type that this constant represents. Set on validation.
    },
    /// Floating-point constant
    float: struct {
        common: AST_Common,
        data: f64,
        _represents: *AST, //< Type that this constant represents. Set on validation.
    },
    /// Character constant
    char: struct { common: AST_Common },
    /// String constant
    string: struct {
        common: AST_Common,
        data: []const u8,
    },
    /// True constant
    true: struct { common: AST_Common },
    /// False constant
    false: struct { common: AST_Common },
    /// Field
    /// This tag is used for the right-hand-side of selects. They do not refer to symbols.
    field: struct { common: AST_Common },
    /// Identifier
    identifier: struct { common: AST_Common, _symbol: ?*symbol_.Symbol = null },

    not: struct { common: AST_Common, _expr: *AST },
    negate: struct { common: AST_Common, _expr: *AST },
    dereference: struct { common: AST_Common, _expr: *AST },
    @"try": struct {
        common: AST_Common,
        _expr: *AST,
        _symbol: ?*symbol_.Symbol, // `try`'s must be in functions. This is the function's symbol.
    },
    discard: struct { common: AST_Common, _expr: *AST },
    @"comptime": struct {
        common: AST_Common,
        _expr: *AST,
        name: ?*AST = null,
        _symbol: ?*symbol_.Symbol = null,
        result: ?*AST = null,
    },

    // Binary operators
    assign: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    @"or": struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    @"and": struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    add: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    sub: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    mult: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    div: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    mod: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    equal: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    not_equal: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    greater: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    lesser: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    greater_equal: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    lesser_equal: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    @"catch": struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    @"orelse": struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    call: struct { common: AST_Common, _lhs: *AST, _args: std.ArrayList(*AST) },
    index: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    select: struct {
        common: AST_Common,
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
    function: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    invoke: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    sum: struct {
        common: AST_Common,
        _terms: std.ArrayList(*AST),
        from: Sum_From = .none,
        all_unit: ?bool = null,
        pub fn is_all_unit(self: *@This()) bool {
            if (self.all_unit) |all_unit| {
                return all_unit;
            }
            var res = true;
            for (self._terms.items) |term| {
                res = res and term.c_types_match(primitives_.unit_type);
            }
            self.all_unit = res;
            return res;
        }
    },
    inferred_error: struct {
        common: AST_Common,
        _terms: std.ArrayList(*AST),
    },
    inject: struct {
        common: AST_Common,
        _lhs: *AST,
        _rhs: *AST,
        domain: ?*AST, // Filled by validate
    },
    product: struct {
        common: AST_Common,
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
                if (!first_type.types_match(term)) {
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
    @"union": struct { common: AST_Common, _lhs: *AST, _rhs: *AST },

    // Fancy operators
    addr_of: struct { common: AST_Common, _expr: *AST, mut: bool },
    slice_of: struct { common: AST_Common, _expr: *AST, kind: Slice_Kind },
    array_of: struct { common: AST_Common, _expr: *AST, len: *AST },
    sub_slice: struct { common: AST_Common, super: *AST, lower: ?*AST, upper: ?*AST },
    annotation: struct { common: AST_Common, pattern: *AST, type: *AST, predicate: ?*AST, init: ?*AST },
    inferred_member: struct {
        common: AST_Common,
        ident: *AST,
        init: ?*AST = null,
        base: ?*AST = null, // This should ideally be kept in unexpanded form. use `typeof(inferredMember)` for expanded form
        _pos: ?usize = null,
    },
    type_of: struct {
        common: AST_Common,
        _expr: *AST,
    },
    default: struct {
        common: AST_Common,
        _expr: *AST,
    },
    size_of: struct {
        common: AST_Common,
        _expr: *AST,
    },
    domain_of: struct {
        common: AST_Common,
        sum_expr: *AST,
        _expr: *AST,
    },

    // Control-flow expressions
    @"if": struct {
        common: AST_Common,
        scope: ?*symbol_.Scope,
        let: ?*AST,
        condition: *AST,
        body_block: *AST,
        else_block: ?*AST,
    },
    match: struct {
        common: AST_Common,
        scope: ?*symbol_.Scope,
        let: ?*AST,
        _expr: *AST,
        _mappings: std.ArrayList(*AST),
    },
    mapping: struct {
        common: AST_Common,
        _lhs: *AST,
        _rhs: *AST,
        scope: ?*symbol_.Scope, // Scope used for `match` mappings, rooted in `match`'s scope. Captures, rhs live in this scope
    },
    @"while": struct {
        common: AST_Common,
        scope: ?*symbol_.Scope,
        let: ?*AST,
        condition: *AST,
        post: ?*AST,
        body_block: *AST,
        else_block: ?*AST,
    },
    @"for": struct {
        common: AST_Common,
        scope: ?*symbol_.Scope,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        body_block: *AST,
        else_block: ?*AST,
    },
    block: struct {
        common: AST_Common,
        scope: ?*symbol_.Scope,
        _statements: std.ArrayList(*AST),
        final: ?*AST, // either `return`, `continue`, or `break`
    },

    // Control-flow statements
    @"break": struct { common: AST_Common },
    @"continue": struct { common: AST_Common },
    @"unreachable": struct { common: AST_Common },
    @"return": struct {
        common: AST_Common,
        _ret_expr: ?*AST,
        _symbol: ?*symbol_.Symbol, // `retrun`'s must be in functions. This is the function's symbol.
    },
    /// This type is a special version of an identifier. It is needed to encapsulate information about a
    /// symbol declaration that is needed before the symbol is even constructed. An identifier AST cannot be
    /// used for this purpose, because it refers to a symbol _after_ symbol decoration.
    pattern_symbol: struct {
        common: AST_Common,
        name: []const u8,
        kind: symbol_.Symbol_Kind,
        _symbol: ?*symbol_.Symbol = undefined,
    },
    decl: struct {
        common: AST_Common,
        symbols: std.ArrayList(*symbol_.Symbol), // List of symbols that are defined with this statement
        pattern: *AST, // Structure of ASTs. Has to be structured to allow tree patterns like `let ((a, b), (c, d)) = blah`
        type: *AST,
        init: *AST,
        top_level: bool,
    },
    fn_decl: struct {
        common: AST_Common,
        name: ?*AST,
        _params: std.ArrayList(*AST), // Parameters' decl ASTs
        param_symbols: std.ArrayList(*symbol_.Symbol), // Parameters' symbols
        ret_type: *AST,
        refinement: ?*AST,
        init: *AST,
        _symbol: ?*symbol_.Symbol = null,
        infer_error: bool,
    },
    @"defer": struct { common: AST_Common, _statement: *AST },
    @"errdefer": struct { common: AST_Common, _statement: *AST },

    pub fn create_poison(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .poison = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_unit_type(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .unit_type = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_unit_value(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .unit_value = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_int(_token: token_.Token, data: i128, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .int = .{ .common = _common, .data = data, ._represents = primitives_.int_type } }, allocator);
    }

    pub fn create_char(
        _token: token_.Token, // `token.data` should of course encompass the `'` used for character delimination. This is unlike strings.
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .char = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_float(_token: token_.Token, data: f64, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .float = .{ .common = _common, .data = data, ._represents = primitives_.float_type } }, allocator);
    }

    pub fn create_string(
        _token: token_.Token,
        data: []const u8, // The string's raw utf8 bytes, not containing `"`'s, with escapes escaped
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .string = .{ .common = AST_Common{ ._token = _token, ._type = null }, .data = data } }, allocator);
    }

    pub fn create_field(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .field = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_identifier(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .identifier = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_unreachable(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"unreachable" = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_true(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .true = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_false(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .false = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_not(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .not = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn create_negate(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .negate = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn create_dereference(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .dereference = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn create_try(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .@"try" = .{ .common = _common, ._expr = _expr, ._symbol = null } }, allocator);
    }

    pub fn create_discard(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .discard = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn create_comptime(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .@"comptime" = .{ .common = _common, ._expr = _expr, .name = null, ._symbol = null } }, allocator);
    }

    pub fn create_type_of(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .type_of = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn create_default(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .default = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn create_size_of(_token: token_.Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .size_of = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._expr = _expr } }, allocator);
    }

    pub fn create_domain_of(_token: token_.Token, sum_expr: *AST, _expr: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .domain_of = .{ .common = _common, .sum_expr = sum_expr, ._expr = _expr } }, allocator);
    }

    pub fn create_assign(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .assign = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_or(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"or" = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_and(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"and" = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_equal(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .equal = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_not_equal(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .not_equal = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_greater(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .greater = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_lesser(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .lesser = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_greater_equal(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .greater_equal = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_lesser_equal(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .lesser_equal = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_add(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .add = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_sub(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .sub = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_mult(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .mult = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_div(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .div = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_mod(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .mod = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_catch(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .@"catch" = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_orelse(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .@"orelse" = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_call(_token: token_.Token, _lhs: *AST, args: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .call = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._args = args } }, allocator);
    }

    pub fn create_index(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .index = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_select(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .select = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs, ._pos = null } }, allocator);
    }

    pub fn create_sum(_token: token_.Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .sum = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._terms = terms } }, allocator);
    }

    pub fn create_inferred_error(_token: token_.Token, ok: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        var retval: AST = AST{ .inferred_error = .{ .common = _common, ._terms = std.ArrayList(*AST).init(allocator) } };
        const ok_ident = AST.create_identifier(token_.Token.init_simple("ok"), allocator);
        const ok_annot = create_annotation(_token, ok_ident, ok, null, null, allocator);
        retval.children().append(ok_annot) catch unreachable;

        return AST.box(retval, allocator);
    }

    pub fn create_inject(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .inject = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs, .domain = null } }, allocator);
    }

    pub fn create_function(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .function = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_invoke(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .invoke = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_product(_token: token_.Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .product = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._terms = terms } }, allocator);
    }

    pub fn create_union(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .@"union" = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_addr_of(_token: token_.Token, _expr: *AST, mut: bool, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .addr_of = .{ .common = _common, ._expr = _expr, .mut = mut } }, allocator);
    }

    pub fn create_slice_of(_token: token_.Token, _expr: *AST, kind: Slice_Kind, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .slice_of = .{ .common = _common, ._expr = _expr, .kind = kind } }, allocator);
    }

    pub fn create_array_of(_token: token_.Token, _expr: *AST, len: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .array_of = .{ .common = _common, ._expr = _expr, .len = len } }, allocator);
    }

    pub fn create_sub_slice(_token: token_.Token, super: *AST, lower: ?*AST, upper: ?*AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .sub_slice = .{ .common = _common, .super = super, .lower = lower, .upper = upper } }, allocator);
    }

    pub fn create_annotation(
        _token: token_.Token,
        pattern: *AST,
        _type: *AST,
        predicate: ?*AST,
        init: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(
            AST{ .annotation = .{ .common = _common, .pattern = pattern, .type = _type, .predicate = predicate, .init = init } },
            allocator,
        );
    }

    pub fn create_inferred_member(_token: token_.Token, ident: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .inferred_member = .{ .common = AST_Common{ ._token = _token, ._type = null }, .ident = ident } }, allocator);
    }

    pub fn create_if(
        _token: token_.Token,
        let: ?*AST,
        condition: *AST,
        body_block: *AST,
        else_block: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(
            AST{ .@"if" = .{
                .common = _common,
                .scope = null,
                .let = let,
                .condition = condition,
                .body_block = body_block,
                .else_block = else_block,
            } },
            allocator,
        );
    }

    pub fn create_match(
        _token: token_.Token,
        let: ?*AST,
        _expr: *AST,
        mappings: std.ArrayList(*AST),
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .match = .{
                .common = AST_Common{ ._token = _token, ._type = null },
                .scope = null,
                .let = let,
                ._expr = _expr,
                ._mappings = mappings,
            } },
            allocator,
        );
    }

    pub fn create_mapping(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .mapping = .{
                .common = AST_Common{ ._token = _token, ._type = null },
                ._lhs = _lhs,
                ._rhs = _rhs,
                .scope = null,
            } },
            allocator,
        );
    }

    pub fn create_while(
        _token: token_.Token,
        let: ?*AST,
        condition: *AST,
        post: ?*AST,
        body_block: *AST,
        else_block: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .@"while" = .{
                .common = AST_Common{ ._token = _token, ._type = null },
                .scope = null,
                .let = let,
                .condition = condition,
                .post = post,
                .body_block = body_block,
                .else_block = else_block,
            } },
            allocator,
        );
    }

    pub fn create_for(
        _token: token_.Token,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        body_block: *AST,
        else_block: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .@"for" = .{
                .common = AST_Common{ ._token = _token, ._type = null },
                .scope = null,
                .let = let,
                .elem = elem,
                .iterable = iterable,
                .body_block = body_block,
                .else_block = else_block,
            } },
            allocator,
        );
    }

    pub fn create_block(_token: token_.Token, statements: std.ArrayList(*AST), final: ?*AST, allocator: std.mem.Allocator) *AST {
        if (final) |_final| {
            std.debug.assert(_final.* == .@"return" or _final.* == .@"continue" or _final.* == .@"break");
        }
        return AST.box(
            AST{ .block = .{
                .common = AST_Common{ ._token = _token, ._type = null },
                .scope = null,
                ._statements = statements,
                .final = final,
            } },
            allocator,
        );
    }

    pub fn create_break(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"break" = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_continue(_token: token_.Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"continue" = .{ .common = AST_Common{ ._token = _token, ._type = null } } }, allocator);
    }

    pub fn create_return(_token: token_.Token, _ret_expr: ?*AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .@"return" = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._ret_expr = _ret_expr, ._symbol = null } },
            allocator,
        );
    }

    pub fn create_symbol(_token: token_.Token, kind: symbol_.Symbol_Kind, name: []const u8, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .pattern_symbol = .{ .common = AST_Common{ ._token = _token, ._type = null }, .kind = kind, .name = name } },
            allocator,
        );
    }

    pub fn create_decl(_token: token_.Token, pattern: *AST, _type: *AST, init: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .decl = .{
                .common = AST_Common{ ._token = _token, ._type = null },
                .symbols = std.ArrayList(*symbol_.Symbol).init(allocator),
                .pattern = pattern,
                .type = _type,
                .init = init,
                .top_level = false,
            } },
            allocator,
        );
    }

    pub fn create_fn_decl(
        _token: token_.Token,
        name: ?*AST,
        params: std.ArrayList(*AST),
        ret_type: *AST,
        refinement: ?*AST,
        init: *AST,
        infer_error: bool,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .fn_decl = .{
            .common = AST_Common{ ._token = _token, ._type = null },
            .name = name,
            ._params = params,
            .param_symbols = std.ArrayList(*symbol_.Symbol).init(allocator),
            .ret_type = ret_type,
            .refinement = refinement,
            .init = init,
            .infer_error = infer_error,
        } }, allocator);
    }

    pub fn create_defer(_token: token_.Token, _statement: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"defer" = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._statement = _statement } }, allocator);
    }

    pub fn create_errdefer(_token: token_.Token, _statement: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .@"errdefer" = .{ .common = AST_Common{ ._token = _token, ._type = null }, ._statement = _statement } },
            allocator,
        );
    }

    /// Boxes an AST value into an allocator.
    fn box(ast: AST, alloc: std.mem.Allocator) *AST {
        const retval = alloc.create(AST) catch unreachable;
        retval.* = ast;
        return retval;
    }

    pub fn common(self: *AST) *AST_Common {
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
            .fn_decl => &self.fn_decl._params,
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
            .fn_decl => self.fn_decl._params = val,
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

    pub fn create_array_type(len: *AST, of: *AST, allocator: std.mem.Allocator) *AST {
        // Inflate an array-of to a product with `len` `of`'s
        var new_terms = std.ArrayList(*AST).init(allocator);
        std.debug.assert(len.int.data >= 0);
        for (0..@as(usize, @intCast(len.int.data))) |_| {
            new_terms.append(of) catch unreachable;
        }
        return AST.create_product(of.token(), new_terms, allocator);
    }

    pub fn create_slice_type(of: *AST, mut: bool, allocator: std.mem.Allocator) *AST {
        var term_types = std.ArrayList(*AST).init(allocator);
        const data_type = AST.create_addr_of(
            of.token(),
            of,
            mut,
            allocator,
        ).assert_valid();
        const annot_type = AST.create_annotation(
            of.token(),
            AST.create_identifier(token_.Token.init("data", null, "", "", 0, 0), allocator),
            data_type,
            null,
            null,
            allocator,
        ).assert_valid();
        term_types.append(annot_type) catch unreachable;
        term_types.append(AST.create_annotation(
            of.token(),
            AST.create_identifier(token_.Token.init("length", null, "", "", 0, 0), allocator),
            primitives_.int_type,
            null,
            null,
            allocator,
        )) catch unreachable;
        var retval = AST.create_product(of.token(), term_types, allocator).assert_valid();
        retval.product.was_slice = true;
        return retval;
    }

    // Expr must be a product value of length `l`. Slice value is `(&expr[0], l)`.
    pub fn create_slice_value(_expr: *AST, mut: bool, expr_type: *AST, allocator: std.mem.Allocator) *AST {
        var new_terms = std.ArrayList(*AST).init(allocator);
        const zero = (AST.create_int(_expr.token(), 0, allocator)).assert_valid();
        const index = (AST.create_index(
            _expr.token(),
            _expr,
            zero,
            allocator,
        )).assert_valid();
        const addr = (AST.create_addr_of(
            _expr.token(),
            index,
            mut,
            allocator,
        )).assert_valid();
        new_terms.append(addr) catch unreachable;

        const length = (AST.create_int(_expr.token(), expr_type.children().items.len, allocator)).assert_valid();
        new_terms.append(length) catch unreachable;

        var retval = AST.create_product(_expr.token(), new_terms, allocator);
        retval.product.was_slice = true;
        return retval;
    }

    pub fn create_optional_type(of_type: *AST, allocator: std.mem.Allocator) *AST {
        var term_types = std.ArrayList(*AST).init(allocator);

        const some_type = AST.create_annotation(
            of_type.token(),
            AST.create_identifier(token_.Token.init("some", null, "", "", 0, 0), allocator),
            of_type,
            null,
            null,
            allocator,
        );
        term_types.append(some_type) catch unreachable;

        const none_type = AST.create_annotation(
            of_type.token(),
            AST.create_identifier(token_.Token.init_simple("none"), allocator),
            primitives_.unit_type,
            null,
            AST.create_unit_value(token_.Token.init_simple("none init"), allocator),
            allocator,
        );
        term_types.append(none_type) catch unreachable;

        var retval = AST.create_sum(of_type.token(), term_types, allocator);
        retval.sum.from = .optional;
        return retval;
    }

    pub fn create_some_value(opt_type: *AST, value: *AST, allocator: std.mem.Allocator) *AST {
        const member = create_inferred_member(value.token(), AST.create_identifier(token_.Token.init_simple("some"), allocator), allocator);
        member.inferred_member.base = opt_type;
        member.inferred_member.init = value;
        member.set_pos(opt_type.get_pos("some"));
        return member.assert_valid();
    }

    pub fn create_none_value(opt_type: *AST, allocator: std.mem.Allocator) *AST {
        const member = create_inferred_member(
            token_.Token.init_simple("none"),
            AST.create_identifier(token_.Token.init_simple("none"), allocator),
            allocator,
        );
        member.inferred_member.base = opt_type;
        member.set_pos(opt_type.get_pos("none"));
        return member.assert_valid();
    }

    pub fn create_error_type(err_type: *AST, ok_type: *AST, allocator: std.mem.Allocator) *AST {
        const ok_annot = AST.create_annotation(
            ok_type.token(),
            AST.create_identifier(token_.Token.init("ok", null, "", "", 0, 0), allocator),
            ok_type,
            null,
            null,
            allocator,
        );
        var ok_sum_terms = std.ArrayList(*AST).init(allocator);
        ok_sum_terms.append(ok_annot) catch unreachable;
        var ok_sum = AST.create_sum(ok_type.token(), ok_sum_terms, allocator);
        ok_sum.sum.from = .@"error";

        // Err!Ok => (ok:Ok|) || Err
        // This is done so that `ok` has an invariant tag of `0`, and errors have a non-zero tag.
        const retval = AST.create_union(err_type.token(), ok_sum, err_type, allocator);
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
        if (self.common()._expanded_type != null and self.* != .identifier) {
            return self.common()._expanded_type.?;
        }
        const retval = expand_type_internal(self, allocator).assert_valid();
        self.common()._expanded_type = retval;
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
                if (expand_type_list(self.children(), allocator)) |new_terms| {
                    var retval = AST.create_product(self.token(), new_terms, allocator);
                    retval.product.was_slice = self.product.was_slice;
                    return retval;
                } else {
                    return self;
                }
            },
            .sum => {
                if (expand_type_list(self.children(), allocator)) |new_terms| {
                    var retval = AST.create_sum(self.token(), new_terms, allocator);
                    retval.sum.from = self.sum.from;
                    return retval;
                } else {
                    return self;
                }
            },
            .function => {
                const _lhs = self.lhs().expand_type(allocator);
                const _rhs = self.rhs().expand_type(allocator);
                return AST.create_function(self.token(), _lhs, _rhs, allocator);
            },
            .annotation => {
                const _expr = self.annotation.type.expand_type(allocator);
                return AST.create_annotation(
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
            .addr_of, .poison, .unit_type => return self,

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

    // Expands an ast one level if it is an identifier
    pub fn expand_identifier(self: *AST) *AST {
        if (self.* == .identifier) {
            return self.symbol().?.init;
        } else {
            return self;
        }
    }

    pub fn create_binop(_token: token_.Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        switch (_token.kind) {
            .plus_equals => return create_add(_token, _lhs, _rhs, allocator),
            .minus_equals => return create_sub(_token, _lhs, _rhs, allocator),
            .star_equals => return create_mult(_token, _lhs, _rhs, allocator),
            .slash_equals => return create_div(_token, _lhs, _rhs, allocator),
            .percent_equals => return create_mod(_token, _lhs, _rhs, allocator),
            else => {
                std.debug.print("not a operator-assign token\n", .{});
                unreachable;
            },
        }
    }

    pub fn print_type(self: *AST, out: anytype) !void {
        switch (self.*) {
            .unit_type => try out.print("()", .{}),
            .identifier => try out.print("{s}", .{self.token().data}),
            .addr_of => {
                try out.print("&", .{});
                if (self.addr_of.mut) {
                    try out.print("mut ", .{});
                }
                try self.expr().print_type(out);
            },
            .slice_of => {
                try out.print("[", .{});
                switch (self.slice_of.kind) {
                    .mut => try out.print("mut", .{}),
                    .multiptr => try out.print("*", .{}),
                    .slice => {},
                    .array => unreachable,
                }
                try out.print("]", .{});
                try self.expr().print_type(out);
            },
            .array_of => {
                try out.print("[", .{});
                try self.array_of.len.print_type(out);
                try out.print("]", .{});
                try self.expr().print_type(out);
            },
            .function => {
                try out.print("(", .{});
                try self.lhs().print_type(out);
                try out.print(")->", .{});
                try self.rhs().print_type(out);
            },
            .product => if (self.product.homotypical != null and self.product.homotypical.?) {
                try out.print("[{}]", .{self.children().items.len});
                try self.children().items[0].print_type(out);
            } else if (self.product.was_slice) {
                try out.print("[]", .{});
                try self.children().items[0].print_type(out);
            } else if (self.children().items.len == 0) {
                try out.print("()", .{});
            } else {
                try out.print("(", .{});
                for (self.children().items, 0..self.children().items.len) |term, _| {
                    try term.print_type(out);
                    try out.print(", ", .{});
                }
                try self.children().items[self.children().items.len - 1].print_type(out);
                try out.print(")", .{});
            },
            .sum => if (self.sum.from == .optional) {
                try out.print("?", .{});
                try self.get_some_type().annotation.type.print_type(out);
            } else {
                try out.print("(", .{});
                for (self.sum._terms.items, 0..) |term, i| {
                    try term.print_type(out);
                    if (self.sum._terms.items.len == 1 or i + 1 != self.sum._terms.items.len) {
                        try out.print(" | ", .{});
                    }
                }
                try out.print(")", .{});
            },
            .inferred_error => {
                try out.print("!", .{});
                try self.inferred_error._terms.items[0].annotation.type.print_type(out);
            },
            .@"union" => {
                try self.lhs().print_type(out);
                try out.print("||", .{});
                try self.rhs().print_type(out);
            },
            .annotation => {
                try out.print("{s}: ", .{self.annotation.pattern.token().data});
                try self.annotation.type.print_type(out);
            },

            // Not necessarily types, but may appear in a type definition
            .int => try out.print("{}", .{self.int.data}),
            .block => {
                try out.print("{{", .{});
                for (self.block._statements.items, 0..) |_statement, i| {
                    try _statement.print_type(out);
                    if (self.block.final != null or i > self.block._statements.items.len - 1) {
                        try out.print("; ", .{});
                    }
                }
                if (self.block.final) |final| {
                    try final.print_type(out);
                }
                try out.print("}}", .{});
            },
            .index => {
                try self.lhs().print_type(out);
                try out.print("[", .{});
                try self.rhs().print_type(out);
                try out.print("]", .{});
            },
            .@"unreachable" => try out.print("unreachable", .{}),
            .poison => try out.print("<error>", .{}),
            else => {
                try out.print("\nprint_types(): Unimplemented or not a type: {s}\n", .{@tagName(self.*)});
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
            .true,
            .false,
            .not,
            .@"or",
            .@"and",
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
            .@"union",
            .function,
            .type_of,
            .array_of,
            => return primitives_.type_type,

            // Unit type
            .unit_value,
            .decl,
            .assign,
            .@"defer",
            .@"errdefer",
            .discard,
            => return primitives_.unit_type,

            // Void type
            .@"continue",
            .@"break",
            .@"return",
            .@"unreachable",
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
                if (first_type.types_match(primitives_.type_type)) {
                    // typeof product type is Type
                    return primitives_.type_type;
                } else if (self.product.was_slice) {
                    var addr: *AST = self.children().items[0];
                    var retval = create_slice_type(addr.expr().typeof(allocator), addr.addr_of.mut, allocator);
                    retval.product.was_slice = true;
                    return retval;
                } else {
                    var terms = std.ArrayList(*AST).init(allocator);
                    for (self.children().items) |term| {
                        const term_type = term.typeof(allocator);
                        terms.append(term_type) catch unreachable;
                    }
                    var retval = AST.create_product(self.token(), terms, allocator);
                    retval.product.was_slice = self.product.was_slice;
                    return retval;
                }
            },

            .index => {
                var lhs_type = self.lhs().typeof(allocator).expand_type(allocator);
                if (lhs_type.types_match(primitives_.type_type) and self.lhs().* == .product) {
                    return self.lhs().children().items[0];
                } else if (lhs_type.* == .product) {
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
            .@"comptime", .negate => return self.expr().typeof(allocator),
            .dereference => {
                const _type = self.expr().typeof(allocator).expand_type(allocator);
                return _type.expr();
            },
            .addr_of => {
                var child_type = self.expr().typeof(allocator);
                if (child_type.types_match(primitives_.type_type)) {
                    return primitives_.type_type;
                } else {
                    return create_addr_of(self.token(), child_type, self.addr_of.mut, std.heap.page_allocator);
                }
            },
            .slice_of => {
                var expr_type = self.expr().typeof(allocator);
                if (expr_type.* != .product or !expr_type.product.is_homotypical()) {
                    return poisoned;
                } else {
                    var child_type = expr_type.children().items[0];
                    if (child_type.types_match(primitives_.type_type)) {
                        return primitives_.type_type;
                    } else {
                        return create_slice_type(expr_type.children().items[0], self.slice_of.kind == .mut, allocator);
                    }
                }
            },
            .sub_slice => return self.sub_slice.super.typeof(allocator),
            .inferred_member => return self.inferred_member.base.?.expand_type(allocator),
            .@"try" => return self.expr().typeof(allocator).get_ok_type(),
            .default => return self.expr(),

            // Control-flow expressions
            .@"if" => { // TODO: This could be unified with .@"while"'s typeof
                const body_type = self.@"if".body_block.typeof(allocator);
                if (self.@"if".else_block != null or
                    primitives_.unit_type.types_match(body_type.expand_type(allocator)) or
                    body_type.expand_type(allocator).types_match(primitives_.void_type))
                {
                    return body_type;
                } else {
                    return create_optional_type(body_type, allocator);
                }
            },
            .match => return self.children().items[0].typeof(allocator),
            .@"while" => {
                const body_type = self.@"while".body_block.typeof(allocator);
                if (body_type.types_match(primitives_.void_type)) {
                    return primitives_.unit_type;
                } else if (self.@"while".else_block != null or primitives_.unit_type.types_match(body_type)) {
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
            .fn_decl => return self.symbol().?._type,
            .pattern_symbol => return self.symbol().?._type,
            .inject => return self.lhs().typeof(allocator),

            else => {
                std.debug.print("Unimplemented typeof() for: AST.{s}\n", .{@tagName(self.*)});
                unreachable;
            },
        }
    }

    /// Retrieves the size in bytes of an AST node.
    pub fn sizeof(self: *AST) i64 {
        if (self.common()._size == null) {
            self.common()._size = self.sizeof_internal(); // memoize call
        }

        return self.common()._size.?;
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

            .function, .addr_of => return 8,

            .unit_type => return 0,

            .annotation => return self.annotation.type.sizeof(),

            else => {
                std.debug.print("Unimplemented sizeof for {}\n", .{self});
                unreachable;
            },
        }
    }

    pub fn alignof(self: *AST) i64 {
        if (self.common()._alignof == null) {
            self.common()._alignof = self.alignof_internal(); // memoize call
        }

        return self.common()._alignof.?;
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
            .addr_of,
            => return 8,

            .unit_type => return 1, // fogedda bout it

            .annotation => return self.annotation.type.alignof(),

            else => {
                std.debug.print("Unimplemented alignof for {}\n", .{self});
                unreachable;
            },
        }
    }

    /// For two types `A` and `B`, we say `A <: B` iff for every value `a` belonging to the type `A`, then
    /// `a` belongs to the type `B`.
    ///
    /// Another way to view this is if `(a: A) <: (b: B)`, then the assignment `b = a` is permissible, since
    /// `a: B`.
    ///
    /// Since the type `Void` has no values, the following are always true for any type T:
    /// - `Void <: T`
    /// - `let x: Void = y` is never type sound (there is no possible value `y` can be)
    /// - `let x: T = void_typed_expression` is always type-sound.
    /// - `types_match(primitives_.void_type, T)` is always true
    ///
    /// The unit type (`()`) acts like the top type. The following are always true for any type T:
    /// - `T <: ()`
    /// - `let x: T = unit_typed_expression` type-sound only if `T == ()`
    /// - `let x: () = y` is always type-sound (y is discarded)
    /// - `types_match(X, primitives_.unit_type)` is always true
    ///
    /// Thus, we have the following type map:
    /// ```txt
    ///                        ( )
    ///       /     /     /     |    \      \     \
    ///     Bool  Byte  Char  Float  Int  String  ...
    ///       \     \     \     |    /      /     /
    ///                       Void
    /// ```
    ///
    /// Also, `&mut T <: &T`, because for every `t: &mut T`, `t: &T`. Thus, `let x: &T = mut_expression` is
    /// always type-sound.
    ///
    /// Also, (x: T,) == T == (x: T,)
    pub fn types_match(A: *AST, B: *AST) bool {
        // std.debug.print("{} == {}\n", .{ A, B });
        if (A.* == .annotation) {
            return types_match(A.annotation.type, B);
        } else if (B.* == .annotation) {
            return types_match(A, B.annotation.type);
        }
        if (A.* == .identifier and B.* != .identifier and A != A.expand_identifier()) {
            // If only A is an identifier, and A isn't an atom type, dive
            return types_match(A.expand_identifier(), B);
        } else if (A.* != .identifier and B.* == .identifier and B != B.expand_identifier()) {
            // If only B is an identifier, and B isn't an atom type, dive
            return types_match(A, B.expand_identifier());
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
            .addr_of => return (B.addr_of.mut == false or B.addr_of.mut == A.addr_of.mut) and types_match(A.expr(), B.expr()),
            .slice_of => return (B.slice_of.kind != .mut or
                @intFromEnum(B.slice_of.kind) == @intFromEnum(A.slice_of.kind)) and
                types_match(A.expr(), B.expr()),
            .array_of => return types_match(A.expr(), B.expr()),
            .unit_type => return true,
            .product => {
                if (B.children().items.len != A.children().items.len) {
                    return false;
                }
                var retval = true;
                for (A.children().items, B.children().items) |term, B_term| {
                    retval = retval and term.types_match(B_term);
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
                    retval = retval and std.mem.eql(u8, this_name, B_name) and term.types_match(B_term);
                }
                return retval;
            },
            .function => return A.lhs().types_match(B.lhs()) and A.rhs().types_match(B.rhs()),
            .inferred_error => return A == B,
            else => {
                std.debug.print("types_match(): Unimplemented for {s}\n", .{@tagName(A.*)});
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
        if (expanded.* == .addr_of) {
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
        return primitives_.from_ast(expanded).?.is_eq();
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
        return primitives_.from_ast(expanded).?.is_ord();
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
        return primitives_.from_ast(expanded).?.is_num();
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
        return primitives_.from_ast(expanded).?.is_int();
    }

    pub fn is_comptime_expr(self: *AST) bool {
        // It's easier to list all the ASTs that AREN'T comptime! :-)
        return !(self.* == .@"try" or
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

    pub fn c_types_match(self: *AST, other: *AST) bool {
        if (self.* == .annotation) {
            return c_types_match(self.annotation.type, other);
        } else if (other.* == .annotation) {
            return c_types_match(self, other.annotation.type);
        }
        std.debug.assert(self.common().validation_state == .valid);
        std.debug.assert(other.common().validation_state == .valid);

        if (@intFromEnum(self.*) != @intFromEnum(other.*)) {
            return false;
        }

        switch (self.*) {
            .identifier => return std.mem.eql(u8, self.token().data, other.token().data),
            .addr_of => return c_types_match(self.expr(), other.expr()),
            .unit_type => return other.* == .unit_type,
            .product, .sum => {
                if (other.children().items.len != self.children().items.len) {
                    return false;
                }
                var retval = true;
                for (self.children().items, other.children().items) |term, other_term| {
                    retval = retval and term.c_types_match(other_term);
                }
                return retval;
            },
            .function => return self.lhs().c_types_match(other.lhs()) and self.rhs().c_types_match(other.rhs()),
            else => {
                std.debug.print("types_match(): Unimplemented for {s}\n", .{@tagName(self.*)});
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
            .@"unreachable" => try out.writer().print("unreachable", .{}),
            .true => try out.writer().print("true", .{}),
            .false => try out.writer().print("false", .{}),

            .not => try out.writer().print("not()", .{}),
            .negate => try out.writer().print("negate({})", .{self.expr()}),
            .dereference => try out.writer().print("dereference()", .{}),
            .@"try" => try out.writer().print("try()", .{}),
            .discard => try out.writer().print("discard()", .{}),
            .type_of => try out.writer().print("typeof({})", .{self.expr()}),
            .default => try out.writer().print("default({})", .{self.expr()}),
            .size_of => try out.writer().print("sizeOf({})", .{self.expr()}),
            .domain_of => try out.writer().print("domainof()", .{}),
            .@"comptime" => try out.writer().print("comptime({})", .{self.expr()}),

            .assign => try out.writer().print("assign()", .{}),
            .@"or" => try out.writer().print("or()", .{}),
            .@"and" => try out.writer().print("and()", .{}),
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
            .@"union" => try out.writer().print("union()", .{}),

            .addr_of => try out.writer().print("addrOf({})", .{self.expr()}),
            .slice_of => try out.writer().print("sliceOf()", .{}),
            .array_of => try out.writer().print("arrayOf()", .{}),
            .sub_slice => try out.writer().print("subSlice()", .{}),
            .annotation => try out.writer().print("annotation(.field={}, .type={},.init={?})", .{
                self.annotation.pattern,
                self.annotation.type,
                self.annotation.init,
            }),
            .inferred_member => try out.writer().print("inferredMember(.ident={s})", .{self.inferred_member.ident.token().data}),

            .@"if" => try out.writer().print("if()", .{}),
            .match => try out.writer().print("match()", .{}),
            .mapping => try out.writer().print("mapping()", .{}),
            .@"while" => try out.writer().print("while()", .{}),
            .@"for" => try out.writer().print("for()", .{}),
            .block => {
                try out.writer().print("block(", .{});
                for (self.block._statements.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.block._statements.items.len) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(".final={?})", .{self.block.final});
            },
            .@"break" => try out.writer().print("break", .{}),
            .@"continue" => try out.writer().print("continue", .{}),
            .@"return" => try out.writer().print("return()", .{}),
            .pattern_symbol => try out.writer().print("pattern_symbol({s})", .{self.pattern_symbol.name}),
            .decl => {
                try out.writer().print("decl(\n", .{});
                try out.writer().print("    .pattern = {},\n", .{self.decl.pattern});
                try out.writer().print("    .type = {?},\n", .{self.decl.type});
                try out.writer().print("    .init = {?},\n", .{self.decl.init});
                try out.writer().print(")", .{});
            },
            .fn_decl => try out.writer().print("fnDecl()", .{}),
            .@"defer" => try out.writer().print("defer()", .{}),
            .@"errdefer" => try out.writer().print("errdefer()", .{}),
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
