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
            if (expected != null and !expected.?.typesMatch(_ast.unitType) and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .int => {
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .char => {
            if (expected != null and !expected.?.typesMatch(_ast.charType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.charType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .float => {
            if (expected != null and !expected.?.typesMatch(_ast.floatType)) {
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
            if (expected != null and !expected.?.typesMatch(symbol._type.?)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = symbol._type.?, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        ._true => {
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        ._false => {
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .not => {
            ast.not.expr = try validateAST(ast.not.expr, _ast.boolType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .negate => {
            ast.negate.expr = try validateAST(ast.negate.expr, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
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
                if (expected != null and !expected.?.typesMatch(ast_type)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                    return error.typeError;
                }
            } else {
                ast.dereference.expr = try validateAST(ast.dereference.expr, null, scope, errors, allocator);
            }
            retval = ast;
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
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        ._and => {
            ast._and.lhs = try validateAST(ast._and.lhs, _ast.boolType, scope, errors, allocator);
            ast._and.rhs = try validateAST(ast._and.rhs, _ast.boolType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .notEqual => {
            ast.notEqual.lhs = try validateAST(ast.notEqual.lhs, null, scope, errors, allocator);
            ast.notEqual.rhs = try validateAST(ast.notEqual.rhs, try ast.notEqual.lhs.typeof(scope, errors, allocator), scope, errors, allocator);

            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .add => {
            ast.add.lhs = try validateAST(ast.add.lhs, _ast.floatType, scope, errors, allocator);
            ast.add.rhs = try validateAST(ast.add.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .sub => {
            ast.sub.lhs = try validateAST(ast.sub.lhs, _ast.floatType, scope, errors, allocator);
            ast.sub.rhs = try validateAST(ast.sub.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .mult => {
            ast.mult.lhs = try validateAST(ast.mult.lhs, _ast.floatType, scope, errors, allocator);
            ast.mult.rhs = try validateAST(ast.mult.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .div => {
            ast.div.lhs = try validateAST(ast.div.lhs, _ast.floatType, scope, errors, allocator);
            ast.div.rhs = try validateAST(ast.div.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .mod => {
            ast.mod.lhs = try validateAST(ast.mod.lhs, _ast.floatType, scope, errors, allocator);
            ast.mod.rhs = try validateAST(ast.mod.rhs, _ast.floatType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
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
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .call => {
            ast.call.lhs = try validateAST(ast.call.lhs, null, scope, errors, allocator);
            var lhs_type = try ast.call.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* != .function) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "call is not to a function", .stage = .typecheck } });
                return error.typeError;
            }

            ast.call.rhs = try validateAST(ast.call.rhs, lhs_type.function.lhs, scope, errors, allocator);

            if (expected != null and !expected.?.typesMatch(lhs_type.function.rhs)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.function.rhs, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .index => {
            ast.index.lhs = try validateAST(ast.index.lhs, null, scope, errors, allocator);
            ast.index.rhs = try validateAST(ast.index.rhs, _ast.intType, scope, errors, allocator);

            var lhs_type = try ast.index.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* == .product and !lhs_type.product.is_homotypical() and !lhs_type.product.was_slice) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "array is not homotypical", .stage = .typecheck } });
                return error.typeError;
            }

            if (expected != null) {
                if (lhs_type.* == .product and !lhs_type.product.was_slice and !expected.?.typesMatch(lhs_type.product.terms.items[0])) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type, .stage = .typecheck } });
                    return error.typeError;
                } else if (lhs_type.* == .product and lhs_type.product.was_slice and !expected.?.typesMatch(lhs_type.product.terms.items[0].annotation.type.addrOf.expr)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type, .stage = .typecheck } });
                    return error.typeError;
                } else if (lhs_type.* != .product and lhs_type.* != .sliceOf) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type, .stage = .typecheck } });
                    return error.typeError;
                } else {
                    std.debug.print("hehre\n", .{});
                    retval = ast;
                }
            } else {
                retval = ast;
            }
        },
        .select => {
            ast.select.lhs = try validateAST(ast.select.lhs, null, scope, errors, allocator);

            var select_lhs_type = try ast.select.lhs.typeof(scope, errors, allocator);

            // Implicit dereference
            if (select_lhs_type.* == .addrOf) {
                ast.select.lhs = try validateAST(try AST.createDereference(ast.getToken(), ast.select.lhs, allocator), null, scope, errors, allocator);
                select_lhs_type = try ast.select.lhs.typeof(scope, errors, allocator);
            }

            if (select_lhs_type.* != .product) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "left-hand-side of select is not selectable",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }

            ast.getCommon().is_valid = true;
            var ast_type = try ast.typeof(scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(ast_type)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = ast_type, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .function => {
            ast.function.lhs = try validateAST(ast.function.lhs, _ast.typeType, scope, errors, allocator);
            ast.function.rhs = try validateAST(ast.function.rhs, _ast.typeType, scope, errors, allocator);
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .sum => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        ._error => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        ._union => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        .product => {
            var new_terms = std.ArrayList(*AST).init(allocator);
            if (expected != null and expected.?.typesMatch(_ast.typeType)) {
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
        .conditional => {
            var new_exprs = std.ArrayList(*AST).init(allocator);
            for (ast.conditional.exprs.items) |child| {
                try new_exprs.append(try validateAST(child, _ast.floatType, scope, errors, allocator));
            }
            ast.conditional.exprs = new_exprs;
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .addrOf => {
            if (expected != null and expected.?.typesMatch(_ast.typeType)) {
                // Address type, type of this ast must be a type, inner must be a type
                ast.addrOf.expr = try validateAST(ast.addrOf.expr, _ast.typeType, scope, errors, allocator);
                var ast_type: *AST = try ast.addrOf.expr.typeof(scope, errors, allocator);
                if (!ast_type.typesMatch(expected.?)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return error.typeError;
                }
            } else if (expected != null and expected.?.* == .addrOf) {
                // Address value, expected must be an address, inner must match with expected's inner
                ast.addrOf.expr = try validateAST(ast.addrOf.expr, expected.?.addrOf.expr, scope, errors, allocator);
                ast.getCommon().is_valid = true;
                if (!expected.?.typesMatch(try ast.typeof(scope, errors, allocator))) {
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
            if (expected != null and expected.?.typesMatch(_ast.typeType)) {
                // Slice-of type, type of this ast must be a type, inner must be a type
                ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, _ast.typeType, scope, errors, allocator);
                var ast_type: *AST = try ast.sliceOf.expr.typeof(scope, errors, allocator);
                if (!ast_type.typesMatch(expected.?)) {
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
                    for (0..@intCast(usize, ast.sliceOf.len.?.int.data)) |_| {
                        try new_terms.append(ast.sliceOf.expr);
                    }
                    ast = try AST.createProduct(ast.getToken(), new_terms, allocator);
                } else {
                    // Regular slice type, change to product of data address and length
                    var term_types = std.ArrayList(*AST).init(allocator);
                    var data_type = try AST.createAddrOf(ast.getToken(), ast.sliceOf.expr, ast.sliceOf.kind == .MUT, allocator);
                    var annot_type = try AST.createAnnotation(ast.getToken(), try AST.createIdentifier(Token.create("data", null, 0, 0), allocator), data_type, null, null, allocator);
                    data_type.getCommon().is_valid = true;
                    annot_type.getCommon().is_valid = true;
                    try term_types.append(annot_type);
                    try term_types.append(try AST.createAnnotation(
                        ast.getToken(),
                        try AST.createIdentifier(Token.create("length", null, 0, 0), allocator),
                        _ast.intType,
                        null,
                        null,
                        allocator,
                    ));
                    ast = try AST.createProduct(ast.getToken(), term_types, allocator);
                    ast.getCommon().is_valid = true;
                    ast.product.was_slice = true;
                }
                was_type = true;
            } else {
                ast.sliceOf.expr = try validateAST(ast.sliceOf.expr, null, scope, errors, allocator);

                // Slice-of value, expected must be an slice, inner must match with expected's inner
                // ast.sliceOf.expr must be homotypical product type of expected
                var expr_type = try ast.sliceOf.expr.typeof(scope, errors, allocator);
                ast.getCommon().is_valid = true;
                if (expr_type.* != .product or !expr_type.product.is_homotypical()) {
                    errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "attempt to take slice-of something that is not an array", .stage = .typecheck } });
                    return error.typeError;
                } else if (expected != null and !expected.?.typesMatch(try ast.typeof(scope, errors, allocator))) {
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
                try new_terms.append(try AST.createAddrOf(ast.getToken(), ast.sliceOf.expr, ast.sliceOf.kind == .MUT, allocator));
                try new_terms.append(try AST.createInt(ast.getToken(), expr_type.product.terms.items.len, allocator));
                ast = try AST.createProduct(ast.getToken(), new_terms, allocator);
                ast.getCommon().is_valid = true;
                ast.product.was_slice = true;
            }
            retval = ast;
        },

        .namedArg => {
            unreachable;
        },
        .annotation => {
            ast.annotation.type = try validateAST(ast.annotation.type, _ast.typeType, scope, errors, allocator);
            if (ast.annotation.init != null) {
                ast.annotation.init = try validateAST(ast.annotation.init.?, ast.annotation.type, scope, errors, allocator);
            }

            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },

        ._if => {
            if (ast._if.let) |let| {
                ast._if.let = try validateAST(let, null, scope, errors, allocator);
            }
            ast._if.condition = try validateAST(ast._if.condition, _ast.boolType, ast._if.scope.?, errors, allocator);
            ast._if.bodyBlock = try validateAST(ast._if.bodyBlock, expected, ast._if.scope.?, errors, allocator);
            if (ast._if.elseBlock) |elseBlock| {
                ast._if.elseBlock = try validateAST(elseBlock, expected, ast._if.scope.?, errors, allocator);
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
            ast._while.condition = try validateAST(ast._while.condition, _ast.boolType, ast._while.scope.?, errors, allocator);
            ast._while.bodyBlock = try validateAST(ast._while.bodyBlock, expected, ast._while.scope.?, errors, allocator);
            if (ast._while.elseBlock) |elseBlock| {
                ast._while.elseBlock = try validateAST(elseBlock, expected, ast._while.scope.?, errors, allocator);
            }
            if (ast._while.post) |post| {
                ast._while.post = try validateAST(post, null, ast._while.scope.?, errors, allocator);
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
                    try new_statements.append(try validateAST(ast.block.statements.items[0], null, ast.block.scope.?, errors, allocator));
                    ast.block.statements = new_statements;
                }

                ast.getCommon().is_valid = true; // So that the typeof code can be reused. All children should be validated at this point
                var block_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !expected.?.typesMatch(block_type)) {
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
        .fnDecl => {
            try validateSymbol(ast.fnDecl.symbol.?, errors, allocator);
            retval = ast;
        },
        .decl => {
            ast.decl.symbol.?.defined = true;
            // statement, no type
            if (expected != null) {
                errors.addError(Error{ .expectedType = .{ .span = ast.getToken().span, .expected = expected.?, .stage = .typecheck } });
                return error.typeError;
            }
            retval = ast;
        },

        else => {
            std.debug.print("validateAST() unimplemented for {s}\n", .{@tagName(ast.*)});
            unreachable;
        },
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
        .namedArg => return true,
        .product => {
            var seen_named = false;
            var seen_pos = false;
            for (ast.product.terms.items) |term| {
                if (term.* == .namedArg) {
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
    var arg_map = std.StringArrayHashMap(*AST).init(allocator);

    // Associate argument names with their values
    switch (ast.*) { // Can assume ast is either namedArg, or product of namedArgs
        .namedArg => try putOrError(ast, &arg_map, errors),

        .product => for (ast.product.terms.items) |term| {
            try putOrError(term, &arg_map, errors);
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
                var arg = arg_map.get(term.annotation.pattern.identifier.common.token.data);
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

fn putOrError(ast: *AST, arg_map: *std.StringArrayHashMap(*AST), errors: *errs.Errors) !void {
    var name = ast.namedArg.ident.identifier.common.token.data;
    if (arg_map.get(name)) |_| {
        errors.addError(Error{ .basic = .{
            .span = ast.getToken().span,
            .msg = "parameter is already defined",
            .stage = .typecheck,
        } });
        return error.typeError;
    } else {
        try arg_map.put(name, ast.namedArg.init);
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
            if (lhs_type.* == .sliceOf and (lhs_type.sliceOf.kind != .MUT or lhs_type.sliceOf.kind != .MULTIPTR)) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "attempt to modify non-mutable slice",
                    .stage = .typecheck,
                } });
                return error.typeError;
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
