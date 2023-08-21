const std = @import("std");
const errs = @import("errors.zig");
const compiler = @import("main.zig");
const term = @import("term.zig");
const String = @import("zig-string/zig-string.zig").String;

const allocator = std.heap.page_allocator;
const revert = term.Attr{};
const out = std.io.getStdOut().writer();
const succeed_color = term.Attr{ .fg = .green, .bold = true };
const fail_color = term.Attr{ .fg = .red, .bold = true };
const not_orng_color = term.Attr{ .fg = .blue, .bold = true };

const Test_File_Fn = @TypeOf(integrateTestFile);

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
            try parse_args(args, "tests/integration", integrateTestFile);
        } else if (std.mem.eql(u8, "coverage", arg)) {
            _ = try testDir("", null, true, "tests/integration", integrateTestFile);
        } else if (std.mem.eql(u8, "negative-coverage", arg)) {
            _ = try testDir("", null, true, "tests/integration", integrateTestFile);
            _ = try testDir("", null, true, "tests/negative", negativeTestFile);
        } else if (std.mem.eql(u8, "fuzz", arg)) {
            try fuzzTests();
        } else if (std.mem.eql(u8, "negative", arg)) {
            try parse_args(args, "tests/negative", negativeTestFile);
        } else {
            std.debug.print("invalid command-line argument: {s}\nusage: orng-test (integration | coverage | fuzz)\n", .{arg});
            return error.InvalidCliArgument;
        }
    }
}

fn parse_args(old_args: std.process.ArgIterator, root: []const u8, comptime test_file: Test_File_Fn) !void {
    var args = old_args;
    try term.outputColor(succeed_color, "[============]\n", out);

    var results = Results{ .passed = 0, .failed = 0 };
    if (args.inner.index < args.inner.count) {
        while (args.next()) |next| {
            if (indexOf(next, '.')) |_| {
                _ = try test_file("", next, false);
            } else {
                var open_dir_name = try String.init_with_contents(allocator, "/");
                defer open_dir_name.deinit();
                try open_dir_name.concat(next);
                _ = try testDir(open_dir_name.str(), &results, false, root, test_file);
            }
        }
    } else {
        try testDir("", &results, false, root, test_file);
        try term.outputColor(succeed_color, "[============]\n", out);
        try out.print("Passed tests: {}\n", .{results.passed});
        try out.print("Failed tests: {}\n", .{results.failed});
        if (results.failed > 0) {
            return error.TestsFailed;
        }
        std.debug.print("Coverage output to kcov-out/index.html\n", .{});
    }
}

/// kcov can't handle child processes for some reason and freezes.
/// When `coverage` is false, integration testing occurs as normal, and child processes are spawned for gcc, executing the executable, etc
/// When `coverage` is true, no child processes are spawned, and no output is given.
const Results = struct { passed: i64, failed: i64 };
fn testDir(dir_name: []const u8, results: ?*Results, coverage: bool, start: []const u8, comptime test_file_fn: Test_File_Fn) !void {
    var open_dir_name = try String.init_with_contents(allocator, start);
    defer open_dir_name.deinit();
    try open_dir_name.concat(dir_name);
    // Add all files names in the src folder to `files`
    var dir = try std.fs.cwd().openIterableDir(open_dir_name.str(), .{});
    defer dir.close();

    var it = dir.iterate();
    while (try it.next()) |file| {
        if (std.mem.eql(u8, file.name, "build") or std.mem.eql(u8, file.name, "README.md")) {
            continue;
        }
        switch (file.kind) {
            .file => {
                var res = try test_file_fn(dir_name, file.name, coverage);
                if (!coverage) {
                    if (res) {
                        results.?.passed += 1;
                    } else {
                        results.?.failed += 1;
                    }
                }
            },
            .directory => {
                var new_dir_name = try String.init_with_contents(allocator, "");
                defer new_dir_name.deinit();
                try new_dir_name.concat(dir_name);
                try new_dir_name.concat("/");
                try new_dir_name.concat(file.name);
                try testDir(new_dir_name.str(), results, coverage, start, test_file_fn);
            },
            else => continue,
        }
    }
}

fn integrateTestFile(dir_name: []const u8, filename: []const u8, coverage: bool) !bool {
    if (filename.len < 4 or !std.mem.eql(u8, filename[filename.len - 4 ..], "orng")) {
        return true;
    }
    var dot_index = indexOf(filename, '.') orelse {
        std.debug.print("filename {s} doens't contain a '.'", .{filename});
        return error.InvalidFilename;
    };
    var test_name = filename[0..dot_index];

    // Input .orng file
    var in_name: String = try String.init_with_contents(allocator, "tests/integration");
    defer in_name.deinit();
    try in_name.concat(dir_name);
    try in_name.concat("/");
    try in_name.concat(filename);

    // Output .c file
    var out_name: String = try String.init_with_contents(allocator, "tests/integration/build");
    defer out_name.deinit();
    try out_name.concat(dir_name);
    if (!coverage) { // Create output directory if it doesn't exist
        _ = exec(&[_][]const u8{ "/bin/mkdir", "-p", out_name.str() }) catch {};
    }
    try out_name.concat("/");
    try out_name.concat(test_name);
    try out_name.concat(".c");

    if (!coverage) {
        try term.outputColor(succeed_color, "[ RUN    ... ] ", out);
        if (dir_name.len > 1) {
            try out.print("{s}/{s}\n", .{ dir_name[1..], filename });
        } else {
            try out.print("{s}\n", .{filename});
        }
    }

    // Read in the expected value and stdout
    var f = std.fs.cwd().openFile(in_name.str(), .{}) catch |err| switch (err) {
        error.FileNotFound => {
            std.debug.print("filename {s} doesn't exist\n", .{filename});
            return err;
        },
        else => return err,
    };
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
    compiler.compile(&errors, in_name.str(), out_name.str(), allocator) catch |err| {
        if (!coverage) {
            std.debug.print("{}\n", .{err});
            try term.outputColor(fail_color, "[ ... FAILED ] ", out);
            switch (err) {
                error.lexerError,
                error.parserError,
                error.symbolError,
                error.typeError,
                => try out.print("Orng -> C.\n", .{}),
                else => try out.print("Orng Compiler crashed!\n", .{}),
            }
            std.debug.dumpCurrentStackTrace(128);
            return err;
        }
        return false;
    };
    if (coverage) {
        return false;
    }

    // compile C (make sure no errors)
    var gcc_res = exec(&[_][]const u8{ "/bin/gcc", out_name.str(), "-lm", "-O3", "-fsanitize=undefined,address" }) catch {
        std.debug.print("Error compiling with GCC", .{});
        return false;
    };
    if (gcc_res.retcode != 0) {
        try term.outputColor(fail_color, "[ ... FAILED ] ", out);
        try out.print("C -> Executable.\n", .{});
        return false;
    }

    // execute (make sure no signals)
    var res = exec(&[_][]const u8{"./a.out"}) catch |e| {
        try out.print("{?}\n", .{e});
        try term.outputColor(fail_color, "[ ... FAILED ] ", out);
        try out.print("Execution interrupted!\n", .{});
        return false;
    };
    if (!std.mem.eql(u8, res.stdout, expectedOut)) {
        try term.outputColor(fail_color, "[ ... FAILED ] ", out);
        try out.print("Expected \"{s}\" retcode, got \"{s}\"\n", .{ expectedOut, res.stdout });
        return false;
    }

    // Monitor stdout and capture return value, if these don't match expected as commented in the file, print error
    try term.outputColor(succeed_color, "[ ... PASSED ]\n", out);
    return true;
}

fn negativeTestFile(dir_name: []const u8, filename: []const u8, coverage: bool) !bool {
    if (filename.len < 4 or !std.mem.eql(u8, filename[filename.len - 4 ..], "orng")) {
        return true;
    }
    var dot_index = indexOf(filename, '.') orelse {
        std.debug.print("filename {s} doens't contain a '.'", .{filename});
        return error.InvalidFilename;
    };
    var test_name = filename[0..dot_index];
    _ = test_name;

    // Input .orng file
    var in_name: String = try String.init_with_contents(allocator, "tests/negative");
    defer in_name.deinit();
    try in_name.concat(dir_name);
    try in_name.concat("/");
    try in_name.concat(filename);

    if (!coverage) {
        try term.outputColor(succeed_color, "[ RUN    ... ] ", out);
        if (dir_name.len > 1) {
            try out.print("{s}/{s}\n", .{ dir_name[1..], filename });
        } else {
            try out.print("{s}\n", .{filename});
        }
    }

    // Read in the expected value and stdout
    var f = std.fs.cwd().openFile(in_name.str(), .{}) catch |err| switch (err) {
        error.FileNotFound => {
            std.debug.print("filename {s} doesn't exist\n", .{filename});
            return err;
        },
        else => return err,
    };
    defer f.close();
    var buf_reader = std.io.bufferedReader(f.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    try in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF);

    // Try to compile Orng (make sure no errors)
    var errors = errs.Errors.init(allocator);
    defer errors.deinit();
    compiler.compile(&errors, in_name.str(), "a.out", allocator) catch |err| {
        if (!coverage) {
            switch (err) {
                error.lexerError,
                error.parserError,
                error.symbolError,
                error.typeError,
                => {
                    try term.outputColor(succeed_color, "[ ... PASSED ]\n", out);
                    return true;
                },
                else => {
                    std.debug.print("{}\n", .{err});
                    try term.outputColor(fail_color, "[ ... FAILED ] ", out);
                    try out.print("Orng Compiler crashed unexpectedly!\n", .{});
                    std.debug.dumpCurrentStackTrace(128);
                    return err;
                },
            }
        } else {
            return false;
        }
    };
    try term.outputColor(fail_color, "[ ... FAILED ] ", out);
    try out.print("Negative test compiled without error.\n", .{});
    return false;
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
    var i: usize = 0;

    // Add lines to arraylist
    var start: usize = indexOf(contents, '"').? + 1;
    var end: usize = start + 1;
    var broken: bool = false;
    while (end < contents.len and !broken) : (end += 1) {
        if (contents[end] == '"') {
            defer {
                if (end < contents.len - 4) {
                    start = indexOf(contents[end + 1 ..], '"').? + end + 2;
                    end = start;
                } else {
                    broken = true;
                }
            }

            // Found end of string
            var program_text: []const u8 = contents[start..end];

            // std.debug.print("{s}\n", .{program_text});
            // Feed to Orng compiler (specifying fuzz tokens) to compile to fuzz-out.c
            var errors = errs.Errors.init(allocator);
            defer errors.deinit();
            var lines = std.ArrayList([]const u8).init(allocator);
            defer lines.deinit();
            i += 1;
            var file_root = compiler.compileContents(&errors, &lines, "fuzz", program_text, true, allocator) catch |err| {
                try errors.printErrors(&lines, "");
                switch (err) {
                    error.lexerError,
                    error.symbolError,
                    error.typeError,
                    => {
                        passed += 1;
                        try term.outputColor(succeed_color, "[ ... PASSED ] ", out);
                        try out.print("Orng -> IR. {}\n", .{i});
                        continue;
                    },
                    error.parserError => {
                        failed += 1;
                        try term.outputColor(fail_color, "[ ... FAILED ] ", out);
                        try out.print("Parsing mismatch!\n", .{});
                        return;
                    },
                    else => {
                        failed += 1;
                        try term.outputColor(fail_color, "[ ... FAILED ] ", out);
                        try out.print("Orng Compiler crashed!\n", .{});
                        return;
                    },
                }
            };
            compiler.output(&errors, &lines, file_root, 0, "tests/fuzz/fuzz-out.c", allocator) catch |err| {
                switch (err) {
                    error.symbolError => {
                        passed += 1;
                        try term.outputColor(succeed_color, "[ ... PASSED ] ", out);
                        try out.print("Orng -> C. {}\n", .{i});
                        continue;
                    },
                    else => {
                        failed += 1;
                        try term.outputColor(fail_color, "[ ... FAILED ] ", out);
                        try out.print("Orng Compiler crashed with input above!\n", .{});
                        return;
                    },
                }
            };

            var should_continue: bool = false;
            for (errors.errors_list.items) |err| {
                if (err.getStage() == .parsing) {
                    try term.outputColor(fail_color, "[ ... FAILED ] ", out);
                    try out.print("Orng failed to parse the above correctly!\n", .{});
                    failed += 1;
                    should_continue = true;
                    break;
                }
            }
            if (should_continue) {
                continue;
            }
            try term.outputColor(succeed_color, "[ ... PASSED ]\n", out);
            passed += 1;
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

    const child = try child_process.wait();
    switch (child) {
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
fn indexOf(str: []const u8, c: u8) ?usize {
    for (0..str.len) |i| {
        if (str[i] == c) {
            return i;
        }
    }
    return null;
}

fn untilNewline(str: []const u8) usize {
    var i: usize = 0;
    while (i < str.len and str[i] != '\n') : (i += 1) {}
    return i;
}
