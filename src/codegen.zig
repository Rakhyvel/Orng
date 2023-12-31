const std = @import("std");
const ast_ = @import("ast.zig");
const basic_block_ = @import("basic-block.zig");
const cfg_ = @import("cfg.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const primitives_ = @import("primitives.zig");
const module_ = @import("module.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;
const type_set_ = @import("type-set.zig");
const symbol_ = @import("symbol.zig");

var cheat_module: *module_.Module = undefined; // TODO: I hate this
const HIGHEST_PRECEDENCE = 100;

const CodeGen_Error = std.fs.File.WriteError;
const Writer = std.fs.File.Writer;

/// Takes in a file handler and a module structure
pub fn generate(module: *module_.Module, writer: Writer) CodeGen_Error!void {
    cheat_module = module;
    try writer.print(
        \\/* Code generated using the Orng compiler https://ornglang.org */
        \\#include <math.h>
        \\#include <stdio.h>
        \\#include <stdint.h>
        \\#include <stdlib.h>
        \\
        \\#include "debug.inc"
        \\
        \\
    , .{});

    try output_typedefs(&module.type_set, writer);
    try output_interned_strings(&module.interned_strings, writer);
    try forall_functions(&module.cfgs, "/* Function forward definitions */", writer, output_forward_function);
    try forall_functions(&module.cfgs, "\n/* Function definitions */", writer, output_function_definition);
    try output_main_function(module.entry, writer);
}

fn output_typedefs(type_set: *type_set_.Type_Set, writer: Writer) CodeGen_Error!void {
    if (type_set.types.items.len > 0) {
        try writer.print("/* Typedefs */\n", .{});
    }
    for (type_set.types.items) |dag| {
        try output_typedef(dag, writer);
    }
}

fn output_typedef(dag: *type_set_.DAG, writer: Writer) CodeGen_Error!void {
    if (dag.visited) {
        return;
    }
    dag.visited = true;

    for (dag.dependencies.items) |depen| {
        try output_typedef(depen, writer);
    }

    if (dag.base.* == .function) {
        try writer.print("typedef ", .{});
        try output_type(dag.base.rhs(), writer);
        try writer.print("(*function{})(", .{dag.uid});
        if (dag.base.lhs().* == .product) {
            // Function pointer takes more than one argument
            const product = dag.base.lhs();
            for (product.children().items, 0..) |term, i| {
                if (!term.c_types_match(primitives_.unit_type)) {
                    // Do not output `void` parameters
                    try output_type(term, writer);
                    if (i + 1 < product.children().items.len) {
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
        try writer.print("typedef struct {{\n", .{});
        try output_field_list(dag.base.children(), writer);
        try writer.print("}} struct{};\n\n", .{dag.uid});
    } else if (dag.base.* == .sum) {
        try writer.print("typedef struct {{\n    uint64_t tag;\n", .{});
        if (!dag.base.sum.is_all_unit()) {
            try writer.print("    union {{\n", .{});
            try output_field_list(dag.base.children(), writer);
            try writer.print("    }};\n", .{});
        }
        try writer.print("}} struct{};\n\n", .{dag.uid});
    }
}

fn output_field_list(fields: *std.ArrayList(*ast_.AST), writer: Writer) CodeGen_Error!void {
    for (fields.items, 0..) |term, i| {
        if (!term.c_types_match(primitives_.unit_type)) {
            // Don't gen `void` structure fields
            try writer.print("        ", .{});
            try output_type(term, writer);
            try writer.print(" _{};\n", .{i});
        }
    }
}

fn output_interned_strings(interned_strings: *std.StringArrayHashMap(usize), writer: Writer) CodeGen_Error!void {
    const key_set = interned_strings.keys();
    if (key_set.len > 0) {
        try writer.print("/* Interned Strings */\n", .{});
    }
    for (0..key_set.len) |i| {
        const str = key_set[i];
        const id = interned_strings.get(str).?;
        try writer.print("char* string_{} = \"", .{id});
        for (str) |byte| {
            try writer.print("\\x{X:0>2}", .{byte});
        }
        try writer.print("\";\n", .{});
    }
    if (key_set.len > 0) {
        try writer.print("\n", .{});
    }
}

fn forall_functions(
    cfgs: *std.ArrayList(*cfg_.CFG),
    header_comment: []const u8,
    writer: Writer,
    comptime f: fn (*cfg_.CFG, Writer) CodeGen_Error!void,
) CodeGen_Error!void {
    try writer.print("{s}\n", .{header_comment});
    for (cfgs.items) |cfg| {
        if (cfg.symbol.decl.?.* == .fn_decl) { // Don't output for `_comptime` decls
            try f(cfg, writer);
        }
    }
}

fn output_forward_function(cfg: *cfg_.CFG, writer: Writer) CodeGen_Error!void {
    try output_function_prototype(cfg, writer);
    try writer.print(";\n", .{});
}

fn output_function_definition(cfg: *cfg_.CFG, writer: Writer) CodeGen_Error!void {
    try output_function_prototype(cfg, writer);
    try writer.print("{{\n", .{});

    // Collect and then declare all local variables
    for (cfg.symbvers.items) |symbver| {
        if (symbver.symbol.expanded_type.?.* == .unit_type) {
            continue; // Do not output unit variables
        }
        try output_var_decl(symbver.symbol, writer, false);
        symbver.symbol.decld = true;
    }

    for (cfg.symbol.decl.?.fn_decl.param_symbols.items) |param| {
        // Mark unused parameters as discarded
        // Do this only if they aren't discarded in source
        // Users can discard parameters, however used parameters may also become unused through optimizations
        if (param.uses == 0 and param.discards == 0) {
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

fn output_function_prototype(cfg: *cfg_.CFG, writer: Writer) CodeGen_Error!void {
    // Print function return type, name, parameter list
    try output_type(cfg.symbol.expanded_type.?.rhs(), writer);
    try writer.print(" ", .{});
    try output_symbol(cfg.symbol, writer);
    try writer.print("(", .{});
    var num_non_unit_params: i64 = 0;
    for (cfg.symbol.decl.?.fn_decl.param_symbols.items, 0..) |term, i| {
        if (!term.expanded_type.?.c_types_match(primitives_.unit_type)) {
            // Print out parameter declarations
            try output_var_decl(term, writer, true);
            if (i + 1 < cfg.symbol.decl.?.fn_decl.param_symbols.items.len) {
                try writer.print(", ", .{});
            }
            num_non_unit_params += 1;
        }
    }
    if (num_non_unit_params == 0) {
        // If there are no parameters, mark as void
        try writer.print("void", .{});
    }
    try writer.print(")", .{});
}

fn output_main_function(cfg: *cfg_.CFG, writer: Writer) CodeGen_Error!void {
    const codomain = cfg.symbol.expanded_type.?.rhs();
    var string_access: []const u8 = "";
    var specifier: []const u8 = undefined;
    switch (codomain.*) {
        .identifier => {
            const info = primitives_.get(codomain.token().data);
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
        else => unreachable,
    }
    try writer.print(
        \\int main(void) {{
        \\  printf("%{s}{s}",
    , .{ if (codomain.sizeof() == 8) "l" else "", specifier });
    try output_symbol(cfg.symbol, writer);
    try writer.print(
        \\(){s});
        \\  return 0;
        \\}}
        \\
    , .{string_access});
}

/// Outputs a symbol's declaration. Parameters are not formatted with a preceding tab, nor a
/// semicolon nor newline.
fn output_var_decl(symbol: *symbol_.Symbol, writer: Writer, is_parameter: bool) CodeGen_Error!void {
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

/// Outputs a symbol with it's unique identifier to a file
fn output_symbol(symbol: *symbol_.Symbol, writer: Writer) CodeGen_Error!void {
    try writer.print("_{}_{s}", .{ symbol.scope.uid, symbol.name });
}

fn output_type(_type: *ast_.AST, writer: Writer) CodeGen_Error!void {
    switch (_type.*) {
        .identifier => if (_type.common()._expanded_type.? != _type) {
            try output_type(_type.common()._expanded_type.?, writer);
        } else {
            try writer.print("{s}", .{primitives_.get(_type.token().data).c_name});
        },
        .addr_of => {
            try output_type(_type.expr(), writer);
            try writer.print("*", .{});
        },
        .function => {
            const i = (cheat_module.type_set.get(_type)).?.uid;
            try writer.print("function{}", .{i});
        },
        .sum, .product => {
            const i = (cheat_module.type_set.get(_type)).?.uid;
            try writer.print("struct{}", .{i});
        },
        .unit_type => try writer.print("void", .{}),
        .annotation => try output_type(_type.annotation.type, writer),
        else => {
            std.debug.print("Unimplemented output_type() for {?}", .{_type.*});
            unreachable;
        },
    }
}

fn output_basic_block(cfg: *cfg_.CFG, start_bb: *basic_block_.Basic_Block, return_symbol: *symbol_.Symbol, writer: Writer) CodeGen_Error!void {
    var bb_queue = std.ArrayList(*basic_block_.Basic_Block).init(std.heap.page_allocator);
    defer bb_queue.deinit();
    bb_queue.append(start_bb) catch unreachable;
    start_bb.visited = true;

    var head: usize = 0;
    while (head < bb_queue.items.len) {
        const bb: *basic_block_.Basic_Block = bb_queue.items[head];
        head += 1;

        const is_head_bb = cfg.block_graph_head != null and cfg.block_graph_head.? == bb;
        const more_than_one_incoming = bb.number_predecessors > 1;
        if (!is_head_bb or more_than_one_incoming) {
            try writer.print("BB{}:\n", .{bb.uid});
        }
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            try output_IR(ir, writer);
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
                    try writer.print("    ", .{});
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

fn output_IR(ir: *ir_.IR, writer: Writer) CodeGen_Error!void {
    if (ir.dest != null) {
        try output_lvalue_check(ir.span, ir.dest.?, writer);
    }
    if (ir.src1 != null) {
        try output_lvalue_check(ir.span, ir.src1.?, writer);
    }
    if (ir.src2 != null) {
        try output_lvalue_check(ir.span, ir.src2.?, writer);
    }
    if (ir.data == .lval_list) {
        for (ir.data.lval_list.items) |lval| {
            try output_lvalue_check(ir.span, lval, writer);
        }
    }

    if (ir.dest != null and ir.dest.?.get_type().* == .unit_type and ir.kind != .call) {
        return;
    }

    try output_IR_post_check(ir, writer);
}

fn output_IR_post_check(ir: *ir_.IR, writer: Writer) CodeGen_Error!void {
    switch (ir.kind) {
        .load_unit => {}, // Nop!
        .load_symbol => {
            try output_var_assign(ir.dest.?, writer);
            try output_symbol(ir.data.symbol, writer);
            try writer.print(";\n", .{});
        },
        .load_int => {
            try output_var_assign(ir.dest.?, writer);
            try writer.print("{};\n", .{ir.data.int});
        },
        .load_float => {
            try output_var_assign(ir.dest.?, writer);
            try writer.print("{};\n", .{ir.data.float});
        },
        .load_string => {
            try output_var_assign_cast(ir.dest.?, ir.dest.?.get_expanded_type(), writer);
            try writer.print("{{(uint8_t*)string_{}, {}}};\n", .{
                ir.data.string_id,
                cheat_module.interned_strings.keys()[ir.data.string_id].len,
            });
        },
        .load_struct => {
            try output_var_assign_cast(ir.dest.?, ir.dest.?.get_expanded_type(), writer);
            try writer.print("{{", .{});
            var product_list = ir.dest.?.get_expanded_type().children().*;
            for (ir.data.lval_list.items, product_list.items, 1..) |term, expected, i| {
                if (!expected.c_types_match(primitives_.unit_type)) {
                    // Don't use values of type `void` (don't exist in C! (Goobersville!))
                    try output_rvalue(term, ir.kind.precedence(), writer);
                    if (i < product_list.items.len and !product_list.items[i - 1].c_types_match(primitives_.unit_type)) {
                        try writer.print(", ", .{});
                    }
                }
            }
            try writer.print("}};\n", .{});
        },
        .load_union => {
            try output_var_assign_cast(ir.dest.?, ir.dest.?.get_expanded_type(), writer);
            try writer.print("{{.tag={}", .{ir.data.int});
            if (ir.src1 != null and ir.src1.?.get_expanded_type().* != .unit_type) {
                try writer.print(", ._{}=", .{ir.data.int});
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            }
            try writer.print("}};\n", .{});
        },
        .copy => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .addr_of => {
            try output_var_assign(ir.dest.?, writer);
            try output_lvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .not,
        .negate_int,
        .negate_float,
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
        => try output_operator(ir, writer),
        .get_tag => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(".tag;\n", .{});
        },
        .call => {
            const void_fn = ir.dest.?.get_type().* == .unit_type;
            if (!void_fn) {
                try output_var_assign(ir.dest.?, writer);
            } else {
                try writer.print("    ", .{});
            }
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print("(", .{});
            for (ir.data.lval_list.items, 0..) |term, i| {
                if (!term.get_expanded_type().c_types_match(primitives_.unit_type)) {
                    // Do not output `void` arguments
                    try output_rvalue(term, HIGHEST_PRECEDENCE, writer);
                    if (i + 1 < ir.data.lval_list.items.len) {
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
            var spaces = String.init(std.heap.page_allocator);
            defer spaces.deinit();
            for (1..ir.span.col - 1) |_| {
                spaces.insert(" ", spaces.size) catch unreachable;
            }
            try writer.print("    $lines[$line_idx++] = ", .{});
            try ir.span.print_debug_line(writer, span_.c_format);
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
                .{ir.data.string},
            );
        },
        .discard => if (ir.src1.?.get_expanded_type().* != .unit_type) {
            try writer.print("    (void)", .{});
            try output_rvalue(ir.src1.?, ir_.Kind.cast.precedence(), writer);
            try writer.print(";\n", .{});
        },
        else => {
            std.debug.print("Unimplemented output_IR() for: Kind.{s}\n", .{@tagName(ir.kind)});
            unreachable;
        },
    }
}

fn output_lvalue_check(span: span_.Span, lvalue: *lval_.L_Value, writer: Writer) CodeGen_Error!void {
    switch (lvalue.*) {
        .symbver => {},
        .dereference => try output_lvalue_check(span, lvalue.dereference.expr, writer),
        .index => {
            try output_lvalue_check(span, lvalue.index.lhs, writer);
            try output_lvalue_check(span, lvalue.index.rhs, writer);

            if (lvalue.index.upper_bound != null) {
                try writer.print("    $bounds_check(", .{});
                try output_rvalue(lvalue.index.rhs, HIGHEST_PRECEDENCE, writer); // idx
                try writer.print(", ", .{});
                try output_rvalue(lvalue.index.upper_bound.?, HIGHEST_PRECEDENCE, writer); // length
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
    }
}

fn output_rvalue(lvalue: *lval_.L_Value, outer_precedence: i128, writer: Writer) CodeGen_Error!void {
    if (outer_precedence < lvalue.precedence()) {
        // Opening paren, if needed by precedence
        try writer.print("(", .{});
    }
    switch (lvalue.*) {
        .dereference => {
            try writer.print("*", .{});
            try output_rvalue(lvalue.dereference.expr, lvalue.precedence(), writer);
        },
        .index => {
            try writer.print("*", .{});
            try output_lvalue(lvalue, lvalue.precedence(), writer);
        },
        .select => {
            try output_rvalue(lvalue.select.lhs, lvalue.precedence(), writer); // This will dereference, no need for `->`
            try writer.print("._{}", .{lvalue.select.field});
        },
        .symbver => try output_symbol(lvalue.symbver.symbol, writer),
    }
    if (outer_precedence < lvalue.precedence()) {
        // Closing paren, if needed by precedence
        try writer.print(")", .{});
    }
}

fn output_lvalue(lvalue: *lval_.L_Value, outer_precedence: i128, writer: Writer) CodeGen_Error!void {
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
            try output_lvalue(lvalue.index.lhs, 2, writer);

            // Only generate index add if index is non-zero
            // NOTE: Do not generate checked addition. The index is already checked.
            try writer.print(" + ", .{});
            try output_rvalue(lvalue.index.rhs, lvalue.precedence(), writer);

            try writer.print(")", .{});
        },
        .symbver, .select => {
            // For symbvers and selects, just print out the rvalue version, and take the address of it
            if (outer_precedence < 2) {
                try writer.print("(", .{});
            }
            try writer.print("&", .{});
            try output_rvalue(lvalue, 2, writer);
            if (outer_precedence < 2) {
                try writer.print(")", .{});
            }
        },
    }
}

/// Emits the return statement from a function
fn output_return(return_symbol: *symbol_.Symbol, writer: Writer) CodeGen_Error!void {
    try writer.print("    return", .{});
    if (return_symbol.versions > 0 and return_symbol.expanded_type.?.* != .unit_type) {
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

fn output_var_assign_cast(lval: *lval_.L_Value, _type: *ast_.AST, writer: Writer) CodeGen_Error!void {
    try output_var_assign(lval, writer);
    try writer.print("(", .{});
    try output_type(_type, writer);
    try writer.print(") ", .{});
}

fn output_operator(ir: *ir_.IR, writer: Writer) CodeGen_Error!void {
    try output_var_assign(ir.dest.?, writer);
    if (ir.kind.is_checked() and primitives_.represents_signed_primitive(ir.dest.?.get_expanded_type())) { // TODO: Check if checked operations are enabled, too
        try writer.print("${s}_{s}(", .{ ir.kind.checked_name(), primitives_.from_ast(ir.dest.?.get_expanded_type()).c_name });
        try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
        try writer.print(", ", .{});
        if (ir.kind.arity() == .binop) {
            try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            try writer.print(", ", .{});
        }
        try ir.span.print_debug_line(writer, span_.c_format);
        try writer.print(")", .{});
    } else if (ir.kind.arity() == .unop) {
        // Unop, no-check
        try writer.print("{s}", .{ir.kind.symbol()});
        try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
    } else {
        // Binop, no-check
        try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
        try writer.print("{s}", .{ir.kind.symbol()});
        try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
    }
    try writer.print(";\n", .{});
}
