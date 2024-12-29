const exec = @import("exec.zig").exec;
const std = @import("std");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");

const Package = @This();

name: []const u8,
absolute_path: []const u8,
root: *symbol_.Symbol,
requirements: std.StringArrayHashMap(*symbol_.Symbol),
is_static_lib: bool,
visited: bool,

pub fn new(allocator: std.mem.Allocator, package_name: []const u8, package_absolute_path: []const u8, is_static_lib: bool) *Package {
    const package = allocator.create(Package) catch unreachable;
    package.root = undefined; // filled in later
    package.requirements = std.StringArrayHashMap(*symbol_.Symbol).init(allocator);
    package.visited = false;
    package.name = package_name;
    package.absolute_path = package_absolute_path;
    package.is_static_lib = is_static_lib;
    return package;
}

pub fn compile_c(self: *Package, packages: std.StringArrayHashMap(*Package), allocator: std.mem.Allocator) !void {
    if (self.visited) {
        return;
    }
    self.visited = true;

    for (self.requirements.keys()) |requirement_name| {
        const required_package = packages.get(requirement_name).?;
        try required_package.compile_c(packages, allocator);
    }
    std.debug.print("DOING PACKAGE {s}: {s}\n", .{ self.name, self.absolute_path });

    try self.gcc(packages, allocator);
    try self.ar(allocator);
}

fn gcc(self: *Package, packages: std.StringArrayHashMap(*Package), allocator: std.mem.Allocator) !void {
    // Base gcc command
    var gcc_cmd = std.ArrayList([]const u8).init(allocator);
    gcc_cmd.appendSlice(&[_][]const u8{
        "/bin/gcc",
    }) catch unreachable;

    // Add input/output
    var c_files = String.init(allocator);
    defer c_files.deinit();
    c_files.writer().print("{s}/build/{s}-{s}.c", .{ self.absolute_path, self.name, self.root.name }) catch unreachable;
    if (self.is_static_lib) {
        var input_paths = String.init(allocator);
        input_paths.writer().print("{s}", .{c_files.str()}) catch unreachable;
        gcc_cmd.append("-c") catch unreachable;
        gcc_cmd.append(input_paths.str()) catch unreachable;

        var output_flag_string = String.init(allocator);
        output_flag_string.writer().print("-o{s}.o", .{self.name}) catch unreachable;
        gcc_cmd.append(output_flag_string.str()) catch unreachable;
    } else {
        var input_paths = String.init(allocator);
        input_paths.writer().print("{s}", .{c_files.str()}) catch unreachable;
        gcc_cmd.append(input_paths.str()) catch unreachable;

        var output_flag_string = String.init(allocator);
        output_flag_string.writer().print("-o{s}", .{self.name}) catch unreachable;
        gcc_cmd.append(output_flag_string.str()) catch unreachable;
    }

    // Add basic flags
    gcc_cmd.appendSlice(&[_][]const u8{
        "-std=c11",
        "-O3",
        "-g",
        "-I/home/jshimel/Orng/std",
    }) catch unreachable;

    // Add dependency include directories and libraries
    for (self.requirements.keys()) |requirement_name| {
        const requirement = packages.get(requirement_name).?;

        var requirement_include_path = String.init(allocator);
        requirement_include_path.writer().print("-I{s}/build", .{requirement.root.init.?.module.module.get_package_abs_path()}) catch unreachable;
        gcc_cmd.append(requirement_include_path.str()) catch unreachable;

        var requirement_library_path = String.init(allocator);
        requirement_library_path.writer().print("{s}/build", .{requirement.root.init.?.module.module.get_package_abs_path()}) catch unreachable;
        gcc_cmd.append("-L") catch unreachable;
        gcc_cmd.append(requirement_library_path.str()) catch unreachable;
        std.debug.print("{s}\n", .{requirement_library_path.str()});

        var requirement_library = String.init(allocator);
        requirement_library.writer().print("-l{s}", .{requirement_name}) catch unreachable;
        gcc_cmd.append(requirement_library.str()) catch unreachable;
    }

    // Set cwd
    var cwd_string = String.init(allocator);
    cwd_string.writer().print("{s}/build", .{self.absolute_path}) catch unreachable;

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
        std.debug.print("{s}\n", .{run_res.stderr});
        return error.CompileError;
    }
}

fn ar(self: *Package, allocator: std.mem.Allocator) !void {
    // Base gcc command
    var cmd = std.ArrayList([]const u8).init(allocator);
    cmd.appendSlice(&[_][]const u8{
        "/usr/bin/ar",
        "rcs",
    }) catch unreachable;

    // Add the lib name
    var lib_name = String.init(allocator);
    lib_name.writer().print("lib{s}.a", .{self.name}) catch unreachable;
    cmd.append(lib_name.str()) catch unreachable;

    // Add all the object files
    var lib_obj = String.init(allocator);
    lib_obj.writer().print("{s}/build/{s}.o", .{ self.absolute_path, self.name }) catch unreachable;
    cmd.append(lib_obj.str()) catch unreachable;

    // Set cwd
    var cwd_string = String.init(allocator);
    cwd_string.writer().print("{s}/build", .{self.absolute_path}) catch unreachable;

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
        std.debug.print("{s}\n", .{run_res.stderr});
        return error.CompileError;
    }
}
