const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const primitives_ = @import("primitives.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const token_ = @import("token.zig");

const SymbolErrorEnum = error{SymbolError};

pub fn symbolTableFromASTList(
    asts: std.ArrayList(*ast_.AST),
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) SymbolErrorEnum!void {
    for (asts.items) |ast| {
        try symbolTableFromAST(ast, scope, errors, allocator);
    }
}

// Takes in an ast, returns the scope constructed from that AST node
// Most AST nodes don't do anything, except blocks and decls, which can be buried deep in an AST
fn symbolTableFromAST(
    maybe_ast: ?*ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) SymbolErrorEnum!void {
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
        ._unreachable,
        ._true,
        ._false,
        .inferredMember,
        .poison,
        .pattern_symbol,
        .domainOf,
        .sizeOf,
        => {},

        ._break => try in_loop_check(ast, "break", scope, errors),
        ._continue => try in_loop_check(ast, "continue", scope, errors),

        ._typeOf,
        .default,
        .not,
        .negate,
        .dereference,
        .addrOf,
        .sliceOf,
        .discard,
        => try symbolTableFromAST(ast.expr(), scope, errors, allocator),

        ._try => {
            ast.set_symbol(try in_function_check(ast, "try", scope, errors));
            try symbolTableFromAST(ast.expr(), scope, errors, allocator);
        },

        ._comptime => {
            const symbol = try create_temp_comptime_symbol(ast, null, scope, errors, allocator);
            try put_symbol(symbol, scope, errors);
            ast.set_symbol(symbol);
        },

        .assign,
        ._or,
        ._and,
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
        .inject,
        ._union,
        .@"catch",
        .@"orelse",
        => {
            try symbolTableFromAST(ast.lhs(), scope, errors, allocator);
            try symbolTableFromAST(ast.rhs(), scope, errors, allocator);
        },
        .call => {
            try symbolTableFromAST(ast.lhs(), scope, errors, allocator);
            try symbolTableFromASTList(ast.children().*, scope, errors, allocator);
        },
        .sum, .inferred_error, .product => try symbolTableFromASTList(ast.children().*, scope, errors, allocator),

        .arrayOf => {
            try symbolTableFromAST(ast.expr(), scope, errors, allocator);
            try symbolTableFromAST(ast.arrayOf.len, scope, errors, allocator);
        },
        .subSlice => {
            try symbolTableFromAST(ast.subSlice.super, scope, errors, allocator);
            try symbolTableFromAST(ast.subSlice.lower, scope, errors, allocator);
            try symbolTableFromAST(ast.subSlice.upper, scope, errors, allocator);
        },
        .annotation => {
            try symbolTableFromAST(ast.annotation.type, scope, errors, allocator);
            try symbolTableFromAST(ast.annotation.predicate, scope, errors, allocator);
            try symbolTableFromAST(ast.annotation.init, scope, errors, allocator);
        },

        ._if => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast._if.scope = new_scope;
            try symbolTableFromAST(ast._if.let, scope, errors, allocator);
            try symbolTableFromAST(ast._if.condition, new_scope, errors, allocator);
            try symbolTableFromAST(ast._if.bodyBlock, new_scope, errors, allocator);
            try symbolTableFromAST(ast._if.elseBlock, new_scope, errors, allocator);
        },
        .match => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast.match.scope = new_scope;
            try symbolTableFromAST(ast.match.let, scope, errors, allocator);
            try symbolTableFromAST(ast.expr(), new_scope, errors, allocator);
            try create_match_pattern_symbol(ast, new_scope, errors, allocator);
            try symbolTableFromASTList(ast.children().*, new_scope, errors, allocator);
        },
        .mapping => try symbolTableFromAST(ast.mapping_lhs(), scope, errors, allocator),
        ._while => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            var loop_scope = symbol_.Scope.init(new_scope, "", allocator); // let, cond, post are NOT in loop scope
            loop_scope.in_loop = true;
            ast._while.scope = new_scope;
            try symbolTableFromAST(ast._while.let, new_scope, errors, allocator);
            try symbolTableFromAST(ast._while.condition, new_scope, errors, allocator);
            try symbolTableFromAST(ast._while.post, new_scope, errors, allocator);
            try symbolTableFromAST(ast._while.bodyBlock, loop_scope, errors, allocator);
            try symbolTableFromAST(ast._while.elseBlock, loop_scope, errors, allocator);
        },
        ._for => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast._for.scope = new_scope;
            try symbolTableFromAST(ast._for.let, scope, errors, allocator);
            try symbolTableFromAST(ast._for.elem, scope, errors, allocator);
            try symbolTableFromAST(ast._for.iterable, scope, errors, allocator);
            try symbolTableFromAST(ast._for.bodyBlock, scope, errors, allocator);
            try symbolTableFromAST(ast._for.elseBlock, scope, errors, allocator);
        },
        .block => {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            ast.block.scope = new_scope;
            try symbolTableFromASTList(ast.children().*, new_scope, errors, allocator);
            if (ast.block.final) |final| {
                try symbolTableFromAST(final, new_scope, errors, allocator);
            }
        },

        ._return => {
            ast.set_symbol(try in_function_check(ast, "return", scope, errors));
            try symbolTableFromAST(ast._return._ret_expr, scope, errors, allocator);
        },
        .decl => {
            // Both put a Symbol in the current scope, and recurse
            try create_symbol(&ast.decl.symbols, ast.decl.pattern, ast.decl.type, ast.decl.init, scope, errors, allocator);
            try put_all_symbols(&ast.decl.symbols, scope, errors);
            try symbolTableFromAST(ast.decl.type, scope, errors, allocator);
            try symbolTableFromAST(ast.decl.init, scope, errors, allocator);

            if (ast.decl.top_level) {
                for (ast.decl.symbols.items) |symbol| {
                    if (symbol.kind != .@"const") {
                        errors.addError(errs_.Error{ .basic = .{
                            .span = symbol.span,
                            .msg = "top level symbols must be marked `const`",
                        } });
                        return error.SymbolError;
                    }
                }
            }
        },
        .fnDecl => {
            if (ast.symbol() != null) {
                // Do not re-do symbol if already declared
                return;
            }
            const symbol = try createFunctionSymbol(ast, scope, errors, allocator);
            try put_symbol(symbol, scope, errors);
            ast.set_symbol(symbol);
        },
        ._defer => {
            scope.defers.append(ast.statement()) catch unreachable;
            try symbolTableFromAST(ast.statement(), scope, errors, allocator);
        },
        ._errdefer => {
            scope.errdefers.append(ast.statement()) catch unreachable;
            try symbolTableFromAST(ast.statement(), scope, errors, allocator);
        },
    }
}

fn in_loop_check(ast: *ast_.AST, name: []const u8, scope: *symbol_.Scope, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (!scope.in_loop) {
        errors.addError(errs_.Error{ .not_inside_loop = .{
            .span = ast.token().span,
            .name = name,
        } });
        return error.SymbolError;
    }
}

/// Returns the inner symbol of a scope, or an error if one doesnt exist
fn in_function_check(ast: *ast_.AST, name: []const u8, scope: *symbol_.Scope, errors: *errs_.Errors) !*symbol_.Symbol { // TODO: Uninfer error
    if (scope.inner_function == null) {
        errors.addError(errs_.Error{ .not_inside_function = .{
            .span = ast.token().span,
            .name = name,
        } });
        return error.SymbolError;
    } else {
        return scope.inner_function.?;
    }
}

fn put_symbol(symbol: *symbol_.Symbol, scope: *symbol_.Scope, errors: *errs_.Errors) !void { // TODO: Uninfer error
    const res = scope.lookup(symbol.name, false);
    switch (res) {
        .found => {
            const first = res.found;
            errors.addError(errs_.Error{ .redefinition = .{
                .first_defined_span = first.span,
                .redefined_span = symbol.span,
                .name = symbol.name,
            } });
            return error.SymbolError;
        },
        else => scope.symbols.put(symbol.name, symbol) catch unreachable,
    }
}

fn put_all_symbols(symbols: *std.ArrayList(*symbol_.Symbol), scope: *symbol_.Scope, errors: *errs_.Errors) !void { // TODO: Uninfer error
    for (symbols.items) |symbol| {
        try put_symbol(symbol, scope, errors);
    }
}

fn create_symbol(
    symbols: *std.ArrayList(*symbol_.Symbol),
    pattern: *ast_.AST,
    _type: *ast_.AST,
    init: *ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) SymbolErrorEnum!void {
    switch (pattern.*) {
        .pattern_symbol => {
            if (std.mem.eql(u8, pattern.pattern_symbol.name, "_")) {
                if (pattern.pattern_symbol.kind != .let) {
                    // It is an error for `_` to be marked as `const` or `mut`
                    errors.addError(errs_.Error{ .discard_marked = .{
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
                const index = ast_.AST.createInt(pattern.token(), i, allocator);
                const new_type: *ast_.AST = ast_.AST.createIndex(_type.token(), _type, index, allocator);
                const new_init: *ast_.AST = ast_.AST.createIndex(init.token(), init, index, allocator);
                try create_symbol(symbols, term, new_type, new_init, scope, errors, allocator);
            }
        },
        .inject => {
            const lhs_type = ast_.AST.createTypeOf(pattern.token(), init, allocator);
            const rhs_type = ast_.AST.createDomainOf(pattern.token(), lhs_type, pattern, allocator);
            // All symbols need inits, this is just a phony init since these symbols are more like parameters.
            // We do the same for parameters, btw!
            const phony_init = ast_.AST.createDefault(pattern.token(), rhs_type, allocator);

            try create_symbol(symbols, pattern.lhs(), lhs_type, phony_init, scope, errors, allocator);
            try create_symbol(symbols, pattern.rhs(), rhs_type, phony_init, scope, errors, allocator);
        },
        else => {},
    }
}

fn create_match_pattern_symbol(match: *ast_.AST, scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) !void { // TODO: Uninfer error
    for (match.children().items) |mapping| {
        if (mapping.mapping_lhs() != null) {
            const new_scope = symbol_.Scope.init(scope, "", allocator);
            mapping.mapping.scope = new_scope;
            var symbols = std.ArrayList(*symbol_.Symbol).init(allocator);
            defer symbols.deinit();
            const _type = ast_.AST.createTypeOf(match.expr().token(), match.expr(), allocator);
            try create_symbol(&symbols, mapping.mapping_lhs().?, _type, match.expr(), new_scope, errors, allocator);
            for (symbols.items) |symbol| {
                symbol.defined = true;
            }
            try put_all_symbols(&symbols, new_scope, errors);
            try symbolTableFromAST(mapping.rhs(), new_scope, errors, allocator);
        } else {
            try symbolTableFromAST(mapping.rhs(), scope, errors, allocator);
        }
    }
}

fn createFunctionSymbol(
    ast: *ast_.AST,
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) SymbolErrorEnum!*symbol_.Symbol {
    // Calculate the domain type from the function paramter types
    const domain = extractDomain(
        ast.children().*,
        ast.fnDecl.retType.token(),
        allocator,
    );

    // Create the function type
    const _type = ast_.AST.createFunction(
        ast.fnDecl.retType.token(),
        domain,
        ast.fnDecl.retType,
        allocator,
    );

    // Create the function scope
    var fnScope = symbol_.Scope.init(scope, "", allocator);
    fnScope.in_function = scope.in_function + 1;

    // Recurse parameters and init
    try symbolTableFromASTList(ast.children().*, fnScope, errors, allocator);
    try symbolTableFromAST(ast.fnDecl.retType, fnScope, errors, allocator);

    // Put the param symbols in the param symbols list
    for (ast.children().items) |param| {
        const symbol = param.decl.symbols.items[0];
        ast.fnDecl.param_symbols.append(symbol) catch unreachable;
    }

    const keySet = fnScope.symbols.keys();
    var i: usize = 0;
    while (i < keySet.len) : (i += 1) {
        const key = keySet[i];
        var symbol = fnScope.symbols.get(key).?;
        symbol.defined = true;
        symbol.decld = true;
        symbol.param = true;
    }

    // Choose name (maybe anon)
    var buf: []const u8 = undefined;
    if (ast.fnDecl.name) |name| {
        buf = name.token().data;
    } else {
        buf = next_anon_name("anon", allocator);
    }
    const retval = symbol_.Symbol.init(
        fnScope,
        buf,
        ast.token().span,
        _type,
        ast.fnDecl.init,
        ast,
        .@"fn",
        allocator,
    );
    fnScope.inner_function = retval;

    try symbolTableFromAST(ast.fnDecl.init, fnScope, errors, allocator);
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

fn extractDomain(params: std.ArrayList(*ast_.AST), token: token_.Token, allocator: std.mem.Allocator) *ast_.AST {
    if (params.items.len == 0) {
        return ast_.AST.createUnitType(token, allocator);
    } else if (params.items.len <= 1) {
        return ast_.AST.createAnnotation(
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
        var i: usize = 0;
        while (i < params.items.len) : (i += 1) {
            param_types.append(ast_.AST.createAnnotation(
                params.items[i].token(),
                params.items[i].decl.pattern,
                params.items[i].decl.type,
                null,
                params.items[i].decl.init,
                allocator,
            )) catch unreachable;
        }
        const retval = ast_.AST.createProduct(params.items[0].token(), param_types, allocator);
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
) !*ast_.AST { // TODO: Uninfer error
    const retval = ast_.AST.createComptime(old_init.token(), old_init, allocator);
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
) SymbolErrorEnum!*symbol_.Symbol {
    // Create the function type. The rhs is a typeof node, since type expansion is done in a later time
    const lhs = ast_.AST.createUnitType(ast.expr().token(), allocator);
    const rhs = ast_.AST.createTypeOf(ast.expr().token(), ast.expr(), allocator);
    const _type = ast_.AST.createFunction(ast.expr().token(), lhs, rhs_type_hint orelse rhs, allocator);

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

    try symbolTableFromAST(ast.expr(), comptime_scope, errors, allocator);
    return retval;
}
