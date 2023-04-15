const std = @import("std");
const ast = @import("ast.zig");

pub const Scope = struct {
    parent: ?*Scope,
    children: std.ArrayList(*Scope),
    symbols: std.StringHashMap(*Symbol),
};

pub const Symbol = struct {
    name: []const u8,
    _type: *ast.AST,
    init: *ast.AST,
};

pub fn createSymbolTable(program: *ast.AST, allocator: std.mem.Allocator) !*Scope {
    _ = program;
    return try allocator.create(Scope);
}
