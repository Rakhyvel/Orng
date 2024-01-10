const std = @import("std");

// Have to live on the edge because of ZLS >:-(
pub fn build(b: *std.Build) void {
    const target = b.host;
    const optimize = b.standardOptimizeOption(.{});

    executable(b, optimize, target, "orng-test", "src/test.zig", "orng-test", "Runs the integration tests");
    executable(b, optimize, target, "orng", "src/main.zig", "orng", "Runs the compiler");
}

fn executable(b: *std.Build, optimize: std.builtin.OptimizeMode, target: std.Build.ResolvedTarget, name: []const u8, path: []const u8, run: []const u8, run_desc: []const u8) void {
    const exe = b.addExecutable(.{
        .name = name,
        .root_source_file = .{ .path = path },
        .target = target,
        .optimize = optimize,
    });
    const install_cmd = b.addInstallArtifact(exe, .{});
    const install_step = b.step(run, run_desc);
    install_step.dependOn(&install_cmd.step);
}
