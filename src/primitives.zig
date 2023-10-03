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

var prelude: ?*Scope = null;
pub fn init() !*Scope {
    if (prelude == null) {
        // Create ASTs for primitives
        bool_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Bool", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        byte_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Byte", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        char_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Char", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        float_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Float", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        float32_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Float32", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        float64_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Float64", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        int_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Int", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        int8_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Int8", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        int16_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Int16", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        int32_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Int32", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        int64_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Int64", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        string_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "String", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        type_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Type", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        unit_type = try AST.createUnit(Token{ .kind = .L_PAREN, .data = "(", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        void_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Void", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        word16_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Word16", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        word32_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Word32", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        word64_type = try AST.createIdentifier(Token{ .kind = .IDENTIFIER, .data = "Word64", .span = Span{ .filename = "", .line = 0, .col = 0 } }, std.heap.page_allocator);
        // Slice types must be AFTER intType
        byte_slice_type = try AST.create_slice_type(byte_type, false, std.heap.page_allocator);

        // Mark as valid
        bool_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = bool_type } };
        byte_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = byte_type } };
        char_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = char_type } };
        float_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = float_type } };
        float32_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = float32_type } };
        float64_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = float64_type } };
        int_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = int_type } };
        int8_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = int8_type } };
        int16_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = int16_type } };
        int32_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = int32_type } };
        int64_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = int64_type } };
        string_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = string_type } };
        type_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = type_type } };
        unit_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = unit_type } };
        void_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = void_type } };
        word16_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = word16_type } };
        word32_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = word32_type } };
        word64_type.getCommon().validation_state = ast.Validation_State{ .valid = .{ .valid_form = word64_type } };

        // Create prelude scope
        prelude = try Scope.init(null, "", std.heap.page_allocator);

        // Create Symbols for primitives
        _ = try create_prelude_symbol("String", type_type, byte_slice_type, true);
        _ = try create_prelude_symbol("Type", type_type, null, true);
        _ = try create_prelude_symbol("Void", type_type, null, true);
        _ = try create_prelude_symbol("_", ast.poisoned, null, true);

        // Setup primitive map
        primitives = std.StringArrayHashMap(Primitive_Info).init(std.heap.page_allocator);
        try create_info("Bool", null, "uint8_t", bool_type, null, .eq, false);
        try create_info("Byte", Bounds{ .lower = 0, .upper = 255 }, "uint8_t", byte_type, null, .num, false);
        try create_info("Char", null, "uint32_t", char_type, null, .ord, false);
        try create_info("Float", null, "double", float_type, null, .num, false);
        try create_info("Float32", null, "float", float32_type, null, .num, false);
        try create_info("Float64", null, "double", float64_type, float_type, .num, false);
        try create_info("Int", Bounds{ .lower = -0x8000_0000_0000_0000, .upper = 0x7FFF_FFFF_FFFF_FFFF }, "int64_t", int_type, null, .num, true);
        try create_info("Int8", Bounds{ .lower = -0x80, .upper = 0x7F }, "int8_t", int8_type, null, .num, true);
        try create_info("Int16", Bounds{ .lower = -0x8000, .upper = 0x7FFF }, "int16_t", int16_type, null, .num, true);
        try create_info("Int32", Bounds{ .lower = -0x8000_000, .upper = 0x7FFF_FFFF }, "int32_t", int32_type, null, .num, true);
        try create_info("Int64", Bounds{ .lower = -0x8000_0000_0000_0000, .upper = 0x7FFF_FFFF_FFFF_FFFF }, "int64_t", int64_type, int_type, .num, true);
        try create_info("Word16", Bounds{ .lower = 0, .upper = 0xFFFF }, "uint16_t", int16_type, null, .num, false);
        try create_info("Word32", Bounds{ .lower = 0, .upper = 0xFFFF_FFFF }, "uint32_t", int32_type, null, .num, false);
        try create_info("Word64", Bounds{ .lower = 0, .upper = 0xFFFF_FFFF_FFFF_FFFF }, "uint64_t", int64_type, null, .num, false);
    }
    return prelude.?;
}

fn create_info(name: []const u8, bounds: ?Bounds, c_name: []const u8, _ast: *AST, alias: ?*AST, type_class: Type_Class, signed_integer: bool) !void {
    var symbol = try create_prelude_symbol(name, type_type, alias, true);
    try primitives.put(name, Primitive_Info{
        .name = name,
        .bounds = bounds,
        .c_name = c_name,
        .ast = _ast,
        .symbol = symbol,
        .type_class = type_class,
        .signed_integer = signed_integer,
    });
}

fn create_prelude_symbol(name: []const u8, _type: *AST, val: ?*AST, is_temp: bool) !*Symbol {
    var symbol = try Symbol.create(
        prelude.?,
        name,
        Span{ .filename = "", .col = 0, .line = 0 },
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
    return primitives.get(_type.getToken().data).?;
}

pub fn represents_signed_primitive(_type: *AST) bool {
    if (_type.* != .identifier) {
        return false;
    }
    var info = primitives.get(_type.getToken().data) orelse return false;
    return info.signed_integer;
}
