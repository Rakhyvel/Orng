const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const std = @import("std");
const symbols = @import("symbol.zig");

const AST = _ast.AST;
const Error = errs.Error;
const Scope = symbols.Scope;
const Symbol = symbols.Symbol;

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
    std.debug.print("{s}\n", .{symbol.name});

    if (symbol.kind == ._fn) {
        var codomain = symbol._type.?.function.rhs;
        symbol.init = try validateAST(symbol.init.?, codomain, symbol.scope, errors, allocator);
    } else {
        if (symbol.init != null and symbol._type != null) {
            symbol._type = try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors, allocator);
            symbol.init = try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
        } else if (symbol.init == null) {
            // Default value (probably done at the IR side?)
        } else if (symbol._type == null) {
            // Infer type
            var _type = try symbol.init.?.typeof(symbol.scope, errors, allocator);
            symbol._type = _type;
            symbol.init = try validateAST(symbol.init.?, symbol._type, symbol.scope, errors, allocator);
        } else {
            unreachable;
        }
    }
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
pub fn validateAST(old_ast: *AST, expected: ?*AST, scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) error{ typeError, Unimplemented, OutOfMemory }!*AST {
    var retval: *AST = undefined;
    var ast = old_ast;

    if (expected != null and (expected.?.* == .product or expected.?.* == .annotation)) {
        ast = try defaultArgs(ast, expected.?, errors, allocator);
    }

    switch (ast.*) {
        .unit => {
            if (expected != null and !expected.?.typesMatch(_ast.unitType)) {
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
            var _type = symbol._type.?;
            if (expected != null and !expected.?.typesMatch(_type)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _type, .stage = .typecheck } });
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
                var ast_type = try ast.typeof(scope, errors, allocator);
                if (expected != null and !expected.?.typesMatch(ast_type)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                    return error.typeError;
                }
                ast.dereference.expr = try validateAST(ast.dereference.expr, try _ast.AST.createAddrOf(ast.getToken(), expected.?, false, std.heap.page_allocator), scope, errors, allocator);
            } else {
                ast.dereference.expr = try validateAST(ast.dereference.expr, null, scope, errors, allocator);
            }
            retval = ast;
        },

        .assign => {
            try validateLValue(ast.assign.lhs, scope, errors);
            try assertMutable(ast.assign.lhs, scope, errors, allocator);
            ast.assign.rhs = try validateAST(ast.assign.rhs, try ast.assign.lhs.typeof(scope, errors, allocator), scope, errors, allocator);
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
            // TODO: typeof lhs and typeof rhs match
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
            // TODO: Validate lhs is function, returns expected
            var lhs_type = try ast.call.lhs.typeof(scope, errors, allocator);
            if (lhs_type.* != .function) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "call is not to a function", .stage = .typecheck } });
                return error.typeError;
            }

            ast.call.lhs = try validateAST(ast.call.lhs, null, scope, errors, allocator);
            ast.call.rhs = try validateAST(ast.call.rhs, lhs_type.function.lhs, scope, errors, allocator);

            if (expected != null and !expected.?.typesMatch(lhs_type.function.rhs)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = lhs_type.function.rhs, .stage = .typecheck } });
                return error.typeError;
            } else {
                retval = ast;
            }
        },
        .select => {
            var select_lhs_type = try ast.select.lhs.typeof(scope, errors, allocator);
            var selectable: bool = undefined;
            switch (select_lhs_type.*) {
                .annotation => selectable = true,
                .product => {
                    for (select_lhs_type.product.terms.items) |term| {
                        if (term.* != .annotation) {
                            selectable = false;
                            break;
                        }
                    }
                    selectable = true;
                },
                else => selectable = false,
            }
            if (!selectable) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "left-hand-side of select is not selectable",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }

            ast.select.lhs = try validateAST(ast.select.lhs, null, scope, errors, allocator);

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
                    std.debug.print("2\n", .{});
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
                var ast_type: *AST = try ast.addrOf.expr.typeof(scope, errors, allocator);
                if (!ast_type.typesMatch(expected.?)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return error.typeError;
                } else {
                    ast.addrOf.expr = try validateAST(ast.addrOf.expr, _ast.typeType, scope, errors, allocator);
                }
            } else if (expected != null and expected.?.* == .addrOf) {
                // Address value, expected must be an address, inner must match with expected's inner
                if (!expected.?.typesMatch(try ast.typeof(scope, errors, allocator))) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors, allocator), .stage = .typecheck } });
                    return error.typeError;
                }
                ast.addrOf.expr = try validateAST(ast.addrOf.expr, expected.?.addrOf.expr, scope, errors, allocator);
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

        .namedArg => {
            unreachable;
        },
        .annotation => {
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
        .cond => {
            if (ast.cond.let) |let| {
                ast.cond.let = try validateAST(let, null, scope, errors, allocator);
            }
            var new_mappings = std.ArrayList(*AST).init(allocator);
            var num_rhs: usize = 0;
            for (ast.cond.mappings.items) |mapping| {
                try new_mappings.append(try validateAST(mapping, expected, ast.cond.scope.?, errors, allocator));
                if (mapping.mapping.rhs) |_| {
                    num_rhs += 1;
                }
            }
            if (num_rhs == 0) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected at least one non-null rhs prong", .stage = .typecheck } });
                return error.typeError;
            } else {
                ast.cond.mappings = new_mappings;
                retval = ast;
            }
        },
        .mapping => {
            switch (ast.mapping.kind) {
                .cond => {
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

        .throw, ._return => {
            if (scope.in_function == 0) {
                errors.addError(Error{ .basic = .{
                    .span = ast.getToken().span,
                    .msg = "`return` must be contained in a function",
                    .stage = .typecheck,
                } });
                return error.typeError;
            }
            retval = ast;
        },
        ._unreachable => {
            retval = ast;
        },

        ._defer => {
            try scope.defers.append(ast._defer.statement);
            retval = ast;
        },
        .fnDecl => {
            // TODO: ast expression is a function type
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
                if (ast.* == .product and i < ast.product.terms.items.len) {
                    try new_terms.append(ast.product.terms.items[i]);
                } else if (ast.* == .unit or (ast.* != .product and i > 0) or (ast.* == .product and i >= ast.product.terms.items.len)) {
                    if (term.* == .annotation and term.annotation.init != null) {
                        try new_terms.append(term.annotation.init.?);
                    }
                } else {
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
