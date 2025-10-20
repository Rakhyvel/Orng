//! This file represents a struct for an AST walk, and expands complex import pattern ASTs into simpler forms which
//! are easier to work with.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const walker_ = @import("../ast/walker.zig");

indent: usize,

const Self = @This();

pub fn new(indent: usize) Self {
    return Self{ .indent = indent };
}

/// Converts imports to constant declarations
pub fn prefix(self: Self, ast: *ast_.AST) walker_.Error!?Self {
    for (0..self.indent) |_| {
        std.debug.print(" ", .{});
    }
    std.debug.print("{t}(", .{ast.*});
    switch (ast.*) {
        else => {},
        .identifier => std.debug.print(".data={s}, .symbol={?f}", .{ ast.token().data, if (ast.symbol()) |sym| sym.type() else null }),
        .fn_decl => std.debug.print(".name={?f}", .{ast.fn_decl.name}),
        .binding => std.debug.print(".pattern={f}, .type={f}, .init={?f}", .{ ast.binding.pattern, ast.binding.type, ast.binding.init }),
    }
    std.debug.print(")\n", .{});
    return Self.new(self.indent + 4);
}
