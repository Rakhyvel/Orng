// Tree Writer allows for easy formatted pretty-printing of tree structures, such as ASTs, Symbol trees, and lvalue trees

const std = @import("std");
const String = @import("zig-string/zig-string.zig").String;

const Tree_Writer = @This();

// backing string behind the scenes
out: String,

// number of spaces to prepend before each new line
indentation: i16,

// how much each tab is in spaces
tab_size: i16,

/// Initializes a new Tree Writer
pub fn init(tab_size: i16, alloc: std.mem.Allocator) Tree_Writer {
    return .{
        .out = String.init(alloc),
        .indentation = 0,
        .tab_size = tab_size,
    };
}

/// Deinitializes a Tree Writer.
pub fn deinit(self: *Tree_Writer) void {
    self.out.deinit();
}

/// Returns a caller-owned string after writing, deinitializes the Tree Writer.
pub fn to_owned(self: *Tree_Writer) []u8 {
    defer self.deinit();
    return (self.out.toOwned() catch unreachable).?;
}

/// Prints formatted text to the backing String
pub fn print(self: *Tree_Writer, comptime fmt: []const u8, args: anytype) void {
    self.out.writer().print(fmt, args) catch unreachable;
}

/// Prints formatted text to the backing String, with a newline and possible change in indentation
pub fn println(self: *Tree_Writer, comptime fmt: []const u8, args: anytype, change_in_tabs: i16) void {
    self.print(fmt, args);
    self.newline(change_in_tabs);
}

/// Goes to newline, with a possible change in indentation
pub fn newline(self: *Tree_Writer, change_in_tabs: i16) void {
    self.indentation += change_in_tabs * self.tab_size;
    self.out.writer().writeByte('\n') catch unreachable;
    for (0..@intCast(self.indentation)) |_| {
        self.out.writer().writeByte(' ') catch unreachable;
    }
}
