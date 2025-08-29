const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const Symbol = @import("symbol.zig");
const module_ = @import("../hierarchy/module.zig");
const UID_Gen = @import("../util/uid_gen.zig");

const Self = @This();

const Lookup_Result = union(enum) { found_but_rt, found_but_fn, not_found, found: *Symbol };

parent: ?*Self,
children: std.ArrayList(*Self),
symbols: std.StringArrayHashMap(*Symbol),
traits: std.ArrayList(*ast_.AST), // List of all `trait`s in this scope. Added to in the `decorate` phase.
impls: std.ArrayList(*ast_.AST), // List of all `impl`s in this scope Added to in the `decorate` phase.
tests: std.ArrayList(*ast_.AST), // List of all `test`s in this scope Added to in the `decorate` phase.
module: ?*module_.Module, // Enclosing module
uid: usize,
uid_gen: *UID_Gen,

function_depth: usize = 0,
inner_function: ?*Symbol = null,

pub fn init(parent: ?*Self, uid_gen: *UID_Gen, allocator: std.mem.Allocator) *Self {
    var retval = allocator.create(Self) catch unreachable;
    retval.parent = parent;
    retval.children = std.ArrayList(*Self).init(allocator);
    retval.symbols = std.StringArrayHashMap(*Symbol).init(allocator);
    retval.traits = std.ArrayList(*ast_.AST).init(allocator);
    retval.impls = std.ArrayList(*ast_.AST).init(allocator);
    retval.tests = std.ArrayList(*ast_.AST).init(allocator);
    retval.uid = uid_gen.uid();
    retval.uid_gen = uid_gen;
    if (parent) |_parent| {
        _parent.children.append(retval) catch unreachable;
        retval.function_depth = _parent.function_depth;
        retval.inner_function = _parent.inner_function;
        retval.module = _parent.module;
    } else {
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

pub fn lookup(self: *Self, name: []const u8, flags: Lookup_Flags) Lookup_Result {
    if (false) {
        const found = self.symbols.get(name) != null;
        std.debug.print("searching for: {s} {}({})\n", .{ name, found, flags });
        self.pprint();
    }

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
pub fn impl_trait_lookup(self: *Self, for_type: *ast_.AST, trait: *Symbol) Impl_Trait_Lookup_Result {
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
pub fn lookup_impl_member(self: *Self, for_type: *ast_.AST, name: []const u8) ?*ast_.AST {
    std.debug.assert(for_type.* != .@"comptime"); // these must be in expanded form
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

    // Search for any imports
    for (self.symbols.keys()) |symbol_name| {
        const symbol = self.symbols.get(symbol_name).?;
        if (symbol.kind == .import) {
            const res = self.parent.?.lookup(symbol.kind.import.real_name, .{ .allow_modules = true });
            switch (res) {
                .found => {
                    const module_scope = res.found.init_value.?.scope().?;
                    const module_scope_lookup = module_scope.lookup_impl_member(for_type, name);
                    if (module_scope_lookup != null) {
                        return module_scope_lookup;
                    }
                },
                else => std.debug.panic("compiler error: import didn't resolve to a module: {s}", .{symbol.kind.import.real_name}),
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

pub fn pprint(self: *Self) void {
    std.debug.print("scope_{}:\n", .{self.uid});
    for (self.symbols.keys()) |name| {
        const symbol = self.symbols.get(name).?;
        std.debug.print("  {s} {s}\n", .{ @tagName(symbol.kind), name });
    }
}

pub fn put_symbol(scope: *Self, symbol: *Symbol, errors: *errs_.Errors) error{CompileError}!void {
    const res = scope.lookup(symbol.name, .{});
    switch (res) {
        .found => {
            const first = res.found;
            errors.add_error(errs_.Error{ .redefinition = .{
                .first_defined_span = first.span,
                .redefined_span = symbol.span,
                .name = symbol.name,
            } });
            return error.CompileError;
        },
        else => scope.symbols.put(symbol.name, symbol) catch unreachable,
    }
}

pub fn put_all_symbols(scope: *Self, symbols: *std.ArrayList(*Symbol), errors: *errs_.Errors) error{CompileError}!void {
    for (symbols.items) |symbol| {
        try scope.put_symbol(symbol, errors);
    }
}

pub fn collect_traits_and_impls(
    self: *Self,
    traits: *std.ArrayList(*ast_.AST),
    impls: *std.ArrayList(*ast_.AST),
) void {
    traits.appendSlice(self.traits.items) catch unreachable;
    impls.appendSlice(self.impls.items) catch unreachable;

    for (self.children.items) |child| {
        child.collect_traits_and_impls(traits, impls);
    }
}

pub fn collect_tests(
    self: *Self,
    tests: *std.ArrayList(*ast_.AST),
) void {
    tests.appendSlice(self.tests.items) catch unreachable;

    for (self.children.items) |child| {
        child.collect_tests(tests);
    }
}
