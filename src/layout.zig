const errs = @import("errors.zig");
const _token = @import("token.zig");
const Token = _token.Token;
const TokenKind = _token.TokenKind;
const std = @import("std");

const PRINT_TOKENS = false;

pub fn doLayout(tokens: *std.ArrayList(Token)) !void {
    commentPreempt(tokens);
    preemptBinaryOperator(tokens);
    try paren_rules(tokens);
}

fn commentPreempt(tokens: *std.ArrayList(Token)) void {
    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        var token = tokens.items[i];
        if (token.kind != .COMMENT) {
            continue;
        }

        var j: usize = i;
        while (j >= 0 and (tokens.items[j].kind == .NEWLINE or tokens.items[j].kind == .COMMENT)) {
            _ = tokens.orderedRemove(j);
            if (j != 0) {
                j -= 1;
            } else {
                break;
            }
        }
        i = j;
    }
}

// function where newlines are pre-empted by binary operators and other newlines
fn preemptBinaryOperator(tokens: *std.ArrayList(Token)) void {
    // Loop through list of tokens...
    var i: usize = 0;
    var prev_indent: i64 = 1;
    var line_start: i64 = 1;
    var do_line_start = true;
    while (i < tokens.items.len - 1) : (i += 1) {
        // If token at `i` is a newline, ...
        var token = tokens.items[i];
        if (token.kind != .NEWLINE) {
            do_line_start = true;
            continue;
        }

        var next = tokens.items[i + 1];
        prev_indent = @as(i64, @intCast(next.span.col)) - @as(i64, @intCast(next.data.len)) - 1;
        for (_token.binaryOperators) |binopKind| {
            if (next.kind == binopKind and (prev_indent >= line_start)) {
                // But the next token is a binary operator, remove the newline.
                _ = tokens.orderedRemove(i);
                i -= 1;
                break;
            }
        } else if (do_line_start) {
            do_line_start = false;
            line_start = prev_indent;
        }
    }
}

// Remove newlines from within parenthesis, unless interrupted by a brace
fn paren_rules(tokens: *std.ArrayList(Token)) !void {
    var stack = std.ArrayList(TokenKind).init(tokens.allocator);
    defer stack.deinit();

    // Loop through list of tokens...
    var i: usize = 0;
    while (i < tokens.items.len) : (i += 1) {
        // If token at `i` is a newline, ...
        var token = tokens.items[i];
        if (token.kind == .L_PAREN or token.kind == .L_BRACE) {
            try stack.append(token.kind);
        } else if (token.kind == .R_PAREN or token.kind == .R_BRACE) {
            var popped = stack.pop();
            if (popped != token.kind) {
                // TODO: Throw fit
            }
        } else if (token.kind == .NEWLINE) {
            // Remove if stack is not empty and l paren is on top of stack
            if (stack.items.len > 0 and stack.getLast() == .L_PAREN) {
                _ = tokens.orderedRemove(i);
                i -= 1;
            }
        }
    }
}
