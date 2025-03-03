const std = @import("std");

pub fn exec(argv: []const []const u8) !struct { stdout: []u8, retcode: i64 } { // TODO: Uninfer error
    const allocator = std.heap.page_allocator;

    const max_output_size = 100 * 1024 * 1024;
    var child_process = std.process.Child.init(argv, allocator);
    defer _ = child_process.kill() catch unreachable;

    child_process.stdout_behavior = .Pipe;
    child_process.spawn() catch |err| {
        return err;
    };

    const child_stdout_reader = child_process.stdout.?.reader();
    const child_stdout = try child_stdout_reader.readAllAlloc(allocator, max_output_size);
    var retcode: i64 = 0;
    errdefer allocator.free(child_stdout);

    const child = try child_process.wait();
    switch (child) {
        .Exited => |c| {
            retcode = c;
        },
        .Signal => |c| switch (c) {
            11 => return error.SegmentationFault,
            else => return error.UnknownSignal,
        },
        else => return error.CommandFailed,
    }

    return .{ .stdout = child_stdout, .retcode = retcode };
}
