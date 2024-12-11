const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const errs_ = @import("errors.zig");
const interpreter_ = @import("interpreter.zig");
const primitives_ = @import("primitives.zig");
const module_ = @import("module.zig");
const symbol_ = @import("symbol.zig");

const version_year: usize = 25;
const version_month: usize = 1;
const version_minor: ?usize = null;

const Command_Error: type = (std.fs.File.WriteError ||
    std.fs.File.ReadError ||
    std.fs.File.OpenError ||
    std.mem.Allocator.Error ||
    module_.Module_Errors ||
    std.posix.RealPathError || // TODO: Fix for Windows
    error{ StreamTooLong, BuildOrngError });

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
    var args = try std.process.ArgIterator.initWithAllocator(allocator);
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
                error.NotCompileTimeKnown,
                error.InvalidCharacter,
                error.Overflow,
                error.SymbolError,
                error.TypeError,
                error.IRError,
                error.DivideByZero,
                error.NotAnLValue,
                error.InterpreterPanic,
                error.BuildOrngError,
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
    var path_buffer: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    // const path: []u8 = try std.fs.realpath(args.next().?, &path_buffer);
    const path = std.fs.cwd().realpath("build.orng", &path_buffer) catch |err| switch (err) {
        error.FileNotFound => {
            // TODO: This should be printed out in bold and red
            try std.io.getStdOut().writer().print("error: no `build.orng` file found in current working directory\n", .{});
            return error.BuildOrngError;
        },
        else => return err,
    };

    var errors = errs_.Errors.init(allocator);
    defer errors.deinit();

    // MUST init ast before primitives_
    ast_.init_structures();
    const prelude = try primitives_.get_scope();

    // var program = program_.init(); // initializes prelude module, has a common instructions list
    // program.compile_module(&errors, path, "build", false, allocator);

    const build_module = try compile_module(&errors, path, "build", prelude, false, allocator);

    const cfg = build_module.scope.lookup("build", false).found.cfg.?;

    var build_context = interpreter_.Context.init(cfg, primitives_.int_type, .{ .module_uid = build_module.uid, .inst_idx = cfg.offset.? });
    build_context.load_module(build_module);
    try build_context.interpret();

    // Extract the retval
    const result = build_context.extract_ast(0, primitives_.package_type, allocator);
    std.debug.print("root: {s}\n", .{result.children().items[0].string.data});

    // const fuzz_tokens = std.mem.eql(u8, name, "_fuzz_tokens"); // TODO: Re-add fuzz tokens
}

fn print_version(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = allocator;
    _ = args;
    try std.io.getStdOut().writer().print("Orng {}.{:0>2}", .{ version_year, version_month });
    if (version_minor != null) {
        try std.io.getStdOut().writer().print(".{}", .{version_minor.?});
    }
    try std.io.getStdOut().writer().print("\n", .{});
}

fn help(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) Command_Error!void {
    _ = name;
    _ = allocator;
    _ = args;
    try std.io.getStdOut().writer().print("Usage: orng [command] [options]\n\nCommands:\n", .{});
    for (command_table) |command_entry| {
        if (command_entry.name[0] == '_') {
            // Skip internal commands
            continue;
        }
        try std.io.getStdOut().writer().print("  {s}", .{command_entry.name});
        const num_spaces = 12 - command_entry.name.len;
        for (0..num_spaces) |_| {
            try std.io.getStdOut().writer().print(" ", .{});
        }
        try std.io.getStdOut().writer().print("{s}\n", .{command_entry.help});
    }
    try std.io.getStdOut().writer().print("\n", .{});
}

pub fn init(name: []const u8, args: *std.process.ArgIterator, allocator: std.mem.Allocator) !void {
    _ = args;
    _ = name;
    _ = allocator; // defining these as _ to silence the compiler

    const main_path = "main.orng";
    if (std.fs.cwd().openFile(main_path, .{})) |_| {
        std.log.err("the file `{s}` already exists", .{main_path});
        return error.BuildOrngError;
    } else |err| switch (err) {
        error.FileNotFound => {},
        else => return err,
    }

    const build_path = "build.orng";
    if (std.fs.cwd().openFile(build_path, .{})) |_| {
        std.log.err("the file `{s}` already exists", .{build_path});
        return error.BuildOrngError;
    } else |err| switch (err) {
        error.FileNotFound => {},
        else => return err,
    }
    var main_orng = try std.fs.cwd().createFile(main_path, .{});
    defer main_orng.close();

    const main_content =
        \\import std::debug
        \\
        \\fn main() -> () {
        \\    debug::println("Hello, World!")
        \\}
    ;
    try main_orng.writer().writeAll(main_content);

    var build_orng = try std.fs.cwd().createFile(build_path, .{});
    defer build_orng.close();

    const build_content =
        \\fn build() -> Package {
        \\    Package::executable(.root="main.orng")
        \\}
    ;
    try build_orng.writer().writeAll(build_content);
}

/// Compiles a module from a file
fn compile_module(
    errors: *errs_.Errors,
    in_name: []const u8,
    entry_name: []const u8,
    prelude: *symbol_.Scope,
    fuzz_tokens: bool,
    allocator: std.mem.Allocator,
) Command_Error!*module_.Module {
    // Open the file
    var file = try std.fs.cwd().openFile(in_name, .{});
    defer file.close();

    const stat = try file.stat();
    const uid = stat.mtime;
    _ = uid;

    // Read in the contents of the file
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    defer contents_arraylist.deinit();
    try in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF);
    const contents = try contents_arraylist.toOwnedSlice();

    const module = module_.Module.compile(contents, in_name, entry_name, prelude, fuzz_tokens, errors, allocator) catch |err| {
        switch (err) {
            error.LexerError,
            error.ParseError,
            => {
                try errors.print_errors();
                return err;
            },
            error.SymbolError,
            error.TypeError,
            => if (!fuzz_tokens) {
                try errors.print_errors();
                return err;
            } else {
                return err;
            },
            else => return err,
        }
    };
    return module;
}
