///! This file is responsible for handling the prelude. The prelude is a scope that is common to all files. It includes
/// common types that other languages might call "primitives". Types such as Int, String, and Word64.
const std = @import("std");
const ast_ = @import("../ast/ast.zig");
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
pub var unit_value: *ast_.AST = undefined;
pub var void_type: *Type_AST = undefined;
pub var word8_type: *Type_AST = undefined;
pub var word16_type: *Type_AST = undefined;
pub var word32_type: *Type_AST = undefined;
pub var word64_type: *Type_AST = undefined;

pub var blackhole: *Symbol = undefined;

pub const Primitive_Info = struct {
    c_name: []const u8,
    bounds: ?Bounds,
    type_class: Type_Class,
    type_kind: Type_Kind,
    default_value: ?*ast_.AST,
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
pub fn get_scope(compiler: *Compiler_Context) !*Scope {
    if (prelude == null) {
        try create_prelude(compiler);
    }
    return prelude.?;
}

pub fn deinit() void {
    prelude = null;
}

fn create_prelude(compiler: *Compiler_Context) !void {
    // Create ASTs for primitives
    anyptr_type = create_anyptr_type_primitive(compiler.allocator());
    bool_type = create_primitive_identifier("Bool", compiler.allocator());
    byte_type = create_primitive_identifier("Byte", compiler.allocator());
    char_type = create_primitive_identifier("Char", compiler.allocator());
    float_type = create_primitive_identifier("Float", compiler.allocator());
    float32_type = create_primitive_identifier("Float32", compiler.allocator());
    float64_type = create_primitive_identifier("Float64", compiler.allocator());
    int_type = create_primitive_identifier("Int", compiler.allocator());
    int8_type = create_primitive_identifier("Int8", compiler.allocator());
    int16_type = create_primitive_identifier("Int16", compiler.allocator());
    int32_type = create_primitive_identifier("Int32", compiler.allocator());
    int64_type = create_primitive_identifier("Int64", compiler.allocator());
    string_type = create_primitive_identifier("String", compiler.allocator());
    unit_type = create_unit_type(compiler.allocator());
    unit_value = create_unit_value(compiler.allocator());
    void_type = create_primitive_identifier("Void", compiler.allocator());
    word8_type = create_primitive_identifier("Word8", compiler.allocator());
    word16_type = create_primitive_identifier("Word16", compiler.allocator());
    word32_type = create_primitive_identifier("Word32", compiler.allocator());
    word64_type = create_primitive_identifier("Word64", compiler.allocator());
    // Slice types must be AFTER int_type
    byte_slice_type = Type_AST.create_slice_type(byte_type, false, compiler.allocator());

    // Create prelude scope
    var uid_gen = UID_Gen.init();
    prelude = Scope.init(null, &uid_gen, compiler.allocator());

    // Create Symbols for primitives
    blackhole = create_prelude_symbol("_", unit_type, unit_value, compiler.allocator());

    // Setup default values
    // These have to be all different AST nodes because they then represent different types
    // The types are created later, and then the represents field is set after that
    const default_float32 = ast_.AST.create_float(Token.init_simple("0.0"), 0.0, compiler.allocator());
    const default_float64 = ast_.AST.create_float(Token.init_simple("0.0"), 0.0, compiler.allocator());
    // TODO: De-duplicate the following
    const default_int8 = ast_.AST.create_int(Token.init_simple("0"), 0, compiler.allocator());
    const default_int16 = ast_.AST.create_int(Token.init_simple("0"), 0, compiler.allocator());
    const default_int32 = ast_.AST.create_int(Token.init_simple("0"), 0, compiler.allocator());
    const default_int64 = ast_.AST.create_int(Token.init_simple("0"), 0, compiler.allocator());
    const default_word8 = ast_.AST.create_int(Token.init_simple("0"), 0, compiler.allocator());
    const default_word16 = ast_.AST.create_int(Token.init_simple("0"), 0, compiler.allocator());
    const default_word32 = ast_.AST.create_int(Token.init_simple("0"), 0, compiler.allocator());
    const default_word64 = ast_.AST.create_int(Token.init_simple("0"), 0, compiler.allocator());

    // Setup primitive map
    primitives = std.StringArrayHashMap(Primitive_Info).init(compiler.allocator());
    create_info(
        "Float32",
        null,
        "float",
        float32_type,
        .num,
        .floating_point,
        default_float32,
        4,
        compiler.allocator(),
    );
    create_info(
        "Float64",
        null,
        "double",
        float64_type,
        .num,
        .floating_point,
        default_float64,
        8,
        compiler.allocator(),
    );
    create_info(
        "Int8",
        Bounds{ .lower = -0x80, .upper = 0x7F },
        "int8_t",
        int8_type,
        .int,
        .signed_integer,
        default_int8,
        1,
        compiler.allocator(),
    );
    create_info(
        "Int16",
        Bounds{ .lower = -0x8000, .upper = 0x7FFF },
        "int16_t",
        int16_type,
        .int,
        .signed_integer,
        default_int16,
        2,
        compiler.allocator(),
    );
    create_info(
        "Int32",
        Bounds{ .lower = -0x8000_000, .upper = 0x7FFF_FFFF },
        "int32_t",
        int32_type,
        .int,
        .signed_integer,
        default_int32,
        4,
        compiler.allocator(),
    );
    create_info(
        "Int64",
        Bounds{ .lower = -0x8000_0000_0000_0000, .upper = 0x7FFF_FFFF_FFFF_FFFF },
        "int64_t",
        int64_type,
        .int,
        .signed_integer,
        default_int64,
        8,
        compiler.allocator(),
    );
    create_info(
        "Void",
        null,
        "NO C EQUIVALENT!",
        void_type,
        .none,
        .none,
        null,
        0,
        compiler.allocator(),
    );
    create_info(
        "Word8",
        Bounds{ .lower = 0, .upper = 0xFFFF },
        "uint8_t",
        word8_type,
        .int,
        .unsigned_integer,
        default_word16,
        2,
        compiler.allocator(),
    );
    create_info(
        "Word16",
        Bounds{ .lower = 0, .upper = 0xFFFF },
        "uint16_t",
        word16_type,
        .int,
        .unsigned_integer,
        default_word16,
        2,
        compiler.allocator(),
    );
    create_info(
        "Word32",
        Bounds{ .lower = 0, .upper = 0xFFFF_FFFF },
        "uint32_t",
        word32_type,
        .int,
        .unsigned_integer,
        default_word32,
        4,
        compiler.allocator(),
    );
    create_info(
        "Word64",
        Bounds{ .lower = 0, .upper = 0xFFFF_FFFF_FFFF_FFFF },
        "uint64_t",
        word64_type,
        .int,
        .unsigned_integer,
        default_word64,
        8,
        compiler.allocator(),
    );

    _ = create_type_alias_symbol("String", byte_slice_type, string_type, compiler.allocator());
    _ = create_type_alias_symbol("Int", int64_type, int_type, compiler.allocator());
    _ = create_type_alias_symbol("Float", float64_type, float_type, compiler.allocator());
    _ = create_type_alias_symbol("Char", word32_type, char_type, compiler.allocator());
    _ = create_type_alias_symbol("Byte", word8_type, byte_type, compiler.allocator());
    _ = create_type_alias_symbol("Bool", word8_type, bool_type, compiler.allocator());

    default_int8.set_represents(int8_type);
    default_int16.set_represents(int16_type);
    default_int32.set_represents(int32_type);
    default_int64.set_represents(int_type);

    default_word8.set_represents(byte_type);
    default_word16.set_represents(word16_type);
    default_word32.set_represents(word32_type);
    default_word64.set_represents(word64_type);

    default_float32.set_represents(float32_type);
    default_float64.set_represents(float64_type);

    var errors = errs_.Errors.init(compiler.allocator());
    defer errors.deinit();

    var prelude_abs_path = String.init_with_contents(compiler.allocator(), "/prelude") catch unreachable;
    prelude_abs_path.writer().print("{c}prelude.orng", .{std.fs.path.sep}) catch unreachable;
    const module = module_.Module.init((prelude_abs_path.toOwned() catch unreachable).?, compiler.allocator());
    const symbol = Symbol.init(
        compiler.prelude,
        "prelude",
        ast_.AST.create_module(
            Token.init_simple("prelude"),
            prelude.?,
            module,
            compiler.allocator(),
        ),
        .module,
        .local,
        compiler.allocator(),
    );
    try prelude.?.put_symbol(symbol, &compiler.errors);
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

fn create_unit_value(allocator: std.mem.Allocator) *ast_.AST {
    return ast_.AST.create_unit_value(Token.init_simple("{"), allocator).assert_ast_valid();
}

fn create_prelude_symbol(name: []const u8, _type: *Type_AST, init: *ast_.AST, allocator: std.mem.Allocator) *Symbol {
    const token = Token.init_simple(name);
    const decl = ast_.AST.create_decl(
        token,
        ast_.AST.create_pattern_symbol(token, .@"const", .local, name, allocator),
        _type,
        init,
        true,
        allocator,
    );
    var symbol = Symbol.init(
        prelude.?,
        name,
        decl,
        .@"const",
        .local,
        allocator,
    ).assert_symbol_valid();
    symbol.is_temp = true;
    _type.set_expanded_type(_type);
    prelude.?.symbols.put(name, symbol) catch unreachable;
    return symbol;
}

fn create_type_alias_symbol(name: []const u8, _type: *Type_AST, repr_ident: *Type_AST, allocator: std.mem.Allocator) *Symbol {
    const token = Token.init_simple(name);
    const decl = ast_.AST.create_type_alias(
        token,
        ast_.AST.create_pattern_symbol(token, .type, .local, name, allocator),
        _type,
        allocator,
    );
    var symbol = Symbol.init(
        prelude.?,
        name,
        decl,
        .type,
        .local,
        allocator,
    ).assert_symbol_valid();
    symbol.is_temp = true;
    repr_ident.set_symbol(symbol);
    _type.set_expanded_type(_type);
    prelude.?.symbols.put(name, symbol) catch unreachable;
    return symbol;
}

fn create_c_extern_symbol(name: []const u8, c_name: []const u8, allocator: std.mem.Allocator) *Symbol {
    const token = Token.init_simple(name);
    const storage: Symbol.Storage = .{ .@"extern" = .{ .c_name = ast_.AST.create_string(Token.init_simple(c_name), c_name, allocator) } };
    const decl = ast_.AST.create_type_alias(
        token,
        ast_.AST.create_pattern_symbol(token, .type, storage, name, allocator),
        null,
        allocator,
    );
    var symbol = Symbol.init(
        prelude.?,
        name,
        decl,
        .type,
        storage,
        allocator,
    ).assert_symbol_valid();
    symbol.is_temp = true;
    prelude.?.symbols.put(name, symbol) catch unreachable;
    return symbol;
}

fn create_info(
    name: []const u8, // Name of the primitive type identifier
    bounds: ?Bounds, // Optional bounds info for integral types
    c_name: []const u8, // Name to use when generating the primitive to C
    _ast: *Type_AST, // The AST representation of the type
    type_class: Type_Class, // Typeclass this primitive belongs to
    type_kind: Type_Kind, // What kind of type this type is
    default_value: ?*ast_.AST, // Optional AST of default value for the primitive
    size: i64, // Size of values of the type in bytes
    allocator: std.mem.Allocator,
) void {
    const symbol: *Symbol = create_c_extern_symbol(name, c_name, allocator);
    _ast.set_symbol(symbol);
    primitives.put(name, Primitive_Info{
        .bounds = bounds,
        .c_name = c_name,
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
