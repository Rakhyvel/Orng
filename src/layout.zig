const errs = @import("errors.zig");
const _token = @import("token.zig");
const Token = _token.Token;
const TokenKind = _token.TokenKind;
const std = @import("std");

const PRINT_TOKENS = false;

pub fn doLayout(tokens: *std.ArrayList(Token)) !void {
    strip_comments(tokens);
    try newline_rules(tokens);
}

/// Removes comment tokens from token stream. This should be disabled for documentation generation.
fn strip_comments(tokens: *std.ArrayList(Token)) void {
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

/// A newline token is removed if it is immediately surrounded by parenthesis. If
/// it is immediately surrounded by braces, it is removed when not preceded by the
/// following token kinds:
///     1. identifier (including `true` or `false`)
///     2. integer literal (decimal, hexadecimal, octal, or binary)
///     3. floating point literal
///     4. character literal
///     5. string literal
///     6. jump keywords (`unreachable`, `break`, `continue`, or `return`)
///     7. closing delimiters (`)`, `]`, or `}`)
///     8. postfix operators (`^`)
/// Otherwise, the newline token is removed.
fn newline_rules(tokens: *std.ArrayList(Token)) !void {
    var stack = std.ArrayList(TokenKind).init(tokens.allocator);
    defer stack.deinit();

    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        // If token at `i` is a newline, ...
        var token = tokens.items[i];
        if (token.kind == .L_PAREN or token.kind == .L_BRACE) {
            try stack.append(token.kind);
        } else if (token.kind == .R_PAREN or token.kind == .R_BRACE and stack.items.len > 0) {
            var popped = stack.pop();
            if (popped != token.kind) {
                // TODO: Throw a great big ol fit
            }
        } else if (token.kind == .NEWLINE) {
            if (stack.items.len > 0 and stack.getLast() == .L_PAREN) {
                // Remove if stack is not empty and l paren is on top of stack
                _ = tokens.orderedRemove(i);
                i -|= 1;
            } else if (i == 0 or !tokens.items[i - 1].kind.is_end_token()) {
                // Remove newline if previous token was not a line-ending token
                _ = tokens.orderedRemove(i);
                i -|= 1;
            }
        }
    }
}
