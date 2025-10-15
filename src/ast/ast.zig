// TODO: Can this file be split up?? At ALL?
// 1. keep AST union in this file
// 2. `pub using namespace @import("type-check.zig");`
// 3. `pub using namespace @import("type-properties.zig");`
// 4. `pub using namespace @import("validate-ast.zig");`
// 5. `pub using namespace @import("type-representation.zig");`, or a better name, for `can_represent_X`, `is_ord`, etc
// 6. `pub using namespace @import("poisoned-ast.zig");

const std = @import("std");
const Ast_Id = @import("ast_store.zig").Ast_Id;
const module_ = @import("../hierarchy/module.zig");
const alignment_ = @import("../util/alignment.zig");
const core_ = @import("../hierarchy/core.zig");
const poison_ = @import("poison.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Scope = @import("../symbol/scope.zig");
const Span = @import("../util/span.zig");
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const Monomorph_Map = @import("../ast/type_map.zig").Monomorph_Map;
const validation_state_ = @import("../util/validation_state.zig");
const unification_ = @import("../types/unification.zig");
const fmt_ = @import("../util/fmt.zig");

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

/// Represents an Abstract Syntax Tree.
pub const AST = union(enum) {
    poison: struct { _token: Token },
    /// Unit value
    unit_value: struct { _token: Token },
    /// Integer constant
    int: struct {
        _token: Token,
        data: i128,
    },
    /// Floating-point constant
    float: struct {
        _token: Token,
        data: f64,
    },
    /// Character constant
    char: struct { _token: Token },
    /// String constant
    string: struct {
        _token: Token,
        data: []const u8,
    },
    /// True constant
    true: struct { _token: Token },
    /// False constant
    false: struct { _token: Token },
    /// Field
    /// This tag is used for the right-hand-side of selects. They do not refer to symbols.
    field: struct { _token: Token },
    /// Identifier
    identifier: struct {
        _token: Token,
        _symbol: ?*Symbol = null,

        pub inline fn refers_to_template(self: @This()) bool {
            return self._symbol.?.kind == .template;
        }
    },

    not: struct { _token: Token, _expr: Ast_Id },
    negate: struct { _token: Token, _expr: Ast_Id },
    dereference: struct { _token: Token, _expr: Ast_Id },
    @"try": struct {
        _token: Token,
        _expr: Ast_Id,
        _symbol: ?*Symbol, // `try`'s must be in functions. This is the function's symbol.
    },
    @"comptime": struct {
        _token: Token,
        _expr: Ast_Id,
        name: ?Ast_Id = null,
        result: ?Ast_Id = null,
        _scope: ?*Scope = null, // Surrounding scope. Filled in at symbol-tree creation. Used to create a comptime symbol
    },

    // Binary operators
    // TODO: We could de-duplicate this, I suppose.
    assign: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    @"or": struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    @"and": struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    add: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    sub: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    mult: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    div: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    mod: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    equal: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    not_equal: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    greater: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    lesser: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    greater_equal: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    lesser_equal: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    @"catch": struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    @"orelse": struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    call: struct { _token: Token, _lhs: Ast_Id, _args: std.array_list.Managed(Ast_Id) },
    bit_and: struct { _token: Token, _args: std.array_list.Managed(Ast_Id) },
    bit_or: struct { _token: Token, _args: std.array_list.Managed(Ast_Id) },
    bit_xor: struct { _token: Token, _args: std.array_list.Managed(Ast_Id) },
    bit_not: struct { _token: Token, _expr: Ast_Id },
    left_shift: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    right_shift: struct { _token: Token, _lhs: Ast_Id, _rhs: Ast_Id },
    index: struct { _token: Token, _lhs: Ast_Id, _children: std.array_list.Managed(Ast_Id) },
    generic_apply: struct {
        _token: Token,
        _lhs: Ast_Id,
        _children: std.array_list.Managed(*Type_AST),
        _symbol: ?*Symbol = null,
        state: enum { unmorphed, morphing, morphed } = .unmorphed,
    },
    select: struct {
        _token: Token,
        _lhs: Ast_Id,
        _rhs: Ast_Id,
        _pos: ?usize = null,
    },
    access: struct {
        _token: Token,
        _lhs: Ast_Id,
        _rhs: Ast_Id,
        // _pos: ?usize,
        _symbol: ?*Symbol = null,
        _scope: ?*Scope = null, // Surrounding scope. Filled in at symbol-tree creation.
    },
    trait: struct {
        _token: Token,
        method_decls: std.array_list.Managed(Ast_Id),
        const_decls: std.array_list.Managed(Ast_Id),
        num_virtual_methods: i64 = 0,
        _symbol: ?*Symbol = null, // Filled by symbol-tree pass.
        _scope: ?*Scope = null, // Filled by symbol-tree pass.

        pub fn find_method(self: @This(), name: []const u8) ?Ast_Id {
            for (self.method_decls.items) |decl| {
                if (std.mem.eql(u8, decl.method_decl.name.token().data, name)) {
                    return decl;
                }
            }
            return null;
        }
    },
    impl: struct {
        _token: Token,
        trait: ?Ast_Id, // Identifier-like ast which refers to the trait
        _type: *Type_AST, // The `for` type for this impl
        method_defs: std.array_list.Managed(Ast_Id),
        const_defs: std.array_list.Managed(Ast_Id),
        _generic_params: std.array_list.Managed(Ast_Id), // list of annotations
        num_virtual_methods: i64 = 0,
        _scope: ?*Scope = null, // Scope used for `impl` methods, rooted in `impl`'s scope.
        impls_anon_trait: bool = false, // true when this impl implements an anonymous trait
        instantiations: Monomorph_Map(Ast_Id),
    },
    invoke: struct {
        _token: Token,
        _lhs: Ast_Id,
        _rhs: Ast_Id,
        _args: std.array_list.Managed(Ast_Id),
        _scope: ?*Scope = null, // Surrounding scope. Filled in at symbol-tree creation.
        method_decl: ?Ast_Id = null,
        prepended: bool = false, // Whether or not this invoke has already been prepended, so that clones don't re-do that (TODO: Maybe turn invokes into calls?)
    },
    /// A struct-like-value of pointers to the vtable, and to the receiver
    dyn_value: struct {
        _token: Token,
        dyn_type: *Type_AST, // reference to the type of this value, since it is only created using address-ofs
        _expr: Ast_Id,
        mut: bool,
        impl: ?Ast_Id = null, // The implementation AST, whose vtable should be used
        _scope: ?*Scope = null, // Surrounding scope. Filled in when addr-of is converted
    },
    enum_value: struct {
        _token: Token,
        domain: ?*Type_AST = null, // kept in it's annotation form, for compatability with calls
        init: ?Ast_Id = null,
        base: ?*Type_AST = null,
        _pos: ?usize = null,

        pub fn get_name(self: *const @This()) []const u8 {
            return self._token.data;
        }
    },
    struct_value: struct {
        _token: Token,
        parent: *Type_AST,
        _terms: std.array_list.Managed(Ast_Id),
        was_slice: bool,
    },
    tuple_value: struct {
        _token: Token,
        _terms: std.array_list.Managed(Ast_Id),
    },
    array_value: struct {
        _token: Token,
        _terms: std.array_list.Managed(Ast_Id),
    },

    // Fancy operators
    as: struct {
        _token: Token,
        _expr: Ast_Id,
        _type: *Type_AST,
    },
    addr_of: struct {
        _token: Token,
        _expr: Ast_Id,
        mut: bool,
        multiptr: bool = false,
        anytptr: bool = false, // When this is true, the addr_of should output as a void*, and should be cast whenever dereferenced
        _scope: ?*Scope = null, // Surrounding scope. Filled in at symbol-tree creation.
    },
    slice_of: struct {
        _token: Token,
        _expr: Ast_Id,
        mut: bool,
    },
    sub_slice: struct { _token: Token, super: Ast_Id, lower: ?Ast_Id, upper: ?Ast_Id },
    receiver: struct {
        _token: Token,
        kind: Receiver_Kind,
        _type: ?*Type_AST = null,
    },
    default: struct {
        _token: Token,
        _type: *Type_AST,
    },
    size_of: struct {
        _token: Token,
        _type: *Type_AST,
    },

    // Control-flow expressions
    @"if": struct {
        _token: Token,
        _scope: ?*Scope,
        let: ?Ast_Id,
        condition: Ast_Id,
        _body_block: Ast_Id,
        _else_block: ?Ast_Id,
    },
    match: struct {
        _token: Token,
        _scope: ?*Scope,
        let: ?Ast_Id,
        _expr: Ast_Id,
        _mappings: std.array_list.Managed(Ast_Id),
    },
    mapping: struct {
        _token: Token,
        _lhs: Ast_Id,
        _rhs: Ast_Id,
        captures: std.array_list.Managed(Ast_Id),
        _scope: ?*Scope, // Scope used for `match` mappings, rooted in `match`'s scope. Captures, rhs live in this scope
    },
    @"while": struct {
        _token: Token,
        _scope: ?*Scope,
        let: ?Ast_Id,
        condition: Ast_Id,
        post: ?Ast_Id,
        _body_block: Ast_Id,
        _else_block: ?Ast_Id,
    },
    @"for": struct {
        _token: Token,
        _scope: ?*Scope,
        let: ?Ast_Id,
        elem: Ast_Id,
        iterable: Ast_Id,
        _body_block: Ast_Id,
        _else_block: ?Ast_Id,
    },
    block: struct {
        _token: Token,
        _scope: ?*Scope,
        _statements: std.array_list.Managed(Ast_Id),
        defers: std.array_list.Managed(Ast_Id),
        errdefers: std.array_list.Managed(Ast_Id),
        final: ?Ast_Id, // either `return`, `continue`, or `break`
    },

    // Control-flow statements
    @"break": struct { _token: Token },
    @"continue": struct { _token: Token },
    @"unreachable": struct { _token: Token },
    @"return": struct {
        _token: Token,
        _ret_expr: ?Ast_Id,
        _symbol: ?*Symbol, // `retrun`'s must be in functions. This is the function's symbol.
    },
    /// This type is a special version of an identifier. It is needed to encapsulate information about a
    /// symbol declaration that is needed before the symbol is even constructed. An identifier AST cannot be
    /// used for this purpose, because it refers to a symbol _after_ symbol decoration.
    pattern_symbol: struct {
        _token: Token,
        name: []const u8,
        kind: Symbol.Kind,
        storage: Symbol.Storage,
        _symbol: ?*Symbol = undefined,
    },
    binding: struct {
        _token: Token,
        pattern: Ast_Id, // Pattern of the binding
        type: *Type_AST, // Conceptually, the type for the binding as a whole
        init: ?Ast_Id, // The init value for the binding as a whole. Possible to be null if `undefiend`.
        decls: std.array_list.Managed(Ast_Id),
    },
    decl: struct {
        _token: Token,
        name: Ast_Id, // The pattern symbol AST for this decl. Access the symbol through this
        type: *Type_AST,
        init: ?Ast_Id,
    },
    fn_decl: struct {
        _token: Token,
        _generic_params: std.array_list.Managed(Ast_Id),
        name: ?Ast_Id, //
        _params: std.array_list.Managed(Ast_Id), // Parameters' decl ASTs
        _param_symbols: std.array_list.Managed(*Symbol), // Parameters' symbols
        ret_type: *Type_AST,
        _decl_type: ?*Type_AST = null,
        refinement: ?Ast_Id,
        init: Ast_Id,
        _symbol: ?*Symbol = null,
        _scope: ?*Scope = null,
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
    type_param_decl: struct {
        _token: Token,
        _symbol: ?*Symbol = null,
    },
    struct_decl: struct {
        _token: Token,
        name: Ast_Id,
        fields: std.array_list.Managed(*Type_AST),
        _generic_params: std.array_list.Managed(Ast_Id),
        _type: *Type_AST,
        _symbol: ?*Symbol = null,
        _scope: ?*Scope = null,
    },
    enum_decl: struct {
        _token: Token,
        name: Ast_Id,
        fields: std.array_list.Managed(*Type_AST),
        _generic_params: std.array_list.Managed(Ast_Id),
        _type: *Type_AST,
        _symbol: ?*Symbol = null,
        _scope: ?*Scope = null,
    },
    type_alias: struct {
        _token: Token,
        name: Ast_Id,
        init: ?*Type_AST,
        _generic_params: std.array_list.Managed(Ast_Id),
        _symbol: ?*Symbol = null,
        _scope: ?*Scope = null,
    },
    method_decl: struct {
        _token: Token,
        name: Ast_Id,
        is_virtual: bool,
        receiver: ?Ast_Id,
        _params: std.array_list.Managed(Ast_Id), // Parameters' decl ASTs
        _param_symbols: std.array_list.Managed(*Symbol), // Parameters' symbols
        c_type: ?*Type_AST = null,
        domain: ?*Type_AST = null, // Domain type when calling. Filled in at symbol-tree creation for impls and traits.
        ret_type: *Type_AST,
        _decl_type: ?*Type_AST = null,
        refinement: ?Ast_Id,
        init: ?Ast_Id,
        impl: ?Ast_Id = null, // The surrounding `impl`. Null for method_decls in traits.
        _symbol: ?*Symbol = null,
    },
    @"test": struct {
        _token: Token,
        name: ?Ast_Id,
        init: Ast_Id,
        _symbol: ?*Symbol = null,
    },
    module: struct {
        _token: Token,
        _scope: ?*Scope, // Only null for compatibility. Always present.
        module: *module_.Module,
    },
    import: struct {
        _token: Token,
        pattern: Ast_Id,
    },
    cinclude: struct {
        _token: Token,
        _expr: Ast_Id,
    },
    @"defer": struct { _token: Token, _statement: Ast_Id },
    @"errdefer": struct { _token: Token, _statement: Ast_Id },

    pub fn token(self: *const AST) Token {
        return get_field_const_ref(self, "_token");
    }

    pub fn set_token(self: Ast_Id, tok: Token) void {
        get_field_ref(self, "_token").* = tok;
    }

    pub fn span(self: *const AST) Span {
        return self.span();
    }

    pub fn set_span(self: Ast_Id, _span: Span) void {
        get_field_ref(self, "_token").span = _span;
    }

    pub fn expr(self: AST) Ast_Id {
        return get_struct_field(self, "_expr");
    }

    pub fn set_expr(self: Ast_Id, val: Ast_Id) void {
        set_field(self, "_expr", val);
    }

    pub fn @"type"(self: AST) *Type_AST {
        return switch (self) {
            .as => self.as._type,
            .size_of => self.size_of._type,
            .default => self.default._type,
            else => std.debug.panic("can't call type on {s}\n", .{@tagName(self)}),
        };
    }

    pub fn symbol(self: AST) ?*Symbol {
        return get_struct_field(self, "_symbol");
    }

    pub fn set_symbol(self: Ast_Id, val: ?*Symbol) void {
        set_field(self, "_symbol", val);
    }

    pub fn scope(self: AST) ?*Scope {
        return get_struct_field(self, "_scope");
    }

    pub fn set_scope(self: Ast_Id, val: ?*Scope) void {
        set_field(self, "_scope", val);
    }

    pub fn lhs(self: AST) Ast_Id {
        return get_struct_field(self, "_lhs");
    }

    pub fn set_lhs(self: Ast_Id, val: Ast_Id) void {
        set_field(self, "_lhs", val);
    }

    pub fn rhs(self: AST) Ast_Id {
        return get_struct_field(self, "_rhs");
    }

    pub fn set_rhs(self: Ast_Id, val: Ast_Id) void {
        set_field(self, "_rhs", val);
    }

    pub fn children_mut(self: Ast_Id) *std.array_list.Managed(Ast_Id) {
        return switch (self.*) {
            .call => &self.call._args,
            .index => &self.index._children,
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
            else => std.debug.panic("compiler error: cannot call `.children()` on the AST `{f}`", .{self.*}),
        };
    }

    pub fn children(self: *const AST) *const std.array_list.Managed(Ast_Id) {
        return switch (self.*) {
            .call => &self.call._args,
            .index => &self.index._children,
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
            else => std.debug.panic("compiler error: cannot call `.children()` on the AST `{f}`", .{self.*}),
        };
    }

    pub fn set_children(self: Ast_Id, val: std.array_list.Managed(Ast_Id)) void {
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

    pub fn decl_type(self: *const AST) *Type_AST {
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

    pub fn decl_init(self: Ast_Id) ?Ast_Id {
        return switch (self.*) {
            .decl => self.decl.init,
            .fn_decl => self.fn_decl.init,
            .method_decl => self.method_decl.init,
            .@"test" => self.@"test".init,
            .module, .trait => self,
            .struct_decl, .enum_decl, .type_alias, .receiver, .type_param_decl => null,
            else => std.debug.panic("compiler error: cannot call `.decl_init()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn set_decl_init(self: Ast_Id, init: Ast_Id) void {
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

    pub fn decl_typedef(self: Ast_Id) ?*Type_AST {
        return switch (self.*) {
            .struct_decl => self.struct_decl._type,
            .enum_decl => self.enum_decl._type,
            .type_alias => self.type_alias.init,
            .type_param_decl => null, // No type... yet!
            else => std.debug.panic("compiler error: cannot call `.decl_typedef()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn decl_name(self: Ast_Id) Ast_Id {
        return switch (self.*) {
            .struct_decl => self.struct_decl.name,
            .enum_decl => self.enum_decl.name,
            .type_alias => self.type_alias.name,
            else => std.debug.panic("compiler error: cannot call `.decl_name()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn set_decl_name(self: Ast_Id, name: Ast_Id) void {
        switch (self.*) {
            .struct_decl => self.struct_decl.name = name,
            .enum_decl => self.enum_decl.name = name,
            .type_alias => self.type_alias.name = name,
            .fn_decl => self.fn_decl.name = name,
            else => std.debug.panic("compiler error: cannot call `.decl_name()` on the AST `{s}`", .{@tagName(self.*)}),
        }
    }

    pub fn param_symbols(self: Ast_Id) ?*std.array_list.Managed(*Symbol) {
        return switch (self.*) {
            .fn_decl => &self.fn_decl._param_symbols,
            .method_decl => &self.method_decl._param_symbols,
            .@"test" => null,
            else => std.debug.panic("compiler error: cannot call `.param_symbols()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn generic_params(self: Ast_Id) *std.array_list.Managed(Ast_Id) {
        return switch (self.*) {
            .struct_decl => &self.struct_decl._generic_params,
            .enum_decl => &self.enum_decl._generic_params,
            .type_alias => &self.type_alias._generic_params,
            .impl => &self.impl._generic_params,
            .fn_decl => &self.fn_decl._generic_params,
            else => std.debug.panic("compiler error: cannot call `.generic_params()` on the AST `{t}`", .{self.*}),
        };
    }

    pub fn set_generic_params(self: Ast_Id, _generic_params: std.array_list.Managed(Ast_Id)) void {
        switch (self.*) {
            .struct_decl => self.struct_decl._generic_params = _generic_params,
            .enum_decl => self.enum_decl._generic_params = _generic_params,
            .type_alias => self.type_alias._generic_params = _generic_params,
            .impl => self.impl._generic_params = _generic_params,
            .fn_decl => self.fn_decl._generic_params = _generic_params,
            else => std.debug.panic("compiler error: cannot call `.set_generic_params()` on the AST `{t}`", .{self.*}),
        }
    }

    pub fn top_level(self: Ast_Id) bool {
        return switch (self.*) {
            .decl => false,
            .fn_decl, .method_decl, .@"test" => true,
            else => std.debug.panic("compiler error: cannot call `.top_level()` on the AST `{s}`", .{@tagName(self.*)}),
        };
    }

    pub fn get_field(self: Ast_Id, _type: *Type_AST, field_name: []const u8) Ast_Id {
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

    pub fn set_pos(self: Ast_Id, val: ?usize) void {
        set_field(self, "_pos", val);
    }

    pub fn statement(self: AST) Ast_Id {
        return get_struct_field(self, "_statement");
    }

    pub fn set_statement(self: Ast_Id, val: Ast_Id) void {
        set_field(self, "_statement", val);
    }

    pub fn body_block(self: AST) Ast_Id {
        return get_struct_field(self, "_body_block");
    }

    pub fn set_body_block(self: Ast_Id, val: Ast_Id) void {
        set_field(self, "_body_block", val);
    }

    pub fn else_block(self: AST) ?Ast_Id {
        return get_struct_field(self, "_else_block");
    }

    pub fn set_else_block(self: Ast_Id, val: ?Ast_Id) void {
        set_field(self, "_else_block", val);
    }

    pub fn mut(self: AST) bool {
        return get_struct_field(self, "mut");
    }

    pub fn set_mut(self: Ast_Id, val: bool) void {
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

    /// Generically retrieve a reference to a field in a Zig union type
    fn get_field_const_ref(u: anytype, comptime field: []const u8) *const Unwrapped(@TypeOf(u.*), field) {
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

    /// Determines if an AST expression can be evaluated at compile-time without having to specify a `comptime`
    /// keyword.
    pub fn is_comptime_expr(self: Ast_Id) bool {
        // It's easier to list all the ASTs that AREN'T comptime! :-)
        return !(self.* == .@"try" or
            self.* == .block or
            self.* == .call);
        // AST kinds like `and` and `or` are technically control-flow, but conceptually, they terminate and
        // are pure.
        // `try` breaks normal control-flow. `block` allows for unpure statements like `continue`, `break`,
        // `return`, and `try`. `call` is non-comptime because functions are not pure in Orange.
        // Kinds like `and`, `or`, `orelse`, `catch`, `if`, `match`, and `while` are in a way "purer", and it
        // would be annoying to have to wrap these in comptime.
    }

    pub fn refers_to_type(self: Ast_Id) bool {
        return switch (self.*) {
            else => false,

            .identifier, .access => self.symbol().?.refers_to_type(),

            .index => self.lhs().refers_to_type(), // generic type
            .generic_apply => self.lhs().refers_to_type(),
        };
    }

    // TODO: Use Tree Writer, don't call writer print, recursively call pprint
    pub fn pprint(self: AST, allocator: std.mem.Allocator) ![]const u8 {
        var out = std.array_list.Managed(u8).init(allocator);
        defer out.deinit();

        switch (self) {
            .poison => try out.print("poison", .{}),
            .unit_value => try out.print("unit_value", .{}),
            .int => try out.print("int({})", .{self.int.data}),
            .char => try out.print("char()", .{}),
            .float => try out.print("float()", .{}),
            .string => try out.print("string()", .{}),
            .field => try out.print("field(\"{s}\")", .{self.field._token.data}),
            .identifier => try out.print("identifier(\"{s}\")", .{self.identifier._token.data}),
            .@"unreachable" => try out.print("unreachable", .{}),
            .true => try out.print("true", .{}),
            .false => try out.print("false", .{}),

            .not => try out.print("not()", .{}),
            .negate => try out.print("negate({f})", .{self.expr()}),
            .dereference => try out.print("dereference()", .{}),
            .@"try" => try out.print("try()", .{}),
            .default => {
                try out.print("default(", .{});
                var writer = out.writer().adaptToNewApi(&.{}).new_interface;
                try self.default._type.print_type(&writer);
                try out.print(")", .{});
            },
            .size_of => try out.print("size_of({f})", .{self.expr()}),
            .@"comptime" => try out.print("comptime({f})", .{self.expr()}),

            .assign => {
                try out.print("assign({f}, {f})", .{ self.lhs(), self.rhs() });
            },
            .@"or" => try out.print("or()", .{}),
            .@"and" => try out.print("and()", .{}),
            .add => try out.print("add()", .{}),
            .sub => try out.print("sub()", .{}),
            .mult => try out.print("mult()", .{}),
            .div => try out.print("div()", .{}),
            .mod => try out.print("mod()", .{}),
            .equal => try out.print("equal()", .{}),
            .not_equal => try out.print("not_equal()", .{}),
            .greater => try out.print("greater()", .{}),
            .lesser => try out.print("lesser()", .{}),
            .greater_equal => try out.print("greater_equal()", .{}),
            .lesser_equal => try out.print("lesser_equal()", .{}),
            .@"catch" => try out.print("catch()", .{}),
            .@"orelse" => try out.print("orelse()", .{}),
            .call => {
                try out.print("call(lhs={f},args=[", .{self.call._lhs});
                for (self.call._args.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.call._args.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print("])", .{});
            },
            .bit_and => {
                try out.print("@bit_and(", .{});
                for (self.call._args.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.call._args.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print(")", .{});
            },
            .bit_or => {
                try out.print("@bit_or(", .{});
                for (self.call._args.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.call._args.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print(")", .{});
            },
            .bit_xor => {
                try out.print("@bit_xor(", .{});
                for (self.call._args.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.call._args.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print(")", .{});
            },
            .bit_not => try out.print("@bit_not({f})", .{self.expr()}),
            .left_shift => try out.print("@left_shift({f}, {f})", .{ self.lhs(), self.rhs() }),
            .right_shift => try out.print("@right_shift({f}, {f})", .{ self.lhs(), self.rhs() }),
            .index => {
                try out.print("index(lhs={f},args=[", .{self.index._lhs});
                for (self.index._children.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.index._children.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print("])", .{});
            },
            .generic_apply => {
                try out.print("generic_apply(lhs={f},args=[", .{self.generic_apply._lhs});
                for (self.generic_apply._children.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.generic_apply._children.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print("])", .{});
            },
            .select => {
                try out.print("select({f},{f})", .{ self.lhs(), self.rhs() });
            },
            .access => {
                try out.print("access({f},{f})", .{ self.lhs(), self.rhs() });
            },
            .trait => try out.print("trait({*})", .{if (self.symbol() != null) self.symbol() else null}),
            .impl => {
                try out.print("impl(.trait={?f}, .type={f}\n", .{ self.impl.trait, self.impl._type });
                for (self.impl.method_defs.items) |method| {
                    try out.print("    {f}\n", .{method});
                }
                try out.print(")", .{});
            },
            .invoke => try out.print("invoke()", .{}),
            .dyn_value => try out.print("dyn_value()", .{}),
            .enum_value => {
                try out.print("enum_value(.name={s}, .init={?f}, .tag={?})", .{ self.enum_value.get_name(), self.enum_value.init, self.enum_value._pos });
            },
            .type_param_decl => try out.print("type_param_decl({s})", .{self.type_param_decl._token.data}),
            .struct_decl => {
                try out.print("struct_decl(\n", .{});
                try out.print("\t.name = {f}\n", .{self.struct_decl.name});
                try out.print("\t.fields = {f}\n", .{fmt_.List_Printer(Type_AST){ .list = &self.struct_decl.fields }});
                try out.print("\t.generic_params = {f}\n", .{fmt_.List_Printer(AST){ .list = &self.struct_decl._generic_params }});
                try out.print(")", .{});
            },
            .enum_decl => {
                try out.print("enum()", .{});
            },
            .type_alias => {
                try out.print("type_alias()", .{});
            },
            .struct_value => {
                try out.print("struct_value(", .{});
                for (self.struct_value._terms.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.struct_value._terms.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print(")", .{});
            },
            .tuple_value => {
                try out.print("tuple_value(", .{});
                for (self.tuple_value._terms.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.tuple_value._terms.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print(")", .{});
            },
            .array_value => {
                try out.print("array_value(", .{});
                for (self.array_value._terms.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.array_value._terms.items.len - 1) {
                        try out.print(",", .{});
                    }
                }
                try out.print(")", .{});
            },

            .as => try out.print("as({f}, {f})", .{ self.expr(), self.type() }),
            .addr_of => try out.print("addr_of({f})", .{self.expr()}),
            .slice_of => try out.print("slice_of()", .{}),
            .sub_slice => try out.print("sub_slice()", .{}),
            .receiver => try out.print("receiver({?f})", .{self.receiver._type}),

            .@"if" => try out.print("if()", .{}),
            .match => try out.print("match()", .{}),
            .mapping => try out.print("mapping()", .{}),
            .@"while" => try out.print("while()", .{}),
            .@"for" => try out.print("for()", .{}),
            .block => {
                try out.print("block(", .{});
                for (self.block._statements.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.block._statements.items.len) {
                        try out.print(",", .{});
                    }
                }
                try out.print(".final={?f})", .{self.block.final});
            },
            .@"break" => try out.print("break", .{}),
            .@"continue" => try out.print("continue", .{}),
            .@"return" => try out.print("return()", .{}),
            .pattern_symbol => try out.print("pattern_symbol({s}, {s})", .{ @tagName(self.pattern_symbol.kind), self.pattern_symbol.name }),
            .binding => {
                try out.print("binding(.type={f})", .{self.binding.type});
            },
            .decl => {
                try out.print("decl(\n", .{});
                try out.print("    .pattern = {f},\n", .{self.decl.name});
                try out.print("    .type = {f},\n", .{self.decl.type});
                try out.print("    .init = {?f},\n", .{self.decl.init});
                try out.print(")", .{});
            },
            .fn_decl => {
                try out.print("fn_decl(\n", .{});
                try out.print("    .name = {?f},\n", .{self.fn_decl.name});
                try out.print("    ._params = [", .{});
                for (self.fn_decl._params.items, 0..) |item, i| {
                    try out.print("{f}", .{item});
                    if (i < self.fn_decl._params.items.len) {
                        try out.print(",", .{});
                    }
                }
                try out.print("],\n", .{});
                try out.print("    .param_symbols = [", .{});
                for (self.fn_decl._param_symbols.items, 0..) |item, i| {
                    try out.print("{s}", .{item.name});
                    if (i < self.fn_decl._param_symbols.items.len) {
                        try out.print(",", .{});
                    }
                }
                try out.print("],\n", .{});
                try out.print("    .ret_type = {f},\n", .{self.fn_decl.ret_type});
                try out.print("    .refinement = {?f},\n", .{self.fn_decl.refinement});
                // try out.print("    .init = {f},\n", .{self.fn_decl.init});
                try out.print("    ._symbol = {?s},\n", .{if (self.fn_decl._symbol) |sym| sym.name else null});
                try out.print("    .infer_error = {},\n", .{self.fn_decl.infer_error});
                try out.print(")", .{});
            },
            .module => try out.print("module()", .{}),
            .import => try out.print("import({f})", .{self.import.pattern}),
            .cinclude => try out.print("cinclude({f})", .{self.cinclude._expr}),
            .template => try out.print("template()", .{}),
            .method_decl => {
                try out.print("method_decl(.name={f}, .receiver={?f}, . .params=[", .{
                    self.method_decl.name,
                    self.method_decl.receiver,
                });
                for (self.method_decl._params.items, 0..) |param, i| {
                    try out.print("{f}", .{param});
                    if (i < self.method_decl._params.items.len) {
                        try out.print(",", .{});
                    }
                }
                try out.print("], .ret_type={f})", .{self.method_decl.ret_type});
            },
            .@"test" => try out.print("test(.name={?f})", .{self.@"test".name}),
            .@"defer" => try out.print("defer()", .{}),
            .@"errdefer" => try out.print("errdefer()", .{}),
        }

        return try out.toOwnedSlice();
    }

    pub fn format(self: AST, writer: *std.io.Writer) !void {
        var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator); // page alloc ok, immediately deinit'd
        defer arena.deinit();

        // TODO: Generic pprinter that makes the arena and string and passes the writer to a pprint method

        const out = self.pprint(arena.allocator()) catch unreachable;

        try writer.print("{s}", .{out});
    }
};
