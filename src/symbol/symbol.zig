const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const CFG = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const Scope = @import("../symbol/scope.zig");
const Span = @import("../util/span.zig");
const Token = @import("../lexer/token.zig");
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
init_value: ?*ast_.AST,
kind: Kind,
cfg: ?*CFG,
decl: ?*ast_.AST,

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
    retval.init_value = _init;
    retval.decl = decl;
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

/// when this is true, this symbol is a type-alias, and should be expanded before use
pub fn is_alias(self: *Self) bool {
    return if (self.decl != null and self.decl.?.* == .decl) self.decl.?.decl.is_alias else false;
}

pub fn lvalue_is_symbol(self: *Self, return_symbol: *Self) bool {
    return !self.is_temp and // isnt temporary
        self != return_symbol // isnt the function's return value
    ;
}

pub fn err_if_undefined(self: *Self, errors: *errs_.Errors) error{CompileError}!void {
    if (self.kind != .import and !self.defined) {
        errors.add_error(errs_.Error{ .use_before_def = .{ .identifier = Token.init_simple(self.name) } });
        return error.CompileError;
    }
}

/// Throws an `error.CompileError` if a symbol is not used.
pub fn err_if_unused(self: *Self, errors: *errs_.Errors) error{CompileError}!void {
    if (self.kind != .@"const" and
        self.uses == 0)
    {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = self.span,
            .context_span = null,
            .name = self.name,
            .problem = "is never used",
            .context_message = "",
        } });
        return error.CompileError;
    }
}

pub fn err_if_undefd(self: *Self, errors: *errs_.Errors, use: Span) error{CompileError}!void {
    // std.debug.print("{s} uses:{} defs:{}\n", .{ symbol.name, symbol.uses, symbol.defs });
    if (self.uses != 0 and // symbol has been used somewhere
        self.defs == 0 and // symbol hasn't been defined anywhere
        !self.param and // symbol isn't a parameter (these don't have defs!)
        self.kind != .@"extern" // symbol isn't an extern (these also don't have defs!)
    ) {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = use,
            .context_span = self.span,
            .name = self.name,
            .problem = "is never defined",
            .context_message = "declared here",
        } });
        return error.CompileError;
    }
}

/// Throws an `error.CompileError` if a symbol is marked `mut`, but is never mutated.
///
/// Symbols are mutated when:
/// - They are the root of at least one Instruction's destination's L-Value tree, OR
/// - They are aliased with `&mut`.
pub fn err_if_var_not_mutated(self: *Self, errors: *errs_.Errors) error{CompileError}!void {
    if (self.kind == .mut and
        self.aliases == 0 and
        self.roots == 0)
    {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = self.span,
            .context_span = null,
            .name = self.name,
            .problem = "is marked `mut` but is never mutated",
            .context_message = "",
        } });
        return error.CompileError;
    }
}

pub fn set_offset(self: *Self, local_offsets: i64) i64 {
    self.offset = local_offsets;
    return @as(i64, @intCast(self.expanded_type.?.sizeof()));
}

pub fn represents_method(self: *Self, impl_for_type: *ast_.AST, method_name: []const u8) bool {
    return self.decl != null and
        self.decl.?.* == .method_decl and
        self.decl.?.method_decl.impl != null and
        self.decl.?.method_decl.impl.?.impl._type.types_match(impl_for_type) and
        std.mem.eql(u8, self.name, method_name);
}
