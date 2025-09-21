//! This file contains various semantic checks relating to pattern-matching.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const Span = @import("../util/span.zig");
const poison_ = @import("../ast/poison.zig");
const typecheck_AST = @import("typecheck.zig").typecheck_AST;
const typing_ = @import("typing.zig");
const Type_AST = @import("../types/type.zig").Type_AST;

const Validate_Error_Enum = error{CompileError};

const Self: type = @This();

ctx: *Compiler_Context,
map: std.AutoArrayHashMap(*ast_.AST, *Type_AST),

pub fn init(ctx: *Compiler_Context) Self {
    return Self{
        .ctx = ctx,
        .map = std.AutoArrayHashMap(*ast_.AST, *Type_AST).init(ctx.allocator()),
    };
}

/// Validates that `pattern` is valid given a match's `expr`
pub fn assert_pattern_matches(
    self: *Self,
    pattern: *ast_.AST,
    expr_type: *Type_AST,
) Validate_Error_Enum!void {
    switch (pattern.*) {
        .unit_value => try typing_.type_check(pattern.token().span, prelude_.unit_type, expr_type, &self.ctx.errors),
        .int => _ = try typing_.type_check_int(pattern, expr_type, &self.ctx.errors),
        .char => try typing_.type_check(pattern.token().span, prelude_.char_type, expr_type, &self.ctx.errors),
        .string => try typing_.type_check(pattern.token().span, prelude_.string_type, expr_type, &self.ctx.errors), // TODO: Has to wait until we can match on slices
        .float => _ = try typing_.type_check_float(pattern, expr_type, &self.ctx.errors),
        .true, .false => try typing_.type_check(pattern.token().span, prelude_.bool_type, expr_type, &self.ctx.errors),
        .block => {
            const pattern_type = try self.ctx.typecheck.typecheck_AST(pattern, expr_type);
            try poison_.assert_none_poisoned(pattern);
            try typing_.type_check(pattern.token().span, pattern_type, expr_type, &self.ctx.errors);
        },
        .select, .enum_value => {
            const pattern_type = try self.ctx.typecheck.typecheck_AST(pattern, expr_type);
            try poison_.assert_none_poisoned(pattern);
            pattern.set_pos(pattern.pos().?);
            try typing_.type_check(pattern.token().span, pattern_type, expr_type, &self.ctx.errors);
        },
        .tuple_value => {
            const pattern_type = try self.ctx.typecheck.typecheck_AST(pattern, expr_type);
            const expanded_expr_type = expr_type.expand_identifier();
            if (expanded_expr_type.* != .tuple_type or expanded_expr_type.children().items.len != pattern.children().items.len) {
                return typing_.throw_unexpected_type(pattern.token().span, expr_type, pattern_type, &self.ctx.errors);
            }
            for (pattern.children().items, expanded_expr_type.children().items) |term, expanded_term| {
                try self.assert_pattern_matches(term, expanded_term);
            }
        },
        .array_value => {
            const pattern_type = try self.ctx.typecheck.typecheck_AST(pattern, expr_type);
            const expanded_expr_type = expr_type.expand_identifier();
            if (expanded_expr_type.* != .array_of or expanded_expr_type.array_of.len.int.data != pattern.children().items.len) {
                return typing_.throw_unexpected_type(pattern.token().span, expr_type, pattern_type, &self.ctx.errors);
            }
            for (pattern.children().items) |term| {
                try self.assert_pattern_matches(term, expanded_expr_type.child());
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
    self: *Self,
    _type: *Type_AST,
    mappings: *std.ArrayList(*ast_.AST),
    match_span: Span,
) Validate_Error_Enum!void {
    if (_type.* == .enum_type) {
        var total_sum_ids = std.ArrayList(usize).init(self.ctx.allocator());
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
            var forgotten_sum_variants = std.ArrayList(*Type_AST).init(self.ctx.allocator()); // Not deallocated, lives until error emission
            for (total_sum_ids.items) |id| {
                forgotten_sum_variants.append(_type.children().items[id]) catch unreachable;
            }
            self.ctx.errors.add_error(errs_.Error{ .non_exhaustive_sum = .{ .span = match_span, .forgotten = forgotten_sum_variants } });
            return error.CompileError;
        }
    }
}

fn exhaustive_check_sub(ast: *ast_.AST, ids: *std.ArrayList(usize)) void {
    switch (ast.*) {
        .select, .enum_value => {
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
