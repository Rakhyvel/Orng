const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const builtin_ = @import("builtin.zig");
const cfg_ = @import("../ir/cfg.zig");
const compiler_ = @import("../compilation/compiler.zig");
const errs_ = @import("../util/errors.zig");
const ir_ = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const module_ = @import("../hierarchy/module.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const offsets_ = @import("../hierarchy/offsets.zig");
const token_ = @import("../lexer/token.zig");
const span_ = @import("../util/span.zig");
const symbol_ = @import("../symbol/symbol.zig");

/// Interpreter execution timeout in milliseconds
const timeout_ms = 1000;
/// Size of the stack. 32 KiB, or around 1024 stack frames.
const stack_limit = 0x8000; // 32 KiB

/// Executing an instruction at this address causes the interpreter to halt. This is used as the return address for the
/// entry point, so that if the entry returns, interpretation halts. Also allows for a way to halt interpretation from
/// anywhere, by simply jumping to here.
const halt_trap_instruction: offsets_.Instruction_Idx = 0xFFFF_FFF0;

/// When true, interpreter runs each instruction at a time, printing the stack and registers for debugging purposes.
/// I _think_ that VSCode language servers consume a JSON file representing the state of the debugger, so this could be
/// useful.
const debugger: bool = false;

const Instruction_Pointer = struct {
    /// The UID of the module currently being executed
    module_uid: module_.Module_UID,
    /// The index of the instruction currently being executed, relative to the current module
    inst_idx: offsets_.Instruction_Idx,
};

pub const Context = struct {
    // These are signed to make offsets (which can be negative from the base pointer) easier
    stack_pointer: i64,
    base_pointer: i64,
    bump_alloc_pointer: i64,
    instruction_pointer: Instruction_Pointer,

    memory: []u8, // TODO: Memory pool with load, store, move methods
    modules: std.AutoArrayHashMap(module_.Module_UID, *module_.Module),
    debug_call_stack: std.ArrayList(span_.Span),
    start_time: i64,

    call_depth: i64,

    errors: *errs_.Errors,
    allocator: std.mem.Allocator,

    /// Initializes a new interpreter context.
    pub fn init(errors: *errs_.Errors, allocator: std.mem.Allocator) Context {
        return Context{
            .memory = allocator.alloc(u8, stack_limit) catch unreachable,
            .bump_alloc_pointer = stack_limit,
            .stack_pointer = 0,
            .base_pointer = 0,

            .modules = std.AutoArrayHashMap(module_.Module_UID, *module_.Module).init(allocator),
            .instruction_pointer = .{ .module_uid = 0, .inst_idx = 0 },
            .debug_call_stack = std.ArrayList(span_.Span).init(allocator),

            .start_time = std.time.milliTimestamp(),

            .call_depth = 0,

            .errors = errors,
            .allocator = allocator,
        };
    }

    pub fn set_entry_point(
        self: *Context,
        entry: *cfg_.CFG,
        ret_type: *ast_.AST,
    ) void {
        const frame_address = offsets_.next_alignment(ret_type.sizeof(), 8);
        const module = entry.symbol.scope.module.?;

        self.stack_pointer = (5 * @sizeOf(i64)) + frame_address + entry.locals_size.?;
        self.base_pointer = (3 * @sizeOf(i64)) + frame_address;
        self.instruction_pointer = .{ .module_uid = module.uid, .inst_idx = entry.offset.? };

        // First `ret_type.sizeof()` bytes are reserved for the return value
        // Initial stack frame is setup immediately after
        self.store_int(frame_address + 0 * @sizeOf(i64), @sizeOf(i64), 0); // Set the return value address to 0
        self.store_int(frame_address + 1 * @sizeOf(i64), @sizeOf(i64), 0); // Set the prev-bp to 0
        self.store_int(frame_address + 2 * @sizeOf(i64), @sizeOf(i64), 0); // Set the prev-sp to 0
        self.store(Instruction_Pointer, frame_address + 3 * @sizeOf(i64), .{ .module_uid = 0, .inst_idx = halt_trap_instruction }); // Set the return address to halt trap value

        self.debug_call_stack.append(entry.symbol.span) catch unreachable;

        self.load_module(module);
    }

    pub fn deinit(self: *Context) void {
        self.modules.deinit();
        self.debug_call_stack.deinit();
        self.allocator.free(self.memory);
    }

    /// Interprets the interpreter's instructions until the interpreter has executed more return instructions than call
    /// instructions, and the instruction pointer isn't a trap representation.
    pub fn run(
        self: *Context,
        compiler: *compiler_.Context,
    ) error{CompileError}!void {
        const initial_call_depth = self.call_depth;
        // Stop whenever has returned more than called, or instruction pointer is not a halt trap representation
        while (self.call_depth >= initial_call_depth and self.instruction_pointer.inst_idx < halt_trap_instruction) : (self.instruction_pointer.inst_idx += 1) {
            const instr: *ir_.Instruction = try self.curr_instruction();
            if (debugger) {
                std.debug.print("\n", .{});
                self.print_registers();
                self.print_stack();
                std.debug.print("\n\n\n\n{s}\n{}=> ", .{ instr.span.line_text, instr });
            }
            const time_now = std.time.milliTimestamp();
            if (!debugger and time_now - self.start_time > timeout_ms) {
                return self.interpreter_panic("interpreter error: compile-time interpreter timeout\n", .{});
            }
            if (debugger) {
                var in_buffer: [256]u8 = undefined;
                _ = std.io.getStdIn().read(&in_buffer) catch unreachable;
            }
            try self.execute_instruction(instr, compiler);
        }
    }

    /// Executes an instruction within the interpreter context.
    inline fn execute_instruction(self: *Context, instr: *ir_.Instruction, compiler: *compiler_.Context) error{CompileError}!void { // This doesn't work if it's not inlined, lol!
        switch (instr.kind) {
            // Invalid instructions
            .load_extern,
            .size_of,
            => unreachable,

            // Nops
            .label, .load_unit => {},

            // Load literals
            .load_int => {
                try self.assert_fits(instr.data.int, instr.dest.?.get_expanded_type(), "integer value", instr.span);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), instr.data.int);
            },
            .load_float => self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), instr.data.float),
            .load_string => self.store(ir_.String_Idx, try self.effective_address(instr.dest.?), instr.data.string_id),
            .load_symbol => {
                const symbol_module = instr.data.symbol.scope.module.?;
                if (self.modules.get(symbol_module.uid) == null) {
                    self.load_module(symbol_module);
                }
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), @intFromPtr(instr.data.symbol));
            },
            .load_AST => {
                // std.debug.print("loading: {}\n", .{instr.data.ast});
                self.store_int(try self.effective_address(instr.dest.?), 8, @intFromPtr(instr.data.ast));
            },
            .load_struct => try self.move_lval_list(try self.effective_address(instr.dest.?), &instr.data.lval_list),
            .load_union => {
                if (instr.src1 != null) {
                    // Store data into first field
                    const dest = try self.effective_address(instr.dest.?);
                    const src = try self.effective_address(instr.src1.?);
                    self.move(dest, src, instr.src1.?.expanded_type_sizeof());
                }
                // Store tag in last field
                const tag_address = try self.effective_address(instr.dest.?) + instr.dest.?.expanded_type_sizeof() - 8;
                self.store(i64, tag_address, @as(i64, @intCast(instr.data.int)));
            },

            .copy => {
                std.debug.assert(instr.dest.?.expanded_type_sizeof() == instr.src1.?.expanded_type_sizeof());
                const dest = try self.effective_address(instr.dest.?);
                const src = try self.effective_address(instr.src1.?);
                self.move(dest, src, instr.dest.?.expanded_type_sizeof());
            },
            .not => {
                const data = self.load_int(try self.effective_address(instr.src1.?), instr.src1.?.expanded_type_sizeof());
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data != 0) 0 else 1);
            },
            .negate_int => {
                const data = self.load_int(try self.effective_address(instr.src1.?), instr.src1.?.expanded_type_sizeof());
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), -data);
            },
            .negate_float => {
                const data = self.load_float(try self.effective_address(instr.src1.?), instr.src1.?.expanded_type_sizeof());
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), -data);
            },
            .mut_addr_of, .addr_of => {
                const data = try self.effective_address(instr.src1.?);
                self.store_int(try self.effective_address(instr.dest.?), 8, data);
            },
            .equal => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 == data.src2) 1 else 0);
            },
            .not_equal => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 != data.src2) 1 else 0);
            },
            .greater_int => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 > data.src2) 1 else 0);
            },
            .greater_float => {
                const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 > data.src2) 1 else 0);
            },
            .lesser_int => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 < data.src2) 1 else 0);
            },
            .lesser_float => {
                const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 < data.src2) 1 else 0);
            },
            .greater_equal_int => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 >= data.src2) 1 else 0);
            },
            .greater_equal_float => {
                const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 >= data.src2) 1 else 0);
            },
            .lesser_equal_int => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 <= data.src2) 1 else 0);
            },
            .lesser_equal_float => {
                const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 <= data.src2) 1 else 0);
            },
            .add_int => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                const val = data.src1 + data.src2;
                try self.assert_fits(val, instr.dest.?.get_expanded_type(), "addition result", instr.span);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
            },
            .add_float => {
                const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), data.src1 + data.src2);
            },
            .sub_int => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                const val = data.src1 - data.src2;
                try self.assert_fits(val, instr.dest.?.get_expanded_type(), "subtraction result", instr.span);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
            },
            .sub_float => {
                const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), data.src1 - data.src2);
            },
            .mult_int => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                const val = data.src1 * data.src2;
                try self.assert_fits(val, instr.dest.?.get_expanded_type(), "multiplication result", instr.span);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
            },
            .mult_float => {
                const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), data.src1 * data.src2);
            },
            .div_int => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                if (data.src2 == 0) {
                    self.debug_call_stack.append(instr.span) catch unreachable;
                    return self.interpreter_panic("interpreter error: division by zero\n", .{});
                }
                const val = @divTrunc(data.src1, data.src2);
                try self.assert_fits(val, instr.dest.?.get_expanded_type(), "division result", instr.span);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
            },
            .div_float => {
                const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
                self.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), @divTrunc(data.src1, data.src2));
            },
            .mod => {
                const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
                const val = @rem(data.src1, data.src2);
                try self.assert_fits(val, instr.dest.?.get_expanded_type(), "modulus result", instr.span);
                self.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
            },
            .get_tag => { // gets the tag of a union value. The tag will be located in the last slot
                const tag_offset = instr.src1.?.expanded_type_sizeof() - 8;
                std.debug.assert(instr.dest.?.expanded_type_sizeof() == 8);
                self.move(try self.effective_address(instr.dest.?), try self.effective_address(instr.src1.?) + tag_offset, 8);
            },
            .jump => {
                if (instr.data.jump_bb.next) |next| {
                    self.instruction_pointer.inst_idx = next.offset.?;
                } else {
                    self.ret();
                }
            },
            .branch_if_false => {
                if (self.load_int(try self.effective_address(instr.src1.?), instr.src1.?.expanded_type_sizeof()) != 0) {
                    if (instr.data.branch_bb.next) |next| {
                        self.instruction_pointer.inst_idx = next.offset.?;
                    } else {
                        self.ret();
                    }
                } else {
                    if (instr.data.branch_bb.branch) |branch| {
                        self.instruction_pointer.inst_idx = branch.offset.?;
                    } else {
                        self.ret();
                    }
                }
            },
            .call => {
                // std.debug.print("symbol instr src: {}\n", .{instr.src1.?});
                const symbol_loc = try self.effective_address(instr.src1.?);
                // std.debug.print("symbol_loc: {}\n", .{symbol_loc});
                const symbol_int = @as(usize, @intCast(self.load_int(symbol_loc, 8)));
                // std.debug.print("symbol_int: {}\n", .{symbol_int});
                const symbol: *symbol_.Symbol = @ptrFromInt(symbol_int);

                // Intercept method calls to builtin methods
                if (symbol.decl != null and
                    symbol.decl.?.* == .method_decl and
                    symbol.decl.?.method_decl.impl != null and
                    symbol.decl.?.method_decl.impl.?.impl._type.types_match(primitives_.package_type))
                {
                    const method_name = symbol.name;
                    if (std.mem.eql(u8, method_name, "find")) {
                        const arg: *lval_.L_Value = instr.data.lval_list.items[@as(usize, @intCast(0))];
                        const path_ast = try self.extract_ast(try self.effective_address(arg), primitives_.string_type, instr.span);
                        const current_module_path = (self.curr_module() catch unreachable).absolute_path;
                        const ret_addr = try self.effective_address(instr.dest.?);
                        if (builtin_.package_find(compiler, self, current_module_path, path_ast.string.data)) |package_info| {
                            const adrs = package_info.package_adrs;
                            // Store the directory of the package inside the package struct before returning
                            const dir_string = self.modules.get(0).?.interned_string_set_add(package_info.package_dirname);
                            const dir_offset = primitives_.package_type.product.get_offset_field("dir", self.allocator);
                            self.store(ir_.String_Idx, adrs + dir_offset, dir_string);
                            // Store the address of the package in the retval
                            self.store_int(ret_addr, 8, adrs);
                        } else |_| {
                            return self.interpreter_panic("interpreter error: cannot find package\n", .{});
                        }
                        return;
                    }
                }

                try self.call(symbol, instr.dest.?, instr.data.lval_list);
            },
            .invoke => {
                const symbol_loc = try self.effective_address(instr.data.invoke.method_decl_lval.?);
                const symbol_int = @as(usize, @intCast(self.load_int(symbol_loc, 8)));
                const symbol: *symbol_.Symbol = @ptrFromInt(symbol_int);

                try self.call(symbol, instr.dest.?, instr.data.invoke.lval_list);
            },
            .push_stack_trace => { // Pushes a static span/code to the lines array if debug mode is on
                self.debug_call_stack.append(instr.span) catch unreachable;
            },
            .pop_stack_trace => { // Pops a message off the stack after a function is successfully called
                _ = self.debug_call_stack.pop();
            },
            .panic => { // if debug mode is on, panics with a message, unrolls lines stack, exits
                return self.interpreter_panic("interpreter error: reached unreachable code\n", .{});
            },
            else => std.debug.panic("interpreter error: interpreter.zig::interpret(): Unimplemented Instruction for {s}\n", .{@tagName(instr.kind)}),
        }
    }

    pub fn load_module(self: *Context, module: *module_.Module) void {
        self.modules.put(module.uid, module) catch unreachable;
    }

    /// Sets up the caller's stack frame, pushes function arguments in reverse order, stores the return value location,
    /// and then jumps to the function's code.
    pub fn call(self: *Context, function_symbol: *symbol_.Symbol, retval_place: *lval_.L_Value, args_list: std.ArrayList(*lval_.L_Value)) error{CompileError}!void {
        self.call_depth += 1;
        // Save old stack pointer
        const old_sp = self.stack_pointer;
        self.stack_pointer = offsets_.next_alignment(self.stack_pointer, 8); // align stack pointer to 8 before pushing args

        // push args in reverse order
        var i: i64 = @as(i64, @intCast(args_list.items.len)) - 1;
        while (i >= 0) : (i -= 1) {
            const arg = args_list.items[@as(usize, @intCast(i))];
            const size = arg.get_expanded_type().sizeof();
            const alignof = arg.expanded_type_alignof();
            self.stack_pointer = offsets_.next_alignment(self.stack_pointer, alignof);
            try self.push_move(try self.effective_address(arg), size);
        }
        self.stack_pointer = offsets_.next_alignment(self.stack_pointer, 8);

        // Setup next stackframe
        try self.push_int(8, try self.effective_address(retval_place)); // push return-value address
        try self.push_int(8, old_sp); //                                push old sp
        try self.push_int(8, self.base_pointer); //                     push bp
        try self.push(Instruction_Pointer, self.instruction_pointer); //          push return address
        self.base_pointer = self.stack_pointer - 8; //                        bp := sp -1

        // allocate space for locals
        const local_size_bytes = function_symbol.cfg.?.locals_size.?;
        try self.memory_check(local_size_bytes);
        self.stack_pointer += local_size_bytes;

        // jump to symbol addr
        self.instruction_pointer = Instruction_Pointer{
            .module_uid = function_symbol.scope.module.?.uid,
            .inst_idx = function_symbol.cfg.?.offset.?,
        };
    }

    /// Tears down the stack frame, and jumps back to the caller's location
    inline fn ret(self: *Context) void {
        self.call_depth -= 1;
        // deallocate locals
        self.stack_pointer = self.base_pointer + 8;
        // jump to return-address
        self.instruction_pointer = self.pop(Instruction_Pointer);
        // restore previous base-pointer
        self.base_pointer = @as(i64, @intCast(self.pop_int(8)));
        // restore previous stack-pointer, deallocate params, deallocate return-pointer
        self.stack_pointer = @as(i64, @intCast(self.pop_int(8)));
        // self.print_registers();
    }

    pub fn alloc(self: *Context, nbytes: i64, align_to: i64) error{CompileError}!usize {
        std.debug.assert(nbytes > 0);
        std.debug.assert(align_to == 1 or align_to == 2 or align_to == 4 or align_to == 8);

        try self.memory_check(nbytes);
        self.bump_alloc_pointer -= nbytes;
        const alignment_subtract = @rem(self.bump_alloc_pointer, align_to);
        try self.memory_check(alignment_subtract);
        self.bump_alloc_pointer -= alignment_subtract;
        return @intCast(self.bump_alloc_pointer);
    }

    /// Extracts an AST value from a specified memory address in interpreter's memory, based on the given AST type.
    pub fn extract_ast(self: *Context, address: i64, _type: *ast_.AST, span: span_.Span) error{CompileError}!*ast_.AST {
        // FIXME: High Cyclo
        std.debug.assert(address >= 0);
        switch (_type.*) {
            .identifier => {
                const info = primitives_.info_from_name(_type.token().data);
                if (info == null) {
                    return try self.extract_ast(address, _type.symbol().?.init.?, span);
                }
                switch (info.?.type_kind) {
                    .type => {
                        const stack_value = self.load_unsigned_int(address, 8);
                        if (stack_value == 0xAAAAAAAAAAAAAAAA) { // NOTE: This only works if the interpreter never overwrites this address...
                            return primitives_.unit_type;
                        } else {
                            return @ptrFromInt(stack_value);
                        }
                    },
                    .string => {
                        const idx = self.load(ir_.String_Idx, address);
                        const module = self.modules.get(idx.module_uid) orelse std.debug.panic("interpreter error: unknown module uid: {}\n", .{idx.module_uid});
                        const string = module.interned_strings.items[idx.string_idx];
                        return ast_.AST.create_string(token_.Token.init_simple("\""), string, self.allocator);
                    },
                    .none => unreachable,
                    .boolean => {
                        const val = self.load_int(address, info.?.size);
                        if (val == 0) {
                            return ast_.AST.create_false(token_.Token.init_simple("false"), self.allocator).assert_ast_valid();
                        } else {
                            return ast_.AST.create_true(token_.Token.init_simple("true"), self.allocator).assert_ast_valid();
                        }
                    },
                    .signed_integer => {
                        const retval = ast_.AST.create_int(
                            token_.Token.init_simple("signed int"),
                            self.load_int(address, info.?.size),
                            self.allocator,
                        ).assert_ast_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                    .unsigned_integer => {
                        const retval = ast_.AST.create_int(
                            token_.Token.init_simple("unsigned int"),
                            self.load_int(address, info.?.size),
                            self.allocator,
                        ).assert_ast_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                    .floating_point => {
                        const retval = ast_.AST.create_float(
                            token_.Token.init_simple("float"),
                            self.load_float(address, info.?.size),
                            self.allocator,
                        ).assert_ast_valid();
                        retval.set_represents(_type);
                        return retval;
                    },
                }
            },
            .addr_of => return ast_.AST.create_int(
                token_.Token.init_simple("unsigned int"),
                self.load_int(address, 8),
                self.allocator,
            ).assert_ast_valid(),
            .function => {
                const stack_value = @as(usize, @intCast(self.load_int(address, 8)));
                if (stack_value == 0) {
                    return primitives_.void_type;
                } else {
                    const symbol: *symbol_.Symbol = @ptrFromInt(stack_value);
                    const ast = ast_.AST.create_pattern_symbol(
                        token_.Token.init_simple("function"),
                        .@"fn",
                        symbol.name,
                        self.allocator,
                    );
                    ast.set_symbol(symbol);
                    return ast.assert_ast_valid();
                }
            },
            .unit_type => return ast_.AST.create_unit_value(_type.token(), self.allocator).assert_ast_valid(),
            .sum_type => {
                // self.print_memory(@intCast(address), @intCast(address + _type.sizeof()));
                var retval = ast_.AST.create_sum_value(_type.token(), self.allocator).assert_ast_valid();
                const tag = self.load_int(address + _type.sizeof() - 8, 8);
                retval.set_pos(@as(usize, @intCast(tag)));
                retval.sum_value.base = _type;
                const proper_term: *ast_.AST = _type.children().items[@as(usize, @intCast(tag))];
                retval.sum_value.init = try self.extract_ast(address, proper_term, span);
                return retval;
            },
            .product => {
                var value_terms = std.ArrayList(*ast_.AST).init(self.allocator);
                errdefer value_terms.deinit();
                for (0.., _type.children().items) |i, term| {
                    // std.debug.print("term:{}\n", .{i});
                    const offset = _type.product.get_offset(i, self.allocator);
                    // std.debug.print("offset:{}\n", .{offset});
                    const extracted_term = try self.extract_ast(address + offset, term, span);
                    // std.debug.print("extracted_term:{}\n", .{extracted_term});
                    value_terms.append(extracted_term) catch unreachable;
                }
                return ast_.AST.create_product(_type.token(), value_terms, self.allocator).assert_ast_valid();
            },
            .untagged_sum_type => {
                self.errors.add_error(errs_.Error{ .basic = .{
                    .span = span,
                    .msg = "comptime untagged sum values cannot propagate to runtime",
                } });
                return error.CompileError;
            },
            .annotation => return try self.extract_ast(address, _type.annotation.type, span),
            else => std.debug.panic("interpreter error: unimplemented extract_ast() for: AST.{s}\n", .{@tagName(_type.*)}),
        }
    }

    pub fn extract_memory_to_owned(self: *Context, address: usize, size_bytes: usize, allocator: std.mem.Allocator) []u8 {
        const owned = allocator.alloc(u8, size_bytes) catch unreachable;

        @memcpy(owned, self.memory[address .. address + size_bytes]);

        return owned;
    }

    /// Prints the values of the interpreter's registers
    fn print_registers(self: *Context) void {
        const module: ?*module_.Module = self.curr_module() catch null;
        std.debug.print("bp:0x{X} sp:0x{X} ip:[{s}#{}]@{X}\n", .{
            self.base_pointer,
            self.stack_pointer,
            if (module != null) module.?.name else "?",
            self.instruction_pointer.module_uid,
            self.instruction_pointer.inst_idx,
        });
    }

    /// Prints the contents of the interpreter's stack. Used for debugging.
    fn print_stack(self: *Context) void {
        self.print_memory(0, @as(usize, @intCast(self.stack_pointer)));
    }

    fn print_memory(self: *Context, start: usize, end: usize) void {
        for (start..end) |i| {
            if (@rem(i, 8) == 0) {
                std.debug.print("0x{0X:0>2.}: ", .{i});
            }
            std.debug.print("{X:0>2.}", .{self.memory[i]});
            if (@rem(i, 8) == 7) {
                std.debug.print(" ", .{});
            }
            if (@rem(i, 32) == 31) {
                std.debug.print("\n", .{});
            }
        }
    }

    fn print_debug_stack(self: *Context) void {
        for (0..self.debug_call_stack.items.len) |i| {
            const span = self.debug_call_stack.items[i];
            std.debug.print("{}: {s}\n", .{ i, span.line_text });
        }
        std.debug.print("\n", .{});
    }

    fn curr_instruction(self: *Context) error{CompileError}!*ir_.Instruction {
        const module = try self.curr_module();
        return module.instructions.items[@as(usize, @intCast(self.instruction_pointer.inst_idx))];
    }

    pub fn curr_module(self: *Context) error{CompileError}!*module_.Module {
        return self.modules.get(self.instruction_pointer.module_uid) orelse
            self.interpreter_panic("interpreter error: attempt to use module 0x{X}, which hasn't been loaded yet\n", .{self.instruction_pointer.module_uid});
    }

    /// Loads integer values from the specified L_Values and returns a structure containing both the loaded
    /// values.
    fn binop_load_int(self: *Context, src1: *lval_.L_Value, src2: *lval_.L_Value) !struct { src1: i128, src2: i128 } {
        return .{
            .src1 = self.load_int(try self.effective_address(src1), src1.expanded_type_sizeof()),
            .src2 = self.load_int(try self.effective_address(src2), src2.expanded_type_sizeof()),
        };
    }

    /// Loads floating-point values from the specified L_Values and returns a structure containing both the
    /// loaded values.
    fn binop_load_float(self: *Context, src1: *lval_.L_Value, src2: *lval_.L_Value) !struct { src1: f64, src2: f64 } {
        return .{
            .src1 = self.load_float(try self.effective_address(src1), src1.expanded_type_sizeof()),
            .src2 = self.load_float(try self.effective_address(src2), src2.expanded_type_sizeof()),
        };
    }

    /// Copies memory blocks referenced by a list of L_Values to the specified destination address in the
    /// interpreter's memory.
    fn move_lval_list(
        self: *Context,
        dest: i64,
        list: *std.ArrayList(*lval_.L_Value),
    ) !void {
        std.debug.assert(dest >= 0);
        var cursor = dest;
        for (list.items) |lval| {
            cursor = offsets_.next_alignment(cursor, lval.expanded_type_alignof());
            const src = try self.effective_address(lval);
            const len = lval.expanded_type_sizeof();
            // std.debug.print("dest:0x{X} src:0x{X} len:0x{X}\n", .{ cursor, src, len });
            // std.debug.print("{}\n", .{lval});
            self.move(cursor, src, len);
            cursor += len;
        }
    }

    /// Moves a block of memory from the source address to the destination address in the interpreter's memory.
    fn move(self: *Context, dest: i64, src: i64, len: i64) void {
        if (debugger) {
            std.debug.print("dest:0x{X} src:0x{X} len:0x{X}\n", .{ dest, src, len });
        }
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
            self.memory[@as(usize, @intCast(dest))..@as(usize, @intCast(dest + len))],
            self.memory[@as(usize, @intCast(src))..@as(usize, @intCast(src + len))],
        );
    }

    /// Gets the effective address of an lvalue in the interpreter's memory.
    fn effective_address(self: *Context, lval: *lval_.L_Value) error{CompileError}!i64 {
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
                        self.debug_call_stack.append(lval.symbver.def.?.span) catch unreachable;
                        return self.interpreter_panic("interpreter error: variable `{s}` isn't comptime known\n", .{lval.symbver.symbol.name});
                    } else {
                        // symbver def is null, use symbol span instead (bad fortune!! curse on family)
                        self.debug_call_stack.append(lval.symbver.symbol.span) catch unreachable;
                        return self.interpreter_panic("interpreter error: variable `{s}` isn't comptime known\n", .{lval.symbver.symbol.name});
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
                return base + index * lval.expanded_type_sizeof();
            },
            .select => {
                const base = try self.effective_address(lval.select.lhs);
                return base + lval.select.offset;
            },
            .raw_address => return lval.raw_address.adrs,
        }
    }

    /// Pops and returns an integer value from the interpreter's stack. The size of the integer is allowed to be known
    /// only at compiler runtime.
    fn pop_int(self: *Context, int_size_bytes: i64) i128 {
        self.stack_pointer -= int_size_bytes;
        return self.load_int(self.stack_pointer, int_size_bytes);
    }

    /// Pops a generic, compiler-comptime-known type from the stack
    fn pop(self: *Context, comptime T: type) T {
        const t_size: usize = @sizeOf(T);
        self.stack_pointer -= t_size;
        return self.load(T, self.stack_pointer);
    }

    /// Pushes an integer value onto the interpreter's stack.
    fn push_int(self: *Context, size: i64, val: i128) error{CompileError}!void {
        try self.memory_check(size);
        self.store_int(self.stack_pointer, size, val);
        self.stack_pointer += size;
    }

    /// Pushes a memory block of the specified size onto the interpreter's stack.
    fn push_move(self: *Context, block_addr: i64, block_size: i64) error{CompileError}!void {
        try self.memory_check(block_size);
        self.move(self.stack_pointer, block_addr, block_size);
        self.stack_pointer += block_size;
    }

    /// Pushes a generic, compiler-comptime-known type to the stack
    fn push(self: *Context, comptime T: type, val: T) error{CompileError}!void {
        const t_size: usize = @sizeOf(T);
        try self.memory_check(t_size);
        self.store(T, self.stack_pointer, val);
        self.stack_pointer += t_size;
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

    /// Stores a value of type T at the specified address in the interpreter's memory.
    fn store(self: *Context, comptime T: type, address: i64, val: T) void {
        std.debug.assert(address >= 0);
        // std.debug.print("[0x{X}:{}] = {}\n", .{ address, @alignOf(T), val });
        @as(*T, @alignCast(@ptrCast(&self.memory[@as(usize, @intCast(address))]))).* = val;
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

    /// Loads an integer value from the specified address in the interpreter's memory.
    fn load_unsigned_int(self: *Context, address: i64, size: i64) u64 {
        std.debug.assert(address >= 0);
        return switch (size) {
            1 => self.load(u8, address),
            2 => self.load(u16, address),
            4 => self.load(u32, address),
            8 => self.load(u64, address),
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

    /// Loads a value of type T from the specified address in the interpreter's memory.
    fn load(self: *Context, comptime T: type, address: i64) T {
        std.debug.assert(address >= 0);
        const val = @as(*T, @ptrCast(@alignCast(&self.memory[@as(usize, @intCast(address))]))).*;
        // std.debug.print("[0x{X}:{}] \t// {}\n", .{ address, @alignOf(T), val });
        return val;
    }

    /// Asserts that the provided `val` fits within the bounds specified by the data type `_type`.
    /// Adds an error if the value is out of bounds.
    fn assert_fits(self: *Context, val: i128, _type: *ast_.AST, operation_name: []const u8, span: span_.Span) error{CompileError}!void {
        const bounds = primitives_.bounds_from_ast(_type) orelse return;
        if (val < bounds.lower or val > bounds.upper) {
            self.debug_call_stack.append(span) catch unreachable;
            return self.interpreter_panic("interpreter error: {s} is out of bounds; value={}\n", .{ operation_name, val });
        }
    }

    fn memory_check(self: *Context, space_needed: i64) error{CompileError}!void {
        if (self.bump_alloc_pointer -| self.stack_pointer < space_needed) {
            return self.interpreter_panic("interpreter error: out of memory!\n", .{});
        }
    }

    /// Signals an interpreter panic, printing an error message and call stack information.
    fn interpreter_panic(self: *Context, comptime msg: []const u8, args: anytype) error{CompileError} {
        std.io.getStdOut().writer().print(msg, args) catch return error.CompileError;

        var i = self.debug_call_stack.items.len - 1;
        while (true) {
            const stack_span = self.debug_call_stack.items[i];
            stack_span.print_debug_line(std.io.getStdOut().writer(), span_.interpreter_format) catch return error.CompileError;

            if (i == 0) {
                break;
            } else {
                i -= 1;
            }
        }
        return error.CompileError;
    }
};
