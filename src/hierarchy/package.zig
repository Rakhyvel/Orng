const std = @import("std");
const module_ = @import("../hierarchy/module.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");

const Package = @This();

name: []const u8,
absolute_path: []const u8,
output_absolute_path: []const u8,
root: *Symbol,
local_modules: std.ArrayList(*module_.Module),
/// Maps the names of required packages, relative to this package, to the symbol of their root module
requirements: std.StringArrayHashMap(*Symbol),
include_directories: std.StringArrayHashMap(void),
library_directories: std.StringArrayHashMap(void),
libraries: std.StringArrayHashMap(void),
is_static_lib: bool,
visited: bool,

pub fn new(allocator: std.mem.Allocator, package_absolute_path: []const u8, is_static_lib: bool) *Package {
    const package = allocator.create(Package) catch unreachable;
    package.root = undefined; // filled in later
    package.output_absolute_path = undefined; // filled in when the output binary is created
    package.requirements = std.StringArrayHashMap(*Symbol).init(allocator);
    package.include_directories = std.StringArrayHashMap(void).init(allocator);
    package.library_directories = std.StringArrayHashMap(void).init(allocator);
    package.libraries = std.StringArrayHashMap(void).init(allocator);
    package.local_modules = std.ArrayList(*module_.Module).init(allocator);
    package.visited = false;
    package.name = std.fs.path.basename(package_absolute_path);
    package.absolute_path = package_absolute_path;
    package.is_static_lib = is_static_lib;
    return package;
}

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

    if (self.is_static_lib) {
        try self.ar(obj_files, allocator);
    } else {
        try self.executable(obj_files, packages, allocator);
    }
}

fn compile_obj_files(self: *Package, packages: std.StringArrayHashMap(*Package), extra_flags: bool, allocator: std.mem.Allocator) !std.ArrayList([]const u8) {
    var obj_files = std.ArrayList([]const u8).init(allocator);
    for (self.local_modules.items) |local_module| {
        var c_file = String.init(allocator);
        c_file.writer().print("{s}{c}build{c}{s}-{s}.c", .{
            self.absolute_path,
            std.fs.path.sep,
            std.fs.path.sep,
            self.name,
            local_module.name(),
        }) catch unreachable;

        var o_file = String.init(allocator);
        o_file.writer().print("{s}.o", .{local_module.name()}) catch unreachable;
        obj_files.append(o_file.str()) catch unreachable;

        try self.cc(c_file.str(), o_file.str(), packages, extra_flags, allocator);
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

    // print_cmd(&cc_cmd);
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
    var lib_name = String.init(allocator);
    lib_name.writer().print("lib{s}.a", .{self.name}) catch unreachable;
    cmd.append(lib_name.str()) catch unreachable;

    // Add all the object files
    cmd.appendSlice(obj_files.items) catch unreachable;

    // print_cmd(&cmd);

    // Set cwd
    var cwd_string = String.init(allocator);
    cwd_string.writer().print("{s}{c}build", .{ self.absolute_path, std.fs.path.sep }) catch unreachable;

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

/// Runs the command to link the object files of a package into an executable
fn executable(self: *Package, obj_files: std.ArrayList([]const u8), packages: std.StringArrayHashMap(*Package), allocator: std.mem.Allocator) !void {
    const cmd = try self.construct_exe_cc_cmd(obj_files, packages, allocator);
    var output_absolute_path = String.init(allocator);
    output_absolute_path.writer().print("{s}{c}build{c}{s}", .{
        self.absolute_path,
        std.fs.path.sep,
        std.fs.path.sep,
        self.name,
    }) catch unreachable;
    self.output_absolute_path = output_absolute_path.str();

    // print_cmd(&cmd);

    // Set cwd
    var cwd_string = String.init(allocator);
    cwd_string.writer().print("{s}{c}build", .{ self.absolute_path, std.fs.path.sep }) catch unreachable;

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
    var output_name = String.init(allocator);
    output_name.writer().print("{s}", .{self.name}) catch unreachable;
    cmd.append("-o") catch unreachable;
    cmd.append(output_name.str()) catch unreachable;

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

fn print_cmd(cmd: *const std.ArrayList([]const u8)) void {
    for (cmd.items) |item| {
        std.debug.print("{s} ", .{item});
    }
    std.debug.print("\n", .{});
}
