const _ast = @import("ast.zig");
const _ir = @import("ir.zig");
const _program = @import("program.zig");
const std = @import("std");
const strings = @import("zig-string/zig-string.zig");
const _symbol = @import("symbol.zig");

const AST = _ast.AST;
const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const IR = _ir.IR;
const Program = _program.Program;
const Scope = _symbol.Scope;
const String = strings.String;
const Symbol = _symbol.Symbol;
const SymbolVersion = _ir.SymbolVersion;

var program: *Program = undefined;

/// Takes in a file handler and a program structure
pub fn generate(__program: *Program, file: *std.fs.File) !void {
    program = __program;
    try file.writer().print("/* Code generated using the Orng compiler https://ornglang.org */\n", .{});
    try file.writer().print("#ifndef ORNG_{}\n#define ORNG_{}\n\n#include <math.h>\n#include <stdio.h>\n#include <stdint.h>\n#include <stdlib.h>\n\n", .{ program.uid, program.uid });

    try file.writer().print("/* Debug information */\n", .{});
    try generateDebug(file);

    try file.writer().print("/* Typedefs */\n", .{});
    try generateFunctionTypedefs(&program.types, file);
    try file.writer().print("\n/* Interned Strings */\n", .{});
    try generateInternedStrings(program.interned_strings, file);
    try file.writer().print("\n/* Function forward definitions */\n", .{});
    try generateFowardFunctions(program.callGraph, file);
    try file.writer().print("\n/* Function definitions */\n", .{});
    try generateFunctions(program.callGraph, file);
    try file.writer().print("\n", .{});
    try generateMainFunction(program.callGraph, file);

    try file.writer().print("#endif\n", .{});
}

fn generateFunctionTypedefs(dags: *std.ArrayList(*_program.DAG), out: *std.fs.File) !void {
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
        try out.writer().print(");\n", .{});
    } else if (dag.base.* == .product) {
        try out.writer().print("typedef struct {{\n", .{});
        for (dag.base.product.terms.items, 0..) |term, i| {
            if (!term.c_typesMatch(_ast.unitType)) {
                // Don't gen `void` structure fields
                try out.writer().print("    ", .{});
                try printType(term, out);
                try out.writer().print(" _{};\n", .{i});
            }
        }
        try out.writer().print("}} struct{};\n", .{dag.uid});
    } else if (dag.base.* == .sum) {
        try out.writer().print("typedef struct {{\n    uint64_t tag;\n", .{});
        if (!dag.base.sum.is_all_unit()) {
            try out.writer().print("    union {{\n", .{});
            for (dag.base.sum.terms.items, 0..) |term, i| {
                if (!term.annotation.type.c_typesMatch(_ast.unitType)) {
                    // Don't gen `void` structure fields
                    try out.writer().print("        ", .{});
                    try printType(term, out);
                    try out.writer().print(" _{};\n", .{i});
                }
            }
            try out.writer().print("    }};\n", .{});
        }
        try out.writer().print("}} struct{};\n", .{dag.uid});
    }
}

fn generateInternedStrings(interned_strings: *std.ArrayList([]const u8), out: *std.fs.File) !void {
    for (interned_strings.items, 0..) |str, i| {
        try out.writer().print("char* string_{} = \"", .{i});
        var escape = false;
        var skip: i8 = 0;
        for (str, 0..) |byte, j| {
            if (skip > 0) {
                skip -= 1;
                continue;
            } else if (j == 0 or j == str.len - 1) {
                continue;
            } else if (escape) {
                escape = false;
                if (byte == 'n') {
                    try out.writer().print("\\x0A", .{});
                } else if (byte == 'r') {
                    try out.writer().print("\\x0D", .{});
                } else if (byte == 't') {
                    try out.writer().print("\\x09", .{});
                } else if (byte == '\\') {
                    try out.writer().print("\\x5C", .{});
                } else if (byte == '\'') {
                    try out.writer().print("\\x27", .{});
                } else if (byte == '"') {
                    try out.writer().print("\\x22", .{});
                } else if (byte == 'x') {
                    var res: usize = get_nibble(str[j + 1]) * 16 + get_nibble(str[j + 2]);
                    try out.writer().print("\\x{X}", .{res});
                    skip = 2;
                } else {
                    unreachable;
                }
            } else {
                if (byte == '\\') {
                    escape = true;
                } else {
                    try out.writer().print("\\x{X}", .{byte});
                }
            }
        }
        try out.writer().print("\";\n", .{});
    }
}

fn get_nibble(c: u8) u8 {
    if ('0' <= c and c <= '9') {
        return c - '0';
    } else if ('a' <= c and c <= 'f') {
        return c - 'a' + 10;
    } else if ('A' <= c and c <= 'F') {
        return c - 'A' + 10;
    } else {
        unreachable;
    }
}

fn generateFowardFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    try printType(callGraph.symbol._type.?.function.rhs, out);
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
    try out.writer().print(");\n", .{});

    for (callGraph.children.items) |child| {
        try generateFowardFunctions(child, out);
    }
}

fn generateFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    // Print function return type, name, parameter list
    try printType(callGraph.symbol._type.?.function.rhs, out);
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
    try out.writer().print(") {{\n", .{});

    // Collect and then declare all local variables
    for (callGraph.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest) |dest| {
                if (dest.symbol.decld or dest.type.* == .unit or dest.symbol.versions == 0) {
                    continue;
                }
                try printVarDecl(dest.symbol, out, false);
                dest.symbol.decld = true;
            }
        }
    }

    // Generate the basic-block graph, starting at the init basic block
    if (callGraph.block_graph_head) |block_graph_head| {
        try generateBasicBlock(block_graph_head, callGraph.return_symbol, out);
        callGraph.clearVisitedBBs();
    }

    try out.writer().print("}}\n\n", .{});

    // Generate leaf functions
    for (callGraph.children.items) |child| {
        try generateFunctions(child, out);
    }
}

fn generateDebug(out: *std.fs.File) !void {
    try out.writer().print(
        \\static const char* $lines[1024];
        \\static uint16_t $line_idx = 0;
        \\
        \\
    , .{});
}

fn generateMainFunction(callGraph: *CFG, out: *std.fs.File) !void {
    if (std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "Int")) {
        try out.writer().print(
            \\int main()
            \\{{
            \\  printf("%ld",
        , .{});
    } else if (std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.getToken().data, "String")) {
        try out.writer().print(
            \\int main()
            \\{{
            \\  printf("%s",
        , .{});
    } else {
        try out.writer().print(
            \\int main()
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
            \\
        , .{});
    } else {
        try out.writer().print(
            \\());
            \\  return 0;
            \\}}
            \\
            \\
        , .{});
    }
}

fn generateBasicBlock(bb: *BasicBlock, symbol: *Symbol, out: *std.fs.File) !void {
    if (bb.visited) {
        return;
    }
    bb.visited = true;

    try out.writer().print("BB{}:\n", .{bb.uid});
    var maybe_ir = bb.ir_head;
    while (maybe_ir) |ir| : (maybe_ir = ir.next) {
        try generateIR(ir, out);
    }

    if (bb.has_branch) {
        // Generate the if
        try out.writer().print("    if (", .{});
        try printSymbolVersion(bb.condition.?, out);
        try out.writer().print(") {{\n", .{});

        // Generate branch `if-else`
        if (bb.next) |next| {
            try out.writer().print("        goto BB{};\n    }} else {{\n", .{next.uid});
        } else {
            try out.writer().print("    ", .{});
            try printReturn(symbol, out);
            try out.writer().print("    }} else {{\n", .{});
        }

        // Generate the `branch` BB
        if (bb.branch) |branch| {
            try out.writer().print("        goto BB{};\n    }}\n", .{branch.uid});
            try generateBasicBlock(branch, symbol, out);
        } else {
            try out.writer().print("    ", .{});
            try printReturn(symbol, out);
            try out.writer().print("    }}\n", .{});
        }

        // Generate the `next` BB
        if (bb.next) |next| {
            try generateBasicBlock(next, symbol, out);
        }
    } else {
        if (bb.next) |next| {
            try out.writer().print("    goto BB{};\n", .{next.uid});
            try generateBasicBlock(next, symbol, out);
        } else {
            try printReturn(symbol, out);
        }
    }
}

fn generateIR(ir: *IR, out: *std.fs.File) !void {
    if (ir.dest != null and ir.dest.?.lvalue and ir.kind != .copy) {
        return;
    } else if (ir.dest != null and ir.dest.?.type.* == .unit and ir.kind != .call) {
        return;
    }

    switch (ir.kind) {
        .loadSymbol => {
            try printVarAssign(ir.dest.?, out);
            try printSymbol(ir.data.symbol, out);
            try out.writer().print(";\n", .{});
        },
        .loadInt => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("{};\n", .{ir.data.int});
        },
        .loadFloat => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("{};\n", .{ir.data.float});
        },
        .loadString => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("(", .{});
            try printType(ir.dest.?.symbol._type.?, out);
            try out.writer().print(") {{string_{}, {}}};\n", .{ ir.data.string_id, program.interned_strings.items[ir.data.string_id].len - 1 });
        },
        .loadStruct => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("(", .{});
            try printType(ir.dest.?.symbol._type.?, out);
            try out.writer().print(") {{", .{});
            for (ir.data.symbverList.items, ir.dest.?.symbol._type.?.product.terms.items, 1..) |symbver, expected, i| {
                if (!expected.c_typesMatch(_ast.unitType)) {
                    // Don't values of type `void` (don't exist in C! (Goobersville!))
                    if (!expected.c_typesMatch(symbver.symbol._type.?)) {
                        try out.writer().print("(", .{});
                        try printType(expected, out);
                        try out.writer().print(")", .{});
                    }
                    try printSymbolVersion(symbver, out);
                    if (i != ir.data.symbverList.items.len) {
                        try out.writer().print(", ", .{});
                    }
                }
            }
            try out.writer().print("}};\n", .{});
        },
        .loadUnion => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("(", .{});
            try printType(ir.dest.?.symbol._type.?, out);
            try out.writer().print(") {{.tag={}", .{ir.data.int});
            if (ir.src1) |init| {
                try out.writer().print(", ._{}=", .{ir.data.int});
                try printSymbolVersion(init, out);
            }
            try out.writer().print("}};\n", .{});
        },

        // Monadic instructions
        .copy => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .not => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("!", .{});
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .negate => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("-", .{});
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .addrOf => {
            try printVarAssign(ir.dest.?, out);
            try generateLValueIR(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .dereference => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("*", .{});
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .derefCopy => {
            try out.writer().print("    **", .{});
            try generateLValueIR(ir.src1.?, out);
            try out.writer().print(" = ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .indexCopy => if (!ir.src1.?.symbol._type.?.product.was_slice) {
            // store(lval(index(src1, src2)), rval(data.symbver))
            try out.writer().print("    *(((", .{});
            try printType(ir.data.symbver.symbol._type.?, out);
            try out.writer().print("*)(", .{});
            try generateLValueIR(ir.src1.?, out);
            try out.writer().print("))+", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(") = ", .{});
            try printSymbolVersion(ir.data.symbver, out);
            try out.writer().print(";\n", .{});
        } else {
            try out.writer().print("    *(((", .{});
            try printType(ir.data.symbver.symbol._type.?, out);
            try out.writer().print("*)((", .{});
            try generateLValueIR(ir.src1.?, out);
            try out.writer().print(")->_0))+", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(") = ", .{});
            try printSymbolVersion(ir.data.symbver, out);
            try out.writer().print(";\n", .{});
        },
        .selectCopy => {
            try out.writer().print("    (", .{});
            try generateLValueIR(ir.src1.?, out);
            try out.writer().print(")->_{} = ", .{ir.data.int});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },

        // Diadic instructions
        .notEqual => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" != ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .equal => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" == ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .greater => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" > ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .greaterEqual => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" >= ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .lesser => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" < ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .lesserEqual => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" <= ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .add => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" + ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .sub => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" - ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .mult => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" * ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .div => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" / ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .mod => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(" % ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .exponent => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("powf(", .{});
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(", ", .{});
            try printSymbolVersion(ir.src2.?, out);
            try out.writer().print(");\n", .{});
        },
        .index => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("*", .{});
            try generateLValueIR(ir.dest.?, out);
            try out.writer().print(";\n", .{});
        },
        .select => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("(", .{});
            try generateLValueIR(ir.src1.?, out);
            try out.writer().print(")->_{};\n", .{ir.data.int});
        },
        .get_tag => {
            try printVarAssign(ir.dest.?, out);
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print(".tag;\n", .{});
        },

        // Control-flow
        .label,
        .jump,
        .branchIfFalse,
        .decl,
        => {},
        else => {
            std.debug.print("Unimplemented generateIR() for: IRKind.{s}\n", .{@tagName(ir.kind)});
            return error.Unimplemented;
        },
        .call => {
            var void_fn = ir.dest.?.type.* == .unit;
            if (!void_fn) {
                try printVarAssign(ir.dest.?, out);
            } else {
                try out.writer().print("    ", .{});
            }
            try printSymbolVersion(ir.src1.?, out);
            try out.writer().print("(", .{});
            for (ir.data.symbverList.items, 0..) |symbver, i| {
                try printSymbolVersion(symbver, out);
                if (i + 1 != ir.data.symbverList.items.len) {
                    try out.writer().print(", ", .{});
                }
            }
            try out.writer().print(");\n", .{});
        },

        // Non-Code Generating
        .discard => {},

        // Errors
        .pushStackTrace => {
            var spaces = String.init(std.heap.page_allocator);
            defer spaces.deinit();
            for (1..ir.span.col - 1) |i| {
                _ = i;
                try spaces.insert(" ", spaces.size);
            }
            try out.writer().print(
                \\    $lines[$line_idx++] = "{s}:{}:{}:\n{s}\n{s}^";
                \\
            , .{ ir.span.filename, ir.span.line, ir.span.col, program.lines.items[ir.span.line - 1], spaces.str() });
        },
        .popStackTrace => {
            try out.writer().print(
                \\    $line_idx--;
                \\
            , .{});
        },
        .panic => {
            try out.writer().print(
                \\    fprintf(stderr, "panic: {s}\n");
                \\    for(uint16_t $i = 0; $i < $line_idx; $i++) {{
                \\        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
                \\    }}
                \\    exit(1);
                \\
            ,
                .{ir.data.string},
            );
        },
    }
}

// Generates the C code to evaluate the l-value of a given AST
fn generateLValueIR(symbver: *SymbolVersion, out: *std.fs.File) !void {
    if (symbver.def) |ir| {
        switch (ir.kind) {
            .dereference => {
                // The lval of a dereference is the reference itself
                try printSymbolVersion(ir.src1.?, out);
            },
            .index => {
                var lhs_type = ir.src1.?.symbol._type.?;
                if (lhs_type.* == .product and !lhs_type.product.was_slice) {
                    try out.writer().print("(((", .{});
                    try printType(ir.dest.?.symbol._type.?, out);
                    try out.writer().print("*)(", .{});
                    try generateLValueIR(ir.src1.?, out);
                    try out.writer().print("))+", .{});
                    try printSymbolVersion(ir.src2.?, out);
                    try out.writer().print(")", .{});
                } else {
                    try out.writer().print("(((", .{});
                    try printType(ir.dest.?.symbol._type.?, out);
                    try out.writer().print("*)((", .{});
                    try generateLValueIR(ir.src1.?, out);
                    try out.writer().print(")->_0))+", .{});
                    try printSymbolVersion(ir.src2.?, out);
                    try out.writer().print(")", .{});
                }
            },
            .select => {
                try out.writer().print("&((", .{});
                try generateLValueIR(ir.src1.?, out);
                try out.writer().print(")->_{}", .{ir.data.int});
                try out.writer().print(")", .{});
            },
            else => {
                try out.writer().print("&", .{});
                try printSymbolVersion(symbver, out);
            },
        }
    } else {
        // Function parameters are a common example of symbol versions that do not have a definition
        try out.writer().print("&", .{});
        try printSymbolVersion(symbver, out);
    }
}

fn printType(_type: *AST, out: *std.fs.File) !void {
    switch (_type.*) {
        .identifier => { // TODO: Print out identifier's expanded_type, make prelude types extern types
            if (std.mem.eql(u8, _type.getToken().data, "Bool")) {
                try out.writer().print("uint8_t", .{});
            } else if (std.mem.eql(u8, _type.getToken().data, "Byte")) {
                try out.writer().print("uint8_t", .{});
            } else if (std.mem.eql(u8, _type.getToken().data, "Int")) {
                try out.writer().print("int64_t", .{});
            } else if (std.mem.eql(u8, _type.getToken().data, "Float")) {
                try out.writer().print("double", .{});
            } else if (std.mem.eql(u8, _type.getToken().data, "Char")) {
                try out.writer().print("uint32_t", .{});
            } else {
                try printType(_type.getCommon().expanded_type.?, out);
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
    try printType(symbol._type.?, out);
    try out.writer().print(" ", .{});
    try printSymbol(symbol, out);
    if (!param) {
        try out.writer().print(";\n", .{});
    }
}

fn printSymbol(symbol: *Symbol, out: *std.fs.File) !void {
    try out.writer().print("_{}_{s}", .{ symbol.scope.uid, symbol.name });
}

fn printSymbolVersion(symbver: *SymbolVersion, out: *std.fs.File) !void {
    try printSymbol(symbver.symbol, out);
}

fn printReturn(return_symbol: *Symbol, out: *std.fs.File) !void {
    if (return_symbol.versions > 0) { // To fix errors when function ends in `unreachable`
        try out.writer().print("    return ", .{});
        try printSymbol(return_symbol, out);
        try out.writer().print(";\n", .{});
    }
}
