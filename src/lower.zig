// Lowers an AST into a list of IR.

const std = @import("std");
const ast_ = @import("ast.zig");
const cfg_ = @import("cfg.zig");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const module_ = @import("module.zig");
const primitives_ = @import("primitives.zig");
const validate_ = @import("validate.zig");

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
};

pub fn lower_AST(
    cfg: *cfg_.CFG,
    ast: *ast_.AST,
    labels: Labels,
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!?*lval_.L_Value {
    switch (ast.*) {
        // Literals
        .unit_type => {
            const lval = cfg.create_temp_lvalue(ast, allocator);
            cfg.appendInstruction(ir_.IR.init_ast(lval, ast, ast.getToken().span, allocator));
            return lval;
        },
        .unit_value => {
            const lval = cfg.create_temp_lvalue(primitives_.unit_type, allocator);
            cfg.appendInstruction(ir_.IR.init(.loadUnit, lval, null, null, ast.getToken().span, allocator));
            return lval;
        },
        .int => {
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            const ir = ir_.IR.initInt(temp, ast.int.data, ast.getToken().span, allocator);
            // temp.def = ir;
            cfg.appendInstruction(ir);
            return temp;
        },
        .char => {
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            // Convert the character inside to a codepoint
            var codepoint: u21 = undefined;
            switch (ast.getToken().data[1]) {
                '\\' => switch (ast.getToken().data[2]) {
                    'n' => codepoint = 0x0A,
                    'r' => codepoint = 0x0D,
                    't' => codepoint = 0x09,
                    '\\' => codepoint = 0x5C,
                    '\'' => codepoint = 0x27,
                    '"' => codepoint = 0x22,
                    else => unreachable,
                },
                else => {
                    const num_bytes = std.unicode.utf8ByteSequenceLength(ast.getToken().data[1]) catch return error.typeError;
                    codepoint = std.unicode.utf8Decode(ast.getToken().data[1 .. num_bytes + 1]) catch return error.typeError; // TODO: Add actual error diagnostics here
                },
            }
            const ir = ir_.IR.initInt(temp, codepoint, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .float => {
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            const ir = ir_.IR.initFloat(temp, ast.float.data, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .string => {
            module_.interned_string_set_add(ast.string.data, cfg.interned_strings);
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            const ir = ir_.IR.initString(temp, cfg.interned_strings.items.len - 1, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .identifier => {
            const symbol = ast.identifier.symbol.?;
            if (symbol.kind == ._fn) {
                _ = try symbol.get_cfg(cfg, cfg.interned_strings, errors, allocator);
                const lval = cfg.create_temp_lvalue(symbol._type, allocator);
                var ir = ir_.IR.init(.loadSymbol, lval, null, null, ast.getToken().span, allocator);
                ir.data = ir_.Data{ .symbol = symbol };
                cfg.appendInstruction(ir);
                return lval;
            } else if (symbol.expanded_type.?.typesMatch(primitives_.type_type)) {
                const lval = cfg.create_temp_lvalue(symbol._type, allocator);
                cfg.appendInstruction(ir_.IR.init_ast(lval, ast, ast.getToken().span, allocator));
                return lval;
            } else if (symbol.kind == ._const) {
                return try lower_AST(cfg, symbol.init, labels, errors, allocator);
            } else {
                const src = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                return src;
            }
        },
        .symbol => {
            const symbol = ast.symbol.symbol;
            std.debug.assert(symbol.kind == ._fn); // For returning functions at compile-time!
            _ = try symbol.get_cfg(cfg, cfg.interned_strings, errors, allocator);
            const lval = cfg.create_temp_lvalue(symbol._type, allocator);
            var ir = ir_.IR.init(.loadSymbol, lval, null, null, ast.getToken().span, allocator);
            ir.data = ir_.Data{ .symbol = symbol };
            cfg.appendInstruction(ir);
            return lval;
        },
        ._true => {
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            const ir = ir_.IR.initInt(temp, 1, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        ._false => {
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            const ir = ir_.IR.initInt(temp, 0, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },

        // Unary operators
        .not => {
            const expr = try lower_AST(cfg, ast.not.expr, labels, errors, allocator);
            if (expr == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init(.not, temp, expr, null, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .negate => {
            const expr = try lower_AST(cfg, ast.negate.expr, labels, errors, allocator);
            if (expr == null) {
                return null;
            }
            var temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init(if (temp.get_type().can_represent_float()) .negate_float else .negate_int, temp, expr, null, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .dereference => {
            const expr = try lower_AST(cfg, ast.dereference.expr, labels, errors, allocator);
            if (expr == null) {
                return null;
            }
            const _type = ast.typeof(allocator);
            const size = _type.expand_type(allocator).sizeof();
            const temp = lval_.L_Value.create_dereference(expr.?, size, _type, _type.expand_type(allocator), allocator);
            return temp;
        },
        ._try => {
            var expr = (try lower_AST(cfg, ast._try.expr, labels, errors, allocator)) orelse return null;

            const end = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const err = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

            var expanded_expr_type = expr.get_type().expand_type(allocator);
            // Trying error sum, runtime check if error, branch to error path
            const condition = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            cfg.appendInstruction(ir_.IR.initGetTag(condition, expr, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
            cfg.appendInstruction(ir_.IR.initBranch(condition, err, ast.getToken().span, allocator));

            // Unwrap the `.ok` value
            const retval_lval = lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
            cfg.appendInstruction(ir_.IR.init_simple_copy(retval_lval, expr, ast.getToken().span, allocator));
            cfg.appendInstruction(ir_.IR.initJump(labels.error_label, ast.getToken().span, allocator));

            // Else, store the error in retval, return through error
            cfg.appendInstruction(err);

            const ok_lval = lval_.L_Value.create_select(expr, 0, 0, expanded_expr_type.get_ok_type().sizeof(), expanded_expr_type.get_ok_type(), expanded_expr_type.get_ok_type().expand_type(allocator), null, allocator);
            cfg.appendInstruction(ir_.IR.initJump(end, ast.getToken().span, allocator));
            cfg.appendInstruction(end);

            return ok_lval;
        },
        .discard => {
            var expr = try lower_AST(cfg, ast.discard.expr, labels, errors, allocator);
            if (expr == null) {
                return null;
            }
            expr.?.extract_symbver().symbol.discard_span = ast.getToken().span;
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.initDiscard(expr.?, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },

        // Binary operators
        .assign => {
            const rhs = try lower_AST(cfg, ast.assign.rhs, labels, errors, allocator);
            if (rhs == null) {
                return null;
            }
            // If product, recursively generate a series of assignments
            // Else, create a *single* copy IR with an L_Value tree
            return try generate_assign(cfg, ast.assign.lhs, rhs.?, labels, errors, allocator);
        },
        ._or => {
            // Create the result symbol and IR
            const symbol = cfg.createTempSymbol(ast.typeof(allocator), allocator);
            const temp = lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // Labels used
            const else_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

            // Test lhs, branch
            const lhs = (try lower_AST(cfg, ast._or.lhs, labels, errors, allocator)) orelse return null;
            const branch = ir_.IR.initBranch(lhs, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // lhs was true, store `true` in temp
            const load_true_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            const load_true = ir_.IR.initInt(load_true_lval, 1, ast.getToken().span, allocator);
            cfg.appendInstruction(load_true);
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));

            // lhs was false, recurse to rhs, store in temp
            cfg.appendInstruction(else_label);
            const rhs = try lower_AST(cfg, ast._or.rhs, labels, errors, allocator);
            if (rhs == null) {
                return null;
            }
            const copy_right_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            const copy_right = ir_.IR.init_simple_copy(copy_right_lval, rhs.?, ast.getToken().span, allocator);
            cfg.appendInstruction(copy_right);
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));
            cfg.appendInstruction(end_label);
            return temp;
        },
        ._and => {
            // Create the result symbol and IR
            const symbol = cfg.createTempSymbol(ast.typeof(allocator), allocator);
            const temp = lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // Labels used
            const else_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

            // Test lhs, branch
            const lhs = (try lower_AST(cfg, ast._and.lhs, labels, errors, allocator)) orelse return null;
            const branch = ir_.IR.initBranch(lhs, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // lhs was true, recurse to rhs, store in temp
            const rhs = try lower_AST(cfg, ast._and.rhs, labels, errors, allocator);
            if (rhs == null) {
                return null;
            }
            const copy_right_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            const copy_right = ir_.IR.init_simple_copy(copy_right_lval, rhs.?, ast.getToken().span, allocator);
            cfg.appendInstruction(copy_right);
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));

            // lhs was false, store `false` in temp
            cfg.appendInstruction(else_label);
            const load_false_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            const load_false = ir_.IR.initInt(load_false_lval, 0, ast.getToken().span, allocator);
            cfg.appendInstruction(load_false);
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));
            cfg.appendInstruction(end_label);
            return temp;
        },
        .add => {
            const lhs = try lower_AST(cfg, ast.add.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.add.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init_int_float_kind(.add_int, .add_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .sub => {
            const lhs = try lower_AST(cfg, ast.sub.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.sub.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init_int_float_kind(.sub_int, .sub_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .mult => {
            const lhs = try lower_AST(cfg, ast.mult.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.mult.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init_int_float_kind(.mult_int, .mult_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .div => {
            const lhs = try lower_AST(cfg, ast.div.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.div.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init_int_float_kind(.div_int, .div_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .mod => {
            const lhs = try lower_AST(cfg, ast.mod.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.mod.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init(.mod, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .equal => {
            const lhs = try lower_AST(cfg, ast.equal.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.equal.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            // Labels used
            const fail_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

            generate_tuple_equality(cfg, lhs.?, rhs.?, fail_label, allocator);

            cfg.appendInstruction(ir_.IR.initInt(temp, 1, ast.getToken().span, allocator));
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));
            cfg.appendInstruction(fail_label);
            cfg.appendInstruction(ir_.IR.initInt(temp, 0, ast.getToken().span, allocator));
            cfg.appendInstruction(end_label);

            return temp;
        },
        .not_equal => {
            const lhs = try lower_AST(cfg, ast.not_equal.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.not_equal.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const lhs_type = ast.not_equal.lhs.typeof(allocator).expand_type(allocator);
            if (lhs_type.* == .sum) {
                const lhs_tag = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                const rhs_tag = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                cfg.appendInstruction(ir_.IR.initGetTag(lhs_tag, lhs.?, ast.getToken().span, allocator));
                cfg.appendInstruction(ir_.IR.initGetTag(rhs_tag, rhs.?, ast.getToken().span, allocator));
                cfg.appendInstruction(ir_.IR.init(.not_equal, temp, lhs_tag, rhs_tag, ast.getToken().span, allocator));
            } else {
                cfg.appendInstruction(ir_.IR.init(.not_equal, temp, lhs, rhs, ast.getToken().span, allocator));
            }
            return temp;
        },
        .greater => {
            const lhs = try lower_AST(cfg, ast.greater.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.greater.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init_int_float_kind(.greater_int, .greater_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .lesser => {
            const lhs = try lower_AST(cfg, ast.lesser.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.lesser.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init_int_float_kind(.lesser_int, .lesser_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .greater_equal => {
            const lhs = try lower_AST(cfg, ast.greater_equal.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.greater_equal.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init_int_float_kind(.greater_equal_int, .greater_equal_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .lesser_equal => {
            const lhs = try lower_AST(cfg, ast.lesser_equal.lhs, labels, errors, allocator);
            const rhs = try lower_AST(cfg, ast.lesser_equal.rhs, labels, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.init_int_float_kind(.lesser_equal_int, .lesser_equal_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        ._catch => {
            // Create the result symbol.
            // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
            const symbol = cfg.createTempSymbol(ast.typeof(allocator), allocator);
            const temp = lval_.L_Value.create_unversioned_symbver(symbol, allocator); // Not actually assigned directly, just so that optimizations can capture the version

            const lhs = (try lower_AST(cfg, ast._catch.lhs, labels, errors, allocator)) orelse return null;

            // Labels used
            const else_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

            // Test if lhs tag is 0 (ok)
            const condition = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            cfg.appendInstruction(ir_.IR.initGetTag(condition, lhs, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
            cfg.appendInstruction(ir_.IR.initBranch(condition, else_label, ast.getToken().span, allocator));

            // tag was an error, store rhs in temp
            const rhs = (try lower_AST(cfg, ast._catch.rhs, labels, errors, allocator)) orelse return null;
            const rhs_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(ir_.IR.init_simple_copy(rhs_lval, rhs, ast.getToken().span, allocator));

            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));
            cfg.appendInstruction(else_label);

            // tag was `.ok`, store lhs.some in temp
            const _type = ast.typeof(allocator);
            const size = _type.expand_type(allocator).sizeof();
            const val = lval_.L_Value.create_select(lhs, 0, 0, size, _type, _type.expand_type(allocator), null, allocator);
            const some_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(ir_.IR.init_simple_copy(some_lval, val, ast.getToken().span, allocator));

            cfg.appendInstruction(end_label);
            return temp;
        },
        ._orelse => {
            // Create the result symbol.
            // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
            const symbol = cfg.createTempSymbol(ast.typeof(allocator), allocator);
            const temp = lval_.L_Value.create_unversioned_symbver(symbol, allocator); // Not actually assigned directly, just so that optimizations can capture the version

            var lhs = (try lower_AST(cfg, ast._orelse.lhs, labels, errors, allocator)) orelse return null;

            // Labels used
            const else_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

            // Test if lhs tag is 1 (some)
            const condition = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const load_tag = ir_.IR.initGetTag(condition, lhs, ast.getToken().span, allocator); // Assumes `some` tag is nonzero, `none` tag is zero
            cfg.appendInstruction(load_tag);

            const branch = ir_.IR.initBranch(condition, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // tag was `.some`, store lhs.some in temp
            const _type = ast.typeof(allocator);
            const size = _type.expand_type(allocator).sizeof();
            const offset = lhs.get_type().expand_type(allocator).sum.get_offset(1, allocator);
            const val = lval_.L_Value.create_select(lhs, 1, offset, size, _type, _type.expand_type(allocator), null, allocator);
            const some_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(ir_.IR.init_simple_copy(some_lval, val, ast.getToken().span, allocator));
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));

            cfg.appendInstruction(else_label);

            // tag was `.none`, store rhs in temp
            const rhs = (try lower_AST(cfg, ast._orelse.rhs, labels, errors, allocator)) orelse return null;

            const rhs_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(ir_.IR.init_simple_copy(rhs_lval, rhs, ast.getToken().span, allocator));

            cfg.appendInstruction(end_label);
            return temp;
        },
        .call => {
            const lhs = (try lower_AST(cfg, ast.call.lhs, labels, errors, allocator)) orelse return null;
            var temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            temp.extract_symbver().symbol.span = ast.getToken().span;

            var ir = ir_.IR.initCall(temp, lhs, ast.getToken().span, allocator);
            for (ast.call.args.items) |term| {
                ir.data.lval_list.append((try lower_AST(cfg, term, labels, errors, allocator)) orelse continue) catch unreachable;
            }
            cfg.appendInstruction(ir_.IR.initStackPush(ast.getToken().span, allocator));
            cfg.appendInstruction(ir);
            cfg.appendInstruction(ir_.IR.initStackPop(ast.getToken().span, allocator));
            return temp;
        },
        .function => {
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            cfg.appendInstruction(ir_.IR.init_ast(temp, ast, ast.getToken().span, allocator));
            return temp;
        },
        .index => {
            const _type = ast.typeof(allocator);
            const size = _type.expand_type(allocator).sizeof();

            // Get the type of the index ast. This will determine if this is an array index or a slice index
            const ast_expanded_type = ast.index.lhs.typeof(allocator).expand_type(allocator);

            // Flatten index expr
            const rhs = try lower_AST(cfg, ast.index.rhs, labels, errors, allocator);

            // Recursively get index's ast L_Value node
            const pre_ast_lval = try lower_AST(cfg, ast.index.lhs, labels, errors, allocator);
            var ast_lval = pre_ast_lval;

            if (ast_expanded_type.product.was_slice) {
                // Indexing a slice; index_val := lhs._0^[rhs]
                const addr_type = ast_expanded_type.product.terms.items[0];
                const addr_size = _type.expand_type(allocator).sizeof();
                ast_lval = lval_.L_Value.create_select(ast_lval.?, 0, 0, addr_size, addr_type, _type.expand_type(allocator), null, allocator);
                ast_lval = lval_.L_Value.create_dereference(ast_lval.?, addr_size, addr_type, _type.expand_type(allocator), allocator);
            }

            // Do bounds-check
            var length: *lval_.L_Value = undefined;
            if (ast_expanded_type.* == .product and ast_expanded_type.product.was_slice) {
                const offset = ast_expanded_type.product.get_offset(1, allocator);
                length = lval_.L_Value.create_select(pre_ast_lval.?, 1, offset, 8, primitives_.int64_type, primitives_.int64_type, null, allocator);
            } else if (ast_expanded_type.* == .product and !ast_expanded_type.product.was_slice) {
                length = cfg.create_temp_lvalue(primitives_.int_type, allocator);
                const ir = ir_.IR.initInt(length, ast_expanded_type.product.terms.items.len, ast.getToken().span, allocator);
                cfg.appendInstruction(ir);
            } else {
                unreachable;
            }

            // Surround with L_Value node
            return lval_.L_Value.create_index(ast_lval.?, rhs.?, length, size, _type, _type.expand_type(allocator), allocator);
        },
        .select => {
            // Recursively get select's ast L_Value node
            const ast_lval = try lower_AST(cfg, ast.select.lhs, labels, errors, allocator);

            // Get the offset into the struct that this select does
            var lhs_expanded_type = ast.select.lhs.typeof(allocator).expand_type(allocator);
            const offset = if (lhs_expanded_type.* == .product)
                lhs_expanded_type.product.get_offset(ast.select.pos.?, allocator)
            else
                lhs_expanded_type.sum.get_offset(ast.select.pos.?, allocator);

            var tag: ?*lval_.L_Value = null;
            if (lhs_expanded_type.* == .sum) {
                // Check that the sum value has the proper tag before a selection
                tag = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                cfg.appendInstruction(ir_.IR.initGetTag(tag.?, ast_lval.?, ast.getToken().span, allocator));
            }

            // Surround with L_Value node
            const _type = ast.typeof(allocator);
            const expanded_type = _type.expand_type(allocator);
            return lval_.L_Value.create_select(ast_lval.?, ast.select.pos.?, offset, expanded_type.sizeof(), _type, expanded_type, tag, allocator);
        },
        .product => {
            if (ast.product.terms.items[0].typeof(allocator).typesMatch(primitives_.type_type)) {
                const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
                cfg.appendInstruction(ir_.IR.init_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            } else {
                const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
                var ir = ir_.IR.initLoadStruct(temp, ast.getToken().span, allocator);
                for (ast.product.terms.items) |term| {
                    ir.data.lval_list.append((try lower_AST(cfg, term, labels, errors, allocator)) orelse return null) catch unreachable;
                }
                cfg.appendInstruction(ir);
                return temp;
            }
        },
        .sum => {
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            cfg.appendInstruction(ir_.IR.init_ast(temp, ast, ast.getToken().span, allocator));
            return temp;
        },

        // Fancy Operators
        .addrOf => {
            if ((ast.typeof(allocator)).typesMatch(primitives_.type_type)) {
                const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
                cfg.appendInstruction(ir_.IR.init_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            } else {
                const expr = try lower_AST(cfg, ast.addrOf.expr, labels, errors, allocator);
                const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

                const ir = ir_.IR.init(.addrOf, temp, expr, null, ast.getToken().span, allocator);
                cfg.appendInstruction(ir);
                return temp;
            }
        },
        .subSlice => {
            const arr = (try lower_AST(cfg, ast.subSlice.super, labels, errors, allocator)) orelse return null;
            const lower = (try lower_AST(cfg, ast.subSlice.lower.?, labels, errors, allocator)) orelse return null;
            const upper = (try lower_AST(cfg, ast.subSlice.upper.?, labels, errors, allocator)) orelse return null;

            // Statically confirm that lower <= upper
            // if (lower.def.?.kind == .loadInt and upper.def.?.kind == .loadInt and lower.def.?.data.int > upper.def.?.data.int) {
            //     errors.addError(Error{ .slice_lower_upper = .{
            //         .span = lower.def.?.span,
            //         .lower = lower.def.?.data.int,
            //         .upper = upper.def.?.data.int,
            //     } });
            //     return error.typeError;
            // } else
            { // Dynamically confirm that lower <= upper
                const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
                const compare = cfg.create_temp_lvalue(primitives_.bool_type, allocator);
                const ir = ir_.IR.init(.greater_int, compare, lower, upper, ast.getToken().span, allocator);
                cfg.appendInstruction(ir);
                const branch = ir_.IR.initBranch(compare, end_label, ast.getToken().span, allocator);
                cfg.appendInstruction(branch);
                cfg.appendInstruction(ir_.IR.initStackPush(ast.getToken().span, allocator));
                cfg.appendInstruction(ir_.IR.initPanic("subslice lower bound is greater than upper bound", ast.getToken().span, allocator));
                cfg.appendInstruction(end_label);
            }

            const new_size = cfg.create_temp_lvalue(primitives_.int_type, allocator);
            const new_size_ir = ir_.IR.init(.sub_int, new_size, upper, lower, ast.getToken().span, allocator);
            cfg.appendInstruction(new_size_ir);

            const slice_type = ast.typeof(allocator);
            const data_type = slice_type.product.terms.items[0];
            const size = data_type.expand_type(allocator).sizeof();
            const data_ptr = lval_.L_Value.create_select(arr, 0, 0, size, data_type, data_type.expand_type(allocator), null, allocator);

            const new_data_ptr = cfg.create_temp_lvalue(data_type, allocator);
            const new_data_ptr_ir = ir_.IR.init(.add_int, new_data_ptr, data_ptr, lower, ast.getToken().span, allocator);
            cfg.appendInstruction(new_data_ptr_ir);

            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            var load_struct = ir_.IR.initLoadStruct(temp, ast.getToken().span, allocator);
            load_struct.data.lval_list.append(new_data_ptr) catch unreachable;
            load_struct.data.lval_list.append(new_size) catch unreachable;
            cfg.appendInstruction(load_struct);
            return temp;
        },
        .annotation => {
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);
            cfg.appendInstruction(ir_.IR.init_ast(temp, ast, ast.getToken().span, allocator));
            return temp;
        },
        .inferredMember => {
            var init: ?*lval_.L_Value = null;
            const pos: i128 = ast.inferredMember.pos.?;
            const proper_term: *ast_.AST = (ast.typeof(allocator)).sum.terms.items[@as(usize, @intCast(pos))];
            if (proper_term.annotation.type.* != .unit_type) {
                init = try lower_AST(cfg, ast.inferredMember.init.?, labels, errors, allocator);
            }
            const temp = cfg.create_temp_lvalue(ast.typeof(allocator), allocator);

            const ir = ir_.IR.initUnion(temp, init, ast.inferredMember.pos.?, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },

        // Control-flow expressions
        ._if => {
            // Create the result symbol and IR
            const symbol = cfg.createTempSymbol(ast.typeof(allocator), allocator);
            const temp = lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // If there's a let, then do it, dumby!
            if (ast._if.let) |let| {
                _ = try lower_AST(cfg, let, labels, errors, allocator);
            }

            // Labels used
            const else_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

            // Test lhs, branch
            const condition = (try lower_AST(cfg, ast._if.condition, labels, errors, allocator)) orelse return null;
            const branch = ir_.IR.initBranch(condition, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // lhs was true, recurse to rhs, store in temp
            if (try lower_AST(cfg, ast._if.bodyBlock, labels, errors, allocator)) |block_lval| {
                const block_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                var block_copy: *ir_.IR = undefined;
                if (ast._if.elseBlock == null) {
                    // no else block => if is optional, coerce up to `.some <- block`
                    block_copy = ir_.IR.initUnion(block_copy_lval, block_lval, 1, ast.getToken().span, allocator);
                } else {
                    // regular if-else => copy block
                    block_copy = ir_.IR.init_simple_copy(block_copy_lval, block_lval, ast.getToken().span, allocator);
                }
                cfg.appendInstruction(block_copy);
            }
            cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));

            // lhs was false, store `false` in temp
            cfg.appendInstruction(else_label);
            if (ast._if.elseBlock) |elseBlock| {
                if (try lower_AST(cfg, elseBlock, labels, errors, allocator)) |else_lval| {
                    const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    const else_copy = ir_.IR.init_simple_copy(else_copy_lval, else_lval, ast.getToken().span, allocator);
                    cfg.appendInstruction(else_copy);
                }
                cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));
            } else {
                // no else block => if is optional, store null
                const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const else_copy = ir_.IR.initUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                cfg.appendInstruction(else_copy);
            }
            cfg.appendInstruction(end_label);
            return temp;
        },
        .match => {
            // Create the result symbol and IR
            const symbol_type = if (ast.match.has_else)
                // Match has an else, type of the mappings should be the type of the match
                ast.typeof(allocator)
            else
                // Match has no else, type of the mappings should be wrapped in an optional type
                ast_.AST.create_optional_type(ast.typeof(allocator), allocator);
            const symbol = cfg.createTempSymbol(symbol_type, allocator);
            const temp = lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // Exit label of match
            const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            // Label jumped to if all tests fail and no `else` mapping
            const none_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            // List of labels to branch to on an unsuccessful test (ie "next pattern")
            var lhs_label_list = std.ArrayList(*ir_.IR).init(allocator);
            defer lhs_label_list.deinit();
            // List of labels to branch to on a successful test (ie "code for the mapping")
            var rhs_label_list = std.ArrayList(*ir_.IR).init(allocator);
            defer rhs_label_list.deinit();
            for (ast.match.mappings.items) |_| {
                lhs_label_list.append(ir_.IR.initLabel(cfg, ast.getToken().span, allocator)) catch unreachable;
                rhs_label_list.append(ir_.IR.initLabel(cfg, ast.getToken().span, allocator)) catch unreachable;
            }
            std.debug.assert(lhs_label_list.items.len == ast.match.mappings.items.len);

            // If there's a let, then do it, dumby!
            if (ast.match.let) |let| {
                _ = try lower_AST(cfg, let, labels, errors, allocator);
            }

            const expr = try lower_AST(cfg, ast.match.expr, labels, errors, allocator);
            if (expr == null) {
                return null;
            }

            // Generate the lhs of the mappings
            var label_index: usize = 0;
            for (ast.match.mappings.items) |mapping| {
                const lhs_label = lhs_label_list.items[label_index];
                cfg.appendInstruction(lhs_label);
                if (mapping.mapping.lhs) |lhs| {
                    const next_label = if (label_index < lhs_label_list.items.len - 1)
                        lhs_label_list.items[label_index + 1]
                    else
                        none_label;
                    try generate_match_pattern_check(cfg, lhs, expr.?, next_label, labels, errors, allocator);
                }
                cfg.appendInstruction(ir_.IR.initJump(rhs_label_list.items[label_index], mapping.getToken().span, allocator));
                label_index += 1;
            }

            if (!ast.match.has_else) { // All tests failed, no `else` mapping. Store `.none` as result
                cfg.appendInstruction(none_label);
                const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const else_copy = ir_.IR.initUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                cfg.appendInstruction(else_copy);
                cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));
            }

            // Write the labels and the rhs of the mappings
            label_index = 0;
            for (ast.match.mappings.items) |mapping| {
                cfg.appendInstruction(rhs_label_list.items[label_index]);
                if (mapping.mapping.lhs) |lhs| {
                    // Generate initialization for patterns before the rhs
                    try generate_pattern(cfg, lhs, expr.?.get_type(), expr.?, errors, allocator);
                }

                // Generate the rhs, copy result to temp
                if (try lower_AST(cfg, mapping.mapping.rhs.?, labels, errors, allocator)) |rhs_lval| {
                    const rhs_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    var rhs_copy: *ir_.IR = undefined;
                    if (ast.match.has_else) {
                        rhs_copy = ir_.IR.init_simple_copy(rhs_copy_lval, rhs_lval, ast.getToken().span, allocator);
                    } else {
                        rhs_copy = ir_.IR.initUnion(rhs_copy_lval, rhs_lval, 1, ast.getToken().span, allocator);
                    }
                    cfg.appendInstruction(rhs_copy);
                }
                cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));
                label_index += 1;
            }
            cfg.appendInstruction(end_label);

            return temp;
        },
        ._while => {
            // Create the result symbol and IR
            const symbol = cfg.createTempSymbol(ast.typeof(allocator), allocator);
            const temp = lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // Labels used
            const cond_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const current_continue_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const else_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);
            const end_label = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

            // If there's a let, then do it, dumby!
            if (ast._while.let) |let| {
                _ = try lower_AST(cfg, let, labels, errors, allocator);
            }

            // Test condition, branch to either body or else block
            cfg.appendInstruction(cond_label);
            const condition = (try lower_AST(cfg, ast._while.condition, .{ .return_label = labels.return_label, .break_label = end_label, .continue_label = current_continue_label, .error_label = labels.error_label }, errors, allocator)) orelse return null;
            const branch = ir_.IR.initBranch(condition, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // Body block
            if (try lower_AST(cfg, ast._while.bodyBlock, .{ .return_label = labels.return_label, .break_label = end_label, .continue_label = current_continue_label, .error_label = labels.error_label }, errors, allocator)) |block_lval| {
                const block_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                var block_copy: *ir_.IR = undefined;
                if (ast._while.elseBlock == null) {
                    // no else block => while is optional, coerce up to `.some <- block`
                    block_copy = ir_.IR.initUnion(block_copy_lval, block_lval, 1, ast.getToken().span, allocator);
                } else {
                    // regular while-else => copy block
                    block_copy = ir_.IR.init_simple_copy(block_copy_lval, block_lval, ast.getToken().span, allocator);
                }
                cfg.appendInstruction(block_copy);
            }

            // Post-condition, jump to condition test
            cfg.appendInstruction(current_continue_label);
            if (ast._while.post) |post| {
                _ = try lower_AST(cfg, post, .{ .return_label = labels.return_label, .break_label = end_label, .continue_label = labels.continue_label, .error_label = labels.error_label }, errors, allocator);
            }
            cfg.appendInstruction(ir_.IR.initJump(cond_label, ast.getToken().span, allocator));

            // Else block
            cfg.appendInstruction(else_label);
            if (ast._while.elseBlock) |elseBlock| {
                if (try lower_AST(cfg, elseBlock, labels, errors, allocator)) |else_lval| {
                    const elseCopy = ir_.IR.init_simple_copy(temp, else_lval, ast.getToken().span, allocator);
                    cfg.appendInstruction(elseCopy);
                }
                cfg.appendInstruction(ir_.IR.initJump(end_label, ast.getToken().span, allocator));
            } else {
                // no else block => while is optional, store null
                const else_copy_lval = lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const else_copy = ir_.IR.initUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                cfg.appendInstruction(else_copy);
            }
            cfg.appendInstruction(end_label);
            return temp;
        },
        .block => {
            if (ast.block.statements.items.len == 0 and ast.block.final == null) {
                return null;
            } else {
                var continue_labels = std.ArrayList(*ir_.IR).init(allocator);
                defer continue_labels.deinit();
                var break_labels = std.ArrayList(*ir_.IR).init(allocator);
                defer break_labels.deinit();
                var return_labels = std.ArrayList(*ir_.IR).init(allocator);
                defer return_labels.deinit();
                var error_labels = std.ArrayList(*ir_.IR).init(allocator);
                defer error_labels.deinit();
                for (ast.block.scope.?.defers.items) |_| {
                    continue_labels.append(ir_.IR.initLabel(cfg, ast.getToken().span, allocator)) catch unreachable;
                    break_labels.append(ir_.IR.initLabel(cfg, ast.getToken().span, allocator)) catch unreachable;
                    return_labels.append(ir_.IR.initLabel(cfg, ast.getToken().span, allocator)) catch unreachable;
                }
                for (ast.block.scope.?.errdefers.items) |_| {
                    error_labels.append(ir_.IR.initLabel(cfg, ast.getToken().span, allocator)) catch unreachable;
                }
                const end = ir_.IR.initLabel(cfg, ast.getToken().span, allocator);

                // These are the labels to go to on each final statement. These are updated to point to different places in the defer chain at the end of this block.
                var current_continue_label = if (labels.continue_label != null) labels.continue_label else end;
                var current_break_label = labels.break_label;
                var current_return_label = labels.return_label;
                var current_error_label = labels.error_label;
                var defer_label_index: usize = 0;
                var errdefer_label_index: usize = 0;

                var temp: ?*lval_.L_Value = null;
                for (ast.block.statements.items) |child| {
                    temp = try lower_AST(cfg, child, .{ .return_label = current_return_label, .break_label = current_break_label, .continue_label = current_continue_label, .error_label = current_error_label }, errors, allocator);
                    if (child.* == ._defer) {
                        current_continue_label = continue_labels.items[defer_label_index];
                        current_break_label = break_labels.items[defer_label_index];
                        current_return_label = return_labels.items[defer_label_index];
                        defer_label_index += 1;
                    } else if (child.* == ._errdefer) {
                        current_error_label = error_labels.items[errdefer_label_index];
                        errdefer_label_index += 1;
                    }
                }
                if (ast.block.final) |final| {
                    temp = try lower_AST(cfg, final, .{ .return_label = current_return_label, .break_label = current_break_label, .continue_label = current_continue_label, .error_label = current_error_label }, errors, allocator);
                } else if (temp) |_temp| {
                    const expanded_temp_type = _temp.get_type().expand_type(allocator);
                    if (current_error_label != null and expanded_temp_type.* == .sum and expanded_temp_type.sum.was_error) {
                        // Returning error sum, runtime check if error, branch to error path
                        const condition = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                        cfg.appendInstruction(ir_.IR.initGetTag(condition, _temp, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                        const not_condition = cfg.create_temp_lvalue(primitives_.bool_type, allocator);
                        cfg.appendInstruction(ir_.IR.init(.not, not_condition, condition, null, ast.getToken().span, allocator));
                        cfg.appendInstruction(ir_.IR.initBranch(not_condition, current_error_label, ast.getToken().span, allocator));
                    }
                }

                try generateDefers(cfg, &ast.block.scope.?.defers, &continue_labels, errors, allocator);
                cfg.appendInstruction(ir_.IR.initJump(end, ast.getToken().span, allocator));

                try generateDefers(cfg, &ast.block.scope.?.defers, &break_labels, errors, allocator);
                cfg.appendInstruction(ir_.IR.initJump(labels.break_label, ast.getToken().span, allocator));

                try generateDefers(cfg, &ast.block.scope.?.defers, &return_labels, errors, allocator);
                cfg.appendInstruction(ir_.IR.initJump(labels.return_label, ast.getToken().span, allocator));

                try generateDefers(cfg, &ast.block.scope.?.errdefers, &error_labels, errors, allocator);
                cfg.appendInstruction(ir_.IR.initJump(labels.error_label, ast.getToken().span, allocator));

                cfg.appendInstruction(end);

                return temp;
            }
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
        .fnDecl => {
            _ = try ast.fnDecl.symbol.?.get_cfg(cfg, cfg.interned_strings, errors, allocator);
            const temp = cfg.create_temp_lvalue(ast.fnDecl.symbol.?._type, allocator);
            var ir = ir_.IR.init(.loadSymbol, temp, null, null, ast.getToken().span, allocator);
            ir.data = ir_.Data{ .symbol = ast.fnDecl.symbol.? };
            cfg.appendInstruction(ir);
            return temp;
        },
        ._errdefer, ._defer => {
            return null;
        },
        ._continue => {
            cfg.appendInstruction(ir_.IR.initJump(labels.continue_label, ast.getToken().span, allocator));
            return null;
        },
        ._unreachable => {
            cfg.appendInstruction(ir_.IR.initStackPush(ast.getToken().span, allocator));
            cfg.appendInstruction(ir_.IR.initPanic("reached unreachable code", ast.getToken().span, allocator));
            return null;
        },
        ._break => {
            cfg.appendInstruction(ir_.IR.initJump(labels.break_label, ast.getToken().span, allocator));
            return null;
        },
        ._return => {
            if (ast._return.expr) |expr| {
                // Copy expr to retval
                const retval = (try lower_AST(cfg, expr, labels, errors, allocator)) orelse return null;
                const retval_lval = lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
                const retval_copy = ir_.IR.init_simple_copy(retval_lval, retval, ast.getToken().span, allocator);
                cfg.appendInstruction(retval_copy);

                const expanded_expr_type = expr.typeof(allocator).expand_type(allocator);
                if (expanded_expr_type.* == .sum and expanded_expr_type.sum.was_error) {
                    // Returning error sum, runtime check if error, branch to error path
                    const condition = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                    cfg.appendInstruction(ir_.IR.initGetTag(condition, retval, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                    const not_condition = cfg.create_temp_lvalue(primitives_.bool_type, allocator);
                    cfg.appendInstruction(ir_.IR.init(.not, not_condition, condition, null, ast.getToken().span, allocator));
                    cfg.appendInstruction(ir_.IR.initBranch(not_condition, labels.error_label, ast.getToken().span, allocator));
                }
                cfg.appendInstruction(ir_.IR.initJump(labels.return_label, ast.getToken().span, allocator));
            } else {
                // Jump to return_label
                cfg.appendInstruction(ir_.IR.initJump(labels.return_label, ast.getToken().span, allocator));
            }
            return null;
        },

        else => {
            std.debug.print("Unimplemented lower_AST() for: AST.{s}\n", .{@tagName(ast.*)});
            unreachable;
        },
    }
}

fn generate_tuple_equality(
    cfg: *cfg_.CFG,
    lhs: *lval_.L_Value,
    rhs: *lval_.L_Value,
    fail_label: *ir_.IR,
    allocator: std.mem.Allocator,
) void {
    const new_lhs = lhs; // try L_Value.create_unversioned_symbver(lhs.symbol, lhs.symbol._type.?, allocator);
    const new_rhs = rhs; // try L_Value.create_unversioned_symbver(rhs.symbol, rhs.symbol._type.?, allocator);
    const temp = cfg.create_temp_lvalue(primitives_.bool_type, allocator);
    var lhs_type = lhs.get_type().expand_type(allocator);
    if (lhs_type.* == .product) {
        for (0..lhs_type.product.terms.items.len) |i| {
            const _type = lhs_type.product.terms.items[i];
            const size = (_type.expand_type(allocator)).sizeof();
            const lhs_select = lval_.L_Value.create_select(new_lhs, i, lhs_type.product.get_offset(i, allocator), size, _type, _type.expand_type(allocator), null, allocator);
            const rhs_select = lval_.L_Value.create_select(new_rhs, i, lhs_type.product.get_offset(i, allocator), size, _type, _type.expand_type(allocator), null, allocator);
            generate_tuple_equality(cfg, lhs_select, rhs_select, fail_label, allocator);
        }
    } else if (lhs_type.* == .sum) {
        const lhs_tag = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
        const rhs_tag = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
        cfg.appendInstruction(ir_.IR.initGetTag(lhs_tag, new_lhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(ir_.IR.initGetTag(rhs_tag, new_rhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(ir_.IR.init(.equal, temp, lhs_tag, rhs_tag, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(ir_.IR.initBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
    } else {
        cfg.appendInstruction(ir_.IR.init(.equal, temp, new_lhs, rhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(ir_.IR.initBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
    }
}

fn generate_assign(
    cfg: *cfg_.CFG, // Current control-flow-graph
    lhs: *ast_.AST, // AST node for the LHS of the `=`
    rhs: *lval_.L_Value, // L_Value which holds the value to assign
    labels: Labels,
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!?*lval_.L_Value // If assign is to a single symbver, returns the symbver
{
    if (lhs.* == .product) {
        // Recursively call `generate_assign` for each term in the product.
        // product-assigns may be nested, for example:
        //     ((x, y), (a, b)) = get_tuple()
        // So it's important that this is recursive
        var lhs_expanded_type = lhs.typeof(allocator).expand_type(allocator);
        for (lhs.product.terms.items, 0..) |term, i| {
            const product_lhs = try lower_AST(cfg, term, labels, errors, allocator);
            if (product_lhs == null) {
                continue;
            }
            const _type = rhs.get_type().product.terms.items[i];
            const size = _type.expand_type(allocator).sizeof();
            const select = lval_.L_Value.create_select(rhs, i, lhs_expanded_type.product.get_offset(i, allocator), size, _type, _type.expand_type(allocator), null, allocator);
            _ = try generate_assign(cfg, term, select, labels, errors, allocator);
        }
        return null;
    } else {
        // Get L_Value tree, create a `copy` IR of L_Value tree and rhs
        const lval = try lower_AST(cfg, lhs, labels, errors, allocator);
        var ir = ir_.IR.init(.copy, null, rhs, null, lhs.getToken().span, allocator);
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
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!void {
    if (pattern.* == .symbol) {
        if (!std.mem.eql(u8, pattern.symbol.name, "_")) {
            const symbver = lval_.L_Value.create_unversioned_symbver(pattern.symbol.symbol, allocator);
            const ir = ir_.IR.init_simple_copy(symbver, def, pattern.getToken().span, allocator);
            cfg.appendInstruction(ir);
        }
    } else if (pattern.* == .product) {
        for (pattern.product.terms.items, 0..) |term, i| {
            const subscript_type = _type.product.terms.items[i];
            const size = subscript_type.expand_type(allocator).sizeof();
            const offset = _type.product.get_offset(i, allocator);
            const lval = lval_.L_Value.create_select(def, i, offset, size, subscript_type, subscript_type.expand_type(allocator), null, allocator);
            try generate_pattern(cfg, term, subscript_type, lval, errors, allocator);
        }
    } else if (pattern.* == .inject) {
        const lhs_type = pattern.inject.lhs.typeof(allocator);
        const domain = try validate_.domainof(pattern, lhs_type, errors, allocator);
        const size = domain.expand_type(allocator).sizeof();
        const lval = lval_.L_Value.create_select(def, pattern.inject.lhs.inferredMember.pos.?, 0, size, domain, domain.expand_type(allocator), null, allocator);
        try generate_pattern(cfg, pattern.inject.rhs, domain, lval, errors, allocator);
    }
}

/// Generates the code which checks if the pattern matches the match expression
fn generate_match_pattern_check(
    cfg: *cfg_.CFG,
    pattern: ?*ast_.AST,
    expr: *lval_.L_Value,
    next_pattern: *ir_.IR,
    labels: Labels,
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!void {
    if (pattern == null) {
        // Implies `else` branch, infallible.
        return;
    }
    switch (pattern.?.*) {
        .int,
        .float,
        ._true,
        ._false,
        .char,
        .string,
        .block,
        => {
            const value = try lower_AST(cfg, pattern.?, labels, errors, allocator);
            const condition = cfg.create_temp_lvalue(primitives_.bool_type, allocator);
            const condition_ir = ir_.IR.init(.equal, condition, expr, value.?, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(condition_ir);
            const branch = ir_.IR.initBranch(condition, next_pattern, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(branch);
        },
        .symbol => {
            // Infallible check, do not branch to next pattern
        },
        .product => {
            for (pattern.?.product.terms.items, 0..) |term, i| {
                const subscript_type = expr.get_type().product.terms.items[i];
                const size = subscript_type.expand_type(allocator).sizeof();
                const pattern_type = pattern.?.typeof(allocator).expand_type(allocator);
                const offset = pattern_type.product.get_offset(i, allocator);
                const lval = lval_.L_Value.create_select(expr, i, offset, size, subscript_type, subscript_type.expand_type(allocator), null, allocator);
                try generate_match_pattern_check(cfg, term, lval, next_pattern, labels, errors, allocator);
            }
        },
        .select => {
            // Get tag of pattern
            const sel = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const sel_ir = ir_.IR.initInt(sel, pattern.?.select.pos.?, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(sel_ir);

            // Get tag of expr
            const tag = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const tag_ir = ir_.IR.initGetTag(tag, expr, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(tag_ir);

            // Compare them, jump to next pattern if they are not equal
            const neql = cfg.create_temp_lvalue(primitives_.bool_type, allocator);
            const neql_ir = ir_.IR.init(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(neql_ir);
            const branch = ir_.IR.initBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(branch);
        },
        .inferredMember => {
            // Get tag of pattern
            const sel = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const sel_ir = ir_.IR.initInt(sel, pattern.?.inferredMember.pos.?, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(sel_ir);

            // Get tag of expr
            const tag = cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const tag_ir = ir_.IR.initGetTag(tag, expr, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(tag_ir);

            // Compare them, jump to next pattern if they are not equal
            const neql = cfg.create_temp_lvalue(primitives_.bool_type, allocator);
            const neql_ir = ir_.IR.init(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(neql_ir);
            const branch = ir_.IR.initBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(branch);
        },
        .inject => {
            try generate_match_pattern_check(cfg, pattern.?.inject.lhs, expr, next_pattern, labels, errors, allocator);
        },
        else => {
            std.debug.print("Unimplemented generate_match_pattern_check() for {s}\n", .{@tagName(pattern.?.*)});
            unreachable;
        },
    }
}

fn generateDefers(cfg: *cfg_.CFG, defers: *std.ArrayList(*ast_.AST), deferLabels: *std.ArrayList(*ir_.IR), errors: *errs.Errors, allocator: std.mem.Allocator) FlattenASTError!void {
    var i: usize = defers.items.len;
    while (i > 0) : (i -= 1) {
        cfg.appendInstruction(deferLabels.items[i - 1]);
        _ = try lower_AST(cfg, defers.items[i - 1], .{ .return_label = null, .break_label = null, .continue_label = null, .error_label = null }, errors, allocator);
    }
}
