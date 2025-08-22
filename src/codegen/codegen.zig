const std = @import("std");
const Module_Iterator = @import("../util/dfs.zig").Dfs_Iterator(*Module);
const String = @import("../zig-string/zig-string.zig").String;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");
const Module = @import("../hierarchy/module.zig").Module;
const Header_Emitter = @import("header_emitter.zig");
const Source_Emitter = @import("source_emitter.zig");
const Emitter = @import("emitter.zig");
const Test_Emitter = @import("test_emitter.zig");

/// Goes through each package and outputs a C/H file header pair for each module in each package
pub fn output_modules(compiler: *Compiler_Context) !void {
    // Start from root module, of each package, DFS through imports and generate
    for (compiler.packages.keys()) |package_name| {
        const package = compiler.lookup_package(package_name).?;
        const package_root_module = package.root.init_value.?.module.module;

        const build_path = package.get_build_path(compiler.allocator());
        _ = std.fs.openDirAbsolute(build_path, .{}) catch {
            std.fs.makeDirAbsolute(build_path) catch unreachable;
        };

        var modules = std.ArrayList(*Module).init(compiler.allocator());
        defer modules.deinit();
        var dfs_iter: Module_Iterator = Module_Iterator.init(package_root_module, compiler.allocator());
        defer dfs_iter.deinit();
        while (dfs_iter.next()) |module| {
            if (std.mem.eql(u8, module.get_package_abs_path(), package.absolute_path)) {
                try output(module, &compiler.module_interned_strings, build_path, compiler.allocator());
                modules.append(module) catch unreachable;

                if (package.kind == .test_executable) {
                    try output_tests(module, &compiler.module_interned_strings, build_path, compiler.allocator());
                }
            }
        }

        switch (package.kind) {
            .test_executable => try output_testrunner(modules, build_path, compiler.allocator()),
            .executable => try output_start(package_root_module, &compiler.module_interned_strings, build_path, compiler.allocator()),
            else => {},
        }
    }
}

/// Takes in a statically correct module, writes it out to C source and header files
fn output(
    module: *Module,
    module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set),
    build_path: []const u8,
    allocator: std.mem.Allocator,
) !void {
    var output_h_file = try open_file(module.package_name, module.name(), ".h", build_path, allocator);
    defer output_h_file.close();
    var header_emitter = Header_Emitter.init(module, output_h_file.writer());
    header_emitter.generate() catch return error.CompileError;

    var output_c_file = try open_file(module.package_name, module.name(), ".c", build_path, allocator);
    defer output_c_file.close();
    var source_emitter = Source_Emitter.init(module, module_interned_strings, output_c_file.writer());
    source_emitter.generate() catch return error.CompileError;
}

/// Takes in a statically correct module, writes the tests out to C source and header files
fn output_tests(
    module: *Module,
    module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set),
    build_path: []const u8,
    allocator: std.mem.Allocator,
) !void {
    var output_h_file = try open_file(module.package_name, module.name(), "-tests.h", build_path, allocator);
    defer output_h_file.close();

    var output_c_file = try open_file(module.package_name, module.name(), "-tests.c", build_path, allocator);
    defer output_c_file.close();

    var test_emitter = Test_Emitter.init(module, module_interned_strings, output_c_file.writer(), output_h_file.writer());
    test_emitter.generate() catch return error.CompileError;
}

fn output_start(module: *Module, module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set), build_path: []const u8, allocator: std.mem.Allocator) !void {
    const paths = [_][]const u8{ build_path, "start.c" };
    const path = std.fs.path.join(allocator, &paths) catch unreachable;

    var testrunner_file = std.fs.createFileAbsolute(path, .{}) catch unreachable;
    defer testrunner_file.close();

    var start_writer = testrunner_file.writer();

    var source_emitter = Source_Emitter.init(module, module_interned_strings, start_writer);
    source_emitter.output_header_include() catch return error.CompileError;
    start_writer.print("#include <stdio.h>\n\n", .{}) catch return error.CompileError;
    source_emitter.output_main_function() catch return error.CompileError;
}

fn output_testrunner(modules: std.ArrayList(*Module), build_path: []const u8, allocator: std.mem.Allocator) !void {
    const paths = [_][]const u8{ build_path, "test-runner.c" };
    const path = std.fs.path.join(allocator, &paths) catch unreachable;

    var testrunner_file = std.fs.createFileAbsolute(path, .{}) catch unreachable;
    defer testrunner_file.close();

    var testrunner_writer = testrunner_file.writer();
    testrunner_writer.print(
        \\/* Code generated using the Orng compiler http://ornglang.org */
        \\
        \\#include <stdio.h>
        \\#include <stdlib.h>
        \\#include <string.h>
        \\
        \\
    , .{}) catch return error.CompileError;

    for (modules.items) |module| {
        testrunner_writer.print("#include \"{s}-{s}-tests.h\"\n", .{ module.package_name, module.name() }) catch unreachable;
    }

    testrunner_writer.print(
        \\
        \\struct test_entry {{
        \\    const char* filename;
        \\    const char* name;
        \\    void (*run)(void);
        \\}};
        \\
        \\struct test_entry tests[] = {{
        \\
    , .{}) catch return error.CompileError;

    var num_tests: usize = 0;
    for (modules.items) |module| {
        var emitter = Emitter.init(module, testrunner_writer);
        for (module.tests.items) |@"test"| {
            testrunner_writer.print("    {{\"{s}\", \"{s}\", ", .{ @"test".symbol.scope.module.?.name(), @"test".symbol.decl.?.@"test".name.?.string.data }) catch return error.CompileError;
            emitter.output_symbol(@"test".symbol) catch return error.CompileError;
            testrunner_writer.print("}},\n", .{}) catch return error.CompileError;
            num_tests += 1;
        }
    }

    testrunner_writer.print(
        \\}};
        \\const size_t num_tests = {};
        \\
        \\int main(int argc, char* argv[]) {{
        \\    const char *substr = NULL;
        \\    if (argc >= 2) {{
        \\        substr = argv[1];
        \\    }}
        \\
        \\    for (int i = 0; i < num_tests; i += 1) {{
        \\        if (substr == NULL || strstr(tests[i].name, substr)) {{
        \\            printf("[ RUN    ... ] %s.orng: %s\n", tests[i].filename, tests[i].name);
        \\            tests[i].run();
        \\            printf("[ ... PASSED ]\n");
        \\        }}
        \\    }}
        \\}}
    , .{num_tests}) catch return error.CompileError;
}

fn open_file(package_name: []const u8, module_name: []const u8, ext: []const u8, build_path: []const u8, allocator: std.mem.Allocator) !std.fs.File {
    var output_filename = String.init(allocator);
    defer output_filename.deinit();
    output_filename.writer().print("{s}-{s}{s}", .{ package_name, module_name, ext }) catch unreachable;

    const out_paths = [_][]const u8{ build_path, output_filename.str() };
    const out_path = std.fs.path.join(allocator, &out_paths) catch unreachable;

    const output_file = std.fs.createFileAbsolute(out_path, .{}) catch unreachable;
    return output_file;
}
