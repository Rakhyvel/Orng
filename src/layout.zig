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
                } else if (token.data.len < stack.getLast()) {
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

//////////////////////
// TESTS BEGIN HERE //
//////////////////////

test "condenseNewLines" {
    const lexer = @import("lexer.zig");
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try lexer.getTokens("{\n //comment\n  \n   }", &errors, std.testing.allocator);
    defer tokens.deinit();

    condenseNewLines(&tokens);

    try std.testing.expectEqual(@as(usize, 4), tokens.items.len);
    try std.testing.expectEqual(@as(_token.TokenKind, .L_BRACE), tokens.items[0].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .NEWLINE), tokens.items[1].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .R_BRACE), tokens.items[2].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .EOF), tokens.items[3].kind);
}

test "preemptBinaryOperator" {
    const lexer = @import("lexer.zig");
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try lexer.getTokens("x \n + y \n (y)", &errors, std.testing.allocator);
    defer tokens.deinit();

    preemptBinaryOperator(&tokens);

    try std.testing.expectEqual(@as(usize, 8), tokens.items.len);
    try std.testing.expectEqual(@as(_token.TokenKind, .IDENTIFIER), tokens.items[0].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .PLUS), tokens.items[1].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .IDENTIFIER), tokens.items[2].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .NEWLINE), tokens.items[3].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .L_PAREN), tokens.items[4].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .IDENTIFIER), tokens.items[5].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .R_PAREN), tokens.items[6].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .EOF), tokens.items[7].kind);
}

test "indentation" {
    const lexer = @import("lexer.zig");
    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    var tokens = try lexer.getTokens("x\n    y\n        z\na", &errors, std.testing.allocator);
    defer tokens.deinit();

    try insertIndentDedents(&tokens);

    try std.testing.expectEqual(@as(usize, 10), tokens.items.len);
    try std.testing.expectEqual(@as(_token.TokenKind, .IDENTIFIER), tokens.items[0].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .INDENT), tokens.items[1].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .IDENTIFIER), tokens.items[2].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .INDENT), tokens.items[3].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .IDENTIFIER), tokens.items[4].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .NEWLINE), tokens.items[5].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .DEDENT), tokens.items[6].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .IDENTIFIER), tokens.items[7].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .DEDENT), tokens.items[8].kind);
    try std.testing.expectEqual(@as(_token.TokenKind, .EOF), tokens.items[9].kind);
}
