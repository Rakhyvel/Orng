const std = @import("std");
const errs = @import("errors.zig");
const compiler = @import("main.zig");
const String = @import("zig-string/zig-string.zig").String;

const Colour = enum {
    none,
    black,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    bright_black,
    bright_red,
    bright_green,
    bright_yellow,
    bright_blue,
    bright_magenta,
    bright_cyan,
    bright_white,
};

pub const Attr = struct {
    fg: Colour = .white,
    bg: Colour = .none,

    // Pretty much all style escape codes I could find, minus a few that are
    // not widely supported.
    bold: bool = false,
    dimmed: bool = false,
    italic: bool = false,
    underline: bool = false,
    blinking: bool = false,
    reverse: bool = false,
    hidden: bool = false,
    overline: bool = false,
    strikethrough: bool = false,

    fn eql(self: Attr, other: Attr) bool {
        inline for (@typeInfo(Attr).Struct.fields) |field| {
            if (@field(self, field.name) != @field(other, field.name)) return false;
        }
        return true;
    }

    fn dump(self: Attr, writer: anytype) !void {
        try writer.writeAll("\x1B[0");
        if (self.bold) try writer.writeAll(";1");
        if (self.dimmed) try writer.writeAll(";2");
        if (self.italic) try writer.writeAll(";3");
        if (self.underline) try writer.writeAll(";4");
        if (self.blinking) try writer.writeAll(";5");
        if (self.reverse) try writer.writeAll(";7");
        if (self.hidden) try writer.writeAll(";8");
        if (self.overline) try writer.writeAll(";53");
        if (self.strikethrough) try writer.writeAll(";9");
        switch (self.fg) {
            .none => {},
            .black => try writer.writeAll(";30"),
            .red => try writer.writeAll(";31"),
            .green => try writer.writeAll(";32"),
            .yellow => try writer.writeAll(";33"),
            .blue => try writer.writeAll(";34"),
            .magenta => try writer.writeAll(";35"),
            .cyan => try writer.writeAll(";36"),
            .white => try writer.writeAll(";37"),
            .bright_black => try writer.writeAll(";90"),
            .bright_red => try writer.writeAll(";91"),
            .bright_green => try writer.writeAll(";92"),
            .bright_yellow => try writer.writeAll(";93"),
            .bright_blue => try writer.writeAll(";94"),
            .bright_magenta => try writer.writeAll(";95"),
            .bright_cyan => try writer.writeAll(";96"),
            .bright_white => try writer.writeAll(";97"),
        }
        switch (self.bg) {
            .none => {},
            .black => try writer.writeAll(";40"),
            .red => try writer.writeAll(";41"),
            .green => try writer.writeAll(";42"),
            .yellow => try writer.writeAll(";43"),
            .blue => try writer.writeAll(";44"),
            .magenta => try writer.writeAll(";45"),
            .cyan => try writer.writeAll(";46"),
            .white => try writer.writeAll(";74"),
            .bright_black => try writer.writeAll(";100"),
            .bright_red => try writer.writeAll(";101"),
            .bright_green => try writer.writeAll(";102"),
            .bright_yellow => try writer.writeAll(";103"),
            .bright_blue => try writer.writeAll(";104"),
            .bright_magenta => try writer.writeAll(";105"),
            .bright_cyan => try writer.writeAll(";106"),
            .bright_white => try writer.writeAll(";107"),
        }
        try writer.writeAll("m");
    }
};

pub fn main() !void {
    // For each file in tests/integration/...
    const allocator = std.heap.page_allocator;
    const out = std.io.getStdOut().writer();
    var revert = Attr{};
    var succeed_color = Attr{ .fg = .green, .bold = true };
    var fail_color = Attr{ .fg = .red, .bold = true };

    try succeed_color.dump(out);
    try out.print("\n[============]\n", .{});
    try revert.dump(out);

    var passed: i64 = 0;
    var failed: i64 = 0;

    // Add all files names in the src folder to `files`
    var dir = try std.fs.cwd().openIterableDir("tests/integration/", .{});
    var it = dir.iterate();
    while (try it.next()) |file| {
        if (file.kind != .File) {
            continue;
        }
        var in_name: String = try String.init_with_contents(allocator, "tests/integration/");
        defer in_name.deinit();
        try in_name.insert(file.name, in_name.len());

        try succeed_color.dump(out);
        try out.print("[ RUN    ... ] ", .{});
        try revert.dump(out);
        try out.print("{s}\n", .{file.name});

        // Read in the expected value and stdout

        // Try to compile Orng (make sure no errors)
        var errors = errs.Errors.init(allocator);
        defer errors.deinit();
        compiler.compile(&errors, in_name.str(), "out.c", allocator) catch {
            try fail_color.dump(out);
            std.debug.print("[ ... FAILED ]\n", .{});
            try revert.dump(out);
            failed += 1;
            std.debug.dumpCurrentStackTrace(128);
            continue;
        };
        if (errors.errors_list.items.len > 0) {
            try fail_color.dump(out);
            std.debug.print("[ ... FAILED ]\n", .{});
            try revert.dump(out);
            failed += 1;
            continue;
        }

        // defer rm out.c

        // compile C (make sure no errors)
        // execute (make sure no signals)
        // Monitor stdout and capture return value, if these don't match expected as commented in the file, print error

        try succeed_color.dump(out);
        try out.print("[ ... PASSED ]\n", .{});
        try revert.dump(out);
        passed += 1;
    }

    try succeed_color.dump(out);
    try out.print("[============]\n", .{});
    try revert.dump(out);
    try out.print("Passed tests: {}\n", .{passed});
    try out.print("Failed tests: {}\n", .{failed});
}
