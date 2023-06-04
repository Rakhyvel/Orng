const std = @import("std");
const ast = @import("ast.zig");
const errs = @import("errors.zig");
const _span = @import("span.zig");

const AST = ast.AST;
const Error = errs.Error;
const Span = _span.Span;
const String = @import("zig-string/zig-string.zig").String;
const Token = @import("token.zig").Token;

pub const SymbolErrorEnum = error{ symbolError, OutOfMemory, NoSpaceLeft, InvalidRange };

var scopeUID: usize = 0;
pub const Scope = struct {
    parent: ?*Scope,
    children: std.ArrayList(*Scope),
    symbols: std.StringArrayHashMap(*Symbol),
    name: []const u8,
    uid: usize,

    in_loop: bool = false,
    in_function: bool = false,
    defers: std.ArrayList(*AST),

    pub fn init(parent: ?*Scope, name: []const u8, allocator: std.mem.Allocator) !*Scope {
        var retval = try allocator.create(Scope);
        retval.parent = parent;
        retval.children = std.ArrayList(*Scope).init(allocator);
        retval.symbols = std.StringArrayHashMap(*Symbol).init(allocator);
        retval.name = name;
        retval.uid = scopeUID;
        retval.defers = std.ArrayList(*AST).init(allocator);
        scopeUID += 1;
        if (parent) |_parent| {
            try _parent.children.append(retval);
        }
        return retval;
    }

    pub fn lookup(self: *Scope, name: []const u8) ?*Symbol {
        if (self.symbols.get(name)) |symbol| {
            return symbol;
        } else if (self.parent) |non_null_parent| {
            return non_null_parent.lookup(name);
        } else {
            return null;
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
        var keySet = self.symbols.keys();
        var i: usize = 0;
        while (i < keySet.len) : (i += 1) {
            var key = keySet[i];
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

    pub fn containedInALoop(self: *Scope) bool {
        if (self.in_loop) {
            return true;
        } else if (self.parent) |parent| {
            return containedInALoop(parent);
        } else {
            return false;
        }
    }

    pub fn containedInAFunction(self: *Scope) bool {
        if (self.in_function) {
            return true;
        } else if (self.parent) |parent| {
            return containedInAFunction(parent);
        } else {
            return false;
        }
    }
};

pub const SymbolKind = enum { _fn, _const, let, mut };

pub const Symbol = struct {
    scope: *Scope,
    name: []const u8,
    span: Span,
    _type: ?*ast.AST,
    init: ?*ast.AST,
    versions: u64,
    kind: SymbolKind,

    defined: bool,
    valid: bool,
    /// When a local variable, whether or not the variable has been printed out or not
    decld: bool,

    pub fn create(scope: *Scope, name: []const u8, span: Span, _type: ?*ast.AST, _init: ?*ast.AST, kind: SymbolKind, allocator: std.mem.Allocator) !*Symbol {
        var retval = try allocator.create(Symbol);
        retval.scope = scope;
        retval.name = name;
        retval.span = span;
        retval._type = _type;
        retval.init = _init;
        retval.versions = 0;
        retval.kind = kind;
        if (kind == ._fn or kind == ._const) {
            retval.defined = true;
        } else {
            retval.defined = false;
        }
        retval.valid = false;
        retval.decld = false;
        return retval;
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
        .unit,
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
        => {},

        .not => try symbolTableFromAST(definition.not.expr, scope, errors, allocator),
        .negate => try symbolTableFromAST(definition.negate.expr, scope, errors, allocator),
        .dereference => try symbolTableFromAST(definition.dereference.expr, scope, errors, allocator),
        ._try => try symbolTableFromAST(definition._try.expr, scope, errors, allocator),
        .optional => try symbolTableFromAST(definition.optional.expr, scope, errors, allocator),
        .fromOptional => try symbolTableFromAST(definition.fromOptional.expr, scope, errors, allocator),
        .inferredError => try symbolTableFromAST(definition.inferredError.expr, scope, errors, allocator),

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
        .notEqual => {
            try symbolTableFromAST(definition.notEqual.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.notEqual.rhs, scope, errors, allocator);
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
        .exponent => {
            try symbolTableFromASTList(definition.exponent.terms, scope, errors, allocator);
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
            try symbolTableFromAST(definition.call.rhs, scope, errors, allocator);
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
        .delta => {
            try symbolTableFromAST(definition.delta.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.delta.rhs, scope, errors, allocator);
        },
        .composition => {
            try symbolTableFromAST(definition.composition.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.composition.rhs, scope, errors, allocator);
        },
        .prepend => {
            try symbolTableFromAST(definition.prepend.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.prepend.rhs, scope, errors, allocator);
        },
        .sum => {
            try symbolTableFromAST(definition.sum.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.sum.rhs, scope, errors, allocator);
        },
        ._error => {
            try symbolTableFromAST(definition._error.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition._error.rhs, scope, errors, allocator);
        },
        .diff => {
            try symbolTableFromAST(definition.diff.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.diff.rhs, scope, errors, allocator);
        },
        .concat => {
            try symbolTableFromAST(definition.concat.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.concat.rhs, scope, errors, allocator);
        },
        ._union => {
            try symbolTableFromAST(definition._union.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition._union.rhs, scope, errors, allocator);
        },

        .product => {
            try symbolTableFromASTList(definition.product.terms, scope, errors, allocator);
        },
        .conditional => {
            try symbolTableFromASTList(definition.conditional.exprs, scope, errors, allocator);
        },
        .addrOf => try symbolTableFromAST(definition.addrOf.expr, scope, errors, allocator),
        .sliceOf => {
            try symbolTableFromAST(definition.sliceOf.expr, scope, errors, allocator);
            try symbolTableFromAST(definition.sliceOf.len, scope, errors, allocator);
        },
        .namedArg => {
            try symbolTableFromAST(definition.namedArg.ident, scope, errors, allocator);
            try symbolTableFromAST(definition.namedArg.init, scope, errors, allocator);
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
        .inferredMember => {
            try symbolTableFromAST(definition.inferredMember.ident, scope, errors, allocator);
            try symbolTableFromAST(definition.inferredMember.init, scope, errors, allocator);
        },

        ._if => {
            var new_scope = try Scope.init(scope, "", allocator);
            definition._if.scope = new_scope;
            try symbolTableFromAST(definition._if.let, scope, errors, allocator);
            try symbolTableFromAST(definition._if.condition, scope, errors, allocator);
            try symbolTableFromAST(definition._if.bodyBlock, scope, errors, allocator);
            try symbolTableFromAST(definition._if.elseBlock, scope, errors, allocator);
        },
        .cond => {
            var new_scope = try Scope.init(scope, "", allocator);
            definition.cond.scope = new_scope;
            try symbolTableFromAST(definition.cond.let, scope, errors, allocator);
            try symbolTableFromASTList(definition.cond.mappings, scope, errors, allocator);
        },
        .match => {
            var new_scope = try Scope.init(scope, "", allocator);
            definition.match.scope = new_scope;
            try symbolTableFromAST(definition.match.let, scope, errors, allocator);
            try symbolTableFromAST(definition.match.expr, scope, errors, allocator);
            try symbolTableFromASTList(definition.match.mappings, scope, errors, allocator);
        },
        .mapping => {
            try symbolTableFromAST(definition.mapping.lhs, scope, errors, allocator);
            try symbolTableFromAST(definition.mapping.rhs, scope, errors, allocator);
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
            var new_scope = try Scope.init(scope, "", allocator);
            definition._for.scope = new_scope;
            try symbolTableFromAST(definition._for.let, scope, errors, allocator);
            try symbolTableFromAST(definition._for.elem, scope, errors, allocator);
            try symbolTableFromAST(definition._for.iterable, scope, errors, allocator);
            try symbolTableFromAST(definition._for.bodyBlock, scope, errors, allocator);
            try symbolTableFromAST(definition._for.elseBlock, scope, errors, allocator);
        },
        .block => {
            var new_scope = try Scope.init(scope, "", allocator);
            definition.block.scope = new_scope;
            try symbolTableFromASTList(definition.block.statements, new_scope, errors, allocator);
            if (definition.block.final) |final| {
                try symbolTableFromAST(final, new_scope, errors, allocator);
            }
        },

        .throw => try symbolTableFromAST(definition.throw.expr, scope, errors, allocator),
        ._return => try symbolTableFromAST(definition._return.expr, scope, errors, allocator),
        .decl => {
            // Both put a Symbol in the current scope, and recurse
            var symbol = try createSymbol(definition, scope, allocator);
            if (scope.lookup(symbol.name)) |first| {
                errors.addError(Error{ .redefinition = .{
                    .first_defined_span = first.span,
                    .redefined_span = symbol.span,
                    .name = symbol.name,
                    .stage = .symbolTree,
                } });
                return error.symbolError;
            } else {
                try scope.symbols.put(symbol.name, symbol);
            }
            try symbolTableFromAST(definition.decl.type, scope, errors, allocator);
            try symbolTableFromAST(definition.decl.init, scope, errors, allocator);
        },
        .fnDecl => {
            var symbol = try createFunctionSymbol(definition, scope, errors, allocator);
            if (scope.lookup(symbol.name)) |first| {
                errors.addError(Error{ .redefinition = .{
                    .first_defined_span = first.span,
                    .redefined_span = symbol.span,
                    .name = symbol.name,
                    .stage = .symbolTree,
                } });
                return error.symbolError;
            } else {
                try scope.symbols.put(symbol.name, symbol);
            }
        },
        ._defer => try symbolTableFromAST(definition._defer.statement, scope, errors, allocator),
    }
}

fn createSymbol(definition: *ast.AST, scope: *Scope, allocator: std.mem.Allocator) SymbolErrorEnum!*Symbol {
    var kind: SymbolKind = undefined;
    switch (definition.decl.common.token.kind) {
        .CONST => kind = ._const,
        .LET => kind = .let,
        .MUT => kind = .mut,
        else => unreachable,
    }

    var retval = try Symbol.create(
        scope,
        definition.decl.pattern.identifier.common.token.data,
        definition.decl.pattern.getToken().span,
        definition.decl.type,
        definition.decl.init,
        kind,
        allocator,
    );
    definition.decl.symbol = retval;
    return retval;
}

fn createFunctionSymbol(definition: *ast.AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) SymbolErrorEnum!*Symbol {
    var domain = try extractDomain(
        definition.fnDecl.params,
        definition.fnDecl.retType.getToken(),
        allocator,
    );
    var _type = try AST.createFunction(
        definition.fnDecl.retType.getToken(),
        domain,
        definition.fnDecl.retType,
        allocator,
    );
    var fnScope = try Scope.init(scope, "", allocator);
    fnScope.in_function = true;
    try symbolTableFromASTList(definition.fnDecl.params, fnScope, errors, allocator);
    try symbolTableFromAST(definition.fnDecl.init, fnScope, errors, allocator);

    var buf: []const u8 = undefined;
    if (definition.fnDecl.name) |name| {
        buf = name.identifier.common.token.data;
    } else {
        buf = try nextAnonFunctionName();
    }
    return try Symbol.create(
        fnScope,
        buf,
        definition.getToken().span,
        _type,
        definition.fnDecl.init,
        ._fn,
        allocator,
    );
}

var numAnonFunctions: usize = 0;
fn nextAnonFunctionName() SymbolErrorEnum![]const u8 {
    defer numAnonFunctions += 1;
    var buf: [64]u8 = undefined;
    _ = try std.fmt.bufPrint(&buf, "_anon{}", .{numAnonFunctions});
    return &buf;
}

fn extractDomain(params: std.ArrayList(*AST), token: Token, allocator: std.mem.Allocator) SymbolErrorEnum!*AST {
    if (params.items.len == 0) {
        return try AST.createUnit(token, allocator);
    } else if (params.items.len < 2) {
        return params.items[0].decl.type.?;
    } else {
        std.debug.assert(params.items.len >= 2);
        var param_types = std.ArrayList(*AST).init(allocator);
        var i: usize = 0;
        while (i < params.items.len) : (i += 1) {
            try param_types.append(params.items[i]);
        }
        return try AST.createProduct(params.items[0].getToken(), param_types, allocator);
    }
}

var prelude: ?*Scope = null;
pub fn getPrelude() !*Scope {
    if (prelude) |_prelude| {
        return _prelude;
    }
    prelude = try Scope.init(null, "", std.heap.page_allocator);
    try prelude.?.symbols.put("Bool", try Symbol.create(
        prelude.?,
        "Bool",
        Span{ .col = 0, .line = 0 },
        ast.typeType,
        null,
        ._const,
        std.heap.page_allocator,
    ));
    try prelude.?.symbols.put("Char", try Symbol.create(
        prelude.?,
        "Char",
        Span{ .col = 0, .line = 0 },
        ast.typeType,
        null,
        ._const,
        std.heap.page_allocator,
    ));
    try prelude.?.symbols.put("Float", try Symbol.create(
        prelude.?,
        "Float",
        Span{ .col = 0, .line = 0 },
        ast.typeType,
        null,
        ._const,
        std.heap.page_allocator,
    ));
    try prelude.?.symbols.put("Int", try Symbol.create(
        prelude.?,
        "Int",
        Span{ .col = 0, .line = 0 },
        ast.typeType,
        null,
        ._const,
        std.heap.page_allocator,
    ));
    try prelude.?.symbols.put("Type", try Symbol.create(
        prelude.?,
        "Type",
        Span{ .col = 0, .line = 0 },
        ast.typeType,
        null,
        ._const,
        std.heap.page_allocator,
    ));
    return prelude.?;
}
pub fn resetPrelude() void {
    prelude = null;
}
