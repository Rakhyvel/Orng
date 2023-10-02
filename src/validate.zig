const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const primitives = @import("primitives.zig");
const std = @import("std");
const symbols = @import("symbol.zig");

const AST = _ast.AST;
const Error = errs.Error;
const Scope = symbols.Scope;
const Span = @import("span.zig").Span;
const String = @import("zig-string/zig-string.zig").String;
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
        symbol._type.? = try validateAST(symbol._type.?, primitives.type_type, symbol.scope, errors, allocator);
        symbol.validation_state = .valid;
        if (symbol._type.?.* != .poison) {
            symbol.expanded_type = try symbol._type.?.expand_type(symbol.scope, errors, allocator);
            symbol.init = try validateAST(symbol.init.?, symbol._type.?.function.rhs, symbol.scope, errors, allocator);
        } else {
            symbol.init = _ast.poisoned;
        }
    } else {
        if (symbol.init != null and symbol._type != null) {
            symbol._type = try validateAST(symbol._type.?, primitives.type_type, symbol.scope, errors, allocator);
            symbol.validation_state = .valid;
            if (symbol._type.?.* != .poison) {
                symbol.expanded_type = try symbol._type.?.expand_type(symbol.scope, errors, allocator);
                symbol.init = try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
            } else {
                symbol.init = _ast.poisoned;
            }
        } else if (symbol.init == null and symbol._type != null) {
            // Default value
            symbol._type = try validateAST(symbol._type.?, primitives.type_type, symbol.scope, errors, allocator);
            symbol.expanded_type = try symbol._type.?.expand_type(symbol.scope, errors, allocator);
            symbol.validation_state = .valid;
        } else if (symbol.init != null and symbol._type == null) {
            // Infer type
            symbol.init = try validateAST(symbol.init.?, null, symbol.scope, errors, allocator);
            if (symbol.init.?.* != .poison) {
                symbol._type = try validateAST(try symbol.init.?.typeof(symbol.scope, errors, allocator), primitives.type_type, symbol.scope, errors, allocator);
                symbol.expanded_type = try symbol._type.?.expand_type(symbol.scope, errors, allocator);
                symbol.validation_state = .valid;
            } else {
                symbol._type = _ast.poisoned;
            }
        } else {
            std.debug.print("symbol `{s}` has null type and null init value\n", .{symbol.name});
            unreachable;
        }
    }

    // Symbol's name must be capitalizes iff it type is Type
    if (symbol.expanded_type != null) {
        if (symbol.expanded_type.?.* == .identifier and std.mem.eql(u8, symbol.expanded_type.?.getToken().data, "Type")) {
            if (!std.ascii.isUpper(symbol.name[0])) {
                errors.addError(Error{ .basic = .{ .span = symbol.span, .msg = "symbol of type Type must start with an uppercase letter" } });
            }
        } else {
            if (std.ascii.isUpper(symbol.name[0])) {
                errors.addError(Error{ .basic = .{ .span = symbol.span, .msg = "symbol of type other than Type must not start with an uppercase letter" } });
            }
        }
    }
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
pub fn validateAST(old_ast: *AST, old_expected: ?*AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, Unimplemented, OutOfMemory }!*AST {
    var retval: *AST = undefined;
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
        std.debug.assert(expected.?.* != .poison);
        var expanded_expected = try expected.?.expand_type(scope, errors, allocator);
        if (expanded_expected.* == .product or expanded_expected.* == .annotation) {
            // Attempt to modify ast to fit default values. This may not be possible, especially in the case of a type error
            ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
            var list = std.ArrayList(*AST).init(allocator);
            if (ast.* == .product) {
                for (ast.product.terms.items) |term| {
                    try list.append(term);
                }
            } else if (ast.* != .unit) {
                try list.append(ast);
            }
            var new_list = default_args(list, expanded_expected, errors, allocator) catch |err| switch (err) {
                error.NoDefault => std.ArrayList(*AST).init(allocator),
                error.typeError => return ast.enpoison(),
                error.OutOfMemory => return error.OutOfMemory,
            };
            if (new_list.items.len == 1) {
                ast = new_list.items[0];
            } else if (new_list.items.len > 1) {
                ast = try AST.createProduct(ast.getToken(), new_list, allocator);
            } else {
                // ast = ast;
            }
        }
        if (expected.?.* == .annotation) {
            expected = expected.?.annotation.type;
        }
        std.debug.assert(expected.?.getCommon().validation_state == .valid);
        var exp_type = try expected.?.typeof(scope, errors, allocator);
        std.debug.assert(try exp_type.typesMatch(primitives.type_type, scope, errors, allocator));
    }

    // std.debug.print("{s}\n", .{@tagName(ast.*)});
    switch (ast.*) {
        .poison => retval = ast,
        .unit => {
            if (expected != null and !try primitives.unit_type.typesMatch(expected.?, scope, errors, allocator) and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.unit_type } });
                return ast.enpoison();
            } else {
                retval = ast;
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
                ast.int.represents = expected orelse ast.int.represents;
                retval = ast;
            }
        },

        .char => {
            if (expected != null and !try primitives.char_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.char_type } });
                return ast.enpoison();
            } else {
                retval = ast;
            }
        },

        .string => {
            if (expected != null and !try primitives.string_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.string_type } });
                return ast.enpoison();
            } else {
                retval = ast;
            }
        },

        .float => {
            if (expected != null and !try expected.?.can_represent_float(scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.float_type } });
                return ast.enpoison();
            } else {
                ast.float.represents = expected orelse ast.float.represents;
                retval = ast;
            }
        },

        .identifier => {
            // look up symbol, that's the type
            var symbol = findSymbol(ast, expected, scope, errors) catch |err| switch (err) {
                error.typeError => return ast.enpoison(),
                else => return err,
            };
            try validateSymbol(symbol, errors, allocator);
            if (symbol._type == null or symbol.validation_state != .valid or symbol._type == null or symbol._type.?.getCommon().validation_state != .valid) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "recursive definition detected" } });
                return ast.enpoison();
            }
            if (expected != null and !try symbol._type.?.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = symbol._type.? } });
                return ast.enpoison();
            } else {
                retval = ast;
            }
        },

        ._true => {
            if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            } else {
                retval = ast;
            }
        },

        ._false => {
            if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            } else {
                retval = ast;
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
                retval = ast;
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
            } else if (expected != null and !try primitives.int_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.float_type } });
                return ast.enpoison();
            } else {
                retval = ast;
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
            var expanded_expr_type = try expr_type.expand_type(scope, errors, allocator);
            if (expanded_expr_type.* != .addrOf) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected an address" } });
                return ast.enpoison();
            } else {
                retval = ast;
            }
        },
        ._try => {
            var expr_span = ast._try.expr.getToken().span;
            ast._try.expr = try validateAST(ast._try.expr, null, scope, errors, allocator);
            if (ast._try.expr.* == .poison) {
                return ast.enpoison();
            }
            var lhs_expanded_type = try (try ast._try.expr.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_error) {
                // lhs is not even an error type
                errors.addError(Error{ .basic = .{ .span = expr_span, .msg = "not an error expression" } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_expanded_type.sum.terms.items[1].annotation.type.typesMatch(expected.?, scope, errors, allocator)) {
                // lhs is error union, but .err field types don't match with expected
                errors.addError(Error{ .expected2Type = .{ .span = expr_span, .expected = expected.?, .got = lhs_expanded_type.sum.terms.items[1].annotation.type } });
                return ast.enpoison();
            } else if (scope.inner_function == null) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "try operator is not within a function" } });
                return ast.enpoison();
            } else {
                var expanded_function_return = try scope.inner_function.?._type.?.function.rhs.expand_type(scope, errors, allocator);
                if (expanded_function_return.* != .sum or !expanded_function_return.sum.was_error) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "enclosing function around try expression does not return an error" } });
                    return ast.enpoison();
                } else if (!try lhs_expanded_type.sum.terms.items[0].annotation.type.typesMatch(expanded_function_return.sum.terms.items[0].annotation.type, scope, errors, allocator)) {
                    // lhs error union's `.err` member is not a compatible type with the function's error type
                    errors.addError(Error{ .expected2Type = .{
                        .span = expr_span,
                        .expected = lhs_expanded_type,
                        .got = expanded_function_return,
                    } });
                    return ast.enpoison();
                }
            }
            retval = ast;
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
            retval = ast;
        },
        .domainOf => {
            ast.domainOf.sum_expr = try validateAST(ast.domainOf.sum_expr, primitives.type_type, scope, errors, allocator);
            if (ast.domainOf.sum_expr.* == .poison) {
                return ast.enpoison();
            }
            retval = try domainof(ast.domainOf.expr, ast.domainOf.sum_expr, scope, errors, allocator);
        },
        ._typeOf => {
            ast._typeOf.expr = try validateAST(ast._typeOf.expr, null, scope, errors, allocator);
            if (expected != null and !try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            retval = try ast._typeOf.expr.typeof(scope, errors, allocator);
        },
        .assign => {
            ast.assign.lhs = try validateAST(ast.assign.lhs, null, scope, errors, allocator);
            validateLValue(ast.assign.lhs, scope, errors) catch |err| switch (err) {
                error.typeError => return ast.enpoison(),
                else => return err,
            };
            var lhs_type = try ast.assign.lhs.typeof(scope, errors, allocator);
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
            retval = ast;
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
                retval = ast;
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
                retval = ast;
            }
        },
        .add => {
            ast.add.lhs = try validateAST(ast.add.lhs, expected, scope, errors, allocator);
            var lhs_type = try ast.add.lhs.typeof(scope, errors, allocator);
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
                retval = ast;
            }
        },
        .sub => {
            ast.sub.lhs = try validateAST(ast.sub.lhs, expected, scope, errors, allocator);
            var lhs_type = try ast.sub.lhs.typeof(scope, errors, allocator);
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
                retval = ast;
            }
        },
        .mult => {
            ast.mult.lhs = try validateAST(ast.mult.lhs, expected, scope, errors, allocator);
            var lhs_type = try ast.mult.lhs.typeof(scope, errors, allocator);
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
                retval = ast;
            }
        },
        .div => {
            ast.div.lhs = try validateAST(ast.div.lhs, expected, scope, errors, allocator);
            var lhs_type = try ast.div.lhs.typeof(scope, errors, allocator);
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
                retval = ast;
            }
        },
        .mod => {
            ast.mod.lhs = try validateAST(ast.mod.lhs, primitives.int_type, scope, errors, allocator);
            var lhs_type = try ast.mod.lhs.typeof(scope, errors, allocator);
            ast.mod.rhs = try validateAST(ast.mod.rhs, primitives.int_type, scope, errors, allocator);

            if (ast.mod.lhs.* == .poison or ast.mod.rhs.* == .poison) {
                return ast.enpoison();
            } else if (expected != null and !try primitives.int_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type } });
                return ast.enpoison();
            } else {
                retval = ast;
            }
        },
        .exponent => {
            std.debug.assert(ast.exponent.terms.items.len > 1);
            var new_terms = std.ArrayList(*AST).init(allocator);
            var poisoned = false;
            var changed = false;

            ast.exponent.terms.items[0] = try validateAST(ast.exponent.terms.items[0], expected, scope, errors, allocator);
            var lhs_type = try ast.exponent.terms.items[0].typeof(scope, errors, allocator);
            if (!try lhs_type.is_num_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "arithmetic", .got = lhs_type } });
                return ast.enpoison();
            }

            for (ast.exponent.terms.items) |term| {
                var new_term = try validateAST(term, lhs_type, scope, errors, allocator);
                try new_terms.append(new_term);
                changed = changed or new_term != term;
                poisoned = poisoned or new_term.* == .poison;
            }
            if (poisoned) {
                return ast.enpoison();
            } else if (changed) {
                ast.exponent.terms = new_terms;
            } else {
                new_terms.deinit();
            }
            if (expected != null and !try lhs_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type } });
                return ast.enpoison();
            } else {
                retval = ast;
            }
        },
        .equal => {
            ast.equal.lhs = try validateAST(ast.equal.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.equal.lhs.typeof(scope, errors, allocator);
            ast.equal.rhs = try validateAST(ast.equal.rhs, lhs_type, scope, errors, allocator);
            if (ast.equal.lhs.* == .poison or ast.equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_eq_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "equalable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            retval = ast;
        },
        .not_equal => {
            ast.not_equal.lhs = try validateAST(ast.not_equal.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.not_equal.lhs.typeof(scope, errors, allocator);
            ast.not_equal.rhs = try validateAST(ast.not_equal.rhs, lhs_type, scope, errors, allocator);
            if (ast.not_equal.lhs.* == .poison or ast.not_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_eq_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "equalable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            retval = ast;
        },
        .greater => {
            ast.greater.lhs = try validateAST(ast.greater.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.greater.lhs.typeof(scope, errors, allocator);
            ast.greater.rhs = try validateAST(ast.greater.rhs, lhs_type, scope, errors, allocator);
            if (ast.greater.lhs.* == .poison or ast.greater.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_ord_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "orderable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            retval = ast;
        },
        .lesser => {
            ast.lesser.lhs = try validateAST(ast.lesser.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.lesser.lhs.typeof(scope, errors, allocator);
            ast.lesser.rhs = try validateAST(ast.lesser.rhs, lhs_type, scope, errors, allocator);
            if (ast.lesser.lhs.* == .poison or ast.lesser.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_ord_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "orderable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            retval = ast;
        },
        .greater_equal => {
            ast.greater_equal.lhs = try validateAST(ast.greater_equal.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.greater_equal.lhs.typeof(scope, errors, allocator);
            ast.greater_equal.rhs = try validateAST(ast.greater_equal.rhs, lhs_type, scope, errors, allocator);
            if (ast.greater_equal.lhs.* == .poison or ast.greater_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_ord_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "ordered", .got = lhs_type } });
                return ast.enpoison();
            } else if (!try lhs_type.is_eq_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "equalable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            retval = ast;
        },
        .lesser_equal => {
            ast.lesser_equal.lhs = try validateAST(ast.lesser_equal.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.lesser_equal.lhs.typeof(scope, errors, allocator);
            ast.lesser_equal.rhs = try validateAST(ast.lesser_equal.rhs, lhs_type, scope, errors, allocator);
            if (ast.lesser_equal.lhs.* == .poison or ast.lesser_equal.rhs.* == .poison) {
                return ast.enpoison();
            }

            if (!try lhs_type.is_ord_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "ordered", .got = lhs_type } });
                return ast.enpoison();
            } else if (!try lhs_type.is_eq_type(scope, errors, allocator)) {
                errors.addError(Error{ .expectedBuiltinTypeclass = .{ .span = ast.getToken().span, .expected = "equalable", .got = lhs_type } });
                return ast.enpoison();
            } else if (expected != null and !try primitives.bool_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.bool_type } });
                return ast.enpoison();
            }
            retval = ast;
        },
        ._catch => {
            ast._catch.lhs = try validateAST(ast._catch.lhs, null, scope, errors, allocator);
            ast._catch.rhs = try validateAST(ast._catch.rhs, expected, scope, errors, allocator);
            var lhs_expanded_type = try (try ast._catch.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_error) {
                errors.addError(Error{ .basic = .{ .span = ast._catch.lhs.getToken().span, .msg = "left-hand side of catch is not an error type" } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_expanded_type.sum.terms.items[1].annotation.type.typesMatch(expected.?, scope, errors, allocator)) {
                // TODO: Print the correct expected and got type, to match orelse for this error.
                // Tough because we don't have the lhs error information... or maybe not?
                errors.addError(Error{ .expected2Type = .{ .span = ast._catch.lhs.getToken().span, .expected = expected.?, .got = lhs_expanded_type.sum.terms.items[1].annotation.type } });
                return ast.enpoison();
            } else {
                ast._catch.lhs = try validateAST(ast._catch.lhs, null, scope, errors, allocator);
            }
            if (ast._catch.lhs.* == .poison or ast._catch.rhs.* == .poison) {
                return ast.enpoison();
            }
            retval = ast;
        },
        ._orelse => {
            ast._orelse.lhs = try validateAST(ast._orelse.lhs, null, scope, errors, allocator);
            ast._orelse.rhs = try validateAST(ast._orelse.rhs, expected, scope, errors, allocator);
            var lhs_expanded_type = try (try ast._orelse.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_optional) {
                errors.addError(Error{ .basic = .{ .span = ast._orelse.lhs.getToken().span, .msg = "left-hand side of orelse is not an optional type" } });
                return ast.enpoison();
            } else if (expected != null and !try lhs_expanded_type.sum.terms.items[1].annotation.type.typesMatch(expected.?, scope, errors, allocator)) {
                var optional_expected = try AST.create_optional_type(expected.?, allocator);
                errors.addError(Error{ .expected2Type = .{ .span = ast._orelse.lhs.getToken().span, .expected = optional_expected, .got = lhs_expanded_type } });
                return ast.enpoison();
            }
            if (ast._orelse.lhs.* == .poison or ast._orelse.rhs.* == .poison) {
                return ast.enpoison();
            }
            retval = ast;
        },
        .call => {
            ast.call.lhs = try validateAST(ast.call.lhs, null, scope, errors, allocator);
            if (ast.call.lhs.* == .poison) {
                return ast.enpoison();
            }
            var lhs_type = try ast.call.lhs.typeof(scope, errors, allocator);
            var expanded_lhs_type = try lhs_type.expand_type(scope, errors, allocator);
            if (expanded_lhs_type.* != .function) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "call is not to a function" } });
                return ast.enpoison();
            }

            // Apply default arguments
            ast.call.args = default_args(ast.call.args, lhs_type.function.lhs, errors, allocator) catch |err| switch (err) {
                error.NoDefault => ast.call.args,
                error.typeError => return ast.enpoison(),
                error.OutOfMemory => return error.OutOfMemory,
            };

            // Validate
            var new_args = std.ArrayList(*AST).init(allocator);
            var changed = false;
            var poisoned = false;
            if (expanded_lhs_type.function.lhs.* == .unit) {
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
                    var new_arg = try validateAST(arg, param_type, scope, errors, allocator);
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

            if (expected != null and !try lhs_type.function.rhs.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.function.rhs } });
                return ast.enpoison();
            } else if (poisoned) {
                return ast.enpoison();
            } else if (changed) {
                ast.call.args = new_args;
            } else {
                new_args.deinit();
            }
            retval = ast;
        },
        .index => {
            var lhs_span = ast.index.lhs.getToken().span; // Used for error reporting
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
                retval = ast.index.lhs.product.terms.items[@as(usize, @intCast(ast.index.rhs.int.data))];
            } else if (lhs_type.* != .product and !(lhs_type.* == .identifier and std.mem.eql(u8, lhs_type.getToken().data, "String"))) {
                // TODO: Replace with check that lhs type implements Indexable
                errors.addError(Error{ .notIndexable = .{ .span = lhs_span, ._type = lhs_type } });
                return ast.enpoison();
            } else if (lhs_type.* == .product and !lhs_type.product.was_slice and !try lhs_type.product.is_homotypical(scope, errors, allocator)) {
                errors.addError(Error{ .basic = .{ .span = lhs_span, .msg = "array is not homotypical" } });
                return ast.enpoison();
            } else if (expected != null) {
                if (lhs_type.* == .product and !lhs_type.product.was_slice and !try lhs_type.product.terms.items[0].typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.product.terms.items[0] } });
                    return ast.enpoison();
                } else if (lhs_type.* == .product and lhs_type.product.was_slice and !try lhs_type.product.terms.items[0].annotation.type.addrOf.expr.typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.product.terms.items[0].annotation.type.addrOf.expr } });
                    return ast.enpoison();
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
                var inferred_member = try AST.createInferredMember(ast.getToken(), ast.select.rhs, allocator);
                retval = try validateAST(inferred_member, ast.select.lhs, scope, errors, allocator);
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
                    retval = ast;
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
                retval = ast;
            }
        },
        .sum => {
            var poisoned = false;
            var changed = false;
            var new_terms = std.ArrayList(*AST).init(allocator);
            var idents_seen = std.StringArrayHashMap(*AST).init(allocator);
            defer idents_seen.deinit();
            for (ast.sum.terms.items) |term| {
                // Make sure identifiers aren't repeated
                if (term.* == .annotation) {
                    var new_term = try validateAST(term, primitives.type_type, scope, errors, allocator);
                    changed = changed or new_term != term;
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                    var name = term.annotation.pattern.getToken().data;
                    var res = try idents_seen.fetchPut(name, term);
                    if (res) |_res| {
                        errors.addError(Error{ .sum_duplicate = .{ .span = term.getToken().span, .identifier = name, .first = _res.value.getToken().span } });
                        return ast.enpoison();
                    }
                } else if (term.* == .identifier) {
                    var new_annotation = try AST.createAnnotation(term.getToken(), term, primitives.unit_type, null, null, allocator);
                    new_annotation.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = new_annotation } };
                    changed = true;
                    try new_terms.append(new_annotation);
                    var name = term.getToken().data;
                    var res = try idents_seen.fetchPut(name, term);
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
                retval = ast;
            }
        },
        .inject => {
            var domain = try domainof(ast, expected, scope, errors, allocator);
            if (domain.* == .poison) {
                return domain;
            }
            ast.inject.lhs.inferredMember.init = try validateAST(ast.inject.rhs, domain, scope, errors, allocator);
            if (ast.inject.lhs.inferredMember.init.?.* == .poison) {
                return ast.enpoison();
            }
            ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
            retval = ast.inject.lhs;
        },

        .product => {
            var poisoned = false;
            var changed = false;
            var new_terms = std.ArrayList(*AST).init(allocator);
            var expanded_expected: ?*AST = if (expected == null) null else try expected.?.expand_type(scope, errors, allocator);
            if (expanded_expected != null and try expanded_expected.?.typesMatch(primitives.type_type, scope, errors, allocator)) {
                // Expecting ast to be a product type
                for (ast.product.terms.items) |term| {
                    var new_term = try validateAST(term, primitives.type_type, scope, errors, allocator);
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
                    var new_term = try validateAST(term, expected_term, scope, errors, allocator);
                    changed = changed or new_term != term;
                    try new_terms.append(new_term);
                    if (new_term.* == .poison) {
                        poisoned = true;
                    }
                }
            } else if (expanded_expected == null) {
                // Not expecting anything
                for (ast.product.terms.items) |term| {
                    var new_term = try validateAST(term, null, scope, errors, allocator);
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
            retval = ast;
        },
        ._union => {
            // Save spans since lhs and rhs are expanded, need spans for errors
            var lhs_span = ast._union.lhs.getToken().span;
            var rhs_span = ast._union.rhs.getToken().span;

            ast._union.lhs = try validateAST(ast._union.lhs, primitives.type_type, scope, errors, allocator);
            ast._union.rhs = try validateAST(ast._union.rhs, primitives.type_type, scope, errors, allocator);
            if (ast._union.lhs.* == .poison or ast._union.rhs.* == .poison) {
                return ast.enpoison();
            }

            var expand_lhs = try ast._union.lhs.expand_type(scope, errors, allocator);
            var expand_rhs = try ast._union.rhs.expand_type(scope, errors, allocator);
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

                retval = try AST.createSum(ast.getToken(), new_terms, allocator);
            }
        },
        .addrOf => {
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
                    var expanded_expected = try expected.?.expand_type(scope, errors, allocator); // Call is memoized
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
                    validateLValue(ast.addrOf.expr, scope, errors) catch |err| switch (err) {
                        error.typeError => return ast.enpoison(),
                        else => return err,
                    };
                    if (ast.addrOf.mut) {
                        assertMutable(ast.addrOf.expr, scope, errors, allocator) catch |err| switch (err) {
                            error.typeError => return ast.enpoison(), // Soft unreachable, will be caught early but is still good to have this here
                            else => return err,
                        };
                    }
                }
            }
            retval = ast;
        },
        .sliceOf => {
            var was_type = false;
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                // Slice-of type, type of this ast must be a type, inner must be a type

                ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, primitives.type_type, scope, errors, allocator);
                if (ast.sliceOf.expr.* == .poison) {
                    return ast.enpoison();
                }
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
                        // TODO: Compile-time evaluate array size
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
                    if (ast.sliceOf.len.?.int.data == 1) {
                        retval = new_terms.items[0];
                    } else {
                        retval = try AST.createProduct(ast.getToken(), new_terms, allocator);
                    }
                } else {
                    // Regular slice type, change to product of data address and length
                    retval = try AST.create_slice_type(ast.sliceOf.expr, ast.sliceOf.kind == .MUT, allocator);
                }
                was_type = true;
            } else {
                // Slice-of value, expected must be an slice, inner must match with expected's inner
                if (ast.sliceOf.kind != .SLICE and ast.sliceOf.kind != .MUT) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "array length is not allowed in slice-of operator" } });
                    return ast.enpoison();
                }
                ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, null, scope, errors, allocator);
                if (ast.sliceOf.expr.* == .poison) {
                    return ast.enpoison();
                }

                // ast.sliceOf.expr must be homotypical product type of expected
                var expr_type = try ast.sliceOf.expr.typeof(scope, errors, allocator);
                if (expr_type.* != .product or !try expr_type.product.is_homotypical(scope, errors, allocator)) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "attempt to take slice-of something that is not an array" } });
                    return ast.enpoison();
                }

                ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                if (expected != null and !try (try ast.typeof(scope, errors, allocator)).typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator) } });
                    return ast.enpoison();
                }

                validateLValue(ast.sliceOf.expr, scope, errors) catch |err| switch (err) {
                    error.typeError => return ast.enpoison(), // soft unreachable, will be rejected because not a slice type
                    else => return err,
                };
                if (ast.sliceOf.kind == .MUT) {
                    assertMutable(ast.sliceOf.expr, scope, errors, allocator) catch |err| switch (err) {
                        error.typeError => return ast.enpoison(), // soft unreachable, will be rejected because not a slice type
                        else => return err,
                    };
                }

                // Restructrure as product
                var new_terms = std.ArrayList(*AST).init(allocator);
                var zero = try AST.createInt(ast.getToken(), 0, allocator);
                zero.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = zero } };
                var index = try AST.createIndex(
                    ast.getToken(),
                    ast.sliceOf.expr,
                    zero,
                    allocator,
                );
                index.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = index } };
                var addr = try AST.createAddrOf(
                    ast.getToken(),
                    index,
                    ast.sliceOf.kind == .MUT,
                    allocator,
                );
                addr.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = addr } };
                try new_terms.append(addr);

                var length = try AST.createInt(ast.getToken(), expr_type.product.terms.items.len, allocator);
                length.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = length } };
                try new_terms.append(length);

                retval = try AST.createProduct(ast.getToken(), new_terms, allocator);
                retval.product.was_slice = true;
            }
        },
        .subSlice => {
            ast.subSlice.super = try validateAST(ast.subSlice.super, null, scope, errors, allocator);
            if (ast.subSlice.super.* == .poison) {
                return ast.enpoison();
            }
            var super_type = try ast.subSlice.super.typeof(scope, errors, allocator);
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
                var length = try AST.createIdentifier(Token.create("length", null, "", 0, 0), allocator);
                length.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = length } };
                var index = try AST.createSelect(
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
            retval = ast;
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
                retval = ast;
            }
        },
        .inferredMember => {
            var expected_expanded: *AST = undefined;
            if (expected != null) {
                expected_expanded = try expected.?.expand_type(scope, errors, allocator);
            }
            if (expected == null) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot infer the sum type" } });
                return ast.enpoison();
            } else if (expected != null and expected_expanded.* != .sum) {
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
            ast._if.condition = try validateAST(ast._if.condition, primitives.bool_type, ast._if.scope.?, errors, allocator);
            if (expected != null) {
                // expecting a type
                var expected_expanded = try expected.?.expand_type(scope, errors, allocator);
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
            retval = ast;
        },
        .match => {
            var poisoned = false;
            if (ast.match.let) |let| {
                ast.match.let = try validateAST(let, null, scope, errors, allocator);
                poisoned = ast.match.let.?.* == .poison or poisoned;
            }
            ast.match.expr = try validateAST(ast.match.expr, null, ast.match.scope.?, errors, allocator);
            poisoned = ast.match.expr.* == .poison or poisoned;

            var expr_type = try ast.match.expr.typeof(scope, errors, allocator);
            var expr_type_expanded = try expr_type.expand_type(scope, errors, allocator);
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
                    var is_expected_optional = expected_expanded.* == .sum and expected_expanded.sum.was_optional;
                    var has_else = ast.match.has_else;
                    if (has_else) {
                        // match has `else` => validate regular expected type
                        var new_mapping = try validateAST(mapping, expected, ast.match.scope.?, errors, allocator);
                        try new_mappings.append(new_mapping);
                        changed = changed or new_mapping != mapping;
                        poisoned = poisoned or new_mapping.* == .poison;
                    } else if (is_expected_optional) {
                        // match has no `else`, expecting an optional type => validate mappings w/ base of optional expected type
                        var full_type = expected_expanded.sum.terms.items[1];
                        var new_mapping = try validateAST(mapping, full_type, ast.match.scope.?, errors, allocator);
                        try new_mappings.append(new_mapping);
                        changed = changed or new_mapping != mapping;
                        poisoned = poisoned or new_mapping.* == .poison;
                    } else {
                        // match has no else, not expecting an optional type => type error
                        var new_map = try validateAST(mapping, expected.?, ast.match.scope.?, errors, allocator);
                        ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = ast } };
                        errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try new_map.typeof(scope, errors, allocator) } });
                        return ast.enpoison();
                    }
                } else {
                    // Not expecting anything => validate mappings with null type
                    var new_mapping = try validateAST(mapping, null, ast.match.scope.?, errors, allocator);
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
            retval = ast;
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
            retval = ast;
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
                return ast.enpoison();
            }
            retval = ast;
        },
        .block => {
            var changed = false;
            var poisoned = false;
            var new_statements = std.ArrayList(*AST).init(allocator);
            if (ast.block.final) |final| {
                // Has final

                for (ast.block.statements.items) |statement| {
                    var new_statement = try validateAST(statement, null, ast.block.scope.?, errors, allocator);
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
                    var expect_type: ?*AST = if (i == ast.block.statements.items.len - 1) expected else null;
                    var new_statement = try validateAST(statement, expect_type, ast.block.scope.?, errors, allocator);
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
                    // std.debug.assert(ast.block.statements.items.len == 0); // this this true? what about a block that ends in a defer? or a decl?
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = block_type } });
                    return ast.enpoison();
                }
            }
            if (poisoned) {
                return ast.enpoison();
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
                } });
                return ast.enpoison();
            }
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            retval = ast;
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
            retval = ast;
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
                ast._return.expr = try validateAST(expr, scope.inner_function.?._type.?.function.rhs, scope, errors, allocator);
                if (ast._return.expr.?.* == .poison) {
                    return ast.enpoison();
                }
            } else if (expected != null and (try expected.?.expand_type(scope, errors, allocator)).* != .unit) {
                // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            retval = ast;
        },
        ._unreachable => {
            if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = primitives.void_type } });
                return ast.enpoison();
            }
            retval = ast;
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
            retval = ast;
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
            retval = ast;
        },
        .fnDecl => {
            try validateSymbol(ast.fnDecl.symbol.?, errors, allocator);
            if (ast.fnDecl.symbol.?._type.?.* == .poison) {
                return ast.enpoison();
            }
            if (expected) |_expected| {
                var expected_expanded = try _expected.expand_type(scope, errors, allocator);
                var self_type = try ast.typeof(scope, errors, allocator);
                if (!try expected_expanded.typesMatch(self_type, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected_expanded, .got = self_type } });
                    return ast.enpoison();
                }
            }
            retval = ast;
        },
        .decl => {
            var poisoned = false;
            if (ast.decl.type != null and ast.decl.init != null) {
                // Normal decl
                ast.decl.type = try validateAST(ast.decl.type.?, primitives.type_type, scope, errors, allocator);
                if (ast.decl.type.?.* != .poison) {
                    ast.decl.init = try validateAST(ast.decl.init.?, ast.decl.type, scope, errors, allocator);
                    poisoned = ast.decl.init.?.* == .poison;
                } else {
                    return ast.enpoison();
                }
            } else if (ast.decl.init == null) {
                // Default value
                ast.decl.type = try validateAST(ast.decl.type.?, primitives.type_type, scope, errors, allocator);
                poisoned = ast.decl.type.?.* == .poison;
            } else if (ast.decl.type == null) {
                // Infer type
                ast.decl.init = try validateAST(ast.decl.init.?, null, scope, errors, allocator);
                if (ast.decl.init.?.* != .poison) {
                    ast.decl.type = try validateAST(try ast.decl.init.?.typeof(scope, errors, allocator), primitives.type_type, scope, errors, allocator);
                    poisoned = ast.decl.type.?.* == .poison;
                } else {
                    return ast.enpoison();
                }
            } else {
                unreachable;
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
            retval = ast;
        },
        else => {
            std.debug.print("validateAST() unimplemented for {s}\n", .{@tagName(ast.*)});
            unreachable;
        },
    }

    if (expected != null and try primitives.type_type.typesMatch(expected.?, scope, errors, allocator)) {
        _ = try retval.expand_type(scope, errors, allocator);
    }

    ast.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = retval } };
    retval.getCommon().validation_state = _ast.Validation_State{ .valid = .{ .valid_form = retval } };
    return retval;
}

fn default_args(asts: std.ArrayList(*AST), expected: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) !std.ArrayList(*AST) {
    if (try args_are_named(asts, errors)) {
        return named_args(asts, expected, errors, allocator);
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

        .unit => {
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

fn named_args(asts: std.ArrayList(*AST), expected: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) !std.ArrayList(*AST) {
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
    switch (expected.*) {
        .annotation => {
            if (arg_map.keys().len != 1) { // Cannot be 0, since that is technically a positional arglist
                errors.addError(Error{ .basic = .{
                    .span = asts.items[0].getToken().span,
                    .msg = "too many arguments specifed",
                } });
                return error.NoDefault;
            } else {
                try retval.append(arg_map.values()[0]);
            }
        },

        .product => {
            for (expected.product.terms.items) |term| {
                if (term.* != .annotation) {
                    errors.addError(Error{ .basic = .{
                        .span = asts.items[0].getToken().span,
                        .msg = "expected type does not accept named arugments",
                    } });
                    return error.NoDefault;
                }
                var arg = arg_map.get(term.annotation.pattern.getToken().data);
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
    var name = ast.assign.lhs.inferredMember.ident.getToken().data;
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
    var name = ast.annotation.pattern.getToken().data;
    if (arg_map.get(name)) |_| {
        errors.addError(Error{ .basic = .{
            .span = ast.getToken().span,
            .msg = "duplicate annotation identifiers detected",
        } });
        return error.typeError;
    } else {
        try arg_map.put(name, ast.annotation.type);
    }
}

pub fn findSymbol(ast: *AST, expected: ?*AST, scope: *Scope, errors: *errs.Errors) !*Symbol {
    var symbol = scope.lookup(ast.getToken().data, false) orelse {
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
            var symbol = try findSymbol(ast, null, scope, errors);
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
            var child_type = try child.typeof(scope, errors, allocator);
            if (!child_type.addrOf.mut) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "cannot modify non-mutable address",
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
        .unit => {
            if (!try expr_type.typesMatch(primitives.unit_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = primitives.unit_type } });
                return error.typeError;
            }
        },
        .int => {
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
            var pattern_type = try new_pattern.typeof(scope, errors, allocator);
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
            var pattern_type = try new_pattern.typeof(scope, errors, allocator);
            if (!try expr_type.typesMatch(pattern_type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = pattern.getToken().span, .expected = expr_type, .got = pattern_type } });
                return error.typeError;
            }
        },
        .inject => {
            var domain = try domainof(pattern, expr_type, scope, errors, allocator);
            if (domain.* == .poison) {
                return error.typeError;
            }
            try assert_pattern_matches(pattern.inject.rhs, domain, scope, errors, allocator);
        },
        .product => {
            var expanded_expr = try expr_type.expand_type(scope, errors, allocator);
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
            var id: ?usize = indexof(ids, @intCast(ast.select.pos.?));
            if (id) |_id| {
                _ = ids.swapRemove(_id);
            }
        },
        .inferredMember => {
            var id: ?usize = indexof(ids, @intCast(ast.inferredMember.pos.?));
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
    var expanded_lhs_type = try lhs_type.expand_type(scope, errors, allocator);
    if (expanded_lhs_type.* == .sum and ast.inject.lhs.* == .inferredMember) {
        if (sum_type != null and !try sum_type.?.typesMatch(lhs_type, scope, errors, allocator)) {
            errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = sum_type.?, .got = ast.inject.lhs.inferredMember.base.? } });
            return _ast.poisoned;
        }
        var pos: i128 = ast.inject.lhs.inferredMember.pos.?;
        var proper_term: *AST = (try ast.inject.lhs.typeof(scope, errors, allocator)).sum.terms.items[@as(usize, @intCast(pos))];
        return proper_term.annotation.type;
    } else {
        errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "inject is not to a sum" } });
        return _ast.poisoned;
    }
}
