const exec = @import("exec.zig").exec;
const module_ = @import("module.zig");
const std = @import("std");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");

const Package = @This();

name: []const u8,
absolute_path: []const u8,
output_absolute_path: []const u8,
root: *symbol_.Symbol,
local_modules: std.ArrayList(*module_.Module),
requirements: std.StringArrayHashMap(*symbol_.Symbol),
include_directories: std.StringArrayHashMap(void),
library_directories: std.StringArrayHashMap(void),
libraries: std.StringArrayHashMap(void),
is_static_lib: bool,
visited: bool,

pub fn new(allocator: std.mem.Allocator, package_absolute_path: []const u8, is_static_lib: bool) *Package {
    const package = allocator.create(Package) catch unreachable;
    package.root = undefined; // filled in later
    package.output_absolute_path = undefined; // filled in when the output binary is created
    package.requirements = std.StringArrayHashMap(*symbol_.Symbol).init(allocator);
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

pub fn compile_c(self: *Package, packages: std.StringArrayHashMap(*Package), extra_flags: bool, allocator: std.mem.Allocator) !void {
    if (self.visited) {
        return;
    }
    self.visited = true;

    for (self.requirements.keys()) |requirement_name| {
        const required_package = packages.get(requirement_name).?;
        try required_package.compile_c(packages, extra_flags, allocator);
    }

    var obj_files = std.ArrayList([]const u8).init(allocator);
    for (self.local_modules.items) |local_module| {
        var c_file = String.init(allocator);
        c_file.writer().print("{s}{c}build{c}{s}-{s}.c", .{
            self.absolute_path,
            std.fs.path.sep,
            std.fs.path.sep,
            self.name,
            local_module.name,
        }) catch unreachable;

        var o_file = String.init(allocator);
        o_file.writer().print("{s}.o", .{local_module.name}) catch unreachable;
        obj_files.append(o_file.str()) catch unreachable;

        try self.gcc(c_file.str(), o_file.str(), packages, extra_flags, allocator);
    }
    if (self.is_static_lib) {
        try self.ar(obj_files, allocator);
    } else {
        try self.executable(obj_files, packages, allocator);
    }
}

pub fn append_include_dir(self: *Package, packages: std.StringArrayHashMap(*Package), include_dirs: *std.StringArrayHashMap(void)) void {
    for (self.requirements.keys()) |requirement_name| {
        const required_package = packages.get(requirement_name).?;
        required_package.append_include_dir(packages, &self.include_directories);
    }
    for (self.include_directories.keys()) |dir| {
        include_dirs.put(dir, void{}) catch unreachable;
    }
}

fn gcc(
    self: *Package,
    c_file: []const u8,
    o_file: []const u8,
    packages: std.StringArrayHashMap(*Package),
    extra_flags: bool,
    allocator: std.mem.Allocator,
) !void {
    var env_map = std.process.getEnvMap(allocator) catch unreachable;
    defer env_map.deinit();

    // Base gcc command
    var gcc_cmd = std.ArrayList([]const u8).init(allocator);
    gcc_cmd.appendSlice(&[_][]const u8{ "zig", "cc" }) catch unreachable;

    // Add input/output
    gcc_cmd.append("-c") catch unreachable;
    gcc_cmd.append(c_file) catch unreachable;

    gcc_cmd.append("-o") catch unreachable;
    gcc_cmd.append(o_file) catch unreachable;

    const std_path = env_map.get("ORNG_STD_PATH").?;
    var std_include_path = String.init(allocator);
    std_include_path.writer().print("-I{s}", .{std_path}) catch unreachable;

    // Add basic flags
    gcc_cmd.appendSlice(&[_][]const u8{
        "-std=c11",
        "-O3",
        "-g",
        std_include_path.str(),
    }) catch unreachable;

    if (extra_flags) {
        gcc_cmd.appendSlice(&[_][]const u8{
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

    // Add dependency include directories and libraries
    for (self.requirements.keys()) |requirement_name| {
        const requirement = packages.get(requirement_name).?;

        var requirement_include_path = String.init(allocator);
        requirement_include_path.writer().print("-I{s}{c}build", .{ requirement.root.init.?.module.module.get_package_abs_path(), std.fs.path.sep }) catch unreachable;
        gcc_cmd.append(requirement_include_path.str()) catch unreachable;
    }

    // Add all include directories
    for (self.include_directories.keys()) |include_dir| {
        var requirement_include_path = String.init(allocator);
        requirement_include_path.writer().print("-I{s}", .{include_dir}) catch unreachable;
        gcc_cmd.append(requirement_include_path.str()) catch unreachable;
    }

    // print_cmd(&gcc_cmd);

    // Set cwd
    var cwd_string = String.init(allocator);
    cwd_string.writer().print("{s}{c}build", .{ self.absolute_path, std.fs.path.sep }) catch unreachable;

    const run_res = std.process.Child.run(.{
        .allocator = allocator,
        .argv = gcc_cmd.items,
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
        std.debug.print("{s}", .{run_res.stderr});
        return error.CompileError;
    }
}

fn ar(self: *Package, obj_files: std.ArrayList([]const u8), allocator: std.mem.Allocator) !void {
    var env_map = std.process.getEnvMap(allocator) catch unreachable;
    defer env_map.deinit();

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
        std.debug.print("ar error: {s}\n", .{run_res.stderr});
        return error.CompileError;
    }
}

fn executable(self: *Package, obj_files: std.ArrayList([]const u8), packages: std.StringArrayHashMap(*Package), allocator: std.mem.Allocator) !void {
    var env_map = std.process.getEnvMap(allocator) catch unreachable;
    defer env_map.deinit();

    // Base command
    var cmd = std.ArrayList([]const u8).init(allocator);
    cmd.appendSlice(&[_][]const u8{ "zig", "cc" }) catch unreachable;

    // Add all the object files
    cmd.appendSlice(obj_files.items) catch unreachable;

    for (self.requirements.keys()) |requirement_name| {
        const requirement = packages.get(requirement_name).?;

        var requirement_library_path = String.init(allocator);
        requirement_library_path.writer().print("{s}{c}build", .{ requirement.root.init.?.module.module.get_package_abs_path(), std.fs.path.sep }) catch unreachable;
        cmd.append("-L") catch unreachable;
        cmd.append(requirement_library_path.str()) catch unreachable;

        for (self.library_directories.keys()) |lib_dir| {
            cmd.append("-L") catch unreachable;
            cmd.append(lib_dir) catch unreachable;
        }

        var requirement_library = String.init(allocator);
        requirement_library.writer().print("-l{s}", .{requirement.name}) catch unreachable;
        cmd.append(requirement_library.str()) catch unreachable;

        for (self.libraries.keys()) |lib| {
            cmd.append("-l") catch unreachable;
            cmd.append(lib) catch unreachable;
        }
    }

    // Add the output name
    var output_name = String.init(allocator);
    output_name.writer().print("{s}", .{self.name}) catch unreachable;
    cmd.append("-o") catch unreachable;
    cmd.append(output_name.str()) catch unreachable;

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

fn print_cmd(cmd: *const std.ArrayList([]const u8)) void {
    for (cmd.items) |item| {
        std.debug.print("{s} ", .{item});
    }
    std.debug.print("\n", .{});
}
