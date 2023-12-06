const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const module_ = @import("module.zig");
const primitives = @import("primitives.zig");
const std = @import("std");
const symbols = @import("symbol.zig");

const AST = _ast.AST;
const Context = @import("interpreter.zig").Context;
const Error = errs.Error;
const Module = module_.Module;
const Scope = symbols.Scope;
const Span = @import("span.zig").Span;
const String = @import("zig-string/zig-string.zig").String;
const Symbol = symbols.Symbol;
const Token = @import("token.zig").Token;

pub fn validate_module(module: *Module, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    try validate_scope(module.scope, errors, allocator);
}

fn validate_scope(scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    for (scope.symbols.keys()) |key| {
        const symbol = scope.symbols.get(key).?;
        try validateSymbol(symbol, errors, allocator);
    }
    for (scope.children.items) |child| {
        try validate_scope(child, errors, allocator);
    }
}

pub fn validateSymbol(symbol: *Symbol, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, Unimplemented, OutOfMemory, InvalidRange, NotAnLValue }!void {
    if (symbol.validation_state == .valid or symbol.validation_state == .validating) {
        return;
    }
    symbol.validation_state = .validating;

    if (symbol.kind == ._fn or symbol.kind == ._comptime) {
        symbol._type = try validateAST(symbol._type, primitives.type_type, symbol.scope, errors, allocator);
        symbol.validation_state = .valid;
        if (symbol._type.* != .poison) {
            symbol.expanded_type = try symbol._type.expand_type(symbol.scope, errors, allocator);
            symbol.init = try validateAST(symbol.init, symbol._type.function.rhs, symbol.scope, errors, allocator);
            if (symbol._type.function.rhs.* == .inferred_error) {
                const terms = symbol._type.function.rhs.inferred_error.terms;
                symbol._type.function.rhs.* = AST{ .sum = .{ .common = symbol._type.function.rhs.getCommon().*, .terms = terms, .was_error = true } };
            }
        } else {
            symbol.init = _ast.poisoned;
        }
    } else {
        symbol._type = try validateAST(symbol._type, primitives.type_type, symbol.scope, errors, allocator);
        symbol.validation_state = .valid;
        if (symbol._type.* != .poison) {
            symbol.expanded_type = try symbol._type.expand_type(symbol.scope, errors, allocator);
            symbol.init = try validateAST(symbol.init, symbol._type, symbol.scope, errors, allocator);
        } else {
            symbol.init = _ast.poisoned;
        }
    }

    // Symbol's name must be capitalizes iff it type is Type
    if (symbol.expanded_type != null and !std.mem.eql(u8, symbol.name, "_")) {
        if (symbol.expanded_type.?.* == .identifier and std.mem.eql(u8, symbol.expanded_type.?.getToken().data, "Type")) {
            if (!std.ascii.isUpper(symbol.name[0])) {
                errors.addError(Error{ .symbol_error = .{
                    .span = symbol.span,
                    .context_span = null,
                    .name = symbol.name,
                    .problem = "of type `Type` must start with an uppercase letter",
                    .context_message = "",
                } });
            }
        } else {
            if (std.ascii.isUpper(symbol.name[0])) {
                errors.addError(Error{ .symbol_error = .{
                    .span = symbol.span,
                    .context_span = null,
                    .name = symbol.name,
                    .problem = "of type other than `Type` must start with a lowercase letter",
                    .context_message = "",
                } });
            }
        }
    }
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
fn validateAST(
    old_ast: *AST,
    old_expected: ?*AST,
    scope: *Scope,
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) error{ typeError, Unimplemented, OutOfMemory, InvalidRange, NotAnLValue }!*AST {
    var expected = old_expected;
    var ast = old_ast;

    if (ast.getCommon().validation_state == .validating) {
        errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "recursive definition detected" } });
        return _ast.poisoned;
    } else if (ast.getCommon().validation_state == .invalid) {
        return _ast.poisoned;
    } else if (ast.getCommon().validation_state == .valid) {
        return ast.getCommon().validation_state.valid.valid_form;
    }
    ast.getCommon().validation_state = .validating;

    if (expected) |_| {
        // expected must be a valid Type type
        std.debug.assert(expected.?.* != .poison);
        std.debug.assert(expected.?.getCommon().validation_state == .valid);
        var expected_type = try expected.?.typeof(scope, errors, allocator);
        std.debug.assert(try expected_type.typesMatch(primitives.type_type, scope, errors, allocator));

        if (expected.?.* == .annotation) {
            expected = expected.?.annotation.type;
        }
    }

    var retval = try validate_AST_internal(ast, expected, scope, errors, allocator);

    // Might as well memoize expanded_type
    if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
        _ = try retval.expand_type(scope, errors, allocator);
    }

    ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = retval } };
    retval.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = retval } };
    return retval;
}

fn validate_AST_internal(
    ast: *AST,
    expected: ?*AST,
    scope: *Scope,
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) error{ OutOfMemory, InvalidRange, typeError, Unimplemented, NotAnLValue }!*AST {
    // std.debug.print("{}\n", .{ast});
    switch (ast.*) {
        .poison => return ast,
        .unit_type => {
            if (expected != null and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.type_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .unit_value => {
            if (expected != null and !try primitives.unit_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.unit_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },

        .int => {
            // Check if data fits in expected type bounds
            // typeOf should be untyped int, matches any int type
            // TODO: Add emit a separate error if not representable because the value doesn't fit!
            if (expected != null and !try expected.?.can_represent_integer(ast.int.data, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.int_type } });
                return ast.enpoison();
            } else {
                ast.int.represents = expected orelse primitives.int_type;
                return ast;
            }
        },

        .char => {
            if (expected != null and !try primitives.char_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.char_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },

        .string => {
            if (expected != null and !try primitives.string_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.string_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },

        .float => {
            if (expected != null and !try expected.?.can_represent_float(scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.float_type } });
                return ast.enpoison();
            } else {
                ast.float.represents = expected orelse primitives.float_type;
                return ast;
            }
        },

        .identifier => {
            // look up symbol, that's the type
            var symbol = findSymbol(ast, expected, scope, errors) catch |err| switch (err) {
                error.typeError => return ast.enpoison(),
                else => return err,
            };
            try validateSymbol(symbol, errors, allocator);
            if (symbol.validation_state != .valid or symbol._type.getCommon().validation_state != .valid) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "recursive definition detected" } });
                return ast.enpoison();
            }
            if (expected != null and !try symbol._type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = symbol._type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },

        ._true => {
            if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },

        ._false => {
            if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },

        .not => {
            ast.not.expr = try validateAST(ast.not.expr, primitives.bool_type, scope, errors, allocator);
            if (ast.not.expr.* == .poison) {
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.float_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .negate => {
            ast.negate.expr = try validateAST(ast.negate.expr, null, scope, errors, allocator);
            var expr_type = try ast.negate.expr.typeof(scope, errors, allocator);

            if (ast.negate.expr.* == .poison) {
                return ast.enpoison();
            } else if (!try expr_type.is_num_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "arithmetic", .got = expr_type } });
                return ast.enpoison();
            } else if (expected != null and !try expr_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = expr_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .dereference => {
            if (expected != null) {
                var addr_of = try _ast.AST.createAddrOf(ast.getToken(), expected.?, false, std.heap.page_allocator);
                addr_of.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = addr_of } };
                ast.dereference.expr = try validateAST(ast.dereference.expr, addr_of, scope, errors, allocator);
            } else {
                ast.dereference.expr = try validateAST(ast.dereference.expr, null, scope, errors, allocator);
            }
            if (ast.dereference.expr.* == .poison) {
                return ast.enpoison();
            }
            var expr_type = try ast.dereference.expr.typeof(scope, errors, allocator);
            const expanded_expr_type = try expr_type.expand_type(scope, errors, allocator);
            if (expanded_expr_type.* != .addrOf) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected an address" } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        ._try => {
            const expr_span = ast._try.expr.getToken().span;
            ast._try.expr = try validateAST(ast._try.expr, null, scope, errors, allocator);
            if (ast._try.expr.* == .poison) {
                return ast.enpoison();
            }
            var expr_expanded_type = try (try ast._try.expr.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            if (expr_expanded_type.* != .sum or !expr_expanded_type.sum.was_error) {
                // expr is not even an error type
                errors.addError(Error{ .basic = .{ .span = expr_span, .msg = "not an error expression" } });
                return ast.enpoison();
            } else if (expected != null and expected.?.* != .inferred_error and !try expr_expanded_type.get_ok_type().annotation.type.typesMatch(expected.?, scope, errors, allocator)) {
                // expr is error union, but .err field types don't match with expected
                errors.addError(Error{ .expected2Type = .{ .span = expr_span, .expected = expected.?, .got = expr_expanded_type.get_ok_type().annotation.type } });
                return ast.enpoison();
            } else if (scope.inner_function == null) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "try operator is not within a function" } });
                return ast.enpoison();
            } else {
                var expanded_function_return = try scope.inner_function.?._type.function.rhs.expand_type(scope, errors, allocator);
                if (expanded_function_return.* == .inferred_error) {
                    // This checks that the `ok` fields match, for free!
                    for (expr_expanded_type.sum.terms.items) |term| {
                        try expanded_function_return.inferred_error.add_term(term, scope, errors, allocator);
                    }
                } else if (expanded_function_return.* != .sum or !expanded_function_return.sum.was_error) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "enclosing function around try expression does not return an error" } });
                    return ast.enpoison();
                } else if (!try expr_expanded_type.sum.terms.items[1].annotation.type.typesMatch(expanded_function_return.sum.terms.items[1].annotation.type, scope, errors, allocator)) {
                    // MASSIVE TODO: Check ALL sum terms, not just the first one
                    // expr error union's `.err` member is not a compatible type with the function's error type
                    errors.addError(Error{ .expected2Type = .{
                        .span = expr_span,
                        .expected = expr_expanded_type,
                        .got = expanded_function_return,
                    } });
                    return ast.enpoison();
                }
            }
            return ast;
        },
        .discard => {
            ast.discard.expr = try validateAST(ast.discard.expr, null, scope, errors, allocator);
            if (ast.discard.expr.* == .poison) {
                return ast.enpoison();
            }
            if (expected != null and !try primitives.unit_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            return ast;
        },
        .domainOf => {
            ast.domainOf.sum_expr = try validateAST(ast.domainOf.sum_expr, primitives.type_type, scope, errors, allocator);
            if (ast.domainOf.sum_expr.* == .poison) {
                return ast.enpoison();
            }
            return try domainof(ast.domainOf.expr, ast.domainOf.sum_expr, scope, errors, allocator);
        },
        ._typeOf => {
            ast._typeOf.expr = try validateAST(ast._typeOf.expr, null, scope, errors, allocator);
            if (expected != null and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.type_type } });
                return ast.enpoison();
            }
            return try ast._typeOf.expr.typeof(scope, errors, allocator);
        },
        .default => {
            ast.default.expr = try validateAST(ast.default.expr, null, scope, errors, allocator);
            if (expected != null and !try ast.default.expr.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast.default.expr } });
                return ast.enpoison();
            }
            return try ast.default.expr.generate_default(scope, errors, allocator);
        },
        ._comptime => {
            // Validate symbol
            try validateSymbol(ast._comptime.symbol.?, errors, allocator); // ast._comptime.symbol.? is created during symbol tree expansion
            if (ast._comptime.symbol.?._type.* == .poison) {
                return ast.enpoison();
            }

            // Get the cfg from the symbol, and embed into the module
            const cfg = try ast._comptime.symbol.?.get_cfg(null, &scope.module.?.interned_strings, errors, allocator);
            defer cfg.deinit(); // Remove the cfg so that it isn't output

            const idx = try scope.module.?.append_instructions(cfg);
            defer scope.module.?.pop_cfg(idx); // Remove the cfg so that it isn't output

            // Create a context and interpret
            var context = try Context.init(cfg, &scope.module.?.instructions, ast._comptime.symbol.?._type.function.rhs.get_slots(), cfg.offset.?);
            var ir_data = try context.interpret();

            // Extract the retval
            return try ir_data.to_ast(ast.getToken(), allocator);
        },
        .assign => {
            ast.assign.lhs = try validateAST(ast.assign.lhs, null, scope, errors, allocator);
            validateLValue(ast.assign.lhs, scope, errors) catch |err| switch (err) {
                error.typeError => return ast.enpoison(),
                else => return err,
            };
            const lhs_type = try ast.assign.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.assign.rhs = try validateAST(ast.assign.rhs, lhs_type, scope, errors, allocator);
            if (ast.assign.lhs.* == .poison or ast.assign.rhs.* == .poison) {
                return ast.enpoison();
            }
            if (expected != null and !try primitives.unit_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            assertMutable(ast.assign.lhs, scope, errors, allocator) catch |err| switch (err) {
                error.typeError => return ast.enpoison(),
                else => return err,
            };
            return ast;
        },
        ._or => {
            ast._or.lhs = try validateAST(ast._or.lhs, primitives.bool_type, scope, errors, allocator);
            ast._or.rhs = try validateAST(ast._or.rhs, primitives.bool_type, scope, errors, allocator);
            if (ast._or.lhs.* == .poison or ast._or.rhs.* == .poison) {
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        ._and => {
            ast._and.lhs = try validateAST(ast._and.lhs, primitives.bool_type, scope, errors, allocator);
            ast._and.rhs = try validateAST(ast._and.rhs, primitives.bool_type, scope, errors, allocator);
            if (ast._and.lhs.* == .poison or ast._and.rhs.* == .poison) {
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .add => {
            ast.add.lhs = try validateAST(ast.add.lhs, expected, scope, errors, allocator);
            var lhs_type = try ast.add.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.add.rhs = try validateAST(ast.add.rhs, lhs_type, scope, errors, allocator);

            if (ast.add.lhs.* == .poison or ast.add.rhs.* == .poison) {
                return ast.enpoison();
            } else if (!try lhs_type.is_num_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "arithmetic", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .sub => {
            ast.sub.lhs = try validateAST(ast.sub.lhs, expected, scope, errors, allocator);
            var lhs_type = try ast.sub.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.sub.rhs = try validateAST(ast.sub.rhs, lhs_type, scope, errors, allocator);

            if (ast.sub.lhs.* == .poison or ast.sub.rhs.* == .poison) {
                return ast.enpoison();
            } else if (!try lhs_type.is_num_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "arithmetic", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .mult => {
            ast.mult.lhs = try validateAST(ast.mult.lhs, expected, scope, errors, allocator);
            var lhs_type = try ast.mult.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.mult.rhs = try validateAST(ast.mult.rhs, lhs_type, scope, errors, allocator);

            if (ast.mult.lhs.* == .poison or ast.mult.rhs.* == .poison) {
                return ast.enpoison();
            } else if (!try lhs_type.is_num_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "arithmetic", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .div => {
            ast.div.lhs = try validateAST(ast.div.lhs, expected, scope, errors, allocator);
            var lhs_type = try ast.div.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.div.rhs = try validateAST(ast.div.rhs, lhs_type, scope, errors, allocator);

            if (ast.div.lhs.* == .poison or ast.div.rhs.* == .poison) {
                return ast.enpoison();
            } else if (!try lhs_type.is_num_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "arithmetic", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .mod => {
            ast.mod.lhs = try validateAST(ast.mod.lhs, primitives.int_type, scope, errors, allocator);
            const lhs_type = try ast.mod.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.mod.rhs = try validateAST(ast.mod.rhs, primitives.int_type, scope, errors, allocator);

            if (ast.mod.lhs.* == .poison or ast.mod.rhs.* == .poison) {
                return ast.enpoison();
            } else if (expected != null and !try primitives.int_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .equal => {
            ast.equal.lhs = try validateAST(ast.equal.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.equal.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.equal.rhs = try validateAST(ast.equal.rhs, lhs_type, scope, errors, allocator);
            if (ast.equal.lhs.* == .poison or ast.equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_eq_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.equal.lhs.getToken().span, .expected = "equalable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            return ast;
        },
        .not_equal => {
            ast.not_equal.lhs = try validateAST(ast.not_equal.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.not_equal.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.not_equal.rhs = try validateAST(ast.not_equal.rhs, lhs_type, scope, errors, allocator);
            if (ast.not_equal.lhs.* == .poison or ast.not_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_eq_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.not_equal.lhs.getToken().span, .expected = "equalable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            return ast;
        },
        .greater => {
            ast.greater.lhs = try validateAST(ast.greater.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.greater.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.greater.rhs = try validateAST(ast.greater.rhs, lhs_type, scope, errors, allocator);
            if (ast.greater.lhs.* == .poison or ast.greater.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_ord_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.greater.lhs.getToken().span, .expected = "ordered", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            return ast;
        },
        .lesser => {
            ast.lesser.lhs = try validateAST(ast.lesser.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.lesser.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.lesser.rhs = try validateAST(ast.lesser.rhs, lhs_type, scope, errors, allocator);
            if (ast.lesser.lhs.* == .poison or ast.lesser.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_ord_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.lesser.lhs.getToken().span, .expected = "ordered", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            return ast;
        },
        .greater_equal => {
            ast.greater_equal.lhs = try validateAST(ast.greater_equal.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.greater_equal.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.greater_equal.rhs = try validateAST(ast.greater_equal.rhs, lhs_type, scope, errors, allocator);
            if (ast.greater_equal.lhs.* == .poison or ast.greater_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_ord_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.greater_equal.lhs.getToken().span, .expected = "ordered", .got = lhs_type } });
                return ast.enpoison();
            } else if (!try lhs_type.is_eq_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.greater_equal.lhs.getToken().span, .expected = "equalable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            return ast;
        },
        .lesser_equal => {
            ast.lesser_equal.lhs = try validateAST(ast.lesser_equal.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.lesser_equal.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.lesser_equal.rhs = try validateAST(ast.lesser_equal.rhs, lhs_type, scope, errors, allocator);
            if (ast.lesser_equal.lhs.* == .poison or ast.lesser_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_ord_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.lesser_equal.lhs.getToken().span, .expected = "ordered", .got = lhs_type } });
                return ast.enpoison();
            } else if (!try lhs_type.is_eq_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.lesser_equal.lhs.getToken().span, .expected = "equalable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            return ast;
        },
        ._catch => {
            ast._catch.lhs = try validateAST(ast._catch.lhs, null, scope, errors, allocator);
            ast._catch.rhs = try validateAST(ast._catch.rhs, expected, scope, errors, allocator);
            var lhs_expanded_type = try (try ast._catch.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_error) {
                errors.addError(Error{ .basic = .{ .span = ast._catch.lhs.getToken().span, .msg = "left-hand side of catch is not an error type" } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_expanded_type.get_ok_type().annotation.type.typesMatch(expected.?, scope, errors, allocator)) {
                // MASSIVE TODO: Print the correct expected and got type, to match orelse for this error.
                // Tough because we don't have the lhs error information... or maybe not?
                errors.addError(Error{ .expected2Type = .{ .span = ast._catch.lhs.getToken().span, .expected = expected.?, .got = lhs_expanded_type.sum.terms.items[1].annotation.type } });
                return ast.enpoison();
            } else {
                ast._catch.lhs = try validateAST(ast._catch.lhs, null, scope, errors, allocator);
            }
            if (ast._catch.lhs.* == .poison or ast._catch.rhs.* == .poison) {
                return ast.enpoison();
            }
            return ast;
        },
        ._orelse => {
            ast._orelse.lhs = try validateAST(ast._orelse.lhs, null, scope, errors, allocator);
            ast._orelse.rhs = try validateAST(ast._orelse.rhs, expected, scope, errors, allocator);
            var lhs_expanded_type = try (try ast._orelse.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_optional) {
                errors.addError(Error{ .basic = .{ .span = ast._orelse.lhs.getToken().span, .msg = "left-hand side of orelse is not an optional type" } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_expanded_type.get_some_type().annotation.type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast._orelse.lhs.getToken().span, .expected = expected.?, .got = lhs_expanded_type.get_some_type().annotation.type } });
                return ast.enpoison();
            }
            if (ast._orelse.lhs.* == .poison or ast._orelse.rhs.* == .poison) {
                return ast.enpoison();
            }
            return ast;
        },
        .call => { // TODO: TOO LONG!
            ast.call.lhs = try validateAST(ast.call.lhs, null, scope, errors, allocator);
            if (ast.call.lhs.* == .poison) {
                return ast.enpoison();
            }
            var lhs_type = try ast.call.lhs.typeof(scope, errors, allocator);
            const expanded_lhs_type = try lhs_type.expand_identifier(scope, errors, allocator);
            if (expanded_lhs_type.* != .function) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "call is not to a function" } });
                return ast.enpoison();
            }

            // Apply default arguments
            ast.call.args = default_args(ast.call.args, expanded_lhs_type.function.lhs, scope, errors, allocator) catch |err| switch (err) {
                error.NoDefault => ast.call.args,
                error.typeError => return ast.enpoison(),
                error.OutOfMemory => return error.OutOfMemory,
                error.Unimplemented => return error.Unimplemented,
                error.InvalidRange => return error.InvalidRange,
                error.NotAnLValue => return error.NotAnLValue,
            };

            // Validate
            var new_args = std.ArrayList(*AST).init(allocator);
            var changed = false;
            var poisoned = false;
            if (expanded_lhs_type.function.lhs.* == .unit_type) {
                if (ast.call.args.items.len > 0) {
                    errors.addError(Error{ .mismatchCallArity = .{
                        .span = ast.getToken().span,
                        .takes = 0,
                        .given = ast.call.args.items.len,
                    } });
                    return ast.enpoison();
                }
            } else if (expanded_lhs_type.function.lhs.* == .product) {
                if (ast.call.args.items.len != expanded_lhs_type.function.lhs.product.terms.items.len) {
                    errors.addError(Error{ .mismatchCallArity = .{
                        .span = ast.getToken().span,
                        .takes = expanded_lhs_type.function.lhs.product.terms.items.len,
                        .given = ast.call.args.items.len,
                    } });
                    return ast.enpoison();
                }
                for (expanded_lhs_type.function.lhs.product.terms.items, ast.call.args.items) |param_type, arg| {
                    const new_arg = try validateAST(arg, param_type, scope, errors, allocator);
                    changed = changed or new_arg != arg;
                    try new_args.append(new_arg);
                    if (new_arg.* == .poison) {
                        poisoned = true;
                    }
                }
            } else {
                if (ast.call.args.items.len != 1) {
                    errors.addError(Error{ .mismatchCallArity = .{
                        .span = ast.getToken().span,
                        .takes = 1,
                        .given = ast.call.args.items.len,
                    } });
                    return ast.enpoison();
                }

                ast.call.args.items[0] = try validateAST(ast.call.args.items[0], expanded_lhs_type.function.lhs, scope, errors, allocator);
            }

            if (expected != null and !try expanded_lhs_type.function.rhs.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = expanded_lhs_type.function.rhs } });
                return ast.enpoison();
            } else if (poisoned) {
                return ast.enpoison();
            } else if (changed) {
                ast.call.args = new_args;
            } else {
                new_args.deinit();
            }
            return ast;
        },
        .index => { // TODO: TOO LONG!
            const lhs_span = ast.index.lhs.getToken().span; // Used for error reporting
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                ast.index.lhs = try validateAST(ast.index.lhs, primitives.type_type, scope, errors, allocator);
            } else {
                ast.index.lhs = try validateAST(ast.index.lhs, null, scope, errors, allocator);
            }
            ast.index.rhs = try validateAST(ast.index.rhs, primitives.int_type, scope, errors, allocator);
            if (ast.index.lhs.* == .poison or ast.index.rhs.* == .poison) {
                return ast.enpoison();
            }

            var lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .addrOf) {
                // Implicit dereference
                ast.index.lhs = try validateAST(try AST.createDereference(ast.getToken(), ast.index.lhs, allocator), null, scope, errors, allocator);
                lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);
                if (ast.index.lhs.* == .poison) {
                    return ast.enpoison();
                }
            } else if (lhs_type.* == .poison) {
                return ast.enpoison();
            }

            if (try lhs_type.typesMatch(primitives.type_type, scope, errors, allocator) and ast.index.lhs.* == .product and ast.index.rhs.* == .int and ast.index.lhs.product.terms.items.len > ast.index.rhs.int.data) {
                // Index a product type, resolve immediately
                // TODO: Perhaps add a pattern-index type that's only used by patterns, gauranteed to be infallible
                return ast.index.lhs.product.terms.items[@as(usize, @intCast(ast.index.rhs.int.data))];
            } else if (lhs_type.* != .product and !(lhs_type.* == .identifier and std.mem.eql(u8, lhs_type.getToken().data, "String"))) {
                errors.addError(Error{ .notIndexable = .{ .span = lhs_span, ._type = lhs_type } });
                return ast.enpoison();
            } else if (lhs_type.* == .product and !lhs_type.product.was_slice and !try lhs_type.product.is_homotypical(scope, errors, allocator)) {
                if (ast.index.rhs.* == .int) {
                    // rhs is compile-time known, change to select
                    var select = try AST.createSelect(ast.getToken(), ast.index.lhs, try AST.createIdentifier(Token.create("homotypical index", .IDENTIFIER, "", "", 0, 0), allocator), allocator);
                    select.select.pos = @as(usize, @intCast(ast.index.rhs.int.data));
                    select.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = select } };
                    return select;
                } else {
                    // rhs is not int, error
                    errors.addError(Error{ .basic = .{ .span = lhs_span, .msg = "array is not homotypical and index is not compile-time known" } });
                    return ast.enpoison();
                }
            } else if (expected != null) {
                if (lhs_type.* == .product and !lhs_type.product.was_slice and !try lhs_type.product.terms.items[0].typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.product.terms.items[0] } });
                    return ast.enpoison();
                } else if (lhs_type.* == .product and lhs_type.product.was_slice and !try lhs_type.product.terms.items[0].annotation.type.addrOf.expr.typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.product.terms.items[0].annotation.type.addrOf.expr } });
                    return ast.enpoison();
                } else {
                    return ast;
                }
            } else {
                return ast;
            }
        },
        .select => {
            ast.select.lhs = try validateAST(ast.select.lhs, null, scope, errors, allocator);
            if (ast.select.lhs.* == .poison) {
                return ast.enpoison();
            }

            var lhs_type = try ast.select.lhs.typeof(scope, errors, allocator);
            var select_lhs_type = try lhs_type.expand_type(scope, errors, allocator);

            // Implicit dereference
            if (select_lhs_type.* == .addrOf) {
                ast.select.lhs = try validateAST(try AST.createDereference(ast.getToken(), ast.select.lhs, allocator), null, scope, errors, allocator);
                select_lhs_type = try (try ast.select.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                if (ast.select.lhs.* == .poison) {
                    return ast.enpoison();
                }
            }

            if (try select_lhs_type.typesMatch(primitives.type_type, scope, errors, allocator) and (try ast.select.lhs.expand_type(scope, errors, allocator)).* == .sum) {
                const inferred_member = try AST.createInferredMember(ast.getToken(), ast.select.rhs, allocator);
                return try validateAST(inferred_member, ast.select.lhs, scope, errors, allocator);
            } else if (select_lhs_type.* != .product and select_lhs_type.* != .sum) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "left-hand-side of select is not selectable",
                } });
                return ast.enpoison();
            } else {
                ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                var ast_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !try ast_type.typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast_type } });
                    return ast.enpoison();
                } else {
                    return ast;
                }
            }
        },
        .function => {
            ast.function.lhs = try validateAST(ast.function.lhs, primitives.type_type, scope, errors, allocator);
            ast.function.rhs = try validateAST(ast.function.rhs, primitives.type_type, scope, errors, allocator);
            if (ast.function.lhs.* == .poison or ast.function.rhs.* == .poison) {
                return ast.enpoison();
            }
            if (expected != null and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.type_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .sum => { // TODO: TOO LONG!
            var poisoned = false;
            var changed = false;
            var new_terms = std.ArrayList(*AST).init(allocator);
            var idents_seen = std.StringArrayHashMap(*AST).init(allocator);
            defer idents_seen.deinit();
            for (ast.sum.terms.items) |term| {
                // Make sure identifiers aren't repeated
                if (term.* == .annotation) {
                    const new_term = try validateAST(term, primitives.type_type, scope, errors, allocator);
                    changed = changed or new_term != term;
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                    const name = term.annotation.pattern.getToken().data;
                    const res = try idents_seen.fetchPut(name, term);
                    if (res) |_res| {
                        errors.addError(Error{ .sum_duplicate = .{ .span = term.getToken().span, .identifier = name, .first = _res.value.getToken().span } });
                        return ast.enpoison();
                    }
                } else if (term.* == .identifier) {
                    var new_annotation = try AST.createAnnotation(term.getToken(), term, primitives.unit_type, null, null, allocator);
                    new_annotation.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = new_annotation } };
                    changed = true;
                    try new_terms.append(new_annotation);
                    const name = term.getToken().data;
                    const res = try idents_seen.fetchPut(name, term);
                    if (res) |_res| {
                        errors.addError(Error{ .sum_duplicate = .{ .span = term.getToken().span, .identifier = name, .first = _res.value.getToken().span } });
                        return ast.enpoison();
                    }
                } else {
                    errors.addError(Error{ .basic = .{ .span = term.getToken().span, .msg = "invalid sum expression, must be annotation or identifier" } });
                    return ast.enpoison();
                }
            }
            if (poisoned) {
                return ast.enpoison();
            } else if (changed) {
                ast.sum.terms = new_terms;
            } else {
                new_terms.deinit();
            }
            if (expected != null and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.type_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .inferred_error => {
            // Inferred errors are expanded after the node is validated. They should only have one term, the `ok` term
            std.debug.assert(ast.inferred_error.terms.items.len == 1);

            ast.inferred_error.terms.items[0] = try validateAST(ast.inferred_error.terms.items[0], primitives.type_type, scope, errors, allocator);
            if (ast.inferred_error.terms.items[0].* == .poison) {
                return ast.enpoison();
            }

            if (expected != null and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator) } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .inject => {
            if (expected != null and expected.?.* == .inferred_error) {
                ast.inject.lhs.inferredMember.init = try validateAST(ast.inject.rhs, null, scope, errors, allocator);
                ast.inject.lhs = try validateAST(ast.inject.lhs, expected, scope, errors, allocator);
                ast.inject.lhs.inferredMember.base = expected;
                if (ast.inject.lhs.inferredMember.init.?.* == .poison) {
                    return ast.enpoison();
                }
                ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                return ast.inject.lhs;
            } else {
                const domain = try domainof(ast, expected, scope, errors, allocator);
                if (domain.* == .poison) {
                    return domain;
                }
                ast.inject.lhs.inferredMember.init = try validateAST(ast.inject.rhs, domain, scope, errors, allocator);
                if (ast.inject.lhs.inferredMember.init.?.* == .poison) {
                    return ast.enpoison();
                }
                ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                return ast.inject.lhs;
            }
        },

        .product => { // TODO: TOO LONG!
            var poisoned = false;
            var changed = false;
            var new_terms = std.ArrayList(*AST).init(allocator);
            var expanded_expected: ?*AST = if (expected == null) null else try expected.?.expand_type(scope, errors, allocator);

            if (expanded_expected != null and expanded_expected.?.* == .product) {
                ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                ast.product.terms = default_args(ast.product.terms, expanded_expected.?, scope, errors, allocator) catch |err| switch (err) {
                    error.NoDefault => std.ArrayList(*AST).init(allocator),
                    error.typeError => return ast.enpoison(),
                    error.OutOfMemory => return error.OutOfMemory,
                    error.Unimplemented => return error.Unimplemented,
                    error.InvalidRange => return error.InvalidRange,
                    error.NotAnLValue => return error.NotAnLValue,
                };
            }

            if (expanded_expected != null and try expanded_expected.?.typesMatch(primitives.type_type, scope, errors, allocator)) {
                // Expecting ast to be a product type
                for (ast.product.terms.items) |term| {
                    const new_term = try validateAST(term, primitives.type_type, scope, errors, allocator);
                    changed = changed or new_term != term;
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
            } else if (expanded_expected != null and expanded_expected.?.* == .product) {
                // Expecting ast to be a product value
                if (expanded_expected.?.product.terms.items.len != ast.product.terms.items.len) {
                    errors.addError(Error{ .mismatchTupleArity = .{
                        .span = ast.getToken().span,
                        .takes = expanded_expected.?.product.terms.items.len,
                        .given = ast.product.terms.items.len,
                    } });
                    return ast.enpoison();
                }
                for (ast.product.terms.items, expanded_expected.?.product.terms.items) |term, expected_term| { // Ok, this is cool!
                    const new_term = try validateAST(term, expected_term, scope, errors, allocator);
                    changed = changed or new_term != term;
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
            } else if (expanded_expected == null) {
                // Not expecting anything
                for (ast.product.terms.items) |term| {
                    const new_term = try validateAST(term, null, scope, errors, allocator);
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
            } else {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.poisoned } });
                return ast.enpoison();
            }
            if (poisoned) {
                return ast.enpoison();
            } else if (changed) {
                ast.product.terms = new_terms;
            } else {
                new_terms.deinit();
            }
            return ast;
        },
        ._union => {
            // Save spans since lhs and rhs are expanded, need spans for errors
            const lhs_span = ast._union.lhs.getToken().span;
            const rhs_span = ast._union.rhs.getToken().span;

            ast._union.lhs = try validateAST(ast._union.lhs, primitives.type_type, scope, errors, allocator);
            ast._union.rhs = try validateAST(ast._union.rhs, primitives.type_type, scope, errors, allocator);
            if (ast._union.lhs.* == .poison or ast._union.rhs.* == .poison) {
                return ast.enpoison();
            }

            const expand_lhs = try ast._union.lhs.expand_type(scope, errors, allocator);
            const expand_rhs = try ast._union.rhs.expand_type(scope, errors, allocator);
            if (expand_lhs.* != .sum) {
                errors.addError(Error{ .basic = .{ .span = lhs_span, .msg = "left hand side of union is not a sum type" } });
                return ast.enpoison();
            } else if (expand_rhs.* != .sum) {
                errors.addError(Error{ .basic = .{ .span = rhs_span, .msg = "right hand side of union is not a sum type" } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator) } });
                return ast.enpoison();
            } else {
                var new_terms = std.ArrayList(*AST).init(allocator);
                var names = std.StringArrayHashMap(*AST).init(allocator);
                defer names.deinit();

                for (expand_lhs.sum.terms.items) |term| {
                    putAnnotation(term, &names, errors) catch |err| switch (err) {
                        error.typeError => unreachable, // I don't believe this is possible
                        else => return err,
                    };
                    try new_terms.append(term);
                }
                for (expand_rhs.sum.terms.items) |term| {
                    putAnnotation(term, &names, errors) catch |err| switch (err) {
                        error.typeError => return ast.enpoison(),
                        else => return err,
                    };
                    try new_terms.append(term);
                }

                var retval = try AST.createSum(ast.getToken(), new_terms, allocator);
                if (expand_lhs.sum.was_error) {
                    retval.sum.was_error = true;
                }
                return retval;
            }
        },
        .addrOf => { // TODO: TOO LONG!
            if (expected == null) {
                // Not expecting anything, just validate expr
                ast.addrOf.expr = try validateAST(ast.addrOf.expr, null, scope, errors, allocator);
                if (ast.addrOf.expr.* == .poison) {
                    return ast.enpoison();
                }
                validateLValue(ast.addrOf.expr, scope, errors) catch |err| switch (err) {
                    error.typeError => return ast.enpoison(),
                    else => return err,
                };
            } else {
                if (try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                    // Address type, type of this ast must be a type, inner must be a type
                    ast.addrOf.expr = try validateAST(ast.addrOf.expr, primitives.type_type, scope, errors, allocator);
                    if (ast.addrOf.expr.* == .poison) {
                        return ast.enpoison();
                    }
                } else {
                    // Address value, expected must be an address, inner must match with expected's inner
                    const expanded_expected = try expected.?.expand_type(scope, errors, allocator); // Call is memoized
                    if (expanded_expected.* != .addrOf) {
                        // Didn't expect an address type. Validate expr and report error
                        ast.addrOf.expr = try validateAST(ast.addrOf.expr, null, scope, errors, allocator);
                        if (ast.addrOf.expr.* == .poison) {
                            return ast.enpoison();
                        }
                        errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator) } });
                        return ast.enpoison();
                    }

                    // Everythings Ok.
                    ast.addrOf.expr = try validateAST(ast.addrOf.expr, expanded_expected.addrOf.expr, scope, errors, allocator);
                    if (ast.addrOf.expr.* == .poison) {
                        return ast.enpoison();
                    }
                    ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                    if (ast.addrOf.expr.* != .product) {
                        // Validate that expr is an L-value *only if* expr is not a product
                        // It is possible to take a addr of a product. The address is the address of the temporary
                        // This is mirrored with a slice_of a product.
                        validateLValue(ast.addrOf.expr, scope, errors) catch |err| switch (err) {
                            error.typeError => return ast.enpoison(),
                            else => return err,
                        };
                    }
                    if (ast.addrOf.mut) {
                        assertMutable(ast.addrOf.expr, scope, errors, allocator) catch |err| switch (err) {
                            error.typeError => return ast.enpoison(), // Soft unreachable, will be caught early but is still good to have this here
                            else => return err,
                        };
                    }
                }
            }
            return ast;
        },
        .sliceOf => { // TODO: TOO LONG!
            var was_type = false;
            ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, null, scope, errors, allocator);
            if (ast.sliceOf.expr.* == .poison) {
                return ast.enpoison();
            }
            var expr_type = try ast.sliceOf.expr.typeof(scope, errors, allocator);

            if (try primitives.type_type.typesMatch(expr_type, scope, errors, allocator)) {
                // Slice-of type, type of this ast must be a type, inner must be a type
                if (ast.sliceOf.len) |len| {
                    ast.sliceOf.len = try validateAST(len, primitives.int_type, scope, errors, allocator);
                    if (ast.sliceOf.len.?.* == .poison) {
                        return ast.enpoison();
                    }
                }
                if (ast.sliceOf.kind == .ARRAY) {
                    // Inflate to product
                    var new_terms = std.ArrayList(*AST).init(allocator);
                    if (ast.sliceOf.len.?.* != .int) {
                        errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "not integer literal" } });
                        return ast.enpoison();
                    }
                    for (0..@as(usize, @intCast(ast.sliceOf.len.?.int.data))) |_| {
                        try new_terms.append(ast.sliceOf.expr);
                    }
                    if (ast.sliceOf.len.?.int.data <= 0) {
                        errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "array length is negative" } });
                        return ast.enpoison();
                    }
                    return try AST.createProduct(ast.getToken(), new_terms, allocator);
                } else {
                    // Regular slice type, change to product of data address and length
                    return try AST.create_slice_type(ast.sliceOf.expr, ast.sliceOf.kind == .MUT, allocator);
                }
                was_type = true;
            } else { // Slice-of value, expected must be an slice, inner must match with expected's inner
                if (ast.sliceOf.kind != .SLICE and ast.sliceOf.kind != .MUT) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "array length is not allowed in slice-of operator" } });
                    return ast.enpoison();
                }

                // ast.sliceOf.expr must be homotypical product type of expected
                if (expr_type.* != .product or !try expr_type.product.is_homotypical(scope, errors, allocator)) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "attempt to take slice-of something that is not an array" } });
                    return ast.enpoison();
                }

                ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                if (expected != null and !try (try ast.typeof(scope, errors, allocator)).typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator) } });
                    return ast.enpoison();
                }

                if (ast.sliceOf.expr.* != .product) {
                    // Validate that expr is an L-value *only if* expr is not a product
                    // It is possible to take a slice of a product. The slice is the sliceof the temporary
                    // This is mirrored with addr_of a product.
                    validateLValue(ast.sliceOf.expr, scope, errors) catch |err| switch (err) {
                        error.typeError => return ast.enpoison(), // soft unreachable, will be rejected because not a slice type
                        else => return err,
                    };
                }
                if (ast.sliceOf.kind == .MUT) {
                    assertMutable(ast.sliceOf.expr, scope, errors, allocator) catch |err| switch (err) {
                        error.typeError => return ast.enpoison(), // soft unreachable, will be rejected because not a slice type
                        else => return err,
                    };
                }

                return try AST.create_slice_value(ast.sliceOf.expr, ast.sliceOf.kind == .MUT, expr_type, allocator);
            }
        },
        .subSlice => {
            ast.subSlice.super = try validateAST(ast.subSlice.super, null, scope, errors, allocator);
            if (ast.subSlice.super.* == .poison) {
                return ast.enpoison();
            }
            const super_type = try ast.subSlice.super.typeof(scope, errors, allocator);
            if (super_type.* != .product or !super_type.product.was_slice) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot take a sub-slice of something that is not a slice" } });
                return ast.enpoison();
            }

            if (ast.subSlice.lower) |lower| {
                ast.subSlice.lower = try validateAST(lower, primitives.int_type, scope, errors, allocator);
            } else {
                ast.subSlice.lower = try AST.createInt(ast.getToken(), 0, allocator);
                ast.subSlice.lower.?.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast.subSlice.lower.? } };
            }
            if (ast.subSlice.upper) |upper| {
                ast.subSlice.upper = try validateAST(upper, primitives.int_type, scope, errors, allocator);
            } else {
                var length = try AST.createIdentifier(Token.create("length", null, "", "", 0, 0), allocator);
                length.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = length } };
                const index = try AST.createSelect(
                    ast.getToken(),
                    ast.subSlice.super,
                    length,
                    allocator,
                );
                ast.subSlice.upper = try validateAST(index, primitives.int_type, scope, errors, allocator);
            }
            if (ast.subSlice.lower.?.* == .poison or ast.subSlice.upper.?.* == .poison) {
                return ast.enpoison();
            }
            return ast;
        },
        .annotation => {
            ast.annotation.type = try validateAST(ast.annotation.type, primitives.type_type, scope, errors, allocator);
            if (ast.annotation.init != null) {
                ast.annotation.init = try validateAST(ast.annotation.init.?, ast.annotation.type, scope, errors, allocator);
            }
            if (ast.annotation.type.* == .poison or (ast.annotation.init != null and ast.annotation.init.?.* == .poison)) {
                return ast.enpoison();
            }

            if (expected != null and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.type_type } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        .inferredMember => { // TODO: TOO LONG!
            var expected_expanded: *AST = undefined;
            if (expected != null) {
                expected_expanded = try expected.?.expand_type(scope, errors, allocator);
            }

            if (expected == null) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot infer the sum type" } });
                return ast.enpoison();
            } else if (expected_expanded.* == .inferred_error) {
                ast.inferredMember.base = expected;
                const name = ast.inferredMember.ident.getToken().data;
                for (expected_expanded.inferred_error.terms.items, 0..) |term, i| {
                    if (std.mem.eql(u8, term.annotation.pattern.getToken().data, name)) {
                        ast.inferredMember.pos = i;
                        break;
                    }
                }
                if (ast.inferredMember.pos == null) {
                    // Put in inferred_error
                    const annot_type = if (ast.inferredMember.init == null) primitives.unit_type else try ast.inferredMember.init.?.typeof(scope, errors, allocator);
                    const annot = try AST.createAnnotation(ast.getToken(), try AST.createIdentifier(ast.inferredMember.ident.getToken(), allocator), annot_type, null, null, allocator);
                    try expected_expanded.inferred_error.terms.append(annot);
                    ast.inferredMember.pos = expected_expanded.inferred_error.terms.items.len - 1;
                }
                return ast;
            } else if (expected_expanded.* != .sum) {
                errors.addError(Error{ .expectedGotString = .{ .span = ast.getToken().span, .expected = expected.?, .got = "an inferred member" } });
                return ast.enpoison();
            } else {
                ast.inferredMember.base = expected;
                for (expected_expanded.sum.terms.items, 0..) |term, i| {
                    if (std.mem.eql(u8, term.annotation.pattern.getToken().data, ast.inferredMember.ident.getToken().data)) {
                        ast.inferredMember.pos = i;
                        break;
                    }
                }
                if (ast.inferredMember.pos == null) {
                    errors.addError(Error{ .member_not_in = .{ .span = ast.getToken().span, .identifier = ast.inferredMember.ident.getToken().data, .group_name = "sum" } });
                    return ast.enpoison();
                }

                const pos: i128 = ast.inferredMember.pos.?;
                const proper_term: *AST = expected_expanded.sum.terms.items[@as(usize, @intCast(pos))];

                if (proper_term.annotation.init) |_init| {
                    ast.inferredMember.init = _init; // This will be overriden by an inject expression's rhs
                }

                return ast;
            }
        },
        ._if => {
            if (ast._if.let) |let| {
                ast._if.let = try validateAST(let, null, scope, errors, allocator);
            }
            ast._if.condition = try validateAST(ast._if.condition, primitives.bool_type, ast._if.scope.?, errors, allocator);
            if (expected != null) {
                // expecting a type
                var expected_expanded = try expected.?.expand_type(scope, errors, allocator);
                const is_expected_optional = expected_expanded.* == .sum and expected_expanded.sum.was_optional;
                const has_else = ast._if.elseBlock != null;
                if (has_else) {
                    ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, expected.?, ast._if.scope.?, errors, allocator);
                    ast._if.elseBlock = try validateAST(ast._if.elseBlock.?, expected.?, ast._if.scope.?, errors, allocator);
                } else if (is_expected_optional) {
                    const full_type = expected_expanded.get_some_type();
                    ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, full_type, ast._if.scope.?, errors, allocator);
                } else {
                    ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, expected.?, ast._if.scope.?, errors, allocator);
                    ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator) } });
                    return ast.enpoison();
                }
            } else {
                // expecting nothing
                ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, null, ast._if.scope.?, errors, allocator);
                if (ast._if.elseBlock) |elseBlock| {
                    ast._if.elseBlock = try validateAST(elseBlock, null, ast._if.scope.?, errors, allocator);
                }
            }
            if ((ast._if.let != null and ast._if.let.?.* == .poison) or
                ast._if.condition.* == .poison or
                ast._if.bodyBlock.* == .poison or
                (ast._if.elseBlock != null and ast._if.elseBlock.?.* == .poison))
            {
                return ast.enpoison();
            }
            return ast;
        },
        .match => { // TODO: TOO LONG!
            var poisoned = false;
            if (ast.match.let) |let| {
                ast.match.let = try validateAST(let, null, scope, errors, allocator);
                poisoned = ast.match.let.?.* == .poison or poisoned;
            }
            ast.match.expr = try validateAST(ast.match.expr, null, ast.match.scope.?, errors, allocator);
            poisoned = ast.match.expr.* == .poison or poisoned;

            var expr_type = try ast.match.expr.typeof(scope, errors, allocator);
            const expr_type_expanded = try expr_type.expand_type(scope, errors, allocator);
            if (expr_type_expanded.* == .poison) {
                return ast.enpoison(); // Can't do anything with this
            }

            if (ast.match.mappings.items.len == 0) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "match has no patterns" } });
                return ast.enpoison();
            }

            // Go through mappings, get their validated form
            var changed = false;
            var new_mappings = std.ArrayList(*AST).init(allocator);
            for (ast.match.mappings.items) |mapping| {
                if (expected != null) {
                    // Expecting a type from the match
                    var expected_expanded = try expected.?.expand_type(scope, errors, allocator);
                    const is_expected_optional = expected_expanded.* == .sum and expected_expanded.sum.was_optional;
                    const has_else = ast.match.has_else;
                    if (has_else) {
                        // match has `else` => validate regular expected type
                        const new_mapping = try validateAST(mapping, expected, ast.match.scope.?, errors, allocator);
                        try new_mappings.append(new_mapping);
                        changed = changed or new_mapping != mapping;
                        poisoned = poisoned or new_mapping.* == .poison;
                    } else if (is_expected_optional) {
                        // match has no `else`, expecting an optional type => validate mappings w/ base of optional expected type
                        const full_type = expected_expanded.get_some_type();
                        const new_mapping = try validateAST(mapping, full_type, ast.match.scope.?, errors, allocator);
                        try new_mappings.append(new_mapping);
                        changed = changed or new_mapping != mapping;
                        poisoned = poisoned or new_mapping.* == .poison;
                    } else {
                        // match has no else, not expecting an optional type => type error
                        var new_map = try validateAST(mapping, expected.?, ast.match.scope.?, errors, allocator);
                        const new_map_type = try new_map.typeof(scope, errors, allocator);
                        ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                        errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try AST.create_optional_type(new_map_type, allocator) } });
                        return ast.enpoison();
                    }
                } else {
                    // Not expecting anything => validate mappings with null type
                    const new_mapping = try validateAST(mapping, null, ast.match.scope.?, errors, allocator);
                    try new_mappings.append(new_mapping);
                    changed = changed or new_mapping != mapping;
                    poisoned = poisoned or new_mapping.* == .poison;
                }
                if (mapping.mapping.lhs) |lhs| {
                    try assert_pattern_matches(lhs, expr_type_expanded, ast.match.scope.?, errors, allocator);
                }
            }
            try exhaustive_check(expr_type_expanded, &ast.match.mappings, ast.getToken().span, errors, allocator);
            if (poisoned) {
                return ast.enpoison();
            } else if (changed) {
                ast.match.mappings = new_mappings;
            } else {
                new_mappings.deinit();
            }
            return ast;
        },
        .mapping => {
            // lhs for match mappings must be done elsewhere
            if (ast.mapping.scope) |mapping_scope| {
                // non-else mappings have their own scope
                ast.mapping.rhs = try validateAST(ast.mapping.rhs.?, expected, mapping_scope, errors, allocator);
            } else {
                // else mappings use the scope of the surrounding match statement
                ast.mapping.rhs = try validateAST(ast.mapping.rhs.?, expected, scope, errors, allocator);
            }
            if ((ast.mapping.lhs != null and ast.mapping.lhs.?.* == .poison) or ast.mapping.rhs.?.* == .poison) {
                return ast.enpoison();
            }
            return ast;
        },
        ._while => {
            if (ast._while.let) |let| {
                ast._while.let = try validateAST(let, null, scope, errors, allocator);
            }
            if (ast._while.post) |post| {
                ast._while.post = try validateAST(post, null, ast._while.scope.?, errors, allocator);
            }
            ast._while.condition = try validateAST(ast._while.condition, primitives.bool_type, ast._while.scope.?, errors, allocator);

            var optional_type = false; //< Set if expected is an optional type
            if (expected != null) {
                var expected_expanded = try expected.?.expand_type(scope, errors, allocator);
                if (expected_expanded.* == .sum and expected_expanded.sum.was_optional) {
                    const full_type = expected_expanded.get_some_type();
                    ast._while.bodyBlock = try validateAST(ast._while.bodyBlock, full_type, ast._while.scope.?, errors, allocator);
                    optional_type = true;
                }
            }
            if (!optional_type) {
                ast._while.bodyBlock = try validateAST(ast._while.bodyBlock, expected, ast._while.scope.?, errors, allocator);
                if (ast._while.elseBlock) |elseBlock| {
                    ast._while.elseBlock = try validateAST(elseBlock, expected, ast._while.scope.?, errors, allocator);
                }
            }
            if ((ast._while.let != null and ast._while.let.?.* == .poison) or
                (ast._while.post != null and ast._while.post.?.* == .poison) or
                ast._while.condition.* == .poison or
                ast._while.bodyBlock.* == .poison or
                (ast._while.elseBlock != null and ast._while.elseBlock.?.* == .poison))
            {
                return ast.enpoison();
            }
            return ast;
        },
        .block => { // TODO: TOO LONG!
            var changed = false;
            var poisoned = false;
            var new_statements = std.ArrayList(*AST).init(allocator);
            if (ast.block.final) |final| {
                // Has final

                for (ast.block.statements.items) |statement| {
                    const new_statement = try validateAST(statement, null, ast.block.scope.?, errors, allocator);
                    try new_statements.append(new_statement);
                    poisoned = poisoned or new_statement.* == .poison;
                    changed = changed or new_statement != statement;
                }
                ast.block.final = try validateAST(final, expected, ast.block.scope.?, errors, allocator);
                poisoned = poisoned or ast.block.final.?.* == .poison;
                if (changed) {
                    ast.block.statements = new_statements;
                } else {
                    new_statements.deinit();
                }
            } else {
                // Hasn't final

                for (ast.block.statements.items, 0..) |statement, i| {
                    const expect_type: ?*AST = if (i == ast.block.statements.items.len - 1) expected else null;
                    const new_statement = try validateAST(statement, expect_type, ast.block.scope.?, errors, allocator);
                    try new_statements.append(new_statement);
                    poisoned = poisoned or new_statement.* == .poison;
                    changed = changed or new_statement != statement;
                }
                if (changed) {
                    ast.block.statements = new_statements;
                } else {
                    new_statements.deinit();
                }

                ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } }; // So that the typeof code can be reused. All children should be validated at this point
                var block_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !try block_type.typesMatch(expected.?, scope, errors, allocator)) {
                    // std.debug.assert(ast.block.statements.items.len == 0); // is this true? what about a block that ends in a defer? or a decl?
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = block_type } });
                    return ast.enpoison();
                }
            }
            if (poisoned) {
                return ast.enpoison();
            } else {
                return ast;
            }
        },

        // no return
        ._break => {
            if (!scope.in_loop) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`break` must be inside a loop",
                } });
                return ast.enpoison();
            }
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            return ast;
        },
        ._continue => {
            if (!scope.in_loop) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`continue` must be inside a loop",
                } });
                return ast.enpoison();
            }
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            return ast;
        },

        ._return => {
            if (scope.in_function == 0 or scope.inner_function == null) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`return` must be inside in a function",
                } });
                return ast.enpoison();
            }
            if (ast._return.expr) |expr| {
                ast._return.expr = try validateAST(expr, scope.inner_function.?._type.function.rhs, scope, errors, allocator);
                if (ast._return.expr.?.* == .poison) {
                    return ast.enpoison();
                }
            } else if (expected != null and (try expected.?.expand_type(scope, errors, allocator)).* != .unit_type) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            return ast;
        },
        ._unreachable => {
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            return ast;
        },

        ._defer => {
            ast._defer.statement = try validateAST(ast._defer.statement, null, scope, errors, allocator);
            if (ast._defer.statement.* == .poison) {
                return ast.enpoison();
            }
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            try scope.defers.append(ast._defer.statement);
            return ast;
        },
        ._errdefer => {
            ast._errdefer.statement = try validateAST(ast._errdefer.statement, null, scope, errors, allocator);
            if (ast._errdefer.statement.* == .poison) {
                return ast.enpoison();
            }
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            try scope.errdefers.append(ast._errdefer.statement);
            return ast;
        },
        .fnDecl => {
            try validateSymbol(ast.fnDecl.symbol.?, errors, allocator);
            if (ast.fnDecl.symbol.?._type.* == .poison) {
                return ast.enpoison();
            }
            if (expected) |_expected| {
                var expected_expanded = try _expected.expand_type(scope, errors, allocator);
                const self_type = try ast.typeof(scope, errors, allocator);
                if (!try expected_expanded.typesMatch(self_type, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected_expanded, .got = self_type } });
                    return ast.enpoison();
                }
            }
            return ast;
        },
        .decl => {
            var poisoned = false;
            ast.decl.type = try validateAST(ast.decl.type, primitives.type_type, scope, errors, allocator);
            if (ast.decl.type.* != .poison) {
                ast.decl.init = try validateAST(ast.decl.init, ast.decl.type, scope, errors, allocator);
                poisoned = ast.decl.init.* == .poison;
            } else {
                return ast.enpoison();
            }

            for (ast.decl.symbols.items) |symbol| {
                symbol.defined = true;
                try validateSymbol(symbol, errors, allocator);
            }

            // statement, no type
            if (poisoned) {
                return ast.enpoison();
            } else if (expected != null and !try primitives.unit_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expectedType = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast } });
                return ast.enpoison();
            }
            return ast;
        },
        else => {
            std.debug.print("validateAST() unimplemented for {s}\n", .{@tagName(ast.*)});
            unreachable;
        },
    }
}

fn default_args(asts: std.ArrayList(*AST), expected: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !std.ArrayList(*AST) {
    if (try args_are_named(asts, errors)) {
        return named_args(asts, expected, scope, errors, allocator);
    } else {
        return positional_args(asts, expected, allocator);
    }
}

fn args_are_named(asts: std.ArrayList(*AST), errors: *errs.Errors) !bool {
    if (asts.items.len == 0) {
        return false;
    }

    var seen_named = false;
    var seen_pos = false;
    for (asts.items) |term| {
        if (term.* == .assign) {
            seen_named = true;
        } else {
            seen_pos = true;
        }
    }
    std.debug.assert(seen_named or seen_pos);
    if (seen_named and seen_pos) {
        errors.addError(Error{ .basic = .{
            .span = asts.items[0].getToken().span,
            .msg = "mixed positional and named arguments are not allowed",
        } });
        return error.typeError;
    } else {
        return seen_named;
    }
}

fn positional_args(asts: std.ArrayList(*AST), expected: *AST, allocator: std.mem.Allocator) !std.ArrayList(*AST) {
    var retval = std.ArrayList(*AST).init(allocator);
    errdefer retval.deinit();

    switch (expected.*) {
        .annotation => {
            if (asts.items.len == 0 and expected.annotation.init != null) {
                try retval.append(expected.annotation.init.?);
            } else if (asts.items.len > 0) {
                for (asts.items) |item| {
                    try retval.append(item);
                }
            } else {
                return error.NoDefault;
            }
        },

        .product => {
            for (expected.product.terms.items, 0..) |term, i| {
                // ast is product, append ast's corresponding term
                if (asts.items.len > 1 and i < asts.items.len) {
                    try retval.append(asts.items[i]);
                }
                // ast is unit or ast isn't a product and i > 0 or ast is a product and off the edge of ast's terms, try to fill with the default
                else if (asts.items.len == 0 or (asts.items.len <= 1 and i > 0) or (asts.items.len > 1 and i >= asts.items.len)) {
                    if (term.* == .annotation and term.annotation.init != null) {
                        try retval.append(term.annotation.init.?);
                    } else {
                        return error.NoDefault;
                    }
                }
                // ast is not product, i != 0, append ast as first term
                else {
                    try retval.append(asts.items[0]);
                }
            }
        },

        .unit_type => {
            retval = asts;
        },

        .identifier => {
            retval = asts;
        },

        else => {
            std.debug.print("unimplemented for {s}\n", .{@tagName(expected.*)});
            unreachable;
        },
    }
    return retval;
}

fn named_args(asts: std.ArrayList(*AST), expected: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !std.ArrayList(*AST) {
    std.debug.assert(asts.items.len > 0);
    // Maps assign.lhs name to assign.rhs
    var arg_map = std.StringArrayHashMap(*AST).init(allocator);
    defer arg_map.deinit();

    // Associate argument names with their values
    if (asts.items.len == 1) {
        putAssign(asts.items[0], &arg_map, errors) catch |err| switch (err) {
            error.typeError => return error.NoDefault,
            else => return err,
        };
    } else {
        for (asts.items) |term| {
            putAssign(term, &arg_map, errors) catch |err| switch (err) {
                error.typeError => return error.NoDefault,
                else => return err,
            };
        }
    }

    // Construct positional args in the order specified by `expected`
    var retval = std.ArrayList(*AST).init(allocator);
    errdefer retval.deinit();
    var new_expected = expected;
    if (expected.* == .annotation and (try expected.annotation.type.expand_type(scope, errors, allocator)).* == .product) {
        new_expected = try expected.annotation.type.expand_type(scope, errors, allocator);
    }
    switch (new_expected.*) {
        .annotation => {
            if (arg_map.keys().len != 1) { // Cannot be 0, since that is technically a positional arglist
                errors.addError(Error{ .basic = .{
                    .span = asts.items[0].getToken().span,
                    .msg = "too many arguments/fields specifed",
                } });
                // return error.NoDefault;
                unreachable;
            } else {
                try retval.append(arg_map.values()[0]);
            }
        },

        .product => {
            for (new_expected.product.terms.items) |term| {
                if (term.* != .annotation) {
                    errors.addError(Error{ .basic = .{
                        .span = asts.items[0].getToken().span,
                        .msg = "expected type does not accept named arugments",
                    } });
                    return error.NoDefault;
                }
                const arg = arg_map.get(term.annotation.pattern.getToken().data);
                if (arg == null) {
                    if (term.annotation.init != null) {
                        try retval.append(term.annotation.init.?);
                    } else {
                        errors.addError(Error{ .basic = .{
                            .span = asts.items[0].getToken().span,
                            .msg = "not all arguments are specified",
                        } });
                        return error.NoDefault;
                    }
                } else {
                    try retval.append(arg.?);
                }
            }
        },

        else => unreachable,
    }
    return retval;
}

fn putAssign(ast: *AST, arg_map: *std.StringArrayHashMap(*AST), errors: *errs.Errors) !void {
    if (ast.assign.lhs.* != .inferredMember) {
        errors.addError(Error{ .expectedBasicToken = .{
            .expected = "an inferred member",
            .got = ast.assign.lhs.getToken(),
        } });
        return error.typeError;
    }
    const name = ast.assign.lhs.inferredMember.ident.getToken().data;
    if (arg_map.get(name)) |_| {
        errors.addError(Error{ .basic = .{
            .span = ast.getToken().span,
            .msg = "parameter is already defined",
        } });
        return error.typeError;
    } else {
        try arg_map.put(name, ast.assign.rhs);
    }
}

fn putAnnotation(ast: *AST, arg_map: *std.StringArrayHashMap(*AST), errors: *errs.Errors) !void {
    const name = ast.annotation.pattern.getToken().data;
    if (arg_map.get(name)) |_| { // TODO: Only error if the types are not identical
        errors.addError(Error{ .basic = .{
            .span = ast.getToken().span,
            .msg = "duplicate annotation identifiers detected",
        } });
        return error.typeError;
    } else {
        try arg_map.put(name, ast.annotation.type);
    }
}

// TODO: Move this elsewhere
pub fn findSymbol(ast: *AST, expected: ?*AST, scope: *Scope, errors: *errs.Errors) !*Symbol {
    const symbol = scope.lookup(ast.getToken().data, false) orelse {
        errors.addError(Error{ .undeclaredIdentifier = .{ .identifier = ast.getToken(), .scope = scope, .expected = expected } });
        return error.typeError;
    };
    if (!symbol.defined) {
        errors.addError(Error{ .useBeforeDef = .{ .identifier = ast.getToken(), .symbol = symbol } });
        return error.typeError;
    }
    return symbol;
}

fn validateLValue(ast: *AST, scope: *Scope, errors: *errs.Errors) !void {
    switch (ast.*) {
        .identifier => {
            _ = try findSymbol(ast, null, scope, errors);
        },

        .dereference => {
            const child = ast.dereference.expr;
            if (child.* != .addrOf) {
                try validateLValue(child, scope, errors);
            }
        },

        .index => {
            try validateLValue(ast.index.lhs, scope, errors);
        },

        .select => {
            try validateLValue(ast.select.lhs, scope, errors);
        },

        .product => {
            for (ast.product.terms.items) |term| {
                try validateLValue(term, scope, errors);
            }
        },

        else => {
            errors.addError(Error{ .basic = .{
                .span = ast.getToken().span,
                .msg = "not an l-value",
            } });
            return error.typeError;
        },
    }
}

fn assertMutable(ast: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    switch (ast.*) {
        .identifier => {
            const symbol = try findSymbol(ast, null, scope, errors);
            if (!std.mem.eql(u8, symbol.name, "_") and symbol.kind != .mut) {
                errors.addError(Error{ .modifyImmutable = .{
                    .identifier = ast.getToken(),
                    .symbol = symbol,
                } });
                return error.typeError;
            }
        },

        .dereference => {
            var child = ast.dereference.expr;
            const child_type = try child.typeof(scope, errors, allocator);
            if (!child_type.addrOf.mut) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "cannot modify non-mutable address",
                } });
                return error.typeError;
            }
        },

        .index => {
            const lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .product and lhs_type.product.was_slice) {
                const child_type = lhs_type.product.terms.items[0];
                if (!child_type.annotation.type.addrOf.mut) {
                    errors.addError(Error{ .basic = .{
                        .span = ast.getToken().span,
                        .msg = "cannot modify non-mutable address",
                    } });
                    return error.typeError;
                }
            } else {
                try assertMutable(ast.index.lhs, scope, errors, allocator);
            }
        },

        .product => {
            for (ast.product.terms.items) |term| {
                try assertMutable(term, scope, errors, allocator);
            }
        },

        .select => {
            try assertMutable(ast.select.lhs, scope, errors, allocator);
        },

        else => unreachable,
    }
}

/// Validates that `pattern` is valid given a match's `expr`
fn assert_pattern_matches(pattern: *AST, expr_type: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    switch (pattern.*) {
        .unit_value => {
            if (!try expr_type.typesMatch(primitives.unit_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = primitives.unit_type } });
                return error.typeError;
            }
        },
        .int => {
            // TODO: These should check for `can_represent`, not straight match
            if (!try expr_type.typesMatch(primitives.int_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = primitives.int_type } });
                return error.typeError;
            }
        },
        .char => {
            if (!try expr_type.typesMatch(primitives.char_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = primitives.char_type } });
                return error.typeError;
            }
        },
        .string => {
            if (!try expr_type.typesMatch(primitives.string_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = primitives.string_type } });
                return error.typeError;
            }
        },
        .float => {
            if (!try expr_type.typesMatch(primitives.float_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = primitives.float_type } });
                return error.typeError;
            }
        },
        ._true, ._false => {
            if (!try expr_type.typesMatch(primitives.bool_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = primitives.bool_type } });
                return error.typeError;
            }
        },
        .block => {
            var new_pattern = try validateAST(pattern, expr_type, scope, errors, allocator);
            if (!try expr_type.typesMatch(try new_pattern.typeof(scope, errors, allocator), scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = primitives.int_type } });
                return error.typeError;
            }
        },
        .select => {
            var new_pattern = try validateAST(pattern, expr_type, scope, errors, allocator);
            if (new_pattern.* == .poison) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = _ast.poisoned } });
                return error.typeError;
            }
            pattern.select.pos = @as(usize, @intCast(new_pattern.inferredMember.pos.?));
            const pattern_type = try new_pattern.typeof(scope, errors, allocator);
            if (!try expr_type.typesMatch(pattern_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = pattern_type } });
                return error.typeError;
            }
        },
        .inferredMember => {
            var new_pattern = try validateAST(pattern, expr_type, scope, errors, allocator);
            if (new_pattern.* == .poison) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = _ast.poisoned } });
                return error.typeError;
            }
            pattern.inferredMember.pos = new_pattern.inferredMember.pos.?;
            const pattern_type = try new_pattern.typeof(scope, errors, allocator);
            if (!try expr_type.typesMatch(pattern_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = pattern_type } });
                return error.typeError;
            }
        },
        .inject => {
            const domain = try domainof(pattern, expr_type, scope, errors, allocator);
            if (domain.* == .poison) {
                return error.typeError;
            }
            try assert_pattern_matches(pattern.inject.rhs, domain, scope, errors, allocator);
        },
        .product => {
            const expanded_expr = try expr_type.expand_type(scope, errors, allocator);
            if (expanded_expr.* != .product or expanded_expr.product.terms.items.len != pattern.product.terms.items.len) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = _ast.poisoned } });
                return error.typeError;
            }
            for (pattern.product.terms.items, expanded_expr.product.terms.items) |term, expanded_term| {
                try assert_pattern_matches(term, expanded_term, scope, errors, allocator);
            }
        },
        .symbol => {},
        else => {
            std.debug.print("unimplemented assert_pattern_matches() for {s}\n", .{@tagName(pattern.*)});
            unreachable;
        },
    }
    pattern.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = pattern } };
}

fn indexof(list: *std.ArrayList(usize), elem: usize) ?usize {
    for (list.items, 0..) |item, i| {
        if (item == elem) {
            return i;
        }
    }
    return null;
}

fn exhaustive_check(_type: *AST, mappings: *std.ArrayList(*AST), match_span: Span, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    if (_type.* == .sum) {
        var ids = std.ArrayList(usize).init(allocator);
        defer ids.deinit();

        for (_type.sum.terms.items, 0..) |_, i| {
            try ids.append(i);
        }
        for (mappings.items) |m| {
            if (m.mapping.lhs == null) {
                continue;
            }
            exhaustive_check_sub(m.mapping.lhs.?, &ids);
        }
        if (ids.items.len > 0) {
            var forgotten = std.ArrayList(*AST).init(std.heap.page_allocator); // Not deallocated, lifetime should be until error emission
            for (ids.items) |id| {
                try forgotten.append(_type.sum.terms.items[id]);
            }
            errors.addError(Error{ .nonExhaustiveSum = .{ .span = match_span, .forgotten = forgotten } });
            return error.typeError;
        }
    }
}

fn exhaustive_check_sub(ast: *AST, ids: *std.ArrayList(usize)) void {
    switch (ast.*) {
        .select => {
            const id: ?usize = indexof(ids, @intCast(ast.select.pos.?));
            if (id) |_id| {
                _ = ids.swapRemove(_id);
            }
        },
        .inferredMember => {
            const id: ?usize = indexof(ids, @intCast(ast.inferredMember.pos.?));
            if (id) |_id| {
                _ = ids.swapRemove(_id);
            }
        },
        .inject => {
            exhaustive_check_sub(ast.inject.lhs, ids);
        },
        .symbol => {
            ids.clearRetainingCapacity();
        },
        else => {},
    }
}

// Takes in an inject AST (pattern or expr) of the form `lhs <- rhs` and returns the type that `rhs` should be.
// Also validates the inject AST. Thus, if `lhs` is an inferred member, it will find out the sum type it belongs to.
pub fn domainof(ast: *AST, sum_type: ?*AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !*AST {
    if (ast.inject.lhs.* == .inferredMember) {
        // Pass sum_type so that base can be inferred call
        ast.inject.lhs = try validateAST(ast.inject.lhs, sum_type, scope, errors, allocator);
    } else {
        ast.inject.lhs = try validateAST(ast.inject.lhs, null, scope, errors, allocator);
    }
    if (ast.inject.lhs.* == .poison) { // Don't bother moving on...
        return _ast.poisoned;
    }
    var lhs_type = try ast.inject.lhs.typeof(scope, errors, allocator);
    const expanded_lhs_type = try lhs_type.expand_type(scope, errors, allocator);
    if (expanded_lhs_type.* == .sum and ast.inject.lhs.* == .inferredMember) {
        if (sum_type != null and !try sum_type.?.typesMatch(lhs_type, scope, errors, allocator)) {
            errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = sum_type.?, .got = ast.inject.lhs.inferredMember.base.? } });
            return _ast.poisoned;
        }
        const pos: i128 = ast.inject.lhs.inferredMember.pos.?;
        const proper_term: *AST = (try ast.inject.lhs.typeof(scope, errors, allocator)).sum.terms.items[@as(usize, @intCast(pos))];
        return proper_term.annotation.type;
    } else {
        errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "inject is not to a sum" } });
        return _ast.poisoned;
    }
}
