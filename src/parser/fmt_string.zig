const std = @import("std");
const AST = @import("../ast/ast.zig").AST;
const errs_ = @import("../util/errors.zig");
const Span = @import("../util/span.zig");

const pipeline_ = @import("../util/pipeline.zig");

const Split_Lines = @import("../lexer/split_lines.zig");
const Tokenize = @import("../lexer/tokenize.zig");
const Apply_Layout = @import("../lexer/apply_layout.zig");
const Parse = @import("../parser/parse.zig");

/// Takes a format string and returns a list of things to print out
pub fn parse_fmt_string(fmt_str: *AST, span: Span, errors: *errs_.Errors, allocator: std.mem.Allocator) !std.array_list.Managed(*AST) {
    std.debug.assert(fmt_str.* == .string);

    const data = fmt_str.string.data;

    var retval = std.array_list.Managed(*AST).init(allocator);

    var i: usize = 0;
    var prev: usize = 0;
    while (i < data.len) : (i += 1) {
        if (data[i] == '{') {
            if (i + 1 == data.len) {
                var err_span = span;
                err_span.col -= data.len;
                err_span.col += i;
                errors.add_error(errs_.Error{ .basic = .{
                    .span = err_span,
                    .msg = "unexpected end of format string",
                } });
                return error.ParseError;
            } else if (data[i + 1] == '{') {
                try retval.append(AST.create_string(fmt_str.token(), data[prev..i], allocator));
                i += 1;
                prev = i;
            } else {
                var end = i;
                while (end < data.len and data[end] != '}') : (end += 1) {}
                if (end == data.len) {
                    var err_span = span;
                    err_span.col -= data.len;
                    err_span.col += i;
                    errors.add_error(errs_.Error{ .basic = .{
                        .span = err_span,
                        .msg = "unexpected end of format string",
                    } });
                    return error.ParseError;
                }
                if (end - i <= 1) {
                    var err_span = span;
                    err_span.col -= data.len;
                    err_span.col += i;
                    errors.add_error(errs_.Error{ .basic = .{
                        .span = err_span,
                        .msg = "empty format argument",
                    } });
                    return error.ParseError;
                }
                if (i > prev) {
                    try retval.append(AST.create_string(fmt_str.token(), data[prev..i], allocator));
                    prev = i;
                }

                const asts = pipeline_.run(data[i + 1 .. end], .{
                    Split_Lines.init(errors, allocator),
                    Tokenize.init(span.filename, span.line_number, span.col, errors, false, allocator),
                    Parse.init(.expr, errors, allocator),
                }) catch return error.ParseError;

                try retval.append(asts.items[0]);
                i = end;
                prev = i + 1;
            }
        } else if (data[i] == '}') {
            if (i + 1 == data.len) {
                var err_span = span;
                err_span.col -= data.len;
                err_span.col += i;
                errors.add_error(errs_.Error{ .basic = .{
                    .span = err_span,
                    .msg = "unexpected end of format string",
                } });
                return error.ParseError;
            } else if (data[i + 1] == '}') {
                try retval.append(AST.create_string(fmt_str.token(), data[prev .. i - 1], allocator));
                i += 1;
                prev = i;
            } else {
                var err_span = span;
                err_span.col -= data.len;
                err_span.col += i;
                errors.add_error(errs_.Error{ .basic = .{
                    .span = err_span,
                    .msg = "expected `}`",
                } });
                return error.ParseError;
            }
        }
    }

    if (i > prev) {
        try retval.append(AST.create_string(fmt_str.token(), data[prev..i], allocator));
    }

    for (retval.items) |item| {
        std.debug.print("{f} ", .{item});
    }
    std.debug.print("\n", .{});

    return retval;
}
