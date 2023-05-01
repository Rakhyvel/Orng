const std = @import("std");
const errs = @import("errors.zig");
const compiler = @import("main.zig");
const String = @import("zig-string/zig-string.zig").String;

const Colour = enum {
    none,
    black,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    bright_black,
    bright_red,
    bright_green,
    bright_yellow,
    bright_blue,
    bright_magenta,
    bright_cyan,
    bright_white,
};

pub const Attr = struct {
    fg: Colour = .white,
    bg: Colour = .none,

    // Pretty much all style escape codes I could find, minus a few that are
    // not widely supported.
    bold: bool = false,
    dimmed: bool = false,
    italic: bool = false,
    underline: bool = false,
    blinking: bool = false,
    reverse: bool = false,
    hidden: bool = false,
    overline: bool = false,
    strikethrough: bool = false,

    fn eql(self: Attr, other: Attr) bool {
        inline for (@typeInfo(Attr).Struct.fields) |field| {
            if (@field(self, field.name) != @field(other, field.name)) return false;
        }
        return true;
    }

    fn dump(self: Attr, writer: anytype) !void {
        try writer.writeAll("\x1B[0");
        if (self.bold) try writer.writeAll(";1");
        if (self.dimmed) try writer.writeAll(";2");
        if (self.italic) try writer.writeAll(";3");
        if (self.underline) try writer.writeAll(";4");
        if (self.blinking) try writer.writeAll(";5");
        if (self.reverse) try writer.writeAll(";7");
        if (self.hidden) try writer.writeAll(";8");
        if (self.overline) try writer.writeAll(";53");
        if (self.strikethrough) try writer.writeAll(";9");
        switch (self.fg) {
            .none => {},
            .black => try writer.writeAll(";30"),
            .red => try writer.writeAll(";31"),
            .green => try writer.writeAll(";32"),
            .yellow => try writer.writeAll(";33"),
            .blue => try writer.writeAll(";34"),
            .magenta => try writer.writeAll(";35"),
            .cyan => try writer.writeAll(";36"),
            .white => try writer.writeAll(";37"),
            .bright_black => try writer.writeAll(";90"),
            .bright_red => try writer.writeAll(";91"),
            .bright_green => try writer.writeAll(";92"),
            .bright_yellow => try writer.writeAll(";93"),
            .bright_blue => try writer.writeAll(";94"),
            .bright_magenta => try writer.writeAll(";95"),
            .bright_cyan => try writer.writeAll(";96"),
            .bright_white => try writer.writeAll(";97"),
        }
        switch (self.bg) {
            .none => {},
            .black => try writer.writeAll(";40"),
            .red => try writer.writeAll(";41"),
            .green => try writer.writeAll(";42"),
            .yellow => try writer.writeAll(";43"),
            .blue => try writer.writeAll(";44"),
            .magenta => try writer.writeAll(";45"),
            .cyan => try writer.writeAll(";46"),
            .white => try writer.writeAll(";74"),
            .bright_black => try writer.writeAll(";100"),
            .bright_red => try writer.writeAll(";101"),
            .bright_green => try writer.writeAll(";102"),
            .bright_yellow => try writer.writeAll(";103"),
            .bright_blue => try writer.writeAll(";104"),
            .bright_magenta => try writer.writeAll(";105"),
            .bright_cyan => try writer.writeAll(";106"),
            .bright_white => try writer.writeAll(";107"),
        }
        try writer.writeAll("m");
    }
};

const allocator = std.heap.page_allocator;
const revert = Attr{};
const out = std.io.getStdOut().writer();
const succeed_color = Attr{ .fg = .green, .bold = true };
const fail_color = Attr{ .fg = .red, .bold = true };

pub fn main() !void {
    var args = try std.process.ArgIterator.initWithAllocator(allocator);
    _ = args.next() orelse unreachable;
    var arg: []const u8 = undefined;
    if (args.next()) |_arg| {
        arg = _arg;
        while (std.mem.eql(u8, arg, "--")) {
            arg = args.next().?;
        }
        if (std.mem.eql(u8, "integration", arg)) {
            try integrationTests(false);
        } else if (std.mem.eql(u8, "coverage", arg)) {
            try integrationTests(true);
        } else if (std.mem.eql(u8, "fuzz", arg)) {
            try fuzzTests();
        } else {
            std.debug.print("invalid command-line argument: {s}\nusage: orng-test (integration | coverage | fuzz)\n", .{arg});
            return error.InvalidCliArgument;
        }
    }
}

/// kcov can't handle child processes for some reason and freezes.
/// When `coverage` is false, integration testing occurs as normal, and child processes are spawned for gcc, executing the executable, etc
/// When `coverage` is true, no child processes are spawned, and no output is given.
fn integrationTests(coverage: bool) !void {
    if (!coverage) {
        try succeed_color.dump(out);
        try out.print("\n[============]\n", .{});
        try revert.dump(out);
    }

    var passed: i64 = 0;
    var failed: i64 = 0;
    if (!coverage) {
        _ = exec(&[_][]const u8{ "/bin/rm", "-rf", "tests/integration/build/" }) catch {};
        _ = exec(&[_][]const u8{ "/bin/mkdir", "tests/integration/build/" }) catch {};
    }

    // Add all files names in the src folder to `files`
    var dir = try std.fs.cwd().openIterableDir("tests/integration/", .{});
    var it = dir.iterate();
    while (try it.next()) |file| {
        if (file.kind != .File) {
            continue;
        }
        var dot_index = indexOf(file.name, '.');
        var test_name = file.name[0..dot_index];

        // Input .orng file
        var in_name: String = try String.init_with_contents(allocator, "tests/integration/");
        defer in_name.deinit();
        try in_name.insert(file.name, in_name.len());

        // Output .c file
        var out_name: String = try String.init_with_contents(allocator, "tests/integration/build/");
        defer out_name.deinit();
        try out_name.insert(test_name, out_name.len());
        try out_name.insert(".c", out_name.len());

        if (!coverage) {
            try succeed_color.dump(out);
            try out.print("[ RUN    ... ] ", .{});
            try revert.dump(out);
            try out.print("{s}\n", .{file.name});
        }

        // Read in the expected value and stdout
        var f = try std.fs.cwd().openFile(in_name.str(), .{});
        defer f.close();
        var buf_reader = std.io.bufferedReader(f.reader());
        var in_stream = buf_reader.reader();
        var contents_arraylist = std.ArrayList(u8).init(allocator);
        try in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF);
        var contents = try contents_arraylist.toOwnedSlice();
        var expectedOut = contents[3..untilNewline(contents)];

        // Try to compile Orng (make sure no errors)
        var errors = errs.Errors.init(allocator);
        defer errors.deinit();
        compiler.compile(&errors, in_name.str(), out_name.str(), allocator) catch {
            if (!coverage) {
                try fail_color.dump(out);
                try out.print("[ ... FAILED ] ", .{});
                try revert.dump(out);
                try out.print("Orng Compiler crashed!\n", .{});
                failed += 1;
                std.debug.dumpCurrentStackTrace(128);
            }
            continue;
        };
        if (coverage) {
            continue;
        }
        if (errors.errors_list.items.len > 0) {
            try fail_color.dump(out);
            try out.print("[ ... FAILED ] ", .{});
            try revert.dump(out);
            try out.print("Orng -> C.\n", .{});
            failed += 1;
            continue;
        }

        // compile C (make sure no errors)
        var gcc_res = exec(&[_][]const u8{ "/bin/gcc", out_name.str(), "-lm" }) catch {
            continue;
        };
        if (gcc_res.retcode != 0) {
            try fail_color.dump(out);
            try out.print("[ ... FAILED ] ", .{});
            try revert.dump(out);
            try out.print("C -> Executable.\n", .{});
            failed += 1;
            continue;
        }
        defer _ = exec(&[_][]const u8{ "/bin/rm", "-f", "a.out" }) catch {};

        // execute (make sure no signals)
        var res = exec(&[_][]const u8{"./a.out"}) catch |e| {
            try out.print("{?}\n", .{e});
            try fail_color.dump(out);
            try out.print("[ ... FAILED ] ", .{});
            try revert.dump(out);
            try out.print("Execution interrupted!\n", .{});
            failed += 1;
            continue;
        };
        if (!std.mem.eql(u8, res.stdout, expectedOut)) {
            try fail_color.dump(out);
            try out.print("[ ... FAILED ] ", .{});
            try revert.dump(out);
            try out.print("Expected \"{s}\" retcode, got \"{s}\"\n", .{ expectedOut, res.stdout });
            failed += 1;
            continue;
        }

        // Monitor stdout and capture return value, if these don't match expected as commented in the file, print error

        try succeed_color.dump(out);
        try out.print("[ ... PASSED ]\n", .{});
        try revert.dump(out);
        passed += 1;
    }

    if (!coverage) {
        try succeed_color.dump(out);
        try out.print("[============]\n", .{});
        try revert.dump(out);
        try out.print("Passed tests: {}\n", .{passed});
        try out.print("Failed tests: {}\n", .{failed});
        if (failed > 0) {
            return error.TestsFailed;
        }
    } else {
        std.debug.print("Coverage output to kcov-out/index.html\n", .{});
    }
}

/// Uses Dr. Proebsting's rdgen to create random Orng programs, feeds them to the compiler
fn fuzzTests() !void {
    // Open and read tests/fuzz/fuzz.txt
    var file = try std.fs.cwd().openFile("tests/fuzz/fuzz.txt", .{});
    defer file.close();

    // Read in the contents of the file
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    try in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF);
    var contents = try contents_arraylist.toOwnedSlice();

    var passed: usize = 0;
    var failed: usize = 0;

    // Add lines to arraylist
    var start: usize = indexOf(contents, '"') + 1;
    var end: usize = start + 1;
    while (end < contents.len) : (end += 1) {
        if (contents[end] == '"') {
            // Found end of string
            var program_text: []const u8 = contents[start..end];

            // Feed to Orng compiler (specifying fuzz tokens) to compile to fuzz-out.c
            var errors = errs.Errors.init(allocator);
            defer errors.deinit();
            compiler.compileContents(&errors, program_text, "tests/fuzz/fuzz-out.c", true, allocator) catch {
                std.debug.print("{s}\n", .{program_text});
                try fail_color.dump(out);
                try out.print("[ ... FAILED ] ", .{});
                try revert.dump(out);
                try out.print("Orng Compiler crashed!\n", .{});
                failed += 1;
                continue;
            };

            for (errors.errors_list.items) |err| {
                if (err.getStage() == .parsing) {
                    std.debug.print("{s}\n", .{program_text});
                    try fail_color.dump(out);
                    try out.print("[ ... FAILED ] ", .{});
                    try revert.dump(out);
                    try out.print("Orng failed to parse correctly!\n", .{});
                    failed += 1;
                    continue;
                }
            }

            try succeed_color.dump(out);
            try out.print("[ ... PASSED ]\n", .{});
            try revert.dump(out);
            passed += 1;

            if (end < contents.len - 4) {
                start = indexOf(contents[end + 1 ..], '"') + end + 2;
                end = start;
            } else {
                break;
            }
        }
    }

    if (passed + failed != 0) {
        std.debug.print("Fuzz test percentage: {d}%\n", .{100.0 * std.math.lossyCast(f64, passed) / std.math.lossyCast(f64, passed + failed)});
    }
}

fn exec(argv: []const []const u8) !struct { stdout: []u8, retcode: i64 } {
    const max_output_size = 100 * 1024 * 1024;
    var child_process = std.ChildProcess.init(argv, allocator);
    defer _ = child_process.kill() catch unreachable;

    child_process.stdout_behavior = .Pipe;
    child_process.spawn() catch |err| {
        return err;
    };

    const stdout = try child_process.stdout.?.reader().readAllAlloc(allocator, max_output_size);
    var retcode: i64 = 0;
    errdefer allocator.free(stdout);

    const term = try child_process.wait();
    switch (term) {
        .Exited => |c| {
            retcode = c;
        },
        .Signal => |c| switch (c) {
            11 => return error.SegmentationFault,
            else => return error.UnknownSignal,
        },
        else => {
            return error.CommandFailed;
        },
    }
    return .{ .stdout = stdout, .retcode = retcode };
}

// Great std lib function candidate! Holy hell...
fn indexOf(str: []const u8, c: u8) usize {
    var retval: usize = 0;
    while (str[retval] != c) : (retval += 1) {}
    return retval;
}

fn untilNewline(str: []const u8) usize {
    var i: usize = 0;
    while (i < str.len and str[i] != '\n') : (i += 1) {}
    return i;
}
