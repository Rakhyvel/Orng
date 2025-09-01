const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const args_ = @import("../semantic/args.zig");
const cfg_builder_ = @import("../ir/cfg_builder.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Interpreter_Context = @import("../interpretation/interpreter.zig");
const Decorate = @import("../ast/decorate.zig");
const Decorate_Access = @import("../ast/decorate-access.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const Span = @import("../util/span.zig");
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const scope_validate_ = @import("../semantic/scope_validate.zig");
const Symbol_Tree = @import("../ast/symbol-tree.zig");
const Token = @import("../lexer/token.zig");
const typing_ = @import("typing.zig");
const UID_Gen = @import("../util/uid_gen.zig");
const walker_ = @import("../ast/walker.zig");

/// Relatively light-weight way to interpret an AST.
///
/// - `ast`: AST to interpret
/// - `ret_type`: Expected return type of the AST after interpretation
/// - `scope`: Scope context to interpret the AST within
/// - `errors`: Error managing context, to output errors to
/// - `allocator`: Allocator to use for interpretation
///
/// TODO: Move to compiler
///
/// Errors out either during AST-Instruction lowering, or interpretation.
pub fn interpret(
    ast: *ast_.AST,
    ret_type: *ast_.AST,
    scope: *Scope,
    compiler: *Compiler_Context,
) error{ CompileError, LexerError, ParseError }!*ast_.AST {
    const symbol: *Symbol = (try Symbol_Tree.create_temp_comptime_symbol(
        ast,
        ret_type,
        scope,
        compiler.allocator(),
    )).assert_symbol_valid().assert_init_valid();

    // Get the cfg from the symbol, and embed into the module
    const module = symbol.scope.module.?;
    const intered_strings = compiler.lookup_interned_string_set(module.uid).?;

    const cfg = try cfg_builder_.get_cfg(symbol, intered_strings, &compiler.errors, compiler.allocator());
    defer cfg.deinit(); // Remove the cfg so that it isn't output

    const idx = cfg.emplace_cfg(&module.cfgs, &module.instructions);
    defer module.pop_cfg(idx); // Remove the cfg so that it isn't output

    // Create a context and interpret
    var context = Interpreter_Context.init(&compiler.errors, compiler.allocator());
    context.set_entry_point(cfg, ret_type);
    defer context.deinit();
    context.load_module(module);
    try context.run(compiler);

    // Extract the retval
    const retval = try context.extract_ast(0, ret_type, ast.token().span, &compiler.module_interned_strings);
    return retval.expand_type(compiler);
}

pub fn eval_comptime(ast: *ast_.AST, expected: ?*ast_.AST, compiler: *Compiler_Context) error{ LexerError, ParseError, CompileError }!*ast_.AST {
    if (ast.@"comptime".result != null) {
        return ast.@"comptime".result.?;
    }
    if (ast.@"comptime".expanding) {
        return ast;
    }
    ast.@"comptime".expanding = true;
    std.debug.print("{}\n\n", .{ast.expr()});
    const ast_type = try ast.expr().typeof(compiler);
    const expanded_ast_type = try ast_type.expand_type(compiler);
    if (try typing_.checked_types_match(expanded_ast_type, prelude_.void_type, &compiler.errors)) {
        return typing_.throw_unexpected_void_type(ast.expr().token().span, &compiler.errors);
    }
    try typing_.type_check(ast.token().span, expanded_ast_type, expected, &compiler.errors);

    var expanded_expected = expected;
    if (expected != null and expected.?.* == .type_of) {
        expanded_expected = try expected.?.expand_type(compiler);
    }
    ast.@"comptime".result = try interpret(ast.expr(), expanded_expected orelse expanded_ast_type, ast.scope().?, compiler);
    return ast.@"comptime".result.?;
}
