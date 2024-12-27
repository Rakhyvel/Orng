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
    modules: std.StringArrayHashMap(*symbol_.Symbol),

    // Maps package names to their root module
    packages: std.StringArrayHashMap(*Package),

    const Package = struct {
        requirements: std.StringArrayHashMap(*symbol_.Symbol),
    };

    /// Throws an error if the prelude could not be compiled
    pub fn init(alloc: std.mem.Allocator) Error!*Context {
        var retval: *Context = alloc.create(Context) catch unreachable;
        retval.arena = std.heap.ArenaAllocator.init(alloc);

        ast_.init_structures(retval.allocator());
        retval.errors = errs_.Errors.init(retval.allocator());
        retval.prelude = primitives_.get_scope(retval) catch {
            // Prelude compilation can sometimes fail :(
            retval.errors.print_errors();
            return error.CompileError;
        };
        retval.modules = std.StringArrayHashMap(*symbol_.Symbol).init(retval.allocator());
        retval.packages = std.StringArrayHashMap(*Package).init(retval.allocator());

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
        return build_module.init.?.scope().?.lookup("build", .{}).found.cfg.?;
    }

    /// Compiles a module from a file
    pub fn compile_module(
        self: *Context,
        absolute_path: []const u8,
        entry_name: ?[]const u8,
        fuzz_tokens: bool,
    ) Error!*symbol_.Symbol {
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

        std.debug.print("  compiling {s}/{s}...\n", .{ std.fs.path.basename(std.fs.path.dirname(absolute_path).?), std.fs.path.basename(absolute_path) });
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
        self.modules.put(absolute_path, module.symbol) catch unreachable;
        return module.symbol;
    }

    pub fn lookup_module(self: *Context, absolute_path: []const u8) ?*symbol_.Symbol {
        return self.modules.get(absolute_path);
    }

    pub fn lookup_package_root_module(self: *Context, package_name: []const u8, requirement_name: []const u8) ?*symbol_.Symbol {
        return self.packages.get(package_name).?.requirements.get(requirement_name);
    }

    pub fn register_package(self: *Context, package_name: []const u8, requirement_name: []const u8, requirement_root_module: *symbol_.Symbol) void {
        std.debug.print("package name:{s}, requirement name:{s}\n", .{ package_name, requirement_name });
        if (self.packages.get(package_name)) |package| {
            package.requirements.put(requirement_name, requirement_root_module) catch unreachable;
        } else {
            const package = self.allocator().create(Package) catch unreachable;
            package.requirements = std.StringArrayHashMap(*symbol_.Symbol).init(self.allocator());
            self.packages.put(package_name, package) catch unreachable;
            package.requirements.put(requirement_name, requirement_root_module) catch unreachable;
        }
    }

    pub fn output_modules(self: *Context) void {
        // Start from root module, of each package, DFS through imports and generate
        for (self.modules.keys()) |name| {
            const module = self.modules.get(name).?.init.?.module.module;
            std.debug.print(" generating: {s}\n", .{module.name});
        }
    }
};
