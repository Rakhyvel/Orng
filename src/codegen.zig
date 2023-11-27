const _ast = @import("ast.zig");
const ir_ = @import("ir.zig");
const primitives = @import("primitives.zig");
const module_ = @import("module.zig");
const span_ = @import("span.zig");
const std = @import("std");
const strings = @import("zig-string/zig-string.zig");
const _symbol = @import("symbol.zig");

const AST = _ast.AST;
const BasicBlock = ir_.BasicBlock;
const CFG = ir_.CFG;
const IR = ir_.IR;
const IRKind = ir_.IRKind;
const Module = module_.Module;
const Scope = _symbol.Scope;
const Span = span_.Span;
const String = strings.String;
const Symbol = _symbol.Symbol;
const SymbolVersion = ir_.SymbolVersion;

var cheat_module: *Module = undefined; // TODO: I hate this
const HIGHEST_PRECEDENCE = 100;

/// Takes in a file handler and a module structure
pub fn generate(module: *Module, writer: anytype) !void {
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

    try output_typedefs(&module.types, writer);
    try output_interned_strings(&module.interned_strings, writer);
    try writer.print("/* Function forward definitions */\n", .{});
    for (module.cfgs.items) |cfg| {
        if (cfg.symbol.decl.?.* == .fnDecl) { // Don't output for `_comptime` decls
            try output_forward_function(cfg, writer);
        }
    }
    try writer.print("\n/* Function definitions */\n", .{});
    for (module.cfgs.items) |cfg| {
        if (cfg.symbol.decl.?.* == .fnDecl) { // Don't output for `_comptime` decls
            try output_function_definition(cfg, writer);
        }
    }
    try output_main_function(module.entry, writer);
}

fn output_main_function(cfg: *CFG, writer: anytype) !void {
    if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Int") or
        std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Int64"))
    {
        try writer.print(
            \\int main(void) {{
            \\  printf("%ld",
        , .{});
    } else if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Word64")) {
        try writer.print(
            \\int main(void) {{
            \\  printf("%lu",
        , .{});
    } else if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Float64") or
        std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Float32") or
        std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Float"))
    {
        try writer.print(
            \\int main(void) {{
            \\  printf("%f",
        , .{});
    } else if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "String") or cfg.symbol._type.?.function.rhs.* == .product) {
        try writer.print(
            \\int main(void) {{
            \\  printf("%s",
        , .{});
    } else {
        try writer.print(
            \\int main(void) {{
            \\  printf("%d",
        , .{});
    }
    try output_symbol(cfg.symbol, writer);
    if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "String") or cfg.symbol._type.?.function.rhs.* == .product) {
        try writer.print(
            \\()._0);
            \\  return 0;
            \\}}
            \\
        , .{});
    } else {
        try writer.print(
            \\());
            \\  return 0;
            \\}}
            \\
        , .{});
    }
}

fn output_typedefs(dags: *std.ArrayList(*module_.DAG), writer: anytype) !void {
    if (dags.items.len > 0) {
        try writer.print("/* Typedefs */\n", .{});
    }
    for (dags.items) |dag| {
        try output_typedef(dag, writer);
    }
}

fn output_typedef(dag: *module_.DAG, writer: anytype) !void {
    if (dag.visited) {
        return;
    }
    dag.visited = true;

    for (dag.dependencies.items) |depen| {
        try output_typedef(depen, writer);
    }

    if (dag.base.* == .function) {
        try writer.print("typedef ", .{});
        try output_type(dag.base.function.rhs, writer);
        try writer.print("(*function{})(", .{dag.uid});
        if (dag.base.function.lhs.* == .product) {
            // Function pointer takes more than one argument
            const product = dag.base.function.lhs;
            for (product.product.terms.items, 0..) |term, i| {
                if (!term.c_typesMatch(primitives.unit_type)) {
                    // Do not output `void` parameters
                    try output_type(term, writer);
                    if (i + 1 < product.product.terms.items.len) {
                        try writer.print(", ", .{});
                    }
                }
            }
        } else {
            // Function pointer takes one argument
            try output_type(dag.base.function.lhs, writer);
        }
        try writer.print(");\n\n", .{});
    } else if (dag.base.* == .product) {
        try writer.print("typedef struct {{\n", .{});
        for (dag.base.product.terms.items, 0..) |term, i| {
            if (!term.c_typesMatch(primitives.unit_type)) {
                // Don't gen `void` structure fields
                try writer.print("    ", .{});
                try output_type(term, writer);
                try writer.print(" _{};\n", .{i});
            }
        }
        try writer.print("}} struct{};\n\n", .{dag.uid});
    } else if (dag.base.* == .sum) {
        try writer.print("typedef struct {{\n    uint64_t tag;\n", .{});
        if (!dag.base.sum.is_all_unit()) {
            try writer.print("    union {{\n", .{});
            for (dag.base.sum.terms.items, 0..) |term, i| {
                if (!term.annotation.type.c_typesMatch(primitives.unit_type)) {
                    // Don't gen `void` structure fields
                    try writer.print("        ", .{});
                    try output_type(term, writer);
                    try writer.print(" _{};\n", .{i});
                }
            }
            try writer.print("    }};\n", .{});
        }
        try writer.print("}} struct{};\n\n", .{dag.uid});
    }
}

fn output_interned_strings(interned_strings: *std.ArrayList([]const u8), writer: anytype) !void {
    if (interned_strings.items.len > 0) {
        try writer.print("/* Interned Strings */\n", .{});
    }
    for (interned_strings.items, 0..) |str, i| {
        try writer.print("char* string_{} = \"", .{i});
        for (str) |byte| {
            try writer.print("\\x{X:0>2}", .{byte});
        }
        try writer.print("\";\n", .{});
    }
    if (interned_strings.items.len > 0) {
        try writer.print("\n", .{});
    }
}

fn output_forward_function(cfg: *CFG, writer: anytype) !void {
    try output_type(cfg.symbol.expanded_type.?.function.rhs, writer);
    try writer.print(" ", .{});
    try output_symbol(cfg.symbol, writer);
    try writer.print("(", .{});
    for (cfg.symbol.decl.?.fnDecl.param_symbols.items, 0..) |param, i| {
        if (!param.expanded_type.?.c_typesMatch(primitives.unit_type)) {
            // Print out parameter declarations
            try output_var_decl(param, writer, true);
            if (i + 1 < cfg.symbol.decl.?.fnDecl.param_symbols.items.len) {
                try writer.print(",", .{});
            }
        }
    }
    if (cfg.symbol.decl.?.fnDecl.param_symbols.items.len == 0) {
        // If there are no parameters, mark as void
        try writer.print("void", .{});
    }
    try writer.print(");\n", .{});
}

fn output_function_definition(cfg: *CFG, writer: anytype) !void {
    // Print function return type, name, parameter list
    try output_type(cfg.symbol.expanded_type.?.function.rhs, writer);
    try writer.print(" ", .{});
    try output_symbol(cfg.symbol, writer);
    try writer.print("(", .{});
    for (cfg.symbol.decl.?.fnDecl.param_symbols.items, 0..) |param, i| {
        if (!param.expanded_type.?.c_typesMatch(primitives.unit_type)) {
            // Print out parameter declarations
            try output_var_decl(param, writer, true);
            if (i + 1 < cfg.symbol.decl.?.fnDecl.param_symbols.items.len) {
                try writer.print(",", .{});
            }
        }
    }
    if (cfg.symbol.decl.?.fnDecl.param_symbols.items.len == 0) {
        // If there are no parameters, mark as void
        try writer.print("void", .{});
    }
    try writer.print(") {{\n", .{});

    // Collect and then declare all local variables
    for (cfg.symbvers.items) |symbver| {
        try output_var_decl(symbver.symbol, writer, false);
        symbver.symbol.decld = true;
    }

    for (cfg.symbol.decl.?.fnDecl.param_symbols.items) |param| {
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
        cfg.clearVisitedBBs();
    }

    try writer.print("}}\n\n", .{});
}

fn output_basic_block(cfg: *CFG, start_bb: *BasicBlock, symbol: *Symbol, writer: anytype) !void {
    var bb_queue = std.ArrayList(*BasicBlock).init(std.heap.page_allocator); // Seriously? No circular buffer? Or any kind of queue? DoublyLinkedList is awful btw
    defer bb_queue.deinit();
    try bb_queue.append(start_bb);
    start_bb.visited = true;

    var head: usize = 0;
    while (head < bb_queue.items.len) {
        const bb: *BasicBlock = bb_queue.items[head];
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
                        try bb_queue.append(next);
                        next.visited = true;
                    }
                } else {
                    try writer.print("    ", .{});
                    try printReturn(symbol, writer);
                    try writer.print("    }}", .{});
                }

                // Generate the `branch` BB if it isn't the next one up
                if (bb.branch) |branch| {
                    if (!branch.visited) {
                        try bb_queue.append(branch);
                        branch.visited = true;
                    }
                    try writer.print(" else {{\n        goto BB{};\n    }}\n", .{branch.uid});
                } else {
                    try writer.print("    ", .{});
                    try printReturn(symbol, writer);
                    try writer.print("    }}\n", .{});
                }
            } else {
                if (bb.next) |next| {
                    if (!next.visited) {
                        try bb_queue.append(next);
                        next.visited = true;
                    }
                    try writer.print("    goto BB{};\n", .{next.uid});
                } else {
                    try printReturn(symbol, writer);
                }
            }
        }
    }
}

fn output_IR(ir: *IR, writer: anytype) !void {
    if (ir.meta == .bounds_check) {
        var spaces = String.init(std.heap.page_allocator);
        defer spaces.deinit();
        for (1..ir.span.col - 1) |i| {
            _ = i;
            try spaces.insert(" ", spaces.size);
        }
        try writer.print("    $bounds_check(", .{});
        try output_lvalue(ir.src2.?, HIGHEST_PRECEDENCE, writer); // idx
        try writer.print(", ", .{});
        try output_rvalue(ir.meta.bounds_check.length, HIGHEST_PRECEDENCE, writer); // length
        try writer.print(", ", .{});
        try ir.span.print_debug_line(writer, span_.c_format);
        try writer.print(");\n", .{});
    } else if (ir.meta == .active_field_check) {
        var spaces = String.init(std.heap.page_allocator);
        defer spaces.deinit();
        for (1..ir.span.col - 1) |i| {
            _ = i;
            try spaces.insert(" ", spaces.size);
        }
        try writer.print("    $tag_check(", .{});
        try output_rvalue(ir.meta.active_field_check.tag, HIGHEST_PRECEDENCE, writer); // tag
        try writer.print(", {}, ", .{ir.meta.active_field_check.selection});
        try ir.span.print_debug_line(writer, span_.c_format);
        try writer.print(");\n", .{});
    }

    if (ir.dest != null and ir.dest.?.get_type().* == .unit and ir.kind != .call) {
        return;
    }

    switch (ir.kind) {
        .loadSymbol => {
            try output_var_assign(ir.dest.?, writer);
            try output_symbol(ir.data.symbol, writer);
            try writer.print(";\n", .{});
        },
        .loadInt => {
            try output_var_assign(ir.dest.?, writer);
            try writer.print("{}", .{ir.data.int});
            try writer.print(";\n", .{});
        },
        .loadFloat => {
            try output_var_assign(ir.dest.?, writer);
            try writer.print("{}", .{ir.data.float});
            try writer.print(";\n", .{});
        },
        .loadString => {
            try output_var_assign(ir.dest.?, writer);
            try writer.print("(", .{});
            try output_type(ir.dest.?.get_expanded_type(), writer);
            try writer.print(") {{(uint8_t*)string_{}, {}}}", .{ ir.data.string_id, cheat_module.interned_strings.items[ir.data.string_id].len });
            try writer.print(";\n", .{});
        },
        .loadStruct => {
            try output_var_assign(ir.dest.?, writer);
            try writer.print("(", .{});
            try output_type(ir.dest.?.get_expanded_type(), writer);
            try writer.print(") {{", .{});
            var product_list = ir.dest.?.get_expanded_type().product.terms;
            for (ir.data.lval_list.items, product_list.items, 1..) |lval, expected, i| {
                if (!expected.c_typesMatch(primitives.unit_type)) {
                    // Don't use values of type `void` (don't exist in C! (Goobersville!))
                    try output_rvalue(lval, ir.kind.precedence(), writer);
                    if (i < product_list.items.len and !product_list.items[i - 1].c_typesMatch(primitives.unit_type)) {
                        try writer.print(", ", .{});
                    }
                }
            }
            try writer.print("}}", .{});
            try writer.print(";\n", .{});
        },
        .loadUnion => {
            try output_var_assign(ir.dest.?, writer);
            try writer.print("(", .{});
            try output_type(ir.dest.?.get_expanded_type(), writer);
            try writer.print(") {{.tag={}", .{ir.data.int});
            if (ir.src1) |init| {
                try writer.print(", ._{}=", .{ir.data.int});
                try output_rvalue(init, ir.kind.precedence(), writer);
            }
            try writer.print("}}", .{});
            try writer.print(";\n", .{});
        },

        // Monadic instructions
        .copy => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .not => {
            try output_var_assign(ir.dest.?, writer);
            try writer.print("!", .{});
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .addrOf => {
            try output_var_assign(ir.dest.?, writer);
            try output_lvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .negate_int, .negate_float => {
            try output_var_assign(ir.dest.?, writer);
            if (primitives.represents_signed_primitive(ir.dest.?.get_expanded_type())) {
                try writer.print("$negate_{s}(", .{primitives.from_ast(ir.dest.?.get_expanded_type()).c_name});
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer, span_.c_format);
                try writer.print(")", .{});
            } else {
                try writer.print("-", .{});
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            }
            try writer.print(";\n", .{});
        },

        // Diadic instructions
        .equal => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" == ", .{});
            try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .not_equal => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" != ", .{});
            try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .greater_int, .greater_float => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" > ", .{});
            try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .greater_equal_int, .greater_equal_float => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" >= ", .{});
            try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .lesser_int, .lesser_float => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" < ", .{});
            try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .lesser_equal_int, .lesser_equal_float => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" <= ", .{});
            try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            try writer.print(";\n", .{});
        },
        .add_int, .add_float => {
            try output_var_assign(ir.dest.?, writer);
            if (primitives.represents_signed_primitive(ir.dest.?.get_expanded_type())) {
                try writer.print("$add_{s}(", .{primitives.from_ast(ir.dest.?.get_expanded_type()).c_name});
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer, span_.c_format);
                try writer.print(")", .{});
            } else {
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" + ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            }
            try writer.print(";\n", .{});
        },
        .sub_int, .sub_float => {
            try output_var_assign(ir.dest.?, writer);
            if (primitives.represents_signed_primitive(ir.dest.?.get_expanded_type())) {
                try writer.print("$sub_{s}(", .{primitives.from_ast(ir.dest.?.get_expanded_type()).c_name});
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer, span_.c_format);
                try writer.print(")", .{});
            } else {
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" - ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            }
            try writer.print(";\n", .{});
        },
        .mult_int, .mult_float => {
            try output_var_assign(ir.dest.?, writer);
            if (primitives.represents_signed_primitive(ir.dest.?.get_expanded_type())) {
                try writer.print("$mult_{s}(", .{primitives.from_ast(ir.dest.?.get_expanded_type()).c_name});
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer, span_.c_format);
                try writer.print(")", .{});
            } else {
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" * ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            }
            try writer.print(";\n", .{});
        },
        .div_int, .div_float => {
            try output_var_assign(ir.dest.?, writer);
            if (primitives.represents_signed_primitive(ir.dest.?.get_expanded_type())) {
                try writer.print("$div_{s}(", .{primitives.from_ast(ir.dest.?.get_expanded_type()).c_name});
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer, span_.c_format);
                try writer.print(")", .{});
            } else {
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" / ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            }
            try writer.print(";\n", .{});
        },
        .mod => {
            try output_var_assign(ir.dest.?, writer);
            if (primitives.represents_signed_primitive(ir.dest.?.get_expanded_type())) {
                try writer.print("$mod_{s}(", .{primitives.from_ast(ir.dest.?.get_expanded_type()).c_name});
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer, span_.c_format);
                try writer.print(")", .{});
            } else {
                try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" % ", .{});
                try output_rvalue(ir.src2.?, ir.kind.precedence(), writer);
            }
            try writer.print(";\n", .{});
        },
        .get_tag => {
            try output_var_assign(ir.dest.?, writer);
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(".tag", .{});
            try writer.print(";\n", .{});
        },

        .call => {
            const void_fn = ir.dest.?.get_type().* == .unit;
            if (!void_fn) {
                try output_var_assign(ir.dest.?, writer);
            } else {
                try writer.print("    ", .{});
            }
            try output_rvalue(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print("(", .{});
            for (ir.data.lval_list.items, 0..) |lval, i| {
                try output_rvalue(lval, HIGHEST_PRECEDENCE, writer);
                if (i + 1 != ir.data.lval_list.items.len) {
                    try writer.print(", ", .{});
                }
            }
            try writer.print(")", .{});
            try writer.print(";\n", .{});
        },

        // Control-flow
        .label,
        .jump,
        .branchIfFalse,
        => {},
        else => {
            std.debug.print("Unimplemented output_IR() for: IRKind.{s}\n", .{@tagName(ir.kind)});
            return error.Unimplemented;
        },

        // Errors
        .pushStackTrace => {
            var spaces = String.init(std.heap.page_allocator);
            defer spaces.deinit();
            for (1..ir.span.col - 1) |i| {
                _ = i;
                try spaces.insert(" ", spaces.size);
            }
            try writer.print("    $lines[$line_idx++] = ", .{});
            try ir.span.print_debug_line(writer, span_.c_format);
            try writer.print(";\n", .{});
        },
        .popStackTrace => {
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
        .discard => if (ir.src1.?.get_expanded_type().* != .unit) {
            try writer.print("    (void)", .{});
            try output_rvalue(ir.src1.?, IRKind.cast.precedence(), writer);
            try writer.print(";\n", .{});
        },
    }
}

fn output_lvalue(lvalue: *ir_.L_Value, outer_precedence: i128, writer: anytype) CodeGen_Error!void {
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

fn output_rvalue(lvalue: *ir_.L_Value, outer_precedence: i128, writer: anytype) CodeGen_Error!void {
    switch (lvalue.*) {
        .dereference => {
            if (outer_precedence < lvalue.precedence()) {
                try writer.print("(", .{});
            }
            try writer.print("*", .{});
            try output_rvalue(lvalue.dereference.expr, lvalue.precedence(), writer);
            if (outer_precedence < lvalue.precedence()) {
                try writer.print(")", .{});
            }
        },
        .index => {
            if (outer_precedence < lvalue.precedence()) {
                try writer.print("(", .{});
            }
            try writer.print("*", .{});
            try output_lvalue(lvalue, lvalue.precedence(), writer);
            if (outer_precedence < lvalue.precedence()) {
                try writer.print(")", .{});
            }
        },
        .select => {
            if (outer_precedence < lvalue.precedence()) {
                // Opening paren, if needed by precedence
                try writer.print("(", .{});
            }

            // Output lhs of select
            try output_rvalue(lvalue.select.lhs, lvalue.precedence(), writer); // This will dereference, no need for `->`
            try writer.print("._{}", .{lvalue.select.field});

            if (outer_precedence < lvalue.precedence()) {
                // Closing paren, if needed by precedence
                try writer.print(")", .{});
            }
        },
        .symbver => {
            try output_symbol(lvalue.symbver.symbol, writer);
        },
    }
}

fn output_type(_type: *AST, writer: anytype) CodeGen_Error!void {
    switch (_type.*) {
        .identifier => { // TODO: Print out identifier's expanded_type, make prelude types extern types
            if (_type.getCommon().expanded_type.? != _type) {
                try output_type(_type.getCommon().expanded_type.?, writer);
            } else {
                try writer.print("{s}", .{primitives.get(_type.getToken().data).c_name});
            }
        },
        .addrOf => {
            try output_type(_type.addrOf.expr, writer);
            try writer.print("*", .{});
        },
        .function => {
            const i = (module_.type_set_get(_type, &cheat_module.types)).?.uid;
            try writer.print("function{}", .{i});
        },
        .sum, .product => {
            const i = (module_.type_set_get(_type, &cheat_module.types)).?.uid;
            try writer.print("struct{}", .{i});
        },
        .unit => {
            try writer.print("void", .{});
        },
        .annotation => {
            try output_type(_type.annotation.type, writer);
        },
        else => {
            std.debug.print("Unimplemented output_type() for {?}", .{_type.*});
            unreachable;
        },
    }
}

/// Outputs an assignment to a symbol template. It is expected that a value is output immediately
/// after this to complete the assignment.
fn output_var_assign(lval: *ir_.L_Value, writer: anytype) !void {
    try writer.print("    ", .{});
    try output_rvalue(lval, HIGHEST_PRECEDENCE, writer);
    try writer.print(" = ", .{});
}

/// Outputs a symbol's declaration. Parameters are not formatted with a preceding tab, nor a
/// semicolon nor newline.
/// TODO: No bool parameters!
fn output_var_decl(symbol: *Symbol, writer: anytype, is_parameter: bool) !void {
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
fn output_symbol(symbol: *Symbol, writer: anytype) !void {
    try writer.print("_{}_{s}", .{ symbol.scope.uid, symbol.name });
}

const CodeGen_Error = error{
    DiskQuota,
    FileTooBig,
    InputOutput,
    NoSpaceLeft,
    DeviceBusy,
    InvalidArgument,
    AccessDenied,
    BrokenPipe,
    SystemResources,
    OperationAborted,
    NotOpenForWriting,
    LockViolation,
    WouldBlock,
    ConnectionResetByPeer,
    Unexpected,
    OutOfMemory,
    typeError,
    Unimplemented,
    InvalidRange,
    NotAnLValue,
};

/// Emits the return statement from a function
fn printReturn(return_symbol: *Symbol, writer: anytype) !void {
    if (return_symbol.versions > 0) { // To fix errors when function ends in `unreachable`
        try writer.print("    return ", .{});
        try output_symbol(return_symbol, writer);
        try writer.print(";\n", .{});
    }
}
