const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const module_ = @import("module.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;
const validation_state_ = @import("validation_state.zig");

const Lookup_Result = union(enum) { found_but_rt, found_but_fn, not_found, found: *Symbol };

var scope_UID: usize = 0;
pub const Scope = struct {
    parent: ?*Scope,
    children: std.ArrayList(*Scope),
    symbols: std.StringArrayHashMap(*Symbol),
    traits: std.ArrayList(*ast_.AST), // List of all `trait`s in this scope. Added to in the `decorate` phase.
    impls: std.ArrayList(*ast_.AST), // List of all `impl`s in this scope Added to in the `decorate` phase.
    module: ?*module_.Module, // Enclosing module
    name: []const u8,
    uid: usize,

    function_depth: usize = 0,
    in_loop: bool = false,
    defers: std.ArrayList(*ast_.AST),
    errdefers: std.ArrayList(*ast_.AST),
    inner_function: ?*Symbol = null,
    is_param_scope: bool = false, // true when this scope encompases function parameters and externs. prohibits defaults from being generated

    pub fn init(parent: ?*Scope, name: []const u8, allocator: std.mem.Allocator) *Scope {
        var retval = allocator.create(Scope) catch unreachable;
        retval.parent = parent;
        retval.children = std.ArrayList(*Scope).init(allocator);
        retval.symbols = std.StringArrayHashMap(*Symbol).init(allocator);
        retval.traits = std.ArrayList(*ast_.AST).init(allocator);
        retval.impls = std.ArrayList(*ast_.AST).init(allocator);
        retval.name = name;
        retval.uid = scope_UID;
        retval.defers = std.ArrayList(*ast_.AST).init(allocator);
        retval.errdefers = std.ArrayList(*ast_.AST).init(allocator);
        scope_UID += 1;
        if (parent) |_parent| {
            _parent.children.append(retval) catch unreachable;
            retval.in_loop = _parent.in_loop;
            retval.function_depth = _parent.function_depth;
            retval.inner_function = _parent.inner_function;
            retval.module = _parent.module;
        } else {
            retval.in_loop = false;
            retval.function_depth = 0;
            retval.inner_function = null;
            retval.module = null;
        }
        return retval;
    }

    pub const Lookup_Flags = struct {
        crossed_boundary: bool = false,
        allow_modules: bool = false,
    };
    pub fn lookup(self: *Scope, name: []const u8, flags: Lookup_Flags) Lookup_Result {
        if (self.symbols.get(name)) |symbol| {
            if (!flags.allow_modules and symbol.kind == .module) {
                if (self.parent) |parent| {
                    var new_flags = flags;
                    new_flags.crossed_boundary = parent.function_depth < self.function_depth or flags.crossed_boundary;
                    return parent.lookup(name, new_flags);
                } else {
                    return .not_found;
                }
            }

            if (flags.crossed_boundary and (symbol.kind == .mut or symbol.kind == .let)) {
                // Found the symbol, but it's non-const and we've crossed an inner-function boundary
                return .found_but_fn;
            } else {
                // Found the symbol just fine
                return Lookup_Result{ .found = symbol };
            }
        } else if (self.parent) |parent| {
            var new_flags = flags;
            new_flags.crossed_boundary = parent.function_depth < self.function_depth or flags.crossed_boundary;
            const res = parent.lookup(name, new_flags);
            if (res == .found_but_fn and self.inner_function != null and self.inner_function.?.kind == .@"comptime") {
                // If have to cross a `comptime` boundary, change fn error to rt error
                return .found_but_rt;
            } else {
                // (normal recursion)
                return res;
            }
        } else {
            // Did not find the symbol at all
            return .not_found;
        }
    }

    const Impl_Trait_Lookup_Result = struct { count: u8, ast: ?*ast_.AST };

    /// Returns the number of impls found for a given type-trait pair, and the impl ast. The impl is unique if count == 1.
    pub fn impl_trait_lookup(self: *Scope, for_type: *ast_.AST, trait: *Symbol) Impl_Trait_Lookup_Result {
        var retval: Impl_Trait_Lookup_Result = .{ .count = 0, .ast = null };

        // Go through the scope's list of implementations, check to see if the types and traits match
        for (self.impls.items) |impl| {
            const types_match = (impl.impl._type.types_match(for_type) or for_type.types_match(impl.impl._type));
            const traits_match = impl.impl.trait.?.symbol() == trait;
            if (types_match and traits_match) {
                retval.count += 1;
                retval.ast = retval.ast orelse impl;
            }
        }

        if (self.parent != null) {
            // Did not match in this scope. Try parent scope
            const parent_res = self.parent.?.impl_trait_lookup(for_type, trait);
            retval.count += parent_res.count;
            retval.ast = retval.ast orelse parent_res.ast;
            return retval;
        } else {
            // Not found, parent scope is null
            return retval;
        }
    }

    /// Looks up the impl's decl/method_decl ast for a given type, with a given name
    pub fn lookup_impl_member(self: *Scope, for_type: *ast_.AST, name: []const u8) ?*ast_.AST {
        if (!for_type.valid_type()) {
            return null;
        }
        // Go through the list of implementations, check to see if the types and traits match
        for (self.impls.items) |impl| {
            if (!impl.impl._type.valid_type()) {
                // The type of the impl isn't even valid
                // This is an edge case for badly formed programs
                return null;
            }
            if (!impl.impl._type.types_match(for_type) or !for_type.types_match(impl.impl._type)) {
                // The type for this impl does not equal the given type
                continue;
            }
            for (impl.impl.method_defs.items) |method_def| {
                if (std.mem.eql(u8, method_def.method_decl.name.token().data, name)) {
                    return method_def;
                }
            }
            for (impl.impl.const_defs.items) |const_def| {
                if (std.mem.eql(u8, const_def.decl.symbols.items[0].name, name)) {
                    return const_def;
                }
            }
        }

        if (self.parent != null) {
            // Did not match in this scope. Try parent scope
            return self.parent.?.lookup_impl_member(for_type, name);
        } else {
            // Not found, parent scope is null
            return null;
        }
    }

    /// Given a scope and a type, fills in a map of methods defined for that type in that scope.
    pub fn fill_method_map(self: *Scope, for_type: *ast_.AST, method_map: *std.StringArrayHashMap(*ast_.AST)) void {
        // TODO: Is this even called?
        if (self.parent != null) {
            self.parent.?.fill_method_map(for_type, method_map);
        }
        for (self.impls.items) |impl| {
            if (!impl.impl._type.types_match(for_type) or !for_type.types_match(impl.impl._type)) {
                // Types do not match
                continue;
            }
            for (impl.impl.method_defs.items) |def| {
                if (method_map.get(def.decl.symbols.items[0].name)) {
                    unreachable; // TODO: Give an error about redefining a method for a given type
                }
                method_map.put(def.decl.symbols.items[0].name, def);
            }
        }
    }

    pub fn pprint(self: *Scope) void {
        std.debug.print("scope_{}:\n", .{self.uid});
        for (self.symbols.keys()) |name| {
            const symbol = self.symbols.get(name).?;
            std.debug.print("  {s} {s}\n", .{ @tagName(symbol.kind), name });
        }
    }
};

pub const Symbol_Kind = union(enum) {
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

pub const Symbol_Validation_State = validation_state_.Validation_State(*Symbol);

var number_of_comptime: usize = 0;
pub const Symbol = struct {
    // TODO: Much like AST, create a symbol-create.zig, and usingnamespace it here with `create_comptime_init`, `create_symbol`, `create_method_type`, `create_temp_comptime_symbol`, `create_template_symbol`, `create_function_symbol`, and any other supporting infra
    scope: *Scope, // Enclosing parent scope
    name: []const u8,
    span: span_.Span,
    _type: *ast_.AST,
    expanded_type: ?*ast_.AST,
    init: ?*ast_.AST,
    kind: Symbol_Kind,
    cfg: ?*cfg_.CFG,
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
    decld: bool, // True when the symbol is a local variable, whether or not the variable has been printed out or not
    param: bool, // True when the symbol is a parameter in a function
    is_temp: bool = false, // True

    // Offset
    offset: ?i64, // The offset from the BP that this symbol

    pub fn init(
        scope: *Scope,
        name: []const u8,
        span: span_.Span,
        _type: *ast_.AST,
        _init: ?*ast_.AST,
        decl: ?*ast_.AST,
        kind: Symbol_Kind,
        allocator: std.mem.Allocator,
    ) *Symbol {
        var retval = allocator.create(Symbol) catch unreachable;
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
        retval.decld = false;
        return retval;
    }

    pub fn assert_symbol_valid(self: *Symbol) *Symbol {
        self.validation_state = Symbol_Validation_State{ .valid = .{ .valid_form = self } };
        return self;
    }

    pub fn assert_init_valid(self: *Symbol) *Symbol {
        self.init_validation_state = Symbol_Validation_State{ .valid = .{ .valid_form = self } };
        return self;
    }
};
