const std = @import("std");
const AST = @import("ast.zig").AST;
const Monomorph_Map = @import("../ast/type_map.zig").Monomorph_Map;
const Token = @import("../lexer/token.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const unification_ = @import("../types/unification.zig");

const Self = @This();

pub const Ast_Id = usize;

asts: std.array_list.Managed(AST),

pub fn init(alloc: std.mem.Allocator) Self {
    return Self{
        .asts = std.array_list.Managed(AST).init(alloc),
    };
}

pub fn add(self: *Self, ast: AST) !Ast_Id {
    const retval = self.asts.items.len;
    try self.asts.append(ast);
    return retval;
}

pub fn replace(self: *Self, id: Ast_Id, ast: AST) void {
    self.asts.items[id] = ast;
}

pub fn get(self: *const Self, id: Ast_Id) *AST {
    return &self.asts.items[id];
}

/// Clones an AST given a substitution map. If any identifiers match a substitution, they are substituted.
///
/// Deliberately does _not_ copy over symbols and scopes. These need to be re-decorated.
pub fn clone(self: *Self, ast_id: Ast_Id, substs: *unification_.Substitutions, allocator: std.mem.Allocator) !Ast_Id {
    const ast = self.get(ast_id);
    switch (ast.*) {
        inline else => |a| self.clone_ast(a, substs, allocator),
    }
}

fn clone_ast(self: *Self, ast: anytype, substs: *unification_.Substitutions, allocator: std.mem.Allocator) !Ast_Id {
    const T: type = @TypeOf(ast);
    const info = @typeInfo(T);
    std.debug.assert(info == .@"struct");

    var retval: T = undefined;

    inline for (info.@"struct".fields) |field| {
        const Field_Type = field.type;
        const field_type_info = @typeInfo(Field_Type);
        const field_name = field.name;

        const src_field = @field(ast, field_name);
        var dst_field: Field_Type = undefined;

        if (field_type_info == .optional) {
            dst_field = null;
        } else if (Field_Type == Ast_Id) {
            dst_field = try self.clone(src_field, substs, allocator);
        } else if (Field_Type == std.array_list.Managed(Ast_Id)) {
            dst_field = try self.clone_asts(src_field, substs, allocator);
        } else if (Field_Type == Type_AST) {
            dst_field = src_field.clone(substs, allocator);
        } else if (Field_Type == std.array_list.Managed(*Type_AST)) {
            dst_field = Type_AST.clone_types(src_field, substs, allocator);
        } else {
            // Fallback, shallow copy
            dst_field = src_field;
        }

        @field(retval, field_name) = dst_field;
    }

    return retval;
}

pub fn clone_asts(self: *Self, children_terms: std.array_list.Managed(Ast_Id), substs: *unification_.Substitutions, allocator: std.mem.Allocator) !std.array_list.Managed(Ast_Id) {
    var retval = std.array_list.Managed(Ast_Id).init(allocator);
    for (children_terms.items) |child| {
        const cloned_id = self.clone(child, substs, allocator);
        try retval.append(cloned_id);
    }
    return retval;
}

// Expr must be an array value of length `l`. Slice value is `(&expr[0], l)`.
pub fn create_slice_value(self: *Self, expr_id: Ast_Id, _mut: bool, expr_type: *Type_AST, allocator: std.mem.Allocator) Ast_Id {
    const expr = self.get(expr_id);

    var new_terms = std.array_list.Managed(Ast_Id).init(allocator);
    const zero = try self.add(.{ .int = .{ ._token = Token.init_simple("0"), .data = 0 } });
    var index_rhs = std.array_list.Managed(Ast_Id).init(allocator);
    index_rhs.append(zero) catch unreachable;
    const index = try self.add(.{ .index = .{
        ._token = Token.init_simple("0"),
        ._lhs = expr_id,
        ._children = index_rhs,
    } });

    const addr = try self.add(.{ .addr_of = .{
        ._token = expr.token(),
        ._expr = index,
        .mut = _mut,
        .multiptr = true,
    } });
    new_terms.append(addr) catch unreachable;

    const length = expr_type.array_of.len;
    new_terms.append(length) catch unreachable;

    const elem_type = expr_type.child();
    const slice_type = Type_AST.create_slice_type(elem_type, _mut, allocator);
    return try self.add(.{ .struct_value = .{
        ._token = expr.token(),
        ._terms = new_terms,
        .parent = slice_type,
        .was_slice = true,
    } });
}

pub fn create_some_value(self: *Self, opt_type: *Type_AST, value: Ast_Id) !Ast_Id {
    const member = try self.add(.{ .enum_value = .{ ._token = value.token() } });
    member.enum_value.base = opt_type;
    member.enum_value.init = value;
    member.set_pos(opt_type.get_pos("some"));
    return member;
}

pub fn create_none_value(self: *Self, opt_type: *Type_AST) !Ast_Id {
    const member = try self.add(.{ .enum_value = .{ ._token = Token.init_simple("none") } });
    member.enum_value.base = opt_type;
    member.set_pos(opt_type.get_pos("none"));
    return member;
}

pub fn create_binop(self: *Self, _token: Token, _lhs: Ast_Id, _rhs: Ast_Id) !Ast_Id {
    switch (_token.kind) {
        .plus_equals => return try self.add(.{ .add = .{ ._token = _token, ._lhs = _lhs, ._rhs = _rhs } }),
        .minus_equals => return try self.add(.{ .sub = .{ ._token = _token, ._lhs = _lhs, ._rhs = _rhs } }),
        .star_equals => return try self.add(.{ .mult = .{ ._token = _token, ._lhs = _lhs, ._rhs = _rhs } }),
        .slash_equals => return try self.add(.{ .div = .{ ._token = _token, ._lhs = _lhs, ._rhs = _rhs } }),
        .percent_equals => return try self.add(.{ .mod = .{ ._token = _token, ._lhs = _lhs, ._rhs = _rhs } }),
        else => std.debug.panic("compiler error: {s} is not a operator-assign token", .{@tagName(_token.kind)}),
    }
}
