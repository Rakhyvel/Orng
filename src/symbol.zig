const std = @import("std");
const ast = @import("ast.zig");
const errs = @import("errors.zig");
const _span = @import("span.zig");

const AST = ast.AST;
const Error = errs.Error;
const Span = _span.Span;
const String = @import("zig-string/zig-string.zig").String;
const Token = @import("token.zig").Token;

pub const SymbolErrorEnum = error{ symbolError, OutOfMemory };

pub const Scope = struct {
    parent: ?*Scope,
    children: std.ArrayList(*Scope),
    symbols: std.StringArrayHashMap(*Symbol),

    pub fn init(parent: ?*Scope, allocator: std.mem.Allocator) !*Scope {
        var retval = try allocator.create(Scope);
        retval.parent = parent;
        retval.children = std.ArrayList(*Scope).init(allocator);
        retval.symbols = std.StringArrayHashMap(*Symbol).init(allocator);
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

    pub fn pprint(self: *Scope) void {
        for (self.symbols.keys()) |key| {
            std.debug.print("{s}\n", .{key});
        }
    }

    pub fn serialize(self: *Scope, out: *String) !void {
        try out.insert("{", out.len());
        var keySet = self.symbols.keys();
        var i: usize = 0;
        while (i < keySet.len) : (i += 1) {
            var key = keySet[i];
            try out.insert(self.symbols.get(key).?.name, out.len());
            if (i < keySet.len - 1) {
                try out.insert(", ", out.len());
            }
        }
        try out.insert("}", out.len());
    }
};

pub const Symbol = struct {
    scope: *Scope,
    name: []const u8,
    span: Span,
    _type: ?*ast.AST,
    init: ?*ast.AST,

    pub fn create(scope: *Scope, name: []const u8, span: Span, _type: ?*ast.AST, _init: ?*ast.AST, allocator: std.mem.Allocator) !*Symbol {
        var retval = try allocator.create(Symbol);
        retval.scope = scope;
        retval.name = name;
        retval.span = span;
        retval._type = _type;
        retval.init = _init;
        return retval;
    }
};

// Walk AST, if come across a block, create new scope on it, if def, create new symbol entry
pub fn createScope(definitions: std.ArrayList(*ast.AST), root: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) SymbolErrorEnum!*Scope {
    var retval = try Scope.init(root, allocator);
    retval.parent = root;
    for (definitions.items) |definition| {
        switch (definition.*) {
            .block => {
                try retval.children.append(try createScope(definition.block.statements, retval, errors, allocator));
            },

            .decl => {
                var symbol = try createSymbol(definition, retval, allocator);
                if (retval.lookup(symbol.name)) |first| {
                    errors.addError(Error{ .redefinition = .{
                        .first_defined_span = first.span,
                        .redefined_span = symbol.span,
                        .name = symbol.name,
                    } });
                    return error.symbolError;
                } else {
                    try retval.symbols.put(symbol.name, symbol);
                }
            },

            .fnDecl => {
                var symbol = try createFunctionSymbol(definition, retval, errors, allocator);
                if (retval.lookup(symbol.name)) |first| {
                    errors.addError(Error{ .redefinition = .{
                        .first_defined_span = first.span,
                        .redefined_span = symbol.span,
                        .name = symbol.name,
                    } });
                    return error.symbolError;
                } else {
                    try retval.symbols.put(symbol.name, symbol);
                }
            },

            else => {},
        }
    }

    return retval;
}

fn createSymbol(definition: *ast.AST, scope: *Scope, allocator: std.mem.Allocator) SymbolErrorEnum!*Symbol {
    return try Symbol.create(
        scope,
        definition.decl.pattern.identifier.token.data,
        definition.decl.pattern.getToken().span,
        definition.decl.type,
        definition.decl.init,
        allocator,
    );
}

fn createFunctionSymbol(definition: *ast.AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) SymbolErrorEnum!*Symbol {
    var domain = try extractDomain(
        definition.fnDecl.params,
        definition.fnDecl.retType.getToken(),
        allocator,
    );
    var _type = try AST.createBinop(
        definition.fnDecl.retType.getToken(),
        domain,
        definition.fnDecl.retType,
        allocator,
    );
    var fnScope = try createScope(definition.fnDecl.params, scope, errors, allocator);

    return try Symbol.create(
        fnScope,
        definition.fnDecl.name.?.identifier.token.data, // TODO: This currently doesn't support anonymous functions
        definition.fnDecl.name.?.getToken().span,
        _type,
        definition.fnDecl.init,
        allocator,
    );
}

fn extractDomain(params: std.ArrayList(*AST), token: Token, allocator: std.mem.Allocator) SymbolErrorEnum!*AST {
    if (params.items.len == 0) {
        return try AST.createUnit(token, allocator);
    } else {
        var retval: *AST = params.items[0].decl.type.?;
        var i: usize = 1;
        while (i < params.items.len) : (i += 1) {
            retval = try AST.createBinop(params.items[i].getToken(), retval, params.items[i], allocator);
        }
        return retval;
    }
}
