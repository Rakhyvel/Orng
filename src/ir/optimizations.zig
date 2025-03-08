const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const CFG = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const Instruction = @import("../ir/instruction.zig");
const lval_ = @import("../ir/lval.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Span = @import("../util/span.zig");
const Symbol_Version = @import("symbol_version.zig");

var debug = false;

pub fn optimize(cfg: *CFG, errors: *errs_.Errors, allocator: std.mem.Allocator) error{CompileError}!void {
    // debug = std.mem.eql(u8, cfg.symbol.name, "main") and std.mem.eql(u8, cfg.module.package_name, "externs");
    if (debug) {
        std.debug.print("[  CFG  ]: {s}\n", .{cfg.symbol.name});
        cfg.block_graph_head.?.pprint();
        log("\n\n");
    }

    while (try propagate(cfg, errors, allocator) or
        remove_unused_defs(cfg) or
        bb_optimizations(cfg, allocator) or
        remove_unused_defs(cfg))
    {}
    cfg.clear_visited_BBs();

    log_optimization_pass("final", cfg);
}

fn propagate(cfg: *CFG, errors: *errs_.Errors, allocator: std.mem.Allocator) error{CompileError}!bool {
    var retval = false;

    cfg.calculate_definitions();
    cfg.calculate_usage();

    for (cfg.basic_blocks.items) |bb| {
        // For each BB, keep a map of symbol versions and their definitions
        var def_map = std.AutoArrayHashMap(*Symbol_Version, ?*Instruction).init(allocator);
        defer def_map.deinit();

        for (bb.instructions.items) |instr| {
            // Walk through Instruction in BB, update map of src1 and src2 defs
            const src1_def: ?*Instruction = if (instr.src1 != null and instr.src1.?.* == .symbver) def_map.get(instr.src1.?.symbver) orelse null else null;
            const src2_def: ?*Instruction = if (instr.src2 != null and instr.src2.?.* == .symbver) def_map.get(instr.src2.?.symbver) orelse null else null;
            retval = try propagate_instruction(instr, src1_def, src2_def, errors) or retval;

            if (instr.dest != null and instr.dest.?.* != .symbver) {
                def_map.put(instr.dest.?.extract_symbver(), null) catch unreachable;
            } else if (instr.kind == .mut_addr_of) {
                def_map.put(instr.src1.?.extract_symbver(), null) catch unreachable;
            }
            if (instr.dest != null and instr.dest.?.* == .symbver) {
                def_map.put(instr.dest.?.symbver, instr) catch unreachable;
            }
        }
        bb.remove_marked_instrs();
        if (bb.terminator == .conditional and bb.terminator.conditional.condition.* == .symbver) {
            const cond_def: ?*Instruction = def_map.get(bb.terminator.conditional.condition.symbver) orelse null;
            bb.terminator.conditional.condition.symbver.def = cond_def;
            if (cond_def != null and cond_def.?.kind == .copy and cond_def.?.src1 != null) {
                bb.terminator.conditional.condition = cond_def.?.src1.?;
                retval = true;
            }
        }
    }

    return retval;
}

/// May throw `error.CompileError` for integer arithmetic overflow, or `error.CompileError` when it can be
/// proven that code would divide by zero.
fn propagate_instruction(instr: *Instruction, src1_def: ?*Instruction, src2_def: ?*Instruction, errors: *errs_.Errors) error{CompileError}!bool {
    var retval = false;

    switch (instr.kind) {
        .copy => {
            const src1_def_is_ast = src1_def != null and src1_def.?.kind == .load_AST;
            if (instr.src1 == null or (instr.src1.?.expanded_type_sizeof() == 0 and !src1_def_is_ast)) {
                logfln("unit-copy elimination {?}", .{instr.src1.?.expanded_type_sizeof()});
                instr.removed = true; // Mark for deletion in a later pass
            } else if (instr.dest.?.* == .symbver and
                instr.src1.?.* == .symbver and
                instr.dest.?.symbver.symbol == instr.src1.?.symbver.symbol and
                src1_def != null)
            {
                log("self-copy elimination");
                instr.removed = true; // Mark for deletion in a later pass
                retval = true;
            } else {
                logfln("copy-propagation {?}", .{src1_def});
                retval = try copy_prop(instr, src1_def, .load_int, errors) or // TODO: Check if data fits int type bounds!
                    try copy_prop(instr, src1_def, .load_float, errors) or
                    try copy_prop(instr, src1_def, .load_string, errors) or
                    (instr.src1.?.* == .symbver and instr.src1.?.symbver.uses == 1 and try copy_prop(instr, src1_def, .load_struct, errors)) or
                    try copy_prop(instr, src1_def, .load_union, errors) or
                    try copy_prop(instr, src1_def, .load_symbol, errors) or
                    try copy_prop(instr, src1_def, .load_AST, errors) or
                    (try copy_prop(instr, src1_def, .copy, errors) and instr.src1 != src1_def.?.src1.?) or
                    try copy_prop(instr, src1_def, .addr_of, errors) or
                    try copy_prop(instr, src1_def, .mut_addr_of, errors) or
                    try copy_prop(instr, src1_def, .add_int, errors) or try copy_prop(instr, src1_def, .add_float, errors) or
                    try copy_prop(instr, src1_def, .sub_int, errors) or try copy_prop(instr, src1_def, .sub_float, errors) or
                    try copy_prop(instr, src1_def, .mult_int, errors) or try copy_prop(instr, src1_def, .mult_float, errors) or
                    try copy_prop(instr, src1_def, .div_int, errors) or try copy_prop(instr, src1_def, .div_float, errors) or
                    try copy_prop(instr, src1_def, .mod, errors);
                // DO NOT IMPLEMENT .call => propagation
            }
        },

        .not => {
            if (src1_def != null and src1_def.?.kind == .load_int) {
                log("not; known int value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.int == 0) 1 else 0 }, errors);
                retval = true;
            }
        },

        .negate_int => {
            if (src1_def != null and src1_def.?.kind == .load_int) {
                log("negate_int; known value");
                try convert_to_load(instr, .load_int, .{ .int = -src1_def.?.data.int }, errors);
                retval = true;
            }
        },

        .negate_float => {
            if (src1_def != null and src1_def.?.kind == .load_float) {
                log("negate_float; known value");
                try convert_to_load(instr, .load_float, .{ .float = -src1_def.?.data.float }, errors);
                retval = true;
            }
        },

        .equal => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("equal; known int,int value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.int == src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("equal; known float,float value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.float == src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            } else if (instr.src1.?.* == .symbver and
                instr.src2.?.* == .symbver and
                instr.src1.?.symbver.symbol == instr.src2.?.symbver.symbol and
                !instr.src1.?.symbver.symbol.expanded_type.?.can_expanded_represent_float())
            {
                // `x == x => true (where x is NOT floating-point type)`
                // NOTE: Cannot do `x == x  ==> true` optimization for floats, `NaN == NaN` is false!
                log("equal; self inequality");
                try convert_to_load(instr, .load_int, .{ .int = 1 }, errors);
                retval = true;
            }
        },

        .not_equal => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("not_equal; known int,int value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.int != src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("not_equal; known float,float value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.float != src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            } else if (instr.src1.?.* == .symbver and instr.src2.?.* == .symbver and instr.src1.?.symbver.symbol == instr.src2.?.symbver.symbol) {
                // `x != x` => `false`
                log("not_equal; self inequality");
                try convert_to_load(instr, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .greater_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("greater_int; known int,int value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.int > src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (instr.src1.?.* == .symbver and instr.src2.?.* == .symbver and instr.src1.?.symbver.symbol == instr.src2.?.symbver.symbol) {
                // `x > x` => `false`
                log("greater_int; self compare");
                try convert_to_load(instr, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .greater_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("greater_float; known float,float value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.float > src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            } else if (instr.src1.?.* == .symbver and instr.src2.?.* == .symbver and instr.src1.?.symbver.symbol == instr.src2.?.symbver.symbol) {
                // `x > x` => `false`
                log("greater_float; self compare");
                try convert_to_load(instr, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .lesser_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("lesser_int; known int,int value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.int < src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (instr.src1.?.* == .symbver and instr.src2.?.* == .symbver and instr.src1.?.symbver.symbol == instr.src2.?.symbver.symbol) {
                // `x < x` => `false`
                log("lesser_int; self compare");
                try convert_to_load(instr, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .lesser_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("lesser_float; known int,int value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.float < src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            } else if (instr.src1.?.* == .symbver and instr.src2.?.* == .symbver and instr.src1.?.symbver.symbol == instr.src2.?.symbver.symbol) {
                // `x < x` => `false`
                log("lesser_float; self compare");
                try convert_to_load(instr, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .greater_equal_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("greater_equal_int; known int,int value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.int >= src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (instr.src1.?.* == .symbver and instr.src2.?.* == .symbver and instr.src1.?.symbver.symbol == instr.src2.?.symbver.symbol) {
                // `x >= x` => `true`
                log("greater_equal_int; self compare");
                try convert_to_load(instr, .load_int, .{ .int = 1 }, errors);
                retval = true;
            }
        },

        .greater_equal_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("greater_equal_float; known float,float value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.float >= src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            }
            // NOTE: Cannot do `x >= x  ==> true` optimization for floats, `NaN >= NaN` is false!
        },

        .lesser_equal_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("lesser_equal_int; known int,int value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.int <= src2_def.?.data.int) 1 else 0 }, errors);
                retval = true;
            } else if (instr.src1.?.* == .symbver and instr.src2.?.* == .symbver and instr.src1.?.symbver.symbol == instr.src2.?.symbver.symbol) {
                // `x <= x` => `true`
                log("lesser_equal_int; self compare");
                try convert_to_load(instr, .load_int, .{ .int = 1 }, errors);
                retval = true;
            }
        },

        .lesser_equal_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("lesser_equal_float; known float,float value");
                try convert_to_load(instr, .load_int, .{ .int = if (src1_def.?.data.float <= src2_def.?.data.float) 1 else 0 }, errors);
                retval = true;
            }
            // NOTE: Cannot do `x <= x  ==> true` optimization, `NaN <= NaN` is false!
        },

        .add_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("add_int; known int,int value");
                try convert_to_load(instr, .load_int, try src1_def.?.data.add_int_overflow(src2_def.?.data), errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 0) {
                log("add_int; add 0 lhs");
                convert_to_unop(instr, instr.src2.?, .copy);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 0) {
                log("add_int; add 0 rhs");
                convert_to_unop(instr, instr.src1.?, .copy);
                retval = true;
            }
        },

        .add_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("add_float; known float,float value");
                try convert_to_load(instr, .load_float, .{ .float = src1_def.?.data.float + src2_def.?.data.float }, errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_float and src1_def.?.data.float == 0.0) {
                log("add_float; add 0.0 lhs");
                convert_to_unop(instr, instr.src2.?, .copy);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 0.0) {
                log("add_float; add 0.0 rhs");
                convert_to_unop(instr, instr.src1.?, .copy);
                retval = true;
            }
        },

        .sub_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("sub; known int,int value");
                try convert_to_load(instr, .load_int, try src1_def.?.data.sub_int_overflow(src2_def.?.data), errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 0) {
                log("sub; sub 0 lhs");
                convert_to_unop(instr, instr.src2.?, .negate_int);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 0) {
                log("sub; sub 0 rhs");
                convert_to_unop(instr, instr.src1.?, .copy);
                retval = true;
            }
        },

        .sub_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("sub; known float,float value");
                try convert_to_load(instr, .load_float, .{ .float = src1_def.?.data.float - src2_def.?.data.float }, errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_float and src1_def.?.data.float == 0.0) {
                log("sub; sub 0.0 lhs");
                convert_to_unop(instr, instr.src2.?, .negate_float);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 0.0) {
                log("sub; sub 0.0 rhs");
                convert_to_unop(instr, instr.src1.?, .copy);
                retval = true;
            }
        },

        .mult_int => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("mult_int; known int,int value");
                try convert_to_load(instr, .load_int, try src1_def.?.data.mult_int_overflow(src2_def.?.data), errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 1) {
                log("mult; mult 1 lhs");
                convert_to_unop(instr, instr.src2.?, .copy);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 1) {
                log("mult; mult 1 rhs");
                convert_to_unop(instr, instr.src1.?, .copy);
                retval = true;
            } else if ((src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 0) or
                (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 0))
            {
                log("mult; mult 0 lhs int");
                try convert_to_load(instr, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .mult_float => {
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("mult_float; known float,float value");
                try convert_to_load(instr, .load_float, .{ .float = src1_def.?.data.float * src2_def.?.data.float }, errors);
                retval = true;
            } else if (src1_def != null and src1_def.?.kind == .load_float and src1_def.?.data.float == 1.0) {
                log("mult; mult 1.0 lhs");
                convert_to_unop(instr, instr.src2.?, .copy);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 1.0) {
                log("mult; mult 1.0 rhs");
                convert_to_unop(instr, instr.src1.?, .copy);
                retval = true;
            } else if ((src1_def != null and src1_def.?.kind == .load_float and src1_def.?.data.float == 0.0) or
                (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 0.0))
            {
                log("mult; mult 0.0 lhs float");
                try convert_to_load(instr, .load_float, .{ .float = 0.0 }, errors);
                retval = true;
            }
        },

        .div_int => {
            try divide_by_zero_check(src2_def, errors); // Static check; divide by zero
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("div_int; known int value");
                try convert_to_load(instr, .load_int, .{ .int = @divTrunc(src1_def.?.data.int, src2_def.?.data.int) }, errors);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 1) {
                log("div; div 1 rhs");
                convert_to_unop(instr, instr.src1.?, .copy);
                retval = true;
            }
        },

        .div_float => {
            try divide_by_zero_check(src2_def, errors); // Static check; divide by zero
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_float and src2_def.?.kind == .load_float) {
                log("div_float; known float value");
                try convert_to_load(instr, .load_float, .{ .float = src1_def.?.data.float / src2_def.?.data.float }, errors);
                retval = true;
            } else if (src2_def != null and src2_def.?.kind == .load_float and src2_def.?.data.float == 1.0) {
                log("div; div 1.0 rhs");
                convert_to_unop(instr, instr.src1.?, .copy);
                retval = true;
            }
        },

        .mod => {
            try divide_by_zero_check(src2_def, errors); // Static check; divide by zero
            if (src1_def != null and src2_def != null and src1_def.?.kind == .load_int and src2_def.?.kind == .load_int) {
                log("mod; known int value");
                try convert_to_load(instr, .load_int, .{ .int = @rem(src1_def.?.data.int, src2_def.?.data.int) }, errors);
                retval = true;
            } else if ((src1_def != null and src1_def.?.kind == .load_int and src1_def.?.data.int == 0) or
                (src2_def != null and src2_def.?.kind == .load_int and src2_def.?.data.int == 1))
            {
                log("mod; mod 0 lhs");
                try convert_to_load(instr, .load_int, .{ .int = 0 }, errors);
                retval = true;
            }
        },

        .get_tag => {
            if (src1_def != null and src1_def.?.kind == .load_union) {
                log("get_tag; known tag");
                try convert_to_load(instr, .load_int, .{ .int = src1_def.?.data.int }, errors); // Copy the src's tag (in data.int)
                retval = true;
            }
        },

        else => {},
    }

    retval = copy_of_prop(instr, &instr.src1, src1_def) or retval;
    retval = copy_of_prop(instr, &instr.src2, src2_def) or retval;

    return retval;
}

fn copy_prop(instr: *Instruction, src1_def: ?*Instruction, kind: Instruction.Kind, errors: *errs_.Errors) error{CompileError}!bool {
    if (src1_def != null and src1_def.?.kind == kind) {
        if (kind == .load_int) {
            try assert_fits(src1_def.?.data.int, instr.dest.?.get_expanded_type(), instr.span, errors);
        }
        instr.kind = kind;
        instr.data = src1_def.?.data;
        instr.span = src1_def.?.span;
        instr.src2 = src1_def.?.src2;
        instr.src1 = src1_def.?.src1;
        return true;
    } else {
        return false;
    }
}

/// Determines if a source value can be safely replaced by its definition in the Instruction and updates the source if possible,
/// modifying src when propagation is performed.
fn copy_of_prop(instr: *Instruction, src: *?*lval_.L_Value, src_def: ?*Instruction) bool {
    if (instr.kind != .addr_of and instr.kind != .mut_addr_of and // instr is not an address, this could mess with aliasing
        src_def != null and // src has a definition
        src_def.?.kind == .copy and // src's definition is a copy of something
        src_def.?.src1.?.* == .symbver and // src's copy definition is of a plain symbver
        (src_def.?.dest.?.* != .symbver or src_def.?.src1.?.extract_symbver() != src_def.?.dest.?.extract_symbver()) // prevent self-copy
    ) {
        // Find recent version of what src's definition copies
        const src_def_redefinition = src_def.?.in_block.?.any_def_after(src_def.?, src_def.?.src1.?.symbver.symbol, instr);
        if (src_def_redefinition == null) {
            // there is no re-definition in between src's definition and this Instruction, safe to copy-propagate
            logfln("copy-of propagation: {?} => {?} {}", .{ src, src_def.?.src1, instr });
            src.* = src_def.?.src1;
            return true;
        } else {
            // there was another definition in between src's definition, cannot copy-propagate.
            // the redefinition is likely junk, too. ex: `x[3] = 4` <= here we cannot just replace `x` with `4`.
            return false;
        }
    } else {
        // src's definition isn't in a good shape to look up re-definitions. Cannot do copy-propagation.
        return false;
    }
}

/// Checks if a value fits within the bounds of a given type and reports an overflow error if it does not, modifying the
/// error list.
fn assert_fits(val: i128, _type: *ast_.AST, span: Span, errors: *errs_.Errors) error{CompileError}!void {
    const bounds = primitives_.bounds_from_ast(_type);
    if (bounds != null and (val < bounds.?.lower or val > bounds.?.upper)) {
        errors.add_error(errs_.Error{ .integer_out_of_bounds = .{
            .span = span,
            .expected = _type,
            .value = val,
        } });
        return error.CompileError;
    }
}

/// Converts a non-load Instruction to a load Instruction, with data. Performs bounds checking for load_int destination Instruction Kinds.
fn convert_to_load(instr: *Instruction, kind: Instruction.Kind, data: Instruction.Data, errors: *errs_.Errors) error{CompileError}!void {
    if (kind == .load_int) {
        try assert_fits(data.int, instr.dest.?.get_expanded_type(), instr.span, errors);
    }
    instr.kind = kind;
    instr.data = data;
    instr.src1 = null;
    instr.src2 = null;
}

/// Converts a non-unop Instruction to an unop Instruction.
fn convert_to_unop(instr: *Instruction, src1: *lval_.L_Value, kind: Instruction.Kind) void {
    instr.kind = kind;
    instr.data = .none;
    instr.src1 = src1;
    instr.src2 = null;
}

/// Checks if a div_int, div_float, or mod Instruction divides by zero
fn divide_by_zero_check(instr: ?*Instruction, errors: *errs_.Errors) error{CompileError}!void {
    if (instr != null) {
        if (instr.?.kind == .load_int and instr.?.data.int == 0) {
            errors.add_error(errs_.Error{ .basic = .{
                .span = instr.?.span,
                .msg = "divide by 0",
            } });
            return error.CompileError;
        } else if (instr.?.kind == .load_float and instr.?.data.float == 0.0) {
            errors.add_error(errs_.Error{ .basic = .{
                .span = instr.?.span,
                .msg = "divide by 0.0",
            } });
            return error.CompileError;
        }
    }
}

/// Removes unused definitions from the CFG, skipping calls and invokes (to avoid removing instructions with side
/// effects). Returns true if any instructions were removed.
/// TODO: Move to ssa file/namespace, along with the other use/def stuff
fn remove_unused_defs(cfg: *CFG) bool {
    var retval = false;

    cfg.calculate_usage();
    cfg.calculate_definitions();

    for (cfg.basic_blocks.items) |bb| {
        for (bb.instructions.items) |instr| {
            if (instr.dest != null and
                !instr.removed and
                instr.dest.?.* == .symbver and
                instr.dest.?.symbver.uses == 0 and
                instr.dest.?.symbver.symbol.uses == 0 and
                instr.dest.?.symbver.symbol != cfg.return_symbol)
            {
                logfln("removing: {}", .{instr});
                if (instr.kind != .call and instr.kind != .invoke) {
                    // Calls and invokes may have side-effects, do not remove them!
                    instr.removed = true;
                    retval = true;
                }
            }
        }
        bb.remove_marked_instrs();
    }

    return retval;
}

/// Performs various Basic Block optimizations in a CFG. Returns true if any optimizations are made.
/// TODO: Split up optimization checks into their own functions
fn bb_optimizations(cfg: *CFG, allocator: std.mem.Allocator) bool {
    // FIXME: High Cyclo
    var retval: bool = false;

    cfg.count_bb_predecessors();
    cfg.calculate_definitions();

    for (cfg.basic_blocks.items) |bb| {
        if (bb.number_predecessors == 0) {
            defer log_optimization_pass("remove unused block", cfg);
            cfg.remove_basic_block(bb);
            bb.mark_instructions_as_removed();
            return true; // Perhaps mark these and remove them in a sweep pass?
        }
    }

    for (cfg.basic_blocks.items) |bb| {
        // TODO: Too long
        // Adopt basic blocks with only one incoming block
        if (bb.terminator == .unconditional and !bb.empty() and bb.terminator.unconditional != null and bb.terminator.unconditional.?.number_predecessors == 1) {
            var log_msg = String.init(allocator);
            defer log_msg.deinit();
            log_msg.writer().print("adopt BB{} into BB{}", .{ bb.terminator.unconditional.?.uid, bb.uid }) catch unreachable;
            defer log_optimization_pass(log_msg.str(), cfg);
            cfg.remove_basic_block(bb.terminator.unconditional.?);
            bb.merge_with(bb.terminator.unconditional.?);
            retval = true;
            break;
        }

        if (bb.terminator == .conditional and bb.terminator.conditional.condition.* == .symbver) {
            const latest_condition = bb.terminator.conditional.condition.symbver.def; // This is set by `propagate()`
            // Convert constant true/false branches to jumps
            if (latest_condition != null and latest_condition.?.kind == .load_int) {
                defer log_optimization_pass("convert constant true/false to jumps", cfg);
                if (bb.terminator.conditional.condition.symbver.def.?.data.int == 0) {
                    bb.terminator = .{ .unconditional = bb.terminator.conditional.false_target };
                } else {
                    bb.terminator = .{ .unconditional = bb.terminator.conditional.true_target };
                }
                retval = true;
            }
            // Flip labels if branch condition is negation, plunge negation
            else if (latest_condition != null and latest_condition.?.kind == .not and latest_condition.?.src1.?.* == .symbver and
                latest_condition.?.src1.?.symbver.def != null // prevents a loop if a function parameter (which are without a def) is neg'd
            ) {
                defer log_optimization_pass("flip not condition", cfg);
                const old_branch = bb.terminator.conditional.false_target;
                bb.terminator.conditional.false_target = bb.terminator.conditional.true_target;
                bb.terminator.conditional.true_target = old_branch;
                bb.terminator.conditional.condition = latest_condition.?.src1.?;
                retval = true;
            }
        }

        // Remove jump chains.
        // Replace:
        //   BB1():
        //       ...
        //       jump BB2()
        //   BB2():
        //       jump BB3()
        // with:
        //   BB1():
        //       jump BB3()
        if (bb.terminator == .unconditional and bb.terminator.unconditional != null) {
            const next_bb = bb.terminator.unconditional.?;
            if (next_bb.empty() and
                next_bb.terminator == .unconditional and
                next_bb != bb and
                next_bb.terminator.unconditional != bb and
                (next_bb.terminator.unconditional == null or (next_bb.terminator.unconditional.?.terminator == .unconditional and next_bb.terminator.unconditional.?.terminator.unconditional != next_bb)))
            {
                var s = String.init(allocator);
                s.writer().print("remove jump chain BB{}", .{next_bb.uid}) catch unreachable;
                defer s.deinit();
                defer log_optimization_pass(s.str(), cfg);
                bb.terminator.unconditional = next_bb.terminator.unconditional;
                retval = true;
            }
        } // TODO: Generalize and do for unconditional jumps too

        if (bb.terminator == .conditional and bb.terminator.conditional.false_target != null) {
            const branch = bb.terminator.conditional.false_target.?;
            if (branch.empty() and branch.terminator == .unconditional) {
                bb.terminator.conditional.false_target = branch.terminator.unconditional;
                retval = true;
            }
        }

        // If a conditional branch has the same target for both true and false, convert to unconditional
        if (bb.terminator == .conditional and bb.terminator.conditional.true_target == bb.terminator.conditional.false_target) {
            bb.terminator = .{ .unconditional = bb.terminator.conditional.true_target };
            retval = true;
        }

        // If next is a branch that depends on a known arugment
        if (bb.terminator == .unconditional and bb.terminator.unconditional != null) {
            const next = bb.terminator.unconditional.?;
            if (next.terminator == .conditional and next.empty() and next.terminator.conditional.condition.* == .symbver) {
                defer log_optimization_pass("next depends on known argument", cfg);
                const def = bb.get_latest_def(next.terminator.conditional.condition, null);
                if (def != null and def.?.kind == .load_int) {
                    if (def.?.data.int == 0) {
                        bb.terminator.unconditional = next.terminator.conditional.false_target;
                    } else {
                        bb.terminator.unconditional = next.terminator.conditional.true_target;
                    }
                }
            }
        }

        // If branch is a branch that depends on a known arugment
        if (bb.terminator == .conditional and
            bb.terminator.conditional.false_target != null and
            bb.terminator.conditional.false_target.?.terminator == .conditional and
            bb.terminator.conditional.false_target.?.empty() and
            bb.terminator.conditional.false_target.?.terminator.conditional.condition.* == .symbver)
        {
            defer log_optimization_pass("branch depends on known argument", cfg);
            const def = bb.get_latest_def(bb.terminator.conditional.false_target.?.terminator.conditional.condition, null);
            if (def != null and def.?.kind == .load_int) {
                if (def.?.data.int == 0) {
                    bb.terminator.conditional.false_target = bb.terminator.conditional.false_target.?.terminator.conditional.false_target;
                } else {
                    bb.terminator.conditional.false_target = bb.terminator.conditional.false_target.?.terminator.conditional.true_target;
                }
            }
        }
    }

    // Rebase block graph if jump chain
    if (cfg.block_graph_head) |head| {
        // TODO: For this optimization to truly be effective, we'll need to see that `head` is not apart of its precedessor set
        // It's not a very important optimization though, totally cosmetic
        if (head.empty() and head.terminator == .unconditional and head.terminator.unconditional != head and head.number_predecessors == 0) {
            defer log_optimization_pass("rebase block", cfg);
            cfg.block_graph_head = head.terminator.unconditional;
            retval = true;
        }
    }

    return retval;
}

// TODO: Move this out, and into a proper logging system that's configurable from the cmd line
fn log_optimization_pass(msg: []const u8, cfg: *CFG) void {
    if (debug) {
        std.debug.print("[OPTIMIZATION] {s}\n", .{msg});
        if (cfg.block_graph_head) |block_head| {
            cfg.clear_visited_BBs();
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

fn logfln(comptime fmt: []const u8, args: anytype) void {
    if (debug) {
        std.debug.print(fmt, args);
        std.debug.print("\n", .{});
    }
}
