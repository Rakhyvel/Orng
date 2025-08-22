// This file contains the emitter for emitting out test blocks

const std = @import("std");
const Source_Emitter = @import("source_emitter.zig");
const module_ = @import("../hierarchy/module.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");

const Self = @This();

module: *module_.Module,
source_emitter: Source_Emitter,
writer: Writer,

pub const CodeGen_Error = std.fs.File.WriteError;
const Writer = std.fs.File.Writer;

pub fn init(module: *module_.Module, module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set), writer: Writer) Self {
    const source_emitter = Source_Emitter.init(module, module_interned_strings, writer);
    return Self{
        .module = module,
        .source_emitter = source_emitter,
        .writer = writer,
    };
}

/// Generates C code for the provided Orng module and writes it to the given writer.
pub fn generate(self: *Self) CodeGen_Error!void {
    try self.writer.print(
        \\/* Code generated using the Orng compiler http://ornglang.org */
        \\
        \\#include "{s}-{s}.h"
        \\
        \\
    , .{ self.module.package_name, self.module.name() });

    for (self.module.tests.items) |@"test"| {
        try self.source_emitter.output_function_definition(@"test");
    }
}
