const _ir = @import("ir.zig");
const std = @import("std");
const _symbol = @import("symbol.zig");

const BasicBlock = _ir.BasicBlock;
const CFG = _ir.CFG;
const IR = _ir.IR;
const Program = @import("program.zig").Program;
const Symbol = _symbol.Symbol;
const SymbolVersion = _ir.SymbolVersion;

/// Takes in a file handler and a program structure
pub fn generate(program: *Program, file: *std.fs.File) !void {
    try file.writer().print("/* Code generated using the Orng compiler https://ornglang.org */\n", .{});
    try file.writer().print("#ifndef ORNG_{}\n#define ORNG_{}\n\n", .{ program.uid, program.uid });

    try file.writer().print("/* Function Definitions */\n", .{});
    try generateFowardFunctions(program.callGraph, file);
    try file.writer().print("\n", .{});
    try generateFunctions(program.callGraph, file);
    try file.writer().print("\n", .{});
    try generateMainFunction(program.callGraph, file);

    try file.writer().print("#endif\n", .{});
}

fn generateFowardFunctions(callGraph: *CFG, out: *std.fs.File) !void {
    try out.writer().print("int {s}();\n", .{callGraph.symbol.name});

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
    try out.writer().print("int test_{s}() {{\n", .{callGraph.symbol.name});

    // TODO: If the function return type isn't void, create a `retval` variable

    // TODO: Declare all (registers) used by the function
    for (callGraph.basic_blocks.items) |bb| {
        var maybe_ir: ?*IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest) |dest| {
                try printVarDef(dest, out);
            }
        }
    }

    // Generate the basic-block graph, starting at the init basic block
    if (callGraph.block_graph_head) |block_graph_head| {
        try generateBasicBlock(block_graph_head, out);
    }

    // Generate the `end` basic block
    try out.writer().print("}}\n", .{});

    // Generate leaf functions
    for (callGraph.leaves.items) |leaf| {
        try generateFowardFunctions(leaf, out);
    }
}

fn generateMainFunction(callGraph: *CFG, out: *std.fs.File) !void {
    _ = callGraph;
    try out.writer().print(
        \\int main()
        \\{{
        \\  printf("Hello, World!");
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
    defer bb.visited = false;

    try out.writer().print("BB{}:;\n", .{bb.uid});
    var maybe_ir = bb.ir_head;
    while (maybe_ir) |ir| : (maybe_ir = ir.next) {
        try generateIR(ir, out);
    }

    if (bb.has_branch) {
        // Generate the if
        // Generate the `branch` BB
        // Generate the `next` BB
    } else if (bb.next) |_| {
        // generatePhi
        // \tgoto BB{};\n
        // Generate the `next` BB
    } else {
        // \tgoto end;\n
    }
}

fn generateIR(ir: *IR, out: *std.fs.File) !void {
    switch (ir.kind) {
        .loadInt => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("{};\n", .{ir.data.int});
        },
        .loadFloat => {
            try printVarAssign(ir.dest.?, out);
            try out.writer().print("{};\n", .{ir.data.float});
        },
        else => {
            std.debug.print("Unimplemented generateIR() for: IRKind.{s}\n", .{@tagName(ir.kind)});
            return error.Unimplemented;
        },
    }
}

fn printVarAssign(symbver: *SymbolVersion, out: *std.fs.File) !void {
    try out.writer().print("\t", .{});
    if (symbver.symbol.name[0] != '$') {
        try printPath(symbver.symbol, out);
    }
    try out.writer().print("_{} = ", .{symbver.version.?});
}

fn printVarDef(symbver: *SymbolVersion, out: *std.fs.File) !void {
    try out.writer().print("\tint ", .{});
    if (symbver.symbol.name[0] != '$') {
        try printPath(symbver.symbol, out);
    }
    try out.writer().print("_{};\n", .{symbver.version.?});
}

fn printPath(symbol: *Symbol, out: *std.fs.File) !void {
    try out.writer().print("{s}", .{symbol.name});
}
