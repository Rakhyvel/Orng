const std = @import("std");
const CFG = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");
const module_ = @import("../hierarchy/module.zig");
const Package = @import("../hierarchy/package.zig");
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
module_interned_strings: std.StringArrayHashMap(*Interned_String_Set),

// Maps package names to their root module
packages: std.StringArrayHashMap(*Package),

/// Throws an error if the prelude could not be compiled
pub fn init(alloc: std.mem.Allocator) Error!*Self {
    var retval: *Self = alloc.create(Self) catch unreachable;
    retval.arena = std.heap.ArenaAllocator.init(alloc);

    poison_.init_structures(retval.allocator());
    retval.errors = errs_.Errors.init(retval.allocator());
    retval.module_interned_strings = std.StringArrayHashMap(*Interned_String_Set).init(retval.allocator());
    retval.prelude = primitives_.get_scope(retval) catch {
        // Prelude compilation can sometimes fail :(
        retval.errors.print_errors();
        return error.CompileError;
    };
    retval.modules = std.StringArrayHashMap(*Symbol).init(retval.allocator());
    retval.packages = std.StringArrayHashMap(*Package).init(retval.allocator());

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

    std.debug.print("  compiling {s}/{s}...\n", .{ std.fs.path.basename(std.fs.path.dirname(absolute_path).?), std.fs.path.basename(absolute_path) });
    const module = module_.Module.compile(absolute_path, entry_name, fuzz_tokens, self) catch |err| {
        switch (err) {
            // Always print these errors for fuzz testing
            error.LexerError,
            error.ParseError,
            error.FileNotFound,
            => {
                self.errors.print_errors();
                return err;
            },

            // Only print these errors if NOT fuzz testing
            error.CompileError,
            => if (!fuzz_tokens) {
                self.errors.print_errors();
                return err;
            } else {
                return err;
            },
        }
    };
    self.modules.put(absolute_path, module.symbol) catch unreachable;

    return module.symbol;
}

pub fn lookup_module(self: *Self, absolute_path: []const u8) ?*Symbol {
    return self.modules.get(absolute_path);
}

pub fn register_interned_string_set(self: *Self, module_uid: u32, absolute_path: []const u8) void {
    const interned_strings = self.allocator().create(Interned_String_Set) catch unreachable;
    interned_strings.* = Interned_String_Set.init(module_uid, self.allocator());
    self.module_interned_strings.put(absolute_path, interned_strings) catch unreachable;
}

pub fn lookup_interned_string_set(self: *Self, absolute_path: []const u8) ?*Interned_String_Set {
    return self.module_interned_strings.get(absolute_path);
}

pub fn lookup_package(self: *Self, package_name: []const u8) ?*Package {
    return self.packages.get(package_name);
}

pub fn lookup_package_root_module(self: *Self, package_name: []const u8, requirement_name: []const u8) ?*Symbol {
    return self.lookup_package(package_name).?.requirements.get(requirement_name);
}

pub fn register_package(self: *Self, package_name: []const u8, package_absolute_path: []const u8, is_static_lib: bool) void {
    if (self.lookup_package(package_name) == null) {
        const package = Package.new(self.allocator(), package_absolute_path, is_static_lib);
        self.packages.put(package_name, package) catch unreachable;
    }
}

pub fn make_package_requirement_link(self: *Self, package_name: []const u8, requirement_name: []const u8) void {
    const package = self.lookup_package(package_name).?;
    const requirement = self.lookup_package(requirement_name).?;
    package.requirements.put(requirement_name, requirement.root) catch unreachable;
}

pub fn set_package_root(self: *Self, package_name: []const u8, root: *Symbol) void {
    const package = self.lookup_package(package_name).?;
    package.root = root;
}

pub fn propagate_include_directories(self: *Self, root_package_name: []const u8) void {
    const package = self.lookup_package(root_package_name).?;
    package.append_include_dir(self.packages, &package.include_directories);
}

pub fn compile_c(self: *Self, root_package_name: []const u8, extra_flags: bool) !void {
    try self.lookup_package(root_package_name).?.compile_c(self.packages, extra_flags, self.allocator());
}
