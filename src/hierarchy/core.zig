///! This file is responsible for interacting with the core library. The core library is a library that the compiler
/// knows through this file, but are not as ubiquitous as to be placed in the prelude. It includes traits such as
/// Allocator, Writer, Reader.
const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const module_ = @import("../hierarchy/module.zig");
const prelude_ = @import("prelude.zig");
const repo_ = @import("../util/repo.zig");
const Span = @import("../util/span.zig");
const Scope = @import("../symbol/scope.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");
const UID_Gen = @import("../util/uid_gen.zig");

// TODO: Think about how to remove these public variables. They're only variable because they need to be constructed later.
pub var package_type: *ast_.AST = undefined;
pub var package_source_type: *ast_.AST = undefined;
pub var test_result_type: *ast_.AST = undefined;

var core: ?*Scope = null;
pub var core_symbol: ?*Symbol = null;
pub var core_package_name: []const u8 = undefined;
pub fn get_scope(compiler: *Compiler_Context) !*Scope {
    if (core == null) {
        try create_core(compiler);
    }
    return core.?;
}

pub fn deinit() void {
    core = null;
}

fn create_core(compiler: *Compiler_Context) !void {
    // Create core scope
    var uid_gen = UID_Gen.init();

    repo_.ensure_packages_dir_exists(compiler.allocator());
    core_package_name = repo_.get_repo_dir("core", compiler.allocator());
    _ = std.fs.openDirAbsolute(core_package_name, .{}) catch {
        std.fs.makeDirAbsolute(core_package_name) catch unreachable;
    };

    var core_module_abs_path = String.init_with_contents(compiler.allocator(), core_package_name) catch unreachable;
    core_module_abs_path.writer().print("{c}core.orng", .{std.fs.path.sep}) catch unreachable;

    const module = module_.Module.init((core_module_abs_path.toOwned() catch unreachable).?, compiler.allocator());
    core = Scope.init(compiler.prelude, &uid_gen, compiler.allocator());
    core_symbol = Symbol.init(
        compiler.prelude,
        "core",
        Span{ .col = 1, .line_number = 1, .filename = "core", .line_text = "" },
        prelude_.unit_type,
        ast_.AST.create_module(
            Token.init_simple("core"),
            core.?,
            module,
            compiler.allocator(),
        ),
        null,
        .module,
        compiler.allocator(),
    );
    try compiler.prelude.put_symbol(core_symbol.?, &compiler.errors);
    core.?.module = module;

    const contents: []const u8 = @embedFile("core.orng");
    try module_.Module.fill_contents(
        contents,
        "core.orng",
        null,
        core.?,
        module,
        core_symbol.?,
        false,
        compiler,
    );

    package_type = compiler.module_scope(module.absolute_path).?.lookup("Package", .{}).found.init_value.?;
    package_source_type = compiler.module_scope(module.absolute_path).?.lookup("Package_Source", .{}).found.init_value.?;
    test_result_type = compiler.module_scope(module.absolute_path).?.lookup("Test_Result", .{}).found.init_value.?;
    _ = compiler.module_scope(module.absolute_path).?.lookup("Requirement", .{}).found.init_value.?;
}
