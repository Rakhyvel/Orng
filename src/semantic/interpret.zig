const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const args_ = @import("../semantic/args.zig");
const cfg_builder_ = @import("../ir/cfg_builder.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Interpreter_Context = @import("../interpretation/interpreter.zig");
const Decorate = @import("../ast/decorate.zig");
const Decorate_Access = @import("../ast/decorate-access.zig");
const Span = @import("../util/span.zig");
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const scope_validate_ = @import("../semantic/scope_validate.zig");
const Symbol_Tree = @import("../ast/symbol-tree.zig");
const Token = @import("../lexer/token.zig");
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
) !*ast_.AST {
    const symbol: *Symbol = (try Symbol_Tree.create_temp_comptime_symbol(
        ast,
        ret_type,
        scope,
        compiler.allocator(),
    )).assert_symbol_valid().assert_init_valid();

    // Get the cfg from the symbol, and embed into the module
    const module = symbol.scope.module.?;
    const intered_strings = compiler.lookup_interned_string_set(module.uid).?;
    const cfg = try cfg_builder_.get_cfg(symbol, null, intered_strings, &compiler.errors, compiler.allocator());
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
    return try context.extract_ast(0, ret_type, ast.token().span, &compiler.module_interned_strings);
}
