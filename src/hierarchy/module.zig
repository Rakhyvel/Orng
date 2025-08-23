const std = @import("std");
const module_validate_ = @import("../semantic/module_validate.zig");
const ast_ = @import("../ast/ast.zig");
const CFG = @import("../ir/cfg.zig");
const cfg_builder_ = @import("../ir/cfg_builder.zig");
const Cfg_Iterator = @import("../util/dfs.zig").Dfs_Iterator(*CFG);
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const Instruction = @import("../ir/instruction.zig");
const pipeline_ = @import("../util/pipeline.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const Span = @import("../util/span.zig");
const Scope = @import("../symbol/scope.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");
const Module_Hash = @import("module_hash.zig");
const Token = @import("../lexer/token.zig");
const Type_Set = @import("../ast/type-set.zig");
const UID_Gen = @import("../util/uid_gen.zig");

// Front-end pipeline steps
const Read_File = @import("../lexer/read_file.zig");
const Hash = @import("../lexer/hash.zig");
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

    /// Unique Identifier generator for symbols in this module, so that symbols are given predictable, stable UIDs
    uid_gen: UID_Gen,

    // Absolute path of the module
    absolute_path: []const u8,

    // The name of the package this module belongs to
    package_name: []const u8,

    /// Set of local modules that are imported
    local_imported_modules: std.AutoArrayHashMap(*Module, void),

    // Set of C headers to include
    cincludes: std.ArrayList(*ast_.AST),

    // A graph of type dependencies
    type_set: Type_Set,

    /// List of instructions for this module. Used by the interpreter, so that instructions are indexable by a random
    /// access instruction pointer.
    instructions: std.ArrayList(*Instruction),

    /// List of CFGs defined in this module. Used by codegen to generate functions and method definitions.
    cfgs: std.ArrayList(*CFG),

    /// Main function. Used by codegen to jump to the main function. May be null for modules that don't contain the
    /// entry point of the package.
    /// TODO: Isn't this more of a property of the package than the module?
    entry: ?*CFG,

    /// List of all traits defined in this module. Used by codegen to output the vtable structs definitions
    traits: std.ArrayList(*ast_.AST),

    /// List of all impls defined in this module. Used by codegen to output the vtable implementations.
    impls: std.ArrayList(*ast_.AST),

    /// List of all tests defined in this module. Used by codegen to output the vtable implementations.
    tests: std.ArrayList(*CFG),

    /// Allocator for the module
    allocator: std.mem.Allocator,

    /// The hash of the contents, used to track changes
    hash: u64,

    modified: ?bool,

    pub fn init(absolute_path: []const u8, allocator: std.mem.Allocator) *Module {
        var retval = allocator.create(Module) catch unreachable;
        retval.uid = module_uids;
        retval.uid_gen = UID_Gen.init();
        module_uids += 1;
        std.debug.assert(std.fs.path.isAbsolute(absolute_path));
        retval.absolute_path = absolute_path;
        retval.package_name = std.fs.path.basename(std.fs.path.dirname(absolute_path).?);
        retval.allocator = allocator;
        retval.local_imported_modules = std.AutoArrayHashMap(*Module, void).init(allocator);
        retval.cincludes = std.ArrayList(*ast_.AST).init(allocator);
        retval.instructions = std.ArrayList(*Instruction).init(allocator);
        retval.traits = std.ArrayList(*ast_.AST).init(allocator);
        retval.impls = std.ArrayList(*ast_.AST).init(allocator);
        retval.tests = std.ArrayList(*CFG).init(allocator);
        retval.cfgs = std.ArrayList(*CFG).init(allocator);
        retval.type_set = Type_Set.init(allocator);
        retval.entry = null;
        retval.modified = null;

        return retval;
    }

    // TODO: Move to compiler context
    pub fn compile(
        absolute_path: []const u8,
        entry_name: ?[]const u8,
        fuzz_tokens: bool,
        compiler: *Compiler_Context,
    ) Module_Errors!*Module {
        // Check to see if the file exists
        {
            var file = std.fs.openFileAbsolute(absolute_path, .{}) catch |err| switch (err) {
                error.FileNotFound => return error.FileNotFound,
                else => return error.CompileError,
            };
            defer file.close();
        }

        // Create the symbol for this module
        const module = Module.init(absolute_path, compiler.allocator());
        var file_root = Scope.init(compiler.prelude, &module.uid_gen, compiler.allocator());
        file_root.module = module;
        const symbol = Symbol.init(
            compiler.prelude,
            module.name(),
            Span{ .col = 1, .line_number = 1, .filename = absolute_path, .line_text = "" },
            primitives_.unit_type,
            ast_.AST.create_module(
                Token.init_simple(module.name()),
                file_root,
                module,
                compiler.allocator(),
            ),
            null,
            .module,
            compiler.allocator(),
        );
        try compiler.prelude.put_symbol(symbol, &compiler.errors);
        file_root.module = module;

        try fill_contents(absolute_path, entry_name, file_root, module, symbol, fuzz_tokens, compiler);

        return module;
    }

    pub fn name(self: *const Module) []const u8 {
        const basename = std.fs.path.basename(self.absolute_path);
        var i: usize = 0;
        while (i < basename.len and basename[i] != '.') : (i += 1) {}
        return basename[0..i];
    }

    pub fn fill_contents(
        in_name: []const u8,
        entry_name: ?[]const u8,
        file_root: *Scope,
        module: *Module,
        module_symbol: *Symbol,
        fuzz_tokens: bool,
        compiler: *Compiler_Context,
    ) Module_Errors!void {
        compiler.register_interned_string_set(module.uid);
        compiler.register_module(module.absolute_path, module_symbol);

        // Setup and run the front-end pipeline
        _ = try pipeline_.run(in_name, .{
            Read_File.init(compiler.allocator()),
            Hash.init(&module.hash),
            Split_Lines.init(&compiler.errors, compiler.allocator()),
            Tokenize.init(in_name, &compiler.errors, fuzz_tokens, compiler.allocator()),
            Apply_Layout.init(),
            Parse.init(&compiler.errors, compiler.allocator()),
            Apply_Ast_Walk(Expand).init(Expand.new(&compiler.errors, compiler.allocator())),
            Apply_Flat_Ast_Walk(Import).init(Import.new(compiler, module.get_package_abs_path(), &module.local_imported_modules)),
            Apply_Flat_Ast_Walk(Cinclude).init(Cinclude.new(&module.cincludes)),
            Apply_Ast_Walk(Symbol_Tree).init(Symbol_Tree.new(file_root, &compiler.errors, compiler.allocator())),
            Apply_Ast_Walk(Decorate).init(Decorate.new(file_root, &compiler.errors, compiler.allocator())),
            Apply_Ast_Walk(Decorate_Access).init(Decorate_Access.new(file_root, &compiler.errors, compiler)),
        });

        // Perform checks and collections on the module
        try module_validate_.validate(module, compiler);
        compiler.module_scope(module.absolute_path).?.collect_traits_and_impls(&module.traits, &module.impls);
        try module.add_all_cfgs(entry_name, compiler);
        if (module.entry) |entry| {
            entry.assert_needed_at_runtime();
        }
        try module.collect_impl_cfgs(compiler);
        try module.collect_tests(compiler);
        module.collect_trait_types(compiler.allocator());
        module.collect_cfg_types(compiler.allocator());
    }

    fn add_all_cfgs(self: *Module, entry_name: ?[]const u8, compiler: *Compiler_Context) Module_Errors!void {
        var found_entry = false;
        const need_entry = entry_name != null;
        for (compiler.module_scope(self.absolute_path).?.symbols.keys()) |key| {
            const symbol: *Symbol = compiler.module_scope(self.absolute_path).?.symbols.get(key).?;
            if (symbol.kind != .@"fn") {
                continue;
            }

            // Instruction translation
            const interned_strings = compiler.lookup_interned_string_set(self.uid).?;
            const cfg = try cfg_builder_.get_cfg(symbol, interned_strings, &compiler.errors, compiler.allocator());
            self.collect_cfgs(cfg);

            if (need_entry and std.mem.eql(u8, key, entry_name.?)) {
                self.entry = cfg;
                found_entry = true;
            }
        }
        if (need_entry and !found_entry) {
            compiler.errors.add_error(errs_.Error{ .basic = .{
                .span = Span.phony,
                .msg = "no main function found",
            } });
            // Cannot find main function, fatal, do not procede
            return error.CompileError;
        }
    }

    /// This allows us to pick up anon and inner CFGs that wouldn't be exposed to the module's scope
    fn collect_cfgs(self: *Module, cfg: *CFG) void {
        var cfg_dfs_iter = Cfg_Iterator.init(cfg, self.allocator);
        while (cfg_dfs_iter.next()) |next_cfg| {
            next_cfg.collect_generated_symbvers();
            _ = next_cfg.emplace_cfg(&self.cfgs, &self.instructions);
        }
    }

    fn collect_trait_types(self: *Module, allocator: std.mem.Allocator) void {
        for (self.traits.items) |trait| {
            for (trait.trait.method_decls.items) |decl| {
                _ = self.type_set.add(decl.method_decl.c_type.?, allocator);
            }
        }
    }

    fn collect_impl_cfgs(self: *Module, compiler: *Compiler_Context) Module_Errors!void {
        for (self.impls.items) |impl| {
            for (impl.impl.method_defs.items) |def| {
                const symbol = def.symbol().?;
                const interned_strings = compiler.lookup_interned_string_set(self.uid).?;
                const cfg = (try cfg_builder_.get_cfg(symbol, interned_strings, &compiler.errors, compiler.allocator()));
                cfg.assert_needed_at_runtime();
                self.collect_cfgs(cfg);
            }
        }
    }

    fn collect_tests(self: *Module, compiler: *Compiler_Context) Module_Errors!void {
        var test_asts = std.ArrayList(*ast_.AST).init(compiler.allocator());
        compiler.module_scope(self.absolute_path).?.collect_tests(&test_asts);

        for (test_asts.items) |test_ast| {
            const symbol = test_ast.symbol().?;
            const interned_strings = compiler.lookup_interned_string_set(self.uid).?;
            const cfg = (try cfg_builder_.get_cfg(symbol, interned_strings, &compiler.errors, compiler.allocator()));
            self.tests.append(cfg) catch unreachable;
            cfg.assert_needed_at_runtime();
            self.collect_cfgs(cfg);
        }
    }

    fn collect_cfg_types(self: *Module, allocator: std.mem.Allocator) void {
        for (self.cfgs.items) |cfg| {
            // Add parameter types to type set
            const decl = cfg.symbol.decl.?;
            const param_symbols = decl.param_symbols();
            if (param_symbols != null) {
                for (param_symbols.?.items) |param| {
                    _ = self.type_set.add(param.expanded_type.?, allocator);
                }
            }

            for (cfg.basic_blocks.items) |bb| {
                for (bb.instructions.items) |instr| {
                    if (instr.dest != null) {
                        _ = self.type_set.add(instr.dest.?.get_expanded_type(), allocator);
                        _ = self.type_set.add(instr.dest.?.extract_symbver().symbol.expanded_type.?, allocator);
                    }
                }
            }
        }
    }

    pub fn get_package_abs_path(self: *Module) []const u8 {
        return std.fs.path.dirname(self.absolute_path).?;
    }

    pub fn pop_cfg(self: *Module, idx: i64) void {
        _ = self.cfgs.orderedRemove(@as(usize, @intCast(idx)));
    }

    pub fn get_adjacent(self: *Module) []*Module {
        return self.local_imported_modules.keys();
    }

    pub fn print_instructions(self: *Module) void {
        for (self.instructions.items) |instr| {
            std.debug.print("{}", .{instr});
        }
    }

    /// A module is modified if:
    /// - Its source hash differs from what is stored in the package's json file
    /// - Any of the module it imports have been modified
    pub fn determine_if_modified(self: *Module, compiler: *Compiler_Context) void {
        if (self.modified != null) {
            return;
        }

        const module_hashes = compiler.lookup_package(self.get_package_abs_path()).?.module_hash;
        const old_hash = module_hashes.get_module_stored_hash(self.name());
        const local_module_number_string = std.fmt.allocPrint(compiler.allocator(), "{X}", .{self.hash}) catch unreachable;
        defer compiler.allocator().free(local_module_number_string);
        self.modified = (old_hash == null) or !std.mem.eql(u8, local_module_number_string, old_hash.?);

        for (self.local_imported_modules.keys()) |imported_module| {
            imported_module.determine_if_modified(compiler);
            self.modified = imported_module.modified.? or self.modified.?;
        }
    }

    pub fn update_module_hash(self: *const Module, module_hash: *Module_Hash, allocator: std.mem.Allocator) void {
        const local_module_number_string = std.fmt.allocPrint(allocator, "{X}", .{self.hash}) catch unreachable;
        module_hash.set_module_hash(self.name(), local_module_number_string, allocator);
    }
};
