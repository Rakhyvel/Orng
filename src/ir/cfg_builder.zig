// The name of this file is

const std = @import("std");
const Symbol = @import("../symbol/symbol.zig");
const CFG = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const Lower_Context = @import("../ir/lower.zig");
const cfg_validate_ = @import("../semantic/cfg_validate.zig");
const optimizations_ = @import("../ir/optimizations.zig");
const offsets_ = @import("../hierarchy/offsets.zig");

pub fn get_cfg(
    symbol: *Symbol,
    caller: ?*CFG,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Context.Lower_Errors!*CFG {
    std.debug.assert(symbol.kind == .@"fn" or symbol.kind == .@"comptime");
    std.debug.assert(symbol.validation_state == .valid);
    if (symbol.init_validation_state == .validating) {
        errors.add_error(errs_.Error{ .recursive_definition = .{
            .span = symbol.span,
            .symbol_name = symbol.name,
        } });
        return error.CompileError;
    }
    if (symbol.cfg == null) {
        symbol.cfg = CFG.init(symbol, caller, allocator);
        var lower_context = Lower_Context.init(symbol.cfg.?, errors, allocator);
        try lower_context.lower_AST_into_cfg();
        try cfg_validate_.validate_cfg(symbol.cfg.?, errors);
        try optimizations_.optimize(symbol.cfg.?, errors, allocator);
        symbol.cfg.?.collect_generated_symbvers();
        symbol.cfg.?.locals_size = offsets_.calculate_offsets(symbol);
    }
    return symbol.cfg.?;
}
