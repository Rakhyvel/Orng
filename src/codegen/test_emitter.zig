// This file contains the emitter for emitting out test blocks

const std = @import("std");
const Source_Emitter = @import("source_emitter.zig");
const Header_Emitter = @import("header_emitter.zig");
const Type_Set = @import("../ast/type-set.zig");
const module_ = @import("../hierarchy/module.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");

const Self = @This();

module: *module_.Module,
source_emitter: Source_Emitter,
header_emitter: Header_Emitter,

header_writer: *std.array_list.Managed(u8),

pub const CodeGen_Error = error{OutOfMemory};

pub fn init(
    module: *module_.Module,
    module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set),
    type_set: *const Type_Set,
    source_writer: *std.array_list.Managed(u8),
    header_writer: *std.array_list.Managed(u8),
) Self {
    const source_emitter = Source_Emitter.init(module, module_interned_strings, type_set, source_writer);
    const header_emitter = Header_Emitter.init(module, type_set, header_writer);
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
    try self.header_writer.print(
        \\/* Code generated using the Orange compiler http://ornglang.org */
        \\
        \\#ifndef _{0s}_{1s}_TESTS_h
        \\#define _{0s}_{1s}_TESTS_h
        \\
        \\#include "{0s}-{1s}.h"
        \\
        \\
    , .{ self.module.package_name, self.module.name() });
}
