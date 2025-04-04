// Lowers an AST into a list of Instruction.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const Basic_Block = @import("../ir/basic-block.zig");
const CFG = @import("../ir/cfg.zig");
const cfg_builder_ = @import("../ir/cfg_builder.zig");
const errs_ = @import("../util/errors.zig");
const Interned_String_Set = @import("../ir/interned_string_set.zig");
const Instruction = @import("../ir/instruction.zig");
const lval_ = @import("lval.zig");
const module_ = @import("../hierarchy/module.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Span = @import("../util/span.zig");
const Symbol = @import("../symbol/symbol.zig");
const Symbol_Version = @import("symbol_version.zig");

pub const Lower_Errors = error{CompileError};

const Self = @This();

instructions: std.ArrayList(*Instruction),
interned_strings: *Interned_String_Set,
errors: *errs_.Errors,
allocator: std.mem.Allocator,
cfg: *CFG,
number_temps: usize = 0,

const Labels = struct {
    return_label: ?*Instruction,
    break_label: ?*Instruction,
    continue_label: ?*Instruction,
    error_label: ?*Instruction,

    const null_labels: Labels = .{ .return_label = null, .break_label = null, .continue_label = null, .error_label = null };
};

pub fn init(cfg: *CFG, interned_strings: *Interned_String_Set, errors: *errs_.Errors, allocator: std.mem.Allocator) Self {
    return Self{
        .instructions = std.ArrayList(*Instruction).init(allocator),
        .interned_strings = interned_strings,
        .errors = errors,
        .allocator = allocator,
        .cfg = cfg,
    };
}

pub fn lower_AST_into_cfg(self: *Self) Lower_Errors!void {
    const eval: ?*lval_.L_Value = try self.lower_AST(self.cfg.symbol.init_value.?, Labels.null_labels);
    if (self.cfg.symbol.decl.?.* == .fn_decl or self.cfg.symbol.decl.?.* == .method_decl) {
        // `_comptime` symbols don't have parameters anyway
        const param_symbols = if (self.cfg.symbol.decl.?.* == .fn_decl) self.cfg.symbol.decl.?.fn_decl.param_symbols else self.cfg.symbol.decl.?.method_decl.param_symbols;
        for (param_symbols.items) |param| {
            self.cfg.parameters.append(Symbol_Version.create_unversioned(param, self.allocator)) catch unreachable;
        }
    }
    const return_version = lval_.L_Value.create_unversioned_symbver(self.cfg.return_symbol, self.allocator);
    if (eval != null) {
        self.instructions.append(Instruction.init_simple_copy(return_version, eval.?, self.cfg.symbol.span, self.allocator)) catch unreachable;
    }
    self.instructions.append(Instruction.init_jump(null, self.cfg.symbol.span, self.allocator)) catch unreachable;

    if (false) {
        // Print symbol Instruction after lowering, before breaking up into basic blocks
        std.debug.print("CFG {s}:\n", .{self.cfg.symbol.name});
        for (self.instructions.items) |instr| {
            std.debug.print("{}", .{instr});
        }
        std.debug.print("\n", .{});
    }

    self.cfg.block_graph_head = self.cfg.basic_block_from_instructions(self.instructions, 0);

    if (false) {
        // Print out the basic blocks
        for (self.cfg.basic_blocks.items) |bb| {
            std.debug.print("Basic Block {}({}):\n", .{ bb.uid, bb.empty() });
            for (bb.instructions.items) |instr| {
                std.debug.print("{}", .{instr});
            }
            std.debug.print("\n", .{});
        }
    }
}

fn lower_AST(self: *Self, ast: *ast_.AST, labels: Labels) Lower_Errors!?*lval_.L_Value {
    const retval = self.lower_AST_inner(ast, labels);
    // std.debug.print("{}\n", .{ast});
    if (false) {
        // Print symbol Instruction after lowering, before breaking up into basic blocks
        std.debug.print("CFG {s}:\n", .{self.cfg.symbol.name});
        while (self.instructions.items) |instr| {
            std.debug.print("{}", .{instr});
        }
        std.debug.print("\n", .{});
    }
    return retval;
}

fn lower_AST_inner(
    self: *Self,
    ast: *ast_.AST,
    labels: Labels,
) Lower_Errors!?*lval_.L_Value {
    switch (ast.*) {
        // Straight up types, yo
        .function,
        .unit_type,
        .sum_type,
        .untagged_sum_type,
        .annotation,
        .dyn_type,
        => return self.lval_from_ast(ast.expand_type(self.allocator)),
        // Unit-values
        .unit_value, .template, .trait, .impl => return self.lval_from_unit_value(ast),
        // Literals
        .int => return self.lval_from_int(ast.int.data, ast.typeof(self.allocator), ast.token().span),
        .char => {
            const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
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
            self.instructions.append(Instruction.init_int(temp, codepoint, ast.token().span, self.allocator)) catch unreachable;
            return temp;
        },
        .float => {
            const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
            self.instructions.append(Instruction.init_float(temp, ast.float.data, ast.token().span, self.allocator)) catch unreachable;
            return temp;
        },
        .string => {
            const id: Interned_String_Set.String_Idx = self.interned_strings.add(ast.string.data, self.cfg.symbol.scope.module.?.uid);
            const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
            self.instructions.append(Instruction.init_string(temp, id, ast.token().span, self.allocator)) catch unreachable;
            return temp;
        },
        .access, .identifier => {
            const symbol = ast.symbol().?;
            if (symbol.init_validation_state == .validating) {
                self.errors.add_error(errs_.Error{ .recursive_definition = .{
                    .span = symbol.span,
                    .symbol_name = symbol.name,
                } });
                return error.CompileError;
            }
            if (symbol.kind == .@"fn") {
                return try self.lval_from_symbol_cfg(symbol, ast.token().span);
            } else if (symbol.expanded_type.?.types_match(primitives_.type_type)) {
                return self.lval_from_ast(ast);
            } else if (symbol.kind == .@"const") {
                return try self.lower_AST(symbol.init_value.?, labels);
            } else {
                const src = lval_.L_Value.create_unversioned_symbver(symbol, self.allocator);
                return src;
            }
        },
        .pattern_symbol => return try self.lval_from_symbol_cfg(ast.symbol().?, ast.token().span),
        .true => return self.lval_from_int(1, ast.typeof(self.allocator), ast.token().span),
        .false => return self.lval_from_int(0, ast.typeof(self.allocator), ast.token().span),
        // Unary operators
        .not, .negate, .addr_of, .bit_not => return try self.unop(ast, labels),
        .dereference => {
            const expr = try self.lower_AST(ast.expr(), labels) orelse return null;
            const expanded_type = ast.typeof(self.allocator).expand_type(self.allocator);
            const temp = expr.create_dereference_lval(expanded_type, self.allocator);
            return temp;
        },
        .@"try" => {
            var expr = (try self.lower_AST(ast.expr(), labels)) orelse return null;

            const end_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);
            const err_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);

            var expanded_expr_type = expr.get_expanded_type();
            // Trying error sum, runtime check if error, branch to error path
            const condition = self.create_temp_lvalue(primitives_.word64_type);
            self.instructions.append(Instruction.init_get_tag(condition, expr, ast.token().span, self.allocator)) catch unreachable; // `ok` is zero, `err`s are nonzero
            self.instructions.append(Instruction.init_branch(condition, err_label, ast.token().span, self.allocator)) catch unreachable;

            // Unwrap the `.ok` value
            const retval_lval = lval_.L_Value.create_unversioned_symbver(self.cfg.return_symbol, self.allocator);
            self.instructions.append(Instruction.init_simple_copy(retval_lval, expr, ast.token().span, self.allocator)) catch unreachable;
            self.instructions.append(Instruction.init_jump(labels.error_label, ast.token().span, self.allocator)) catch unreachable;

            // Else, store the error in retval, return through error
            self.instructions.append(err_label) catch unreachable;

            const ok_type = expanded_expr_type.get_ok_type().expand_type(self.allocator);
            const ok_lval = expr.create_select_lval(0, 0, ok_type, null, self.allocator);
            self.instructions.append(Instruction.init_jump(end_label, ast.token().span, self.allocator)) catch unreachable;
            self.instructions.append(end_label) catch unreachable;

            return ok_lval;
        },

        // Binary operators
        .assign => {
            const rhs = try self.lower_AST(ast.rhs(), labels) orelse return null;
            // If product, recursively generate a series of assignments
            // Else, create a *single* copy Instruction with an L_Value tree
            try self.generate_assign(ast.lhs(), rhs, labels);
            return self.lval_from_unit_value(ast);
        },

        .@"or", .@"and" => return try self.or_and_op(ast, labels),

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
        => return try self.binop(ast, labels),

        .equal, .not_equal => return try self.tuple_equality_check(ast, labels),

        .@"catch", .@"orelse" => return try self.coalesce_op(ast, labels),

        .bit_and, .bit_or, .bit_xor => {
            var temp: *lval_.L_Value = undefined;
            var src1 = (try self.lower_AST(ast.children().items[0], labels)) orelse return null;

            for (1..ast.children().items.len) |i| {
                temp = self.create_temp_lvalue(ast.typeof(self.allocator));
                const src2 = (try self.lower_AST(ast.children().items[i], labels)) orelse continue;
                self.instructions.append(Instruction.init(bit_ir_kind_from_ast_kind(ast), temp, src1, src2, ast.token().span, self.allocator)) catch unreachable;
                src1 = temp;
            }
            return temp;
        },
        .call => {
            const lhs = (try self.lower_AST(ast.lhs(), labels)) orelse return null;
            var temp = self.create_temp_lvalue(ast.typeof(self.allocator));
            temp.extract_symbver().symbol.span = ast.token().span;

            var instr = Instruction.init_call(temp, lhs, ast.token().span, self.allocator);
            for (ast.children().items) |term| {
                instr.data.lval_list.append((try self.lower_AST(term, labels)) orelse continue) catch unreachable;
            }
            self.instructions.append(Instruction.init_stack_push(ast.token().span, self.allocator)) catch unreachable;
            self.instructions.append(instr) catch unreachable;
            self.instructions.append(Instruction.init_stack_pop(ast.token().span, self.allocator)) catch unreachable;
            return temp;
        },
        .invoke => {
            var temp = self.create_temp_lvalue(ast.typeof(self.allocator));
            temp.extract_symbver().symbol.span = ast.token().span;

            // dyn_value is the method receiver that will be passed in
            var dyn_value: ?*lval_.L_Value = null;
            var lval_list = std.ArrayList(*lval_.L_Value).init(self.allocator);
            if (ast.children().items.len == 0) {
                // dyn_value should be the receiver
                if (ast.lhs().typeof(self.allocator).expand_identifier().* == .dyn_type) {
                    dyn_value = (try self.lower_AST(ast.lhs(), labels)) orelse return null;
                }
            } else {
                for (ast.children().items, 0..) |term, i| {
                    // Lower each child
                    const term_lval = (try self.lower_AST(term, labels)) orelse continue;
                    lval_list.append(term_lval) catch unreachable;

                    // Try to find the first child, it's possibly the receiver
                    if (ast.lhs().typeof(self.allocator).expand_identifier().* == .dyn_type and i == 0) {
                        if (term == ast.lhs()) {
                            // UFCS-like, receiver was prepended to the children list
                            dyn_value = term_lval;
                        } else {
                            // Other wise, lower the lhs
                            dyn_value = (try self.lower_AST(ast.lhs(), labels)) orelse continue;
                        }
                    }
                }
            }
            const instr = Instruction.init_invoke(temp, ast.invoke.method_decl.?, lval_list, dyn_value, ast.token().span, self.allocator);
            if (ast.invoke.method_decl.?.symbol() != null) {
                // Fine if symbol is null, for invokes on trait objects.
                instr.data.invoke.method_decl_lval = try self.lval_from_symbol_cfg(ast.invoke.method_decl.?.symbol().?, ast.token().span);
            }
            self.instructions.append(Instruction.init_stack_push(ast.token().span, self.allocator)) catch unreachable;
            self.instructions.append(instr) catch unreachable;
            self.instructions.append(Instruction.init_stack_pop(ast.token().span, self.allocator)) catch unreachable;
            return temp;
        },
        .dyn_value => {
            const expr = try self.lower_AST(ast.expr(), labels) orelse return null;
            const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
            self.instructions.append(Instruction.init_dyn(temp, expr, ast.dyn_value.mut, ast.dyn_value.impl.?, ast.token().span, self.allocator)) catch unreachable;
            return temp;
        },
        .index => {
            const lhs = (try self.lower_AST(ast.lhs(), labels)) orelse return null;
            const rhs = (try self.lower_AST(ast.rhs(), labels)) orelse return null;
            var new_lhs = lhs;

            // Get the type of the index ast. This will determine if this is an array index or a slice index
            const ast_expanded_type = ast.lhs().typeof(self.allocator).expand_type(self.allocator);
            const _type = ast.typeof(self.allocator);
            if (ast_expanded_type.* == .addr_of) {
                // Indexing a multi-ptr, don't change lhs
                std.debug.assert(ast_expanded_type.addr_of.multiptr);
            } else if (ast_expanded_type.* == .product and ast_expanded_type.product.was_slice) {
                // Indexing a slice; index_val := lhs._0^[rhs]
                new_lhs = new_lhs.create_select_lval(0, 0, _type.expand_type(self.allocator), null, self.allocator);
                new_lhs = new_lhs.create_dereference_lval(_type.expand_type(self.allocator), self.allocator);
            }

            // Surround with L_Value node
            const length: ?*lval_.L_Value = self.generate_indexable_length(lhs, ast_expanded_type, ast.token().span);
            return new_lhs.create_index_lval(rhs, length, _type.expand_type(self.allocator), self.allocator);
        },
        .select => {
            // Recursively get select's ast L_Value node
            const ast_lval = try self.lower_AST(ast.lhs(), labels); // cannot be unreachable, since unreachable isn't selectable

            // Get the offset into the struct that this select does
            var lhs_expanded_type = ast.lhs().typeof(self.allocator).expand_type(self.allocator);
            const offset = if (lhs_expanded_type.* == .product)
                lhs_expanded_type.product.get_offset(ast.pos().?, self.allocator)
            else
                0;

            var tag: ?*lval_.L_Value = null;
            if (lhs_expanded_type.* == .sum_type) {
                // Check that the sum value has the proper tag before a selection
                tag = self.create_temp_lvalue(primitives_.word64_type);
                self.instructions.append(Instruction.init_get_tag(tag.?, ast_lval.?, ast.token().span, self.allocator)) catch unreachable;
            }

            // Surround with L_Value node
            const field = ast.pos().?;
            const expanded_type = ast.typeof(self.allocator).expand_type(self.allocator);
            return ast_lval.?.create_select_lval(field, offset, expanded_type, tag, self.allocator);
        },
        .product => {
            if (ast.children().items[0].typeof(self.allocator).types_match(primitives_.type_type)) {
                return self.lval_from_ast(ast);
            } else {
                const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
                var instr = Instruction.init_load_struct(temp, ast.token().span, self.allocator);
                for (ast.children().items) |term| {
                    instr.data.lval_list.append((try self.lower_AST(term, labels)) orelse return null) catch unreachable;
                }
                self.instructions.append(instr) catch unreachable;
                return temp;
            }
        },
        // Fancy Operators
        .sub_slice => {
            const arr = (try self.lower_AST(ast.sub_slice.super, labels)) orelse return null;
            const lower = (try self.lower_AST(ast.sub_slice.lower.?, labels)) orelse return null;
            const upper = (try self.lower_AST(ast.sub_slice.upper.?, labels)) orelse return null;

            self.generate_subslice_check(lower, upper, ast.token().span);

            const new_size = self.create_temp_lvalue(primitives_.int_type);
            self.instructions.append(Instruction.init(.sub_int, new_size, upper, lower, ast.token().span, self.allocator)) catch unreachable;

            const data_type = ast.typeof(self.allocator).children().items[0];
            const data_ptr = arr.create_select_lval(0, 0, data_type.expand_type(self.allocator), null, self.allocator);

            const new_data_ptr = self.create_temp_lvalue(data_type);
            self.instructions.append(Instruction.init(.add_int, new_data_ptr, data_ptr, lower, ast.token().span, self.allocator)) catch unreachable;

            const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
            var load_struct = Instruction.init_load_struct(temp, ast.token().span, self.allocator);
            load_struct.data.lval_list.append(new_data_ptr) catch unreachable;
            load_struct.data.lval_list.append(new_size) catch unreachable;
            self.instructions.append(load_struct) catch unreachable;
            return temp;
        },
        .sum_value => {
            var _init: ?*lval_.L_Value = null;
            const pos: usize = ast.pos().?;
            const proper_term: *ast_.AST = (ast.typeof(self.allocator)).children().items[pos];
            if (ast.sum_value.init != null) {
                const sum_init = try self.lower_AST(ast.sum_value.init.?, labels);
                if (proper_term.annotation.type.* != .unit_type) { // still output the Instruction, but do not refer to it unless the type isn't unit
                    _init = sum_init;
                }
            }
            const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
            self.instructions.append(Instruction.init_union(temp, _init, ast.pos().?, ast.token().span, self.allocator)) catch unreachable;
            return temp;
        },
        // Control-flow expressions
        .@"if" => {
            // Create the result symbol and labels used
            const symbol = self.create_temp_symbol(ast.typeof(self.allocator));
            const else_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);
            const end_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);

            // If there's a let, then do it, dumby!
            if (ast.@"if".let) |let| {
                _ = try self.lower_AST(let, labels);
            }

            // Test condition
            try self.flow(ast.@"if".condition, else_label, false, ast.token().span, labels);

            // lhs was true
            try self.generate_control_flow_block(ast.body_block(), symbol, ast.else_block() != null, labels);
            // TODO: De-duplicate 1
            self.instructions.append(Instruction.init_jump(end_label, ast.token().span, self.allocator)) catch unreachable;

            // lhs was false
            self.instructions.append(else_label) catch unreachable;
            try self.generate_control_flow_else(ast.else_block(), symbol, ast.token().span, labels);

            self.instructions.append(end_label) catch unreachable;
            return lval_.L_Value.create_unversioned_symbver(symbol, self.allocator);
        },
        .match => {
            // Create the result symbol and labels used
            const symbol = self.create_temp_symbol(ast.typeof(self.allocator));
            const end_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator); // Exit label of match
            const none_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator); // jumped to if all tests fail and no `else` mapping

            if (ast.match.let) |let| { // If there's a let, then do it, dumby!
                _ = try self.lower_AST(let, labels);
            }

            const expr = (try self.lower_AST(ast.expr(), labels)) orelse return null;
            const rhs_label_list = try self.generate_match_pattern_checks(expr, ast.children().*, none_label, labels);

            // Couldn't match pattern, panic!
            self.instructions.append(none_label) catch unreachable;
            self.instructions.append(Instruction.init_stack_push(ast.token().span, self.allocator)) catch unreachable;
            self.instructions.append(Instruction.init_panic("could not match pattern", ast.token().span, self.allocator)) catch unreachable;

            const span = ast.token().span;
            try self.generate_match_bodies(expr, ast.children().*, rhs_label_list, symbol, end_label, span, labels);

            self.instructions.append(end_label) catch unreachable;
            return lval_.L_Value.create_unversioned_symbver(symbol, self.allocator);
        },
        .@"while" => {
            // Create the result symbol and labels used
            const symbol = self.create_temp_symbol(ast.typeof(self.allocator));
            const cond_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);
            const current_continue_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);
            const else_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);
            const end_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);

            if (ast.@"while".let) |let| { // do `let` if there's a let
                _ = try self.lower_AST(let, labels);
            }

            const loop_labels = Labels{
                .return_label = labels.return_label,
                .break_label = end_label,
                .continue_label = current_continue_label,
                .error_label = labels.error_label,
            };
            const post_labels = Labels{
                .return_label = labels.return_label,
                .break_label = end_label,
                .continue_label = labels.continue_label,
                .error_label = labels.error_label,
            };

            // Test condition, branch to either body or else block
            self.instructions.append(cond_label) catch unreachable;
            try self.flow(ast.@"while".condition, else_label, false, ast.token().span, loop_labels);

            // Body block
            try self.generate_control_flow_block(ast.body_block(), symbol, ast.else_block() != null, loop_labels);

            self.instructions.append(current_continue_label) catch unreachable;
            if (ast.@"while".post) |post| { // do `post` if there's a post, jump to end_label to break
                _ = try self.lower_AST(post, post_labels);
            }
            self.instructions.append(Instruction.init_jump(cond_label, ast.token().span, self.allocator)) catch unreachable;

            self.instructions.append(else_label) catch unreachable;
            try self.generate_control_flow_else(ast.else_block(), symbol, ast.token().span, labels);

            self.instructions.append(end_label) catch unreachable;
            return lval_.L_Value.create_unversioned_symbver(symbol, self.allocator);
        },
        .block => { // TODO: TOO LONG
            if (ast.children().items.len == 0 and ast.block.final == null) {
                return self.lval_from_unit_value(ast);
            }

            var continue_labels = std.ArrayList(*Instruction).init(self.allocator);
            defer continue_labels.deinit();
            var break_labels = std.ArrayList(*Instruction).init(self.allocator);
            defer break_labels.deinit();
            var return_labels = std.ArrayList(*Instruction).init(self.allocator);
            defer return_labels.deinit();
            var error_labels = std.ArrayList(*Instruction).init(self.allocator);
            defer error_labels.deinit();
            for (ast.block.defers.items) |_| {
                continue_labels.append(Instruction.init_label(self.cfg, ast.token().span, self.allocator)) catch unreachable;
                break_labels.append(Instruction.init_label(self.cfg, ast.token().span, self.allocator)) catch unreachable;
                return_labels.append(Instruction.init_label(self.cfg, ast.token().span, self.allocator)) catch unreachable;
            }
            for (ast.block.errdefers.items) |_| {
                error_labels.append(Instruction.init_label(self.cfg, ast.token().span, self.allocator)) catch unreachable;
            }
            const end_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);

            // These are the labels to go to on each final statement.
            // These are updated to point to different places in the defer chain at the end of this block.
            var current_labels: Labels = labels;

            var defer_label_index: usize = 0;
            var errdefer_label_index: usize = 0;

            var temp: ?*lval_.L_Value = null;
            for (ast.children().items) |child| {
                temp = try self.lower_AST(child, current_labels);
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
                _ = try self.lower_AST(final, current_labels);
            } else if (temp) |_temp| {
                self.wrap_error_return(_temp, ast.token().span, current_labels);
            }

            try self.generate_defers(&ast.block.defers, &continue_labels);
            self.instructions.append(Instruction.init_jump(end_label, ast.token().span, self.allocator)) catch unreachable;

            try self.generate_defers(&ast.block.defers, &break_labels);
            self.instructions.append(Instruction.init_jump(labels.break_label, ast.token().span, self.allocator)) catch unreachable;

            try self.generate_defers(&ast.block.defers, &return_labels);
            self.instructions.append(Instruction.init_jump(labels.return_label, ast.token().span, self.allocator)) catch unreachable;

            try self.generate_defers(&ast.block.errdefers, &error_labels);
            self.instructions.append(Instruction.init_jump(labels.error_label, ast.token().span, self.allocator)) catch unreachable;

            self.instructions.append(end_label) catch unreachable;

            return temp;
        },

        // Control-flow statements
        .decl => {
            if (ast.decl.init) |_init| {
                const def: ?*lval_.L_Value = try self.lower_AST(_init, labels);
                if (def == null) {
                    return null;
                }
                try self.generate_pattern(ast.decl.pattern, ast.decl.type.expand_type(self.allocator), def.?);
            }
            return self.lval_from_unit_value(ast);
        },
        .fn_decl => return try self.lval_from_symbol_cfg(ast.symbol().?, ast.token().span),
        .@"errdefer", .@"defer" => return self.lval_from_unit_value(ast),
        .@"continue" => {
            self.instructions.append(Instruction.init_jump(labels.continue_label, ast.token().span, self.allocator)) catch unreachable;
            return null;
        },
        .@"unreachable" => {
            self.instructions.append(Instruction.init_stack_push(ast.token().span, self.allocator)) catch unreachable;
            self.instructions.append(Instruction.init_panic("reached unreachable code", ast.token().span, self.allocator)) catch unreachable;
            return null;
        },
        .@"break" => {
            self.instructions.append(Instruction.init_jump(labels.break_label, ast.token().span, self.allocator)) catch unreachable;
            return null;
        },
        .@"return" => {
            if (ast.@"return"._ret_expr) |expr| {
                // Copy expr to retval
                const retval = (try self.lower_AST(expr, labels)) orelse return null;
                const retval_lval = lval_.L_Value.create_unversioned_symbver(self.cfg.return_symbol, self.allocator);
                self.instructions.append(Instruction.init_simple_copy(retval_lval, retval, ast.token().span, self.allocator)) catch unreachable;
                self.wrap_error_return(retval, ast.token().span, labels);
            }
            self.instructions.append(Instruction.init_jump(labels.return_label, ast.token().span, self.allocator)) catch unreachable;
            return null;
        },

        else => std.debug.panic("compiler error: unimplemented lower_AST() for: AST.{s}", .{@tagName(ast.*)}),
    }
}

fn lval_from_ast(
    self: *Self,
    ast: *ast_.AST,
) *lval_.L_Value {
    const lval = self.create_temp_lvalue(ast);
    self.instructions.append(Instruction.init_ast(lval, ast, ast.token().span, self.allocator)) catch unreachable;
    return lval;
}

fn lval_from_unit_value(
    self: *Self,
    ast: *ast_.AST, // TODO: Just accept span
) *lval_.L_Value {
    const lval = self.create_temp_lvalue(primitives_.unit_type);
    self.instructions.append(Instruction.init(.load_unit, lval, null, null, ast.token().span, self.allocator)) catch unreachable;
    return lval;
}

fn lval_from_int(
    self: *Self,
    int: i128,
    _type: *ast_.AST,
    span: Span,
) *lval_.L_Value {
    const temp = self.create_temp_lvalue(_type);
    self.instructions.append(Instruction.init_int(temp, int, span, self.allocator)) catch unreachable;
    return temp;
}

fn lval_from_symbol_cfg(
    self: *Self,
    symbol: *Symbol,
    span: Span,
) Lower_Errors!*lval_.L_Value {
    const callee = try cfg_builder_.get_cfg(symbol, self.cfg, self.interned_strings, self.errors, self.allocator);
    self.cfg.children.put(callee, {}) catch unreachable;
    const lval = self.create_temp_lvalue(symbol._type);
    const instr = Instruction.init_symbol(lval, symbol, span, self.allocator);
    self.instructions.append(instr) catch unreachable;
    return lval;
}

fn unop(
    self: *Self,
    ast: *ast_.AST, // TODO: Create some sort of context for these parameters?
    labels: Labels,
) Lower_Errors!?*lval_.L_Value {
    if (ast.typeof(self.allocator).types_match(primitives_.type_type)) {
        return self.lval_from_ast(ast); // for addr_of types, ex: `&T`
    }
    const expr = try self.lower_AST(ast.expr(), labels) orelse return null;
    const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
    self.instructions.append(Instruction.init_int_float_kind(int_kind(ast), float_kind(ast), temp, expr, null, ast.token().span, self.allocator)) catch unreachable;
    return temp;
}

fn binop(
    self: *Self,
    ast: *ast_.AST, // TODO: Create some sort of context for these parameters?
    labels: Labels,
) Lower_Errors!?*lval_.L_Value {
    const lhs_lval = try self.lower_AST(ast.lhs(), labels);
    const rhs_lval = try self.lower_AST(ast.rhs(), labels);
    if (lhs_lval == null or rhs_lval == null) {
        return null;
    }
    const temp = self.create_temp_lvalue(ast.typeof(self.allocator));
    self.instructions.append(Instruction.init_int_float_kind(int_kind(ast), float_kind(ast), temp, lhs_lval, rhs_lval, ast.token().span, self.allocator)) catch unreachable;
    return temp;
}

fn int_kind(ast: *ast_.AST) Instruction.Kind {
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

fn float_kind(ast: *ast_.AST) Instruction.Kind {
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
    self: *Self,
    ast: *ast_.AST,
    labels: Labels,
) Lower_Errors!?*lval_.L_Value {
    // Create the result symbol and labels used
    const or_and_symbol = self.create_temp_symbol(ast.typeof(self.allocator));
    const jump_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);
    const end_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);

    const should_jump = ast.* == .@"or";

    // Test condition
    try self.flow(ast.lhs(), jump_label, should_jump, ast.token().span, labels);
    try self.flow(ast.rhs(), jump_label, should_jump, ast.token().span, labels);

    // never jumped, store whether that's good or not in temp
    const load_false_lval = lval_.L_Value.create_unversioned_symbver(or_and_symbol, self.allocator);
    self.instructions.append(Instruction.init_int(load_false_lval, if (should_jump) 0 else 1, ast.token().span, self.allocator)) catch unreachable;
    self.instructions.append(Instruction.init_jump(end_label, ast.token().span, self.allocator)) catch unreachable;

    // jumped, store whether that's good or not in temp
    self.instructions.append(jump_label) catch unreachable;
    const load_true_lval = lval_.L_Value.create_unversioned_symbver(or_and_symbol, self.allocator);
    self.instructions.append(Instruction.init_int(load_true_lval, if (should_jump) 1 else 0, ast.token().span, self.allocator)) catch unreachable;

    self.instructions.append(end_label) catch unreachable;
    return lval_.L_Value.create_unversioned_symbver(or_and_symbol, self.allocator);
}

fn tuple_equality_check(
    self: *Self,
    ast: *ast_.AST,
    labels: Labels,
) Lower_Errors!?*lval_.L_Value {
    std.debug.assert(ast.* == .equal or ast.* == .not_equal);
    const lhs = try self.lower_AST(ast.lhs(), labels);
    const rhs = try self.lower_AST(ast.rhs(), labels);
    if (lhs == null or rhs == null) {
        return null;
    }
    const temp = self.create_temp_lvalue(ast.typeof(self.allocator));

    // Labels used
    const fail_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);
    const end_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);

    self.tuple_equality_flow(lhs.?, rhs.?, fail_label);

    self.instructions.append(Instruction.init_int(temp, if (ast.* == .equal) 1 else 0, ast.token().span, self.allocator)) catch unreachable;
    self.instructions.append(Instruction.init_jump(end_label, ast.token().span, self.allocator)) catch unreachable;

    self.instructions.append(fail_label) catch unreachable;
    self.instructions.append(Instruction.init_int(temp, if (ast.* == .equal) 0 else 1, ast.token().span, self.allocator)) catch unreachable;

    self.instructions.append(end_label) catch unreachable;
    return temp;
}

fn tuple_equality_flow(
    self: *Self,
    lhs: *lval_.L_Value,
    rhs: *lval_.L_Value,
    fail_label: *Instruction,
) void {
    const new_lhs = lhs; // try L_Value.create_unversioned_symbver(lhs.symbol, lhs.symbol._type.?, allocator);
    const new_rhs = rhs; // try L_Value.create_unversioned_symbver(rhs.symbol, rhs.symbol._type.?, allocator);
    const temp = self.create_temp_lvalue(primitives_.bool_type);
    var lhs_type = lhs.get_expanded_type();
    if (lhs_type.* == .product) {
        for (0..lhs_type.children().items.len) |field| {
            const expanded_type = lhs_type.children().items[field].expand_type(self.allocator);
            const offset = lhs_type.product.get_offset(field, self.allocator);
            const lhs_select = new_lhs.create_select_lval(field, offset, expanded_type, null, self.allocator);
            const rhs_select = new_rhs.create_select_lval(field, offset, expanded_type, null, self.allocator);
            self.tuple_equality_flow(lhs_select, rhs_select, fail_label);
        }
    } else if (lhs_type.* == .sum_type) {
        const lhs_tag = self.create_temp_lvalue(primitives_.word64_type);
        const rhs_tag = self.create_temp_lvalue(primitives_.word64_type);
        self.instructions.append(Instruction.init_get_tag(lhs_tag, new_lhs, lhs.extract_symbver().symbol.span, self.allocator)) catch unreachable;
        self.instructions.append(Instruction.init_get_tag(rhs_tag, new_rhs, lhs.extract_symbver().symbol.span, self.allocator)) catch unreachable;
        self.instructions.append(Instruction.init(.equal, temp, lhs_tag, rhs_tag, lhs.extract_symbver().symbol.span, self.allocator)) catch unreachable;
        self.instructions.append(Instruction.init_branch(temp, fail_label, lhs.extract_symbver().symbol.span, self.allocator)) catch unreachable;
    } else {
        self.instructions.append(Instruction.init(.equal, temp, new_lhs, rhs, lhs.extract_symbver().symbol.span, self.allocator)) catch unreachable;
        self.instructions.append(Instruction.init_branch(temp, fail_label, lhs.extract_symbver().symbol.span, self.allocator)) catch unreachable;
    }
}

fn coalesce_op(
    self: *Self,
    ast: *ast_.AST, // The coalesce operator to lower
    labels: Labels, // The current labels to use
) Lower_Errors!?*lval_.L_Value {
    // Create the result symbol and labels
    const coalesce_symbol = self.create_temp_symbol(ast.typeof(self.allocator));
    const zero_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);
    const end_label = Instruction.init_label(self.cfg, ast.token().span, self.allocator);

    // Test if lhs tag is 0 (`ok` or `some`)
    const lhs = (try self.lower_AST(ast.lhs(), labels)) orelse return null;

    const condition = self.create_temp_lvalue(primitives_.word64_type);
    self.instructions.append(Instruction.init_get_tag(condition, lhs, ast.token().span, self.allocator)) catch unreachable;
    self.instructions.append(Instruction.init_branch(condition, zero_label, ast.token().span, self.allocator)) catch unreachable;

    // tag was an error/none, store rhs in temp
    const maybe_rhs = (try self.lower_AST(ast.rhs(), labels));
    if (maybe_rhs) |rhs| {
        const rhs_lval = lval_.L_Value.create_unversioned_symbver(coalesce_symbol, self.allocator);
        self.instructions.append(Instruction.init_simple_copy(rhs_lval, rhs, ast.token().span, self.allocator)) catch unreachable;
        self.instructions.append(Instruction.init_jump(end_label, ast.token().span, self.allocator)) catch unreachable;
    }

    // tag was `.ok` or `.some`, store lhs in temp
    self.instructions.append(zero_label) catch unreachable;
    const expanded_type = ast.typeof(self.allocator).expand_type(self.allocator);
    const val = lhs.create_select_lval(0, 0, expanded_type, null, self.allocator);
    const ok_lval = lval_.L_Value.create_unversioned_symbver(coalesce_symbol, self.allocator);
    self.instructions.append(Instruction.init_simple_copy(ok_lval, val, ast.token().span, self.allocator)) catch unreachable;

    self.instructions.append(end_label) catch unreachable;
    return lval_.L_Value.create_unversioned_symbver(coalesce_symbol, self.allocator);
}

fn bit_ir_kind_from_ast_kind(ast: *ast_.AST) Instruction.Kind {
    return switch (ast.*) {
        .bit_and => Instruction.Kind.bit_and,
        .bit_or => Instruction.Kind.bit_or,
        .bit_xor => Instruction.Kind.bit_xor,
        else => std.debug.panic("compiler error: not a bit ast: {s}\n", .{@tagName(ast.*)}),
    };
}

fn generate_assign(
    self: *Self,
    lhs: *ast_.AST, // AST node for the LHS of the `=`
    rhs: *lval_.L_Value, // L_Value which holds the value to assign
    labels: Labels,
) Lower_Errors!void {
    if (lhs.* == .product) {
        // Recursively call `generate_assign` for each term in the product.
        // product-assigns may be nested, for example:
        //     ((x, y), (a, b)) = get_tuple()
        // So it's important that this is recursive
        var lhs_expanded_type = lhs.typeof(self.allocator).expand_type(self.allocator);
        for (lhs.children().items, 0..) |term, field| {
            const product_lhs = try self.lower_AST(term, labels);
            if (product_lhs == null) {
                continue;
            }
            const expanded_type = rhs.get_expanded_type().children().items[field].expand_type(self.allocator);
            const offset = lhs_expanded_type.product.get_offset(field, self.allocator);
            const select = rhs.create_select_lval(field, offset, expanded_type, null, self.allocator);
            try self.generate_assign(term, select, labels);
        }
    } else if (lhs.* == .select and lhs.lhs().typeof(self.allocator).expand_type(self.allocator).* == .sum_type) {
        // Select on a sum-type, convert to a copy of a sum_value
        const sum_value = self.create_temp_lvalue(lhs.lhs().typeof(self.allocator).expand_type(self.allocator));
        self.instructions.append(Instruction.init_union(sum_value, rhs, lhs.pos().?, lhs.token().span, self.allocator)) catch unreachable;
        try self.generate_assign(lhs.lhs(), sum_value, labels);
    } else {
        // Get L_Value tree, create a `copy` Instruction of L_Value tree and rhs
        const lval = try self.lower_AST(lhs, labels);
        const instr = Instruction.init(.copy, lval, rhs, null, lhs.token().span, self.allocator);
        self.instructions.append(instr) catch unreachable;
    }
}

/// Generates the Instruction to get the length of either an array or a slice. Used by indices to get the length for bounds checks
fn generate_indexable_length(
    self: *Self,
    lhs: *lval_.L_Value,
    _type: *ast_.AST,
    span: Span,
) ?*lval_.L_Value {
    if (_type.* == .addr_of) {
        // Implies multiptr, unfortunately there is no way to get the length
        std.debug.assert(_type.addr_of.multiptr);
        return null;
    } else if (_type.* == .product and _type.product.was_slice) {
        const offset = _type.product.get_offset(1, self.allocator);
        return lhs.create_select_lval(1, offset, primitives_.int64_type, null, self.allocator);
    } else if (_type.* == .product and !_type.product.was_slice) {
        const retval = self.create_temp_lvalue(primitives_.int_type);
        self.instructions.append(Instruction.init_int(retval, _type.children().items.len, span, self.allocator)) catch unreachable;
        return retval;
    } else {
        std.debug.panic("compiler error: cannot generate Instruction to get length of type AST.{s}\n", .{@tagName(_type.*)});
    }
}

/// Generates code to verify at runtime that a subslice's lower bound is less-than-or-equal-to the subslice's upper bound.
fn generate_subslice_check(
    self: *Self,
    lower: *lval_.L_Value,
    upper: *lval_.L_Value,
    span: Span,
) void {
    const end_label = Instruction.init_label(self.cfg, span, self.allocator);
    const compare = self.create_temp_lvalue(primitives_.bool_type);
    self.instructions.append(Instruction.init(.greater_int, compare, lower, upper, span, self.allocator)) catch unreachable;
    self.instructions.append(Instruction.init_branch(compare, end_label, span, self.allocator)) catch unreachable;
    self.instructions.append(Instruction.init_stack_push(span, self.allocator)) catch unreachable;
    self.instructions.append(Instruction.init_panic("subslice lower bound is greater than upper bound", span, self.allocator)) catch unreachable;
    self.instructions.append(end_label) catch unreachable;
}

/// Generates Instruction code to jump to `label` iff `condition` evaluates to `sense`.
fn flow(
    self: *Self,
    condition: *ast_.AST,
    label: *Instruction,
    sense: bool,
    span: Span,
    labels: Labels,
) Lower_Errors!void {
    // FIXME: High Cyclo
    switch (condition.*) {
        .true => if (sense) {
            self.instructions.append(Instruction.init_jump(label, span, self.allocator)) catch unreachable;
        },
        .false => if (!sense) {
            self.instructions.append(Instruction.init_jump(label, span, self.allocator)) catch unreachable;
        },
        .not => try self.flow(condition.expr(), label, !sense, span, labels),
        .@"or" => if (sense) {
            try self.flow(condition.lhs(), label, true, span, labels);
            try self.flow(condition.rhs(), label, true, span, labels);
        } else {
            const skip_label = Instruction.init_label(self.cfg, span, self.allocator);
            try self.flow(condition.lhs(), skip_label, true, span, labels);
            try self.flow(condition.rhs(), label, false, span, labels);
            self.instructions.append(skip_label) catch unreachable;
        },
        .@"and" => if (sense) {
            const skip_label = Instruction.init_label(self.cfg, span, self.allocator);
            try self.flow(condition.lhs(), skip_label, false, span, labels);
            try self.flow(condition.rhs(), label, true, span, labels);
            self.instructions.append(skip_label) catch unreachable;
        } else {
            try self.flow(condition.lhs(), label, false, span, labels);
            try self.flow(condition.rhs(), label, false, span, labels);
        },
        else => if (sense) {
            const condition_lval = try self.lower_AST(condition, labels) orelse return;
            const not_condition_lval = self.create_temp_lvalue(primitives_.bool_type);
            self.instructions.append(Instruction.init(.not, not_condition_lval, condition_lval, null, span, self.allocator)) catch unreachable; // Will be optimized out!
            self.instructions.append(Instruction.init_branch(not_condition_lval, label, span, self.allocator)) catch unreachable;
        } else {
            const condition_lval = try self.lower_AST(condition, labels) orelse return;
            self.instructions.append(Instruction.init_branch(condition_lval, label, span, self.allocator)) catch unreachable;
        },
    }
}

/// Wraps stores to an lval in either a union or as a simple-copy
fn generate_control_flow_block(
    self: *Self,
    ast: *ast_.AST,
    symbol: *Symbol,
    has_else: bool,
    labels: Labels,
) Lower_Errors!void {
    if (try self.lower_AST(ast, labels)) |rhs_lval| {
        const rhs_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, self.allocator);
        if (has_else) {
            self.instructions.append(Instruction.init_simple_copy(rhs_copy_lval, rhs_lval, ast.token().span, self.allocator)) catch unreachable;
        } else {
            self.instructions.append(Instruction.init_union(rhs_copy_lval, rhs_lval, 0, ast.token().span, self.allocator)) catch unreachable; // `some` is 0
        }
    }
}

fn generate_control_flow_else(
    self: *Self,
    ast: ?*ast_.AST,
    symbol: *Symbol,
    span: Span,
    labels: Labels,
) Lower_Errors!void {
    if (ast) |else_block| {
        if (try self.lower_AST(else_block, labels)) |else_lval| {
            const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, self.allocator);
            self.instructions.append(Instruction.init_simple_copy(else_copy_lval, else_lval, span, self.allocator)) catch unreachable;
        }
    } else {
        // no else block => store null
        const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, self.allocator);
        self.instructions.append(Instruction.init_union(else_copy_lval, null, 1, span, self.allocator)) catch unreachable; // `none` is 1
    }
}

fn generate_match_pattern_checks(
    self: *Self,
    expr: *lval_.L_Value,
    mappings: std.ArrayList(*ast_.AST),
    none_label: *Instruction,
    labels: Labels,
) Lower_Errors!std.ArrayList(*Instruction) {
    var lhs_label_list = std.ArrayList(*Instruction).init(self.allocator); // labels to branch on an unsuccessful test ("next pattern")
    defer lhs_label_list.deinit();
    var rhs_label_list = std.ArrayList(*Instruction).init(self.allocator); // labels to branch on a successful test ("code for the mapping")
    errdefer rhs_label_list.deinit();
    for (mappings.items) |mapping| {
        lhs_label_list.append(Instruction.init_label(self.cfg, mapping.token().span, self.allocator)) catch unreachable;
        rhs_label_list.append(Instruction.init_label(self.cfg, mapping.token().span, self.allocator)) catch unreachable;
    }
    for (mappings.items, 0..) |mapping, i| {
        self.instructions.append(lhs_label_list.items[i]) catch unreachable;
        const next_label = if (i < lhs_label_list.items.len - 1)
            lhs_label_list.items[i + 1]
        else
            none_label;
        try self.generate_match_pattern_check(mapping.lhs(), expr, next_label, labels);
        self.instructions.append(Instruction.init_jump(rhs_label_list.items[i], mapping.token().span, self.allocator)) catch unreachable;
    }
    return rhs_label_list;
}

/// Generates the code which checks if the pattern matches the match expression
fn generate_match_pattern_check(
    self: *Self,
    pattern: ?*ast_.AST,
    expr: *lval_.L_Value,
    next_pattern: *Instruction,
    labels: Labels,
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
            const value = (try self.lower_AST(pattern.?, labels)) orelse return;
            const condition = self.create_temp_lvalue(primitives_.bool_type);
            self.instructions.append(Instruction.init(.equal, condition, expr, value, pattern.?.token().span, self.allocator)) catch unreachable;
            self.instructions.append(Instruction.init_branch(condition, next_pattern, pattern.?.token().span, self.allocator)) catch unreachable;
        },
        .product => {
            for (pattern.?.children().items, 0..) |term, field| {
                const expanded_type = expr.get_expanded_type().children().items[field].expand_type(self.allocator);
                const pattern_type = pattern.?.typeof(self.allocator).expand_type(self.allocator);
                const offset = pattern_type.product.get_offset(field, self.allocator);
                const lval = expr.create_select_lval(field, offset, expanded_type, null, self.allocator);
                try self.generate_match_pattern_check(term, lval, next_pattern, labels);
            }
        },
        .select, .sum_value => {
            // Get tag of pattern
            const sel = self.create_temp_lvalue(primitives_.word64_type);
            self.instructions.append(Instruction.init_int(sel, pattern.?.pos().?, pattern.?.token().span, self.allocator)) catch unreachable;

            // Get tag of expr
            const tag = self.create_temp_lvalue(primitives_.word64_type);
            self.instructions.append(Instruction.init_get_tag(tag, expr, pattern.?.token().span, self.allocator)) catch unreachable;

            // Compare them, jump to next pattern if they are not equal
            const neql = self.create_temp_lvalue(primitives_.bool_type);
            self.instructions.append(Instruction.init(.equal, neql, tag, sel, pattern.?.token().span, self.allocator)) catch unreachable;
            self.instructions.append(Instruction.init_branch(neql, next_pattern, pattern.?.token().span, self.allocator)) catch unreachable;
        },
        else => std.debug.panic("compiler error: unimplemented generate_match_pattern_check() for {s}", .{@tagName(pattern.?.*)}),
    }
}

fn generate_match_bodies(
    self: *Self,
    expr: *lval_.L_Value,
    mappings: std.ArrayList(*ast_.AST),
    rhs_label_list: std.ArrayList(*Instruction),
    symbol: *Symbol,
    end_label: *Instruction,
    span: Span,
    labels: Labels,
) Lower_Errors!void {
    for (mappings.items, 0..) |mapping, i| {
        self.instructions.append(rhs_label_list.items[i]) catch unreachable;
        // Generate initialization for patterns before the rhs
        try self.generate_pattern(mapping.lhs(), expr.get_expanded_type(), expr);

        // Generate the rhs, copy result to symbol
        if (try self.lower_AST(mapping.rhs(), labels)) |rhs_lval| {
            const rhs_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, self.allocator);
            self.instructions.append(Instruction.init_simple_copy(rhs_copy_lval, rhs_lval, mapping.rhs().token().span, self.allocator)) catch unreachable;
        }
        self.instructions.append(Instruction.init_jump(end_label, span, self.allocator)) catch unreachable;
    }
}

fn wrap_error_return(
    self: *Self,
    expr: *lval_.L_Value,
    span: Span,
    labels: Labels,
) void {
    const expanded_temp_type = expr.get_expanded_type();
    if (labels.error_label != null and expanded_temp_type.* == .sum_type and expanded_temp_type.sum_type.from == .@"error") {
        // Returning error sum, runtime check if error, branch to error path
        const condition = self.create_temp_lvalue(primitives_.word64_type);
        self.instructions.append(Instruction.init_get_tag(condition, expr, span, self.allocator)) catch unreachable; // `ok` is 0 `err`s nonzero
        const not_condition = self.create_temp_lvalue(primitives_.bool_type);
        self.instructions.append(Instruction.init(.not, not_condition, condition, null, span, self.allocator)) catch unreachable;
        self.instructions.append(Instruction.init_branch(not_condition, labels.error_label, span, self.allocator)) catch unreachable;
    }
}

fn create_temp_lvalue(self: *Self, _type: *ast_.AST) *lval_.L_Value {
    const temp_symbol = self.create_temp_symbol(_type);
    const retval = lval_.L_Value.create_unversioned_symbver(temp_symbol, self.allocator);
    return retval;
}

fn create_temp_symbol(self: *Self, _type: *ast_.AST) *Symbol {
    var buf = String.init_with_contents(self.allocator, "t") catch unreachable;
    buf.writer().print("{}", .{self.number_temps}) catch unreachable;
    self.number_temps += 1;
    var temp_symbol = Symbol.init(
        self.cfg.symbol.scope,
        (buf.toOwned() catch unreachable).?,
        Span.phony,
        _type,
        undefined,
        null,
        .mut,
        self.allocator,
    );
    temp_symbol.expanded_type = _type.expand_type(self.allocator);
    temp_symbol.is_temp = true;
    return temp_symbol;
}

fn generate_defers(
    self: *Self,
    defers: *std.ArrayList(*ast_.AST),
    defer_labels: *std.ArrayList(*Instruction),
) Lower_Errors!void {
    var i: usize = defers.items.len;
    while (i > 0) : (i -= 1) {
        self.instructions.append(defer_labels.items[i - 1]) catch unreachable;
        _ = try self.lower_AST(defers.items[i - 1], Labels.null_labels);
    }
}

/// Generates all symbol definitions in a pattern
fn generate_pattern(
    self: *Self,
    pattern: *ast_.AST,
    _type: *ast_.AST,
    def: *lval_.L_Value,
) Lower_Errors!void {
    if (pattern.* == .pattern_symbol) {
        if (!std.mem.eql(u8, pattern.pattern_symbol.name, "_")) {
            const symbver = lval_.L_Value.create_unversioned_symbver(pattern.symbol().?, self.allocator);
            self.instructions.append(Instruction.init_simple_copy(symbver, def, pattern.token().span, self.allocator)) catch unreachable;
        }
    } else if (pattern.* == .product) {
        for (pattern.children().items, 0..) |term, field| {
            const expanded_type = _type.children().items[field].expand_type(self.allocator);
            const offset = _type.product.get_offset(field, self.allocator);
            const lval = def.create_select_lval(field, offset, expanded_type, null, self.allocator);
            try self.generate_pattern(term, expanded_type, lval);
        }
    } else if (pattern.* == .sum_value) {
        const expanded_type = pattern.sum_value.domain.?.annotation.type.expand_type(self.allocator);
        const field = pattern.pos().?;
        const lval = def.create_select_lval(field, 0, expanded_type, null, self.allocator);
        try self.generate_pattern(pattern.sum_value.init.?, expanded_type, lval);
    }
}
