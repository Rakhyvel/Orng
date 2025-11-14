const std = @import("std");
const AST = @import("../ast/ast.zig").AST;

/// Takes a format string and returns a list of things to print out
pub fn parse_fmt_string(fmt_str: *AST, allocator: std.mem.Allocator) !std.array_list.Managed(*AST) {
    std.debug.assert(fmt_str.* == .string);

    const data = fmt_str.string.data;
    std.debug.print("data: '{s}'\n", .{data});

    var retval = std.array_list.Managed(*AST).init(allocator);
    try retval.append(fmt_str);
    return retval;
}
