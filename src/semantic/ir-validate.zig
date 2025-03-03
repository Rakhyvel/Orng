// This file validates a CFG of IR. It checks for things like unused symbols, symbols marked `mut` that are never mutated, etc.

const std = @import("std");
const cfg_ = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const ir_ = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const span_ = @import("../util/span.zig");
const symbol_ = @import("../symbol/symbol.zig");

pub fn validate_cfg(cfg: *cfg_.CFG, errors: *errs_.Errors) error{CompileError}!void {
    cfg.calculate_usage();
    cfg.calculate_definitions();

    if (cfg.symbol.decl.?.* == .fn_decl or cfg.symbol.decl.?.* == .method_decl) {
        const param_symbols = if (cfg.symbol.decl.?.* == .fn_decl) cfg.symbol.decl.?.fn_decl.param_symbols else cfg.symbol.decl.?.method_decl.param_symbols;
        for (param_symbols.items) |param_symbol| {
            try err_if_unused(param_symbol, errors);
            try err_if_var_not_mutated(param_symbol, errors);
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir: ?*ir_.IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and // has a dest symbol to test
                ir.dest.?.* == .symbver and // dest is symbver
                !ir.dest.?.symbver.symbol.is_temp and // dest symbver's symbol isn't temporary
                ir.dest.?.symbver.symbol != cfg.return_symbol // dest symbver's symbol isn't the function's return value
            ) {
                try err_if_unused(ir.dest.?.symbver.symbol, errors);
                try err_if_var_not_mutated(ir.dest.?.symbver.symbol, errors);
            }
            try err_if_chain_undefd(ir.src1, errors, cfg.return_symbol, ir.span);
            try err_if_chain_undefd(ir.src2, errors, cfg.return_symbol, ir.span);
            if (ir.data == .lval_list) {
                for (ir.data.lval_list.items) |lval| {
                    try err_if_chain_undefd(lval, errors, cfg.return_symbol, ir.span);
                }
            }
            if (ir.data == .invoke) {
                try err_if_chain_undefd(ir.data.invoke.dyn_value, errors, cfg.return_symbol, ir.span);
                for (ir.data.invoke.lval_list.items) |lval| {
                    try err_if_chain_undefd(lval, errors, cfg.return_symbol, ir.span);
                }
            }
            try valid_lvalue_expanded_type_check(ir.span, ir.dest, errors);
            try valid_lvalue_expanded_type_check(ir.span, ir.src1, errors);
            try valid_lvalue_expanded_type_check(ir.span, ir.src2, errors);
        }
    }
}

fn lvalue_is_symbol(symbol: *symbol_.Symbol, return_symbol: *symbol_.Symbol) bool {
    return !symbol.is_temp and // isnt temporary
        symbol != return_symbol // isnt the function's return value
    ;
}

/// Throws an `error.CompileError` if a symbol is not used.
fn err_if_unused(symbol: *symbol_.Symbol, errors: *errs_.Errors) error{CompileError}!void {
    if (symbol.kind != .@"const" and
        symbol.uses == 0)
    {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = symbol.span,
            .context_span = null,
            .name = symbol.name,
            .problem = "is never used",
            .context_message = "",
        } });
        return error.CompileError;
    }
}

fn err_if_chain_undefd(maybe_lval: ?*lval_.L_Value, errors: *errs_.Errors, return_symbol: *symbol_.Symbol, use: span_.Span) error{CompileError}!void {
    if (maybe_lval == null) {
        return;
    }

    switch (maybe_lval.?.*) {
        .symbver => if (lvalue_is_symbol(maybe_lval.?.symbver.symbol, return_symbol)) {
            try err_if_undefd(maybe_lval.?.symbver.symbol, errors, use);
        },
        .dereference => try err_if_chain_undefd(maybe_lval.?.dereference.expr, errors, return_symbol, use),
        .index => {
            try err_if_chain_undefd(maybe_lval.?.index.length, errors, return_symbol, use);
            try err_if_chain_undefd(maybe_lval.?.index.lhs, errors, return_symbol, use);
            try err_if_chain_undefd(maybe_lval.?.index.rhs, errors, return_symbol, use);
        },
        .select => {
            try err_if_chain_undefd(maybe_lval.?.select.tag, errors, return_symbol, use);
            try err_if_chain_undefd(maybe_lval.?.select.lhs, errors, return_symbol, use);
        },
        .raw_address => std.debug.panic("compiler error: undefined err_if_chain_undefd for raw_address", .{}),
    }
}

fn err_if_undefd(symbol: *symbol_.Symbol, errors: *errs_.Errors, use: span_.Span) error{CompileError}!void {
    // std.debug.print("{s} uses:{} defs:{}\n", .{ symbol.name, symbol.uses, symbol.defs });
    if (symbol.uses != 0 and // symbol has been used somewhere
        symbol.defs == 0 and // symbol hasn't been defined anywhere
        !symbol.param and // symbol isn't a parameter (these don't have defs!)
        symbol.kind != .@"extern" // symbol isn't an extern (these also don't have defs!)
    ) {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = use,
            .context_span = symbol.span,
            .name = symbol.name,
            .problem = "is never defined",
            .context_message = "declared here",
        } });
        return error.CompileError;
    }
}

/// Throws an `error.CompileError` if a symbol is marked `mut`, but is never mutated.
///
/// Symbols are mutated when:
/// - They are the root of at least one IR's destination's L-Value tree, OR
/// - They are aliased with `&mut`.
fn err_if_var_not_mutated(symbol: *symbol_.Symbol, errors: *errs_.Errors) error{CompileError}!void {
    if (symbol.kind == .mut and
        symbol.aliases == 0 and
        symbol.roots == 0)
    {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = symbol.span,
            .context_span = null,
            .name = symbol.name,
            .problem = "is marked `mut` but is never mutated",
            .context_message = "",
        } });
        return error.CompileError;
    }
}

fn valid_lvalue_expanded_type_check(span: span_.Span, lvalue: ?*lval_.L_Value, errors: *errs_.Errors) error{CompileError}!void {
    if (lvalue != null and !lvalue.?.get_expanded_type().valid_type()) {
        errors.add_error(errs_.Error{ .recursive_definition = .{
            .span = span,
            .symbol_name = null,
        } });
        return error.CompileError;
    }
}
