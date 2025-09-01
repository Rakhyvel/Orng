const std = @import("std");
const AST = @import("../ast/ast.zig").AST;
const CFG = @import("../ir/cfg.zig");
const Module = @import("../hierarchy/module.zig").Module;
const prelude_ = @import("../hierarchy/prelude.zig");
const Dependency_Node = @import("../ast/dependency_node.zig");
const Symbol = @import("../symbol/symbol.zig");

const Writer = std.fs.File.Writer;
pub const CodeGen_Error = std.fs.File.WriteError;

const Self: type = @This();

module: *Module,
writer: Writer,

pub fn init(module: *Module, writer: Writer) Self {
    return Self{ .module = module, .writer = writer };
}

/// Outputs the C type which corresponds to an AST type.
pub fn output_type(self: *Self, _type: *AST) CodeGen_Error!void {
    if (_type.common()._unexpanded_type != null and
        _type.common()._unexpanded_type.?.* == .identifier and
        _type.common()._unexpanded_type.?.symbol() != null and
        _type.common()._unexpanded_type.?.symbol().?.kind == .@"extern")
    {
        // Output simply the C name for an extern type
        try self.writer.print("{s}", .{_type.common()._unexpanded_type.?.symbol().?.kind.@"extern".c_name.?.string.data});
        return;
    }

    if (_type.* == .call) {
        return try self.output_type(_type.common()._expanded_type.?);
    }

    // if (_type.common()._expanded_type != null and _type.common()._expanded_type.?.* == .@"comptime") {
    //     return try self.output_type(_type.common()._expanded_type.?.@"comptime".result.?);
    // }
    std.debug.assert(_type.common()._expanded_type == null or _type.common()._expanded_type.?.* != .@"comptime");

    if (_type.common()._expanded_type != null and _type.common()._expanded_type.?.sizeof() == 0) {
        // For zero-size types that are still required to be output, ie pointers to empty untagged unions, structs, or ()
        try self.writer.print("void", .{});
        return;
    }

    switch (_type.*) {
        .identifier => if (_type.common()._expanded_type != null and _type.common()._expanded_type.? != _type) {
            try self.output_type(_type.common()._expanded_type.?);
        } else {
            try self.writer.print("{s}", .{prelude_.info_from_name(_type.token().data).?.c_name});
        },
        .addr_of => {
            try self.output_type(_type.expr());
            try self.writer.print("*", .{});
        },
        .anyptr_type => try self.writer.print("void", .{}),
        .function => {
            const dep = self.module.type_set.get(_type).?;
            try self.output_function_name(dep);
        },
        .sum_type, .product => {
            const dep = self.module.type_set.get(_type).?;
            try self.output_struct_name(dep);
        },
        .untagged_sum_type => {
            const dep = self.module.type_set.get(_type).?;
            try self.output_untagged_sum_name(dep);
        },
        .dyn_type => {
            const dep = self.module.type_set.get(_type).?;
            try self.output_dyn_name(dep);
        },
        .unit_type => try self.writer.print("void", .{}),
        .annotation => try self.output_type(_type.annotation.type),
        else => std.debug.panic("compiler error: unimplemented output_type() for {?}", .{_type.*}),
    }
}

pub fn output_function_name(self: *Self, dep: *const Dependency_Node) CodeGen_Error!void {
    const type_uid = dep.uid;
    try self.writer.print("{s}_{s}_function{}", .{ self.module.package_name, self.module.name(), type_uid });
}

pub fn output_struct_name(self: *Self, dep: *const Dependency_Node) CodeGen_Error!void {
    const type_uid = dep.uid;
    try self.writer.print("struct {s}_{s}_struct{}", .{ self.module.package_name, self.module.name(), type_uid });
}

pub fn output_dyn_name(self: *Self, dep: *const Dependency_Node) CodeGen_Error!void {
    const type_uid = dep.uid;
    try self.writer.print("struct {s}_{s}_dyn{}", .{ self.module.package_name, self.module.name(), type_uid });
}

pub fn output_untagged_sum_name(self: *Self, dep: *const Dependency_Node) CodeGen_Error!void {
    const type_uid = dep.uid;
    try self.writer.print("union {s}_{s}_union{}", .{ self.module.package_name, self.module.name(), type_uid });
}

/// Applies a function to all CFGs in a list of CFGs.
pub fn forall_functions(
    self: *Self,
    sub: anytype,
    header_comment: []const u8,
    comptime f: fn (@TypeOf(sub), *CFG) CodeGen_Error!void,
) CodeGen_Error!void {
    try self.writer.print("{s}\n", .{header_comment});

    // apply the function `f` to all CFGs in the `cfgs` list
    for (self.module.cfgs.items) |cfg| {
        if (!cfg.needed_at_runtime) {
            continue;
        }
        if (cfg.symbol.decl.?.* == .fn_decl or cfg.symbol.decl.?.* == .method_decl) { // Don't output for `_comptime` decls
            try f(sub, cfg);
        }
    }
    try self.writer.print("\n", .{});
}

/// Outputs the prototype of a function
pub fn output_function_prototype(
    self: *Self,
    cfg: *CFG, // TODO: Accept cfg symbol
) CodeGen_Error!void {
    // Output function return type and name
    try self.output_type(cfg.symbol.expanded_type.?.rhs());
    try self.writer.print(" ", .{});
    try self.output_symbol(cfg.symbol);

    // Output function parameters
    var num_non_unit_params: i64 = 0;
    try self.writer.print("(", .{});
    const decl = cfg.symbol.decl.?;
    const param_symbols = decl.param_symbols();
    if (param_symbols != null) {
        for (param_symbols.?.items, 0..) |term, i| {
            if (!term.expanded_type.?.is_c_void_type()) {
                if (decl.* == .method_decl and decl.method_decl.receiver != null and i == 0) {
                    // Print out method receiver
                    try self.writer.print("void* ", .{});
                    try self.output_symbol(term);
                } else {
                    // Print out parameter declarations
                    try self.output_var_decl(term, true);
                }
                if (i + 1 < param_symbols.?.items.len and !param_symbols.?.items[i + 1].expanded_type.?.is_c_void_type()) {
                    try self.writer.print(", ", .{});
                }
                num_non_unit_params += 1;
            }
        }
    }

    if (num_non_unit_params == 0) {
        // If there are no parameters, mark parameter list as void
        try self.writer.print("void", .{});
    }
    try self.writer.print(")", .{});
}

/// Outputs a symbol's declaration. Parameters are not formatted with a preceding tab, nor a
/// semicolon nor newline.
pub fn output_var_decl(
    self: *Self,
    symbol: *Symbol,
    is_parameter: bool, // TODO: New function, that surrounds output_var_decl
) CodeGen_Error!void {
    if (!is_parameter) {
        try self.writer.print("    ", .{});
    }
    try self.output_type(symbol.expanded_type.?);
    try self.writer.print(" ", .{});
    try self.output_symbol(symbol);
    if (!is_parameter) {
        try self.writer.print(";\n", .{});
    }
}

/// Outputs a symbol with it's file's unique identifier
pub fn output_symbol(self: *Self, symbol: *Symbol) CodeGen_Error!void {
    if (symbol.kind == .@"extern") {
        try self.writer.print("{s}", .{symbol.kind.@"extern".c_name.?.string.data});
    } else if (symbol.decl != null and symbol.decl.?.* != .receiver and symbol.decl.?.top_level()) {
        try self.writer.print("p{s}_m{s}_{}_{s}", .{ symbol.scope.module.?.package_name, symbol.scope.module.?.name(), symbol.scope.uid, symbol.name });
    } else {
        try self.writer.print("_{}_{s}", .{ symbol.scope.uid, symbol.name });
    }
}
