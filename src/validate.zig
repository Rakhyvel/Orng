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
        var symbol = scope.symbols.get(key) orelse {
            std.debug.print("{s} doesn't exist in this scope\n", .{key});
            return error.typeError;
        };
        try validateSymbol(symbol, errors, allocator);
    }
    for (scope.children.items) |child| {
        try validateScope(child, errors, allocator);
    }
}

pub fn validateSymbol(symbol: *Symbol, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, Unimplemented, OutOfMemory }!void {
    if (symbol.valid) {
        return;
    }
    symbol.valid = true;

    if (symbol.kind == ._fn) {
        symbol._type.? = try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors, allocator);
        symbol.init = try validateAST(symbol.init.?, symbol._type.?.function.rhs, symbol.scope, errors, allocator);
    } else {
        if (symbol.init != null and symbol._type != null) {
            symbol._type = try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors, allocator);
            symbol.init = try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
        } else if (symbol.init == null) {
            // Default value (probably done at the IR side?) OR function parameter
            symbol._type = try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors, allocator);
        } else if (symbol._type == null) {
            // Infer type
            symbol.init = try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
            symbol._type = try validateAST(try symbol.init.?.typeof(symbol.scope, errors, allocator), _ast.typeType, symbol.scope, errors, allocator);
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
            error.typeError => return error.typeError,
            error.OutOfMemory => return error.OutOfMemory,
        };
    }

    if (expected != null and expected.?.* == .annotation) {
        expected = expected.?.annotation.type;
    }
    if (expected) |exp| {
        std.debug.assert(exp.getCommon().is_valid);
    }

    switch (ast.*) {
        .unit => {
            if (expected != null and !try expected.?.typesMatch(_ast.unitType, scope, errors, allocator) and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .int => {
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .char => {
            if (expected != null and !try expected.?.typesMatch(_ast.charType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.charType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .string => {
            if (expected != null and !try expected.?.typesMatch(_ast.stringType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.stringType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .float => {
            if (expected != null and !try expected.?.typesMatch(_ast.floatType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .identifier => {
            // look up symbol, that's the type
            var symbol = try findSymbol(ast, scope, errors);
            try validateSymbol(symbol, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(symbol._type.?, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = symbol._type.?, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        ._true => {
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        ._false => {
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .not => {
            ast.not.expr = try validateAST(ast.not.expr, _ast.boolType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .negate => {
            ast.negate.expr = try validateAST(ast.negate.expr, _ast.floatType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .dereference => {
            if (expected != null) {
                var addr_of = try _ast.AST.createAddrOf(ast.getToken(), expected.?, false, std.heap.page_allocator);
                addr_of.getCommon().is_valid = true;
                ast.dereference.expr = try validateAST(ast.dereference.expr, addr_of, scope, errors, allocator);

                ast.getCommon().is_valid = true;
                var ast_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !try expected.?.typesMatch(ast_type, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                    return error.typeError;
                }
            } else {
                ast.dereference.expr = try validateAST(ast.dereference.expr, null, scope, errors, allocator);
            }
            retval = ast;
        },
        ._error => {
            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return error.typeError;
            }
            ast._error.lhs = try validateAST(ast._error.lhs, _ast.typeType, scope, errors, allocator);
            ast._error.rhs = try validateAST(ast._error.rhs, _ast.typeType, scope, errors, allocator);
            retval = try AST.create_error_type(ast._error.lhs, ast._error.rhs, allocator);
        },
        ._try => {
            var lhs_expanded_type = try (try ast._try.expr.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_error) {
                // lhs is not even an expected type
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "try is not of an error expression", .stage = .typecheck } });
                return error.typeError;
            } else if (expected != null and !try expected.?.typesMatch(lhs_expanded_type.sum.terms.items[1].annotation.type, scope, errors, allocator)) {
                // Error union, but .err field types don't match with expected
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                // Everything is fine, validate expr without an expectation of a type
                ast._try.expr = try validateAST(ast._try.expr, null, scope, errors, allocator);
            }
            retval = ast;
        },
        .optional => {
            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return error.typeError;
            }
            ast.optional.expr = try validateAST(ast.optional.expr, _ast.typeType, scope, errors, allocator);
            retval = try AST.create_optional_type(ast.optional.expr, allocator);
        },
        .assign => {
            ast.assign.lhs = try validateAST(ast.assign.lhs, null, scope, errors, allocator);
            ast.assign.rhs = try validateAST(ast.assign.rhs, try ast.assign.lhs.typeof(scope, errors, allocator), scope, errors, allocator);
            try validateLValue(ast.assign.lhs, scope, errors);
            try assertMutable(ast.assign.lhs, scope, errors, allocator);
            retval = ast;
        },
        ._or => {
            ast._or.lhs = try validateAST(ast._or.lhs, _ast.boolType, scope, errors, allocator);
            ast._or.rhs = try validateAST(ast._or.rhs, _ast.boolType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        ._and => {
            ast._and.lhs = try validateAST(ast._and.lhs, _ast.boolType, scope, errors, allocator);
            ast._and.rhs = try validateAST(ast._and.rhs, _ast.boolType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .add => {
            ast.add.lhs = try validateAST(ast.add.lhs, _ast.floatType, scope, errors, allocator);
            ast.add.rhs = try validateAST(ast.add.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .sub => {
            ast.sub.lhs = try validateAST(ast.sub.lhs, _ast.floatType, scope, errors, allocator);
            ast.sub.rhs = try validateAST(ast.sub.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .mult => {
            ast.mult.lhs = try validateAST(ast.mult.lhs, _ast.floatType, scope, errors, allocator);
            ast.mult.rhs = try validateAST(ast.mult.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .div => {
            ast.div.lhs = try validateAST(ast.div.lhs, _ast.floatType, scope, errors, allocator);
            ast.div.rhs = try validateAST(ast.div.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .mod => {
            ast.mod.lhs = try validateAST(ast.mod.lhs, _ast.floatType, scope, errors, allocator);
            ast.mod.rhs = try validateAST(ast.mod.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .exponent => {
            var new_terms = std.ArrayList(*AST).init(allocator);
            for (ast.exponent.terms.items) |term| {
                try new_terms.append(try validateAST(term, _ast.floatType, scope, errors, allocator));
            }
            ast.exponent.terms = new_terms;
            if (expected != null and !try expected.?.typesMatch(_ast.intType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        ._catch => {
            ast._catch.rhs = try validateAST(ast._catch.rhs, expected, scope, errors, allocator);
            var lhs_expanded_type = try (try ast._catch.lhs.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_error) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "left-hand side of catch is not an error type", .stage = .typecheck } });
                return error.typeError;
            } else if (expected != null and !try expected.?.typesMatch(lhs_expanded_type.sum.terms.items[1].annotation.type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                ast._catch.lhs = try validateAST(ast._catch.lhs, null, scope, errors, allocator);
            }
            retval = ast;
        },
        ._orelse => {
            ast._orelse.rhs = try validateAST(ast._orelse.rhs, expected, scope, errors, allocator);
            var lhs_expanded_type = try (try ast._orelse.lhs.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);
            if (lhs_expanded_type.* != .sum or !lhs_expanded_type.sum.was_optional) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "left-hand side of orelse is not an optional type", .stage = .typecheck } });
                return error.typeError;
            } else if (expected != null and !try expected.?.typesMatch(lhs_expanded_type.sum.terms.items[1].annotation.type, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                ast._orelse.lhs = try validateAST(ast._orelse.lhs, null, scope, errors, allocator);
            }
            retval = ast;
        },
        .call => {
            ast.call.lhs = try validateAST(ast.call.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.call.lhs.typeof(scope, errors, allocator);
            var expanded_lhs_type = try lhs_type.exapnd_type(scope, errors, allocator);
            if (expanded_lhs_type.* == .function) {
                ast.call.rhs = try validateAST(ast.call.rhs, lhs_type.function.lhs, scope, errors, allocator);

                if (expected != null and !try expected.?.typesMatch(lhs_type.function.rhs, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.function.rhs, .stage = .typecheck } });
                    return error.typeError;
                } else {
                    retval = ast;
                }
            } else {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "call is not to a function", .stage = .typecheck } });
                return error.typeError;
            }
        },
        .index => {
            ast.index.lhs = try validateAST(ast.index.lhs, null, scope, errors, allocator);
            ast.index.rhs = try validateAST(ast.index.rhs, _ast.intType, scope, errors, allocator);

            var lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);

            // Implicit dereference
            if (lhs_type.* == .addrOf) {
                ast.index.lhs = try validateAST(try AST.createDereference(ast.getToken(), ast.index.lhs, allocator), null, scope, errors, allocator);
                lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);
            }

            if (lhs_type.* == .product and !lhs_type.product.was_slice and !try lhs_type.product.is_homotypical(scope, errors, allocator)) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "array is not homotypical", .stage = .typecheck } });
                return error.typeError;
            }

            if (expected != null) {
                if (lhs_type.* == .product and !lhs_type.product.was_slice and !try expected.?.typesMatch(lhs_type.product.terms.items[0], scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type, .stage = .typecheck } });
                    return error.typeError;
                } else if (lhs_type.* == .product and lhs_type.product.was_slice and !try expected.?.typesMatch(lhs_type.product.terms.items[0].annotation.type.addrOf.expr, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type, .stage = .typecheck } });
                    return error.typeError;
                } else {
                    retval = ast;
                }
            } else {
                retval = ast;
            }
        },
        .select => {
            ast.select.lhs = try validateAST(ast.select.lhs, null, scope, errors, allocator);

            var select_lhs_type = try (try ast.select.lhs.typeof(scope, errors, allocator)).exapnd_type(scope, errors, allocator);

            // Implicit dereference
            if (select_lhs_type.* == .addrOf) {
                ast.select.lhs = try validateAST(try AST.createDereference(ast.getToken(), ast.select.lhs, allocator), null, scope, errors, allocator);
                select_lhs_type = try ast.select.lhs.typeof(scope, errors, allocator);
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
                return error.typeError;
            } else {
                ast.getCommon().is_valid = true;
                var ast_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !try expected.?.typesMatch(ast_type, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast_type, .stage = .typecheck } });
                    return error.typeError;
                } else {
                    retval = ast;
                }
            }
        },
        .function => {
            ast.function.lhs = try validateAST(ast.function.lhs, _ast.typeType, scope, errors, allocator);
            ast.function.rhs = try validateAST(ast.function.rhs, _ast.typeType, scope, errors, allocator);
            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .sum => {
            var new_terms = std.ArrayList(*AST).init(allocator);
            var idents_seen = std.StringArrayHashMap(void).init(allocator);
            defer idents_seen.deinit();
            for (ast.sum.terms.items) |term| {
                // Make sure identifiers aren't repeated
                if (term.* == .annotation) {
                    try new_terms.append(try validateAST(term, _ast.typeType, scope, errors, allocator));
                    var res = try idents_seen.fetchPut(term.annotation.pattern.getToken().data, {});
                    if (res) |_| {
                        errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "duplication of sum member", .stage = .typecheck } });
                        return error.typeError;
                    }
                } else if (term.* == .identifier) {
                    var new_annotation = try AST.createAnnotation(term.getToken(), term, _ast.unitType, null, null, allocator);
                    new_annotation.getCommon().is_valid = true;
                    try new_terms.append(new_annotation);
                    var res = try idents_seen.fetchPut(term.getToken().data, {});
                    if (res) |_| {
                        errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "duplication of sum member", .stage = .typecheck } });
                        return error.typeError;
                    }
                } else {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "invalid sum expression, must be annotation or identifier", .stage = .typecheck } });
                    return error.typeError;
                }
            }
            ast.sum.terms = new_terms;
            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
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
            var lhs_type = try ast.inject.lhs.typeof(scope, errors, allocator);
            var expanded_lhs_type = try lhs_type.exapnd_type(scope, errors, allocator);
            if (expanded_lhs_type.* == .sum and ast.inject.lhs.* == .inferredMember) {
                if (expected != null and !try expected.?.typesMatch(lhs_type, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type, .stage = .typecheck } });
                    return error.typeError;
                }
                var pos: i128 = ast.inject.lhs.inferredMember.pos.?;
                var proper_term: *AST = ast.inject.lhs.inferredMember.base.?.sum.terms.items[@as(usize, @intCast(pos))];

                ast.inject.lhs.inferredMember.init = try validateAST(ast.inject.rhs, proper_term.annotation.type, scope, errors, allocator);
                retval = ast.inject.lhs;
            } else {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "inject is not to a sum", .stage = .typecheck } });
                return error.typeError;
            }
        },
        .product => {
            var new_terms = std.ArrayList(*AST).init(allocator);
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                for (ast.product.terms.items) |term| {
                    try new_terms.append(try validateAST(term, _ast.typeType, scope, errors, allocator));
                }
                ast.product.terms = new_terms;
            } else if (expected != null and expected.?.* == .product) {
                if (expected.?.product.terms.items.len != ast.product.terms.items.len) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                }
                for (ast.product.terms.items, expected.?.product.terms.items) |term, expected_term| { // Ok, this is cool!
                    try new_terms.append(try validateAST(term, expected_term, scope, errors, allocator));
                }
                ast.product.terms = new_terms;
            } else if (expected == null) {
                for (ast.product.terms.items) |term| {
                    try new_terms.append(try validateAST(term, null, scope, errors, allocator));
                }
                ast.product.terms = new_terms;
            } else {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return error.typeError;
                // unreachable;
            }
            retval = ast;
        },
        ._union => {
            ast._union.lhs = try validateAST(ast._union.lhs, _ast.typeType, scope, errors, allocator);
            ast._union.rhs = try validateAST(ast._union.rhs, _ast.typeType, scope, errors, allocator);

            var expand_lhs = try ast._union.lhs.exapnd_type(scope, errors, allocator);
            var expand_rhs = try ast._union.rhs.exapnd_type(scope, errors, allocator);
            if (expand_lhs.* != .sum or expand_rhs.* != .sum) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "the union operator is not applied to a sum type", .stage = .typecheck } });
                return error.typeError;
            } else if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return error.typeError;
            } else {
                var new_terms = std.ArrayList(*AST).init(allocator);
                var names = std.StringArrayHashMap(*AST).init(allocator);

                for (expand_lhs.sum.terms.items) |term| {
                    try putAnnotation(term, &names, errors);
                    try new_terms.append(term);
                }
                for (expand_rhs.sum.terms.items) |term| {
                    try putAnnotation(term, &names, errors);
                    try new_terms.append(term);
                }

                retval = try AST.createSum(ast.getToken(), new_terms, allocator);
            }
        },
        .conditional => {
            var new_exprs = std.ArrayList(*AST).init(allocator);
            for (ast.conditional.exprs.items) |child| {
                try new_exprs.append(try validateAST(child, _ast.floatType, scope, errors, allocator));
            }
            ast.conditional.exprs = new_exprs;
            if (expected != null and !try expected.?.typesMatch(_ast.boolType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .addrOf => {
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                // Address type, type of this ast must be a type, inner must be a type
                ast.addrOf.expr = try validateAST(ast.addrOf.expr, _ast.typeType, scope, errors, allocator);
                var ast_type: *AST = try ast.addrOf.expr.typeof(scope, errors, allocator);
                if (!try ast_type.typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return error.typeError;
                }
            } else if (expected != null and expected.?.* == .addrOf) {
                // Address value, expected must be an address, inner must match with expected's inner
                ast.addrOf.expr = try validateAST(ast.addrOf.expr, expected.?.addrOf.expr, scope, errors, allocator);
                ast.getCommon().is_valid = true;
                if (!try expected.?.typesMatch(try ast.typeof(scope, errors, allocator), scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return error.typeError;
                }
                try validateLValue(ast.addrOf.expr, scope, errors);
                if (ast.addrOf.mut) {
                    try assertMutable(ast.addrOf.expr, scope, errors, allocator);
                }
            } else if (expected == null) {
                ast.addrOf.expr = try validateAST(ast.addrOf.expr, null, scope, errors, allocator);
                try validateLValue(ast.addrOf.expr, scope, errors);
            } else {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                return error.typeError;
            }
            retval = ast;
        },
        .sliceOf => {
            var was_type = false;
            if (expected != null and try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                // Slice-of type, type of this ast must be a type, inner must be a type
                ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, _ast.typeType, scope, errors, allocator);
                var ast_type: *AST = try ast.sliceOf.expr.typeof(scope, errors, allocator);
                if (!try ast_type.typesMatch(expected.?, scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return error.typeError;
                } else {
                    if (ast.sliceOf.len) |len| {
                        ast.sliceOf.len = try validateAST(len, _ast.intType, scope, errors, allocator);
                    }
                }
                if (ast.sliceOf.kind == .ARRAY) {
                    // Inflate to product
                    var new_terms = std.ArrayList(*AST).init(allocator);
                    for (0..@as(usize, @intCast(ast.sliceOf.len.?.int.data))) |_| {
                        try new_terms.append(ast.sliceOf.expr);
                    }
                    ast = try AST.createProduct(ast.getToken(), new_terms, allocator);
                } else {
                    // Regular slice type, change to product of data address and length
                    ast = try AST.create_slice_type(ast.sliceOf.expr, ast.sliceOf.kind == .MUT, allocator);
                }
                was_type = true;
            } else {
                ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, null, scope, errors, allocator);

                // Slice-of value, expected must be an slice, inner must match with expected's inner
                // ast.sliceOf.expr must be homotypical product type of expected
                var expr_type = try ast.sliceOf.expr.typeof(scope, errors, allocator);
                ast.getCommon().is_valid = true;
                if (expr_type.* != .product or !try expr_type.product.is_homotypical(scope, errors, allocator)) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "attempt to take slice-of something that is not an array", .stage = .typecheck } });
                    return error.typeError;
                } else if (expected != null and !try expected.?.typesMatch(try ast.typeof(scope, errors, allocator), scope, errors, allocator)) {
                    errors.addError(Error{ .expected2Type = .{
                        .span = ast.getToken().span,
                        .expected = expected.?,
                        .got = try ast.typeof(scope, errors, allocator),
                        .stage = .typecheck,
                    } });
                    return error.typeError;
                } else if (ast.sliceOf.len != null or ast.sliceOf.kind == .ARRAY) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "illegal length specifier in slice-of operator", .stage = .typecheck } });
                    return error.typeError;
                }

                try validateLValue(ast.sliceOf.expr, scope, errors);

                if (ast.sliceOf.kind == .MUT) {
                    try assertMutable(ast.sliceOf.expr, scope, errors, allocator);
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
            var super_type = try ast.subSlice.super.typeof(scope, errors, allocator);
            if (super_type.* != .product or !super_type.product.was_slice) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "cannot take a sub-slice of something that is not a slice", .stage = .typecheck } });
                return error.typeError;
            } else {
                ast.subSlice.super = try validateAST(ast.subSlice.super, null, scope, errors, allocator);
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
                    try AST.createIdentifier(Token.create("length", null, 0, 0), allocator),
                    allocator,
                );
                ast.subSlice.upper = try validateAST(index, _ast.intType, scope, errors, allocator);
            }
            retval = ast;
        },
        .annotation => {
            ast.annotation.type = try validateAST(ast.annotation.type, _ast.typeType, scope, errors, allocator);
            if (ast.annotation.init != null) {
                ast.annotation.init = try validateAST(ast.annotation.init.?, ast.annotation.type, scope, errors, allocator);
            }

            if (expected != null and !try expected.?.typesMatch(_ast.typeType, scope, errors, allocator)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
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
                return error.typeError;
            } else if (expected != null and expected_expanded.* != .sum) {
                // TODO: Better error message
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected a sum type", .stage = .typecheck } });
                return error.typeError;
            } else {
                ast.inferredMember.base = expected_expanded;
                for (expected_expanded.sum.terms.items, 0..) |term, i| {
                    if (std.mem.eql(u8, term.annotation.pattern.getToken().data, ast.inferredMember.ident.getToken().data)) {
                        ast.inferredMember.pos = i;
                        break;
                    }
                }

                var pos: i128 = ast.inferredMember.pos.?;
                var proper_term: *AST = ast.inferredMember.base.?.sum.terms.items[@as(usize, @intCast(pos))];

                if (proper_term.annotation.init) |_init| {
                    ast.inferredMember.init = _init; // This will be overriden by a call expression's rhs
                }
                if (ast.inferredMember.pos == null) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "not a member of the sum type", .stage = .typecheck } });
                    return error.typeError;
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
                var expected_expanded = try expected.?.exapnd_type(scope, errors, allocator);
                var expects_optional = expected_expanded.* == .sum and expected_expanded.sum.was_optional;
                var has_else = ast._if.elseBlock != null;
                if (has_else) {
                    ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, expected.?, ast._if.scope.?, errors, allocator);
                    ast._if.elseBlock = try validateAST(ast._if.elseBlock.?, expected.?, ast._if.scope.?, errors, allocator);
                } else if (expects_optional) {
                    var full_type = expected_expanded.sum.terms.items[1];
                    ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, full_type, ast._if.scope.?, errors, allocator);
                    if (ast._if.elseBlock) |elseBlock| {
                        ast._if.elseBlock = try validateAST(elseBlock, full_type, ast._if.scope.?, errors, allocator);
                    }
                } else {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "if expression without else gives optional", .stage = .typecheck } });
                    return error.typeError;
                }
            } else {
                ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, null, ast._if.scope.?, errors, allocator);
                if (ast._if.elseBlock) |elseBlock| {
                    ast._if.elseBlock = try validateAST(elseBlock, null, ast._if.scope.?, errors, allocator);
                }
            }
            retval = ast;
        },
        .case => {
            if (ast.case.let) |let| {
                ast.case.let = try validateAST(let, null, scope, errors, allocator);
            }
            var new_mappings = std.ArrayList(*AST).init(allocator);
            var num_rhs: usize = 0;
            for (ast.case.mappings.items) |mapping| {
                try new_mappings.append(try validateAST(mapping, expected, ast.case.scope.?, errors, allocator));
                if (mapping.mapping.rhs) |_| {
                    num_rhs += 1;
                }
            }
            if (num_rhs == 0) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected at least one non-null rhs prong", .stage = .typecheck } });
                return error.typeError;
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

            var optional_type = false;
            if (expected != null) {
                var expected_expanded = try expected.?.exapnd_type(scope, errors, allocator);
                if (expected_expanded.* == .sum and expected_expanded.sum.was_optional) {
                    var full_type = expected_expanded.sum.terms.items[1];
                    ast._while.bodyBlock = try validateAST(ast._while.bodyBlock, full_type, ast._while.scope.?, errors, allocator);
                    if (ast._while.elseBlock) |elseBlock| {
                        ast._while.elseBlock = try validateAST(elseBlock, full_type, ast._while.scope.?, errors, allocator);
                    }
                    optional_type = true;
                }
            }
            if (!optional_type) {
                ast._while.bodyBlock = try validateAST(ast._while.bodyBlock, expected, ast._while.scope.?, errors, allocator);
                if (ast._while.elseBlock) |elseBlock| {
                    ast._while.elseBlock = try validateAST(elseBlock, expected, ast._while.scope.?, errors, allocator);
                }
            }
            retval = ast;
        },
        .block => {
            var new_statements = std.ArrayList(*AST).init(allocator);
            if (ast.block.final) |final| {
                var i: usize = 0;
                while (i < ast.block.statements.items.len) : (i += 1) {
                    var term = ast.block.statements.items[i];
                    try new_statements.append(try validateAST(term, null, ast.block.scope.?, errors, allocator));
                }
                ast.block.statements = new_statements;
                ast.block.final = try validateAST(final, null, ast.block.scope.?, errors, allocator);
            } else {
                if (ast.block.statements.items.len > 1) {
                    var i: usize = 0;
                    while (i < ast.block.statements.items.len - 1) : (i += 1) {
                        var term = ast.block.statements.items[i];
                        try new_statements.append(try validateAST(term, null, ast.block.scope.?, errors, allocator));
                    }
                    try new_statements.append(try validateAST(ast.block.statements.items[ast.block.statements.items.len - 1], expected, ast.block.scope.?, errors, allocator));
                    ast.block.statements = new_statements;
                } else if (ast.block.statements.items.len == 1) {
                    try new_statements.append(try validateAST(ast.block.statements.items[0], expected, ast.block.scope.?, errors, allocator));
                    ast.block.statements = new_statements;
                }

                ast.getCommon().is_valid = true; // So that the typeof code can be reused. All children should be validated at this point
                var block_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !try expected.?.typesMatch(block_type, scope, errors, allocator)) {
                    if (ast.block.statements.items.len > 1) {
                        errors.addError(Error{ .expected2Type = .{ .span = ast.block.statements.items[ast.block.statements.items.len - 1].getToken().span, .expected = expected.?, .got = block_type, .stage = .typecheck } });
                        return error.typeError;
                    } else {
                        errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = block_type, .stage = .typecheck } });
                        return error.typeError;
                    }
                }
            }
            retval = ast;
        },

        // no return
        ._break => {
            if (!scope.in_loop) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`break` must be inside a loop",
                    .stage = .typecheck,
                } });
                return error.typeError;
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
                return error.typeError;
            }
            retval = ast;
        },

        ._return => {
            if (scope.in_function == 0 or scope.inner_function == null) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`return` must be contained in a function",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
            if (ast._return.expr) |expr| {
                ast._return.expr = try validateAST(expr, scope.inner_function.?._type.?.function.rhs, scope, errors, allocator);
            }
            retval = ast;
        },
        ._unreachable => {
            retval = ast;
        },

        ._defer => {
            ast._defer.statement = try validateAST(ast._defer.statement, null, scope, errors, allocator);
            try scope.defers.append(ast._defer.statement);
            retval = ast;
        },
        ._errdefer => {
            ast._errdefer.statement = try validateAST(ast._errdefer.statement, null, scope, errors, allocator);
            try scope.errdefers.append(ast._errdefer.statement);
            retval = ast;
        },
        .fnDecl => {
            try validateSymbol(ast.fnDecl.symbol.?, errors, allocator);
            retval = ast;
        },
        .decl => {
            ast.decl.symbol.?.defined = true;
            // statement, no type
            if (expected != null) {
                errors.addError(Error{ .expectedType = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast, .stage = .typecheck } });
                return error.typeError;
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
        return positionalArgs(ast, expected, errors, allocator);
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

fn positionalArgs(ast: *AST, expected: *AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*AST {
    switch (expected.*) {
        .annotation => {
            if (ast.* == .unit and expected.annotation.init != null) {
                return expected.annotation.init.?;
            } else if (ast.* != .unit) {
                return ast;
            } else {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "too few arguments",
                    .stage = .typecheck,
                } });
                return error.typeError;
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
            try putAssign(ast, &arg_map, errors);
        },

        .product => {
            for (ast.product.terms.items) |term| {
                try putAssign(term, &arg_map, errors);
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
                return error.typeError;
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
                        .msg = "receiver does not accept named arugments",
                        .stage = .typecheck,
                    } });
                    return error.typeError;
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
                        return error.typeError;
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

fn findSymbol(ast: *AST, scope: *Scope, errors: *errs.Errors) !*Symbol {
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

        .index => {},

        .select => {},

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
                    .msg = "attempt to modify non-mutable address",
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
                        .msg = "attempt to modify non-mutable address",
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

        else => {
            errors.addError(Error{ .basic = .{
                .span = ast.getToken().span,
                .msg = "not modifiable",
                .stage = .typecheck,
            } });
            return error.typeError;
        },
    }
}
