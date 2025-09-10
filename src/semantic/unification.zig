const std = @import("std");
const ast_ = @import("../ast/ast.zig");

pub const Substitutions = std.StringArrayHashMap(*ast_.AST);

// Attempt to match the rhs with the lhs
pub fn unify(lhs: *ast_.AST, rhs: *ast_.AST, withs: std.ArrayList(*ast_.AST), subst: *Substitutions) !void {
    switch (lhs.*) {
        .identifier, .pattern_symbol => {
            if (identifier_is_with(lhs, withs)) |_| {
                try subst.put(lhs.token().data, rhs);
                return;
            }

            if (rhs.* != .identifier or !std.mem.eql(u8, lhs.token().data, rhs.token().data)) {
                return error.TypesMismatch;
            }
        },

        .call => {
            if (rhs.* != .call) {
                return error.TypesMismatch;
            }
            const lhs_constructor = lhs.lhs();
            const rhs_constructor = rhs.common()._unexpanded_type.?.lhs();
            if (!std.mem.eql(u8, lhs_constructor.token().data, rhs_constructor.token().data)) {
                return error.TypesMismatch;
            }
            if (lhs.children().items.len != rhs.common()._unexpanded_type.?.children().items.len) {
                return error.TypesMismatch;
            }

            for (lhs.children().items, rhs.common()._unexpanded_type.?.children().items) |l_arg, r_arg| {
                try unify(l_arg, r_arg, withs, subst);
            }
        },

        else => return, // TODO: Support more types, add error for unsupported constructs
    }
}

pub fn with_list_from_subst_map(subst: *Substitutions, with_decls: std.ArrayList(*ast_.AST), alloc: std.mem.Allocator) std.ArrayList(*ast_.AST) {
    var retval = std.ArrayList(*ast_.AST).init(alloc);
    for (with_decls.items) |with_decl| {
        const with_ident: *ast_.AST = with_decl.decl.pattern;
        const with_value = subst.get(with_ident.token().data).?;
        retval.append(with_value) catch unreachable;
    }
    return retval;
}

fn identifier_is_with(ident: *ast_.AST, withs: std.ArrayList(*ast_.AST)) ?*ast_.AST {
    for (withs.items) |with| {
        const with_ident: *ast_.AST = with.decl.pattern;
        if (std.mem.eql(u8, with_ident.token().data, ident.token().data)) {
            return with;
        }
    }
    return null;
}
