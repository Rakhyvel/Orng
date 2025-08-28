///! This file is responsible for interacting with the core library. The core library is a library that the compiler
/// knows through this file, but are not as ubiquitous as to be placed in the prelude. It includes traits such as
/// Allocator, Writer, Reader.
const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const module_ = @import("../hierarchy/module.zig");
const prelude_ = @import("prelude.zig");
const Span = @import("../util/span.zig");
const Scope = @import("../symbol/scope.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");

// TODO: Think about how to remove these public variables. They're only variable because they need to be constructed later.
pub var package_type: *ast_.AST = undefined;
pub var package_source_type: *ast_.AST = undefined;
pub var test_result_type: *ast_.AST = undefined;

// The prelude should only be created once per compilation. _ALL_ packages and modules are within this one prelude scope.
var prelude: ?*Scope = null;
pub fn get_scope(compiler: *Compiler_Context) !*Scope {
    if (prelude == null) {
        try create_prelude(compiler);
    }
    return prelude.?;
}

pub fn deinit() void {
    prelude = null;
}

fn create_prelude(compiler: *Compiler_Context) !void {
    var prelude_abs_path = String.init_with_contents(compiler.allocator(), "/prelude") catch unreachable;
    prelude_abs_path.writer().print("{c}prelude.orng", .{std.fs.path.sep}) catch unreachable;
    const module = module_.Module.init((prelude_abs_path.toOwned() catch unreachable).?, compiler.allocator());
    const symbol = Symbol.init(
        compiler.prelude,
        "prelude",
        Span{ .col = 1, .line_number = 1, .filename = "prelude", .line_text = "" },
        prelude_.unit_type,
        ast_.AST.create_module(
            Token.init_simple("core"),
            prelude.?,
            module,
            compiler.allocator(),
        ),
        null,
        .module,
        compiler.allocator(),
    );
    try prelude.?.put_symbol(symbol, &compiler.errors);

    var env_map = std.process.getEnvMap(compiler.allocator()) catch unreachable;
    defer env_map.deinit();
    prelude.?.module = module;
    const contents: []const u8 = @embedFile("core.orng");
    try module_.Module.fill_contents(
        contents,
        "core.orng",
        null,
        prelude.?,
        module,
        symbol,
        false,
        compiler,
    );

    package_type = compiler.module_scope(module.absolute_path).?.lookup("Package", .{}).found.init_value.?;
    package_source_type = compiler.module_scope(module.absolute_path).?.lookup("Package_Source", .{}).found.init_value.?;
    test_result_type = compiler.module_scope(module.absolute_path).?.lookup("Test_Result", .{}).found.init_value.?;
    _ = compiler.module_scope(module.absolute_path).?.lookup("Requirement", .{}).found.init_value.?;
}
