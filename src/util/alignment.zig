const std = @import("std");

pub fn next_alignment(address: i64, align_to: i64) i64 {
    // std.debug.print("align_to:{}\n", .{align_to});
    std.debug.assert(align_to == 1 or align_to == 2 or align_to == 4 or align_to == 8);
    if (address == 0) {
        return address;
    } else if (address > 0) {
        const div = @divTrunc(address - 1, align_to);
        return div * align_to + align_to;
    } else {
        // needed because offsets can sometimes be negative!
        const div = @divTrunc(address + 1, align_to);
        return div * align_to - align_to;
    }
}
