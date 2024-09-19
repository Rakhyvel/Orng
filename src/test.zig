const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const module_ = @import("module.zig");
const primitives_ = @import("primitives.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const term_ = @import("term.zig");

const allocator = std.heap.page_allocator;
const revert = term_.Attr{};
const stdout = std.io.getStdOut();
const out = stdout.writer();
const succeed_color = term_.Attr{ .fg = .green, .bold = true };
const fail_color = term_.Attr{ .fg = .red, .bold = true };
const not_orng_color = term_.Attr{ .fg = .blue, .bold = true };

const Test_File_Fn = fn ([]const u8, *symbol_.Scope, bool) bool;

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
            try parse_args(args, false, integrate_test_file);
        } else if (std.mem.eql(u8, "coverage", arg)) {
            try parse_args(args, true, integrate_test_file);
        } else if (std.mem.eql(u8, "negative", arg)) {
            try parse_args(args, false, negative_test_file);
        } else if (std.mem.eql(u8, "negative-coverage", arg)) {
            try parse_args(args, true, negative_test_file);
        } else if (std.mem.eql(u8, "fuzz", arg)) {
            try fuzz_tests();
        } else {
            std.debug.print("invalid command-line argument: {s}\nusage: orng-test (integration | coverage | fuzz)\n", .{arg});
            return error.InvalidCliArgument;
        }
    }
}

/// kcov can't handle child processes for some reason and freezes.
/// When `coverage` is false, integration testing occurs as normal, and child processes are spawned for gcc, executing the executable, etc
/// When `coverage` is true, no child processes are spawned, and no output is given.
const Results = struct { passed: usize, failed: usize };
fn parse_args(old_args: std.process.ArgIterator, coverage: bool, comptime test_file: Test_File_Fn) !void { // TODO: Uninfer error
    var args = old_args;
    if (!coverage) {
        try term_.outputColor(succeed_color, "[============]\n", out);
    }

    var results = Results{ .passed = 0, .failed = 0 };
    ast_.init_structures();
    const prelude = primitives_.get_scope();
    while (args.next()) |next| {
        const res = test_file(next, prelude, coverage);
        if (res) {
            results.passed += 1;
        } else {
            results.failed += 1;
        }
    }

    if (!coverage) {
        try term_.outputColor(succeed_color, "[============]\n", out);
        try out.print("Passed tests: {}\n", .{results.passed});
        try out.print("Failed tests: {}\n", .{results.failed});
        if (results.failed > 0) {
            return error.TestsFailed;
        }
    }
}

fn integrate_test_file(filename: []const u8, prelude: *symbol_.Scope, coverage: bool) bool {
    // FIXME: High Cyclo
    if (filename.len < 4 or !std.mem.eql(u8, filename[filename.len - 4 ..], "orng")) {
        return true;
    }
    const dot_index = index_of(filename, '.') orelse {
        std.debug.print("filename {s} doens't contain a '.'", .{filename});
        return false;
    };
    var test_name = filename[17..dot_index];

    // Output .c file
    var out_name: String = String.init_with_contents(allocator, "tests/integration/build") catch unreachable;
    defer out_name.deinit();
    out_name.concat(test_name) catch unreachable;
    if (!coverage) { // Create output directory if it doesn't exist
        const slash_index = last_index_of(out_name.str(), '/').?;
        _ = exec(&[_][]const u8{ "/bin/mkdir", "-p", out_name.str()[0..slash_index] }) catch {};
    }
    out_name.concat(".c") catch unreachable;

    if (!coverage) {
        term_.outputColor(succeed_color, "[ RUN    ... ] ", out) catch unreachable;
        out.print("{s}.orng\n", .{test_name[1..]}) catch unreachable;
    }

    // Read in the expected value and stdout
    var f = std.fs.cwd().openFile(filename, .{}) catch |err| switch (err) {
        error.FileNotFound => {
            std.debug.print("filename {s} doesn't exist\n", .{filename});
            return false;
        },
        else => return false,
    };
    defer f.close();
    var buf_reader = std.io.bufferedReader(f.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    defer contents_arraylist.deinit();
    in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF) catch unreachable;
    var contents = contents_arraylist.toOwnedSlice() catch unreachable;
    const new_line_idx = until_newline(contents);
    if (new_line_idx < 3) {
        std.debug.print("hey dumby, make it `// ` at least", .{});
    }
    const expected_out = contents[3..new_line_idx];

    // Try to compile Orng (make sure no errors)
    var errors = errs_.Errors.init(allocator);
    defer errors.deinit();
    const module = module_.Module.compile(contents, filename, prelude, false, &errors, allocator) catch |err| {
        if (!coverage) {
            errors.print_errors() catch unreachable;
            term_.outputColor(fail_color, "[ ... FAILED ] ", out) catch unreachable;
            switch (err) {
                error.LexerError,
                error.ParseError,
                error.SymbolError,
                error.TypeError,
                error.IRError,
                error.DivideByZero,
                => out.print("Orng -> C.\n", .{}) catch unreachable,
                else => out.print("Orng Compiler crashed! {}\n", .{err}) catch unreachable,
            }
            std.debug.dumpCurrentStackTrace(128);
        }
        return false;
    };
    // Open the output file
    var output_file = std.fs.cwd().createFile(
        out_name.str(),
        .{ .read = false },
    ) catch |e| switch (e) {
        error.FileNotFound => {
            std.debug.print("Cannot create file: {s}\n", .{out_name.str()});
            return false;
        },
        else => return false,
    };
    defer output_file.close();
    module.output(output_file.writer()) catch unreachable;
    if (coverage) {
        return false;
    }

    // compile C (make sure no errors)
    const gcc_res = exec(&[_][]const u8{
        "/bin/gcc",
        out_name.str(),
        "-std=c11",
        "-lm",
        "-Istd",
        "-O3",
        "-g",
        "-Werror",
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
        "-fsanitize=undefined,address",
    }) catch {
        std.debug.print("Error compiling with GCC", .{});
        return false;
    };
    if (gcc_res.retcode != 0) {
        term_.outputColor(fail_color, "[ ... FAILED ] ", out) catch unreachable;
        out.print("C -> Executable.\n", .{}) catch unreachable;
        return false;
    }

    // execute (make sure no signals)
    const res = exec(&[_][]const u8{"./a.out"}) catch |e| {
        out.print("{?}\n", .{e}) catch unreachable;
        term_.outputColor(fail_color, "[ ... FAILED ] ", out) catch unreachable;
        out.print("Execution interrupted!\n", .{}) catch unreachable;
        return false;
    };
    if (!std.mem.eql(u8, res.stdout, expected_out)) {
        term_.outputColor(fail_color, "[ ... FAILED ] ", out) catch unreachable;
        out.print("Expected \"{s}\" retcode, got \"{s}\"\n", .{ expected_out, res.stdout }) catch unreachable;
        return false;
    }

    // Monitor stdout and capture return value, if these don't match expected as commented in the file, print error
    term_.outputColor(succeed_color, "[ ... PASSED ]\n", out) catch unreachable;
    return true;
}

fn negative_test_file(filename: []const u8, prelude: *symbol_.Scope, coverage: bool) bool {
    // FIXME: High Cyclo
    if (filename.len < 4 or !std.mem.eql(u8, filename[filename.len - 4 ..], "orng")) {
        return true;
    }
    const dot_index = index_of(filename, '.') orelse {
        std.debug.print("filename {s} doens't contain a '.'", .{filename});
        return false;
    };
    const test_name = filename[0..dot_index];
    _ = test_name;

    if (!coverage) {
        term_.outputColor(succeed_color, "[ RUN    ... ] ", out) catch unreachable;
        out.print("{s}\n", .{filename}) catch unreachable;
    }

    // Read in the expected value and stdout
    var f = std.fs.cwd().openFile(filename, .{}) catch |err| switch (err) {
        error.FileNotFound => {
            std.debug.print("filename {s} doesn't exist\n", .{filename});
            return false;
        },
        else => return false,
    };
    defer f.close();
    var buf_reader = std.io.bufferedReader(f.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    defer contents_arraylist.deinit();
    in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF) catch unreachable;
    const contents = contents_arraylist.toOwnedSlice() catch unreachable;

    // Try to compile Orng (make sure no errors)
    var errors = errs_.Errors.init(allocator);
    defer errors.deinit();
    const module = module_.Module.compile(contents, filename, prelude, false, &errors, allocator) catch |err| {
        if (!coverage) {
            switch (err) {
                error.LexerError,
                error.SymbolError,
                error.TypeError,
                error.InterpreterPanic,
                error.IRError,
                error.DivideByZero,
                error.Overflow,
                => {
                    errors.print_errors() catch unreachable;
                    term_.outputColor(succeed_color, "[ ... PASSED ]\n", out) catch unreachable;
                    return true;
                },
                error.ParseError => {
                    var str = String.init_with_contents(allocator, filename) catch unreachable;
                    defer str.deinit();
                    errors.print_errors() catch unreachable;
                    if (str.find("parser") != null) {
                        term_.outputColor(succeed_color, "[ ... PASSED ]\n", out) catch unreachable;
                        return true;
                    } else {
                        std.debug.print("{}\n", .{err});
                        term_.outputColor(fail_color, "[ ... FAILED ] ", out) catch unreachable;
                        out.print("Non-parser negative tests should parse!\n", .{}) catch unreachable;
                        errors.print_errors() catch unreachable;
                        return false;
                    }
                },
                else => {
                    std.debug.print("{}\n", .{err});
                    term_.outputColor(fail_color, "[ ... FAILED ] ", out) catch unreachable;
                    out.print("Orng Compiler crashed unexpectedly!\n", .{}) catch unreachable;
                    std.debug.dumpCurrentStackTrace(128);
                    return false;
                },
            }
        } else {
            return false;
        }
    };

    // Test that codegen doesn't crash
    const negative_out_name = "a.out"; // this is gitignored
    var output_file = std.fs.cwd().createFile(
        negative_out_name,
        .{ .read = false },
    ) catch |e| switch (e) {
        error.FileNotFound => {
            std.debug.print("Cannot create file: {s}\n", .{negative_out_name});
            return false;
        },
        else => return false,
    };
    defer output_file.close();
    module.output(output_file.writer()) catch unreachable;
    if (coverage) {
        return false;
    }

    term_.outputColor(fail_color, "[ ... FAILED ] ", out) catch unreachable;
    out.print("Negative test compiled without error.\n", .{}) catch unreachable;
    return false;
}

/// Uses Dr. Proebsting's rdgen to create random Orng programs, feeds them to the compiler
fn fuzz_tests() !void { // TODO: Uninfer error
    // FIXME: High Cyclo
    // Open and read tests/fuzz/fuzz.txt
    var file = try std.fs.cwd().openFile("tests/fuzz/fuzz.txt", .{});
    defer file.close();

    // Read in the contents of the file
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    defer contents_arraylist.deinit();
    try in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF);
    var contents = try contents_arraylist.toOwnedSlice();

    var passed: usize = 0;
    var failed: usize = 0;
    var i: usize = 0;

    const prelude = primitives_.get_scope();

    // Add lines to arraylist
    var start: usize = index_of(contents, '"').? + 1;
    var end: usize = start + 1;
    var broken: bool = false;
    while (end < contents.len and !broken) : (end += 1) { // TODO: Too long!
        if (contents[end] == '"') {
            defer {
                if (end < contents.len - 4) {
                    start = index_of(contents[end + 1 ..], '"').? + end + 2;
                    end = start;
                } else {
                    broken = true;
                }
            }

            // Found end of string
            const program_text: []const u8 = contents[start..end];

            std.debug.print("{}: {s}\n", .{ i, program_text });
            // Feed to Orng compiler (specifying fuzz tokens) to compile to fuzz-out.c
            var errors = errs_.Errors.init(allocator);
            defer errors.deinit();
            var lines = std.ArrayList([]const u8).init(allocator);
            defer lines.deinit();
            i += 1;
            const module = module_.Module.compile(contents, "fuzz", prelude, false, &errors, allocator) catch |err| {
                try errors.print_errors();
                switch (err) {
                    error.LexerError,
                    error.SymbolError,
                    error.TypeError,
                    error.IRError,
                    error.DivideByZero,
                    => {
                        // passed += 1;
                        // try term_.outputColor(succeed_color, "[ ... PASSED ] ", out);
                        // try out.print("Orng -> IR. {}\n", .{i});
                        continue;
                    },
                    error.ParseError => {
                        failed += 1;
                        try term_.outputColor(fail_color, "[ ... FAILED ] ", out);
                        try out.print("Parsing mismatch! (Remember: you want the parser to be consistent with the EBNF!)\n", .{});
                        return;
                    },
                    else => {
                        failed += 1;
                        try term_.outputColor(fail_color, "[ ... FAILED ] ", out);
                        try out.print("Orng Compiler crashed!\n", .{});
                        return;
                    },
                }
            };
            // Open the output file
            var output_file = std.fs.cwd().createFile(
                "tests/fuzz/fuzz-out.c",
                .{ .read = false },
            ) catch |e| switch (e) {
                error.FileNotFound => {
                    std.debug.print("Cannot create file: {s}\n", .{"tests/fuzz/fuzz-out.c"});
                    return error.IoError;
                },
                else => return error.IoError,
            };
            defer output_file.close();
            module.output(output_file.writer()) catch {
                failed += 1;
                try term_.outputColor(fail_color, "[ ... FAILED ] ", out);
                try out.print("Orng Compiler crashed with input above!\n", .{});
                return;
            };

            var should_continue: bool = false;
            for (errors.errors_list.items) |err| {
                if (err == .expected2token or err == .expected_basic_token or err == .missing_close) {
                    try term_.outputColor(fail_color, "[ ... FAILED ] ", out);
                    try out.print("Orng failed to parse the above correctly!\n", .{});
                    failed += 1;
                    should_continue = true;
                    break;
                }
            }
            if (should_continue) {
                continue;
            }
            try term_.outputColor(succeed_color, "[ ... PASSED ]\n", out);
            passed += 1;
            // return;
        }
    }
    std.debug.print("Fuzz test percentage: {d}% ({} / {})\n", .{ 100.0 * std.math.lossyCast(f64, passed) / std.math.lossyCast(f64, passed + failed), passed, failed });
}

fn exec(argv: []const []const u8) !struct { stdout: []u8, retcode: i64 } { // TODO: Uninfer error
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

// Great std lib function candidate! Holy hell...
fn index_of(str: []const u8, c: u8) ?usize {
    for (0..str.len) |i| {
        if (str[i] == c) {
            return i;
        }
    }
    return null;
}

fn last_index_of(str: []const u8, c: u8) ?usize {
    var i: usize = str.len - 1;
    while (i >= 0) : (i -= 1) {
        if (str[i] == c) {
            return i;
        }
    }
    return null;
}

fn until_newline(str: []const u8) usize {
    var i: usize = 0;
    while (i < str.len and str[i] != '\n') : (i += 1) {}
    return i;
}
