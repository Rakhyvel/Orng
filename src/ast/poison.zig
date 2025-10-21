const std = @import("std");
const AST = @import("ast.zig").AST;
const Token = @import("../lexer/token.zig");
const Type_AST = @import("../types/type.zig").Type_AST;

pub var poisoned: *AST = undefined;
pub var poisoned_type: *Type_AST = undefined;
var inited: bool = false;

// TODO: This could/should be a component in the compiler context

/// Initializes internal structures if they are not already initialized.
pub fn init_structures(allocator: std.mem.Allocator) void {
    if (!inited) {
        poisoned = AST.create_poison(
            Token.init_simple("LMAO GET POISONED!"),
            allocator,
        );
        poisoned_type = Type_AST.create_poisoned_type(
            Token.init_simple("LMAO GET POISONED!"),
            allocator,
        );
        _ = poisoned.enpoison();
        inited = true;
    }
}

pub fn deinit() void {
    inited = false;
}

pub fn assert_none_poisoned(value: anytype) error{CompileError}!void {
    // This entire function is cursed...
    const T = @TypeOf(value);
    if (T == *std.array_list.Managed(*AST)) {
        for (value.items) |ast| {
            if (ast.* == .poison) {
                return error.CompileError;
            }
        }
    } else switch (@typeInfo(T)) {
        .@"struct" => |info| {
            inline for (info.fields) |f| {
                try assert_none_poisoned(@field(value, f.name));
            }
        },
        .optional => if (value != null and value.?.* == .poison) return error.CompileError,
        .pointer => |info| switch (info.size) {
            .one => if (value.* == .poison) return error.CompileError,
            .slice => for (value) |f| {
                try assert_none_poisoned(f);
            },
            else => unreachable,
        },
        else => {},
    }
}
