const Span = @import("span.zig").Span;
const String = @import("zig-string/zig-string.zig").String;
const _token = @import("token.zig");
const Token = _token.Token;
const TokenKind = _token.TokenKind;
const std = @import("std");

const PRINT_TOKENS = false;

pub fn doLayout(tokens: *std.ArrayList(Token)) void {
    strip_comments(tokens);
    combine_multilines(tokens);
    trailing_comma_rules(tokens);
    newline_rules(tokens);
}

/// Removes comment tokens from token stream. This should be disabled for documentation generation.
fn strip_comments(tokens: *std.ArrayList(Token)) void {
    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        const token = tokens.items[i];
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

fn combine_multilines(tokens: *std.ArrayList(Token)) void {
    var i: usize = 0;
    while (i < tokens.items.len) : (i += 1) {
        var out: ?String = null;
        var span: ?Span = null;
        while (i < tokens.items.len and tokens.items[i].kind == .MULTI_LINE) : (i += 1) {
            if (out == null) {
                out = String.init(std.heap.page_allocator);
                span = tokens.items[i].span;
            } else {
                // out was not null => there must have been a multiline before this one => insert newline
                out.?.insert("\n", out.?.len()) catch unreachable;
            }
            const multiline: Token = tokens.orderedRemove(i); // Remove multiline
            _ = tokens.orderedRemove(i); // Remove newline (do not compensate)
            i -= 1; // Compensate for removed multiline
            out.?.insert(multiline.data, out.?.len()) catch unreachable; // Append data to out
        }
        if (out != null) {
            const token = Token.init((out.?.toOwned() catch unreachable).?, .MULTI_LINE, span.?.filename, span.?.line_text, span.?.line, span.?.col);
            tokens.insert(i, token) catch unreachable;
        }
    }
}

/// THIS PASS MUST BE RUN BEFORE NEWLINES ARE REMOVED. It uses newlines and
/// parentheses to detect and remove trailing commas and bars.
///
/// Given an input token stream:
///     [ ... X ',' '\n' ')' ... ]
/// or:
///     [ ... X '|' '\n' ')' ... ]
/// The trailing comma/bar is removed, like so:
///     [ ... X ',' ')' ... ]
/// respectively:
///     [ ... X '|' ')' ... ]
/// When X is one of the following kind of tokens:
///     1. identifier (including `true` or `false`)
///     2. integer literal (decimal, hexadecimal, octal, or binary)
///     3. floating point literal
///     4. character literal
///     5. string literal
///     6. jump keyword ('unreachable', 'break', 'continue', or 'return')
///     7. closing delimeters (`)`, `]`, or `}`)
///     8. postfix operators (`^`)
fn trailing_comma_rules(tokens: *std.ArrayList(Token)) void {
    if (tokens.items.len < 4) {
        return;
    }
    var i: usize = 0;
    while (i < tokens.items.len - 4) : (i += 1) {
        if (tokens.items[i + 0].kind.is_end_token() and
            (tokens.items[i + 1].kind == .COMMA or tokens.items[i + 1].kind == .BAR) and
            tokens.items[i + 2].kind == .NEWLINE and
            tokens.items[i + 3].kind == .R_PAREN)
        {
            _ = tokens.orderedRemove(i + 2); // Remove newline
            i += 2;
            std.debug.assert(tokens.items[i].kind == .R_PAREN); // Make sure `i` is correct
        }
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
fn newline_rules(tokens: *std.ArrayList(Token)) void {
    var stack = std.ArrayList(TokenKind).init(tokens.allocator);
    defer stack.deinit();

    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        // If token at `i` is a newline, ...
        const token = tokens.items[i];
        if (token.kind == .L_PAREN or token.kind == .L_BRACE) {
            stack.append(token.kind) catch unreachable;
        } else if (token.kind == .R_PAREN or token.kind == .R_BRACE and stack.items.len > 0) {
            const popped = stack.pop();
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
