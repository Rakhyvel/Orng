// This file contains the emitter for emitting out test blocks

const std = @import("std");
const Source_Emitter = @import("source_emitter.zig");
const Header_Emitter = @import("header_emitter.zig");
const Type_Set = @import("../ast/type-set.zig");
const String = @import("../zig-string/zig-string.zig").String;
const module_ = @import("../hierarchy/module.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");

const Self = @This();

module: *module_.Module,
source_emitter: Source_Emitter,
header_emitter: Header_Emitter,

header_writer: *std.array_list.Managed(u8),

pub const CodeGen_Error = error{ WriteFailed, OutOfMemory };

pub fn init(
    module: *module_.Module,
    module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set),
    source_writer: *std.array_list.Managed(u8),
    header_writer: *std.array_list.Managed(u8),
) Self {
    const source_emitter = Source_Emitter.init(module, module_interned_strings, source_writer);
    const header_emitter = Header_Emitter.init(module, header_writer);
    return Self{
        .module = module,
        .source_emitter = source_emitter,
        .header_emitter = header_emitter,
        .header_writer = header_writer,
    };
}

/// Directs the source and header emitters to output the tests
pub fn generate(self: *Self) CodeGen_Error!void {
    try self.source_emitter.output_header_include();
    for (self.module.tests.items) |@"test"| {
        try self.source_emitter.output_function_definition(@"test");
    }

    try self.output_test_include_guard_begin();
    for (self.module.tests.items) |@"test"| {
        try self.header_emitter.output_forward_function(@"test");
    }
    try self.header_emitter.output_include_guard_end();
}

pub fn output_test_include_guard_begin(self: *Self) CodeGen_Error!void {
    var guard_macro = String.init(std.heap.page_allocator);
    defer guard_macro.deinit();

    var guard_macro_writer = guard_macro.writer(&.{});
    const guard_macro_writer_intfc = &guard_macro_writer.interface;
    try guard_macro_writer_intfc.print("{s}__{s}__TESTS_H", .{ self.module.package_name, self.module.name() });

    guard_macro.toUppercase();

    try self.header_writer.print(
        \\/* Code generated using the Orange compiler http://ornglang.org */
        \\
        \\#ifndef {0s}
        \\#define {0s}
        \\
        \\#include "{1s}-{2s}.h"
        \\
        \\
    , .{ guard_macro.str(), self.module.package_name, self.module.name() });
}
