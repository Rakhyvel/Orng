const std = @import("std");
const Module = @import("../hierarchy/module.zig").Module;
const CFG = @import("../ir/cfg.zig");
const Compiler_Context = @import("compiler.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");
const Module_Hash = @import("module_hash.zig");

const Package = @This();

name: []const u8,
absolute_path: []const u8,
output_absolute_path: []const u8,
root: *Symbol,
local_modules: std.ArrayList(*Module),
/// Maps the names of required packages, relative to this package, to the symbol of their root module
requirements: std.StringArrayHashMap(*Symbol),
include_directories: std.StringArrayHashMap(void),
library_directories: std.StringArrayHashMap(void),
libraries: std.StringArrayHashMap(void),
kind: Package_Kind,
visited: bool,
module_hash: Module_Hash,
modified: ?bool,

pub const Package_Kind = enum {
    executable,
    static_library,
    shared_library,
    test_executable,
};

pub const Package_Iterator_Node = struct {
    compiler: *Compiler_Context,
    package: *Package,

    pub fn init(compiler: *Compiler_Context, package_abs_path: []const u8) Package_Iterator_Node {
        const package = compiler.lookup_package(package_abs_path).?;
        return Package_Iterator_Node{ .compiler = compiler, .package = package };
    }

    pub fn get_adjacent(self: *Package_Iterator_Node) []Package_Iterator_Node {
        var list = std.ArrayList(Package_Iterator_Node).init(self.compiler.allocator());

        for (self.package.requirements.keys()) |requirement_name| {
            const requirement_root_module_symbol = self.package.requirements.get(requirement_name);
            const requirement_root_module = requirement_root_module_symbol.?.init_value.?.module.module;
            const requirement_root_abs_path = requirement_root_module.get_package_abs_path();
            list.append(Package_Iterator_Node.init(self.compiler, requirement_root_abs_path)) catch unreachable;
        }

        return list.toOwnedSlice() catch unreachable;
    }

    pub fn free_adjacent(self: *Package_Iterator_Node, adj: []Package_Iterator_Node) void {
        self.compiler.allocator().free(adj);
    }
};

pub fn new(allocator: std.mem.Allocator, package_absolute_path: []const u8, kind: Package_Kind) *Package {
    const package = allocator.create(Package) catch unreachable;
    package.root = undefined; // filled in later
    package.output_absolute_path = undefined; // filled in when the output binary is created
    package.requirements = std.StringArrayHashMap(*Symbol).init(allocator);
    package.include_directories = std.StringArrayHashMap(void).init(allocator);
    package.library_directories = std.StringArrayHashMap(void).init(allocator);
    package.libraries = std.StringArrayHashMap(void).init(allocator);
    package.local_modules = std.ArrayList(*Module).init(allocator);
    package.visited = false;
    package.name = std.fs.path.basename(package_absolute_path);
    package.absolute_path = package_absolute_path;
    package.kind = kind;
    package.module_hash = Module_Hash.init(package_absolute_path, allocator) catch unreachable;
    package.modified = null;

    package.set_executable_name(allocator) catch unreachable;

    return package;
}

pub fn get_build_path(self: *const Package, allocator: std.mem.Allocator) []const u8 {
    const package_root_module = self.root.init_value.?.module.module;
    const package_path = package_root_module.get_package_abs_path();
    const build_paths = [_][]const u8{ package_path, "build" };
    return std.fs.path.join(allocator, &build_paths) catch unreachable;
}

pub fn get_build_module_absolute_path(self: *const Package, allocator: std.mem.Allocator) []const u8 {
    const package_root_module = self.root.init_value.?.module.module;
    const package_path = package_root_module.get_package_abs_path();
    const build_paths = [_][]const u8{ package_path, "build.orng" };
    return std.fs.path.join(allocator, &build_paths) catch unreachable;
}

pub fn entry(self: *const Package) ?*CFG {
    return self.root.init_value.?.module.module.entry;
}

pub fn get_build_module(self: *const Package, compiler: *Compiler_Context) ?*Module {
    const build_module_absolute_path = self.get_build_module_absolute_path(compiler.allocator());
    const build_module_symbol = compiler.lookup_module(build_module_absolute_path) orelse return null;
    return build_module_symbol.init_value.?.module.module;
}

/// A package is modified if:
/// - Any of its modules are modified
/// - Any of its dependencies are modified
pub fn determine_if_modified(self: *Package, packages: std.StringArrayHashMap(*Package), compiler: *Compiler_Context) void {
    if (self.modified != null) {
        return;
    }
    self.modified = false;

    // Check if any packages are modified
    for (self.requirements.keys()) |requirement_name| {
        const requirement_root_module_symbol = self.requirements.get(requirement_name);
        const requirement_root_module = requirement_root_module_symbol.?.init_value.?.module.module;
        const requirement_root_abs_path = requirement_root_module.get_package_abs_path();
        const required_package: *Package = packages.get(requirement_root_abs_path).?;
        required_package.determine_if_modified(packages, compiler);
        self.modified = required_package.modified.? or self.modified.?;
    }

    // Check if the build module was modified, if it was, entire package will be rebuilt
    if (self.get_build_module(compiler)) |build_module| {
        build_module.determine_if_modified(compiler);
        build_module.update_module_hash(&self.module_hash, compiler.allocator());
        self.modified = build_module.modified.? or self.modified.?;
    }

    // Check if any modules are modified
    for (self.local_modules.items) |local_module| {
        local_module.determine_if_modified(compiler);
        self.modified = local_module.modified.? or self.modified.?;
    }

    // Check if the output exists - if it doesn't, package is modified
    self.modified = !file_exists(self.output_absolute_path) or self.modified.?;
}

fn file_exists(abs_path: []const u8) bool {
    var file = std.fs.openFileAbsolute(abs_path, .{}) catch |err| switch (err) {
        error.FileNotFound => return false,
        else => return false,
    };
    defer file.close();
    return true;
}

/// Compiles a package. Assumes C files have already been emitted.
pub fn compile(self: *Package, packages: std.StringArrayHashMap(*Package), extra_flags: bool, allocator: std.mem.Allocator) !void {
    if (self.visited) {
        return;
    }
    self.visited = true;

    for (self.requirements.keys()) |requirement_name| {
        const requirement_root_module_symbol = self.requirements.get(requirement_name);
        const requirement_root_module = requirement_root_module_symbol.?.init_value.?.module.module;
        const requirement_root_abs_path = requirement_root_module.get_package_abs_path();
        const required_package = packages.get(requirement_root_abs_path).?;
        try required_package.compile(packages, extra_flags, allocator);
    }

    const obj_files = try self.compile_obj_files(packages, extra_flags, allocator);
    self.module_hash.output_new_json(allocator);

    if (self.modified.?) {
        if (self.kind == .static_library) {
            try self.ar(obj_files, allocator);
        } else {
            try self.link_executable(obj_files, packages, allocator);
        }
    }
}

fn compile_obj_files(self: *Package, packages: std.StringArrayHashMap(*Package), extra_flags: bool, allocator: std.mem.Allocator) !std.ArrayList([]const u8) {
    var obj_files = std.ArrayList([]const u8).init(allocator);
    for (self.local_modules.items) |local_module| {
        if (!std.mem.eql(u8, local_module.get_package_abs_path(), self.absolute_path)) {
            break;
        }

        // Append the o filename to the obj files list, even if this isn't compiled!
        var o_file = String.init(allocator);
        o_file.writer().print("{s}.o", .{local_module.name()}) catch unreachable;
        obj_files.append(o_file.str()) catch unreachable;
        local_module.update_module_hash(&self.module_hash, allocator);

        if (!local_module.modified.?) {
            // No need to re-compile!
            continue;
        }

        var c_file = String.init(allocator);
        c_file.writer().print("{s}{c}build{c}{s}-{s}.c", .{
            self.absolute_path,
            std.fs.path.sep,
            std.fs.path.sep,
            self.name,
            local_module.name(),
        }) catch unreachable;

        try self.cc(c_file.str(), o_file.str(), packages, extra_flags, allocator);
    }

    // Include the entry point for executables
    if (self.modified.?) {
        switch (self.kind) {
            .test_executable => {
                const test_runner_o_file = "test-runner.o";
                obj_files.append(test_runner_o_file) catch unreachable;
                var c_file = String.init(allocator);
                c_file.writer().print("{s}{c}build{c}test-runner.c", .{
                    self.absolute_path,
                    std.fs.path.sep,
                    std.fs.path.sep,
                }) catch unreachable;

                try self.cc(c_file.str(), test_runner_o_file, packages, extra_flags, allocator);
            },
            .executable => {
                const test_runner_o_file = "start.o";
                obj_files.append(test_runner_o_file) catch unreachable;
                var c_file = String.init(allocator);
                c_file.writer().print("{s}{c}build{c}start.c", .{
                    self.absolute_path,
                    std.fs.path.sep,
                    std.fs.path.sep,
                }) catch unreachable;

                try self.cc(c_file.str(), test_runner_o_file, packages, extra_flags, allocator);
            },
            else => {},
        }
    }

    return obj_files;
}

pub fn append_include_dir(self: *Package, packages: std.StringArrayHashMap(*Package), include_dirs: *std.StringArrayHashMap(void)) void {
    for (self.requirements.keys()) |requirement_name| {
        const requirement_root_module_symbol = self.requirements.get(requirement_name);
        const requirement_root_module = requirement_root_module_symbol.?.init_value.?.module.module;
        const requirement_root_abs_path = requirement_root_module.get_package_abs_path();
        const required_package = packages.get(requirement_root_abs_path).?;
        required_package.append_include_dir(packages, &self.include_directories);
    }
    for (self.include_directories.keys()) |dir| {
        include_dirs.put(dir, void{}) catch unreachable;
    }
}

fn cc(
    self: *Package,
    c_file: []const u8,
    o_file: []const u8,
    packages: std.StringArrayHashMap(*Package),
    extra_flags: bool,
    allocator: std.mem.Allocator,
) !void {
    const cc_cmd = try self.construct_obj_cc_cmd(c_file, o_file, packages, extra_flags, allocator);
    print_cmd(&cc_cmd);

    var cwd_string = String.init(allocator);
    cwd_string.writer().print("{s}{c}build", .{ self.absolute_path, std.fs.path.sep }) catch unreachable;

    const run_res = std.process.Child.run(.{
        .allocator = allocator,
        .argv = cc_cmd.items,
        .cwd = cwd_string.str(),
    }) catch |err| switch (err) {
        else => std.debug.panic("compile error: on cc invoke: {}", .{err}),
    };

    var retcode: u8 = 0;
    switch (run_res.term) {
        .Exited => |c| {
            retcode = c;
        },
        .Signal => return error.CompileError,
        else => {
            std.debug.print("{s}\n", .{run_res.stderr});
            return error.CompileError;
        },
    }

    if (retcode != 0) {
        std.debug.print("{s}", .{run_res.stderr});
        return error.CompileError;
    }
}

/// Constructs the command to call zig cc to compile a modules .o file
fn construct_obj_cc_cmd(
    self: *Package,
    c_file: []const u8,
    o_file: []const u8,
    packages: std.StringArrayHashMap(*Package),
    extra_flags: bool,
    allocator: std.mem.Allocator,
) !std.ArrayList([]const u8) {
    var env_map = std.process.getEnvMap(allocator) catch unreachable;
    defer env_map.deinit();

    // Base cc command
    var cc_cmd = std.ArrayList([]const u8).init(allocator);
    cc_cmd.appendSlice(&[_][]const u8{ "zig", "cc" }) catch unreachable;

    // Add input/output
    cc_cmd.append("-c") catch unreachable;
    cc_cmd.append(c_file) catch unreachable;

    cc_cmd.append("-o") catch unreachable;
    cc_cmd.append(o_file) catch unreachable;

    const std_path = env_map.get("ORNG_STD_PATH").?;
    var std_include_path = String.init(allocator);
    std_include_path.writer().print("-I{s}", .{std_path}) catch unreachable;

    // Add basic flags
    cc_cmd.appendSlice(&[_][]const u8{
        "-std=c11",
        "-O3",
        "-g",
        std_include_path.str(),
    }) catch unreachable;

    if (extra_flags) {
        cc_cmd.appendSlice(&[_][]const u8{
            // "-Werror", // TODO: Requires us to know when interned strings are unused
            "-Wall",
            "-Wextra",
            "-Wpedantic",
            "-pedantic-errors",
            "-Wconversion",
            "-Wsign-conversion",
            "-Wfloat-conversion",
            "-Wcast-qual",
            "-Wlogical-op",
            "-Wshadow",
            "-Wformat=2",
            "-Wmisleading-indentation",
            "-Wstrict-prototypes",
            "-Wmissing-prototypes",
            "-Winit-self",
            "-Wjump-misses-init",
            "-Wdeclaration-after-statement",
            "-Wbad-function-cast",
            "-Wc11-c2x-compat",
            "-Wcast-align",
            // "-fsanitize=undefined,address", // TODO: Needs some kind of linking
        }) catch unreachable;
    }

    self.append_requirements_includes(&cc_cmd, packages, allocator);
    self.append_self_includes(&cc_cmd, allocator);

    return cc_cmd;
}

/// Appends the include directories of the packages that this packages requires to the cc command
fn append_requirements_includes(
    self: *Package,
    cc_cmd: *std.ArrayList([]const u8),
    packages: std.StringArrayHashMap(*Package),
    allocator: std.mem.Allocator,
) void {
    for (self.requirements.keys()) |requirement_name| {
        const requirement_root_module_symbol = self.requirements.get(requirement_name);
        const requirement_root_module = requirement_root_module_symbol.?.init_value.?.module.module;
        const requirement_root_abs_path = requirement_root_module.get_package_abs_path();
        const required_package = packages.get(requirement_root_abs_path).?;

        var requirement_include_path = String.init(allocator);
        requirement_include_path.writer().print("-I{s}{c}build", .{ required_package.root.init_value.?.module.module.get_package_abs_path(), std.fs.path.sep }) catch unreachable;
        cc_cmd.append(requirement_include_path.str()) catch unreachable;
    }
}

/// Appends the include directories that this package specified in `build.orng` to the cc command
fn append_self_includes(
    self: *Package,
    cc_cmd: *std.ArrayList([]const u8),
    allocator: std.mem.Allocator,
) void {
    for (self.include_directories.keys()) |include_dir| {
        var requirement_include_path = String.init(allocator);
        requirement_include_path.writer().print("-I{s}", .{include_dir}) catch unreachable;
        cc_cmd.append(requirement_include_path.str()) catch unreachable;
    }
}

fn ar(self: *Package, obj_files: std.ArrayList([]const u8), allocator: std.mem.Allocator) !void {
    // Base command
    var cmd = std.ArrayList([]const u8).init(allocator);
    cmd.appendSlice(&[_][]const u8{
        "zig",
        "ar",
        "rcs",
    }) catch unreachable;

    // Add the lib name
    cmd.append(self.output_absolute_path) catch unreachable;

    // Add all the object files
    cmd.appendSlice(obj_files.items) catch unreachable;

    // Set cwd
    var cwd_string = String.init(allocator);
    cwd_string.writer().print("{s}{c}build", .{ self.absolute_path, std.fs.path.sep }) catch unreachable;

    print_cmd(&cmd);
    const run_res = std.process.Child.run(.{
        .allocator = allocator,
        .argv = cmd.items,
        .cwd = cwd_string.str(),
    }) catch unreachable;

    var retcode: u8 = 0;
    switch (run_res.term) {
        .Exited => |c| {
            retcode = c;
        },
        .Signal => return error.CompileError,
        else => {
            std.debug.print("{s}\n", .{run_res.stderr});
            return error.CompileError;
        },
    }

    if (retcode != 0) {
        std.debug.print("ar error: {s}\n", .{run_res.stderr});
        return error.CompileError;
    }
}

pub fn set_executable_name(self: *Package, allocator: std.mem.Allocator) !void {
    var output_absolute_path = String.init(allocator);
    output_absolute_path.writer().print("{s}{c}build{c}", .{
        self.absolute_path,
        std.fs.path.sep,
        std.fs.path.sep,
    }) catch unreachable;
    switch (self.kind) {
        .executable => try output_absolute_path.writer().print("{s}", .{self.name}),
        .test_executable => try output_absolute_path.writer().print("{s}-test", .{self.name}),
        .static_library => try output_absolute_path.writer().print("lib{s}.a", .{self.name}),
        .shared_library => try output_absolute_path.writer().print("{s}.so", .{self.name}),
    }
    self.output_absolute_path = output_absolute_path.str();
}

/// Runs the command to link the object files of a package into an executable
fn link_executable(self: *Package, obj_files: std.ArrayList([]const u8), packages: std.StringArrayHashMap(*Package), allocator: std.mem.Allocator) !void {
    const cmd = try self.construct_exe_cc_cmd(obj_files, packages, allocator);

    // Set cwd
    var cwd_string = String.init(allocator);
    cwd_string.writer().print("{s}{c}build", .{ self.absolute_path, std.fs.path.sep }) catch unreachable;

    print_cmd(&cmd);
    const run_res = std.process.Child.run(.{
        .allocator = allocator,
        .argv = cmd.items,
        .cwd = cwd_string.str(),
    }) catch unreachable;

    var retcode: u8 = 0;
    switch (run_res.term) {
        .Exited => |c| {
            retcode = c;
        },
        .Signal => |c| switch (c) {
            11 => return error.CompileError,
            else => return error.CompileError,
        },
        else => {
            std.debug.print("{s}\n", .{run_res.stderr});
            return error.CompileError;
        },
    }

    if (retcode != 0) {
        std.debug.print("err:{s}\n", .{run_res.stderr});
        return error.CompileError;
    }
}

/// Constructs the command to call zig cc to compile an executable from a list of object files
fn construct_exe_cc_cmd(
    self: *Package,
    obj_files: std.ArrayList([]const u8),
    packages: std.StringArrayHashMap(*Package),
    allocator: std.mem.Allocator,
) !std.ArrayList([]const u8) {
    var env_map = std.process.getEnvMap(allocator) catch unreachable;
    defer env_map.deinit();

    // Base command
    var cmd = std.ArrayList([]const u8).init(allocator);
    cmd.appendSlice(&[_][]const u8{ "zig", "cc" }) catch unreachable;

    // Add all the object files
    cmd.appendSlice(obj_files.items) catch unreachable;

    for (self.requirements.keys()) |requirement_name| {
        self.append_requirement_link(&cmd, packages, requirement_name, allocator);
    }

    // Add the output name
    cmd.append("-o") catch unreachable;
    cmd.append(self.output_absolute_path) catch unreachable;

    return cmd;
}

/// Appends the flags to link against a required package
fn append_requirement_link(
    self: *Package,
    cmd: *std.ArrayList([]const u8),
    packages: std.StringArrayHashMap(*Package),
    requirement_name: []const u8,
    allocator: std.mem.Allocator,
) void {
    const requirement_root_module_symbol = self.requirements.get(requirement_name);
    const requirement_root_module = requirement_root_module_symbol.?.init_value.?.module.module;
    const requirement_root_abs_path = requirement_root_module.get_package_abs_path();
    const required_package = packages.get(requirement_root_abs_path).?;

    var requirement_library_path = String.init(allocator);
    requirement_library_path.writer().print("{s}{c}build", .{ required_package.root.init_value.?.module.module.get_package_abs_path(), std.fs.path.sep }) catch unreachable;
    cmd.append("-L") catch unreachable;
    cmd.append(requirement_library_path.str()) catch unreachable;

    for (self.library_directories.keys()) |lib_dir| {
        cmd.append("-L") catch unreachable;
        cmd.append(lib_dir) catch unreachable;
    }

    var requirement_library = String.init(allocator);
    requirement_library.writer().print("-l{s}", .{required_package.name}) catch unreachable;
    cmd.append(requirement_library.str()) catch unreachable;

    for (self.libraries.keys()) |lib| {
        cmd.append("-l") catch unreachable;
        cmd.append(lib) catch unreachable;
    }
}

const debug: bool = true;
fn print_cmd(cmd: *const std.ArrayList([]const u8)) void {
    if (debug) {
        for (cmd.items) |item| {
            std.debug.print("{s} ", .{item});
        }
        std.debug.print("\n", .{});
    }
}
