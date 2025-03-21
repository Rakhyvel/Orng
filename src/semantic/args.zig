//! This file contains various semantic checks relating to arguments and fields, including default arguments/fields, and
//! named arguments/fields.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const Span = @import("../util/span.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

pub const Validate_Args_Thing = enum {
    function,
    method,
    product,

    fn name(self: @This()) []const u8 {
        return @tagName(self);
    }

    fn takes_name(self: @This()) []const u8 {
        return switch (self) {
            .function, .method => "parameter",
            .product => "field",
        };
    }

    fn given_name(self: @This()) []const u8 {
        return switch (self) {
            .function, .method => "argument",
            .product => "value",
        };
    }
};

// This has to be ok to do twice for the same args, because stamps have to do it internally.
pub fn default_args(
    asts: std.ArrayList(*ast_.AST), // The args for a call, or the terms for a product
    expected: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!std.ArrayList(*ast_.AST) {
    if (try args_are_named(asts, errors) and expected.* != .unit_type) {
        return named_args(asts, expected, errors, allocator) catch |err| switch (err) {
            error.NoDefault => asts,
            error.CompileError, error.ParseError, error.LexerError => error.CompileError,
        };
    } else {
        return positional_args(asts, expected, allocator) catch |err| switch (err) {
            error.NoDefault => asts,
        };
    }
}

/// Determines if there are named arguments in an argument list. If there are no arguments, there are
/// no named arguments.
///
/// Throws `error.CompileError` if there is a mix of positional and named arguments.
fn args_are_named(
    asts: std.ArrayList(*ast_.AST),
    errors: *errs_.Errors,
) Validate_Error_Enum!bool {
    if (asts.items.len == 0) {
        return false;
    }

    var has_named_arg = false;
    var has_pos_arg = false;
    for (asts.items) |term| {
        if (term.* == .assign) {
            has_named_arg = true;
        } else {
            has_pos_arg = true;
        }
    }
    std.debug.assert(has_named_arg or has_pos_arg);
    if (has_named_arg and has_pos_arg) {
        const arg_span = asts.items[0].token().span;
        errors.add_error(errs_.Error{ .basic = .{ .span = arg_span, .msg = "mixed positional and named arguments are not allowed" } });
        return error.CompileError;
    } else {
        return has_named_arg;
    }
}

/// Accepts a list of AST arguments, the expected parameter type, and if the ASTs list isn't long enough for the parameters, prepends the
/// default values for each missing argument.
///
/// Returns NoDefault when a default value cannot be created
fn positional_args(
    asts: std.ArrayList(*ast_.AST),
    expected: *ast_.AST,
    allocator: std.mem.Allocator,
) error{NoDefault}!std.ArrayList(*ast_.AST) {
    // TODO: Too long
    var filled_args = std.ArrayList(*ast_.AST).init(allocator);
    errdefer filled_args.deinit();

    switch (expected.*) {
        .annotation => {
            if (asts.items.len == 0 and expected.annotation.init != null) {
                // Use expected's init, asts are empty
                filled_args.append(expected.annotation.init.?) catch unreachable;
            } else if (asts.items.len > 0) {
                // Copy asts over to filled_args
                for (asts.items) |item| {
                    filled_args.append(item) catch unreachable;
                }
            } else {
                // empty args, no default init in parameter. No default possible!
                return error.NoDefault;
            }
        },

        .product => {
            for (expected.children().items, 0..) |term, i| {
                // ast is product, append ast's corresponding term
                if (asts.items.len > 1 and i < asts.items.len) {
                    filled_args.append(asts.items[i]) catch unreachable;
                }
                // ast is unit or ast isn't a product and i > 0 or ast is a product and off the edge of ast's terms
                // try to fill with the default
                else if (asts.items.len == 0 or (asts.items.len <= 1 and i > 0) or (asts.items.len > 1 and i >= asts.items.len)) {
                    if (term.* == .annotation and term.annotation.init != null) {
                        filled_args.append(term.annotation.init.?) catch unreachable;
                    } else {
                        return error.NoDefault;
                    }
                }
                // ast is not product, i != 0, append ast as first term
                else {
                    filled_args.append(asts.items[0]) catch unreachable;
                }
            }
        },

        else => filled_args = asts,

        // else => std.debug.panic("compiler error: positional_args(): unimplemented for {s}", .{@tagName(expected.*)}),
    }
    if (filled_args.items.len < asts.items.len) {
        // Add the rest, for extern variadic function calls
        for (filled_args.items.len..asts.items.len) |i| {
            filled_args.append(asts.items[i]) catch unreachable;
        }
    }
    return filled_args;
}

fn named_args(
    asts: std.ArrayList(*ast_.AST),
    expected: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) (Validate_Error_Enum || error{NoDefault})!std.ArrayList(*ast_.AST) {
    // FIXME: High cyclo
    std.debug.assert(asts.items.len > 0);
    // Maps assign.lhs name to assign.rhs
    var arg_name_to_val_map = std.StringArrayHashMap(*ast_.AST).init(allocator);
    defer arg_name_to_val_map.deinit();

    // Associate argument names with their values
    for (asts.items) |term| {
        put_assign(term, &arg_name_to_val_map, errors) catch |err| switch (err) {
            error.CompileError => return error.NoDefault,
            else => return err,
        };
    }

    // Construct positional args in the order specified by `expected`
    var filled_args = std.ArrayList(*ast_.AST).init(allocator);
    errdefer filled_args.deinit();
    switch (expected.*) {
        .annotation => {
            if (arg_name_to_val_map.keys().len > 1) { // Cannot be 0, since that is technically a positional arglist
                errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = asts.items[0].token().span,
                    .takes = 1,
                    .given = arg_name_to_val_map.keys().len,
                    .thing_name = "function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.NoDefault;
            } else {
                filled_args.append(arg_name_to_val_map.values()[0]) catch unreachable;
            }
        },

        .product => {
            for (expected.children().items) |term| {
                if (term.* != .annotation) {
                    errors.add_error(errs_.Error{ .basic = .{
                        .span = asts.items[0].token().span,
                        .msg = "expected type does not accept named arugments",
                    } });
                    return error.NoDefault;
                }
                const arg = arg_name_to_val_map.get(term.annotation.pattern.token().data);
                if (arg == null) {
                    if (term.annotation.init != null) {
                        filled_args.append(term.annotation.init.?) catch unreachable;
                    } else {
                        // Value is not provided, and there is no default init, ERROR!
                        errors.add_error(errs_.Error{ .mismatch_arity = .{
                            .span = asts.items[0].token().span,
                            .takes = expected.children().items.len,
                            .given = arg_name_to_val_map.keys().len,
                            .thing_name = "type",
                            .takes_name = "value",
                            .given_name = "value",
                        } });
                        return error.NoDefault;
                    }
                } else {
                    filled_args.append(arg.?) catch unreachable;
                }
            }
        },

        else => std.debug.panic("compiler error: unimplemented named_args() for `{}`", .{expected.*}),
    }
    return filled_args;
}

fn put_assign(ast: *ast_.AST, arg_map: *std.StringArrayHashMap(*ast_.AST), errors: *errs_.Errors) Validate_Error_Enum!void {
    if (ast.lhs().* != .sum_value) {
        errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "an inferred member", .got = ast.lhs().token() } });
        return error.CompileError;
    }
    try put_ast_map(ast.rhs(), ast.lhs().sum_value.get_name(), ast.token().span, arg_map, errors);
}

/// Puts an ast into a String->AST map, if a given name isn't already in the map.
pub fn put_ast_map(
    ast: *ast_.AST,
    name: []const u8,
    span: Span,
    map: *std.StringArrayHashMap(*ast_.AST),
    errors: *errs_.Errors,
) Validate_Error_Enum!void {
    if (map.get(name)) |_| {
        errors.add_error(errs_.Error{ .duplicate = .{
            .span = span,
            .identifier = name,
            .first = null,
        } });
    } else {
        map.put(name, ast) catch unreachable;
    }
}

/// Validates that the number of arguments matches the number of parameters
pub fn validate_args_arity(
    thing: Validate_Args_Thing,
    args: *std.ArrayList(*ast_.AST),
    expected: *ast_.AST,
    variadic: bool,
    span: Span,
    errors: *errs_.Errors,
) Validate_Error_Enum!void {
    const expected_length = if (expected.* == .unit_type) 0 else if (expected.* == .product) expected.children().items.len else 1;
    if (variadic) {
        if (args.items.len < expected_length) {
            errors.add_error(errs_.Error{ .mismatch_arity = .{
                .span = span,
                .takes = expected_length,
                .given = args.items.len,
                .thing_name = thing.name(),
                .takes_name = thing.takes_name(),
                .given_name = thing.given_name(),
            } });
            return error.CompileError;
        }
    } else if (args.items.len != expected_length) {
        errors.add_error(errs_.Error{ .mismatch_arity = .{
            .span = span,
            .takes = expected_length,
            .given = args.items.len,
            .thing_name = thing.name(),
            .takes_name = thing.takes_name(),
            .given_name = thing.given_name(),
        } });
        return error.CompileError;
    }
}
