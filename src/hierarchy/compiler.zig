const std = @import("std");
const AST = @import("../ast/ast.zig").AST;
const CFG = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");
const Module = @import("../hierarchy/module.zig").Module;
const Module_Iterator = @import("../util/dfs.zig").Dfs_Iterator(*Module);
const Package = @import("../hierarchy/package.zig");
const Package_Iterator = @import("../util/dfs.zig").Dfs_Iterator(Package_Iterator_Node);
const Package_Iterator_Node = @import("../hierarchy/package.zig").Package_Iterator_Node;
const poison_ = @import("../ast/poison.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");
const Scope = @import("../symbol/scope.zig");

const Self = @This();

const Error: type = error{
    LexerError,
    ParseError,
    CompileError,
    FileNotFound,
};

arena: std.heap.ArenaAllocator,

/// List of errors found during compilation
errors: errs_.Errors,

prelude: *Scope,

/// Maps module absolute paths to their symbol
modules: std.StringArrayHashMap(*Symbol),

/// Maps module absolute paths to the interned string set for that module
module_interned_strings: std.AutoArrayHashMap(u32, *Interned_String_Set),

// Maps package names to their root module
packages: std.StringArrayHashMap(*Package),

/// Throws an error if the prelude could not be compiled
pub fn init(alloc: std.mem.Allocator) Error!*Self {
    var retval: *Self = alloc.create(Self) catch unreachable;
    retval.arena = std.heap.ArenaAllocator.init(alloc);

    poison_.init_structures(retval.allocator());
    retval.errors = errs_.Errors.init(retval.allocator());
    retval.module_interned_strings = std.AutoArrayHashMap(u32, *Interned_String_Set).init(retval.allocator());
    retval.modules = std.StringArrayHashMap(*Symbol).init(retval.allocator());
    retval.packages = std.StringArrayHashMap(*Package).init(retval.allocator());
    retval.prelude = primitives_.get_scope(retval) catch {
        // Prelude compilation can sometimes fail :(
        retval.errors.print_errors(errs_.get_std_err(), .{});
        return error.CompileError;
    };

    return retval;
}

pub fn deinit(self: *Self) void {
    self.arena.deinit();
    self.arena.child_allocator.destroy(self);
}

pub fn allocator(self: *Self) std.mem.Allocator {
    return self.arena.allocator();
}

pub fn compile_build_file(self: *Self, absolute_path: []const u8) Error!*CFG {
    const build_module = try self.compile_module(absolute_path, "build", false);
    return build_module.init_value.?.scope().?.lookup("build", .{}).found.cfg.?;
}

/// Compiles a module from a file
pub fn compile_module(
    self: *Self,
    absolute_path: []const u8,
    entry_name: ?[]const u8,
    fuzz_tokens: bool,
) Error!*Symbol {
    if (self.modules.get(absolute_path)) |module| {
        return module;
    }

    const module = Module.compile(absolute_path, entry_name, fuzz_tokens, self) catch |err| {
        switch (err) {
            // Always print these errors for fuzz testing
            error.LexerError,
            error.ParseError,
            error.FileNotFound,
            => {
                self.errors.print_errors(errs_.get_std_err(), .{});
                return err;
            },

            // Only print these errors if NOT fuzz testing
            error.CompileError,
            => if (!fuzz_tokens) {
                self.errors.print_errors(errs_.get_std_err(), .{});
                return err;
            } else {
                return err;
            },
        }
    };

    return self.lookup_module(module.absolute_path).?;
}

pub fn lookup_module(self: *Self, absolute_path: []const u8) ?*Symbol {
    return self.modules.get(absolute_path);
}

pub fn register_module(self: *Self, absolute_path: []const u8, module: *Symbol) void {
    self.modules.put(absolute_path, module) catch unreachable;
}

pub fn module_scope(self: *Self, absolute_path: []const u8) ?*Scope {
    const module_symbol = self.lookup_module(absolute_path) orelse return null;
    return module_symbol.init_value.?.scope();
}

pub fn register_interned_string_set(self: *Self, module_uid: u32) void {
    const interned_strings = self.allocator().create(Interned_String_Set) catch unreachable;
    interned_strings.* = Interned_String_Set.init(module_uid, self.allocator());
    self.module_interned_strings.put(module_uid, interned_strings) catch unreachable;
}

pub fn get_builtin_type(self: *Self, name: []const u8) *AST {
    const prelude_abs_path = self.prelude.module.?.absolute_path;
    return self.module_scope(prelude_abs_path).?.lookup(name, .{}).found.init_value.?;
}

pub fn lookup_interned_string_set(self: *Self, module_uid: u32) ?*Interned_String_Set {
    return self.module_interned_strings.get(module_uid);
}

pub fn lookup_package(self: *Self, package_absolute_path: []const u8) ?*Package {
    std.debug.assert(std.fs.path.isAbsolute(package_absolute_path));
    return self.packages.get(package_absolute_path);
}

pub fn lookup_package_root_module(self: *Self, package_absolute_path: []const u8, requirement_name: []const u8) ?*Symbol {
    std.debug.assert(std.fs.path.isAbsolute(package_absolute_path));
    const package = self.lookup_package(package_absolute_path);
    if (package == null) {
        return null;
    }
    return package.?.requirements.get(requirement_name);
}

pub fn register_package(self: *Self, package_absolute_path: []const u8, kind: Package.Package_Kind) void {
    std.debug.assert(std.fs.path.isAbsolute(package_absolute_path));
    if (self.lookup_package(package_absolute_path) == null) {
        const package = Package.new(self.allocator(), package_absolute_path, kind);
        self.packages.put(package_absolute_path, package) catch unreachable;
    }
}

pub fn make_package_requirement_link(self: *Self, package_absolute_path: []const u8, requirement_name: []const u8, requirement_absolute_path: []const u8) void {
    std.debug.assert(std.fs.path.isAbsolute(package_absolute_path));
    std.debug.assert(std.fs.path.isAbsolute(requirement_absolute_path));
    const package = self.lookup_package(package_absolute_path).?;
    const requirement = self.lookup_package(requirement_absolute_path).?;
    package.requirements.put(requirement_name, requirement.root) catch unreachable;
}

pub fn set_package_root(self: *Self, package_absolute_path: []const u8, root: *Symbol) void {
    std.debug.assert(std.fs.path.isAbsolute(package_absolute_path));
    const package = self.lookup_package(package_absolute_path).?;
    package.root = root;
}

pub fn propagate_include_directories(self: *Self, root_package_absolute_path: []const u8) void {
    std.debug.assert(std.fs.path.isAbsolute(root_package_absolute_path));
    const package = self.lookup_package(root_package_absolute_path).?;
    package.append_include_dir(self.packages, &package.include_directories);
}

pub fn set_package_kind(self: *Self, package_absolute_path: []const u8, kind: Package.Package_Kind) void {
    std.debug.assert(std.fs.path.isAbsolute(package_absolute_path));
    const package = self.lookup_package(package_absolute_path).?;
    package.kind = kind;
    package.set_executable_name(self.allocator()) catch unreachable;
}

pub fn clean_package(self: *Self, package_absolute_path: []const u8) void {
    var dfs_iter: Package_Iterator = Package_Iterator.init(Package_Iterator_Node.init(self, package_absolute_path), self.allocator());
    defer dfs_iter.deinit();
    while (dfs_iter.next()) |package_node| {
        const build_path = package_node.package.get_build_path(self.allocator());
        std.fs.deleteTreeAbsolute(build_path) catch |err| switch (err) {
            error.FileNotFound => {}, // This is ok!
            else => std.debug.panic("{}\n", .{err}),
        };
    }
}

pub fn collect_package_local_modules(self: *Self) void {
    for (self.packages.keys()) |package_name| {
        const package = self.lookup_package(package_name).?;
        const module = package.root.init_value.?.module.module;

        const package_path = module.get_package_abs_path();
        const build_paths = [_][]const u8{ package_path, "build" };
        const build_path = std.fs.path.join(self.allocator(), &build_paths) catch unreachable;
        _ = std.fs.openDirAbsolute(build_path, .{}) catch {
            std.fs.makeDirAbsolute(build_path) catch unreachable;
        };

        var dfs_iter: Module_Iterator = Module_Iterator.init(module, self.allocator());
        defer dfs_iter.deinit();
        while (dfs_iter.next()) |next_module| {
            package.local_modules.append(next_module) catch unreachable;
        }
    }
}

pub fn determine_if_modified(self: *Self, root_package_absolute_path: []const u8) void {
    const package = self.lookup_package(root_package_absolute_path).?;
    package.determine_if_modified(self.packages, self);
}

pub fn compile(self: *Self, root_package_absolute_path: []const u8, extra_flags: bool) !void {
    std.debug.assert(std.fs.path.isAbsolute(root_package_absolute_path));
    try self.lookup_package(root_package_absolute_path).?.compile(self.packages, extra_flags, self.allocator());
}
