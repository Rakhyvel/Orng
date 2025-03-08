//! This file contains the semantic validation logic for modules.

const validate_AST = @import("ast_validate.zig").validate_AST;
const Compiler_Context = @import("../compilation/compiler.zig");
const module_ = @import("../hierarchy/module.zig");
const poison_ = @import("../ast/poison.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const validate_scope_ = @import("scope_validate.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

pub fn validate(module: *module_.Module, compiler: *Compiler_Context) Validate_Error_Enum!void {
    try validate_scope_.validate(module.top_level_scope(), compiler);
    for (0..module.cincludes.items.len) |i| {
        module.cincludes.items[i] = validate_AST(module.cincludes.items[i], primitives_.string_type, compiler);
    }
    try poison_.assert_none_poisoned(module.cincludes.items);
    if (compiler.errors.errors_list.items.len > 0) {
        return error.CompileError;
    }
}
