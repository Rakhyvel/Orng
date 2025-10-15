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
const Type_AST = @import("../types/type.zig").Type_AST;

// TODO: Think about how to remove these public variables. They're only variable because they need to be constructed later.
pub var package_type: *Type_AST = undefined;
pub var package_source_type: *Type_AST = undefined;
pub var test_result_type: *Type_AST = undefined;
pub var test_type: *Type_AST = undefined;

var core: ?*Scope = null;
pub var core_symbol: ?*Symbol = null;
pub var core_package_name: []const u8 = undefined;
pub fn get_scope(ctx: *Compiler_Context) !*Scope {
    if (core == null) {
        try create_core(ctx);
    }
    return core.?;
}

pub fn deinit() void {
    core = null;
}

fn create_core(ctx: *Compiler_Context) !void {
    // Create core scope
    var uid_gen = UID_Gen.init();

    repo_.ensure_packages_dir_exists(ctx.allocator());
    core_package_name = repo_.get_repo_dir("core", ctx.allocator());
    _ = std.fs.openDirAbsolute(core_package_name, .{}) catch {
        std.fs.makeDirAbsolute(core_package_name) catch unreachable;
    };

    var core_module_abs_path = std.array_list.Managed(u8).init(ctx.allocator());
    core_module_abs_path.print("{s}{c}core.orng", .{ core_package_name, std.fs.path.sep }) catch unreachable;

    const module = module_.Module.init(core_module_abs_path.toOwnedSlice() catch unreachable, ctx);
    core = Scope.init(ctx.prelude, &uid_gen, ctx.allocator());
    core_symbol = Symbol.init(
        ctx.prelude,
        "core",
        try ctx.ast_store.add(.{ .module = .{
            ._token = Token.init_simple("core"),
            ._scope = core.?,
            .module = module,
        } }),
        .module,
        .local,
        ctx.allocator(),
    );
    try ctx.prelude.put_symbol(core_symbol.?, &ctx.errors);
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
        ctx,
    );

    const module_scope = ctx.module_scope(module.absolute_path).?;
    package_type = module_scope.lookup("Package", .{}).found.init_typedef().?;
    package_source_type = module_scope.lookup("Package_Source", .{}).found.init_typedef().?;
    test_result_type = module_scope.lookup("Test_Result", .{}).found.init_typedef().?;
    test_type = Type_AST.create_function(
        test_result_type.token(),
        prelude_.unit_type,
        test_result_type,
        ctx.allocator(),
    );

    _ = module_scope.lookup("Requirement", .{}).found.init_typedef().?;
}
