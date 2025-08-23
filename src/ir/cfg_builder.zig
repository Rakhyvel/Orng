// The name of this file is

const std = @import("std");
const Symbol = @import("../symbol/symbol.zig");
const CFG = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");
const Lower_Context = @import("../ir/lower.zig");
const cfg_validate_ = @import("../semantic/cfg_validate.zig");
const optimizations_ = @import("../ir/optimizations.zig");

pub fn get_cfg(
    symbol: *Symbol,
    interned_strings: *Interned_String_Set,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Context.Lower_Errors!*CFG {
    std.debug.assert(symbol.kind == .@"fn" or symbol.kind == .@"comptime" or symbol.kind == .@"test");
    std.debug.assert(symbol.validation_state == .valid);
    if (symbol.init_validation_state == .validating) {
        errors.add_error(errs_.Error{ .recursive_definition = .{
            .span = symbol.span,
            .symbol_name = symbol.name,
        } });
        return error.CompileError;
    }
    if (symbol.cfg == null) {
        symbol.cfg = CFG.init(symbol, allocator);
        var lower_context = Lower_Context.init(symbol.cfg.?, interned_strings, errors, allocator);
        try lower_context.lower_AST_into_cfg();
        try cfg_validate_.validate_cfg(symbol.cfg.?, errors);
        try optimizations_.optimize(symbol.cfg.?, errors, allocator);
        symbol.cfg.?.collect_generated_symbvers();
    }
    return symbol.cfg.?;
}
