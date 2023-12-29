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

pub const Context = struct {
    stack: [stack_limit]u8,
    stack_pointer: i64,
    base_pointer: i64,

    instructions: *std.ArrayList(*ir_.IR),
    instruction_pointer: i64,

    debug_call_mem: [stack_limit]u8,
    debug_call_stack: std.ArrayList(span_.Span),

    pub fn init(
        cfg: *cfg_.CFG,
        instructions: *std.ArrayList(*ir_.IR), // Flat list of instructions to interpret
        ret_type: *ast_.AST,
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
        };

        var fba = std.heap.FixedBufferAllocator.init(&retval.debug_call_mem);
        retval.debug_call_stack = std.ArrayList(span_.Span).init(fba.allocator());

        // First `ret_type.sizeof()` bytes are reserved for the return value
        // Initial stack frame is setup immediately after
        retval.store_int(frame_address + 0 * @sizeOf(i64), @sizeOf(i64), 0); // Set the return value address to 0
        retval.store_int(frame_address + 1 * @sizeOf(i64), @sizeOf(i64), 0); // Set the prev-bp to 0
        retval.store_int(frame_address + 2 * @sizeOf(i64), @sizeOf(i64), 0); // Set the prev-sp to 0
        retval.store_int(frame_address + 3 * @sizeOf(i64), @sizeOf(i64), halt_trap); // Set the return address to halt trap value

        return retval;
    }

    fn get_lval(self: *Context, lval: *lval_.L_Value) i64 {
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
                    std.debug.print("cannot use `{s}` because its comptime, lol!\n", .{lval.symbver.symbol.name});
                    unreachable; // TODO: Make proper error ( :( )
                } else {
                    // std.debug.print("{s}\n", .{lval.symbver.symbol.name});
                    return self.base_pointer + lval.symbver.symbol.offset.?;
                }
            },
            .dereference => return self.load(i64, self.get_lval(lval.dereference.expr)),
            .index => {
                const base = self.get_lval(lval.index.lhs);
                const index = self.load(i64, self.get_lval(lval.index.rhs));
                return base + index * lval.index.size;
            },
            .select => {
                const base = self.get_lval(lval.select.lhs);
                return base + lval.select.offset;
            },
        }
    }

    fn store(self: *Context, comptime T: type, address: i64, val: T) void {
        std.debug.assert(address >= 0);
        // std.debug.print("[0x{X}:{}] = {}\n", .{ address, @alignOf(T), val });
        @as(*T, @alignCast(@ptrCast(&self.stack[@as(usize, @intCast(address))]))).* = val;
    }

    fn store_int(self: *Context, address: i64, size: i64, val: i128) void {
        std.debug.assert(address >= 0);
        switch (size) {
            1 => self.store(i8, address, @as(i8, @intCast(val))),
            2 => self.store(i16, address, @as(i16, @intCast(val))),
            4 => self.store(i32, address, @as(i32, @intCast(val))),
            8 => self.store(i64, address, @as(i64, @intCast(val))),
            else => {
                std.debug.print("cannot store an int of size {}\n", .{size});
                unreachable;
            },
        }
    }

    fn store_float(self: *Context, address: i64, size: i64, val: f64) void {
        std.debug.assert(address >= 0);
        switch (size) {
            4 => self.store(f32, address, @as(f32, @floatCast(val))),
            8 => self.store(f64, address, val),
            else => unreachable,
        }
    }

    fn load(self: *Context, comptime T: type, address: i64) T {
        std.debug.assert(address >= 0);
        const val = @as(*T, @ptrCast(@alignCast(&self.stack[@as(usize, @intCast(address))]))).*;
        // std.debug.print("[0x{X}:{}] \t// {}\n", .{ address, @alignOf(T), val });
        return val;
    }

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

    fn load_float(self: *Context, address: i64, size: i64) f64 {
        std.debug.assert(address >= 0);
        return switch (size) {
            4 => self.load(f32, address),
            8 => self.load(f64, address),
            else => unreachable,
        };
    }

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

    fn move_lval_list(self: *Context, dest: i64, list: *std.ArrayList(*lval_.L_Value)) void {
        std.debug.assert(dest >= 0);
        var cursor = dest;
        for (list.items) |lval| {
            cursor = offsets_.next_alignment(cursor, lval.alignof());
            const len = lval.sizeof();
            self.move(cursor, self.get_lval(lval), len);
            cursor += len;
        }
    }

    fn push_int(self: *Context, size: i64, val: i128) void {
        self.store_int(self.stack_pointer, size, val);
        self.stack_pointer += size;
    }

    fn push_move(self: *Context, addr: i64, size: i64) void {
        self.move(self.stack_pointer, addr, size);
        self.stack_pointer += size;
    }

    fn pop_int(self: *Context, size: i64) i128 {
        self.stack_pointer -= size;
        return self.load_int(self.stack_pointer, size);
    }

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

    fn print_registers(self: *Context) void {
        std.debug.print("bp:0x{X} sp:0x{X} ip:0x{X}\n", .{ self.base_pointer, self.stack_pointer, self.instruction_pointer });
    }

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

    fn binop_load_int(self: *Context, src1: *lval_.L_Value, src2: *lval_.L_Value) struct { src1: i128, src2: i128 } {
        return .{ .src1 = self.load_int(self.get_lval(src1), src1.sizeof()), .src2 = self.load_int(self.get_lval(src2), src2.sizeof()) };
    }

    fn binop_load_float(self: *Context, src1: *lval_.L_Value, src2: *lval_.L_Value) struct { src1: f64, src2: f64 } {
        return .{ .src1 = self.load_float(self.get_lval(src1), src1.sizeof()), .src2 = self.load_float(self.get_lval(src2), src2.sizeof()) };
    }

    pub fn interpret(self: *Context) error{interpreter_panic}!void {
        // Halt whenever instruction pointer is negative
        while (self.instruction_pointer < halt_trap) : (self.instruction_pointer += 1) {
            const ir: *ir_.IR = self.instructions.items[@as(usize, @intCast(self.instruction_pointer))];
            // self.print_registers();
            // self.print_stack();
            // std.debug.print("\n\n\n\n{}=>\n", .{ir});
            try self.execute(ir);
        }
    }

    inline fn execute(self: *Context, ir: *ir_.IR) error{interpreter_panic}!void { // This doesn't work if it's not inlined, lol!
        switch (ir.kind) {
            // Invalid instructions
            .load_extern,
            .size_of,
            => unreachable,

            // Nops
            .label, .discard, .load_unit => {},

            // Load literals
            .load_int => {
                try self.assert_fits(ir.data.int, ir.dest.?.get_expanded_type(), "integer value", ir.span);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), ir.data.int);
            },
            .load_float => self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), ir.data.float),
            .load_string => self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), ir.data.string_id),
            .load_symbol => self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), @intFromPtr(ir.data.symbol)),
            .load_AST => self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), @intFromPtr(ir.data.ast)),
            .load_struct => self.move_lval_list(self.get_lval(ir.dest.?), &ir.data.lval_list),
            .load_union => {
                if (ir.src1 != null) {
                    // Store data into first field
                    self.move(self.get_lval(ir.dest.?), self.get_lval(ir.src1.?), ir.src1.?.sizeof());
                }
                // Store tag in last field
                self.store(i64, self.get_lval(ir.dest.?) + ir.dest.?.sizeof() - 8, @as(i64, @intCast(ir.data.int)));
            },

            .copy => {
                std.debug.assert(ir.dest.?.sizeof() == ir.src1.?.sizeof());
                self.move(self.get_lval(ir.dest.?), self.get_lval(ir.src1.?), ir.dest.?.sizeof());
            },
            .not => {
                const data = self.load_int(self.get_lval(ir.src1.?), ir.src1.?.sizeof());
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data != 0) 0 else 1);
            },
            .negate_int => {
                const data = self.load_int(self.get_lval(ir.src1.?), ir.src1.?.sizeof());
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), -data);
            },
            .negate_float => {
                const data = self.load_float(self.get_lval(ir.src1.?), ir.src1.?.sizeof());
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), -data);
            },
            .addr_of => {
                const data = self.get_lval(ir.src1.?);
                self.store_int(self.get_lval(ir.dest.?), 8, data);
            },
            .equal => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 == data.src2) 1 else 0);
            },
            .not_equal => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 != data.src2) 1 else 0);
            },
            .greater_int => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 > data.src2) 1 else 0);
            },
            .greater_float => {
                const data = self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 > data.src2) 1 else 0);
            },
            .lesser_int => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 < data.src2) 1 else 0);
            },
            .lesser_float => {
                const data = self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 < data.src2) 1 else 0);
            },
            .greater_equal_int => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 >= data.src2) 1 else 0);
            },
            .greater_equal_float => {
                const data = self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 >= data.src2) 1 else 0);
            },
            .lesser_equal_int => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 <= data.src2) 1 else 0);
            },
            .lesser_equal_float => {
                const data = self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), if (data.src1 <= data.src2) 1 else 0);
            },
            .add_int => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                const val = data.src1 + data.src2;
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "addition results", ir.span);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .add_float => {
                const data = self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), data.src1 + data.src2);
            },
            .sub_int => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                const val = data.src1 - data.src2;
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "subtraction results", ir.span);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .sub_float => {
                const data = self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), data.src1 - data.src2);
            },
            .mult_int => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                const val = data.src1 * data.src2;
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "multiplication results", ir.span);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .mult_float => {
                const data = self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), data.src1 * data.src2);
            },
            .div_int => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                if (data.src2 == 0) {
                    try self.panic(ir.span, "error: division by zero\n", .{});
                }
                const val = @divTrunc(data.src1, data.src2);
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "division results", ir.span);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .div_float => {
                const data = self.binop_load_float(ir.src1.?, ir.src2.?);
                self.store_float(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), @divTrunc(data.src1, data.src2));
            },
            .mod => {
                const data = self.binop_load_int(ir.src1.?, ir.src2.?);
                const val = @rem(data.src1, data.src2);
                try self.assert_fits(val, ir.dest.?.get_expanded_type(), "modulus results", ir.span);
                self.store_int(self.get_lval(ir.dest.?), ir.dest.?.sizeof(), val);
            },
            .get_tag => { // gets the tag of a union value. The tag will be located in the last slot
                const tag_offset = ir.src1.?.sizeof() - 8;
                std.debug.assert(ir.dest.?.sizeof() == 8);
                self.move(self.get_lval(ir.dest.?), self.get_lval(ir.src1.?) + tag_offset, 8);
            },
            .cast => std.debug.print("interpreter.zig::interpret(): Unimplemented IR for {s}\n", .{@tagName(ir.kind)}),
            .jump => {
                if (ir.data.jump_bb.next) |next| {
                    self.instruction_pointer = next.offset.?;
                } else {
                    self.ret();
                }
            },
            .branch_if_false => { // TODO: This is confusing...
                if (self.load_int(self.get_lval(ir.src1.?), ir.src1.?.sizeof()) != 0) {
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
                const symbol: *symbol_.Symbol = @ptrFromInt(@as(usize, @intCast(self.load_int(self.get_lval(ir.src1.?), 8))));

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
                    self.push_move(self.get_lval(arg), size);
                }
                self.stack_pointer = offsets_.next_alignment(self.stack_pointer, 8);

                // Setup next stackframe
                self.push_int(8, self.get_lval(ir.dest.?)); //          push return-value address
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
                try self.panic(ir.span, "error: reached unreachable code\n", .{});
            },
        }
    }

    fn panic(self: *Context, span: span_.Span, comptime msg: []const u8, args: anytype) error{interpreter_panic}!void {
        std.io.getStdErr().writer().print(msg, args) catch return error.interpreter_panic;
        self.debug_call_stack.append(span) catch unreachable;

        var i = self.debug_call_stack.items.len - 1;
        while (true) {
            var stack_span = self.debug_call_stack.items[i];
            stack_span.print_debug_line(std.io.getStdOut().writer(), span_.interpreter_format) catch return error.interpreter_panic;

            if (i == 0) {
                break;
            } else {
                i -= 1;
            }
        }
        return error.interpreter_panic;
    }

    fn assert_fits(self: *Context, val: i128, _type: *ast_.AST, name: []const u8, span: span_.Span) !void {
        const bounds = primitives_.get_bounds(_type);
        if (val < bounds.lower or val > bounds.upper) {
            try self.panic(span, "error: {s} is out of bounds; value={}\n", .{ name, val });
        }
    }

    pub fn extract_ast(self: *Context, address: i64, _type: *ast_.AST, allocator: std.mem.Allocator) *ast_.AST {
        std.debug.assert(address >= 0);
        switch (_type.*) {
            .identifier => {
                const info = primitives_.get(_type.token().data);
                switch (info.type_kind) {
                    .type => return @ptrFromInt(@as(usize, @intCast(self.load_int(address, 8)))),
                    .none => unreachable,
                    .boolean => {
                        const val = self.load_int(address, info.size);
                        if (val == 0) {
                            return ast_.AST.createFalse(token_.Token.init_simple("false"), allocator).assert_valid();
                        } else {
                            return ast_.AST.createTrue(token_.Token.init_simple("true"), allocator).assert_valid();
                        }
                    },
                    .signed_integer => {
                        const retval = ast_.AST.createInt(
                            token_.Token.init_simple("signed int"),
                            self.load_int(address, info.size),
                            allocator,
                        ).assert_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                    .unsigned_integer => {
                        const retval = ast_.AST.createInt(
                            token_.Token.init_simple("unsigned int"),
                            self.load_int(address, info.size),
                            allocator,
                        ).assert_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                    .floating_point => {
                        const retval = ast_.AST.createFloat(
                            token_.Token.init_simple("float"),
                            self.load_float(address, info.size),
                            allocator,
                        ).assert_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                }
            },
            .addrOf => return ast_.AST.createInt(
                token_.Token.init_simple("unsigned int"),
                self.load_int(address, 8),
                allocator,
            ).assert_valid(),
            .function => {
                const symbol: *symbol_.Symbol = @ptrFromInt(@as(usize, @intCast(self.load_int(address, 8))));
                const ast = ast_.AST.createSymbol(
                    token_.Token.init_simple("function"),
                    .@"fn",
                    symbol.name,
                    allocator,
                );
                ast.set_symbol(symbol);
                return ast.assert_valid();
            },
            .unit_type => return ast_.AST.createUnitValue(_type.token(), allocator).assert_valid(),
            .sum => {
                var retval = ast_.AST.createInferredMember(
                    _type.token(),
                    ast_.AST.createIdentifier(
                        token_.Token.init("extracted from interpreter", .identifier, "", "", 0, 0),
                        allocator,
                    ).assert_valid(),
                    allocator,
                ).assert_valid();
                const tag = self.load_int(address + _type.sizeof() - 8, 8);
                retval.set_pos(@as(usize, @intCast(tag)));
                retval.inferredMember.base = _type;
                const proper_term: *ast_.AST = _type.children().items[@as(usize, @intCast(tag))];
                retval.inferredMember.init = self.extract_ast(address, proper_term, allocator);
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
                return ast_.AST.createProduct(_type.token(), value_terms, allocator).assert_valid();
            },
            .annotation => return self.extract_ast(address, _type.annotation.type, allocator),
            else => {
                std.debug.print("Unimplemented generate_default() for: AST.{s}\n", .{@tagName(_type.*)});
                unreachable;
            },
        }
    }
};
