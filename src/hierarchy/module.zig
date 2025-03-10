const std = @import("std");
const ast_validate_ = @import("../semantic/ast-validate.zig");
const ast_ = @import("../ast/ast.zig");
const basic_block_ = @import("../ir/basic-block.zig");
const cfg_ = @import("../ir/cfg.zig");
const codegen_ = @import("../codegen/codegen.zig");
const compiler_ = @import("../compilation/compiler.zig");
const errs_ = @import("../util/errors.zig");
const interpreter_ = @import("../interpretation/interpreter.zig");
const ir_validate_ = @import("../semantic/ir-validate.zig");
const ir_ = @import("../ir/instruction.zig");
const lower_ = @import("../ir/lower.zig");
const offsets_ = @import("../hierarchy/offsets.zig");
const optimizations_ = @import("../ir/optimizations.zig");
const pipeline_ = @import("../util/pipeline.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const span_ = @import("../util/span.zig");
const String = @import("../zig-string/zig-string.zig").String;
const symbol_ = @import("../symbol/symbol.zig");
const token_ = @import("../lexer/token.zig");
const type_set_ = @import("../ast/type-set.zig");
const walker_ = @import("../ast/walker.zig");

// Front-end pipeline steps
const Read_File = @import("../lexer/read_file.zig");
const Split_Lines = @import("../lexer/split_lines.zig");
const Tokenize = @import("../lexer/tokenize.zig");
const Apply_Layout = @import("../lexer/apply_layout.zig");
const Parse = @import("../parser/parse.zig");
const Apply_Ast_Walk = @import("../ast/walker.zig").Apply_Ast_Walk;
const Apply_Flat_Ast_Walk = @import("../ast/walker.zig").Apply_Flat_Ast_Walk;

// AST walks
const Expand = @import("../ast/expand.zig");
const Import = @import("../ast/import.zig");
const Cinclude = @import("../ast/cinclude.zig");
const Symbol_Tree = @import("../ast/symbol-tree.zig");
const Decorate = @import("../ast/decorate.zig");
const Decorate_Access = @import("../ast/decorate-access.zig");

pub const Module_Errors = error{ LexerError, ParseError, CompileError, FileNotFound };
pub const Module_UID: type = u32;
const Writer = std.fs.File.Writer;

var module_uids: Module_UID = 0;

/// This structure represents a module being compiled. Each module corresponds to a single .c/.h pair. A program has
/// many modules.
///
/// Each module has a list of instructions, and a table of symbols/cfgs that refer to their corresponding instructions.
pub const Module = struct {
    // A unique identifier for this Orng module
    uid: Module_UID,

    // Name of the module
    name: []const u8,

    // Absolute path of the module
    absolute_path: []const u8,

    // The name of the package this module belongs to
    package_name: []const u8,

    // List of local modules that are imported
    local_imported_modules: std.AutoArrayHashMap(*Module, void),

    // Set of C headers to include
    cincludes: std.ArrayList(*ast_.AST),

    // A graph of type dependencies
    type_set: type_set_.Type_Set,

    // List of instructions for this module
    instructions: std.ArrayList(*ir_.Instruction),

    // List of CFGs defined in this module
    cfgs: std.ArrayList(*cfg_.CFG),

    // Main function.
    entry: ?*cfg_.CFG,

    // List of all traits defined in this module
    traits: std.ArrayList(*ast_.AST),

    // List of all impls defined in this module
    impls: std.ArrayList(*ast_.AST),

    // Interned strings
    interned_strings: std.ArrayList([]const u8),

    // The symbol that represents this module
    symbol: *symbol_.Symbol,

    // Whether or not this module has been visited in a graph traversal
    visited: bool,

    // Allocator for the module
    allocator: std.mem.Allocator,

    pub fn init(name: []const u8, absolute_path: []const u8, symbol: *symbol_.Symbol, allocator: std.mem.Allocator) *Module {
        var retval = allocator.create(Module) catch unreachable;
        retval.uid = module_uids;
        module_uids += 1;
        retval.name = name;
        std.debug.assert(std.fs.path.isAbsolute(absolute_path));
        retval.absolute_path = absolute_path;
        retval.package_name = std.fs.path.basename(std.fs.path.dirname(absolute_path).?);
        retval.interned_strings = std.ArrayList([]const u8).init(allocator);
        retval.symbol = symbol;
        retval.allocator = allocator;
        retval.local_imported_modules = std.AutoArrayHashMap(*Module, void).init(allocator);
        retval.cincludes = std.ArrayList(*ast_.AST).init(allocator);
        retval.instructions = std.ArrayList(*ir_.Instruction).init(allocator);
        retval.traits = std.ArrayList(*ast_.AST).init(allocator);
        retval.impls = std.ArrayList(*ast_.AST).init(allocator);
        retval.cfgs = std.ArrayList(*cfg_.CFG).init(allocator);
        retval.type_set = type_set_.Type_Set.init(allocator);
        retval.visited = false;
        retval.entry = null;
        return retval;
    }

    // TODO: Move to compiler context
    pub fn compile(
        in_name: []const u8,
        entry_name: ?[]const u8,
        fuzz_tokens: bool,
        compiler: *compiler_.Context,
    ) Module_Errors!*Module {
        // Construct the name
        var i: usize = 0;
        while (i < in_name.len and in_name[i] != '.') : (i += 1) {}
        const full_name: []const u8 = in_name[0..i];
        i = full_name.len - 1;
        while (i >= 1 and full_name[i] != std.fs.path.sep) : (i -= 1) {}
        const short_name: []const u8 = full_name[i + 1 ..];

        if (!module_name_is_good(short_name)) {
            compiler.errors.add_error(errs_.Error{ .symbol_error = .{
                .problem = "has an improper module name",
                .span = span_.Span{ .filename = in_name, .col = 0, .line_number = 0, .line_text = "" },
                .name = short_name,
            } });
        }

        // Create the symbol for this module
        var file_root = symbol_.Scope.init(compiler.prelude, full_name, compiler.allocator());
        var module = Module.init(short_name, in_name, undefined, compiler.allocator());
        file_root.module = module;
        const symbol = symbol_.Symbol.init(
            compiler.prelude,
            short_name,
            span_.Span{ .col = 1, .line_number = 1, .filename = in_name, .line_text = "" },
            primitives_.unit_type,
            ast_.AST.create_module(
                token_.Token.init_simple(short_name),
                file_root,
                module,
                compiler.allocator(),
            ),
            null,
            .module,
            compiler.allocator(),
        );
        module.symbol = symbol;
        try Symbol_Tree.put_symbol(symbol, compiler.prelude, &compiler.errors);
        file_root.module = module;

        try fill_contents(in_name, entry_name, file_root, module, fuzz_tokens, compiler);
        // module.top_level_scope().pprint();

        return module;
    }

    fn module_name_is_good(module_name: []const u8) bool {
        if (module_name.len == 0) {
            return false;
        }
        if (!std.ascii.isLower(module_name[0])) {
            return false;
        }
        for (module_name) |c| {
            if (!std.ascii.isAlphanumeric(c) and c != '_') {
                return false;
            }
        }
        return true;
    }

    pub fn fill_contents(
        in_name: []const u8,
        entry_name: ?[]const u8,
        file_root: *symbol_.Scope,
        module: *Module,
        fuzz_tokens: bool,
        compiler: *compiler_.Context,
    ) Module_Errors!void {
        // Setup and run the front-end pipeline
        _ = try pipeline_.run(in_name, .{
            Read_File.init(compiler.allocator()),
            Split_Lines.init(&compiler.errors, compiler.allocator()),
            Tokenize.init(in_name, &compiler.errors, fuzz_tokens, compiler.allocator()),
            Apply_Layout.init(),
            Parse.init(&compiler.errors, compiler.allocator()),
            Apply_Ast_Walk(Expand).init(Expand.new(&compiler.errors, compiler.allocator())),
            Apply_Flat_Ast_Walk(Import).init(Import.new(compiler, module)),
            Apply_Flat_Ast_Walk(Cinclude).init(Cinclude.new(module)),
            Apply_Ast_Walk(Symbol_Tree).init(Symbol_Tree.new(file_root, &compiler.errors, compiler.allocator())),
            Apply_Ast_Walk(Decorate).init(Decorate.new(file_root, &compiler.errors, compiler.allocator())),
            Apply_Ast_Walk(Decorate_Access).init(Decorate_Access.new(file_root, &compiler.errors, compiler)),
        });
        // Perform checks and collections on the module
        try ast_validate_.validate_module(module, compiler);
        module.collect_traits_and_impls(module.top_level_scope());
        try module.add_all_cfgs(entry_name, compiler);
        try module.collect_impl_cfgs(compiler);
        module.collect_trait_types(compiler.allocator());
        module.collect_cfg_types(compiler.allocator());
    }

    fn add_all_cfgs(self: *Module, entry_name: ?[]const u8, compiler: *compiler_.Context) Module_Errors!void {
        var found_entry = false;
        const need_entry = entry_name != null;
        for (self.top_level_scope().symbols.keys()) |key| {
            const symbol: *symbol_.Symbol = self.top_level_scope().symbols.get(key).?;
            if (symbol.kind != .@"fn") {
                continue;
            }
            // Instruction translation
            const cfg = try get_cfg(symbol, null, &compiler.errors, compiler.allocator());
            self.collect_cfgs(cfg);

            if (need_entry and std.mem.eql(u8, key, entry_name.?)) {
                self.entry = cfg;
                self.entry.?.needed_at_runtime = true;
                found_entry = true;
            }
        }
        if (need_entry and !found_entry) {
            compiler.errors.add_error(errs_.Error{ .basic = .{
                .span = span_.phony_span,
                .msg = "no main function found",
            } });
            // Cannot find main function, fatal, do not procede
            return error.CompileError;
        }
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

    fn collect_trait_types(self: *Module, allocator: std.mem.Allocator) void {
        for (self.traits.items) |trait| {
            for (trait.trait.method_decls.items) |decl| {
                _ = self.type_set.add(decl.method_decl.c_type.?, allocator);
            }
        }
    }

    fn collect_impl_cfgs(self: *Module, compiler: *compiler_.Context) Module_Errors!void {
        for (self.impls.items) |impl| {
            for (impl.impl.method_defs.items) |def| {
                const symbol = def.symbol().?;
                const cfg = try get_cfg(symbol, null, &compiler.errors, compiler.allocator());
                self.collect_cfgs(cfg);
                cfg.needed_at_runtime = true;
            }
        }
    }

    fn collect_cfg_types(self: *Module, allocator: std.mem.Allocator) void {
        for (self.cfgs.items) |cfg| {
            // Add parameter types to type set
            const decl = cfg.symbol.decl.?;
            const param_symbols = if (decl.* == .fn_decl) decl.fn_decl.param_symbols else decl.method_decl.param_symbols;
            for (param_symbols.items) |param| {
                _ = self.type_set.add(param.expanded_type.?, allocator);
            }

            for (cfg.basic_blocks.items) |bb| {
                var maybe_instr = bb.instr_head;
                while (maybe_instr) |instr| : (maybe_instr = instr.next) {
                    if (instr.dest != null) {
                        _ = self.type_set.add(instr.dest.?.get_expanded_type(), allocator);
                        _ = self.type_set.add(instr.dest.?.extract_symbver().symbol.expanded_type.?, allocator);
                    }
                }
            }
        }
    }

    /// Takes in a statically correct symbol tree, writes it out to a file
    pub fn output(self: *Module, build_path: []const u8, local_modules: *std.ArrayList(*Module), allocator: std.mem.Allocator) !void {
        if (self.visited) {
            return;
        }
        self.visited = true;

        local_modules.append(self) catch unreachable;

        var output_c_filename = String.init(allocator);
        defer output_c_filename.deinit();
        var output_h_filename = String.init(allocator);
        defer output_h_filename.deinit();
        output_c_filename.writer().print("{s}-{s}.c", .{ self.package_name, self.name }) catch unreachable;
        output_h_filename.writer().print("{s}-{s}.h", .{ self.package_name, self.name }) catch unreachable;
        const out_c_paths = [_][]const u8{ build_path, output_c_filename.str() };
        const out_h_paths = [_][]const u8{ build_path, output_h_filename.str() };
        const out_c_path = std.fs.path.join(allocator, &out_c_paths) catch unreachable;
        const out_h_path = std.fs.path.join(allocator, &out_h_paths) catch unreachable;

        var output_c_file = std.fs.createFileAbsolute(out_c_path, .{}) catch unreachable;
        defer output_c_file.close();
        var output_h_file = std.fs.createFileAbsolute(out_h_path, .{}) catch unreachable;
        defer output_h_file.close();

        codegen_.generate(self, output_c_file.writer(), output_h_file.writer()) catch unreachable;

        for (self.local_imported_modules.keys()) |child| {
            if (std.mem.eql(u8, child.package_name, self.package_name)) {
                try child.output(build_path, local_modules, allocator);
            }
        }
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

    pub fn get_package_abs_path(self: *Module) []const u8 {
        return std.fs.path.dirname(self.absolute_path).?;
    }

    /// Appends the instructions in a BasicBlock to the module's instructions.
    /// Returns the offset of the basic block
    fn append_basic_block(
        self: *Module,
        first_bb: *basic_block_.Basic_Block,
        cfg: *cfg_.CFG,
    ) offsets_.Instruction_Idx {
        var work_queue = std.ArrayList(*basic_block_.Basic_Block).init(self.allocator);
        defer work_queue.deinit();
        work_queue.append(first_bb) catch unreachable;

        while (work_queue.items.len > 0) {
            // TODO: Too long
            var bb = work_queue.orderedRemove(0); // Youch! Does this really have to be ordered?

            if (bb.offset != null) {
                continue;
            }

            bb.offset = @as(offsets_.Instruction_Idx, @intCast(self.instructions.items.len));
            var label = ir_.Instruction.init_label(cfg, span_.phony_span, self.allocator);
            label.uid = bb.uid;
            self.instructions.append(label) catch unreachable;

            var maybe_instr = bb.instr_head;
            while (maybe_instr) |instr| : (maybe_instr = instr.next) {
                self.instructions.append(instr) catch unreachable;
            }

            if (bb.has_branch) {
                if (bb.next) |next| {
                    work_queue.append(next) catch unreachable;
                }
                if (bb.branch) |branch| {
                    work_queue.append(branch) catch unreachable;
                }
                self.instructions.append(ir_.Instruction.init_branch_addr(
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
                self.instructions.append(ir_.Instruction.init_jump_addr(
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
    fn append_phony_block(
        self: *Module,
        cfg: *cfg_.CFG,
    ) offsets_.Instruction_Idx {
        const offset = @as(offsets_.Instruction_Idx, @intCast(self.instructions.items.len));
        // Append a label which has a back-reference to the CFG
        self.instructions.append(ir_.Instruction.init_label(
            cfg,
            span_.phony_span,
            self.allocator,
        )) catch unreachable;
        // Append a return instruction (a jump to null)
        self.instructions.append(ir_.Instruction.init_jump_addr(
            null,
            span_.phony_span,
            self.allocator,
        )) catch unreachable;
        return offset;
    }

    pub fn pop_cfg(self: *Module, idx: i64) void {
        _ = self.cfgs.orderedRemove(@as(usize, @intCast(idx)));
    }

    pub fn interned_string_set_add(self: *Module, str: []const u8) ir_.String_Idx {
        for (0..self.interned_strings.items.len) |i| {
            const item = self.interned_strings.items[i];
            if (std.mem.eql(u8, item, str)) {
                return .{ .module_uid = self.uid, .string_idx = @as(u32, @intCast(i)) };
            }
        }
        // sanitized_str must not be in set, add it
        const idx: u32 = @intCast(self.interned_strings.items.len);
        self.interned_strings.append(str) catch unreachable;
        return .{ .module_uid = self.uid, .string_idx = idx };
    }

    /// Returns the scope that contains this module's top-level definitions
    pub fn top_level_scope(self: *Module) *symbol_.Scope {
        return self.symbol.init.?.scope().?;
    }

    pub fn print_instructions(self: *Module) void {
        for (self.instructions.items) |instr| {
            std.debug.print("{}", .{instr});
        }
    }
};

// TODO: Move to own file
pub fn get_cfg(
    symbol: *symbol_.Symbol,
    caller: ?*cfg_.CFG,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) lower_.Lower_Errors!*cfg_.CFG {
    std.debug.assert(symbol.kind == .@"fn" or symbol.kind == .@"comptime");
    std.debug.assert(symbol.validation_state == .valid);
    if (symbol.init_validation_state == .validating) {
        errors.add_error(errs_.Error{ .recursive_definition = .{
            .span = symbol.span,
            .symbol_name = symbol.name,
        } });
        return error.CompileError;
    }
    if (symbol.cfg == null) {
        symbol.cfg = cfg_.CFG.init(symbol, caller, allocator);
        symbol.cfg.?.module = symbol.scope.module.?;
        // TODO: These should be steps in a pipeline
        try lower_.lower_AST_into_cfg(symbol.cfg.?, errors, allocator);
        try ir_validate_.validate_cfg(symbol.cfg.?, errors);
        try optimizations_.optimize(symbol.cfg.?, errors, allocator);
        symbol.cfg.?.collect_generated_symbvers();
        symbol.cfg.?.locals_size = offsets_.calculate_offsets(symbol);
    }
    return symbol.cfg.?;
}

/// Stamps out a new function declaration along with a fully built and validated symbol tree, and decorated identifiers.
///
/// ## Returns:
/// An identifier AST, decorated with the stamped out anonymous function.
/// TODO: Move to compiler
pub fn stamp(
    template_ast: *ast_.AST,
    args: *std.ArrayList(*ast_.AST),
    call_span: span_.Span,
    scope: *symbol_.Scope,
    compiler: *compiler_.Context,
) !*ast_.AST {
    std.debug.assert(template_ast.* == .template);
    if (template_ast.template.memo == null) {
        // Clone out a new fn decl AST, with a new name
        const fn_decl = template_ast.template.decl.clone(compiler.allocator());
        fn_decl.fn_decl.remove_const_params();
        fn_decl.fn_decl.name = null; // make function anonymous

        // Create a new symbol and scope for the new fn decl
        const fn_symbol = try Symbol_Tree.create_function_symbol(
            fn_decl,
            scope,
            &compiler.errors,
            compiler.allocator(),
        );
        try Symbol_Tree.put_symbol(fn_symbol, fn_symbol.scope, &compiler.errors);
        fn_decl.set_symbol(fn_symbol);

        const domain = Symbol_Tree.extract_domain(template_ast.template.decl.children().*, compiler.allocator());
        args.* = try ast_validate_.default_args(args.*, domain, &compiler.errors, compiler.allocator());
        _ = try ast_validate_.validate_args_arity(.function, args, domain, false, call_span, &compiler.errors);

        // Go through each comptime arg, evaluate it, and store it in a list along with it's position
        // Combines the arg value and the position in the args/params list
        var const_decls = std.ArrayList(*ast_.AST).init(compiler.allocator());
        defer const_decls.deinit();
        for (template_ast.template.decl.fn_decl._params.items, args.items) |param, arg| {
            if (param.decl.pattern.pattern_symbol.kind == .@"const") {
                const decl = ast_.AST.create_decl(
                    param.token(),
                    param.decl.pattern,
                    param.decl.type,
                    arg, // TODO: Comptime eval this
                    true,
                    compiler.allocator(),
                );
                const_decls.append(decl) catch unreachable;
            }
        }

        // Define each constant parameter in the fn decl's scope
        try walker_.walk_asts(&const_decls, Symbol_Tree.new(scope, &compiler.errors, compiler.allocator()));

        // Decorate identifiers, validate
        const decorate_context = Decorate.new(scope, &compiler.errors, compiler.allocator());
        const decorate_access_context = Decorate_Access.new(scope, &compiler.errors, compiler);
        for (const_decls.items) |decl| {
            try walker_.walk_ast(decl, decorate_context);
            try walker_.walk_ast(decl, decorate_access_context);
        }
        try walker_.walk_ast(fn_decl, decorate_context);
        try walker_.walk_ast(fn_decl, decorate_access_context);
        try ast_validate_.validate_scope(fn_symbol.scope, compiler);

        // Memoize symbol
        template_ast.template.memo = fn_symbol;
    }

    const identifier = ast_.AST.create_identifier(token_.Token.init_simple(template_ast.template.memo.?.name), compiler.allocator());
    identifier.set_symbol(template_ast.template.memo);
    return identifier;
}

/// Relatively light-weight way to interpret an AST.
///
/// - `ast`: AST to interpret
/// - `ret_type`: Expected return type of the AST after interpretation
/// - `scope`: Scope context to interpret the AST within
/// - `errors`: Error managing context, to output errors to
/// - `allocator`: Allocator to use for interpretation
///
/// TODO: Move to compiler
///
/// Errors out either during AST-Instruction lowering, or interpretation.
pub fn interpret(
    ast: *ast_.AST,
    ret_type: *ast_.AST,
    scope: *symbol_.Scope,
    compiler: *compiler_.Context,
) !*ast_.AST {
    const symbol: *symbol_.Symbol = (try Symbol_Tree.create_temp_comptime_symbol(
        ast,
        ret_type,
        scope,
        &compiler.errors,
        compiler.allocator(),
    )).assert_symbol_valid().assert_init_valid();

    // Get the cfg from the symbol, and embed into the module
    const module = symbol.scope.module.?;
    const cfg = try get_cfg(symbol, null, &compiler.errors, compiler.allocator());
    defer cfg.deinit(); // Remove the cfg so that it isn't output

    const idx = module.emplace_cfg(cfg);
    defer module.pop_cfg(idx); // Remove the cfg so that it isn't output

    // Create a context and interpret
    var context = interpreter_.Context.init(&compiler.errors, compiler.allocator());
    context.set_entry_point(cfg, ret_type);
    defer context.deinit();
    context.load_module(module);
    try context.run(compiler);

    // Extract the retval
    return try context.extract_ast(0, ret_type, ast.token().span);
}
