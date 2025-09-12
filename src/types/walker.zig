//! This file defines a generic way to walk over ASTs, applying a walk context to each node.

const std = @import("std");
const Type_AST = @import("type.zig").Type_AST;

pub const Error = error{CompileError};

pub fn Apply_Type_Walk(Context_Type: type) type {
    return struct {
        const Self: type = @This();
        context: Context_Type,

        pub fn init(context: Context_Type) Self {
            return Self{ .context = context };
        }

        pub fn run(self: *Self, types: *std.ArrayList(*Type_AST)) Error!*std.ArrayList(*Type_AST) {
            try walk_types(types, self.context);
            return types;
        }
    };
}

pub fn Apply_Flat_Type_Walk(Context_Type: type) type {
    return struct {
        const Self: type = @This();
        context: Context_Type,

        pub fn init(context: Context_Type) Self {
            return Self{ .context = context };
        }

        pub fn run(self: *Self, types: *std.ArrayList(*Type_AST)) Error!*std.ArrayList(*Type_AST) {
            try walk_types_flat(types, self.context);
            return types;
        }
    };
}

pub fn walk_types(types: *const std.ArrayList(*Type_AST), context: anytype) Error!void {
    for (types.items) |_type| {
        try walk_type(_type, context);
    }
}

pub fn walk_types_flat(types: *std.ArrayList(*Type_AST), context: anytype) Error!void {
    var i: usize = 0;
    while (i < types.items.len) : (i += 1) {
        const _type = types.items[i];
        i += try context.flat(_type, types, i);
    }
}

// A function that walks over an AST, applying prefix, postfix's function to each one
pub fn walk_type(maybe_type: ?*Type_AST, context: anytype) Error!void {
    if (maybe_type == null) {
        return;
    }
    const _type = maybe_type.?;

    var new_context = context;
    if (@hasDecl(@TypeOf(context), "prefix")) {
        const maybe_new_context = try context.prefix(_type);
        if (maybe_new_context == null) {
            return;
        } else {
            new_context = maybe_new_context.?;
        }
    }

    switch (_type.*) {}

    if (@hasDecl(@TypeOf(context), "postfix")) {
        try context.postfix(_type);
    }
}
