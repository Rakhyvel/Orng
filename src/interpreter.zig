const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const primitives_ = @import("primitives.zig");
const offsets_ = @import("offsets.zig");
const token_ = @import("token.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");

const stack_limit = 0x4000; // 16 KiB
const uninit_byte: u8 = 0x58; // It is, in general, not a good idea to memset to 0x00!
const halt_trap: i64 = 0xFFFF_FFFF_FFF0;
const timeout_ms = 1000;

// TODO: Could you make a debugger, that lets you step to the next instruction etc?
pub const Context = struct {
    stack: [stack_limit]u8,
    stack_pointer: i64,
    base_pointer: i64,

    instructions: *std.ArrayList(*ir_.IR),
    instruction_pointer: i64,

    debug_call_mem: [stack_limit]u8,
    debug_call_stack: std.ArrayList(span_.Span),

    start_time: i64,

    /// Initializes a new interpreter context.
    pub fn init(
        cfg: *cfg_.CFG,
        instructions: *std.ArrayList(*ir_.IR), // Flat list of instructions to interpret
        ret_type: *ast_.AST, // TODO: Just accept ret_type size
        entry_point: i64, // Address of the intruction to start execution at
    ) Context {
        std.debug.assert(entry_point >= 0);
        const frame_address = offsets_.next_alignment(ret_type.sizeof(), 8);
        var retval = Context{
            .stack = [_]u8{uninit_byte} ** stack_limit,
            .stack_pointer = (5 * @sizeOf(i64)) + frame_address + cfg.locals_size.?,
            .base_pointer = (4 * @sizeOf(i64)) + frame_address,

            .instructions = instructions,
            .instruction_pointer = entry_point,
            .debug_call_mem = [_]u8{uninit_byte} ** stack_limit,
            .debug_call_stack = undefined,

            .start_time = std.time.milliTimestamp(),
        };

        var fba = std.heap.FixedBufferAllocator.init(&retval.debug_call_mem);
        retval.debug_call_stack = std.ArrayList(span_.Span).init(fba.allocator());

        retval.debug_call_stack.append(cfg.symbol.span) catch unreachable;

        // First `ret_type.sizeof()` bytes are reserved for the return value
        // Initial stack frame is setup immediately after
        retval.store_int(frame_address + 0 * @sizeOf(i64), @sizeOf(i64), 0); // Set the return value address to 0
        retval.store_int(frame_address + 1 * @sizeOf(i64), @sizeOf(i64), 0); // Set the prev-bp to 0
        retval.store_int(frame_address + 2 * @sizeOf(i64), @sizeOf(i64), 0); // Set the prev-sp to 0
        retval.store_int(frame_address + 3 * @sizeOf(i64), @sizeOf(i64), halt_trap); // Set the return address to halt trap value

        return retval;
    }

    /// Gets the effective address of an lvalue in the interpreter's memory.
    fn effective_address(self: *Context, lval: *lval_.L_Value) error{InterpreterPanic}!i64 {
        switch (lval.*) {
            .symbver => {
                if (std.mem.eql(u8, "$retval", lval.symbver.symbol.name)) {
                    // Intercept stores to the return symbol of the form:
                    //     retval := val
                    // and replace with:
                    //     retval^ := val
                    return self.load(i64, self.base_pointer + offsets_.retval_offset);
                } else if (lval.symbver.symbol.offset == null) {
                    // If this is triggered for a temporary or a constant, you didn't offset it correctly
                    if (lval.symbver.def != null) {
                        // symbver def is real (Good fortune!!)
                        return self.panic(lval.symbver.def.?.span, "interpreter error: variable `{s}` isn't comptime known\n", .{lval.symbver.symbol.name});
                    } else {
                        // symbver def is null, use symbol span instead (bad fortune!! curse on family)
                        return self.panic(lval.symbver.symbol.span, "interpreter error: variable `{s}` isn't comptime known\n", .{lval.symbver.symbol.name});
                    }
                } else {
                    // std.debug.print("{s}\n", .{lval.symbver.symbol.name});
                    return self.base_pointer + lval.symbver.symbol.offset.?;
                }
            },
            .dereference => return self.load(i64, try self.effective_address(lval.dereference.expr)),
            .index => {
                const base = try self.effective_address(lval.index.lhs);
                const index = self.load(i64, try self.effective_address(lval.index.rhs));
                return base + index * lval.sizeof();
            },
            .select => {
                const base = try self.effective_address(lval.select.lhs);
                return base + lval.select.offset;
            },
        }
    }

    /// Stores a value of type T at the specified address in the interpreter's memory.
    fn store(self: *Context, comptime T: type, address: i64, val: T) void {
        std.debug.assert(address >= 0);
        // std.debug.print("[0x{X}:{}] = {}\n", .{ address, @alignOf(T), val });
        @as(*T, @alignCast(@ptrCast(&self.stack[@as(usize, @intCast(address))]))).* = val;
    }

    /// Stores an integer value at the specified address in the interpreter's memory.
    fn store_int(self: *Context, address: i64, size: i64, val: i128) void {
        std.debug.assert(address >= 0);
        switch (size) {
            1 => self.store(i8, address, @as(i8, @intCast(val))),
            2 => self.store(i16, address, @as(i16, @intCast(val))),
            4 => self.store(i32, address, @as(i32, @intCast(val))),
            8 => self.store(i64, address, @as(i64, @intCast(val))),
            else => std.debug.panic("interpreter error: cannot store an int of size {}\n", .{size}),
        }
    }

    /// Stores a floating-point value at the specified address in the interpreter's memory.
    fn store_float(self: *Context, address: i64, size: i64, val: f64) void {
        std.debug.assert(address >= 0);
        switch (size) {
            4 => self.store(f32, address, @as(f32, @floatCast(val))),
            8 => self.store(f64, address, val),
            else => unreachable,
        }
    }

    /// Loads a value of type T from the specified address in the interpreter's memory.
    fn load(self: *Context, comptime T: type, address: i64) T {
        std.debug.assert(address >= 0);
        const val = @as(*T, @ptrCast(@alignCast(&self.stack[@as(usize, @intCast(address))]))).*;
        // std.debug.print("[0x{X}:{}] \t// {}\n", .{ address, @alignOf(T), val });
        return val;
    }

    /// Loads an integer value from the specified address in the interpreter's memory.
    fn load_int(self: *Context, address: i64, size: i64) i128 {
        std.debug.assert(address >= 0);
        return switch (size) {
            1 => self.load(i8, address),
            2 => self.load(i16, address),
            4 => self.load(i32, address),
            8 => self.load(i64, address),
            else => unreachable,
        };
    }

    /// Loads a floating-point value from the specified address in the interpreter's memory.
    fn load_float(self: *Context, address: i64, size: i64) f64 {
        std.debug.assert(address >= 0);
        return switch (size) {
            4 => self.load(f32, address),
            8 => self.load(f64, address),
            else => unreachable,
        };
    }

    /// Moves a block of memory from the source address to the destination address in the interpreter's memory.
    fn move(self: *Context, dest: i64, src: i64, len: i64) void {
        std.debug.assert(dest >= 0);
        std.debug.assert(src >= 0);
        if (len == 0) {
            // moving no bytes is a no-op
            return;
        }
        std.debug.assert(dest != src); // dest is not src
        if (dest > src) {
            std.debug.assert(dest >= src + len); // dest is not within src
        } else {
            std.debug.assert(src >= dest + len); // src is not within dest
        }
        @memcpy(
            self.stack[@as(usize, @intCast(dest))..@as(usize, @intCast(dest + len))],
            self.stack[@as(usize, @intCast(src))..@as(usize, @intCast(src + len))],
        );
    }

    /// Copies memory blocks referenced by a list of L_Values to the specified destination address in the
    /// interpreter's memory.
    fn move_lval_list(
        self: *Context,
        dest: i64,
        list: *std.ArrayList(*lval_.L_Value), // TODO: Slice only
    ) !void {
        std.debug.assert(dest >= 0);
        var cursor = dest;
        for (list.items) |lval| {
            cursor = offsets_.next_alignment(cursor, lval.alignof());
            const len = lval.sizeof();
            self.move(cursor, try self.effective_address(lval), len);
            cursor += len;
        }
    }

    /// Pushes an integer value onto the interpreter's stack.
    fn push_int(self: *Context, size: i64, val: i128) void {
        self.store_int(self.stack_pointer, size, val);
        self.stack_pointer += size;
    }

    /// Pushes a memory block of the specified size onto the interpreter's stack.
    fn push_move(self: *Context, block_addr: i64, block_size: i64) void {
        self.move(self.stack_pointer, block_addr, block_size);
        self.stack_pointer += block_size;
    }

    /// Pops and returns an integer value from the interpreter's stack.
    fn pop_int(self: *Context, int_size_bytes: i64) i128 {
        self.stack_pointer -= int_size_bytes;
        return self.load_int(self.stack_pointer, int_size_bytes);
    }

    /// Handles the return operation in the interpreter's calling convention
    fn ret(self: *Context) void {
        // deallocate locals
        self.stack_pointer = self.base_pointer + 8;
        // jump to return-address
        self.instruction_pointer = @as(i64, @intCast(self.pop_int(8)));
        // restore previous base-pointer
        self.base_pointer = @as(i64, @intCast(self.pop_int(8)));
        // restore previous stack-pointer, deallocate params, deallocate return-pointer
        self.stack_pointer = @as(i64, @intCast(self.pop_int(8)));
        // self.print_registers();
    }

    /// Prints the values of the interpreter's registers
    fn print_registers(self: *Context) void {
        std.debug.print("bp:0x{X} sp:0x{X} ip:0x{X}\n", .{ self.base_pointer, self.stack_pointer, self.instruction_pointer });
    }

    /// Prints the contents of the interpreter's stack. Used for debugging.
    fn print_stack(self: *Context) void {
        for (0..@as(usize, @intCast(self.stack_pointer))) |i| {
            if (@rem(i, 8) == 0) {
                std.debug.print("0x{0X:0>2.}: ", .{i});
            }
            std.debug.print("{X:0>2.}", .{self.stack[i]});
            if (@rem(i, 8) == 7) {
                std.debug.print(" ", .{});
            }
            if (@rem(i, 32) == 31) {
                std.debug.print("\n", .{});
            }
        }
    }

    /// Loads integer values from the specified L_Values and returns a structure containing both the loaded
    /// values.
    fn binop_load_int(self: *Context, src1: *lval_.L_Value, src2: *lval_.L_Value) !struct { src1: i128, src2: i128 } {
        return .{
            .src1 = self.load_int(try self.effective_address(src1), src1.sizeof()),
            .src2 = self.load_int(try self.effective_address(src2), src2.sizeof()),
        };
    }

    /// Loads floating-point values from the specified L_Values and returns a structure containing both the
    /// loaded values.
    fn binop_load_float(self: *Context, src1: *lval_.L_Value, src2: *lval_.L_Value) !struct { src1: f64, src2: f64 } {
        return .{
            .src1 = self.load_float(try self.effective_address(src1), src1.sizeof()),
            .src2 = self.load_float(try self.effective_address(src2), src2.sizeof()),
        };
    }

    /// Interprets the interpreter's instructions until the interpreter's instruction pointer is less than
    /// the maximum allowed instructions.
    pub fn interpret(self: *Context) error{InterpreterPanic}!void {
        // Halt whenever instruction pointer is greater than the max allowed instructions
        while (self.instruction_pointer < halt_trap) : (self.instruction_pointer += 1) {
            const ir: *ir_.IR = self.instructions.items[@as(usize, @intCast(self.instruction_pointer))];
            // self.print_registers();
            // self.print_stack();
            // std.debug.print("\n\n\n\n{}=>\n", .{ir});
            const time_now = std.time.milliTimestamp();
            if (time_now - self.start_time > timeout_ms) {
                return self.panic(null, "interpreter error: compile-time interpreter timeout\n", .{});
            }
            try self.execute_instruction(ir);
        }
    }

    /// Executes an instruction within the interpreter context.
    inline fn execute_instruction(self: *Context, ir: *ir_.IR) error{InterpreterPanic}!void { // This doesn't work if it's not inlined, lol!
        switch (ir.kind) {
            // Invalid instructions
            .load_extern,
            .size_of,
            => unreachable,

            // Nops
            .label, .load_unit => {},

            // Load literals
            .load_int => {
                try self.assert_fits(ir.data.int, ir.dest.?.get_expanded_type(), "integer value", ir.span);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), ir.data.int);
            },
            .load_float => self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), ir.data.float),
            .load_string => self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), ir.data.string_id),
            .load_symbol => self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), @intFromPtr(ir.data.symbol)),
            .load_AST => self.store_int(try self.effective_address(ir.dest.?), 8, @intFromPtr(ir.data.ast)),
            .load_struct => try self.move_lval_list(try self.effective_address(ir.dest.?), &ir.data.lval_list),
            .load_union => {
                if (ir.src1 != null) {
                    // Store data into first field
                    self.move(try self.effective_address(ir.dest.?), try self.effective_address(ir.src1.?), ir.src1.?.sizeof());
                }
                // Store tag in last field
                self.store(i64, try self.effective_address(ir.dest.?) + ir.dest.?.sizeof() - 8, @as(i64, @intCast(ir.data.int)));
            },

            .copy => {
                std.debug.assert(ir.dest.?.sizeof() == ir.src1.?.sizeof());
                self.move(try self.effective_address(ir.dest.?), try self.effective_address(ir.src1.?), ir.dest.?.sizeof());
            },
            .not => {
                const data = self.load_int(try self.effective_address(ir.src1.?), ir.src1.?.sizeof());
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data != 0) 0 else 1);
            },
            .negate_int => {
                const data = self.load_int(try self.effective_address(ir.src1.?), ir.src1.?.sizeof());
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), -data);
            },
            .negate_float => {
                const data = self.load_float(try self.effective_address(ir.src1.?), ir.src1.?.sizeof());
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), -data);
            },
            .mut_addr_of, .addr_of => {
                const data = try self.effective_address(ir.src1.?);
                self.store_int(try self.effective_address(ir.dest.?), 8, data);
            },
            .equal => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 == data.src2) 1 else 0);
            },
            .not_equal => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 != data.src2) 1 else 0);
            },
            .greater_int => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 > data.src2) 1 else 0);
            },
            .greater_float => {
                const data = try self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 > data.src2) 1 else 0);
            },
            .lesser_int => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 < data.src2) 1 else 0);
            },
            .lesser_float => {
                const data = try self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 < data.src2) 1 else 0);
            },
            .greater_equal_int => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 >= data.src2) 1 else 0);
            },
            .greater_equal_float => {
                const data = try self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 >= data.src2) 1 else 0);
            },
            .lesser_equal_int => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 <= data.src2) 1 else 0);
            },
            .lesser_equal_float => {
                const data = try self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 <= data.src2) 1 else 0);
            },
            .add_int => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                const val = data.src1 + data.src2;
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "addition result", ir.span);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .add_float => {
                const data = try self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), data.src1 + data.src2);
            },
            .sub_int => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                const val = data.src1 - data.src2;
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "subtraction result", ir.span);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .sub_float => {
                const data = try self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), data.src1 - data.src2);
            },
            .mult_int => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                const val = data.src1 * data.src2;
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "multiplication result", ir.span);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .mult_float => {
                const data = try self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), data.src1 * data.src2);
            },
            .div_int => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                if (data.src2 == 0) {
                    return self.panic(ir.span, "interpreter error: division by zero\n", .{});
                }
                const val = @divTrunc(data.src1, data.src2);
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "division result", ir.span);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .div_float => {
                const data = try self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), @divTrunc(data.src1, data.src2));
            },
            .mod => {
                const data = try self.binop_load_int(ir.src1.?, ir.src2.?);
                const val = @rem(data.src1, data.src2);
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "modulus result", ir.span);
                self.store_int(try self.effective_address(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .get_tag => { // gets the tag of a union value. The tag will be located in the last slot
                const tag_offset = ir.src1.?.sizeof() - 8;
                std.debug.assert(ir.dest.?.sizeof() == 8);
                self.move(try self.effective_address(ir.dest.?), try self.effective_address(ir.src1.?) + tag_offset, 8);
            },
            .jump => {
                if (ir.data.jump_bb.next) |next| {
                    self.instruction_pointer = next.offset.?;
                } else {
                    self.ret();
                }
            },
            .branch_if_false => {
                if (self.load_int(try self.effective_address(ir.src1.?), ir.src1.?.sizeof()) != 0) {
                    if (ir.data.branch_bb.next) |next| {
                        self.instruction_pointer = next.offset.?;
                    } else {
                        self.ret();
                    }
                } else {
                    if (ir.data.branch_bb.branch) |branch| {
                        self.instruction_pointer = branch.offset.?;
                    } else {
                        self.ret();
                    }
                }
            },
            .call => {
                const symbol: *symbol_.Symbol = @ptrFromInt(@as(usize, @intCast(self.load_int(try self.effective_address(ir.src1.?), 8))));

                // Save old stack pointer
                const old_sp = self.stack_pointer;
                self.stack_pointer = offsets_.next_alignment(self.stack_pointer, 8); // align stack pointer to 8 before pushing args

                //  push args in reverse order
                var i: i64 = @as(i64, @intCast(ir.data.lval_list.items.len)) - 1;
                while (i >= 0) : (i -= 1) {
                    const arg = ir.data.lval_list.items[@as(usize, @intCast(i))];
                    const size = arg.get_expanded_type().sizeof();
                    const alignof = arg.get_expanded_type().alignof();
                    self.stack_pointer = offsets_.next_alignment(self.stack_pointer, alignof);
                    self.push_move(try self.effective_address(arg), size);
                }
                self.stack_pointer = offsets_.next_alignment(self.stack_pointer, 8);

                // Setup next stackframe
                self.push_int(8, try self.effective_address(ir.dest.?)); //          push return-value address
                self.push_int(8, old_sp); //                            push old sp
                self.push_int(8, self.base_pointer); //                 push bp
                self.push_int(8, self.instruction_pointer); //          push return address
                self.base_pointer = self.stack_pointer - 8; //          bp := sp -1

                // allocate space for locals
                self.stack_pointer += symbol.cfg.?.locals_size.?;

                // jump to symbol addr
                self.instruction_pointer = symbol.cfg.?.offset.?;
            },
            .push_stack_trace => { // Pushes a static span/code to the lines array if debug mode is on
                self.debug_call_stack.append(ir.span) catch unreachable;
            },
            .pop_stack_trace => { // Pops a message off the stack after a function is successfully called
                _ = self.debug_call_stack.pop();
            },
            .panic => { // if debug mode is on, panics with a message, unrolls lines stack, exits
                return self.panic(ir.span, "interpreter error: reached unreachable code\n", .{});
            },
            else => std.debug.panic("interpreter error: interpreter.zig::interpret(): Unimplemented IR for {s}\n", .{@tagName(ir.kind)}),
        }
    }

    /// Signals an interpreter panic, printing an error message and call stack information.
    fn panic(self: *Context, span: ?span_.Span, comptime msg: []const u8, args: anytype) error{InterpreterPanic} {
        std.io.getStdErr().writer().print(msg, args) catch return error.InterpreterPanic;
        if (span != null) {
            self.debug_call_stack.append(span.?) catch unreachable;
        }

        var i = self.debug_call_stack.items.len - 1;
        while (true) {
            var stack_span = self.debug_call_stack.items[i];
            stack_span.print_debug_line(std.io.getStdOut().writer(), span_.interpreter_format) catch return error.InterpreterPanic;

            if (i == 0) {
                break;
            } else {
                i -= 1;
            }
        }
        return error.InterpreterPanic;
    }

    /// Asserts that the provided `val` fits within the bounds specified by the data type `_type`.
    /// Adds an error if the value is out of bounds.
    fn assert_fits(self: *Context, val: i128, _type: *ast_.AST, operation_name: []const u8, span: span_.Span) error{InterpreterPanic}!void {
        const bounds = primitives_.bounds_from_ast(_type) orelse return;
        if (val < bounds.lower or val > bounds.upper) {
            return self.panic(span, "interpreter error: {s} is out of bounds; value={}\n", .{ operation_name, val });
        }
    }

    /// Extracts an AST value from a specified memory address in interpreter's memory, based on the given AST type.
    pub fn extract_ast(self: *Context, address: i64, _type: *ast_.AST, allocator: std.mem.Allocator) *ast_.AST {
        // FIXME: High Cyclo
        std.debug.assert(address >= 0);
        switch (_type.*) {
            .identifier => {
                const info = primitives_.info_from_name(_type.token().data);
                switch (info.type_kind) {
                    .type => {
                        const stack_value = @as(usize, @intCast(self.load_int(address, 8)));
                        if (stack_value == 0x5858585858585858) { // This works only if the interpreter never has uninitialized memory
                            return primitives_.unit_type;
                        } else {
                            return @ptrFromInt(stack_value);
                        }
                    },
                    .none => unreachable,
                    .boolean => {
                        const val = self.load_int(address, info.size);
                        if (val == 0) {
                            return ast_.AST.create_false(token_.Token.init_simple("false"), allocator).assert_valid();
                        } else {
                            return ast_.AST.create_true(token_.Token.init_simple("true"), allocator).assert_valid();
                        }
                    },
                    .signed_integer => {
                        const retval = ast_.AST.create_int(
                            token_.Token.init_simple("signed int"),
                            self.load_int(address, info.size),
                            allocator,
                        ).assert_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                    .unsigned_integer => {
                        const retval = ast_.AST.create_int(
                            token_.Token.init_simple("unsigned int"),
                            self.load_int(address, info.size),
                            allocator,
                        ).assert_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                    .floating_point => {
                        const retval = ast_.AST.create_float(
                            token_.Token.init_simple("float"),
                            self.load_float(address, info.size),
                            allocator,
                        ).assert_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                }
            },
            .addr_of => return ast_.AST.create_int(
                token_.Token.init_simple("unsigned int"),
                self.load_int(address, 8),
                allocator,
            ).assert_valid(),
            .function => {
                const stack_value = @as(usize, @intCast(self.load_int(address, 8)));
                if (stack_value == 0) {
                    return primitives_.void_type;
                } else {
                    const symbol: *symbol_.Symbol = @ptrFromInt(stack_value);
                    const ast = ast_.AST.create_symbol(
                        token_.Token.init_simple("function"),
                        .@"fn",
                        symbol.name,
                        allocator,
                    );
                    ast.set_symbol(symbol);
                    return ast.assert_valid();
                }
            },
            .unit_type => return ast_.AST.create_unit_value(_type.token(), allocator).assert_valid(),
            .sum_type => {
                var retval = ast_.AST.create_sum_value(_type.token(), allocator).assert_valid();
                const tag = self.load_int(address + _type.sizeof() - 8, 8);
                retval.set_pos(@as(usize, @intCast(tag)));
                retval.sum_value.base = _type;
                const proper_term: *ast_.AST = _type.children().items[@as(usize, @intCast(tag))];
                retval.sum_value.init = self.extract_ast(address, proper_term, allocator);
                return retval;
            },
            .product => {
                var value_terms = std.ArrayList(*ast_.AST).init(allocator);
                errdefer value_terms.deinit();
                var offset: i64 = 0;
                for (_type.children().items) |term| {
                    offset = offsets_.next_alignment(offset, term.alignof());
                    const extracted_term = self.extract_ast(address + offset, term, allocator);
                    value_terms.append(extracted_term) catch unreachable;
                    offset += term.sizeof();
                }
                return ast_.AST.create_product(_type.token(), value_terms, allocator).assert_valid();
            },
            .annotation => return self.extract_ast(address, _type.annotation.type, allocator),
            else => std.debug.panic("interpreter error: unimplemented generate_default() for: AST.{s}\n", .{@tagName(_type.*)}),
        }
    }
};
