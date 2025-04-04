//! This file contains the logic for generating default values for types.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const Span = @import("../util/span.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

pub fn generate_default(_type: *ast_.AST, span: Span, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!*ast_.AST {
    var retval = (try generate_default_unvalidated(_type, span, errors, allocator)).assert_ast_valid();
    retval.common()._type = _type;
    return retval;
}

fn generate_default_unvalidated(_type: *ast_.AST, span: Span, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!*ast_.AST {
    // TODO: Too long
    switch (_type.*) {
        .anyptr_type => return _type,
        .identifier => {
            const expanded_type = _type.expand_type(allocator);
            if (expanded_type == _type) {
                const primitive_info = primitives_.info_from_name(_type.token().data) orelse {
                    errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
                    return error.CompileError;
                };
                if (primitive_info.default_value != null) {
                    return primitive_info.default_value.?;
                } else {
                    errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
                    return error.CompileError;
                }
            } else {
                return try generate_default(expanded_type, span, errors, allocator);
            }
        },
        .function => {
            errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
            return error.CompileError;
        },
        .dyn_type, .addr_of => return ast_.AST.create_int(_type.token(), 0, allocator),
        .unit_type => return ast_.AST.create_unit_value(_type.token(), allocator),
        .sum_type => {
            var retval = ast_.AST.create_sum_value(_type.token(), allocator);
            if (_type.sum_type.from == .optional) {
                retval.set_pos(1);
            } else {
                retval.set_pos(0); // if nothing's wrong, then everything's `.ok`!
            }
            retval.sum_value.base = _type;
            const proper_term: *ast_.AST = _type.children().items[0];
            retval.sum_value.init = try generate_default(proper_term, span, errors, allocator);
            return retval;
        },
        .call => {
            return try generate_default(_type.expand_type(allocator), span, errors, allocator);
        },
        .product => {
            var value_terms = std.ArrayList(*ast_.AST).init(allocator);
            errdefer value_terms.deinit();
            for (_type.children().items) |term| {
                const default_term = try generate_default(term, span, errors, allocator);
                value_terms.append(default_term) catch unreachable;
            }
            return ast_.AST.create_product(_type.token(), value_terms, allocator);
        },
        .annotation => if (_type.annotation.init != null) {
            return _type.annotation.init.?;
        } else {
            return generate_default(_type.annotation.type, span, errors, allocator);
        },
        else => std.debug.panic("compiler error: unimplemented generate_default() for: AST.{s}", .{@tagName(_type.*)}),
    }
}
