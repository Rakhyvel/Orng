const std = @import("std");
const ast_ = @import("ast.zig");
const basic_block_ = @import("basic-block.zig");
const cfg_ = @import("cfg.zig");
const errs_ = @import("errors.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const primitives_ = @import("primitives.zig");
const String = @import("zig-string/zig-string.zig").String;
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");

const debug = false;

pub fn optimize(cfg: *cfg_.CFG, errors: *errs_.Errors, allocator: std.mem.Allocator) error{ DivideByZero, Unused, Overflow }!void {
    if (debug) {
        std.debug.print("[  CFG  ]: {s}\n", .{cfg.symbol.name});
        cfg.block_graph_head.?.pprint();
        log("\n\n");
    }

    try find_unused(cfg, errors);

    while (try propagate(cfg, errors, allocator) or
        remove_unused_defs(cfg) or
        bb_optimizations(cfg, allocator) or
        remove_unused_defs(cfg))
    {}
    cfg.clear_visited_BBs();

    log_optimization_pass("final", cfg);
}

fn find_unused(cfg: *cfg_.CFG, errors: *errs_.Errors) error{Unused}!void {
    calculate_usage(cfg);
    if (cfg.symbol.decl.?.* == .fn_decl) {
        for (cfg.symbol.decl.?.fn_decl.param_symbols.items) |param_symbol| {
            try err_if_unused(param_symbol, errors);
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir: ?*ir_.IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and
                !ir.removed and
                ir.dest.?.* == .symbver and
                !ir.dest.?.symbver.symbol.is_temp and
                ir.dest.?.symbver.symbol != cfg.return_symbol)
            {
                try err_if_unused(ir.dest.?.symbver.symbol, errors);
            }
        }
    }
}

/// Throws `error.Unused` if a symbol:
/// - is not used
/// - is discarded more than once
/// - discarded and used.
fn err_if_unused(symbol: *symbol_.Symbol, errors: *errs_.Errors) error{Unused}!void {
    if (symbol.discards > 1) {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = symbol.discard_span.?,
            .context_span = symbol.span,
            .name = symbol.name,
            .problem = "is discarded more than once",
            .context_message = "defined here",
        } });
        return error.Unused;
    } else if (symbol.discards == 1 and symbol.uses > 1) {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = symbol.discard_span.?,
            .context_span = symbol.span,
            .name = symbol.name,
            .problem = "is discarded when it is used",
            .context_message = "defined here",
        } });
        return error.Unused;
    } else if (symbol.kind != .@"const" and
        symbol.discards == 0 and
        symbol.uses == 0 and
        !primitives_.unit_type.types_match(symbol.expanded_type.?)) // Unit-typed symbols do not need to be discarded!
    {
        errors.add_error(errs_.Error{ .symbol_error = .{
            .span = symbol.span,
            .context_span = null,
            .name = symbol.name,
            .problem = "is never used",
            .context_message = "",
        } });
        return error.Unused;
    }
}

fn propagate(cfg: *cfg_.CFG, errors: *errs_.Errors, allocator: std.mem.Allocator) error{ Overflow, DivideByZero }!bool {
    var retval = false;

    calculate_versions(cfg);
    calculate_usage(cfg);

    for (cfg.basic_blocks.items) |bb| {
        // For each BB, keep a map of symbol versions and their definitions
        var def_map = std.AutoArrayHashMap(*lval_.Symbol_Version, ?*ir_.IR).init(allocator);
        defer def_map.deinit();

        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            // Walk through IR in BB, update map of src1 and src2 defs
            const src1_def: ?*ir_.IR = if (ir.src1 != null and ir.src1.?.* == .symbver) def_map.get(ir.src1.?.symbver) orelse null else null;
            const src2_def: ?*ir_.IR = if (ir.src2 != null and ir.src2.?.* == .symbver) def_map.get(ir.src2.?.symbver) orelse null else null;
            retval = try propagate_IR(ir, src1_def, src2_def, errors) or retval;

            if (ir.dest != null and ir.dest.?.* != .symbver) {
                def_map.put(ir.dest.?.extract_symbver(), null) catch unreachable;
            } else if (ir.kind == .addr_of) {
                def_map.put(ir.src1.?.extract_symbver(), null) catch unreachable;
            }
            if (ir.dest != null and ir.dest.?.* == .symbver) {
                def_map.put(ir.dest.?.symbver, ir) catch unreachable;
            }
        }
        if (bb.has_branch and bb.condition.?.* == .symbver) {
            const cond_def: ?*ir_.IR = def_map.get(bb.condition.?.symbver) orelse null;
            bb.condition.?.symbver.def = cond_def;
            if (cond_def != null and cond_def.?.kind == .copy) {
                bb.condition = cond_def.?.src1;
                retval = true;
            }
        }
    }

    return retval;
}

/// May throw `error.Overflow` for integer arithmetic overflow, or `error.DivideByZero` when it can be
/// proven that code would divide by zero.
fn propagate_IR(ir: *ir_.IR, src1_def: ?*ir_.IR, src2_def: ?*ir_.IR, errors: *errs_.Errors) error{ Overflow, DivideByZero }!bool {
    var retval = false;

    switch (ir.kind) {
        .copy => {
            if (ir.src1 == null) {
                log("unit-copy elimination");
                ir.in_block.?.remove_instruction(ir);
            } else if (ir.dest.?.* == .symbver and
                ir.src1.?.* == .symbver and
                ir.dest.?.symbver.symbol == ir.src1.?.symbver.symbol and
                src1_def != null and
                ir.dest.?.symbver.version == ir.src1.?.symbver.version)
            {
                log("self-copy elimination");
                ir.in_block.?.remove_instruction(ir);
                retval = true;
            } else {
                log("copy-propagation");
                retval = try copy_prop(ir, src1_def, .load_int, errors) or // TODO: Check if data fits int type bounds!
                    try copy_prop(ir, src1_def, .load_float, errors) or
                    try copy_prop(ir, src1_def, .load_string, errors) or
                    (ir.src1.?.* == .symbver and ir.src1.?.symbver.uses == 1 and try copy_prop(ir, src1_def, .load_struct, errors)) or
                    try copy_prop(ir, src1_def, .load_union, errors) or
                    try copy_prop(ir, src1_def, .load_symbol, errors) or
                    try copy_prop(ir, src1_def, .load_AST, errors) or
                    (try copy_prop(ir, src1_def, .copy, errors) and ir.src1 != src1_def.?.src1.?) or
                    try copy_prop(ir, src1_def, .addr_of, errors) or
                    try copy_prop(ir, src1_def, .add_int, errors) or try copy_prop(ir, src1_def, .add_float, errors) or
                    try copy_prop(ir, src1_def, .sub_int, errors) or try copy_prop(ir, src1_def, .sub_float, errors) or
                    try copy_prop(ir, src1_def, .mult_int, errors) or try copy_prop(ir, src1_def, .mult_float, errors) or
                    try copy_prop(ir, src1_def, .div_int, errors) or try copy_prop(ir, src1_def, .div_float, errors) or
                    try copy_prop(ir, src1_def, .mod, errors);
                // DO NOT IMPLEMENT .call => propagation
            }
        },

        .not => {
            if (src1_def != null and src1_def.?.kind == .load_int) {
                log("not; known int value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.int == 0) 1 else 0 }, errors);
                retval = true;
            }
        },

        .negate_int => {
            if (src1_def != null and src1_def.?.kind == .load_int) {
                log("negate_int; known value");
                try convert_to_load(ir, .load_int, .{ .int = -src1_def.?.data.int }, errors);
                retval = true;
            }
        },

        .negate_float => {
            if (src1_def != null and src1_def.?.kind == .load_float) {
                log("negate_float; known value");
                try convert_to_load(ir, .load_float, .{ .float = -src1_def.?.data.float }, errors);
                retval = true;
            }
        },

        .equal => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("equal; known int,int value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.int == src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("equal; known float,float value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.float == src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            } else if (ir.src1.?.* == .symbver and
                ir.src2.?.* == .symbver and
                ir.src1.?.symbver.symbol == ir.src2.?.symbver.symbol and
                !ir.src1.?.symbver.symbol.expanded_type.?.can_expanded_represent_float())
            {
                // `x == x => true (where x is NOT floating-point type)`
                // NOTE: Cannot do `x == x  ==> true` optimization for floats, `NaN == NaN` is false!
                log("equal; self inequality");
                try convert_to_load(ir, .load_int, .{ .int = 1 }, errors);
                retval = true;
            }
        },

        .not_equal => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("not_equal; known int,int value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.int != src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("not_equal; known float,float value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.float != src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            } else if (ir.src1.?.* == .symbver and ir.src2.?.* == .symbver and ir.src1.?.symbver.symbol == ir.src2.?.symbver.symbol) {
                // `x != x` => `false`
                log("not_equal; self inequality");
                try convert_to_load(ir, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .greater_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("greater_int; known int,int value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.int > src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (ir.src1.?.* == .symbver and ir.src2.?.* == .symbver and ir.src1.?.symbver.symbol == ir.src2.?.symbver.symbol) {
                // `x > x` => `false`
                log("greater_int; self compare");
                try convert_to_load(ir, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .greater_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("greater_float; known float,float value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.float > src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            } else if (ir.src1.?.* == .symbver and ir.src2.?.* == .symbver and ir.src1.?.symbver.symbol == ir.src2.?.symbver.symbol) {
                // `x > x` => `false`
                log("greater_float; self compare");
                try convert_to_load(ir, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .lesser_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("lesser_int; known int,int value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.int < src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (ir.src1.?.* == .symbver and ir.src2.?.* == .symbver and ir.src1.?.symbver.symbol == ir.src2.?.symbver.symbol) {
                // `x < x` => `false`
                log("lesser_int; self compare");
                try convert_to_load(ir, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .lesser_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("lesser_float; known int,int value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.float < src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            } else if (ir.src1.?.* == .symbver and ir.src2.?.* == .symbver and ir.src1.?.symbver.symbol == ir.src2.?.symbver.symbol) {
                // `x < x` => `false`
                log("lesser_float; self compare");
                try convert_to_load(ir, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .greater_equal_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("greater_equal_int; known int,int value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.int >= src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (ir.src1.?.* == .symbver and ir.src2.?.* == .symbver and ir.src1.?.symbver.symbol == ir.src2.?.symbver.symbol) {
                // `x >= x` => `true`
                log("greater_equal_int; self compare");
                try convert_to_load(ir, .load_int, .{ .int = 1 }, errors);
                retval = true;
            }
        },

        .greater_equal_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("greater_equal_float; known float,float value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.float >= src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            }
            // NOTE: Cannot do `x >= x  ==> true` optimization for floats, `NaN >= NaN` is false!
        },

        .lesser_equal_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("lesser_equal_int; known int,int value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.int <= src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (ir.src1.?.* == .symbver and ir.src2.?.* == .symbver and ir.src1.?.symbver.symbol == ir.src2.?.symbver.symbol) {
                // `x <= x` => `true`
                log("lesser_equal_int; self compare");
                try convert_to_load(ir, .load_int, .{ .int = 1 }, errors);
                retval = true;
            }
        },

        .lesser_equal_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("lesser_equal_float; known float,float value");
                try convert_to_load(ir, .load_int, .{ .int = if (src1_def.?.data.float <= src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            }
            // NOTE: Cannot do `x <= x  ==> true` optimization, `NaN <= NaN` is false!
        },

        .add_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("add_int; known int,int value");
                try convert_to_load(ir, .load_int, try src1_def.?.data.add_int_overflow(src2_def.?.data, ir.span, errors), errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 0) {
                log("add_int; add 0 lhs");
                convert_to_unop(ir, ir.src2.?, .copy);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 0) {
                log("add_int; add 0 rhs");
                convert_to_unop(ir, ir.src1.?, .copy);
                retval = true;
            }
        },

        .add_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("add_float; known float,float value");
                try convert_to_load(ir, .load_float, .{ .float = src1_def.?.data.float + src2_def.?.data.float }, errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_float and src1_def.?.data.float == 0.0) {
                log("add_float; add 0.0 lhs");
                convert_to_unop(ir, ir.src2.?, .copy);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 0.0) {
                log("add_float; add 0.0 rhs");
                convert_to_unop(ir, ir.src1.?, .copy);
                retval = true;
            }
        },

        .sub_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("sub; known int,int value");
                try convert_to_load(ir, .load_int, try src1_def.?.data.sub_int_overflow(src2_def.?.data, ir.span, errors), errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 0) {
                log("sub; sub 0 lhs");
                convert_to_unop(ir, ir.src2.?, .negate_int);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 0) {
                log("sub; sub 0 rhs");
                convert_to_unop(ir, ir.src1.?, .copy);
                retval = true;
            }
        },

        .sub_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("sub; known float,float value");
                try convert_to_load(ir, .load_float, .{ .float = src1_def.?.data.float - src2_def.?.data.float }, errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_float and src1_def.?.data.float == 0.0) {
                log("sub; sub 0.0 lhs");
                convert_to_unop(ir, ir.src2.?, .negate_float);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 0.0) {
                log("sub; sub 0.0 rhs");
                convert_to_unop(ir, ir.src1.?, .copy);
                retval = true;
            }
        },

        .mult_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("mult_int; known int,int value");
                try convert_to_load(ir, .load_int, try src1_def.?.data.mult_int_overflow(src2_def.?.data, ir.span, errors), errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 1) {
                log("mult; mult 1 lhs");
                convert_to_unop(ir, ir.src2.?, .copy);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 1) {
                log("mult; mult 1 rhs");
                convert_to_unop(ir, ir.src1.?, .copy);
                retval = true;
            } else if ((src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 0) or
                (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 0))
            {
                log("mult; mult 0 lhs int");
                try convert_to_load(ir, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .mult_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("mult_float; known float,float value");
                try convert_to_load(ir, .load_float, .{ .float = src1_def.?.data.float * src2_def.?.data.float }, errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_float and src1_def.?.data.float == 1.0) {
                log("mult; mult 1.0 lhs");
                convert_to_unop(ir, ir.src2.?, .copy);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 1.0) {
                log("mult; mult 1.0 rhs");
                convert_to_unop(ir, ir.src1.?, .copy);
                retval = true;
            } else if ((src1_def != null and src1_def.?.kind == .load_float and src1_def.?.data.float == 0.0) or
                (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 0.0))
            {
                log("mult; mult 0.0 lhs float");
                try convert_to_load(ir, .load_float, .{ .float = 0.0 }, errors);
                retval = true;
            }
        },

        .div_int => {
            try divide_by_zero_check(src2_def, errors); // Static check; divide by zero
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("div_int; known int value");
                try convert_to_load(ir, .load_int, .{ .int = @divTrunc(src1_def.?.data.int, src2_def.?.data.int) }, errors);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 1) {
                log("div; div 1 rhs");
                convert_to_unop(ir, ir.src1.?, .copy);
                retval = true;
            }
        },

        .div_float => {
            try divide_by_zero_check(src2_def, errors); // Static check; divide by zero
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("div_float; known float value");
                try convert_to_load(ir, .load_float, .{ .float = src1_def.?.data.float / src2_def.?.data.float }, errors);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 1.0) {
                log("div; div 1.0 rhs");
                convert_to_unop(ir, ir.src1.?, .copy);
                retval = true;
            }
        },

        .mod => {
            try divide_by_zero_check(src2_def, errors); // Static check; divide by zero
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("mod; known int value");
                try convert_to_load(ir, .load_int, .{ .int = @rem(src1_def.?.data.int, src2_def.?.data.int) }, errors);
                retval = true;
            } else if ((src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 0) or
                (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 1))
            {
                log("mod; mod 0 lhs");
                try convert_to_load(ir, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .get_tag => {
            if (src1_def != null and src1_def.?.kind == .load_union) {
                log("get_tag; known tag");
                try convert_to_load(ir, .load_int, .{ .int = src1_def.?.data.int }, errors); // Copy the src's tag (in data.int)
                retval = true;
            }
        },

        else => {},
    }

    if (!retval and ir.dest == null or ir.dest.?.* == .symbver) {
        // Need to make sure src1_def.dest is not assigned to in between src1_def and ir.
        //   srcn_def:        dest = ?
        //             ...
        //   recent_srcn_def: dest = ? // If this exists, then srcn_def is NOT the most up to date
        //             ...
        //   ir:              ...
        if (src1_def != null and src1_def.?.kind == .copy and src1_def.?.src1.?.* == .symbver) {
            // src1 copy propagation
            const recent_src1_def = src1_def.?.next.?.any_def_after(src1_def.?.src1.?.symbver.symbol, ir);
            if (recent_src1_def == null) {
                ir.src1 = src1_def.?.src1;
                retval = true;
            }
        } else if (src2_def != null and src2_def.?.kind == .copy and src2_def.?.src1.?.* == .symbver) {
            // src2 copy propagation
            const recent_src2_def = src2_def.?.next.?.any_def_after(src2_def.?.src1.?.symbver.symbol, ir);
            if (recent_src2_def == null) {
                ir.src2 = src2_def.?.src1;
                retval = true;
            }
        }
    }

    return retval;
}

fn copy_prop(ir: *ir_.IR, src1_def: ?*ir_.IR, kind: ir_.Kind, errors: *errs_.Errors) error{Overflow}!bool {
    if (src1_def != null and src1_def.?.kind == kind) {
        if (kind == .load_int) {
            try assert_fits(src1_def.?.data.int, ir.dest.?.get_type(), ir.span, errors);
        }
        ir.kind = kind;
        ir.data = src1_def.?.data;
        ir.span = src1_def.?.span;
        ir.src2 = src1_def.?.src2;
        ir.src1 = src1_def.?.src1;
        return true;
    } else {
        return false;
    }
}

fn assert_fits(val: i128, _type: *ast_.AST, span: span_.Span, errors: *errs_.Errors) error{Overflow}!void {
    const bounds = primitives_.bounds_from_ast(_type);
    if (bounds != null and (val < bounds.?.lower or val > bounds.?.upper)) {
        errors.add_error(errs_.Error{ .integer_out_of_bounds = .{
            .span = span,
            .expected = _type,
            .value = val,
        } });
        return error.Overflow;
    }
}

fn convert_to_load(ir: *ir_.IR, kind: ir_.Kind, data: ir_.Data, errors: *errs_.Errors) error{Overflow}!void {
    if (kind == .load_int) {
        try assert_fits(data.int, ir.dest.?.get_type(), ir.span, errors);
    }
    ir.kind = kind;
    ir.data = data;
    ir.src1 = null;
    ir.src2 = null;
}

fn convert_to_unop(ir: *ir_.IR, src1: *lval_.L_Value, kind: ir_.Kind) void {
    ir.kind = kind;
    ir.data = .none;
    ir.src1 = src1;
    ir.src2 = null;
}

fn divide_by_zero_check(ir: ?*ir_.IR, errors: *errs_.Errors) error{DivideByZero}!void {
    if (ir != null) {
        if (ir.?.kind == .load_int and ir.?.data.int == 0) {
            errors.add_error(errs_.Error{ .basic = .{
                .span = ir.?.span,
                .msg = "divide by 0",
            } });
            return error.DivideByZero;
        } else if (ir.?.kind == .load_float and ir.?.data.float == 0.0) {
            errors.add_error(errs_.Error{ .basic = .{
                .span = ir.?.span,
                .msg = "divide by 0.0",
            } });
            return error.DivideByZero;
        }
    }
}

fn remove_unused_defs(cfg: *cfg_.CFG) bool {
    var retval = false;

    calculate_usage(cfg);
    calculate_versions(cfg);

    for (cfg.basic_blocks.items) |bb| {
        var maybe_ir: ?*ir_.IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and
                !ir.removed and
                ir.dest.?.* == .symbver and
                ir.dest.?.symbver.uses == 0 and
                ir.dest.?.symbver.symbol.uses == 0 and
                ir.dest.?.symbver.symbol != cfg.return_symbol)
            {
                if (debug) {
                    std.debug.print("removing: {}", .{ir});
                }
                if (ir.kind != .call) {
                    bb.remove_instruction(ir);
                    retval = true;
                }
            }
        }
    }

    return retval;
}

fn bb_optimizations(cfg: *cfg_.CFG, allocator: std.mem.Allocator) bool {
    var retval: bool = false;

    count_predecessors(cfg);
    cfg.calculate_phi_params_and_args(allocator);
    calculate_versions(cfg);

    for (cfg.basic_blocks.items) |bb| {
        if (bb.number_predecessors == 0) {
            defer log_optimization_pass("remove unused block", cfg);
            remove_BB(cfg, bb, true);
            return true; // Perhaps mark these and remove them in a sweep pass?
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        // Adopt basic blocks with only one incoming block
        if (bb.next != null and bb.ir_head != null and !bb.has_branch and bb.next.?.number_predecessors == 1) {
            var log_msg = String.init(allocator);
            defer log_msg.deinit();
            log_msg.writer().print("adopt BB{} into BB{}", .{ bb.next.?.uid, bb.uid }) catch unreachable;
            defer log_optimization_pass(log_msg.str(), cfg);
            var end: *ir_.IR = bb.ir_head.?.get_tail();

            // Join next block at the end of this block
            end.next = bb.next.?.ir_head;
            if (bb.next.?.ir_head != null) {
                bb.next.?.ir_head.?.prev = end;
            }

            // Copy basic block end conditions
            bb.has_branch = bb.next.?.has_branch;
            bb.branch = bb.next.?.branch;
            bb.condition = bb.next.?.condition;
            bb.next_arguments = bb.next.?.next_arguments;
            bb.branch_arguments = bb.next.?.branch_arguments;

            var maybe_child: ?*ir_.IR = bb.next.?.ir_head;
            while (maybe_child) |child| : (maybe_child = child.next) {
                child.in_block = bb;
            }

            // Remove the next block
            remove_BB(cfg, bb.next.?, false);
            bb.next = bb.next.?.next;
            retval = true;
            break;
        }

        if (bb.has_branch and bb.condition.?.* == .symbver) {
            const latest_condition = bb.condition.?.symbver.def; // This is set by `propagate()`
            // Convert constant true/false branches to jumps
            if (latest_condition != null and latest_condition.?.kind == .load_int) {
                defer log_optimization_pass("convert constant true/false to jumps", cfg);
                bb.has_branch = false;
                if (bb.condition.?.symbver.def.?.data.int == 0) {
                    bb.next = bb.branch;
                    bb.next_arguments = bb.branch_arguments;
                }
                bb.branch = null;
                retval = true;
            }
            // Flip labels if branch condition is negation, plunge negation
            else if (latest_condition != null and latest_condition.?.kind == .not and latest_condition.?.src1.?.* == .symbver and
                latest_condition.?.src1.?.symbver.def != null // prevents a loop if a function parameter (which are without a def) is neg'd
            ) {
                defer log_optimization_pass("flip not condition", cfg);
                const old_branch = bb.branch.?;
                bb.branch = bb.next;
                bb.next = old_branch;
                bb.condition = latest_condition.?.src1;
                retval = true;
            }
        }

        // Remove jump chains
        if (bb.next) |next| {
            if (next.ir_head == null and !next.has_branch) {
                var s = String.init(allocator);
                s.writer().print("remove jump chain BB{}", .{next.uid}) catch unreachable;
                defer s.deinit();
                defer log_optimization_pass(s.str(), cfg);
                bb.next = next.next;
                retval = true;
            }
        }

        if (bb.branch) |branch| {
            if (branch.ir_head == null and !branch.has_branch) {
                bb.branch = branch.next;
                retval = true;
            }
        }

        if (bb.has_branch and bb.branch == bb.next) {
            bb.has_branch = false;
            retval = true;
        }

        // If next is a branch that depends on a known arugment
        if (bb.next) |next| {
            if (next.has_branch and next.ir_head == null and next.condition.?.* == .symbver) {
                defer log_optimization_pass("next depends on known argument", cfg);
                const def = bb.get_latest_def(next.condition.?, null);
                if (def != null and def.?.kind == .load_int) {
                    if (def.?.data.int == 0) {
                        bb.next = next.branch;
                    } else {
                        bb.next = next.next;
                    }
                }
            }
        }

        // If branch is a branch that depends on a known arugment
        if (bb.has_branch and
            bb.branch != null and
            bb.branch.?.has_branch and
            bb.branch.?.ir_head == null and
            bb.branch.?.condition.?.* == .symbver)
        {
            defer log_optimization_pass("branch depends on known argument", cfg);
            const def = bb.get_latest_def(bb.branch.?.condition.?, null);
            if (def != null and def.?.kind == .load_int) {
                if (def.?.data.int == 0) {
                    bb.branch = bb.branch.?.branch;
                } else {
                    bb.branch = bb.branch.?.next;
                }
            }
        }
    }

    // Rebase block graph if jump chain
    if (cfg.block_graph_head) |head| {
        if (head.ir_head == null and !head.has_branch) {
            defer log_optimization_pass("rebase block", cfg);
            cfg.block_graph_head = head.next;
            retval = true;
        }
    }

    if (retval) {
        cfg.calculate_phi_params_and_args(allocator);
    }

    return retval;
}

fn calculate_usage(cfg: *cfg_.CFG) void {
    if (cfg.symbol.decl.?.* == .fn_decl) {
        for (cfg.symbol.decl.?.fn_decl.param_symbols.items) |param_symbol| {
            param_symbol.uses = 0;
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        // Clear all used flags
        var maybe_ir: ?*ir_.IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null) {
                reset_usage_lval(ir.dest.?);
            }
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        // Arguments are default used
        for (bb.next_arguments.items) |symbver| {
            symbver.uses += 1;
        }
        for (bb.branch_arguments.items) |symbver| {
            symbver.uses += 1;
        }

        // Go through and see if each symbol is used
        var maybe_ir = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and ir.dest.?.* != .symbver) {
                calculate_usage_lval(ir.dest.?);
            }
            if (ir.src1 != null) {
                calculate_usage_lval(ir.src1.?);
            }
            if (ir.src2 != null) {
                calculate_usage_lval(ir.src2.?);
            }

            if (ir.data == .lval_list) {
                for (ir.data.lval_list.items) |lval| {
                    calculate_usage_lval(lval);
                }
            }
        }

        // Conditions are used
        if (bb.has_branch) {
            bb.condition.?.extract_symbver().uses += 1;
            bb.condition.?.extract_symbver().symbol.uses += 1;
        }
    }
}

fn reset_usage_lval(lval: *lval_.L_Value) void {
    switch (lval.*) {
        .symbver => {
            lval.symbver.uses = 0;
            lval.symbver.symbol.uses = 0;
        },
        .dereference => reset_usage_lval(lval.dereference.expr),
        .index => {
            reset_usage_lval(lval.index.lhs);
            reset_usage_lval(lval.index.rhs);
            if (lval.index.upper_bound != null) {
                reset_usage_lval(lval.index.upper_bound.?);
            }
        },
        .select => {
            reset_usage_lval(lval.select.lhs);
            if (lval.select.tag != null) {
                reset_usage_lval(lval.select.tag.?);
            }
        },
    }
}

fn calculate_usage_lval(lval: *lval_.L_Value) void {
    switch (lval.*) {
        .symbver => {
            lval.symbver.uses += 1;
            lval.symbver.symbol.uses += 1;
        },
        .dereference => calculate_usage_lval(lval.dereference.expr),
        .index => {
            calculate_usage_lval(lval.index.lhs);
            calculate_usage_lval(lval.index.rhs);
            if (lval.index.upper_bound != null) {
                calculate_usage_lval(lval.index.upper_bound.?);
            }
        },
        .select => {
            calculate_usage_lval(lval.select.lhs);
            if (lval.select.tag != null) {
                calculate_usage_lval(lval.select.tag.?);
            }
        },
    }
}

fn calculate_versions(cfg: *cfg_.CFG) void {
    for (cfg.basic_blocks.items) |bb| {
        // Reset all reachable symbol verison counts to 0
        var maybe_ir: ?*ir_.IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and ir.dest.?.* == .symbver) {
                ir.dest.?.symbver.symbol.versions = 0;
            }
            if (ir.src1 != null and ir.src1.?.* == .symbver) {
                ir.src1.?.symbver.symbol.versions = 0;
            }
            if (ir.src2 != null and ir.src2.?.* == .symbver) {
                ir.src2.?.symbver.symbol.versions = 0;
            }
        }
        cfg.return_symbol.versions = 0;
    }

    for (cfg.basic_blocks.items) |bb| {
        // Parameters define symbol versions
        for (bb.next_arguments.items) |symbver| {
            symbver.symbol.versions += 1;
        }

        // Go through sum up each definition
        var maybe_ir: ?*ir_.IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            if (ir.dest != null and ir.dest.?.* == .symbver) {
                ir.dest.?.symbver.def = ir;
                ir.dest.?.symbver.symbol.versions += 1;
            }
        }
    }
}

fn count_predecessors(cfg: *cfg_.CFG) void {
    for (cfg.basic_blocks.items) |bb| {
        bb.number_predecessors = 0;
    }
    cfg.clear_visited_BBs();
    _count_predecessors(cfg.block_graph_head orelse return);
}

fn _count_predecessors(bb: *basic_block_.Basic_Block) void {
    bb.number_predecessors += 1;
    if (bb.visited) {
        return;
    }
    bb.visited = true;
    if (bb.next) |next| {
        _count_predecessors(next);
    }
    if (bb.has_branch) {
        if (bb.branch) |branch| {
            _count_predecessors(branch);
        }
    }
}

fn remove_BB(cfg: *cfg_.CFG, bb: *basic_block_.Basic_Block, wipe_IR: bool) void {
    var i: usize = 0;
    while (i < cfg.basic_blocks.items.len) : (i += 1) {
        if (bb == cfg.basic_blocks.items[i]) {
            break;
        }
    }
    _ = cfg.basic_blocks.swapRemove(i);
    if (wipe_IR) {
        var maybe_ir: ?*ir_.IR = bb.ir_head;
        while (maybe_ir) |ir| : (maybe_ir = ir.next) {
            ir.removed = true;
        }
    }
    bb.removed = true;
}

fn log_optimization_pass(msg: []const u8, cfg: *cfg_.CFG) void {
    if (debug) {
        std.debug.print("[OPTIMIZATION] {s}\n", .{msg});
        if (cfg.block_graph_head) |block_head| {
            block_head.pprint();
            cfg.clear_visited_BBs();
            log("\n\n");
        } else {
            std.debug.print("[WARNING] block head for CFG: {s} is null\n", .{cfg.symbol.name});
        }
    }
}

fn log(msg: []const u8) void {
    if (debug) {
        std.debug.print("{s}\n", .{msg});
    }
}
