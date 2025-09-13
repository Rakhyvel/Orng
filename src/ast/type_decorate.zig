//! This file represents a struct for an AST walk, and is used to decorate ASTs with their types.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const Scope = @import("../symbol/scope.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const walk_ = @import("../ast/walker.zig");
const type_walk_ = @import("../types/walker.zig");

scope: *Scope,
errors: *errs_.Errors,
allocator: std.mem.Allocator,

const Self = @This();

pub fn new(scope: *Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) Self {
    return Self{
        .scope = scope,
        .errors = errors,
        .allocator = allocator,
    };
}

pub fn postfix_type(self: Self, _type: *Type_AST) type_walk_.Error!void {
    while (_type.* == .type_of) {
        _type.* = _type.type_of._expr.typeof(self.allocator).expand_identifier().*;
    }
}
