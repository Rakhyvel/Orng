const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const args_ = @import("../semantic/args.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Decorate = @import("../ast/decorate.zig");
const Decorate_Access = @import("../ast/decorate-access.zig");
const Span = @import("../util/span.zig");
const Scope = @import("../symbol/scope.zig");
const scope_validate_ = @import("../semantic/scope_validate.zig");
const Symbol_Tree = @import("../ast/symbol-tree.zig");
const Token = @import("../lexer/token.zig");
const walker_ = @import("../ast/walker.zig");

/// Stamps out a new function declaration along with a fully built and validated symbol tree, and decorated identifiers.
///
/// ## Returns:
/// An identifier AST, decorated with the stamped out anonymous function.
pub fn stamp(
    template_ast: *ast_.AST,
    args: *std.ArrayList(*ast_.AST),
    call_span: Span,
    scope: *Scope,
    compiler: *Compiler_Context,
) !*ast_.AST {
    std.debug.assert(template_ast.* == .template);
    if (template_ast.template.memo == null) {
        // Clone out a new fn decl AST, with a new name
        const fn_decl = template_ast.template.decl.clone(compiler.allocator());
        fn_decl.fn_decl.remove_const_params();
        fn_decl.fn_decl.name = null; // make function anonymous

        // Create a new symbol and scope for the new fn decl
        const fn_symbol = try Symbol_Tree.create_function_symbol(
            fn_decl,
            scope,
            &compiler.errors,
            compiler.allocator(),
        );
        try fn_symbol.scope.put_symbol(fn_symbol, &compiler.errors);
        fn_decl.set_symbol(fn_symbol);

        const domain = Symbol_Tree.extract_domain(template_ast.template.decl.children().*, compiler.allocator());
        args.* = try args_.default_args(.function, args.*, call_span, domain, &compiler.errors, compiler.allocator());
        _ = try args_.validate_args_arity(.function, args, domain, false, call_span, &compiler.errors);

        // Go through each comptime arg, evaluate it, and store it in a list along with it's position
        // Combines the arg value and the position in the args/params list
        var const_decls = std.ArrayList(*ast_.AST).init(compiler.allocator());
        defer const_decls.deinit();
        for (template_ast.template.decl.fn_decl._params.items, args.items) |param, arg| {
            if (param.decl.pattern.pattern_symbol.kind == .@"const") {
                const decl = ast_.AST.create_decl(
                    param.token(),
                    param.decl.pattern,
                    param.decl.type,
                    arg, // TODO: Comptime eval this
                    true,
                    compiler.allocator(),
                );
                const_decls.append(decl) catch unreachable;
            }
        }

        // Define each constant parameter in the fn decl's scope
        try walker_.walk_asts(&const_decls, Symbol_Tree.new(scope, &compiler.errors, compiler.allocator()));

        // Decorate identifiers, validate
        const decorate_context = Decorate.new(scope, &compiler.errors, compiler.allocator());
        const decorate_access_context = Decorate_Access.new(scope, &compiler.errors, compiler);
        for (const_decls.items) |decl| {
            try walker_.walk_ast(decl, decorate_context);
            try walker_.walk_ast(decl, decorate_access_context);
        }
        try walker_.walk_ast(fn_decl, decorate_context);
        try walker_.walk_ast(fn_decl, decorate_access_context);
        try scope_validate_.validate(fn_symbol.scope, compiler);

        // Memoize symbol
        template_ast.template.memo = fn_symbol;
    }

    const identifier = ast_.AST.create_identifier(Token.init_simple(template_ast.template.memo.?.name), compiler.allocator());
    identifier.set_symbol(template_ast.template.memo);
    return identifier;
}
