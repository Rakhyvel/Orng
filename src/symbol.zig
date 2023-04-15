const std = @import("std");
const ast = @import("ast.zig");
const errors = @import("errors.zig");
const _span = @import("span.zig");

const Error = errors.Error;
const Span = _span.Span;
const String = @import("zig-string/zig-string.zig").String;

pub const SymbolErrorEnum = error{symbolError};

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
};

pub const Symbol = struct {
    scope: *Scope,
    name: []const u8,
    span: Span,
    _type: ?*ast.AST,
    init: ?*ast.AST,

    pub fn init(scope: *Scope, name: []const u8, span: Span, _type: ?*ast.AST, _init: ?*ast.AST, allocator: std.mem.Allocator) !*Symbol {
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
pub fn createScope(definitions: std.ArrayList(*ast.AST), root: *Scope, allocator: std.mem.Allocator) !*Scope {
    var retval = try Scope.init(root, allocator);
    retval.parent = root;
    for (definitions.items) |definition| {
        switch (definition.data) {
            .block => {
                try retval.children.append(try createScope(definition.data.block.statements, retval, allocator));
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
                var symbol = try createFunctionSymbol(definition, retval, allocator);
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

fn createSymbol(definition: *ast.AST, scope: *Scope, allocator: std.mem.Allocator) !*Symbol {
    return try Symbol.init(
        scope,
        definition.data.decl.pattern.data.identifier.data,
        definition.data.decl.pattern.token.span,
        definition.data.decl.type,
        definition.data.decl.init,
        allocator,
    );
}

fn createFunctionSymbol(definition: *ast.AST, scope: *Scope, allocator: std.mem.Allocator) !*Symbol {
    return try Symbol.init(
        scope,
        definition.data.fnDecl.name.?.data.identifier.data, // TODO: This currently doesn't support anonymous functions
        definition.data.fnDecl.name.?.token.span,
        definition.data.fnDecl.retType,
        definition.data.fnDecl.init,
        allocator,
    );
}
