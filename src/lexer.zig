const Token = @import("token.zig").Token;
const std = @import("std");
const ctype = @cImport(@cInclude("ctype.h"));

pub fn getTokens(line: []u8, tokens: *std.ArrayList(Token)) !usize {
    var i: usize = 0;
    var indentation: usize = 0;
    // Count leading indentation for this line
    while (i < line.len and ctype.isspace(line[i]) != 0) {
        indentation += 1;
        i += 1;
    }

    // Iterate through line, find tokens
    while (i < line.len) : (i += 1) {
        var string = std.ArrayList(u8).init(std.heap.page_allocator);
        errdefer string.deinit();

        // Check for comment at begining of token
        if (i < line.len - 1 and line[i] == '/' and line[i + 1] == '/') {
            var literals_shouldnt_be_const: [1]u8 = undefined;
            literals_shouldnt_be_const[0] = '\n';
            try tokens.append(Token.create(&literals_shouldnt_be_const));
            break;
        }

        try string.append(line[i]);
        i += 1;

        // Keep iterating until end of token
        while (i < line.len and !shouldSplitToken(line[i], string.items[0])) : (i += 1) {
            try string.append(line[i]);
        }
        try tokens.append(Token.create(try string.toOwnedSlice()));

        // Skip trailing whitespace after token
        while (i < line.len and ctype.isspace(line[i]) != 0) : (i += 1) {
            if (line[i] == '\n') {
                var literals_shouldnt_be_const: [1]u8 = undefined;
                literals_shouldnt_be_const[0] = '\n';
                try tokens.append(Token.create(&literals_shouldnt_be_const));
            }
        }
    }
    return indentation;
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
