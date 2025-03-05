//! This file represents a struct for an AST walk, and is used to decorate access ASTs with symbols they refer to.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const compiler_ = @import("../compilation/compiler.zig");
const errs_ = @import("../util/errors.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const walk_ = @import("../ast/walker.zig");

scope: *Scope,
errors: *errs_.Errors,
compiler: *compiler_.Context,

const Self = @This();

pub fn new(scope: *Scope, errors: *errs_.Errors, compiler: *compiler_.Context) Self {
    return Self{ .scope = scope, .errors = errors, .compiler = compiler };
}

pub fn prefix(self: Self, ast: *ast_.AST) walk_.Error!?Self {
    switch (ast.*) {
        else => return self,

        .access => {
            ast.set_symbol(try self.resolve_qualified_name(ast));
            return null;
        },
    }
}

fn resolve_qualified_name(self: Self, ast: *ast_.AST) walk_.Error!*Symbol {
    if ((ast.* == .identifier or ast.* == .pattern_symbol) and ast.symbol().?.kind == .import) {
        const this_module = ast.symbol().?.scope.module.?;
        const curr_package_path = this_module.get_package_abs_path();
        var module_path_name = String.init(self.compiler.allocator());
        defer module_path_name.deinit();
        module_path_name.writer().print("{s}.orng", .{ast.token().data}) catch unreachable;
        const package_build_paths = [_][]const u8{ curr_package_path, module_path_name.str() };
        const other_module_dir = std.fs.path.join(self.compiler.allocator(), &package_build_paths) catch unreachable;

        // TODO: If these are both non-null, report the ambiguity
        //       If these are both null, report that the module was not found

        const local_module_lookup = self.compiler.lookup_module(other_module_dir);
        const foreign_module_lookup = self.compiler.lookup_package_root_module(this_module.package_name, ast.symbol().?.kind.import.real_name);

        return (local_module_lookup orelse foreign_module_lookup).?;
    } else if ((ast.* == .identifier or ast.* == .pattern_symbol) and ast.symbol().?.kind == .module) {
        return ast.symbol().?;
    } else if (ast.* == .identifier) {
        // NOT an import symbol
        // MUST be within this module
        // just return whatever it refers to
        return ast.symbol().?;
    } else if (ast.* == .access) {
        const stripped_lhs = if (ast.lhs().* == .addr_of) ast.lhs().expr() else ast.lhs();
        const expanded_lhs = try self.resolve_qualified_name(stripped_lhs);
        return try self.resolve_access_symbol(expanded_lhs, ast.rhs(), ast.scope().?);
    } else {
        std.debug.panic("compiler error: fell through {}", .{ast});
    }
}

fn resolve_access_symbol(self: Self, lhs: *Symbol, rhs: *ast_.AST, scope: *Scope) walk_.Error!*Symbol {
    var access_result: ?*ast_.AST = null;
    switch (lhs.kind) {
        else => std.debug.panic("unsupported: {}\n", .{lhs.kind}),

        .module => {
            const module_lookup_res = lhs.init.?.scope().?.lookup(
                rhs.token().data,
                .{},
            );
            access_result = switch (module_lookup_res) {
                .found => module_lookup_res.found.decl,
                else => {
                    self.compiler.errors.add_error(errs_.Error{
                        .member_not_in = .{
                            .span = rhs.token().span,
                            .identifier = rhs.token().data,
                            .name = "module",
                            .group = lhs.init.?,
                        },
                    });
                    return error.CompileError;
                },
            };
        },

        .import => {
            const res = lhs.scope.parent.?.lookup(lhs.kind.import.real_name, .{ .allow_modules = true });
            switch (res) {
                // Found the symbol, decorate the identifier AST with it
                .found => return try self.resolve_access_symbol(res.found, rhs, scope),

                // Couldn't find the symbol
                .not_found => {
                    self.errors.add_error(errs_.Error{ .undeclared_identifier = .{ .identifier = rhs.token(), .expected = null } });
                    return error.CompileError;
                },

                // Found the symbol, but must cross a comptime-boundary to access it, and it is not const
                .found_but_rt => {
                    self.errors.add_error(errs_.Error{ .comptime_access_runtime = .{ .identifier = rhs.token() } });
                    return error.CompileError;
                },

                // Found the symbol, but must cross an inner-function boundary to access it, and it is not const
                .found_but_fn => {
                    self.errors.add_error(errs_.Error{ .inner_fn_access_runtime = .{ .identifier = rhs.token() } });
                    return error.CompileError;
                },
            }
        },

        .import_inner => {
            return try self.resolve_access_symbol(try self.resolve_qualified_name(lhs.init.?), rhs, scope);
        },

        .@"const" => {
            access_result = scope.lookup_impl_member(lhs.init.?, rhs.token().data);
            if (access_result == null) {
                self.compiler.errors.add_error(errs_.Error{
                    .type_not_impl_method = .{
                        .span = rhs.token().span,
                        .method_name = rhs.token().data,
                        ._type = lhs.init.?,
                    },
                });
                return error.CompileError;
            }
        },
    }

    if (access_result.?.* == .decl) {
        std.debug.assert(access_result.?.decl.symbols.items.len > 0);
        return access_result.?.decl.symbols.items[0];
    } else if (access_result.?.* == .method_decl or access_result.?.* == .fn_decl) {
        return access_result.?.symbol().?;
    } else {
        std.debug.panic("compiler error: type access isn't decl or method_decl, it's {s}", .{@tagName(access_result.?.*)});
    }
}
