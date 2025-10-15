//! This file represents a struct for an AST walk, and is used to decorate identifier ASTs with symbols they refer to.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Ast_Id = @import("../ast/ast_store.zig").Ast_Id;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const Interpreter_Context = @import("../interpretation/interpreter.zig");
const errs_ = @import("../util/errors.zig");
const defaults_ = @import("defaults.zig");
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const Symbol_Tree = @import("../ast/symbol-tree.zig");
const walk_ = @import("../ast/walker.zig");

const Self: type = @This();

ctx: *Compiler_Context,
map: std.AutoArrayHashMap(Ast_Id, void),

pub fn new(ctx: *Compiler_Context) Self {
    return Self{
        .ctx = ctx,
        .map = std.AutoArrayHashMap(Ast_Id, void).init(ctx.allocator()),
    };
}

pub fn prefix(self: *Self, ast_id: Ast_Id) walk_.Error!?Self {
    const ast = self.ctx.ast_store.get(ast_id);
    if (self.map.get(ast)) |_| {
        return null;
    }

    try self.eval_internal(ast);
    self.map.put(ast, void{}) catch unreachable;

    return self.*;
}

fn eval_internal(self: *Self, ast_id: Ast_Id) walk_.Error!void {
    const ast = self.ctx.ast_store.get(ast_id);
    switch (ast.*) {
        else => {},

        .@"comptime" => {
            try self.eval_internal(ast.expr());
            const expected_type = self.ctx.typecheck.typecheck_AST(ast, null) catch return error.CompileError;
            ast.* = (try self.interpret(ast.expr(), expected_type, ast.scope().?)).*;
            _ = self.ctx.typecheck.typecheck_AST(ast, expected_type) catch return error.CompileError;
        },

        .default => {
            const _type = ast.default._type;
            ast.* = (try defaults_.generate_default(ast.default._type, ast.span(), &self.ctx.errors, self.ctx.allocator())).*;
            _ = self.ctx.typecheck.typecheck_AST(ast, _type) catch return error.CompileError;
        },

        .size_of => {
            const _type = ast.size_of._type;
            self.ctx.ast_store.replace(ast_id, .{ .int = .{ ._token = ast.token(), .data = _type.sizeof() } });
            _ = self.ctx.typecheck.typecheck_AST(ast, null) catch return error.CompileError;
        },
    }
}

pub fn interpret(
    self: *Self,
    ast_id: Ast_Id,
    ret_type: *Type_AST,
    scope: *Scope,
) !Ast_Id {
    const symbol_tree = Symbol_Tree.new(scope, &self.ctx.errors, self.ctx.allocator());
    const symbol: *Symbol = (try symbol_tree.create_temp_comptime_symbol(
        ast_id,
        ret_type,
        scope,
        self.ctx.allocator(),
    )).assert_symbol_valid().assert_init_valid();

    // Get the cfg from the symbol, and embed into the module
    const module = symbol.scope.module.?;
    const intered_strings = self.ctx.lookup_interned_string_set(module.uid).?;
    const cfg = try self.ctx.cfg_store.get_cfg(symbol, intered_strings);
    defer cfg.deinit(); // Remove the cfg so that it isn't output

    const idx = cfg.emplace_cfg(&module.cfgs, &module.instructions);
    defer module.pop_cfg(idx); // Remove the cfg so that it isn't output

    // Create a context and interpret
    var context = Interpreter_Context.init(self.ctx);
    context.set_entry_point(cfg, ret_type);
    defer context.deinit();
    context.load_module(module);
    try context.run();

    // Extract the retval
    const ast = self.ctx.ast_store.get(ast_id);
    return try context.extract_ast(0, ret_type, ast.span());
}
