const std = @import("std");
const Span = @import("../util/span.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Token = @import("../lexer/token.zig");

const Self: type = @This();

pub fn init() Self {
    return Self{};
}

pub fn run(self: Self, tokens: *std.array_list.Managed(Token)) error{}!*std.array_list.Managed(Token) {
    _ = self;
    strip_comments(tokens);
    combine_multilines(tokens);
    trailing_comma_rules(tokens);
    newline_rules(tokens);
    return tokens;
}

/// Removes comment tokens from token stream. This should be disabled for documentation generation.
fn strip_comments(tokens: *std.array_list.Managed(Token)) void {
    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        const token = tokens.items[i];
        if (token.kind != .comment) {
            continue;
        }

        var j: usize = i;
        while (j >= 0 and (tokens.items[j].kind == .newline or tokens.items[j].kind == .comment)) {
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

fn combine_multilines(tokens: *std.array_list.Managed(Token)) void {
    var i: usize = 0;
    while (i < tokens.items.len) : (i += 1) {
        var out: ?String = null;
        var span: ?Span = null;
        while (i < tokens.items.len and tokens.items[i].kind == .multi_line_string) : (i += 1) {
            if (out == null) {
                out = String.init_with_contents(std.heap.page_allocator, "") catch unreachable;
                span = tokens.items[i].span;
            } else {
                // out was not null => there must have been a multiline before this one => insert newline
                out.?.insert("\n", out.?.len()) catch unreachable;
            }
            const multiline: Token = tokens.orderedRemove(i); // Remove multiline
            _ = tokens.orderedRemove(i); // Remove newline (do not compensate)
            i -|= 1; // Compensate for removed multiline
            out.?.insert(multiline.data, out.?.len()) catch unreachable; // Append data to out
        }
        if (out != null) {
            const token = Token.init(
                (out.?.toOwned() catch unreachable).?,
                .multi_line_string,
                span.?.filename,
                span.?.line_text,
                span.?.line_number,
                span.?.col,
            );
            tokens.insert(i, token) catch unreachable;
        }
    }
}

/// THIS PASS MUST BE RUN BEFORE NEWLINES ARE REMOVED. It uses newlines and
/// parentheses to detect and remove trailing commas and bars.
///
/// Given an input token stream:
///     [ ... X ',' '\n' ')' ... ]
/// The trailing comma/bar is removed, like so:
///     [ ... X ',' ')' ... ]
/// When X is one of the following kind of tokens:
///     1. identifier (including `true` or `false`)
///     2. integer literal (decimal, hexadecimal, octal, or binary)
///     3. floating point literal
///     4. character literal
///     5. string literal
///     6. jump keyword ('unreachable', 'break', 'continue', or 'return')
///     7. closing delimeters (`)`, `]`, or `}`)
///     8. postfix operators (`^`)
fn trailing_comma_rules(tokens: *std.array_list.Managed(Token)) void {
    if (tokens.items.len < 4) {
        return;
    }
    var i: usize = 0;
    while (i < tokens.items.len - 4) : (i += 1) {
        if (tokens.items[i + 0].kind.is_end_token() and
            (tokens.items[i + 1].kind == .comma) and
            tokens.items[i + 2].kind == .newline and
            tokens.items[i + 3].kind == .right_parenthesis)
        {
            _ = tokens.orderedRemove(i + 2); // Remove newline
            i += 2;
            std.debug.assert(tokens.items[i].kind == .right_parenthesis); // Make sure `i` is correct
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
fn newline_rules(tokens: *std.array_list.Managed(Token)) void {
    var stack = std.array_list.Managed(Token.Kind).init(tokens.allocator);
    defer stack.deinit();

    var i: usize = 0;
    while (i < tokens.items.len - 1) : (i += 1) {
        // If token at `i` is a newline, ...
        const token = tokens.items[i];
        if (token.kind == .left_parenthesis or token.kind == .left_brace) {
            stack.append(token.kind) catch unreachable;
        } else if (token.kind == .right_parenthesis or token.kind == .right_brace and stack.items.len > 0) {
            _ = stack.pop();
        } else if (token.kind == .newline) {
            if (stack.items.len > 0 and stack.getLast() == .left_parenthesis) {
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
