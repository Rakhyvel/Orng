//! This file contains the semantic validation logic for types.
const std = @import("std");
const errs_ = @import("../util/errors.zig");
const Type_AST = @import("type.zig").Type_AST;

const Validate_Error_Enum = error{CompileError};

pub fn validate(@"type": *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    switch (@"type".*) {
        .identifier => {
            if (!@"type".symbol().?.refers_to_type()) {
                errors.add_error(errs_.Error{ .basic = .{ .msg = "expected a type", .span = @"type".token().span } });
                return error.CompileError;
            }
        },

        .array_of => {
            if (@"type".array_of.len.* != .int) {
                errors.add_error(errs_.Error{ .basic = .{ .span = @"type".token().span, .msg = "not integer literal" } });
                return error.CompileError;
            }
            try validate(@"type".child(), errors);
        },

        .untagged_sum_type => {
            if (@"type".child().expand_identifier().* != .enum_type) { // TODO: What if the identifier is cyclic?
                errors.add_error(errs_.Error{ .basic = .{ .span = @"type".token().span, .msg = "not an enum type" } });
                return error.CompileError;
            }
            try validate(@"type".child(), errors);
        },

        .dyn_type => {
            if (@"type".child().* != .identifier or @"type".child().symbol().?.kind != .trait) {
                errors.add_error(errs_.Error{ .basic = .{ .span = @"type".child().token().span, .msg = "not a trait" } });
                return error.CompileError;
            }
        },

        .annotation,
        .addr_of,
        .index,
        .domain_of,
        => {
            try validate(@"type".child(), errors);
        },

        .function => {
            try validate(@"type".lhs(), errors);
            try validate(@"type".rhs(), errors);
        },

        .enum_type,
        .struct_type,
        .tuple_type,
        => {
            for (@"type".children().items) |child| {
                try validate(child, errors);
            }
        },

        else => {},
    }
}

pub fn detect_cycle(ty: *Type_AST, allocator: std.mem.Allocator) bool {
    var visiting = std.AutoHashMap(*Type_AST, bool).init(allocator);
    defer visiting.deinit();

    var visited = std.AutoHashMap(*Type_AST, bool).init(allocator);
    defer visited.deinit();

    return dfs(ty, &visiting, &visited, false);
}

fn dfs(
    ty: *Type_AST,
    visiting: *std.AutoHashMap(*Type_AST, bool),
    visited: *std.AutoHashMap(*Type_AST, bool),
    seen_indirection: bool,
) bool {
    if (visited.contains(ty)) return false;

    if (visiting.contains(ty)) {
        // cycle detected
        return !seen_indirection; // invalid if no indirection seen
    }

    visiting.put(ty, true) catch unreachable;

    const next_seen = seen_indirection or ty.is_indirect();

    switch (ty.*) {
        else => {},

        .identifier, .access => if (ty.symbol().?.init_typedef() != null and dfs(ty.symbol().?.init_typedef().?, visiting, visited, next_seen)) return true,

        .array_of,
        .untagged_sum_type,
        .annotation,
        .addr_of,
        .index,
        .domain_of,
        => {
            if (dfs(ty.child(), visiting, visited, next_seen)) return true;
        },

        .function => {
            if (dfs(ty.lhs(), visiting, visited, next_seen)) return true;
            if (dfs(ty.rhs(), visiting, visited, next_seen)) return true;
        },

        .enum_type,
        .struct_type,
        .tuple_type,
        => {
            for (ty.children().items) |child| {
                if (dfs(child, visiting, visited, next_seen)) {
                    return true; // invalid cycle found
                }
            }
        },
    }

    _ = visiting.remove(ty);
    visited.put(ty, true) catch unreachable;

    return false;
}
