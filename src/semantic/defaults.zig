//! This file contains the logic for generating default values for types.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const Span = @import("../util/span.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

pub fn generate_default(_type: *ast_.AST, span: Span, compiler: *Compiler_Context) Validate_Error_Enum!*ast_.AST {
    var retval = (try generate_default_unvalidated(_type, span, compiler)).assert_ast_valid();
    retval.common()._type = _type;
    return retval;
}

fn generate_default_unvalidated(_type: *ast_.AST, span: Span, compiler: *Compiler_Context) Validate_Error_Enum!*ast_.AST {
    // TODO: Too long
    switch (_type.*) {
        .anyptr_type => return _type,
        .identifier => {
            const expanded_type = try _type.expand_type(compiler);
            if (expanded_type == _type) {
                const primitive_info = prelude_.info_from_name(_type.token().data) orelse {
                    compiler.errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
                    return error.CompileError;
                };
                if (primitive_info.default_value != null) {
                    return primitive_info.default_value.?;
                } else {
                    compiler.errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
                    return error.CompileError;
                }
            } else {
                return try generate_default(expanded_type, span, compiler);
            }
        },
        .function => {
            compiler.errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
            return error.CompileError;
        },
        .dyn_type, .addr_of => return ast_.AST.create_int(_type.token(), 0, compiler.allocator()),
        .unit_type => return ast_.AST.create_unit_value(_type.token(), compiler.allocator()),
        .sum_type => {
            var retval = ast_.AST.create_sum_value(_type.token(), compiler.allocator());
            if (_type.sum_type.from == .optional) {
                retval.set_pos(1);
            } else {
                retval.set_pos(0); // if nothing's wrong, then everything's `.ok`!
            }
            retval.sum_value.base = _type;
            const proper_term: *ast_.AST = _type.children().items[0];
            retval.sum_value.init = try generate_default(proper_term, span, compiler);
            return retval;
        },
        .untagged_sum_type => {
            return try generate_default_unvalidated(_type.expr(), span, compiler);
        },
        .call => {
            return try generate_default(try _type.expand_type(compiler), span, compiler);
        },
        .product => {
            var value_terms = std.ArrayList(*ast_.AST).init(compiler.allocator());
            errdefer value_terms.deinit();
            for (_type.children().items) |term| {
                const default_term = try generate_default(term, span, compiler);
                value_terms.append(default_term) catch unreachable;
            }
            return ast_.AST.create_product(_type.token(), value_terms, compiler.allocator());
        },
        .annotation => if (_type.annotation.init != null) {
            return _type.annotation.init.?;
        } else {
            return generate_default(_type.annotation.type, span, compiler);
        },
        else => std.debug.panic("compiler error: unimplemented generate_default() for: AST.{s}", .{@tagName(_type.*)}),
    }
}
