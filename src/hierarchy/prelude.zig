///! This file is responsible for handling the prelude. The prelude is a scope that is common to all files. It includes
/// common types that other languages might call "primitives". Types such as Int, String, and Word64.
const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Ast_Id = @import("../ast/ast_store.zig").Ast_Id;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const module_ = @import("../hierarchy/module.zig");
const Span = @import("../util/span.zig");
const Scope = @import("../symbol/scope.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");
const Symbol_Tree = @import("../ast/symbol-tree.zig");
const Token = @import("../lexer/token.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const UID_Gen = @import("../util/uid_gen.zig");

// TODO: Think about how to remove these public variables. They're only variable because they need to be constructed later.
pub var anyptr_type: *Type_AST = undefined;
pub var bool_type: *Type_AST = undefined;
pub var byte_type: *Type_AST = undefined;
pub var byte_slice_type: *Type_AST = undefined;
pub var char_type: *Type_AST = undefined;
pub var float_type: *Type_AST = undefined;
pub var float32_type: *Type_AST = undefined;
pub var float64_type: *Type_AST = undefined;
pub var int_type: *Type_AST = undefined;
pub var int8_type: *Type_AST = undefined;
pub var int16_type: *Type_AST = undefined;
pub var int32_type: *Type_AST = undefined;
pub var int64_type: *Type_AST = undefined;
pub var string_type: *Type_AST = undefined;
// pub var type_type: *Type_AST = undefined;
pub var unit_type: *Type_AST = undefined;
pub var unit_value: Ast_Id = undefined;
pub var void_type: *Type_AST = undefined;
pub var word8_type: *Type_AST = undefined;
pub var word16_type: *Type_AST = undefined;
pub var word32_type: *Type_AST = undefined;
pub var word64_type: *Type_AST = undefined;

pub var blackhole: *Symbol = undefined;

pub const Primitive_Info = struct {
    c_name: []const u8,
    canon_name: []const u8,
    bounds: ?Bounds,
    type_class: Type_Class,
    type_kind: Type_Kind,
    default_value: ?Ast_Id,
    size: i64,
    _align: i64,

    pub fn is_eq(self: Primitive_Info) bool {
        return self.type_class == .eq or self.is_ord();
    }

    pub fn is_ord(self: Primitive_Info) bool {
        return self.type_class == .ord or self.is_num();
    }

    pub fn is_num(self: Primitive_Info) bool {
        return self.type_class == .num or self.is_int();
    }

    pub fn is_int(self: Primitive_Info) bool {
        return self.type_class == .int;
    }

    pub fn is_bits(self: Primitive_Info) bool {
        return self.type_kind == .unsigned_integer;
    }
};

pub const Bounds = struct {
    lower: i128, // inclusive
    upper: i128, // inclusive
};

pub const Type_Class = enum {
    none,
    eq,
    ord,
    num,
    int,
};

pub const Type_Kind = enum {
    type,
    none,
    signed_integer,
    unsigned_integer,
    floating_point,
    boolean,
    string,
};

var primitives: std.StringArrayHashMap(Primitive_Info) = undefined;

// The prelude should only be created once per compilation. _ALL_ packages and modules are within this one prelude scope.
var prelude: ?*Scope = null;
pub fn get_scope(ctx: *Compiler_Context) !*Scope {
    if (prelude == null) {
        try create_prelude(ctx);
    }
    return prelude.?;
}

pub fn deinit() void {
    prelude = null;
}

fn create_prelude(ctx: *Compiler_Context) !void {
    // Create ASTs for primitives
    anyptr_type = create_anyptr_type_primitive(ctx.allocator());
    bool_type = create_primitive_identifier("Bool", ctx.allocator());
    byte_type = create_primitive_identifier("Byte", ctx.allocator());
    char_type = create_primitive_identifier("Char", ctx.allocator());
    float_type = create_primitive_identifier("Float", ctx.allocator());
    float32_type = create_primitive_identifier("Float32", ctx.allocator());
    float64_type = create_primitive_identifier("Float64", ctx.allocator());
    int_type = create_primitive_identifier("Int", ctx.allocator());
    int8_type = create_primitive_identifier("Int8", ctx.allocator());
    int16_type = create_primitive_identifier("Int16", ctx.allocator());
    int32_type = create_primitive_identifier("Int32", ctx.allocator());
    int64_type = create_primitive_identifier("Int64", ctx.allocator());
    string_type = create_primitive_identifier("String", ctx.allocator());
    unit_type = create_unit_type(ctx.allocator());
    unit_value = create_unit_value(ctx.allocator());
    void_type = create_primitive_identifier("Void", ctx.allocator());
    word8_type = create_primitive_identifier("Word8", ctx.allocator());
    word16_type = create_primitive_identifier("Word16", ctx.allocator());
    word32_type = create_primitive_identifier("Word32", ctx.allocator());
    word64_type = create_primitive_identifier("Word64", ctx.allocator());
    // Slice types must be AFTER int_type
    byte_slice_type = Type_AST.create_slice_type(byte_type, false, ctx.allocator());

    // Create prelude scope
    var uid_gen = UID_Gen.init();
    prelude = Scope.init(null, &uid_gen, ctx.allocator());

    // Create Symbols for primitives
    blackhole = create_prelude_symbol("_", unit_type, unit_value, ctx.allocator());

    // Setup default values
    // These have to be all different AST nodes because they then represent different types
    // The types are created later, and then the represents field is set after that
    const default_float32 = try ctx.ast_store.add(.{ .float = .{ ._token = Token.init_simple("0.0"), .data = 0.0 } });
    const default_float64 = try ctx.ast_store.add(.{ .float = .{ ._token = Token.init_simple("0.0"), .data = 0.0 } });
    // TODO: De-duplicate the following
    const default_bool = try ctx.ast_store.add(.{ .false = .{ ._token = Token.init_simple("false") } });
    const default_char = try ctx.ast_store.add(.{ .char = .{ ._token = Token.init_simple("'\\\\0'") } });
    const default_int8 = try ctx.ast_store.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });
    const default_int16 = try ctx.ast_store.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });
    const default_int32 = try ctx.ast_store.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });
    const default_int64 = try ctx.ast_store.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });
    const default_word8 = try ctx.ast_store.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });
    const default_word16 = try ctx.ast_store.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });
    const default_word32 = try ctx.ast_store.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });
    const default_word64 = try ctx.ast_store.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });

    // Setup primitive map
    primitives = std.StringArrayHashMap(Primitive_Info).init(ctx.allocator());
    create_info(
        "Bool",
        null,
        "uint8_t",
        "u8",
        bool_type,
        .eq,
        .boolean,
        default_bool,
        1,
        ctx.allocator(),
    );
    create_info(
        "Char",
        null,
        "uint32_t",
        "u32",
        char_type,
        .ord,
        .unsigned_integer,
        default_char,
        4,
        ctx.allocator(),
    );
    create_info(
        "Float32",
        null,
        "float",
        "f32",
        float32_type,
        .num,
        .floating_point,
        default_float32,
        4,
        ctx.allocator(),
    );
    create_info(
        "Float64",
        null,
        "double",
        "f64",
        float64_type,
        .num,
        .floating_point,
        default_float64,
        8,
        ctx.allocator(),
    );
    create_info(
        "Int8",
        Bounds{ .lower = -0x80, .upper = 0x7F },
        "int8_t",
        "i8",
        int8_type,
        .int,
        .signed_integer,
        default_int8,
        1,
        ctx.allocator(),
    );
    create_info(
        "Int16",
        Bounds{ .lower = -0x8000, .upper = 0x7FFF },
        "int16_t",
        "i16",
        int16_type,
        .int,
        .signed_integer,
        default_int16,
        2,
        ctx.allocator(),
    );
    create_info(
        "Int32",
        Bounds{ .lower = -0x8000_000, .upper = 0x7FFF_FFFF },
        "int32_t",
        "i32",
        int32_type,
        .int,
        .signed_integer,
        default_int32,
        4,
        ctx.allocator(),
    );
    create_info(
        "Int64",
        Bounds{ .lower = -0x8000_0000_0000_0000, .upper = 0x7FFF_FFFF_FFFF_FFFF },
        "int64_t",
        "i64",
        int64_type,
        .int,
        .signed_integer,
        default_int64,
        8,
        ctx.allocator(),
    );
    create_info(
        "Void",
        null,
        "NO C EQUIVALENT!",
        "NO C EQUIVALENT!",
        void_type,
        .none,
        .none,
        null,
        0,
        ctx.allocator(),
    );
    create_info(
        "Word8",
        Bounds{ .lower = 0, .upper = 0xFFFF },
        "uint8_t",
        "u8",
        word8_type,
        .int,
        .unsigned_integer,
        default_word8,
        2,
        ctx.allocator(),
    );
    create_info(
        "Word16",
        Bounds{ .lower = 0, .upper = 0xFFFF },
        "uint16_t",
        "u16",
        word16_type,
        .int,
        .unsigned_integer,
        default_word16,
        2,
        ctx.allocator(),
    );
    create_info(
        "Word32",
        Bounds{ .lower = 0, .upper = 0xFFFF_FFFF },
        "uint32_t",
        "u32",
        word32_type,
        .int,
        .unsigned_integer,
        default_word32,
        4,
        ctx.allocator(),
    );
    create_info(
        "Word64",
        Bounds{ .lower = 0, .upper = 0xFFFF_FFFF_FFFF_FFFF },
        "uint64_t",
        "u64",
        word64_type,
        .int,
        .unsigned_integer,
        default_word64,
        8,
        ctx.allocator(),
    );

    _ = create_type_alias_symbol("String", byte_slice_type, string_type, ctx.allocator());
    _ = create_type_alias_symbol("Int", int64_type, int_type, ctx.allocator());
    _ = create_type_alias_symbol("Float", float64_type, float_type, ctx.allocator());
    _ = create_type_alias_symbol("Byte", word8_type, byte_type, ctx.allocator());

    var errors = errs_.Errors.init(ctx.allocator());
    defer errors.deinit();

    var prelude_abs_path = std.array_list.Managed(u8).init(ctx.allocator());
    prelude_abs_path.print("/prelude{c}prelude.orng", .{std.fs.path.sep}) catch unreachable;
    const module = module_.Module.init(prelude_abs_path.toOwnedSlice() catch unreachable, ctx);
    const symbol = Symbol.init(
        ctx.prelude,
        "prelude",
        try ctx.ast_store.add(.{ .module = .{
            ._token = Token.init_simple("prelude"),
            ._scope = prelude.?,
            .module = module,
        } }),
        .module,
        .local,
        ctx.allocator(),
    );
    try prelude.?.put_symbol(symbol, &ctx.errors);
}

fn create_primitive_identifier(name: []const u8, allocator: std.mem.Allocator) *Type_AST {
    return Type_AST.create_identifier(Token.init_simple(name), allocator);
}

fn create_unit_type(allocator: std.mem.Allocator) *Type_AST {
    return Type_AST.create_unit_type(Token.init_simple("("), allocator);
}

fn create_anyptr_type_primitive(allocator: std.mem.Allocator) *Type_AST {
    return Type_AST.create_anyptr_type(Token.init_simple("anyptr_type"), allocator);
}

fn create_unit_value(ctx: *Compiler_Context) Ast_Id {
    return try ctx.ast_store.add(.{ .unit_value = .{ ._token = Token.init_simple("{") } });
}

fn create_prelude_symbol(name: []const u8, _type: *Type_AST, init: Ast_Id, ctx: *Compiler_Context) *Symbol {
    const token = Token.init_simple(name);
    const decl = try ctx.ast_store.add(.{ .decl = .{
        ._token = token,
        .name = try ctx.ast_store.add(.{ .pattern_symbol = .{ ._token = token, .kind = .@"const", .storage = .local, .name = name } }),
        .type = _type,
        .init = init,
    } });
    var symbol = Symbol.init(
        prelude.?,
        name,
        decl,
        .@"const",
        .local,
        ctx.allocator(),
    ).assert_symbol_valid();
    symbol.is_temp = true;
    _type.set_expanded_type(_type);
    prelude.?.symbols.put(name, symbol) catch unreachable;
    return symbol;
}

fn create_type_alias_symbol(name: []const u8, _type: *Type_AST, repr_ident: *Type_AST, ctx: *Compiler_Context) *Symbol {
    const token = Token.init_simple(name);
    const decl = try ctx.ast_store.add(.{ .type_alias = .{
        ._token = token,
        .name = try ctx.ast_store.add(.{
            .pattern_symbol = .{
                ._token = token,
                .kind = .type,
                .storage = .local,
                .name = name,
            },
        }),
        .init = _type,
        ._generic_params = std.array_list.Managed(Ast_Id).init(ctx.allocator()),
    } });
    var symbol = Symbol.init(
        prelude.?,
        name,
        decl,
        .type,
        .local,
        ctx.allocator(),
    ).assert_symbol_valid();
    symbol.is_temp = true;
    repr_ident.set_symbol(symbol);
    _type.set_expanded_type(_type);
    prelude.?.symbols.put(name, symbol) catch unreachable;
    return symbol;
}

fn create_c_extern_symbol(name: []const u8, c_name: []const u8, ctx: *Compiler_Context) *Symbol {
    const token = Token.init_simple(name);
    const storage: Symbol.Storage = .{ .@"extern" = .{ .c_name = try ctx.ast_store.add(.{ .string = .{
        ._token = Token.init_simple(c_name),
        .data = c_name,
    } }) } };
    const decl = try ctx.ast_store.add(.{ .type_alias = .{
        ._token = token,
        .name = try ctx.ast_store.add(.{
            .pattern_symbol = .{
                ._token = token,
                .kind = .type,
                .storage = .local,
                .name = name,
            },
        }),
        .init = null,
        ._generic_params = std.array_list.Managed(Ast_Id).init(ctx.allocator()),
    } });
    var symbol = Symbol.init(
        prelude.?,
        name,
        decl,
        .type,
        storage,
        ctx.allocator(),
    ).assert_symbol_valid();
    symbol.is_temp = true;
    prelude.?.symbols.put(name, symbol) catch unreachable;
    return symbol;
}

fn create_info(
    name: []const u8, // Name of the primitive type identifier
    bounds: ?Bounds, // Optional bounds info for integral types
    c_name: []const u8, // Name to use when generating the primitive to C
    canon_name: []const u8, // Name to use when generating the canonical representation
    _ast: *Type_AST, // The AST representation of the type
    type_class: Type_Class, // Typeclass this primitive belongs to
    type_kind: Type_Kind, // What kind of type this type is
    default_value: ?Ast_Id, // Optional AST of default value for the primitive
    size: i64, // Size of values of the type in bytes
    allocator: std.mem.Allocator,
) void {
    const symbol: *Symbol = create_c_extern_symbol(name, c_name, allocator);
    _ast.set_symbol(symbol);
    primitives.put(name, Primitive_Info{
        .bounds = bounds,
        .c_name = c_name,
        .canon_name = canon_name,
        .type_class = type_class,
        .type_kind = type_kind,
        .default_value = default_value,
        .size = size,
        ._align = if (size < 8) size else 8,
    }) catch unreachable;
}

pub fn info_from_name(name: []const u8) ?Primitive_Info {
    return primitives.get(name);
}

pub fn bounds_from_ast(_type: *Type_AST) ?Bounds {
    // _type is expanded
    switch (_type.*) {
        .identifier => return bounds_from_identifier(_type),
        .addr_of, .function => return Bounds{ .lower = 0, .upper = 0xFFFF_FFFF_FFFF_FFFF },
        else => return null,
    }
}

fn bounds_from_identifier(ident_type: *Type_AST) ?Bounds {
    const info = primitives.get(ident_type.token().data) orelse return null;
    if (info.bounds == null) {
        return null;
    }
    return switch (info.type_kind) {
        .signed_integer => info.bounds.?,
        .unsigned_integer => info.bounds.?,
        .boolean => Bounds{ .lower = 0, .upper = 2 },
        else => return null,
    };
}

pub fn info_from_ast(expanded_type: *Type_AST) ?Primitive_Info {
    var unwrapped = expanded_type;
    while (unwrapped.* == .annotation) {
        unwrapped = unwrapped.child();
    }
    if (unwrapped.* != .identifier) { // Cannot be a primitive!
        return null;
    }
    return info_from_name(unwrapped.token().data);
}
