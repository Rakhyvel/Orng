//! This file represents a struct for an AST walk, and is used to decorate identifier ASTs with symbols they refer to.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const Scope = @import("../symbol/scope.zig");
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
            const res = self.scope.lookup(ast.token().data, .{});
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

            // try ast.symbol().?.err_if_undefined(self.errors);

            return self;
        },

        .@"if", .match, .mapping, .@"while", .@"for", .block, .impl, .trait => {
            var new_context = self;
            new_context.scope = ast.scope().?;
            return new_context;
        },

        .fn_decl => {
            var new_context = self;
            new_context.scope = ast.symbol().?.scope;
            return new_context;
        },

        .access => {
            // Capture scope, so that `Trait::member` accesses are began at the access point
            ast.set_scope(self.scope);
            return self;
        },
    }
}

pub fn postfix(self: Self, ast: *ast_.AST) walk_.Error!void {
    switch (ast.*) {
        else => {},

        .decl => {
            for (ast.decl.symbols.items) |symbol| {
                symbol.defined = true;
            }
        },
        .trait => self.scope.traits.append(ast) catch unreachable,
        .impl => self.scope.impls.append(ast) catch unreachable,
        .@"test" => self.scope.tests.append(ast) catch unreachable,
    }
}
