// Lowers an AST into a list of IR.

const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const errs_ = @import("errors.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const module_ = @import("module.zig");
const primitives_ = @import("primitives.zig");
const String = @import("zig-string/zig-string.zig").String;
const span_ = @import("span.zig");
const symbol_ = @import("symbol.zig");

const FlattenASTError = error{
    typeError,
    NotAnLValue,
    interpreter_panic,
};

const Labels = struct {
    return_label: ?*ir_.IR,
    break_label: ?*ir_.IR,
    continue_label: ?*ir_.IR,
    error_label: ?*ir_.IR,

    const null_labels: Labels = .{ .return_label = null, .break_label = null, .continue_label = null, .error_label = null };
};

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

fn create_temp_lvalue(cfg: *cfg_.CFG, _type: *ast_.AST, allocator: std.mem.Allocator) *lval_.L_Value {
    const temp_symbol = create_temp_symbol(cfg, _type, allocator);
    const retval = lval_.L_Value.create_unversioned_symbver(temp_symbol, allocator);
    return retval;
}

pub fn lower_AST_into_cfg(cfg: *cfg_.CFG, errors: *errs_.Errors, allocator: std.mem.Allocator) !void {
    const eval: ?*lval_.L_Value = try lower_AST(cfg, cfg.symbol.init, Labels.null_labels, errors, allocator);
    if (cfg.symbol.decl.?.* == .fnDecl) {
        // `_comptime` symbols don't have parameters anyway
        for (cfg.symbol.decl.?.fnDecl.param_symbols.items) |param| {
            cfg.parameters.append(lval_.Symbol_Version.createUnversioned(param, allocator)) catch unreachable;
        }
    }
    const return_version = lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
    if (eval != null) {
        cfg.appendInstruction(ir_.IR.init_simple_copy(return_version, eval.?, cfg.symbol.span, allocator));
    }
    cfg.appendInstruction(ir_.IR.initJump(null, cfg.symbol.span, allocator));

    cfg.block_graph_head = cfg.basicBlockFromIR(cfg.ir_head, allocator);
    cfg.removeBasicBlockLastInstruction();

    // for (retval.basic_blocks.items) |bb| {
    //     bb.pprint();
    // }
    // retval.clearVisitedBBs();

    cfg.calculatePhiParamsAndArgs(allocator);
}

fn lower_AST(
    cfg: *cfg_.CFG,
    ast: *ast_.AST,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!?*lval_.L_Value {
    switch (ast.*) {
        // Straight up types, yo
        .function,
        .unit_type,
        .sum,
        .annotation,
        => return lval_from_ast(ast, cfg, allocator),
        // Literals
        .unit_value => {
            const lval = create_temp_lvalue(cfg, primitives_.unit_type, allocator);
            cfg.appendInstruction(ir_.IR.init(.loadUnit, lval, null, null, ast.token().span, allocator));
            return lval;
        },
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
                    const num_bytes = std.unicode.utf8ByteSequenceLength(ast.token().data[1]) catch return error.typeError;
                    codepoint = std.unicode.utf8Decode(ast.token().data[1 .. num_bytes + 1]) catch return error.typeError; // TODO: Add actual error diagnostics here
                },
            }
            cfg.appendInstruction(ir_.IR.initInt(temp, codepoint, ast.token().span, allocator));
            return temp;
        },
        .float => {
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            cfg.appendInstruction(ir_.IR.initFloat(temp, ast.float.data, ast.token().span, allocator));
            return temp;
        },
        .string => {
            const res = cfg.interned_strings.get(ast.string.data);
            var id: usize = undefined;
            if (res) |res_| {
                id = res_;
            } else {
                id = cfg.interned_strings.count();
                cfg.interned_strings.put(ast.string.data, id) catch unreachable;
            }
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            cfg.appendInstruction(ir_.IR.initString(temp, id, ast.token().span, allocator));
            return temp;
        },
        .identifier => {
            const symbol = ast.symbol().?;
            if (symbol.kind == ._fn) {
                return try lval_from_symbol_cfg(ast.symbol().?, cfg, ast.token().span, errors, allocator);
            } else if (symbol.expanded_type.?.typesMatch(primitives_.type_type)) {
                return lval_from_ast(ast, cfg, allocator);
            } else if (symbol.kind == ._const) {
                return try lower_AST(cfg, symbol.init, labels, errors, allocator);
            } else {
                const src = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                return src;
            }
        },
        .pattern_symbol => return try lval_from_symbol_cfg(ast.symbol().?, cfg, ast.token().span, errors, allocator),
        ._true => return lval_from_int(1, ast.typeof(allocator), ast.token().span, cfg, allocator),
        ._false => return lval_from_int(0, ast.typeof(allocator), ast.token().span, cfg, allocator),
        // Unary operators
        .not, .negate, .addrOf => return try unop(ast, cfg, labels, errors, allocator),
        .dereference => {
            const expr = try lower_AST(cfg, ast.expr(), labels, errors, allocator) orelse return null;
            const _type = ast.typeof(allocator);
            const size = _type.expand_type(allocator).sizeof();
            const temp = lval_.L_Value.create_dereference(expr, size, _type, _type.expand_type(allocator), allocator);
            return temp;
        },
        ._try => {
            var expr = (try lower_AST(cfg, ast.expr(), labels, errors, allocator)) orelse return null;

            const end_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);
            const err_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);

            var expanded_expr_type = expr.get_type().expand_type(allocator);
            // Trying error sum, runtime check if error, branch to error path
            const condition = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
            cfg.appendInstruction(ir_.IR.initGetTag(condition, expr, ast.token().span, allocator)); // `ok` is zero, `err`s are nonzero
            cfg.appendInstruction(ir_.IR.initBranch(condition, err_label, ast.token().span, allocator));

            // Unwrap the `.ok` value
            const retval_lval = lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
            cfg.appendInstruction(ir_.IR.init_simple_copy(retval_lval, expr, ast.token().span, allocator));
            cfg.appendInstruction(ir_.IR.initJump(labels.error_label, ast.token().span, allocator));

            // Else, store the error in retval, return through error
            cfg.appendInstruction(err_label);

            const ok_lval = lval_.L_Value.create_select(
                expr,
                0,
                0,
                expanded_expr_type.get_ok_type().sizeof(),
                expanded_expr_type.get_ok_type(),
                expanded_expr_type.get_ok_type().expand_type(allocator),
                null,
                allocator,
            );
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.token().span, allocator));
            cfg.appendInstruction(end_label);

            return ok_lval;
        },
        .discard => {
            var expr = try lower_AST(cfg, ast.expr(), labels, errors, allocator);
            if (expr == null) {
                return null;
            }
            expr.?.extract_symbver().symbol.discard_span = ast.token().span;
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            cfg.appendInstruction(ir_.IR.initDiscard(expr.?, ast.token().span, allocator));
            return temp;
        },

        // Binary operators
        .assign => {
            const rhs = try lower_AST(cfg, ast.rhs(), labels, errors, allocator);
            if (rhs == null) {
                return null;
            }
            // If product, recursively generate a series of assignments
            // Else, create a *single* copy IR with an L_Value tree
            return try generate_assign(cfg, ast.lhs(), rhs.?, labels, errors, allocator);
        },

        ._or, ._and => return try or_and_op(ast, cfg, labels, errors, allocator),

        .add,
        .sub,
        .mult,
        .div,
        .mod,
        .greater,
        .lesser,
        .greater_equal,
        .lesser_equal,
        => return try binop(ast, cfg, labels, errors, allocator),

        .equal, .not_equal => return try tuple_equality_check(ast, cfg, labels, errors, allocator),

        ._catch, ._orelse => return try coalesce_op(ast, cfg, labels, errors, allocator),

        .call => {
            const lhs = (try lower_AST(cfg, ast.lhs(), labels, errors, allocator)) orelse return null;
            var temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            temp.extract_symbver().symbol.span = ast.token().span;

            var ir = ir_.IR.initCall(temp, lhs, ast.token().span, allocator);
            for (ast.children().items) |term| {
                ir.data.lval_list.append((try lower_AST(cfg, term, labels, errors, allocator)) orelse continue) catch unreachable;
            }
            cfg.appendInstruction(ir_.IR.initStackPush(ast.token().span, allocator));
            cfg.appendInstruction(ir);
            cfg.appendInstruction(ir_.IR.initStackPop(ast.token().span, allocator));
            return temp;
        },
        .index => {
            const lhs = (try lower_AST(cfg, ast.lhs(), labels, errors, allocator)) orelse return null;
            const rhs = (try lower_AST(cfg, ast.rhs(), labels, errors, allocator)) orelse return null;
            var new_lhs = lhs;

            // Get the type of the index ast. This will determine if this is an array index or a slice index
            const ast_expanded_type = ast.lhs().typeof(allocator).expand_type(allocator);
            const _type = ast.typeof(allocator);
            if (ast_expanded_type.product.was_slice) {
                // Indexing a slice; index_val := lhs._0^[rhs]
                const addr_type = ast_expanded_type.children().items[0];
                const addr_size = _type.expand_type(allocator).sizeof();
                new_lhs = lval_.L_Value.create_select(new_lhs, 0, 0, addr_size, addr_type, _type.expand_type(allocator), null, allocator);
                new_lhs = lval_.L_Value.create_dereference(new_lhs, addr_size, addr_type, _type.expand_type(allocator), allocator);
            }

            // Surround with L_Value node
            const length: *lval_.L_Value = generate_indexable_length(cfg, lhs, ast_expanded_type, ast.token().span, allocator);
            const size = _type.expand_type(allocator).sizeof();
            return lval_.L_Value.create_index(new_lhs, rhs, length, size, _type, _type.expand_type(allocator), allocator);
        },
        .select => {
            // Recursively get select's ast L_Value node
            const ast_lval = try lower_AST(cfg, ast.lhs(), labels, errors, allocator);

            // Get the offset into the struct that this select does
            var lhs_expanded_type = ast.lhs().typeof(allocator).expand_type(allocator);
            const offset = if (lhs_expanded_type.* == .product)
                lhs_expanded_type.product.get_offset(ast.pos().?, allocator)
            else
                lhs_expanded_type.sum.get_offset(ast.pos().?, allocator);

            var tag: ?*lval_.L_Value = null;
            if (lhs_expanded_type.* == .sum) {
                // Check that the sum value has the proper tag before a selection
                tag = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
                cfg.appendInstruction(ir_.IR.initGetTag(tag.?, ast_lval.?, ast.token().span, allocator));
            }

            // Surround with L_Value node
            const _type = ast.typeof(allocator);
            const expanded_type = _type.expand_type(allocator);
            return lval_.L_Value.create_select(
                ast_lval.?,
                ast.pos().?,
                offset,
                expanded_type.sizeof(),
                _type,
                expanded_type,
                tag,
                allocator,
            );
        },
        .product => {
            if (ast.children().items[0].typeof(allocator).typesMatch(primitives_.type_type)) {
                return lval_from_ast(ast, cfg, allocator);
            } else {
                const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
                var ir = ir_.IR.initLoadStruct(temp, ast.token().span, allocator);
                for (ast.children().items) |term| {
                    ir.data.lval_list.append((try lower_AST(cfg, term, labels, errors, allocator)) orelse return null) catch unreachable;
                }
                cfg.appendInstruction(ir);
                return temp;
            }
        },
        // Fancy Operators
        .subSlice => {
            const arr = (try lower_AST(cfg, ast.subSlice.super, labels, errors, allocator)) orelse return null;
            const lower = (try lower_AST(cfg, ast.subSlice.lower.?, labels, errors, allocator)) orelse return null;
            const upper = (try lower_AST(cfg, ast.subSlice.upper.?, labels, errors, allocator)) orelse return null;

            generate_subslice_check(cfg, lower, upper, ast.token().span, allocator);

            const new_size = create_temp_lvalue(cfg, primitives_.int_type, allocator);
            cfg.appendInstruction(ir_.IR.init(.sub_int, new_size, upper, lower, ast.token().span, allocator));

            const slice_type = ast.typeof(allocator);
            const data_type = slice_type.children().items[0];
            const size = data_type.expand_type(allocator).sizeof();
            const data_ptr = lval_.L_Value.create_select(arr, 0, 0, size, data_type, data_type.expand_type(allocator), null, allocator);

            const new_data_ptr = create_temp_lvalue(cfg, data_type, allocator);
            cfg.appendInstruction(ir_.IR.init(.add_int, new_data_ptr, data_ptr, lower, ast.token().span, allocator));

            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            var load_struct = ir_.IR.initLoadStruct(temp, ast.token().span, allocator);
            load_struct.data.lval_list.append(new_data_ptr) catch unreachable;
            load_struct.data.lval_list.append(new_size) catch unreachable;
            cfg.appendInstruction(load_struct);
            return temp;
        },
        .inferredMember => {
            var init: ?*lval_.L_Value = null;
            const pos: usize = ast.pos().?;
            const proper_term: *ast_.AST = (ast.typeof(allocator)).children().items[pos];
            if (proper_term.annotation.type.* != .unit_type) {
                init = try lower_AST(cfg, ast.inferredMember.init.?, labels, errors, allocator);
            }
            const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
            cfg.appendInstruction(ir_.IR.initUnion(temp, init, ast.pos().?, ast.token().span, allocator));
            return temp;
        },
        // Control-flow expressions
        ._if => {
            // Create the result symbol and labels used
            const symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
            const else_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);

            // If there's a let, then do it, dumby!
            if (ast._if.let) |let| {
                _ = try lower_AST(cfg, let, labels, errors, allocator);
            }

            // Test condition
            try flow(ast._if.condition, else_label, false, cfg, ast.token().span, labels, errors, allocator);

            // lhs was true
            try generate_control_flow_block(cfg, ast._if.bodyBlock, symbol, ast._if.elseBlock != null, labels, errors, allocator);
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.token().span, allocator));

            // lhs was false
            cfg.appendInstruction(else_label);
            try generate_control_flow_else(cfg, ast._if.elseBlock, symbol, ast.token().span, labels, errors, allocator);

            cfg.appendInstruction(end_label);
            return lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        },
        .match => {
            // Create the result symbol and labels used
            const symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.token().span, allocator); // Exit label of match
            const none_label = ir_.IR.initLabel(cfg, ast.token().span, allocator); // jumped to if all tests fail and no `else` mapping

            if (ast.match.let) |let| { // If there's a let, then do it, dumby!
                _ = try lower_AST(cfg, let, labels, errors, allocator);
            }

            const expr = (try lower_AST(cfg, ast.expr(), labels, errors, allocator)) orelse return null;
            const rhs_label_list = try generate_match_pattern_checks(cfg, expr, ast.children().*, none_label, labels, errors, allocator);

            if (!ast.match.has_else) { // All tests failed, no `else` mapping. Store `.none` as result
                cfg.appendInstruction(none_label);
                try generate_control_flow_else(cfg, null, symbol, ast.token().span, labels, errors, allocator);
                cfg.appendInstruction(ir_.IR.initJump(end_label, ast.token().span, allocator));
            }

            try generate_match_bodies(
                cfg,
                expr,
                ast.children().*,
                rhs_label_list,
                symbol,
                ast.match.has_else,
                end_label,
                ast.token().span,
                labels,
                errors,
                allocator,
            );

            cfg.appendInstruction(end_label);
            return lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        },
        ._while => {
            // Create the result symbol and labels used
            const symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
            const cond_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);
            const current_continue_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);
            const else_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);

            if (ast._while.let) |let| { // do `let` if there's a let
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
            cfg.appendInstruction(cond_label);
            try flow(ast._while.condition, else_label, false, cfg, ast.token().span, loop_labels, errors, allocator);

            // Body block
            try generate_control_flow_block(cfg, ast._while.bodyBlock, symbol, ast._while.elseBlock != null, loop_labels, errors, allocator);

            cfg.appendInstruction(current_continue_label);
            if (ast._while.post) |post| { // do `post` if there's a post, jump to end_label to break
                _ = try lower_AST(cfg, post, post_labels, errors, allocator);
            }
            cfg.appendInstruction(ir_.IR.initJump(cond_label, ast.token().span, allocator));

            cfg.appendInstruction(else_label);
            try generate_control_flow_else(cfg, ast._while.elseBlock, symbol, ast.token().span, labels, errors, allocator);

            cfg.appendInstruction(end_label);
            return lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        },
        .block => { // TODO: TOO LONG
            if (ast.children().items.len == 0 and ast.block.final == null) {
                return null;
            }
            var continue_labels = std.ArrayList(*ir_.IR).init(allocator);
            defer continue_labels.deinit();
            var break_labels = std.ArrayList(*ir_.IR).init(allocator);
            defer break_labels.deinit();
            var return_labels = std.ArrayList(*ir_.IR).init(allocator);
            defer return_labels.deinit();
            var error_labels = std.ArrayList(*ir_.IR).init(allocator);
            defer error_labels.deinit();
            for (ast.block.scope.?.defers.items) |_| {
                continue_labels.append(ir_.IR.initLabel(cfg, ast.token().span, allocator)) catch unreachable;
                break_labels.append(ir_.IR.initLabel(cfg, ast.token().span, allocator)) catch unreachable;
                return_labels.append(ir_.IR.initLabel(cfg, ast.token().span, allocator)) catch unreachable;
            }
            for (ast.block.scope.?.errdefers.items) |_| {
                error_labels.append(ir_.IR.initLabel(cfg, ast.token().span, allocator)) catch unreachable;
            }
            const end_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);

            // These are the labels to go to on each final statement.
            // These are updated to point to different places in the defer chain at the end of this block.
            var current_labels: Labels = labels;

            var defer_label_index: usize = 0;
            var errdefer_label_index: usize = 0;

            var temp: ?*lval_.L_Value = null;
            for (ast.children().items) |child| {
                temp = try lower_AST(cfg, child, current_labels, errors, allocator);
                if (child.* == ._defer) {
                    current_labels.continue_label = continue_labels.items[defer_label_index];
                    current_labels.break_label = break_labels.items[defer_label_index];
                    current_labels.return_label = return_labels.items[defer_label_index];
                    defer_label_index += 1;
                } else if (child.* == ._errdefer) {
                    current_labels.error_label = error_labels.items[errdefer_label_index];
                    errdefer_label_index += 1;
                }
            }
            if (ast.block.final) |final| {
                _ = try lower_AST(cfg, final, current_labels, errors, allocator);
            } else if (temp) |_temp| {
                wrap_error_return(_temp, cfg, ast.token().span, current_labels, allocator);
            }

            try generateDefers(cfg, &ast.block.scope.?.defers, &continue_labels, errors, allocator);
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.token().span, allocator));

            try generateDefers(cfg, &ast.block.scope.?.defers, &break_labels, errors, allocator);
            cfg.appendInstruction(ir_.IR.initJump(labels.break_label, ast.token().span, allocator));

            try generateDefers(cfg, &ast.block.scope.?.defers, &return_labels, errors, allocator);
            cfg.appendInstruction(ir_.IR.initJump(labels.return_label, ast.token().span, allocator));

            try generateDefers(cfg, &ast.block.scope.?.errdefers, &error_labels, errors, allocator);
            cfg.appendInstruction(ir_.IR.initJump(labels.error_label, ast.token().span, allocator));

            cfg.appendInstruction(end_label);

            return temp;
        },

        // Control-flow statements
        .decl => {
            const def: ?*lval_.L_Value = try lower_AST(cfg, ast.decl.init, labels, errors, allocator);
            if (def == null) {
                return null;
            }
            try generate_pattern(cfg, ast.decl.pattern, ast.decl.type.expand_type(allocator), def.?, errors, allocator);
            return null;
        },
        .fnDecl => return try lval_from_symbol_cfg(ast.symbol().?, cfg, ast.token().span, errors, allocator),
        ._errdefer, ._defer => return null,
        ._continue => {
            cfg.appendInstruction(ir_.IR.initJump(labels.continue_label, ast.token().span, allocator));
            return null;
        },
        ._unreachable => {
            cfg.appendInstruction(ir_.IR.initStackPush(ast.token().span, allocator));
            cfg.appendInstruction(ir_.IR.initPanic("reached unreachable code", ast.token().span, allocator));
            return null;
        },
        ._break => {
            cfg.appendInstruction(ir_.IR.initJump(labels.break_label, ast.token().span, allocator));
            return null;
        },
        ._return => {
            if (ast._return._ret_expr) |expr| {
                // Copy expr to retval
                const retval = (try lower_AST(cfg, expr, labels, errors, allocator)) orelse return null;
                const retval_lval = lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
                cfg.appendInstruction(ir_.IR.init_simple_copy(retval_lval, retval, ast.token().span, allocator));
                wrap_error_return(retval, cfg, ast.token().span, labels, allocator);
            }
            cfg.appendInstruction(ir_.IR.initJump(labels.return_label, ast.token().span, allocator));
            return null;
        },

        else => {
            std.debug.print("Unimplemented lower_AST() for: AST.{s}\n", .{@tagName(ast.*)});
            unreachable;
        },
    }
}

fn lval_from_symbol_cfg(
    symbol: *symbol_.Symbol,
    cfg: *cfg_.CFG,
    span: span_.Span,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !*lval_.L_Value {
    _ = try module_.get_cfg(symbol, cfg, cfg.interned_strings, errors, allocator);
    const lval = create_temp_lvalue(cfg, symbol._type, allocator);
    var ir = ir_.IR.init(.loadSymbol, lval, null, null, span, allocator);
    ir.data = ir_.Data{ .symbol = symbol };
    cfg.appendInstruction(ir);
    return lval;
}

fn lval_from_ast(
    ast: *ast_.AST,
    cfg: *cfg_.CFG,
    allocator: std.mem.Allocator,
) *lval_.L_Value {
    const lval = create_temp_lvalue(cfg, ast, allocator);
    cfg.appendInstruction(ir_.IR.init_ast(lval, ast, ast.token().span, allocator));
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
    cfg.appendInstruction(ir_.IR.initInt(temp, int, span, allocator));
    return temp;
}

fn unop(
    ast: *ast_.AST,
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !?*lval_.L_Value {
    if ((ast.typeof(allocator)).typesMatch(primitives_.type_type)) {
        return lval_from_ast(ast, cfg, allocator); // for addrOf
    }
    const expr = try lower_AST(cfg, ast.expr(), labels, errors, allocator) orelse return null;
    const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
    cfg.appendInstruction(ir_.IR.init_int_float_kind(int_kind(ast), float_kind(ast), temp, expr, null, ast.token().span, allocator));
    return temp;
}

fn or_and_op(
    ast: *ast_.AST,
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !?*lval_.L_Value {
    // Create the result symbol and labels used
    const or_and_symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
    const jump_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);
    const end_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);

    const should_jump = ast.* == ._or;

    // Test condition
    try flow(ast.lhs(), jump_label, should_jump, cfg, ast.token().span, labels, errors, allocator);
    try flow(ast.rhs(), jump_label, should_jump, cfg, ast.token().span, labels, errors, allocator);

    // never jumped, store whether that's good or not in temp
    const load_false_lval = lval_.L_Value.create_unversioned_symbver(or_and_symbol, allocator);
    cfg.appendInstruction(ir_.IR.initInt(load_false_lval, if (should_jump) 0 else 1, ast.token().span, allocator));
    cfg.appendInstruction(ir_.IR.initJump(end_label, ast.token().span, allocator));

    // jumped, store whether that's good or not in temp
    cfg.appendInstruction(jump_label);
    const load_true_lval = lval_.L_Value.create_unversioned_symbver(or_and_symbol, allocator);
    cfg.appendInstruction(ir_.IR.initInt(load_true_lval, if (should_jump) 1 else 0, ast.token().span, allocator));

    cfg.appendInstruction(end_label);
    return lval_.L_Value.create_unversioned_symbver(or_and_symbol, allocator);
}

fn binop(
    ast: *ast_.AST,
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !?*lval_.L_Value {
    const lhs_lval = try lower_AST(cfg, ast.lhs(), labels, errors, allocator);
    const rhs_lval = try lower_AST(cfg, ast.rhs(), labels, errors, allocator);
    if (lhs_lval == null or rhs_lval == null) {
        return null;
    }
    const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);
    cfg.appendInstruction(ir_.IR.init_int_float_kind(int_kind(ast), float_kind(ast), temp, lhs_lval, rhs_lval, ast.token().span, allocator));
    return temp;
}

fn int_kind(ast: *ast_.AST) ir_.Kind {
    return switch (ast.*) {
        .not => .not,
        .negate => .negate_int,
        .addrOf => .addrOf,
        .add => .add_int,
        .sub => .sub_int,
        .mult => .mult_int,
        .div => .div_int,
        .mod => .mod,
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
        .addrOf => .addrOf,
        .add => .add_float,
        .sub => .sub_float,
        .mult => .mult_float,
        .div => .div_float,
        .mod => .mod,
        .greater => .greater_float,
        .lesser => .lesser_float,
        .greater_equal => .greater_equal_float,
        .lesser_equal => .lesser_equal_float,
        else => unreachable,
    };
}

fn tuple_equality_check(
    ast: *ast_.AST,
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !?*lval_.L_Value {
    std.debug.assert(ast.* == .equal or ast.* == .not_equal);
    const lhs = try lower_AST(cfg, ast.lhs(), labels, errors, allocator);
    const rhs = try lower_AST(cfg, ast.rhs(), labels, errors, allocator);
    if (lhs == null or rhs == null) {
        return null;
    }
    const temp = create_temp_lvalue(cfg, ast.typeof(allocator), allocator);

    // Labels used
    const fail_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);
    const end_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);

    tuple_equality_flow(cfg, lhs.?, rhs.?, fail_label, allocator);

    cfg.appendInstruction(ir_.IR.initInt(temp, if (ast.* == .equal) 1 else 0, ast.token().span, allocator));
    cfg.appendInstruction(ir_.IR.initJump(end_label, ast.token().span, allocator));

    cfg.appendInstruction(fail_label);
    cfg.appendInstruction(ir_.IR.initInt(temp, if (ast.* == .equal) 0 else 1, ast.token().span, allocator));

    cfg.appendInstruction(end_label);
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
    var lhs_type = lhs.get_type().expand_type(allocator);
    if (lhs_type.* == .product) {
        for (0..lhs_type.children().items.len) |i| {
            const _type = lhs_type.children().items[i];
            const size = (_type.expand_type(allocator)).sizeof();
            const lhs_select = lval_.L_Value.create_select(
                new_lhs,
                i,
                lhs_type.product.get_offset(i, allocator),
                size,
                _type,
                _type.expand_type(allocator),
                null,
                allocator,
            );
            const rhs_select = lval_.L_Value.create_select(
                new_rhs,
                i,
                lhs_type.product.get_offset(i, allocator),
                size,
                _type,
                _type.expand_type(allocator),
                null,
                allocator,
            );
            tuple_equality_flow(cfg, lhs_select, rhs_select, fail_label, allocator);
        }
    } else if (lhs_type.* == .sum) {
        const lhs_tag = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
        const rhs_tag = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
        cfg.appendInstruction(ir_.IR.initGetTag(lhs_tag, new_lhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(ir_.IR.initGetTag(rhs_tag, new_rhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(ir_.IR.init(.equal, temp, lhs_tag, rhs_tag, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(ir_.IR.initBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
    } else {
        cfg.appendInstruction(ir_.IR.init(.equal, temp, new_lhs, rhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(ir_.IR.initBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
    }
}

fn coalesce_op(
    ast: *ast_.AST,
    cfg: *cfg_.CFG,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !?*lval_.L_Value {
    // Create the result symbol and labels
    const coalesce_symbol = create_temp_symbol(cfg, ast.typeof(allocator), allocator);
    const zero_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);
    const end_label = ir_.IR.initLabel(cfg, ast.token().span, allocator);

    // Test if lhs tag is 0 (`ok` or `some`)
    const lhs = (try lower_AST(cfg, ast.lhs(), labels, errors, allocator)) orelse return null;
    const condition = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
    cfg.appendInstruction(ir_.IR.initGetTag(condition, lhs, ast.token().span, allocator));
    cfg.appendInstruction(ir_.IR.initBranch(condition, zero_label, ast.token().span, allocator));

    // tag was an error/none, store rhs in temp
    const rhs = (try lower_AST(cfg, ast.rhs(), labels, errors, allocator)) orelse return null;
    const rhs_lval = lval_.L_Value.create_unversioned_symbver(coalesce_symbol, allocator);
    cfg.appendInstruction(ir_.IR.init_simple_copy(rhs_lval, rhs, ast.token().span, allocator));
    cfg.appendInstruction(ir_.IR.initJump(end_label, ast.token().span, allocator));

    // tag was `.ok` or `.some`, store lhs in temp
    cfg.appendInstruction(zero_label);
    const _type = ast.typeof(allocator);
    const size = _type.expand_type(allocator).sizeof();
    const val = lval_.L_Value.create_select(lhs, 0, 0, size, _type, _type.expand_type(allocator), null, allocator);
    const ok_lval = lval_.L_Value.create_unversioned_symbver(coalesce_symbol, allocator);
    cfg.appendInstruction(ir_.IR.init_simple_copy(ok_lval, val, ast.token().span, allocator));

    cfg.appendInstruction(end_label);
    return lval_.L_Value.create_unversioned_symbver(coalesce_symbol, allocator);
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
) !void {
    switch (condition.*) {
        ._true => if (sense) {
            cfg.appendInstruction(ir_.IR.initJump(label, span, allocator));
        },
        ._false => if (!sense) {
            cfg.appendInstruction(ir_.IR.initJump(label, span, allocator));
        },
        .not => try flow(condition.expr(), label, !sense, cfg, span, labels, errors, allocator),
        ._or => if (sense) {
            try flow(condition.lhs(), label, true, cfg, span, labels, errors, allocator);
            try flow(condition.rhs(), label, true, cfg, span, labels, errors, allocator);
        } else {
            const skip_label = ir_.IR.initLabel(cfg, span, allocator);
            try flow(condition.lhs(), skip_label, true, cfg, span, labels, errors, allocator);
            try flow(condition.rhs(), label, false, cfg, span, labels, errors, allocator);
            cfg.appendInstruction(skip_label);
        },
        ._and => if (sense) {
            const skip_label = ir_.IR.initLabel(cfg, span, allocator);
            try flow(condition.lhs(), skip_label, false, cfg, span, labels, errors, allocator);
            try flow(condition.rhs(), label, true, cfg, span, labels, errors, allocator);
            cfg.appendInstruction(skip_label);
        } else {
            try flow(condition.lhs(), label, false, cfg, span, labels, errors, allocator);
            try flow(condition.rhs(), label, false, cfg, span, labels, errors, allocator);
        },
        else => if (sense) {
            const condition_lval = try lower_AST(cfg, condition, labels, errors, allocator) orelse return;
            const not_condition_lval = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
            cfg.appendInstruction(ir_.IR.init(.not, not_condition_lval, condition_lval, null, span, allocator)); // Will be optimized out!
            cfg.appendInstruction(ir_.IR.initBranch(not_condition_lval, label, span, allocator));
        } else {
            const condition_lval = try lower_AST(cfg, condition, labels, errors, allocator) orelse return;
            cfg.appendInstruction(ir_.IR.initBranch(condition_lval, label, span, allocator));
        },
    }
}

fn generate_assign(
    cfg: *cfg_.CFG, // Current control-flow-graph
    lhs: *ast_.AST, // AST node for the LHS of the `=`
    rhs: *lval_.L_Value, // L_Value which holds the value to assign
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!?*lval_.L_Value // If assign is to a single symbver, returns the symbver
{
    if (lhs.* == .product) {
        // Recursively call `generate_assign` for each term in the product.
        // product-assigns may be nested, for example:
        //     ((x, y), (a, b)) = get_tuple()
        // So it's important that this is recursive
        var lhs_expanded_type = lhs.typeof(allocator).expand_type(allocator);
        for (lhs.children().items, 0..) |term, i| {
            const product_lhs = try lower_AST(cfg, term, labels, errors, allocator);
            if (product_lhs == null) {
                continue;
            }
            const _type = rhs.get_type().children().items[i];
            const size = _type.expand_type(allocator).sizeof();
            const select = lval_.L_Value.create_select(
                rhs,
                i,
                lhs_expanded_type.product.get_offset(i, allocator),
                size,
                _type,
                _type.expand_type(allocator),
                null,
                allocator,
            );
            _ = try generate_assign(cfg, term, select, labels, errors, allocator);
        }
        return null;
    } else {
        // Get L_Value tree, create a `copy` IR of L_Value tree and rhs
        const lval = try lower_AST(cfg, lhs, labels, errors, allocator);
        var ir = ir_.IR.init(.copy, null, rhs, null, lhs.token().span, allocator);
        ir.dest = lval;
        ir.safe = true;
        cfg.appendInstruction(ir);
        return null;
    }
}

fn generate_pattern(
    cfg: *cfg_.CFG,
    pattern: *ast_.AST,
    _type: *ast_.AST,
    def: *lval_.L_Value,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!void {
    if (pattern.* == .pattern_symbol) {
        if (!std.mem.eql(u8, pattern.pattern_symbol.name, "_")) {
            const symbver = lval_.L_Value.create_unversioned_symbver(pattern.symbol().?, allocator);
            cfg.appendInstruction(ir_.IR.init_simple_copy(symbver, def, pattern.token().span, allocator));
        }
    } else if (pattern.* == .product) {
        for (pattern.children().items, 0..) |term, i| {
            const subscript_type = _type.children().items[i];
            const size = subscript_type.expand_type(allocator).sizeof();
            const offset = _type.product.get_offset(i, allocator);
            const lval = lval_.L_Value.create_select(
                def,
                i,
                offset,
                size,
                subscript_type,
                subscript_type.expand_type(allocator),
                null,
                allocator,
            );
            try generate_pattern(cfg, term, subscript_type, lval, errors, allocator);
        }
    } else if (pattern.* == .inject) {
        const domain = pattern.inject.domain.?;
        const size = domain.expand_type(allocator).sizeof();
        const lval = lval_.L_Value.create_select(
            def,
            pattern.lhs().pos().?,
            0,
            size,
            domain,
            domain.expand_type(allocator),
            null,
            allocator,
        );
        try generate_pattern(cfg, pattern.rhs(), domain, lval, errors, allocator);
    }
}

/// Generates the IR to get the length of either an array or a slice. Used by indices to get the length for bounds checks
fn generate_indexable_length(
    cfg: *cfg_.CFG,
    lhs: *lval_.L_Value,
    _type: *ast_.AST,
    span: span_.Span,
    allocator: std.mem.Allocator,
) *lval_.L_Value {
    if (_type.* == .product and _type.product.was_slice) {
        const offset = _type.product.get_offset(1, allocator);
        return lval_.L_Value.create_select(lhs, 1, offset, 8, primitives_.int64_type, primitives_.int64_type, null, allocator);
    } else if (_type.* == .product and !_type.product.was_slice) {
        const retval = create_temp_lvalue(cfg, primitives_.int_type, allocator);
        cfg.appendInstruction(ir_.IR.initInt(retval, _type.children().items.len, span, allocator));
        return retval;
    } else {
        unreachable;
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
    const end_label = ir_.IR.initLabel(cfg, span, allocator);
    const compare = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
    cfg.appendInstruction(ir_.IR.init(.greater_int, compare, lower, upper, span, allocator));
    cfg.appendInstruction(ir_.IR.initBranch(compare, end_label, span, allocator));
    cfg.appendInstruction(ir_.IR.initStackPush(span, allocator));
    cfg.appendInstruction(ir_.IR.initPanic("subslice lower bound is greater than upper bound", span, allocator));
    cfg.appendInstruction(end_label);
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
) !void {
    if (try lower_AST(cfg, ast, labels, errors, allocator)) |rhs_lval| {
        const rhs_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        if (has_else) {
            cfg.appendInstruction(ir_.IR.init_simple_copy(rhs_copy_lval, rhs_lval, ast.token().span, allocator));
        } else {
            cfg.appendInstruction(ir_.IR.initUnion(rhs_copy_lval, rhs_lval, 0, ast.token().span, allocator)); // `some` is 0
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
) !void {
    if (ast) |elseBlock| {
        if (try lower_AST(cfg, elseBlock, labels, errors, allocator)) |else_lval| {
            const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(ir_.IR.init_simple_copy(else_copy_lval, else_lval, span, allocator));
        }
    } else {
        // no else block => store null
        const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
        cfg.appendInstruction(ir_.IR.initUnion(else_copy_lval, null, 1, span, allocator)); // `none` is 1
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
) !std.ArrayList(*ir_.IR) {
    var lhs_label_list = std.ArrayList(*ir_.IR).init(allocator); // labels to branch on an unsuccessful test ("next pattern")
    defer lhs_label_list.deinit();
    var rhs_label_list = std.ArrayList(*ir_.IR).init(allocator); // labels to branch on a successful test ("code for the mapping")
    errdefer rhs_label_list.deinit();
    for (mappings.items) |mapping| {
        lhs_label_list.append(ir_.IR.initLabel(cfg, mapping.token().span, allocator)) catch unreachable;
        rhs_label_list.append(ir_.IR.initLabel(cfg, mapping.token().span, allocator)) catch unreachable;
    }
    for (mappings.items, 0..) |mapping, i| {
        cfg.appendInstruction(lhs_label_list.items[i]);
        if (mapping.mapping_lhs()) |lhs| {
            const next_label = if (i < lhs_label_list.items.len - 1)
                lhs_label_list.items[i + 1]
            else
                none_label;
            try generate_match_pattern_check(cfg, lhs, expr, next_label, labels, errors, allocator);
        }
        cfg.appendInstruction(ir_.IR.initJump(rhs_label_list.items[i], mapping.token().span, allocator));
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
) FlattenASTError!void {
    if (pattern == null) {
        // Implies `else` branch, infallible.
        return;
    }
    switch (pattern.?.*) {
        .pattern_symbol => {}, // Infallible check, do not branch to next pattern
        .int,
        .float,
        ._true,
        ._false,
        .char,
        .string,
        .block,
        => {
            const value = try lower_AST(cfg, pattern.?, labels, errors, allocator);
            const condition = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
            cfg.appendInstruction(ir_.IR.init(.equal, condition, expr, value.?, pattern.?.token().span, allocator));
            cfg.appendInstruction(ir_.IR.initBranch(condition, next_pattern, pattern.?.token().span, allocator));
        },
        .product => {
            for (pattern.?.children().items, 0..) |term, i| {
                const subscript_type = expr.get_type().children().items[i];
                const size = subscript_type.expand_type(allocator).sizeof();
                const pattern_type = pattern.?.typeof(allocator).expand_type(allocator);
                const offset = pattern_type.product.get_offset(i, allocator);
                const lval = lval_.L_Value.create_select(
                    expr,
                    i,
                    offset,
                    size,
                    subscript_type,
                    subscript_type.expand_type(allocator),
                    null,
                    allocator,
                );
                try generate_match_pattern_check(cfg, term, lval, next_pattern, labels, errors, allocator);
            }
        },
        .select, .inferredMember => {
            // Get tag of pattern
            const sel = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
            cfg.appendInstruction(ir_.IR.initInt(sel, pattern.?.pos().?, pattern.?.token().span, allocator));

            // Get tag of expr
            const tag = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
            cfg.appendInstruction(ir_.IR.initGetTag(tag, expr, pattern.?.token().span, allocator));

            // Compare them, jump to next pattern if they are not equal
            const neql = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
            cfg.appendInstruction(ir_.IR.init(.equal, neql, tag, sel, pattern.?.token().span, allocator));
            cfg.appendInstruction(ir_.IR.initBranch(neql, next_pattern, pattern.?.token().span, allocator));
        },
        .inject => {
            try generate_match_pattern_check(cfg, pattern.?.lhs(), expr, next_pattern, labels, errors, allocator);
        },
        else => {
            std.debug.print("Unimplemented generate_match_pattern_check() for {s}\n", .{@tagName(pattern.?.*)});
            unreachable;
        },
    }
}

fn generate_match_bodies(
    cfg: *cfg_.CFG,
    expr: *lval_.L_Value,
    mappings: std.ArrayList(*ast_.AST),
    rhs_label_list: std.ArrayList(*ir_.IR),
    symbol: *symbol_.Symbol,
    has_else: bool,
    end_label: *ir_.IR,
    span: span_.Span,
    labels: Labels,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !void {
    for (mappings.items, 0..) |mapping, i| {
        cfg.appendInstruction(rhs_label_list.items[i]);
        if (mapping.mapping_lhs()) |lhs| {
            // Generate initialization for patterns before the rhs
            try generate_pattern(cfg, lhs, expr.get_type(), expr, errors, allocator);
        }

        // Generate the rhs, copy result to symbol
        try generate_control_flow_block(cfg, mapping.rhs(), symbol, has_else, labels, errors, allocator);
        cfg.appendInstruction(ir_.IR.initJump(end_label, span, allocator));
    }
}

fn wrap_error_return(
    expr: *lval_.L_Value,
    cfg: *cfg_.CFG,
    span: span_.Span,
    labels: Labels,
    allocator: std.mem.Allocator,
) void {
    const expanded_temp_type = expr.get_type().expand_type(allocator);
    if (labels.error_label != null and expanded_temp_type.* == .sum and expanded_temp_type.sum.was_error) {
        // Returning error sum, runtime check if error, branch to error path
        const condition = create_temp_lvalue(cfg, primitives_.word64_type, allocator);
        cfg.appendInstruction(ir_.IR.initGetTag(condition, expr, span, allocator)); // `ok` is 0 `err`s nonzero
        const not_condition = create_temp_lvalue(cfg, primitives_.bool_type, allocator);
        cfg.appendInstruction(ir_.IR.init(.not, not_condition, condition, null, span, allocator));
        cfg.appendInstruction(ir_.IR.initBranch(not_condition, labels.error_label, span, allocator));
    }
}

fn generateDefers(
    cfg: *cfg_.CFG,
    defers: *std.ArrayList(*ast_.AST),
    deferLabels: *std.ArrayList(*ir_.IR),
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!void {
    var i: usize = defers.items.len;
    while (i > 0) : (i -= 1) {
        cfg.appendInstruction(deferLabels.items[i - 1]);
        _ = try lower_AST(cfg, defers.items[i - 1], Labels.null_labels, errors, allocator);
    }
}
