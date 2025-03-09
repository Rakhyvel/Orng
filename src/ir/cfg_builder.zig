// The name of this file is

const std = @import("std");
const alignment_ = @import("../util/alignment.zig");
const Symbol = @import("../symbol/symbol.zig");
const CFG = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");
const Lower_Context = @import("../ir/lower.zig");
const cfg_validate_ = @import("../semantic/cfg_validate.zig");
const optimizations_ = @import("../ir/optimizations.zig");

pub fn get_cfg(
    symbol: *Symbol,
    caller: ?*CFG,
    interned_strings: *Interned_String_Set,
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
        var lower_context = Lower_Context.init(symbol.cfg.?, interned_strings, errors, allocator);
        try lower_context.lower_AST_into_cfg();
        try cfg_validate_.validate_cfg(symbol.cfg.?, errors);
        try optimizations_.optimize(symbol.cfg.?, errors, allocator);
        symbol.cfg.?.collect_generated_symbvers();
        symbol.cfg.?.locals_size = calculate_offsets(symbol);
    }
    return symbol.cfg.?;
}

/// Fills in a CFG's local offsets
///
/// ## The Orng interpreter calling convention
/// (stack grows up btw, lmao)
/// ```
///       |         |
/// sp -> |         |
///       | ------- | \
///       | local 2 |  |
///       | ------- |  |
///       | local 1 |  |
/// bp -> | ret-adr |  | - callee stack frame
///    -8 | prev-bp |  |
///   -16 | prev-sp |  |
///   -24 | &retval |  | \
///       | ------- |  |  |
///       | - pad - |  |  |
///       | ------- |  |  |
///   -28 | arg 1   |  |  |
///       | arg 2   |  |  |
///   -30 | arg 2   | /   | - caller stack frame
///       | - pad - |     |
///   -32 | arg 3   |     |
///       | - pad - |     |
///       | local 2 |     |
/// ```
///
/// - Entry (caller)
///   * (save sp, will be pushed later)
///   - push args in reverse order
///   - push address to return-value slot
///   - `call` instruction
///     * push pre-arg sp
///     * push bp
///     * push ret-addr
///     * bp := sp
///   - sp += n  (allocate space for locals)
///
/// - Exit (callee)
///   - sp := bp   (deallocate locals)
///   - `ret` instruction
///     * ip := pop  (set ip to ret-addr)
///     * bp := pop  (set bp to prev-bp)
///     * sp := pop  (deallocate all params)
///
/// There is padding before, in between, and after parameters, locals, and tuple fields so that each
/// location is aligned to a multiple of it's size in bytes.
pub fn calculate_offsets(
    symbol: *Symbol, //< Represents the symbol of a function.
) i64 //< Number of bytes used for locals by the function.
{
    symbol.cfg.?.return_symbol.offset = null; // return value is set using an out-parameter

    // Calculate parameters offsets, descending from retval address offset
    var phony_sp: i64 = 0;
    if (symbol.decl.?.* == .fn_decl or symbol.decl.?.* == .method_decl) {
        const param_symbols = if (symbol.decl.?.* == .fn_decl)
            symbol.decl.?.fn_decl.param_symbols.items
        else
            symbol.decl.?.method_decl.param_symbols.items;
        // Go through params, as if we were pushing them
        var i: i64 = @as(i64, @intCast(param_symbols.len)) - 1;
        while (i >= 0) : (i -= 1) {
            var param: *Symbol = param_symbols[@as(usize, @intCast(i))];
            const size = param.expanded_type.?.sizeof();
            const alignof = param.expanded_type.?.alignof();
            phony_sp = alignment_.next_alignment(phony_sp, alignof);
            param.offset = phony_sp;
            phony_sp += size;
        }

        // Push a "header" word of alignment 8. Pretend this has the offset of the header. Adjust the offsets
        // set before accordingly
        const header = alignment_.next_alignment(phony_sp, 8);
        // Have to do this stupid round-a-bout way because we don't know how much padding to include after the
        // parameters until we get the offsets of each parameter.
        for (param_symbols) |param| {
            param.offset.? -= header - CFG.retval_offset;
        }
    }

    // Calculate locals offsets, ascending from local starting offset
    var local_offsets: i64 = CFG.locals_starting_offset;
    for (symbol.cfg.?.symbvers.items) |symbver| {
        if (symbver.symbol.offset == null and !std.mem.eql(u8, symbver.symbol.name, "$retval")) {
            local_offsets = alignment_.next_alignment(local_offsets, symbver.symbol.expanded_type.?.alignof());
            symbver.symbol.offset = local_offsets;
            local_offsets += @as(i64, @intCast(symbver.symbol.expanded_type.?.sizeof()));
        }
    }
    local_offsets = alignment_.next_alignment(local_offsets, 8);

    // The total number of bytes used for locals
    return local_offsets - CFG.locals_starting_offset;
}
