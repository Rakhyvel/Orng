//! This file contains the semantic validation logic for types.
const std = @import("std");
const errs_ = @import("../util/errors.zig");
const Type_AST = @import("type.zig").Type_AST;

const Validate_Error_Enum = error{CompileError};

pub fn validate(@"type": *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    switch (@"type".*) {
        .identifier => {
            if (!@"type".symbol().?.refers_to_type()) {
                errors.add_error(errs_.Error{ .basic = .{ .msg = "expected a type", .span = @"type".token().span } });
                return error.CompileError;
            }
        },

        else => {},
    }
}
