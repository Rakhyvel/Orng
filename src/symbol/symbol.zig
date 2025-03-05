const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const CFG = @import("../ir/cfg.zig");
const Scope = @import("../symbol/scope.zig");
const Span = @import("../util/span.zig");
const validation_state_ = @import("../util/validation_state.zig");

const Self = @This();

pub const Kind = union(enum) {
    @"fn",
    @"const",
    @"extern": struct { c_name: ?*ast_.AST },
    let,
    mut,
    @"comptime",
    trait,
    template,
    import: struct { // Refers indirectly to modules, or to refinements on modules.
        // Real name of the module, as oposed to the `as` name
        real_name: []const u8,
    },
    import_inner, // Created from the inner expressions of qualified import statements, similar to consts
    module, // Refers to modules. The init is the `module` AST, which refers to the module and to the scope. `Module`s have their symbol
};

pub const Symbol_Validation_State = validation_state_.Validation_State(*Self);

var number_of_comptime: usize = 0;

// TODO: Much like AST, create a symbol-create.zig, and usingnamespace it here with `create_comptime_init`, `create_symbol`, `create_method_type`, `create_temp_comptime_symbol`, `create_template_symbol`, `create_function_symbol`, and any other supporting infra
scope: *Scope, // Enclosing parent scope
name: []const u8,
span: Span,
_type: *ast_.AST,
expanded_type: ?*ast_.AST,
init: ?*ast_.AST,
kind: Kind,
cfg: ?*CFG,
decl: ?*ast_.AST,
is_alias: bool, // when this is true, this symbol is a type-alias, and should be expanded before use

// Use-def
aliases: u64 = 0, // How many times the symbol is taken as a mutable address
roots: u64 = 0, // How many times the symbol is the root of an lvaue tree
uses: u64 = 0,
defs: u64 = 0,

defined: bool, // Used for decorating identifiers. True when the symbol is defined at the identifier
validation_state: Symbol_Validation_State,
init_validation_state: Symbol_Validation_State,
param: bool, // True when the symbol is a parameter in a function
is_temp: bool = false, // True

// Offset
offset: ?i64, // The offset from the BP that this symbol

pub fn init(
    scope: *Scope,
    name: []const u8,
    span: Span,
    _type: *ast_.AST,
    _init: ?*ast_.AST,
    decl: ?*ast_.AST,
    kind: Kind,
    allocator: std.mem.Allocator,
) *Self {
    var retval = allocator.create(Self) catch unreachable;
    retval.scope = scope;
    retval.name = name;
    retval.span = span;
    retval._type = _type;
    retval.expanded_type = null;
    retval.init = _init;
    retval.decl = decl;
    retval.is_alias = if (decl != null and decl.?.* == .decl) decl.?.decl.is_alias else false;
    retval.aliases = 0;
    retval.roots = 0;
    retval.uses = 0;
    retval.offset = null;
    retval.kind = kind;
    retval.cfg = null;
    if (kind == .@"fn" or kind == .@"const" or kind == .@"comptime") {
        retval.defined = true;
    } else {
        retval.defined = false;
    }
    retval.validation_state = .unvalidated;
    retval.init_validation_state = .unvalidated;
    return retval;
}

pub fn assert_symbol_valid(self: *Self) *Self {
    self.validation_state = Symbol_Validation_State{ .valid = .{ .valid_form = self } };
    return self;
}

pub fn assert_init_valid(self: *Self) *Self {
    self.init_validation_state = Symbol_Validation_State{ .valid = .{ .valid_form = self } };
    return self;
}
