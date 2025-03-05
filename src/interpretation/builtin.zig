const std = @import("std");
const compiler_ = @import("../compilation/compiler.zig");
const interpreter_ = @import("../interpretation/interpreter.zig");
const lval_ = @import("../ir/lval.zig");
const primitives_ = @import("../hierarchy/primitives.zig");

const Error: type = error{
    LexerError,
    ParseError,
    CompileError,
    FileNotFound,
};

pub fn module_path() []const u8 {}

/// Implements the Package::find method at build-time. Takes in a string representing the name of
/// the package in the Orng cache, and returns an AST representing the package.
pub fn package_find(compiler: *compiler_.Context, interpreter: *interpreter_.Context, current_module_path: []const u8, package_path: []const u8) Error!struct { package_adrs: i64, package_dirname: []const u8 } {
    // Construct the path to the package's `build.orng` file
    const current_package = std.fs.path.dirname(current_module_path).?;
    const required_package_paths = [_][]const u8{ current_package, package_path };
    const required_package_path = std.fs.path.join(compiler.allocator(), &required_package_paths) catch unreachable;

    const package_buffer = compiler.allocator().alloc(u8, std.fs.MAX_PATH_BYTES) catch unreachable;
    const package_absolute_path = std.fs.cwd().realpath(required_package_path, package_buffer) catch return error.CompileError;

    const package_build_paths = [_][]const u8{ package_absolute_path, "build.orng" };
    const package_build_path = std.fs.path.join(compiler.allocator(), &package_build_paths) catch unreachable;

    const path_buffer = compiler.allocator().alloc(u8, std.fs.MAX_PATH_BYTES) catch unreachable;
    const package_build_absolute_path = std.fs.cwd().realpath(package_build_path, path_buffer) catch return error.CompileError;

    // Compile the package's `build.orng` file
    const build_cfg = try compiler.compile_build_file(package_build_absolute_path);
    interpreter.load_module(build_cfg.symbol.scope.module.?);

    // Allocate space for the package to be placed
    const package_len: usize = @intCast(primitives_.package_type.sizeof());
    const adrs: i64 = @intCast(try interpreter.alloc(@intCast(package_len), 8));
    const retval_place = lval_.L_Value.create_raw_address_lval(adrs, compiler.allocator());

    // Jump to the `build()` fn
    try interpreter.call(build_cfg.symbol, retval_place, std.ArrayList(*lval_.L_Value).init(compiler.allocator()));
    try interpreter.run(compiler);

    return .{ .package_adrs = adrs, .package_dirname = package_absolute_path };
}
