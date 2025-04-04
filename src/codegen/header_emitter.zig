// This file contains the implementation of the Orng compiler's C code generator.
// TODO: Make this a context struct (to fix self.module)

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Basic_Block = @import("../ir/basic-block.zig");
const CFG = @import("../ir/cfg.zig");
const Emitter = @import("emitter.zig");
const Instruction = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const module_ = @import("../hierarchy/module.zig");
const Span = @import("../util/span.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Type_Set = @import("../ast/type-set.zig");
const Dependency_Node = @import("../ast/dependency_node.zig");
const Symbol = @import("../symbol/symbol.zig");

const Self = @This();

module: *module_.Module,
emitter: Emitter,
writer: Writer,

pub const CodeGen_Error = std.fs.File.WriteError;
const Writer = std.fs.File.Writer;

pub fn init(module: *module_.Module, writer: Writer) Self {
    const emitter = Emitter.init(module, writer);
    return Self{ .module = module, .emitter = emitter, .writer = writer };
}

/// Generates the header file for the given module
pub fn generate(self: *Self) CodeGen_Error!void {
    try self.writer.print(
        \\/* Code generated using the Orng compiler http://ornglang.org */
        \\
        \\#ifndef _{0s}_{1s}_h
        \\#define _{0s}_{1s}_h
        \\
        \\#include <stdio.h>
        \\#include <stdint.h>
        \\#include <stdlib.h>
        \\
        \\#include "debug.inc"
        \\
        \\
    , .{ self.module.package_name, self.module.name() });

    try self.output_includes();
    try self.output_forward_typedefs();
    try self.output_typedefs();
    try self.output_traits();
    try self.emitter.forall_functions(self, "/* Function forward definitions */", output_forward_function);
    try self.writer.print(
        \\
        \\#endif
        \\
    , .{});
}

fn output_includes(self: *Self) CodeGen_Error!void {
    if (self.module.cincludes.items.len != 0) {
        for (self.module.cincludes.items) |cinclude| {
            try self.writer.print("#include \"{s}\"\n", .{cinclude.string.data});
        }
        try self.writer.print("\n", .{});
    }

    if (self.module.local_imported_modules.keys().len != 0) {
        for (self.module.local_imported_modules.keys()) |module| {
            try self.writer.print("#include \"{s}-{s}.h\"\n", .{ module.package_name, module.name() });
        }
        try self.writer.print("\n", .{});
    }
}

/// Outputs forward declarations for typedefs based on the provided `Type_Set`.
fn output_forward_typedefs(self: *Self) CodeGen_Error!void {
    if (self.module.type_set.types.items.len > 0) {
        // Don't generate typedefs header comment if there are no typedefs!
        try self.writer.print("/* Forward struct, union, and function declarations */\n", .{});
    }

    // Forward declare all structs/unions
    for (self.module.type_set.types.items) |dep| {
        if (dep.base.* == .product or dep.base.* == .sum_type) {
            try self.emitter.output_struct_name(dep);
            try self.writer.print(";\n", .{});
        } else if (dep.base.* == .dyn_type) {
            try self.emitter.output_dyn_name(dep);
            try self.writer.print(";\n", .{});
        }
    }
}

/// Outputs typedefs based on the provided `Type_Set`.
fn output_typedefs(self: *Self) CodeGen_Error!void {
    if (self.module.type_set.types.items.len > 0) {
        // Don't generate typedefs header comment if there are no typedefs!
        try self.writer.print("\n/* Struct, union, and function definitions */\n", .{});
    }

    // Output all typedefs
    for (self.module.type_set.types.items) |dag| {
        try self.output_typedef(dag);
    }
}

/// Outputs a typedef declaration based on the provided `DAG`.
fn output_typedef(self: *Self, dep: *Dependency_Node) CodeGen_Error!void {
    // FIXME: High Cyclo
    if (dep.visited) {
        // only visit a DAG node once
        return;
    }
    dep.mark_visited();

    // output any types that this type depends on
    for (dep.dependencies.items) |depen| {
        try self.output_typedef(depen);
    }

    if (dep.base.* == .function) {
        try self.writer.print("typedef ", .{});
        try self.emitter.output_type(dep.base.rhs());
        try self.writer.print("(*", .{});
        try self.emitter.output_function_name(dep);
        try self.writer.print(")(", .{});
        if (dep.base.lhs().* == .product) {
            // Function pointer takes more than one argument
            const product = dep.base.lhs();
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
            try self.emitter.output_type(dep.base.lhs());
        }
        try self.writer.print(");\n\n", .{});
    } else if (dep.base.* == .product) {
        try self.emitter.output_struct_name(dep);
        try self.writer.print(" {{\n", .{});
        try self.output_field_list(dep.base.children(), 4);
        try self.writer.print("}};\n\n", .{});
    } else if (dep.base.* == .sum_type) {
        try self.emitter.output_struct_name(dep);
        try self.writer.print(" {{\n    uint64_t tag;\n", .{});
        if (!dep.base.sum_type.is_all_unit()) {
            try self.writer.print("    union {{\n", .{});
            try self.output_field_list(dep.base.children(), 8);
            try self.writer.print("    }};\n", .{});
        }
        try self.writer.print("}};\n\n", .{});
    } else if (dep.base.* == .untagged_sum_type) {
        try self.emitter.output_untagged_sum_name(dep);
        try self.writer.print(" {{\n", .{});
        if (!dep.base.expr().sum_type.is_all_unit()) {
            try self.output_field_list(dep.base.children(), 4);
        }
        try self.writer.print("}};\n\n", .{});
    } else if (dep.base.* == .dyn_type) {
        try self.emitter.output_dyn_name(dep);
        try self.writer.print(" {{\n    void* data_ptr;\n    struct vtable_{s}", .{dep.base.expr().symbol().?.name});
        try self.writer.print("* vtable;\n}};\n\n", .{});
    }
}

/// Outputs the fields of a structure or union type based on the provided list of AST types.
fn output_field_list(self: *Self, fields: *std.ArrayList(*ast_.AST), spaces: usize) CodeGen_Error!void {
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

fn output_traits(self: *Self) CodeGen_Error!void {
    // FIXME: High Cyclo
    if (self.module.traits.items.len > 0) {
        // Do not output header comment if there are no traits!
        try self.writer.print("/* Trait vtable type definitions */\n", .{});
    }

    for (self.module.traits.items) |trait| {
        // TODO: Too long
        if (trait.trait.num_virtual_methods == 0) {
            continue;
        }
        try self.writer.print("struct vtable_{s} {{\n", .{trait.symbol().?.name});
        for (trait.trait.method_decls.items) |decl| {
            if (!decl.method_decl.is_virtual) {
                continue;
            }
            const method_decl_has_receiver = decl.method_decl.receiver != null;
            const num_method_params = decl.children().items.len;

            try self.writer.print("    ", .{});
            try self.emitter.output_type(decl.method_decl.ret_type);
            try self.writer.print("(*{s})(", .{decl.method_decl.name.token().data});

            // Output receiver parameter
            if (method_decl_has_receiver) {
                try self.writer.print("void*", .{});
                if (decl.children().items.len > 0 and !decl.children().items[0].decl.type.is_c_void_type()) {
                    try self.writer.print(", ", .{});
                }
            }

            // Output regular parameters
            for (decl.children().items, 0..) |param_decl, i| {
                if (!param_decl.decl.type.is_c_void_type()) {
                    // Do not output `void` parameters
                    try self.emitter.output_type(param_decl.decl.type);
                    if (i + 1 < num_method_params and !decl.children().items[i + 1].decl.type.is_c_void_type()) {
                        try self.writer.print(", ", .{});
                    }
                }
            }
            if (num_method_params + @intFromBool(method_decl_has_receiver) == 0) {
                // If there are no parameters and no receiver, mark parameter list as void
                try self.writer.print("void", .{});
            }
            try self.writer.print(");\n", .{});
        }
        try self.writer.print("}};\n\n", .{});
    }
}

/// Outputs the forward declaration of a function.
fn output_forward_function(self: *Self, cfg: *CFG) CodeGen_Error!void {
    try self.emitter.output_function_prototype(cfg);
    try self.writer.print(";\n", .{});
}
