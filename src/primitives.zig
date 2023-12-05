// packages
const std = @import("std");
// modules
const ast = @import("ast.zig");
const _symbol = @import("symbol.zig");
// types
const AST = ast.AST;
const Scope = _symbol.Scope;
const Span = @import("span.zig").Span;
const Symbol = _symbol.Symbol;
const Token = @import("token.zig").Token;

pub var bool_type: *AST = undefined;
pub var byte_type: *AST = undefined;
pub var byte_slice_type: *AST = undefined;
pub var char_type: *AST = undefined;
pub var float_type: *AST = undefined;
pub var float32_type: *AST = undefined;
pub var float64_type: *AST = undefined;
pub var int_type: *AST = undefined;
pub var int8_type: *AST = undefined;
pub var int16_type: *AST = undefined;
pub var int32_type: *AST = undefined;
pub var int64_type: *AST = undefined;
pub var string_type: *AST = undefined;
pub var type_type: *AST = undefined;
pub var unit_type: *AST = undefined;
pub var void_type: *AST = undefined;
pub var word16_type: *AST = undefined;
pub var word32_type: *AST = undefined;
pub var word64_type: *AST = undefined;

pub const Primitive_Info = struct {
    name: []const u8,
    c_name: []const u8,
    bounds: ?Bounds,
    ast: *AST,
    symbol: *Symbol,
    type_class: Type_Class,
    signed_integer: bool,
    default_value: ?*AST,

    pub fn is_eq(self: Primitive_Info) bool {
        return self.type_class == .eq or self.is_ord();
    }

    pub fn is_ord(self: Primitive_Info) bool {
        return self.type_class == .ord or self.is_num();
    }

    pub fn is_num(self: Primitive_Info) bool {
        return self.type_class == .num;
    }
};

pub const Bounds = struct {
    lower: i128,
    upper: i128,
};

pub const Type_Class = enum {
    none,
    eq,
    ord,
    num,
};

var primitives: std.StringArrayHashMap(Primitive_Info) = undefined;

// The prelude should only be created once per compilation. _ALL_ packages and modules are within this one prelude scope.
var prelude: ?*Scope = null;
pub fn get_scope() !*Scope {
    if (prelude == null) {
        // Create ASTs for primitives
        bool_type = try create_identifier("Bool");
        byte_type = try create_identifier("Byte");
        char_type = try create_identifier("Char");
        float_type = try create_identifier("Float");
        float32_type = try create_identifier("Float32");
        float64_type = try create_identifier("Float64");
        int_type = try create_identifier("Int");
        int8_type = try create_identifier("Int8");
        int16_type = try create_identifier("Int16");
        int32_type = try create_identifier("Int32");
        int64_type = try create_identifier("Int64");
        string_type = try create_identifier("String");
        type_type = try create_identifier("Type");
        unit_type = try create_unit_type();
        void_type = try create_identifier("Void");
        word16_type = try create_identifier("Word16");
        word32_type = try create_identifier("Word32");
        word64_type = try create_identifier("Word64");
        // Slice types must be AFTER int_type
        byte_slice_type = try AST.create_slice_type(byte_type, false, std.heap.page_allocator);
        byte_slice_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = byte_slice_type } };

        // Create prelude scope
        prelude = try Scope.init(null, "", std.heap.page_allocator);

        // Create Symbols for primitives
        _ = try create_prelude_symbol("String", type_type, byte_slice_type, true);
        _ = try create_prelude_symbol("Type", type_type, null, true);
        _ = try create_prelude_symbol("Void", type_type, null, true);
        _ = try create_prelude_symbol("_", unit_type, try AST.createUnitValue(Token.create_simple("{}"), std.heap.page_allocator), true);

        // Setup default values
        const default_bool = try AST.createFalse(Token.create_simple("false"), std.heap.page_allocator);
        const default_char = try AST.createChar(Token.create_simple("'\\\\0'"), std.heap.page_allocator);
        const default_float = try AST.createFloat(Token.create_simple("0.0"), 0.0, std.heap.page_allocator);
        const default_int = try AST.createInt(Token.create_simple("0"), 0, std.heap.page_allocator);
        const default_string = try AST.createString(Token.create_simple("\"\""), "", std.heap.page_allocator);

        // Setup primitive map
        primitives = std.StringArrayHashMap(Primitive_Info).init(std.heap.page_allocator);
        try create_info("Bool", null, "uint8_t", bool_type, null, .eq, false, default_bool);
        try create_info("Byte", Bounds{ .lower = 0, .upper = 255 }, "uint8_t", byte_type, null, .num, false, default_int);
        try create_info("Char", null, "uint32_t", char_type, null, .ord, false, default_char);
        try create_info("Float", null, "double", float_type, null, .num, false, default_float);
        try create_info("Float32", null, "float", float32_type, null, .num, false, default_float);
        try create_info("Float64", null, "double", float64_type, float_type, .num, false, default_float);
        try create_info("Int", Bounds{ .lower = -0x8000_0000_0000_0000, .upper = 0x7FFF_FFFF_FFFF_FFFF }, "int64_t", int_type, null, .num, true, default_int);
        try create_info("Int8", Bounds{ .lower = -0x80, .upper = 0x7F }, "int8_t", int8_type, null, .num, true, default_int);
        try create_info("Int16", Bounds{ .lower = -0x8000, .upper = 0x7FFF }, "int16_t", int16_type, null, .num, true, default_int);
        try create_info("Int32", Bounds{ .lower = -0x8000_000, .upper = 0x7FFF_FFFF }, "int32_t", int32_type, null, .num, true, default_int);
        try create_info("Int64", Bounds{ .lower = -0x8000_0000_0000_0000, .upper = 0x7FFF_FFFF_FFFF_FFFF }, "int64_t", int64_type, int_type, .num, true, default_int);
        try create_info("String", null, "NO C EQUIVALENT!", string_type, byte_slice_type, .none, false, default_string);
        try create_info("Type", null, "NO C EQUIVALENT!", type_type, null, .none, false, null);
        try create_info("Void", null, "NO C EQUIVALENT!", void_type, null, .none, false, null);
        try create_info("Word16", Bounds{ .lower = 0, .upper = 0xFFFF }, "uint16_t", int16_type, null, .num, false, default_int);
        try create_info("Word32", Bounds{ .lower = 0, .upper = 0xFFFF_FFFF }, "uint32_t", int32_type, null, .num, false, default_int);
        try create_info("Word64", Bounds{ .lower = 0, .upper = 0xFFFF_FFFF_FFFF_FFFF }, "uint64_t", int64_type, null, .num, false, default_int);
    }
    return prelude.?;
}

fn create_identifier(name: []const u8) !*AST {
    var retval = try AST.createIdentifier(Token.create_simple(name), std.heap.page_allocator);
    retval.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = retval } };
    return retval;
}

fn create_unit_type() !*AST {
    var retval = try AST.createUnitType(Token.create_simple("("), std.heap.page_allocator);
    retval.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = retval } };
    return retval;
}

fn create_info(
    name: []const u8, // Name of the primitive type identifier
    bounds: ?Bounds, // Optional bounds info for integral types
    c_name: []const u8, // Name to use when generating the primitive to C
    _ast: *AST, // The AST representation of the type
    alias: ?*AST, // Optional alias for primitive (TODO: Aliases aren't actually supported... this is a new type!)
    type_class: Type_Class, // Typeclass this primitive belongs to
    signed_integer: bool, // Whether the primitive is a signed integer (TODO: This is goobersville)
    default_value: ?*AST, // Optional AST of default value for the primitive
) !void {
    const symbol = try create_prelude_symbol(name, type_type, alias, true);
    try primitives.put(name, Primitive_Info{
        .name = name,
        .bounds = bounds,
        .c_name = c_name,
        .ast = _ast,
        .symbol = symbol,
        .type_class = type_class,
        .signed_integer = signed_integer,
        .default_value = default_value,
    });
}

fn create_prelude_symbol(name: []const u8, _type: *AST, val: ?*AST, is_temp: bool) !*Symbol {
    var symbol = try Symbol.create(
        prelude.?,
        name,
        Span{ .filename = "", .line_text = "", .col = 0, .line = 0 },
        _type,
        val,
        null,
        ._const,
        std.heap.page_allocator,
    );
    symbol.is_temp = is_temp;
    try prelude.?.symbols.put(name, symbol);
    return symbol;
}

pub fn keys() [][]const u8 {
    return primitives.keys();
}

pub fn get(name: []const u8) Primitive_Info {
    return primitives.get(name).?;
}

pub fn from_ast(_type: *AST) Primitive_Info {
    std.debug.assert(_type.* == .identifier);
    return primitives.get(_type.getToken().data) orelse {
        std.debug.print("compiler error: `{s}` is not a primitive\n", .{_type.getToken().data});
        unreachable;
    };
}

pub fn represents_signed_primitive(_type: *AST) bool {
    if (_type.* != .identifier) {
        return false;
    }
    const info = primitives.get(_type.getToken().data) orelse return false;
    return info.signed_integer;
}
