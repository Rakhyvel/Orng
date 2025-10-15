//! This file represents a struct for an AST walk, and expands complex import pattern ASTs into simpler forms which
//! are easier to work with.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Ast_Id = @import("ast_store.zig").Ast_Id;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Module = @import("../hierarchy/module.zig").Module;
const prelude_ = @import("../hierarchy/prelude.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const walker_ = @import("../ast/walker.zig");

package_absolute_path: []const u8,
local_imported_modules: *std.AutoArrayHashMap(*Module, void),
ctx: *Compiler_Context,

const Self = @This();

pub fn new(
    ctx: *Compiler_Context,
    package_absolute_path: []const u8,
    local_imported_modules: *std.AutoArrayHashMap(*Module, void),
) Self {
    return Self{
        .ctx = ctx,
        .package_absolute_path = package_absolute_path,
        .local_imported_modules = local_imported_modules,
    };
}

var num_anons: usize = 0;
fn next_anon_name(class: []const u8, allocator: std.mem.Allocator) []const u8 {
    defer num_anons += 1;
    var out = std.array_list.Managed(u8).init(allocator);
    defer out.deinit();
    out.print("{s}__{}", .{ class, num_anons }) catch unreachable;
    return out.toOwnedSlice() catch unreachable;
}

/// Converts imports to constant declarations
pub fn flat(self: Self, ast_id: Ast_Id, asts: *std.array_list.Managed(Ast_Id), idx: usize) walker_.Error!usize {
    const ast = self.ctx.ast_store.get(ast_id);
    if (ast.* != .import) {
        return 0;
    }

    if (ast.import.pattern.* == .pattern_symbol and ast.import.pattern.pattern_symbol.kind == .import) {
        // Re-arrange to be a decl for the import
        const common = ast_.AST_Common{ ._token = ast.token() };
        ast.* = ast_.AST{ .binding = .{
            .common = common,
            .pattern = ast.import.pattern,
            .type = prelude_.unit_type,
            .init = null,
            .decls = std.array_list.Managed(Ast_Id).init(self.ctx.allocator()),
        } };
        _ = try self.resolve_import(ast.binding.pattern);
        return 0;
    } else if (ast.import.pattern.* == .access) {
        return self.unwrap_access_imports(ast, asts, idx);
    }

    return 0;
}

/// Rewrites import access-sequences of the form:
///   import aaa::bbb::ccc
/// to:
///   import aaa as anon0
///   const anon1 = aaa::bbb
///   const ccc = anon1::ccc
fn unwrap_access_imports(self: Self, ast_id: Ast_Id, asts: *std.array_list.Managed(Ast_Id), idx: usize) !usize {
    const ast = self.ctx.ast_store.get(ast_id);
    var terms = self.create_terms(ast);
    defer terms.deinit();

    var anon_names = self.create_anon_names(&terms);
    defer anon_names.deinit();

    for (0.., terms.items) |i, term| {
        if (i < terms.items.len - 1) {
            // Not the last term, these are just accesses on the i+1th term
            // Insert `const rhs = lhs::rhs`
            const init = try self.ctx.ast_store.add(.{ .access = .{
                ._token = ast.token(),
                ._lhs = try self.ctx.ast_store.add(.{ .identifier = .{ ._token = Token.init_simple(anon_names.items[i + 1]) } }),
                ._rhs = terms.items[i],
            } });
            const const_decl = try self.ctx.ast_store.add(.{ .decl = .{
                ._token = ast.import.pattern.token(),
                .name = try self.ctx.ast_store.add(.{ .pattern_symbol = .{
                    ._token = ast.token(),
                    .kind = .import_inner,
                    .storage = .local,
                    .name = anon_names.items[i],
                } }),
                .init = init,
                .type = Type_AST.create_type_of(ast.token(), init, self.ctx.allocator()),
            } });
            asts.insert(idx, const_decl) catch unreachable;
        } else {
            // The last term, this is the actual root module/package
            const common = ast_.AST_Common{ ._token = ast.token() };
            self.ctx.ast_store.replace(ast_id, .{ .binding = .{
                .common = common,
                .pattern = try self.ctx.ast_store.add(.{ .pattern_symbol = .{
                    ._token = ast.token(),
                    .kind = .{ .import = .{ .real_name = term.token().data } },
                    .storage = .local,
                    .name = anon_names.items[i],
                } }),
                .type = prelude_.unit_type,
                .init = null,
                .decls = std.array_list.Managed(Ast_Id).init(self.ctx.allocator()),
            } });
            const symb = try self.resolve_import(ast.binding.pattern);
            symb.defined = true;
            ast.binding.pattern.pattern_symbol.kind.import.real_symbol = symb;
        }
    }

    return terms.items.len - 1;
}

/// Creates a list of terms from an access-sequence in reverse order.
///
/// Turns:
/// ```
///   aaa::bbb::ccc
/// ```
/// into:
/// ```
///   [ccc, bbb, aaa]
/// ```
fn create_terms(self: Self, ast_id: Ast_Id) std.array_list.Managed(Ast_Id) {
    const ast = self.ctx.ast_store.get(ast_id);
    var curr = ast.import.pattern;
    var terms = std.array_list.Managed(Ast_Id).init(self.ctx.allocator());

    while (curr.* == .access) : (curr = curr.lhs()) {
        terms.append(curr.rhs()) catch unreachable;
    }
    terms.append(curr) catch unreachable;
    return terms;
}

/// Creates a list of anonymous names to use when unwrapping an access-sequence import, where the first is the actual
/// name, and every other is an anonymous name.
///
/// Turns:
/// ```
///    [ccc, bbb, aaa]
/// ```
/// into:
/// ```
///    [ccc, anon0, anon1]
/// ```
fn create_anon_names(self: Self, terms: *std.array_list.Managed(Ast_Id)) std.array_list.Managed([]const u8) {
    var anon_names = std.array_list.Managed([]const u8).init(self.ctx.allocator());
    for (0.., terms.items) |i, term| {
        anon_names.append(
            if (i == 0) term.token().data else next_anon_name("anon_import", self.ctx.allocator()),
        ) catch unreachable;
    }
    return anon_names;
}

/// Given an import pattern symbol `ast`, resolve the module symbol that it refers to, potentially compiling it if
/// necessary.
fn resolve_import(self: Self, pattern_ast_id: Ast_Id) walker_.Error!*Symbol {
    const pattern_ast = self.ctx.ast_store.get(pattern_ast_id);
    std.debug.assert(pattern_ast.* == .pattern_symbol and pattern_ast.pattern_symbol.kind == .import);
    const import_name = pattern_ast.pattern_symbol.kind.import.real_name;
    const import_file_path = self.build_import_path(import_name);

    const import_symbol: *Symbol = try self.lookup_import_module(pattern_ast, import_name, import_file_path);

    const module = self.ctx.ast_store.get(import_symbol.init_value().?).module.module;

    self.local_imported_modules.put(module, void{}) catch unreachable;
    return import_symbol;
}

/// Constructs the absolute path of a hypothetical imported local module from the absolute path of this package and the import name
fn build_import_path(self: Self, import_name: []const u8) []const u8 {
    var import_filename = std.array_list.Managed(u8).init(self.ctx.allocator());
    defer import_filename.deinit();
    import_filename.print("{s}.orng", .{import_name}) catch unreachable;
    const import_file_paths = [_][]const u8{ self.package_absolute_path, import_filename.items };
    return std.fs.path.join(self.ctx.allocator(), &import_file_paths) catch unreachable;
}

/// Looks up an import by name, returning the module symbol for either a foreign package or local module
fn lookup_import_module(self: Self, pattern_ast_id: Ast_Id, import_name: []const u8, import_file_path: []const u8) walker_.Error!*Symbol {
    const pattern_ast = self.ctx.ast_store.get(pattern_ast_id);
    if (self.ctx.lookup_package(self.package_absolute_path) != null and self.ctx.lookup_package_root_module(self.package_absolute_path, import_name) != null) {
        // Foreign import of a package
        return self.ctx.lookup_package_root_module(self.package_absolute_path, import_name).?;
    } else {
        // Local import of a module
        return self.ctx.compile_module(import_file_path, null, false) catch |err| switch (err) {
            error.FileNotFound => {
                self.ctx.errors.add_error(.{ .import_file_not_found = .{
                    .filename = import_name,
                    .span = pattern_ast.span(),
                } });
                return error.CompileError;
            },
            error.CompileError, error.ParseError => {
                // This is possible if the user does `import Int` or something
                return error.CompileError;
            },
            else => std.debug.panic("compiler error: this shouldn't be reachable\n", .{}),
        };
    }
}
