const std = @import("std");
const prelude_ = @import("../hierarchy/prelude.zig");
const Type_AST = @import("../types/type.zig").Type_AST;

pub fn Type_Map(comptime Value: type) type {
    const Key = std.ArrayList(*Type_AST);
    const Pair = struct {
        key: Key,
        value: Value,
    };

    return struct {
        const Self = @This();
        pairs: std.ArrayList(Pair),

        pub fn init(alloc: std.mem.Allocator) Self {
            return .{
                .pairs = std.ArrayList(Pair).init(alloc),
            };
        }

        pub fn get(self: *Self, key: Key) ?Value {
            for (self.pairs.items) |pair| {
                if (lists_match(pair.key, key)) {
                    return pair.value;
                }
            }
            return null;
        }

        pub fn put(self: *Self, key: Key, value: Value) void {
            if (self.get(key)) |_| {
                return;
            }

            self.pairs.append(.{ .key = key.clone() catch unreachable, .value = value }) catch unreachable;
        }

        fn lists_match(lhs: Key, rhs: Key) bool {
            if (lhs.items.len != rhs.items.len) {
                return false;
            }

            for (lhs.items, rhs.items) |lhs_item, rhs_item| {
                if (!lhs_item.types_match(rhs_item) or !rhs_item.types_match(lhs_item)) {
                    return false;
                }
            }

            return true;
        }
    };
}

test "type map" {
    var map = Type_Map(i32).init(std.testing.allocator);
    map.get(prelude_.int_type);
}
