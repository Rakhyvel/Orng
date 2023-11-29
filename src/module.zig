const ast_ = @import("ast.zig");
const codegen = @import("codegen.zig");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const layout = @import("layout.zig");
const lexer = @import("lexer.zig");
const Parser = @import("parser.zig").Parser;
const std = @import("std");
const symbol_ = @import("symbol.zig");
const Span = @import("span.zig").Span;
const validate_ = @import("validate.zig");

const AST = ast_.AST;
const CFG = ir_.CFG;
const Scope = symbol_.Scope;

pub const DAG = struct {
    base: *AST,
    uid: usize,
    dependencies: std.ArrayList(*DAG),
    visited: bool,

    fn init(base: *AST, uid: usize, allocator: std.mem.Allocator) !*DAG {
        var retval = try allocator.create(DAG);
        retval.base = base;
        retval.uid = uid;
        retval.dependencies = std.ArrayList(*DAG).init(allocator);
        retval.visited = false;
        return retval;
    }
};

var module_uids: usize = 0;
/// This structure represents a module being compiled.
pub const Module = struct {
    // A unique identifier for this Orng module
    uid: i128,

    // A graph of type dependencies
    types: std.ArrayList(*DAG),

    // Flat list of instructions
    instructions: std.ArrayList(*ir_.IR),

    // List of CFGs defined in this module
    cfgs: std.ArrayList(*ir_.CFG),

    // Main function. TODO: Temporary
    entry: *ir_.CFG,

    // Interned strings
    interned_strings: std.ArrayList([]const u8),

    // The root scope node for the module
    scope: *Scope,

    // Errors, used as context
    errors: *errs.Errors,

    // Allocator for the module
    allocator: std.mem.Allocator,

    fn init(scope: *Scope, errors: *errs.Errors, allocator: std.mem.Allocator) !*Module {
        var retval = try allocator.create(Module);
        retval.uid = module_uids;
        module_uids += 1;
        retval.interned_strings = std.ArrayList([]const u8).init(allocator);
        retval.scope = scope;
        retval.errors = errors;
        retval.allocator = allocator;
        retval.instructions = std.ArrayList(*ir_.IR).init(allocator);
        retval.cfgs = std.ArrayList(*ir_.CFG).init(allocator);
        retval.types = std.ArrayList(*DAG).init(allocator);
        return retval;
    }

    pub fn compile(
        contents: []const u8,
        in_name: []const u8,
        prelude: *symbol_.Scope,
        fuzz_tokens: bool,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) !*Module {
        // Construct the name
        var i: usize = 0;
        while (i < in_name.len and in_name[i] != '.') : (i += 1) {}
        const name: []const u8 = in_name[0..i];

        // Tokenize, and also append lines to the list of lines
        var lines = std.ArrayList([]const u8).init(allocator);
        defer lines.deinit();
        try lexer.getLines(contents, &lines, errors);
        var tokens = try lexer.getTokens(&lines, in_name, errors, fuzz_tokens, allocator);
        defer tokens.deinit(); // Make copies of tokens, never take their address

        if (false and fuzz_tokens) { // print tokens before layout
            for (tokens.items) |token| {
                std.debug.print("{s} ", .{token.data});
            }
            std.debug.print("\n", .{});
        }

        // Layout
        if (!fuzz_tokens) {
            try layout.doLayout(&tokens);
        }

        if (false) { // Print out tokens after layout
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

        // Parse
        try ast_.init_structures();
        var parser = try Parser.create(&tokens, errors, allocator);
        const module_ast = try parser.parse();

        // Module/Symbol-Tree construction
        var file_root = try symbol_.Scope.init(prelude, name, allocator);
        const module = try Module.init(file_root, errors, allocator);
        file_root.module = module;
        try symbol_.symbolTableFromASTList(module_ast, file_root, errors, allocator);

        // Typecheck
        try validate_.validate_module(module, errors, allocator);
        if (errors.errors_list.items.len > 0) {
            return error.typeError;
        }

        for (module.scope.symbols.keys()) |key| {
            var symbol: *symbol_.Symbol = module.scope.symbols.get(key).?;
            if (symbol.kind != ._fn) {
                continue;
            }
            // IR translation
            const cfg = try symbol.get_cfg(null, &module.interned_strings, errors, allocator);
            try module.collect_cfgs(cfg);

            if (std.mem.eql(u8, key, "main")) {
                module.entry = cfg;
            }
        }

        for (module.cfgs.items) |cfg| {
            try collect_types(cfg, &module.types, allocator);
        }
        return module;
    }

    // This allows us to pick up anon and inner CFGs that wouldn't be exposed to the module's scope
    fn collect_cfgs(self: *Module, cfg: *CFG) !void {
        if (cfg.visited) {
            return;
        }
        cfg.visited = true;

        try cfg.collect_generated_symbvers();
        _ = try self.append_instructions(cfg);

        for (cfg.children.items) |child| {
            try self.collect_cfgs(child);
        }
    }

    /// Takes in a statically correct symbol tree, writes it out to a file
    pub fn output(
        self: *Module,
        out_name: []const u8, // TODO: Replace with writer, shouldn't be responsible for handling files
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) !void {
        _ = allocator;
        _ = errors;

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

        try codegen.generate(self, output_file.writer());
    }

    /// Flattens all CFG's instructions to the module's list of instructions, recursively.
    ///
    /// This also then adds the CFG to the list of CFGs in this module.
    ///
    /// Also sets the `offset` flag of a CFG, which is the address in the instructions list that the
    /// instructions for the CFG start.
    ///
    /// Returns the index in the cfg in the cfgs list.
    pub fn append_instructions(self: *Module, cfg: *CFG) !usize {
        const len = self.cfgs.items.len;
        if (cfg.offset != null) {
            // Already visited, do nothing
            return len;
        } else if (cfg.block_graph_head == null) {
            // CFG doesn't have any real instructions. Insert phony BB.
            cfg.offset = try self.append_phony_block();
            try self.cfgs.append(cfg);
        } else {
            // Normal CFG with instructions, append BBs to instructions list, recursively append children
            cfg.offset = try self.append_basic_block(cfg.block_graph_head.?);
            try self.cfgs.append(cfg);

            for (cfg.children.items) |child| {
                _ = try self.append_instructions(child);
            }
        }
        return len;
    }

    /// Appends the instructions in a BasicBlock to the module's instructions.
    /// Returns the offset of the basic block
    fn append_basic_block(self: *Module, first_bb: *ir_.BasicBlock) !i128 {
        var work_queue = std.ArrayList(*ir_.BasicBlock).init(self.allocator);
        defer work_queue.deinit();
        try work_queue.append(first_bb);

        while (work_queue.items.len > 0) {
            var bb = work_queue.orderedRemove(0); // Youch! Does this really have to be ordered?

            if (bb.offset != null) {
                continue;
            }

            bb.offset = self.instructions.items.len;
            var label = try ir_.IR.createLabel(bb.uid, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator);
            label.uid = bb.uid;
            try self.instructions.append(label);

            var maybe_ir = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                try self.instructions.append(ir);
            }

            if (bb.has_branch) {
                if (bb.next) |next| {
                    try work_queue.append(next);
                }
                if (bb.branch) |branch| {
                    try work_queue.append(branch);
                }
                try self.instructions.append(try ir_.IR.create_branch_addr(bb.condition.?, bb.next, bb.branch, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator));
            } else {
                if (bb.next) |next| {
                    try work_queue.append(next);
                }
                try self.instructions.append(try ir_.IR.create_jump_addr(bb.next, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator));
            }
        }
        return first_bb.offset.?;
    }

    /// This function inserts a label and a return instruction. It is needed for functions which do not have
    /// instructions. The label is needed so that codegen can know there is a new function, and the return
    /// instruction is for interpreting so that jumping to the function won't jump to some random function.
    fn append_phony_block(self: *Module) !i128 {
        const offset = self.instructions.items.len;
        try self.instructions.append(try ir_.IR.createLabel(0, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator));
        try self.instructions.append(try ir_.IR.create_jump_addr(null, Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, self.allocator));
        return offset;
    }

    pub fn pop_cfg(self: *Module, idx: usize) void {
        _ = self.cfgs.orderedRemove(idx);
    }

    pub fn print_instructions(self: *Module) void {
        for (self.instructions.items) |ir| {
            std.debug.print("{}", .{ir});
        }
    }
};

// TODO: I don't think this works with addresses
//     let const A = (x: &B, y: Int)
//     let const B = (x: &A, y: Int)
// The above should work
fn collect_types(cfg: *CFG, set: *std.ArrayList(*DAG), allocator: std.mem.Allocator) !void {
    // Add parameter types to type set
    if (cfg.symbol._type.?.function.lhs.* == .product) {
        // Function has more than one parameter, add types of product terms
        for (cfg.symbol._type.?.function.lhs.product.terms.items) |param_type| {
            _ = try type_set_append(param_type, set, allocator);
        }
    } else {
        // Function has one parameter, add it's type
        _ = try type_set_append(cfg.symbol._type.?.function.lhs, set, allocator);
    }

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null) {
                _ = try type_set_append(ir.dest.?.get_expanded_type(), set, allocator);
            }
        }
    }
}

fn type_set_append(oldast_: *AST, set: *std.ArrayList(*DAG), allocator: std.mem.Allocator) !?*DAG {
    const ast = oldast_;
    if (type_set_get(ast, set)) |dag| {
        // Type is already in the set, return DAG entry for it
        return dag;
    } else if (ast.* == .function) {
        var dag = try DAG.init(ast, set.items.len, allocator);
        try set.append(dag);
        if (try type_set_append(ast.function.lhs, set, allocator)) |domain| {
            try dag.dependencies.append(domain);
        }
        if (try type_set_append(ast.function.rhs, set, allocator)) |codomain| {
            try dag.dependencies.append(codomain);
        }
        return dag;
    } else if (ast.* == .product) {
        var dag = try DAG.init(ast, set.items.len, allocator);
        try set.append(dag);
        for (ast.product.terms.items) |term| {
            if (try type_set_append(term, set, allocator)) |dependency| {
                try dag.dependencies.append(dependency);
            }
        }
        return dag;
    } else if (ast.* == .sum) {
        var dag = try DAG.init(ast, set.items.len, allocator);
        try set.append(dag);
        for (ast.sum.terms.items) |term| {
            if (try type_set_append(term, set, allocator)) |dependency| {
                try dag.dependencies.append(dependency);
            }
        }
        return dag;
    } else if (ast.* == .annotation) {
        return try type_set_append(ast.annotation.type, set, allocator);
    } else if (ast.* == .addrOf) {
        return try type_set_append(ast.addrOf.expr, set, allocator);
    } else {
        return null;
    }
}

pub fn type_set_get(oldast_: *AST, set: *std.ArrayList(*DAG)) ?*DAG {
    const ast = oldast_;
    for (set.items) |dag| {
        if (dag.base.c_typesMatch(ast)) {
            return dag;
        }
    }
    return null;
}

pub fn interned_string_set_add(str: []const u8, set: *std.ArrayList([]const u8)) !void {
    for (set.items) |item| {
        if (std.mem.eql(u8, item, str)) {
            return;
        }
    }
    // sanitized_str must not be in set, add it
    try set.append(str);
}
