const std = @import("std");
const ast_ = @import("ast/ast.zig");
const core_ = @import("hierarchy/core.zig");
const Compiler_Context = @import("hierarchy/compiler.zig");
const Codegen_Context = @import("codegen/codegen.zig");
const errs_ = @import("util/errors.zig");
const Interpreter_Context = @import("interpretation/interpreter.zig");
const Package_Kind = @import("hierarchy/package.zig").Package_Kind;
const Span = @import("util/span.zig");
const Symbol = @import("symbol/symbol.zig");

const version_year: usize = 25;
const version_month: usize = 11;
const version_minor: ?usize = null;

pub const Command_Error: type = error{ LexerError, ParseError, CompileError, FileError, FileNotFound, OutOfMemory };

const Command: type = *const fn (name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void;

const Command_Entry: type = struct {
    name: []const u8, // The name of the command
    help: []const u8, // Printed by the help command
    func: Command, // Command to be performed when selected
};

// Keep these in alphabetical order
const command_table = [_]Command_Entry{
    Command_Entry{ .name = "build", .help = "Builds an Orange package", .func = build },
    Command_Entry{ .name = "clean", .help = "Clears the build cache, and forces a complete rebuild of the Orange package", .func = clean },
    Command_Entry{ .name = "_fuzz_tokens", .help = "Builds an Orange package with fuzz tokens", .func = build },
    Command_Entry{ .name = "help", .help = "Prints this help menu", .func = help },
    Command_Entry{ .name = "init", .help = "Creates two files, one containing a sample Hello World program and a file to allow for it to be built", .func = init_project },
    Command_Entry{ .name = "run", .help = "Builds and runs an Orange package", .func = build },
    Command_Entry{ .name = "test", .help = "Builds and runs any tests in the current Orange package", .func = @"test" },
    Command_Entry{ .name = "version", .help = "Prints the version of Orange", .func = print_version },
};

// Accepts a file as an argument. That file should contain Orange constant/type/function declarations, and an entry-point
// Files may also call some built-in compiletime functions which may import other Orange files, C headers, etc...
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
    _ = args;
    var compiler = try Compiler_Context.init(errs_.get_std_err(), allocator);
    defer compiler.deinit();
    const package_abs_path = try construct_package_dag(compiler);
    compiler.propagate_include_directories(package_abs_path);
    compiler.collect_package_local_modules();
    compiler.determine_if_modified(package_abs_path);
    compiler.collect_types();
    try Codegen_Context.output_modules(compiler);
    try compiler.compile(package_abs_path);

    if (std.mem.eql(u8, name, "run")) {
        try run(compiler, package_abs_path, allocator);
    }
}

/// Compiles and interprets the `build.orng` file, and returns the Directed-Acyclic-Graph Package AST, which stores
/// info for how to build the package
fn run_build_orng(compiler: *Compiler_Context, interpreter: *Interpreter_Context, build_path: []const u8) !*ast_.AST {
    const build_cfg = compiler.compile_build_file(build_path) catch return error.CompileError;
    interpreter.set_entry_point(build_cfg, core_.package_type.expand_identifier());
    try interpreter.run();
    return try interpreter.extract_ast(0, core_.package_type, Span.phony);
}

/// Runs the package executable after it's built
fn run(compiler: *Compiler_Context, package_abs_path: []const u8, allocator: std.mem.Allocator) !void {
    const curr_package = compiler.lookup_package(package_abs_path).?;
    if (curr_package.kind == .static_library) {
        var stderr_writer = errs_.get_std_err().writer(&.{}).interface;
        (errs_.Error{ .basic = .{
            .msg = "cannot run a non-executable package",
            .span = Span.phony,
        } }).fatal_error(&stderr_writer, .{});
        return error.CompileError;
    }

    var output_name = std.array_list.Managed(u8).init(allocator);
    output_name.print("{s}", .{curr_package.output_absolute_path}) catch unreachable;
    const argv = &[_][]const u8{output_name.items};
    var child = std.process.Child.init(argv, allocator);
    child.stdin_behavior = .Inherit;
    child.stdout_behavior = .Inherit;
    child.stderr_behavior = .Inherit;

    child.spawn() catch return error.CompileError;
}

fn @"test"(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = args;

    var compiler = try Compiler_Context.init(errs_.get_std_err(), allocator);
    defer compiler.deinit();
    const package_abs_path = try construct_package_dag(compiler);
    compiler.set_package_kind(package_abs_path, .test_executable);
    compiler.propagate_include_directories(package_abs_path);
    compiler.collect_package_local_modules();
    compiler.determine_if_modified(package_abs_path);
    compiler.collect_types();
    try Codegen_Context.output_modules(compiler);
    try compiler.compile(package_abs_path);

    try run(compiler, package_abs_path, allocator);
}

fn validate_env_vars(allocator: std.mem.Allocator) Command_Error!void {
    var env_map = std.process.getEnvMap(allocator) catch unreachable;
    defer env_map.deinit();

    const build_path_buffer = std.heap.page_allocator.alloc(u8, std.fs.max_path_bytes) catch unreachable;
    defer std.heap.page_allocator.free(build_path_buffer);

    const env_var_res = env_map.get("ORNG_STD_PATH");
    if (env_var_res == null) {
        (errs_.Error{
            .basic = .{
                .msg = "an environment variable is not defined",
                .span = Span.phony,
            },
        }).fatal_error();
        return error.CompileError;
    }
    var dir = std.fs.Dir.openDir(std.fs.cwd(), env_var_res.?, .{}) catch |err| switch (err) {
        error.FileNotFound => {
            (errs_.Error{ .basic = .{
                .msg = "the path specified by an environment variable does not exist",
                .span = Span.phony,
            } }).fatal_error();
            return error.CompileError;
        },
        error.NotDir => {
            (errs_.Error{ .basic = .{
                .msg = "the path specified by an environment variable does not refer to a directory",
                .span = Span.phony,
            } }).fatal_error();
            return error.CompileError;
        },
        else => {
            std.debug.print("an unexpected error occurred when trying to stat an environment variable: {}\n", .{err});
            return error.CompileError;
        },
    };
    dir.close();
}

fn make_package(
    package: *ast_.AST,
    compiler: *Compiler_Context,
    interpreter: *Interpreter_Context,
    package_absolute_path: []const u8,
    entry_name: ?[]const u8,
) Command_Error!*Symbol {
    var package_kind: Package_Kind = undefined;
    switch (package.get_field(core_.package_type, "kind").pos().?) {
        0 => package_kind = .executable,
        1 => package_kind = .static_library,
        else => std.debug.panic("unimplemented", .{}),
    }
    compiler.register_package(package_absolute_path, package_kind);

    for (package.get_field(core_.package_type, "requirements").children().items) |maybe_requirement_addr| {
        if (maybe_requirement_addr.enum_value._pos != 0) {
            continue;
        }
        const requirement = maybe_requirement_addr.enum_value.init.?;
        const required_package_name: []const u8 = requirement.children().items[0].string.data;
        const required_package_addr: i64 = @intCast(requirement.children().items[1].int.data);
        const required_package = try interpreter.extract_ast(required_package_addr, core_.package_type, Span.phony);
        const required_package_dir = required_package.get_field(core_.package_type, "dir").string.data;

        const new_working_directory_buffer = compiler.allocator().alloc(u8, std.fs.max_path_bytes) catch unreachable;
        const new_working_directory = std.fs.cwd().realpath(required_package_dir, new_working_directory_buffer) catch unreachable;
        _ = try make_package(required_package, compiler, interpreter, new_working_directory, null);

        compiler.make_package_requirement_link(package_absolute_path, required_package_name, required_package_dir);
    }

    set_package_include_dirs(package, compiler, package_absolute_path);
    set_package_lib_dirs(package, compiler, package_absolute_path);
    set_package_libs(package, compiler, package_absolute_path);

    const root_filename = package.get_field(core_.package_type, "root").string.data;
    const root_file_paths = [_][]const u8{ package_absolute_path, root_filename };
    const root_file_path = std.fs.path.join(compiler.allocator(), &root_file_paths) catch unreachable;

    const package_root = compiler.compile_module(
        root_file_path,
        entry_name,
        false,
    ) catch return error.CompileError;
    compiler.set_package_root(package_absolute_path, package_root);

    return package_root;
}

/// Adds the specified include directories from the Package AST to the package structure
fn set_package_include_dirs(
    package: *ast_.AST,
    compiler: *Compiler_Context,
    package_absolute_path: []const u8,
) void {
    for (package.get_field(core_.package_type, "include_dirs").children().items) |maybe_include_dir_addr| {
        if (maybe_include_dir_addr.enum_value._pos != 0) {
            continue;
        }
        const include_dir = maybe_include_dir_addr.enum_value.init.?;
        compiler.lookup_package(package_absolute_path).?.include_directories.put(include_dir.string.data, void{}) catch unreachable;
    }
}

/// Adds the specified library directories from the Package AST to the package structure
fn set_package_lib_dirs(
    package: *ast_.AST,
    compiler: *Compiler_Context,
    package_absolute_path: []const u8,
) void {
    for (package.get_field(core_.package_type, "lib_dirs").children().items) |maybe_lib_dir_addr| {
        if (maybe_lib_dir_addr.enum_value._pos != 0) {
            continue;
        }
        const include_dir = maybe_lib_dir_addr.enum_value.init.?;
        compiler.lookup_package(package_absolute_path).?.library_directories.put(include_dir.string.data, void{}) catch unreachable;
    }
}

/// Adds the specified libraries from the Package AST to the package structure
fn set_package_libs(
    package: *ast_.AST,
    compiler: *Compiler_Context,
    package_absolute_path: []const u8,
) void {
    for (package.get_field(core_.package_type, "libs").children().items) |maybe_lib_addr| {
        if (maybe_lib_addr.enum_value._pos != 0) {
            continue;
        }
        const include_dir = maybe_lib_addr.enum_value.init.?;
        compiler.lookup_package(package_absolute_path).?.libraries.put(include_dir.string.data, void{}) catch unreachable;
    }
}

fn print_version(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = allocator;
    _ = args;
    const out = std.fs.File.stdout();
    var writer = out.writer(&.{}).interface;
    writer.print("Orange {}.{:0>2}", .{ version_year, version_month }) catch unreachable;
    if (version_minor != null) {
        writer.print(".{}", .{version_minor.?}) catch unreachable;
    }
    writer.print("\n", .{}) catch unreachable;
}

fn help(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = allocator;
    _ = args;
    var out = std.fs.File.stdout();
    var writer = out.writer(&.{}).interface;
    writer.print("Usage: orng [command] [options]\n\nCommands:\n", .{}) catch unreachable;
    for (command_table) |command_entry| {
        if (command_entry.name[0] == '_') {
            // Skip internal commands
            continue;
        }
        writer.print("  {s}", .{command_entry.name}) catch unreachable;
        const num_spaces = 12 - command_entry.name.len;
        for (0..num_spaces) |_| {
            writer.print(" ", .{}) catch unreachable;
        }
        writer.print("{s}\n", .{command_entry.help}) catch unreachable;
    }
    writer.print("\n", .{}) catch unreachable;
}

pub fn init_project(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = args;
    _ = name;
    _ = allocator; // defining these as _ to silence the compiler

    var stderr_writer = errs_.get_std_err().writer(&.{}).interface;

    const main_path = "main.orng";
    if (std.fs.cwd().openFile(main_path, .{})) |_| {
        (errs_.Error{ .basic = .{
            .msg = "an Orange package already exists here",
            .span = Span.phony,
        } }).fatal_error(&stderr_writer, .{});
    } else |err| switch (err) {
        error.FileNotFound => {},
        else => return error.FileError,
    }

    const build_path = "build.orng";
    if (std.fs.cwd().openFile(build_path, .{})) |_| {
        (errs_.Error{ .basic = .{
            .msg = "an Orange package already exists here",
            .span = Span.phony,
        } }).fatal_error(&stderr_writer, .{});
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
    var main_orng_writer = main_orng.writer(&.{}).interface;
    main_orng_writer.writeAll(main_content) catch return error.FileError;

    var build_orng = std.fs.cwd().createFile(build_path, .{}) catch return error.FileError;
    defer build_orng.close();

    const build_content =
        \\fn build() -> Package {
        \\    let mut retval = Package::executable(.root="main.orng")
        \\    retval.>requires("std", Package::find("std"))
        \\    retval
        \\}
    ;
    var build_orng_writer = build_orng.writer(&.{}).interface;
    build_orng_writer.writeAll(build_content) catch return error.FileError;
}

fn clean(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = args;

    // TODO: Find the package's `build/` and just delete it
    var compiler = try Compiler_Context.init(errs_.get_std_err(), allocator);
    defer compiler.deinit();
    const package_abs_path = try construct_package_dag(compiler);
    compiler.clean_package(package_abs_path);
}

fn construct_package_dag(compiler: *Compiler_Context) Command_Error![]const u8 {
    // try validate_env_vars(allocator);
    const build_path_buffer = std.heap.page_allocator.alloc(u8, std.fs.max_path_bytes) catch unreachable;

    var stderr_writer = errs_.get_std_err().writer(&.{}).interface;
    const build_path: []const u8 = std.fs.cwd().realpath("build.orng", build_path_buffer) catch |err| switch (err) {
        error.FileNotFound => {
            (errs_.Error{ .basic = .{
                .msg = "no `build.orng` file found in current working directory",
                .span = Span.phony,
            } }).fatal_error(&stderr_writer, .{});
        },
        else => return error.CompileError,
    };

    var interpreter = Interpreter_Context.init(compiler);
    defer interpreter.deinit();

    const package_dag = try run_build_orng(compiler, &interpreter, build_path);

    const cwd_buffer = compiler.allocator().alloc(u8, std.fs.max_path_bytes) catch unreachable;
    const package_abs_path = std.fs.cwd().realpath(".", cwd_buffer) catch unreachable;
    _ = try make_package(package_dag, compiler, &interpreter, package_abs_path, "main");

    return package_abs_path;
}
