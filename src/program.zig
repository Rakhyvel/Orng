const std = @import("std");
const CFG = @import("ir.zig").CFG;

/// This structure represents the entire program being compiled
pub const Program = struct {
    // CFG node of entry program point
    callGraph: *CFG,

    // A unique identifier for the event of compiling this Orng program
    uid: i64,

    // A graph of type dependencies

    // A map of includes (key? Or is it really a set)

    // A map of filenames to lists of lines

    pub fn init(callGraph: *CFG, allocator: std.mem.Allocator) !*Program {
        var retval = try allocator.create(Program);
        retval.callGraph = callGraph;
        retval.uid = std.time.timestamp();
        return retval;
    }
};
