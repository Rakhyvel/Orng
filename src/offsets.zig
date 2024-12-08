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
//       | - pad - |  |  |
//       | ------- |  |  |
//   -28 | arg 1   |  |  |
//       | arg 2   |  |  |
//   -30 | arg 2   | /   | - caller stack frame
//       | - pad - |     |
//   -32 | arg 3   |     |
//       | - pad - |     |
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
//
// There is padding before, in between, and after parameters, locals, and tuple fields so that each
// location is aligned to a multiple of it's size in bytes.

pub const Instruction_Idx: type = u32;

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
    var phony_sp: i64 = 0;
    if (symbol.decl.?.* == .fn_decl or symbol.decl.?.* == .method_decl) {
        const param_symbols = if (symbol.decl.?.* == .fn_decl)
            symbol.decl.?.fn_decl.param_symbols.items
        else
            symbol.decl.?.method_decl.param_symbols.items;
        // Go through params, as if we were pushing them
        var i: i64 = @as(i64, @intCast(param_symbols.len)) - 1;
        while (i >= 0) : (i -= 1) {
            var param: *symbol_.Symbol = param_symbols[@as(usize, @intCast(i))];
            const size = param.expanded_type.?.sizeof();
            const alignof = param.expanded_type.?.alignof();
            phony_sp = next_alignment(phony_sp, alignof);
            param.offset = phony_sp;
            phony_sp += size;
        }

        // Push a "header" word of alignment 8. Pretend this has the offset of the header. Adjust the offsets
        // set before accordingly
        const header = next_alignment(phony_sp, 8);
        // Have to do this stupid round-a-bout way because we don't know how much padding to include after the
        // parameters until we get the offsets of each parameter.
        for (param_symbols) |param| {
            param.offset.? -= header - retval_offset;
        }
    }

    // Calculate locals offsets, ascending from local starting offset
    var local_offsets: i64 = locals_starting_offset;
    for (symbol.cfg.?.symbvers.items) |symbver| {
        if (symbver.symbol.offset == null and !std.mem.eql(u8, symbver.symbol.name, "$retval")) {
            local_offsets = next_alignment(local_offsets, symbver.symbol.expanded_type.?.alignof());
            symbver.symbol.offset = local_offsets;
            local_offsets += @as(i64, @intCast(symbver.symbol.expanded_type.?.sizeof()));
        }
    }
    local_offsets = next_alignment(local_offsets, 8);

    // The total number of bytes used for locals
    return local_offsets - locals_starting_offset;
}

pub fn next_alignment(address: i64, align_to: i64) i64 {
    std.debug.assert(align_to == 1 or align_to == 2 or align_to == 4 or align_to == 8);
    if (address == 0) {
        return address;
    } else if (address > 0) {
        const div = @divTrunc(address - 1, align_to);
        return div * align_to + align_to;
    } else {
        // needed because offsets can sometimes be negative!
        const div = @divTrunc(address + 1, align_to);
        return div * align_to - align_to;
    }
}
