const AST = @import("ast.zig").AST;

// Gets the type of an AST expression
pub fn getType(expr: *AST) *AST {
    _ = expr;
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
pub fn typecheck(ast: *AST, expected: ?*AST) void {
    _ = expected;
    _ = ast;
}
