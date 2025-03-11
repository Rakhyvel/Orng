//! This file contains the semantic validation logic for modules.

const std = @import("std");
const validate_AST = @import("ast_validate.zig").validate_AST;
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const module_ = @import("../hierarchy/module.zig");
const poison_ = @import("../ast/poison.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const Span = @import("../util/span.zig");
const validate_scope_ = @import("scope_validate.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

pub fn validate(module: *module_.Module, compiler: *Compiler_Context) Validate_Error_Enum!void {
    try validate_scope_.validate(compiler.module_scope(module.absolute_path).?, compiler);
    for (0..module.cincludes.items.len) |i| {
        module.cincludes.items[i] = validate_AST(module.cincludes.items[i], primitives_.string_type, compiler);
    }
    try poison_.assert_none_poisoned(module.cincludes.items);
    if (compiler.errors.errors_list.items.len > 0) {
        return error.CompileError;
    }

    if (!module_name_is_good(module.name())) {
        compiler.errors.add_error(errs_.Error{ .symbol_error = .{
            .problem = "has an improper module name",
            .span = Span{ .filename = module.absolute_path, .col = 0, .line_number = 0, .line_text = "" },
            .name = module.name(),
        } });
        return error.CompileError;
    }
}

fn module_name_is_good(module_name: []const u8) bool {
    if (module_name.len == 0) {
        return false;
    }
    if (!std.ascii.isLower(module_name[0])) {
        return false;
    }
    for (module_name) |c| {
        if (!std.ascii.isAlphanumeric(c) and c != '_') {
            return false;
        }
    }
    return true;
}
