// This file contains the implementation of the Orng compiler's C code generator.
// TODO: Make this a context struct (to fix cheat_module)

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const basic_block_ = @import("../ir/basic-block.zig");
const cfg_ = @import("../ir/cfg.zig");
const ir_ = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const module_ = @import("../hierarchy/module.zig");
const span_ = @import("../util/span.zig");
const String = @import("../zig-string/zig-string.zig").String;
const type_set_ = @import("../ast/type-set.zig");
const symbol_ = @import("../symbol/symbol.zig");

var cheat_module: *module_.Module = undefined; // TODO: I hate this
const HIGHEST_PRECEDENCE = 100;

pub const CodeGen_Error = std.fs.File.WriteError;
const Writer = std.fs.File.Writer;

/// Generates C code for the provided Orng module and writes it to the given writer.
pub fn generate(module: *module_.Module, source_writer: Writer, header_writer: Writer) CodeGen_Error!void {
    cheat_module = module;
    try generate_source(module, source_writer);
    try generate_header(module, header_writer);
}

pub fn generate_source(module: *module_.Module, writer: Writer) CodeGen_Error!void {
    try writer.print(
        \\/* Code generated using the Orng compiler http://ornglang.org */
        \\
        \\#include "{s}-{s}.h"
        \\
        \\
    , .{ module.package_name, module.name });

    // try output_forward_typedefs(&module.type_set, writer);
    // try output_typedefs(&module.type_set, writer);
    try output_interned_strings(&module.interned_strings, writer);
    // try output_traits(&module.traits, writer);
    // try forall_functions(&module.cfgs, "/* Function forward definitions */", writer, output_forward_function);
    try output_impls(&module.impls, writer);
    try forall_functions(&module.cfgs, "\n/* Function definitions */", writer, output_function_definition);
    if (module.entry) |entry| {
        try output_main_function(entry, writer);
    }
}

pub fn generate_header(module: *module_.Module, writer: Writer) CodeGen_Error!void {
    try writer.print(
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
    , .{ module.package_name, module.name });

    try output_includes(module.cincludes.items, module.local_imported_modules.keys(), writer);
    try output_forward_typedefs(&module.type_set, writer);
    try output_typedefs(&module.type_set, writer);
    try output_traits(&module.traits, writer);
    try forall_functions(&module.cfgs, "/* Function forward definitions */", writer, output_forward_function);
    try writer.print(
        \\
        \\#endif
        \\
    , .{});
}

fn output_includes(cincludes: []*ast_.AST, modules: []*module_.Module, writer: Writer) CodeGen_Error!void {
    if (cincludes.len != 0) {
        for (cincludes) |cinclude| {
            try writer.print("#include \"{s}\"\n", .{cinclude.string.data});
        }
        try writer.print("\n", .{});
    }

    if (modules.len != 0) {
        for (modules) |module| {
            try writer.print("#include \"{s}-{s}.h\"\n", .{ module.package_name, module.name });
        }
        try writer.print("\n", .{});
    }
}

/// Outputs forward declarations for typedefs based on the provided `Type_Set`.
fn output_forward_typedefs(
    type_set: *type_set_.Type_Set,
    writer: Writer,
) CodeGen_Error!void {
    if (type_set.types.items.len > 0) {
        // Don't generate typedefs header comment if there are no typedefs!
        try writer.print("/* Forward struct, union, and function declarations */\n", .{});
    }

    // Forward declare all structs/unions
    for (type_set.types.items) |dag| {
        if (dag.base.* == .product or dag.base.* == .sum_type) {
            try writer.print("struct {s}_struct{};\n", .{ cheat_module.package_name, dag.uid });
        } else if (dag.base.* == .dyn_type) {
            try writer.print("struct {s}_dyn{};\n", .{ cheat_module.package_name, dag.uid });
        }
    }
}

/// Outputs typedefs based on the provided `Type_Set`.
fn output_typedefs(
    type_set: *type_set_.Type_Set,
    writer: Writer,
) CodeGen_Error!void {
    if (type_set.types.items.len > 0) {
        // Don't generate typedefs header comment if there are no typedefs!
        try writer.print("\n/* Struct, union, and function definitions */\n", .{});
    }

    // Output all typedefs
    for (type_set.types.items) |dag| {
        try output_typedef(dag, writer);
    }
}

/// Outputs a typedef declaration based on the provided `DAG`.
fn output_typedef(
    dag: *type_set_.DAG,
    writer: Writer,
) CodeGen_Error!void {
    // FIXME: High Cyclo
    if (dag.visited) {
        // only visit a DAG node once
        return;
    }
    dag.visited = true;

    // output any types that this type depends on
    for (dag.dependencies.items) |depen| {
        try output_typedef(depen, writer);
    }

    if (dag.base.* == .function) {
        try writer.print("typedef ", .{});
        try output_type(dag.base.rhs(), writer);
        try writer.print("(*{s}_function{})(", .{ cheat_module.package_name, dag.uid });
        if (dag.base.lhs().* == .product) {
            // Function pointer takes more than one argument
            const product = dag.base.lhs();
            for (product.children().items, 0..) |term, i| {
                if (!term.is_c_void_type()) {
                    // Do not output `void` parameters
                    try output_type(term, writer);
                    if (i + 1 < product.children().items.len and !product.children().items[i + 1].is_c_void_type()) {
                        try writer.print(", ", .{});
                    }
                }
            }
        } else {
            // Function pointer takes one argument
            try output_type(dag.base.lhs(), writer);
        }
        try writer.print(");\n\n", .{});
    } else if (dag.base.* == .product) {
        try writer.print("struct {s}_struct{} {{\n", .{ cheat_module.package_name, dag.uid });
        try output_field_list(dag.base.children(), 4, writer);
        try writer.print("}};\n\n", .{});
    } else if (dag.base.* == .sum_type) {
        try writer.print("struct {s}_struct{} {{\n    uint64_t tag;\n", .{ cheat_module.package_name, dag.uid });
        if (!dag.base.sum_type.is_all_unit()) {
            try writer.print("    union {{\n", .{});
            try output_field_list(dag.base.children(), 8, writer);
            try writer.print("    }};\n", .{});
        }
        try writer.print("}};\n\n", .{});
    } else if (dag.base.* == .untagged_sum_type) {
        try writer.print("union {s}_union{} {{\n", .{ cheat_module.package_name, dag.uid });
        if (!dag.base.expr().sum_type.is_all_unit()) {
            try output_field_list(dag.base.children(), 4, writer);
        }
        try writer.print("}};\n\n", .{});
    } else if (dag.base.* == .dyn_type) {
        try writer.print("struct {s}_dyn{} {{\n    void* data_ptr;\n    struct vtable_{s}", .{ cheat_module.package_name, dag.uid, dag.base.expr().symbol().?.name });
        try writer.print("* vtable;\n}};\n\n", .{});
    }
}

/// Outputs the fields of a structure or union type based on the provided list of AST types.
fn output_field_list(
    fields: *std.ArrayList(*ast_.AST),
    spaces: usize,
    writer: Writer,
) CodeGen_Error!void {
    // output each field in the list
    for (fields.items, 0..) |term, i| {
        if (!term.is_c_void_type()) {
            // Don't gen `void` structure/union fields
            for (0..spaces) |_| {
                try writer.print(" ", .{});
            }
            try output_type(term, writer);
            try writer.print(" _{};\n", .{i});
        }
    }
}

fn output_traits(
    traits: *std.ArrayList(*ast_.AST),
    writer: Writer,
) CodeGen_Error!void {
    // FIXME: High Cyclo
    if (traits.items.len > 0) {
        // Do not output header comment if there are no traits!
        try writer.print("/* Trait vtable type definitions */\n", .{});
    }

    for (traits.items) |trait| {
        // TODO: Too long
        if (trait.trait.num_virtual_methods == 0) {
            continue;
        }
        try writer.print("struct vtable_{s} {{\n", .{trait.symbol().?.name});
        for (trait.trait.method_decls.items) |decl| {
            if (!decl.method_decl.is_virtual) {
                continue;
            }
            const method_decl_has_receiver = decl.method_decl.receiver != null;
            const num_method_params = decl.children().items.len;

            try writer.print("    ", .{});
            try output_type(decl.method_decl.ret_type, writer);
            try writer.print("(*{s})(", .{decl.method_decl.name.token().data});

            // Output receiver parameter
            if (method_decl_has_receiver) {
                try writer.print("void*", .{});
                if (decl.children().items.len > 0 and !decl.children().items[0].decl.type.is_c_void_type()) {
                    try writer.print(", ", .{});
                }
            }

            // Output regular parameters
            for (decl.children().items, 0..) |param_decl, i| {
                if (!param_decl.decl.type.is_c_void_type()) {
                    // Do not output `void` parameters
                    try output_type(param_decl.decl.type, writer);
                    if (i + 1 < num_method_params and !decl.children().items[i + 1].decl.type.is_c_void_type()) {
                        try writer.print(", ", .{});
                    }
                }
            }
            if (num_method_params + @intFromBool(method_decl_has_receiver) == 0) {
                // If there are no parameters and no receiver, mark parameter list as void
                try writer.print("void", .{});
            }
            try writer.print(");\n", .{});
        }
        try writer.print("}};\n\n", .{});
    }
}

/// Outputs the interned strings declarations
fn output_interned_strings(interned_strings: *std.ArrayList([]const u8), writer: Writer) CodeGen_Error!void {
    if (interned_strings.items.len > 0) {
        // Do not output header comment if there are no interned strings!
        try writer.print("/* Interned Strings */\n", .{});
    }

    // Output each string in the string hash map
    for (0..interned_strings.items.len) |i| {
        try writer.print("static char* string_{} = \"", .{i});
        // Print each byte in the string in hex format
        const str = interned_strings.items[i];
        for (str) |byte| {
            try writer.print("\\x{X:0>2}", .{byte});
        }
        try writer.print("\";\n", .{});
    }

    if (interned_strings.items.len > 0) {
        // Do not output this newline if there are no interned strings!
        try writer.print("\n", .{});
    }
}

/// Applies a function to all CFGs in a list of CFGs.
fn forall_functions(
    cfgs: *std.ArrayList(*cfg_.CFG),
    header_comment: []const u8,
    writer: Writer,
    comptime f: fn (*cfg_.CFG, Writer) CodeGen_Error!void,
) CodeGen_Error!void {
    try writer.print("{s}\n", .{header_comment});

    // apply the function `f` to all CFGs in the `cfgs` list
    for (cfgs.items) |cfg| {
        if (!cfg.needed_at_runtime) {
            continue;
        }
        if (cfg.symbol.decl.?.* == .fn_decl or cfg.symbol.decl.?.* == .method_decl) { // Don't output for `_comptime` decls
            try f(cfg, writer);
        }
    }
    try writer.print("\n", .{});
}

/// Outputs the forward declaration of a function.
fn output_forward_function(cfg: *cfg_.CFG, writer: Writer) CodeGen_Error!void {
    try output_function_prototype(cfg, writer);
    try writer.print(";\n", .{});
}

fn output_impls(
    impls: *std.ArrayList(*ast_.AST),
    writer: Writer,
) CodeGen_Error!void {
    if (impls.items.len > 0) {
        // TODO: Count impls that have virtual methods
        // Do not output header comment if there are no impls!
        try writer.print("/* Trait vtable implementations */\n", .{});
    }

    for (impls.items) |impl| {
        if (impl.impl.num_virtual_methods == 0) {
            continue;
        }
        const trait = impl.impl.trait.?;
        try writer.print("struct vtable_{s} _{}_$vtable = {{\n", .{ trait.symbol().?.name, impl.scope().?.uid });
        for (impl.impl.method_defs.items) |decl| {
            if (!decl.method_decl.is_virtual) {
                continue;
            }
            try writer.print("    .{s} = ", .{decl.method_decl.name.token().data});
            try output_symbol(decl.symbol().?, writer);
            try writer.print(",\n", .{});
        }
        try writer.print("}};\n\n", .{});
    }
}

/// Output the definition of a function.
fn output_function_definition(cfg: *cfg_.CFG, writer: Writer) CodeGen_Error!void {
    try output_function_prototype(cfg, writer);
    try writer.print("{{\n", .{});

    // Declare local variables
    for (cfg.symbvers.items) |symbver| {
        if (symbver.symbol.expanded_type.?.sizeof() == 0 or // symbol's C type is `void`
            (symbver.symbol.uses == 0 and symbver.symbol.name[0] != '$') // non-bookkeeping symbol is not used
        ) {
            continue; // Do not output unit variables
        }
        try output_var_decl(symbver.symbol, writer, false);
        symbver.symbol.decld = true;
    }

    // Mark unused parameters as discarded
    const param_symbols = if (cfg.symbol.decl.?.* == .fn_decl) cfg.symbol.decl.?.fn_decl.param_symbols else cfg.symbol.decl.?.method_decl.param_symbols;
    for (param_symbols.items) |param| {
        // Do this only if they aren't discarded in source
        // Users can discard parameters, however used parameters may also become unused through optimizations
        if (!param.expanded_type.?.is_c_void_type() and // unit-typed parameters aren't emitted
            param.uses == 0)
        {
            try writer.print("    (void)", .{});
            try output_symbol(param, writer);
            try writer.print(";\n", .{});
        }
    }

    // Generate the basic-block graph, starting at the init basic block
    if (cfg.block_graph_head) |block_graph_head| {
        try output_basic_block(cfg, block_graph_head, cfg.return_symbol, writer);
        cfg.clear_visited_BBs();
    }

    try writer.print("}}\n\n", .{});
}

/// Outputs the prototype of a function
fn output_function_prototype(
    cfg: *cfg_.CFG, // TODO: Accept cfg symbol
    writer: Writer,
) CodeGen_Error!void {
    // Output function return type and name
    try output_type(cfg.symbol.expanded_type.?.rhs(), writer);
    try writer.print(" ", .{});
    try output_symbol(cfg.symbol, writer);

    // Output function parameters
    var num_non_unit_params: i64 = 0;
    try writer.print("(", .{});
    const decl = cfg.symbol.decl.?;
    const param_symbols = if (decl.* == .fn_decl) decl.fn_decl.param_symbols else decl.method_decl.param_symbols;
    for (param_symbols.items, 0..) |term, i| {
        if (!term.expanded_type.?.is_c_void_type()) {
            if (decl.* == .method_decl and decl.method_decl.receiver != null and i == 0) {
                // Print out method receiver
                try writer.print("void* ", .{});
                try output_symbol(term, writer);
            } else {
                // Print out parameter declarations
                try output_var_decl(term, writer, true);
            }
            if (i + 1 < param_symbols.items.len and !param_symbols.items[i + 1].expanded_type.?.is_c_void_type()) {
                try writer.print(", ", .{});
            }
            num_non_unit_params += 1;
        }
    }

    if (num_non_unit_params == 0) {
        // If there are no parameters, mark parameter list as void
        try writer.print("void", .{});
    }
    try writer.print(")", .{});
}

fn output_main_function(
    cfg: *cfg_.CFG, // TODO: Accept symbol
    writer: Writer,
) CodeGen_Error!void {
    const codomain = cfg.symbol.expanded_type.?.rhs();
    var string_access: []const u8 = "";
    var specifier: ?[]const u8 = null;
    switch (codomain.*) {
        .identifier => {
            const info = primitives_.info_from_name(codomain.token().data).?;
            specifier = switch (info.type_kind) {
                .boolean, .signed_integer => "d",
                .unsigned_integer => "u",
                .floating_point => "f",
                else => unreachable,
            };
        },
        .product => {
            string_access = "._0";
            specifier = "s";
        },
        else => {},
    }

    try writer.print(
        \\int main(int argc, char *argv[]) {{
        \\  
    , .{});
    if (specifier != null) {
        try writer.print("printf(\"%{s}{s}\", ", .{ if (codomain.sizeof() == 8) "l" else "", specifier.? });
        try output_symbol(cfg.symbol, writer);
        try writer.print("(){s});", .{string_access});
    } else {
        try output_symbol(cfg.symbol, writer);
        try writer.print(
            \\();
            \\
        , .{});
    }
    try writer.print(
        \\  return 0;
        \\}}
        \\
    , .{});
}

/// Outputs a symbol's declaration. Parameters are not formatted with a preceding tab, nor a
/// semicolon nor newline.
fn output_var_decl(
    symbol: *symbol_.Symbol,
    writer: Writer,
    is_parameter: bool, // TODO: New function, that surrounds output_var_decl
) CodeGen_Error!void {
    if (!is_parameter) {
        try writer.print("    ", .{});
    }
    try output_type(symbol.expanded_type.?, writer);
    try writer.print(" ", .{});
    try output_symbol(symbol, writer);
    if (!is_parameter) {
        try writer.print(";\n", .{});
    }
}

/// Outputs a symbol with it's file's unique identifier
fn output_symbol(symbol: *symbol_.Symbol, writer: Writer) CodeGen_Error!void {
    if (symbol.kind == .@"extern") {
        try writer.print("{s}", .{symbol.kind.@"extern".c_name.?.string.data});
    } else if (symbol.decl != null and symbol.decl.?.* != .receiver and symbol.decl.?.top_level()) {
        try writer.print("p{s}_m{s}_{}_{s}", .{ symbol.scope.module.?.package_name, symbol.scope.module.?.name, symbol.scope.uid, symbol.name });
    } else {
        try writer.print("_{}_{s}", .{ symbol.scope.uid, symbol.name });
    }
}

/// Outputs the C type which corresponds to an AST type.
fn output_type(_type: *ast_.AST, writer: Writer) CodeGen_Error!void {
    if (_type.common()._unexpanded_type != null and
        _type.common()._unexpanded_type.?.* == .identifier and
        _type.common()._unexpanded_type.?.symbol() != null and
        _type.common()._unexpanded_type.?.symbol().?.kind == .@"extern")
    {
        // Output simply the C name for an extern type
        try writer.print("{s}", .{_type.common()._unexpanded_type.?.symbol().?.kind.@"extern".c_name.?.string.data});
        return;
    }

    if (_type.common()._expanded_type != null and _type.common()._expanded_type.?.sizeof() == 0) {
        // For zero-size types that are still required to be output, ie pointers to empty untagged unions, structs, or ()
        try writer.print("void", .{});
        return;
    }

    switch (_type.*) {
        .identifier => if (_type.common()._expanded_type != null and _type.common()._expanded_type.? != _type) {
            try output_type(_type.common()._expanded_type.?, writer);
        } else {
            try writer.print("{s}", .{primitives_.info_from_name(_type.token().data).?.c_name});
        },
        .addr_of => {
            try output_type(_type.expr(), writer);
            try writer.print("*", .{});
        },
        .anyptr_type => try writer.print("void", .{}),
        .function => {
            const type_uid = cheat_module.type_set.get(_type).?.uid;
            try writer.print("{s}_function{}", .{ cheat_module.package_name, type_uid });
        },
        .sum_type, .product => {
            const type_uid = cheat_module.type_set.get(_type).?.uid;
            try writer.print("struct {s}_struct{}", .{ cheat_module.package_name, type_uid });
        },
        .untagged_sum_type => {
            const type_uid = cheat_module.type_set.get(_type).?.uid;
            try writer.print("union {s}_union{}", .{ cheat_module.package_name, type_uid });
        },
        .dyn_type => {
            const type_uid = cheat_module.type_set.get(_type).?.uid;
            try writer.print("struct {s}_dyn{}", .{ cheat_module.package_name, type_uid });
        },
        .unit_type => try writer.print("void", .{}),
        .annotation => try output_type(_type.annotation.type, writer),
        else => std.debug.panic("compiler error: unimplemented output_type() for {?}", .{_type.*}),
    }
}

/// Outputs the C code for a basic-block in the given control flow graph.
fn output_basic_block(
    cfg: *cfg_.CFG, // TODO: Accept cfg block graph head
    start_bb: *basic_block_.Basic_Block,
    return_symbol: *symbol_.Symbol,
    writer: Writer,
) CodeGen_Error!void {
    // FIXME: High Cyclo
    var bb_queue = std.ArrayList(*basic_block_.Basic_Block).init(std.heap.page_allocator); // page alloc ok, immediately deinit'd
    defer bb_queue.deinit();
    bb_queue.append(start_bb) catch unreachable;
    start_bb.visited = true;

    // Output basic-blocks in BFS order
    var head: usize = 0;
    while (head < bb_queue.items.len) {
        const bb: *basic_block_.Basic_Block = bb_queue.items[head];
        head += 1;

        const is_head_bb = cfg.block_graph_head != null and cfg.block_graph_head.? == bb;
        const more_than_one_incoming = bb.number_predecessors > 1;
        if (!is_head_bb or more_than_one_incoming) {
            // Do not output a label for a block that is never jumped to (gcc complains)
            try writer.print("BB{}:\n", .{bb.uid});
        }

        // Output Instruction instructions for the basic-block
        var maybe_instr = bb.instr_head;
        while (maybe_instr) |instr| : (maybe_instr = instr.next) {
            try output_instruction(instr, writer);
        }

        if (!bb.has_panic) {
            if (bb.has_branch) {
                // Generate the if
                try writer.print("    if (", .{});
                try output_rvalue(bb.condition.?, HIGHEST_PRECEDENCE, writer);
                try writer.print(") {{\n", .{});

                // Generate the `next` BB
                if (bb.next) |next| {
                    try writer.print("        goto BB{};\n    }}", .{next.uid});
                    if (!next.visited) {
                        bb_queue.append(next) catch unreachable;
                        next.visited = true;
                    }
                } else {
                    try writer.print("    ", .{});
                    try output_return(return_symbol, writer);
                    try writer.print("    }}", .{});
                }

                // Generate the `branch` BB if it isn't the next one up
                if (bb.branch) |branch| {
                    if (!branch.visited) {
                        bb_queue.append(branch) catch unreachable;
                        branch.visited = true;
                    }
                    try writer.print(" else {{\n        goto BB{};\n    }}\n", .{branch.uid});
                } else {
                    try writer.print(" else {{\n    ", .{});
                    try output_return(return_symbol, writer);
                    try writer.print("    }}\n", .{});
                }
            } else {
                if (bb.next) |next| {
                    if (!next.visited) {
                        bb_queue.append(next) catch unreachable;
                        next.visited = true;
                    }
                    try writer.print("    goto BB{};\n", .{next.uid});
                } else {
                    try output_return(return_symbol, writer);
                }
            }
        }
    }
}

/// Outputs the C code for an instruction.
fn output_instruction(instr: *ir_.Instruction, writer: Writer) CodeGen_Error!void {
    if (instr.dest != null) {
        try output_lvalue_check(instr.span, instr.dest.?, writer);
    }
    if (instr.src1 != null) {
        try output_lvalue_check(instr.span, instr.src1.?, writer);
    }
    if (instr.src2 != null) {
        try output_lvalue_check(instr.span, instr.src2.?, writer);
    }
    if (instr.data == .lval_list) {
        for (instr.data.lval_list.items) |lval| {
            try output_lvalue_check(instr.span, lval, writer);
        }
    }

    if (instr.dest != null and instr.dest.?.get_expanded_type().is_c_void_type() and instr.kind != .call and instr.kind != .invoke) {
        return;
    }

    try output_instruction_post_check(instr, writer);
}

/// Outputs the C code for an Instruction instruction after runtime checks have run.
fn output_instruction_post_check(instr: *ir_.Instruction, writer: Writer) CodeGen_Error!void {
    switch (instr.kind) {
        .load_unit => {
            // Do nothing!
        },
        .load_symbol => {
            if (instr.dest.?.get_expanded_type().* == .function) {
                try output_var_assign_cast(instr.dest.?, instr.dest.?.get_expanded_type(), writer);
            } else {
                try output_var_assign(instr.dest.?, writer);
            }
            try output_symbol(instr.data.symbol, writer);
            try writer.print(";\n", .{});
        },
        .load_int => {
            try output_var_assign(instr.dest.?, writer);
            try writer.print("{};\n", .{instr.data.int});
        },
        .load_float => {
            try output_var_assign(instr.dest.?, writer);
            try writer.print("{};\n", .{instr.data.float});
        },
        .load_string => {
            try output_var_assign_cast(instr.dest.?, instr.dest.?.get_expanded_type(), writer);
            try writer.print("{{(uint8_t*)string_{}, {}}};\n", .{
                instr.data.string_id.string_idx,
                cheat_module.interned_strings.items[instr.data.string_id.string_idx].len,
            });
        },
        .load_struct => {
            try output_var_assign_cast(instr.dest.?, instr.dest.?.get_expanded_type(), writer);
            try writer.print("{{", .{});
            var product_list = instr.dest.?.get_expanded_type().children().*;
            for (instr.data.lval_list.items, product_list.items, 1..) |term, expected, i| {
                if (!expected.is_c_void_type()) {
                    // Don't use values of type `void` (don't exist in C! (Goobersville!))
                    try output_rvalue(term, instr.kind.precedence(), writer);
                    if (i < product_list.items.len and !product_list.items[i - 1].is_c_void_type()) {
                        try writer.print(", ", .{});
                    }
                }
            }
            try writer.print("}};\n", .{});
        },
        .load_union => {
            try output_var_assign_cast(instr.dest.?, instr.dest.?.get_expanded_type(), writer);
            try writer.print("{{.tag={}", .{instr.data.int});
            if (instr.src1 != null and !instr.src1.?.get_expanded_type().is_c_void_type()) {
                try writer.print(", ._{}=", .{instr.data.int});
                try output_rvalue(instr.src1.?, instr.kind.precedence(), writer);
            }
            try writer.print("}};\n", .{});
        },
        .copy => {
            try output_var_assign(instr.dest.?, writer);
            try output_rvalue(instr.src1.?, instr.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .mut_addr_of, .addr_of => {
            try output_var_assign(instr.dest.?, writer);
            try output_lvalue(instr.src1.?, instr.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .mut_dyn_value, .dyn_value => {
            try output_var_assign_cast(instr.dest.?, instr.dest.?.get_expanded_type(), writer);
            try writer.print("{{", .{});
            try output_lvalue(instr.src1.?, instr.kind.precedence(), writer);
            try writer.print(", &", .{});
            try output_vtable_impl(instr.data.dyn.impl, writer);
            try writer.print("}};\n", .{});
        },
        .not,
        .negate_int,
        .negate_float,
        .bit_not,
        .equal,
        .not_equal,
        .greater_int,
        .greater_float,
        .greater_equal_int,
        .greater_equal_float,
        .lesser_int,
        .lesser_float,
        .lesser_equal_int,
        .lesser_equal_float,
        .add_int,
        .add_float,
        .sub_int,
        .sub_float,
        .mult_int,
        .mult_float,
        .div_int,
        .div_float,
        .mod,
        .bit_and,
        .bit_or,
        .bit_xor,
        .left_shift,
        .right_shift,
        => try output_operator(instr, writer),
        .get_tag => {
            try output_var_assign(instr.dest.?, writer);
            try output_rvalue(instr.src1.?, instr.kind.precedence(), writer);
            try writer.print(".tag;\n", .{});
        },
        .call => {
            // TODO: De-duplicate 2
            try output_call_prefix(instr, writer);
            try output_rvalue(instr.src1.?, instr.kind.precedence(), writer);
            try writer.print("(", .{});
            for (instr.data.lval_list.items, 0..) |term, i| {
                if (!term.get_expanded_type().is_c_void_type()) {
                    // Do not output `void` arguments
                    try output_rvalue(term, HIGHEST_PRECEDENCE, writer);
                    if (i + 1 < instr.data.lval_list.items.len and !instr.data.lval_list.items[i + 1].get_expanded_type().is_c_void_type()) {
                        try writer.print(", ", .{});
                    }
                }
            }
            try writer.print(");\n", .{});
        },
        .invoke => {
            // FIXME: High Cyclo
            try output_call_prefix(instr, writer);
            if (!instr.data.invoke.method_decl.method_decl.is_virtual) {
                // method is non-virtual
                // { method name }({ args })
                try output_rvalue(instr.data.invoke.method_decl_lval.?, 2, writer);
                try writer.print("(", .{});
            } else if (instr.data.invoke.dyn_value != null) {
                // method is virtual, dyn_value (receiver ptr + vtable ptr) isn't null
                // { dyn value }.vtable->{ method name }({ args })
                try output_rvalue(instr.data.invoke.dyn_value.?, 2, writer);
                try writer.print(".vtable->{s}(", .{instr.data.invoke.method_decl.method_decl.name.token().data});
            } else {
                // method is virtual, dyn_value is null
                // { vtable impl }.{ method name }({ args })
                try output_vtable_impl(instr.data.invoke.method_decl.method_decl.impl.?, writer);
                try writer.print(".{s}(", .{instr.data.invoke.method_decl.method_decl.name.token().data});
            }
            const num_invoke_args = instr.data.invoke.lval_list.items.len;
            for (instr.data.invoke.lval_list.items, 0..) |term, i| {
                if (!term.get_expanded_type().is_c_void_type()) {
                    // Do not output `void` arguments
                    try output_rvalue(term, HIGHEST_PRECEDENCE, writer);
                    if (instr.data.invoke.dyn_value != null and instr.data.invoke.dyn_value == term and i == 0) {
                        try writer.print(".data_ptr", .{});
                    }
                    if (i + 1 < num_invoke_args and !instr.data.invoke.lval_list.items[i + 1].get_expanded_type().is_c_void_type()) {
                        try writer.print(", ", .{});
                    }
                }
            }
            try writer.print(");\n", .{});
        },
        .label,
        .jump,
        .branch_if_false,
        => {},
        .push_stack_trace => {
            var spaces = String.init(std.heap.page_allocator); // page alloc ok, immediately deinit'd
            defer spaces.deinit();
            for (1..instr.span.col - 1) |_| {
                spaces.insert(" ", spaces.size) catch unreachable;
            }
            try writer.print("    $lines[$line_idx++] = ", .{});
            try instr.span.print_debug_line(writer, span_.c_format);
            try writer.print(";\n", .{});
        },
        .pop_stack_trace => {
            try writer.print(
                \\    $line_idx--;
                \\
            , .{});
        },
        .panic => {
            try writer.print(
                \\    $panic("{s}\n");
                \\
            ,
                .{instr.data.string},
            );
        },
        else => std.debug.panic("compiler error: unimplemented output_IR() for: Kind.{s}", .{@tagName(instr.kind)}),
    }
}

/// Outputs C code for the prefix of a call
fn output_call_prefix(instr: *ir_.Instruction, writer: anytype) !void {
    const void_fn = instr.dest.?.get_expanded_type().is_c_void_type();
    const symbol_used = if (instr.dest.?.* == .symbver) instr.dest.?.symbver.symbol.uses > 0 else false;
    if (!symbol_used) {
        try writer.print("    (void) ", .{});
    } else if (!void_fn) {
        try output_var_assign(instr.dest.?, writer);
    } else {
        try writer.print("    ", .{});
    }
}

/// Outputs the C code for checking lvalue operations. The current checks are:
/// - Index bounds check
/// - Tag check on union selects
fn output_lvalue_check(span: span_.Span, lvalue: *lval_.L_Value, writer: Writer) CodeGen_Error!void {
    switch (lvalue.*) {
        .symbver => {},
        .dereference => try output_lvalue_check(span, lvalue.dereference.expr, writer),
        .index => {
            try output_lvalue_check(span, lvalue.index.lhs, writer);
            try output_lvalue_check(span, lvalue.index.rhs, writer);

            if (lvalue.index.length != null) {
                try writer.print("    $bounds_check(", .{});
                try output_rvalue(lvalue.index.rhs, HIGHEST_PRECEDENCE, writer); // idx
                try writer.print(", ", .{});
                try output_rvalue(lvalue.index.length.?, HIGHEST_PRECEDENCE, writer); // length
                try writer.print(", ", .{});
                try span.print_debug_line(writer, span_.c_format);
                try writer.print(");\n", .{});
            }
        },
        .select => {
            try output_lvalue_check(span, lvalue.select.lhs, writer);

            if (lvalue.select.tag != null) {
                try writer.print("    $tag_check(", .{});
                try output_rvalue(lvalue.select.tag.?, HIGHEST_PRECEDENCE, writer); // tag
                try writer.print(", {}, ", .{lvalue.select.field});
                try span.print_debug_line(writer, span_.c_format);
                try writer.print(");\n", .{});
            }
        },
        .raw_address => std.debug.panic("compiler error: cannot output raw address lvalue", .{}),
    }
}

/// Outputs the C code for an rvalue expression based on the provided lvalue.
fn output_rvalue(lvalue: *lval_.L_Value, outer_precedence: i128, writer: Writer) CodeGen_Error!void {
    if (outer_precedence < lvalue.lval_precedence()) {
        // Opening paren, if needed by precedence
        try writer.print("(", .{});
    }
    switch (lvalue.*) {
        .dereference => {
            try writer.print("*", .{});
            if (lvalue.dereference.expr.get_expanded_type().addr_of.anytptr) {
                // Cast from `void*` to true pointer before dereferencing
                try writer.print("(", .{});
                try output_type(lvalue.get_expanded_type(), writer);
                try writer.print("*)", .{});
            }
            try output_rvalue(lvalue.dereference.expr, lvalue.lval_precedence(), writer);
        },
        .index => {
            try writer.print("*", .{});
            try output_lvalue(lvalue, lvalue.lval_precedence(), writer);
        },
        .select => {
            try output_rvalue(lvalue.select.lhs, lvalue.lval_precedence(), writer); // This will dereference, no need for `->`
            const unexpanded_type: ?*ast_.AST = lvalue.select.lhs.get_expanded_type().common()._unexpanded_type;
            if (unexpanded_type != null and unexpanded_type.?.* == .identifier and unexpanded_type.?.symbol() != null and unexpanded_type.?.symbol().?.kind == .@"extern") {
                // Select the nominal C name
                const field_name = lvalue.select.lhs.get_expanded_type().children().items[@intCast(lvalue.select.field)].annotation.pattern.token().data;
                try writer.print(".{s}", .{field_name});
            } else {
                // Select the structural Orng name
                try writer.print("._{}", .{lvalue.select.field});
            }
        },
        .symbver => try output_symbol(lvalue.symbver.symbol, writer),
        .raw_address => std.debug.panic("compiler error: cannot output raw address lvalue", .{}),
    }
    if (outer_precedence < lvalue.lval_precedence()) {
        // Closing paren, if needed by precedence
        try writer.print(")", .{});
    }
}

/// Outputs the C code for an lvalue expression.
fn output_lvalue(lvalue: *lval_.L_Value, outer_precedence: i128, writer: Writer) CodeGen_Error!void {
    if (lvalue.expanded_type_sizeof() == 0) {
        try writer.print("(void*) 0xAAAAAAAA", .{});
        return;
    }
    switch (lvalue.*) {
        .dereference => {
            // lvalue of a dereference is just the rvalue of it's expression
            try output_rvalue(lvalue.dereference.expr, outer_precedence, writer);
        },
        .index => {
            try writer.print("(", .{});

            // Generate reinterpret cast to pointer of elements
            try writer.print("(", .{});
            try output_type(lvalue.get_expanded_type(), writer);
            try writer.print("*)", .{});
            if (lvalue.index.lhs.get_expanded_type().* == .addr_of) {
                // Index of a multiptr addr, lvalue is simply the rvalue
                std.debug.assert(lvalue.index.lhs.get_expanded_type().addr_of.multiptr);
                try output_rvalue(lvalue.index.lhs, 2, writer);
            } else {
                // Index a slice, usual lvalue of lhs
                try output_lvalue(lvalue.index.lhs, 2, writer);
            }

            // Only generate index add if index is non-zero
            // NOTE: Do not generate checked addition. The index is already checked.
            try writer.print(" + ", .{});
            try output_rvalue(lvalue.index.rhs, lvalue.lval_precedence(), writer);

            try writer.print(")", .{});
        },
        .symbver, .select => {
            // For symbvers and selects, just print out the rvalue version, and take the address of it
            if (outer_precedence < 2) {
                try writer.print("(", .{});
            }
            try writer.print("&", .{});
            try output_rvalue(lvalue, 2, writer);
            if (outer_precedence < 2) { // TODO: De-magic number these
                try writer.print(")", .{});
            }
        },
        .raw_address => std.debug.panic("compiler error: cannot output raw address lvalue", .{}),
    }
}

/// Emits the return statement from a function
fn output_return(return_symbol: *symbol_.Symbol, writer: Writer) CodeGen_Error!void {
    try writer.print("    return", .{});
    if (return_symbol.defs > 0 and !return_symbol.expanded_type.?.is_c_void_type()) {
        try writer.print(" ", .{});
        try output_symbol(return_symbol, writer);
    }
    try writer.print(";\n", .{});
}

/// Outputs an assignment to a symbol template. It is expected that a value is output immediately
/// after this to complete the assignment.
fn output_var_assign(lval: *lval_.L_Value, writer: Writer) CodeGen_Error!void {
    try writer.print("    ", .{});
    try output_rvalue(lval, HIGHEST_PRECEDENCE, writer);
    try writer.print(" = ", .{});
}

/// Outputs the C code for assigning a value to a variable with a cast.
fn output_var_assign_cast(lval: *lval_.L_Value, _type: *ast_.AST, writer: Writer) CodeGen_Error!void {
    try output_var_assign(lval, writer);
    try writer.print("(", .{});
    try output_type(_type, writer);
    try writer.print(") ", .{});
}

/// Outputs the C code for an operator from an Instruction.
fn output_operator(instr: *ir_.Instruction, writer: Writer) CodeGen_Error!void {
    try output_var_assign(instr.dest.?, writer);
    if (instr.kind.is_checked() and instr.dest.?.get_expanded_type().can_expanded_represent_int()) { // TODO: Check if checked operations are enabled, too
        try writer.print("${s}_{s}(", .{ instr.kind.checked_name(), primitives_.info_from_ast(instr.dest.?.get_expanded_type()).?.c_name });
        try output_rvalue(instr.src1.?, instr.kind.precedence(), writer);
        try writer.print(", ", .{});
        if (instr.kind.arity() == .binop) {
            try output_rvalue(instr.src2.?, instr.kind.precedence(), writer);
            try writer.print(", ", .{});
        }
        try instr.span.print_debug_line(writer, span_.c_format);
        try writer.print(")", .{});
    } else if (instr.kind.arity() == .unop) {
        // Unop, no-check
        try writer.print("{s}", .{instr.kind.c_token()});
        try output_rvalue(instr.src1.?, instr.kind.precedence(), writer);
    } else {
        // Binop, no-check
        try output_rvalue(instr.src1.?, instr.kind.precedence(), writer);
        try writer.print("{s}", .{instr.kind.c_token()});
        try output_rvalue(instr.src2.?, instr.kind.precedence(), writer);
    }
    try writer.print(";\n", .{});
}

/// Prints out the vtable name given an impl AST
fn output_vtable_impl(
    impl: *ast_.AST,
    writer: Writer,
) CodeGen_Error!void {
    try writer.print("_{}_$vtable", .{impl.scope().?.uid});
}
