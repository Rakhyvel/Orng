const std = @import("std");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const symbol_ = @import("symbol.zig");

// # Orng interpreter calling convention
// (stack grows up btw, lmao)
// ```
//       |         |
// sp -> |         |
//    +4 | ------- | \
//    +3 | local 2 |  |
//    +2 | ------- |  |
//    +1 | local 1 |  |
// bp -> | ret-adr |  | - callee stack frame
//    -1 | prev-bp |  |
//    -2 | prev-sp |  |
//    -3 | &retval |  | \
//    -4 | ------- |  |  |
//    -5 | arg 1   |  |  |
//    -6 | ------- |  |  |
//    -7 | arg 2   | /   | - caller stack frame
//    -8 | ------- |     |
//    -9 | local 2 |     |
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

pub const retval_offset = -3;
pub const locals_starting_offset = 1;

/// Calculate offsets for each local and parameter in a function.
pub fn calculate_offsets(
    symbol: *symbol_.Symbol, //< Represents the symbol of a function.
) i64 //< Number of slots used for locals by the function.
{
    symbol.cfg.?.return_symbol.offset = null; // return value is set using an out-parameter

    // Calculate parameters offsets, descending from retval address offset
    var param_offsets: i64 = retval_offset;
    if (symbol.decl.?.* == .fnDecl) {
        for (symbol.decl.?.fnDecl.param_symbols.items) |param| {
            param_offsets -= param.expanded_type.?.get_slots();
            param.offset = param_offsets;
        }
    }

    // Calculate locals offsets, ascending from local starting offset
    var local_offsets: i64 = locals_starting_offset;
    for (symbol.cfg.?.symbvers.items) |symbver| {
        // std.debug.print("{s}\n", .{symbver.symbol.name});
        if (symbver.symbol.offset == null) {
            symbver.symbol.offset = local_offsets;
            local_offsets += symbver.symbol.expanded_type.?.get_slots();
        }
    }

    // The total number of slots used for locals
    return local_offsets - locals_starting_offset - 1;
}
