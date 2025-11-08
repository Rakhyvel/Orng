const std = @import("std");
const Compiler_Context = @import("hierarchy/compiler.zig");
const Codegen_Context = @import("codegen/codegen.zig");
const core_ = @import("hierarchy/core.zig");
const exec = @import("util/exec.zig").exec;
const module_ = @import("hierarchy/module.zig");
const prelude_ = @import("hierarchy/prelude.zig");
const Read_File = @import("lexer/read_file.zig");
const String = @import("zig-string/zig-string.zig").String;
const term_ = @import("util/term.zig");

const allocator = std.heap.page_allocator;
const revert = term_.Attr{};
const succeed_color = term_.Attr{ .fg = .green, .bold = true };
const fail_color = term_.Attr{ .fg = .red, .bold = true };
const not_orng_color = term_.Attr{ .fg = .blue, .bold = true };

const Test_Mode = enum { regular, coverage, bless };
const Debug_Allocator = std.heap.DebugAllocator(.{
    .never_unmap = false,
    .safety = true,
    .retain_metadata = true,
    .verbose_log = false,
    .resize_stack_traces = true,
    .enable_memory_limit = true,
});
const Test_File_Fn = fn ([]const u8, Test_Mode, *Debug_Allocator) bool;

// This is for compatability with Windows, since stdout for Windows isn't known at compile-time
fn get_std_out() std.fs.File {
    return std.fs.File.stdout();
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
    var writer_struct = get_std_out().writer(&.{});
    const writer = &writer_struct.interface;
    var args = old_args;
    if (mode == .regular) {
        try term_.outputColor(succeed_color, "[==============]\n", writer);
    }

    var failed_tests = std.array_list.Managed([]const u8).init(std.heap.page_allocator);
    defer failed_tests.deinit();

    var results = Results{ .passed = 0, .failed = 0 };
    while (args.next()) |next| {
        if (next.len < 4 or !std.mem.eql(u8, next[next.len - 4 ..], "orng")) {
            continue;
        }

        var debug_alloc = Debug_Allocator{};
        const test_name = get_test_name(next) orelse continue;
        if (mode == .regular) {
            term_.outputColor(succeed_color, "[ RUN      ... ] ", writer) catch unreachable;
            writer.print("{s}\n", .{test_name}) catch unreachable;
        }

        const res = test_file(next, mode, &debug_alloc);

        const debug_result = debug_alloc.deinit();
        var memory_leak_detected: bool = undefined;
        if (debug_result == .leak) {
            writer.print("compiler error: memory leak!\n", .{}) catch unreachable;
            memory_leak_detected = true;
        } else {
            memory_leak_detected = false;
        }

        if (res and !memory_leak_detected) {
            results.passed += 1;
            if (mode == .regular) {
                term_.outputColor(succeed_color, "[  ... PASSED  ]\n", writer) catch unreachable;
            }
        } else {
            results.failed += 1;
            failed_tests.append(test_name) catch unreachable;
            if (mode == .regular) {
                term_.outputColor(fail_color, "[  ... FAILED  ]\n", writer) catch unreachable;
            }
        }
    }

    if (mode == .regular) {
        try term_.outputColor(succeed_color, "[==============]\n", writer);
        try writer.print("Passed tests: {}\n", .{results.passed});
        try writer.print("Failed tests: {}\n", .{results.failed});

        if (results.failed > 0) {
            try term_.outputColor(fail_color, "[ FAILED TESTS ]\n", writer);
            for (failed_tests.items) |failed_test| {
                try writer.print("{s} ", .{failed_test});
            }
            try term_.outputColor(fail_color, "\n[==============]\n", writer);
            return error.TestsFailed;
        }
    }
}

fn integrate_test_file(filename: []const u8, mode: Test_Mode, debug_alloc: *Debug_Allocator) bool {
    // FIXME: High Cyclo
    const absolute_filename = std.fs.cwd().realpathAlloc(allocator, filename) catch unreachable;
    var writer_struct = get_std_out().writer(&.{});
    const writer = &writer_struct.interface;

    // Try to compile Orange (make sure no errors)
    var compiler = Compiler_Context.init(if (mode != .coverage) get_std_out() else null, debug_alloc.allocator()) catch unreachable;
    defer compiler.deinit();
    defer prelude_.deinit();
    defer core_.deinit();

    const module = module_.Module.load_from_filename(absolute_filename, "main", false, compiler) catch {
        if (mode == .regular) {
            writer.print("Orange -> C.\n", .{}) catch unreachable;
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
    compiler.collect_types();

    const package = compiler.lookup_package(package_abs_path).?;
    package.modified = true; // so that it always re-does stuff
    Codegen_Context.output_modules(compiler) catch unreachable;

    if (mode == .coverage) {
        // kcov can't call gcc, so stop JUST before it calls gcc
        return false;
    }

    const contents = Read_File.init(compiler.allocator()).run(absolute_filename) catch unreachable;
    const header_comment_contents = header_comment(contents, debug_alloc.allocator()) catch unreachable;
    defer debug_alloc.allocator().free(header_comment_contents);
    var expected_out = String.init_with_contents(debug_alloc.allocator(), header_comment_contents[0]) catch unreachable;
    defer expected_out.deinit();
    _ = expected_out.replace("\r", "") catch unreachable;
    _ = expected_out.replace("\n", "") catch unreachable;

    compiler.compile(package_abs_path) catch unreachable;

    // execute (make sure no signals)
    var output_name = String.init_with_contents(allocator, "") catch unreachable;
    var output_name_writer = output_name.writer(output_name.buffer.?);
    const out_name_writer_intfc = &output_name_writer.interface;
    out_name_writer_intfc.print("{s}/build/{s}", .{ package_abs_path, module.package_name }) catch unreachable;
    const res = exec(&[_][]const u8{output_name.str()}, .Pipe) catch |e| {
        writer.print("{}\n", .{e}) catch unreachable;
        writer.print("Execution interrupted!\n", .{}) catch unreachable;
        return false;
    };
    if (!std.mem.eql(u8, res.stdout, expected_out.str())) {
        writer.print("Expected \"{s}\" retcode, got \"{s}\"\n", .{ expected_out.str(), res.stdout }) catch unreachable;
        return false;
    }

    // Monitor stdout and capture return value, if these don't match expected as commented in the file, print error
    return true;
}

fn negative_test_file(filename: []const u8, mode: Test_Mode, debug_alloc: *Debug_Allocator) bool {
    // FIXME: High Cyclo
    var writer_struct = get_std_out().writer(&.{});
    const writer = &writer_struct.interface;

    const absolute_filename = std.fs.cwd().realpathAlloc(allocator, filename) catch unreachable;
    // Try to compile Orange (make sure no errors)
    var compiler = Compiler_Context.init(if (mode != .coverage) get_std_out() else null, debug_alloc.allocator()) catch unreachable;
    defer compiler.deinit();
    defer prelude_.deinit();
    defer core_.deinit();
    const contents = Read_File.init(compiler.allocator()).run(absolute_filename) catch unreachable;
    const head = header_comment(contents, debug_alloc.allocator()) catch unreachable;
    defer debug_alloc.allocator().free(head);
    var flat_head = flatten_header_comment(head, debug_alloc.allocator()) catch unreachable;
    defer flat_head.deinit();
    const body = test_body(contents);

    var error_string = String.init_with_contents(debug_alloc.allocator(), "") catch unreachable;
    defer error_string.deinit();

    // Try to compile Orange (make sure YES errors)
    _ = module_.Module.load_from_filename(absolute_filename, "main", false, compiler) catch |err| {
        var error_string_writer = error_string.writer(error_string.buffer.?);
        const error_string_writer_intfc = &error_string_writer.interface;
        compiler.errors.print_errors(error_string_writer_intfc, .{ .print_full_path = false, .print_color = false });
        if (mode == .bless) {
            bless_file(filename, error_string.str(), body) catch unreachable;
            return true;
        } else if (mode == .regular) {
            // For windows compatability, these don't really matter tbh
            _ = error_string.replace("\r", "") catch unreachable;
            _ = error_string.replace("\n", "") catch unreachable;
            _ = flat_head.replace("\r", "") catch unreachable;
            _ = flat_head.replace("\n", "") catch unreachable;
            const errors_match = std.mem.eql(u8, error_string.str(), flat_head.str());
            switch (err) {
                error.LexerError,
                error.CompileError,
                error.OutOfMemory,
                => {
                    return errors_match;
                },
                error.ParseError, error.FileNotFound => {
                    var str = String.init_with_contents(allocator, filename) catch unreachable;
                    defer str.deinit();
                    if (str.find("parser") != null) {
                        return errors_match;
                    } else {
                        writer.print("Non-parser negative tests should parse!\n", .{}) catch unreachable;
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

    writer.print("Negative test compiled without error.\n", .{}) catch unreachable;
    return false;
}

fn bless_file(filename: []const u8, error_msg: []const u8, body: []const u8) !void {
    var file = try std.fs.cwd().createFile(filename, .{});
    defer file.close();

    var file_contents = String.init_with_contents(std.heap.page_allocator, "") catch unreachable;
    defer file_contents.deinit();

    var writer_struct = file_contents.writer(file_contents.buffer.?);
    const writer = &writer_struct.interface;

    _ = try writer.write("// ");
    for (error_msg) |c| {
        _ = try writer.write(&[1]u8{c});
        if (c == '\n') {
            _ = try writer.write("// ");
        }
    }

    _ = try writer.write(&[1]u8{'\n'});
    _ = try writer.write(body);

    _ = file.write(file_contents.str()) catch unreachable;
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
    var lines = std.array_list.Managed([]const u8).init(alloc);
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
    var line = String.init_with_contents(alloc, "") catch unreachable;
    var line_writer = line.writer(line.buffer.?);
    const writer = &line_writer.interface;
    var i: usize = 0;
    for (lines) |l| {
        try writer.print("{s}", .{l});
        if (i < lines.len -| 1) {
            try writer.print("\n", .{});
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
