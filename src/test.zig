const std = @import("std");
const Compiler_Context = @import("hierarchy/compiler.zig");
const Codegen_Context = @import("codegen/codegen.zig");
const exec = @import("util/exec.zig").exec;
const module_ = @import("hierarchy/module.zig");
const primitives_ = @import("hierarchy/primitives.zig");
const Read_File = @import("lexer/read_file.zig");
const String = @import("zig-string/zig-string.zig").String;
const term_ = @import("util/term.zig");

const allocator = std.heap.page_allocator;
const revert = term_.Attr{};
const succeed_color = term_.Attr{ .fg = .green, .bold = true };
const fail_color = term_.Attr{ .fg = .red, .bold = true };
const not_orng_color = term_.Attr{ .fg = .blue, .bold = true };

const Test_Mode = enum { regular, coverage, bless };
const Debug_Allocator = std.heap.DebugAllocator(.{ .never_unmap = true, .safety = true });
const Test_File_Fn = fn ([]const u8, Test_Mode, *Debug_Allocator) bool;

// This is for compatability with Windows, since stdout for Windows isn't known at compile-time
fn get_std_out() std.fs.File.Writer {
    return std.io.getStdOut().writer();
}

pub fn main() !void {
    var args = try std.process.ArgIterator.initWithAllocator(allocator);
    _ = args.next() orelse unreachable;

    _ = std.fs.cwd().realpathAlloc(allocator, ".") catch unreachable;

    var arg: []const u8 = undefined;
    if (args.next()) |_arg| {
        arg = _arg;
        while (std.mem.eql(u8, arg, "--")) {
            arg = args.next().?;
        }
        if (std.mem.eql(u8, "integration", arg)) {
            try parse_args(args, .regular, integrate_test_file);
        } else if (std.mem.eql(u8, "coverage", arg)) {
            try parse_args(args, .coverage, integrate_test_file);
        } else if (std.mem.eql(u8, "negative", arg)) {
            try parse_args(args, .regular, negative_test_file);
        } else if (std.mem.eql(u8, "negative-coverage", arg)) {
            try parse_args(args, .coverage, negative_test_file);
        } else if (std.mem.eql(u8, "bless", arg)) {
            try parse_args(args, .bless, negative_test_file);
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
fn parse_args(old_args: std.process.ArgIterator, mode: Test_Mode, comptime test_file: Test_File_Fn) !void { // TODO: Uninfer error
    var args = old_args;
    if (mode == .regular) {
        try term_.outputColor(succeed_color, "[==============]\n", get_std_out());
    }

    var failed_tests = std.ArrayList([]const u8).init(std.heap.page_allocator);
    defer failed_tests.deinit();

    var results = Results{ .passed = 0, .failed = 0 };
    while (args.next()) |next| {
        if (next.len < 4 or !std.mem.eql(u8, next[next.len - 4 ..], "orng")) {
            continue;
        }

        var debug_alloc = std.heap.DebugAllocator(.{ .never_unmap = true, .safety = true }){};
        const test_name = get_test_name(next) orelse continue;
        if (mode == .regular) {
            term_.outputColor(succeed_color, "[ RUN      ... ] ", get_std_out()) catch unreachable;
            get_std_out().print("{s}\n", .{test_name}) catch unreachable;
        }

        const res = test_file(next, mode, &debug_alloc);

        const debug_result = debug_alloc.deinit();
        var memory_leak_detected: bool = undefined;
        if (debug_result == .leak) {
            get_std_out().print("compiler error: memory leak!\n", .{}) catch unreachable;
            memory_leak_detected = true;
        } else {
            memory_leak_detected = false;
        }

        if (res and !memory_leak_detected) {
            results.passed += 1;
            if (mode == .regular) {
                term_.outputColor(succeed_color, "[  ... PASSED  ]\n", get_std_out()) catch unreachable;
            }
        } else {
            results.failed += 1;
            failed_tests.append(test_name) catch unreachable;
            if (mode == .regular) {
                term_.outputColor(fail_color, "[  ... FAILED  ]\n", get_std_out()) catch unreachable;
            }
        }
    }

    if (mode == .regular) {
        try term_.outputColor(succeed_color, "[==============]\n", get_std_out());
        try get_std_out().print("Passed tests: {}\n", .{results.passed});
        try get_std_out().print("Failed tests: {}\n", .{results.failed});

        if (results.failed > 0) {
            try term_.outputColor(fail_color, "[ FAILED TESTS ]\n", get_std_out());
            for (failed_tests.items) |failed_test| {
                try get_std_out().print("{s} ", .{failed_test});
            }
            try term_.outputColor(fail_color, "\n[==============]\n", get_std_out());
            return error.TestsFailed;
        }
    }
}

fn integrate_test_file(filename: []const u8, mode: Test_Mode, debug_alloc: *Debug_Allocator) bool {
    // FIXME: High Cyclo
    const absolute_filename = std.fs.cwd().realpathAlloc(allocator, filename) catch unreachable;

    // Try to compile Orng (make sure no errors)
    var compiler = Compiler_Context.init(debug_alloc.allocator()) catch unreachable;
    defer compiler.deinit();
    defer primitives_.deinit();

    const module = module_.Module.compile(absolute_filename, "main", false, compiler) catch {
        if (mode == .regular) {
            compiler.errors.print_errors(get_std_out(), .{});
            get_std_out().print("Orng -> C.\n", .{}) catch unreachable;
            std.debug.dumpCurrentStackTrace(128);
        }
        return false;
    };
    const module_symbol = compiler.lookup_module(module.absolute_path).?;

    const package_abs_path = module.get_package_abs_path();
    compiler.register_package(package_abs_path, .executable);
    compiler.set_package_root(package_abs_path, module_symbol);
    compiler.clean_package(package_abs_path);
    compiler.lookup_package(package_abs_path).?.include_directories.put(std.fs.path.dirname(absolute_filename).?, void{}) catch unreachable;

    compiler.propagate_include_directories(package_abs_path);
    compiler.collect_package_local_modules();
    compiler.determine_if_modified(package_abs_path);

    const package = compiler.lookup_package(package_abs_path).?;
    package.modified = true;
    Codegen_Context.output_modules(compiler) catch unreachable;

    if (mode == .coverage) {
        // kcov can't call gcc, so stop JUST before it calls gcc
        return false;
    }

    const contents = Read_File.init(compiler.allocator()).run(absolute_filename) catch unreachable;
    const header_comment_contents = header_comment(contents, debug_alloc.allocator()) catch unreachable;
    defer debug_alloc.allocator().free(header_comment_contents);
    const expected_out = header_comment_contents[0];

    compiler.compile(package_abs_path, false) catch unreachable;

    // execute (make sure no signals)
    var output_name = String.init(allocator);
    output_name.writer().print("{s}/build/{s}", .{ package_abs_path, module.package_name }) catch unreachable;
    const res = exec(&[_][]const u8{output_name.str()}) catch |e| {
        get_std_out().print("{?}\n", .{e}) catch unreachable;
        get_std_out().print("Execution interrupted!\n", .{}) catch unreachable;
        return false;
    };
    if (!std.mem.eql(u8, res.stdout, expected_out)) {
        get_std_out().print("Expected \"{s}\" retcode, got \"{s}\"\n", .{ expected_out, res.stdout }) catch unreachable;
        return false;
    }

    // Monitor stdout and capture return value, if these don't match expected as commented in the file, print error
    return true;
}

fn negative_test_file(filename: []const u8, mode: Test_Mode, debug_alloc: *Debug_Allocator) bool {
    // FIXME: High Cyclo

    const absolute_filename = std.fs.cwd().realpathAlloc(allocator, filename) catch unreachable;
    // Try to compile Orng (make sure no errors)
    var compiler = Compiler_Context.init(debug_alloc.allocator()) catch unreachable;
    defer compiler.deinit();
    defer primitives_.deinit();
    const contents = Read_File.init(compiler.allocator()).run(absolute_filename) catch unreachable;
    const head = header_comment(contents, debug_alloc.allocator()) catch unreachable;
    defer debug_alloc.allocator().free(head);
    var flat_head = flatten_header_comment(head, debug_alloc.allocator()) catch unreachable;
    defer flat_head.deinit();
    const body = test_body(contents);

    var error_string = String.init(debug_alloc.allocator());
    defer error_string.deinit();

    // Try to compile Orng (make sure YES errors)
    _ = module_.Module.compile(absolute_filename, "main", false, compiler) catch |err| {
        compiler.errors.print_errors(error_string.writer(), .{ .print_full_path = false, .print_color = false });
        if (mode == .bless) {
            bless_file(filename, error_string.str(), body) catch unreachable;
            return true;
        } else if (mode == .regular) {
            _ = error_string.replace("\r", "") catch unreachable;
            _ = error_string.replace("\n", "") catch unreachable;
            _ = flat_head.replace("\r", "") catch unreachable;
            _ = flat_head.replace("\n", "") catch unreachable;
            const errors_match = std.mem.eql(u8, error_string.str(), flat_head.str());
            switch (err) {
                error.LexerError,
                error.CompileError,
                => {
                    compiler.errors.print_errors(get_std_out(), .{});
                    return errors_match;
                },
                error.ParseError, error.FileNotFound => {
                    var str = String.init_with_contents(allocator, filename) catch unreachable;
                    defer str.deinit();
                    compiler.errors.print_errors(get_std_out(), .{ .print_full_path = false });
                    if (str.find("parser") != null) {
                        return errors_match;
                    } else {
                        get_std_out().print("Non-parser negative tests should parse!\n", .{}) catch unreachable;
                        compiler.errors.print_errors(get_std_out(), .{});
                        return false;
                    }
                },
            }
        } else {
            return false;
        }
    };

    if (mode == .coverage) {
        return false;
    }

    get_std_out().print("Negative test compiled without error.\n", .{}) catch unreachable;
    return false;
}

fn bless_file(filename: []const u8, error_msg: []const u8, body: []const u8) !void {
    var file = try std.fs.cwd().createFile(filename, .{});
    defer file.close();

    var file_contents = String.init(std.heap.page_allocator);
    defer file_contents.deinit();

    _ = try file_contents.writer().write("// ");
    for (error_msg) |c| {
        _ = try file_contents.writer().write(&[1]u8{c});
        if (c == '\n') {
            _ = try file_contents.writer().write("// ");
        }
    }

    _ = try file_contents.writer().write(&[1]u8{'\n'});
    _ = try file_contents.writer().write(body);

    _ = file.write(file_contents.str()) catch unreachable;
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
            // Feed to Orng compiler (specifying fuzz tokens) to compile to fuzz-get_std_out().c
            var debug_alloc = std.heap.GeneralPurposeAllocator(.{ .never_unmap = false, .safety = true }){};
            var arena_alloc = std.heap.ArenaAllocator.init(debug_alloc.allocator());
            errdefer arena_alloc.deinit();
            var compiler = Compiler_Context.init(arena_alloc.allocator()) catch unreachable;
            defer primitives_.deinit();
            defer compiler.deinit();
            var lines = std.ArrayList([]const u8).init(allocator);
            defer lines.deinit();
            i += 1;
            const module = module_.Module.compile("fuzz", "main", false, compiler) catch |err| {
                compiler.errors.print_errors(get_std_out(), .{});
                switch (err) {
                    error.LexerError,
                    error.CompileError,
                    => continue,

                    error.ParseError, error.FileNotFound => {
                        failed += 1;
                        try term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out());
                        try get_std_out().print("Parsing mismatch! (Remember: you want the parser to be consistent with the EBNF!)\n", .{});
                        return;
                    },
                }
            };
            _ = module; // autofix
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
            // var _local_modules = std.ArrayList(*module_.Module).init(allocator);
            // defer _local_modules.deinit();
            // module.output(&_local_modules, output_file.writer())
            Codegen_Context.output_modules(compiler) catch {
                failed += 1;
                try term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out());
                try get_std_out().print("Orng Compiler crashed with input above!\n", .{});
                return;
            };

            var should_continue: bool = false;
            for (compiler.errors.errors_list.items) |err| {
                if (err == .expected2token or err == .expected_basic_token or err == .missing_close) {
                    try term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out());
                    try get_std_out().print("Orng failed to parse the above correctly!\n", .{});
                    failed += 1;
                    should_continue = true;
                    break;
                }
            }
            if (should_continue) {
                continue;
            }

            try term_.outputColor(succeed_color, "[ ... PASSED ]\n", get_std_out());
            passed += 1;
            // return;
        }
    }
    std.debug.print("Fuzz test percentage: {d}% ({} / {})\n", .{ 100.0 * std.math.lossyCast(f64, passed) / std.math.lossyCast(f64, passed + failed), passed, failed });
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

fn nth_last_index_of(str: []const u8, c: u8, n: usize) ?usize {
    var i: usize = str.len - 1;
    var m = n;
    while (i >= 0) : (i -= 1) {
        if (str[i] == c) {
            if (m == 1) {
                return i;
            } else {
                m -= 1;
            }
        }
    }
    return null;
}

fn get_test_name(filename: []const u8) ?[]const u8 {
    const slash_index = nth_last_index_of(filename, std.fs.path.sep, 2) orelse {
        std.debug.print("filename {s} doens't contain a '/'", .{filename});
        return null;
    };
    return filename[slash_index + 1 ..];
}

/// Given the contents string, returns a slice of strings representing the content of the header comment of a file. User is responsible for deallocating the slice.
fn header_comment(contents: []const u8, alloc: std.mem.Allocator) ![][]const u8 {
    var lines = std.ArrayList([]const u8).init(alloc);
    var cursor: usize = 0;
    var next_newline = until_newline(contents);
    var line: []const u8 = contents[cursor..next_newline];
    while (line.len >= 3 and line[0] == '/' and line[1] == '/' and line[2] == ' ') {
        try lines.append(line[3..]);

        cursor = next_newline + 1;
        next_newline += until_newline(contents[cursor..]) + 1;
        line = contents[cursor..next_newline];
    }

    return lines.toOwnedSlice();
}

fn flatten_header_comment(lines: [][]const u8, alloc: std.mem.Allocator) !String {
    var line = String.init(alloc);
    var i: usize = 0;
    for (lines) |l| {
        try line.writer().print("{s}", .{l});
        if (i < lines.len -| 1) {
            try line.writer().print("\n", .{});
        }
        i += 1;
    }
    return line;
}

/// Retrives the content of a test file after the header comment
fn test_body(contents: []const u8) []const u8 {
    var cursor: usize = 0;
    var next_newline = until_newline(contents);
    var line: []const u8 = contents[cursor..next_newline];
    while (line.len >= 3 and line[0] == '/' and line[1] == '/' and line[2] == ' ') {
        cursor = next_newline + 1;
        next_newline += until_newline(contents[cursor..]) + 1;
        line = contents[cursor..next_newline];
    }
    return contents[cursor..];
}

fn until_newline(str: []const u8) usize {
    var i: usize = 0;
    while (i < str.len and str[i] != '\n') : (i += 1) {}
    return i;
}
