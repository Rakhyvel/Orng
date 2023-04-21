const std = @import("std");
const CFG = @import("ir.zig").CFG;
const Program = @import("program.zig").Program;

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
    try out.writer().print("int {s}() {{}}\n", .{callGraph.symbol.name});

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
