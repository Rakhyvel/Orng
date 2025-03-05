const std = @import("std");
const AST = @import("ast.zig").AST;
const Token = @import("../lexer/token.zig");

pub var poisoned: *AST = undefined;
var inited: bool = false;

/// Initializes internal structures if they are not already initialized.
pub fn init_structures(allocator: std.mem.Allocator) void {
    if (!inited) {
        poisoned = AST.create_poison(
            Token.init_simple("LMAO GET POISONED!"),
            allocator,
        );
        _ = poisoned.enpoison();
        inited = true;
    }
}
