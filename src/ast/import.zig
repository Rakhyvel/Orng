//! This file represents a struct for an AST walk, and expands complex import pattern ASTs into simpler forms which
//! are easier to work with.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
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
compiler: *Compiler_Context,

const Self = @This();

pub fn new(
    compiler: *Compiler_Context,
    package_absolute_path: []const u8,
    local_imported_modules: *std.AutoArrayHashMap(*Module, void),
) Self {
    return Self{
        .compiler = compiler,
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
pub fn flat(self: Self, ast: *ast_.AST, asts: *std.array_list.Managed(*ast_.AST), idx: usize) walker_.Error!usize {
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
            .decls = std.array_list.Managed(*ast_.AST).init(self.compiler.allocator()),
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
fn unwrap_access_imports(self: Self, ast: *ast_.AST, asts: *std.array_list.Managed(*ast_.AST), idx: usize) !usize {
    var terms = self.create_terms(ast);
    defer terms.deinit();

    var anon_names = self.create_anon_names(&terms);
    defer anon_names.deinit();

    for (0.., terms.items) |i, term| {
        if (i < terms.items.len - 1) {
            // Not the last term, these are just accesses on the i+1th term
            // Insert `const rhs = lhs::rhs`
            const init = ast_.AST.create_access(
                ast.token(),
                ast_.AST.create_identifier(Token.init_simple(anon_names.items[i + 1]), self.compiler.allocator()),
                terms.items[i],
                self.compiler.allocator(),
            );
            const const_decl = ast_.AST.create_decl(
                ast.import.pattern.token(),
                ast_.AST.create_pattern_symbol(
                    ast.token(),
                    .import_inner,
                    .local,
                    anon_names.items[i],
                    self.compiler.allocator(),
                ),
                Type_AST.create_type_of(ast.token(), init, self.compiler.allocator()),
                init,
                self.compiler.allocator(),
            );
            asts.insert(idx, const_decl) catch unreachable;
        } else {
            // The last term, this is the actual root module/package
            const common = ast_.AST_Common{ ._token = ast.token() };
            ast.* = ast_.AST{ .binding = .{
                .common = common,
                .pattern = ast_.AST.create_pattern_symbol(
                    ast.token(),
                    .{ .import = .{ .real_name = term.token().data } },
                    .local,
                    anon_names.items[i],
                    self.compiler.allocator(),
                ),
                .type = prelude_.unit_type,
                .init = null,
                .decls = std.array_list.Managed(*ast_.AST).init(self.compiler.allocator()),
            } };
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
fn create_terms(self: Self, ast: *ast_.AST) std.array_list.Managed(*ast_.AST) {
    var curr = ast.import.pattern;
    var terms = std.array_list.Managed(*ast_.AST).init(self.compiler.allocator());

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
fn create_anon_names(self: Self, terms: *std.array_list.Managed(*ast_.AST)) std.array_list.Managed([]const u8) {
    var anon_names = std.array_list.Managed([]const u8).init(self.compiler.allocator());
    for (0.., terms.items) |i, term| {
        anon_names.append(
            if (i == 0) term.token().data else next_anon_name("anon_import", self.compiler.allocator()),
        ) catch unreachable;
    }
    return anon_names;
}

/// Given an import pattern symbol `ast`, resolve the module symbol that it refers to, potentially compiling it if
/// necessary.
fn resolve_import(self: Self, pattern_ast: *ast_.AST) walker_.Error!*Symbol {
    std.debug.assert(pattern_ast.* == .pattern_symbol and pattern_ast.pattern_symbol.kind == .import);
    const import_name = pattern_ast.pattern_symbol.kind.import.real_name;
    const import_file_path = self.build_import_path(import_name);

    const import_symbol: *Symbol = try self.lookup_import_module(pattern_ast, import_name, import_file_path);

    self.local_imported_modules.put(import_symbol.init_value().?.module.module, void{}) catch unreachable;
    return import_symbol;
}

/// Constructs the absolute path of a hypothetical imported local module from the absolute path of this package and the import name
fn build_import_path(self: Self, import_name: []const u8) []const u8 {
    var import_filename = std.array_list.Managed(u8).init(self.compiler.allocator());
    defer import_filename.deinit();
    import_filename.print("{s}.orng", .{import_name}) catch unreachable;
    const import_file_paths = [_][]const u8{ self.package_absolute_path, import_filename.items };
    return std.fs.path.join(self.compiler.allocator(), &import_file_paths) catch unreachable;
}

/// Looks up an import by name, returning the module symbol for either a foreign package or local module
fn lookup_import_module(self: Self, pattern_ast: *ast_.AST, import_name: []const u8, import_file_path: []const u8) walker_.Error!*Symbol {
    if (self.compiler.lookup_package(self.package_absolute_path) != null and self.compiler.lookup_package_root_module(self.package_absolute_path, import_name) != null) {
        // Foreign import of a package
        return self.compiler.lookup_package_root_module(self.package_absolute_path, import_name).?;
    } else {
        // Local import of a module
        return self.compiler.compile_module(import_file_path, null, false) catch |err| switch (err) {
            error.FileNotFound => {
                self.compiler.errors.add_error(.{ .import_file_not_found = .{
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
