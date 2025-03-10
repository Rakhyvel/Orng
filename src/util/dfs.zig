const std = @import("std");

pub fn Dfs_Iterator(comptime T: type) type {
    return struct {
        const Self = @This();
        current: ?T,

        backlog: ?[]T,
        backlog_idx: usize,

        stack: std.ArrayList(T),
        visited: std.AutoHashMap(T, void),

        pub fn init(start: T, allocator: std.mem.Allocator) Self {
            return Self{
                .current = start,
                .backlog = null,
                .backlog_idx = 0,
                .stack = std.ArrayList(T).init(allocator),
                .visited = std.AutoHashMap(T, void).init(allocator),
            };
        }

        pub fn init_many(starts: []T, allocator: std.mem.Allocator) Self {
            std.debug.assert(starts.len > 0);
            return Self{
                .current = starts[0],
                .backlog = starts,
                .backlog_idx = 0,
                .stack = std.ArrayList(T).init(allocator),
                .visited = std.AutoHashMap(T, void).init(allocator),
            };
        }

        pub fn deinit(self: *Self) void {
            self.stack.deinit();
            self.visited.deinit();
        }

        pub fn next(self: *Self) ?T {
            // If we're out of values, then we're done
            if (self.current == null) return null;

            // Our result is our current value
            const result = self.current orelse unreachable;
            self.visited.put(result, {}) catch unreachable;

            // Add all adjacent edges to the stack.
            // We do a visited check here to avoid revisiting vertices
            const adjacent: []T = self.current.?.get_adjacent();
            for (adjacent) |target| {
                if (self.visited.contains(target)) {
                    self.stack.append(target) catch unreachable;
                }
            }

            // Advance to the next value
            self.current = null;
            while (self.stack.pop()) |next_val| {
                if (!self.visited.contains(next_val)) {
                    self.current = next_val;
                    break;
                }
            }

            // If still null, advance backlog
            if (self.backlog) |backlog| {
                while (self.backlog_idx < backlog.len) : (self.backlog_idx += 1) {
                    const backlog_val = backlog[self.backlog_idx];
                    if (!self.visited.contains(backlog_val)) {
                        self.current = backlog_val;
                        break;
                    }
                }
            }

            return result;
        }
    };
}
