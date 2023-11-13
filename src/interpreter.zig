const std = @import("std");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const symbol_ = @import("symbol.zig");
const offsets_ = @import("offsets.zig");
const span_ = @import("span.zig");

const stack_limit = 2048;

pub const Context = struct {
    stack: [stack_limit]ir_.IRData,
    stack_pointer: i128,
    base_pointer: i128,

    instructions: *std.ArrayList(*ir_.IR),
    instruction_pointer: i128,

    pub fn init(cfg: *ir_.CFG, instructions: *std.ArrayList(*ir_.IR), ret_slots: i64) !Context {
        var retval = Context{
            .stack = [_]ir_.IRData{.none} ** stack_limit,
            .stack_pointer = 5 + cfg.slots.?,
            .base_pointer = 4,

            .instructions = instructions,
            .instruction_pointer = 0,
        };

        // First `ret_slots` slots are reserved for the return value
        // Initial stack frame is setup immediately after
        retval.stack[@as(usize, @intCast(ret_slots + 0))] = ir_.IRData{ .int = 0 }; // Set the return value address to 0
        retval.stack[@as(usize, @intCast(ret_slots + 1))] = ir_.IRData{ .int = 0 }; // Set the prev-bp to 0
        retval.stack[@as(usize, @intCast(ret_slots + 2))] = ir_.IRData{ .int = 0 }; // Set the prev-sp to 0
        retval.stack[@as(usize, @intCast(ret_slots + 3))] = ir_.IRData{ .int = -2 }; // Set the return address to -2 (negative is sentinel to halt)

        return retval;
    }

    fn get_lval(self: *Context, lval: *ir_.L_Value) i128 {
        switch (lval.*) {
            .symbver => {
                if (std.mem.eql(u8, "$retval", lval.symbver.symbol.name)) {
                    // Intercept stores to the return symbol of the form:
                    //     retval := val
                    // and replace with:
                    //     retval^ := val
                    return self.load(self.base_pointer + offsets_.retval_offset).int;
                } else {
                    return self.base_pointer + lval.symbver.symbol.offset.?;
                }
            },
            .dereference => {
                return self.load_local(lval.dereference.symbol).int;
            },
            .index => {
                var base = self.get_lval(lval.index.lhs);
                var index = self.load_local(lval.index.field.symbol).int;
                return base + index * lval.index.slots;
            },
            .select => {
                var base = self.get_lval(lval.select.lhs);
                return base + lval.select.offset;
            },
        }
    }

    // Stores a value into a slot addressed with an absolute address
    inline fn store(self: *Context, address: i128, val: ir_.IRData) void {
        std.debug.print("{}^ := {}\n", .{ address, val });
        self.stack[@as(usize, @intCast(address))] = val;
    }

    inline fn store_lval(self: *Context, dest: *ir_.L_Value, val: ir_.IRData) void {
        var addr = self.get_lval(dest);
        self.store(addr, val);
    }

    // Loads a value from a slot addressed with an absolute address
    inline fn load(self: *Context, address: i128) ir_.IRData {
        return self.stack[@as(usize, @intCast(address))];
    }

    // Loads a value from a slot addressed with an address relative to the base-pointer
    inline fn load_local(self: *Context, ref: *symbol_.Symbol) ir_.IRData {
        // std.debug.print("load local: bp+({})\n", .{ref.offset.?});
        // std.debug.print("load local: {}\n", .{self.load(self.base_pointer + ref.offset.?)});
        return self.load(self.base_pointer + ref.offset.?);
    }

    fn move(self: *Context, dest: i128, src: i128, slots: i128) void {
        std.debug.assert(slots >= 0); // slots=0 for units!
        for (0..@as(usize, @intCast(slots))) |i| {
            self.store(dest + i, self.load(src + i));
        }
    }

    fn move_symbver_list(self: *Context, dest_symbol: *symbol_.Symbol, list: *std.ArrayList(*ir_.SymbolVersion)) void {
        var dest: i128 = undefined;
        if (std.mem.eql(u8, "$retval", dest_symbol.name)) {
            // Dest-addr for retval is whatever is stored in the retval slot
            dest = self.load(self.base_pointer + offsets_.retval_offset).int;
        } else {
            dest = self.base_pointer + dest_symbol.offset.?;
        }

        for (list.items) |symbver| {
            var slots = symbver.symbol.expanded_type.?.get_slots();
            self.move(dest, self.addrof_local(symbver.symbol), slots);
            dest += slots;
        }
    }

    inline fn addrof_local(self: *Context, symbol: *symbol_.Symbol) i128 {
        return self.base_pointer + symbol.offset.?;
    }

    inline fn push(self: *Context, val: ir_.IRData) void {
        self.stack[@as(usize, @intCast(self.stack_pointer))] = val;
        self.stack_pointer += 1;
    }

    fn push_move(self: *Context, addr: i128, slots: i128) void {
        for (0..@as(usize, @intCast(slots))) |i| {
            self.stack[@as(usize, @intCast(self.stack_pointer))] = self.stack[@as(usize, @intCast(addr + i))];
            self.stack_pointer += 1;
        }
    }

    inline fn pop(self: *Context) ir_.IRData {
        self.stack_pointer -= 1;
        return self.stack[@as(usize, @intCast(self.stack_pointer))];
    }

    inline fn ret(self: *Context) void {
        // deallocate locals
        self.stack_pointer = self.base_pointer + 1;
        // jump to return-address
        self.instruction_pointer = self.pop().int;
        // restore previous base-pointer
        self.base_pointer = self.pop().int;
        // restore previous stack-pointer, deallocate params, deallocate return-pointer
        self.stack_pointer = self.pop().int;
        // self.print_registers();
    }

    fn print_registers(self: *Context) void {
        std.debug.print("bp:{} sp:{} ip:{}\n", .{ self.base_pointer, self.stack_pointer, self.instruction_pointer });
    }

    fn print_stack(self: *Context) void {
        std.debug.print("[ ", .{});
        for (0..@as(usize, @intCast(self.stack_pointer))) |i| {
            if (i == self.stack_pointer) {
                std.debug.print("sp:", .{});
            } else if (i == self.base_pointer) {
                std.debug.print("bp:", .{});
            }
            std.debug.print("{} ", .{self.stack[i]});
        }
        std.debug.print("]\n", .{});
    }

    pub fn interpret(self: *Context) !ir_.IRData {
        var buffer: [1024]u8 = undefined;
        var fba = std.heap.FixedBufferAllocator.init(&buffer);
        var debug_call_stack: std.ArrayList(span_.Span) = std.ArrayList(span_.Span).init(fba.allocator());

        // Halt whenever instruction pointer is negative
        while (self.instruction_pointer >= 0) : (self.instruction_pointer += 1) {
            var ir: *ir_.IR = self.instructions.items[@as(usize, @intCast(self.instruction_pointer))];
            // self.print_stack();
            // std.debug.print("{}", .{ir});

            if (ir.meta == .bounds_check) {
                // IR has a bounds to be checked
                var length = self.load_local(ir.meta.bounds_check.length.symbol);
                var src2_data = self.load_local(ir.src2.?.symbol);
                if (0 > src2_data.int or src2_data.int >= length.int) {
                    // Bounds check fails, append line and panic
                    try debug_call_stack.append(ir.span);
                    var i = debug_call_stack.items.len - 1;
                    while (true) {
                        var span = debug_call_stack.items[i];
                        try span.print_debug_line(std.io.getStdOut().writer(), span_.interpreter_format);

                        if (i == 0) {
                            break;
                        } else {
                            i -= 1;
                        }
                    }
                    return ir_.IRData.none;
                }
            } else if (ir.meta == .active_field_check) {
                // IR has an active field to check
                var tag = self.load_local(ir.meta.active_field_check.tag.symbol);
                if (tag.int != ir.meta.active_field_check.selection) {
                    // Active field check fails, append line and panic
                    try debug_call_stack.append(ir.span);
                    var i = debug_call_stack.items.len - 1;
                    while (true) {
                        var span = debug_call_stack.items[i];
                        try span.print_debug_line(std.io.getStdOut().writer(), span_.interpreter_format);

                        if (i == 0) {
                            break;
                        } else {
                            i -= 1;
                        }
                    }
                    return ir_.IRData.none;
                }
            }

            switch (ir.kind) {
                // Invalid interpreter operations
                .loadExtern,
                .sizeOf,
                => unreachable,

                // 1-slot literals
                .loadInt,
                .loadFloat,
                .loadString,
                .loadSymbol,
                => self.store_lval(ir.dest.?, ir.data),

                // Tuples
                .loadStruct => self.move_symbver_list(ir.dest.?.symbver.symbol, &ir.data.symbverList),

                .loadUnion => {
                    if (ir.src1 != null) {
                        // Store data
                        self.move(self.get_lval(ir.dest.?), self.addrof_local(ir.src1.?.symbol), ir.dest.?.get_slots());
                    }
                    // Store tag in last slot
                    self.store(self.get_lval(ir.dest.?) + ir.dest.?.get_slots() - 1, ir.data);
                },

                // Monadic operations
                .copy => {
                    self.move(self.get_lval(ir.dest.?), self.addrof_local(ir.src1.?.symbol), ir.dest.?.get_slots()); // TODO: Integration test that all ir.dest.?.get_slots() work with data of more than one slot
                },
                .not => {
                    var data = self.load_local(ir.src1.?.symbol);
                    data.int = if (data.int != 0) 0 else 1;
                    self.store_lval(ir.dest.?, data);
                },
                .negate_int => {
                    var data = self.load_local(ir.src1.?.symbol);
                    data.int = -data.int;
                    self.store_lval(ir.dest.?, data);
                },
                .negate_float => {
                    var data = self.load_local(ir.src1.?.symbol);
                    data.float = -data.float;
                    self.store_lval(ir.dest.?, data);
                },
                .addrOf => {
                    var data = ir_.IRData{ .int = self.get_lval(ir.data.lval) };
                    self.store_lval(ir.dest.?, data);
                },
                .dereference => {
                    self.move(self.get_lval(ir.dest.?), self.load_local(ir.src1.?.symbol).int, ir.dest.?.get_slots());
                },

                // Diadic instructions
                .equal => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.equals(src2_data)) 1 else 0 });
                },
                .not_equal => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (!src1_data.equals(src2_data)) 1 else 0 });
                },
                .greater_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.int > src2_data.int) 1 else 0 });
                },
                .greater_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.float > src2_data.float) 1 else 0 });
                },
                .lesser_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.int < src2_data.int) 1 else 0 });
                },
                .lesser_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.float < src2_data.float) 1 else 0 });
                },
                .greater_equal_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.int >= src2_data.int) 1 else 0 });
                },
                .greater_equal_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.float >= src2_data.float) 1 else 0 });
                },
                .lesser_equal_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.int <= src2_data.int) 1 else 0 });
                },
                .lesser_equal_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = if (src1_data.float <= src2_data.float) 1 else 0 });
                },
                .add_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = src1_data.int + src2_data.int });
                },
                .add_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .float = src1_data.float + src2_data.float });
                },
                .sub_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = src1_data.int - src2_data.int });
                },
                .sub_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .float = src1_data.float - src2_data.float });
                },
                .mult_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = src1_data.int * src2_data.int });
                },
                .mult_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .float = src1_data.float * src2_data.float });
                },
                .div_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = @divTrunc(src1_data.int, src2_data.int) });
                },
                .div_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .float = src1_data.float / src2_data.float });
                },
                .mod => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_lval(ir.dest.?, ir_.IRData{ .int = @rem(src1_data.int, src2_data.int) });
                },
                .index => { // dest = src1[src2]
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    var offset = src2_data.int * ir.dest.?.get_slots();
                    self.move(self.get_lval(ir.dest.?), self.addrof_local(ir.src1.?.symbol) + offset, ir.dest.?.get_slots());
                },
                .select => { // dest = src1._${data.int}
                    self.move(self.get_lval(ir.dest.?), self.addrof_local(ir.src1.?.symbol) + ir.data.select.offset, ir.dest.?.get_slots());
                },
                .get_tag => { // gets the tag of a union value. The tag will be located in the last slot
                    var last_slot_offset = ir.src1.?.symbol.expanded_type.?.get_slots() - 1;
                    self.move(self.get_lval(ir.dest.?), self.addrof_local(ir.src1.?.symbol) + last_slot_offset, 1);
                },
                .cast => {
                    std.debug.print("interpreter.zig::interpret(): Unimplemented IR for {s}\n", .{@tagName(ir.kind)});
                },

                // Control-flow
                .label => {
                    // no-op
                },
                .jump => {
                    if (ir.data.jump_bb.next) |next| {
                        self.instruction_pointer = next.offset.?;
                    } else {
                        self.ret();
                        continue;
                    }
                },
                .branchIfFalse => {
                    if (self.load_local(ir.src1.?.symbol).int != 0) {
                        if (ir.data.branch_bb.next) |next| {
                            self.instruction_pointer = next.offset.?;
                        } else {
                            self.ret();
                            continue;
                        }
                    } else {
                        if (ir.data.branch_bb.branch) |branch| {
                            self.instruction_pointer = branch.offset.?;
                        } else {
                            self.ret();
                            continue;
                        }
                    }
                },
                .call => { // dest = src1(symbver_list...)
                    var symbol = if (ir.src1.?.def == null or ir.src1.?.def.?.data != .symbol)
                        self.load_local(ir.src1.?.symbol).symbol
                    else
                        ir.src1.?.def.?.data.symbol;

                    // Save old stack pointer
                    var old_sp = self.stack_pointer;
                    //  push args in reverse order
                    if (ir.data.symbverList.items.len > 0) {
                        var i = ir.data.symbverList.items.len - 1;
                        var slots: i128 = undefined;
                        while (i > 0) : (i -= 1) {
                            slots = ir.data.symbverList.items[i].symbol.expanded_type.?.get_slots();
                            self.push_move(self.addrof_local(ir.data.symbverList.items[i].symbol), slots);
                        }
                        slots = ir.data.symbverList.items[i].symbol.expanded_type.?.get_slots();
                        self.push_move(self.addrof_local(ir.data.symbverList.items[i].symbol), slots);
                    }

                    //  push dest address
                    self.push(ir_.IRData{ .int = self.addrof_local(ir.dest.?.extract_symbver().symbol) });
                    //  push old sp
                    self.push(ir_.IRData{ .int = old_sp });
                    //  push bp
                    self.push(ir_.IRData{ .int = self.base_pointer });
                    //  push ret-addr
                    self.push(ir_.IRData{ .int = self.instruction_pointer });
                    //  bp := sp
                    self.base_pointer = self.stack_pointer - 1;

                    // allocate space for locals
                    self.stack_pointer += symbol.cfg.?.slots.?;

                    // jump to symbol addr
                    self.instruction_pointer = symbol.cfg.?.offset.?;
                },

                .discard => {
                    // no-op
                },

                // Errors
                .pushStackTrace => { // Pushes a static span/code to the lines array if debug mode is on
                    try debug_call_stack.append(ir.span);
                },
                .popStackTrace => { // Pops a message off the stack after a function is successfully called
                    _ = debug_call_stack.pop();
                },
                .panic => { // if debug mode is on, panics with a message, unrolls lines stack, exits
                    var i = debug_call_stack.items.len - 1;
                    while (true) {
                        var span = debug_call_stack.items[i];
                        try span.print_debug_line(std.io.getStdOut().writer(), span_.interpreter_format);

                        if (i == 0) {
                            break;
                        } else {
                            i -= 1;
                        }
                    }
                    return ir_.IRData.none;
                },
            }
        }

        return self.load(0);
    }
};

const Variable = struct {
    data: ir_.IRData,
};
