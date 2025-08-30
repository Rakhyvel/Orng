const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const builtin_ = @import("builtin.zig");
const core_ = @import("../hierarchy/core.zig");
const CFG = @import("../ir/cfg.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const Instruction = @import("../ir/instruction.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");
const lval_ = @import("../ir/lval.zig");
const Memory = @import("memory.zig");
const module_ = @import("../hierarchy/module.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const alignment_ = @import("../util/alignment.zig");
const Token = @import("../lexer/token.zig");
const Span = @import("../util/span.zig");
const Symbol = @import("../symbol/symbol.zig");

const Self = @This();

const Error = error{CompileError};

/// Interpreter execution timeout in milliseconds
const timeout_ms = 5_000;
/// Size of the stack. 32 KiB, or around 1024 stack frames.
const stack_limit = 0x8000; // 32 KiB

/// Executing an instruction at this address causes the interpreter to halt. This is used as the return address for the
/// entry point, so that if the entry returns, interpretation halts. Also allows for a way to halt interpretation from
/// anywhere, by simply jumping to here.
const halt_trap_instruction: Instruction.Index = 0xFFFF_FFF0;

/// When true, interpreter runs each instruction at a time, printing the stack and registers for debugging purposes.
/// I _think_ that VSCode language servers consume a JSON file representing the state of the debugger, so this could be
/// useful.
const Debugger_Mode = enum {
    /// Interpreter does not emit debugging logs
    off,
    /// Interpreter emits debugging logs
    noninteractive,
    /// Interpreter emits debugging logs, waits for user to proceed to next instruction
    interactive,
};
const debugger: Debugger_Mode = .off;

const Instruction_Pointer = struct {
    /// The UID of the module currently being executed
    module_uid: module_.Module_UID,
    /// The index of the instruction currently being executed, relative to the current module
    inst_idx: Instruction.Index,
};

// These are signed to make offsets (which can be negative from the base pointer) easier
stack_pointer: i64,
base_pointer: i64,
bump_alloc_pointer: i64,
instruction_pointer: Instruction_Pointer,

memory: Memory,
modules: std.AutoArrayHashMap(module_.Module_UID, *module_.Module),
debug_call_stack: std.ArrayList(Span),
start_time: i64,

call_depth: i64,

errors: *errs_.Errors,
allocator: std.mem.Allocator,

/// Initializes a new interpreter context.
pub fn init(errors: *errs_.Errors, allocator: std.mem.Allocator) Self {
    return Self{
        .memory = Memory.init(allocator.alloc(u8, stack_limit) catch unreachable),
        .bump_alloc_pointer = stack_limit,
        .stack_pointer = 0,
        .base_pointer = 0,

        .modules = std.AutoArrayHashMap(module_.Module_UID, *module_.Module).init(allocator),
        .instruction_pointer = .{ .module_uid = 0, .inst_idx = 0 },
        .debug_call_stack = std.ArrayList(Span).init(allocator),

        .start_time = std.time.milliTimestamp(),

        .call_depth = 0,

        .errors = errors,
        .allocator = allocator,
    };
}

pub fn set_entry_point(
    self: *Self,
    entry: *CFG,
    ret_type: *ast_.AST,
) void {
    const frame_address = alignment_.next_alignment(ret_type.sizeof(), 8);
    const module = entry.symbol.scope.module.?;

    self.stack_pointer = (5 * @sizeOf(i64)) + frame_address + entry.locals_size.?;
    self.base_pointer = (3 * @sizeOf(i64)) + frame_address;
    self.instruction_pointer = .{ .module_uid = module.uid, .inst_idx = entry.offset.? };

    // First `ret_type.sizeof()` bytes are reserved for the return value
    // Initial stack frame is setup immediately after
    self.memory.store_int(frame_address + 0 * @sizeOf(i64), @sizeOf(i64), 0); // Set the return value address to 0
    self.memory.store_int(frame_address + 1 * @sizeOf(i64), @sizeOf(i64), 0); // Set the prev-bp to 0
    self.memory.store_int(frame_address + 2 * @sizeOf(i64), @sizeOf(i64), 0); // Set the prev-sp to 0
    self.memory.store(Instruction_Pointer, frame_address + 3 * @sizeOf(i64), .{ .module_uid = 0, .inst_idx = halt_trap_instruction }); // Set the return address to halt trap value

    self.debug_call_stack.append(entry.symbol.span) catch unreachable;

    self.load_module(module);
}

pub fn deinit(self: *Self) void {
    self.modules.deinit();
    self.debug_call_stack.deinit();
    self.allocator.free(self.memory.memory);
}

/// Interprets the interpreter's instructions until the interpreter has executed more return instructions than call
/// instructions, and the instruction pointer isn't a trap representation.
pub fn run(
    self: *Self,
    compiler: *Compiler_Context,
) error{CompileError}!void {
    const initial_call_depth = self.call_depth;
    // Stop whenever has returned more than called, or instruction pointer is not a halt trap representation
    while (self.call_depth >= initial_call_depth and self.instruction_pointer.inst_idx < halt_trap_instruction) : (self.instruction_pointer.inst_idx += 1) {
        const instr: *Instruction = try self.curr_instruction();
        if (debugger != .off) {
            std.debug.print("\n", .{});
            self.print_registers();
            self.print_stack();
            std.debug.print("\n\n\n\n{s}\n{}=> ", .{ instr.span.line_text, instr });
        }
        const time_now = std.time.milliTimestamp();
        if (debugger == .off and time_now - self.start_time > timeout_ms) {
            return self.interpreter_panic("interpreter error: compile-time interpreter timeout\n", .{});
        }
        if (debugger == .interactive) {
            var in_buffer: [256]u8 = undefined;
            _ = std.io.getStdIn().read(&in_buffer) catch unreachable;
        }
        try self.execute_instruction(instr, compiler);
    }
}

/// Executes an instruction within the interpreter context.
inline fn execute_instruction(self: *Self, instr: *Instruction, compiler: *Compiler_Context) Error!void { // This doesn't work if it's not inlined, lol!
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
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), instr.data.int);
        },
        .load_float => self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), instr.data.float),
        .load_string => {
            self.memory.store(Interned_String_Set.String_Idx, try self.effective_address(instr.dest.?), instr.data.string_id);
            const interned_strings = compiler.lookup_interned_string_set(self.modules.get(instr.data.string_id.module_uid).?.uid).?;
            const string = interned_strings.items()[instr.data.string_id.string_idx];
            self.memory.store(u64, try self.effective_address(instr.dest.?) + 8, string.len);
        },
        .load_symbol => {
            const symbol_module = instr.data.symbol.scope.module.?;
            if (self.modules.get(symbol_module.uid) == null) {
                self.load_module(symbol_module);
            }
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), @intFromPtr(instr.data.symbol));
        },
        .load_AST => {
            // std.debug.print("loading: {}\n", .{instr.data.ast});
            self.memory.store_int(try self.effective_address(instr.dest.?), 8, @intFromPtr(instr.data.ast));
        },
        .load_struct => try self.move_lval_list(try self.effective_address(instr.dest.?), &instr.data.lval_list),
        .load_union => {
            if (instr.src1 != null) {
                // Store data into first field
                const dest = try self.effective_address(instr.dest.?);
                const src = try self.effective_address(instr.src1.?);
                self.memory.move(dest, src, instr.src1.?.expanded_type_sizeof());
            }
            // Store tag in last field
            const tag_address = try self.effective_address(instr.dest.?) + instr.dest.?.expanded_type_sizeof() - 8;
            self.memory.store(i64, tag_address, @as(i64, @intCast(instr.data.int)));
        },

        .copy => {
            std.debug.assert(instr.dest.?.expanded_type_sizeof() == instr.src1.?.expanded_type_sizeof());
            const dest = try self.effective_address(instr.dest.?);
            const src = try self.effective_address(instr.src1.?);
            self.memory.move(dest, src, instr.dest.?.expanded_type_sizeof());
        },
        .not => {
            const data = self.memory.load_int(try self.effective_address(instr.src1.?), instr.src1.?.expanded_type_sizeof());
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data != 0) 0 else 1);
        },
        .negate_int => {
            const data = self.memory.load_int(try self.effective_address(instr.src1.?), instr.src1.?.expanded_type_sizeof());
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), -data);
        },
        .negate_float => {
            const data = self.memory.load_float(try self.effective_address(instr.src1.?), instr.src1.?.expanded_type_sizeof());
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), -data);
        },
        .mut_addr_of, .addr_of => {
            const data = try self.effective_address(instr.src1.?);
            self.memory.store_int(try self.effective_address(instr.dest.?), 8, data);
        },
        .equal => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 == data.src2) 1 else 0);
        },
        .not_equal => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 != data.src2) 1 else 0);
        },
        .greater_int => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 > data.src2) 1 else 0);
        },
        .greater_float => {
            const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 > data.src2) 1 else 0);
        },
        .lesser_int => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 < data.src2) 1 else 0);
        },
        .lesser_float => {
            const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 < data.src2) 1 else 0);
        },
        .greater_equal_int => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 >= data.src2) 1 else 0);
        },
        .greater_equal_float => {
            const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 >= data.src2) 1 else 0);
        },
        .lesser_equal_int => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 <= data.src2) 1 else 0);
        },
        .lesser_equal_float => {
            const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), if (data.src1 <= data.src2) 1 else 0);
        },
        .add_int => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            const val = data.src1 + data.src2;
            try self.assert_fits(val, instr.dest.?.get_expanded_type(), "addition result", instr.span);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
        },
        .add_float => {
            const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), data.src1 + data.src2);
        },
        .sub_int => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            const val = data.src1 - data.src2;
            try self.assert_fits(val, instr.dest.?.get_expanded_type(), "subtraction result", instr.span);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
        },
        .sub_float => {
            const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), data.src1 - data.src2);
        },
        .mult_int => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            const val = data.src1 * data.src2;
            try self.assert_fits(val, instr.dest.?.get_expanded_type(), "multiplication result", instr.span);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
        },
        .mult_float => {
            const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), data.src1 * data.src2);
        },
        .div_int => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            if (data.src2 == 0) {
                self.debug_call_stack.append(instr.span) catch unreachable;
                return self.interpreter_panic("interpreter error: division by zero\n", .{});
            }
            const val = @divTrunc(data.src1, data.src2);
            try self.assert_fits(val, instr.dest.?.get_expanded_type(), "division result", instr.span);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
        },
        .div_float => {
            const data = try self.binop_load_float(instr.src1.?, instr.src2.?);
            self.memory.store_float(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), @divTrunc(data.src1, data.src2));
        },
        .mod => {
            const data = try self.binop_load_int(instr.src1.?, instr.src2.?);
            const val = @rem(data.src1, data.src2);
            try self.assert_fits(val, instr.dest.?.get_expanded_type(), "modulus result", instr.span);
            self.memory.store_int(try self.effective_address(instr.dest.?), instr.dest.?.expanded_type_sizeof(), val);
        },
        .get_tag => { // gets the tag of a union value. The tag will be located in the last slot
            const tag_offset = instr.src1.?.expanded_type_sizeof() - 8;
            std.debug.assert(instr.dest.?.expanded_type_sizeof() == 8);
            self.memory.move(try self.effective_address(instr.dest.?), try self.effective_address(instr.src1.?) + tag_offset, 8);
        },
        .jump => {
            if (instr.data.jump_bb.next) |next| {
                self.instruction_pointer.inst_idx = next.offset.?;
            } else {
                self.ret();
            }
        },
        .branch_if_false => {
            if (self.memory.load_int(try self.effective_address(instr.src1.?), instr.src1.?.expanded_type_sizeof()) != 0) {
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
            const symbol_int = @as(usize, @intCast(self.memory.load_int(symbol_loc, 8)));
            // std.debug.print("symbol_int: {}\n", .{symbol_int});
            const symbol: *Symbol = @ptrFromInt(symbol_int);

            // Intercept method calls to builtin methods
            if (symbol.represents_method(core_.package_type, "find")) {
                return self.package_find(instr, compiler);
            }

            try self.call(symbol, instr.dest.?, instr.data.lval_list);
        },
        .invoke => {
            const symbol_loc = try self.effective_address(instr.data.invoke.method_decl_lval.?);
            const symbol_int = @as(usize, @intCast(self.memory.load_int(symbol_loc, 8)));
            const symbol: *Symbol = @ptrFromInt(symbol_int);

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

fn package_find(self: *Self, instr: *Instruction, compiler: *Compiler_Context) !void {
    const arg: *lval_.L_Value = instr.data.lval_list.items[@as(usize, @intCast(0))];
    const interned_strings = compiler.lookup_interned_string_set(self.modules.get(1).?.uid).?;
    const src_ast = try self.extract_ast(try self.effective_address(arg), core_.package_source_type, instr.span, &compiler.module_interned_strings);
    const current_module_path = (self.curr_module() catch unreachable).absolute_path;
    if (builtin_.package_find(compiler, self, current_module_path, src_ast)) |package_info| {
        const adrs = package_info.package_adrs;
        // Store the directory of the package inside the package struct before returning
        const dir_string = interned_strings.add(package_info.package_dirname, self.modules.get(1).?.uid);
        const dir_offset = core_.package_type.product.get_offset_field("dir", self.allocator);
        self.memory.store(Interned_String_Set.String_Idx, adrs + dir_offset, dir_string);
        // Store the address of the package in the retval
        const ret_addr = try self.effective_address(instr.dest.?);
        self.memory.store_int(ret_addr, 8, adrs);
    } else |_| {
        return self.interpreter_panic("interpreter error: cannot find package\n", .{});
    }
    return;
}

pub fn load_module(self: *Self, module: *module_.Module) void {
    self.modules.put(module.uid, module) catch unreachable;
}

/// Sets up the caller's stack frame, pushes function arguments in reverse order, stores the return value location,
/// and then jumps to the function's code.
pub fn call(self: *Self, function_symbol: *Symbol, retval_place: *lval_.L_Value, args_list: std.ArrayList(*lval_.L_Value)) error{CompileError}!void {
    self.call_depth += 1;
    // Save old stack pointer
    const old_sp = self.stack_pointer;
    self.stack_pointer = alignment_.next_alignment(self.stack_pointer, 8); // align stack pointer to 8 before pushing args

    // push args in reverse order
    var i: i64 = @as(i64, @intCast(args_list.items.len)) - 1;
    while (i >= 0) : (i -= 1) {
        const arg = args_list.items[@as(usize, @intCast(i))];
        const size = arg.get_expanded_type().sizeof();
        const alignof = arg.expanded_type_alignof();
        self.stack_pointer = alignment_.next_alignment(self.stack_pointer, alignof);
        try self.push_move(try self.effective_address(arg), size);
    }
    self.stack_pointer = alignment_.next_alignment(self.stack_pointer, 8);

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
inline fn ret(self: *Self) void {
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

pub fn alloc(self: *Self, nbytes: i64, align_to: i64) error{CompileError}!usize {
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
pub fn extract_ast(self: *Self, address: i64, _type: *ast_.AST, span: Span, module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set)) Error!*ast_.AST {
    // FIXME: High Cyclo
    std.debug.assert(address >= 0);
    switch (_type.*) {
        .identifier => return self.extract_identifier(address, _type, span, module_interned_strings),
        .addr_of => return ast_.AST.create_int(
            Token.init_simple("unsigned int"),
            self.memory.load_int(address, 8),
            self.allocator,
        ).assert_ast_valid(),
        .function => return self.extract_function(address),
        .unit_type => return ast_.AST.create_unit_value(_type.token(), self.allocator).assert_ast_valid(),
        .sum_type => return self.extract_sum_type(address, _type, span, module_interned_strings),
        .product => return self.extract_product_type(address, _type, span, module_interned_strings),
        .untagged_sum_type => {
            self.errors.add_error(errs_.Error{ .basic = .{
                .span = span,
                .msg = "comptime untagged sum values cannot propagate to runtime",
            } });
            return error.CompileError;
        },
        .annotation => return try self.extract_ast(address, _type.annotation.type, span, module_interned_strings),
        else => std.debug.panic("interpreter error: unimplemented extract_ast() for: AST.{s}\n", .{@tagName(_type.*)}),
    }
}

fn extract_identifier(self: *Self, address: i64, identifier_type: *ast_.AST, span: Span, module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set)) Error!*ast_.AST {
    const info = prelude_.info_from_name(identifier_type.token().data);
    if (info == null) {
        return try self.extract_ast(address, identifier_type.symbol().?.init_value.?, span, module_interned_strings);
    }
    switch (info.?.type_kind) {
        .type => {
            const stack_value = self.memory.load_unsigned_int(address, 8);
            if (stack_value == 0xAAAAAAAAAAAAAAAA) { // NOTE: This only works if the interpreter never overwrites this address...
                return prelude_.unit_type;
            } else {
                return @ptrFromInt(stack_value);
            }
        },
        .string => {
            const idx = self.memory.load(Interned_String_Set.String_Idx, address);
            const interned_strings = module_interned_strings.get(idx.module_uid);
            std.debug.assert(idx.module_uid == interned_strings.?.uid);
            const string = interned_strings.?.items()[idx.string_idx];
            return ast_.AST.create_string(Token.init_simple("\""), string, self.allocator);
        },
        .none => unreachable,
        .boolean => {
            const val = self.memory.load_int(address, info.?.size);
            if (val == 0) {
                return ast_.AST.create_false(Token.init_simple("false"), self.allocator).assert_ast_valid();
            } else {
                return ast_.AST.create_true(Token.init_simple("true"), self.allocator).assert_ast_valid();
            }
        },
        .signed_integer => {
            const retval = ast_.AST.create_int(
                Token.init_simple("signed int"),
                self.memory.load_int(address, info.?.size),
                self.allocator,
            ).assert_ast_valid();
            retval.set_represents(identifier_type);
            return retval;
        },
        .unsigned_integer => {
            const retval = ast_.AST.create_int(
                Token.init_simple("unsigned int"),
                self.memory.load_int(address, info.?.size),
                self.allocator,
            ).assert_ast_valid();
            retval.set_represents(identifier_type);
            return retval;
        },
        .floating_point => {
            const retval = ast_.AST.create_float(
                Token.init_simple("float"),
                self.memory.load_float(address, info.?.size),
                self.allocator,
            ).assert_ast_valid();
            retval.set_represents(identifier_type);
            return retval;
        },
    }
}

fn extract_function(self: *Self, address: i64) Error!*ast_.AST {
    const stack_value = @as(usize, @intCast(self.memory.load_int(address, 8)));
    if (stack_value == 0) {
        return prelude_.void_type;
    } else {
        const symbol: *Symbol = @ptrFromInt(stack_value);
        const ast = ast_.AST.create_pattern_symbol(
            Token.init_simple("function"),
            .@"fn",
            symbol.name,
            self.allocator,
        );
        ast.set_symbol(symbol);
        return ast.assert_ast_valid();
    }
}

fn extract_sum_type(self: *Self, address: i64, sum_type: *ast_.AST, span: Span, module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set)) Error!*ast_.AST {
    // self.print_memory(@intCast(address), @intCast(address + _type.sizeof()));
    var retval = ast_.AST.create_sum_value(sum_type.token(), self.allocator).assert_ast_valid();
    const tag = self.memory.load_int(address + sum_type.sizeof() - 8, 8);
    retval.set_pos(@as(usize, @intCast(tag)));
    retval.sum_value.base = sum_type;
    const proper_term: *ast_.AST = sum_type.children().items[@as(usize, @intCast(tag))];
    retval.sum_value.init = try self.extract_ast(address, proper_term, span, module_interned_strings);
    return retval;
}

fn extract_product_type(self: *Self, address: i64, product_type: *ast_.AST, span: Span, module_interned_strings: *const std.AutoArrayHashMap(u32, *Interned_String_Set)) Error!*ast_.AST {
    if (product_type.types_match(prelude_.string_type)) {
        return self.extract_ast(address, prelude_.string_type, span, module_interned_strings);
    }
    var value_terms = std.ArrayList(*ast_.AST).init(self.allocator);
    errdefer value_terms.deinit();
    for (0.., product_type.children().items) |i, term| {
        // std.debug.print("term:{}\n", .{i});
        const offset = product_type.product.get_offset(i, self.allocator);
        // std.debug.print("offset:{}\n", .{offset});
        const extracted_term = try self.extract_ast(address + offset, term, span, module_interned_strings);
        // std.debug.print("extracted_term:{}\n", .{extracted_term});
        value_terms.append(extracted_term) catch unreachable;
    }
    return ast_.AST.create_product(product_type.token(), value_terms, self.allocator).assert_ast_valid();
}

/// Prints the values of the interpreter's registers
fn print_registers(self: *Self) void {
    const module: ?*module_.Module = self.curr_module() catch null;
    std.debug.print("bp:0x{X} sp:0x{X} ip:[{s}#{}]@{X}\n", .{
        self.base_pointer,
        self.stack_pointer,
        if (module != null) module.?.name() else "?",
        self.instruction_pointer.module_uid,
        self.instruction_pointer.inst_idx,
    });
}

/// Prints the contents of the interpreter's stack. Used for debugging.
fn print_stack(self: *Self) void {
    self.memory.print_memory(0, @as(usize, @intCast(self.stack_pointer)));
}

fn print_debug_stack(self: *Self) void {
    for (0..self.debug_call_stack.items.len) |i| {
        const span = self.debug_call_stack.items[i];
        std.debug.print("{}: {s}\n", .{ i, span.line_text });
    }
    std.debug.print("\n", .{});
}

fn curr_instruction(self: *Self) error{CompileError}!*Instruction {
    const module = try self.curr_module();
    return module.instructions.items[@as(usize, @intCast(self.instruction_pointer.inst_idx))];
}

pub fn curr_module(self: *Self) error{CompileError}!*module_.Module {
    return self.modules.get(self.instruction_pointer.module_uid) orelse
        self.interpreter_panic("interpreter error: attempt to use module 0x{X}, which hasn't been loaded yet\n", .{self.instruction_pointer.module_uid});
}

/// Loads integer values from the specified L_Values and returns a structure containing both the loaded
/// values.
fn binop_load_int(self: *Self, src1: *lval_.L_Value, src2: *lval_.L_Value) !struct { src1: i128, src2: i128 } {
    return .{
        .src1 = self.memory.load_int(try self.effective_address(src1), src1.expanded_type_sizeof()),
        .src2 = self.memory.load_int(try self.effective_address(src2), src2.expanded_type_sizeof()),
    };
}

/// Loads floating-point values from the specified L_Values and returns a structure containing both the
/// loaded values.
fn binop_load_float(self: *Self, src1: *lval_.L_Value, src2: *lval_.L_Value) !struct { src1: f64, src2: f64 } {
    return .{
        .src1 = self.memory.load_float(try self.effective_address(src1), src1.expanded_type_sizeof()),
        .src2 = self.memory.load_float(try self.effective_address(src2), src2.expanded_type_sizeof()),
    };
}

/// Copies memory blocks referenced by a list of L_Values to the specified destination address in the
/// interpreter's memory.
fn move_lval_list(
    self: *Self,
    dest: i64,
    list: *std.ArrayList(*lval_.L_Value),
) !void {
    std.debug.assert(dest >= 0);
    var cursor = dest;
    for (list.items) |lval| {
        cursor = alignment_.next_alignment(cursor, lval.expanded_type_alignof());
        const src = try self.effective_address(lval);
        const len = lval.expanded_type_sizeof();
        // std.debug.print("dest:0x{X} src:0x{X} len:0x{X}\n", .{ cursor, src, len });
        // std.debug.print("{}\n", .{lval});
        self.memory.move(cursor, src, len);
        cursor += len;
    }
}

/// Gets the effective address of an lvalue in the interpreter's memory.
fn effective_address(self: *Self, lval: *lval_.L_Value) error{CompileError}!i64 {
    switch (lval.*) {
        .symbver => {
            if (std.mem.eql(u8, "$retval", lval.symbver.symbol.name)) {
                // Intercept stores to the return symbol of the form:
                //     retval := val
                // and replace with:
                //     retval^ := val
                return self.memory.load(i64, self.base_pointer + CFG.retval_offset);
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
        .dereference => return self.memory.load(i64, try self.effective_address(lval.dereference.expr)),
        .index => {
            const base = try self.effective_address(lval.index.lhs);
            const index = self.memory.load(i64, try self.effective_address(lval.index.rhs));
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
fn pop_int(self: *Self, int_size_bytes: i64) i128 {
    self.stack_pointer -= int_size_bytes;
    return self.memory.load_int(self.stack_pointer, int_size_bytes);
}

/// Pops a generic, compiler-comptime-known type from the stack
fn pop(self: *Self, comptime T: type) T {
    const t_size: usize = @sizeOf(T);
    self.stack_pointer -= t_size;
    return self.memory.load(T, self.stack_pointer);
}

/// Pushes an integer value onto the interpreter's stack.
fn push_int(self: *Self, size: i64, val: i128) error{CompileError}!void {
    try self.memory_check(size);
    self.memory.store_int(self.stack_pointer, size, val);
    self.stack_pointer += size;
}

/// Pushes a memory block of the specified size onto the interpreter's stack.
fn push_move(self: *Self, block_addr: i64, block_size: i64) error{CompileError}!void {
    try self.memory_check(block_size);
    self.memory.move(self.stack_pointer, block_addr, block_size);
    self.stack_pointer += block_size;
}

/// Pushes a generic, compiler-comptime-known type to the stack
fn push(self: *Self, comptime T: type, val: T) error{CompileError}!void {
    const t_size: usize = @sizeOf(T);
    try self.memory_check(t_size);
    self.memory.store(T, self.stack_pointer, val);
    self.stack_pointer += t_size;
}
/// Asserts that the provided `val` fits within the bounds specified by the data type `_type`.
/// Adds an error if the value is out of bounds.
fn assert_fits(self: *Self, val: i128, _type: *ast_.AST, operation_name: []const u8, span: Span) error{CompileError}!void {
    const bounds = prelude_.bounds_from_ast(_type) orelse return;
    if (val < bounds.lower or val > bounds.upper) {
        self.debug_call_stack.append(span) catch unreachable;
        return self.interpreter_panic("interpreter error: {s} is out of bounds; value={}\n", .{ operation_name, val });
    }
}

fn memory_check(self: *Self, space_needed: i64) error{CompileError}!void {
    if (self.bump_alloc_pointer -| self.stack_pointer < space_needed) {
        return self.interpreter_panic("interpreter error: out of memory!\n", .{});
    }
}

/// Signals an interpreter panic, printing an error message and call stack information.
fn interpreter_panic(self: *Self, comptime msg: []const u8, args: anytype) error{CompileError} {
    std.io.getStdOut().writer().print(msg, args) catch return error.CompileError;

    var i = self.debug_call_stack.items.len - 1;
    while (true) {
        const stack_span = self.debug_call_stack.items[i];
        stack_span.print_debug_line(std.io.getStdOut().writer(), Span.interpreter_format) catch return error.CompileError;

        if (i == 0) {
            break;
        } else {
            i -= 1;
        }
    }
    return error.CompileError;
}
