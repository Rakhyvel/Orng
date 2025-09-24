//! This file represents a struct for an AST walk, and is used to decorate identifier ASTs with symbols they refer to.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
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
map: std.AutoArrayHashMap(*ast_.AST, void),

pub fn new(ctx: *Compiler_Context) Self {
    return Self{
        .ctx = ctx,
        .map = std.AutoArrayHashMap(*ast_.AST, void).init(ctx.allocator()),
    };
}

pub fn prefix(self: *Self, ast: *ast_.AST) walk_.Error!?Self {
    if (self.map.get(ast)) |_| {
        return null;
    }

    try self.eval_internal(ast);
    self.map.put(ast, void{}) catch unreachable;

    return self.*;
}

fn eval_internal(self: *Self, ast: *ast_.AST) walk_.Error!void {
    switch (ast.*) {
        else => {},

        .@"comptime" => {
            const expected_type = try self.ctx.typecheck.typecheck_AST(ast, null);
            ast.* = (try self.interpret(ast.expr(), expected_type, ast.scope().?)).*;
            _ = try self.ctx.typecheck.typecheck_AST(ast, null);
        },

        .default => {
            const _type = ast.default._type;
            ast.* = (try defaults_.generate_default(ast.default._type, ast.token().span, &self.ctx.errors, self.ctx.allocator())).*;
            _ = try self.ctx.typecheck.typecheck_AST(ast, _type);
        },

        .size_of => {
            const _type = ast.size_of._type;
            ast.* = ast_.AST.create_int(ast.token(), _type.sizeof(), self.ctx.allocator()).*;
            _ = try self.ctx.typecheck.typecheck_AST(ast, null);
        },
    }
}

pub fn interpret(
    self: *Self,
    ast: *ast_.AST,
    ret_type: *Type_AST,
    scope: *Scope,
) !*ast_.AST {
    const symbol: *Symbol = (try Symbol_Tree.create_temp_comptime_symbol(
        ast,
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
    return try context.extract_ast(0, ret_type, ast.token().span);
}
