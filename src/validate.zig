const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const std = @import("std");
const symbols = @import("symbol.zig");

const AST = _ast.AST;
const Error = errs.Error;
const Scope = symbols.Scope;
const Symbol = symbols.Symbol;
const Token = @import("token.zig").Token;

pub fn validateScope(scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    for (scope.symbols.keys()) |key| {
        var symbol = scope.symbols.get(key).?;
        try validateSymbol(symbol, errors, allocator);
    }
    for (scope.children.items) |child| {
        try validateScope(child, errors, allocator);
    }
}

pub fn validateSymbol(symbol: *Symbol, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, Unimplemented, OutOfMemory }!void {
    if (symbol.validation_state == .valid or symbol.validation_state == .validating) {
        return;
    }
    symbol.validation_state = .validating;

    if (symbol.kind == ._fn) {
        symbol._type.? = try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors, allocator);
        symbol.validation_state = .valid;
        if (symbol._type.?.* != .poison) {
            symbol.init = try validateAST(symbol.init.?, symbol._type.?.function.rhs, symbol.scope, errors, allocator);
        } else {
            symbol.init = _ast.poisoned;
        }
    } else {
        if (symbol.init != null and symbol._type != null) {
            symbol._type = try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors, allocator);
            symbol.validation_state = .valid;
            if (symbol._type.?.* != .poison) {
                symbol.init = try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
            } else {
                symbol.init = _ast.poisoned;
            }
        } else if (symbol.init == null) {
            // Default value (probably done at the IR side?) OR function parameter
            symbol._type = try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors, allocator);
            symbol.validation_state = .valid;
        } else if (symbol._type == null) {
            // Infer type
            symbol.init = try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
            if (symbol.init.?.* != .poison) {
                symbol._type = try validateAST(try symbol.init.?.typeof(symbol.scope, errors, allocator), _ast.typeType, symbol.scope, errors, allocator);
                symbol.validation_state = .valid;
            } else {
                symbol._type = _ast.poisoned;
            }
        } else {
            unreachable;
        }
    }
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
pub fn validateAST(old_ast: *AST, old_expected: ?*AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, Unimplemented, OutOfMemory }!*AST {
    var retval: *AST = undefined;
    var ast = old_ast;
    var expected = old_expected;

    if (old_ast.getCommon().is_valid) {
        return old_ast;
    }

    if (expected != null and (expected.?.* == .product or expected.?.* == .annotation)) {
        // Attempt to modify ast to fit default values. This may not be possible, especially in the case of a type error
        ast = defaultArgs(ast, expected.?, errors, allocator) catch |err| switch (err) {
            error.NoDefault => ast,
            error.typeError => return _ast.poisoned,
            error.OutOfMemory => return error.OutOfMemory,
        };
    }

    if (expected != null and expected.?.* == .annotation) {
        expected = expected.?.annotation.type;
    }
    if (expected) |exp| {
        std.debug.assert(exp.getCommon().is_valid);
        var exp_type = try exp.typeof(scope, errors, allocator);
        std.debug.assert(try exp_type.typesMatch(_ast.typeType, scope, errors, allocator));
    }

    switch (ast.*) {
        .poison => return ast,
        .unit => {
            if (expected != null and !try expected.?.typesMatch(_ast.unitType, scope, errors, allocator) and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.unitType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        .int => {
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        .char => {
            if (expected != null and !try expected.?.typesMatch(_ast.charType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.charType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        .string => {
            if (expected != null and !try expected.?.typesMatch(_ast.stringType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.stringType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        .float => {
            if (expected != null and !try expected.?.typesMatch(_ast.floatType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        .identifier => {
            // look up symbol, that's the type
            var symbol = findSymbol(ast, scope, errors) catch |err| switch (err) {
                error.typeError => return _ast.poisoned,
                else => return err,
            };
            try validateSymbol(symbol, errors, allocator);
            if (symbol._type == null or symbol.validation_state != .valid) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "recursive definition detected", .stage = .typecheck } });
                return _ast.poisoned;
            }
            if (expected != null and !try expected.?.typesMatch(symbol._type.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = symbol._type.?, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        ._true => {
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        ._false => {
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        .not => {
            ast.not.expr = try validateAST(ast.not.expr, _ast.boolType, scope, errors, allocator);
            if (ast.not.expr.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .negate => {
            ast.negate.expr = try validateAST(ast.negate.expr, _ast.floatType, scope, errors, allocator);
            if (ast.negate.expr.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .dereference => {
            if (expected != null) {
                var addr_of = try _ast.AST.createAddrOf(ast.getToken(), expected.?, false, std.heap.page_allocator);
                addr_of.getCommon().is_valid = true;
                ast.dereference.expr = try validateAST(ast.dereference.expr, addr_of, scope, errors, allocator);
            } else {
                ast.dereference.expr = try validateAST(ast.dereference.expr, null, scope, errors, allocator);
            }
            if (ast.dereference.expr.* == .poison) {
                return _ast.poisoned;
            }
            var expr_type = try ast.dereference.expr.typeof(scope, errors, allocator);
            var expanded_expr_type = try expr_type.exapnd_type(scope, errors, allocator);
            if (expanded_expr_type.* != .addrOf) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected an address", .stage = .typecheck } });
                return _ast.poisoned;
            }
            retval = ast;
        },
        ._error => {
            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return _ast.poisoned;
            }
            ast._error.lhs = try validateAST(ast._error.lhs, _ast.typeType, scope, errors, allocator);
            ast._error.rhs = try validateAST(ast._error.rhs, _ast.typeType, scope, errors, allocator);
            if (ast._error.lhs.* == .poison or ast._error.rhs.* == .poison) {
                return _ast.poisoned;
            }
            retval = try AST.create_error_type(ast._error.lhs, ast._error.rhs, allocator);
        },
        ._try => {
            var expr_span = ast._try.expr.getToken().span;
            ast._try.expr = try validateAST(ast._try.expr, null, scope, errors, allocator);
            if (ast._try.expr.* == .poison) {
                return _ast.poisoned;
            }
            var lhs_expanded_type = try (try ast._try.expr.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_error) {
                // lhs is not even an error type
                errors.addError(Error{ .basic = .{ .span = expr_span, .msg = "not an error expression", .stage = .typecheck } });
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(lhs_expanded_type.sum.terms.items[1].annotation.type, scope, errors, allocator)) {
                // lhs is error union, but .err field types don't match with expected
                errors.addError(Error{ .expected2Type = .{ .span = expr_span, .expected = expected.?, .got = lhs_expanded_type.sum.terms.items[1].annotation.type, .stage = .typecheck } });
                return _ast.poisoned;
            } else if (scope.inner_function == null) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "try operator is not within a function", .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                var expanded_function_return = try scope.inner_function.?._type.?.function.rhs.exapnd_type(scope, errors, allocator);
                if (expanded_function_return.* != .sum or !expanded_function_return.sum.was_error) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "enclosing function around try expression does not return an error", .stage = .typecheck } });
                    return _ast.poisoned;
                } else if (!try lhs_expanded_type.sum.terms.items[0].annotation.type.typesMatch(expanded_function_return.sum.terms.items[0].annotation.type, scope, errors, allocator)) {
                    // lhs error union's `.err` member is not a compatible type with the function's error type
                    errors.addError(Error{ .expected2Type = .{
                        .span = expr_span,
                        .expected = lhs_expanded_type,
                        .got = expanded_function_return,
                        .stage = .typecheck,
                    } });
                    return _ast.poisoned;
                }
            }
            retval = ast;
        },
        .optional => {
            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return _ast.poisoned;
            }
            ast.optional.expr = try validateAST(ast.optional.expr, _ast.typeType, scope, errors, allocator);
            if (ast.optional.expr.* == .poison) {
                return _ast.poisoned;
            }
            retval = try AST.create_optional_type(ast.optional.expr, allocator);
        },
        .assign => {
            ast.assign.lhs = try validateAST(ast.assign.lhs, null, scope, errors, allocator);
            validateLValue(ast.assign.lhs, scope, errors) catch |err| switch (err) {
                error.typeError => return _ast.poisoned,
                else => return err,
            };
            ast.assign.rhs = try validateAST(ast.assign.rhs, try ast.assign.lhs.typeof(scope, errors, allocator), scope, errors, allocator);
            if (ast.assign.lhs.* == .poison or ast.assign.rhs.* == .poison) {
                return _ast.poisoned;
            }
            assertMutable(ast.assign.lhs, scope, errors, allocator) catch |err| switch (err) {
                error.typeError => return _ast.poisoned,
                else => return err,
            };
            retval = ast;
        },
        ._or => {
            ast._or.lhs = try validateAST(ast._or.lhs, _ast.boolType, scope, errors, allocator);
            ast._or.rhs = try validateAST(ast._or.rhs, _ast.boolType, scope, errors, allocator);
            if (ast._or.lhs.* == .poison or ast._or.rhs.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        ._and => {
            ast._and.lhs = try validateAST(ast._and.lhs, _ast.boolType, scope, errors, allocator);
            ast._and.rhs = try validateAST(ast._and.rhs, _ast.boolType, scope, errors, allocator);
            if (ast._and.lhs.* == .poison or ast._and.rhs.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .add => {
            ast.add.lhs = try validateAST(ast.add.lhs, _ast.floatType, scope, errors, allocator);
            ast.add.rhs = try validateAST(ast.add.rhs, _ast.floatType, scope, errors, allocator);
            if (ast.add.lhs.* == .poison or ast.add.rhs.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .sub => {
            ast.sub.lhs = try validateAST(ast.sub.lhs, _ast.floatType, scope, errors, allocator);
            ast.sub.rhs = try validateAST(ast.sub.rhs, _ast.floatType, scope, errors, allocator);
            if (ast.sub.lhs.* == .poison or ast.sub.rhs.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .mult => {
            ast.mult.lhs = try validateAST(ast.mult.lhs, _ast.floatType, scope, errors, allocator);
            ast.mult.rhs = try validateAST(ast.mult.rhs, _ast.floatType, scope, errors, allocator);
            if (ast.mult.lhs.* == .poison or ast.mult.rhs.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .div => {
            ast.div.lhs = try validateAST(ast.div.lhs, _ast.floatType, scope, errors, allocator);
            ast.div.rhs = try validateAST(ast.div.rhs, _ast.floatType, scope, errors, allocator);
            if (ast.div.lhs.* == .poison or ast.div.rhs.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .mod => {
            ast.mod.lhs = try validateAST(ast.mod.lhs, _ast.floatType, scope, errors, allocator);
            ast.mod.rhs = try validateAST(ast.mod.rhs, _ast.floatType, scope, errors, allocator);
            if (ast.mod.lhs.* == .poison or ast.mod.rhs.* == .poison) {
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .exponent => {
            var poisoned = false;
            var new_terms = std.ArrayList(*AST).init(allocator);
            for (ast.exponent.terms.items) |term| {
                var new_term = try validateAST(term, _ast.floatType, scope, errors, allocator);
                try new_terms.append(new_term);
                if (new_term.* == .poison) {
                    poisoned = true;
                }
            }
            if (poisoned) {
                return _ast.poisoned;
            } else ast.exponent.terms = new_terms;
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        ._catch => {
            ast._catch.lhs = try validateAST(ast._catch.lhs, null, scope, errors, allocator);
            ast._catch.rhs = try validateAST(ast._catch.rhs, expected, scope, errors, allocator);
            var lhs_expanded_type = try (try ast._catch.lhs.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_error) {
                errors.addError(Error{ .basic = .{ .span = ast._catch.lhs.getToken().span, .msg = "left-hand side of catch is not an error type", .stage = .typecheck } });
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(lhs_expanded_type.sum.terms.items[1].annotation.type, scope, errors, allocator)) {
                // TODO: Print the correct expected and got type, to match orelse for this error.
                // Tough because we don't have the lhs error information... or maybe not?
                errors.addError(Error{ .expected2Type = .{ .span = ast._catch.lhs.getToken().span, .expected = expected.?, .got = lhs_expanded_type.sum.terms.items[1].annotation.type, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                ast._catch.lhs = try validateAST(ast._catch.lhs, null, scope, errors, allocator);
            }
            if (ast._catch.lhs.* == .poison or ast._catch.rhs.* == .poison) {
                return _ast.poisoned;
            }
            retval = ast;
        },
        ._orelse => {
            ast._orelse.lhs = try validateAST(ast._orelse.lhs, null, scope, errors, allocator);
            ast._orelse.rhs = try validateAST(ast._orelse.rhs, expected, scope, errors, allocator);
            var lhs_expanded_type = try (try ast._orelse.lhs.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_optional) {
                errors.addError(Error{ .basic = .{ .span = ast._orelse.lhs.getToken().span, .msg = "left-hand side of orelse is not an optional type", .stage = .typecheck } });
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(lhs_expanded_type.sum.terms.items[1].annotation.type, scope, errors, allocator)) {
                var optional_expected = try AST.create_optional_type(expected.?, allocator);
                errors.addError(Error{ .expected2Type = .{ .span = ast._orelse.lhs.getToken().span, .expected = optional_expected, .got = lhs_expanded_type, .stage = .typecheck } });
                return _ast.poisoned;
            }
            if (ast._orelse.lhs.* == .poison or ast._orelse.rhs.* == .poison) {
                return _ast.poisoned;
            }
            retval = ast;
        },
        .call => {
            ast.call.lhs = try validateAST(ast.call.lhs, null, scope, errors, allocator);
            if (ast.call.lhs.* == .poison) {
                return _ast.poisoned;
            }
            var lhs_type = try ast.call.lhs.typeof(scope, errors, allocator);
            var expanded_lhs_type = try lhs_type.exapnd_type(scope, errors, allocator);
            if (expanded_lhs_type.* == .function) {
                ast.call.rhs = try validateAST(ast.call.rhs, lhs_type.function.lhs, scope, errors, allocator);
                if (ast.call.rhs.* == .poison) {
                    return _ast.poisoned;
                }
                if (expected != null and !try expected.?.typesMatch(lhs_type.function.rhs, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.function.rhs, .stage = .typecheck } });
                    return _ast.poisoned;
                } else {
                    retval = ast;
                }
            } else {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "call is not to a function", .stage = .typecheck } });
                return _ast.poisoned;
            }
        },
        .index => {
            var lhs_span = ast.index.lhs.getToken().span; // Used for error reporting
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                ast.index.lhs = try validateAST(ast.index.lhs, _ast.typeType, scope, errors, allocator);
            } else {
                ast.index.lhs = try validateAST(ast.index.lhs, null, scope, errors, allocator);
            }
            ast.index.rhs = try validateAST(ast.index.rhs, _ast.intType, scope, errors, allocator);
            if (ast.index.lhs.* == .poison or ast.index.rhs.* == .poison) {
                return _ast.poisoned;
            }

            var lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .addrOf) {
                // Implicit dereference
                ast.index.lhs = try validateAST(try AST.createDereference(ast.getToken(), ast.index.lhs, allocator), null, scope, errors, allocator);
                lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);
                if (ast.index.lhs.* == .poison) {
                    return _ast.poisoned;
                }
            } else if (lhs_type.* == .poison) {
                return _ast.poisoned;
            }

            if (lhs_type.* != .product and !(lhs_type.* == .identifier and std.mem.eql(u8, lhs_type.getToken().data, "String"))) {
                // TODO: Replace with check that lhs type implements Indexable
                errors.addError(Error{ .notIndexable = .{ .span = lhs_span, ._type = lhs_type, .stage = .typecheck } });
                return _ast.poisoned;
            }

            if (lhs_type.* == .product and !lhs_type.product.was_slice and !try lhs_type.product.is_homotypical(scope, errors, allocator)) {
                errors.addError(Error{ .basic = .{ .span = lhs_span, .msg = "array is not homotypical", .stage = .typecheck } });
                return _ast.poisoned;
            }

            if (expected != null) {
                if (lhs_type.* == .product and !lhs_type.product.was_slice and !try expected.?.typesMatch(lhs_type.product.terms.items[0], scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.product.terms.items[0], .stage = .typecheck } });
                    return _ast.poisoned;
                } else if (lhs_type.* == .product and lhs_type.product.was_slice and !try expected.?.typesMatch(lhs_type.product.terms.items[0].annotation.type.addrOf.expr, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.product.terms.items[0].annotation.type.addrOf.expr, .stage = .typecheck } });
                    return _ast.poisoned;
                } else {
                    retval = ast;
                }
            } else {
                retval = ast;
            }
        },
        .select => {
            ast.select.lhs = try validateAST(ast.select.lhs, null, scope, errors, allocator);
            if (ast.select.lhs.* == .poison) {
                return _ast.poisoned;
            }

            var lhs_type = try ast.select.lhs.typeof(scope, errors, allocator);
            var select_lhs_type = try lhs_type.exapnd_type(scope, errors, allocator);

            // Implicit dereference
            if (select_lhs_type.* == .addrOf) {
                ast.select.lhs = try validateAST(try AST.createDereference(ast.getToken(), ast.select.lhs, allocator), null, scope, errors, allocator);
                select_lhs_type = try (try ast.select.lhs.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);
                if (ast.select.lhs.* == .poison) {
                    return _ast.poisoned;
                }
            }

            if (try select_lhs_type.typesMatch(_ast.typeType, scope, errors, allocator) and (try ast.select.lhs.exapnd_type(scope, errors, allocator)).* == .sum) {
                var inferred_member = try AST.createInferredMember(ast.getToken(), ast.select.rhs, allocator);
                retval = try validateAST(inferred_member, ast.select.lhs, scope, errors, allocator);
            } else if (select_lhs_type.* != .product and select_lhs_type.* != .sum) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "left-hand-side of select is not selectable",
                    .stage = .typecheck,
                } });
                return _ast.poisoned;
            } else {
                ast.getCommon().is_valid = true;
                var ast_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !try expected.?.typesMatch(ast_type, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast_type, .stage = .typecheck } });
                    return _ast.poisoned;
                } else {
                    retval = ast;
                }
            }
        },
        .function => {
            ast.function.lhs = try validateAST(ast.function.lhs, _ast.typeType, scope, errors, allocator);
            ast.function.rhs = try validateAST(ast.function.rhs, _ast.typeType, scope, errors, allocator);
            if (ast.function.lhs.* == .poison or ast.function.rhs.* == .poison) {
                return _ast.poisoned;
            }
            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .sum => {
            var poisoned = false;
            var new_terms = std.ArrayList(*AST).init(allocator);
            var idents_seen = std.StringArrayHashMap(*AST).init(allocator);
            defer idents_seen.deinit();
            for (ast.sum.terms.items) |term| {
                // Make sure identifiers aren't repeated
                if (term.* == .annotation) {
                    var new_term = try validateAST(term, _ast.typeType, scope, errors, allocator);
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                    var name = term.annotation.pattern.getToken().data;
                    var res = try idents_seen.fetchPut(name, term);
                    if (res) |_res| {
                        errors.addError(Error{ .sum_duplicate = .{ .span = term.getToken().span, .identifier = name, .first = _res.value.getToken().span, .stage = .typecheck } });
                        return _ast.poisoned;
                    }
                } else if (term.* == .identifier) {
                    var new_annotation = try AST.createAnnotation(term.getToken(), term, _ast.unitType, null, null, allocator);
                    new_annotation.getCommon().is_valid = true;
                    try new_terms.append(new_annotation);
                    var name = term.getToken().data;
                    var res = try idents_seen.fetchPut(name, term);
                    if (res) |_res| {
                        errors.addError(Error{ .sum_duplicate = .{ .span = term.getToken().span, .identifier = name, .first = _res.value.getToken().span, .stage = .typecheck } });
                        return _ast.poisoned;
                    }
                } else {
                    errors.addError(Error{ .basic = .{ .span = term.getToken().span, .msg = "invalid sum expression, must be annotation or identifier", .stage = .typecheck } });
                    return _ast.poisoned;
                }
            }
            if (poisoned) {
                return _ast.poisoned;
            }
            ast.sum.terms = new_terms;
            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .inject => {
            if (ast.inject.lhs.* == .inferredMember) {
                // Pass expected so that base can be inferred call
                ast.inject.lhs = try validateAST(ast.inject.lhs, expected, scope, errors, allocator);
            } else {
                ast.inject.lhs = try validateAST(ast.inject.lhs, null, scope, errors, allocator);
            }
            if (ast.inject.lhs.* == .poison) { // Don't bother moving on...
                return _ast.poisoned;
            }
            var lhs_type = try ast.inject.lhs.typeof(scope, errors, allocator);
            var expanded_lhs_type = try lhs_type.exapnd_type(scope, errors, allocator);
            if (expanded_lhs_type.* == .sum and ast.inject.lhs.* == .inferredMember) {
                if (expected != null and !try expected.?.typesMatch(lhs_type, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast.inject.lhs.inferredMember.base.?, .stage = .typecheck } });
                    return _ast.poisoned;
                }
                var pos: i128 = ast.inject.lhs.inferredMember.pos.?;
                var proper_term: *AST = (try ast.inject.lhs.typeof(scope, errors, allocator)).sum.terms.items[@as(usize, @intCast(pos))];

                ast.inject.lhs.inferredMember.init = try validateAST(ast.inject.rhs, proper_term.annotation.type, scope, errors, allocator);
                if (ast.inject.lhs.inferredMember.init.?.* == .poison) {
                    return _ast.poisoned;
                }
                retval = ast.inject.lhs;
            } else {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "inject is not to a sum", .stage = .typecheck } });
                return _ast.poisoned;
            }
        },
        .product => {
            var poisoned = false;
            var new_terms = std.ArrayList(*AST).init(allocator);
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                for (ast.product.terms.items) |term| {
                    var new_term = try validateAST(term, _ast.typeType, scope, errors, allocator);
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
                ast.product.terms = new_terms;
            } else if (expected != null and expected.?.* == .product) {
                if (expected.?.product.terms.items.len != ast.product.terms.items.len) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return _ast.poisoned;
                }
                for (ast.product.terms.items, expected.?.product.terms.items) |term, expected_term| { // Ok, this is cool!
                    var new_term = try validateAST(term, expected_term, scope, errors, allocator);
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
                ast.product.terms = new_terms;
            } else if (expected == null) {
                for (ast.product.terms.items) |term| {
                    var new_term = try validateAST(term, null, scope, errors, allocator);
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
                ast.product.terms = new_terms;
            } else {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return _ast.poisoned;
            }
            if (poisoned) {
                return _ast.poisoned;
            }
            retval = ast;
        },
        ._union => {
            // Save spans since lhs and rhs are expanded, need spans for errors
            var lhs_span = ast._union.lhs.getToken().span;
            var rhs_span = ast._union.rhs.getToken().span;

            ast._union.lhs = try validateAST(ast._union.lhs, _ast.typeType, scope, errors, allocator);
            ast._union.rhs = try validateAST(ast._union.rhs, _ast.typeType, scope, errors, allocator);
            if (ast._union.lhs.* == .poison or ast._union.rhs.* == .poison) {
                return _ast.poisoned;
            }

            var expand_lhs = try ast._union.lhs.exapnd_type(scope, errors, allocator);
            var expand_rhs = try ast._union.rhs.exapnd_type(scope, errors, allocator);
            if (expand_lhs.* != .sum) {
                errors.addError(Error{ .basic = .{ .span = lhs_span, .msg = "left hand side of union is not a sum type", .stage = .typecheck } });
                return _ast.poisoned;
            } else if (expand_rhs.* != .sum) {
                errors.addError(Error{ .basic = .{ .span = rhs_span, .msg = "right hand side of union is not a sum type", .stage = .typecheck } });
                return _ast.poisoned;
            } else if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                var new_terms = std.ArrayList(*AST).init(allocator);
                var names = std.StringArrayHashMap(*AST).init(allocator);

                for (expand_lhs.sum.terms.items) |term| {
                    putAnnotation(term, &names, errors) catch |err| switch (err) {
                        error.typeError => unreachable, // I don't believe this is possible
                        else => return err,
                    };
                    try new_terms.append(term);
                }
                for (expand_rhs.sum.terms.items) |term| {
                    putAnnotation(term, &names, errors) catch |err| switch (err) {
                        error.typeError => return _ast.poisoned,
                        else => return err,
                    };
                    try new_terms.append(term);
                }

                retval = try AST.createSum(ast.getToken(), new_terms, allocator);
            }
        },
        .conditional => {
            var poisoned = false;
            var new_exprs = std.ArrayList(*AST).init(allocator);
            for (ast.conditional.exprs.items) |child| {
                var new_term = try validateAST(child, _ast.floatType, scope, errors, allocator);
                try new_exprs.append(new_term);
                if (new_term.* == .poison) {
                    poisoned = true;
                }
            }
            ast.conditional.exprs = new_exprs;
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return _ast.poisoned;
            } else if (poisoned) {
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .addrOf => {
            if (expected == null) {
                // Not expecting anything, just validate expr
                ast.addrOf.expr = try validateAST(ast.addrOf.expr, null, scope, errors, allocator);
                if (ast.addrOf.expr.* == .poison) {
                    return _ast.poisoned;
                }
                validateLValue(ast.addrOf.expr, scope, errors) catch |err| switch (err) {
                    error.typeError => return _ast.poisoned,
                    else => return err,
                };
            } else {
                if (try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                    // Address type, type of this ast must be a type, inner must be a type
                    ast.addrOf.expr = try validateAST(ast.addrOf.expr, _ast.typeType, scope, errors, allocator);
                    if (ast.addrOf.expr.* == .poison) {
                        return _ast.poisoned;
                    }
                } else {
                    // Address value, expected must be an address, inner must match with expected's inner
                    var expanded_expected = try expected.?.exapnd_type(scope, errors, allocator); // Call is memoized
                    if (expanded_expected.* != .addrOf) {
                        // Didn't expect an address type. Validate expr and report error
                        ast.addrOf.expr = try validateAST(ast.addrOf.expr, null, scope, errors, allocator);
                        if (ast.addrOf.expr.* == .poison) {
                            return _ast.poisoned;
                        }
                        errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                        return _ast.poisoned;
                    }

                    // Everythings Ok.
                    ast.addrOf.expr = try validateAST(ast.addrOf.expr, expanded_expected.addrOf.expr, scope, errors, allocator);
                    if (ast.addrOf.expr.* == .poison) {
                        return _ast.poisoned;
                    }
                    ast.getCommon().is_valid = true;
                    validateLValue(ast.addrOf.expr, scope, errors) catch |err| switch (err) {
                        error.typeError => return _ast.poisoned,
                        else => return err,
                    };
                    if (ast.addrOf.mut) {
                        assertMutable(ast.addrOf.expr, scope, errors, allocator) catch |err| switch (err) {
                            error.typeError => return _ast.poisoned, // Soft unreachable, will be caught early but is still good to have this here
                            else => return err,
                        };
                    }
                }
            }
            retval = ast;
        },
        .sliceOf => {
            var was_type = false;
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                // Slice-of type, type of this ast must be a type, inner must be a type
                ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, _ast.typeType, scope, errors, allocator);
                if (ast.sliceOf.expr.* == .poison) {
                    return _ast.poisoned;
                }
                if (ast.sliceOf.len) |len| {
                    ast.sliceOf.len = try validateAST(len, _ast.intType, scope, errors, allocator);
                    if (ast.sliceOf.len.?.* == .poison) {
                        return _ast.poisoned;
                    }
                }
                if (ast.sliceOf.kind == .ARRAY) {
                    // Inflate to product
                    var new_terms = std.ArrayList(*AST).init(allocator);
                    // TODO: Compile-time evaluate array size
                    for (0..@as(usize, @intCast(ast.sliceOf.len.?.int.data))) |_| {
                        try new_terms.append(ast.sliceOf.expr);
                    }
                    if (ast.sliceOf.len.?.int.data <= 0) {
                        errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "array length is negative", .stage = .typecheck } });
                        return _ast.poisoned;
                    }
                    ast = try AST.createProduct(ast.getToken(), new_terms, allocator);
                } else {
                    // Regular slice type, change to product of data address and length
                    ast = try AST.create_slice_type(ast.sliceOf.expr, ast.sliceOf.kind == .MUT, allocator);
                }
                was_type = true;
            } else {
                if (ast.sliceOf.kind != .SLICE and ast.sliceOf.kind != .MUT) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "array length is not allowed in slice-of operator", .stage = .typecheck } });
                    return _ast.poisoned;
                }
                ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, null, scope, errors, allocator);
                if (ast.sliceOf.expr.* == .poison) {
                    return _ast.poisoned;
                }

                // Slice-of value, expected must be an slice, inner must match with expected's inner
                // ast.sliceOf.expr must be homotypical product type of expected
                var expr_type = try ast.sliceOf.expr.typeof(scope, errors, allocator);
                ast.getCommon().is_valid = true;
                if (expr_type.* != .product or !try expr_type.product.is_homotypical(scope, errors, allocator)) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "attempt to take slice-of something that is not an array", .stage = .typecheck } });
                    return _ast.poisoned;
                } else if (expected != null and !try expected.?.typesMatch(try ast.typeof(scope, errors, allocator), scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return _ast.poisoned;
                }

                validateLValue(ast.sliceOf.expr, scope, errors) catch |err| switch (err) {
                    error.typeError => return _ast.poisoned, // soft unreachable, will be rejected because not a slice type
                    else => return err,
                };
                if (ast.sliceOf.kind == .MUT) {
                    assertMutable(ast.sliceOf.expr, scope, errors, allocator) catch |err| switch (err) {
                        error.typeError => return _ast.poisoned, // soft unreachable, will be rejected because not a slice type
                        else => return err,
                    };
                }

                // Restructrure as product
                var new_terms = std.ArrayList(*AST).init(allocator);
                var index = try AST.createIndex(
                    ast.getToken(),
                    ast.sliceOf.expr,
                    try AST.createInt(ast.getToken(), 0, allocator),
                    allocator,
                );
                try new_terms.append(try AST.createAddrOf(
                    ast.getToken(),
                    index,
                    ast.sliceOf.kind == .MUT,
                    allocator,
                ));
                try new_terms.append(try AST.createInt(ast.getToken(), expr_type.product.terms.items.len, allocator));
                ast = try AST.createProduct(ast.getToken(), new_terms, allocator);
                ast.product.was_slice = true;
                ast.getCommon().is_valid = true;
                ast.product.was_slice = true;
            }
            retval = ast;
        },
        .subSlice => {
            ast.subSlice.super = try validateAST(ast.subSlice.super, null, scope, errors, allocator);
            if (ast.subSlice.super.* == .poison) {
                return _ast.poisoned;
            }
            var super_type = try ast.subSlice.super.typeof(scope, errors, allocator);
            if (super_type.* != .product or !super_type.product.was_slice) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot take a sub-slice of something that is not a slice", .stage = .typecheck } });
                return _ast.poisoned;
            }

            if (ast.subSlice.lower) |lower| {
                ast.subSlice.lower = try validateAST(lower, _ast.intType, scope, errors, allocator);
            } else {
                ast.subSlice.lower = try AST.createInt(ast.getToken(), 0, allocator);
            }
            if (ast.subSlice.upper) |upper| {
                ast.subSlice.upper = try validateAST(upper, _ast.intType, scope, errors, allocator);
            } else {
                var index = try AST.createSelect(
                    ast.getToken(),
                    ast.subSlice.super,
                    try AST.createIdentifier(Token.create("length", null, "", 0, 0), allocator),
                    allocator,
                );
                ast.subSlice.upper = try validateAST(index, _ast.intType, scope, errors, allocator);
            }
            if (ast.subSlice.lower.?.* == .poison or ast.subSlice.upper.?.* == .poison) {
                return _ast.poisoned;
            }
            retval = ast;
        },
        .annotation => {
            ast.annotation.type = try validateAST(ast.annotation.type, _ast.typeType, scope, errors, allocator);
            if (ast.annotation.init != null) {
                ast.annotation.init = try validateAST(ast.annotation.init.?, ast.annotation.type, scope, errors, allocator);
            }
            if (ast.annotation.type.* == .poison or (ast.annotation.init != null and ast.annotation.init.?.* == .poison)) {
                return _ast.poisoned;
            }

            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },
        .inferredMember => {
            var expected_expanded: *AST = undefined;
            if (expected != null) {
                expected_expanded = try expected.?.exapnd_type(scope, errors, allocator);
            }
            if (expected == null) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot infer the sum type", .stage = .typecheck } });
                return _ast.poisoned;
            } else if (expected != null and expected_expanded.* != .sum) {
                errors.addError(Error{ .expectedGotString = .{ .span = ast.getToken().span, .expected = expected.?, .got = "an inferred member", .stage = .typecheck } });
                return _ast.poisoned;
            } else {
                ast.inferredMember.base = expected;
                for (expected_expanded.sum.terms.items, 0..) |term, i| {
                    if (std.mem.eql(u8, term.annotation.pattern.getToken().data, ast.inferredMember.ident.getToken().data)) {
                        ast.inferredMember.pos = i;
                        break;
                    }
                }
                if (ast.inferredMember.pos == null) {
                    errors.addError(Error{ .member_not_in = .{ .span = ast.getToken().span, .identifier = ast.inferredMember.ident.getToken().data, .group_name = "sum", .stage = .typecheck } });
                    return _ast.poisoned;
                }

                var pos: i128 = ast.inferredMember.pos.?;
                var proper_term: *AST = expected_expanded.sum.terms.items[@as(usize, @intCast(pos))];

                if (proper_term.annotation.init) |_init| {
                    ast.inferredMember.init = _init; // This will be overriden by a call expression's rhs
                }

                retval = ast;
            }
        },
        ._if => {
            if (ast._if.let) |let| {
                ast._if.let = try validateAST(let, null, scope, errors, allocator);
            }
            ast._if.condition = try validateAST(ast._if.condition, _ast.boolType, ast._if.scope.?, errors, allocator);
            if (expected != null) {
                // expecting a type
                var expected_expanded = try expected.?.exapnd_type(scope, errors, allocator);
                var is_expected_optional = expected_expanded.* == .sum and expected_expanded.sum.was_optional;
                var has_else = ast._if.elseBlock != null;
                if (has_else) {
                    ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, expected.?, ast._if.scope.?, errors, allocator);
                    ast._if.elseBlock = try validateAST(ast._if.elseBlock.?, expected.?, ast._if.scope.?, errors, allocator);
                } else if (is_expected_optional) {
                    var full_type = expected_expanded.sum.terms.items[1];
                    ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, full_type, ast._if.scope.?, errors, allocator);
                } else {
                    ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, expected.?, ast._if.scope.?, errors, allocator);
                    ast.getCommon().is_valid = true;
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return _ast.poisoned;
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
                return _ast.poisoned;
            }
            retval = ast;
        },
        .case => {
            var poisoned = false;
            if (ast.case.let) |let| {
                ast.case.let = try validateAST(let, null, scope, errors, allocator);
                poisoned = poisoned or ast.case.let.?.* == .poison;
            }
            var new_mappings = std.ArrayList(*AST).init(allocator);
            var num_rhs: usize = 0;
            for (ast.case.mappings.items) |mapping| {
                if (mapping.mapping.rhs) |_| {
                    num_rhs += 1;
                }

                if (expected != null) {
                    var expected_expanded = try expected.?.exapnd_type(scope, errors, allocator);
                    var is_expected_optional = expected_expanded.* == .sum and expected_expanded.sum.was_optional;
                    var has_else = ast.case.has_else;
                    if (has_else) {
                        var new_mapping = try validateAST(mapping, expected, ast.case.scope.?, errors, allocator);
                        try new_mappings.append(new_mapping);
                        poisoned = poisoned or new_mapping.* == .poison;
                    } else if (is_expected_optional) {
                        var full_type = expected_expanded.sum.terms.items[1];
                        var new_mapping = try validateAST(mapping, full_type, ast.case.scope.?, errors, allocator);
                        try new_mappings.append(new_mapping);
                        poisoned = poisoned or new_mapping.* == .poison;
                    } else {
                        var new_map = try validateAST(mapping, expected.?, ast.case.scope.?, errors, allocator);
                        ast.getCommon().is_valid = true;
                        errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try new_map.typeof(scope, errors, allocator), .stage = .typecheck } });
                        return _ast.poisoned;
                    }
                } else {
                    var new_mapping = try validateAST(mapping, null, ast.case.scope.?, errors, allocator);
                    try new_mappings.append(new_mapping);
                    poisoned = poisoned or new_mapping.* == .poison;
                }
            }
            if (num_rhs == 0) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "case does not have a prong with `=>`", .stage = .typecheck } });
                return _ast.poisoned;
            } else if (poisoned) {
                return _ast.poisoned;
            } else {
                ast.case.mappings = new_mappings;
                retval = ast;
            }
        },
        .mapping => {
            switch (ast.mapping.kind) {
                .case => {
                    if (ast.mapping.lhs) |lhs| {
                        ast.mapping.lhs = try validateAST(lhs, _ast.boolType, scope, errors, allocator);
                    }
                    if (ast.mapping.rhs) |rhs| {
                        ast.mapping.rhs = try validateAST(rhs, expected, scope, errors, allocator);
                    }
                    if ((ast.mapping.lhs != null and ast.mapping.lhs.?.* == .poison) or
                        (ast.mapping.rhs != null and ast.mapping.rhs.?.* == .poison))
                    {
                        return _ast.poisoned;
                    }
                },
                .match => {},
            }
            retval = ast;
        },
        ._while => {
            if (ast._while.let) |let| {
                ast._while.let = try validateAST(let, null, scope, errors, allocator);
            }
            if (ast._while.post) |post| {
                ast._while.post = try validateAST(post, null, ast._while.scope.?, errors, allocator);
            }
            ast._while.condition = try validateAST(ast._while.condition, _ast.boolType, ast._while.scope.?, errors, allocator);

            var optional_type = false; //< Set if expected is an optional type
            if (expected != null) {
                var expected_expanded = try expected.?.exapnd_type(scope, errors, allocator);
                if (expected_expanded.* == .sum and expected_expanded.sum.was_optional) {
                    var full_type = expected_expanded.sum.terms.items[1];
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
                return _ast.poisoned;
            }
            retval = ast;
        },
        .block => {
            var poisoned = false;
            var new_statements = std.ArrayList(*AST).init(allocator);
            if (ast.block.final) |final| {
                // Has final
                var i: usize = 0;
                while (i < ast.block.statements.items.len) : (i += 1) {
                    var term = ast.block.statements.items[i];
                    var new_statement = try validateAST(term, null, ast.block.scope.?, errors, allocator);
                    try new_statements.append(new_statement);
                    poisoned = poisoned or new_statement.* == .poison;
                }
                ast.block.statements = new_statements;
                ast.block.final = try validateAST(final, expected, ast.block.scope.?, errors, allocator);
                poisoned = poisoned or ast.block.final.?.* == .poison;
            } else {
                // block has no 'final' statement (return, continue, break, etc)
                if (ast.block.statements.items.len > 1) {
                    var i: usize = 0;
                    while (i < ast.block.statements.items.len - 1) : (i += 1) {
                        var term = ast.block.statements.items[i];
                        var new_statement = try validateAST(term, null, ast.block.scope.?, errors, allocator);
                        try new_statements.append(new_statement);
                        poisoned = poisoned or new_statement.* == .poison;
                    }
                    var new_statement = try validateAST(ast.block.statements.items[ast.block.statements.items.len - 1], expected, ast.block.scope.?, errors, allocator);
                    try new_statements.append(new_statement);
                    poisoned = poisoned or new_statement.* == .poison;
                    ast.block.statements = new_statements;
                } else if (ast.block.statements.items.len == 1) {
                    var new_statement = try validateAST(ast.block.statements.items[0], expected, ast.block.scope.?, errors, allocator);
                    try new_statements.append(new_statement);
                    poisoned = poisoned or new_statement.* == .poison;
                    ast.block.statements = new_statements;
                }

                ast.getCommon().is_valid = true; // So that the typeof code can be reused. All children should be validated at this point
                var block_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !try expected.?.typesMatch(block_type, scope, errors, allocator)) {
                    // std.debug.assert(ast.block.statements.items.len == 0); // this this true? what about a block that ends in a defer? or a decl?
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = block_type, .stage = .typecheck } });
                    return _ast.poisoned;
                }
            }
            if (poisoned) {
                return _ast.poisoned;
            } else {
                retval = ast;
            }
        },

        // no return
        ._break => {
            if (!scope.in_loop) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`break` must be inside a loop",
                    .stage = .typecheck,
                } });
                return _ast.poisoned;
            }
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return _ast.poisoned;
            }
            retval = ast;
        },
        ._continue => {
            if (!scope.in_loop) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`continue` must be inside a loop",
                    .stage = .typecheck,
                } });
                return _ast.poisoned;
            }
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return _ast.poisoned;
            }
            retval = ast;
        },

        ._return => {
            if (scope.in_function == 0 or scope.inner_function == null) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`return` must be inside in a function",
                    .stage = .typecheck,
                } });
                return _ast.poisoned;
            }
            if (ast._return.expr) |expr| {
                ast._return.expr = try validateAST(expr, scope.inner_function.?._type.?.function.rhs, scope, errors, allocator);
                if (ast._return.expr.?.* == .poison) {
                    return _ast.poisoned;
                }
            } else if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return _ast.poisoned;
            }
            retval = ast;
        },
        ._unreachable => {
            retval = ast;
        },

        ._defer => {
            ast._defer.statement = try validateAST(ast._defer.statement, null, scope, errors, allocator);
            if (ast._defer.statement.* == .poison) {
                return _ast.poisoned;
            }
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return _ast.poisoned;
            }
            try scope.defers.append(ast._defer.statement);
            retval = ast;
        },
        ._errdefer => {
            ast._errdefer.statement = try validateAST(ast._errdefer.statement, null, scope, errors, allocator);
            if (ast._errdefer.statement.* == .poison) {
                return _ast.poisoned;
            }
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return _ast.poisoned;
            }
            try scope.errdefers.append(ast._errdefer.statement);
            retval = ast;
        },
        .fnDecl => {
            try validateSymbol(ast.fnDecl.symbol.?, errors, allocator);
            if (ast.fnDecl.symbol.?._type.?.* == .poison) {
                return _ast.poisoned;
            }
            if (expected) |_expected| {
                var expected_expanded = try _expected.exapnd_type(scope, errors, allocator);
                var self_type = try ast.typeof(scope, errors, allocator);
                if (!try expected_expanded.typesMatch(self_type, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected_expanded, .got = self_type, .stage = .typecheck } });
                    return _ast.poisoned;
                }
            }
            retval = ast;
        },
        .decl => {
            ast.decl.symbol.?.defined = true;
            try validateSymbol(ast.decl.symbol.?, errors, allocator);
            // statement, no type
            if (expected != null and !try expected.?.typesMatch(_ast.unitType, scope, errors, allocator)) {
                errors.addError(Error{ .expectedType = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast, .stage = .typecheck } });
                return _ast.poisoned;
            }
            retval = ast;
        },

        else => {
            std.debug.print("validateAST() unimplemented for {s}\n", .{@tagName(ast.*)});
            unreachable;
        },
    }

    if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
        _ = try retval.exapnd_type(scope, errors, allocator);
    }

    retval.getCommon().is_valid = true;
    return retval;
}

fn defaultArgs(ast: *AST, expected: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*AST {
    if (try argsAreNames(ast, errors)) {
        return namedArgs(ast, expected, errors, allocator);
    } else {
        return positionalArgs(ast, expected, allocator);
    }
}

fn argsAreNames(ast: *AST, errors: *errs.Errors) !bool {
    switch (ast.*) {
        .assign => return true,
        .product => {
            var seen_named = false;
            var seen_pos = false;
            for (ast.product.terms.items) |term| {
                if (term.* == .assign) {
                    seen_named = true;
                } else {
                    seen_pos = true;
                }
            }
            std.debug.assert(seen_named or seen_pos);
            if (seen_named and seen_pos) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "mixed positional and named arguments are not allowed",
                    .stage = .typecheck,
                } });
                return error.typeError;
            } else {
                return seen_named;
            }
        },
        else => return false,
    }
}

fn positionalArgs(ast: *AST, expected: *AST, allocator: std.mem.Allocator) !*AST {
    switch (expected.*) {
        .poison => return ast,

        .annotation => {
            if (ast.* == .unit and expected.annotation.init != null) {
                return expected.annotation.init.?;
            } else if (ast.* != .unit) {
                return ast;
            } else {
                return error.NoDefault;
            }
        },

        .product => {
            var new_terms = std.ArrayList(*AST).init(allocator);
            for (expected.product.terms.items, 0..) |term, i| {
                // ast is product, append ast's corresponding term
                if (ast.* == .product and i < ast.product.terms.items.len) {
                    try new_terms.append(ast.product.terms.items[i]);
                }
                // ast is unit or ast isn't a product and i > 0 or ast is a product and off the edge of ast's terms, try to fill with the default
                else if (ast.* == .unit or (ast.* != .product and i > 0) or (ast.* == .product and i >= ast.product.terms.items.len)) {
                    if (term.* == .annotation and term.annotation.init != null) {
                        try new_terms.append(term.annotation.init.?);
                    } else {
                        return error.NoDefault;
                    }
                }
                // ast is not product, i != 0, append ast as first term
                else {
                    try new_terms.append(ast);
                }
            }
            return try AST.createProduct(ast.getToken(), new_terms, allocator);
        },

        else => unreachable,
    }
}

fn namedArgs(ast: *AST, expected: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*AST {
    // Maps assign.lhs name to assign.rhs
    var arg_map = std.StringArrayHashMap(*AST).init(allocator);

    // Associate argument names with their values
    switch (ast.*) { // Can assume ast is either assignment, or product of assignments
        .assign => {
            putAssign(ast, &arg_map, errors) catch |err| switch (err) {
                error.typeError => return _ast.poisoned,
                else => return err,
            };
        },

        .product => {
            for (ast.product.terms.items) |term| {
                putAssign(term, &arg_map, errors) catch |err| switch (err) {
                    error.typeError => return _ast.poisoned,
                    else => return err,
                };
            }
        },

        else => unreachable,
    }

    // Construct positional args in the order specified by `expected`
    switch (expected.*) {
        .annotation => {
            if (arg_map.keys().len != 1) { // Cannot be 0, since that is technically a positional arglist
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "too many arguments specifed",
                    .stage = .typecheck,
                } });
                return _ast.poisoned;
            } else {
                return arg_map.values()[0];
            }
        },

        .product => {
            var new_terms = std.ArrayList(*AST).init(allocator);
            for (expected.product.terms.items) |term| {
                if (term.* != .annotation) {
                    errors.addError(Error{ .basic = .{
                        .span = ast.getToken().span,
                        .msg = "expected type does not accept named arugments",
                        .stage = .typecheck,
                    } });
                    return _ast.poisoned;
                }
                var arg = arg_map.get(term.annotation.pattern.getToken().data);
                if (arg == null) {
                    if (term.annotation.init != null) {
                        try new_terms.append(term.annotation.init.?);
                    } else {
                        errors.addError(Error{ .basic = .{
                            .span = ast.getToken().span,
                            .msg = "not all arguments are specified",
                            .stage = .typecheck,
                        } });
                        return _ast.poisoned;
                    }
                } else {
                    try new_terms.append(arg.?);
                }
            }
            return AST.createProduct(ast.getToken(), new_terms, allocator);
        },

        else => unreachable,
    }
}

fn putAssign(ast: *AST, arg_map: *std.StringArrayHashMap(*AST), errors: *errs.Errors) !void {
    var name = ast.assign.lhs.getToken().data;
    if (arg_map.get(name)) |_| {
        errors.addError(Error{ .basic = .{
            .span = ast.getToken().span,
            .msg = "parameter is already defined",
            .stage = .typecheck,
        } });
        return error.typeError;
    } else {
        try arg_map.put(name, ast.assign.rhs);
    }
}

fn putAnnotation(ast: *AST, arg_map: *std.StringArrayHashMap(*AST), errors: *errs.Errors) !void {
    var name = ast.annotation.pattern.getToken().data;
    if (arg_map.get(name)) |_| {
        errors.addError(Error{ .basic = .{
            .span = ast.getToken().span,
            .msg = "duplicate annotation identifiers detected",
            .stage = .typecheck,
        } });
        return error.typeError;
    } else {
        try arg_map.put(name, ast.annotation.type);
    }
}

pub fn findSymbol(ast: *AST, scope: *Scope, errors: *errs.Errors) !*Symbol {
    var symbol = scope.lookup(ast.identifier.common.token.data, false) orelse {
        errors.addError(Error{ .undeclaredIdentifier = .{ .identifier = ast.identifier.common.token, .stage = .typecheck } });
        return error.typeError;
    };
    if (!symbol.defined) {
        errors.addError(Error{ .useBeforeDef = .{ .identifier = ast.identifier.common.token, .symbol = symbol, .stage = .typecheck } });
        return error.typeError;
    }
    return symbol;
}

fn validateLValue(ast: *AST, scope: *Scope, errors: *errs.Errors) !void {
    switch (ast.*) {
        .identifier => {
            _ = try findSymbol(ast, scope, errors);
        },

        .dereference => {
            var child = ast.dereference.expr;
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

        else => {
            errors.addError(Error{ .basic = .{
                .span = ast.getToken().span,
                .msg = "not an l-value",
                .stage = .typecheck,
            } });
            return error.typeError;
        },
    }
}

fn assertMutable(ast: *AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !void {
    switch (ast.*) {
        .identifier => {
            var symbol = try findSymbol(ast, scope, errors);
            if (symbol.kind != .mut) {
                errors.addError(Error{ .modifyImmutable = .{
                    .identifier = ast.identifier.common.token,
                    .symbol = symbol,
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
        },

        .dereference => {
            var child = ast.dereference.expr;
            var child_type = try child.typeof(scope, errors, allocator);
            if (!child_type.addrOf.mut) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "cannot modify non-mutable address",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
        },

        .index => {
            var lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .product and lhs_type.product.was_slice) {
                var child_type = lhs_type.product.terms.items[0];
                if (!child_type.annotation.type.addrOf.mut) {
                    errors.addError(Error{ .basic = .{
                        .span = ast.getToken().span,
                        .msg = "cannot modify non-mutable address",
                        .stage = .typecheck,
                    } });
                    return error.typeError;
                }
            } else {
                try assertMutable(ast.index.lhs, scope, errors, allocator);
            }
        },

        .select => {
            try assertMutable(ast.select.lhs, scope, errors, allocator);
        },

        else => unreachable,
    }
}
