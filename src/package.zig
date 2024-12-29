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

    const module = self.root.init.?.module.module;

    const package_path = module.get_package_abs_path();
    const build_paths = [_][]const u8{ package_path, "build" };
    const build_path = std.fs.path.join(allocator, &build_paths) catch unreachable;

    var c_files = String.init(allocator);
    defer c_files.deinit();
    c_files.writer().print("{s}/{s}-{s}.c", .{ build_path, self.name, self.root.name }) catch unreachable;

    // Base gcc flags
    var gcc_cmd = std.ArrayList([]const u8).init(allocator);
    gcc_cmd.appendSlice(&[_][]const u8{
        "/bin/gcc",
        "-c",
        c_files.str(),
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
        requirement_library_path.writer().print("-L{s}/build", .{requirement.root.init.?.module.module.get_package_abs_path()}) catch unreachable;
        gcc_cmd.append(requirement_library_path.str()) catch unreachable;

        var requirement_library = String.init(allocator);
        requirement_library.writer().print("-l{s}", .{requirement_name}) catch unreachable;
        gcc_cmd.append(requirement_library.str()) catch unreachable;
    }

    // Add linked dependencies

    // Add output
    var output_flag_string = String.init(allocator);
    output_flag_string.writer().print("-o {s}.a", .{self.name}) catch unreachable;
    gcc_cmd.append(output_flag_string.str()) catch unreachable;

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
