const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const errs_ = @import("errors.zig");
const module_ = @import("module.zig");
const primitives_ = @import("primitives.zig");
const symbol_ = @import("symbol.zig");

const Error: type = error{
    LexerError,
    ParseError,
    CompileError,
    FileNotFound,
};

pub const Context = struct {
    arena: std.heap.ArenaAllocator,

    /// List of errors found during compilation
    errors: errs_.Errors,

    prelude: *symbol_.Scope,

    // So far, only stores a local module's name to it's module struct
    // This will need to be modified to store packages, too, and deal with module name collisions
    modules: std.StringArrayHashMap(*module_.Module),

    /// Throws an error if the prelude could not be compiled
    pub fn init(alloc: std.mem.Allocator) Error!*Context {
        var retval: *Context = alloc.create(Context) catch unreachable;
        retval.arena = std.heap.ArenaAllocator.init(alloc);
        ast_.init_structures(retval.allocator());
        retval.errors = errs_.Errors.init(retval.allocator());
        retval.prelude = try primitives_.get_scope(retval);
        retval.modules = std.StringArrayHashMap(*module_.Module).init(retval.allocator());
        return retval;
    }

    pub fn deinit(self: *Context) void {
        self.arena.deinit();
        self.arena.child_allocator.destroy(self);
    }

    pub fn allocator(self: *Context) std.mem.Allocator {
        return self.arena.allocator();
    }

    pub fn compile_build_file(self: *Context, absolute_path: []const u8) Error!*cfg_.CFG {
        const build_module = try self.compile_module(absolute_path, "build", false);
        return build_module.scope.lookup("build", false).found.cfg.?;
    }

    /// Compiles a module from a file
    pub fn compile_module(
        self: *Context,
        absolute_path: []const u8,
        entry_name: ?[]const u8,
        fuzz_tokens: bool,
    ) Error!*module_.Module {
        _ = self.allocator().alloc(u8, 100000) catch unreachable;
        if (self.modules.get(absolute_path)) |module| {
            return module;
        }

        // Open the file
        var file = std.fs.openFileAbsolute(absolute_path, .{}) catch |err| switch (err) {
            error.FileNotFound => return error.FileNotFound,
            else => return error.CompileError,
        };
        defer file.close();

        const stat = file.stat() catch return error.CompileError;
        const uid = stat.mtime;
        _ = uid;

        // Read in the contents of the file
        var buf_reader = std.io.bufferedReader(file.reader());
        var in_stream = buf_reader.reader();
        var contents_arraylist = std.ArrayList(u8).init(self.allocator());
        defer contents_arraylist.deinit();
        in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF) catch unreachable;
        const contents = contents_arraylist.toOwnedSlice() catch unreachable;

        const module = module_.Module.compile(contents, absolute_path, entry_name, fuzz_tokens, self) catch |err| {
            switch (err) {
                // Always print these errors for fuzz testing
                error.LexerError,
                error.ParseError,
                => {
                    self.errors.print_errors();
                    return err;
                },

                // Only print these errors if NOT fuzz testing
                error.CompileError,
                => if (!fuzz_tokens) {
                    self.errors.print_errors();
                    return err;
                } else {
                    return err;
                },
            }
        };
        self.modules.put(absolute_path, module) catch unreachable;
        return module;
    }
};
