const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const interpreter_ = @import("interpreter.zig");
const module_ = @import("module.zig");
const primitives_ = @import("primitives.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const token_ = @import("token.zig");

pub fn validate_module(module: *module_.Module, errors: *errs_.Errors, allocator: std.mem.Allocator) !void {
    try validate_scope(module.scope, errors, allocator);
}

fn validate_scope(scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) !void {
    for (scope.symbols.keys()) |key| {
        const symbol = scope.symbols.get(key).?;
        try validateSymbol(symbol, errors, allocator);
    }
    for (scope.children.items) |child| {
        try validate_scope(child, errors, allocator);
    }
}

fn validateSymbol(symbol: *symbol_.Symbol, errors: *errs_.Errors, allocator: std.mem.Allocator) error{ typeError, interpreter_panic, NotAnLValue }!void {
    if (symbol.validation_state == .valid or symbol.validation_state == .validating) {
        return;
    }
    symbol.validation_state = .validating;

    std.debug.assert(symbol.init.* != .poison);
    // std.debug.print("{s}: {} = {}\n", .{ symbol.name, symbol._type, symbol.init });
    symbol._type = validateAST(symbol._type, primitives_.type_type, errors, allocator);
    if (symbol._type.* != .poison) {
        _ = symbol.assert_valid();
        symbol.expanded_type = symbol._type.expand_type(allocator);
        const expected = if (symbol.kind == ._fn or symbol.kind == ._comptime) symbol._type.function.rhs else symbol._type;
        symbol.init = validateAST(symbol.init, expected, errors, allocator);
        if (symbol.init.* == .poison) {
            symbol.validation_state = .invalid;
            return error.typeError;
            // unreachable;
        } else if ((symbol.kind == ._fn or symbol.kind == ._comptime) and symbol._type.function.rhs.* == .inferred_error) {
            const terms = symbol._type.function.rhs.inferred_error.terms;
            symbol._type.function.rhs.* = ast_.AST{ .sum = .{ .common = symbol._type.function.rhs.getCommon().*, .terms = terms, .was_error = true } };
        }
    } else {
        symbol.validation_state = .invalid;
        return error.typeError;
    }

    // Symbol's name must be capitalizes iff it type is Type
    if (symbol.expanded_type != null and !std.mem.eql(u8, symbol.name, "_")) {
        if (symbol.expanded_type.?.* == .identifier and std.mem.eql(u8, symbol.expanded_type.?.getToken().data, "Type")) {
            if (!std.ascii.isUpper(symbol.name[0])) {
                errors.addError(errs_.Error{ .symbol_error = .{
                    .span = symbol.span,
                    .context_span = null,
                    .name = symbol.name,
                    .problem = "of type `Type` must start with an uppercase letter",
                    .context_message = "",
                } });
            }
        } else {
            if (std.ascii.isUpper(symbol.name[0])) {
                errors.addError(errs_.Error{ .symbol_error = .{
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
    ast: *ast_.AST,
    old_expected_type: ?*ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) *ast_.AST {
    var expected_type = old_expected_type;
    if (ast.getCommon().validation_state == .validating) {
        errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "recursive definition detected" } });
        return ast_.poisoned;
    } else if (ast.getCommon().validation_state == .invalid) {
        return ast_.poisoned;
    } else if (ast.getCommon().validation_state == .valid) {
        return ast.getCommon().validation_state.valid.valid_form;
    }
    // std.debug.print("{}: {?}\n", .{ ast, expected });
    ast.getCommon().validation_state = .validating;

    if (expected_type) |_| {
        // expected must be a valid Type type
        std.debug.assert(expected_type.?.* != .poison);
        std.debug.assert(expected_type.?.getCommon().validation_state == .valid);
        var type_expected = expected_type.?.typeof(allocator);
        // std.debug.print("typeof({?}) = {}\n", .{ expected, expected_type });
        std.debug.assert(type_expected.typesMatch(primitives_.type_type));

        if (expected_type.?.* == .annotation) {
            expected_type = expected_type.?.annotation.type;
        }
    }

    var retval = validate_AST_internal(ast, expected_type, errors, allocator) catch {
        return ast.enpoison();
    };

    if (retval.* == .poison) {
        return ast.enpoison();
    } else {
        // Might as well memoize expanded_type
        if (expected_type != null and primitives_.type_type.typesMatch(expected_type.?)) {
            _ = retval.expand_type(allocator);
        }

        ast.getCommon().validation_state = ast_.AST_Validation_State{ .valid = .{ .valid_form = retval } };
        retval.getCommon().validation_state = ast_.AST_Validation_State{ .valid = .{ .valid_form = retval } };
        return retval;
    }
}

fn validate_AST_internal(
    ast: *ast_.AST,
    expected: ?*ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) error{ interpreter_panic, typeError, NotAnLValue }!*ast_.AST {
    // std.debug.print("{}\n", .{ast});
    switch (ast.*) {
        .poison => return ast,
        .unit_type => {
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .unit_value => {
            try type_check(ast, primitives_.unit_type, expected, errors);
            return ast;
        },

        .int => {
            try type_check_int(ast, expected, errors);
            return ast;
        },

        .float => {
            try type_check_float(ast, expected, errors);
            return ast;
        },

        .char => {
            try type_check(ast, primitives_.char_type, expected, errors);
            return ast;
        },

        .string => {
            try type_check(ast, primitives_.string_type, expected, errors);
            return ast;
        },

        .identifier => {
            // look up symbol, that's the type
            var symbol = ast.identifier.symbol.?;
            if (symbol.validation_state == .invalid) {
                return ast.enpoison();
            }
            try validateSymbol(symbol, errors, allocator);
            if (symbol.validation_state != .valid or symbol._type.getCommon().validation_state != .valid) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "recursive definition detected" } });
                return ast.enpoison();
            }
            try type_check(ast, symbol._type, expected, errors);
            return ast;
        },

        ._true, ._false => {
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },

        .not => {
            ast.not.expr = validateAST(ast.not.expr, primitives_.bool_type, errors, allocator);
            if (ast.not.expr.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .negate => {
            ast.negate.expr = validateAST(ast.negate.expr, expected, errors, allocator);
            if (ast.negate.expr.* == .poison) {
                return ast.enpoison();
            }
            try type_check_arithmetic(ast, ast.negate.expr.typeof(allocator), errors);
            try type_check(ast, ast.negate.expr.typeof(allocator), expected, errors);
            return ast;
        },
        .dereference => {
            if (expected != null) {
                const addr_of = ast_.AST.createAddrOf(ast.getToken(), expected.?, false, std.heap.page_allocator).assert_valid();
                ast.dereference.expr = validateAST(ast.dereference.expr, addr_of, errors, allocator);
            } else {
                ast.dereference.expr = validateAST(ast.dereference.expr, null, errors, allocator);
            }
            if (ast.dereference.expr.* == .poison) {
                return ast.enpoison();
            }
            const expr_type = ast.dereference.expr.typeof(allocator);
            const expanded_expr_type = expr_type.expand_type(allocator);
            if (expanded_expr_type.* != .addrOf) {
                // TODO: Got?
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected an address" } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        ._try => {
            const expr_span = ast._try.expr.getToken().span;
            ast._try.expr = validateAST(ast._try.expr, null, errors, allocator);
            if (ast._try.expr.* == .poison) {
                return ast.enpoison();
            }
            var expr_expanded_type = ast._try.expr.typeof(allocator).expand_type(allocator);
            if (expr_expanded_type.* != .sum or !expr_expanded_type.sum.was_error) {
                // expr is not even an error type
                // TODO: What type is it?
                errors.addError(errs_.Error{ .basic = .{ .span = expr_span, .msg = "not an error expression" } });
                return ast.enpoison();
            }
            try type_check(ast, expr_expanded_type.get_ok_type().annotation.type, expected, errors);
            const expanded_function_return = ast._try.function.?._type.function.rhs.expand_type(allocator);
            if (expanded_function_return.* == .inferred_error) {
                // This checks that the `ok` fields match, for free!
                for (expr_expanded_type.sum.terms.items) |term| {
                    try add_term(expanded_function_return, term, errors);
                }
            } else if (expanded_function_return.* != .sum or !expanded_function_return.sum.was_error) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "enclosing function around try expression does not return an error" } });
                return ast.enpoison();
            } else if (!expr_expanded_type.sum.terms.items[1].annotation.type.typesMatch(expanded_function_return.sum.terms.items[1].annotation.type)) {
                // MASSIVE TODO: Check ALL sum terms, not just the first one
                // expr error union's `.err` member is not a compatible type with the function's error type
                errors.addError(errs_.Error{ .expected2Type = .{ .span = expr_span, .expected = expr_expanded_type, .got = expanded_function_return } });
                return ast.enpoison();
            }
            return ast;
        },
        .discard => {
            ast.discard.expr = validateAST(ast.discard.expr, null, errors, allocator);
            if (ast.discard.expr.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.unit_type, expected, errors);
            return ast;
        },
        .domainOf => {
            ast.domainOf.sum_expr = validateAST(ast.domainOf.sum_expr, primitives_.type_type, errors, allocator);
            if (ast.domainOf.sum_expr.* == .poison) {
                return ast.enpoison();
            }
            return try domainof(ast.domainOf.expr, ast.domainOf.sum_expr, errors, allocator);
        },
        ._typeOf => {
            ast._typeOf.expr = validateAST(ast._typeOf.expr, null, errors, allocator);
            if (ast._typeOf.expr.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast._typeOf.expr.typeof(allocator);
        },
        .default => {
            ast.default.expr = validateAST(ast.default.expr, primitives_.type_type, errors, allocator);
            if (ast.default.expr.* == .poison) {
                return ast.enpoison();
            }
            const ast_type = ast.typeof(allocator);
            try type_check(ast, ast_type, expected, errors);
            return generate_default(ast_type, errors, allocator);
        },
        .sizeOf => {
            ast.sizeOf.expr = validateAST(ast.sizeOf.expr, primitives_.type_type, errors, allocator);
            if (ast.sizeOf.expr.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.int_type, expected, errors);
            return ast_.AST.createInt(ast.getToken(), ast.sizeOf.expr.expand_type(allocator).sizeof(), allocator);
        },
        ._comptime => {
            // Validate symbol
            try validateSymbol(ast._comptime.symbol.?, errors, allocator); // ast._comptime.symbol.? is created during symbol tree expansion
            if (ast._comptime.symbol.?._type.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, ast._comptime.symbol.?._type.function.rhs, expected, errors);

            // Get the cfg from the symbol, and embed into the module
            const cfg = try ast._comptime.symbol.?.get_cfg(null, &ast._comptime.symbol.?.scope.module.?.interned_strings, errors, allocator);
            defer cfg.deinit(); // Remove the cfg so that it isn't output

            const idx = ast._comptime.symbol.?.scope.module.?.append_instructions(cfg);
            defer ast._comptime.symbol.?.scope.module.?.pop_cfg(idx); // Remove the cfg so that it isn't output

            // Create a context and interpret
            const ret_type = ast._comptime.symbol.?._type.function.rhs.expand_type(allocator);
            var context = interpreter_.Context.init(cfg, &ast._comptime.symbol.?.scope.module.?.instructions, ret_type, cfg.offset.?);
            try context.interpret();

            // Extract the retval
            return context.extract_ast(0, ret_type, allocator);
        },
        .assign => {
            ast.assign.lhs = validateAST(ast.assign.lhs, null, errors, allocator);
            try validateLValue(ast.assign.lhs, errors);
            const lhs_type = ast.assign.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.assign.rhs = validateAST(ast.assign.rhs, lhs_type, errors, allocator);
            if (ast.assign.lhs.* == .poison or ast.assign.rhs.* == .poison) {
                return ast.enpoison();
            }
            try assertMutable(ast.assign.lhs, errors, allocator);
            try type_check(ast, primitives_.unit_type, expected, errors);
            return ast;
        },
        ._or => {
            ast._or.lhs = validateAST(ast._or.lhs, primitives_.bool_type, errors, allocator);
            ast._or.rhs = validateAST(ast._or.rhs, primitives_.bool_type, errors, allocator);
            if (ast._or.lhs.* == .poison or ast._or.rhs.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        ._and => {
            ast._and.lhs = validateAST(ast._and.lhs, primitives_.bool_type, errors, allocator);
            ast._and.rhs = validateAST(ast._and.rhs, primitives_.bool_type, errors, allocator);
            if (ast._and.lhs.* == .poison or ast._and.rhs.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .add => {
            ast.add.lhs = validateAST(ast.add.lhs, expected, errors, allocator);
            const lhs_type = ast.add.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.add.rhs = validateAST(ast.add.rhs, lhs_type, errors, allocator);
            if (ast.add.lhs.* == .poison or ast.add.rhs.* == .poison) {
                return ast.enpoison();
            }

            try type_check_arithmetic(ast, lhs_type, errors);
            try type_check(ast, lhs_type, expected, errors);
            return ast;
        },
        .sub => {
            ast.sub.lhs = validateAST(ast.sub.lhs, expected, errors, allocator);
            const lhs_type = ast.sub.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.sub.rhs = validateAST(ast.sub.rhs, lhs_type, errors, allocator);
            if (ast.sub.lhs.* == .poison or ast.sub.rhs.* == .poison) {
                return ast.enpoison();
            }

            try type_check_arithmetic(ast, lhs_type, errors);
            try type_check(ast, lhs_type, expected, errors);
            return ast;
        },
        .mult => {
            ast.mult.lhs = validateAST(ast.mult.lhs, expected, errors, allocator);
            const lhs_type = ast.mult.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.mult.rhs = validateAST(ast.mult.rhs, lhs_type, errors, allocator);
            if (ast.mult.lhs.* == .poison or ast.mult.rhs.* == .poison) {
                return ast.enpoison();
            }

            try type_check_arithmetic(ast, lhs_type, errors);
            try type_check(ast, lhs_type, expected, errors);
            return ast;
        },
        .div => {
            ast.div.lhs = validateAST(ast.div.lhs, expected, errors, allocator);
            const lhs_type = ast.div.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.div.rhs = validateAST(ast.div.rhs, lhs_type, errors, allocator);
            if (ast.div.lhs.* == .poison or ast.div.rhs.* == .poison) {
                return ast.enpoison();
            }

            try type_check_arithmetic(ast, lhs_type, errors);
            try type_check(ast, lhs_type, expected, errors);
            return ast;
        },
        .mod => {
            // TODO: Assert integer type
            ast.mod.lhs = validateAST(ast.mod.lhs, null, errors, allocator);
            const lhs_type = ast.mod.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.mod.rhs = validateAST(ast.mod.rhs, lhs_type, errors, allocator);

            if (ast.mod.lhs.* == .poison or ast.mod.rhs.* == .poison) {
                return ast.enpoison();
            }
            try type_check_integral(ast, lhs_type, errors);
            try type_check(ast, lhs_type, expected, errors);
            return ast;
        },
        .equal => {
            ast.equal.lhs = validateAST(ast.equal.lhs, null, errors, allocator);
            var lhs_type = ast.equal.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.equal.rhs = validateAST(ast.equal.rhs, lhs_type, errors, allocator);
            if (ast.equal.lhs.* == .poison or ast.equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            const expanded_lhs_type = lhs_type.expand_type(allocator);
            if (primitives_.type_type.typesMatch(expanded_lhs_type)) {
                if (!ast.equal.lhs.typesMatch(ast.equal.rhs)) {
                    return ast_.AST.createFalse(ast.getToken(), allocator);
                } else if (!ast.equal.rhs.typesMatch(ast.equal.lhs)) {
                    return ast_.AST.createFalse(ast.getToken(), allocator);
                } else {
                    return ast_.AST.createTrue(ast.getToken(), allocator);
                }
            }
            try type_check_eq(ast, lhs_type, errors);
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .not_equal => {
            ast.not_equal.lhs = validateAST(ast.not_equal.lhs, null, errors, allocator);
            var lhs_type = ast.not_equal.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.not_equal.rhs = validateAST(ast.not_equal.rhs, lhs_type, errors, allocator);
            if (ast.not_equal.lhs.* == .poison or ast.not_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            const expanded_lhs_type = lhs_type.expand_type(allocator);
            if (primitives_.type_type.typesMatch(expanded_lhs_type)) {
                if (ast.not_equal.lhs.typesMatch(ast.not_equal.rhs)) {
                    return ast_.AST.createFalse(ast.getToken(), allocator);
                } else if (ast.not_equal.rhs.typesMatch(ast.not_equal.lhs)) {
                    return ast_.AST.createFalse(ast.getToken(), allocator);
                } else {
                    return ast_.AST.createTrue(ast.getToken(), allocator);
                }
            }
            try type_check_eq(ast, lhs_type, errors);
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .greater => {
            ast.greater.lhs = validateAST(ast.greater.lhs, null, errors, allocator);
            const lhs_type = ast.greater.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.greater.rhs = validateAST(ast.greater.rhs, lhs_type, errors, allocator);
            if (ast.greater.lhs.* == .poison or ast.greater.rhs.* == .poison) {
                return ast.enpoison();
            }

            try type_check_ord(ast, lhs_type, errors);
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .lesser => {
            ast.lesser.lhs = validateAST(ast.lesser.lhs, null, errors, allocator);
            const lhs_type = ast.lesser.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.lesser.rhs = validateAST(ast.lesser.rhs, lhs_type, errors, allocator);
            if (ast.lesser.lhs.* == .poison or ast.lesser.rhs.* == .poison) {
                return ast.enpoison();
            }

            try type_check_ord(ast, lhs_type, errors);
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .greater_equal => {
            ast.greater_equal.lhs = validateAST(ast.greater_equal.lhs, null, errors, allocator);
            const lhs_type = ast.greater_equal.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.greater_equal.rhs = validateAST(ast.greater_equal.rhs, lhs_type, errors, allocator);
            if (ast.greater_equal.lhs.* == .poison or ast.greater_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            try type_check_ord(ast, lhs_type, errors);
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .lesser_equal => {
            ast.lesser_equal.lhs = validateAST(ast.lesser_equal.lhs, null, errors, allocator);
            const lhs_type = ast.lesser_equal.lhs.typeof(allocator);
            if (lhs_type.* == .poison) {
                return ast.enpoison();
            }
            ast.lesser_equal.rhs = validateAST(ast.lesser_equal.rhs, lhs_type, errors, allocator);
            if (ast.lesser_equal.lhs.* == .poison or ast.lesser_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            try type_check_ord(ast, lhs_type, errors);
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        ._catch => {
            ast._catch.lhs = validateAST(ast._catch.lhs, null, errors, allocator);
            ast._catch.rhs = validateAST(ast._catch.rhs, expected, errors, allocator);
            if (ast._catch.lhs.* == .poison or ast._catch.rhs.* == .poison) {
                return ast.enpoison();
            }

            var lhs_expanded_type = ast._catch.lhs.typeof(allocator).expand_type(allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_error) {
                // TODO: What is it?
                errors.addError(errs_.Error{ .basic = .{ .span = ast._catch.lhs.getToken().span, .msg = "left-hand side of catch is not an error type" } });
                return ast.enpoison();
            }
            try type_check(ast, lhs_expanded_type.get_ok_type().annotation.type, expected, errors);
            return ast;
        },
        ._orelse => {
            ast._orelse.lhs = validateAST(ast._orelse.lhs, null, errors, allocator);
            ast._orelse.rhs = validateAST(ast._orelse.rhs, expected, errors, allocator);
            if (ast._orelse.lhs.* == .poison or ast._orelse.rhs.* == .poison) {
                return ast.enpoison();
            }

            var lhs_expanded_type = ast._orelse.lhs.typeof(allocator).expand_type(allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_optional) {
                // TODO: What type is it?
                errors.addError(errs_.Error{ .basic = .{ .span = ast._orelse.lhs.getToken().span, .msg = "left-hand side of orelse is not an optional type" } });
                return ast.enpoison();
            }
            try type_check(ast, lhs_expanded_type.get_some_type().annotation.type, expected, errors);
            return ast;
        },
        .call => {
            ast.call.lhs = validateAST(ast.call.lhs, null, errors, allocator);
            if (ast.call.lhs.* == .poison) {
                return ast.enpoison();
            }
            var lhs_type = ast.call.lhs.typeof(allocator);
            const expanded_lhs_type = lhs_type.expand_identifier();
            if (expanded_lhs_type.* != .function) {
                // TODO: Emit expanded_lhs_type for user
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "call is not to a function" } });
                return ast.enpoison();
            }

            ast.call.args = try default_args(ast.call.args, expanded_lhs_type.function.lhs, errors, allocator);
            ast.call.args = try validate_args(ast.call.args, expanded_lhs_type.function.lhs, ast.getToken().span, errors, allocator);
            try type_check(ast, expanded_lhs_type.function.rhs, expected, errors);
            return ast;
        },
        .index => { // TODO: TOO LONG!
            const lhs_span = ast.index.lhs.getToken().span; // Used for error reporting
            if (expected != null and primitives_.type_type.typesMatch(expected.?)) {
                ast.index.lhs = validateAST(ast.index.lhs, primitives_.type_type, errors, allocator);
            } else {
                ast.index.lhs = validateAST(ast.index.lhs, null, errors, allocator);
            }
            ast.index.rhs = validateAST(ast.index.rhs, primitives_.int_type, errors, allocator);
            if (ast.index.lhs.* == .poison or ast.index.rhs.* == .poison) {
                return ast.enpoison();
            }

            var lhs_type = ast.index.lhs.typeof(allocator);
            if (lhs_type.* == .addrOf) {
                // Implicit dereference
                ast.index.lhs = validateAST(ast_.AST.createDereference(ast.getToken(), ast.index.lhs, allocator), null, errors, allocator);
                lhs_type = ast.index.lhs.typeof(allocator);
                if (ast.index.lhs.* == .poison) {
                    return ast.enpoison();
                }
            } else if (lhs_type.* == .poison) {
                return ast.enpoison();
            }

            const lhs_expanded_type = lhs_type.expand_type(allocator);
            if (lhs_type.typesMatch(primitives_.type_type) and ast.index.lhs.* == .product and ast.index.rhs.* == .int and ast.index.lhs.product.terms.items.len > ast.index.rhs.int.data) {
                // Index a product type, resolve immediately
                // TODO: Perhaps add a pattern-index type that's only used by patterns, gauranteed to be infallible
                return ast.index.lhs.product.terms.items[@as(usize, @intCast(ast.index.rhs.int.data))];
            } else if (lhs_expanded_type.* != .product) {
                errors.addError(errs_.Error{ .notIndexable = .{ .span = lhs_span, ._type = lhs_expanded_type } });
                return ast.enpoison();
            } else if (lhs_expanded_type.* == .product and !lhs_expanded_type.product.was_slice and !lhs_expanded_type.product.is_homotypical()) {
                if (ast.index.rhs.* == .int) {
                    // rhs is compile-time known, change to select
                    var select = ast_.AST.createSelect(ast.getToken(), ast.index.lhs, ast_.AST.createIdentifier(token_.Token.init("homotypical index", .IDENTIFIER, "", "", 0, 0), allocator), allocator).assert_valid();
                    select.select.pos = @as(usize, @intCast(ast.index.rhs.int.data));
                    return select;
                } else {
                    // rhs is not int, error
                    errors.addError(errs_.Error{ .basic = .{ .span = lhs_span, .msg = "array is not homotypical and index is not compile-time known" } });
                    return ast.enpoison();
                }
            } else if (expected != null) {
                if (lhs_expanded_type.* == .product and !lhs_expanded_type.product.was_slice) {
                    try type_check(ast, lhs_expanded_type.product.terms.items[0], expected, errors);
                } else if (lhs_expanded_type.* == .product and lhs_expanded_type.product.was_slice) {
                    try type_check(ast, lhs_expanded_type.product.terms.items[0].annotation.type.addrOf.expr, expected, errors);
                }
            }
            return ast;
        },
        .select => { // TODO: Too long!
            ast.select.lhs = validateAST(ast.select.lhs, null, errors, allocator);
            if (ast.select.lhs.* == .poison) {
                return ast.enpoison();
            }

            var lhs_type = ast.select.lhs.typeof(allocator);
            var select_lhs_type = lhs_type.expand_type(allocator);

            // Implicit dereference
            if (select_lhs_type.* == .addrOf) {
                ast.select.lhs = validateAST(ast_.AST.createDereference(ast.getToken(), ast.select.lhs, allocator), null, errors, allocator);
                select_lhs_type = ast.select.lhs.typeof(allocator).expand_type(allocator);
                if (ast.select.lhs.* == .poison) {
                    return ast.enpoison();
                }
            }

            if (select_lhs_type.typesMatch(primitives_.type_type) and ast.select.lhs.expand_type(allocator).* == .sum) {
                // Select on a Type (only valid for a sum type), change to inferred-member
                const inferred_member = ast_.AST.createInferredMember(ast.getToken(), ast.select.rhs, allocator);
                return validateAST(inferred_member, ast.select.lhs, errors, allocator);
            } else {
                // Select on something annot-list-like, get the pos
                var annot_list: *std.ArrayList(*ast_.AST) = undefined;
                if (select_lhs_type.* == .product) {
                    annot_list = &select_lhs_type.product.terms;
                } else if (select_lhs_type.* == .sum) {
                    annot_list = &select_lhs_type.sum.terms;
                } else if (select_lhs_type.* == .inferred_error) {
                    annot_list = &select_lhs_type.inferred_error.terms;
                } else {
                    errors.addError(errs_.Error{ .basic = .{
                        .span = ast.getToken().span,
                        .msg = "left-hand-side of select is not selectable",
                    } });
                    return ast.enpoison();
                }
                if (ast.select.pos == null) {
                    for (annot_list.items, 0..) |term, i| {
                        if (term.* != .annotation) {
                            errors.addError(errs_.Error{ .basic = .{
                                .span = ast.getToken().span,
                                .msg = "left-hand-side of select is not selectable",
                            } });
                            return ast.enpoison();
                        }
                        if (std.mem.eql(u8, term.annotation.pattern.getToken().data, ast.select.rhs.getToken().data)) {
                            ast.select.pos = i;
                            break;
                        }
                    } else {
                        errors.addError(errs_.Error{ .member_not_in = .{
                            .span = ast.getToken().span,
                            .identifier = ast.select.rhs.getToken().data,
                            .group_name = "tuple",
                        } });
                        return ast.enpoison();
                    }
                }
            }

            _ = ast.assert_valid();
            const ast_type = ast.typeof(allocator);
            try type_check(ast, ast_type, expected, errors);
            return ast;
        },
        .function => {
            ast.function.lhs = validateAST(ast.function.lhs, primitives_.type_type, errors, allocator);
            ast.function.rhs = validateAST(ast.function.rhs, primitives_.type_type, errors, allocator);
            if (ast.function.lhs.* == .poison or ast.function.rhs.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .sum => {
            var poisoned = false;
            var changed = false;
            var new_terms = std.ArrayList(*ast_.AST).init(allocator);
            var idents_seen = std.StringArrayHashMap(*ast_.AST).init(allocator);
            defer idents_seen.deinit();
            for (ast.sum.terms.items) |term| {
                std.debug.assert(term.* == .annotation); // sums are expanded in sum-expand.zig
                const new_term = validateAST(term, primitives_.type_type, errors, allocator);
                changed = changed or new_term != term;
                new_terms.append(new_term) catch unreachable;
                if (new_term.* == .poison) {
                    poisoned = true;
                }
            }
            if (poisoned) {
                return ast.enpoison();
            } else if (changed) {
                ast.sum.terms = new_terms;
            } else {
                new_terms.deinit();
            }
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .inferred_error => {
            // Inferred errors are expanded after the node is validated. They should only have one term, the `ok` term
            std.debug.assert(ast.inferred_error.terms.items.len == 1);
            ast.inferred_error.terms.items[0] = validateAST(ast.inferred_error.terms.items[0], primitives_.type_type, errors, allocator);
            if (ast.inferred_error.terms.items[0].* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .inject => {
            if (expected != null and expected.?.* == .inferred_error) {
                ast.inject.lhs.inferredMember.init = validateAST(ast.inject.rhs, null, errors, allocator);
                ast.inject.lhs = validateAST(ast.inject.lhs, expected, errors, allocator);
                ast.inject.lhs.inferredMember.base = expected;
                if (ast.inject.lhs.inferredMember.init.?.* == .poison) {
                    return ast.enpoison();
                }
                _ = ast.assert_valid();
                return ast.inject.lhs;
            } else {
                const domain = try domainof(ast, expected, errors, allocator);
                if (domain.* == .poison) {
                    return ast.enpoison();
                }
                ast.inject.lhs.inferredMember.init = validateAST(ast.inject.rhs, domain, errors, allocator);
                if (ast.inject.lhs.inferredMember.init.?.* == .poison) {
                    return ast.enpoison();
                }
                _ = ast.assert_valid();
                return ast.inject.lhs;
            }
        },

        .product => { // TODO: TOO LONG!
            var poisoned = false;
            var changed = false;
            var new_terms = std.ArrayList(*ast_.AST).init(allocator);
            var expanded_expected: ?*ast_.AST = if (expected == null) null else expected.?.expand_type(allocator);

            if (expanded_expected != null and expanded_expected.?.* == .product) {
                _ = ast.assert_valid();
                ast.product.terms = try default_args(ast.product.terms, expanded_expected.?, errors, allocator);
            }

            if (expanded_expected != null and expanded_expected.?.typesMatch(primitives_.type_type)) {
                // Expecting ast to be a product type
                for (ast.product.terms.items) |term| {
                    const new_term = validateAST(term, primitives_.type_type, errors, allocator);
                    changed = changed or new_term != term;
                    new_terms.append(new_term) catch unreachable;
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
            } else if (expanded_expected != null and expanded_expected.?.* == .product) {
                // Expecting ast to be a product value
                if (expanded_expected.?.product.terms.items.len != ast.product.terms.items.len) {
                    errors.addError(errs_.Error{ .mismatchTupleArity = .{
                        .span = ast.getToken().span,
                        .takes = expanded_expected.?.product.terms.items.len,
                        .given = ast.product.terms.items.len,
                    } });
                    return ast.enpoison();
                }
                for (ast.product.terms.items, expanded_expected.?.product.terms.items) |term, expected_term| { // Ok, this is cool!
                    const new_term = validateAST(term, expected_term, errors, allocator);
                    changed = changed or new_term != term;
                    new_terms.append(new_term) catch unreachable;
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
            } else if (expanded_expected == null) {
                // Not expecting anything
                for (ast.product.terms.items) |term| {
                    const new_term = validateAST(term, null, errors, allocator);
                    new_terms.append(new_term) catch unreachable;
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
            } else {
                // not expecting a type nor a product!
                // poison `got`, so that it doesn't print anything for the `got` section, wouldn't make sense anyway
                errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast_.poisoned } });
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
        ._union => { // TODO: TOO LONG
            // Save spans since lhs and rhs are expanded, need spans for errors
            const lhs_span = ast._union.lhs.getToken().span;
            const rhs_span = ast._union.rhs.getToken().span;

            ast._union.lhs = validateAST(ast._union.lhs, primitives_.type_type, errors, allocator);
            ast._union.rhs = validateAST(ast._union.rhs, primitives_.type_type, errors, allocator);
            if (ast._union.lhs.* == .poison or ast._union.rhs.* == .poison) {
                return ast.enpoison();
            }

            const expand_lhs = ast._union.lhs.expand_type(allocator);
            const expand_rhs = ast._union.rhs.expand_type(allocator);
            if (expand_lhs.* != .sum) {
                errors.addError(errs_.Error{ .basic = .{ .span = lhs_span, .msg = "left hand side of union is not a sum type" } });
                return ast.enpoison();
            } else if (expand_rhs.* != .sum) {
                errors.addError(errs_.Error{ .basic = .{ .span = rhs_span, .msg = "right hand side of union is not a sum type" } });
                return ast.enpoison();
            }

            try type_check(ast, primitives_.type_type, expected, errors);

            var new_terms = std.ArrayList(*ast_.AST).init(allocator);
            var names = std.StringArrayHashMap(*ast_.AST).init(allocator);
            defer names.deinit();

            for (expand_lhs.sum.terms.items) |term| {
                try putAnnotation(term, &names, errors);
                new_terms.append(term) catch unreachable;
            }
            for (expand_rhs.sum.terms.items) |term| {
                try putAnnotation(term, &names, errors);
                new_terms.append(term) catch unreachable;
            }

            var retval = ast_.AST.createSum(ast.getToken(), new_terms, allocator);
            if (expand_lhs.sum.was_error) {
                retval.sum.was_error = true;
            }
            return retval;
        },
        .addrOf => {
            if (expected == null) {
                // Not expecting anything, just validate expr
                ast.addrOf.expr = validateAST(ast.addrOf.expr, null, errors, allocator);
                if (ast.addrOf.expr.* == .poison) {
                    return ast.enpoison();
                }
                try validateLValue(ast.addrOf.expr, errors);
            } else if (primitives_.type_type.typesMatch(expected.?)) {
                // Address type, type of this ast must be a type, inner must be a type
                ast.addrOf.expr = validateAST(ast.addrOf.expr, primitives_.type_type, errors, allocator);
                if (ast.addrOf.expr.* == .poison) {
                    return ast.enpoison();
                }
            } else {
                // Address value, expected must be an address, inner must match with expected's inner
                const expanded_expected = expected.?.expand_type(allocator); // Call is memoized
                if (expanded_expected.* != .addrOf) {
                    // Didn't expect an address type. Validate expr and report error
                    errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast_.poisoned } });
                    return error.typeError;
                }

                // Everythings Ok.
                ast.addrOf.expr = validateAST(ast.addrOf.expr, expanded_expected.addrOf.expr, errors, allocator);
                if (ast.addrOf.expr.* == .poison) {
                    return ast.enpoison();
                }
                _ = ast.assert_valid();
                if (ast.addrOf.expr.* != .product) {
                    // Validate that expr is an L-value *only if* expr is not a product
                    // It is possible to take a addr of a product. The address is the address of the temporary
                    // This is mirrored with a slice_of a product.
                    try validateLValue(ast.addrOf.expr, errors);
                }
                if (ast.addrOf.mut) {
                    try assertMutable(ast.addrOf.expr, errors, allocator);
                }
            }

            return ast;
        },
        .sliceOf => {
            ast.sliceOf.expr = validateAST(ast.sliceOf.expr, null, errors, allocator);
            if (ast.sliceOf.expr.* == .poison) {
                return ast.enpoison();
            }
            var expr_type = ast.sliceOf.expr.typeof(allocator);

            if (expr_type.* != .unit_type and primitives_.type_type.typesMatch(expr_type)) {
                // Regular slice type, change to product of data address and length
                return ast_.AST.create_slice_type(ast.sliceOf.expr, ast.sliceOf.kind == .MUT, allocator);
            } else { // Slice-of value, expected must be an slice, inner must match with expected's inner
                // ast.sliceOf.expr must be homotypical product type of expected
                if (expr_type.* != .product or !expr_type.product.is_homotypical()) {
                    errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "attempt to take slice-of something that is not an array" } });
                    return ast.enpoison();
                }

                _ = ast.assert_valid();
                const ast_type = ast.typeof(allocator);
                try type_check(ast, ast_type, expected, errors);

                if (ast.sliceOf.expr.* != .product) {
                    // Validate that expr is an L-value *only if* expr is not a product
                    // It is possible to take a slice of a product. The slice is the sliceof the temporary
                    // This is mirrored with addr_of a product.
                    try validateLValue(ast.sliceOf.expr, errors);
                }
                if (ast.sliceOf.kind == .MUT) {
                    try assertMutable(ast.sliceOf.expr, errors, allocator);
                }
                return ast_.AST.create_slice_value(ast.sliceOf.expr, ast.sliceOf.kind == .MUT, expr_type, allocator);
            }
        },
        .arrayOf => {
            ast.arrayOf.expr = validateAST(ast.arrayOf.expr, primitives_.type_type, errors, allocator);
            if (ast.arrayOf.expr.* == .poison) {
                return ast.enpoison();
            }

            try type_check(ast, primitives_.type_type, expected, errors);

            // Array-of type, type of this ast must be a type, inner must be a type
            ast.arrayOf.len = validateAST(ast.arrayOf.len, primitives_.int_type, errors, allocator);
            if (ast.arrayOf.len.* == .poison) {
                return ast.enpoison();
            }
            if (ast.arrayOf.len.* != .int) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "not integer literal" } });
                return ast.enpoison();
            }
            if (ast.arrayOf.len.int.data <= 0) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "array length is negative" } });
                return ast.enpoison();
            }
            return ast_.AST.create_array_type(ast.arrayOf.len, ast.arrayOf.expr, allocator);
        },
        .subSlice => { // TODO: TOO LONG
            ast.subSlice.super = validateAST(ast.subSlice.super, null, errors, allocator);
            if (ast.subSlice.super.* == .poison) {
                return ast.enpoison();
            }
            const super_type = ast.subSlice.super.typeof(allocator);
            if (super_type.* != .product or !super_type.product.was_slice) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot take a sub-slice of something that is not a slice" } });
                return ast.enpoison();
            }

            if (ast.subSlice.lower) |lower| {
                ast.subSlice.lower = validateAST(lower, primitives_.int_type, errors, allocator);
            } else {
                ast.subSlice.lower = ast_.AST.createInt(ast.getToken(), 0, allocator);
                _ = ast.subSlice.lower.?.assert_valid();
            }
            if (ast.subSlice.upper) |upper| {
                ast.subSlice.upper = validateAST(upper, primitives_.int_type, errors, allocator);
            } else {
                const length = (ast_.AST.createIdentifier(token_.Token.init("length", null, "", "", 0, 0), allocator)).assert_valid();
                const index = ast_.AST.createSelect(
                    ast.getToken(),
                    ast.subSlice.super,
                    length,
                    allocator,
                );
                ast.subSlice.upper = validateAST(index, primitives_.int_type, errors, allocator);
            }
            if (ast.subSlice.lower.?.* == .poison or ast.subSlice.upper.?.* == .poison) {
                return ast.enpoison();
            }
            return ast;
        },
        .annotation => {
            ast.annotation.type = validateAST(ast.annotation.type, primitives_.type_type, errors, allocator);
            if (ast.annotation.type.* == .poison) {
                return ast.enpoison();
            }
            if (ast.annotation.init != null) {
                ast.annotation.init = validateAST(ast.annotation.init.?, ast.annotation.type, errors, allocator);
            }
            if (ast.annotation.init != null and ast.annotation.init.?.* == .poison) {
                return ast.enpoison();
            }
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .inferredMember => { // TODO: TOO LONG!
            var expected_expanded: *ast_.AST = undefined;
            if (expected != null) {
                expected_expanded = expected.?.expand_type(allocator);
            }

            if (expected == null) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot infer the sum type" } });
                return ast.enpoison();
            } else if (expected_expanded.* == .inferred_error) {
                ast.inferredMember.base = expected;
                ast.inferredMember.pos = expected_expanded.inferred_error.get_pos(ast.inferredMember.ident.getToken().data);
                if (ast.inferredMember.pos == null) {
                    // Wasn't in inferred error set, put in inferred error set
                    const annot_type = if (ast.inferredMember.init == null) primitives_.unit_type else ast.inferredMember.init.?.typeof(allocator);
                    const annot = ast_.AST.createAnnotation(ast.getToken(), ast_.AST.createIdentifier(ast.inferredMember.ident.getToken(), allocator), annot_type, null, null, allocator);
                    expected_expanded.inferred_error.terms.append(annot) catch unreachable;
                    ast.inferredMember.pos = expected_expanded.inferred_error.terms.items.len - 1;
                }
                return ast;
            } else if (expected_expanded.* != .sum) {
                errors.addError(errs_.Error{ .expectedGotString = .{ .span = ast.getToken().span, .expected = expected.?, .got = "an inferred member" } });
                return ast.enpoison();
            } else {
                ast.inferredMember.base = expected;
                ast.inferredMember.pos = expected_expanded.sum.get_pos(ast.inferredMember.ident.getToken().data) orelse {
                    errors.addError(errs_.Error{ .member_not_in = .{ .span = ast.getToken().span, .identifier = ast.inferredMember.ident.getToken().data, .group_name = "sum" } });
                    return ast.enpoison();
                };
                const proper_term: *ast_.AST = expected_expanded.sum.terms.items[@as(usize, @intCast(ast.inferredMember.pos.?))];
                if (proper_term.annotation.init) |_init| {
                    ast.inferredMember.init = _init; // This will be overriden by an inject expression's rhs
                } else {
                    ast.inferredMember.init = try generate_default(proper_term, errors, allocator);
                }
                return ast;
            }
        },
        ._if => { // TODO: TOO LONG!
            if (ast._if.let) |let| {
                ast._if.let = validateAST(let, null, errors, allocator);
            }

            ast._if.condition = validateAST(ast._if.condition, primitives_.bool_type, errors, allocator);
            if (ast._if.condition.* == .poison) {
                return ast.enpoison();
            }

            // expecting a type
            const has_else = ast._if.elseBlock != null;
            var expected_type: ?*ast_.AST = undefined;
            var expected_expanded: *ast_.AST = undefined;
            if (expected == null) {
                expected_type = null;
            } else {
                expected_expanded = expected.?.expand_type(allocator);
                const is_expected_optional = expected_expanded.* == .sum and expected_expanded.sum.was_optional;
                if (has_else) {
                    expected_type = expected.?;
                } else if (is_expected_optional) {
                    expected_type = expected_expanded.get_some_type();
                } else {
                    errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast_.poisoned } });
                    return error.typeError;
                }
            }

            if (ast._if.condition.* != ._false) {
                ast._if.bodyBlock = validateAST(ast._if.bodyBlock, expected_type, errors, allocator);
            }

            if (has_else and ast._if.condition.* != ._true) {
                ast._if.elseBlock = validateAST(ast._if.elseBlock.?, expected_type, errors, allocator);
            }

            if ((ast._if.let != null and ast._if.let.?.* == .poison) or
                ast._if.bodyBlock.* == .poison or
                (ast._if.elseBlock != null and ast._if.elseBlock.?.* == .poison))
            {
                return ast.enpoison();
            }

            if (ast._if.condition.* == ._true and ast._if.elseBlock != null) {
                // condition is true and theres an else => return {let; body}
                if (ast._if.let != null) {
                    ast._if.bodyBlock.block.statements.insert(0, ast._if.let.?) catch unreachable;
                }
                return ast._if.bodyBlock;
            } else if (ast._if.condition.* == ._true and ast._if.elseBlock == null) {
                // condition is true and theres no else => return {let; some(body)}
                if (ast._if.let != null) {
                    ast._if.bodyBlock.block.statements.insert(0, ast._if.let.?) catch unreachable;
                }
                const opt_type = ast_.AST.create_optional_type(ast._if.bodyBlock.typeof(allocator), allocator);
                return ast_.AST.create_some_value(opt_type, ast._if.bodyBlock, allocator);
            } else if (ast._if.condition.* == ._false and ast._if.elseBlock != null) {
                // condition is false and theres an else => return {let; else}
                if (ast._if.let != null) {
                    ast._if.elseBlock.?.block.statements.insert(0, ast._if.let.?) catch unreachable;
                }
                return ast._if.elseBlock.?;
            } else if (ast._if.condition.* == ._false and ast._if.elseBlock == null) {
                // condition is false and theres no else => return {let; none()}
                const opt_type = ast_.AST.create_optional_type(ast._if.bodyBlock.typeof(allocator), allocator);
                var statements = std.ArrayList(*ast_.AST).init(allocator);
                if (ast._if.let != null) {
                    statements.append(ast._if.let.?) catch unreachable;
                }
                statements.append(ast_.AST.create_none_value(opt_type, allocator)) catch unreachable;
                const ret_block = ast_.AST.createBlock(token_.Token.init_simple("{"), statements, null, allocator);
                ret_block.block.scope = ast._if.scope.?.parent.?;
                return ret_block;
            } else {
                // condition is undeterminable at compile-time, return if AST
                return ast;
            }
        },
        .match => { // TODO: TOO LONG!
            var poisoned = false;
            if (ast.match.let) |let| {
                ast.match.let = validateAST(let, null, errors, allocator);
                poisoned = ast.match.let.?.* == .poison or poisoned;
            }
            ast.match.expr = validateAST(ast.match.expr, null, errors, allocator);
            poisoned = ast.match.expr.* == .poison or poisoned;

            var expr_type = ast.match.expr.typeof(allocator);
            const expr_type_expanded = expr_type.expand_type(allocator);
            if (expr_type_expanded.* == .poison) {
                return ast.enpoison(); // Can't do anything with this
            }

            if (ast.match.mappings.items.len == 0) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "match has no patterns" } });
                return ast.enpoison();
            }

            // Go through mappings, get their validated form
            var changed = false;
            var new_mappings = std.ArrayList(*ast_.AST).init(allocator);
            for (ast.match.mappings.items) |mapping| {
                if (expected != null) {
                    // Expecting a type from the match
                    var expected_expanded = expected.?.expand_type(allocator);
                    const is_expected_optional = expected_expanded.* == .sum and expected_expanded.sum.was_optional;
                    const has_else = ast.match.has_else;
                    if (has_else) {
                        // match has `else` => validate regular expected type
                        const new_mapping = validateAST(mapping, expected, errors, allocator);
                        new_mappings.append(new_mapping) catch unreachable;
                        changed = changed or new_mapping != mapping;
                        poisoned = poisoned or new_mapping.* == .poison;
                    } else if (is_expected_optional) {
                        // match has no `else`, expecting an optional type => validate mappings w/ base of optional expected type
                        const full_type = expected_expanded.get_some_type();
                        const new_mapping = validateAST(mapping, full_type, errors, allocator);
                        new_mappings.append(new_mapping) catch unreachable;
                        changed = changed or new_mapping != mapping;
                        poisoned = poisoned or new_mapping.* == .poison;
                    } else {
                        // match has no else, not expecting an optional type => type error
                        // TODO: Include all that ^ in the error message (without having to asser_valid()!), because this is kinda confusing
                        // TODO: Matches should have to be exhaustive, so they would never return none :-)
                        errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast_.poisoned } });
                        return error.typeError;
                    }
                } else {
                    // Not expecting anything => validate mappings with null type
                    const new_mapping = validateAST(mapping, null, errors, allocator);
                    new_mappings.append(new_mapping) catch unreachable;
                    changed = changed or new_mapping != mapping;
                    poisoned = poisoned or new_mapping.* == .poison;
                }
                if (mapping.mapping.lhs) |lhs| {
                    try assert_pattern_matches(lhs, expr_type_expanded, errors, allocator);
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
            ast.mapping.rhs = validateAST(ast.mapping.rhs.?, expected, errors, allocator);
            if ((ast.mapping.lhs != null and ast.mapping.lhs.?.* == .poison) or ast.mapping.rhs.?.* == .poison) {
                return ast.enpoison();
            }
            return ast;
        },
        ._while => { // TODO: TOO LONG
            if (ast._while.let) |let| {
                ast._while.let = validateAST(let, null, errors, allocator);
            }
            if (ast._while.post) |post| {
                ast._while.post = validateAST(post, null, errors, allocator);
            }
            ast._while.condition = validateAST(ast._while.condition, primitives_.bool_type, errors, allocator);

            var optional_type = false; //< Set if expected is an optional type
            if (expected != null) {
                var expected_expanded = expected.?.expand_type(allocator);
                if (expected_expanded.* == .sum and expected_expanded.sum.was_optional) {
                    const full_type = expected_expanded.get_some_type();
                    ast._while.bodyBlock = validateAST(ast._while.bodyBlock, full_type, errors, allocator);
                    optional_type = true;
                }
            }
            if (!optional_type) {
                ast._while.bodyBlock = validateAST(ast._while.bodyBlock, expected, errors, allocator);
                if (ast._while.elseBlock) |elseBlock| {
                    ast._while.elseBlock = validateAST(elseBlock, expected, errors, allocator);
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
        .block => { // TODO: TOO LONG
            var changed = false;
            var poisoned = false;
            var new_statements = std.ArrayList(*ast_.AST).init(allocator);
            if (ast.block.final) |final| {
                // Has final (return, continue, break)
                for (ast.block.statements.items) |statement| {
                    const new_statement = validateAST(statement, null, errors, allocator);
                    new_statements.append(new_statement) catch unreachable;
                    poisoned = poisoned or new_statement.* == .poison;
                    changed = changed or new_statement != statement;
                }
                ast.block.final = validateAST(final, expected, errors, allocator);
                poisoned = poisoned or ast.block.final.?.* == .poison;
                if (changed) {
                    ast.block.statements = new_statements;
                } else {
                    new_statements.deinit();
                }
            } else {
                // Hasn't final
                for (ast.block.statements.items, 0..) |statement, i| {
                    const expect_type: ?*ast_.AST = if (i == ast.block.statements.items.len - 1) expected else null;
                    const new_statement = validateAST(statement, expect_type, errors, allocator);
                    new_statements.append(new_statement) catch unreachable;
                    poisoned = poisoned or new_statement.* == .poison;
                    changed = changed or new_statement != statement;
                }

                if (changed) {
                    ast.block.statements = new_statements;
                } else {
                    new_statements.deinit();
                }

                _ = ast.assert_valid(); // So that the typeof code can be reused. All children should be validated at this point
                const block_type = ast.typeof(allocator);
                try type_check(ast, block_type, expected, errors);
            }
            if (poisoned) {
                return ast.enpoison();
            } else {
                return ast;
            }
        },

        ._break, ._continue, ._unreachable => {
            try void_check(ast, expected, errors);
            return ast;
        },
        ._return => {
            if (ast._return.expr) |expr| {
                ast._return.expr = validateAST(expr, ast._return.function.?._type.function.rhs, errors, allocator);
                if (ast._return.expr.?.* == .poison) {
                    return ast.enpoison();
                }
            } else if (expected != null and (expected.?.expand_type(allocator)).* != .unit_type) {
                errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives_.void_type } });
                return error.typeError;
            }
            return ast;
        },
        ._defer => {
            ast._defer.statement = validateAST(ast._defer.statement, null, errors, allocator);
            if (ast._defer.statement.* == .poison) {
                return ast.enpoison();
            }
            try void_check(ast, expected, errors);
            return ast;
        },
        ._errdefer => {
            ast._errdefer.statement = validateAST(ast._errdefer.statement, null, errors, allocator);
            if (ast._errdefer.statement.* == .poison) {
                return ast.enpoison();
            }
            try void_check(ast, expected, errors);
            return ast;
        },
        .fnDecl => {
            try validateSymbol(ast.fnDecl.symbol.?, errors, allocator);
            if (ast.fnDecl.symbol.?._type.* == .poison) {
                return ast.enpoison();
            }
            if (expected) |_expected| {
                const expected_expanded = _expected.expand_type(allocator);
                const self_type = ast.typeof(allocator);
                try type_check(ast, self_type, expected_expanded, errors);
            }
            return ast;
        },
        .decl => {
            var poisoned = false;
            ast.decl.type = validateAST(ast.decl.type, primitives_.type_type, errors, allocator);
            if (ast.decl.type.* != .poison) {
                ast.decl.init = validateAST(ast.decl.init, ast.decl.type, errors, allocator);
                poisoned = ast.decl.init.* == .poison;
            } else {
                return ast.enpoison();
            }

            for (ast.decl.symbols.items) |symbol| {
                try validateSymbol(symbol, errors, allocator);
            }

            // statement, no type
            if (poisoned) {
                return ast.enpoison();
            } else if (expected != null and !primitives_.unit_type.typesMatch(expected.?)) {
                errors.addError(errs_.Error{ .expectedType = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast } });
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

fn type_check(ast: *ast_.AST, got: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) !void {
    if (expected != null and !got.typesMatch(expected.?)) {
        errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = got } });
        return error.typeError;
    }
}

fn void_check(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) !void {
    if (expected != null and primitives_.type_type.typesMatch(expected.?)) {
        // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
        errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives_.void_type } });
        return error.typeError;
    }
}

fn type_check_int(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) !void {
    if (expected != null and !expected.?.can_represent_integer(ast.int.data)) {
        // TODO: Add emit a separate error if not representable because the value doesn't fit, vs because it's not an integer primitive type at all
        errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives_.int_type } });
        return error.typeError;
    }
    ast.int.represents = expected orelse primitives_.int_type;
}

fn type_check_float(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) !void {
    if (expected != null and !expected.?.can_represent_float()) {
        errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives_.float_type } });
        return error.typeError;
    }
    ast.float.represents = expected orelse primitives_.float_type;
}

fn type_check_eq(ast: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) !void {
    if (!got.is_eq_type()) {
        errors.addError(errs_.Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "equalable", .got = got } });
        return error.typeError;
    }
}

fn type_check_ord(ast: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) !void {
    if (!got.is_ord_type()) {
        errors.addError(errs_.Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "orderable", .got = got } });
        return error.typeError;
    }
}

fn type_check_arithmetic(ast: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) !void {
    if (!got.is_num_type()) {
        errors.addError(errs_.Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "arithmetic", .got = got } });
        return error.typeError;
    }
}

fn type_check_integral(ast: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) !void {
    if (!got.is_int_type()) {
        errors.addError(errs_.Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "integral", .got = got } });
        return error.typeError;
    }
}

fn default_args(asts: std.ArrayList(*ast_.AST), expected: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !std.ArrayList(*ast_.AST) {
    if (try args_are_named(asts, errors)) {
        return named_args(asts, expected, errors, allocator) catch |err| switch (err) {
            error.NoDefault => asts,
            error.typeError => error.typeError,
        };
    } else {
        return positional_args(asts, expected, allocator) catch |err| switch (err) {
            error.NoDefault => asts,
        };
    }
}

fn args_are_named(asts: std.ArrayList(*ast_.AST), errors: *errs_.Errors) !bool {
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
        errors.addError(errs_.Error{ .basic = .{
            .span = asts.items[0].getToken().span,
            .msg = "mixed positional and named arguments are not allowed",
        } });
        return error.typeError;
    } else {
        return seen_named;
    }
}

fn positional_args(asts: std.ArrayList(*ast_.AST), expected: *ast_.AST, allocator: std.mem.Allocator) !std.ArrayList(*ast_.AST) {
    var retval = std.ArrayList(*ast_.AST).init(allocator);
    errdefer retval.deinit();

    switch (expected.*) {
        .annotation => {
            if (asts.items.len == 0 and expected.annotation.init != null) {
                retval.append(expected.annotation.init.?) catch unreachable;
            } else if (asts.items.len > 0) {
                for (asts.items) |item| {
                    retval.append(item) catch unreachable;
                }
            } else {
                return error.NoDefault;
            }
        },

        .product => {
            for (expected.product.terms.items, 0..) |term, i| {
                // ast is product, append ast's corresponding term
                if (asts.items.len > 1 and i < asts.items.len) {
                    retval.append(asts.items[i]) catch unreachable;
                }
                // ast is unit or ast isn't a product and i > 0 or ast is a product and off the edge of ast's terms, try to fill with the default
                else if (asts.items.len == 0 or (asts.items.len <= 1 and i > 0) or (asts.items.len > 1 and i >= asts.items.len)) {
                    if (term.* == .annotation and term.annotation.init != null) {
                        retval.append(term.annotation.init.?) catch unreachable;
                    } else {
                        return error.NoDefault;
                    }
                }
                // ast is not product, i != 0, append ast as first term
                else {
                    retval.append(asts.items[0]) catch unreachable;
                }
            }
        },

        .unit_type, .identifier => retval = asts,

        else => {
            std.debug.print("unimplemented for {s}\n", .{@tagName(expected.*)});
            unreachable;
        },
    }
    return retval;
}

fn named_args(asts: std.ArrayList(*ast_.AST), expected: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !std.ArrayList(*ast_.AST) {
    std.debug.assert(asts.items.len > 0);
    // Maps assign.lhs name to assign.rhs
    var arg_map = std.StringArrayHashMap(*ast_.AST).init(allocator);
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
    var retval = std.ArrayList(*ast_.AST).init(allocator);
    errdefer retval.deinit();
    var new_expected = expected;
    if (expected.* == .annotation and (expected.annotation.type.expand_type(allocator)).* == .product) {
        new_expected = expected.annotation.type.expand_type(allocator);
    }
    switch (new_expected.*) {
        .annotation => {
            if (arg_map.keys().len != 1) { // Cannot be 0, since that is technically a positional arglist
                errors.addError(errs_.Error{ .basic = .{
                    .span = asts.items[0].getToken().span,
                    .msg = "too many arguments/fields specifed",
                } });
                // return error.NoDefault;
                unreachable;
            } else {
                retval.append(arg_map.values()[0]) catch unreachable;
            }
        },

        .product => {
            for (new_expected.product.terms.items) |term| {
                if (term.* != .annotation) {
                    errors.addError(errs_.Error{ .basic = .{
                        .span = asts.items[0].getToken().span,
                        .msg = "expected type does not accept named arugments",
                    } });
                    return error.NoDefault;
                }
                const arg = arg_map.get(term.annotation.pattern.getToken().data);
                if (arg == null) {
                    if (term.annotation.init != null) {
                        retval.append(term.annotation.init.?) catch unreachable;
                    } else {
                        errors.addError(errs_.Error{ .basic = .{
                            .span = asts.items[0].getToken().span,
                            .msg = "not all arguments are specified",
                        } });
                        return error.NoDefault;
                    }
                } else {
                    retval.append(arg.?) catch unreachable;
                }
            }
        },

        else => unreachable,
    }
    return retval;
}

fn validate_args(args: std.ArrayList(*ast_.AST), expected: *ast_.AST, span: span_.Span, errors: *errs_.Errors, allocator: std.mem.Allocator) !std.ArrayList(*ast_.AST) {
    var new_args = std.ArrayList(*ast_.AST).init(allocator);
    errdefer new_args.deinit();
    var changed = false;
    var poisoned = false;
    if (expected.* == .unit_type) {
        if (args.items.len > 0) {
            errors.addError(errs_.Error{ .mismatchCallArity = .{
                .span = span,
                .takes = 0,
                .given = args.items.len,
            } });
            return error.typeError;
        }
    } else if (expected.* == .product) {
        if (args.items.len != expected.product.terms.items.len) {
            errors.addError(errs_.Error{ .mismatchCallArity = .{
                .span = span,
                .takes = expected.product.terms.items.len,
                .given = args.items.len,
            } });
            return error.typeError;
        }
        for (expected.product.terms.items, args.items) |param_type, arg| {
            const new_arg = validateAST(arg, param_type, errors, allocator);
            changed = changed or new_arg != arg;
            new_args.append(new_arg) catch unreachable;
            if (new_arg.* == .poison) {
                poisoned = true;
            }
        }
    } else {
        if (args.items.len != 1) {
            errors.addError(errs_.Error{ .mismatchCallArity = .{
                .span = span,
                .takes = 1,
                .given = args.items.len,
            } });
            return error.typeError;
        }

        args.items[0] = validateAST(args.items[0], expected, errors, allocator);
    }
    if (poisoned) {
        return error.typeError;
    } else if (changed) {
        return new_args;
    } else {
        new_args.deinit();
        return args;
    }
}

fn putAssign(ast: *ast_.AST, arg_map: *std.StringArrayHashMap(*ast_.AST), errors: *errs_.Errors) !void {
    if (ast.assign.lhs.* != .inferredMember) {
        errors.addError(errs_.Error{ .expectedBasicToken = .{
            .expected = "an inferred member",
            .got = ast.assign.lhs.getToken(),
        } });
        return error.typeError;
    }
    const name = ast.assign.lhs.inferredMember.ident.getToken().data;
    if (arg_map.get(name)) |_| {
        errors.addError(errs_.Error{ .basic = .{
            .span = ast.getToken().span,
            .msg = "parameter is already defined",
        } });
        return error.typeError;
    } else {
        arg_map.put(name, ast.assign.rhs) catch unreachable;
    }
}

fn putAnnotation(ast: *ast_.AST, arg_map: *std.StringArrayHashMap(*ast_.AST), errors: *errs_.Errors) !void {
    const name = ast.annotation.pattern.getToken().data;
    if (arg_map.get(name)) |_| { // TODO: Only error if the types are not identical
        errors.addError(errs_.Error{ .basic = .{
            .span = ast.getToken().span,
            .msg = "duplicate annotation identifiers detected",
        } });
        return error.typeError;
    } else {
        arg_map.put(name, ast.annotation.type) catch unreachable;
    }
}

fn validateLValue(ast: *ast_.AST, errors: *errs_.Errors) !void {
    switch (ast.*) {
        .identifier => {},

        .dereference => {
            const child = ast.dereference.expr;
            if (child.* != .addrOf) {
                try validateLValue(child, errors);
            }
        },

        .index => {
            try validateLValue(ast.index.lhs, errors);
        },

        .select => {
            try validateLValue(ast.select.lhs, errors);
        },

        .product => {
            for (ast.product.terms.items) |term| {
                try validateLValue(term, errors);
            }
        },

        else => {
            errors.addError(errs_.Error{ .basic = .{
                .span = ast.getToken().span,
                .msg = "not an l-value",
            } });
            return error.typeError;
        },
    }
}

fn assertMutable(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !void {
    switch (ast.*) {
        .identifier => {
            const symbol = ast.identifier.symbol.?;
            if (!std.mem.eql(u8, symbol.name, "_") and symbol.kind != .mut) {
                errors.addError(errs_.Error{ .modifyImmutable = .{ .identifier = ast.getToken() } });
                return error.typeError;
            }
        },

        .dereference => {
            var child = ast.dereference.expr;
            const child_type = child.typeof(allocator);
            if (!child_type.addrOf.mut) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot modify non-mutable address" } });
                return error.typeError;
            }
        },

        .index => {
            const lhs_type = ast.index.lhs.typeof(allocator);
            if (lhs_type.* == .product and lhs_type.product.was_slice) {
                const child_type = lhs_type.product.terms.items[0];
                if (!child_type.annotation.type.addrOf.mut) {
                    errors.addError(errs_.Error{ .basic = .{
                        .span = ast.getToken().span,
                        .msg = "cannot modify non-mutable address",
                    } });
                    return error.typeError;
                }
            } else {
                try assertMutable(ast.index.lhs, errors, allocator);
            }
        },

        .product => for (ast.product.terms.items) |term| {
            try assertMutable(term, errors, allocator);
        },

        .select => try assertMutable(ast.select.lhs, errors, allocator),

        else => unreachable,
    }
}

/// Validates that `pattern` is valid given a match's `expr`
fn assert_pattern_matches(pattern: *ast_.AST, expr_type: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !void {
    switch (pattern.*) {
        .unit_value => try type_check(pattern, primitives_.unit_type, expr_type, errors),
        .int => try type_check_int(pattern, expr_type, errors),
        .char => try type_check(pattern, primitives_.char_type, expr_type, errors),
        .string => try type_check(pattern, primitives_.string_type, expr_type, errors),
        .float => try type_check_float(pattern, expr_type, errors),
        ._true, ._false => try type_check(pattern, primitives_.bool_type, expr_type, errors),
        .block => {
            const new_pattern = validateAST(pattern, expr_type, errors, allocator);
            if (new_pattern.* == .poison) {
                return error.typeError;
            }
            try type_check(pattern, new_pattern.typeof(allocator), expr_type, errors);
        },
        .select => {
            var new_pattern = validateAST(pattern, expr_type, errors, allocator);
            if (new_pattern.* == .poison) {
                return error.typeError;
            }
            pattern.select.pos = @as(usize, @intCast(new_pattern.inferredMember.pos.?));
            try type_check(pattern, new_pattern.typeof(allocator), expr_type, errors);
        },
        .inferredMember => {
            var new_pattern = validateAST(pattern, expr_type, errors, allocator);
            if (new_pattern.* == .poison) {
                return error.typeError;
            }
            pattern.inferredMember.pos = new_pattern.inferredMember.pos.?;
            try type_check(pattern, new_pattern.typeof(allocator), expr_type, errors);
        },
        .inject => {
            const domain = try domainof(pattern, expr_type, errors, allocator);
            if (domain.* == .poison) {
                return error.typeError;
            }
            pattern.inject.domain = domain;
            try assert_pattern_matches(pattern.inject.rhs, domain, errors, allocator);
        },
        .product => {
            const expanded_expr = expr_type.expand_type(allocator);
            if (expanded_expr.* != .product or expanded_expr.product.terms.items.len != pattern.product.terms.items.len) {
                errors.addError(errs_.Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = pattern.typeof(allocator) } });
                return error.typeError;
            }
            for (pattern.product.terms.items, expanded_expr.product.terms.items) |term, expanded_term| {
                try assert_pattern_matches(term, expanded_term, errors, allocator);
            }
        },
        .symbol => {},
        else => {
            std.debug.print("unimplemented assert_pattern_matches() for {s}\n", .{@tagName(pattern.*)});
            unreachable;
        },
    }
    _ = pattern.assert_valid();
}

fn indexof(list: *std.ArrayList(usize), elem: usize) ?usize {
    for (list.items, 0..) |item, i| {
        if (item == elem) {
            return i;
        }
    }
    return null;
}

fn exhaustive_check(_type: *ast_.AST, mappings: *std.ArrayList(*ast_.AST), match_span: span_.Span, errors: *errs_.Errors, allocator: std.mem.Allocator) !void {
    if (_type.* == .sum) {
        var ids = std.ArrayList(usize).init(allocator);
        defer ids.deinit();

        for (_type.sum.terms.items, 0..) |_, i| {
            ids.append(i) catch unreachable;
        }
        for (mappings.items) |m| {
            if (m.mapping.lhs == null) {
                continue;
            }
            exhaustive_check_sub(m.mapping.lhs.?, &ids);
        }
        if (ids.items.len > 0) {
            var forgotten = std.ArrayList(*ast_.AST).init(std.heap.page_allocator); // Not deallocated, lifetime should be until error emission
            for (ids.items) |id| {
                forgotten.append(_type.sum.terms.items[id]) catch unreachable;
            }
            errors.addError(errs_.Error{ .nonExhaustiveSum = .{ .span = match_span, .forgotten = forgotten } });
            return error.typeError;
        }
    }
}

fn exhaustive_check_sub(ast: *ast_.AST, ids: *std.ArrayList(usize)) void {
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

/// Adds a term to an inferred error
fn add_term(ast: *ast_.AST, addend: *ast_.AST, errors: *errs_.Errors) !void {
    std.debug.assert(addend.* == .annotation);
    for (ast.inferred_error.terms.items) |term| {
        if (std.mem.eql(u8, term.annotation.pattern.getToken().data, addend.annotation.pattern.getToken().data)) {
            if (!term.annotation.type.typesMatch(term)) {
                errors.addError(errs_.Error{ .sum_duplicate = .{ .span = ast.inferred_error.common.token.span, .identifier = term.annotation.pattern.getToken().data, .first = term.getToken().span } });
                return error.typeError;
            } else {
                // Duplicate found, types match. OK!
                return;
            }
        }
    }
    // No duplicate found, add to inferred error set
    ast.inferred_error.terms.append(addend) catch unreachable;
}

fn generate_default(_type: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST {
    return (try generate_default_unvalidated(_type, errors, allocator)).assert_valid();
}

fn generate_default_unvalidated(_type: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) error{typeError}!*ast_.AST {
    switch (_type.*) {
        .identifier => {
            const expanded_type = _type.expand_type(allocator);
            if (expanded_type == _type) {
                const primitive_info = primitives_.get(_type.getToken().data);
                if (primitive_info.default_value != null) {
                    return primitive_info.default_value.?;
                } else {
                    errors.addError(errs_.Error{ .no_default = .{ .span = _type.getToken().span, ._type = _type } });
                    return error.typeError;
                }
            } else {
                return try generate_default(expanded_type, errors, allocator);
            }
        },
        .addrOf, .function => return ast_.AST.createInt(_type.getToken(), 0, allocator),
        .unit_type => return ast_.AST.createUnitValue(_type.getToken(), allocator),
        .sum => {
            var retval = ast_.AST.createInferredMember(_type.getToken(), ast_.AST.createIdentifier(token_.Token.init("default lmao", .IDENTIFIER, "", "", 0, 0), allocator), allocator);
            retval.inferredMember.pos = 0;
            retval.inferredMember.base = _type;
            const proper_term: *ast_.AST = _type.sum.terms.items[0];
            retval.inferredMember.init = try generate_default(proper_term, errors, allocator);
            return retval;
        },
        .product => {
            var value_terms = std.ArrayList(*ast_.AST).init(allocator);
            errdefer value_terms.deinit();
            for (_type.product.terms.items) |term| {
                const default_term = try generate_default(term, errors, allocator);
                value_terms.append(default_term) catch unreachable;
            }
            return ast_.AST.createProduct(_type.getToken(), value_terms, allocator);
        },
        .annotation => if (_type.annotation.init != null) {
            return _type.annotation.init.?;
        } else {
            return generate_default(_type.annotation.type, errors, allocator);
        },
        else => {
            std.debug.print("Unimplemented generate_default() for: AST.{s}\n", .{@tagName(_type.*)});
            unreachable;
        },
    }
}

// Takes in an inject AST (pattern or expr) of the form `lhs <- rhs` and returns the type that `rhs` should be.
// Also validates the inject ast_.AST. Thus, if `lhs` is an inferred member, it will find out the sum type it belongs to.
pub fn domainof(ast: *ast_.AST, sum_type: ?*ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST {
    if (ast.inject.lhs.* == .inferredMember) {
        // Pass sum_type so that base can be inferred call
        ast.inject.lhs = validateAST(ast.inject.lhs, sum_type, errors, allocator);
    } else {
        ast.inject.lhs = validateAST(ast.inject.lhs, null, errors, allocator);
    }
    if (ast.inject.lhs.* == .poison) { // Don't bother moving on...
        return ast_.poisoned;
    }
    var lhs_type = ast.inject.lhs.typeof(allocator);
    const expanded_lhs_type = lhs_type.expand_type(allocator);
    if (expanded_lhs_type.* == .sum and ast.inject.lhs.* == .inferredMember) {
        if (sum_type != null and !sum_type.?.typesMatch(lhs_type)) {
            errors.addError(errs_.Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = sum_type.?, .got = ast.inject.lhs.inferredMember.base.? } });
            return ast_.poisoned;
        }
        const pos: i128 = ast.inject.lhs.inferredMember.pos.?;
        const proper_term: *ast_.AST = (ast.inject.lhs.typeof(allocator)).sum.terms.items[@as(usize, @intCast(pos))];
        return proper_term.annotation.type;
    } else {
        errors.addError(errs_.Error{ .basic = .{ .span = ast.getToken().span, .msg = "inject is not to a sum" } });
        return ast_.poisoned;
    }
}
