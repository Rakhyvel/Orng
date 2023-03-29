const Token = @import("token.zig").Token;
const std = @import("std");
const ctype = @cImport(@cInclude("ctype.h"));

pub fn getTokens(line: []u8, tokens: *std.ArrayList(Token)) !void {
    var i: usize = 0;
    while (i < line.len) : (i += 1) {
        var string = std.ArrayList(u8).init(std.heap.page_allocator);
        errdefer string.deinit();

        try string.append(line[i]);
        i += 1;

        while (i < line.len and !shouldSplitToken(line[i], string.items[0])) : (i += 1) {
            try string.append(line[i]);
        }
        i -= 1;
        var data = string.toOwnedSlice();
        std.debug.print("[{s}]\n", .{try data});
    }
    _ = tokens;
}

fn shouldSplitToken(c: u8, start: u8) bool {
    if (start == '\n' //
    or start == ')' //
    or start == '{' //
    or start == '}' //
    or start == '[' //
    or start == ']' //
    or start == ';' //
    or start == '?' //
    or start == ':' //
    or start == ',' //
    or (start == '(' and c != '|') //
    or (start == '=' and c != '=' and c != '>') //
    or (start == '&' and c != '&' and c != '=') //
    or (start == '|' and c != '|' and c != '=') //
    or (start == '<' and c != '<' and c != '=') //
    or (start == '>' and c != '>' and c != '=') //
    or (start == '.' and c != '.') //
    or (start == '+' and c != '+' and c != '=') //
    or (start == '-' and c != '>' and c != '-' and c != '=') //
    or (start == '*' and c != '=') //
    or (start == '/' and c != '=' and c != '/') //
    or (start == '%' and c != '=') //
    or (start == '!' and c != '=')) {
        return true;
    } else {
        return getCharType(c) != getCharType(start);
    }
}

fn getCharType(c: u8) i32 {
    if (ctype.isalnum(c) != 0 or c == '_') {
        return 0;
    } else if (ctype.isspace(c) != 0) {
        return 1;
    } else {
        return 2;
    }
}
