const _ast = @import("ast.zig");
const _ir = @import("ir.zig");
const primitives = @import("primitives.zig");
const _program = @import("program.zig");
const std = @import("std");
const strings = @import("zig-string/zig-string.zig");
const _symbol = @import("symbol.zig");

const AST = _ast.AST;
const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const IR = _ir.IR;
const IRKind = _ir.IRKind;
const Program = _program.Program;
const Scope = _symbol.Scope;
const Span = @import("span.zig").Span;
const String = strings.String;
const Symbol = _symbol.Symbol;
const SymbolVersion = _ir.SymbolVersion;

var program: *Program = undefined;
const HIGHEST_PRECEDENCE = 100;

/// Takes in a file handler and a program structure
pub fn generate(__program: *Program, file: *std.fs.File) !void {
    program = __program;
    try file.writer().print(
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

    try generateFunctionTypedefs(&program.types, file);
    try generateInternedStrings(program.interned_strings, file);
    try file.writer().print("/* Function forward definitions */\n", .{});
    try generateFowardFunctions(program.callGraph, file);
    try file.writer().print("\n/* Function definitions */\n", .{});
    try generateFunctions(program.callGraph, file);
    try generateMainFunction(program.callGraph, file);
}

fn generateFunctionTypedefs(dags: *std.ArrayList(*_program.DAG), out: *std.fs.File) !void {
    if (dags.items.len > 0) {
        try out.writer().print("/* Typedefs */\n", .{});
    }
    for (dags.items) |dag| {
        try generateTypedefs(dag, out);
    }
}

fn generateTypedefs(dag: *_program.DAG, out: *std.fs.File) !void {
    if (dag.visited) {
        return;
    }
    dag.visited = true;

    for (dag.dependencies.items) |depen| {
        try generateTypedefs(depen, out);
    }

    if (dag.base.* == .function) {
        try out.writer().print("typedef ", .{});
        try printType(dag.base.function.rhs, out);
        try out.writer().print("(*function{})(", .{dag.uid});
        try printType(dag.base.function.lhs, out);
        try out.writer().print(");\n\n", .{});
    } else if (dag.base.* == .product) {
        try out.writer().print("typedef struct {{\n", .{});
        for (dag.base.product.terms.items, 0..) |term, i| {
            if (!term.c_typesMatch(primitives.unit_type)) {
                // Don't gen `void` structure fields
                try out.writer().print("    ", .{});
                try printType(term, out);
                try out.writer().print(" _{};\n", .{i});
            }
        }
        try out.writer().print("}} struct{};\n\n", .{dag.uid});
    } else if (dag.base.* == .sum) {
        try out.writer().print("typedef struct {{\n    uint64_t tag;\n", .{});
        if (!dag.base.sum.is_all_unit()) {
            try out.writer().print("    union {{\n", .{});
            for (dag.base.sum.terms.items, 0..) |term, i| {
                if (!term.annotation.type.c_typesMatch(primitives.unit_type)) {
                    // Don't gen `void` structure fields
                    try out.writer().print("        ", .{});
                    try printType(term, out);
                    try out.writer().print(" _{};\n", .{i});
                }
            }
            try out.writer().print("    }};\n", .{});
        }
        try out.writer().print("}} struct{};\n\n", .{dag.uid});
    }
}

fn generateInternedStrings(interned_strings: *std.ArrayList([]const u8), out: *std.fs.File) !void {
    if (interned_strings.items.len > 0) {
        try out.writer().print("/* Interned Strings */\n", .{});
    }
    for (interned_strings.items, 0..) |str, i| {
        try out.writer().print("char* string_{} = \"", .{i});
        for (str) |byte| {
            try out.writer().print("\\x{X:0>2}", .{byte});
        }
        try out.writer().print("\";", .{});
    }
    if (interned_strings.items.len > 0) {
        try out.writer().print("\n", .{});
    }
}

fn generateFowardFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    try printType(callGraph.symbol.expanded_type.?.function.rhs, out);
    try out.writer().print(" ", .{});
    try printSymbol(callGraph.symbol, out);
    try out.writer().print("(", .{});
    for (callGraph.symbol.decl.?.fnDecl.param_symbols.items, 0..) |param, i| {
        // Print out parameter declarations
        try printVarDecl(param, out, true);
        if (i + 1 < callGraph.symbol.decl.?.fnDecl.param_symbols.items.len) {
            try out.writer().print(",", .{});
        }
    }
    if (callGraph.symbol.decl.?.fnDecl.param_symbols.items.len == 0) {
        // If there are no parameters, mark as void
        try out.writer().print("void", .{});
    }
    try out.writer().print(");\n", .{});

    for (callGraph.children.items) |child| {
        try generateFowardFunctions(child, out);
    }
}

fn generateFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    // Print function return type, name, parameter list
    try printType(callGraph.symbol.expanded_type.?.function.rhs, out);
    try out.writer().print(" ", .{});
    try printSymbol(callGraph.symbol, out);
    try out.writer().print("(", .{});
    for (callGraph.symbol.decl.?.fnDecl.param_symbols.items, 0..) |param, i| {
        // Print out parameter declarations
        try printVarDecl(param, out, true);
        if (param.uses == 0) {}
        if (i + 1 < callGraph.symbol.decl.?.fnDecl.param_symbols.items.len) {
            try out.writer().print(",", .{});
        }
    }
    if (callGraph.symbol.decl.?.fnDecl.param_symbols.items.len == 0) {
        // If there are no parameters, mark as void
        try out.writer().print("void", .{});
    }
    try out.writer().print(") {{\n", .{});

    // Collect and then declare all local variables
    for (callGraph.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest) |dest| {
                if (dest.symbol.decld or dest.type.* == .unit or dest.symbol.versions == 0) {
                    continue;
                }
                if (hide_temporary(dest)) {
                    continue;
                }
                try printVarDecl(dest.symbol, out, false);
                dest.symbol.decld = true;
            }
        }
    }

    for (callGraph.symbol.decl.?.fnDecl.param_symbols.items) |param| {
        // Mark unused parameters as discarded
        // Do this only if they aren't discarded in source
        // Users can discard parameters, however used parameters may also become unused through optimizations
        if (param.uses == 0 and param.discards == 0) {
            try out.writer().print("    (void)", .{});
            try printSymbol(param, out);
            try out.writer().print(";\n", .{});
        }
    }

    // Generate the basic-block graph, starting at the init basic block
    if (callGraph.block_graph_head) |block_graph_head| {
        try generateBasicBlock(callGraph, block_graph_head, callGraph.return_symbol, out);
        callGraph.clearVisitedBBs();
    }

    try out.writer().print("}}\n\n", .{});

    // Generate leaf functions
    for (callGraph.children.items) |child| {
        try generateFunctions(child, out);
    }
}

fn generateMainFunction(callGraph: *CFG, out: *std.fs.File) !void {
    if (std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "Int") or
        std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "Int64"))
    {
        try out.writer().print(
            \\int main(void)
            \\{{
            \\  printf("%ld",
        , .{});
    } else if (std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "Word64")) {
        try out.writer().print(
            \\int main(void)
            \\{{
            \\  printf("%lu",
        , .{});
    } else if (std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "Float64") or
        std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "Float32") or
        std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "Float"))
    {
        try out.writer().print(
            \\int main(void)
            \\{{
            \\  printf("%f",
        , .{});
    } else if (std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "String")) {
        try out.writer().print(
            \\int main(void)
            \\{{
            \\  printf("%s",
        , .{});
    } else {
        try out.writer().print(
            \\int main(void)
            \\{{
            \\  printf("%d",
        , .{});
    }
    try printSymbol(callGraph.symbol, out);
    if (std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "String")) {
        try out.writer().print(
            \\()._0);
            \\  return 0;
            \\}}
            \\
        , .{});
    } else {
        try out.writer().print(
            \\());
            \\  return 0;
            \\}}
            \\
        , .{});
    }
}

fn generateBasicBlock(callGraph: *CFG, start_bb: *BasicBlock, symbol: *Symbol, out: *std.fs.File) !void {
    var bb_queue = std.ArrayList(*BasicBlock).init(std.heap.page_allocator); // Seriously? No circular buffer? Or any kind of queue? DoublyLinkedList is awful btw
    defer bb_queue.deinit();
    try bb_queue.append(start_bb);

    var head: usize = 0;
    while (head < bb_queue.items.len) {
        var bb: *BasicBlock = bb_queue.items[head];
        head += 1;

        const is_head_bb = callGraph.block_graph_head != null and callGraph.block_graph_head.? == bb;
        const no_incoming = bb.number_predecessors <= 1;
        if (!is_head_bb or !no_incoming) {
            // Only print the label if this basic block isn't the first one in the graph
            try out.writer().print("BB{}:\n", .{bb.uid});
        }
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            try generateIR(ir, out);
        }

        if (!bb.has_panic) {
            if (bb.has_branch) {
                // Generate the if
                try out.writer().print("    if (", .{});
                try printSymbolVersion(bb.condition.?, HIGHEST_PRECEDENCE, out);
                try out.writer().print(") {{\n", .{});

                // Generate the `next` BB
                if (bb.next) |next| {
                    try out.writer().print("        goto BB{};\n    }}", .{next.uid});
                    if (!next.visited) {
                        try bb_queue.append(next);
                        next.visited = true;
                    }
                } else {
                    try out.writer().print("    ", .{});
                    try printReturn(symbol, out);
                    try out.writer().print("    }}", .{});
                }

                // Generate the `branch` BB if it isn't the next one up
                if (bb.branch) |branch| {
                    if (!branch.visited) {
                        try bb_queue.append(branch);
                        branch.visited = true;
                    }
                    if (head >= bb_queue.items.len or bb_queue.items[head].uid != branch.uid) {
                        try out.writer().print(" else {{\n        goto BB{};\n    }}\n", .{branch.uid});
                    } else {
                        try out.writer().print("\n", .{});
                    }
                } else {
                    try out.writer().print("    ", .{});
                    try printReturn(symbol, out);
                    try out.writer().print("    }}\n", .{});
                }
            } else {
                if (bb.next) |next| {
                    if (!next.visited) {
                        try bb_queue.append(next);
                        next.visited = true;
                    }
                    if (head >= bb_queue.items.len or bb_queue.items[head].uid != next.uid) {
                        try out.writer().print("    goto BB{};\n", .{next.uid});
                    }
                } else {
                    try printReturn(symbol, out);
                }
            }
        }
    }
}

fn generateIR(ir: *IR, out: *std.fs.File) !void {
    if (ir.meta == .bounds_check) {
        var spaces = String.init(std.heap.page_allocator);
        defer spaces.deinit();
        for (1..ir.span.col - 1) |i| {
            _ = i;
            try spaces.insert(" ", spaces.size);
        }
        try out.writer().print("    $bounds_check(", .{});
        try printSymbolVersion(ir.src2.?, HIGHEST_PRECEDENCE, out); // idx
        try out.writer().print(", ", .{});
        try printSymbolVersion(ir.meta.bounds_check.length, HIGHEST_PRECEDENCE, out); // length
        try out.writer().print(", ", .{});
        try print_debug_line(out, ir.span);
        try out.writer().print(");\n", .{});
    } else if (ir.meta == .active_field_check) {
        var spaces = String.init(std.heap.page_allocator);
        defer spaces.deinit();
        for (1..ir.span.col - 1) |i| {
            _ = i;
            try spaces.insert(" ", spaces.size);
        }
        try out.writer().print("    $tag_check(", .{});
        try printSymbolVersion(ir.meta.active_field_check.tag, HIGHEST_PRECEDENCE, out); // tag
        try out.writer().print(", {}, ", .{ir.meta.active_field_check.selection});
        try print_debug_line(out, ir.span);
        try out.writer().print(");\n", .{});
    }

    if (ir.dest != null and ir.dest.?.lvalue and ir.kind != .copy) {
        return;
    } else if (ir.dest != null and ir.dest.?.type.* == .unit and ir.kind != .call) {
        return;
    } else if (ir.dest != null and hide_temporary(ir.dest.?)) {
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
        .negate,
        .addrOf,
        .dereference,
        => {
            try printVarAssign(ir.dest.?, out);
            try generate_IR_RHS(ir, HIGHEST_PRECEDENCE, out);
            try out.writer().print(";\n", .{});
        },

        .call => {
            var void_fn = ir.dest.?.type.* == .unit;
            if (!void_fn) {
                try printVarAssign(ir.dest.?, out);
            } else {
                try out.writer().print("    ", .{});
            }
            try generate_IR_RHS(ir, 100, out);
            try out.writer().print(";\n", .{});
        },

        .derefCopy => {
            try out.writer().print("    **", .{});
            try generateLValueIR(ir.src1.?, IRKind.dereference.precedence(), out);
            try out.writer().print(" = ", .{});
            try printSymbolVersion(ir.src2.?, HIGHEST_PRECEDENCE, out);
            try out.writer().print(";\n", .{});
        },
        .indexCopy => {
            try out.writer().print("    *", .{});
            try generateIndexExpr(ir, IRKind.dereference.precedence(), out);
            try out.writer().print(" = ", .{});
            try printSymbolVersion(ir.data.symbver, HIGHEST_PRECEDENCE, out);
            try out.writer().print(";\n", .{});
        },
        .selectCopy => {
            try out.writer().print("    ", .{});
            try generateSelectIR(ir, IRKind.selectCopy.precedence(), out);
            try out.writer().print(" = ", .{});
            try printSymbolVersion(ir.src2.?, HIGHEST_PRECEDENCE, out);
            try out.writer().print(";\n", .{});
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
            try out.writer().print("    $lines[$line_idx++] = ", .{});
            try print_debug_line(out, ir.span);
            try out.writer().print(";\n", .{});
        },
        .popStackTrace => {
            try out.writer().print(
                \\    $line_idx--;
                \\
            , .{});
        },
        .panic => {
            try out.writer().print(
                \\    $panic("{s}\n");
                \\
            ,
                .{ir.data.string},
            );
        },
        .discard => {
            try out.writer().print("    (void)", .{});
            try printSymbolVersion(ir.src1.?, IRKind.cast.precedence(), out);
            try out.writer().print(";\n", .{});
        },
    }
}

fn generate_IR_RHS(ir: *IR, precedence: i128, out: *std.fs.File) CodeGen_Error!void {
    _ = precedence;
    if (ir.dest != null and ir.dest.?.lvalue and ir.kind != .copy and ir.kind != .discard) {
        return;
    } else if (ir.dest != null and ir.dest.?.type.* == .unit and ir.kind != .call and ir.kind != .discard) {
        return;
    }

    switch (ir.kind) {
        .loadSymbol => {
            try printSymbol(ir.data.symbol, out);
        },
        .loadInt => {
            try out.writer().print("{}", .{ir.data.int});
        },
        .loadFloat => {
            try out.writer().print("{}", .{ir.data.float});
        },
        .loadString => {
            try out.writer().print("(", .{});
            try printType(ir.dest.?.symbol.expanded_type.?, out);
            try out.writer().print(") {{(uint8_t*)string_{}, {}}}", .{ ir.data.string_id, program.interned_strings.items[ir.data.string_id].len - 1 });
        },
        .loadStruct => {
            try out.writer().print("(", .{});
            try printType(ir.dest.?.symbol.expanded_type.?, out);
            try out.writer().print(") {{", .{});
            var product_list = ir.dest.?.symbol.expanded_type.?.product.terms;
            for (ir.data.symbverList.items, product_list.items, 1..) |symbver, expected, i| {
                if (!expected.c_typesMatch(primitives.unit_type)) {
                    // Don't values of type `void` (don't exist in C! (Goobersville!))
                    if (!expected.c_typesMatch(symbver.symbol.expanded_type.?)) {
                        try out.writer().print("(", .{});
                        try printType(expected, out);
                        try out.writer().print(")", .{});
                    }
                    try printSymbolVersion(symbver, ir.kind.precedence(), out);
                    if (i < product_list.items.len and !product_list.items[i].c_typesMatch(primitives.unit_type)) {
                        try out.writer().print(", ", .{});
                    }
                }
            }
            try out.writer().print("}}", .{});
        },
        .loadUnion => {
            try out.writer().print("(", .{});
            try printType(ir.dest.?.symbol.expanded_type.?, out);
            try out.writer().print(") {{.tag={}", .{ir.data.int});
            if (ir.src1) |init| {
                try out.writer().print(", ._{}=", .{ir.data.int});
                try printSymbolVersion(init, ir.kind.precedence(), out);
            }
            try out.writer().print("}}", .{});
        },

        // Monadic instructions
        .copy => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
        },
        .not => {
            try out.writer().print("!", .{});
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
        },
        .negate => {
            if (primitives.represents_signed_primitive(ir.dest.?.symbol.expanded_type.?)) {
                try out.writer().print("$negate_{s}(", .{primitives.from_ast(ir.dest.?.symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try print_debug_line(out, ir.span);
                try out.writer().print(")", .{});
            } else {
                try out.writer().print("-", .{});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            }
        },
        .addrOf => {
            try generateLValueIR(ir.src1.?, ir.kind.precedence(), out);
        },
        .dereference => {
            try out.writer().print("*", .{});
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
        },

        // Diadic instructions
        .notEqual => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            try out.writer().print(" != ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
        },
        .equal => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            try out.writer().print(" == ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
        },
        .greater => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            try out.writer().print(" > ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
        },
        .greaterEqual => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            try out.writer().print(" >= ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
        },
        .lesser => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            try out.writer().print(" < ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
        },
        .lesserEqual => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            try out.writer().print(" <= ", .{});
            try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
        },
        .add => {
            if (primitives.represents_signed_primitive(ir.dest.?.symbol.expanded_type.?)) {
                try out.writer().print("$add_{s}(", .{primitives.from_ast(ir.dest.?.symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try print_debug_line(out, ir.span);
                try out.writer().print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(" + ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
            }
        },
        .sub => {
            if (primitives.represents_signed_primitive(ir.dest.?.symbol.expanded_type.?)) {
                try out.writer().print("$sub_{s}(", .{primitives.from_ast(ir.dest.?.symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try print_debug_line(out, ir.span);
                try out.writer().print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(" - ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
            }
        },
        .mult => {
            if (primitives.represents_signed_primitive(ir.dest.?.symbol.expanded_type.?)) {
                try out.writer().print("$mult_{s}(", .{primitives.from_ast(ir.dest.?.symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try print_debug_line(out, ir.span);
                try out.writer().print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(" * ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
            }
        },
        .div => {
            if (primitives.represents_signed_primitive(ir.dest.?.symbol.expanded_type.?)) {
                try out.writer().print("$div_{s}(", .{primitives.from_ast(ir.dest.?.symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try print_debug_line(out, ir.span);
                try out.writer().print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(" / ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
            }
        },
        .mod => {
            if (primitives.represents_signed_primitive(ir.dest.?.symbol.expanded_type.?)) {
                try out.writer().print("$mod_{s}(", .{primitives.from_ast(ir.dest.?.symbol.expanded_type.?).c_name});
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
                try out.writer().print(", ", .{});
                try print_debug_line(out, ir.span);
                try out.writer().print(")", .{});
            } else {
                try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
                try out.writer().print(" % ", .{});
                try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
            }
        },
        .index => {
            try out.writer().print("*", .{});
            try generateLValueIR(ir.dest.?, IRKind.dereference.precedence(), out);
        },
        .select => {
            try generateSelectIR(ir, ir.kind.precedence(), out);
        },
        .get_tag => {
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            try out.writer().print(".tag", .{});
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
            try printSymbolVersion(ir.src1.?, ir.kind.precedence(), out);
            try out.writer().print("(", .{});
            for (ir.data.symbverList.items, 0..) |symbver, i| {
                try printSymbolVersion(symbver, HIGHEST_PRECEDENCE, out);
                if (i + 1 != ir.data.symbverList.items.len) {
                    try out.writer().print(", ", .{});
                }
            }
            try out.writer().print(")", .{});
        },
    }
}

// Generates the C code to evaluate the l-value of a given AST
fn generateLValueIR(symbver: *SymbolVersion, outer_precedence: i128, out: *std.fs.File) CodeGen_Error!void {
    if (symbver.def) |ir| {
        switch (ir.kind) {
            // The lval of a dereference is the reference itself
            .dereference => try printSymbolVersion(ir.src1.?, outer_precedence, out),
            .indexCopy, .index => try generateIndexExpr(ir, outer_precedence, out),
            .select => {
                if (outer_precedence < IRKind.addrOf.precedence()) {
                    try out.writer().print("(", .{});
                }
                try out.writer().print("&", .{});
                try generateSelectExpr(symbver, IRKind.addrOf.precedence(), out);
                if (outer_precedence < IRKind.addrOf.precedence()) {
                    try out.writer().print(")", .{});
                }
            },
            else => {
                if (outer_precedence < IRKind.addrOf.precedence()) {
                    try out.writer().print("(", .{});
                }
                try out.writer().print("&", .{});
                try printSymbolVersion(symbver, ir.kind.precedence(), out);
                if (outer_precedence < IRKind.addrOf.precedence()) {
                    try out.writer().print(")", .{});
                }
            },
        }
    } else {
        // Function parameters are a common example of symbol versions that do not have a definition
        if (outer_precedence < IRKind.addrOf.precedence()) {
            try out.writer().print("(", .{});
        }
        try out.writer().print("&", .{});
        try printSymbolVersion(symbver, outer_precedence, out);
        if (outer_precedence < IRKind.addrOf.precedence()) {
            try out.writer().print(")", .{});
        }
    }
}

fn generateIndexExpr(ir: *IR, outer_precedence: i128, out: *std.fs.File) CodeGen_Error!void {
    // Do not add the index if it is `0`, since this is pointless
    var do_add = ir.src2.?.def == null or ir.src2.?.def.?.kind != .loadInt or ir.src2.?.def.?.data.int != 0;
    // Inner self precedence changes depending on if the index is non-zero
    var self_precedence = if (do_add) IRKind.add.precedence() else IRKind.cast.precedence();
    if (outer_precedence < self_precedence) {
        try out.writer().print("(", .{});
    }

    // Generate reinterpret cast to pointer of elements
    var elem_type = if (ir.dest != null) ir.dest.?.symbol.expanded_type.? else ir.data.symbver.type;
    try out.writer().print("(", .{});
    try printType(elem_type, out);
    try out.writer().print("*)", .{});

    var lhs_type = ir.src1.?.symbol.expanded_type.?;
    if (lhs_type.* == .product and !lhs_type.product.was_slice) {
        // Array index; dereference(lvalue + index)
        try generateLValueIR(ir.src1.?, IRKind.cast.precedence(), out);
    } else {
        // Slice/String index; dereference(src1._0 + index)
        try generateSelectExpr(ir.src1.?, IRKind.select.precedence(), out);
        if (ir.src1.?.def != null and (ir.src1.?.def.?.kind == .dereference or ir.src1.?.def.?.kind == .index)) {
            try out.writer().print("->_0", .{});
        } else {
            try out.writer().print("._0", .{});
        }
    }

    if (do_add) {
        // Only generate index add if index is non-zero
        // NOTE: Do not generate checked addition. The index is already checked.
        try out.writer().print(" + ", .{});
        try printSymbolVersion(ir.src2.?, ir.kind.precedence(), out);
    }

    if (outer_precedence < self_precedence) {
        try out.writer().print(")", .{});
    }
}

// Generates the C code of a clean looking select expression.
fn generateSelectExpr(symbver: *SymbolVersion, outer_precedence: i128, out: *std.fs.File) CodeGen_Error!void {
    if (symbver.def) |ir| {
        switch (ir.kind) {
            .dereference => try printSymbolVersion(ir.src1.?, outer_precedence, out),
            .index => try generateLValueIR(symbver, outer_precedence, out),
            .select => try generateSelectIR(ir, outer_precedence, out),
            else => try printSymbolVersion(symbver, outer_precedence, out),
        }
    } else {
        try printSymbolVersion(symbver, outer_precedence, out);
    }
}

fn generateSelectIR(ir: *IR, outer_precedence: i128, out: *std.fs.File) CodeGen_Error!void {
    if (outer_precedence < IRKind.select.precedence()) {
        try out.writer().print("(", .{});
    }
    try generateSelectExpr(ir.src1.?, IRKind.select.precedence(), out);
    if (ir.src1.?.def != null and (ir.src1.?.def.?.kind == .dereference or ir.src1.?.def.?.kind == .index)) {
        try out.writer().print("->_{}", .{ir.data.int});
    } else {
        try out.writer().print("._{}", .{ir.data.int});
    }
    if (outer_precedence < IRKind.select.precedence()) {
        try out.writer().print(")", .{});
    }
}

fn printType(_type: *AST, out: *std.fs.File) !void {
    switch (_type.*) {
        .identifier => { // TODO: Print out identifier's expanded_type, make prelude types extern types
            if (_type.getCommon().expanded_type.? != _type) {
                try printType(_type.getCommon().expanded_type.?, out);
            } else {
                try out.writer().print("{s}", .{primitives.get(_type.getToken().data).c_name});
            }
        },
        .addrOf => {
            try printType(_type.addrOf.expr, out);
            try out.writer().print("*", .{});
        },
        .function => {
            var i = (try _program.typeSetGet(_type, &program.types, program.prelude, program.errors, program.allocator)).?.uid;
            try out.writer().print("function{}", .{i});
        },
        .sum, .product => {
            var i = (try _program.typeSetGet(_type, &program.types, program.prelude, program.errors, program.allocator)).?.uid;
            try out.writer().print("struct{}", .{i});
        },
        .unit => {
            try out.writer().print("void", .{});
        },
        .annotation => {
            try printType(_type.annotation.type, out);
        },
        else => {
            std.debug.print("Unimplemented printType() for {?}", .{_type.*});
            unreachable;
        },
    }
}

fn printVarAssign(symbver: *SymbolVersion, out: *std.fs.File) !void {
    try out.writer().print("    ", .{});
    try printSymbol(symbver.symbol, out);
    try out.writer().print(" = ", .{});
}

fn printVarDecl(symbol: *Symbol, out: *std.fs.File, param: bool) !void {
    if (!param) {
        try out.writer().print("    ", .{});
    }
    try printType(symbol.expanded_type.?, out);
    try out.writer().print(" ", .{});
    try printSymbol(symbol, out);
    if (!param) {
        try out.writer().print(";\n", .{});
    }
}

fn printSymbol(symbol: *Symbol, out: *std.fs.File) !void {
    try out.writer().print("_{}_{s}", .{ symbol.scope.uid, symbol.name });
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

fn hide_temporary(symbver: *SymbolVersion) bool {
    if (symbver.def == null) {
        // parameters do not have defs; they should never be hidden
        return false;
    } else if (symbver.symbol.discards > 0) {
        return true;
    }
    return symbver.symbol.is_temp and !symbver.lvalue and symbver.uses == 1 and symbver.symbol.versions == 1 and symbver.def != null and symbver.type.* == .identifier;
}

fn is_literal(ir: *IR) bool {
    return ir.kind == .loadSymbol or ir.kind == .loadInt or ir.kind == .loadFloat or ir.kind == .loadString or ir.kind == .loadStruct or ir.kind == .loadUnion or ir.kind == .copy or ir.kind == .get_tag or ir.kind == .call;
}

fn commutative(ir: *IR) bool {
    return ir.kind != .sub and ir.kind != .div;
}

fn printSymbolVersion(symbver: *SymbolVersion, precedence: i128, out: *std.fs.File) CodeGen_Error!void {
    if (hide_temporary(symbver)) {
        if (precedence < symbver.def.?.kind.precedence() or (precedence == symbver.def.?.kind.precedence() and !commutative(symbver.def.?))) {
            try out.writer().print("(", .{});
        }
        try generate_IR_RHS(symbver.def.?, precedence, out);
        if (precedence < symbver.def.?.kind.precedence() or (precedence == symbver.def.?.kind.precedence() and !commutative(symbver.def.?))) {
            try out.writer().print(")", .{});
        }
    } else {
        try printSymbol(symbver.symbol, out);
    }
}

fn printReturn(return_symbol: *Symbol, out: *std.fs.File) !void {
    if (return_symbol.versions > 0) { // To fix errors when function ends in `unreachable`
        try out.writer().print("    return ", .{});
        try printSymbol(return_symbol, out);
        try out.writer().print(";\n", .{});
    }
}

/// Prints out a line string, with quotes and arrow.
fn print_debug_line(out: *std.fs.File, span: Span) !void {
    var spaces = String.init(std.heap.page_allocator);
    defer spaces.deinit();
    for (1..span.col - 1) |_| {
        try spaces.insert(" ", spaces.size);
    }
    try out.writer().print("\"{s}:{}:{}:\\n{s}\\n{s}^\"", .{
        span.filename,
        span.line,
        span.col,
        try sanitize_string(program.lines.items[span.line - 1], std.heap.page_allocator),
        spaces.str(),
    });
}

fn sanitize_string(str: []const u8, allocator: std.mem.Allocator) ![]const u8 {
    var builder = String.init(allocator);
    for (str) |byte| {
        if (byte == '\\' or byte == '"') {
            try builder.insert("\\", builder.len());
        }
        const insert_me_daddy: [1]u8 = .{byte};
        try builder.insert(&insert_me_daddy, builder.len());
    }
    return (try builder.toOwned()).?;
}
