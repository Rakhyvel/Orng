const std = @import("std");
const symbol_ = @import("symbol.zig");

// # Orng interpreter calling convention
// (stack grows up btw, lmao)
// ```
//       |         |
// sp -> |         |
//       | ------- | \
//       | local 2 |  |
//       | ------- |  |
//       | local 1 |  |
// bp -> | ret-adr |  | - callee stack frame
//    -8 | prev-bp |  |
//   -16 | prev-sp |  |
//   -24 | &retval |  | \
//       | ------- |  |  |
//       | arg 1   |  |  |
//       | ------- |  |  |
//       | arg 2   | /   | - caller stack frame
//       | ------- |     |
//       | local 2 |     |
// ```
//
// - Entry (caller)
//   * (save sp, will be pushed later)
//   - push args in reverse order
//   - push address to return-value slot
//   - `call` instruction
//     * push pre-arg sp
//     * push bp
//     * push ret-addr
//     * bp := sp
//   - sp += n  (allocate space for locals)
//
// - Exit (callee)
//   - sp := bp   (deallocate locals)
//   - `ret` instruction
//     * ip := pop  (set ip to ret-addr)
//     * bp := pop  (set bp to prev-bp)
//     * sp := pop  (deallocate all params)

// bp offset of a frame's retval address
pub const retval_offset: i64 = -3 * @sizeOf(i64);
pub const locals_starting_offset = 8;

/// Calculate offsets for each local and parameter in a function.
pub fn calculate_offsets(
    symbol: *symbol_.Symbol, //< Represents the symbol of a function.
) i64 //< Number of bytes used for locals by the function.
{
    symbol.cfg.?.return_symbol.offset = null; // return value is set using an out-parameter

    // Calculate parameters offsets, descending from retval address offset
    var param_offsets: i64 = retval_offset;
    if (symbol.decl.?.* == .fnDecl) {
        for (symbol.decl.?.fnDecl.param_symbols.items) |param| {
            param_offsets -= @as(i64, @intCast(param.expanded_type.?.sizeof()));
            param.offset = param_offsets;
        }
    }

    // Calculate locals offsets, ascending from local starting offset
    var local_offsets: i64 = locals_starting_offset;
    for (symbol.cfg.?.symbvers.items) |symbver| {
        if (symbver.symbol.offset == null) {
            symbver.symbol.offset = local_offsets;
            local_offsets += @as(i64, @intCast(symbver.symbol.expanded_type.?.sizeof()));
        }
    }

    // The total number of bytes used for locals
    return local_offsets - locals_starting_offset - 8;
}

pub fn next_alignment(address: i64, align_to: i64) i64 {
    const div = @divTrunc(address - 1, align_to);
    return div * align_to + align_to;
}
