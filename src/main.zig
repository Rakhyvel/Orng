const std = @import("std");
const ast = @import("ast.zig");
const codegen = @import("codegen.zig");
const errs = @import("errors.zig");
const ir = @import("ir.zig");
const layout = @import("layout.zig");
const lexer = @import("lexer.zig");
const Parser = @import("parser.zig").Parser;
const Program = @import("program.zig").Program;
const symbol = @import("symbol.zig");
const Token = @import("token.zig").Token;
const typecheck = @import("typecheck.zig");

pub const PRINT_TOKENS = false;

// - compile = outputCFG <> compileFile
// - compileFile: (contents: String)->(output: &AST)
// - outputCFG: (output: &AST, outputFilename: String)->!()

// Accepts a file as an argument. That file should contain orng constant/type/function declarations, and an entry-point
// Files may also call some built-in compiletime functions which may import other Orng files, C headers, etc...
// Afterwards, the program is collated to a CFG and written to a .c file. A C compiler may be called, and a
pub fn main() !void {
    const allocator = std.heap.page_allocator;

    // Get second command line argument
    var args = try std.process.ArgIterator.initWithAllocator(allocator);
    _ = args.next() orelse unreachable;
    var arg = args.next() orelse {
        std.debug.print("{s}\n", .{"Usage: zig build run -- <orng-filename>"});
        return;
    };

    // Get the path
    var path_buffer: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    const path: []u8 = try std.fs.realpath(arg, &path_buffer);

    var errors = errs.Errors.init(allocator);
    defer errors.deinit();

    try compile(&errors, path, "examples/out.c", allocator);
}

/// Compiles and outputs a file
pub fn compile(errors: *errs.Errors, in_name: []const u8, out_name: []const u8, allocator: std.mem.Allocator) !void {
    // Open the file
    var file = try std.fs.cwd().openFile(in_name, .{});
    defer file.close();

    // Read in the contents of the file
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    try in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF);
    var contents = try contents_arraylist.toOwnedSlice();

    var lines = std.ArrayList([]const u8).init(allocator);
    defer lines.deinit();

    var file_root = compileContents(errors, &lines, contents, false, allocator) catch |err| {
        switch (err) {
            error.lexerError,
            error.parserError,
            error.symbolError,
            error.typeError,
            => {
                try errors.printErrors(&lines, in_name);
                return err;
            },
            else => return err,
        }
    };
    try output(errors, &lines, file_root, out_name, allocator);
}

/// Takes in a statically correct symbol tree, writes it out to a file
pub fn output(errors: *errs.Errors, lines: *std.ArrayList([]const u8), file_root: *symbol.Scope, out_name: []const u8, allocator: std.mem.Allocator) !void {
    // IR translation
    var irAllocator = std.heap.ArenaAllocator.init(allocator);
    defer irAllocator.deinit();
    var main_symbol = file_root.symbols.get("main");
    if (main_symbol) |msymb| {
        var cfg = try ir.CFG.create(msymb, null, allocator);

        // Code generation
        var program = try Program.init(cfg, allocator);
        var outputFile = try std.fs.cwd().createFile(
            out_name,
            .{
                .read = false,
            },
        );
        defer outputFile.close();
        try codegen.generate(program, &outputFile);
    } else {
        errors.addError(errs.Error{ .basicNoSpan = .{ .msg = "no `main` function specified", .stage = .symbolTree } });
        try errors.printErrors(lines, "");
        return error.symbolError;
    }
}

/// Takes in a string of contents, compiles it to a statically correct symbol-tree
pub fn compileContents(errors: *errs.Errors, lines: *std.ArrayList([]const u8), contents: []const u8, fuzz_tokens: bool, allocator: std.mem.Allocator) !*symbol.Scope {
    // Tokenize, and also append lines to the list of lines
    try lexer.getLines(contents, lines);
    var tokens = try lexer.getTokens(contents, errors, fuzz_tokens, allocator);
    defer tokens.deinit(); // Make copies of tokens, never take their address

    // Layout
    if (!fuzz_tokens) {
        layout.preemptBinaryOperator(&tokens);
        try layout.insertIndentDedents(&tokens);
        layout.condenseNewLines(&tokens);
        if (PRINT_TOKENS) {
            for (tokens.items) |*token| {
                token.pprint();
            }
        }
    }

    // Parse
    try ast.initTypes();
    var parser = try Parser.create(&tokens, errors, allocator);
    var program_ast = try parser.parse();

    // Symbol tree construction
    var file_root = try symbol.Scope.init(null, "test", allocator); // TODO: replace "test" with the filename, obvi
    try symbol.symbolTableFromASTList(program_ast, file_root, errors, allocator);

    // Typecheck
    try typecheck.typecheckScope(file_root, errors);

    return file_root;
}
