// TODO: Can this file be split up?? At ALL?
// 1. keep AST union in this file
// 2. `pub using namespace @import("type-check.zig");`
// 3. `pub using namespace @import("type-properties.zig");`
// 4. `pub using namespace @import("validate-ast.zig");`
// 5. `pub using namespace @import("type-representation.zig");`, or a better name, for `can_represent_X`, `is_ord`, etc
// 6. `pub using namespace @import("poisoned-ast.zig");

const std = @import("std");
const module_ = @import("../hierarchy/module.zig");
const alignment_ = @import("../util/alignment.zig");
const core_ = @import("../hierarchy/core.zig");
const poison_ = @import("poison.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const Type_Map = @import("../ast/type_map.zig").Type_Map;
const validation_state_ = @import("../util/validation_state.zig");
const unification_ = @import("../types/unification.zig");

pub const AST_Validation_State = validation_state_.Validation_State;

pub const Receiver_Kind = enum {
    value, // Receiver is taken by value
    addr_of, // Receiver is taken by immutable address
    mut_addr_of, // Receiver is taken by mutable address

    pub fn to_string(self: @This()) []const u8 {
        return switch (self) {
            .value => "self",
            .addr_of => "&self",
            .mut_addr_of => "&mut self",
        };
    }
};

pub const Sum_From = enum {
    optional, // Sum-type comes from an optional constructor (ex: `?T`)
    @"error", // Sum-type comes from an error constructor (ex: `E!T`)
    none, // Regular, plain sum-type
};

/// Contains common properties of all AST nodes
pub const AST_Common = struct {
    /// Token that defined the AST node in text.
    _token: Token,

    /// The AST's validation status.
    validation_state: AST_Validation_State = .unvalidated,

    ok_for_comptime: bool = false, // HACK: generic functions that return a type have this set to true, passes valid_type check
};

/// Represents an Abstract Syntax Tree.
pub const AST = union(enum) {
    poison: struct { common: AST_Common },
    /// Unit value
    unit_value: struct { common: AST_Common },
    /// Integer constant
    int: struct {
        common: AST_Common,
        data: i128,
    },
    /// Floating-point constant
    float: struct {
        common: AST_Common,
        data: f64,
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
    identifier: struct {
        common: AST_Common,
        _symbol: ?*Symbol = null,

        pub inline fn refers_to_template(self: @This()) bool {
            return self._symbol.?.kind == .template;
        }
    },

    not: struct { common: AST_Common, _expr: *AST },
    negate: struct { common: AST_Common, _expr: *AST },
    dereference: struct { common: AST_Common, _expr: *AST },
    @"try": struct {
        common: AST_Common,
        _expr: *AST,
        _symbol: ?*Symbol, // `try`'s must be in functions. This is the function's symbol.
    },
    // @"comptime": struct {
    //     common: AST_Common,
    //     _expr: *AST,
    //     name: ?*AST = null,
    //     result: ?*AST = null,
    //     _scope: ?*Scope = null, // Surrounding scope. Filled in at symbol-tree creation. Used to create a comptime symbol
    // },

    // Binary operators
    // TODO: We could de-duplicate this, I suppose.
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
    bit_and: struct { common: AST_Common, _args: std.ArrayList(*AST) },
    bit_or: struct { common: AST_Common, _args: std.ArrayList(*AST) },
    bit_xor: struct { common: AST_Common, _args: std.ArrayList(*AST) },
    bit_not: struct { common: AST_Common, _expr: *AST },
    left_shift: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    right_shift: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    index: struct { common: AST_Common, _lhs: *AST, _rhs: *AST },
    select: struct {
        common: AST_Common,
        _lhs: *AST,
        _rhs: *AST,
        _pos: ?usize,
    },
    access: struct {
        common: AST_Common,
        _lhs: *AST,
        _rhs: *AST,
        // _pos: ?usize,
        _symbol: ?*Symbol = null,
        _scope: ?*Scope = null, // Surrounding scope. Filled in at symbol-tree creation.
    },
    trait: struct {
        common: AST_Common,
        method_decls: std.ArrayList(*AST),
        const_decls: std.ArrayList(*AST),
        num_virtual_methods: i64 = 0,
        _symbol: ?*Symbol = null, // Filled by symbol-tree pass.
        _scope: ?*Scope = null, // Filled by symbol-tree pass.

        pub fn find_method(self: @This(), name: []const u8) ?*AST {
            for (self.method_decls.items) |decl| {
                if (std.mem.eql(u8, decl.method_decl.name.token().data, name)) {
                    return decl;
                }
            }
            return null;
        }
    },
    impl: struct {
        common: AST_Common,
        trait: ?*AST, // Identifier-like ast which refers to the trait
        _type: *Type_AST, // The `for` type for this impl
        method_defs: std.ArrayList(*AST),
        const_defs: std.ArrayList(*AST),
        with_decls: std.ArrayList(*AST), // list of annotations
        num_virtual_methods: i64 = 0,
        _scope: ?*Scope = null, // Scope used for `impl` methods, rooted in `impl`'s scope.
        impls_anon_trait: bool = false, // true when this impl implements an anonymous trait
        instantiations: Type_Map(*AST),
    },
    invoke: struct {
        common: AST_Common,
        _lhs: *AST,
        _rhs: *AST,
        _args: std.ArrayList(*AST),
        _scope: ?*Scope = null, // Surrounding scope. Filled in at symbol-tree creation.
        method_decl: ?*AST = null,
    },
    /// A struct-like-value of pointers to the vtable, and to the receiver
    dyn_value: struct {
        common: AST_Common,
        dyn_type: *Type_AST, // reference to the type of this value, since it is only created using address-ofs
        _expr: *AST,
        mut: bool,
        impl: ?*AST = null, // The implementation AST, whose vtable should be used
        _scope: ?*Scope = null, // Surrounding scope. Filled in when addr-of is converted
    },
    enum_value: struct {
        common: AST_Common,
        domain: ?*Type_AST = null, // kept in it's annotation form, for compatability with calls
        init: ?*AST = null,
        base: ?*Type_AST = null,
        _pos: ?usize = null,

        pub fn get_name(self: *const @This()) []const u8 {
            return self.common._token.data;
        }
    },
    struct_value: struct {
        common: AST_Common,
        parent: *Type_AST,
        _terms: std.ArrayList(*AST),
        was_slice: bool,
    },
    tuple_value: struct {
        common: AST_Common,
        _terms: std.ArrayList(*AST),
    },
    array_value: struct {
        common: AST_Common,
        _terms: std.ArrayList(*AST),
    },

    // Fancy operators
    addr_of: struct {
        common: AST_Common,
        _expr: *AST,
        mut: bool,
        multiptr: bool = false,
        anytptr: bool = false, // When this is true, the addr_of should output as a void*, and should be cast whenever dereferenced
        _scope: ?*Scope = null, // Surrounding scope. Filled in at symbol-tree creation.
    },
    slice_of: struct {
        common: AST_Common,
        _expr: *AST,
        mut: bool,
    },
    sub_slice: struct { common: AST_Common, super: *AST, lower: ?*AST, upper: ?*AST },
    receiver: struct {
        common: AST_Common,
        kind: Receiver_Kind,
        _type: ?*Type_AST = null,
    },
    default: struct {
        common: AST_Common,
        _type: *Type_AST,
    },
    size_of: struct {
        common: AST_Common,
        _type: *Type_AST,
    },

    // Control-flow expressions
    @"if": struct {
        common: AST_Common,
        _scope: ?*Scope,
        let: ?*AST,
        condition: *AST,
        _body_block: *AST,
        _else_block: ?*AST,
    },
    match: struct {
        common: AST_Common,
        _scope: ?*Scope,
        let: ?*AST,
        _expr: *AST,
        _mappings: std.ArrayList(*AST),
    },
    mapping: struct {
        common: AST_Common,
        _lhs: *AST,
        _rhs: *AST,
        captures: std.ArrayList(*AST),
        _scope: ?*Scope, // Scope used for `match` mappings, rooted in `match`'s scope. Captures, rhs live in this scope
    },
    @"while": struct {
        common: AST_Common,
        _scope: ?*Scope,
        let: ?*AST,
        condition: *AST,
        post: ?*AST,
        _body_block: *AST,
        _else_block: ?*AST,
    },
    @"for": struct {
        common: AST_Common,
        _scope: ?*Scope,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        _body_block: *AST,
        _else_block: ?*AST,
    },
    block: struct {
        common: AST_Common,
        _scope: ?*Scope,
        _statements: std.ArrayList(*AST),
        defers: std.ArrayList(*AST),
        errdefers: std.ArrayList(*AST),
        final: ?*AST, // either `return`, `continue`, or `break`
    },

    // Control-flow statements
    @"break": struct { common: AST_Common },
    @"continue": struct { common: AST_Common },
    @"unreachable": struct { common: AST_Common },
    @"return": struct {
        common: AST_Common,
        _ret_expr: ?*AST,
        _symbol: ?*Symbol, // `retrun`'s must be in functions. This is the function's symbol.
    },
    /// This type is a special version of an identifier. It is needed to encapsulate information about a
    /// symbol declaration that is needed before the symbol is even constructed. An identifier AST cannot be
    /// used for this purpose, because it refers to a symbol _after_ symbol decoration.
    pattern_symbol: struct {
        common: AST_Common,
        name: []const u8,
        kind: Symbol.Kind,
        storage: Symbol.Storage,
        _symbol: ?*Symbol = undefined,
    },
    binding: struct {
        common: AST_Common,
        pattern: *AST, // Pattern of the binding
        type: *Type_AST, // Conceptually, the type for the binding as a whole
        init: ?*AST, // The init value for the binding as a whole. Possible to be null if `undefiend`.
        decls: std.ArrayList(*AST),
    },
    decl: struct {
        common: AST_Common,
        name: *AST, // The pattern symbol AST for this decl. Access the symbol through this
        type: *Type_AST,
        init: ?*AST,
    },
    fn_decl: struct {
        common: AST_Common,
        name: ?*AST, //
        _params: std.ArrayList(*AST), // Parameters' decl ASTs
        _param_symbols: std.ArrayList(*Symbol), // Parameters' symbols
        ret_type: *Type_AST,
        _decl_type: ?*Type_AST = null,
        refinement: ?*AST,
        init: *AST,
        _symbol: ?*Symbol = null,
        infer_error: bool,

        pub fn is_templated(self: *@This()) bool {
            for (self._params.items) |param| {
                if (param.binding.pattern.pattern_symbol.kind == .@"const") {
                    return true;
                }
            }
            return false;
        }

        pub fn remove_const_params(self: *@This()) void {
            var i: usize = 0;
            while (i < self._params.items.len) : (i +%= 1) {
                const param = self._params.items[i];
                if (param.decl.name.pattern_symbol.kind == .@"const") {
                    _ = self._params.orderedRemove(i);
                    i -%= 1;
                }
            }
        }
    },
    struct_decl: struct {
        common: AST_Common,
        name: *AST,
        fields: std.ArrayList(*Type_AST),
        _type: *Type_AST,
        _symbol: ?*Symbol = null,
    },
    enum_decl: struct {
        common: AST_Common,
        name: *AST,
        fields: std.ArrayList(*Type_AST),
        _type: *Type_AST,
        _symbol: ?*Symbol = null,
    },
    type_alias: struct {
        common: AST_Common,
        name: *AST,
        init: ?*Type_AST,
        _symbol: ?*Symbol = null,
    },
    method_decl: struct {
        common: AST_Common,
        name: *AST,
        is_virtual: bool,
        receiver: ?*AST,
        _params: std.ArrayList(*AST), // Parameters' decl ASTs
        _param_symbols: std.ArrayList(*Symbol), // Parameters' symbols
        c_type: ?*Type_AST = null,
        domain: ?*Type_AST = null, // Domain type when calling. Filled in at symbol-tree creation for impls and traits.
        ret_type: *Type_AST,
        _decl_type: ?*Type_AST = null,
        refinement: ?*AST,
        init: ?*AST,
        impl: ?*AST = null, // The surrounding `impl`. Null for method_decls in traits.
        _symbol: ?*Symbol = null,
    },
    @"test": struct {
        common: AST_Common,
        name: ?*AST,
        init: *AST,
        _symbol: ?*Symbol = null,
    },
    module: struct {
        common: AST_Common,
        _scope: ?*Scope, // Only null for compatibility. Always present.
        module: *module_.Module,
    },
    import: struct {
        common: AST_Common,
        pattern: *AST,
    },
    cinclude: struct {
        common: AST_Common,
        _expr: *AST,
    },
    template: struct {
        common: AST_Common,
        decl: *AST, // The decl of the symbol(s) that is being templated
        memo: Type_Map(*Symbol),
        _symbol: ?*Symbol = null, // The symbol for this template
    },
    @"defer": struct { common: AST_Common, _statement: *AST },
    @"errdefer": struct { common: AST_Common, _statement: *AST },

    pub fn create_poison(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .poison = .{ .common = AST_Common{
            ._token = _token,
        } } }, allocator);
    }

    pub fn create_unit_value(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .unit_value = .{ .common = AST_Common{
            ._token = _token,
        } } }, allocator);
    }

    pub fn create_int(_token: Token, data: i128, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .int = .{
            .common = _common,
            .data = data,
        } }, allocator);
    }

    pub fn create_char(
        _token: Token, // `token.data` should of course encompass the `'` used for character delimination. This is unlike strings.
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .char = .{ .common = AST_Common{
            ._token = _token,
        } } }, allocator);
    }

    pub fn create_float(_token: Token, data: f64, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .float = .{
            .common = _common,
            .data = data,
        } }, allocator);
    }

    pub fn create_string(
        _token: Token,
        data: []const u8, // The string's raw utf8 bytes, not containing `"`'s, with escapes escaped
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .string = .{ .common = AST_Common{
            ._token = _token,
        }, .data = data } }, allocator);
    }

    pub fn create_field(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .field = .{ .common = AST_Common{
            ._token = _token,
        } } }, allocator);
    }

    pub fn create_identifier(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .identifier = .{ .common = AST_Common{
            ._token = _token,
        } } }, allocator);
    }

    pub fn create_unreachable(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"unreachable" = .{ .common = AST_Common{
            ._token = _token,
        } } }, allocator);
    }

    pub fn create_true(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .true = .{ .common = AST_Common{
            ._token = _token,
        } } }, allocator);
    }

    pub fn create_false(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .false = .{ .common = AST_Common{
            ._token = _token,
        } } }, allocator);
    }

    pub fn create_not(_token: Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .not = .{
            .common = AST_Common{ ._token = _token },
            ._expr = _expr,
        } }, allocator);
    }

    pub fn create_negate(_token: Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .negate = .{
            .common = AST_Common{ ._token = _token },
            ._expr = _expr,
        } }, allocator);
    }

    pub fn create_dereference(_token: Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .dereference = .{
            .common = AST_Common{ ._token = _token },
            ._expr = _expr,
        } }, allocator);
    }

    pub fn create_try(_token: Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .@"try" = .{ .common = _common, ._expr = _expr, ._symbol = null } }, allocator);
    }

    // pub fn create_comptime(_token: Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
    //     const _common: AST_Common = .{ ._token = _token };
    //     return AST.box(
    //         AST{ .@"comptime" = .{ .common = _common, ._expr = _expr, .name = null } },
    //         allocator,
    //     );
    // }

    pub fn create_default(_token: Token, _expr: *Type_AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .default = .{
            .common = AST_Common{ ._token = _token },
            ._type = _expr,
        } }, allocator);
    }

    pub fn create_size_of(_token: Token, _expr: *Type_AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .size_of = .{
            .common = AST_Common{ ._token = _token },
            ._type = _expr,
        } }, allocator);
    }

    pub fn create_assign(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .assign = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_or(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"or" = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_and(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"and" = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_equal(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .equal = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_not_equal(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .not_equal = .{
            .common = _common,
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_greater(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .greater = .{
            .common = _common,
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_lesser(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .lesser = .{
            .common = _common,
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_greater_equal(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .greater_equal = .{
            .common = _common,
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_lesser_equal(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .lesser_equal = .{
            .common = _common,
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_add(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .add = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_sub(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .sub = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_mult(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .mult = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_div(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .div = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_mod(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .mod = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_catch(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .@"catch" = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_orelse(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .@"orelse" = .{ .common = _common, ._lhs = _lhs, ._rhs = _rhs } }, allocator);
    }

    pub fn create_call(_token: Token, _lhs: *AST, args: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .call = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._args = args,
        } }, allocator);
    }

    pub fn create_bit_and(_token: Token, args: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .bit_and = .{
            .common = AST_Common{ ._token = _token },
            ._args = args,
        } }, allocator);
    }

    pub fn create_bit_or(_token: Token, args: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .bit_or = .{
            .common = AST_Common{ ._token = _token },
            ._args = args,
        } }, allocator);
    }

    pub fn create_bit_xor(_token: Token, args: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .bit_xor = .{
            .common = AST_Common{ ._token = _token },
            ._args = args,
        } }, allocator);
    }

    pub fn create_bit_not(_token: Token, _expr: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .bit_not = .{
            .common = AST_Common{ ._token = _token },
            ._expr = _expr,
        } }, allocator);
    }

    pub fn create_left_shift(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .left_shift = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_right_shift(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .right_shift = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_index(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .index = .{
            .common = AST_Common{ ._token = _token },
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_select(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .select = .{
            .common = _common,
            ._lhs = _lhs,
            ._rhs = _rhs,
            ._pos = null,
        } }, allocator);
    }

    pub fn create_access(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .access = .{
            .common = _common,
            ._lhs = _lhs,
            ._rhs = _rhs,
        } }, allocator);
    }

    pub fn create_enum_value(_token: Token, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .enum_value = .{ .common = _common } }, allocator);
    }

    pub fn create_trait(
        _token: Token,
        method_decls: std.ArrayList(*AST),
        const_decls: std.ArrayList(*AST),
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .trait = .{
            .common = AST_Common{ ._token = _token },
            .method_decls = method_decls,
            .const_decls = const_decls,
        } }, allocator);
    }

    pub fn create_impl(
        _token: Token,
        _trait: ?*AST,
        _type: *Type_AST,
        method_defs: std.ArrayList(*AST),
        const_defs: std.ArrayList(*AST),
        with_decls: std.ArrayList(*AST),
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .impl = .{
                .common = AST_Common{ ._token = _token },
                .trait = _trait,
                ._type = _type,
                .method_defs = method_defs,
                .const_defs = const_defs,
                .with_decls = with_decls,
                .instantiations = Type_Map(*AST).init(allocator),
            } },
            allocator,
        );
    }

    pub fn create_invoke(
        _token: Token,
        _lhs: *AST,
        _rhs: *AST,
        args: std.ArrayList(*AST),
        allocator: std.mem.Allocator,
    ) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .invoke = .{
            .common = _common,
            ._lhs = _lhs,
            ._rhs = _rhs,
            ._args = args,
        } }, allocator);
    }

    pub fn create_dyn_value(
        _token: Token,
        dyn_type: *Type_AST,
        _expr: *AST,
        _scope: *Scope,
        _mut: bool,
        allocator: std.mem.Allocator,
    ) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .dyn_value = .{
            .common = _common,
            .dyn_type = dyn_type,
            ._expr = _expr,
            ._scope = _scope,
            .mut = _mut,
        } }, allocator);
    }

    pub fn create_struct_value(_token: Token, parent: *Type_AST, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .struct_value = .{
            .common = AST_Common{ ._token = _token },
            .parent = parent,
            ._terms = terms,
            .was_slice = false,
        } }, allocator);
    }

    pub fn create_tuple_value(_token: Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .tuple_value = .{
            .common = AST_Common{ ._token = _token },
            ._terms = terms,
        } }, allocator);
    }

    pub fn create_array_value(_token: Token, terms: std.ArrayList(*AST), allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .array_value = .{
            .common = AST_Common{ ._token = _token },
            ._terms = terms,
        } }, allocator);
    }

    pub fn create_addr_of(_token: Token, _expr: *AST, _mut: bool, multiptr: bool, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .addr_of = .{
            .common = _common,
            ._expr = _expr,
            .mut = _mut,
            .multiptr = multiptr,
        } }, allocator);
    }

    pub fn create_slice_of(_token: Token, _expr: *AST, _mut: bool, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .slice_of = .{
            .common = _common,
            ._expr = _expr,
            .mut = _mut,
        } }, allocator);
    }

    pub fn create_sub_slice(
        _token: Token,
        super: *AST,
        lower: ?*AST,
        upper: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(AST{ .sub_slice = .{
            .common = _common,
            .super = super,
            .lower = lower,
            .upper = upper,
        } }, allocator);
    }

    pub fn create_receiver(_token: Token, kind: Receiver_Kind, allocator: std.mem.Allocator) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(
            AST{ .receiver = .{ .common = _common, .kind = kind } },
            allocator,
        );
    }

    pub fn create_if(
        _token: Token,
        let: ?*AST,
        condition: *AST,
        _body_block: *AST,
        _else_block: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        const _common: AST_Common = .{ ._token = _token };
        return AST.box(
            AST{ .@"if" = .{
                .common = _common,
                ._scope = null,
                .let = let,
                .condition = condition,
                ._body_block = _body_block,
                ._else_block = _else_block,
            } },
            allocator,
        );
    }

    pub fn create_match(
        _token: Token,
        let: ?*AST,
        _expr: *AST,
        mappings: std.ArrayList(*AST),
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .match = .{
                .common = AST_Common{ ._token = _token },
                ._scope = null,
                .let = let,
                ._expr = _expr,
                ._mappings = mappings,
            } },
            allocator,
        );
    }

    pub fn create_mapping(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .mapping = .{
                .common = AST_Common{ ._token = _token },
                ._lhs = _lhs,
                ._rhs = _rhs,
                ._scope = null,
                .captures = std.ArrayList(*AST).init(allocator),
            } },
            allocator,
        );
    }

    pub fn create_while(
        _token: Token,
        let: ?*AST,
        condition: *AST,
        post: ?*AST,
        _body_block: *AST,
        _else_block: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .@"while" = .{
                .common = AST_Common{ ._token = _token },
                ._scope = null,
                .let = let,
                .condition = condition,
                .post = post,
                ._body_block = _body_block,
                ._else_block = _else_block,
            } },
            allocator,
        );
    }

    pub fn create_for(
        _token: Token,
        let: ?*AST,
        elem: *AST,
        iterable: *AST,
        _body_block: *AST,
        _else_block: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .@"for" = .{
                .common = AST_Common{ ._token = _token },
                ._scope = null,
                .let = let,
                .elem = elem,
                .iterable = iterable,
                ._body_block = _body_block,
                ._else_block = _else_block,
            } },
            allocator,
        );
    }

    pub fn create_block(
        _token: Token,
        statements: std.ArrayList(*AST),
        final: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        if (final) |_final| {
            std.debug.assert(_final.* == .@"return" or _final.* == .@"continue" or _final.* == .@"break");
        }
        return AST.box(
            AST{ .block = .{
                .common = AST_Common{ ._token = _token },
                ._scope = null,
                ._statements = statements,
                .defers = std.ArrayList(*AST).init(allocator),
                .errdefers = std.ArrayList(*AST).init(allocator),
                .final = final,
            } },
            allocator,
        );
    }

    pub fn create_break(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{
            .@"break" = .{ .common = AST_Common{ ._token = _token } },
        }, allocator);
    }

    pub fn create_continue(_token: Token, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"continue" = .{
            .common = AST_Common{ ._token = _token },
        } }, allocator);
    }

    pub fn create_return(_token: Token, _ret_expr: ?*AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .@"return" = .{
                .common = AST_Common{ ._token = _token },
                ._ret_expr = _ret_expr,
                ._symbol = null,
            } },
            allocator,
        );
    }

    pub fn create_pattern_symbol(
        _token: Token,
        kind: Symbol.Kind,
        storage: Symbol.Storage,
        name: []const u8,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .pattern_symbol = .{
                .common = AST_Common{ ._token = _token },
                .kind = kind,
                .storage = storage,
                .name = name,
            } },
            allocator,
        );
    }

    pub fn create_binding(
        _token: Token,
        pattern: *AST,
        _type: *Type_AST,
        init: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(
            AST{ .binding = .{
                .common = AST_Common{ ._token = _token },
                .pattern = pattern,
                .type = _type,
                .init = init,
                .decls = std.ArrayList(*AST).init(allocator),
            } },
            allocator,
        );
    }

    pub fn create_decl(
        _token: Token,
        name: *AST,
        _type: *Type_AST,
        init: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        std.debug.assert(name.* == .pattern_symbol);
        return AST.box(
            AST{ .decl = .{
                .common = AST_Common{ ._token = _token },
                .name = name,
                .type = _type,
                .init = init,
            } },
            allocator,
        );
    }

    pub fn create_fn_decl(
        _token: Token,
        name: ?*AST,
        params: std.ArrayList(*AST),
        ret_type: *Type_AST,
        refinement: ?*AST,
        init: *AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .fn_decl = .{
            .common = AST_Common{ ._token = _token },
            .name = name,
            ._params = params,
            ._param_symbols = std.ArrayList(*Symbol).init(allocator),
            .ret_type = ret_type,
            .refinement = refinement,
            .init = init,
            .infer_error = false,
        } }, allocator);
    }

    pub fn create_struct_decl(
        _token: Token,
        name: *AST,
        fields: std.ArrayList(*Type_AST),
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .struct_decl = .{
            .common = AST_Common{ ._token = _token },
            .name = name,
            .fields = fields,
            ._type = Type_AST.create_struct_type(_token, fields, allocator),
        } }, allocator);
    }

    pub fn create_enum_decl(
        _token: Token,
        name: *AST,
        fields: std.ArrayList(*Type_AST),
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .enum_decl = .{
            .common = AST_Common{ ._token = _token },
            .name = name,
            .fields = fields,
            ._type = Type_AST.create_enum_type(_token, fields, allocator),
        } }, allocator);
    }

    pub fn create_type_alias(
        _token: Token,
        name: *AST,
        init: ?*Type_AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .type_alias = .{
            .common = AST_Common{ ._token = _token },
            .name = name,
            .init = init,
        } }, allocator);
    }

    pub fn create_method_decl(
        _token: Token,
        name: *AST,
        is_virtual: bool,
        receiver: ?*AST,
        params: std.ArrayList(*AST),
        ret_type: *Type_AST,
        refinement: ?*AST,
        init: ?*AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .method_decl = .{
            .common = AST_Common{ ._token = _token },
            .name = name,
            .is_virtual = is_virtual,
            .receiver = receiver,
            ._params = params,
            ._param_symbols = std.ArrayList(*Symbol).init(allocator),
            .ret_type = ret_type,
            .refinement = refinement,
            .init = init,
        } }, allocator);
    }

    pub fn create_test(
        _token: Token,
        name: ?*AST,
        init: *AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .@"test" = .{
            .common = AST_Common{ ._token = _token },
            .name = name,
            .init = init,
        } }, allocator);
    }

    pub fn create_module(
        _token: Token,
        _scope: *Scope,
        module: *module_.Module,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .module = .{
            .common = AST_Common{ ._token = _token },
            ._scope = _scope,
            .module = module,
        } }, allocator);
    }

    pub fn create_import(
        _token: Token,
        pattern: *AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .import = .{
            .common = AST_Common{ ._token = _token },
            .pattern = pattern,
        } }, allocator);
    }

    pub fn create_cinclude(
        _token: Token,
        _expr: *AST,
        allocator: std.mem.Allocator,
    ) *AST {
        return AST.box(AST{ .cinclude = .{
            .common = AST_Common{ ._token = _token },
            ._expr = _expr,
        } }, allocator);
    }

    pub fn create_defer(_token: Token, _statement: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(AST{ .@"defer" = .{
            .common = AST_Common{ ._token = _token },
            ._statement = _statement,
        } }, allocator);
    }

    pub fn create_errdefer(_token: Token, _statement: *AST, allocator: std.mem.Allocator) *AST {
        return AST.box(
            AST{ .@"errdefer" = .{
                .common = AST_Common{ ._token = _token },
                ._statement = _statement,
            } },
            allocator,
        );
    }

    pub fn clone(self: *AST, substs: *unification_.Substitutions, allocator: std.mem.Allocator) *AST {
        switch (self.*) {
            .poison => unreachable,
            .unit_value => return create_unit_value(self.token(), allocator),
            .int => return create_int(self.token(), self.int.data, allocator),
            .char => return create_char(self.token(), allocator),
            .float => return create_float(self.token(), self.float.data, allocator),
            .string => return create_string(self.token(), self.string.data, allocator),
            .field => return create_field(self.token(), allocator),
            .identifier => return create_identifier(self.token(), allocator),
            .@"unreachable" => return create_unreachable(self.token(), allocator),
            .true => return create_true(self.token(), allocator),
            .false => return create_false(self.token(), allocator),

            .template => unreachable, // TODO: You probably want this...

            .not => return create_not(self.token(), self.expr().clone(substs, allocator), allocator),
            .negate => return create_negate(self.token(), self.expr().clone(substs, allocator), allocator),
            .dereference => return create_dereference(
                self.token(),
                self.expr().clone(substs, allocator),
                allocator,
            ),
            .@"try" => return create_try(self.token(), self.expr().clone(substs, allocator), allocator),
            .default => return create_default(self.token(), self.default._type.clone(substs, allocator), allocator),
            .size_of => return create_size_of(self.token(), self.size_of._type.clone(substs, allocator), allocator),
            // .@"comptime" => return create_comptime(self.token(), self.expr().clone(substs, allocator), allocator),

            .assign => return create_assign(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .@"or" => return create_or(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .@"and" => return create_and(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .add => return create_add(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .sub => return create_sub(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .mult => return create_mult(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .div => return create_div(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .mod => return create_mod(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .equal => return create_equal(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .not_equal => return create_not_equal(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .greater => return create_greater(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .lesser => return create_lesser(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .greater_equal => return create_greater_equal(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .lesser_equal => return create_lesser_equal(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .@"catch" => return create_catch(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .@"orelse" => return create_orelse(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .call => {
                const cloned_args = clone_children(self.children().*, substs, allocator);
                return create_call(self.token(), self.lhs().clone(substs, allocator), cloned_args, allocator);
            },
            .bit_and => {
                const cloned_args = clone_children(self.children().*, substs, allocator);
                return create_bit_and(self.token(), cloned_args, allocator);
            },
            .bit_or => {
                const cloned_args = clone_children(self.children().*, substs, allocator);
                return create_bit_or(self.token(), cloned_args, allocator);
            },
            .bit_xor => {
                const cloned_args = clone_children(self.children().*, substs, allocator);
                return create_bit_xor(self.token(), cloned_args, allocator);
            },
            .bit_not => return create_bit_not(self.token(), self.expr().clone(substs, allocator), allocator),
            .left_shift => return create_left_shift(self.token(), self.lhs().clone(substs, allocator), self.rhs().clone(substs, allocator), allocator),
            .right_shift => return create_right_shift(self.token(), self.lhs().clone(substs, allocator), self.rhs().clone(substs, allocator), allocator),
            .index => return create_index(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .select => return create_select(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .access => return create_access(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .trait => {
                const cloned_method_decls = clone_children(self.trait.method_decls, substs, allocator);
                const cloned_const_decls = clone_children(self.trait.const_decls, substs, allocator);
                var retval = create_trait(
                    self.token(),
                    cloned_method_decls,
                    cloned_const_decls,
                    allocator,
                );
                retval.set_symbol(self.symbol());
                retval.set_scope(self.scope());
                return retval;
            },
            .impl => {
                const cloned_method_defs = clone_children(self.impl.method_defs, substs, allocator);
                const cloned_const_defs = clone_children(self.impl.const_defs, substs, allocator);
                const cloned_with_decls = clone_children(self.impl.with_decls, substs, allocator);
                var retval = create_impl(
                    self.token(),
                    if (self.impl.trait) |_trait| _trait.clone(substs, allocator) else null,
                    self.impl._type.clone(substs, allocator),
                    cloned_method_defs,
                    cloned_const_defs,
                    cloned_with_decls,
                    allocator,
                );
                retval.impl.impls_anon_trait = self.impl.impls_anon_trait;
                retval.set_scope(self.scope());
                return retval;
            },
            .invoke => {
                const cloned_args = clone_children(self.children().*, substs, allocator);
                return create_invoke(
                    self.token(),
                    self.lhs().clone(substs, allocator),
                    self.rhs().clone(substs, allocator),
                    cloned_args,
                    allocator,
                );
            },
            .dyn_value => unreachable, // Shouldn't exist yet... have to clone scope?
            .enum_value => {
                var retval = create_enum_value(self.token(), allocator);
                retval.enum_value.init = self.enum_value.init;
                return retval;
            },
            .struct_value => {
                const cloned_terms = clone_children(self.children().*, substs, allocator);
                var retval = create_struct_value(
                    self.token(),
                    self.struct_value.parent.clone(substs, allocator),
                    cloned_terms,
                    allocator,
                );
                retval.struct_value.was_slice = self.struct_value.was_slice;
                return retval;
            },
            .tuple_value => {
                const cloned_terms = clone_children(self.children().*, substs, allocator);
                return create_tuple_value(
                    self.token(),
                    cloned_terms,
                    allocator,
                );
            },
            .array_value => {
                const cloned_terms = clone_children(self.children().*, substs, allocator);
                return create_array_value(
                    self.token(),
                    cloned_terms,
                    allocator,
                );
            },
            .struct_decl => {
                const cloned_terms = Type_AST.clone_types(self.struct_decl.fields, substs, allocator);
                var retval = create_struct_decl(
                    self.token(),
                    self.struct_decl.name.clone(substs, allocator),
                    cloned_terms, // TODO: clone types
                    allocator,
                );
                retval.set_symbol(self.symbol());
                return retval;
            },
            .enum_decl => {
                const cloned_terms = Type_AST.clone_types(self.enum_decl.fields, substs, allocator);
                var retval = create_enum_decl(
                    self.token(),
                    self.enum_decl.name.clone(substs, allocator),
                    cloned_terms,
                    allocator,
                );
                retval.set_symbol(self.symbol());
                return retval;
            },
            .type_alias => {
                var retval = create_type_alias(
                    self.token(),
                    self.type_alias.name.clone(substs, allocator),
                    if (self.type_alias.init == null) null else self.type_alias.init.?.clone(substs, allocator),
                    allocator,
                );
                retval.set_symbol(self.symbol());
                return retval;
            },
            .addr_of => return create_addr_of(
                self.token(),
                self.expr().clone(substs, allocator),
                self.mut(),
                self.addr_of.multiptr,
                allocator,
            ),
            .slice_of => return create_slice_of(
                self.token(),
                self.expr().clone(substs, allocator),
                self.slice_of.mut,
                allocator,
            ),
            .sub_slice => return create_sub_slice(
                self.token(),
                self.sub_slice.super.clone(substs, allocator),
                if (self.sub_slice.lower) |lower| lower.clone(substs, allocator) else null,
                if (self.sub_slice.upper) |upper| upper.clone(substs, allocator) else null,
                allocator,
            ),
            .receiver => return create_receiver(
                self.token(),
                self.receiver.kind,
                allocator,
            ),

            .@"if" => {
                var retval = create_if(
                    self.token(),
                    if (self.@"if".let) |let| let.clone(substs, allocator) else null,
                    self.@"if".condition.clone(substs, allocator),
                    self.body_block().clone(substs, allocator),
                    if (self.else_block()) |_else| _else.clone(substs, allocator) else null,
                    allocator,
                );
                retval.set_scope(self.scope());
                return retval;
            },
            .match => {
                const cloned_mappings = clone_children(self.children().*, substs, allocator);
                var retval = create_match(
                    self.token(),
                    if (self.match.let) |let| let.clone(substs, allocator) else null,
                    self.expr().clone(substs, allocator),
                    cloned_mappings,
                    allocator,
                );
                retval.set_scope(self.scope());
                return retval;
            },
            .mapping => return create_mapping(
                self.token(),
                self.lhs().clone(substs, allocator),
                self.rhs().clone(substs, allocator),
                allocator,
            ),
            .@"while" => {
                var retval = create_while(
                    self.token(),
                    if (self.@"while".let) |let| let.clone(substs, allocator) else null,
                    self.@"while".condition.clone(substs, allocator),
                    if (self.@"while".post) |post| post.clone(substs, allocator) else null,
                    self.body_block().clone(substs, allocator),
                    if (self.else_block()) |_else| _else.clone(substs, allocator) else null,
                    allocator,
                );
                retval.set_scope(self.scope());
                return retval;
            },
            .@"for" => unreachable, // TODO
            .block => {
                const cloned_statements = clone_children(self.children().*, substs, allocator);
                var retval = create_block(
                    self.token(),
                    cloned_statements,
                    if (self.block.final) |final| final.clone(substs, allocator) else null,
                    allocator,
                );
                retval.set_scope(self.scope());
                return retval;
            },
            .@"break" => return create_break(self.token(), allocator),
            .@"continue" => return create_continue(self.token(), allocator),
            .@"return" => return create_return(
                self.token(),
                if (self.@"return"._ret_expr) |ret_expr| ret_expr.clone(substs, allocator) else null,
                allocator,
            ),
            .pattern_symbol => return create_pattern_symbol(
                self.token(),
                self.pattern_symbol.kind,
                self.pattern_symbol.storage,
                self.pattern_symbol.name,
                allocator,
            ),
            .binding => return create_binding(
                self.token(),
                self.binding.pattern,
                self.binding.type,
                self.binding.init,
                allocator,
            ),
            .decl => return create_decl(
                self.token(),
                self.decl.name.clone(substs, allocator),
                self.decl.type.clone(substs, allocator),
                if (self.decl.init) |init| init.clone(substs, allocator) else null,
                allocator,
            ),
            .fn_decl => {
                const cloned_params = clone_children(self.children().*, substs, allocator);
                var retval = create_fn_decl(
                    self.token(),
                    if (self.fn_decl.name) |name| name.clone(substs, allocator) else null,
                    cloned_params,
                    self.fn_decl.ret_type.clone(substs, allocator),
                    if (self.fn_decl.refinement) |refinement| refinement.clone(substs, allocator) else null,
                    self.fn_decl.init.clone(substs, allocator),
                    allocator,
                );
                retval.set_symbol(self.symbol());
                return retval;
            },
            .method_decl => {
                const cloned_params = clone_children(self.children().*, substs, allocator);
                var retval = create_method_decl(
                    self.token(),
                    self.method_decl.name.clone(substs, allocator),
                    self.method_decl.is_virtual,
                    if (self.method_decl.receiver) |receiver| receiver.clone(substs, allocator) else null,
                    cloned_params,
                    self.method_decl.ret_type.clone(substs, allocator),
                    if (self.method_decl.refinement) |refinement| refinement.clone(substs, allocator) else null,
                    if (self.method_decl.init) |init| init.clone(substs, allocator) else null,
                    allocator,
                );
                retval.method_decl.impl = self.method_decl.impl;
                retval.method_decl.domain = self.method_decl.domain;
                retval.set_symbol(self.symbol());
                return retval;
            },
            .@"test" => return create_test(
                self.token(),
                self.@"test".name,
                self.@"test".init,
                allocator,
            ),
            .import => return create_import(self.token(), self.import.pattern.clone(substs, allocator), allocator),
            .cinclude => return create_cinclude(self.token(), self.cinclude._expr.clone(substs, allocator), allocator),
            .module => return create_module(self.token(), self.scope().?, self.module.module, allocator),
            .@"defer" => return create_defer(self.token(), self.statement().clone(substs, allocator), allocator),
            .@"errdefer" => return create_errdefer(self.token(), self.statement().clone(substs, allocator), allocator),
        }
    }

    pub fn clone_children(children_terms: std.ArrayList(*AST), substs: *unification_.Substitutions, allocator: std.mem.Allocator) std.ArrayList(*AST) {
        var retval = std.ArrayList(*AST).init(allocator);
        for (children_terms.items) |child| {
            retval.append(child.clone(substs, allocator)) catch unreachable;
        }
        return retval;
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

    pub fn token(self: *AST) Token {
        return self.common()._token;
    }

    pub fn expr(self: AST) *AST {
        return get_struct_field(self, "_expr");
    }

    pub fn set_expr(self: *AST, val: *AST) void {
        set_field(self, "_expr", val);
    }

    pub fn @"type"(self: *AST) *Type_AST {
        return switch (self.*) {
            .size_of => self.size_of._type,
            .default => self.default._type,
            else => std.debug.panic("can't call type on {s}\n", .{@tagName(self.*)}),
        };
    }

    pub fn symbol(self: AST) ?*Symbol {
        return get_struct_field(self, "_symbol");
    }

    pub fn set_symbol(self: *AST, val: ?*Symbol) void {
        set_field(self, "_symbol", val);
    }

    pub fn scope(self: AST) ?*Scope {
        return get_struct_field(self, "_scope");
    }

    pub fn set_scope(self: *AST, val: ?*Scope) void {
        set_field(self, "_scope", val);
    }

    pub fn lhs(self: AST) *AST {
        return get_struct_field(self, "_lhs");
    }

    pub fn set_lhs(self: *AST, val: *AST) void {
        set_field(self, "_lhs", val);
    }

    pub fn rhs(self: AST) *AST {
        return get_struct_field(self, "_rhs");
    }

    pub fn set_rhs(self: *AST, val: *AST) void {
        set_field(self, "_rhs", val);
    }

    pub fn children(self: *AST) *std.ArrayList(*AST) {
        return switch (self.*) {
            .call => &self.call._args,
            .struct_value => &self.struct_value._terms,
            .tuple_value => &self.tuple_value._terms,
            .array_value => &self.array_value._terms,
            .match => &self.match._mappings,
            .block => &self.block._statements,
            .fn_decl => &self.fn_decl._params,
            .method_decl => &self.method_decl._params,
            .invoke => &self.invoke._args,
            .bit_and => &self.bit_and._args,
            .bit_or => &self.bit_or._args,
            .bit_xor => &self.bit_xor._args,
            .binding => &self.binding.decls,
            else => std.debug.panic("compiler error: cannot call `.children()` on the AST `{}`", .{self.*}),
        };
    }

    pub fn set_children(self: *AST, val: std.ArrayList(*AST)) void {
        switch (self.*) {
            .call => self.call._args = val,
            .struct_value => self.struct_value._terms = val,
            .tuple_value => self.tuple_value._terms = val,
            .array_value => self.array_value._terms = val,
            .match => self.match._mappings = val,
            .block => self.block._statements = val,
            .fn_decl => self.fn_decl._params = val,
            .method_decl => self.method_decl._params = val,
            .invoke => self.invoke._args = val,
            .bit_and => self.bit_and._args = val,
            .bit_or => self.bit_or._args = val,
            .bit_xor => self.bit_xor._args = val,
            .binding => self.binding.decls = val,
            else => std.debug.panic("compiler error: cannot call `.set_children()` on the AST `{s}`", .{@tagName(self.*)}),
        }
    }

    pub fn decl_type(self: *AST) *Type_AST {
        return switch (self.*) {
            .decl => self.decl.type,
            .fn_decl => self.fn_decl._decl_type.?,
            .method_decl => self.method_decl._decl_type.?,
            .@"test" => core_.test_type,
            .module, .trait => prelude_.unit_type,
            .receiver => self.receiver._type.?,
            else => std.debug.panic("compiler error: cannot call `.decl_type()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn decl_init(self: *AST) ?*AST {
        return switch (self.*) {
            .decl => self.decl.init,
            .fn_decl => self.fn_decl.init,
            .method_decl => self.method_decl.init,
            .@"test" => self.@"test".init,
            .module, .trait => self,
            .struct_decl, .enum_decl, .type_alias, .receiver => null,
            else => std.debug.panic("compiler error: cannot call `.decl_init()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn set_decl_init(self: *AST, init: *AST) void {
        return switch (self.*) {
            .decl => self.decl.init = init,
            .fn_decl => self.fn_decl.init = init,
            .method_decl => self.method_decl.init = init,
            .@"test" => self.@"test".init = init,
            .trait => self.* = init.*,
            .module => {},
            else => std.debug.panic("compiler error: cannot call `.set_decl_init()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn decl_typedef(self: *AST) ?*Type_AST {
        return switch (self.*) {
            .struct_decl => self.struct_decl._type,
            .enum_decl => self.enum_decl._type,
            .type_alias => self.type_alias.init,
            else => std.debug.panic("compiler error: cannot call `.decl_typedef()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn decl_name(self: *AST) *AST {
        return switch (self.*) {
            .struct_decl => self.struct_decl.name,
            .enum_decl => self.enum_decl.name,
            .type_alias => self.type_alias.name,
            else => std.debug.panic("compiler error: cannot call `.decl_name()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn param_symbols(self: *AST) ?*std.ArrayList(*Symbol) {
        return switch (self.*) {
            .fn_decl => &self.fn_decl._param_symbols,
            .method_decl => &self.method_decl._param_symbols,
            .@"test" => null,
            else => std.debug.panic("compiler error: cannot call `.param_symbols()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn top_level(self: *AST) bool {
        return switch (self.*) {
            .decl => false,
            .fn_decl, .method_decl, .@"test" => true,
            else => std.debug.panic("compiler error: cannot call `.top_level()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn get_field(self: *AST, _type: *Type_AST, field_name: []const u8) *AST {
        for (0.., _type.children().items) |i, child| {
            if (child.* == .annotation and std.mem.eql(u8, field_name, child.annotation.pattern.token().data)) {
                return self.children().items[i];
            }
        }
        std.debug.panic("compiler error: {s} didn't have field `{s}`", .{ @tagName(self.*), field_name });
    }

    pub fn pos(self: AST) ?usize {
        return get_struct_field(self, "_pos");
    }

    pub fn set_pos(self: *AST, val: ?usize) void {
        set_field(self, "_pos", val);
    }

    pub fn statement(self: AST) *AST {
        return get_struct_field(self, "_statement");
    }

    pub fn set_statement(self: *AST, val: *AST) void {
        set_field(self, "_statement", val);
    }

    pub fn body_block(self: AST) *AST {
        return get_struct_field(self, "_body_block");
    }

    pub fn set_body_block(self: *AST, val: *AST) void {
        set_field(self, "_body_block", val);
    }

    pub fn else_block(self: AST) ?*AST {
        return get_struct_field(self, "_else_block");
    }

    pub fn set_else_block(self: *AST, val: ?*AST) void {
        set_field(self, "_else_block", val);
    }

    pub fn mut(self: AST) bool {
        return get_struct_field(self, "mut");
    }

    pub fn set_mut(self: *AST, val: bool) void {
        set_field(self, "mut", val);
    }

    /// Returns the type of the field with a given name in a Zig union type
    fn Unwrapped(comptime Union: type, comptime field: []const u8) type {
        return inline for (std.meta.fields(Union)) |variant| {
            const Struct = variant.type;
            const s: Struct = undefined;
            if (@hasField(Struct, field)) break @TypeOf(@field(s, field));
        } else @compileError("No such field in any of the variants!");
    }

    /// Generically retrieve the value of a field in a Zig union type
    fn get_struct_field(u: anytype, comptime field: []const u8) Unwrapped(@TypeOf(u), field) {
        return switch (u) {
            inline else => |v| if (@hasField(@TypeOf(v), field)) @field(v, field) else error.NoField,
        } catch {
            std.debug.panic("compiler error: `{s}` does not have field `{s}` {}", .{ @tagName(u), field, Unwrapped(@TypeOf(u), field) });
        };
    }

    /// Generically retrieve a reference to a field in a Zig union type
    fn get_field_ref(u: anytype, comptime field: []const u8) *Unwrapped(@TypeOf(u.*), field) {
        return switch (u.*) {
            inline else => |*v| &@field(v, field),
        };
    }

    /// Generically set a field in a Zig union type
    fn set_field(u: anytype, comptime field: []const u8, val: Unwrapped(@TypeOf(u.*), field)) void {
        switch (u.*) {
            inline else => |*v| if (@hasField(@TypeOf(v.*), field)) {
                @field(v, field) = val;
            } else {
                std.debug.panic("compiler error: `{s}` does not have field `{s}`", .{ @tagName(u.*), field });
            },
        }
    }

    // Expr must be an array value of length `l`. Slice value is `(&expr[0], l)`.
    pub fn create_slice_value(_expr: *AST, _mut: bool, expr_type: *Type_AST, allocator: std.mem.Allocator) *AST {
        var new_terms = std.ArrayList(*AST).init(allocator);
        const zero = (AST.create_int(_expr.token(), 0, allocator)).assert_ast_valid();
        const index = (AST.create_index(
            _expr.token(),
            _expr,
            zero,
            allocator,
        )).assert_ast_valid();
        const addr = (AST.create_addr_of(
            _expr.token(),
            index,
            _mut,
            true,
            allocator,
        )).assert_ast_valid();
        new_terms.append(addr) catch unreachable;

        const length = expr_type.array_of.len;
        new_terms.append(length) catch unreachable;

        const array_type = _expr.typeof(allocator);
        const elem_type = array_type.child();
        const slice_type = Type_AST.create_slice_type(elem_type, _mut, allocator);
        var retval = AST.create_struct_value(_expr.token(), slice_type, new_terms, allocator);
        retval.struct_value.was_slice = true;
        return retval;
    }

    pub fn create_some_value(opt_type: *Type_AST, value: *AST, allocator: std.mem.Allocator) *AST {
        const member = create_enum_value(value.token(), allocator);
        member.enum_value.base = opt_type;
        member.enum_value.init = value;
        member.set_pos(opt_type.get_pos("some"));
        return member.assert_ast_valid();
    }

    pub fn create_none_value(opt_type: *Type_AST, allocator: std.mem.Allocator) *AST {
        const member = create_enum_value(Token.init_simple("none"), allocator);
        member.enum_value.base = opt_type;
        member.set_pos(opt_type.get_pos("none"));
        return member.assert_ast_valid();
    }

    pub fn create_binop(_token: Token, _lhs: *AST, _rhs: *AST, allocator: std.mem.Allocator) *AST {
        switch (_token.kind) {
            .plus_equals => return create_add(_token, _lhs, _rhs, allocator),
            .minus_equals => return create_sub(_token, _lhs, _rhs, allocator),
            .star_equals => return create_mult(_token, _lhs, _rhs, allocator),
            .slash_equals => return create_div(_token, _lhs, _rhs, allocator),
            .percent_equals => return create_mod(_token, _lhs, _rhs, allocator),
            else => std.debug.panic("compiler error: {s} is not a operator-assign token", .{@tagName(_token.kind)}),
        }
    }

    /// Determines if an AST expression can be evaluated at compile-time without having to specify a `comptime`
    /// keyword.
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

    /// Used to poison an AST node. Marks as valid, so any attempt to validate is memoized to return poison.
    pub fn enpoison(self: *AST) void {
        self.common().validation_state = .invalid;
    }

    /// Sets an ASTs validation status to valid.
    pub fn assert_ast_valid(self: *AST) *AST {
        self.common().validation_state = .valid;
        return self;
    }

    // TODO: Use Tree Writer, don't call writer print, recursively call pprint
    pub fn pprint(self: AST, allocator: std.mem.Allocator) ![]const u8 {
        var out = String.init(allocator);
        defer out.deinit();

        switch (self) {
            .poison => try out.writer().print("poison", .{}),
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
            .default => {
                try out.writer().print("default(", .{});
                try self.default._type.print_type(out.writer());
                try out.writer().print(")", .{});
            },
            .size_of => try out.writer().print("size_of({})", .{self.expr()}),
            // .@"comptime" => try out.writer().print("comptime({})", .{self.expr()}),

            .assign => {
                try out.writer().print("assign({}, {})", .{ self.lhs(), self.rhs() });
            },
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
            .call => {
                try out.writer().print("call(lhs={},args=[", .{self.call._lhs});
                for (self.call._args.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.call._args.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print("])", .{});
            },
            .bit_and => {
                try out.writer().print("@bit_and(", .{});
                for (self.call._args.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.call._args.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },
            .bit_or => {
                try out.writer().print("@bit_or(", .{});
                for (self.call._args.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.call._args.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },
            .bit_xor => {
                try out.writer().print("@bit_xor(", .{});
                for (self.call._args.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.call._args.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },
            .bit_not => try out.writer().print("@bit_not({})", .{self.expr()}),
            .left_shift => try out.writer().print("@left_shift({}, {})", .{ self.lhs(), self.rhs() }),
            .right_shift => try out.writer().print("@right_shift({}, {})", .{ self.lhs(), self.rhs() }),
            .index => try out.writer().print("index({}, {})", .{ self.lhs(), self.rhs() }),
            .select => {
                try out.writer().print("select({},{})", .{ self.lhs(), self.rhs() });
            },
            .access => {
                try out.writer().print("access({},{})", .{ self.lhs(), self.rhs() });
            },
            .trait => try out.writer().print("trait({*})", .{if (self.symbol() != null) self.symbol() else null}),
            .impl => try out.writer().print("impl(.trait={?}, .type={})", .{ self.impl.trait, self.impl._type }),
            .invoke => try out.writer().print("invoke()", .{}),
            .dyn_value => try out.writer().print("dyn_value()", .{}),
            .enum_value => {
                try out.writer().print("enum_value(.name={s}, .init={?}, .tag={?})", .{ self.enum_value.get_name(), self.enum_value.init, self.enum_value._pos });
            },
            .struct_decl => {
                try out.writer().print("struct()", .{});
            },
            .enum_decl => {
                try out.writer().print("enum()", .{});
            },
            .type_alias => {
                try out.writer().print("type_alias()", .{});
            },
            .struct_value => {
                try out.writer().print("struct_value(", .{});
                for (self.struct_value._terms.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.struct_value._terms.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },
            .tuple_value => {
                try out.writer().print("tuple_value(", .{});
                for (self.tuple_value._terms.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.tuple_value._terms.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },
            .array_value => {
                try out.writer().print("array_value(", .{});
                for (self.array_value._terms.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.array_value._terms.items.len - 1) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print(")", .{});
            },

            .addr_of => try out.writer().print("addr_of({})", .{self.expr()}),
            .slice_of => try out.writer().print("slice_of()", .{}),
            .sub_slice => try out.writer().print("sub_slice()", .{}),
            .receiver => try out.writer().print("receiver({s})", .{@tagName(self.receiver.kind)}),

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
            .pattern_symbol => try out.writer().print("pattern_symbol({s}, {s})", .{ @tagName(self.pattern_symbol.kind), self.pattern_symbol.name }),
            .binding => try out.writer().print("binding()", .{}),
            .decl => {
                try out.writer().print("decl(\n", .{});
                try out.writer().print("    .pattern = {},\n", .{self.decl.name});
                try out.writer().print("    .type = {?},\n", .{self.decl.type});
                try out.writer().print("    .init = {?},\n", .{self.decl.init});
                try out.writer().print(")", .{});
            },
            .fn_decl => {
                try out.writer().print("fn_decl(\n", .{});
                try out.writer().print("    .name = {?},\n", .{self.fn_decl.name});
                try out.writer().print("    ._params = [", .{});
                for (self.fn_decl._params.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.fn_decl._params.items.len) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print("],\n", .{});
                try out.writer().print("    .param_symbols = [", .{});
                for (self.fn_decl._param_symbols.items, 0..) |item, i| {
                    try out.writer().print("{}", .{item});
                    if (i < self.fn_decl._param_symbols.items.len) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print("],\n", .{});
                try out.writer().print("    .ret_type = {},\n", .{self.fn_decl.ret_type});
                try out.writer().print("    .refinement = {?},\n", .{self.fn_decl.refinement});
                // try out.writer().print("    .init = {},\n", .{self.fn_decl.init});
                try out.writer().print("    ._symbol = {?},\n", .{self.fn_decl._symbol});
                try out.writer().print("    .infer_error = {},\n", .{self.fn_decl.infer_error});
                try out.writer().print(")", .{});
            },
            .module => try out.writer().print("module()", .{}),
            .import => try out.writer().print("import({})", .{self.import.pattern}),
            .cinclude => try out.writer().print("cinclude({})", .{self.cinclude._expr}),
            .template => try out.writer().print("template()", .{}),
            .method_decl => {
                try out.writer().print("method_decl(.name={s}, .receiver={?}, .params=[", .{
                    self.method_decl.name,
                    self.method_decl.receiver,
                });
                for (self.method_decl._params.items, 0..) |param, i| {
                    try out.writer().print("{}", .{param});
                    if (i < self.method_decl._params.items.len) {
                        try out.writer().print(",", .{});
                    }
                }
                try out.writer().print("])", .{});
            },
            .@"test" => try out.writer().print("test(.name={?})", .{self.@"test".name}),
            .@"defer" => try out.writer().print("defer()", .{}),
            .@"errdefer" => try out.writer().print("errdefer()", .{}),
        }

        return (try out.toOwned()).?;
    }

    pub fn format(self: AST, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = options;
        _ = fmt;
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator); // page alloc ok, immediately deinit'd
        defer arena.deinit();

        // TODO: Generic pprinter that makes the arena and string and passes the writer to a pprint method

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }
};
