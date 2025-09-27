const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const args_ = @import("../semantic/args.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Decorate = @import("../ast/decorate.zig");
const Decorate_Access = @import("../ast/decorate-access.zig");
const interpret = @import("interpret.zig").interpret;
const Span = @import("../util/span.zig");
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const scope_validate_ = @import("../semantic/scope_validate.zig");
const Symbol_Tree = @import("../ast/symbol-tree.zig");
const Token = @import("../lexer/token.zig");
const walker_ = @import("../ast/walker.zig");

const Evaluated_Const_Args = struct {
    args: std.ArrayList(*ast_.AST),
    decls: std.ArrayList(*ast_.AST),
};

// Stamps out a new function declaration along with a fully built and validated symbol tree, and decorated identifiers.
//
// ## Returns:
// An identifier AST, decorated with the stamped out anonymous function.
// pub fn stamp(
//     template_ast: *ast_.AST,
//     args: *std.ArrayList(*ast_.AST),
//     call_span: Span,
//     scope: *Scope,
//     compiler: *Compiler_Context,
// ) !*ast_.AST {
//     std.debug.assert(template_ast.* == .template);

//     var const_decls = try evaluate_const_args(template_ast, args, call_span, scope, compiler);

//     const stamped_symbol = try get_stamp_symbol(template_ast, &const_decls, args, scope, compiler);

//     const identifier = ast_.AST.create_identifier(Token.init_simple(stamped_symbol.name), compiler.allocator());
//     identifier.set_symbol(stamped_symbol);
//     return identifier;
// }

// /// Constructs the compile-time constant declaration list.
// /// TODO: For the next feature, closed world hypo, we will validate templates as if they were normal functions. This will allow us to evaluate constant args, and use those for the type map
// fn evaluate_const_args(
//     template_ast: *ast_.AST,
//     args: *std.ArrayList(*ast_.AST),
//     call_span: Span,
//     scope: *Scope,
//     compiler: *Compiler_Context,
// ) !std.ArrayList(*ast_.AST) {
//     _ = scope;
//     // Go through each comptime arg, evaluate it, and store it in a list along with it's position
//     // Combines the arg value and the position in the args/params list
//     var const_decls = std.ArrayList(*ast_.AST).init(compiler.allocator());

//     const domain = Symbol_Tree.extract_domain(template_ast.template.decl.children().*, compiler.allocator());
//     args.* = try args_.default_args(.function, args.*, call_span, domain, &compiler.errors, compiler.allocator());
//     _ = try args_.validate_args_arity(.function, args, domain, false, call_span, &compiler.errors);

//     for (template_ast.template.decl.fn_decl._params.items, args.items) |param, arg| {
//         if (param.decl.name.pattern_symbol.kind == .@"const") {
//             const decl = ast_.AST.create_decl(
//                 param.token(),
//                 param.decl.name,
//                 param.decl.type,
//                 arg,
//                 compiler.allocator(),
//             );
//             const_decls.append(decl) catch unreachable;
//         }
//     }

//     return const_decls;
// }

// fn get_stamp_symbol(
//     template_ast: *ast_.AST,
//     const_decls: *std.ArrayList(*ast_.AST),
//     args: *std.ArrayList(*ast_.AST),
//     scope: *Scope,
//     compiler: *Compiler_Context,
// ) !*Symbol {
//     const memo_result = template_ast.template.memo.get(args.*);
//     if (memo_result) |retval| {
//         return retval;
//     }

//     const new_scope = Scope.init(scope, scope.uid_gen, compiler.allocator());

//     // Clone out a new fn decl AST, with a new name
//     // const fn_decl = template_ast.template.decl.clone(compiler.allocator());
//     // fn_decl.fn_decl.remove_const_params();
//     // fn_decl.fn_decl.name = null; // make function anonymous

//     // Create a new symbol and scope for the new fn decl
//     const fn_symbol = try Symbol_Tree.create_function_symbol(
//         fn_decl,
//         new_scope,
//         &compiler.errors,
//         compiler.allocator(),
//     );
//     try fn_symbol.scope.put_symbol(fn_symbol, &compiler.errors);
//     fn_decl.set_symbol(fn_symbol);
//     template_ast.template.memo.put(args.*, fn_symbol);

//     // Define each constant parameter in the fn decl's scope
//     try walker_.walk_asts(const_decls, Symbol_Tree.new(new_scope, &compiler.errors, compiler.allocator()));

//     // Decorate identifiers, validate
//     const decorate_context = Decorate.new(new_scope, &compiler.errors, compiler.allocator());
//     const decorate_access_context = Decorate_Access.new(new_scope, &compiler.errors, compiler);
//     for (const_decls.items) |decl| {
//         try walker_.walk_ast(decl, decorate_context);
//         try walker_.walk_ast(decl, decorate_access_context);
//     }
//     try walker_.walk_ast(fn_decl, decorate_context);
//     try walker_.walk_ast(fn_decl, decorate_access_context);
//     try scope_validate_.validate(fn_symbol.scope, compiler);

//     return fn_symbol;
// }
