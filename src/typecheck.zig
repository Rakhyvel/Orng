const _ast = @import("ast.zig");
const errs = @import("errors.zig");
const std = @import("std");
const symbols = @import("symbol.zig");

const AST = _ast.AST;
const Error = errs.Error;
const Scope = symbols.Scope;

pub fn typecheckScope(scope: *Scope, errors: *errs.Errors) !void {
    for (scope.symbols.keys()) |key| {
        var symbol = scope.symbols.get(key).?;
        if (symbol.init != null and symbol._type != null) {
            try typecheckAST(symbol.init.?, symbol._type, scope, errors);
        } else if (symbol.init == null) {
            // Default value (probably done at the IR side?)
        } else if (symbol._type == null) {
            // Infer type
        }
    }
    for (scope.children.items) |child| {
        try typecheckScope(child, errors);
    }
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
pub fn typecheckAST(ast: *AST, expected: ?*AST, scope: *Scope, errors: *errs.Errors) !void {
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
        },

        .identifier => {
            // look up symbol, that's the type
            var _type = scope.lookup(ast.identifier.token.data).?._type.?;
            if (expected != null and !expected.?.typesMatch(_type)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
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

        ._unreachable,
        ._break,
        ._continue,
        => {
            // type-less
        },

        .not => {
            try typecheckAST(ast.not.expr, _ast.boolType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .negate => {
            try typecheckAST(ast.negate.expr, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .dereference => {},
        ._try => {},
        .optional => {},
        .fromOptional => {},
        .inferredError => {},

        .assign => {},
        ._or => {
            try typecheckAST(ast._or.lhs, _ast.boolType, scope, errors);
            try typecheckAST(ast._or.rhs, _ast.boolType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._and => {
            try typecheckAST(ast._and.lhs, _ast.boolType, scope, errors);
            try typecheckAST(ast._and.rhs, _ast.boolType, scope, errors);
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
            try typecheckAST(ast.add.lhs, _ast.intType, scope, errors);
            try typecheckAST(ast.add.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .sub => {
            try typecheckAST(ast.sub.lhs, _ast.intType, scope, errors);
            try typecheckAST(ast.sub.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .mult => {
            try typecheckAST(ast.mult.lhs, _ast.intType, scope, errors);
            try typecheckAST(ast.mult.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .div => {
            try typecheckAST(ast.div.lhs, _ast.intType, scope, errors);
            try typecheckAST(ast.div.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .mod => {
            try typecheckAST(ast.mod.lhs, _ast.intType, scope, errors);
            try typecheckAST(ast.mod.rhs, _ast.intType, scope, errors);
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .exponent => {
            for (ast.exponent.terms.items) |term| {
                try typecheckAST(term, _ast.intType, scope, errors);
            }
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        ._catch => {},
        ._orelse => {},
        .call => {},
        .index => {},
        .select => {},
        .function => {
            // Type type?
        },
        .delta => {},
        .composition => {},
        .prepend => {},
        .sum => {
            // Type type
        },
        ._error => {
            // Type type
        },
        .diff => {},
        .concat => {},
        ._union => {
            // Type type
        },

        .product => {},
        .conditional => {
            // TODO: check that all children are either int or float
            if (expected != null and !expected.?.typesMatch(_ast.boolType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },
        .addrOf => {},
        .sliceOf => {},
        .namedArg => {},
        .subSlice => {},
        .annotation => {},
        .inferredMember => {},

        ._if => {
            try typecheckAST(ast._if.condition, _ast.boolType, ast._if.scope.?, errors);
        },
        .cond => {},
        .case => {},
        .mapping => {
            // If in cond, lhs must be bool
            // If in case, lhs is pattern, not expr
        },
        ._while => {
            try typecheckAST(ast._while.condition, _ast.boolType, ast._while.scope.?, errors);
        },
        ._for => {},
        .block => {
            for (ast.block.statements.items) |term| {
                try typecheckAST(term, null, scope, errors);
            }
        },

        .throw => {},
        ._return => {},
        .decl => {},
        .fnDecl => {},
        ._defer => {},
    }
}
