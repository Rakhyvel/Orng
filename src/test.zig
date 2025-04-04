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

const Test_File_Fn = fn ([]const u8, bool) bool;

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
        try term_.outputColor(succeed_color, "[============]\n", get_std_out());
    }

    var results = Results{ .passed = 0, .failed = 0 };
    while (args.next()) |next| {
        const res = test_file(next, coverage);
        if (res) {
            results.passed += 1;
        } else {
            results.failed += 1;
        }
    }

    if (!coverage) {
        try term_.outputColor(succeed_color, "[============]\n", get_std_out());
        try get_std_out().print("Passed tests: {}\n", .{results.passed});
        try get_std_out().print("Failed tests: {}\n", .{results.failed});
        if (results.failed > 0) {
            return error.TestsFailed;
        }
    }
}

fn integrate_test_file(filename: []const u8, coverage: bool) bool {
    // FIXME: High Cyclo
    if (filename.len < 4 or !std.mem.eql(u8, filename[filename.len - 4 ..], "orng")) {
        return true;
    }
    const dot_index = index_of(filename, '.') orelse {
        std.debug.print("filename {s} doens't contain a '.'", .{filename});
        return false;
    };
    var test_name = filename[17..dot_index];

    if (!coverage) {
        term_.outputColor(succeed_color, "[ RUN    ... ] ", get_std_out()) catch unreachable;
        get_std_out().print("{s}.orng\n", .{test_name[1..]}) catch unreachable;
    }
    const absolute_filename = std.fs.cwd().realpathAlloc(allocator, filename) catch unreachable;
    // Try to compile Orng (make sure no errors)
    var debug_alloc = std.heap.GeneralPurposeAllocator(.{ .never_unmap = true, .safety = true }){};
    var compiler = Compiler_Context.init(debug_alloc.allocator()) catch unreachable;
    defer primitives_.deinit();
    var contents = Read_File.init(compiler.allocator()).run(absolute_filename) catch unreachable;
    const new_line_idx = until_newline(contents);
    if (new_line_idx < 3) {
        std.debug.print("hey dumby, make it `// ` at least", .{});
    }
    const expected_out = contents[3..new_line_idx];
    const module = module_.Module.compile(absolute_filename, "main", false, compiler) catch {
        if (!coverage) {
            compiler.errors.print_errors();
            term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out()) catch unreachable;
            get_std_out().print("Orng -> C.\n", .{}) catch unreachable;
            std.debug.dumpCurrentStackTrace(128);
        }
        return false;
    };
    const module_symbol = compiler.lookup_module(module.absolute_path).?;

    const package_abs_path = module.get_package_abs_path();
    compiler.register_package(package_abs_path, false);
    compiler.set_package_root(package_abs_path, module_symbol);
    compiler.lookup_package(package_abs_path).?.include_directories.put(std.fs.path.dirname(absolute_filename).?, void{}) catch unreachable;

    compiler.propagate_include_directories(package_abs_path);
    compiler.collect_package_local_modules();
    try compiler.determine_if_modified(package_abs_path);

    const package = compiler.lookup_package(package_abs_path).?;
    package.modified = true;
    Codegen_Context.output_modules(compiler) catch unreachable;

    if (coverage) {
        // kcov can't call gcc, so stop JUST before it calls gcc
        return false;
    }

    compiler.compile(package_abs_path, false) catch unreachable;

    // execute (make sure no signals)
    var output_name = String.init(allocator);
    output_name.writer().print("{s}/build/{s}", .{ package_abs_path, module.package_name }) catch unreachable;
    const res = exec(&[_][]const u8{output_name.str()}) catch |e| {
        get_std_out().print("{?}\n", .{e}) catch unreachable;
        term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out()) catch unreachable;
        get_std_out().print("Execution interrupted!\n", .{}) catch unreachable;
        return false;
    };
    if (!std.mem.eql(u8, res.stdout, expected_out)) {
        term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out()) catch unreachable;
        get_std_out().print("Expected \"{s}\" retcode, got \"{s}\"\n", .{ expected_out, res.stdout }) catch unreachable;
        return false;
    }

    compiler.deinit();
    const debug_result = debug_alloc.deinit();
    if (debug_result == .leak) {
        term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out()) catch unreachable;
        get_std_out().print("compiler error: memory leak!\n", .{}) catch unreachable;
        return false;
    }

    // Monitor stdout and capture return value, if these don't match expected as commented in the file, print error
    term_.outputColor(succeed_color, "[ ... PASSED ]\n", get_std_out()) catch unreachable;
    return true;
}

fn negative_test_file(filename: []const u8, coverage: bool) bool {
    // FIXME: High Cyclo
    if (filename.len < 4 or !std.mem.eql(u8, filename[filename.len - 4 ..], "orng")) {
        return true;
    }
    const dot_index = index_of(filename, '.') orelse {
        std.debug.print("filename {s} doens't contain a '.'", .{filename});
        return false;
    };
    var test_name = filename[14..dot_index];

    // Output .c file
    var out_name: String = String.init_with_contents(allocator, "tests/integration/build") catch unreachable;
    defer out_name.deinit();
    out_name.concat(test_name) catch unreachable;

    if (!coverage) {
        term_.outputColor(succeed_color, "[ RUN    ... ] ", get_std_out()) catch unreachable;
        get_std_out().print("{s}.orng\n", .{test_name[1..]}) catch unreachable;
    }

    const absolute_filename = std.fs.cwd().realpathAlloc(allocator, filename) catch unreachable;
    // Try to compile Orng (make sure no errors)
    var debug_alloc = std.heap.GeneralPurposeAllocator(.{ .never_unmap = false, .safety = true }){};
    var compiler = Compiler_Context.init(debug_alloc.allocator()) catch unreachable;
    defer primitives_.deinit();

    // Try to compile Orng (make sure YES errors)
    _ = module_.Module.compile(absolute_filename, "main", false, compiler) catch |err| {
        if (!coverage) {
            switch (err) {
                error.LexerError,
                error.CompileError,
                => {
                    compiler.errors.print_errors();
                    term_.outputColor(succeed_color, "[ ... PASSED ]\n", get_std_out()) catch unreachable;
                    return true;
                },
                error.ParseError, error.FileNotFound => {
                    var str = String.init_with_contents(allocator, filename) catch unreachable;
                    defer str.deinit();
                    compiler.errors.print_errors();
                    if (str.find("parser") != null) {
                        term_.outputColor(succeed_color, "[ ... PASSED ]\n", get_std_out()) catch unreachable;
                        return true;
                    } else {
                        term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out()) catch unreachable;
                        get_std_out().print("Non-parser negative tests should parse!\n", .{}) catch unreachable;
                        compiler.errors.print_errors();
                        return false;
                    }
                },
            }
        } else {
            return false;
        }
    };
    compiler.deinit();

    if (coverage) {
        return false;
    }

    term_.outputColor(fail_color, "[ ... FAILED ] ", get_std_out()) catch unreachable;
    get_std_out().print("Negative test compiled without error.\n", .{}) catch unreachable;
    unreachable;
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
                compiler.errors.print_errors();
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

fn until_newline(str: []const u8) usize {
    var i: usize = 0;
    while (i < str.len and str[i] != '\n' and str[i] != '\r') : (i += 1) {}
    return i;
}
