const std = @import("std");
const AST = @import("../ast/ast.zig").AST;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Interpreter_Context = @import("../interpretation/interpreter.zig");
const lval_ = @import("../ir/lval.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const repo_ = @import("../util/repo.zig");
const String = @import("../zig-string/zig-string.zig").String;

const Error: type = error{
    LexerError,
    ParseError,
    CompileError,
    FileNotFound,
};

/// Implements the Package::find method at build-time. Takes in a string representing the name of
/// the package in the Orng cache, and returns an AST representing the package.
pub fn package_find(compiler: *Compiler_Context, interpreter: *Interpreter_Context, current_module_path: []const u8, package_src: *AST) Error!struct { package_adrs: i64, package_dirname: []const u8 } {
    // Construct the path to the package's `build.orng` file
    const package_absolute_path = switch (package_src.pos().?) {
        0 => try package_find_relative(current_module_path, package_src.sum_value.init.?, compiler.allocator()),
        1 => try package_find_git(compiler, package_src.sum_value.init.?),
        else => unreachable,
    };

    const package_build_paths = [_][]const u8{ package_absolute_path, "build.orng" };
    const package_build_path = std.fs.path.join(compiler.allocator(), &package_build_paths) catch unreachable;

    const path_buffer = compiler.allocator().alloc(u8, std.fs.max_path_bytes) catch unreachable;
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

fn package_find_relative(current_module_path: []const u8, package_src: *AST, allocator: std.mem.Allocator) error{CompileError}![]const u8 {
    const package_path = package_src.string.data;

    const current_package = std.fs.path.dirname(current_module_path).?;
    const required_package_paths = [_][]const u8{ current_package, package_path };
    const required_package_path = std.fs.path.join(allocator, &required_package_paths) catch unreachable;

    const package_buffer = allocator.alloc(u8, std.fs.max_path_bytes) catch unreachable;
    return std.fs.cwd().realpath(required_package_path, package_buffer) catch return error.CompileError;
}

/// Implements `builtin::Package::find` for the git variant
fn package_find_git(compiler: *Compiler_Context, package_src: *AST) error{CompileError}![]const u8 {
    const git_source_type = compiler.get_builtin_type("Git_Source");
    const url = package_src.get_field(git_source_type, "url");
    const subdir = package_src.get_field(git_source_type, "subdir");

    try repo_.git_clone(url.string.data, compiler.allocator());

    const repo_dir = repo_.get_packages_dir(compiler.allocator());
    var dirs = std.ArrayList([]const u8).init(compiler.allocator());
    defer dirs.deinit();
    dirs.append(repo_dir) catch unreachable;
    dirs.append(std.fs.path.basename(url.string.data)) catch unreachable;
    if (subdir.string.data.len > 0) {
        dirs.append(subdir.string.data) catch unreachable;
    }
    return std.fs.path.join(compiler.allocator(), dirs.items) catch unreachable;
}
