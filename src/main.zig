const std = @import("std");
const ast_ = @import("ast/ast.zig");
const compiler_ = @import("compilation/compiler.zig");
const errs_ = @import("util/errors.zig");
const interpreter_ = @import("interpretation/interpreter.zig");
const module_ = @import("hierarchy/module.zig");
const primitives_ = @import("hierarchy/primitives.zig");
const span_ = @import("util/span.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol/symbol.zig");

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

// Keep these in alphabetical order
const command_table = [_]Command_Entry{
    Command_Entry{ .name = "build", .help = "Builds an Orng package", .func = build },
    Command_Entry{ .name = "_fuzz_tokens", .help = "Builds an Orng package with fuzz tokens", .func = build },
    Command_Entry{ .name = "help", .help = "Prints this help menu", .func = help },
    Command_Entry{ .name = "init", .help = "Creates two files, one containing a sample Hello World program and a file to allow for it to be built", .func = init },
    Command_Entry{ .name = "run", .help = "Builds and runs an Orng package", .func = build },
    Command_Entry{ .name = "version", .help = "Prints the version of Orng", .func = print_version },
};

// Accepts a file as an argument. That file should contain orng constant/type/function declarations, and an entry-point
// Files may also call some built-in compiletime functions which may import other Orng files, C headers, etc...
// Afterwards, the program is collated to a CFG and written to a .c file. A C compiler may be called, and a
pub fn main() !void {
    const allocator = std.heap.page_allocator;

    // Get second command line argument
    var args = std.process.ArgIterator.initWithAllocator(allocator) catch unreachable;
    const location = args.next() orelse unreachable;
    _ = location; // autofix

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
    try validate_env_vars(allocator);

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

    var interpreter = interpreter_.Context.init(&compiler.errors, compiler.allocator());
    interpreter.set_entry_point(build_cfg, primitives_.package_type.expand_type(compiler.allocator()));
    try interpreter.run(compiler);
    defer interpreter.deinit();

    // Extract the retval
    const package_dag = try interpreter.extract_ast(0, primitives_.package_type, span_.phony_span);
    const cwd_buffer = compiler.allocator().alloc(u8, std.fs.MAX_PATH_BYTES) catch unreachable;
    const cwd = std.fs.cwd().realpath(".", cwd_buffer) catch unreachable;
    const package_name = std.fs.path.basename(cwd);
    _ = try make_package(package_dag, package_name, compiler, &interpreter, cwd, "main");

    try compiler.output_modules();

    compiler.propagate_include_directories(package_name);
    try compiler.compile_c(package_name, false);

    std.debug.print("done\n", .{});

    if (std.mem.eql(u8, name, "run")) {
        const curr_package = compiler.lookup_package(package_name).?;
        if (curr_package.is_static_lib) {
            (errs_.Error{ .basic = .{
                .msg = "cannot run a non-executable package",
                .span = span_.phony_span,
            } }).fatal_error();
            return error.CompileError;
        }

        var output_name = String.init(allocator);
        output_name.writer().print("{s}", .{curr_package.output_absolute_path}) catch unreachable;
        const argv = &[_][]const u8{output_name.str()};
        var child = std.process.Child.init(argv, allocator);
        child.stdin_behavior = .Inherit;
        child.stdout_behavior = .Inherit;
        child.stderr_behavior = .Inherit;

        child.spawn() catch return error.CompileError;
        const term = child.wait() catch return error.CompileError;
        std.debug.print("exited: {}", .{term.Exited});
    }
}

fn validate_env_vars(allocator: std.mem.Allocator) Command_Error!void {
    var env_map = std.process.getEnvMap(allocator) catch unreachable;
    defer env_map.deinit();

    const build_path_buffer = std.heap.page_allocator.alloc(u8, std.fs.MAX_PATH_BYTES) catch unreachable;
    defer std.heap.page_allocator.free(build_path_buffer);

    const env_var_res = env_map.get("ORNG_STD_PATH");
    if (env_var_res == null) {
        (errs_.Error{
            .basic = .{
                .msg = "an environment variable is not defined",
                .span = span_.phony_span,
            },
        }).fatal_error();
        return error.CompileError;
    }
    _ = std.fs.Dir.openDir(std.fs.cwd(), env_var_res.?, .{}) catch |err| switch (err) {
        error.FileNotFound => {
            (errs_.Error{ .basic = .{
                .msg = "the path specified by an environment variable does not exist",
                .span = span_.phony_span,
            } }).fatal_error();
            return error.CompileError;
        },
        error.NotDir => {
            (errs_.Error{ .basic = .{
                .msg = "the path specified by an environment variable does not refer to a directory",
                .span = span_.phony_span,
            } }).fatal_error();
            return error.CompileError;
        },
        else => {
            std.debug.print("an unexpected error occurred when trying to stat an environment variable: {}\n", .{err});
            return error.CompileError;
        },
    };
}

fn make_package(
    package: *ast_.AST,
    package_name: []const u8,
    compiler: *compiler_.Context,
    interpreter: *interpreter_.Context,
    working_directory: []const u8,
    entry_name: ?[]const u8,
) Command_Error!*symbol_.Symbol {
    const is_static_lib = package.get_field(primitives_.package_type, "kind").pos() == 1;
    compiler.register_package(package_name, working_directory, is_static_lib);

    for (package.get_field(primitives_.package_type, "requirements").children().items) |maybe_requirement_addr| {
        if (maybe_requirement_addr.sum_value._pos != 0) {
            continue;
        }
        const requirement = maybe_requirement_addr.sum_value.init.?;
        const required_package_name: []const u8 = requirement.children().items[0].string.data;
        const required_package_addr: i64 = @intCast(requirement.children().items[1].int.data);
        const requirement_name = requirement.get_field(primitives_.package_type, "root").string.data;
        const required_package = try interpreter.extract_ast(required_package_addr, primitives_.package_type, span_.phony_span);
        const required_package_dir = required_package.get_field(primitives_.package_type, "dir").string.data;

        const new_working_directory_buffer = compiler.allocator().alloc(u8, std.fs.MAX_PATH_BYTES) catch unreachable;
        const new_working_directory = std.fs.cwd().realpath(required_package_dir, new_working_directory_buffer) catch unreachable;
        _ = try make_package(required_package, required_package_name, compiler, interpreter, new_working_directory, null);

        compiler.make_package_requirement_link(package_name, requirement_name);
    }

    for (package.get_field(primitives_.package_type, "include_dirs").children().items) |maybe_include_dir_addr| {
        if (maybe_include_dir_addr.sum_value._pos != 0) {
            continue;
        }
        const include_dir = maybe_include_dir_addr.sum_value.init.?;
        compiler.lookup_package(package_name).?.include_directories.put(include_dir.string.data, void{}) catch unreachable;
    }

    for (package.get_field(primitives_.package_type, "lib_dirs").children().items) |maybe_lib_dir_addr| {
        if (maybe_lib_dir_addr.sum_value._pos != 0) {
            continue;
        }
        const include_dir = maybe_lib_dir_addr.sum_value.init.?;
        compiler.lookup_package(package_name).?.library_directories.put(include_dir.string.data, void{}) catch unreachable;
    }

    for (package.get_field(primitives_.package_type, "libs").children().items) |maybe_lib_addr| {
        if (maybe_lib_addr.sum_value._pos != 0) {
            continue;
        }
        const include_dir = maybe_lib_addr.sum_value.init.?;
        compiler.lookup_package(package_name).?.libraries.put(include_dir.string.data, void{}) catch unreachable;
    }

    const root_filename = package.get_field(primitives_.package_type, "root").string.data;
    const root_file_paths = [_][]const u8{ working_directory, root_filename };
    const root_file_path = std.fs.path.join(compiler.allocator(), &root_file_paths) catch unreachable;

    const package_root = compiler.compile_module(
        root_file_path,
        entry_name,
        false,
    ) catch return error.CompileError;
    compiler.set_package_root(package_name, package_root);

    return package_root;
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
        \\    let mut retval = Package::executable(.root="main.orng")
        \\    retval.>requires("std", Package::find("std"))
        \\    retval
        \\}
    ;
    build_orng.writer().writeAll(build_content) catch return error.FileError;
}
