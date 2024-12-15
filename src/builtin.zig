const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const compiler_ = @import("compiler.zig");
const errs_ = @import("errors.zig");
const interpreter_ = @import("interpreter.zig");
const lval_ = @import("lval.zig");
const primitives_ = @import("primitives.zig");
const module_ = @import("module.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");

const Error: type = error{
    LexerError,
    ParseError,
    CompileError,
    FileNotFound,
};

pub fn module_path() []const u8 {}

/// Implements the Package::find method at build-time. Takes in a string representing the name of
/// the package in the Orng cache, and returns an AST representing the package.
pub fn package_find(compiler: *compiler_.Context, interpreter: *interpreter_.Context, current_module_path: []const u8, package_path: []const u8) Error!i64 {
    var path_buffer: [std.fs.MAX_PATH_BYTES]u8 = undefined;

    // Construct the path to the package's `build.orng` file
    const current_package = std.fs.path.dirname(current_module_path).?;
    const package_build_paths = [_][]const u8{ current_package, package_path, "build.orng" };
    const package_build_dir = std.fs.path.join(std.heap.page_allocator, &package_build_paths) catch unreachable;
    const package_build_file = std.fs.cwd().realpath(package_build_dir, &path_buffer) catch return error.CompileError;

    // Compile the package's `build.orng` file
    const build_cfg = try compiler.compile_build_file(package_build_file);
    interpreter.load_module(build_cfg.symbol.scope.module.?);

    // Allocate space for the package to be placed
    const package_len: usize = @intCast(primitives_.package_type.sizeof());
    const adrs: i64 = @intCast(try interpreter.alloc(@intCast(package_len), 8));
    const retval_place = lval_.L_Value.create_raw_address(adrs, std.heap.page_allocator);

    // Call the `build()` fn
    try interpreter.call(build_cfg.symbol, retval_place, std.ArrayList(*lval_.L_Value).init(std.heap.page_allocator));

    return adrs;
}
