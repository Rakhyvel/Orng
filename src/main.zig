const std = @import("std");
const ast = @import("ast.zig");
// const codegen = @import("codegen.zig");
const Context = @import("interpreter.zig").Context;
const errs = @import("errors.zig");
const ir = @import("ir.zig");
const layout = @import("layout.zig");
const lexer = @import("lexer.zig");
const Parser = @import("parser.zig").Parser;
const primitives = @import("primitives.zig");
const module_ = @import("module.zig");
const Module = module_.Module;
const Span = @import("span.zig");
const symbol = @import("symbol.zig");
const Token = @import("token.zig").Token;
const validate = @import("validate.zig");
const optimizations = @import("optimizations.zig");

// Accepts a file as an argument. That file should contain orng constant/type/function declarations, and an entry-point
// Files may also call some built-in compiletime functions which may import other Orng files, C headers, etc...
// Afterwards, the program is collated to a CFG and written to a .c file. A C compiler may be called, and a
pub fn main() !void {
    const allocator = std.heap.page_allocator;

    // Get second command line argument
    var args = try std.process.ArgIterator.initWithAllocator(allocator);
    _ = args.next() orelse unreachable;
    const arg = args.next() orelse {
        std.debug.print("{s}\n", .{"Usage: zig build run -- <orng-filename>"});
        return;
    };

    // Get the path
    var path_buffer: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    const path: []u8 = try std.fs.realpath(arg, &path_buffer);

    // Parse further args
    var fuzz_tokens = false;
    if (args.next()) |_arg| {
        if (std.mem.eql(u8, "--fuzz", _arg)) {
            fuzz_tokens = true;
        } else {
            std.debug.print("invalid command-line argument: {s}\nusage: orng-test (integration | coverage | fuzz)\n", .{_arg});
            return error.InvalidCliArgument;
        }
    }

    var errors = errs.Errors.init(allocator);
    defer errors.deinit();

    const prelude = try primitives.init();

    if (fuzz_tokens) {
        compile(&errors, path, "examples/out.c", prelude, fuzz_tokens, allocator) catch {};
    } else {
        try compile(&errors, path, "examples/out.c", prelude, fuzz_tokens, allocator);
    }
}

/// Compiles and outputs a file
pub fn compile(
    errors: *errs.Errors,
    in_name: []const u8,
    out_name: []const u8,
    prelude: *symbol.Scope,
    fuzz_tokens: bool,
    allocator: std.mem.Allocator,
) !void {
    // Open the file
    var file = try std.fs.cwd().openFile(in_name, .{});
    defer file.close();

    const stat = try file.stat();
    const uid = stat.mtime;
    _ = uid;

    // Read in the contents of the file
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    defer contents_arraylist.deinit();
    try in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF);
    const contents = try contents_arraylist.toOwnedSlice();

    const module = Module.compile(contents, in_name, prelude, fuzz_tokens, errors, allocator) catch |err| {
        switch (err) {
            error.lexerError,
            error.parserError,
            => {
                try errors.printErrors();
                return err;
            },
            error.symbolError,
            error.typeError,
            => if (!fuzz_tokens) {
                try errors.printErrors();
                return err;
            } else {
                return err;
            },
            else => return err,
        }
    };
    try module.output(out_name, errors, allocator);
    // catch |err| {
    //     switch (err) {
    //         error.symbolError,
    //         error.typeError,
    //         => if (!fuzz_tokens) {
    //             try errors.printErrors();
    //             return err;
    //         },
    //         else => return err,
    //     }
    // };
}
