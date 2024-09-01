const std = @import("std");
const ast_validate_ = @import("ast-validate.zig");
const ast_ = @import("ast.zig");
const basic_block_ = @import("basic-block.zig");
const cfg_ = @import("cfg.zig");
const codegen_ = @import("codegen.zig");
const decorate_ = @import("decorate.zig");
const errs_ = @import("errors.zig");
const expand_ = @import("expand.zig");
const ir_validate_ = @import("ir-validate.zig");
const ir_ = @import("ir.zig");
const layout_ = @import("layout.zig");
const lines_ = @import("lines.zig");
const lexer_ = @import("lexer.zig");
const lower_ = @import("lower.zig");
const offsets_ = @import("offsets.zig");
const optimizations_ = @import("optimizations.zig");
const parser_ = @import("parser.zig");
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");
const symbol_tree_ = @import("symbol-tree.zig");
const token_ = @import("token.zig");
const type_set_ = @import("type-set.zig");

const Module_Errors = error{
    LexerError,
    ParseError,
    NotCompileTimeKnown,
    InvalidCharacter,
    Overflow,
    SymbolError,
    TypeError,
    IRError,
    DivideByZero,
    NotAnLValue,
    InterpreterPanic,
};

const Writer = std.fs.File.Writer;

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

    // List of all traits defined in this module
    traits: std.ArrayList(*ast_.AST),

    // List of all impls defined in this module
    impls: std.ArrayList(*ast_.AST),

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
        retval.traits = std.ArrayList(*ast_.AST).init(allocator);
        retval.impls = std.ArrayList(*ast_.AST).init(allocator);
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
    ) Module_Errors!*Module {
        // Construct the name
        var i: usize = 0;
        while (i < in_name.len and in_name[i] != '.') : (i += 1) {}
        const name: []const u8 = in_name[0..i];

        // Tokenize, and also append lines to the list of lines
        var lines = std.ArrayList([]const u8).init(allocator);
        defer lines.deinit();
        try lines_.get_lines(contents, &lines, errors);
        var scanner = lexer_.Scanner.init(&lines, in_name, errors, fuzz_tokens, allocator);
        var tokens = try scanner.get_tokens();
        defer tokens.deinit(); // Make copies of tokens, never take their address

        if (false and fuzz_tokens) { // print tokens before layout_
            for (tokens.items) |token| {
                std.debug.print("{s} ", .{token.data});
            }
            std.debug.print("\n", .{});
        }

        // Layout
        if (!fuzz_tokens) {
            layout_.do_layout(&tokens);
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
        try symbol_tree_.symbol_table_from_AST_list(module_ast, file_root, errors, allocator);
        try decorate_.decorate_identifiers_from_list(module_ast, file_root, errors, allocator);

        // Validate the module
        try ast_validate_.validate_module(module, errors, allocator);
        if (errors.errors_list.items.len > 0) {
            return error.TypeError;
        }

        module.collect_traits_and_impls(module.scope);

        // Add each CFG's instructions to the module's instruction's list
        for (module.scope.symbols.keys()) |key| {
            const symbol: *symbol_.Symbol = module.scope.symbols.get(key).?;
            if (symbol.kind != .@"fn") {
                continue;
            }
            // IR translation
            const cfg = try get_cfg(symbol, null, &module.interned_strings, errors, allocator);
            module.collect_cfgs(cfg);

            if (std.mem.eql(u8, key, "main")) {
                module.entry = cfg;
                module.entry.needed_at_runtime = true;
            }
        }

        // Go through traits
        for (module.traits.items) |trait| {
            for (trait.children().items) |decl| {
                _ = module.type_set.add(decl.method_decl.c_type.?, allocator);
            }
        }

        // Go through impls
        for (module.impls.items) |impl| {
            for (impl.children().items) |def| {
                const symbol = def.symbol().?;
                const cfg = try get_cfg(symbol, null, &module.interned_strings, errors, allocator);
                module.collect_cfgs(cfg);
                cfg.needed_at_runtime = true;
            }
        }

        // Go through each cfg, collect types
        for (module.cfgs.items) |cfg| {
            // Add parameter types to type set
            const decl = cfg.symbol.decl.?;
            const param_symbols = if (decl.* == .fn_decl) decl.fn_decl.param_symbols else decl.method_decl.param_symbols;
            for (param_symbols.items) |param| {
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

    /// This allows us to pick up anon and inner CFGs that wouldn't be exposed to the module's scope
    fn collect_cfgs(self: *Module, cfg: *cfg_.CFG) void {
        if (cfg.visited) {
            return;
        }
        cfg.visited = true;

        cfg.collect_generated_symbvers();
        _ = self.emplace_cfg(cfg);

        for (cfg.children.items) |child| {
            self.collect_cfgs(child);
        }
    }

    /// Collects traits and implementations from the specified scope and its children, appending them to the module's traits and impls
    /// lists.
    fn collect_traits_and_impls(self: *Module, scope: *symbol_.Scope) void {
        self.traits.appendSlice(scope.traits.items) catch unreachable;
        self.impls.appendSlice(scope.impls.items) catch unreachable;

        for (scope.children.items) |child| {
            self.collect_traits_and_impls(child);
        }
    }

    /// Takes in a statically correct symbol tree, writes it out to a file
    pub fn output(self: *Module, writer: Writer) codegen_.CodeGen_Error!void {
        try codegen_.generate(self, writer);
    }

    /// Flattens all CFG's instructions to the module's list of instructions, recursively.
    ///
    /// This also then adds the CFG to the list of CFGs in this module.
    ///
    /// Also sets the `offset` flag of a CFG, which is the address in the instructions list that the
    /// instructions for the CFG start.
    ///
    /// Returns the index in the cfg in the cfgs list.
    pub fn emplace_cfg(self: *Module, cfg: *cfg_.CFG) i64 {
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
                _ = self.emplace_cfg(child);
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
            var label = ir_.IR.init_label(cfg, span_.phony_span, self.allocator);
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
                    span_.phony_span,
                    self.allocator,
                )) catch unreachable;
            } else {
                if (bb.next) |next| {
                    work_queue.append(next) catch unreachable;
                }
                self.instructions.append(ir_.IR.init_jump_addr(
                    bb.next,
                    span_.phony_span,
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
        self.instructions.append(ir_.IR.init_label(
            cfg,
            span_.phony_span,
            self.allocator,
        )) catch unreachable;
        // Append a return instruction (a jump to null)
        self.instructions.append(ir_.IR.init_jump_addr(
            null,
            span_.phony_span,
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
) lower_.Lower_Errors!*cfg_.CFG {
    std.debug.assert(symbol.kind == .@"fn" or symbol.kind == .@"comptime");
    std.debug.assert(symbol.validation_state == .valid);
    if (symbol.cfg == null) {
        symbol.cfg = cfg_.CFG.init(symbol, caller, interned_strings, allocator);
        try lower_.lower_AST_into_cfg(symbol.cfg.?, errors, allocator);
        try ir_validate_.validate_cfg(symbol.cfg.?, errors);
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

/// Stamps out a new function declaration along with a fully built and validated symbol tree, and decorated identifiers.
///
/// ## Returns:
/// An identifier AST, decorated with the stamped out anonymous function.
pub fn stamp(
    template_ast: *ast_.AST,
    args: *std.ArrayList(*ast_.AST),
    scope: *symbol_.Scope,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !*ast_.AST {
    if (template_ast.template.memo == null) {
        // Clone out a new fn decl AST, with a new name
        const fn_decl = template_ast.template.decl.clone(allocator);
        fn_decl.fn_decl.remove_const_params();
        fn_decl.fn_decl.name = null; // make function anonymous

        // Create a new symbol and scope for the new fn decl
        const fn_symbol = try symbol_tree_.create_function_symbol(
            fn_decl,
            scope,
            errors,
            allocator,
        );
        try symbol_tree_.put_symbol(fn_symbol, fn_symbol.scope, errors);
        fn_decl.set_symbol(fn_symbol);

        const domain = symbol_tree_.extract_domain(template_ast.template.decl.children().*, allocator);
        args.* = try ast_validate_.default_args(args.*, domain, errors, allocator);

        // Go through each comptime arg, evaluate it, and store it in a list along with it's position
        // Combines the arg value and the position in the args/params list
        var const_decls = std.ArrayList(*ast_.AST).init(allocator);
        defer const_decls.deinit();
        for (template_ast.template.decl.fn_decl._params.items, args.items) |param, arg| {
            if (param.decl.pattern.pattern_symbol.kind == .@"const") {
                const decl = ast_.AST.create_decl(
                    param.token(),
                    param.decl.pattern,
                    param.decl.type,
                    arg, // TODO: Comptime eval this
                    true,
                    allocator,
                );
                const_decls.append(decl) catch unreachable;
            }
        }

        // Define each constant parameter in the fn decl's scope
        try symbol_tree_.symbol_table_from_AST_list(const_decls, scope, errors, allocator);

        // Decorate identifiers, validate
        for (const_decls.items) |decl| {
            try decorate_.decorate_identifiers(decl, scope, errors, allocator);
        }
        try decorate_.decorate_identifiers(fn_decl, scope, errors, allocator);
        try ast_validate_.validate_scope(fn_symbol.scope, errors, allocator);

        // Memoize symbol
        template_ast.template.memo = fn_symbol;
    }

    const identifier = ast_.AST.create_identifier(token_.Token.init_simple(template_ast.template.memo.?.name), allocator);
    identifier.set_symbol(template_ast.template.memo);
    return identifier;
}
