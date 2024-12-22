const std = @import("std");
const ast_ = @import("ast.zig");
const compiler_ = @import("compiler.zig");
const errs_ = @import("errors.zig");
const module_ = @import("module.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");
const token_ = @import("token.zig");

// TODO: Think about how to remove these public variables. They're only variable because they need to be constructed later.
pub var anyptr_type: *ast_.AST = undefined;
pub var bool_type: *ast_.AST = undefined;
pub var byte_type: *ast_.AST = undefined;
pub var byte_slice_type: *ast_.AST = undefined;
pub var char_type: *ast_.AST = undefined;
pub var float_type: *ast_.AST = undefined;
pub var float32_type: *ast_.AST = undefined;
pub var float64_type: *ast_.AST = undefined;
pub var int_type: *ast_.AST = undefined;
pub var int8_type: *ast_.AST = undefined;
pub var int16_type: *ast_.AST = undefined;
pub var int32_type: *ast_.AST = undefined;
pub var int64_type: *ast_.AST = undefined;
pub var package_type: *ast_.AST = undefined;
pub var addr_package_type: *ast_.AST = undefined;
pub var string_type: *ast_.AST = undefined;
pub var type_type: *ast_.AST = undefined;
pub var unit_type: *ast_.AST = undefined;
pub var unit_value: *ast_.AST = undefined;
pub var void_type: *ast_.AST = undefined;
pub var word16_type: *ast_.AST = undefined;
pub var word32_type: *ast_.AST = undefined;
pub var word64_type: *ast_.AST = undefined;

pub var blackhole: *symbol_.Symbol = undefined;

pub const Primitive_Info = struct {
    name: []const u8,
    c_name: []const u8,
    bounds: ?Bounds,
    ast: *ast_.AST,
    symbol: *symbol_.Symbol,
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
var prelude: ?*symbol_.Scope = null;
pub fn get_scope(compiler: *compiler_.Context) !*symbol_.Scope {
    if (prelude == null) {
        try create_prelude(compiler);
    }
    return prelude.?;
}

fn create_prelude(compiler: *compiler_.Context) !void {
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
    type_type = create_primitive_identifier("Type", compiler.allocator());
    unit_type = create_unit_type(compiler.allocator());
    unit_value = create_unit_value(compiler.allocator());
    void_type = create_primitive_identifier("Void", compiler.allocator());
    word16_type = create_primitive_identifier("Word16", compiler.allocator());
    word32_type = create_primitive_identifier("Word32", compiler.allocator());
    word64_type = create_primitive_identifier("Word64", compiler.allocator());
    // Slice types must be AFTER int_type
    byte_slice_type = ast_.AST.create_slice_type(byte_type, false, compiler.allocator()).assert_ast_valid();

    // Create prelude scope
    prelude = symbol_.Scope.init(null, "", compiler.allocator());

    // Create Symbols for primitives
    _ = create_prelude_symbol("String", type_type, byte_slice_type, compiler.allocator());
    _ = create_prelude_symbol("Type", type_type, type_type, compiler.allocator());
    _ = create_prelude_symbol("Void", type_type, void_type, compiler.allocator());
    blackhole = create_prelude_symbol("_", unit_type, unit_value, compiler.allocator());

    // Setup default values
    // These have to be all different AST nodes because they then represent different types
    // The types are created later, and then the represents field is set after that
    const default_bool = ast_.AST.create_false(token_.Token.init_simple("false"), compiler.allocator());
    const default_char = ast_.AST.create_char(token_.Token.init_simple("'\\\\0'"), compiler.allocator());
    const default_float32 = ast_.AST.create_float(token_.Token.init_simple("0.0"), 0.0, compiler.allocator());
    const default_float64 = ast_.AST.create_float(token_.Token.init_simple("0.0"), 0.0, compiler.allocator());
    // TODO: De-duplicate the following
    const default_int8 = ast_.AST.create_int(token_.Token.init_simple("0"), 0, compiler.allocator());
    const default_int16 = ast_.AST.create_int(token_.Token.init_simple("0"), 0, compiler.allocator());
    const default_int32 = ast_.AST.create_int(token_.Token.init_simple("0"), 0, compiler.allocator());
    const default_int64 = ast_.AST.create_int(token_.Token.init_simple("0"), 0, compiler.allocator());
    const default_word8 = ast_.AST.create_int(token_.Token.init_simple("0"), 0, compiler.allocator());
    const default_word16 = ast_.AST.create_int(token_.Token.init_simple("0"), 0, compiler.allocator());
    const default_word32 = ast_.AST.create_int(token_.Token.init_simple("0"), 0, compiler.allocator());
    const default_word64 = ast_.AST.create_int(token_.Token.init_simple("0"), 0, compiler.allocator());
    const default_string = ast_.AST.create_string(token_.Token.init_simple("\"\""), "", compiler.allocator());

    // Setup primitive map
    primitives = std.StringArrayHashMap(Primitive_Info).init(compiler.allocator());
    create_info(
        "Bool",
        null,
        "uint8_t",
        bool_type,
        null,
        .eq,
        .boolean,
        default_bool,
        1,
        compiler.allocator(),
    );
    create_info(
        "Byte",
        Bounds{ .lower = 0, .upper = 255 },
        "uint8_t",
        byte_type,
        null,
        .num,
        .unsigned_integer,
        default_word8,
        1,
        compiler.allocator(),
    );
    create_info(
        "Char",
        null,
        "uint32_t",
        char_type,
        null,
        .ord,
        .unsigned_integer,
        default_char,
        4,
        compiler.allocator(),
    );
    create_info(
        "Float",
        null,
        "double",
        float_type,
        null,
        .num,
        .floating_point,
        default_float64,
        8,
        compiler.allocator(),
    );
    create_info(
        "Float32",
        null,
        "float",
        float32_type,
        null,
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
        float_type,
        .num,
        .floating_point,
        default_float64,
        8,
        compiler.allocator(),
    );
    create_info(
        "Int",
        Bounds{ .lower = -0x8000_0000_0000_0000, .upper = 0x7FFF_FFFF_FFFF_FFFF },
        "int64_t",
        int_type,
        null,
        .int,
        .signed_integer,
        default_int64,
        8,
        compiler.allocator(),
    );
    create_info(
        "Int8",
        Bounds{ .lower = -0x80, .upper = 0x7F },
        "int8_t",
        int8_type,
        null,
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
        null,
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
        null,
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
        int_type,
        .int,
        .signed_integer,
        default_int64,
        8,
        compiler.allocator(),
    );
    create_info(
        "String",
        null,
        "NO C EQUIVALENT!",
        string_type,
        byte_slice_type,
        .none,
        .string,
        default_string,
        16,
        compiler.allocator(),
    );
    create_info(
        "Type",
        null,
        "NO C EQUIVALENT!",
        type_type,
        null,
        .eq,
        .type,
        null,
        8,
        compiler.allocator(),
    );
    create_info(
        "Void",
        null,
        "NO C EQUIVALENT!",
        void_type,
        null,
        .none,
        .none,
        null,
        0,
        compiler.allocator(),
    );
    create_info(
        "Word16",
        Bounds{ .lower = 0, .upper = 0xFFFF },
        "uint16_t",
        word16_type,
        null,
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
        null,
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
        null,
        .int,
        .unsigned_integer,
        default_word64,
        8,
        compiler.allocator(),
    );

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

    const prelude_contents =
        \\const Package: Type = (
        \\  root: String,
        \\  kind: (executable | static_library),
        \\  dir: String = ".",
        \\  requirements: [8]?Requirement = (
        \\    (?Requirement).none,
        \\    (?Requirement).none,
        \\    (?Requirement).none,
        \\    (?Requirement).none,
        \\    (?Requirement).none,
        \\    (?Requirement).none,
        \\    (?Requirement).none,
        \\    (?Requirement).none
        \\  ),
        \\)
        \\
        \\const Requirement: Type = (String, &Package)
        \\
        \\impl for Package {
        \\  /// Creates an executable package
        \\  fn executable(root: String) -> Self { (root, .executable, "") }
        \\
        \\  /// Creates a static library package
        \\  fn static_library(root: String) -> Self { (root, .static_library, "") }
        \\
        \\  /// Finds a package given a name
        \\  /// NOTE: This is currently implemented as a builtin-function in the compiler
        \\  fn find(name: String) -> &Self { _ = name; unreachable }
        \\
        \\  /// Adds a package to the list of required packages
        \\  fn requires(&mut self, name: String, other: &Package) -> () {
        \\      while let mut i = 0; i < self.requirements.length; i += 1 {
        \\          if self.requirements[i] == .none {
        \\              self.requirements[i] = .some((name, other))
        \\              return
        \\          }
        \\      }
        \\      unreachable // no more space!
        \\  }
        \\}
        \\
    ;

    var errors = errs_.Errors.init(compiler.allocator());
    defer errors.deinit();
    errdefer errors.print_errors();

    const module = module_.Module.init("prelude", "prelude/prelude.orng", prelude.?, compiler.allocator());
    prelude.?.module = module;
    try module_.Module.fill_contents(
        prelude_contents,
        "prelude.orng",
        null,
        prelude.?,
        module,
        false,
        compiler,
    );

    package_type = module.scope.lookup("Package", false).found.init.?;
    _ = module.scope.lookup("Requirement", false).found.init.?;
    addr_package_type = ast_.AST.create_addr_of(package_type.token(), package_type, false, compiler.allocator());
}

fn create_primitive_identifier(name: []const u8, allocator: std.mem.Allocator) *ast_.AST {
    return ast_.AST.create_identifier(token_.Token.init_simple(name), allocator).assert_ast_valid();
}

fn create_unit_type(allocator: std.mem.Allocator) *ast_.AST {
    return ast_.AST.create_unit_type(token_.Token.init_simple("("), allocator).assert_ast_valid();
}

fn create_anyptr_type_primitive(allocator: std.mem.Allocator) *ast_.AST {
    return ast_.AST.create_anyptr_type(token_.Token.init_simple("anyptr_type"), allocator).assert_ast_valid();
}

fn create_unit_value(allocator: std.mem.Allocator) *ast_.AST {
    return ast_.AST.create_unit_value(token_.Token.init_simple("{"), allocator).assert_ast_valid();
}

fn create_prelude_symbol(name: []const u8, _type: *ast_.AST, init: *ast_.AST, allocator: std.mem.Allocator) *symbol_.Symbol {
    var symbol = symbol_.Symbol.init(
        prelude.?,
        name,
        span_.phony_span,
        _type,
        init,
        null,
        .@"const",
        allocator,
    ).assert_symbol_valid();
    symbol.is_temp = true;
    symbol.expanded_type = _type;
    prelude.?.symbols.put(name, symbol) catch unreachable;
    return symbol;
}

fn create_info(
    name: []const u8, // Name of the primitive type identifier
    bounds: ?Bounds, // Optional bounds info for integral types
    c_name: []const u8, // Name to use when generating the primitive to C
    _ast: *ast_.AST, // The AST representation of the type
    definition: ?*ast_.AST, // Optional definition for primitive (not an alias, but a newtype)
    type_class: Type_Class, // Typeclass this primitive belongs to
    type_kind: Type_Kind, // What kind of type this type is
    default_value: ?*ast_.AST, // Optional AST of default value for the primitive
    size: i64, // Size of values of the type in bytes
    allocator: std.mem.Allocator,
) void {
    const symbol_lookup_res = prelude.?.lookup(name, false);
    var symbol: *symbol_.Symbol = undefined;
    if (symbol_lookup_res == .found) {
        symbol = symbol_lookup_res.found;
    } else {
        symbol = create_prelude_symbol(name, type_type, definition orelse _ast, allocator);
    }
    _ast.set_symbol(symbol);
    primitives.put(name, Primitive_Info{
        .name = name,
        .bounds = bounds,
        .c_name = c_name,
        .ast = _ast,
        .symbol = symbol,
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

pub fn bounds_from_ast(_type: *ast_.AST) ?Bounds {
    // _type is expanded
    switch (_type.*) {
        .identifier => {
            const info = primitives.get(_type.token().data) orelse return null;
            if (info.bounds == null) {
                return null;
            }
            return switch (info.type_kind) {
                .signed_integer => info.bounds.?,
                .unsigned_integer => info.bounds.?,
                .boolean => Bounds{ .lower = 0, .upper = 2 },
                else => return null,
            };
        },
        .addr_of, .function => return Bounds{ .lower = 0, .upper = 0xFFFF_FFFF_FFFF_FFFF },
        else => return null,
    }
}

pub fn info_from_ast(expanded_type: *ast_.AST) ?Primitive_Info {
    var unwrapped = expanded_type;
    while (unwrapped.* == .annotation) {
        unwrapped = unwrapped.annotation.type;
    }
    if (unwrapped.* != .identifier) { // Cannot be a primitive!
        return null;
    }
    return info_from_name(unwrapped.token().data);
}
