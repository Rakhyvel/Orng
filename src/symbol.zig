const std = @import("std");
const ast = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const errs = @import("errors.zig");
const module_ = @import("module.zig");
const offsets = @import("offsets.zig");
const optimizations = @import("optimizations.zig");
const _span = @import("span.zig");
const validation_state_ = @import("validation_state.zig");

const AST = ast.AST;
const CFG = cfg_.CFG;
const Error = errs.Error;
const Module = module_.Module;
const Span = _span.Span;
const String = @import("zig-string/zig-string.zig").String;
const Token = @import("token.zig").Token;

const LookupResult = union(enum) { found_but_rt, found_but_fn, not_found, found: *Symbol };

var scopeUID: usize = 0;
pub const Scope = struct {
    parent: ?*Scope,
    children: std.ArrayList(*Scope),
    symbols: std.StringArrayHashMap(*Symbol),
    module: ?*Module, // Enclosing module
    name: []const u8,
    uid: usize,

    in_function: usize = 0,
    in_loop: bool = false,
    defers: std.ArrayList(*AST),
    errdefers: std.ArrayList(*AST),
    inner_function: ?*Symbol = null,

    pub fn init(parent: ?*Scope, name: []const u8, allocator: std.mem.Allocator) *Scope {
        var retval = allocator.create(Scope) catch unreachable;
        retval.parent = parent;
        retval.children = std.ArrayList(*Scope).init(allocator);
        retval.symbols = std.StringArrayHashMap(*Symbol).init(allocator);
        retval.name = name;
        retval.uid = scopeUID;
        retval.defers = std.ArrayList(*AST).init(allocator);
        retval.errdefers = std.ArrayList(*AST).init(allocator);
        scopeUID += 1;
        if (parent) |_parent| {
            _parent.children.append(retval) catch unreachable;
            retval.in_loop = _parent.in_loop;
            retval.in_function = _parent.in_function;
            retval.inner_function = _parent.inner_function;
            retval.module = _parent.module;
        } else {
            retval.in_loop = false;
            retval.in_function = 0;
            retval.inner_function = null;
            retval.module = null;
        }
        return retval;
    }

    pub fn lookup(self: *Scope, name: []const u8, crossed_boundary: bool) LookupResult {
        if (self.symbols.get(name)) |symbol| {
            if (crossed_boundary and (symbol.kind == .mut or symbol.kind == .let)) {
                // Found the symbol, but it's non-const and we've crossed an inner-function boundary
                return .found_but_fn;
            } else {
                // Found the symbol just fine
                return LookupResult{ .found = symbol };
            }
        } else if (self.parent) |parent| {
            const res = parent.lookup(name, parent.in_function < self.in_function or crossed_boundary);
            if (false and res == .found_but_fn and self.inner_function.?.kind == ._comptime) {
                // If have to cross a `comptime` boundary, change fn error to rt error
                return .found_but_rt;
            } else {
                // (normal recursion)
                return res;
            }
        } else {
            // Did not find the symbol at all
            return .not_found;
        }
    }

    pub fn pprint(self: *Scope) !void {
        var out = String.init(std.heap.page_allocator);
        defer out.deinit();
        try self.serialize(&out, 0);
        std.debug.print("{s}\n", .{out.str()});
    }

    fn serialize(self: *Scope, out: *String, spaces: usize) !void {
        var j: usize = 0;
        while (j < spaces) : (j += 1) {
            try out.insert(" ", out.len());
        }
        try out.insert(self.name, out.len());
        try out.insert(": {\n", out.len());
        const keySet = self.symbols.keys();
        var i: usize = 0;
        while (i < keySet.len) : (i += 1) {
            const key = keySet[i];
            j = 0;
            while (j < spaces + 4) : (j += 1) {
                try out.insert(" ", out.len());
            }
            try out.insert(self.symbols.get(key).?.name, out.len());
            if (i < keySet.len - 1) {
                try out.insert(",", out.len());
            } else {
                try out.insert(",\n", out.len());
            }
            try out.insert("\n", out.len());
        }
        for (self.children.items) |child| {
            try child.serialize(out, spaces + 4);
        }
        j = 0;
        while (j < spaces) : (j += 1) {
            try out.insert(" ", out.len());
        }
        try out.insert("}\n", out.len());
    }

    pub fn root(self: *Scope) ?*Scope {
        if (self.parent) |_parent| {
            return root(_parent);
        } else {
            return self;
        }
    }

    /// This function collects all visible symbols from a scope that:
    ///   1. have an identical expected type
    ///   2. spelled similarly (levenshtein distance is less than half)
    pub fn collect_similar(self: *Scope, name: []const u8, out: *std.ArrayList([]const u8), expected: ?*ast.AST, allocator: std.mem.Allocator) void {
        for (self.symbols.keys()) |key| {
            var symbol: *Symbol = self.symbols.get(key).?;
            if (std.mem.eql(u8, symbol.name, "_")) {
                continue; // never suggest `_`
            }

            const matches = expected == null or symbol._type.typesMatch(expected.?);
            const dist = levenshteinDistance2(allocator, symbol.name, name);
            if (matches and dist <= name.len / 2) {
                out.append(key) catch unreachable;
            }
        }
        if (self.parent) |_parent| {
            _parent.collect_similar(name, out, expected, allocator);
        }
    }

    inline fn idx(i: usize, j: usize, cols: usize) usize {
        return i * cols + j;
    }

    pub fn levenshteinDistance2(allocator: std.mem.Allocator, a: []const u8, b: []const u8) u16 {
        const n = a.len;
        const m = b.len;
        const table = allocator.alloc(u8, n * m) catch unreachable;
        defer allocator.free(table);
        table[0] = 0;

        for (0..n) |i| {
            for (0..m) |j| {
                table[idx(i, j, m)] = @min(
                    (if (i == 0)
                        @as(u8, @truncate(j))
                    else
                        table[idx(i - 1, j, m)]) + 1,
                    (if (j == 0)
                        @as(u8, @truncate(i))
                    else
                        table[idx(i, j - 1, m)]) + 1,
                    (if (i == 0)
                        @as(u8, @truncate(j))
                    else if (j == 0)
                        @as(u8, @truncate(i))
                    else
                        table[idx(i - 1, j - 1, m)]) +
                        @intFromBool(a[i] != b[j]),
                );
            }
        }
        return table[table.len - 1];
    }
};

pub const SymbolKind = enum {
    _fn,
    _const,
    let,
    mut,
    _comptime,
    pub fn to_string(self: SymbolKind) []const u8 {
        return switch (self) {
            ._fn => "fn",
            ._const => "const",
            .let => "let",
            .mut => "mut",
            ._comptime => "comptime",
        };
    }
};

pub const Symbol_Validation_State = validation_state_.Validation_State(*Symbol);

var number_of_comptime: usize = 0;
pub const Symbol = struct {
    scope: *Scope, // Enclosing parent scope
    name: []const u8,
    span: Span,
    _type: *ast.AST,
    expanded_type: ?*ast.AST,
    init: *ast.AST,
    kind: SymbolKind,
    cfg: ?*CFG,
    decl: ?*AST,

    // Use-def
    versions: u64 = 0,
    uses: u64 = 0,
    discards: u64 = 0, // May be 0 if symbol is uses > 0; may be 1 if uses = 0; may not be greater than 1
    discard_span: ?Span,

    defined: bool, // Used for decorating identifiers. True when the symbol is defined at the identifier
    validation_state: Symbol_Validation_State,
    decld: bool, // When a local variable, whether or not the variable has been printed out or not
    param: bool,
    is_temp: bool = false,

    // Offset
    offset: ?i64, // The offset from the BP that this symbol

    pub fn init(scope: *Scope, name: []const u8, span: Span, _type: *ast.AST, _init: *ast.AST, decl: ?*AST, kind: SymbolKind, allocator: std.mem.Allocator) *Symbol {
        var retval = allocator.create(Symbol) catch unreachable;
        retval.scope = scope;
        retval.name = name;
        retval.span = span;
        retval._type = _type;
        retval.expanded_type = null;
        retval.init = _init;
        retval.decl = decl;
        retval.versions = 0;
        retval.discards = 0;
        retval.uses = 0;
        retval.offset = null;
        retval.kind = kind;
        retval.cfg = null;
        if (kind == ._fn or kind == ._const or kind == ._comptime) {
            retval.defined = true;
        } else {
            retval.defined = false;
        }
        retval.validation_state = .unvalidated;
        retval.decld = false;
        return retval;
    }

    pub fn get_cfg(self: *Symbol, caller: ?*CFG, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors, allocator: std.mem.Allocator) !*CFG {
        std.debug.assert(self.kind == ._fn or self.kind == ._comptime);
        std.debug.assert(self.validation_state == .valid);
        if (self.cfg == null) {
            self.cfg = try CFG.create(self, caller, interned_strings, errors, allocator);
            try optimizations.optimize(self.cfg.?, errors, allocator);
            self.cfg.?.collect_generated_symbvers();
            self.cfg.?.locals_size = offsets.calculate_offsets(self);
        }
        return self.cfg.?;
    }

    pub fn assert_valid(self: *Symbol) *Symbol {
        self.validation_state = Symbol_Validation_State{ .valid = .{ .valid_form = self } };
        return self;
    }
};
