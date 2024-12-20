// Walks over AST and Symbol Tree, decorates identifier ASTs with the symbol they refer to.

const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const symbol_ = @import("symbol.zig");
const walk_ = @import("walker.zig");

pub const Decorate_Identifiers = struct {
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,

    const Self = @This();

    pub fn new(scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) Self {
        return Self{
            .scope = scope,
            .errors = errors,
            .allocator = allocator,
        };
    }

    pub fn prefix(self: Self, ast: *ast_.AST) walk_.Error!Self {
        switch (ast.*) {
            else => return self,

            .identifier => {
                const res = self.scope.lookup(ast.token().data, false);
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
                if (!ast.symbol().?.defined) {
                    self.errors.add_error(errs_.Error{ .use_before_def = .{ .identifier = ast.token() } });
                    return error.CompileError;
                }

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
        }
    }
};
