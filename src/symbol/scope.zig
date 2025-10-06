const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Decorate = @import("../ast/decorate.zig");
const Decorate_Access = @import("../ast/decorate-access.zig");
const errs_ = @import("../util/errors.zig");
const Symbol = @import("symbol.zig");
const Symbol_Tree = @import("../ast/symbol-tree.zig");
const module_ = @import("../hierarchy/module.zig");
const unification_ = @import("../types/unification.zig");
const UID_Gen = @import("../util/uid_gen.zig");
const walker_ = @import("../ast/walker.zig");
const Type_AST = @import("../types/type.zig").Type_AST;

const Self = @This();

const Lookup_Result = union(enum) { found_but_rt, found_but_fn, not_found, found: *Symbol };

parent: ?*Self,
children: std.array_list.Managed(*Self),
symbols: std.StringArrayHashMap(*Symbol),
traits: std.array_list.Managed(*ast_.AST), // List of all `trait`s in this scope. Added to in the `decorate` phase.
impls: std.array_list.Managed(*ast_.AST), // List of all `impl`s in this scope Added to in the `decorate` phase.
tests: std.array_list.Managed(*ast_.AST), // List of all `test`s in this scope Added to in the `decorate` phase.
module: ?*module_.Module, // Enclosing module
uid: usize,
uid_gen: *UID_Gen,

function_depth: usize = 0,
inner_function: ?*Symbol = null,

pub fn init(parent: ?*Self, uid_gen: *UID_Gen, allocator: std.mem.Allocator) *Self {
    var retval = allocator.create(Self) catch unreachable;
    retval.parent = parent;
    retval.children = std.array_list.Managed(*Self).init(allocator);
    retval.symbols = std.StringArrayHashMap(*Symbol).init(allocator);
    retval.traits = std.array_list.Managed(*ast_.AST).init(allocator);
    retval.impls = std.array_list.Managed(*ast_.AST).init(allocator);
    retval.tests = std.array_list.Managed(*ast_.AST).init(allocator);
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
        return res;
    } else {
        // Did not find the symbol at all
        return .not_found;
    }
}

const Impl_Trait_Lookup_Result = struct { count: u8, ast: ?*ast_.AST };

/// Returns the number of impls found for a given type-trait pair, and the impl ast. The impl is unique if count == 1.
pub fn impl_trait_lookup(self: *Self, for_type: *Type_AST, trait: *Symbol) Impl_Trait_Lookup_Result {
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
pub fn lookup_impl_member(self: *Self, for_type: *Type_AST, name: []const u8, compiler: *Compiler_Context) !?*ast_.AST {
    if (false) {
        std.debug.print("searching for {f}::{s}\n", .{ for_type, name });
    }
    // Go through the list of implementations, check to see if the types and traits match
    for (self.impls.items) |impl| {
        var subst = unification_.Substitutions.init(std.heap.page_allocator);
        defer subst.deinit();
        try compiler.validate_type.validate(impl.impl._type);
        unification_.unify(impl.impl._type, for_type, impl.impl._generic_params, &subst) catch continue;

        // TODO:
        // - attempt to unify for_type and impl._type given impl's `with` list that defines type parameters (nop for concrete impl), or continue
        // - check types/constraints (nop for concrete impl), or continue
        // - let TheImpl = the instantiation given the unification parameters (nop for concrete impl), create if doesnt exist (Q: Where are these stored? In the impl? How is lookup based on unification parameters done?)
        // - perform normal method lookup on TheImpl
        var the_impl = impl;
        if (impl.impl._generic_params.items.len > 0) {
            const with_list = unification_.type_param_list_from_subst_map(&subst, impl.impl._generic_params, std.heap.page_allocator);
            if (impl.impl.instantiations.get(with_list) == null) {
                const new_impl: *ast_.AST = impl.clone(&subst, std.heap.page_allocator);
                const new_scope = init(self, self.uid_gen, std.heap.page_allocator);

                new_impl.set_scope(new_scope);

                // Define each parameter in the new scope
                // var const_decls = std.array_list.Managed(*ast_.AST).init(compiler.allocator());
                // for (impl.impl._generic_params.items) |type_param| {
                //     const decl_init = subst.get(type_param.token().data);
                //     const decl = ast_.AST.create_type_alias(
                //         type_param.token(),
                //         ast_.AST.create_pattern_symbol(type_param.token(), .type, .local, name, compiler.allocator()),
                //         decl_init,
                //         std.array_list.Managed(*ast_.AST).init(compiler.allocator()),
                //         compiler.allocator(),
                //     );
                //     const_decls.append(decl) catch unreachable;
                // }

                try walker_.walk_ast(new_impl, Symbol_Tree.new(new_scope, &compiler.errors, compiler.allocator()));

                if (new_impl.impl.trait == null or new_impl.impl.impls_anon_trait) {
                    // impl'd for an anon trait, create an anon trait for it
                    // TODO: if there is a withlist, define the withs in the traits scope (?)
                    var token = new_impl.token();
                    token.kind = .identifier;
                    token.data = Symbol_Tree.next_anon_name("Trait", compiler.allocator());
                    const anon_trait = ast_.AST.create_trait(
                        token,
                        new_impl.impl.method_defs,
                        new_impl.impl.const_defs,
                        compiler.allocator(),
                    );
                    try walker_.walk_ast(anon_trait, Symbol_Tree.new(new_scope, &compiler.errors, compiler.allocator()));
                    new_impl.impl.trait = ast_.AST.create_identifier(token, compiler.allocator());
                    new_impl.impl.impls_anon_trait = true;
                }

                // Decorate identifiers, validate
                const decorate_context = Decorate.new(new_scope, &compiler.errors, compiler.allocator());
                const decorate_access_context = Decorate_Access.new(new_scope, &compiler.errors, compiler);
                // for (const_decls.items) |decl| {
                //     try walker_.walk_ast(decl, decorate_context);
                //     try walker_.walk_ast(decl, decorate_access_context);
                // }
                try walker_.walk_ast(new_impl, decorate_context); // this doesn't know about the anonymous trait
                try walker_.walk_ast(new_impl, decorate_access_context);
                try compiler.validate_scope.validate(new_scope);

                impl.impl.instantiations.put(with_list, new_impl) catch unreachable;
            }
            the_impl = impl.impl.instantiations.get(with_list).?; // TODO: substitutions need to be in the same order as withs
        }
        return search_impl(the_impl, name) orelse continue;
    }

    // Search for any imports
    for (self.symbols.keys()) |symbol_name| {
        const symbol = self.symbols.get(symbol_name).?;
        if (symbol.kind == .import) {
            var res_symbol: *Symbol = undefined;
            if (symbol.kind.import.real_symbol != null) {
                res_symbol = symbol.kind.import.real_symbol.?;
            } else {
                const res = self.parent.?.lookup(symbol.kind.import.real_name, .{ .allow_modules = true });
                switch (res) {
                    .found => {
                        res_symbol = res.found;
                    },
                    else => std.debug.panic("compiler error: import didn't resolve to a module: {s}", .{symbol.kind.import.real_name}),
                }
            }

            const module_scope = res_symbol.init_value().?.scope().?;
            const module_scope_lookup = try module_scope.lookup_impl_member(for_type, name, compiler);
            if (module_scope_lookup != null) {
                return module_scope_lookup;
            }
        }
    }

    if (self.parent != null) {
        // Did not match in this scope. Try parent scope
        return self.parent.?.lookup_impl_member(for_type, name, compiler);
    } else {
        // Not found, parent scope is null
        return null;
    }
}

fn search_impl(impl: *ast_.AST, name: []const u8) ?*ast_.AST {
    for (impl.impl.method_defs.items) |method_def| {
        if (std.mem.eql(u8, method_def.method_decl.name.token().data, name)) {
            return method_def;
        }
    }
    for (impl.impl.const_defs.items) |const_def| {
        if (std.mem.eql(u8, const_def.binding.pattern.symbol().?.name, name)) {
            return const_def;
        }
    }
    return null;
}

pub fn pprint(self: *Self) void {
    std.debug.print("scope_{}:\n", .{self.uid});
    for (self.symbols.keys()) |name| {
        const symbol = self.symbols.get(name).?;
        std.debug.print("  {s} {s} \n", .{ @tagName(symbol.kind), name });
    }
}

pub fn put_symbol(scope: *Self, symbol: *Symbol, errors: *errs_.Errors) error{CompileError}!void {
    const res = scope.lookup(symbol.name, .{});
    switch (res) {
        .found => {
            const first = res.found;
            errors.add_error(errs_.Error{ .redefinition = .{
                .first_defined_span = first.span(),
                .redefined_span = symbol.span(),
                .name = symbol.name,
            } });
            return error.CompileError;
        },
        else => scope.symbols.put(symbol.name, symbol) catch unreachable,
    }
}

pub fn put_all_symbols(scope: *Self, symbols: *std.array_list.Managed(*Symbol), errors: *errs_.Errors) error{CompileError}!void {
    for (symbols.items) |symbol| {
        try scope.put_symbol(symbol, errors);
    }
}

pub fn collect_traits_and_impls(
    self: *Self,
    traits: *std.array_list.Managed(*ast_.AST),
    impls: *std.array_list.Managed(*ast_.AST),
) void {
    traits.appendSlice(self.traits.items) catch unreachable;
    impls.appendSlice(self.impls.items) catch unreachable;

    for (self.children.items) |child| {
        child.collect_traits_and_impls(traits, impls);
    }
}

pub fn collect_tests(
    self: *Self,
    tests: *std.array_list.Managed(*ast_.AST),
) void {
    tests.appendSlice(self.tests.items) catch unreachable;

    for (self.children.items) |child| {
        child.collect_tests(tests);
    }
}
