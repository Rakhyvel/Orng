const std = @import("std");
const builtin = @import("builtin");

const Error = error{CompileError};

pub fn git_clone(repo_url: []const u8, allocator: std.mem.Allocator) Error!void {
    ensure_packages_dir_exists(allocator);

    if (repo_exists(repo_url, allocator)) {
        std.debug.print("{s} already exists\n", .{repo_url});
        return;
    }

    var cmd = std.ArrayList([]const u8).init(allocator);
    cmd.appendSlice(&[_][]const u8{
        "git",
        "clone",
    }) catch unreachable;

    cmd.append(repo_url) catch unreachable;

    const run_res = std.process.Child.run(.{
        .allocator = allocator,
        .argv = cmd.items,
        .cwd = get_packages_dir(allocator),
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
        std.debug.print("git error: {} {s}\n", .{ retcode, run_res.stderr });
        return error.CompileError;
    }
}

fn ensure_packages_dir_exists(allocator: std.mem.Allocator) void {
    const orng_dir = get_orng_dir(allocator);
    defer allocator.free(orng_dir);
    _ = std.fs.Dir.openDir(std.fs.cwd(), orng_dir, .{}) catch {
        std.fs.makeDirAbsolute(orng_dir) catch unreachable;
    };
    const repo_dir = get_packages_dir(allocator);
    defer allocator.free(repo_dir);
    _ = std.fs.Dir.openDir(std.fs.cwd(), repo_dir, .{}) catch {
        std.fs.makeDirAbsolute(repo_dir) catch unreachable;
    };
}

pub fn get_orng_dir(allocator: std.mem.Allocator) []const u8 {
    var env_map = std.process.getEnvMap(allocator) catch unreachable;
    defer env_map.deinit();
    const home_dir = env_map.get(if (builtin.target.os.tag == .windows) "USERPROFILE" else "HOME").?;
    const root_file_paths = [_][]const u8{ home_dir, ".orng" };
    return std.fs.path.join(allocator, &root_file_paths) catch unreachable;
}

pub fn get_packages_dir(allocator: std.mem.Allocator) []const u8 {
    const orng_dir = get_orng_dir(allocator);
    defer allocator.free(orng_dir);
    const root_file_paths = [_][]const u8{ orng_dir, "packages" };
    return std.fs.path.join(allocator, &root_file_paths) catch unreachable;
}

pub fn get_repo_dir(repo_url: []const u8, allocator: std.mem.Allocator) []const u8 {
    const repo_dir = get_packages_dir(allocator);
    var dirs = std.ArrayList([]const u8).init(allocator);
    defer dirs.deinit();
    dirs.append(repo_dir) catch unreachable;
    dirs.append(std.fs.path.basename(repo_url)) catch unreachable;
    return std.fs.path.join(allocator, dirs.items) catch unreachable;
}

fn repo_exists(repo_url: []const u8, allocator: std.mem.Allocator) bool {
    const repo_dir = get_repo_dir(repo_url, allocator);
    defer allocator.free(repo_dir);
    var dir = std.fs.Dir.openDir(std.fs.cwd(), repo_dir, .{}) catch {
        return false;
    };
    dir.close();
    return true;
}
