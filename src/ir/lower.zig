// Lowers an AST into a list of IR.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const cfg_ = @import("../ir/cfg.zig");
const errs_ = @import("../util/errors.zig");
const ir_ = @import("../ir/instruction.zig");
const lval_ = @import("lval.zig");
const module_ = @import("../hierarchy/module.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const String = @import("../zig-string/zig-string.zig").String;
const span_ = @import("../util/span.zig");
const symbol_ = @import("../symbol/symbol.zig");

pub const Lower_Errors = error{CompileError};

const Labels = struct {
    return_label: ?*ir_.IR,
    break_label: ?*ir_.IR,
    continue_label: ?*ir_.IR,
    error_label: ?*ir_.IR,

    const null_labels: Labels = .{ .return_label = null, .break_label = null, .continue_label = null, .error_label = null };
};

pub fn lower_AST_into_cfg(cfg: *cfg_.CFG, errors: *errs_.Errors, allocator: std.mem.Allocator) Lower_Errors!void {
    const eval: ?*lval_.L_Value = try lower_AST(cfg, cfg.symbol.init.?, Labels.null_labels, errors, allocator);
    if (cfg.symbol.decl.?.* == .fn_decl or cfg.symbol.decl.?.* == .method_decl) {
        // `_comptime` symbols don't have parameters anyway
        const param_symbols = if (cfg.symbol.decl.?.* == .fn_decl) cfg.symbol.decl.?.fn_decl.param_symbols else cfg.symbol.decl.?.method_decl.param_symbols;
        for (param_symbols.items) |param| {
            cfg.parameters.append(lval_.Symbol_Version.create_unversioned(param, allocator)) catch unreachable;
        }
    }
    const return_version = lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
    if (eval != null) {
        cfg.append_instruction(ir_.IR.init_simple_copy(return_version, eval.?, cfg.symbol.span, allocator));
    }
    cfg.append_instruction(ir_.IR.init_jump(null, cfg.symbol.span, allocator));

    if (false) {
        // Print symbol IR after lowering, before breaking up into basic blocks
        std.debug.print("CFG {s}:\n", .{cfg.symbol.name});
        var maybe_ir = cfg.ir_head;
        while (maybe_ir) |ir| {
            std.debug.print("{}", .{ir});
            maybe_ir = ir.next;
        }
        std.debug.print("\n", .{});
    }

    cfg.block_graph_head = cfg.basic_block_from_IR(cfg.ir_head, allocator);
    cfg.remove_last_instruction();

    cfg.calculate_phi_params_and_args(allocator);
}

fn lower_AST(
    cfg: *cfg_.CFG,
    ast: *ast_.AST,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!?*lval_.L_Value {
    const retval = lower_AST_inner(cfg, ast, labels, errors, allocator);
    // std.debug.print("{}\n", .{ast});
    if (false) {
        // Print symbol IR after lowering, before breaking up into basic blocks
        std.debug.print("CFG {s}:\n", .{cfg.symbol.name});
        var maybe_ir = cfg.ir_head;
        while (maybe_ir) |ir| {
            std.debug.print("{}", .{ir});
            maybe_ir = ir.next;
        }
        std.debug.print("\n", .{});
    }
    return retval;
}

fn lower_AST_inner(
    cfg: *cfg_.CFG,
    ast: *ast_.AST,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!?*lval_.L_Value {
    switch (ast.*) {
        // Straight up types, yo
        .function,
        .unit_type,
        .sum_type,
        .untagged_sum_type,
        .annotation,
        .dyn_type,
        => return lval_from_ast(ast.expand_type(allocator), cfg, allocator),
        // Unit-values
        .unit_value, .template, .trait, .impl => return lval_from_unit_value(ast, cfg, allocator),
        // Literals
        .int => return lval_from_int(ast.int.data, ast.typeof(allocator), ast.token().span, cfg, allocator),
        .char => {
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            // Convert the character inside to a codepoint
            var codepoint: u21 = undefined;
            switch (ast.token().data[1]) {
                '\\' => switch (ast.token().data[2]) {
                    'n' => codepoint = 0x0A,
                    'r' => codepoint = 0x0D,
                    't' => codepoint = 0x09,
                    '\\' => codepoint = 0x5C,
                    '\'' => codepoint = 0x27,
                    '"' => codepoint = 0x22,
                    else => unreachable,
                },
                else => {
                    const num_bytes = std.unicode.utf8ByteSequenceLength(ast.token().data[1]) catch return error.CompileError;
                    codepoint = std.unicode.utf8Decode(ast.token().data[1 .. num_bytes + 1]) catch unreachable; // Checked by lexer
                },
            }
            cfg.append_instruction(ir_.IR.init_int(temp, codepoint, ast.token().span, allocator));
            return temp;
        },
        .float => {
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            cfg.append_instruction(ir_.IR.init_float(temp, ast.float.data, ast.token().span, allocator));
            return temp;
        },
        .string => {
            const module = cfg.symbol.scope.module.?;
            const id: ir_.String_Idx = module.interned_string_set_add(ast.string.data);
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            cfg.append_instruction(ir_.IR.init_string(temp, id, ast.token().span, allocator));
            return temp;
        },
        .access, .identifier => {
            const symbol = ast.symbol().?;
            if (symbol.init_validation_state == .validating) {
                errors.add_error(errs_.Error{ .recursive_definition = .{
                    .span = symbol.span,
                    .symbol_name = symbol.name,
                } });
                return error.CompileError;
            }
            if (symbol.kind == .@"fn") {
                return try lval_from_symbol_cfg(symbol, cfg, ast.token().span, errors, allocator);
            } else if (symbol.expanded_type.?.types_match(primitives_.type_type)) {
                return lval_from_ast(ast, cfg, allocator);
            } else if (symbol.kind == .@"const") {
                return try lower_AST(cfg, symbol.init.?, labels, errors, allocator);
            } else {
                const src = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                return src;
            }
        },
        .pattern_symbol => return try lval_from_symbol_cfg(ast.symbol().?, cfg, ast.token().span, errors, allocator),
        .true => return lval_from_int(1, ast.typeof(allocator), ast.token().span, cfg, allocator),
        .false => return lval_from_int(0, ast.typeof(allocator), ast.token().span, cfg, allocator),
        // Unary operators
        .not, .negate, .addr_of, .bit_not => return try unop(ast, cfg, labels, errors, allocator),
        .dereference => {
            const expr = try lower_AST(cfg, ast.expr(), labels, errors, allocator) orelse return null;
            const expanded_type = ast.typeof(allocator).expand_type(allocator);
            const temp = expr.create_dereference_lval(expanded_type, allocator);
            return temp;
        },
        .@"try" => {
            var expr = (try lower_AST(cfg, ast.expr(), labels, errors, allocator)) orelse return null;

            const end_label = ir_.IR.init_label(cfg, ast.token().span, allocator);
            const err_label = ir_.IR.init_label(cfg, ast.token().span, allocator);

            var expanded_expr_type = expr.get_expanded_type();
            // Trying error sum, runtime check if error, branch to error path
            const condition = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
            cfg.append_instruction(ir_.IR.init_get_tag(condition, expr, ast.token().span, allocator)); // `ok` is zero, `err`s are nonzero
            cfg.append_instruction(ir_.IR.init_branch(condition, err_label, ast.token().span, allocator));

            // Unwrap the `.ok` value
            const retval_lval = lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
            cfg.append_instruction(ir_.IR.init_simple_copy(retval_lval, expr, ast.token().span, allocator));
            cfg.append_instruction(ir_.IR.init_jump(labels.error_label, ast.token().span, allocator));

            // Else, store the error in retval, return through error
            cfg.append_instruction(err_label);

            const ok_type = expanded_expr_type.get_ok_type().expand_type(allocator);
            const ok_lval = expr.create_select_lval(0, 0, ok_type, null, allocator);
            cfg.append_instruction(ir_.IR.init_jump(end_label, ast.token().span, allocator));
            cfg.append_instruction(end_label);

            return ok_lval;
        },

        // Binary operators
        .assign => {
            const rhs = try lower_AST(cfg, ast.rhs(), labels, errors, allocator);
            if (rhs == null) {
                return null;
            }
            // If product, recursively generate a series of assignments
            // Else, create a *single* copy IR with an L_Value tree
            try generate_assign(cfg, ast.lhs(), rhs.?, labels, errors, allocator);
            return lval_from_unit_value(ast, cfg, allocator);
        },

        .@"or", .@"and" => return try or_and_op(ast, cfg, labels, errors, allocator),

        .add,
        .sub,
        .mult,
        .div,
        .mod,
        .left_shift,
        .right_shift,
        .greater,
        .lesser,
        .greater_equal,
        .lesser_equal,
        => return try binop(ast, cfg, labels, errors, allocator),

        .equal, .not_equal => return try tuple_equality_check(ast, cfg, labels, errors, allocator),

        .@"catch", .@"orelse" => return try coalesce_op(ast, cfg, labels, errors, allocator),

        .bit_and, .bit_or, .bit_xor => {
            var temp: *lval_.L_Value = undefined;
            var src1 = (try lower_AST(cfg, ast.children().items[0], labels, errors, allocator)) orelse return null;

            for (1..ast.children().items.len) |i| {
                temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
                const src2 = (try lower_AST(cfg, ast.children().items[i], labels, errors, allocator)) orelse continue;
                cfg.append_instruction(ir_.IR.init(bit_ir_kind_from_ast_kind(ast), temp, src1, src2, ast.token().span, allocator));
                src1 = temp;
            }
            return temp;
        },
        .call => {
            const lhs = (try lower_AST(cfg, ast.lhs(), labels, errors, allocator)) orelse return null;
            var temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            temp.extract_symbver().symbol.span = ast.token().span;

            var ir = ir_.IR.init_call(temp, lhs, ast.token().span, allocator);
            for (ast.children().items) |term| {
                ir.data.lval_list.append((try lower_AST(cfg, term, labels, errors, allocator)) orelse continue) catch unreachable;
            }
            cfg.append_instruction(ir_.IR.init_stack_push(ast.token().span, allocator));
            cfg.append_instruction(ir);
            cfg.append_instruction(ir_.IR.init_stack_pop(ast.token().span, allocator));
            return temp;
        },
        .invoke => {
            var temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            temp.extract_symbver().symbol.span = ast.token().span;

            // dyn_value is the method receiver that will be passed in
            var dyn_value: ?*lval_.L_Value = null;
            var lval_list = std.ArrayList(*lval_.L_Value).init(allocator);
            if (ast.children().items.len == 0) {
                // dyn_value should be the receiver
                if (ast.lhs().typeof(allocator).expand_identifier().* == .dyn_type) {
                    dyn_value = (try lower_AST(cfg, ast.lhs(), labels, errors, allocator)) orelse return null;
                }
            } else {
                for (ast.children().items, 0..) |term, i| {
                    // Lower each child
                    const term_lval = (try lower_AST(cfg, term, labels, errors, allocator)) orelse continue;
                    lval_list.append(term_lval) catch unreachable;

                    // Try to find the first child, it's possibly the receiver
                    if (ast.lhs().typeof(allocator).expand_identifier().* == .dyn_type and i == 0) {
                        if (term == ast.lhs()) {
                            // UFCS-like, receiver was prepended to the children list
                            dyn_value = term_lval;
                        } else {
                            // Other wise, lower the lhs
                            dyn_value = (try lower_AST(cfg, ast.lhs(), labels, errors, allocator)) orelse continue;
                        }
                    }
                }
            }
            const ir = ir_.IR.init_invoke(temp, ast.invoke.method_decl.?, lval_list, dyn_value, ast.token().span, allocator);
            if (ast.invoke.method_decl.?.symbol() != null) {
                // Fine if symbol is null, for invokes on trait objects.
                ir.data.invoke.method_decl_lval = try lval_from_symbol_cfg(ast.invoke.method_decl.?.symbol().?, cfg, ast.token().span, errors, allocator);
            }
            cfg.append_instruction(ir_.IR.init_stack_push(ast.token().span, allocator));
            cfg.append_instruction(ir);
            cfg.append_instruction(ir_.IR.init_stack_pop(ast.token().span, allocator));
            return temp;
        },
        .dyn_value => {
            const expr = try lower_AST(cfg, ast.expr(), labels, errors, allocator) orelse return null;
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            cfg.append_instruction(ir_.IR.init_dyn(temp, expr, ast.dyn_value.mut, ast.dyn_value.impl.?, ast.token().span, allocator));
            return temp;
        },
        .index => {
            const lhs = (try lower_AST(cfg, ast.lhs(), labels, errors, allocator)) orelse return null;
            const rhs = (try lower_AST(cfg, ast.rhs(), labels, errors, allocator)) orelse return null;
            var new_lhs = lhs;

            // Get the type of the index ast. This will determine if this is an array index or a slice index
            const ast_expanded_type = ast.lhs().typeof(allocator).expand_type(allocator);
            const _type = ast.typeof(allocator);
            if (ast_expanded_type.* == .addr_of) {
                // Indexing a multi-ptr, don't change lhs
                std.debug.assert(ast_expanded_type.addr_of.multiptr);
            } else if (ast_expanded_type.* == .product and ast_expanded_type.product.was_slice) {
                // Indexing a slice; index_val := lhs._0^[rhs]
                new_lhs = new_lhs.create_select_lval(0, 0, _type.expand_type(allocator), null, allocator);
                new_lhs = new_lhs.create_dereference_lval(_type.expand_type(allocator), allocator);
            }

            // Surround with L_Value node
            const length: ?*lval_.L_Value = generate_indexable_length(cfg, lhs, ast_expanded_type, ast.token().span, allocator);
            return new_lhs.create_index_lval(rhs, length, _type.expand_type(allocator), allocator);
        },
        .select => {
            // Recursively get select's ast L_Value node
            const ast_lval = try lower_AST(cfg, ast.lhs(), labels, errors, allocator); // cannot be unreachable, since unreachable isn't selectable

            // Get the offset into the struct that this select does
            var lhs_expanded_type = ast.lhs().typeof(allocator).expand_type(allocator);
            const offset = if (lhs_expanded_type.* == .product)
                lhs_expanded_type.product.get_offset(ast.pos().?, allocator)
            else
                0;

            var tag: ?*lval_.L_Value = null;
            if (lhs_expanded_type.* == .sum_type) {
                // Check that the sum value has the proper tag before a selection
                tag = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
                cfg.append_instruction(ir_.IR.init_get_tag(tag.?, ast_lval.?, ast.token().span, allocator));
            }

            // Surround with L_Value node
            const field = ast.pos().?;
            const expanded_type = ast.typeof(allocator).expand_type(allocator);
            return ast_lval.?.create_select_lval(field, offset, expanded_type, tag, allocator);
        },
        .product => {
            if (ast.children().items[0].typeof(allocator).types_match(primitives_.type_type)) {
                return lval_from_ast(ast, cfg, allocator);
            } else {
                const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
                var ir = ir_.IR.init_load_struct(temp, ast.token().span, allocator);
                for (ast.children().items) |term| {
                    ir.data.lval_list.append((try lower_AST(cfg, term, labels, errors, allocator)) orelse return null) catch unreachable;
                }
                cfg.append_instruction(ir);
                return temp;
            }
        },
        // Fancy Operators
        .sub_slice => {
            const arr = (try lower_AST(cfg, ast.sub_slice.super, labels, errors, allocator)) orelse return null;
            const lower = (try lower_AST(cfg, ast.sub_slice.lower.?, labels, errors, allocator)) orelse return null;
            const upper = (try lower_AST(cfg, ast.sub_slice.upper.?, labels, errors, allocator)) orelse return null;

            generate_subslice_check(cfg, lower, upper, ast.token().span, allocator);

            const new_size = create_temp_lvalue(cfg, primitives_.int_type, allocator);
            cfg.append_instruction(ir_.IR.init(.sub_int, new_size, upper, lower, ast.token().span, allocator));

            const data_type = ast.typeof(allocator).children().items[0];
            const data_ptr = arr.create_select_lval(0, 0, data_type.expand_type(allocator), null, allocator);

            const new_data_ptr = create_temp_lvalue(cfg, data_type, allocator);
            cfg.append_instruction(ir_.IR.init(.add_int, new_data_ptr, data_ptr, lower, ast.token().span, allocator));

            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            var load_struct = ir_.IR.init_load_struct(temp, ast.token().span, allocator);
            load_struct.data.lval_list.append(new_data_ptr) catch unreachable;
            load_struct.data.lval_list.append(new_size) catch unreachable;
            cfg.append_instruction(load_struct);
            return temp;
        },
        .sum_value => {
            var init: ?*lval_.L_Value = null;
            const pos: usize = ast.pos().?;
            const proper_term: *ast_.AST = (ast.typeof(allocator)).children().items[pos];
            if (ast.sum_value.init != null) {
                const sum_init = try lower_AST(cfg, ast.sum_value.init.?, labels, errors, allocator);
                if (proper_term.annotation.type.* != .unit_type) { // still output the IR, but do not refer to it unless the type isn't unit
                    init = sum_init;
                }
            }
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            cfg.append_instruction(ir_.IR.init_union(temp, init, ast.pos().?, ast.token().span, allocator));
            return temp;
        },
        // Control-flow expressions
        .@"if" => {
            // Create the result symbol and labels used
            const symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
            const else_label = ir_.IR.init_label(cfg, ast.token().span, allocator);
            const end_label = ir_.IR.init_label(cfg, ast.token().span, allocator);

            // If there's a let, then do it, dumby!
            if (ast.@"if".let) |let| {
                _ = try lower_AST(cfg, let, labels, errors, allocator);
            }

            // Test condition
            try flow(ast.@"if".condition, else_label, false, cfg, ast.token().span, labels, errors, allocator);

            // lhs was true
            try generate_control_flow_block(cfg, ast.body_block(), symbol, ast.else_block() != null, labels, errors, allocator);
            // TODO: De-duplicate 1
            cfg.append_instruction(ir_.IR.init_jump(end_label, ast.token().span, allocator));

            // lhs was false
            cfg.append_instruction(else_label);
            try generate_control_flow_else(cfg, ast.else_block(), symbol, ast.token().span, labels, errors, allocator);

            cfg.append_instruction(end_label);
            return lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        },
        .match => {
            // Create the result symbol and labels used
            const symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
            const end_label = ir_.IR.init_label(cfg, ast.token().span, allocator); // Exit label of match
            const none_label = ir_.IR.init_label(cfg, ast.token().span, allocator); // jumped to if all tests fail and no `else` mapping

            if (ast.match.let) |let| { // If there's a let, then do it, dumby!
                _ = try lower_AST(cfg, let, labels, errors, allocator);
            }

            const expr = (try lower_AST(cfg, ast.expr(), labels, errors, allocator)) orelse return null;
            const rhs_label_list = try generate_match_pattern_checks(cfg, expr, ast.children().*, none_label, labels, errors, allocator);

            // Couldn't match pattern, panic!
            cfg.append_instruction(none_label);
            cfg.append_instruction(ir_.IR.init_stack_push(ast.token().span, allocator));
            cfg.append_instruction(ir_.IR.init_panic("could not match pattern", ast.token().span, allocator));

            const span = ast.token().span;
            try generate_match_bodies(cfg, expr, ast.children().*, rhs_label_list, symbol, end_label, span, labels, errors, allocator);

            cfg.append_instruction(end_label);
            return lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        },
        .@"while" => {
            // Create the result symbol and labels used
            const symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
            const cond_label = ir_.IR.init_label(cfg, ast.token().span, allocator);
            const current_continue_label = ir_.IR.init_label(cfg, ast.token().span, allocator);
            const else_label = ir_.IR.init_label(cfg, ast.token().span, allocator);
            const end_label = ir_.IR.init_label(cfg, ast.token().span, allocator);

            if (ast.@"while".let) |let| { // do `let` if there's a let
                _ = try lower_AST(cfg, let, labels, errors, allocator);
            }

            const loop_labels = .{
                .return_label = labels.return_label,
                .break_label = end_label,
                .continue_label = current_continue_label,
                .error_label = labels.error_label,
            };
            const post_labels = .{
                .return_label = labels.return_label,
                .break_label = end_label,
                .continue_label = labels.continue_label,
                .error_label = labels.error_label,
            };

            // Test condition, branch to either body or else block
            cfg.append_instruction(cond_label);
            try flow(ast.@"while".condition, else_label, false, cfg, ast.token().span, loop_labels, errors, allocator);

            // Body block
            try generate_control_flow_block(cfg, ast.body_block(), symbol, ast.else_block() != null, loop_labels, errors, allocator);

            cfg.append_instruction(current_continue_label);
            if (ast.@"while".post) |post| { // do `post` if there's a post, jump to end_label to break
                _ = try lower_AST(cfg, post, post_labels, errors, allocator);
            }
            cfg.append_instruction(ir_.IR.init_jump(cond_label, ast.token().span, allocator));

            cfg.append_instruction(else_label);
            try generate_control_flow_else(cfg, ast.else_block(), symbol, ast.token().span, labels, errors, allocator);

            cfg.append_instruction(end_label);
            return lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        },
        .block => { // TODO: TOO LONG
            if (ast.children().items.len == 0 and ast.block.final == null) {
                return lval_from_unit_value(ast, cfg, allocator);
            }

            var continue_labels = std.ArrayList(*ir_.IR).init(allocator);
            defer continue_labels.deinit();
            var break_labels = std.ArrayList(*ir_.IR).init(allocator);
            defer break_labels.deinit();
            var return_labels = std.ArrayList(*ir_.IR).init(allocator);
            defer return_labels.deinit();
            var error_labels = std.ArrayList(*ir_.IR).init(allocator);
            defer error_labels.deinit();
            for (ast.scope().?.defers.items) |_| {
                continue_labels.append(ir_.IR.init_label(cfg, ast.token().span, allocator)) catch unreachable;
                break_labels.append(ir_.IR.init_label(cfg, ast.token().span, allocator)) catch unreachable;
                return_labels.append(ir_.IR.init_label(cfg, ast.token().span, allocator)) catch unreachable;
            }
            for (ast.scope().?.errdefers.items) |_| {
                error_labels.append(ir_.IR.init_label(cfg, ast.token().span, allocator)) catch unreachable;
            }
            const end_label = ir_.IR.init_label(cfg, ast.token().span, allocator);

            // These are the labels to go to on each final statement.
            // These are updated to point to different places in the defer chain at the end of this block.
            var current_labels: Labels = labels;

            var defer_label_index: usize = 0;
            var errdefer_label_index: usize = 0;

            var temp: ?*lval_.L_Value = null;
            for (ast.children().items) |child| {
                temp = try lower_AST(cfg, child, current_labels, errors, allocator);
                if (child.* == .@"defer") {
                    current_labels.continue_label = continue_labels.items[defer_label_index];
                    current_labels.break_label = break_labels.items[defer_label_index];
                    current_labels.return_label = return_labels.items[defer_label_index];
                    defer_label_index += 1;
                } else if (child.* == .@"errdefer") {
                    current_labels.error_label = error_labels.items[errdefer_label_index];
                    errdefer_label_index += 1;
                }
            }
            if (ast.block.final) |final| {
                _ = try lower_AST(cfg, final, current_labels, errors, allocator);
            } else if (temp) |_temp| {
                wrap_error_return(_temp, cfg, ast.token().span, current_labels, allocator);
            }

            try generate_defers(cfg, &ast.scope().?.defers, &continue_labels, errors, allocator);
            cfg.append_instruction(ir_.IR.init_jump(end_label, ast.token().span, allocator));

            try generate_defers(cfg, &ast.scope().?.defers, &break_labels, errors, allocator);
            cfg.append_instruction(ir_.IR.init_jump(labels.break_label, ast.token().span, allocator));

            try generate_defers(cfg, &ast.scope().?.defers, &return_labels, errors, allocator);
            cfg.append_instruction(ir_.IR.init_jump(labels.return_label, ast.token().span, allocator));

            try generate_defers(cfg, &ast.scope().?.errdefers, &error_labels, errors, allocator);
            cfg.append_instruction(ir_.IR.init_jump(labels.error_label, ast.token().span, allocator));

            cfg.append_instruction(end_label);

            return temp;
        },

        // Control-flow statements
        .decl => {
            if (ast.decl.init) |init| {
                const def: ?*lval_.L_Value = try lower_AST(cfg, init, labels, errors, allocator);
                if (def == null) {
                    return null;
                }
                try generate_pattern(cfg, ast.decl.pattern, ast.decl.type.expand_type(allocator), def.?, errors, allocator);
            }
            return lval_from_unit_value(ast, cfg, allocator);
        },
        .fn_decl => return try lval_from_symbol_cfg(ast.symbol().?, cfg, ast.token().span, errors, allocator),
        .@"errdefer", .@"defer" => return lval_from_unit_value(ast, cfg, allocator),
        .@"continue" => {
            cfg.append_instruction(ir_.IR.init_jump(labels.continue_label, ast.token().span, allocator));
            return null;
        },
        .@"unreachable" => {
            cfg.append_instruction(ir_.IR.init_stack_push(ast.token().span, allocator));
            cfg.append_instruction(ir_.IR.init_panic("reached unreachable code", ast.token().span, allocator));
            return null;
        },
        .@"break" => {
            cfg.append_instruction(ir_.IR.init_jump(labels.break_label, ast.token().span, allocator));
            return null;
        },
        .@"return" => {
            if (ast.@"return"._ret_expr) |expr| {
                // Copy expr to retval
                const retval = (try lower_AST(cfg, expr, labels, errors, allocator)) orelse return null;
                const retval_lval = lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
                cfg.append_instruction(ir_.IR.init_simple_copy(retval_lval, retval, ast.token().span, allocator));
                wrap_error_return(retval, cfg, ast.token().span, labels, allocator);
            }
            cfg.append_instruction(ir_.IR.init_jump(labels.return_label, ast.token().span, allocator));
            return null;
        },

        else => std.debug.panic("compiler error: unimplemented lower_AST() for: AST.{s}", .{@tagName(ast.*)}),
    }
}

fn lval_from_ast(
    ast: *ast_.AST,
    cfg: *cfg_.CFG,
    allocator: std.mem.Allocator,
) *lval_.L_Value {
    const lval = create_temp_lvalue(cfg, ast, allocator);
    cfg.append_instruction(ir_.IR.init_ast(lval, ast, ast.token().span, allocator));
    return lval;
}

fn lval_from_unit_value(
    ast: *ast_.AST, // TODO: Just accept span
    cfg: *cfg_.CFG,
    allocator: std.mem.Allocator,
) *lval_.L_Value {
    const lval = create_temp_lvalue(cfg, primitives_.unit_type, allocator);
    cfg.append_instruction(ir_.IR.init(.load_unit, lval, null, null, ast.token().span, allocator));
    return lval;
}

fn lval_from_int(
    int: i128,
    _type: *ast_.AST,
    span: span_.Span,
    cfg: *cfg_.CFG,
    allocator: std.mem.Allocator,
) *lval_.L_Value {
    const temp = create_temp_lvalue(cfg, _type, allocator);
    cfg.append_instruction(ir_.IR.init_int(temp, int, span, allocator));
    return temp;
}

fn lval_from_symbol_cfg(
    symbol: *symbol_.Symbol,
    caller: *cfg_.CFG,
    span: span_.Span,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!*lval_.L_Value {
    const callee_cfg = try module_.get_cfg(symbol, caller, errors, allocator);
    callee_cfg.needed_at_runtime = callee_cfg.needed_at_runtime or (caller.symbol.scope.inner_function.?.kind == .@"fn" or
        caller.symbol.scope.inner_function.?.kind == .trait);
    const lval = create_temp_lvalue(caller, symbol._type, allocator);
    var ir = ir_.IR.init(.load_symbol, lval, null, null, span, allocator);
    ir.data = ir_.Data{ .symbol = symbol };
    caller.append_instruction(ir);
    return lval;
}

fn unop(
    ast: *ast_.AST, // TODO: Create some sort of context for these parameters?
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!?*lval_.L_Value {
    if (ast.typeof(allocator).types_match(primitives_.type_type)) {
        return lval_from_ast(ast, cfg, allocator); // for addr_of types, ex: `&T`
    }
    const expr = try lower_AST(cfg, ast.expr(), labels, errors, allocator) orelse return null;
    const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
    cfg.append_instruction(ir_.IR.init_int_float_kind(int_kind(ast), float_kind(ast), temp, expr, null, ast.token().span, allocator));
    return temp;
}

fn binop(
    ast: *ast_.AST, // TODO: Create some sort of context for these parameters?
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!?*lval_.L_Value {
    const lhs_lval = try lower_AST(cfg, ast.lhs(), labels, errors, allocator);
    const rhs_lval = try lower_AST(cfg, ast.rhs(), labels, errors, allocator);
    if (lhs_lval == null or rhs_lval == null) {
        return null;
    }
    const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
    cfg.append_instruction(ir_.IR.init_int_float_kind(int_kind(ast), float_kind(ast), temp, lhs_lval, rhs_lval, ast.token().span, allocator));
    return temp;
}

fn int_kind(ast: *ast_.AST) ir_.Kind {
    return switch (ast.*) {
        .not => .not,
        .negate => .negate_int,
        .bit_not => .bit_not,
        .addr_of => if (ast.addr_of.mut) .mut_addr_of else .addr_of,
        .add => .add_int,
        .sub => .sub_int,
        .mult => .mult_int,
        .div => .div_int,
        .mod => .mod,
        .left_shift => .left_shift,
        .right_shift => .right_shift,
        .greater => .greater_int,
        .lesser => .lesser_int,
        .greater_equal => .greater_equal_int,
        .lesser_equal => .lesser_equal_int,
        else => unreachable,
    };
}

fn float_kind(ast: *ast_.AST) ir_.Kind {
    return switch (ast.*) {
        .not => .not,
        .negate => .negate_float,
        .bit_not => .bit_not,
        .addr_of => if (ast.addr_of.mut) .mut_addr_of else .addr_of,
        .add => .add_float,
        .sub => .sub_float,
        .mult => .mult_float,
        .div => .div_float,
        .mod => .mod,
        .greater => .greater_float,
        .lesser => .lesser_float,
        .greater_equal => .greater_equal_float,
        .lesser_equal => .lesser_equal_float,
        .left_shift => .left_shift,
        .right_shift => .right_shift,
        else => unreachable,
    };
}

fn or_and_op(
    ast: *ast_.AST, // TODO: Create some sort of context for these parameters?
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!?*lval_.L_Value {
    // Create the result symbol and labels used
    const or_and_symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
    const jump_label = ir_.IR.init_label(cfg, ast.token().span, allocator);
    const end_label = ir_.IR.init_label(cfg, ast.token().span, allocator);

    const should_jump = ast.* == .@"or";

    // Test condition
    try flow(ast.lhs(), jump_label, should_jump, cfg, ast.token().span, labels, errors, allocator);
    try flow(ast.rhs(), jump_label, should_jump, cfg, ast.token().span, labels, errors, allocator);

    // never jumped, store whether that's good or not in temp
    const load_false_lval = lval_.L_Value.create_unversioned_symbver(or_and_symbol, allocator);
    cfg.append_instruction(ir_.IR.init_int(load_false_lval, if (should_jump) 0 else 1, ast.token().span, allocator));
    cfg.append_instruction(ir_.IR.init_jump(end_label, ast.token().span, allocator));

    // jumped, store whether that's good or not in temp
    cfg.append_instruction(jump_label);
    const load_true_lval = lval_.L_Value.create_unversioned_symbver(or_and_symbol, allocator);
    cfg.append_instruction(ir_.IR.init_int(load_true_lval, if (should_jump) 1 else 0, ast.token().span, allocator));

    cfg.append_instruction(end_label);
    return lval_.L_Value.create_unversioned_symbver(or_and_symbol, allocator);
}

fn tuple_equality_check(
    ast: *ast_.AST, // TODO: Create some sort of context for these parameters?
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!?*lval_.L_Value {
    std.debug.assert(ast.* == .equal or ast.* == .not_equal);
    const lhs = try lower_AST(cfg, ast.lhs(), labels, errors, allocator);
    const rhs = try lower_AST(cfg, ast.rhs(), labels, errors, allocator);
    if (lhs == null or rhs == null) {
        return null;
    }
    const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);

    // Labels used
    const fail_label = ir_.IR.init_label(cfg, ast.token().span, allocator);
    const end_label = ir_.IR.init_label(cfg, ast.token().span, allocator);

    tuple_equality_flow(cfg, lhs.?, rhs.?, fail_label, allocator);

    cfg.append_instruction(ir_.IR.init_int(temp, if (ast.* == .equal) 1 else 0, ast.token().span, allocator));
    cfg.append_instruction(ir_.IR.init_jump(end_label, ast.token().span, allocator));

    cfg.append_instruction(fail_label);
    cfg.append_instruction(ir_.IR.init_int(temp, if (ast.* == .equal) 0 else 1, ast.token().span, allocator));

    cfg.append_instruction(end_label);
    return temp;
}

fn tuple_equality_flow(
    cfg: *cfg_.CFG,
    lhs: *lval_.L_Value,
    rhs: *lval_.L_Value,
    fail_label: *ir_.IR,
    allocator: std.mem.Allocator,
) void {
    const new_lhs = lhs; // try L_Value.create_unversioned_symbver(lhs.symbol, lhs.symbol._type.?, allocator);
    const new_rhs = rhs; // try L_Value.create_unversioned_symbver(rhs.symbol, rhs.symbol._type.?, allocator);
    const temp = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
    var lhs_type = lhs.get_expanded_type();
    if (lhs_type.* == .product) {
        for (0..lhs_type.children().items.len) |field| {
            const expanded_type = lhs_type.children().items[field].expand_type(allocator);
            const offset = lhs_type.product.get_offset(field, allocator);
            const lhs_select = new_lhs.create_select_lval(field, offset, expanded_type, null, allocator);
            const rhs_select = new_rhs.create_select_lval(field, offset, expanded_type, null, allocator);
            tuple_equality_flow(cfg, lhs_select, rhs_select, fail_label, allocator);
        }
    } else if (lhs_type.* == .sum_type) {
        const lhs_tag = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
        const rhs_tag = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
        cfg.append_instruction(ir_.IR.init_get_tag(lhs_tag, new_lhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.append_instruction(ir_.IR.init_get_tag(rhs_tag, new_rhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.append_instruction(ir_.IR.init(.equal, temp, lhs_tag, rhs_tag, lhs.extract_symbver().symbol.span, allocator));
        cfg.append_instruction(ir_.IR.init_branch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
    } else {
        cfg.append_instruction(ir_.IR.init(.equal, temp, new_lhs, rhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.append_instruction(ir_.IR.init_branch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
    }
}

fn coalesce_op(
    ast: *ast_.AST, // The coalesce operator to lower
    cfg: *cfg_.CFG, // The CFG to lower the coalesce operator into
    labels: Labels, // The current labels to use
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!?*lval_.L_Value {
    // Create the result symbol and labels
    const coalesce_symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
    const zero_label = ir_.IR.init_label(cfg, ast.token().span, allocator);
    const end_label = ir_.IR.init_label(cfg, ast.token().span, allocator);

    // Test if lhs tag is 0 (`ok` or `some`)
    const lhs = (try lower_AST(cfg, ast.lhs(), labels, errors, allocator)) orelse return null;

    const condition = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
    cfg.append_instruction(ir_.IR.init_get_tag(condition, lhs, ast.token().span, allocator));
    cfg.append_instruction(ir_.IR.init_branch(condition, zero_label, ast.token().span, allocator));

    // tag was an error/none, store rhs in temp
    const maybe_rhs = (try lower_AST(cfg, ast.rhs(), labels, errors, allocator));
    if (maybe_rhs) |rhs| {
        const rhs_lval = lval_.L_Value.create_unversioned_symbver(coalesce_symbol, allocator);
        cfg.append_instruction(ir_.IR.init_simple_copy(rhs_lval, rhs, ast.token().span, allocator));
        cfg.append_instruction(ir_.IR.init_jump(end_label, ast.token().span, allocator));
    }

    // tag was `.ok` or `.some`, store lhs in temp
    cfg.append_instruction(zero_label);
    const expanded_type = ast.typeof(allocator).expand_type(allocator);
    const val = lhs.create_select_lval(0, 0, expanded_type, null, allocator);
    const ok_lval = lval_.L_Value.create_unversioned_symbver(coalesce_symbol, allocator);
    cfg.append_instruction(ir_.IR.init_simple_copy(ok_lval, val, ast.token().span, allocator));

    cfg.append_instruction(end_label);
    return lval_.L_Value.create_unversioned_symbver(coalesce_symbol, allocator);
}

fn bit_ir_kind_from_ast_kind(ast: *ast_.AST) ir_.Kind {
    return switch (ast.*) {
        .bit_and => ir_.Kind.bit_and,
        .bit_or => ir_.Kind.bit_or,
        .bit_xor => ir_.Kind.bit_xor,
        else => std.debug.panic("compiler error: not a bit ast: {s}\n", .{@tagName(ast.*)}),
    };
}

fn generate_assign(
    cfg: *cfg_.CFG, // Current control-flow-graph
    lhs: *ast_.AST, // AST node for the LHS of the `=`
    rhs: *lval_.L_Value, // L_Value which holds the value to assign
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!void {
    if (lhs.* == .product) {
        // Recursively call `generate_assign` for each term in the product.
        // product-assigns may be nested, for example:
        //     ((x, y), (a, b)) = get_tuple()
        // So it's important that this is recursive
        var lhs_expanded_type = lhs.typeof(allocator).expand_type(allocator);
        for (lhs.children().items, 0..) |term, field| {
            const product_lhs = try lower_AST(cfg, term, labels, errors, allocator);
            if (product_lhs == null) {
                continue;
            }
            const expanded_type = rhs.get_expanded_type().children().items[field].expand_type(allocator);
            const offset = lhs_expanded_type.product.get_offset(field, allocator);
            const select = rhs.create_select_lval(field, offset, expanded_type, null, allocator);
            try generate_assign(cfg, term, select, labels, errors, allocator);
        }
    } else if (lhs.* == .select and lhs.lhs().typeof(allocator).expand_type(allocator).* == .sum_type) {
        // Select on a sum-type, convert to a copy of a sum_value
        const sum_value = create_temp_lvalue(cfg, lhs.lhs().typeof(allocator).expand_type(allocator), allocator);
        cfg.append_instruction(ir_.IR.init_union(sum_value, rhs, lhs.pos().?, lhs.token().span, allocator));
        try generate_assign(cfg, lhs.lhs(), sum_value, labels, errors, allocator);
    } else {
        // Get L_Value tree, create a `copy` IR of L_Value tree and rhs
        const lval = try lower_AST(cfg, lhs, labels, errors, allocator);
        var ir = ir_.IR.init(.copy, null, rhs, null, lhs.token().span, allocator);
        ir.dest = lval;
        ir.safe = true;
        cfg.append_instruction(ir);
    }
}

/// Generates the IR to get the length of either an array or a slice. Used by indices to get the length for bounds checks
fn generate_indexable_length(
    cfg: *cfg_.CFG,
    lhs: *lval_.L_Value,
    _type: *ast_.AST,
    span: span_.Span,
    allocator: std.mem.Allocator,
) ?*lval_.L_Value {
    if (_type.* == .addr_of) {
        // Implies multiptr, unfortunately there is no way to get the length
        std.debug.assert(_type.addr_of.multiptr);
        return null;
    } else if (_type.* == .product and _type.product.was_slice) {
        const offset = _type.product.get_offset(1, allocator);
        return lhs.create_select_lval(1, offset, primitives_.int64_type, null, allocator);
    } else if (_type.* == .product and !_type.product.was_slice) {
        const retval = create_temp_lvalue(cfg, primitives_.int_type, allocator);
        cfg.append_instruction(ir_.IR.init_int(retval, _type.children().items.len, span, allocator));
        return retval;
    } else {
        std.debug.panic("compiler error: cannot generate IR to get length of type AST.{s}\n", .{@tagName(_type.*)});
    }
}

/// Generates code to verify at runtime that a subslice's lower bound is less-than-or-equal-to the subslice's upper bound.
fn generate_subslice_check(
    cfg: *cfg_.CFG,
    lower: *lval_.L_Value,
    upper: *lval_.L_Value,
    span: span_.Span,
    allocator: std.mem.Allocator,
) void {
    const end_label = ir_.IR.init_label(cfg, span, allocator);
    const compare = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
    cfg.append_instruction(ir_.IR.init(.greater_int, compare, lower, upper, span, allocator));
    cfg.append_instruction(ir_.IR.init_branch(compare, end_label, span, allocator));
    cfg.append_instruction(ir_.IR.init_stack_push(span, allocator));
    cfg.append_instruction(ir_.IR.init_panic("subslice lower bound is greater than upper bound", span, allocator));
    cfg.append_instruction(end_label);
}

/// Generates IR code to jump to `label` iff `condition` evaluates to `sense`.
fn flow(
    condition: *ast_.AST,
    label: *ir_.IR,
    sense: bool,
    cfg: *cfg_.CFG,
    span: span_.Span,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!void {
    // FIXME: High Cyclo
    switch (condition.*) {
        .true => if (sense) {
            cfg.append_instruction(ir_.IR.init_jump(label, span, allocator));
        },
        .false => if (!sense) {
            cfg.append_instruction(ir_.IR.init_jump(label, span, allocator));
        },
        .not => try flow(condition.expr(), label, !sense, cfg, span, labels, errors, allocator),
        .@"or" => if (sense) {
            try flow(condition.lhs(), label, true, cfg, span, labels, errors, allocator);
            try flow(condition.rhs(), label, true, cfg, span, labels, errors, allocator);
        } else {
            const skip_label = ir_.IR.init_label(cfg, span, allocator);
            try flow(condition.lhs(), skip_label, true, cfg, span, labels, errors, allocator);
            try flow(condition.rhs(), label, false, cfg, span, labels, errors, allocator);
            cfg.append_instruction(skip_label);
        },
        .@"and" => if (sense) {
            const skip_label = ir_.IR.init_label(cfg, span, allocator);
            try flow(condition.lhs(), skip_label, false, cfg, span, labels, errors, allocator);
            try flow(condition.rhs(), label, true, cfg, span, labels, errors, allocator);
            cfg.append_instruction(skip_label);
        } else {
            try flow(condition.lhs(), label, false, cfg, span, labels, errors, allocator);
            try flow(condition.rhs(), label, false, cfg, span, labels, errors, allocator);
        },
        else => if (sense) {
            const condition_lval = try lower_AST(cfg, condition, labels, errors, allocator) orelse return;
            const not_condition_lval = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
            cfg.append_instruction(ir_.IR.init(.not, not_condition_lval, condition_lval, null, span, allocator)); // Will be optimized out!
            cfg.append_instruction(ir_.IR.init_branch(not_condition_lval, label, span, allocator));
        } else {
            const condition_lval = try lower_AST(cfg, condition, labels, errors, allocator) orelse return;
            cfg.append_instruction(ir_.IR.init_branch(condition_lval, label, span, allocator));
        },
    }
}

/// Wraps stores to an lval in either a union or as a simple-copy
fn generate_control_flow_block(
    cfg: *cfg_.CFG,
    ast: *ast_.AST,
    symbol: *symbol_.Symbol,
    has_else: bool,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!void {
    if (try lower_AST(cfg, ast, labels, errors, allocator)) |rhs_lval| {
        const rhs_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        if (has_else) {
            cfg.append_instruction(ir_.IR.init_simple_copy(rhs_copy_lval, rhs_lval, ast.token().span, allocator));
        } else {
            cfg.append_instruction(ir_.IR.init_union(rhs_copy_lval, rhs_lval, 0, ast.token().span, allocator)); // `some` is 0
        }
    }
}

fn generate_control_flow_else(
    cfg: *cfg_.CFG,
    ast: ?*ast_.AST,
    symbol: *symbol_.Symbol,
    span: span_.Span,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!void {
    if (ast) |else_block| {
        if (try lower_AST(cfg, else_block, labels, errors, allocator)) |else_lval| {
            const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.append_instruction(ir_.IR.init_simple_copy(else_copy_lval, else_lval, span, allocator));
        }
    } else {
        // no else block => store null
        const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        cfg.append_instruction(ir_.IR.init_union(else_copy_lval, null, 1, span, allocator)); // `none` is 1
    }
}

fn generate_match_pattern_checks(
    cfg: *cfg_.CFG,
    expr: *lval_.L_Value,
    mappings: std.ArrayList(*ast_.AST),
    none_label: *ir_.IR,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!std.ArrayList(*ir_.IR) {
    var lhs_label_list = std.ArrayList(*ir_.IR).init(allocator); // labels to branch on an unsuccessful test ("next pattern")
    defer lhs_label_list.deinit();
    var rhs_label_list = std.ArrayList(*ir_.IR).init(allocator); // labels to branch on a successful test ("code for the mapping")
    errdefer rhs_label_list.deinit();
    for (mappings.items) |mapping| {
        lhs_label_list.append(ir_.IR.init_label(cfg, mapping.token().span, allocator)) catch unreachable;
        rhs_label_list.append(ir_.IR.init_label(cfg, mapping.token().span, allocator)) catch unreachable;
    }
    for (mappings.items, 0..) |mapping, i| {
        cfg.append_instruction(lhs_label_list.items[i]);
        const next_label = if (i < lhs_label_list.items.len - 1)
            lhs_label_list.items[i + 1]
        else
            none_label;
        try generate_match_pattern_check(cfg, mapping.lhs(), expr, next_label, labels, errors, allocator);
        cfg.append_instruction(ir_.IR.init_jump(rhs_label_list.items[i], mapping.token().span, allocator));
    }
    return rhs_label_list;
}

/// Generates the code which checks if the pattern matches the match expression
fn generate_match_pattern_check(
    cfg: *cfg_.CFG,
    pattern: ?*ast_.AST,
    expr: *lval_.L_Value,
    next_pattern: *ir_.IR,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!void {
    switch (pattern.?.*) {
        .pattern_symbol => {
            // Infallible check, do not branch to next pattern
        },
        .int,
        .float,
        .true,
        .false,
        .char,
        .string,
        .block,
        => {
            const value = (try lower_AST(cfg, pattern.?, labels, errors, allocator)) orelse return;
            const condition = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
            cfg.append_instruction(ir_.IR.init(.equal, condition, expr, value, pattern.?.token().span, allocator));
            cfg.append_instruction(ir_.IR.init_branch(condition, next_pattern, pattern.?.token().span, allocator));
        },
        .product => {
            for (pattern.?.children().items, 0..) |term, field| {
                const expanded_type = expr.get_expanded_type().children().items[field].expand_type(allocator);
                const pattern_type = pattern.?.typeof(allocator).expand_type(allocator);
                const offset = pattern_type.product.get_offset(field, allocator);
                const lval = expr.create_select_lval(field, offset, expanded_type, null, allocator);
                try generate_match_pattern_check(cfg, term, lval, next_pattern, labels, errors, allocator);
            }
        },
        .select, .sum_value => {
            // Get tag of pattern
            const sel = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
            cfg.append_instruction(ir_.IR.init_int(sel, pattern.?.pos().?, pattern.?.token().span, allocator));

            // Get tag of expr
            const tag = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
            cfg.append_instruction(ir_.IR.init_get_tag(tag, expr, pattern.?.token().span, allocator));

            // Compare them, jump to next pattern if they are not equal
            const neql = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
            cfg.append_instruction(ir_.IR.init(.equal, neql, tag, sel, pattern.?.token().span, allocator));
            cfg.append_instruction(ir_.IR.init_branch(neql, next_pattern, pattern.?.token().span, allocator));
        },
        else => std.debug.panic("compiler error: unimplemented generate_match_pattern_check() for {s}", .{@tagName(pattern.?.*)}),
    }
}

fn generate_match_bodies(
    cfg: *cfg_.CFG,
    expr: *lval_.L_Value,
    mappings: std.ArrayList(*ast_.AST),
    rhs_label_list: std.ArrayList(*ir_.IR),
    symbol: *symbol_.Symbol,
    end_label: *ir_.IR,
    span: span_.Span,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!void {
    for (mappings.items, 0..) |mapping, i| {
        cfg.append_instruction(rhs_label_list.items[i]);
        // Generate initialization for patterns before the rhs
        try generate_pattern(cfg, mapping.lhs(), expr.get_expanded_type(), expr, errors, allocator);

        // Generate the rhs, copy result to symbol
        if (try lower_AST(cfg, mapping.rhs(), labels, errors, allocator)) |rhs_lval| {
            const rhs_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.append_instruction(ir_.IR.init_simple_copy(rhs_copy_lval, rhs_lval, mapping.rhs().token().span, allocator));
        }
        cfg.append_instruction(ir_.IR.init_jump(end_label, span, allocator));
    }
}

fn wrap_error_return(
    expr: *lval_.L_Value,
    cfg: *cfg_.CFG,
    span: span_.Span,
    labels: Labels,
    allocator: std.mem.Allocator,
) void {
    const expanded_temp_type = expr.get_expanded_type();
    if (labels.error_label != null and expanded_temp_type.* == .sum_type and expanded_temp_type.sum_type.from == .@"error") {
        // Returning error sum, runtime check if error, branch to error path
        const condition = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
        cfg.append_instruction(ir_.IR.init_get_tag(condition, expr, span, allocator)); // `ok` is 0 `err`s nonzero
        const not_condition = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
        cfg.append_instruction(ir_.IR.init(.not, not_condition, condition, null, span, allocator));
        cfg.append_instruction(ir_.IR.init_branch(not_condition, labels.error_label, span, allocator));
    }
}

fn create_temp_lvalue(cfg: *cfg_.CFG, _type: *ast_.AST, allocator: std.mem.Allocator) *lval_.L_Value {
    const temp_symbol = create_temp_symbol(cfg, _type, allocator);
    const retval = lval_.L_Value.create_unversioned_symbver(temp_symbol, allocator);
    return retval;
}

fn create_temp_symbol(cfg: *cfg_.CFG, _type: *ast_.AST, allocator: std.mem.Allocator) *symbol_.Symbol {
    var buf = String.init_with_contents(allocator, "t") catch unreachable;
    buf.writer().print("{}", .{cfg.number_temps}) catch unreachable;
    cfg.number_temps += 1;
    var temp_symbol = symbol_.Symbol.init(
        cfg.symbol.scope,
        (buf.toOwned() catch unreachable).?,
        span_.phony_span,
        _type,
        undefined,
        null,
        .mut,
        allocator,
    );
    temp_symbol.expanded_type = _type.expand_type(allocator);
    temp_symbol.is_temp = true;
    return temp_symbol;
}

fn generate_defers(
    cfg: *cfg_.CFG,
    defers: *std.ArrayList(*ast_.AST),
    defer_labels: *std.ArrayList(*ir_.IR),
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!void {
    var i: usize = defers.items.len;
    while (i > 0) : (i -= 1) {
        cfg.append_instruction(defer_labels.items[i - 1]);
        _ = try lower_AST(cfg, defers.items[i - 1], Labels.null_labels, errors, allocator);
    }
}

/// Generates all symbol definitions in a pattern
fn generate_pattern(
    cfg: *cfg_.CFG,
    pattern: *ast_.AST,
    _type: *ast_.AST,
    def: *lval_.L_Value,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Lower_Errors!void {
    if (pattern.* == .pattern_symbol) {
        if (!std.mem.eql(u8, pattern.pattern_symbol.name, "_")) {
            const symbver = lval_.L_Value.create_unversioned_symbver(pattern.symbol().?, allocator);
            cfg.append_instruction(ir_.IR.init_simple_copy(symbver, def, pattern.token().span, allocator));
        }
    } else if (pattern.* == .product) {
        for (pattern.children().items, 0..) |term, field| {
            const expanded_type = _type.children().items[field].expand_type(allocator);
            const offset = _type.product.get_offset(field, allocator);
            const lval = def.create_select_lval(field, offset, expanded_type, null, allocator);
            try generate_pattern(cfg, term, expanded_type, lval, errors, allocator);
        }
    } else if (pattern.* == .sum_value) {
        const expanded_type = pattern.sum_value.domain.?.annotation.type.expand_type(allocator);
        const field = pattern.pos().?;
        const lval = def.create_select_lval(field, 0, expanded_type, null, allocator);
        try generate_pattern(cfg, pattern.sum_value.init.?, expanded_type, lval, errors, allocator);
    }
}
