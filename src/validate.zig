const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const std = @import("std");
const symbols = @import("symbol.zig");

const AST = _ast.AST;
const Error = errs.Error;
const Scope = symbols.Scope;
const Symbol = symbols.Symbol;

pub fn validateScope(scope: *Scope, errors: *errs.Errors) !void {
    for (scope.symbols.keys()) |key| {
        var symbol = scope.symbols.get(key) orelse {
            std.debug.print("{s} doesn't exist in this scope\n", .{key});
            return error.typeError;
        };
        try validateSymbol(symbol, errors);
    }
    for (scope.children.items) |child| {
        try validateScope(child, errors);
    }
}

pub fn validateSymbol(symbol: *Symbol, errors: *errs.Errors) error{ typeError, Unimplemented, OutOfMemory }!void {
    if (symbol.valid) {
        return;
    }
    if (symbol.kind == ._fn) {
        var codomain = symbol._type.?.function.rhs;
        try validateAST(symbol.init.?, codomain, symbol.scope, errors);
    } else {
        if (symbol.init != null and symbol._type != null) {
            try validateAST(symbol._type.?, _ast.typeType, symbol.scope, errors);
            try validateAST(symbol.init.?, symbol._type, symbol.scope, errors);
        } else if (symbol.init == null) {
            // Default value (probably done at the IR side?)
        } else if (symbol._type == null) {
            // Infer type
            var _type = try symbol.init.?.typeof(symbol.scope, errors);
            symbol._type = _type;
            try validateAST(symbol.init.?, symbol._type, symbol.scope, errors);
        } else {
            unreachable;
        }
    }
    symbol.valid = true;
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
pub fn validateAST(ast: *AST, expected: ?*AST, scope: *Scope, errors: *errs.Errors) error{ typeError, Unimplemented, OutOfMemory }!void {
    switch (ast.*) {
        .unit => {
            if (expected != null and !expected.?.typesMatch(_ast.voidType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .int => {
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .char => {
            if (expected != null and !expected.?.typesMatch(_ast.charType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.charType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .float => {
            if (expected != null and !expected.?.typesMatch(_ast.floatType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .string => {
            // TODO: strings
            std.debug.print("string\n", .{});
        },

        .identifier => {
            // look up symbol, that's the type
            var symbol = try findSymbol(ast, scope, errors);
            try validateSymbol(symbol, errors);
            var _type = symbol._type.?;
            if (expected != null and !expected.?.typesMatch(_type)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _type, .stage = .typecheck } });
                return error.typeError;
            }
        },

        ._true => {
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        ._false => {
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .not => {
            try validateAST(ast.not.expr, _ast.boolType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .negate => {
            try validateAST(ast.negate.expr, _ast.floatType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .dereference => {
            if (expected != null) {
                var ast_type = try ast.typeof(scope, errors);
                if (expected != null and !expected.?.typesMatch(ast_type)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                    return error.typeError;
                }
                try validateAST(ast.dereference.expr, try _ast.AST.createAddrOf(ast.getToken(), expected.?, false, std.heap.page_allocator), scope, errors);
            } else {
                try validateAST(ast.dereference.expr, null, scope, errors);
            }
        },
        ._try => {
            std.debug.print("try\n", .{});
        },
        .optional => {
            std.debug.print("optional\n", .{});
        },
        .fromOptional => {
            std.debug.print("fromOptional\n", .{});
        },
        .inferredError => {
            std.debug.print("inferred error\n", .{});
        },

        .assign => {
            try validateLValue(ast.assign.lhs, scope, errors);
            try assertMutable(ast.assign.lhs, scope, errors);
            try validateAST(ast.assign.rhs, try ast.assign.lhs.typeof(scope, errors), scope, errors);
        },
        ._or => {
            try validateAST(ast._or.lhs, _ast.boolType, scope, errors);
            try validateAST(ast._or.rhs, _ast.boolType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._and => {
            try validateAST(ast._and.lhs, _ast.boolType, scope, errors);
            try validateAST(ast._and.rhs, _ast.boolType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .notEqual => {
            // TODO: typeof lhs and typeof rhs match
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .add => {
            try validateAST(ast.add.lhs, _ast.floatType, scope, errors);
            try validateAST(ast.add.rhs, _ast.floatType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .sub => {
            try validateAST(ast.sub.lhs, _ast.floatType, scope, errors);
            try validateAST(ast.sub.rhs, _ast.floatType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .mult => {
            try validateAST(ast.mult.lhs, _ast.floatType, scope, errors);
            try validateAST(ast.mult.rhs, _ast.floatType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .div => {
            try validateAST(ast.div.lhs, _ast.floatType, scope, errors);
            try validateAST(ast.div.rhs, _ast.floatType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .mod => {
            try validateAST(ast.mod.lhs, _ast.floatType, scope, errors);
            try validateAST(ast.mod.rhs, _ast.floatType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .exponent => {
            for (ast.exponent.terms.items) |term| {
                try validateAST(term, _ast.floatType, scope, errors);
            }
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.floatType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._catch => {
            std.debug.print("catch\n", .{});
        },
        ._orelse => {
            std.debug.print("orelse\n", .{});
        },
        .call => {
            std.debug.print("call\n", .{});
        },
        .index => {
            std.debug.print("index\n", .{});
        },
        .select => {
            std.debug.print("select\n", .{});
        },
        .function => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } }); // TODO: Function types
                return error.typeError;
            }
        },
        .delta => {
            std.debug.print("delta\n", .{});
        },
        .composition => {
            std.debug.print("composition\n", .{});
        },
        .prepend => {
            std.debug.print("prepend\n", .{});
        },
        .sum => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._error => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .diff => {
            std.debug.print("diff\n", .{});
        },
        .concat => {
            std.debug.print("concat\n", .{});
        },
        ._union => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.typeType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .product => {
            std.debug.print("product\n", .{});
        },
        .conditional => {
            for (ast.conditional.exprs.items) |child| {
                try validateAST(child, _ast.floatType, scope, errors);
            }
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.boolType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .addrOf => {
            if (expected != null and expected.?.typesMatch(_ast.typeType)) {
                // Address type, type of this ast must be a type, inner must be a type
                var ast_type: *AST = try ast.addrOf.expr.typeof(scope, errors);
                if (!ast_type.typesMatch(expected.?)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors), .stage = .typecheck } });
                    return error.typeError;
                } else {
                    try validateAST(ast.addrOf.expr, _ast.typeType, scope, errors);
                }
            } else if (expected != null and expected.?.* == .addrOf) {
                // Address value, expected must be an address, inner must match with expected's inner
                if (!expected.?.typesMatch(try ast.typeof(scope, errors))) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors), .stage = .typecheck } });
                    return error.typeError;
                }
                try validateAST(ast.addrOf.expr, expected.?.addrOf.expr, scope, errors);
                try validateLValue(ast.addrOf.expr, scope, errors);
                if (ast.addrOf.mut) {
                    try assertMutable(ast.addrOf.expr, scope, errors);
                }
            } else if (expected == null) {
                try validateAST(ast.addrOf.expr, null, scope, errors);
                try validateLValue(ast.addrOf.expr, scope, errors);
            } else {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = try ast.typeof(scope, errors), .stage = .typecheck } });
                return error.typeError;
            }
        },
        .sliceOf => {
            std.debug.print("slice of\n", .{});
        },
        .namedArg => {
            std.debug.print("arg\n", .{});
        },
        .subSlice => {
            std.debug.print("subslice\n", .{});
        },
        .annotation => {
            std.debug.print("annotation\n", .{});
        },
        .inferredMember => {
            std.debug.print("member\n", .{});
        },

        ._if => {
            if (ast._if.let) |let| {
                try validateAST(let, null, scope, errors);
            }
            try validateAST(ast._if.condition, _ast.boolType, ast._if.scope.?, errors);
            try validateAST(ast._if.bodyBlock, expected, ast._if.scope.?, errors);
            if (ast._if.elseBlock) |elseBlock| {
                try validateAST(elseBlock, expected, ast._if.scope.?, errors);
            }
        },
        .cond => {
            if (ast.cond.let) |let| {
                try validateAST(let, null, scope, errors);
            }
            var num_rhs: usize = 0;
            for (ast.cond.mappings.items) |mapping| {
                try validateAST(mapping, expected, ast.cond.scope.?, errors);
                if (mapping.mapping.rhs) |_| {
                    num_rhs += 1;
                }
            }
            if (num_rhs == 0) {
                errors.addError(Error{ .basic = .{ .span = ast.getToken().span, .msg = "expected at least one non-null rhs prong", .stage = .typecheck } });
                return error.typeError;
            }
        },
        .case => {
            // TODO: After pattern matching
            std.debug.print("case\n", .{});
        },
        .mapping => {
            switch (ast.mapping.kind) {
                .cond => {
                    if (ast.mapping.lhs) |lhs| {
                        try validateAST(lhs, _ast.boolType, scope, errors);
                    }
                    if (ast.mapping.rhs) |rhs| {
                        try validateAST(rhs, expected, scope, errors);
                    }
                },
                .case => {},
            }
        },
        ._while => {
            if (ast._while.let) |let| {
                try validateAST(let, null, scope, errors);
            }
            try validateAST(ast._while.condition, _ast.boolType, ast._while.scope.?, errors);
            try validateAST(ast._while.bodyBlock, expected, ast._while.scope.?, errors);
            if (ast._while.elseBlock) |elseBlock| {
                try validateAST(elseBlock, expected, ast._while.scope.?, errors);
            }
            if (ast._while.post) |post| {
                try validateAST(post, null, ast._while.scope.?, errors);
            }
        },
        ._for => {
            // TODO: After type-classes and iterators
        },
        .block => {
            var i: usize = 0;
            if (ast.block.statements.items.len > 1) {
                while (i < ast.block.statements.items.len - 1) : (i += 1) {
                    var term = ast.block.statements.items[i];
                    try validateAST(term, null, ast.block.scope.?, errors);
                }
            }
            if (ast.block.final) |final| {
                try validateAST(final, null, ast.block.scope.?, errors);
            } else if (ast.block.statements.items.len > 1) {
                try validateAST(ast.block.statements.items[ast.block.statements.items.len - 1], expected, ast.block.scope.?, errors);
            } else if (ast.block.statements.items.len == 1) {
                try validateAST(ast.block.statements.items[0], null, ast.block.scope.?, errors);
            }

            var block_type = try ast.typeof(scope, errors);
            if (expected != null and !expected.?.typesMatch(block_type)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = block_type, .stage = .typecheck } });
                return error.typeError;
            }
        },

        ._unreachable,
        ._break,
        ._continue,
        .throw,
        ._return,
        => {
            // no-return
            std.debug.print("no return\n", .{});
        },

        ._defer => {},
        .fnDecl => {
            // type-less
            if (expected != null) {
                errors.addError(Error{ .expectedType = .{ .span = ast.getToken().span, .expected = expected.?, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .decl => {
            ast.decl.symbol.?.defined = true;
            // type-less
            if (expected != null) {
                errors.addError(Error{ .expectedType = .{ .span = ast.getToken().span, .expected = expected.?, .stage = .typecheck } });
                return error.typeError;
            }
        },
    }
}

fn findSymbol(ast: *AST, scope: *Scope, errors: *errs.Errors) !*Symbol {
    var symbol = scope.lookup(ast.identifier.common.token.data) orelse {
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

fn assertMutable(ast: *AST, scope: *Scope, errors: *errs.Errors) !void {
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
            var child_type = try child.typeof(scope, errors);
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
