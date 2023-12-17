const std = @import("std");
const ast = @import("ast.zig");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const module_ = @import("module.zig");
const offsets = @import("offsets.zig");
const optimizations = @import("optimizations.zig");
const _span = @import("span.zig");
const primitives_ = @import("primitives.zig");

const AST = ast.AST;
const CFG = ir_.CFG;
const Error = errs.Error;
const Module = module_.Module;
const Span = _span.Span;
const String = @import("zig-string/zig-string.zig").String;
const Token = @import("token.zig").Token;

const SymbolErrorEnum = error{ symbolError, OutOfMemory, NoSpaceLeft, InvalidRange };

const LookupResult = union(enum) { found_but_rt, found_but_fn, not_found, found: *Symbol };

var scopeUID: usize = 0;
pub const Scope = struct {
    parent: ?*Scope,
    children: std.ArrayList(*Scope),
    symbols: std.StringArrayHashMap(*Symbol),
    module: ?*Module, // Enclosing module
    name: []const u8,
    uid: usize,

    in_function: usize = 0,
    in_loop: bool = false,
    defers: std.ArrayList(*AST),
    errdefers: std.ArrayList(*AST),
    inner_function: ?*Symbol = null,

    pub fn init(parent: ?*Scope, name: []const u8, allocator: std.mem.Allocator) !*Scope {
        var retval = try allocator.create(Scope);
        retval.parent = parent;
        retval.children = std.ArrayList(*Scope).init(allocator);
        retval.symbols = std.StringArrayHashMap(*Symbol).init(allocator);
        retval.name = name;
        retval.uid = scopeUID;
        retval.defers = std.ArrayList(*AST).init(allocator);
        retval.errdefers = std.ArrayList(*AST).init(allocator);
        scopeUID += 1;
        if (parent) |_parent| {
            try _parent.children.append(retval);
            retval.in_loop = _parent.in_loop;
            retval.in_function = _parent.in_function;
            retval.inner_function = _parent.inner_function;
            retval.module = _parent.module;
        } else {
            retval.in_loop = false;
            retval.in_function = 0;
            retval.inner_function = null;
            retval.module = null;
        }
        return retval;
    }

    pub fn lookup(self: *Scope, name: []const u8, crossed_boundary: bool) LookupResult {
        if (self.symbols.get(name)) |symbol| {
            if (crossed_boundary and (symbol.kind == .mut or symbol.kind == .let)) {
                // Found the symbol, but it's non-const and we've crossed an inner-function boundary
                return .found_but_fn;
            } else {
                // Found the symbol just fine
                return LookupResult{ .found = symbol };
            }
        } else if (self.parent) |parent| {
            const res = parent.lookup(name, parent.in_function < self.in_function or crossed_boundary);
            if (false and res == .found_but_fn and self.inner_function.?.kind == ._comptime) {
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

    pub fn pprint(self: *Scope) !void {
        var out = String.init(std.heap.page_allocator);
        defer out.deinit();
        try self.serialize(&out, 0);
        std.debug.print("{s}\n", .{out.str()});
    }

    fn serialize(self: *Scope, out: *String, spaces: usize) !void {
        var j: usize = 0;
        while (j < spaces) : (j += 1) {
            try out.insert(" ", out.len());
        }
        try out.insert(self.name, out.len());
        try out.insert(": {\n", out.len());
        const keySet = self.symbols.keys();
        var i: usize = 0;
        while (i < keySet.len) : (i += 1) {
            const key = keySet[i];
            j = 0;
            while (j < spaces + 4) : (j += 1) {
                try out.insert(" ", out.len());
            }
            try out.insert(self.symbols.get(key).?.name, out.len());
            if (i < keySet.len - 1) {
                try out.insert(",", out.len());
            } else {
                try out.insert(",\n", out.len());
            }
            try out.insert("\n", out.len());
        }
        for (self.children.items) |child| {
            try child.serialize(out, spaces + 4);
        }
        j = 0;
        while (j < spaces) : (j += 1) {
            try out.insert(" ", out.len());
        }
        try out.insert("}\n", out.len());
    }

    pub fn root(self: *Scope) ?*Scope {
        if (self.parent) |_parent| {
            return root(_parent);
        } else {
            return self;
        }
    }

    /// This function collects all visible symbols from a scope that:
    ///   1. have an identical expected type
    ///   2. spelled similarly (levenshtein distance is less than half)
    pub fn collect_similar(self: *Scope, name: []const u8, out: *std.ArrayList([]const u8), expected: ?*ast.AST, allocator: std.mem.Allocator) !void {
        var errors = errs.Errors.init(allocator);
        defer errors.deinit();
        for (self.symbols.keys()) |key| {
            var symbol: *Symbol = self.symbols.get(key).?;
            if (std.mem.eql(u8, symbol.name, "_")) {
                continue; // never suggest `_`
            }

            const matches = expected == null or try symbol._type.typesMatch(expected.?, self, &errors, allocator);
            const dist = try levenshteinDistance2(allocator, symbol.name, name);
            if (matches and dist <= name.len / 2) {
                try out.append(key);
            }
        }
        if (self.parent) |_parent| {
            try _parent.collect_similar(name, out, expected, allocator);
        }
    }

    inline fn idx(i: usize, j: usize, cols: usize) usize {
        return i * cols + j;
    }

    pub fn levenshteinDistance2(allocator: std.mem.Allocator, a: []const u8, b: []const u8) !u16 {
        const n = a.len;
        const m = b.len;
        const table = try allocator.alloc(u8, n * m);
        defer allocator.free(table);
        table[0] = 0;

        for (0..n) |i| {
            for (0..m) |j| {
                table[idx(i, j, m)] = @min(
                    (if (i == 0)
                        @as(u8, @truncate(j))
                    else
                        table[idx(i - 1, j, m)]) + 1,
                    (if (j == 0)
                        @as(u8, @truncate(i))
                    else
                        table[idx(i, j - 1, m)]) + 1,
                    (if (i == 0)
                        @as(u8, @truncate(j))
                    else if (j == 0)
                        @as(u8, @truncate(i))
                    else
                        table[idx(i - 1, j - 1, m)]) +
                        @intFromBool(a[i] != b[j]),
                );
            }
        }
        return table[table.len - 1];
    }
};

pub const SymbolKind = enum {
    _fn,
    _const,
    let,
    mut,
    _comptime,
    pub fn to_string(self: SymbolKind) []const u8 {
        return switch (self) {
            ._fn => "fn",
            ._const => "const",
            .let => "let",
            .mut => "mut",
            ._comptime => "comptime",
        };
    }
};

var number_of_comptime: usize = 0;
pub const Symbol = struct {
    scope: *Scope, // Enclosing parent scope
    name: []const u8,
    span: Span,
    _type: *ast.AST,
    expanded_type: ?*ast.AST,
    init: *ast.AST,
    kind: SymbolKind,
    cfg: ?*CFG,
    decl: ?*AST,

    // Use-def
    versions: u64 = 0,
    uses: u64 = 0,
    discards: u64 = 0, // May be 0 if symbol is uses > 0; may be 1 if uses = 0; may not be greater than 1
    discard_span: ?Span,

    defined: bool,
    validation_state: enum { // TODO: Move to common file with AST's
        unvalidated, // Has not attempted to validate to validate symbol yet
        validating, // Symbol is currently being validated
        valid, // Symbol has been validated and is valid. Specifically, the type of the symbol is valid and may be used.
        invalid,
    },
    decld: bool, // When a local variable, whether or not the variable has been printed out or not
    param: bool,
    is_temp: bool = false,

    // Offset
    offset: ?i64, // The offset from the BP that this symbol

    pub fn create(scope: *Scope, name: []const u8, span: Span, _type: *ast.AST, _init: *ast.AST, decl: ?*AST, kind: SymbolKind, allocator: std.mem.Allocator) !*Symbol {
        var retval = try allocator.create(Symbol);
        retval.scope = scope;
        retval.name = name;
        retval.span = span;
        retval._type = _type;
        retval.expanded_type = null;
        retval.init = _init;
        retval.decl = decl;
        retval.versions = 0;
        retval.discards = 0;
        retval.uses = 0;
        retval.offset = null;
        retval.kind = kind;
        retval.cfg = null;
        if (kind == ._fn or kind == ._const or kind == ._comptime) {
            retval.defined = true;
        } else {
            retval.defined = false;
        }
        retval.validation_state = .unvalidated;
        retval.decld = false;
        return retval;
    }

    pub fn get_cfg(self: *Symbol, caller: ?*CFG, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors, allocator: std.mem.Allocator) !*CFG {
        std.debug.assert(self.kind == ._fn or self.kind == ._comptime);
        std.debug.assert(self.validation_state == .valid);
        if (self.cfg == null) {
            self.cfg = try CFG.create(self, caller, interned_strings, errors, allocator);
            try optimizations.optimize(self.cfg.?, errors, interned_strings, allocator);
            try self.cfg.?.collect_generated_symbvers();
            self.cfg.?.locals_size = offsets.calculate_offsets(self);
        }
        return self.cfg.?;
    }
};

pub fn symbolTableFromASTList(definitions: std.ArrayList(*ast.AST), scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) SymbolErrorEnum!void {
    for (definitions.items) |definition| {
        try symbolTableFromAST(definition, scope, errors, allocator);
    }
}

// Takes in an ast, returns the scope constructed from that AST node
// Most AST nodes don't do anything, except blocks and decls, which can be buried deep in an AST
pub fn symbolTableFromAST(maybe_definition: ?*ast.AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) SymbolErrorEnum!void {
    if (maybe_definition == null) {
        return;
    }
    var definition = maybe_definition.?;
    switch (definition.*) {
        .unit_type,
        .unit_value,
        .int,
        .char,
        .float,
        .string,
        .identifier,
        ._unreachable,
        ._true,
        ._false,
        ._break,
        ._continue,
        .inferredMember,
        .poison,
        .symbol,
        .domainOf,
        .sizeOf,
        => {},

        ._typeOf => try symbolTableFromAST(definition._typeOf.expr, scope, errors, allocator),
        .default => try symbolTableFromAST(definition.default.expr, scope, errors, allocator),
        .not => try symbolTableFromAST(definition.not.expr, scope, errors, allocator),
        .negate => try symbolTableFromAST(definition.negate.expr, scope, errors, allocator),
        .dereference => try symbolTableFromAST(definition.dereference.expr, scope, errors, allocator),
        ._try => try symbolTableFromAST(definition._try.expr, scope, errors, allocator),
        .discard => try symbolTableFromAST(definition.discard.expr, scope, errors, allocator),
        ._comptime => {
            const symbol = try create_temp_comptime_symbol(definition, null, scope, errors, allocator);
            const res = scope.lookup(symbol.name, false);
            switch (res) {
                .found => {
                    const first = res.found;
                    errors.addError(Error{ .redefinition = .{
                        .first_defined_span = first.span,
                        .redefined_span = symbol.span,
                        .name = symbol.name,
                    } });
                    return error.symbolError;
                },
                else => try scope.symbols.put(symbol.name, symbol),
            }
            definition._comptime.symbol = symbol;
        },

        .assign => {
            try symbolTableFromAST(definition.assign.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.assign.rhs, scope, errors, allocator);
        },
        ._or => {
            try symbolTableFromAST(definition._or.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition._or.rhs, scope, errors, allocator);
        },
        ._and => {
            try symbolTableFromAST(definition._and.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition._and.rhs, scope, errors, allocator);
        },
        .add => {
            try symbolTableFromAST(definition.add.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.add.rhs, scope, errors, allocator);
        },
        .sub => {
            try symbolTableFromAST(definition.sub.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.sub.rhs, scope, errors, allocator);
        },
        .mult => {
            try symbolTableFromAST(definition.mult.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.mult.rhs, scope, errors, allocator);
        },
        .div => {
            try symbolTableFromAST(definition.div.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.div.rhs, scope, errors, allocator);
        },
        .mod => {
            try symbolTableFromAST(definition.mod.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.mod.rhs, scope, errors, allocator);
        },
        .equal => {
            try symbolTableFromAST(definition.equal.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.equal.rhs, scope, errors, allocator);
        },
        .not_equal => {
            try symbolTableFromAST(definition.not_equal.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.not_equal.rhs, scope, errors, allocator);
        },
        .greater => {
            try symbolTableFromAST(definition.greater.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.greater.rhs, scope, errors, allocator);
        },
        .lesser => {
            try symbolTableFromAST(definition.lesser.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.lesser.rhs, scope, errors, allocator);
        },
        .greater_equal => {
            try symbolTableFromAST(definition.greater_equal.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.greater_equal.rhs, scope, errors, allocator);
        },
        .lesser_equal => {
            try symbolTableFromAST(definition.lesser_equal.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.lesser_equal.rhs, scope, errors, allocator);
        },
        ._catch => {
            try symbolTableFromAST(definition._catch.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition._catch.rhs, scope, errors, allocator);
        },
        ._orelse => {
            try symbolTableFromAST(definition._orelse.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition._orelse.rhs, scope, errors, allocator);
        },
        .call => {
            try symbolTableFromAST(definition.call.lhs, scope, errors, allocator);
            try symbolTableFromASTList(definition.call.args, scope, errors, allocator);
        },
        .index => {
            try symbolTableFromAST(definition.index.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.index.rhs, scope, errors, allocator);
        },
        .select => {
            try symbolTableFromAST(definition.select.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.select.rhs, scope, errors, allocator);
        },
        .function => {
            try symbolTableFromAST(definition.function.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.function.rhs, scope, errors, allocator);
        },
        .invoke => {
            try symbolTableFromAST(definition.invoke.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.invoke.rhs, scope, errors, allocator);
        },
        .sum => {
            try symbolTableFromASTList(definition.sum.terms, scope, errors, allocator);
        },
        .inferred_error => {
            try symbolTableFromASTList(definition.inferred_error.terms, scope, errors, allocator);
        },
        .inject => {
            try symbolTableFromAST(definition.inject.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.inject.rhs, scope, errors, allocator);
        },
        ._union => {
            try symbolTableFromAST(definition._union.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition._union.rhs, scope, errors, allocator);
        },

        .product => {
            try symbolTableFromASTList(definition.product.terms, scope, errors, allocator);
        },
        .addrOf => try symbolTableFromAST(definition.addrOf.expr, scope, errors, allocator),
        .sliceOf => {
            try symbolTableFromAST(definition.sliceOf.expr, scope, errors, allocator);
            try symbolTableFromAST(definition.sliceOf.len, scope, errors, allocator);
        },
        .subSlice => {
            try symbolTableFromAST(definition.subSlice.super, scope, errors, allocator);
            try symbolTableFromAST(definition.subSlice.lower, scope, errors, allocator);
            try symbolTableFromAST(definition.subSlice.upper, scope, errors, allocator);
        },
        .annotation => {
            try symbolTableFromAST(definition.annotation.type, scope, errors, allocator);
            try symbolTableFromAST(definition.annotation.predicate, scope, errors, allocator);
            try symbolTableFromAST(definition.annotation.init, scope, errors, allocator);
        },

        ._if => {
            const new_scope = try Scope.init(scope, "", allocator);
            definition._if.scope = new_scope;
            try symbolTableFromAST(definition._if.let, scope, errors, allocator);
            try symbolTableFromAST(definition._if.condition, scope, errors, allocator);
            try symbolTableFromAST(definition._if.bodyBlock, scope, errors, allocator);
            try symbolTableFromAST(definition._if.elseBlock, scope, errors, allocator);
        },
        .match => {
            const new_scope = try Scope.init(scope, "", allocator);
            definition.match.scope = new_scope;
            try symbolTableFromAST(definition.match.let, scope, errors, allocator);
            try symbolTableFromAST(definition.match.expr, new_scope, errors, allocator);
            try create_match_pattern_symbol(definition, new_scope, errors, allocator);
            try symbolTableFromASTList(definition.match.mappings, new_scope, errors, allocator);
        },
        .mapping => {
            try symbolTableFromAST(definition.mapping.lhs, scope, errors, allocator);
        },
        ._while => {
            var new_scope = try Scope.init(scope, "", allocator);
            new_scope.in_loop = true;
            definition._while.scope = new_scope;
            try symbolTableFromAST(definition._while.let, new_scope, errors, allocator);
            try symbolTableFromAST(definition._while.condition, new_scope, errors, allocator);
            try symbolTableFromAST(definition._while.post, new_scope, errors, allocator);
            try symbolTableFromAST(definition._while.bodyBlock, new_scope, errors, allocator);
            try symbolTableFromAST(definition._while.elseBlock, new_scope, errors, allocator);
        },
        ._for => {
            const new_scope = try Scope.init(scope, "", allocator);
            definition._for.scope = new_scope;
            try symbolTableFromAST(definition._for.let, scope, errors, allocator);
            try symbolTableFromAST(definition._for.elem, scope, errors, allocator);
            try symbolTableFromAST(definition._for.iterable, scope, errors, allocator);
            try symbolTableFromAST(definition._for.bodyBlock, scope, errors, allocator);
            try symbolTableFromAST(definition._for.elseBlock, scope, errors, allocator);
        },
        .block => {
            const new_scope = try Scope.init(scope, "", allocator);
            definition.block.scope = new_scope;
            try symbolTableFromASTList(definition.block.statements, new_scope, errors, allocator);
            if (definition.block.final) |final| {
                try symbolTableFromAST(final, new_scope, errors, allocator);
            }
        },

        ._return => try symbolTableFromAST(definition._return.expr, scope, errors, allocator),
        .decl => {
            // Both put a Symbol in the current scope, and recurse
            try create_symbol(&definition.decl.symbols, definition.decl.pattern, definition.decl.type, definition.decl.init, scope, errors, allocator);
            try put_all_symbols(&definition.decl.symbols, scope, errors);
            try symbolTableFromAST(definition.decl.type, scope, errors, allocator);
            try symbolTableFromAST(definition.decl.init, scope, errors, allocator);

            if (definition.decl.top_level) {
                for (definition.decl.symbols.items) |symbol| {
                    if (symbol.kind != ._const) {
                        errors.addError(Error{ .basic = .{ .span = symbol.span, .msg = "top level symbols must be marked `const`" } });
                        return error.symbolError;
                    }
                }
            }
        },
        .fnDecl => {
            if (definition.fnDecl.symbol != null) {
                // Do not re-do symbol if already declared
                return;
            }
            const symbol = try createFunctionSymbol(definition, scope, errors, allocator);
            const res = scope.lookup(symbol.name, false);
            switch (res) {
                .found => {
                    const first = res.found;
                    errors.addError(Error{ .redefinition = .{
                        .first_defined_span = first.span,
                        .redefined_span = symbol.span,
                        .name = symbol.name,
                    } });
                    return error.symbolError;
                },
                else => try scope.symbols.put(symbol.name, symbol),
            }
            definition.fnDecl.symbol = symbol;
        },
        ._defer => try symbolTableFromAST(definition._defer.statement, scope, errors, allocator),
        ._errdefer => try symbolTableFromAST(definition._errdefer.statement, scope, errors, allocator),
    }
}

fn put_all_symbols(symbols: *std.ArrayList(*Symbol), scope: *Scope, errors: *errs.Errors) !void {
    for (symbols.items) |symbol| {
        const res = scope.lookup(symbol.name, false);
        switch (res) {
            .found => {
                const first = res.found;
                errors.addError(Error{ .redefinition = .{
                    .first_defined_span = first.span,
                    .redefined_span = symbol.span,
                    .name = symbol.name,
                } });
                return error.symbolError;
            },
            else => try scope.symbols.put(symbol.name, symbol),
        }
    }
}

fn create_symbol(symbols: *std.ArrayList(*Symbol), pattern: *ast.AST, _type: *ast.AST, init: *ast.AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) SymbolErrorEnum!void {
    switch (pattern.*) {
        .symbol => {
            // TODO: Clean this up
            if (pattern.symbol.kind == ._const) {
                // `const` symbol, surround with comptime
                const definition = try AST.createComptime(init.getToken(), init, allocator);
                const comptime_symbol = try create_temp_comptime_symbol(definition, _type, scope, errors, allocator);
                const res = scope.lookup(comptime_symbol.name, false);
                switch (res) {
                    .found => {
                        const first = res.found;
                        errors.addError(Error{ .redefinition = .{
                            .first_defined_span = first.span,
                            .redefined_span = comptime_symbol.span,
                            .name = comptime_symbol.name,
                        } });
                        return error.symbolError;
                    },
                    else => try scope.symbols.put(comptime_symbol.name, comptime_symbol),
                }
                definition._comptime.symbol = comptime_symbol;

                const symbol = try Symbol.create(
                    scope,
                    pattern.symbol.name,
                    pattern.getToken().span,
                    _type,
                    definition,
                    null,
                    pattern.symbol.kind,
                    allocator,
                );
                pattern.symbol.symbol = symbol;
                try symbols.append(symbol);
            } else if (!std.mem.eql(u8, pattern.symbol.name, "_")) {
                // Regular `let` or `mut` symbol, not `_`
                const symbol = try Symbol.create(
                    scope,
                    pattern.symbol.name,
                    pattern.getToken().span,
                    _type,
                    init,
                    null,
                    pattern.symbol.kind,
                    allocator,
                );
                pattern.symbol.symbol = symbol;
                try symbols.append(symbol);
            } else if (pattern.symbol.kind != .let) {
                // It is an error for `_` to be marked as `const` or `mut`
                errors.addError(Error{ .discard_marked = .{
                    .span = pattern.getToken().span,
                    .kind = pattern.symbol.kind,
                } });
                return error.symbolError;
            } else {
                // Register the symbol of the symbol pattern as the blackhole symbol, but do not append
                pattern.symbol.symbol = primitives_.blackhole;
            }
        },
        .product => {
            for (pattern.product.terms.items, 0..) |term, i| {
                const index = try AST.createInt(pattern.getToken(), i, allocator);
                const new_type: *AST = try AST.createIndex(_type.getToken(), _type, index, allocator);
                const new_init: *AST = try AST.createIndex(init.getToken(), init, index, allocator);
                try create_symbol(symbols, term, new_type, new_init, scope, errors, allocator);
            }
        },
        .inject => {
            const lhs_type = try AST.createTypeOf(pattern.getToken(), init, allocator);
            const rhs_type = try AST.createDomainOf(pattern.getToken(), lhs_type, pattern, allocator);
            // All symbols need inits, this is just a phony init since these symbols are more like parameters.
            // We do the same for parameters, btw!
            const phony_init = try AST.createDefault(pattern.getToken(), rhs_type, allocator);

            try create_symbol(symbols, pattern.inject.lhs, lhs_type, phony_init, scope, errors, allocator);
            try create_symbol(symbols, pattern.inject.rhs, rhs_type, phony_init, scope, errors, allocator);
        },
        else => {},
    }
}

fn create_match_pattern_symbol(match: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    for (match.match.mappings.items) |mapping| {
        if (mapping.mapping.lhs != null) {
            const new_scope = try Scope.init(scope, "", allocator);
            mapping.mapping.scope = new_scope;
            var symbols = std.ArrayList(*Symbol).init(allocator);
            defer symbols.deinit();
            const _type = try AST.createTypeOf(match.match.expr.getToken(), match.match.expr, allocator);
            try create_symbol(&symbols, mapping.mapping.lhs.?, _type, match.match.expr, new_scope, errors, allocator);
            for (symbols.items) |symbol| {
                symbol.defined = true;
            }
            try put_all_symbols(&symbols, new_scope, errors);
            try symbolTableFromAST(mapping.mapping.rhs, new_scope, errors, allocator);
        } else {
            try symbolTableFromAST(mapping.mapping.rhs, scope, errors, allocator);
        }
    }
}

fn createFunctionSymbol(definition: *ast.AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) SymbolErrorEnum!*Symbol {
    // Calculate the domain type from the function paramter types
    const domain = try extractDomain(
        definition.fnDecl.params,
        definition.fnDecl.retType.getToken(),
        allocator,
    );

    // Create the function type
    const _type = try AST.createFunction(
        definition.fnDecl.retType.getToken(),
        domain,
        definition.fnDecl.retType,
        allocator,
    );

    // Create the function scope
    var fnScope = try Scope.init(scope, "", allocator);
    fnScope.in_function = scope.in_function + 1;

    // Recurse parameters and init
    try symbolTableFromASTList(definition.fnDecl.params, fnScope, errors, allocator);
    try symbolTableFromAST(definition.fnDecl.retType, fnScope, errors, allocator);

    // Put the param symbols in the param symbols list
    for (definition.fnDecl.params.items) |param| {
        const symbol = param.decl.symbols.items[0];
        try definition.fnDecl.param_symbols.append(symbol);
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
    if (definition.fnDecl.name) |name| {
        buf = name.getToken().data;
    } else {
        buf = try nextAnonFunctionName(allocator);
    }
    const retval = try Symbol.create(
        fnScope,
        buf,
        definition.getToken().span,
        _type,
        definition.fnDecl.init,
        definition,
        ._fn,
        allocator,
    );
    fnScope.inner_function = retval;

    try symbolTableFromAST(definition.fnDecl.init, fnScope, errors, allocator);
    return retval;
}

var numAnonFunctions: usize = 0;
fn nextAnonFunctionName(allocator: std.mem.Allocator) SymbolErrorEnum![]const u8 {
    defer numAnonFunctions += 1;
    var out = String.init(allocator);
    defer out.deinit();
    try out.writer().print("$anon{}", .{numAnonFunctions});
    return (try out.toOwned()).?;
}

fn extractDomain(params: std.ArrayList(*AST), token: Token, allocator: std.mem.Allocator) SymbolErrorEnum!*AST {
    if (params.items.len == 0) {
        return try AST.createUnitType(token, allocator);
    } else if (params.items.len <= 1) {
        return AST.createAnnotation(params.items[0].getToken(), params.items[0].decl.pattern, params.items[0].decl.type, null, params.items[0].decl.init, allocator);
    } else {
        std.debug.assert(params.items.len >= 2);
        var param_types = std.ArrayList(*AST).init(allocator);
        var i: usize = 0;
        while (i < params.items.len) : (i += 1) {
            try param_types.append(try AST.createAnnotation(params.items[i].getToken(), params.items[i].decl.pattern, params.items[i].decl.type, null, params.items[i].decl.init, allocator));
        }
        const retval = try AST.createProduct(params.items[0].getToken(), param_types, allocator);
        return retval;
    }
}

// definition is a `comptime` ast
fn create_temp_comptime_symbol(definition: *ast.AST, rhs_type_hint: ?*ast.AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) SymbolErrorEnum!*Symbol {
    // Create the function type. The rhs is a typeof node, since type expansion is done in a later time
    const lhs = try AST.createUnitType(definition._comptime.expr.getToken(), allocator);
    const rhs = try AST.createTypeOf(definition._comptime.expr.getToken(), definition._comptime.expr, allocator);
    const _type = try AST.createFunction(definition._comptime.expr.getToken(), lhs, rhs_type_hint orelse rhs, allocator);

    // Create the comptime scope
    // This is to prevent `comptime` expressions from using runtime variables
    var comptime_scope = try Scope.init(scope, "", allocator);
    comptime_scope.in_function = scope.in_function;

    // Choose name
    var buf: []const u8 = undefined;
    buf = try next_comptime_name(allocator);

    // Create the symbol
    const retval = try Symbol.create(
        comptime_scope,
        buf,
        definition.getToken().span,
        _type,
        definition._comptime.expr,
        definition,
        ._comptime,
        allocator,
    );
    comptime_scope.inner_function = retval;

    try symbolTableFromAST(definition._comptime.expr, comptime_scope, errors, allocator);
    return retval;
}

var num_comptime: usize = 0;
fn next_comptime_name(allocator: std.mem.Allocator) SymbolErrorEnum![]const u8 {
    // TODO: Idk maybe generalize this with the anon function name
    defer numAnonFunctions += 1;
    var out = String.init(allocator);
    defer out.deinit();
    try out.writer().print("$comptime{}", .{numAnonFunctions});
    return (try out.toOwned()).?;
}
