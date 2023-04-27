const _ir = @import("ir.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");

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
    try file.writer().print("#ifndef ORNG_{}\n#define ORNG_{}\n\n#include <math.h>\n#include <stdio.h>\n\n", .{ program.uid, program.uid });

    try file.writer().print("/* Function Definitions */\n", .{});
    try generateFowardFunctions(program.callGraph, file);
    try file.writer().print("\n", .{});
    try generateFunctions(program.callGraph, file);
    try file.writer().print("\n", .{});
    try generateMainFunction(program.callGraph, file);

    try file.writer().print("#endif\n", .{});
}

fn generateFowardFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    try out.writer().print("int test_{s}();\n", .{callGraph.symbol.name});

    for (callGraph.leaves.items) |leaf| {
        try generateFowardFunctions(leaf, out);
    }
}

fn generateFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    if (callGraph.visited) {
        return;
    }
    callGraph.visited = true;
    defer callGraph.visited = false;

    // Print function return type, name, parameter list
    // TODO: If the function return type isn't void, create a `retval` variable
    try out.writer().print("int test_{s}() {{\n\tint retval;\n", .{callGraph.symbol.name});

    // TODO: Declare all (registers) used by the function
    for (callGraph.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest) |dest| {
                if (dest.def != ir) {
                    continue;
                }
                try printVarDef(dest, out);
            }
        }
    }

    // Generate the basic-block graph, starting at the init basic block
    if (callGraph.block_graph_head) |block_graph_head| {
        try generateBasicBlock(block_graph_head, out);
        callGraph.clearVisitedBBs();
    }

    // Generate the `end` basic block
    try out.writer().print("end:\n\treturn retval;\n}}\n\n", .{});

    // Generate leaf functions
    for (callGraph.leaves.items) |leaf| {
        try generateFunctions(leaf, out);
    }
}

fn generateMainFunction(callGraph: *CFG, out: *std.fs.File) !void {
    _ = callGraph;
    try out.writer().print(
        \\int main()
        \\{{
        \\  printf("Result: %d\n", test_main());
        \\  return 0;
        \\}}
        \\
        \\
    , .{});
}

fn generateBasicBlock(bb: *BasicBlock, out: *std.fs.File) !void {
    if (bb.visited) {
        return;
    }
    bb.visited = true;

    try out.writer().print("BB{}:;\n", .{bb.uid});
    var maybe_ir = bb.ir_head;
    while (maybe_ir) |ir| : (maybe_ir = ir.next) {
        try generateIR(ir, out);
        ir.pprint();
    }

    if (bb.has_branch) {
        // Generate the if
        try out.writer().print("\tif (!", .{});
        try printVar(bb.condition.?, out);
        try out.writer().print(") {{\n", .{});

        // Generate branch `if-else`
        if (bb.branch) |branch| {
            // TODO: generatePhi
            try out.writer().print("\t\tgoto BB{};\n\t}} else {{\n", .{branch.uid});
        } else {
            // TODO: generatePhi
            try out.writer().print("\t\tgoto end;\n\t}} else {{\n", .{});
        }

        // Generate the `next` BB
        if (bb.next) |next| {
            // TODO: generatePhi
            try out.writer().print("\t\tgoto BB{};\n\t}}\n", .{next.uid});
            try generateBasicBlock(next, out);
        } else {
            try out.writer().print("\t\tgoto end;\n\t}}\n", .{});
        }

        // Generate the `branch` BB
        if (bb.branch) |branch| {
            // TODO: generatePhi
            try generateBasicBlock(branch, out);
        }
    } else {
        if (bb.next) |next| {
            // TODO: generatePhi
            try out.writer().print("\tgoto BB{};\n", .{next.uid});
            try generateBasicBlock(next, out);
        } else {
            try out.writer().print("\tgoto end;\n", .{});
        }
    }
}

fn generateIR(ir: *IR, out: *std.fs.File) !void {
    if (ir.dest != null and ir.dest.?.lvalue and ir.kind != .copy) {
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
        .phony => {},

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
            try printVarAssign(ir.dest.?, out);
            try printVar(ir.src1.?, out);
            try out.writer().print("(", .{});
            for (ir.data.symbverList.items) |symbver| {
                try printVar(symbver, out);
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
                unreachable;
            },
        }
    } else {
        try printVar(symbver, out);
    }
}

fn printVarAssign(symbver: *SymbolVersion, out: *std.fs.File) !void {
    try out.writer().print("\t", .{});
    if (std.mem.eql(u8, symbver.symbol.name, "$retval")) {
        try out.writer().print("retval = ", .{});
    } else {
        if (symbver.symbol.name[0] != '$') {
            try printPath(symbver.symbol, out);
        }
        try out.writer().print("_{} = ", .{symbver.version orelse 0}); // TODO: Assert versioned
    }
}

fn printVarDef(symbver: *SymbolVersion, out: *std.fs.File) !void {
    try out.writer().print("\tint ", .{});
    if (symbver.symbol.name[0] != '$') {
        try printPath(symbver.symbol, out);
    }
    try out.writer().print("_{};\n", .{symbver.version orelse 0}); // TODO: Assert versioned
}

fn printPath(symbol: *Symbol, out: *std.fs.File) !void {
    try printPathScope(symbol.scope, out);
    try out.writer().print("{s}", .{symbol.name});
}

fn printPathScope(scope: *Scope, out: *std.fs.File) !void {
    if (scope.parent) |parent| {
        try printPathScope(parent, out);
    }
    try out.writer().print("{s}", .{scope.name});
    if (scope.name.len > 0) {
        try out.writer().print("_", .{});
    }
}

fn printVar(symbver: *SymbolVersion, out: *std.fs.File) !void {
    if (symbver.symbol.name[0] != '$') {
        try printPath(symbver.symbol, out);
    }
    try out.writer().print("_{}", .{symbver.version orelse 0}); // TODO: Assert versioned
}
