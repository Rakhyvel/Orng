const _ast = @import("ast.zig");
const ir_ = @import("ir.zig");
const primitives = @import("primitives.zig");
const module_ = @import("module.zig");
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
const Span = @import("span.zig").Span;
const String = strings.String;
const Symbol = _symbol.Symbol;
const SymbolVersion = ir_.SymbolVersion;

var cheat_module: *Module = undefined; // I hate this
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

    try generateFunctionTypedefs(&module.types, writer);
    try generateInternedStrings(&module.interned_strings, writer);
    try writer.print("/* Function forward definitions */\n", .{});
    for (module.cfgs.items) |cfg| {
        try output_forward_function(cfg, writer);
    }
    try writer.print("\n/* Function definitions */\n", .{});
    for (module.cfgs.items) |cfg| {
        try output_function_definition(cfg, writer);
    }
    try generateMainFunction(module.cfg, writer);
}

fn generateFunctionTypedefs(dags: *std.ArrayList(*module_.DAG), writer: anytype) !void {
    if (dags.items.len > 0) {
        try writer.print("/* Typedefs */\n", .{});
    }
    for (dags.items) |dag| {
        try generateTypedefs(dag, writer);
    }
}

fn generateTypedefs(dag: *module_.DAG, writer: anytype) !void {
    if (dag.visited) {
        return;
    }
    dag.visited = true;

    for (dag.dependencies.items) |depen| {
        try generateTypedefs(depen, writer);
    }

    if (dag.base.* == .function) {
        try writer.print("typedef ", .{});
        try printType(dag.base.function.rhs, writer);
        try writer.print("(*function{})(", .{dag.uid});
        if (dag.base.function.lhs.* == .product) {
            // Function pointer takes more than one argument
            const product = dag.base.function.lhs;
            for (product.product.terms.items, 0..) |term, i| {
                try writer.print("    ", .{});
                try printType(term, writer);
                if (i + 1 < product.product.terms.items.len) {
                    try writer.print(", ", .{});
                }
            }
        } else {
            // Function pointer takes one argument
            try printType(dag.base.function.lhs, writer);
        }
        try writer.print(");\n\n", .{});
    } else if (dag.base.* == .product) {
        try writer.print("typedef struct {{\n", .{});
        for (dag.base.product.terms.items, 0..) |term, i| {
            if (!term.c_typesMatch(primitives.unit_type)) {
                // Don't gen `void` structure fields
                try writer.print("    ", .{});
                try printType(term, writer);
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
                    try printType(term, writer);
                    try writer.print(" _{};\n", .{i});
                }
            }
            try writer.print("    }};\n", .{});
        }
        try writer.print("}} struct{};\n\n", .{dag.uid});
    }
}

fn generateInternedStrings(interned_strings: *std.ArrayList([]const u8), writer: anytype) !void {
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
    try printType(cfg.symbol.expanded_type.?.function.rhs, writer);
    try writer.print(" ", .{});
    try printSymbol(cfg.symbol, writer);
    try writer.print("(", .{});
    for (cfg.symbol.decl.?.fnDecl.param_symbols.items, 0..) |param, i| {
        if (!param.expanded_type.?.c_typesMatch(primitives.unit_type)) {
            // Print out parameter declarations
            try printVarDecl(param, writer, true);
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
    try printType(cfg.symbol.expanded_type.?.function.rhs, writer);
    try writer.print(" ", .{});
    try printSymbol(cfg.symbol, writer);
    try writer.print("(", .{});
    for (cfg.symbol.decl.?.fnDecl.param_symbols.items, 0..) |param, i| {
        if (!param.expanded_type.?.c_typesMatch(primitives.unit_type)) {
            // Print out parameter declarations
            try printVarDecl(param, writer, true);
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
        if (symbver.hide_temporary() or symbver.symbol.versions == 0) {
            continue;
        }
        try printVarDecl(symbver.symbol, writer, false);
        symbver.symbol.decld = true;
    }

    for (cfg.symbol.decl.?.fnDecl.param_symbols.items) |param| {
        // Mark unused parameters as discarded
        // Do this only if they aren't discarded in source
        // Users can discard parameters, however used parameters may also become unused through optimizations
        if (param.uses == 0 and param.discards == 0) {
            try writer.print("    (void)", .{});
            try printSymbol(param, writer);
            try writer.print(";\n", .{});
        }
    }

    // Generate the basic-block graph, starting at the init basic block
    if (cfg.block_graph_head) |block_graph_head| {
        try generateBasicBlock(cfg, block_graph_head, cfg.return_symbol, writer);
        cfg.clearVisitedBBs();
    }

    try writer.print("}}\n\n", .{});
}

fn generateMainFunction(cfg: *CFG, writer: anytype) !void {
    if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Int") or
        std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Int64"))
    {
        try writer.print(
            \\int main(void)
            \\{{
            \\  printf("%ld",
        , .{});
    } else if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Word64")) {
        try writer.print(
            \\int main(void)
            \\{{
            \\  printf("%lu",
        , .{});
    } else if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Float64") or
        std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Float32") or
        std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "Float"))
    {
        try writer.print(
            \\int main(void)
            \\{{
            \\  printf("%f",
        , .{});
    } else if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "String")) {
        try writer.print(
            \\int main(void)
            \\{{
            \\  printf("%s",
        , .{});
    } else {
        try writer.print(
            \\int main(void)
            \\{{
            \\  printf("%d",
        , .{});
    }
    try printSymbol(cfg.symbol, writer);
    if (std.mem.eql(u8, cfg.symbol._type.?.function.rhs.getToken().data, "String")) {
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

fn generateBasicBlock(cfg: *CFG, start_bb: *BasicBlock, symbol: *Symbol, writer: anytype) !void {
    var bb_queue = std.ArrayList(*BasicBlock).init(std.heap.page_allocator); // Seriously? No circular buffer? Or any kind of queue? DoublyLinkedList is awful btw
    defer bb_queue.deinit();
    try bb_queue.append(start_bb);

    var head: usize = 0;
    while (head < bb_queue.items.len) {
        const bb: *BasicBlock = bb_queue.items[head];
        head += 1;

        const is_head_bb = cfg.block_graph_head != null and cfg.block_graph_head.? == bb;
        const no_incoming = bb.number_predecessors <= 1;
        if (!is_head_bb or !no_incoming) {
            // Only print the label if this basic block isn't the first one in the graph
            try writer.print("BB{}:\n", .{bb.uid});
        }
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            try generateIR(ir, writer);
        }

        if (!bb.has_panic) {
            if (bb.has_branch) {
                // Generate the if
                try writer.print("    if (", .{});
                try printSymbolVersion(bb.condition.?, HIGHEST_PRECEDENCE, writer);
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
                    if (head >= bb_queue.items.len or bb_queue.items[head].uid != branch.uid) {
                        try writer.print(" else {{\n        goto BB{};\n    }}\n", .{branch.uid});
                    } else {
                        try writer.print("\n", .{});
                    }
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
                    if (head >= bb_queue.items.len or bb_queue.items[head].uid != next.uid) {
                        try writer.print("    goto BB{};\n", .{next.uid});
                    }
                } else {
                    try printReturn(symbol, writer);
                }
            }
        }
    }
}

fn generateIR(ir: *IR, writer: anytype) !void {
    if (ir.meta == .bounds_check) {
        var spaces = String.init(std.heap.page_allocator);
        defer spaces.deinit();
        for (1..ir.span.col - 1) |i| {
            _ = i;
            try spaces.insert(" ", spaces.size);
        }
        try writer.print("    $bounds_check(", .{});
        try printSymbolVersion(ir.src2.?, HIGHEST_PRECEDENCE, writer); // idx
        try writer.print(", ", .{});
        try printSymbolVersion(ir.meta.bounds_check.length, HIGHEST_PRECEDENCE, writer); // length
        try writer.print(", ", .{});
        try ir.span.print_debug_line(writer);
        try writer.print(");\n", .{});
    } else if (ir.meta == .active_field_check) {
        var spaces = String.init(std.heap.page_allocator);
        defer spaces.deinit();
        for (1..ir.span.col - 1) |i| {
            _ = i;
            try spaces.insert(" ", spaces.size);
        }
        try writer.print("    $tag_check(", .{});
        try printSymbolVersion(ir.meta.active_field_check.tag, HIGHEST_PRECEDENCE, writer); // tag
        try writer.print(", {}, ", .{ir.meta.active_field_check.selection});
        try ir.span.print_debug_line(writer);
        try writer.print(");\n", .{});
    }

    if (ir.dest != null and ir.dest.?.lvalue and ir.kind != .copy) {
        return;
    } else if (ir.dest != null and ir.dest.?.type.* == .unit and ir.kind != .call) {
        return;
    } else if (ir.dest != null and ir.dest.?.hide_temporary()) {
        return;
    }

    switch (ir.kind) {
        .loadSymbol,
        .loadInt,
        .loadFloat,
        .loadString,
        .loadStruct,
        .loadUnion,
        .copy,
        .not,
        .notEqual,
        .equal,
        .greater,
        .greaterEqual,
        .lesser,
        .lesserEqual,
        .add,
        .sub,
        .mult,
        .div,
        .mod,
        .index,
        .select,
        .get_tag,
        .negate_int,
        .negate_float,
        .addrOf,
        .dereference,
        => {
            try printVarAssign(ir.dest.?, writer);
            try generate_IR_RHS(ir, HIGHEST_PRECEDENCE, writer);
            try writer.print(";\n", .{});
        },

        .call => {
            const void_fn = ir.dest.?.type.* == .unit;
            if (!void_fn) {
                try printVarAssign(ir.dest.?, writer);
            } else {
                try writer.print("    ", .{});
            }
            try generate_IR_RHS(ir, 100, writer);
            try writer.print(";\n", .{});
        },

        .derefCopy => {
            try writer.print("    **", .{});
            try generateLValueIR(ir.src1.?, IRKind.dereference.precedence(), writer);
            try writer.print(" = ", .{});
            try printSymbolVersion(ir.src2.?, HIGHEST_PRECEDENCE, writer);
            try writer.print(";\n", .{});
        },
        .indexCopy => {
            try writer.print("    *", .{});
            try generateIndexExpr(ir, IRKind.dereference.precedence(), writer);
            try writer.print(" = ", .{});
            try printSymbolVersion(ir.data.symbver, HIGHEST_PRECEDENCE, writer);
            try writer.print(";\n", .{});
        },
        .selectCopy => {
            try writer.print("    ", .{});
            try generateSelectIR(ir, IRKind.selectCopy.precedence(), writer);
            try writer.print(" = ", .{});
            try printSymbolVersion(ir.src2.?, HIGHEST_PRECEDENCE, writer);
            try writer.print(";\n", .{});
        },

        // Control-flow
        .label,
        .jump,
        .branchIfFalse,
        => {},
        else => {
            std.debug.print("Unimplemented generateIR() for: IRKind.{s}\n", .{@tagName(ir.kind)});
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
            try ir.span.print_debug_line(writer);
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
        .discard => if (ir.src1.?.symbol.expanded_type.?.* != .unit) {
            try writer.print("    (void)", .{});
            try printSymbolVersion(ir.src1.?, IRKind.cast.precedence(), writer);
            try writer.print(";\n", .{});
        },
    }
}

fn generate_IR_RHS(ir: *IR, precedence: i128, writer: anytype) CodeGen_Error!void {
    _ = precedence;
    if (ir.dest != null and ir.kind != .copy and ir.kind != .discard) {
        return;
    } else if (ir.dest != null and ir.dest.?.get_slots() == 0 and ir.kind != .discard) {
        // Do not output instructions that have `unit` as their dest type (signified by slots being 0)
        return;
    }

    switch (ir.kind) {
        .loadSymbol => {
            try printSymbol(ir.data.symbol, writer);
        },
        .loadInt => {
            try writer.print("{}", .{ir.data.int});
        },
        .loadFloat => {
            try writer.print("{}", .{ir.data.float});
        },
        .loadString => {
            try writer.print("(", .{});
            try printType(ir.dest.?.extract_symbver().symbol.expanded_type.?, writer);
            try writer.print(") {{(uint8_t*)string_{}, {}}}", .{ ir.data.string_id, cheat_module.interned_strings.items[ir.data.string_id].len - 1 });
        },
        .loadStruct => {
            try writer.print("(", .{});
            try printType(ir.dest.?.extract_symbver().symbol.expanded_type.?, writer);
            try writer.print(") {{", .{});
            var product_list = ir.dest.?.extract_symbver().symbol.expanded_type.?.product.terms;
            for (ir.data.symbverList.items, product_list.items, 1..) |symbver, expected, i| {
                if (!expected.c_typesMatch(primitives.unit_type)) {
                    // Don't use values of type `void` (don't exist in C! (Goobersville!))
                    try printSymbolVersion(symbver, ir.kind.precedence(), writer);
                    if (i < product_list.items.len and !product_list.items[i].c_typesMatch(primitives.unit_type)) {
                        try writer.print(", ", .{});
                    }
                }
            }
            try writer.print("}}", .{});
        },
        .loadUnion => {
            try writer.print("(", .{});
            try printType(ir.dest.?.extract_symbver().symbol.expanded_type.?, writer);
            try writer.print(") {{.tag={}", .{ir.data.int});
            if (ir.src1) |init| {
                try writer.print(", ._{}=", .{ir.data.int});
                try printSymbolVersion(init, ir.kind.precedence(), writer);
            }
            try writer.print("}}", .{});
        },

        // Monadic instructions
        .copy => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
        },
        .not => {
            try writer.print("!", .{});
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
        },
        .negate_int,
        .negate_float,
        => {
            if (primitives.represents_signed_primitive(ir.dest.?.extract_symbver().symbol.expanded_type.?)) {
                try writer.print("$negate_{s}(", .{primitives.from_ast(ir.dest.?.extract_symbver().symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer);
                try writer.print(")", .{});
            } else {
                try writer.print("-", .{});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            }
        },
        .addrOf => {
            try generateLValueIR(ir.src1.?, ir.kind.precedence(), writer);
        },
        .dereference => {
            try writer.print("*", .{});
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
        },

        // Diadic instructions
        .equal => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" == ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
        },
        .not_equal => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" != ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
        },
        .greater_int, .greater_float => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" > ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
        },
        .greater_equal_int, .greater_equal_float => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" >= ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
        },
        .lesser_int, .lesser_float => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" < ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
        },
        .lesser_equal_int, .lesser_equal_float => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(" <= ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
        },
        .add_int, .add_float => {
            if (primitives.represents_signed_primitive(ir.dest.?.extract_symbver().symbol.expanded_type.?)) {
                try writer.print("$add_{s}(", .{primitives.from_ast(ir.dest.?.extract_symbver().symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer);
                try writer.print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" + ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
            }
        },
        .sub_int, .sub_float => {
            if (primitives.represents_signed_primitive(ir.dest.?.extract_symbver().symbol.expanded_type.?)) {
                try writer.print("$sub_{s}(", .{primitives.from_ast(ir.dest.?.extract_symbver().symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer);
                try writer.print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" - ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
            }
        },
        .mult_int, .mult_float => {
            if (primitives.represents_signed_primitive(ir.dest.?.extract_symbver().symbol.expanded_type.?)) {
                try writer.print("$mult_{s}(", .{primitives.from_ast(ir.dest.?.extract_symbver().symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer);
                try writer.print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" * ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
            }
        },
        .div_int, .div_float => {
            if (primitives.represents_signed_primitive(ir.dest.?.extract_symbver().symbol.expanded_type.?)) {
                try writer.print("$div_{s}(", .{primitives.from_ast(ir.dest.?.extract_symbver().symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer);
                try writer.print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" / ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
            }
        },
        .mod => {
            if (primitives.represents_signed_primitive(ir.dest.?.extract_symbver().symbol.expanded_type.?)) {
                try writer.print("$mod_{s}(", .{primitives.from_ast(ir.dest.?.extract_symbver().symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
                try writer.print(", ", .{});
                try ir.span.print_debug_line(writer);
                try writer.print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
                try writer.print(" % ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
            }
        },
        .index => {
            try writer.print("*", .{});
            try generateLValueIR(ir.dest.?, IRKind.dereference.precedence(), writer);
        },
        .select => {
            try generateSelectIR(ir, ir.kind.precedence(), writer);
        },
        .get_tag => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print(".tag", .{});
        },

        // Control-flow
        .label,
        .jump,
        .branchIfFalse,
        => {},
        else => {
            std.debug.print("Unimplemented generateIR() for: IRKind.{s}\n", .{@tagName(ir.kind)});
            return error.Unimplemented;
        },
        .call => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), writer);
            try writer.print("(", .{});
            for (ir.data.symbverList.items, 0..) |symbver, i| {
                try printSymbolVersion(symbver, HIGHEST_PRECEDENCE, writer);
                if (i + 1 != ir.data.symbverList.items.len) {
                    try writer.print(", ", .{});
                }
            }
            try writer.print(")", .{});
        },
    }
}

fn output_lvalue(lvalue: *ir_.L_Value, outer_precedence: i128, writer: anytype) CodeGen_Error!void {
    switch (lvalue.*) {
        .dereference => try printSymbolVersion(lvalue.dereference, outer_precedence, writer),
        .index => {},
        .index_slice => {},
        .select => {},
        .symbver => {},
    }
}

// Generates the C code to evaluate the l-value of a given AST
fn generateLValueIR(symbver: *SymbolVersion, outer_precedence: i128, writer: anytype) CodeGen_Error!void {
    if (symbver.def) |ir| {
        switch (ir.kind) {
            // The lval of a dereference is the reference itself
            .dereference => try printSymbolVersion(ir.src1.?, outer_precedence, writer),
            .indexCopy, .index => try generateIndexExpr(ir, outer_precedence, writer),
            .select => {
                if (outer_precedence < IRKind.addrOf.precedence()) {
                    try writer.print("(", .{});
                }
                try writer.print("&", .{});
                try generateSelectExpr(symbver, IRKind.addrOf.precedence(), writer);
                if (outer_precedence < IRKind.addrOf.precedence()) {
                    try writer.print(")", .{});
                }
            },
            else => {
                if (outer_precedence < IRKind.addrOf.precedence()) {
                    try writer.print("(", .{});
                }
                try writer.print("&", .{});
                try printSymbolVersion(symbver, ir.kind.precedence(), writer);
                if (outer_precedence < IRKind.addrOf.precedence()) {
                    try writer.print(")", .{});
                }
            },
        }
    } else {
        // Function parameters are a common example of symbol versions that do not have a definition
        if (outer_precedence < IRKind.addrOf.precedence()) {
            try writer.print("(", .{});
        }
        try writer.print("&", .{});
        try printSymbolVersion(symbver, outer_precedence, writer);
        if (outer_precedence < IRKind.addrOf.precedence()) {
            try writer.print(")", .{});
        }
    }
}

fn generateIndexExpr(ir: *IR, outer_precedence: i128, writer: anytype) CodeGen_Error!void {
    // Do not add the index if it is `0`, since this is pointless
    const do_add = ir.src2.?.def == null or ir.src2.?.def.?.kind != .loadInt or ir.src2.?.def.?.data.int != 0;
    // Inner self precedence changes depending on if the index is non-zero
    const self_precedence = if (do_add) IRKind.add.precedence() else IRKind.cast.precedence();
    if (outer_precedence < self_precedence) {
        try writer.print("(", .{});
    }

    // Generate reinterpret cast to pointer of elements
    const elem_type = if (ir.dest != null) ir.dest.?.extract_symbver().symbol.expanded_type.? else ir.data.symbver.type;
    try writer.print("(", .{});
    try printType(elem_type, writer);
    try writer.print("*)", .{});

    const lhs_type = ir.src1.?.symbol.expanded_type.?;
    if (lhs_type.* == .product and !lhs_type.product.was_slice) {
        // Array index; dereference(lvalue + index)
        try generateLValueIR(ir.src1.?, IRKind.cast.precedence(), writer);
    } else {
        // Slice/String index; dereference(src1._0 + index)
        try generateSelectExpr(ir.src1.?, IRKind.select.precedence(), writer);
        if (ir.src1.?.def != null and (ir.src1.?.def.?.kind == .dereference or ir.src1.?.def.?.kind == .index)) {
            try writer.print("->_0", .{});
        } else {
            try writer.print("._0", .{});
        }
    }

    if (do_add) {
        // Only generate index add if index is non-zero
        // NOTE: Do not generate checked addition. The index is already checked.
        try writer.print(" + ", .{});
        try printSymbolVersion(ir.src2.?, ir.kind.precedence(), writer);
    }

    if (outer_precedence < self_precedence) {
        try writer.print(")", .{});
    }
}

/// Generates representation of a Symbol Version
fn generateSelectExpr(symbver: *SymbolVersion, outer_precedence: i128, writer: anytype) CodeGen_Error!void {
    if (symbver.def) |ir| {
        switch (ir.kind) {
            .dereference => try printSymbolVersion(ir.src1.?, outer_precedence, writer),

            .index => try generateLValueIR(symbver, outer_precedence, writer),

            .select => try generateSelectIR(ir, outer_precedence, writer),

            else => try printSymbolVersion(symbver, outer_precedence, writer),
        }
    } else {
        try printSymbolVersion(symbver, outer_precedence, writer);
    }
}

/// Generates code for a select IR, with respect to a given precedence.
fn generateSelectIR(ir: *IR, outer_precedence: i128, writer: anytype) CodeGen_Error!void {
    if (outer_precedence < IRKind.select.precedence()) {
        // Opening paren, if needed by precedence
        try writer.print("(", .{});
    }

    // Output lhs of select
    try generateSelectExpr(ir.src1.?, IRKind.select.precedence(), writer);

    if (ir.src1.?.def != null and (ir.src1.?.def.?.kind == .dereference or ir.src1.?.def.?.kind == .index)) {
        // Output `->` if lhs is an address to a tuple, OR if it is an index
        try writer.print("->_{}", .{ir.data.int});
    } else {
        // Regular `.` select
        try writer.print("._{}", .{ir.data.int});
    }

    if (outer_precedence < IRKind.select.precedence()) {
        // Closing paren, if needed by precedence
        try writer.print(")", .{});
    }
}

fn printType(_type: *AST, writer: anytype) CodeGen_Error!void {
    switch (_type.*) {
        .identifier => { // TODO: Print out identifier's expanded_type, make prelude types extern types
            if (_type.getCommon().expanded_type.? != _type) {
                try printType(_type.getCommon().expanded_type.?, writer);
            } else {
                try writer.print("{s}", .{primitives.get(_type.getToken().data).c_name});
            }
        },
        .addrOf => {
            try printType(_type.addrOf.expr, writer);
            try writer.print("*", .{});
        },
        .function => {
            const i = (try module_.typeSetGet(_type, &cheat_module.types, try primitives.get_scope(), cheat_module.errors, cheat_module.allocator)).?.uid;
            try writer.print("function{}", .{i});
        },
        .sum, .product => {
            const i = (try module_.typeSetGet(_type, &cheat_module.types, try primitives.get_scope(), cheat_module.errors, cheat_module.allocator)).?.uid;
            try writer.print("struct{}", .{i});
        },
        .unit => {
            try writer.print("void", .{});
        },
        .annotation => {
            try printType(_type.annotation.type, writer);
        },
        else => {
            std.debug.print("Unimplemented printType() for {?}", .{_type.*});
            unreachable;
        },
    }
}

/// Outputs an assignment to a symbol template. It is expected that a value is output immediately
/// after this to complete the assignment.
fn printVarAssign(symbver: *SymbolVersion, writer: anytype) !void {
    try writer.print("    ", .{});
    try printSymbol(symbver.symbol, writer);
    try writer.print(" = ", .{});
}

/// Outputs a symbol's declaration. Parameters are not formatted with a preceding tab, nor a
/// semicolon nor newline.
fn printVarDecl(symbol: *Symbol, writer: anytype, is_parameter: bool) !void {
    if (!is_parameter) {
        try writer.print("    ", .{});
    }
    try printType(symbol.expanded_type.?, writer);
    try writer.print(" ", .{});
    try printSymbol(symbol, writer);
    if (!is_parameter) {
        try writer.print(";\n", .{});
    }
}

/// Outputs a symbol with it's unique identifier to a file
fn printSymbol(symbol: *Symbol, writer: anytype) !void {
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
};

fn is_literal(ir: *IR) bool {
    return ir.kind == .loadSymbol or
        ir.kind == .loadInt or
        ir.kind == .loadFloat or
        ir.kind == .loadString or
        ir.kind == .loadStruct or
        ir.kind == .loadUnion or
        ir.kind == .copy or
        ir.kind == .get_tag or
        ir.kind == .call;
}

/// Checks if the given IR operation is commutative.
///
/// Without this check, the following ASTs:
///    +            -
///   / \          / \
///  1   +        1   -
///     / \          / \
///    2   3        2   3
///
/// Would be code-gen'd as such:
///   1+2+3        1-2-3
///
/// Notice this is OK for `+` since `+` is commutative. It is incorrect for `-`, precisely because
/// it is not commutative. That is, `(1-2)-3 != 1-(2-3)`. The same is true for division (`/`). The
/// solution for these two cases is to keep parenthesis around subtraction (resp. division) for
/// operations lower-than-or-equal-to subtraction's (resp. division's) precedence. This is in
/// contrast with operations such as addition, where only lower precedences require parenthesis.
fn commutative(ir: *IR) bool {
    return ir.kind != .sub and ir.kind != .div;
}

/// Prints out a symbol version. If possible, inlines the symbol version's definition, with correct
/// parenthesis. For example, the following IR:
///     x_0 := 4
///     y_0 := 5
///     z_0 := x_0 + y_0
/// May become the following C, with inlining of symbols x and y:
///     z = 4 + 5;
fn printSymbolVersion(symbver: *SymbolVersion, precedence: i128, writer: anytype) CodeGen_Error!void {
    if (symbver.hide_temporary()) {
        if (precedence < symbver.def.?.kind.precedence() or (precedence == symbver.def.?.kind.precedence() and !commutative(symbver.def.?))) {
            // Add parens when surrounded by a tigher binding precedence OR when same precedence, but order matters (because operation is not commutative)
            try writer.print("(", .{});
        }
        try generate_IR_RHS(symbver.def.?, precedence, writer);
        if (precedence < symbver.def.?.kind.precedence() or (precedence == symbver.def.?.kind.precedence() and !commutative(symbver.def.?))) {
            try writer.print(")", .{});
        }
    } else {
        try printSymbol(symbver.symbol, writer);
    }
}

/// Emits the return statement from a function
fn printReturn(return_symbol: *Symbol, writer: anytype) !void {
    if (return_symbol.versions > 0) { // To fix errors when function ends in `unreachable`
        try writer.print("    return ", .{});
        try printSymbol(return_symbol, writer);
        try writer.print(";\n", .{});
    }
}
