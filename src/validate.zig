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
        if (symbol.init != null and symbol._type != null) {
            try validateAST(symbol._type.?, _ast.typeType, scope, errors);
            try validateAST(symbol.init.?, symbol._type, scope, errors);
        } else if (symbol.init == null) {
            // Default value (probably done at the IR side?)
        } else if (symbol._type == null) {
            // Infer type
        }
    }
    for (scope.children.items) |child| {
        try validateScope(child, errors);
    }
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
pub fn validateAST(ast: *AST, expected: ?*AST, scope: *Scope, errors: *errs.Errors) !void {
    switch (ast.*) {
        .unit => {
            if (expected != null and !expected.?.typesMatch(_ast.voidType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
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
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .float => {
            if (expected != null and !expected.?.typesMatch(_ast.floatType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
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

            var _type = symbol._type.?;
            if (expected != null and !expected.?.typesMatch(_type)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _type, .stage = .typecheck } });
                return error.typeError;
            }
        },

        ._true => {
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        ._false => {
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .not => {
            try validateAST(ast.not.expr, _ast.boolType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .negate => {
            try validateAST(ast.negate.expr, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .dereference => {
            std.debug.print("deref\n", .{});
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
            std.debug.print("assign\n", .{});
            try validateLValue(ast.assign.lhs, scope, errors);
        },
        ._or => {
            try validateAST(ast._or.lhs, _ast.boolType, scope, errors);
            try validateAST(ast._or.rhs, _ast.boolType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._and => {
            try validateAST(ast._and.lhs, _ast.boolType, scope, errors);
            try validateAST(ast._and.rhs, _ast.boolType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .notEqual => {
            // TODO: typeof lhs and typeof rhs match
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .add => {
            try validateAST(ast.add.lhs, _ast.intType, scope, errors);
            try validateAST(ast.add.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .sub => {
            try validateAST(ast.sub.lhs, _ast.intType, scope, errors);
            try validateAST(ast.sub.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .mult => {
            try validateAST(ast.mult.lhs, _ast.intType, scope, errors);
            try validateAST(ast.mult.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .div => {
            try validateAST(ast.div.lhs, _ast.intType, scope, errors);
            try validateAST(ast.div.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .mod => {
            try validateAST(ast.mod.lhs, _ast.intType, scope, errors);
            try validateAST(ast.mod.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .exponent => {
            for (ast.exponent.terms.items) |term| {
                try validateAST(term, _ast.intType, scope, errors);
            }
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
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
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
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
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._error => {
            if (expected != null and !expected.?.typesMatch(_ast.typeType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
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
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
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
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .addrOf => {
            std.debug.print("addr of\n", .{});
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
                        var lhs_type = lhs.typeof(scope);
                        if (!lhs_type.typesMatch(_ast.boolType)) {
                            errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                            return error.typeError;
                        }
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
        },
        ._for => {
            // TODO: After type-classes and iterators
        },
        .block => {
            for (ast.block.statements.items) |term| {
                try validateAST(term, null, ast.block.scope.?, errors);
            }
            if (ast.block.final) |final| {
                try validateAST(final, null, ast.block.scope.?, errors);
            } else if (ast.block.statements.items.len > 0) {
                var last_type = ast.block.statements.items[ast.block.statements.items.len - 1].typeof(ast.block.scope.?);
                if (expected != null and !expected.?.typesMatch(last_type)) {
                    errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                    return error.typeError;
                }
            } else if (expected != null) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.voidType, .stage = .typecheck } });
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
