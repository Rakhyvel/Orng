const _ast = @import("ast.zig");
const _ir = @import("ir.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");

const AST = _ast.AST;
const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const IR = _ir.IR;
const Program = @import("program.zig").Program;
const Scope = _symbol.Scope;
const Symbol = _symbol.Symbol;
const SymbolVersion = _ir.SymbolVersion;

/// Takes in a file handler and a program structure
pub fn generate(program: *Program, file: *std.fs.File) !void {
    try file.writer().print("/* Code generated using the Orng compiler https://ornglang.org */\n", .{});
    try file.writer().print("#ifndef ORNG_{}\n#define ORNG_{}\n\n#include <math.h>\n#include <stdio.h>\n#include <stdint.h>\n\n", .{ program.uid, program.uid });

    try file.writer().print("/* Function Definitions */\n", .{});
    try generateFowardFunctions(program.callGraph, file);
    try file.writer().print("\n", .{});
    try generateFunctions(program.callGraph, file);
    try file.writer().print("\n", .{});
    try generateMainFunction(program.callGraph, file);

    try file.writer().print("#endif\n", .{});
}

fn generateFowardFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    try printType(callGraph.symbol._type.?.function.rhs, out);
    try out.writer().print(" ", .{});
    try printPath(callGraph.symbol, out);
    try out.writer().print("(", .{});
    try printProductList(callGraph.symbol._type.?.function.lhs, out);
    try out.writer().print(");\n", .{});

    for (callGraph.children.items) |child| {
        try generateFowardFunctions(child, out);
    }
}

fn generateFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    // Print function return type, name, parameter list
    // TODO: If the function return type isn't void, create a `retval` variable
    try printType(callGraph.symbol._type.?.function.rhs, out);
    try out.writer().print(" ", .{});
    try printPath(callGraph.symbol, out);
    try out.writer().print("(", .{});
    try printProductList(callGraph.symbol._type.?.function.lhs, out);
    try out.writer().print(") {{\n", .{});

    // Collect and then declare all local variables
    for (callGraph.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest) |dest| {
                if (dest.symbol.decld or dest.type.* == .unit) {
                    continue;
                }
                try printVarDef(dest.symbol, out, false);
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

fn generateMainFunction(callGraph: *CFG, out: *std.fs.File) !void {
    if (std.mem.eql(u8, callGraph.symbol._type.?.function.rhs.identifier.common.token.data, "Int")) {
        try out.writer().print(
            \\int main()
            \\{{
            \\  printf("%ld",
        , .{});
    } else {
        try out.writer().print(
            \\int main()
            \\{{
            \\  printf("%d",
        , .{});
    }
    try printPath(callGraph.symbol, out);
    try out.writer().print(
        \\());
        \\  return 0;
        \\}}
        \\
        \\
    , .{});
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
        try out.writer().print("\tif (!", .{});
        try printVar(bb.condition.?, out);
        try out.writer().print(") {{\n", .{});

        // Generate branch `if-else`
        if (bb.branch) |branch| {
            try out.writer().print("\t\tgoto BB{};\n\t}} else {{\n", .{branch.uid});
        } else {
            try out.writer().print("\t", .{});
            try printReturn(symbol, out);
            try out.writer().print("\t}} else {{\n", .{});
        }

        // Generate the `next` BB
        if (bb.next) |next| {
            try out.writer().print("\t\tgoto BB{};\n\t}}\n", .{next.uid});
            try generateBasicBlock(next, symbol, out);
        } else {
            try out.writer().print("\t", .{});
            try printReturn(symbol, out);
            try out.writer().print("\t}}\n", .{});
        }

        // Generate the `branch` BB
        if (bb.branch) |branch| {
            try generateBasicBlock(branch, symbol, out);
        }
    } else {
        if (bb.next) |next| {
            try out.writer().print("\tgoto BB{};\n", .{next.uid});
            try generateBasicBlock(next, symbol, out);
        } else {
            try printReturn(symbol, out);
        }
    }
}

fn generateIR(ir: *IR, out: *std.fs.File) !void {
    if (ir.dest != null and ir.dest.?.lvalue and ir.kind != .copy) {
        return;
    } else if (ir.dest != null and ir.dest.?.type.* == .unit) {
        return;
    }

    switch (ir.kind) {
        .loadSymbol => {
            try printVarAssign(ir.dest.?, out);
            try printPath(ir.data.symbol, out);
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
            try out.writer().print("{s};\n", .{ir.data.string});
        },

        // Monadic instructions
        .copy => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .not => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("!", .{});
            try printVar(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .negate => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("-", .{});
            try printVar(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .addrOf => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("&", .{});
            try printVar(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .dereference => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("*", .{});
            try printVar(ir.src1.?, out);
            try out.writer().print(";\n", .{});
        },
        .derefCopy => {
            try out.writer().print("\t*", .{});
            try generateLValueIR(ir.src1.?, out);
            try out.writer().print(" = ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },

        // Diadic instructions
        .notEqual => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" != ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .equal => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" == ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .greater => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" > ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .greaterEqual => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" >= ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .lesser => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" < ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .lesserEqual => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" <= ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .add => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" + ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .sub => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" - ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .mult => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" * ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .div => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" / ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .mod => {
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print(" % ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(";\n", .{});
        },
        .exponent => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("powf(", .{});
            try printVar(ir.src1.?, out);
            try out.writer().print(", ", .{});
            try printVar(ir.src2.?, out);
            try out.writer().print(");\n", .{});
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
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print("(", .{});
            for (ir.data.symbverList.items, 0..) |symbver, i| {
                try printVar(symbver, out);
                if (i + 1 != ir.data.symbverList.items.len) {
                    try out.writer().print(", ", .{});
                }
            }
            try out.writer().print(");\n", .{});
        },

        // Errors
    }
}

fn generateLValueIR(symbver: *SymbolVersion, out: *std.fs.File) !void {
    if (symbver.lvalue and symbver.def != null) {
        var def = symbver.def.?;
        switch (def.kind) {
            .loadSymbol => {
                try printPath(def.data.symbol, out);
            },
            .copy => {
                try printPath(symbver.*.symbol, out);
            },
            .addrOf => {
                try out.writer().print("(&", .{});
                try generateLValueIR(def.src1.?, out);
                try out.writer().print(")", .{});
            },
            .dereference => {
                try out.writer().print("(*", .{});
                try generateLValueIR(def.src1.?, out);
                try out.writer().print(")", .{});
            },
            .index => {
                // TODO: defer to arrays
            },
            .select => {
                // TODO: defer to products
            },
            else => {
                std.debug.print("Not an LValue {?}\n", .{symbver.def.?.*});
                unreachable;
            },
        }
    } else {
        try printVar(symbver, out);
    }
}

fn printType(_type: *AST, out: *std.fs.File) !void {
    switch (_type.*) {
        .identifier => {
            if (std.mem.eql(u8, _type.identifier.common.token.data, "Bool")) {
                try out.writer().print("uint8_t", .{});
            } else if (std.mem.eql(u8, _type.identifier.common.token.data, "Int")) {
                try out.writer().print("int64_t", .{});
            } else if (std.mem.eql(u8, _type.identifier.common.token.data, "Float")) {
                try out.writer().print("double", .{});
            } else if (std.mem.eql(u8, _type.identifier.common.token.data, "Char")) {
                try out.writer().print("int32_t", .{});
            }
        },
        .addrOf => {
            try printType(_type.addrOf.expr, out);
            try out.writer().print("*", .{});
        },
        .function => {
            try printType(_type.function.rhs, out);
        },
        .unit => {
            try out.writer().print("void", .{});
        },
        else => {
            std.debug.print("{?}", .{_type.*});
        },
    }
}

fn printVarAssign(symbver: *SymbolVersion, out: *std.fs.File) !void {
    try out.writer().print("\t", .{});
    try printPath(symbver.symbol, out);
    try out.writer().print(" = ", .{});
}

fn printVarDef(symbol: *Symbol, out: *std.fs.File, param: bool) !void {
    if (!param) {
        try out.writer().print("\t", .{});
    }
    try printType(symbol._type.?, out);
    try out.writer().print(" ", .{});
    var is_function = symbol._type.?.* == .function;
    if (is_function) {
        try out.writer().print("(*", .{});
    }
    try printPath(symbol, out);
    if (is_function) {
        try out.writer().print(")(", .{});
        try printProductList(symbol._type.?.function.lhs, out);
        try out.writer().print(")", .{});
    }
    if (!param) {
        try out.writer().print(";\n", .{});
    }
}

fn printProductList(ast: *AST, out: *std.fs.File) std.fs.File.WriteError!void {
    switch (ast.*) {
        .product => for (ast.product.terms.items, 0..) |term, i| {
            try printType(term, out);
            if (i + 1 != ast.product.terms.items.len) {
                try out.writer().print(", ", .{});
            }
        },

        .identifier => try printType(ast, out),

        .annotation => {
            try printType(ast.annotation.type, out);
            try out.writer().print(" ", .{});
            var is_function = ast.annotation.type.* == .function;
            if (is_function) {
                try out.writer().print("(*", .{});
            }
            try out.writer().print("{s}", .{ast.annotation.pattern.identifier.common.token.data});
            if (is_function) {
                try out.writer().print(")(", .{});
                try printProductList(ast.annotation.type.function.lhs, out);
                try out.writer().print(")", .{});
            }
        },

        .unit => {},

        else => {
            std.debug.print("Unimplemented printProductList for: {s}\n", .{@tagName(ast.*)});
            unreachable;
        },
    }
}

fn printPath(symbol: *Symbol, out: *std.fs.File) !void {
    if (!symbol.param) {
        try printPathScope(symbol.scope, out);
    }
    try out.writer().print("{s}", .{symbol.name});
}

fn printPathScope(scope: *Scope, out: *std.fs.File) !void {
    if (scope.name.len > 0) {
        if (scope.parent) |parent| {
            try printPathScope(parent, out);
        }
        var i: usize = 0;
        while (i < scope.name.len) : (i += 1) {
            if (scope.name[i] == '/' or scope.name[i] == '-') {
                try out.writer().print("_", .{});
            } else {
                try out.writer().print("{c}", .{scope.name[i]});
            }
        }
        try out.writer().print("_", .{});
    } else {
        try out.writer().print("_{}_", .{scope.uid});
    }
}

fn printVar(symbver: *SymbolVersion, out: *std.fs.File) !void {
    try printPath(symbver.symbol, out);
}

fn printReturn(return_symbol: *Symbol, out: *std.fs.File) !void {
    try out.writer().print("\treturn ", .{});
    try printPath(return_symbol, out);
    try out.writer().print(";\n", .{});
}
