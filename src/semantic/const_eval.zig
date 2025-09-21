//! This file represents a struct for an AST walk, and is used to decorate identifier ASTs with symbols they refer to.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const defaults_ = @import("defaults.zig");
const Scope = @import("../symbol/scope.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const walk_ = @import("../ast/walker.zig");

const Self: type = @This();

ctx: *Compiler_Context,
map: std.AutoArrayHashMap(*ast_.AST, *Type_AST),

pub fn new(ctx: *Compiler_Context) Self {
    return Self{
        .ctx = ctx,
        .map = std.AutoArrayHashMap(*ast_.AST, *Type_AST).init(ctx.allocator()),
    };
}

pub fn prefix(self: Self, ast: *ast_.AST) walk_.Error!?Self {
    switch (ast.*) {
        else => return self,

        .default => {
            const _type = ast.default._type;
            ast.* = (try defaults_.generate_default(ast.default._type, ast.token().span, &self.ctx.errors, self.ctx.allocator())).*;
            _ = try self.ctx.typecheck.typecheck_AST(ast, _type);
            return self;
        },

        .size_of => {
            const _type = ast.size_of._type;
            ast.* = ast_.AST.create_int(ast.token(), _type.sizeof(), self.ctx.allocator()).*;
            _ = try self.ctx.typecheck.typecheck_AST(ast, null);
            return self;
        },
    }
}
