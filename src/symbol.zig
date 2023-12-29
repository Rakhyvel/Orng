const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const module_ = @import("module.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;
const validation_state_ = @import("validation_state.zig");

const Lookup_Result = union(enum) { found_but_rt, found_but_fn, not_found, found: *Symbol };

var scope_UID: usize = 0;
pub const Scope = struct {
    parent: ?*Scope,
    children: std.ArrayList(*Scope),
    symbols: std.StringArrayHashMap(*Symbol),
    module: ?*module_.Module, // Enclosing module
    name: []const u8,
    uid: usize,

    in_function: usize = 0,
    in_loop: bool = false,
    defers: std.ArrayList(*ast_.AST),
    errdefers: std.ArrayList(*ast_.AST),
    inner_function: ?*Symbol = null,

    pub fn init(parent: ?*Scope, name: []const u8, allocator: std.mem.Allocator) *Scope {
        var retval = allocator.create(Scope) catch unreachable;
        retval.parent = parent;
        retval.children = std.ArrayList(*Scope).init(allocator);
        retval.symbols = std.StringArrayHashMap(*Symbol).init(allocator);
        retval.name = name;
        retval.uid = scope_UID;
        retval.defers = std.ArrayList(*ast_.AST).init(allocator);
        retval.errdefers = std.ArrayList(*ast_.AST).init(allocator);
        scope_UID += 1;
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

    pub fn lookup(self: *Scope, name: []const u8, crossed_boundary: bool) Lookup_Result {
        if (self.symbols.get(name)) |symbol| {
            if (crossed_boundary and (symbol.kind == .mut or symbol.kind == .let)) {
                // Found the symbol, but it's non-const and we've crossed an inner-function boundary
                return .found_but_fn;
            } else {
                // Found the symbol just fine
                return Lookup_Result{ .found = symbol };
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
};

pub const Symbol_Kind = enum {
    @"fn",
    @"const",
    let,
    mut,
    @"comptime",
};

pub const Symbol_Validation_State = validation_state_.Validation_State(*Symbol);

var number_of_comptime: usize = 0;
pub const Symbol = struct {
    scope: *Scope, // Enclosing parent scope
    name: []const u8,
    span: span_.Span,
    _type: *ast_.AST,
    expanded_type: ?*ast_.AST,
    init: *ast_.AST,
    kind: Symbol_Kind,
    cfg: ?*cfg_.CFG,
    decl: ?*ast_.AST,

    // Use-def
    versions: u64 = 0,
    uses: u64 = 0,
    discards: u64 = 0, // May be 0 if symbol is uses > 0; may be 1 if uses = 0; may not be greater than 1
    discard_span: ?span_.Span,

    defined: bool, // Used for decorating identifiers. True when the symbol is defined at the identifier
    validation_state: Symbol_Validation_State,
    decld: bool, // When a local variable, whether or not the variable has been printed out or not
    param: bool,
    is_temp: bool = false,

    // Offset
    offset: ?i64, // The offset from the BP that this symbol

    pub fn init(
        scope: *Scope,
        name: []const u8,
        span: span_.Span,
        _type: *ast_.AST,
        _init: *ast_.AST,
        decl: ?*ast_.AST,
        kind: Symbol_Kind,
        allocator: std.mem.Allocator,
    ) *Symbol {
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
        if (kind == .@"fn" or kind == .@"const" or kind == .@"comptime") {
            retval.defined = true;
        } else {
            retval.defined = false;
        }
        retval.validation_state = .unvalidated;
        retval.decld = false;
        return retval;
    }

    pub fn assert_valid(self: *Symbol) *Symbol {
        self.validation_state = Symbol_Validation_State{ .valid = .{ .valid_form = self } };
        return self;
    }
};
