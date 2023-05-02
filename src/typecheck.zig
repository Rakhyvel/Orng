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
            try typecheckAST(symbol.init.?, symbol._type, errors);
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
pub fn typecheckAST(ast: *AST, expected: ?*AST, errors: *errs.Errors) !void {
    switch (ast.*) {
        .unit => {},

        .int => {
            if (expected != null and !expected.?.typesMatch(_ast.intType)) {
                errors.addError(Error{ .expected2Type = .{ .span = ast.getToken().span, .expected = expected.?, .got = _ast.intType, .stage = .typecheck } });
                return error.typeError;
            }
        },

        .char,
        .float,
        .string,
        .identifier,
        ._unreachable,
        ._break,
        ._continue,
        => {},

        .not => {},
        .negate => {},
        .dereference => {},
        ._try => {},
        .optional => {},
        .fromOptional => {},
        .inferredError => {},

        .assign => {},
        ._or => {},
        ._and => {},
        .notEqual => {},
        .add => {},
        .sub => {},
        .mult => {},
        .div => {},
        .mod => {},
        .exponent => {},
        ._catch => {},
        ._orelse => {},
        .call => {},
        .index => {},
        .select => {},
        .function => {},
        .delta => {},
        .composition => {},
        .prepend => {},
        .sum => {},
        ._error => {},
        .diff => {},
        .concat => {},
        ._union => {},

        .product => {},
        .conditional => {},
        .addrOf => {},
        .sliceOf => {},
        .namedArg => {},
        .subSlice => {},
        .annotation => {},
        .inferredMember => {},

        ._if => {},
        .cond => {},
        .case => {},
        .mapping => {},
        ._while => {},
        ._for => {},
        .block => {},

        .throw => {},
        ._return => {},
        .decl => {},
        .fnDecl => {},
        ._defer => {},
    }
}
