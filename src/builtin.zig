const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const interpreter_ = @import("interpreter.zig");
const primitives_ = @import("primitives.zig");
const module_ = @import("module.zig");
const symbol_ = @import("symbol.zig");

const Command_Error: type = (std.fs.File.WriteError ||
    std.fs.File.ReadError ||
    std.fs.File.OpenError ||
    std.mem.Allocator.Error ||
    module_.Module_Errors ||
    std.posix.RealPathError || // TODO: Fix for Windows
    error{ StreamTooLong, BuildOrngError });

/// Implements the Package::find method at build-time. Takes in a string representing the name of
/// the package in the Orng cache, and returns an AST representing the package.
pub fn package_find(current_module_path: []const u8, package_path: []const u8) Command_Error![]u8 {
    var path_buffer: [std.fs.MAX_PATH_BYTES]u8 = undefined;

    const current_package = std.fs.path.dirname(current_module_path).?;
    const package_build_paths = [_][]const u8{ current_package, package_path, "build.orng" };
    const package_build_dir = std.fs.path.join(std.heap.page_allocator, &package_build_paths) catch unreachable;
    const package_build_file = try std.fs.cwd().realpath(package_build_dir, &path_buffer);
    var build_context = try compile_build_file(package_build_file, std.heap.page_allocator);

    // Extract the retval
    const result = build_context.extract_memory_to_owned(
        0,
        @intCast(primitives_.err_package_type.expand_type(std.heap.page_allocator).sizeof()),
        std.heap.page_allocator,
    );
    return result;
}

pub fn compile_build_file(path: []const u8, allocator: std.mem.Allocator) Command_Error!interpreter_.Context {
    var errors = errs_.Errors.init(allocator);
    defer errors.deinit();

    // MUST init ast before primitives_
    ast_.init_structures();
    const prelude = try primitives_.get_scope();

    const build_module = try compile_module(&errors, path, "build", prelude, false, allocator);

    const cfg = build_module.scope.lookup("build", false).found.cfg.?;

    var build_context = interpreter_.Context.init(cfg, primitives_.int_type, .{ .module_uid = build_module.uid, .inst_idx = cfg.offset.? });
    build_context.load_module(build_module);
    try build_context.interpret();
    return build_context;
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
    var file = try std.fs.openFileAbsolute(in_name, .{});
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
            // Always print these errors for fuzz testing
            error.LexerError,
            error.ParseError,
            => {
                try errors.print_errors();
                return err;
            },

            // Only print these errors if NOT fuzz testing
            error.SymbolError,
            error.TypeError,
            error.IRError,
            => if (!fuzz_tokens) {
                try errors.print_errors();
                return err;
            } else {
                return err;
            },

            // Unknown error
            else => {
                try errors.print_errors();
                return err;
            },
        }
    };
    return module;
}
