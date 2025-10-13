//! This file represents a struct for an AST walk, and is used to decorate identifier ASTs with symbols they refer to.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const Scope = @import("../symbol/scope.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const walk_ = @import("../ast/walker.zig");

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

pub fn prefix(self: Self, ast: *ast_.AST) walk_.Error!?Self {
    switch (ast.*) {
        else => return self,

        .identifier => {
            if (ast.symbol() != null) return self;

            const res = self.scope.lookup(ast.token().data, .{ .allow_modules = true });
            switch (res) {
                // Found the symbol, decorate the identifier AST with it
                .found => ast.set_symbol(res.found),

                // Couldn't find the symbol
                .not_found => {
                    self.errors.add_error(errs_.Error{ .undeclared_identifier = .{ .identifier = ast.token(), .expected = null } });
                    return error.CompileError;
                },

                // Found the symbol, but must cross a comptime-boundary to access it, and it is not const
                .found_but_rt => {
                    self.errors.add_error(errs_.Error{ .comptime_access_runtime = .{ .identifier = ast.token() } });
                    return error.CompileError;
                },

                // Found the symbol, but must cross an inner-function boundary to access it, and it is not const
                .found_but_fn => {
                    self.errors.add_error(errs_.Error{ .inner_fn_access_runtime = .{ .identifier = ast.token() } });
                    return error.CompileError;
                },
            }

            if ((ast.symbol().?.kind == .let or ast.symbol().?.kind == .mut) // local variable
            and ast.symbol().?.decl.?.decl_init() != null // not a parameter
            and !ast.symbol().?.defined // not defined
            ) {
                self.errors.add_error(errs_.Error{ .use_before_def = .{ .identifier = ast.token() } });
                return error.CompileError;
            }

            return self;
        },

        .@"if", .match, .mapping, .@"while", .@"for", .block, .impl, .trait, .struct_decl, .enum_decl, .type_alias, .fn_decl => {
            var new_context = self;
            new_context.scope = ast.scope().?;
            return new_context;
        },

        .method_decl => {
            var new_context = self;
            if (ast.symbol() != null) {
                new_context.scope = ast.symbol().?.scope;
            }
            return new_context;
        },

        .access => {
            // Capture scope, so that `Trait::member` accesses are began at the access point
            ast.set_scope(self.scope);
            return self;
        },
    }
}

pub fn prefix_type(self: Self, _type: *Type_AST) walk_.Error!?Self {
    switch (_type.*) {
        else => return self,

        .identifier => {
            if (_type.symbol()) |_| {
                // Do not re-decorate.
                // Symbols are injected into ident types for lexical generic scoping
                // Keep those symbols the way they are, even if they're not "visible" from this scope!
                return self;
            }
            const res = self.scope.lookup(_type.token().data, .{});
            switch (res) {
                // Found the symbol, decorate the identifier AST with it
                .found => _type.set_symbol(res.found),

                // Couldn't find the symbol
                .not_found => {
                    self.errors.add_error(errs_.Error{ .undeclared_identifier = .{ .identifier = _type.token(), .expected = null } });
                    return error.CompileError;
                },

                // Found the symbol, but must cross a comptime-boundary to access it, and it is not const
                .found_but_rt => {
                    self.errors.add_error(errs_.Error{ .comptime_access_runtime = .{ .identifier = _type.token() } });
                    return error.CompileError;
                },

                // Found the symbol, but must cross an inner-function boundary to access it, and it is not const
                .found_but_fn => {
                    self.errors.add_error(errs_.Error{ .inner_fn_access_runtime = .{ .identifier = _type.token() } });
                    return error.CompileError;
                },
            }

            return self;
        },
    }
}

pub fn postfix(self: Self, ast: *ast_.AST) walk_.Error!void {
    switch (ast.*) {
        else => {},

        .binding => {
            for (ast.binding.decls.items) |decl| {
                if (decl.* == .decl) {
                    decl.decl.name.symbol().?.defined = true;
                }
            }
        },
        .trait => self.scope.traits.append(ast) catch unreachable,
        .impl => self.scope.impls.append(ast) catch unreachable,
        .@"test" => self.scope.tests.append(ast) catch unreachable,

        .select => {
            if (ast.lhs().* == .identifier and ast.lhs().symbol() != null and ast.lhs().symbol().?.refers_to_type()) {
                const enum_value = ast_.AST.create_enum_value(ast.rhs().token(), self.allocator);
                enum_value.enum_value.base = Type_AST.create_identifier(ast.lhs().token(), self.allocator);
                enum_value.enum_value.base.?.set_symbol(ast.lhs().symbol());
                ast.* = enum_value.*;
            }
        },
    }
}
