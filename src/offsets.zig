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

// Calculate offsets and number of slots for each local in a function
pub fn calculate_slots_offsets(symbol: *symbol_.Symbol) void {
    calculate_slots(symbol);
    calculate_offsets(symbol);
}

fn calculate_slots(symbol: *symbol_.Symbol) void {
    symbol.cfg.?.return_symbol.slots = 1;

    for (symbol.decl.?.fnDecl.param_symbols.items) |param| {
        param.slots = 1;
    }

    var total_slots: i16 = 0;
    for (symbol.cfg.?.symbvers.items) |symbver| {
        if (symbver.symbol.slots == null) {
            symbver.symbol.slots = 1;
            total_slots += symbver.symbol.slots.?;
        }
    }
    symbol.cfg.?.slots = total_slots;
}

fn calculate_offsets(symbol: *symbol_.Symbol) void {
    const param_start = -3;
    const local_start = 1;

    symbol.cfg.?.return_symbol.offset = param_start;

    {
        var param_offsets = symbol.cfg.?.return_symbol.offset.?;
        for (symbol.decl.?.fnDecl.param_symbols.items) |param| {
            param_offsets -= param.slots.?;
            param.offset = param_offsets;
        }
    }

    {
        var local_offsets: i16 = local_start;
        for (symbol.cfg.?.symbvers.items) |symbver| {
            if (symbver.symbol.offset == null) {
                symbver.symbol.offset = local_offsets;
                local_offsets += symbver.symbol.slots.?;
            }
        }
    }
}
