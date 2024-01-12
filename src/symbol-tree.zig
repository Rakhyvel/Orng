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

// Takes in an ast, returns the scope constructed from that AST node
// Most AST nodes don't do anything, except blocks and decls, which can be buried deep in an AST
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
    switch (ast.*) {
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
        .domain_of,
        .size_of,
        => {},

        .@"break", .@"continue" => try in_loop_check(ast, scope, errors),

        .type_of,
        .default,
        .not,
        .negate,
        .dereference,
        .addr_of,
        .slice_of,
        .discard,
        => try symbol_table_from_AST(ast.expr(), scope, errors, allocator),

        .@"try" => {
            ast.set_symbol(try in_function_check(ast, scope, errors));
            try symbol_table_from_AST(ast.expr(), scope, errors, allocator);
        },

        .@"comptime" => {
            const symbol = try create_temp_comptime_symbol(ast, null, scope, errors, allocator);
            try put_symbol(symbol, scope, errors);
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
        .invoke,
        .@"union",
        .@"catch",
        .@"orelse",
        => {
            try symbol_table_from_AST(ast.lhs(), scope, errors, allocator);
            try symbol_table_from_AST(ast.rhs(), scope, errors, allocator);
        },
        .call => {
            try symbol_table_from_AST(ast.lhs(), scope, errors, allocator);
            try symbol_table_from_AST_list(ast.children().*, scope, errors, allocator);
        },
        .sum_type, .inferred_error, .product => try symbol_table_from_AST_list(ast.children().*, scope, errors, allocator),
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
            try create_symbol(&ast.decl.symbols, ast.decl.pattern, ast.decl.type, ast.decl.init, scope, errors, allocator);
            try put_all_symbols(&ast.decl.symbols, scope, errors);
            try symbol_table_from_AST(ast.decl.type, scope, errors, allocator);
            try symbol_table_from_AST(ast.decl.init, scope, errors, allocator);

            if (ast.decl.top_level) {
                for (ast.decl.symbols.items) |symbol| {
                    if (symbol.kind != .@"const") {
                        errors.add_error(errs_.Error{ .basic = .{
                            .span = symbol.span,
                            .msg = "top level symbols must be marked `const`",
                        } });
                        return error.SymbolError;
                    }
                }
            }
        },
        .fn_decl => {
            if (ast.symbol() != null) {
                // Do not re-do symbol if already declared
                return;
            }
            const symbol = try create_function_symbol(ast, scope, errors, allocator);
            try put_symbol(symbol, scope, errors);
            ast.set_symbol(symbol);
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
    } else {
        return scope.inner_function.?;
    }
}

fn put_symbol(symbol: *symbol_.Symbol, scope: *symbol_.Scope, errors: *errs_.Errors) Symbol_Error_Enum!void {
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

fn create_symbol(
    symbols: *std.ArrayList(*symbol_.Symbol),
    pattern: *ast_.AST,
    _type: *ast_.AST,
    init: *ast_.AST, // The value being matched on
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
            const symbol_init = if (pattern.pattern_symbol.kind != .@"const")
                init
            else
                try create_comptime_init(init, _type, scope, errors, allocator);
            const symbol = symbol_.Symbol.init(
                scope,
                pattern.pattern_symbol.name,
                pattern.token().span,
                _type,
                symbol_init,
                null,
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
                const new_init: *ast_.AST = ast_.AST.create_index(init.token(), init, index, allocator);
                try create_symbol(symbols, term, new_type, new_init, scope, errors, allocator);
            }
        },
        .sum_value => {
            const lhs_type = ast_.AST.create_type_of(pattern.token(), init, allocator);
            const rhs_type = ast_.AST.create_domain_of(pattern.token(), lhs_type, pattern, allocator);
            // All symbols need inits, this is just a phony init since these symbols are more like parameters.
            // (We do the same for parameters, btw!)
            const phony_init = ast_.AST.create_default(pattern.token(), rhs_type, allocator);

            if (pattern.sum_value.init != null) {
                try create_symbol(symbols, pattern.sum_value.init.?, rhs_type, phony_init, scope, errors, allocator);
            }
        },
        else => {},
    }
}

fn create_match_pattern_symbol(match: *ast_.AST, scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) Symbol_Error_Enum!void {
    for (match.children().items) |mapping| {
        const new_scope = symbol_.Scope.init(scope, "", allocator);
        mapping.mapping.scope = new_scope;
        var symbols = std.ArrayList(*symbol_.Symbol).init(allocator);
        defer symbols.deinit();
        const _type = ast_.AST.create_type_of(match.expr().token(), match.expr(), allocator);
        try create_symbol(&symbols, mapping.lhs(), _type, match.expr(), new_scope, errors, allocator);
        for (symbols.items) |symbol| {
            symbol.defined = true;
        }
        try put_all_symbols(&symbols, new_scope, errors);
        try symbol_table_from_AST(mapping.rhs(), new_scope, errors, allocator);
    }
}

fn create_function_symbol(
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
    fn_scope.in_function = scope.in_function + 1;

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
        ast.token().span,
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
    out.writer().print("${s}{}", .{ class, num_anons }) catch unreachable;
    return (out.toOwned() catch unreachable).?;
}

fn extract_domain(params: std.ArrayList(*ast_.AST), allocator: std.mem.Allocator) *ast_.AST {
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

// `const` symbol, surround with comptime
fn create_comptime_init(
    old_init: *ast_.AST,
    _type: *ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!*ast_.AST {
    const retval = ast_.AST.create_comptime(old_init.token(), old_init, allocator);
    const comptime_symbol = try create_temp_comptime_symbol(retval, _type, scope, errors, allocator);
    try put_symbol(comptime_symbol, scope, errors);
    retval.set_symbol(comptime_symbol);
    return retval;
}

// ast is a `comptime` ast
fn create_temp_comptime_symbol(
    ast: *ast_.AST,
    rhs_type_hint: ?*ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Symbol_Error_Enum!*symbol_.Symbol {
    // Create the function type. The rhs is a typeof node, since type expansion is done in a later time
    const lhs = primitives_.unit_type;
    const rhs = ast_.AST.create_type_of(ast.expr().token(), ast.expr(), allocator);
    const _type = ast_.AST.create_function(ast.expr().token(), lhs, rhs_type_hint orelse rhs, allocator);

    // Create the comptime scope
    // This is to prevent `comptime` expressions from using runtime variables
    var comptime_scope = symbol_.Scope.init(scope, "", allocator);
    comptime_scope.in_function = scope.in_function;

    // Choose name
    var buf: []const u8 = undefined;
    buf = next_anon_name("comptime", allocator);

    // Create the symbol
    const retval = symbol_.Symbol.init(
        comptime_scope,
        buf,
        ast.token().span,
        _type,
        ast.expr(),
        ast,
        .@"comptime",
        allocator,
    );
    comptime_scope.inner_function = retval;

    try symbol_table_from_AST(ast.expr(), comptime_scope, errors, allocator);
    return retval;
}
