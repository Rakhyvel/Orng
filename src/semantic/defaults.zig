//! This file contains the logic for generating default values for types.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Ast_Id = @import("../ast/ast_store.zig").Ast_Id;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const Span = @import("../util/span.zig");
const Type_AST = @import("../types/type.zig").Type_AST;

const Validate_Error_Enum = error{CompileError};

pub fn generate_default(_type: *Type_AST, span: Span, ctx: *Compiler_Context) Validate_Error_Enum!Ast_Id {
    switch (_type.*) {
        .identifier => {
            const expanded_type = _type.expand_identifier();
            if (expanded_type == _type) {
                const primitive_info = prelude_.info_from_name(_type.token().data) orelse {
                    ctx.errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
                    return error.CompileError;
                };
                if (primitive_info.default_value != null) {
                    return primitive_info.default_value.?;
                } else {
                    ctx.errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
                    return error.CompileError;
                }
            } else {
                return try generate_default(expanded_type, span, ctx);
            }
        },
        .function => {
            ctx.errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
            return error.CompileError;
        },
        .dyn_type, .addr_of => return try ctx.ast_store.add(.{ .int = .{ ._token = _type.token(), .data = 0 } }),
        .unit_type => return try ctx.ast_store.add(.{ .unit_value = .{ ._token = _type.token() } }),
        .enum_type => {
            const pos = if (_type.enum_type.from == .optional) 1 else 0;
            const proper_term: *Type_AST = _type.children().items[pos];
            return try ctx.ast_store.add(.{ .enum_value = .{
                ._token = _type.children().items[pos].annotation.pattern.token(),
                ._pos = pos,
                .base = _type,
                .init = try generate_default(proper_term, span, ctx),
            } });
        },
        .untagged_sum_type => {
            return try generate_default(_type.child(), span, ctx);
        },
        .struct_type => {
            var value_terms = std.array_list.Managed(Ast_Id).init(ctx.allocator());
            errdefer value_terms.deinit();
            for (_type.children().items) |term| {
                const default_term = try generate_default(term, span, ctx);
                value_terms.append(default_term) catch unreachable;
            }
            return try ctx.ast_store.add(.{ .struct_value = .{
                ._token = _type.token(),
                .parent = _type,
                ._terms = value_terms,
            } });
        },
        .tuple_type => {
            var value_terms = std.array_list.Managed(Ast_Id).init(ctx.allocator());
            errdefer value_terms.deinit();
            for (_type.children().items) |term| {
                const default_term = try generate_default(term, span, ctx);
                value_terms.append(default_term) catch unreachable;
            }
            return try ctx.ast_store.add(.{ .tuple_value = .{
                ._token = _type.token(),
                ._terms = value_terms,
            } });
        },
        .annotation => if (_type.annotation.init != null) {
            return _type.annotation.init.?;
        } else {
            return generate_default(_type.child(), span, ctx);
        },
        .array_of => {
            var value_terms = std.array_list.Managed(Ast_Id).init(ctx.allocator());
            const child = try generate_default(_type.child(), span, ctx);
            for (0..@intCast(_type.array_of.len.int.data)) |_| {
                value_terms.append(child) catch unreachable;
            }
            return try ctx.ast_store.add(.{ .array_value = .{
                ._token = _type.token(),
                ._terms = value_terms,
            } });
        },

        .generic_apply => return generate_default(_type.generic_apply._symbol.?.init_typedef().?, span, ctx),

        .poison,
        .anyptr_type,
        .access,
        .type_of,
        .domain_of,
        .index,
        => std.debug.panic("compiler error: unimplemented generate_default() for: AST.{s}", .{@tagName(_type.*)}),
    }
}
