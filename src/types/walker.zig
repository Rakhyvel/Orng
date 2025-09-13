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
        i += try context.flat_type(_type, types, i);
    }
}

// A function that walks over an AST, applying prefix, postfix's function to each one
pub fn walk_type(maybe_type: ?*Type_AST, context: anytype) Error!void {
    if (maybe_type == null) {
        return;
    }
    const _type = maybe_type.?;

    var new_context = context;
    if (@hasDecl(@TypeOf(context), "prefix_type")) {
        const maybe_new_context = try context.prefix_type(_type);
        if (maybe_new_context == null) {
            return;
        } else {
            new_context = maybe_new_context.?;
        }
    }

    switch (_type.*) {
        .poison, .anyptr_type, .unit_type, .identifier, .access, .type_of => {},

        .annotation,
        .untagged_sum_type,
        .addr_of,
        .dyn_type,
        .slice_of,
        .array_of,
        .index,
        .domain_of,
        => {
            try walk_type(_type.child(), new_context);
        },

        .function,
        .@"union",
        => {
            try walk_type(_type.lhs(), new_context);
            try walk_type(_type.rhs(), new_context);
        },

        .sum_type,
        .product,
        => {
            try walk_types(_type.children(), new_context);
        },
    }

    if (@hasDecl(@TypeOf(context), "postfix_type")) {
        try context.postfix_type(_type);
    }
}
