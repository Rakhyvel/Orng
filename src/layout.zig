const errs = @import("errors.zig");
const _token = @import("token.zig");
const Token = _token.Token;
const std = @import("std");

// Removes any newlines after the first newline in a series of newline tokens
pub fn condenseNewLines(tokens: *std.ArrayList(Token)) void {
    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        var token = tokens.items[i];
        if (token.kind != .NEWLINE) {
            continue;
        }

        while (i > 0 and tokens.items[i + 1].kind == .NEWLINE) {
            _ = tokens.orderedRemove(i + 1);
            i -= 1;
        }
    }
}

// function where newlines are pre-empted by binary operators and other newlines
pub fn preemptBinaryOperator(tokens: *std.ArrayList(Token)) void {
    // Loop through list of tokens...
    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        // If token at `i` is a newline, ...
        var token = tokens.items[i];
        if (token.kind != .NEWLINE) {
            continue;
        }

        var next = tokens.items[i + 1];
        for (_token.binaryOperators) |binopKind| {
            if (next.kind == binopKind) {
                // But the next token is a binary operator, remove the newline.
                _ = tokens.orderedRemove(i);
                i -= 1;
                break;
            }
        }
    }
}

// converts newlines to indent/dedent tokens
// a newline follows a sequence of one or more dedents
pub fn insertIndentDedents(tokens: *std.ArrayList(Token)) !void {
    // Setup a stack of indentation sizes
    // This is like a precedence stack for infix => postfix transformation
    var stack: std.ArrayList(usize) = std.ArrayList(usize).init(tokens.allocator);
    defer stack.deinit();
    try stack.append(1);

    // Go through tokens and convert some newlines to INDENT and DEDENT tokens
    var i: usize = 0;
    while (i < tokens.items.len) : (i += 1) {
        var token = tokens.items[i];
        switch (token.kind) {
            .NEWLINE => {
                if (token.data.len == stack.getLast()) {
                    // If token spaces == peek spaces => do nothing
                    // This implies this new line is a separator, not an indentor
                } else if (token.data.len > stack.getLast()) {
                    // If token spaces >  peek spaces => append token spaces, replace with indent
                    try stack.append(token.data.len);
                    var slice: [1]Token = undefined;
                    slice[0] = Token.create("", .INDENT, token.span.line, token.span.col);
                    try tokens.replaceRange(i, 1, &slice);
                } else while (token.data.len < stack.getLast()) {
                    // If token spaces <  peek spaces => while token spaces < peek spaces {pop, replace with dedent}
                    _ = stack.pop();
                    var slice: [2]Token = undefined;
                    slice[0] = token;
                    slice[1] = Token.create("", .DEDENT, token.span.line, token.span.col);
                    try tokens.replaceRange(i, 1, &slice);
                }
            },

            // Ignore other tokens besides newlines
            else => {},
        }
    }

    // The file might not end in a newline. If this is the case, the stack will
    // not be empty, and not enough dedents will be inserted.
    // Insert one less than the stack length dedents before the EOF
    if (stack.items.len > 1) {
        const lastToken = tokens.getLast();
        var dedents_to_insert: usize = stack.items.len - 1;
        while (dedents_to_insert > 0) : (dedents_to_insert -= 1) {
            try tokens.insert(tokens.items.len - 1, Token.create("", .DEDENT, lastToken.span.line, lastToken.span.col));
        }
    }
}

pub fn doLayout(tokens: *std.ArrayList(Token)) !void {
    condenseNewLines(tokens);
    preemptBinaryOperator(tokens);
    try insertIndentDedents(tokens);
}
