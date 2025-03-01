// This file validates a CFG of IR. It checks for things like unused symbols, symbols marked `mut` that are never mutated, etc.

const std = @import("std");
const cfg_ = @import("cfg.zig");
const errs_ = @import("errors.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const primitives_ = @import("primitives.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");

pub fn validate_cfg(cfg: *cfg_.CFG, errors: *errs_.Errors) error{CompileError}!void {
    cfg.calculate_usage();
    cfg.calculate_versions();

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
            if (ir.removed) {
                continue;
            }
            if (lvalue_is_symbol(ir.dest, cfg.return_symbol)) |symbol| {
                try err_if_unused(symbol, errors);
                try err_if_var_not_mutated(symbol, errors);
            }
            if (lvalue_is_symbol(ir.src1, cfg.return_symbol)) |symbol| {
                try err_if_undefd(symbol, errors);
            }
            if (lvalue_is_symbol(ir.src2, cfg.return_symbol)) |symbol| {
                try err_if_undefd(symbol, errors);
            }
            try valid_lvalue_expanded_type_check(ir.span, ir.dest, errors);
            try valid_lvalue_expanded_type_check(ir.span, ir.src1, errors);
            try valid_lvalue_expanded_type_check(ir.span, ir.src2, errors);
        }
    }
}

fn lvalue_is_symbol(maybe_lval: ?*lval_.L_Value, return_symbol: *symbol_.Symbol) ?*symbol_.Symbol {
    if (maybe_lval != null and // exists
        maybe_lval.?.* == .symbver and // root is a symbver
        !maybe_lval.?.symbver.symbol.is_temp and // isnt temporary
        maybe_lval.?.symbver.symbol != return_symbol // isnt the function's return value
    ) {
        return maybe_lval.?.symbver.symbol;
    } else {
        return null;
    }
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

fn err_if_undefd(symbol: *symbol_.Symbol, errors: *errs_.Errors) error{CompileError}!void {
    if (symbol.uses != 0 and // symbol has been used somewhere
        symbol.defs == 0 and // symbol hasn't been defined anywhere
        !symbol.param and // symbol isn't a parameter (these don't have defs!)
        symbol.kind != .@"extern" // symbol isn't an extern (these also don't have defs!)
    ) {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = symbol.span,
            .context_span = null,
            .name = symbol.name,
            .problem = "is never defined",
            .context_message = "",
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
