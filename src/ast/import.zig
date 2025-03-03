//! This file represents a struct for an AST walk, and expands complex import pattern ASTs into simpler forms which
//! are easier to work with.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const compiler_ = @import("../compilation/compiler.zig");
const module_ = @import("../hierarchy/module.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const String = @import("../zig-string/zig-string.zig").String;
const symbol_ = @import("../symbol/symbol.zig");
const token_ = @import("../lexer/token.zig");
const walker_ = @import("../ast/walker.zig");

module: *module_.Module,
compiler: *compiler_.Context,

const Self = @This();

pub fn new(compiler: *compiler_.Context, module: *module_.Module) Self {
    return Self{ .compiler = compiler, .module = module };
}

var num_anons: usize = 0;
fn next_anon_name(class: []const u8, allocator: std.mem.Allocator) []const u8 {
    defer num_anons += 1;
    var out = String.init(allocator);
    defer out.deinit();
    const writer = out.writer();
    writer.print("${s}{}", .{ class, num_anons }) catch unreachable;
    return (out.toOwned() catch unreachable).?;
}

pub fn flat(self: Self, ast: *ast_.AST, asts: *std.ArrayList(*ast_.AST), idx: usize) walker_.Error!usize {
    if (ast.* == .import) {
        // If the import is complex, split it up into a root import, and const decl's off of it
        //   Remember: modules are _just_ named unit types!
        //   So something like:
        //     import a::b::c
        //   would become:
        //     import a as $anon_module_0
        //     const $anon_module_1 = $anon_module_0::b
        //     const c = $anon_module_1::c
        if (ast.import.pattern.* == .pattern_symbol and ast.import.pattern.pattern_symbol.kind == .import) {
            // Re-arrange to be a decl for the import
            const common = ast_.AST_Common{ ._token = ast.token(), ._type = null };
            ast.* = ast_.AST{ .decl = .{
                .common = common,
                .symbols = std.ArrayList(*symbol_.Symbol).init(self.compiler.allocator()),
                .pattern = ast.import.pattern,
                .type = primitives_.type_type,
                .init = primitives_.unit_type,
                ._top_level = true,
                .is_alias = false,
                .prohibit_defaults = false,
            } };
            _ = try self.resolve_import(ast.decl.pattern);
            return 0;
        } else if (ast.import.pattern.* == .access) {
            // given lhms::a0::a1::rmhs
            // ((lmhs::a0)::a1)::rmhs
            // The lmhs should be turned into an anon import decl
            // an.. are consts that are accesses of the previous, with anon names
            // rmhs is a const access with the real name
            var curr = ast.import.pattern;
            var terms = std.ArrayList(*ast_.AST).init(self.compiler.allocator());
            defer terms.deinit();

            while (curr.* == .access) : (curr = curr.lhs()) {
                terms.append(curr.rhs()) catch unreachable;
            }
            terms.append(curr) catch unreachable;

            var anon_names = std.ArrayList([]const u8).init(self.compiler.allocator());
            defer anon_names.deinit();

            for (0.., terms.items) |i, term| {
                anon_names.append(
                    if (i == 0) term.token().data else next_anon_name("anon", self.compiler.allocator()),
                ) catch unreachable;
            }

            for (0.., terms.items) |i, term| {
                if (i < terms.items.len - 1) {
                    // Insert `const rhs = lhs::rhs`
                    const init = ast_.AST.create_access(
                        ast.token(),
                        ast_.AST.create_identifier(token_.Token.init_simple(anon_names.items[i + 1]), self.compiler.allocator()),
                        terms.items[i],
                        self.compiler.allocator(),
                    );
                    const const_decl = ast_.AST.create_decl(
                        ast.import.pattern.token(),
                        ast_.AST.create_pattern_symbol(
                            ast.token(),
                            .import_inner,
                            anon_names.items[i],
                            self.compiler.allocator(),
                        ),
                        ast_.AST.create_type_of(ast.token(), init, self.compiler.allocator()),
                        init,
                        false,
                        self.compiler.allocator(),
                    );
                    asts.insert(idx, const_decl) catch unreachable;
                } else {
                    const common = ast_.AST_Common{ ._token = ast.token(), ._type = null };
                    ast.* = ast_.AST{ .decl = .{
                        .common = common,
                        .symbols = std.ArrayList(*symbol_.Symbol).init(self.compiler.allocator()),
                        .pattern = ast_.AST.create_pattern_symbol(
                            ast.token(),
                            .{ .import = .{ .real_name = term.token().data } },
                            anon_names.items[i],
                            self.compiler.allocator(),
                        ),
                        .type = primitives_.type_type,
                        .init = primitives_.unit_type,
                        ._top_level = true,
                        .is_alias = false,
                        .prohibit_defaults = false,
                    } };
                    _ = try self.resolve_import(ast.decl.pattern);
                }
            }

            return terms.items.len - 1;
        }
    }

    return 0;
}

/// Given an import pattern symbol `ast`, resolve the module symbol that it refers to, potentially compiling it if necessary
fn resolve_import(self: Self, ast: *ast_.AST) walker_.Error!*symbol_.Symbol {
    std.debug.assert(ast.* == .pattern_symbol and ast.pattern_symbol.kind == .import);
    const package_path = std.fs.path.dirname(self.module.absolute_path).?;
    const package_name = self.module.package_name;
    var import_filename = String.init(self.compiler.allocator());
    defer import_filename.deinit();
    const import_name = ast.pattern_symbol.kind.import.real_name;
    import_filename.writer().print("{s}.orng", .{import_name}) catch unreachable;
    const import_file_paths = [_][]const u8{ package_path, import_filename.str() };
    const import_file_path = std.fs.path.join(self.compiler.allocator(), &import_file_paths) catch unreachable;

    var import_symbol: *symbol_.Symbol = undefined;
    if (self.compiler.packages.get(package_name) != null and self.compiler.packages.get(package_name).?.requirements.get(import_name) != null) {
        // Foreign import of a package
        import_symbol = self.compiler.packages.get(package_name).?.requirements.get(import_name).?;
    } else {
        // Local import of a module
        import_symbol = self.compiler.compile_module(import_file_path, null, false) catch |err| switch (err) {
            error.FileNotFound => {
                self.compiler.errors.add_error(.{ .import_file_not_found = .{
                    .filename = import_name,
                    .span = ast.token().span,
                } });
                return error.CompileError;
            },
            else => std.debug.panic("compiler error: this shouldn't be reachable\n", .{}),
        };
    }
    self.module.local_imported_modules.put(import_symbol.init.?.module.module, void{}) catch unreachable;
    return import_symbol;
}
