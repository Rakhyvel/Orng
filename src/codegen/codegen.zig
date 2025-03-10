const std = @import("std");
const Module_Iterator = @import("../util/dfs.zig").Dfs_Iterator(*Module);
const String = @import("../zig-string/zig-string.zig").String;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");
const Module = @import("../hierarchy/module.zig").Module;
const Header_Emitter = @import("header_emitter.zig");
const Source_Emitter = @import("source_emitter.zig");

pub fn output_modules(compiler: *Compiler_Context) !void {
    // Start from root module, of each package, DFS through imports and generate
    for (compiler.packages.keys()) |package_name| {
        const package = compiler.lookup_package(package_name).?;
        const module = package.root.init_value.?.module.module;

        const package_path = module.get_package_abs_path();
        const build_paths = [_][]const u8{ package_path, "build" };
        const build_path = std.fs.path.join(compiler.allocator(), &build_paths) catch unreachable;
        std.fs.deleteTreeAbsolute(build_path) catch unreachable;
        std.fs.makeDirAbsolute(build_path) catch unreachable;

        var dfs_iter: Module_Iterator = Module_Iterator.init(module, compiler.allocator());
        defer dfs_iter.deinit();
        while (dfs_iter.next()) |next_module| {
            try output(next_module, &compiler.module_interned_strings, build_path, &package.local_modules, compiler.allocator());
        }
    }
}

/// Takes in a statically correct symbol tree, writes it out to a file
fn output(module: *Module, module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set), build_path: []const u8, local_modules: *std.ArrayList(*Module), allocator: std.mem.Allocator) !void {
    local_modules.append(module) catch unreachable;

    var output_h_filename = String.init(allocator);
    defer output_h_filename.deinit();
    output_h_filename.writer().print("{s}-{s}.h", .{ module.package_name, module.name() }) catch unreachable;
    const out_h_paths = [_][]const u8{ build_path, output_h_filename.str() };
    const out_h_path = std.fs.path.join(allocator, &out_h_paths) catch unreachable;
    var output_h_file = std.fs.createFileAbsolute(out_h_path, .{}) catch unreachable;
    defer output_h_file.close();
    var header_emitter = Header_Emitter.init(module, output_h_file.writer());
    header_emitter.generate() catch return error.CompileError;

    var output_c_filename = String.init(allocator);
    defer output_c_filename.deinit();
    output_c_filename.writer().print("{s}-{s}.c", .{ module.package_name, module.name() }) catch unreachable;
    const out_c_paths = [_][]const u8{ build_path, output_c_filename.str() };
    const out_c_path = std.fs.path.join(allocator, &out_c_paths) catch unreachable;
    var output_c_file = std.fs.createFileAbsolute(out_c_path, .{}) catch unreachable;
    defer output_c_file.close();
    var source_emitter = Source_Emitter.init(module, module_interned_strings, output_c_file.writer());
    source_emitter.generate() catch return error.CompileError;

    for (module.local_imported_modules.keys()) |child| {
        if (std.mem.eql(u8, child.package_name, module.package_name)) {
            try output(child, module_interned_strings, build_path, local_modules, allocator);
        }
    }
}
