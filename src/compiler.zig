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
    // So far, only stores a local module's name to it's module struct
    // This will need to be modified to store packages, too, and deal with module name collisions
    modules: std.StringArrayHashMap(*module_.Module),

    prelude: *symbol_.Scope,

    /// List of errors found during compilation
    errors: errs_.Errors,

    /// Allocator used during compilation
    allocator: std.mem.Allocator,

    /// Throws an error if the prelude could not be compiled
    pub fn init(allocator: std.mem.Allocator) Error!Context {
        ast_.init_structures();
        var retval: Context = .{
            .modules = std.StringArrayHashMap(*module_.Module).init(allocator),
            .prelude = undefined,
            .errors = errs_.Errors.init(allocator),
            .allocator = allocator,
        };
        retval.prelude = try primitives_.get_scope(&retval);
        return retval;
    }

    // TODO: add a deinit function

    pub fn compile_build_file(self: *Context, path: []const u8) Error!*cfg_.CFG {
        const build_module = try self.compile_module(path, "build", false);
        return build_module.scope.lookup("build", false).found.cfg.?;
    }

    /// Compiles a module from a file
    pub fn compile_module(
        self: *Context,
        absolute_path: []const u8,
        entry_name: ?[]const u8,
        fuzz_tokens: bool,
    ) Error!*module_.Module {
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
        var contents_arraylist = std.ArrayList(u8).init(self.allocator);
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
