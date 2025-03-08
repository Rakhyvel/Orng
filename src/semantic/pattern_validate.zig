//! This file contains various semantic checks relating to pattern-matching.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Compiler_Context = @import("../compilation/compiler.zig");
const errs_ = @import("../util/errors.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const Span = @import("../util/span.zig");
const poison_ = @import("../ast/poison.zig");
const validate_AST = @import("ast-validate.zig").validate_AST;
const typing_ = @import("typing.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

/// Validates that `pattern` is valid given a match's `expr`
pub fn assert_pattern_matches(
    pattern: *ast_.AST,
    expr_type: *ast_.AST,
    compiler: *Compiler_Context,
) Validate_Error_Enum!void {
    switch (pattern.*) {
        .unit_value => try typing_.type_check(pattern.token().span, primitives_.unit_type, expr_type, &compiler.errors),
        .int => try typing_.type_check_int(pattern, expr_type, &compiler.errors, compiler.allocator()),
        .char => try typing_.type_check(pattern.token().span, primitives_.char_type, expr_type, &compiler.errors),
        .string => try typing_.type_check(pattern.token().span, primitives_.string_type, expr_type, &compiler.errors),
        .float => try typing_.type_check_float(pattern, expr_type, &compiler.errors),
        .true, .false => try typing_.type_check(pattern.token().span, primitives_.bool_type, expr_type, &compiler.errors),
        .block => {
            const new_pattern = validate_AST(pattern, expr_type, compiler);
            try poison_.assert_none_poisoned(new_pattern);
            try typing_.type_check(pattern.token().span, new_pattern.typeof(compiler.allocator()), expr_type, &compiler.errors);
        },
        .select, .sum_value => {
            const new_pattern = validate_AST(pattern, expr_type, compiler);
            try poison_.assert_none_poisoned(new_pattern);
            pattern.set_pos(new_pattern.pos().?);
            try typing_.type_check(pattern.token().span, new_pattern.typeof(compiler.allocator()), expr_type, &compiler.errors);
        },
        .product => {
            const expanded_expr_type = expr_type.expand_type(compiler.allocator());
            if (expanded_expr_type.* != .product or expanded_expr_type.children().items.len != pattern.children().items.len) {
                return typing_.throw_unexpected_type(pattern.token().span, expr_type, pattern.typeof(compiler.allocator()), &compiler.errors);
            }
            for (pattern.children().items, expanded_expr_type.children().items) |term, expanded_term| {
                try assert_pattern_matches(term, expanded_term, compiler);
            }
        },
        .pattern_symbol => {},
        else => std.debug.panic("compiler error: unimplemented assert_pattern_matches() for {s}", .{@tagName(pattern.*)}),
    }
    _ = pattern.assert_ast_valid();
}

/// Checks that a match's mappings cover all possible cases
///
/// Currently only checks that all sums are covered.
/// HUGE TODO: Figure out how to do this fr for products
pub fn exhaustive_check(
    _type: *ast_.AST,
    mappings: *std.ArrayList(*ast_.AST),
    match_span: Span,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!void {
    if (_type.* == .sum_type) {
        var total_sum_ids = std.ArrayList(usize).init(allocator);
        defer total_sum_ids.deinit();

        // Append all sum IDs to the ids list
        for (_type.children().items, 0..) |_, i| {
            total_sum_ids.append(i) catch unreachable;
        }
        // For each sum ID, remove it if it's covered
        // Yeah I know this sucks. Figure out something better!
        for (mappings.items) |m| {
            exhaustive_check_sub(m.lhs(), &total_sum_ids);
        }
        // If there were any IDs that weren't removed, they weren't covered with a pattern match
        if (total_sum_ids.items.len > 0) {
            var forgotten_sum_variants = std.ArrayList(*ast_.AST).init(allocator); // Not deallocated, lives until error emission
            for (total_sum_ids.items) |id| {
                forgotten_sum_variants.append(_type.children().items[id]) catch unreachable;
            }
            errors.add_error(errs_.Error{ .non_exhaustive_sum = .{ .span = match_span, .forgotten = forgotten_sum_variants } });
            return error.CompileError;
        }
    }
}

fn exhaustive_check_sub(ast: *ast_.AST, ids: *std.ArrayList(usize)) void {
    switch (ast.*) {
        .select, .sum_value => {
            for (ids.items, 0..) |item, i| {
                if (item == ast.pos().?) {
                    _ = ids.swapRemove(i);
                    break;
                }
            }
        },
        .pattern_symbol => ids.clearRetainingCapacity(),
        else => {},
    }
}
