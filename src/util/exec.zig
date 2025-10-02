const std = @import("std");

pub fn exec(argv: []const []const u8) !struct { stdout: []u8, retcode: i64 } { // TODO: Uninfer error
    const allocator = std.heap.page_allocator;

    var child_process = std.process.Child.init(argv, allocator);
    defer _ = child_process.kill() catch unreachable;

    child_process.stdout_behavior = .Pipe;
    child_process.spawn() catch |err| {
        return err;
    };

    // _SEVEN_ lines for something that should be 2 at most
    var buffer: [100 * 1024]u8 = undefined;
    var child_stdout_reader = child_process.stdout.?.reader(&buffer);
    const reader_intfc: *std.Io.Reader = &child_stdout_reader.interface;
    var writer_alloc = std.Io.Writer.Allocating.init(allocator);
    errdefer writer_alloc.deinit();
    const writer = &writer_alloc.writer;
    _ = reader_intfc.stream(writer, .unlimited) catch |e| switch (e) {
        error.EndOfStream => {}, // this isn't a fucking error you retard
        else => return e,
    };

    var retcode: i64 = 0;

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

    return .{ .stdout = writer_alloc.written(), .retcode = retcode };
}
