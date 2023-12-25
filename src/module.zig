const std = @import("std");
const ast_ = @import("ast.zig");
const basic_block_ = @import("basic-block.zig");
const cfg_ = @import("cfg.zig");
const codegen_ = @import("codegen.zig");
const decorate_ = @import("decorate.zig");
const errs_ = @import("errors.zig");
const expand_ = @import("expand.zig");
const ir_ = @import("ir.zig");
const layout_ = @import("layout.zig");
const lexer_ = @import("lexer.zig");
const lower_ = @import("lower.zig");
const offsets_ = @import("offsets.zig");
const optimizations_ = @import("optimizations.zig");
const parser_ = @import("parser.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");
const symbol_tree_ = @import("symbol-tree.zig");
const type_set_ = @import("type-set.zig");
const validate_ = @import("validate.zig");

var module_uids: usize = 0;
/// This structure represents a module being compiled.
pub const Module = struct {
    // A unique identifier for this Orng module
    uid: i128,

    // A graph of type dependencies
    type_set: type_set_.Type_Set,

    // Flat list of instructions
    instructions: std.ArrayList(*ir_.IR),

    // List of CFGs defined in this module
    cfgs: std.ArrayList(*cfg_.CFG),

    // Main function. TODO: Temporary
    entry: *cfg_.CFG,

    // Interned strings
    interned_strings: std.StringArrayHashMap(usize),

    // The root scope node for the module
    scope: *symbol_.Scope,

    // Allocator for the module
    allocator: std.mem.Allocator,

    fn init(scope: *symbol_.Scope, allocator: std.mem.Allocator) *Module {
        var retval = allocator.create(Module) catch unreachable;
        retval.uid = module_uids;
        module_uids += 1;
        retval.interned_strings = std.StringArrayHashMap(usize).init(allocator);
        retval.scope = scope;
        retval.allocator = allocator;
        retval.instructions = std.ArrayList(*ir_.IR).init(allocator);
        retval.cfgs = std.ArrayList(*cfg_.CFG).init(allocator);
        retval.type_set = type_set_.Type_Set.init(allocator);
        return retval;
    }

    pub fn compile(
        contents: []const u8,
        in_name: []const u8,
        prelude: *symbol_.Scope,
        fuzz_tokens: bool,
        errors: *errs_.Errors,
        allocator: std.mem.Allocator,
    ) !*Module {
        // Construct the name
        var i: usize = 0;
        while (i < in_name.len and in_name[i] != '.') : (i += 1) {}
        const name: []const u8 = in_name[0..i];

        // Tokenize, and also append lines to the list of lines
        var lines = std.ArrayList([]const u8).init(allocator);
        defer lines.deinit();
        try lexer_.getLines(contents, &lines, errors);
        var tokens = try lexer_.getTokens(&lines, in_name, errors, fuzz_tokens, allocator);
        defer tokens.deinit(); // Make copies of tokens, never take their address

        if (false and fuzz_tokens) { // print tokens before layout_
            for (tokens.items) |token| {
                std.debug.print("{s} ", .{token.data});
            }
            std.debug.print("\n", .{});
        }

        // Layout
        if (!fuzz_tokens) {
            layout_.doLayout(&tokens);
        }

        if (false) { // Print out tokens after layout_
            var indent: usize = 0;
            for (0..tokens.items.len - 1) |j| {
                var token = tokens.items[j];
                const next_token = tokens.items[j + 1];
                if (next_token.kind == .INDENT) {
                    indent += 1;
                }
                if (next_token.kind == .DEDENT) {
                    indent -= 1;
                }
                std.debug.print("{s} ", .{token.repr()});
                if (token.kind == .NEWLINE or token.kind == .INDENT or token.kind == .DEDENT) {
                    std.debug.print("\n", .{});
                    for (0..indent) |_| {
                        std.debug.print("    ", .{});
                    }
                }
            }
            std.debug.print("\n", .{});
        }

        // Parse, expand AST
        ast_.init_structures();
        var parser = parser_.Parser.init(&tokens, errors, allocator);
        const module_ast = try parser.parse();
        try expand_.expand_from_list(module_ast, errors, allocator);

        // Module/Symbol-Tree construction
        var file_root = symbol_.Scope.init(prelude, name, allocator);
        const module = Module.init(file_root, allocator);
        file_root.module = module;
        try symbol_tree_.symbolTableFromASTList(module_ast, file_root, errors, allocator);
        try decorate_.decorate_identifiers_from_list(module_ast, file_root, errors, allocator);

        // Validate the module
        try validate_.validate_module(module, errors, allocator);
        if (errors.errors_list.items.len > 0) {
            return error.typeError;
        }

        // Add each CFG's instructions to the module's instruction's list
        for (module.scope.symbols.keys()) |key| {
            const symbol: *symbol_.Symbol = module.scope.symbols.get(key).?;
            if (symbol.kind != ._fn) {
                continue;
            }
            // IR translation
            const cfg = try get_cfg(symbol, null, &module.interned_strings, errors, allocator);
            module.collect_cfgs(cfg);

            if (std.mem.eql(u8, key, "main")) {
                module.entry = cfg;
            }
        }

        // TODO: I don't think this works with addresses
        //     let const A = (x: &B, y: Int)
        //     let const B = (x: &A, y: Int)
        // The above should work
        for (module.cfgs.items) |cfg| {
            // Add parameter types to type set
            for (cfg.symbol.decl.?.fnDecl.param_symbols.items) |param| {
                _ = module.type_set.add(param.expanded_type.?, allocator);
            }

            for (cfg.basic_blocks.items) |bb| {
                var maybe_ir = bb.ir_head;
                while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                    if (ir.dest != null) {
                        _ = module.type_set.add(ir.dest.?.get_expanded_type(), allocator);
                    }
                }
            }
        }
        return module;
    }

    // This allows us to pick up anon and inner CFGs that wouldn't be exposed to the module's scope
    fn collect_cfgs(self: *Module, cfg: *cfg_.CFG) void {
        if (cfg.visited) {
            return;
        }
        cfg.visited = true;

        cfg.collect_generated_symbvers();
        _ = self.append_instructions(cfg);

        for (cfg.children.items) |child| {
            self.collect_cfgs(child);
        }
    }

    /// Takes in a statically correct symbol tree, writes it out to a file
    pub fn output(
        self: *Module,
        out_name: []const u8, // TODO: Replace with writer, shouldn't be responsible for handling files
    ) !void {
        // Open the output file
        var output_file = std.fs.cwd().createFile(
            out_name,
            .{ .read = false },
        ) catch |e| switch (e) {
            error.FileNotFound => {
                std.debug.print("Cannot create file: {s}\n", .{out_name});
                return error.IoError;
            },
            else => return error.IoError,
        };
        defer output_file.close();

        try codegen_.generate(self, output_file.writer());
    }

    /// Flattens all CFG's instructions to the module's list of instructions, recursively.
    ///
    /// This also then adds the CFG to the list of CFGs in this module.
    ///
    /// Also sets the `offset` flag of a CFG, which is the address in the instructions list that the
    /// instructions for the CFG start.
    ///
    /// Returns the index in the cfg in the cfgs list.
    pub fn append_instructions(self: *Module, cfg: *cfg_.CFG) i64 {
        const len = @as(i64, @intCast(self.cfgs.items.len));
        if (cfg.offset != null) {
            // Already visited, do nothing
            return len;
        } else if (cfg.block_graph_head == null) {
            // CFG doesn't have any real instructions. Insert phony BB.
            cfg.offset = self.append_phony_block(cfg);
            self.cfgs.append(cfg) catch unreachable;
        } else {
            // Normal CFG with instructions, append BBs to instructions list, recursively append children
            cfg.offset = self.append_basic_block(cfg.block_graph_head.?, cfg);
            self.cfgs.append(cfg) catch unreachable;

            for (cfg.children.items) |child| {
                _ = self.append_instructions(child);
            }
        }
        return len;
    }

    /// Appends the instructions in a BasicBlock to the module's instructions.
    /// Returns the offset of the basic block
    fn append_basic_block(self: *Module, first_bb: *basic_block_.Basic_Block, cfg: *cfg_.CFG) i64 {
        var work_queue = std.ArrayList(*basic_block_.Basic_Block).init(self.allocator);
        defer work_queue.deinit();
        work_queue.append(first_bb) catch unreachable;

        while (work_queue.items.len > 0) {
            var bb = work_queue.orderedRemove(0); // Youch! Does this really have to be ordered?

            if (bb.offset != null) {
                continue;
            }

            bb.offset = @as(i64, @intCast(self.instructions.items.len));
            var label = ir_.IR.initLabel(cfg, span_.Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator);
            label.uid = bb.uid;
            self.instructions.append(label) catch unreachable;

            var maybe_ir = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                self.instructions.append(ir) catch unreachable;
            }

            if (bb.has_branch) {
                if (bb.next) |next| {
                    work_queue.append(next) catch unreachable;
                }
                if (bb.branch) |branch| {
                    work_queue.append(branch) catch unreachable;
                }
                self.instructions.append(ir_.IR.init_branch_addr(
                    bb.condition.?,
                    bb.next,
                    bb.branch,
                    span_.Span{ .filename = "", .line_text = "", .line = 0, .col = 0 },
                    self.allocator,
                )) catch unreachable;
            } else {
                if (bb.next) |next| {
                    work_queue.append(next) catch unreachable;
                }
                self.instructions.append(ir_.IR.init_jump_addr(
                    bb.next,
                    span_.Span{ .filename = "", .line_text = "", .line = 0, .col = 0 },
                    self.allocator,
                )) catch unreachable;
            }
        }
        return first_bb.offset.?;
    }

    /// This function inserts a label and a return instruction. It is needed for functions which do not have
    /// instructions. The label is needed so that codegen_ can know there is a new function, and the return
    /// instruction is for interpreting so that jumping to the function won't jump to some random function.
    fn append_phony_block(self: *Module, cfg: *cfg_.CFG) i64 {
        const offset = @as(i64, @intCast(self.instructions.items.len));
        // Append a label which has a back-reference to the CFG
        self.instructions.append(ir_.IR.initLabel(
            cfg,
            span_.Span{ .filename = "", .line_text = "", .line = 0, .col = 0 },
            self.allocator,
        )) catch unreachable;
        // Append a return instruction (a jump to null)
        self.instructions.append(ir_.IR.init_jump_addr(
            null,
            span_.Span{ .filename = "", .line_text = "", .line = 0, .col = 0 },
            self.allocator,
        )) catch unreachable;
        return offset;
    }

    pub fn pop_cfg(self: *Module, idx: i64) void {
        _ = self.cfgs.orderedRemove(@as(usize, @intCast(idx)));
    }

    pub fn print_instructions(self: *Module) void {
        for (self.instructions.items) |ir| {
            std.debug.print("{}", .{ir});
        }
    }
};

pub fn get_cfg(
    symbol: *symbol_.Symbol,
    caller: ?*cfg_.CFG,
    interned_strings: *std.StringArrayHashMap(usize),
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !*cfg_.CFG {
    std.debug.assert(symbol.kind == ._fn or symbol.kind == ._comptime);
    std.debug.assert(symbol.validation_state == .valid);
    if (symbol.cfg == null) {
        symbol.cfg = try cfg_.CFG.init(symbol, caller, interned_strings, allocator);
        try lower_.lower_AST_into_cfg(symbol.cfg.?, errors, allocator);
        try optimizations_.optimize(symbol.cfg.?, errors, allocator);
        symbol.cfg.?.collect_generated_symbvers();
        symbol.cfg.?.locals_size = offsets_.calculate_offsets(symbol);
    }
    return symbol.cfg.?;
}

pub fn interned_string_set_add(str: []const u8, set: *std.ArrayList([]const u8)) void {
    for (set.items) |item| {
        if (std.mem.eql(u8, item, str)) {
            return;
        }
    }
    // sanitized_str must not be in set, add it
    set.append(str) catch unreachable;
}
