const std = @import("std");
const ast_ = @import("ast.zig");
const builtin_ = @import("builtin.zig");
const compiler_ = @import("compiler.zig");
const errs_ = @import("errors.zig");
const interpreter_ = @import("interpreter.zig");
const module_ = @import("module.zig");
const primitives_ = @import("primitives.zig");
const span_ = @import("span.zig");

const version_year: usize = 25;
const version_month: usize = 1;
const version_minor: ?usize = null;

pub const Command_Error: type = error{ LexerError, ParseError, CompileError, FileError, FileNotFound };

const Command: type = *const fn (name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void;

const Command_Entry: type = struct {
    name: []const u8, // The name of the command
    help: []const u8, // Printed by the help command
    func: Command, // Command to be performed when selected
};

const command_table = [_]Command_Entry{
    Command_Entry{ .name = "build", .help = "Builds an Orng package", .func = build },
    Command_Entry{ .name = "_fuzz_tokens", .help = "Builds an Orng package with fuzz tokens", .func = build },
    Command_Entry{ .name = "help", .help = "Prints this help menu", .func = help },
    Command_Entry{ .name = "version", .help = "Prints the version of Orng", .func = print_version },
    Command_Entry{ .name = "init", .help = "Creates two files, one containing a sample Hello World program and a file to allow for it to be built", .func = init },
};

// Right now, I'll see if it's possible to store the main.orng and build.orng functions as text and write them to a file - dellzer 12/8/24

// Accepts a file as an argument. That file should contain orng constant/type/function declarations, and an entry-point
// Files may also call some built-in compiletime functions which may import other Orng files, C headers, etc...
// Afterwards, the program is collated to a CFG and written to a .c file. A C compiler may be called, and a
pub fn main() !void {
    const allocator = std.heap.page_allocator;

    // Get second command line argument
    var args = std.process.ArgIterator.initWithAllocator(allocator) catch unreachable;
    _ = args.next() orelse unreachable;

    // Parse the command arg
    const command = args.next() orelse {
        try help("help", &args, allocator);
        return;
    };
    for (command_table) |command_entry| {
        if (std.mem.eql(u8, command, command_entry.name)) {
            command_entry.func(command, &args, allocator) catch |err| switch (err) {
                error.LexerError,
                error.ParseError,
                error.CompileError,
                => std.process.exit(1),

                else => return err,
            };
            return;
        }
    }

    try help("help", &args, allocator);
}

fn build(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = args;
    // Get the path
    const build_path_buffer = std.heap.page_allocator.alloc(u8, std.fs.MAX_PATH_BYTES) catch unreachable;
    defer std.heap.page_allocator.free(build_path_buffer);

    const build_path = std.fs.cwd().realpath("build.orng", build_path_buffer) catch |err| switch (err) {
        error.FileNotFound => {
            (errs_.Error{ .basic = .{
                .msg = "no `build.orng` file found in current working directory",
                .span = span_.phony_span,
            } }).fatal_error();
        },
        else => return error.CompileError,
    };

    var compiler = try compiler_.Context.init(allocator);
    defer compiler.deinit();
    const build_cfg = compiler.compile_build_file(build_path) catch return error.CompileError;

    var interpreter = interpreter_.Context.init(compiler.allocator());
    interpreter.set_entry_point(build_cfg, primitives_.package_type.expand_type(compiler.allocator()));
    try interpreter.run(compiler);
    defer interpreter.deinit();

    // Extract the retval
    const package_dag = interpreter.extract_ast(0, primitives_.package_type, allocator);
    const cwd_buffer = compiler.allocator().alloc(u8, std.fs.MAX_PATH_BYTES) catch unreachable;
    const cwd = std.fs.cwd().realpath(".", cwd_buffer) catch unreachable;
    _ = try make_package(package_dag, compiler, &interpreter, cwd, "main");

    // std.fs.cwd().makeDir("build") catch return error.CompileError;
    // compiler.loop_modules();
}

fn make_package(
    package: *ast_.AST,
    compiler: *compiler_.Context,
    interpreter: *interpreter_.Context,
    working_directory: []const u8,
    entry_name: ?[]const u8,
) Command_Error!*module_.Module {
    for (package.children().items[3].children().items) |maybe_requirement_addr| {
        if (maybe_requirement_addr.sum_value._pos != 0) {
            continue;
        }
        const requirement = maybe_requirement_addr.sum_value.init.?;
        const required_package_addr: i64 = @intCast(requirement.children().items[1].int.data);
        // const requirement_name = requirement.children().items[0].string.data; // TODO: Will need this
        const required_package = interpreter.extract_ast(required_package_addr, primitives_.package_type, compiler.allocator());
        const required_package_dir = required_package.children().items[2].string.data;

        const new_working_directory_buffer = compiler.allocator().alloc(u8, std.fs.MAX_PATH_BYTES) catch unreachable;
        const new_working_directory = std.fs.cwd().realpath(required_package_dir, new_working_directory_buffer) catch unreachable;
        _ = try make_package(required_package, compiler, interpreter, new_working_directory, null);
    }

    const root_filename = package.children().items[0].string.data;
    const root_file_paths = [_][]const u8{ working_directory, root_filename };
    const root_file_path = std.fs.path.join(compiler.allocator(), &root_file_paths) catch unreachable;
    return compiler.compile_module(
        root_file_path,
        entry_name,
        false,
    ) catch error.CompileError;
}

fn print_version(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = allocator;
    _ = args;
    const out = std.io.getStdOut().writer();
    out.print("Orng {}.{:0>2}", .{ version_year, version_month }) catch unreachable;
    if (version_minor != null) {
        out.print(".{}", .{version_minor.?}) catch unreachable;
    }
    out.print("\n", .{}) catch unreachable;
}

fn help(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = allocator;
    _ = args;
    const out = std.io.getStdOut().writer();
    out.print("Usage: orng [command] [options]\n\nCommands:\n", .{}) catch unreachable;
    for (command_table) |command_entry| {
        if (command_entry.name[0] == '_') {
            // Skip internal commands
            continue;
        }
        out.print("  {s}", .{command_entry.name}) catch unreachable;
        const num_spaces = 12 - command_entry.name.len;
        for (0..num_spaces) |_| {
            out.print(" ", .{}) catch unreachable;
        }
        out.print("{s}\n", .{command_entry.help}) catch unreachable;
    }
    out.print("\n", .{}) catch unreachable;
}

pub fn init(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = args;
    _ = name;
    _ = allocator; // defining these as _ to silence the compiler

    const main_path = "main.orng";
    if (std.fs.cwd().openFile(main_path, .{})) |_| {
        (errs_.Error{ .basic = .{
            .msg = "an Orng package already exists here",
            .span = span_.phony_span,
        } }).fatal_error();
    } else |err| switch (err) {
        error.FileNotFound => {},
        else => return error.FileError,
    }

    const build_path = "build.orng";
    if (std.fs.cwd().openFile(build_path, .{})) |_| {
        (errs_.Error{ .basic = .{
            .msg = "an Orng package already exists here",
            .span = span_.phony_span,
        } }).fatal_error();
    } else |err| switch (err) {
        error.FileNotFound => {},
        else => return error.FileError,
    }
    var main_orng = std.fs.cwd().createFile(main_path, .{}) catch return error.FileError;
    defer main_orng.close();

    const main_content =
        \\import std::debug
        \\
        \\fn main() -> () {
        \\    debug::println("Hello, World!")
        \\}
    ;
    main_orng.writer().writeAll(main_content) catch return error.FileError;

    var build_orng = std.fs.cwd().createFile(build_path, .{}) catch return error.FileError;
    defer build_orng.close();

    const build_content =
        \\fn build() -> Package {
        \\    Package::executable(.root="main.orng")
        \\}
    ;
    build_orng.writer().writeAll(build_content) catch return error.FileError;
}
