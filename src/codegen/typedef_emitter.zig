// This file contains the implementation of the Orange compiler's C code generator.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Basic_Block = @import("../ir/basic-block.zig");
const CFG = @import("../ir/cfg.zig");
const Emitter = @import("emitter.zig");
const Instruction = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const module_ = @import("../hierarchy/module.zig");
const Span = @import("../util/span.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Type_Set = @import("../ast/type-set.zig");
const Dependency_Node = @import("../ast/dependency_node.zig");
const Symbol = @import("../symbol/symbol.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const Canonical_Type_Fmt = @import("canonical_type_fmt.zig");

const Self = @This();

emitter: Emitter,
_type: *Type_AST,
writer: *std.array_list.Managed(u8),

pub const CodeGen_Error = error{ WriteFailed, OutOfMemory };

pub fn init(_type: *Type_AST, writer: *std.array_list.Managed(u8)) Self {
    const emitter = Emitter.init(writer);
    return Self{ .emitter = emitter, ._type = _type, .writer = writer };
}

/// Generates the header file for the given module
pub fn generate(self: *Self) CodeGen_Error!void {
    try self.output_include_guard_begin();
    try self.output_typedef();
    try self.output_include_guard_end();
}

pub fn output_include_guard_begin(self: *Self) CodeGen_Error!void {
    try self.writer.print(
        \\/* Code generated using the Orange compiler http://ornglang.org */
        \\
        \\#ifndef _{0f}_H
        \\#define _{0f}_H
        \\
        \\
    , .{Canonical_Type_Fmt{ .type = self._type, .case = .upper }});
}

pub fn output_include_guard_end(self: *Self) CodeGen_Error!void {
    try self.writer.print(
        \\#endif
        \\
    , .{});
}

/// Outputs a typedef declaration based on the provided `DAG`.
fn output_typedef(self: *Self) CodeGen_Error!void {
    if (self._type.* == .function) {
        try self.writer.print("typedef ", .{});
        try self.emitter.output_type(self._type.rhs());
        try self.writer.print("(*{f})(", .{Canonical_Type_Fmt{ .type = self._type }});
        if (self._type.lhs().* == .tuple_type) {
            // Function pointer takes more than one argument
            const product = self._type.lhs();
            for (product.children().items, 0..) |term, i| {
                if (!term.is_c_void_type()) {
                    // Do not output `void` parameters
                    try self.emitter.output_type(term);
                    if (i + 1 < product.children().items.len and !product.children().items[i + 1].is_c_void_type()) {
                        try self.writer.print(", ", .{});
                    }
                }
            }
        } else {
            // Function pointer takes one argument
            try self.emitter.output_type(self._type.lhs());
        }
        try self.writer.print(");\n\n", .{});
    } else if (self._type.* == .struct_type or self._type.* == .tuple_type) {
        try self.writer.print("struct {f} {{\n", .{Canonical_Type_Fmt{ .type = self._type }});
        try self.output_field_list(self._type.children(), 4);
        try self.writer.print("}};\n\n", .{});
    } else if (self._type.* == .array_of) {
        try self.writer.print("struct {f} {{\n    ", .{Canonical_Type_Fmt{ .type = self._type }});
        try self.emitter.output_type(self._type.child());
        try self.writer.print(" _0[{}];\n", .{self._type.array_of.len.int.data});
        try self.writer.print("}};\n\n", .{});
    } else if (self._type.* == .enum_type) {
        try self.writer.print("struct {f} {{\n    uint64_t tag;\n", .{Canonical_Type_Fmt{ .type = self._type }});
        if (!self._type.enum_type.is_all_unit()) {
            try self.writer.print("    union {{\n", .{});
            try self.output_field_list(self._type.children(), 8);
            try self.writer.print("    }};\n", .{});
        }
        try self.writer.print("}};\n\n", .{});
    } else if (self._type.* == .untagged_sum_type) {
        try self.writer.print("struct {f} {{\n", .{Canonical_Type_Fmt{ .type = self._type }});
        if (!self._type.child().expand_identifier().enum_type.is_all_unit()) {
            try self.output_field_list(self._type.children(), 4);
        }
        try self.writer.print("}};\n\n", .{});
    } else if (self._type.* == .dyn_type) {
        try self.writer.print("struct {f} {{\n    void* data_ptr;\n    struct vtable_{s}", .{ Canonical_Type_Fmt{ .type = self._type }, self._type.child().symbol().?.name });
        try self.writer.print("* vtable;\n}};\n\n", .{});
    }
}

/// Outputs the fields of a structure or union type based on the provided list of AST types.
fn output_field_list(self: *Self, fields: *const std.array_list.Managed(*Type_AST), spaces: usize) CodeGen_Error!void {
    // output each field in the list
    for (fields.items, 0..) |term, i| {
        if (!term.is_c_void_type()) {
            // Don't gen `void` structure/union fields
            for (0..spaces) |_| {
                try self.writer.print(" ", .{});
            }
            try self.emitter.output_type(term);
            try self.writer.print(" _{};\n", .{i});
        }
    }
}
