const std = @import("std");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const symbol_ = @import("symbol.zig");

const stack_limit = 2048;

pub const Context = struct {
    stack: [stack_limit]ir_.IRData,
    stack_pointer: i128,
    base_pointer: i128,

    instructions: *std.ArrayList(*ir_.IR),
    instruction_pointer: i128,

    cfg: *ir_.CFG,

    pub fn init(cfg: *ir_.CFG, instructions: *std.ArrayList(*ir_.IR)) !Context {
        var retval = Context{
            .stack = [_]ir_.IRData{.none} ** stack_limit,
            .stack_pointer = 5 + cfg.slots.?,
            .base_pointer = 4,
            .instructions = instructions,
            .instruction_pointer = 0,
            .cfg = cfg,
        };

        retval.stack[1] = ir_.IRData{ .int = 0 }; // Set the return value address to 0
        retval.stack[2] = ir_.IRData{ .int = 0 }; // Set the prev-bp to 0
        retval.stack[3] = ir_.IRData{ .int = 0 }; // Set the prev-sp to 0
        retval.stack[4] = ir_.IRData{ .int = -2 }; // Set the return address to -2 (sentinel to halt)

        return retval;
    }

    // Stores a value into a slot addressed with an absolute address
    fn store(self: *Context, address: i128, val: ir_.IRData) void {
        // std.debug.print("{s} := {}\n", .{ dest.symbol.name, val });
        self.stack[@as(usize, @intCast(address))] = val;
    }

    // Loads a value from a slot addressed with an absolute address
    fn load(self: *Context, address: i128) ir_.IRData {
        return self.stack[@as(usize, @intCast(address))];
    }

    // Stores a value into a slot addressed with an address relative to the base-pointer
    fn store_local(self: *Context, dest: *symbol_.Symbol, val: ir_.IRData) void {
        if (std.mem.eql(u8, "$retval", dest.name)) {
            // Intercept stores to the return symbol of the form:
            //     retval := val
            // and replace with:
            //     retval^ := val
            self.store(self.load_local(dest).int, val);
        } else {
            self.store(self.base_pointer + dest.offset.?, val);
        }
    }

    // Loads a value from a slot addressed with an address relative to the base-pointer
    fn load_local(self: *Context, ref: *symbol_.Symbol) ir_.IRData {
        // std.debug.print("load local: bp+({})\n", .{ref.offset.?});
        // std.debug.print("load local: {}\n", .{self.load(self.base_pointer + ref.offset.?)});
        return self.load(self.base_pointer + ref.offset.?);
    }

    fn push(self: *Context, val: ir_.IRData) void {
        self.stack[@as(usize, @intCast(self.stack_pointer))] = val;
        self.stack_pointer += 1;
    }

    fn pop(self: *Context) ir_.IRData {
        self.stack_pointer -= 1;
        return self.stack[@as(usize, @intCast(self.stack_pointer))];
    }

    fn ret(self: *Context) void {
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
        var curr_block: *ir_.BasicBlock = self.cfg.block_graph_head.?;
        _ = curr_block;

        // Halt whenever IP is negative
        while (self.instruction_pointer >= 0) : (self.instruction_pointer += 1) {
            var ir: *ir_.IR = self.instructions.items[@as(usize, @intCast(self.instruction_pointer))];
            // self.print_stack();
            // std.debug.print("{}", .{ir});
            switch (ir.kind) {
                // Invalid interpreter operations
                .loadExtern,
                .sizeOf,
                => unreachable,

                // Literals
                .loadInt,
                .loadFloat,
                .loadStruct,
                .loadUnion,
                .loadString,
                .loadSymbol,
                => self.store_local(ir.dest.?.symbol, ir.data),

                // Monadic operations
                .copy => self.store_local(ir.dest.?.symbol, self.load_local(ir.src1.?.symbol)),
                .not => {
                    var data = self.load_local(ir.src1.?.symbol);
                    data.int = if (data.int != 0) 0 else 1;
                    self.store_local(ir.dest.?.symbol, data);
                },
                .negate_int => {
                    var data = self.load_local(ir.src1.?.symbol);
                    data.int = -data.int;
                    self.store_local(ir.dest.?.symbol, data);
                },
                .negate_float => {
                    var data = self.load_local(ir.src1.?.symbol);
                    data.float = -data.float;
                    self.store_local(ir.dest.?.symbol, data);
                },
                .addrOf => {
                    var data = ir_.IRData{ .symbver = ir.src1.? };
                    self.store_local(ir.dest.?.symbol, data);
                },
                .dereference => {
                    self.store_local(ir.dest.?.symbol, self.load(self.load_local(ir.src1.?.symbol).int));
                },
                .derefCopy => {
                    self.store(self.load_local(ir.src1.?.symbol).int, self.load_local(ir.src2.?.symbol));
                },

                // Diadic instructions
                .equal => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.equals(src2_data)) 1 else 0 });
                },
                .not_equal => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (!src1_data.equals(src2_data)) 1 else 0 });
                },
                .greater_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.int > src2_data.int) 1 else 0 });
                },
                .greater_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.float > src2_data.float) 1 else 0 });
                },
                .lesser_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.int < src2_data.int) 1 else 0 });
                },
                .lesser_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.float < src2_data.float) 1 else 0 });
                },
                .greater_equal_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.int >= src2_data.int) 1 else 0 });
                },
                .greater_equal_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.float >= src2_data.float) 1 else 0 });
                },
                .lesser_equal_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.int <= src2_data.int) 1 else 0 });
                },
                .lesser_equal_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = if (src1_data.float <= src2_data.float) 1 else 0 });
                },
                .add_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = src1_data.int + src2_data.int });
                },
                .add_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .float = src1_data.float + src2_data.float });
                },
                .sub_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = src1_data.int - src2_data.int });
                },
                .sub_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .float = src1_data.float - src2_data.float });
                },
                .mult_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = src1_data.int * src2_data.int });
                },
                .mult_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .float = src1_data.float * src2_data.float });
                },
                .div_int => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = @divTrunc(src1_data.int, src2_data.int) });
                },
                .div_float => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .float = src1_data.float / src2_data.float });
                },
                .mod => {
                    var src1_data = self.load_local(ir.src1.?.symbol);
                    var src2_data = self.load_local(ir.src2.?.symbol);
                    self.store_local(ir.dest.?.symbol, ir_.IRData{ .int = @rem(src1_data.int, src2_data.int) });
                },
                .index, // dest = src1[src2]
                .indexCopy, // src1[src2] = data.symbver
                .select, // dest = src1._${data.int}
                .selectCopy,
                .get_tag, // dest = src1.tag
                .cast,
                => {
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
                        while (i > 0) : (i -= 1) {
                            self.push(self.load_local(ir.data.symbverList.items[i].symbol));
                        }
                        self.push(self.load_local(ir.data.symbverList.items[i].symbol));
                    }

                    //  push dest address
                    self.push(ir_.IRData{ .int = self.base_pointer + ir.dest.?.symbol.offset.? });
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

                // Non-Code Generating
                .discard, // Marks that a symbol isn't used, but that's OK
                => {
                    // no-op
                },

                // Errors
                .pushStackTrace, // Pushes a static span/code to the lines array if debug mode is on
                => {
                    // no-op
                },
                .popStackTrace => // Pops a message off the stack after a function is successfully called
                {
                    // no-op
                },
                .panic, // if debug mode is on, panics with a message, unrolls lines stack, exits
                => {
                    std.debug.print("interpreter.zig::interpret(): Unimplemented IR for {s}\n", .{@tagName(ir.kind)});
                },
            }
        }

        return self.load(0);
    }
};

const Variable = struct {
    data: ir_.IRData,
};
