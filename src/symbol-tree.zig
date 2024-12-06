const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const primitives_ = @import("primitives.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const token_ = @import("token.zig");

const Symbol_Error_Enum = error{SymbolError};

pub fn symbol_table_from_AST_list(
    asts: std.ArrayList(*ast_.AST),
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!void {
    for (asts.items) |ast| {
        try symbol_table_from_AST(ast, scope, errors, allocator);
    }
}

/// Takes in an ast, returns the scope constructed from that AST node
/// Most AST nodes don't do anything, except blocks and decls, which can be buried deep in an AST
///
/// ### Parameters
/// - `maybe_ast`: Possible AST node to construct symbol table from
/// - `scope`: Working scope, to place symbols and child scopes in
/// - `errors`: Error handler
/// - `allocator`: Allocator
///
/// ### Returns
/// Nothing.
///
/// ### Errors
/// Errors out for various semantic checks.
fn symbol_table_from_AST(
    maybe_ast: ?*ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!void {
    if (maybe_ast == null) {
        return;
    }
    const ast = maybe_ast.?;
    // std.debug.print("{}\n", .{ast});
    switch (ast.*) {
        .anyptr_type,
        .unit_type,
        .unit_value,
        .int,
        .char,
        .float,
        .string,
        .field,
        .identifier,
        .@"unreachable",
        .true,
        .false,
        .poison,
        .pattern_symbol,
        .receiver,
        .template,
        => {},

        .@"break", .@"continue" => try in_loop_check(ast, scope, errors),

        .type_of,
        .domain_of,
        .size_of,
        .default,
        .not,
        .negate,
        .dereference,
        .slice_of,
        .dyn_type,
        .dyn_value,
        => try symbol_table_from_AST(ast.expr(), scope, errors, allocator),

        .addr_of => {
            try symbol_table_from_AST(ast.expr(), scope, errors, allocator);
            ast.addr_of.scope = scope;
        },

        .@"try" => {
            ast.set_symbol(try in_function_check(ast, scope, errors));
            try symbol_table_from_AST(ast.expr(), scope, errors, allocator);
        },

        .@"comptime" => {
            const symbol = try create_temp_comptime_symbol(ast.expr(), null, scope, errors, allocator);
            try put_symbol(symbol, scope, errors); // Why? No one refers to it...
            ast.set_symbol(symbol);
        },

        .assign,
        .@"or",
        .@"and",
        .add,
        .sub,
        .mult,
        .div,
        .mod,
        .equal,
        .not_equal,
        .greater,
        .lesser,
        .greater_equal,
        .lesser_equal,
        .index,
        .select,
        .function,
        .@"union",
        .@"catch",
        .@"orelse",
        => {
            try symbol_table_from_AST(ast.lhs(), scope, errors, allocator);
            try symbol_table_from_AST(ast.rhs(), scope, errors, allocator);
        },
        .access => {
            ast.access.scope = scope; // CANNOT do lookup here, because we do not have type info yet
            try symbol_table_from_AST(ast.lhs(), scope, errors, allocator);
        },
        .invoke => {
            ast.invoke.scope = scope; // CANNOT do lookup here, because we do not have type info yet
            try symbol_table_from_AST(ast.lhs(), scope, errors, allocator);
            try symbol_table_from_AST_list(ast.children().*, scope, errors, allocator);
        },
        .call => {
            try symbol_table_from_AST(ast.lhs(), scope, errors, allocator);
            try symbol_table_from_AST_list(ast.children().*, scope, errors, allocator);
        },
        .sum_type, .product => try symbol_table_from_AST_list(ast.children().*, scope, errors, allocator),
        .sum_value => {
            try symbol_table_from_AST(ast.sum_value.init, scope, errors, allocator);
            try symbol_table_from_AST(ast.sum_value.base, scope, errors, allocator);
        },

        .array_of => {
            try symbol_table_from_AST(ast.expr(), scope, errors, allocator);
            try symbol_table_from_AST(ast.array_of.len, scope, errors, allocator);
        },
        .sub_slice => {
            try symbol_table_from_AST(ast.sub_slice.super, scope, errors, allocator);
            try symbol_table_from_AST(ast.sub_slice.lower, scope, errors, allocator);
            try symbol_table_from_AST(ast.sub_slice.upper, scope, errors, allocator);
        },
        .annotation => {
            try symbol_table_from_AST(ast.annotation.type, scope, errors, allocator);
            try symbol_table_from_AST(ast.annotation.predicate, scope, errors, allocator);
            try symbol_table_from_AST(ast.annotation.init, scope, errors, allocator);
        },

        .@"if" => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast.@"if".scope = new_scope;
            try symbol_table_from_AST(ast.@"if".let, scope, errors, allocator);
            try symbol_table_from_AST(ast.@"if".condition, new_scope, errors, allocator);
            try symbol_table_from_AST(ast.body_block(), new_scope, errors, allocator);
            try symbol_table_from_AST(ast.else_block(), new_scope, errors, allocator);
        },
        .match => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast.match.scope = new_scope;
            try symbol_table_from_AST(ast.match.let, scope, errors, allocator);
            try symbol_table_from_AST(ast.expr(), new_scope, errors, allocator);
            try create_match_pattern_symbol(ast, new_scope, errors, allocator);
            try symbol_table_from_AST_list(ast.children().*, new_scope, errors, allocator);
        },
        .mapping => try symbol_table_from_AST(ast.lhs(), scope, errors, allocator),
        .@"while" => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            var loop_scope = symbol_.Scope.init(new_scope, "", allocator); // let, cond, post are NOT in loop scope
            loop_scope.in_loop = true;
            ast.@"while".scope = new_scope;
            try symbol_table_from_AST(ast.@"while".let, new_scope, errors, allocator);
            try symbol_table_from_AST(ast.@"while".condition, new_scope, errors, allocator);
            try symbol_table_from_AST(ast.@"while".post, new_scope, errors, allocator);
            try symbol_table_from_AST(ast.body_block(), loop_scope, errors, allocator);
            try symbol_table_from_AST(ast.else_block(), loop_scope, errors, allocator);
        },
        .@"for" => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast.@"for".scope = new_scope;
            try symbol_table_from_AST(ast.@"for".let, scope, errors, allocator);
            try symbol_table_from_AST(ast.@"for".elem, scope, errors, allocator);
            try symbol_table_from_AST(ast.@"for".iterable, scope, errors, allocator);
            try symbol_table_from_AST(ast.body_block(), scope, errors, allocator);
            try symbol_table_from_AST(ast.else_block(), scope, errors, allocator);
        },
        .block => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast.block.scope = new_scope;
            try symbol_table_from_AST_list(ast.children().*, new_scope, errors, allocator);
            if (ast.block.final) |final| {
                try symbol_table_from_AST(final, new_scope, errors, allocator);
            }
        },

        .@"return" => {
            ast.set_symbol(try in_function_check(ast, scope, errors));
            try symbol_table_from_AST(ast.@"return"._ret_expr, scope, errors, allocator);
        },
        .decl => {
            // Both put a Symbol in the current scope, and recurse
            try create_symbol(&ast.decl.symbols, ast.decl.pattern, ast, ast.decl.type, ast.decl.init, scope, errors, allocator);
            try put_all_symbols(&ast.decl.symbols, scope, errors);
            try symbol_table_from_AST(ast.decl.type, scope, errors, allocator);
            try symbol_table_from_AST(ast.decl.init, scope, errors, allocator);

            if (ast.decl.top_level) {
                for (ast.decl.symbols.items) |symbol| {
                    if (symbol.kind != .@"const" and symbol.kind != .@"extern") {
                        std.debug.print("{}\n", .{ast.decl.pattern.pattern_symbol.kind});
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = symbol.span,
                            .msg = "top level symbols must be marked `const`",
                        } });
                        return error.SymbolError;
                    }
                }
            }

            if (!scope.is_param_scope and ast.decl.init == null) {
                // If this isn't a parameter, and the init is null, set the init to the default value of the type
                ast.decl.init = ast_.AST.create_default(ast.token(), ast.decl.type, allocator);
            }
        },
        .fn_decl => {
            if (ast.symbol() != null) {
                // Do not re-do symbol if already declared
                return;
            } else if (ast.fn_decl.is_templated()) {
                if (ast.fn_decl.name == null) {
                    errors.add_error(
                        errs_.Error{
                            .basic = .{
                                .msg = "anonymous functions specified with const parameters", // TODOL Could use some better wording
                                .span = ast.token().span,
                            },
                        },
                    );
                    return error.SymbolError;
                }
                // Template declaration, transform function into template
                // Clone the fn declaration and keep it to be templated out when stamping
                const template_pattern_fn_decl = ast.clone(allocator);
                const common = ast_.AST_Common{ ._token = ast.token(), ._type = null };
                ast.* = ast_.AST{ .template = .{
                    .common = common,
                    .decl = template_pattern_fn_decl,
                    .memo = null,
                } };
                const symbol = try create_template_symbol(ast, scope, allocator);
                try put_symbol(symbol, scope, errors);
                ast.set_symbol(symbol);
            } else {
                // Normal function declaration
                const symbol = try create_function_symbol(ast, scope, errors, allocator);
                try put_symbol(symbol, scope, errors);
                ast.set_symbol(symbol);
            }
        },
        .trait => {
            if (ast.symbol() != null) {
                // Do not re-do symboo if already declared
                return;
            }
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast.trait.scope = new_scope;
            const symbol = try create_trait_symbol(ast, scope, allocator);
            try put_symbol(symbol, scope, errors);
            ast.set_symbol(symbol);

            const self_type_decl = ast_.AST.create_decl(
                ast.token(),
                ast_.AST.create_symbol(token_.Token.init_simple("Self"), .@"const", "Self", allocator),
                primitives_.type_type,
                primitives_.unit_type,
                true,
                allocator,
            );
            try symbol_table_from_AST(self_type_decl, new_scope, errors, allocator);

            for (ast.trait.method_decls.items) |method_decl| {
                method_decl.method_decl.c_type = create_method_type(method_decl, allocator);
                try symbol_table_from_AST(method_decl, new_scope, errors, allocator);
            }
        },
        .impl => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast.impl.scope = new_scope;
            if (ast.impl.trait == null) {
                var token = ast.token();
                token.kind = .identifier;
                token.data = next_anon_name("trait", allocator);
                ast.impl.trait = ast_.AST.create_trait(
                    token,
                    ast.impl.method_defs,
                    ast.impl.const_defs,
                    allocator,
                );
                ast.impl.impls_anon_trait = true;
            }
            const self_type_decl = ast_.AST.create_decl(
                ast.token(),
                ast_.AST.create_symbol(token_.Token.init_simple("Self"), .@"const", "Self", allocator),
                primitives_.type_type,
                ast.impl._type,
                true,
                allocator,
            );
            try symbol_table_from_AST(ast.impl.trait, scope, errors, allocator);
            try symbol_table_from_AST(self_type_decl, new_scope, errors, allocator);
            try symbol_table_from_AST_list(ast.impl.method_defs, new_scope, errors, allocator);
            try symbol_table_from_AST_list(ast.impl.const_defs, new_scope, errors, allocator);
        },
        .method_decl => {
            if (ast.symbol() != null) {
                // Do not re-do symbol if already declared
                return;
            }
            if (ast.method_decl.init == null) {
                // Trait method decl
                var fn_scope = symbol_.Scope.init(scope, "", allocator);
                fn_scope.function_depth = scope.function_depth + 1;
                try symbol_table_from_AST_list(ast.children().*, fn_scope, errors, allocator);
                try symbol_table_from_AST(ast.method_decl.ret_type, fn_scope, errors, allocator);
            } else {
                // Impl method decl
                const symbol = try create_method_symbol(ast, scope, errors, allocator);
                try put_symbol(symbol, scope, errors);
                ast.set_symbol(symbol);
            }
        },
        .@"defer" => {
            scope.defers.append(ast.statement()) catch unreachable;
            try symbol_table_from_AST(ast.statement(), scope, errors, allocator);
        },
        .@"errdefer" => {
            scope.errdefers.append(ast.statement()) catch unreachable;
            try symbol_table_from_AST(ast.statement(), scope, errors, allocator);
        },
    }
}

fn in_loop_check(ast: *ast_.AST, scope: *symbol_.Scope, errors: *errs_.Errors) Symbol_Error_Enum!void {
    if (!scope.in_loop) {
        errors.add_error(errs_.Error{ .not_inside_loop = .{
            .span = ast.token().span,
            .name = @tagName(ast.*),
        } });
        return error.SymbolError;
    }
}

/// Returns the inner symbol of a scope, or an error if one doesnt exist
fn in_function_check(ast: *ast_.AST, scope: *symbol_.Scope, errors: *errs_.Errors) Symbol_Error_Enum!*symbol_.Symbol {
    if (scope.inner_function == null) {
        errors.add_error(errs_.Error{ .not_inside_function = .{
            .span = ast.token().span,
            .name = @tagName(ast.*),
        } });
        return error.SymbolError;
    } else if (scope.inner_function.?.kind == .@"comptime") {
        errors.add_error(errs_.Error{ .basic = .{
            .span = ast.token().span,
            .msg = "`return` cannot be within comptime",
        } });
        return error.SymbolError;
    } else {
        return scope.inner_function.?;
    }
}

pub fn put_symbol(symbol: *symbol_.Symbol, scope: *symbol_.Scope, errors: *errs_.Errors) Symbol_Error_Enum!void {
    const res = scope.lookup(symbol.name, false);
    switch (res) {
        .found => {
            const first = res.found;
            errors.add_error(errs_.Error{ .redefinition = .{
                .first_defined_span = first.span,
                .redefined_span = symbol.span,
                .name = symbol.name,
            } });
            return error.SymbolError;
        },
        else => scope.symbols.put(symbol.name, symbol) catch unreachable,
    }
}

fn put_all_symbols(symbols: *std.ArrayList(*symbol_.Symbol), scope: *symbol_.Scope, errors: *errs_.Errors) Symbol_Error_Enum!void {
    for (symbols.items) |symbol| {
        try put_symbol(symbol, scope, errors);
    }
}

/// Creates symbols from a given pattern, declaration, type, and initializer within the given scope.
fn create_symbol(
    symbols: *std.ArrayList(*symbol_.Symbol), // Mutable list that accumulates all the created symbols for a given scope, to be put() later.
    pattern: *ast_.AST, // Represents the pattern being matched; processed recursively to create symbols.
    decl: ?*ast_.AST, // Potential decl AST to be given to symbols.
    _type: *ast_.AST, // Type of the current pattern.
    init: ?*ast_.AST, // The value being matched on. Null for function parameter symbols.
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!void {
    switch (pattern.*) {
        .pattern_symbol => {
            if (std.mem.eql(u8, pattern.pattern_symbol.name, "_")) {
                if (pattern.pattern_symbol.kind != .let) {
                    // It is an error for `_` to be marked as `const` or `mut`
                    errors.add_error(errs_.Error{ .discard_marked = .{
                        .span = pattern.token().span,
                        .kind = pattern.pattern_symbol.kind,
                    } });
                    return error.SymbolError;
                } else {
                    // Register the symbol of the symbol pattern as the blackhole symbol, but do not append
                    pattern.set_symbol(primitives_.blackhole);
                    return;
                }
            }
            const symbol_init = if (pattern.pattern_symbol.kind != .@"const" or decl != null and decl.?.decl.is_alias)
                init
            else if (init != null)
                // Wrap init in comptime if symbol is const and non-alias
                try create_comptime_init(init.?, _type, scope, errors, allocator)
            else
                null;
            const symbol = symbol_.Symbol.init(
                scope,
                pattern.pattern_symbol.name,
                pattern.token().span,
                _type,
                symbol_init,
                decl,
                pattern.pattern_symbol.kind,
                allocator,
            );
            pattern.set_symbol(symbol);
            symbols.append(symbol) catch unreachable;
        },
        .product => {
            for (pattern.children().items, 0..) |term, i| {
                const index = ast_.AST.create_int(pattern.token(), i, allocator);
                const new_type: *ast_.AST = ast_.AST.create_index(_type.token(), _type, index, allocator);
                const new_init: *ast_.AST = ast_.AST.create_index(init.?.token(), init.?, index, allocator);
                try create_symbol(symbols, term, decl, new_type, new_init, scope, errors, allocator);
            }
        },
        .sum_value => {
            const lhs_type = ast_.AST.create_type_of(pattern.token(), init.?, allocator);
            const rhs_type = ast_.AST.create_domain_of(pattern.token(), lhs_type, pattern, allocator);

            if (pattern.sum_value.init != null) {
                // Here init is null!
                try create_symbol(symbols, pattern.sum_value.init.?, decl, rhs_type, pattern.sum_value.init.?, scope, errors, allocator);
            }
        },
        // Likely literals etc, for `match` mappings
        else => {},
    }
}

/// Creates and initializes pattern symbols for each mapping in a match expression, defining the symbols within the
/// mapping's scope.
fn create_match_pattern_symbol(match: *ast_.AST, scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) Symbol_Error_Enum!void {
    for (match.children().items) |mapping| {
        const new_scope = symbol_.Scope.init(scope, "", allocator);
        mapping.mapping.scope = new_scope;
        var symbols = std.ArrayList(*symbol_.Symbol).init(allocator);
        defer symbols.deinit();
        const match_expr = match.expr();
        const match_expr_token = match_expr.token();
        const _type = ast_.AST.create_type_of(match_expr_token, match_expr, allocator);
        try create_symbol(&symbols, mapping.lhs(), null, _type, match_expr, new_scope, errors, allocator);
        for (symbols.items) |symbol| {
            symbol.defined = true;
        }
        try put_all_symbols(&symbols, new_scope, errors);
        try symbol_table_from_AST(mapping.rhs(), new_scope, errors, allocator);
    }
}

pub fn create_function_symbol(
    ast: *ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!*symbol_.Symbol {
    // Calculate the domain type from the function paramter types
    const domain = extract_domain(ast.children().*, allocator);

    // Create the function type
    const _type = ast_.AST.create_function(
        ast.fn_decl.ret_type.token(),
        domain,
        ast.fn_decl.ret_type,
        allocator,
    );

    // Create the function scope
    var fn_scope = symbol_.Scope.init(scope, "", allocator);
    fn_scope.function_depth = scope.function_depth + 1;
    fn_scope.is_param_scope = true;

    // Recurse parameters and init
    try symbol_table_from_AST_list(ast.children().*, fn_scope, errors, allocator);
    try symbol_table_from_AST(ast.fn_decl.ret_type, fn_scope, errors, allocator);

    // Put the param symbols in the param symbols list
    for (ast.children().items) |param| {
        const symbol = param.decl.symbols.items[0];
        ast.fn_decl.param_symbols.append(symbol) catch unreachable;
    }

    const key_set = fn_scope.symbols.keys();
    for (0..key_set.len) |i| {
        const key = key_set[i];
        var symbol = fn_scope.symbols.get(key).?;
        symbol.defined = true;
        symbol.decld = true;
        symbol.param = true;
    }

    // Choose name (maybe anon)
    var buf: []const u8 = undefined;
    if (ast.fn_decl.name) |name| {
        buf = name.token().data;
    } else {
        buf = next_anon_name("anon", allocator);
    }
    const retval = symbol_.Symbol.init(
        fn_scope,
        buf,
        if (ast.fn_decl.name) |name| name.token().span else ast.token().span,
        _type,
        ast.fn_decl.init,
        ast,
        .@"fn",
        allocator,
    );
    fn_scope.inner_function = retval;

    try symbol_table_from_AST(ast.fn_decl.init, fn_scope, errors, allocator);
    return retval;
}

var num_anons: usize = 0;
fn next_anon_name(class: []const u8, allocator: std.mem.Allocator) []const u8 {
    defer num_anons += 1;
    var out = String.init(allocator);
    defer out.deinit();
    const writer = out.writer();
    writer.print("${s}{}", .{ class, num_anons }) catch unreachable;
    return (out.toOwned() catch unreachable).?;
}

pub fn extract_domain(params: std.ArrayList(*ast_.AST), allocator: std.mem.Allocator) *ast_.AST {
    if (params.items.len == 0) {
        return primitives_.unit_type;
    } else if (params.items.len <= 1) {
        return ast_.AST.create_annotation(
            params.items[0].token(),
            params.items[0].decl.pattern,
            params.items[0].decl.type,
            null,
            params.items[0].decl.init,
            allocator,
        );
    } else {
        std.debug.assert(params.items.len >= 2);
        var param_types = std.ArrayList(*ast_.AST).init(allocator);
        for (0..params.items.len) |i| {
            param_types.append(ast_.AST.create_annotation(
                params.items[i].token(),
                params.items[i].decl.pattern,
                params.items[i].decl.type,
                null,
                params.items[i].decl.init,
                allocator,
            )) catch unreachable;
        }
        const retval = ast_.AST.create_product(params.items[0].token(), param_types, allocator);
        return retval;
    }
}

fn extract_domain_with_receiver(impl_type: *ast_.AST, receiver: *ast_.AST, params: std.ArrayList(*ast_.AST), allocator: std.mem.Allocator) *ast_.AST {
    const _receiver_type = create_receiver_annot(create_receiver_addr(impl_type, receiver, allocator), receiver, allocator);
    if (params.items.len == 0) {
        return _receiver_type;
    } else {
        var param_types = std.ArrayList(*ast_.AST).init(allocator);
        param_types.append(_receiver_type) catch unreachable;
        for (0..params.items.len) |i| {
            param_types.append(ast_.AST.create_annotation(
                params.items[i].token(),
                params.items[i].decl.pattern,
                params.items[i].decl.type,
                null,
                params.items[i].decl.init,
                allocator,
            )) catch unreachable;
        }
        const retval = ast_.AST.create_product(params.items[0].token(), param_types, allocator);
        return retval;
    }
}

fn create_receiver_addr(impl_type: *ast_.AST, receiver: *ast_.AST, allocator: std.mem.Allocator) *ast_.AST {
    return switch (receiver.receiver.kind) {
        .value, .addr_of => ast_.AST.create_addr_of(receiver.token(), impl_type, false, allocator),
        .mut_addr_of => ast_.AST.create_addr_of(receiver.token(), impl_type, true, allocator),
    };
}

fn create_receiver_annot(receiver_addr: *ast_.AST, receiver: *ast_.AST, allocator: std.mem.Allocator) *ast_.AST {
    return ast_.AST.create_annotation(
        receiver.token(),
        ast_.AST.create_identifier(receiver.token(), allocator),
        receiver_addr,
        null,
        null,
        allocator,
    );
}

/// Creates the comptime context symbol for `const` initializers
fn create_comptime_init(
    old_init: *ast_.AST,
    _type: *ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!*ast_.AST {
    const retval = ast_.AST.create_comptime(old_init.token(), old_init, allocator);
    const comptime_symbol = try create_temp_comptime_symbol(old_init, _type, scope, errors, allocator);
    try put_symbol(comptime_symbol, scope, errors);
    retval.set_symbol(comptime_symbol);
    return retval;
}

/// Creates a symbol which represents the comptime function to be ran.
pub fn create_temp_comptime_symbol(
    ast: *ast_.AST,
    rhs_type_hint: ?*ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!*symbol_.Symbol {
    // Create the function type. The rhs is a typeof node, since type expansion is done in a later time
    const lhs = primitives_.unit_type;
    const rhs = ast_.AST.create_type_of(ast.token(), ast, allocator);
    const _type = ast_.AST.create_function(ast.token(), lhs, rhs_type_hint orelse rhs, allocator);

    // Create the comptime scope
    // This is to prevent `comptime` expressions from using runtime variables
    var comptime_scope = symbol_.Scope.init(scope, "", allocator);
    comptime_scope.function_depth = scope.function_depth + 1;

    // Choose name
    var buf: []const u8 = undefined;
    buf = next_anon_name("comptime", allocator);

    // Create the symbol
    const retval = symbol_.Symbol.init(
        comptime_scope,
        buf,
        ast.token().span,
        _type,
        ast,
        ast,
        .@"comptime",
        allocator,
    );
    comptime_scope.inner_function = retval;

    try symbol_table_from_AST(ast, comptime_scope, errors, allocator);
    return retval;
}

fn create_trait_symbol(
    ast: *ast_.AST,
    scope: *symbol_.Scope,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!*symbol_.Symbol {
    // Create the symbol
    const retval = symbol_.Symbol.init(
        scope,
        ast.token().data,
        ast.token().span,
        primitives_.unit_type,
        primitives_.unit_value,
        ast,
        .trait,
        allocator,
    );
    retval.defined = true;
    return retval;
}

fn create_method_type(ast: *ast_.AST, allocator: std.mem.Allocator) *ast_.AST {
    const receiver_base_type: *ast_.AST = if (ast.method_decl.impl != null)
        ast.method_decl.impl.?.impl._type
    else
        ast_.AST.create_anyptr_type(ast.token(), allocator);
    // Calculate the domain type from the function paramter types
    ast.method_decl.domain = if (ast.method_decl.receiver) |receiver|
        extract_domain_with_receiver(receiver_base_type, receiver, ast.children().*, allocator)
    else
        extract_domain(ast.children().*, allocator);

    // Create the function type
    const _type = ast_.AST.create_function(
        ast.method_decl.ret_type.token(),
        ast.method_decl.domain.?,
        ast.method_decl.ret_type,
        allocator,
    );
    return _type;
}

fn create_method_symbol(
    ast: *ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!*symbol_.Symbol {
    const receiver_base_type: *ast_.AST = ast.method_decl.impl.?.impl._type;

    // Create the function type
    const _type = create_method_type(ast, allocator);

    // Create the function scope
    var fn_scope = symbol_.Scope.init(scope, "", allocator);
    fn_scope.function_depth = scope.function_depth + 1;

    // Recurse parameters and init
    try symbol_table_from_AST_list(ast.children().*, fn_scope, errors, allocator);
    try symbol_table_from_AST(ast.method_decl.ret_type, fn_scope, errors, allocator);

    if (ast.method_decl.receiver != null) {
        // addr-of receiver, prepend receiver to parameters as normal
        const recv_type = create_receiver_addr(receiver_base_type, ast.method_decl.receiver.?, allocator);
        recv_type.addr_of.anytptr = true;
        // value receiver, prepend a void* self_ptr parameter
        const receiver_symbol = symbol_.Symbol.init(
            fn_scope,
            if (ast.method_decl.receiver.?.receiver.kind == .value) "$self_ptr" else "self",
            ast.token().span,
            recv_type,
            null,
            ast.method_decl.receiver,
            .let,
            allocator,
        );
        try put_symbol(receiver_symbol, fn_scope, errors);
        ast.method_decl.param_symbols.append(receiver_symbol) catch unreachable;

        if (ast.method_decl.receiver.?.receiver.kind == .value) {
            const self_type = recv_type.expr();
            const self_init = ast_.AST.create_dereference(ast.token(), ast_.AST.create_identifier(token_.Token.init_simple("$self_ptr"), allocator), allocator);
            const receiver_span = ast.method_decl.receiver.?.token().span;
            const self_decl = ast_.AST.create_decl(
                ast.token(),
                ast_.AST.create_symbol(token_.Token.init("self", .identifier, receiver_span.filename, receiver_span.line_text, receiver_span.line_number, receiver_span.col), .let, "self", allocator),
                self_type,
                self_init,
                false,
                allocator,
            );
            if (ast.method_decl.init.?.* != .unit_value) {
                const method_block_statements = ast.method_decl.init.?.children();
                method_block_statements.insert(0, self_decl) catch unreachable;
            } else {
                // Technically, init COULD be `{ }`, and it would cause a not-used error later on, but we need to handle this properly here before then
                var statements = std.ArrayList(*ast_.AST).init(allocator);
                statements.append(self_decl) catch unreachable;
                ast.method_decl.init = ast_.AST.create_block(ast.method_decl.init.?.token(), statements, null, allocator);
            }
        }
    }

    // Put the param symbols in the param symbols list
    for (ast.children().items) |param| {
        const symbol = param.decl.symbols.items[0];
        ast.method_decl.param_symbols.append(symbol) catch unreachable;
    }

    const key_set = fn_scope.symbols.keys();
    for (0..key_set.len) |i| {
        const key = key_set[i];
        var symbol = fn_scope.symbols.get(key).?;
        symbol.defined = true;
        symbol.decld = true;
        symbol.param = true;
    }

    const retval = symbol_.Symbol.init(
        fn_scope,
        ast.method_decl.name.token().data,
        ast.method_decl.name.token().span,
        _type,
        ast.method_decl.init.?,
        ast,
        .@"fn",
        allocator,
    );
    fn_scope.inner_function = retval;

    try symbol_table_from_AST(ast.method_decl.init, fn_scope, errors, allocator);
    return retval;
}

fn create_template_symbol(
    ast: *ast_.AST,
    scope: *symbol_.Scope,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!*symbol_.Symbol {
    var buf: []const u8 = undefined;
    if (ast.template.decl.fn_decl.name) |name| {
        buf = name.token().data;
    } else {
        buf = next_anon_name("", allocator);
    }
    const retval = symbol_.Symbol.init(
        scope,
        buf,
        ast.template.decl.fn_decl.name.?.token().span,
        primitives_.unit_type,
        primitives_.unit_value,
        ast,
        .template,
        allocator,
    );
    retval.defined = true;
    return retval;
}
