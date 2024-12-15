const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const errs_ = @import("errors.zig");
const interpreter_ = @import("interpreter.zig");
const primitives_ = @import("primitives.zig");
const module_ = @import("module.zig");
const symbol_ = @import("symbol.zig");

const Error: type = error{
    LexerError,
    ParseError,
    CompileError,
};

/// Implements the Package::find method at build-time. Takes in a string representing the name of
/// the package in the Orng cache, and returns an AST representing the package.
pub fn package_find(current_module_path: []const u8, package_path: []const u8) Error!struct { mem: []u8, module: *module_.Module } {
    var path_buffer: [std.fs.MAX_PATH_BYTES]u8 = undefined;

    const current_package = std.fs.path.dirname(current_module_path).?;
    const package_build_paths = [_][]const u8{ current_package, package_path, "build.orng" };
    const package_build_dir = std.fs.path.join(std.heap.page_allocator, &package_build_paths) catch unreachable;
    const package_build_file = std.fs.cwd().realpath(package_build_dir, &path_buffer) catch return error.CompileError;
    const build_cfg = try compile_build_file(package_build_file, std.heap.page_allocator);

    var build_context = interpreter_.Context.init();
    build_context.set_entry_point(build_cfg, primitives_.package_type);
    try build_context.interpret();
    defer build_context.deinit();

    // Extract the retval
    const result = build_context.extract_memory_to_owned(
        0,
        @intCast(primitives_.package_type.sizeof()),
        std.heap.page_allocator,
    );
    return .{ .mem = result, .module = build_cfg.symbol.scope.module.? };
}

pub fn compile_build_file(path: []const u8, allocator: std.mem.Allocator) Error!*cfg_.CFG {
    var errors = errs_.Errors.init(allocator);
    defer errors.deinit();

    // MUST init ast before primitives_
    ast_.init_structures();
    const prelude = try primitives_.get_scope();

    const build_module = try compile_module(&errors, path, "build", prelude, false, allocator);

    return build_module.scope.lookup("build", false).found.cfg.?;
}

/// Compiles a module from a file
fn compile_module(
    errors: *errs_.Errors,
    in_name: []const u8,
    entry_name: []const u8,
    prelude: *symbol_.Scope,
    fuzz_tokens: bool,
    allocator: std.mem.Allocator,
) Error!*module_.Module {
    // Open the file
    var file = std.fs.openFileAbsolute(in_name, .{}) catch return error.CompileError;
    defer file.close();

    const stat = file.stat() catch return error.CompileError;
    const uid = stat.mtime;
    _ = uid;

    // Read in the contents of the file
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    defer contents_arraylist.deinit();
    in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF) catch unreachable;
    const contents = contents_arraylist.toOwnedSlice() catch unreachable;

    const module = module_.Module.compile(contents, in_name, entry_name, prelude, fuzz_tokens, errors, allocator) catch |err| {
        switch (err) {
            // Always print these errors for fuzz testing
            error.LexerError,
            error.ParseError,
            => {
                errors.print_errors();
                return err;
            },

            // Only print these errors if NOT fuzz testing
            error.CompileError,
            => if (!fuzz_tokens) {
                errors.print_errors();
                return err;
            } else {
                return err;
            },
        }
    };
    return module;
}
