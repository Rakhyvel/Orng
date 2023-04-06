const _token = @import("token.zig");
const Token = _token.Token;
const std = @import("std");

// function where newlines are pre-empted by binary operators
pub fn preemptBinaryOperator(tokens: *std.ArrayList(Token)) void {
    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        var token = tokens.items[i];
        _ = token;
        var next = tokens.items[i + 1];
        for (_token.binaryOperators) |binopKind| {
            if (next.kind == binopKind) {
                _ = tokens.orderedRemove(i);
                i -= 1;
            }
        }
    }
}

// indent - dedent token insertion
pub fn insertIndentDedents(tokens: *std.ArrayList(Token)) !void {
    var stack: std.ArrayList(usize) = std.ArrayList(usize).init(tokens.allocator);
    defer stack.deinit();

    var i: usize = 0;
    while (i < tokens.items.len) : (i += 1) {
        var token = tokens.items[i];
        switch (token.kind) {
            .WHITESPACE => {
                // If token spaces == peek spaces => do nothing
                if (token.data.len == stack.getLast()) {}
                // If token spaces >  peek spaces => append token spaces, replace with indent
                else if (token.data.len > stack.getLast()) {
                    try stack.append(token.data.len);
                    var slice: [1]Token = undefined;
                    slice[0] = Token.create("", .INDENT, token.line, token.col);
                    try tokens.replaceRange(i, 1, &slice);
                }
                // If token spaces <  peek spaces => while token spaces < peek spaces {pop, replace with dedent}
                else while (token.data.len < stack.getLast()) {
                    _ = stack.pop();
                    var slice: [1]Token = undefined;
                    slice[0] = Token.create("", .DEDENT, token.line, token.col);
                    try tokens.replaceRange(i, 1, &slice);
                }
            },

            else => {},
        }
    }
}
