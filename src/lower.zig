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
    OutOfMemory,
    NotAnLValue,
    Unimplemented,
    InvalidRange,
    interpreter_panic,
    // Utf8ExpectedContinuation,
    // Utf8OverlongEncoding,
    // Utf8EncodesSurrogateHalf,
    // Utf8CodepointTooLarge,
};

pub fn lower_AST(
    cfg: *cfg_.CFG,
    ast: *ast_.AST,
    return_label: ?*ir_.IR,
    break_label: ?*ir_.IR,
    continue_label: ?*ir_.IR,
    error_label: ?*ir_.IR,
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!?*lval_.L_Value {
    switch (ast.*) {
        // Literals
        .unit_type => {
            const lval = try cfg.create_temp_lvalue(ast, allocator);
            cfg.appendInstruction(try ir_.IR.create_ast(lval, ast, ast.getToken().span, allocator));
            return lval;
        },
        .unit_value => {
            const lval = try cfg.create_temp_lvalue(primitives_.unit_type, allocator);
            cfg.appendInstruction(try ir_.IR.create(.loadUnit, lval, null, null, ast.getToken().span, allocator));
            return lval;
        },
        .int => {
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            const ir = try ir_.IR.createInt(temp, ast.int.data, ast.getToken().span, allocator);
            // temp.def = ir;
            cfg.appendInstruction(ir);
            return temp;
        },
        .char => {
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
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
            const ir = try ir_.IR.createInt(temp, codepoint, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .float => {
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            const ir = try ir_.IR.createFloat(temp, ast.float.data, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .string => {
            try module_.interned_string_set_add(ast.string.data, cfg.interned_strings);
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            const ir = try ir_.IR.createString(temp, cfg.interned_strings.items.len - 1, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .identifier => {
            const symbol = ast.identifier.symbol.?;
            if (symbol.kind == ._fn) {
                _ = try symbol.get_cfg(cfg, cfg.interned_strings, errors, allocator);
                const lval = try cfg.create_temp_lvalue(symbol._type, allocator);
                var ir = try ir_.IR.create(.loadSymbol, lval, null, null, ast.getToken().span, allocator);
                ir.data = ir_.Data{ .symbol = symbol };
                cfg.appendInstruction(ir);
                return lval;
            } else if (try symbol.expanded_type.?.typesMatch(primitives_.type_type)) {
                const lval = try cfg.create_temp_lvalue(symbol._type, allocator);
                cfg.appendInstruction(try ir_.IR.create_ast(lval, ast, ast.getToken().span, allocator));
                return lval;
            } else if (symbol.kind == ._const) {
                return try lower_AST(cfg, symbol.init, return_label, break_label, continue_label, error_label, errors, allocator);
            } else {
                const src = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                return src;
            }
        },
        .symbol => {
            const symbol = ast.symbol.symbol;
            std.debug.assert(symbol.kind == ._fn); // For returning functions at compile-time!
            _ = try symbol.get_cfg(cfg, cfg.interned_strings, errors, allocator);
            const lval = try cfg.create_temp_lvalue(symbol._type, allocator);
            var ir = try ir_.IR.create(.loadSymbol, lval, null, null, ast.getToken().span, allocator);
            ir.data = ir_.Data{ .symbol = symbol };
            cfg.appendInstruction(ir);
            return lval;
        },
        ._true => {
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            const ir = try ir_.IR.createInt(temp, 1, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        ._false => {
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            const ir = try ir_.IR.createInt(temp, 0, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },

        // Unary operators
        .not => {
            const expr = try lower_AST(cfg, ast.not.expr, return_label, break_label, continue_label, error_label, errors, allocator);
            if (expr == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create(.not, temp, expr, null, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .negate => {
            const expr = try lower_AST(cfg, ast.negate.expr, return_label, break_label, continue_label, error_label, errors, allocator);
            if (expr == null) {
                return null;
            }
            var temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create(if (try temp.get_type().can_represent_float(allocator)) .negate_float else .negate_int, temp, expr, null, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .dereference => {
            const expr = try lower_AST(cfg, ast.dereference.expr, return_label, break_label, continue_label, error_label, errors, allocator);
            if (expr == null) {
                return null;
            }
            const _type = try ast.typeof(allocator);
            const size = (try _type.expand_type(allocator)).sizeof();
            const temp = try lval_.L_Value.create_dereference(expr.?, size, _type, try _type.expand_type(allocator), allocator);
            return temp;
        },
        ._try => {
            var expr = (try lower_AST(cfg, ast._try.expr, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

            const end = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const err = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

            var expanded_expr_type = try expr.get_type().expand_type(allocator);
            // Trying error sum, runtime check if error, branch to error path
            const condition = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            cfg.appendInstruction(try ir_.IR.createGetTag(condition, expr, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
            cfg.appendInstruction(try ir_.IR.createBranch(condition, err, ast.getToken().span, allocator));

            // Unwrap the `.ok` value
            const retval_lval = try lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
            cfg.appendInstruction(try ir_.IR.create_simple_copy(retval_lval, expr, ast.getToken().span, allocator));
            cfg.appendInstruction(try ir_.IR.createJump(error_label, ast.getToken().span, allocator));

            // Else, store the error in retval, return through error
            cfg.appendInstruction(err);

            const ok_lval = try lval_.L_Value.create_select(expr, 0, 0, expanded_expr_type.get_ok_type().sizeof(), expanded_expr_type.get_ok_type(), try expanded_expr_type.get_ok_type().expand_type(allocator), null, allocator);
            cfg.appendInstruction(try ir_.IR.createJump(end, ast.getToken().span, allocator));
            cfg.appendInstruction(end);

            return ok_lval;
        },
        .discard => {
            var expr = try lower_AST(cfg, ast.discard.expr, return_label, break_label, continue_label, error_label, errors, allocator);
            if (expr == null) {
                return null;
            }
            expr.?.extract_symbver().symbol.discard_span = ast.getToken().span;
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.createDiscard(expr.?, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },

        // Binary operators
        .assign => {
            const rhs = try lower_AST(cfg, ast.assign.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (rhs == null) {
                return null;
            }
            // If product, recursively generate a series of assignments
            // Else, create a *single* copy IR with an L_Value tree
            return try generate_assign(cfg, ast.assign.lhs, rhs.?, return_label, break_label, continue_label, error_label, errors, allocator);
        },
        ._or => {
            // Create the result symbol and IR
            const symbol = try cfg.createTempSymbol(try ast.typeof(allocator), allocator);
            const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // Labels used
            const else_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

            // Test lhs, branch
            const lhs = (try lower_AST(cfg, ast._or.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
            const branch = try ir_.IR.createBranch(lhs, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // lhs was true, store `true` in temp
            const load_true_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            const load_true = try ir_.IR.createInt(load_true_lval, 1, ast.getToken().span, allocator);
            cfg.appendInstruction(load_true);
            cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));

            // lhs was false, recurse to rhs, store in temp
            cfg.appendInstruction(else_label);
            const rhs = try lower_AST(cfg, ast._or.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (rhs == null) {
                return null;
            }
            const copy_right_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            const copy_right = try ir_.IR.create_simple_copy(copy_right_lval, rhs.?, ast.getToken().span, allocator);
            cfg.appendInstruction(copy_right);
            cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
            cfg.appendInstruction(end_label);
            return temp;
        },
        ._and => {
            // Create the result symbol and IR
            const symbol = try cfg.createTempSymbol(try ast.typeof(allocator), allocator);
            const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // Labels used
            const else_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

            // Test lhs, branch
            const lhs = (try lower_AST(cfg, ast._and.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
            const branch = try ir_.IR.createBranch(lhs, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // lhs was true, recurse to rhs, store in temp
            const rhs = try lower_AST(cfg, ast._and.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (rhs == null) {
                return null;
            }
            const copy_right_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            const copy_right = try ir_.IR.create_simple_copy(copy_right_lval, rhs.?, ast.getToken().span, allocator);
            cfg.appendInstruction(copy_right);
            cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));

            // lhs was false, store `false` in temp
            cfg.appendInstruction(else_label);
            const load_false_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            const load_false = try ir_.IR.createInt(load_false_lval, 0, ast.getToken().span, allocator);
            cfg.appendInstruction(load_false);
            cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
            cfg.appendInstruction(end_label);
            return temp;
        },
        .add => {
            const lhs = try lower_AST(cfg, ast.add.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.add.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create_int_float_kind(.add_int, .add_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .sub => {
            const lhs = try lower_AST(cfg, ast.sub.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.sub.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create_int_float_kind(.sub_int, .sub_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .mult => {
            const lhs = try lower_AST(cfg, ast.mult.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.mult.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create_int_float_kind(.mult_int, .mult_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .div => {
            const lhs = try lower_AST(cfg, ast.div.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.div.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create_int_float_kind(.div_int, .div_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .mod => {
            const lhs = try lower_AST(cfg, ast.mod.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.mod.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create(.mod, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .equal => {
            const lhs = try lower_AST(cfg, ast.equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            // Labels used
            const fail_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

            try generate_tuple_equality(cfg, lhs.?, rhs.?, fail_label, errors, allocator);

            cfg.appendInstruction(try ir_.IR.createInt(temp, 1, ast.getToken().span, allocator));
            cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
            cfg.appendInstruction(fail_label);
            cfg.appendInstruction(try ir_.IR.createInt(temp, 0, ast.getToken().span, allocator));
            cfg.appendInstruction(end_label);

            return temp;
        },
        .not_equal => {
            const lhs = try lower_AST(cfg, ast.not_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.not_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const lhs_type = try (try ast.not_equal.lhs.typeof(allocator)).expand_type(allocator);
            if (lhs_type.* == .sum) {
                const lhs_tag = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                const rhs_tag = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                cfg.appendInstruction(try ir_.IR.createGetTag(lhs_tag, lhs.?, ast.getToken().span, allocator));
                cfg.appendInstruction(try ir_.IR.createGetTag(rhs_tag, rhs.?, ast.getToken().span, allocator));
                cfg.appendInstruction(try ir_.IR.create(.not_equal, temp, lhs_tag, rhs_tag, ast.getToken().span, allocator));
            } else {
                cfg.appendInstruction(try ir_.IR.create(.not_equal, temp, lhs, rhs, ast.getToken().span, allocator));
            }
            return temp;
        },
        .greater => {
            const lhs = try lower_AST(cfg, ast.greater.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.greater.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create_int_float_kind(.greater_int, .greater_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .lesser => {
            const lhs = try lower_AST(cfg, ast.lesser.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.lesser.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create_int_float_kind(.lesser_int, .lesser_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .greater_equal => {
            const lhs = try lower_AST(cfg, ast.greater_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.greater_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create_int_float_kind(.greater_equal_int, .greater_equal_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        .lesser_equal => {
            const lhs = try lower_AST(cfg, ast.lesser_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            const rhs = try lower_AST(cfg, ast.lesser_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
            if (lhs == null or rhs == null) {
                return null;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.create_int_float_kind(.lesser_equal_int, .lesser_equal_float, temp, lhs, rhs, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },
        ._catch => {
            // Create the result symbol.
            // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
            const symbol = try cfg.createTempSymbol(try ast.typeof(allocator), allocator);
            const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator); // Not actually assigned directly, just so that optimizations can capture the version

            const lhs = (try lower_AST(cfg, ast._catch.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

            // Labels used
            const else_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

            // Test if lhs tag is 0 (ok)
            const condition = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            cfg.appendInstruction(try ir_.IR.createGetTag(condition, lhs, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
            cfg.appendInstruction(try ir_.IR.createBranch(condition, else_label, ast.getToken().span, allocator));

            // tag was an error, store rhs in temp
            const rhs = (try lower_AST(cfg, ast._catch.rhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
            const rhs_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(try ir_.IR.create_simple_copy(rhs_lval, rhs, ast.getToken().span, allocator));

            cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
            cfg.appendInstruction(else_label);

            // tag was `.ok`, store lhs.some in temp
            const _type = try ast.typeof(allocator);
            const size = (try _type.expand_type(allocator)).sizeof();
            const val = try lval_.L_Value.create_select(lhs, 0, 0, size, _type, try _type.expand_type(allocator), null, allocator);
            const some_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(try ir_.IR.create_simple_copy(some_lval, val, ast.getToken().span, allocator));

            cfg.appendInstruction(end_label);
            return temp;
        },
        ._orelse => {
            // Create the result symbol.
            // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
            const symbol = try cfg.createTempSymbol(try ast.typeof(allocator), allocator);
            const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator); // Not actually assigned directly, just so that optimizations can capture the version

            var lhs = (try lower_AST(cfg, ast._orelse.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

            // Labels used
            const else_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

            // Test if lhs tag is 1 (some)
            const condition = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const load_tag = try ir_.IR.createGetTag(condition, lhs, ast.getToken().span, allocator); // Assumes `some` tag is nonzero, `none` tag is zero
            cfg.appendInstruction(load_tag);

            const branch = try ir_.IR.createBranch(condition, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // tag was `.some`, store lhs.some in temp
            const _type = try ast.typeof(allocator);
            const size = (try _type.expand_type(allocator)).sizeof();
            const offset = try (try lhs.get_type().expand_type(allocator)).sum.get_offset(1, allocator);
            const val = try lval_.L_Value.create_select(lhs, 1, offset, size, _type, try _type.expand_type(allocator), null, allocator);
            const some_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(try ir_.IR.create_simple_copy(some_lval, val, ast.getToken().span, allocator));
            cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));

            cfg.appendInstruction(else_label);

            // tag was `.none`, store rhs in temp
            const rhs = (try lower_AST(cfg, ast._orelse.rhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

            const rhs_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
            cfg.appendInstruction(try ir_.IR.create_simple_copy(rhs_lval, rhs, ast.getToken().span, allocator));

            cfg.appendInstruction(end_label);
            return temp;
        },
        .call => {
            const lhs = (try lower_AST(cfg, ast.call.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
            var temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            temp.extract_symbver().symbol.span = ast.getToken().span;

            var ir = try ir_.IR.createCall(temp, lhs, ast.getToken().span, allocator);
            for (ast.call.args.items) |term| {
                try ir.data.lval_list.append((try lower_AST(cfg, term, return_label, break_label, continue_label, error_label, errors, allocator)) orelse continue);
            }
            cfg.appendInstruction(try ir_.IR.createStackPush(ast.getToken().span, allocator));
            cfg.appendInstruction(ir);
            cfg.appendInstruction(try ir_.IR.createStackPop(ast.getToken().span, allocator));
            return temp;
        },
        .function => {
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            cfg.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
            return temp;
        },
        .index => {
            const _type = try ast.typeof(allocator);
            const size = (try _type.expand_type(allocator)).sizeof();

            // Get the type of the index ast. This will determine if this is an array index or a slice index
            const ast_expanded_type = try (try ast.index.lhs.typeof(allocator)).expand_type(allocator);

            // Flatten index expr
            const rhs = try lower_AST(cfg, ast.index.rhs, return_label, break_label, continue_label, error_label, errors, allocator);

            // Recursively get index's ast L_Value node
            const pre_ast_lval = try lower_AST(cfg, ast.index.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            var ast_lval = pre_ast_lval;

            if (ast_expanded_type.product.was_slice) {
                // Indexing a slice; index_val := lhs._0^[rhs]
                const addr_type = ast_expanded_type.product.terms.items[0];
                const addr_size = (try _type.expand_type(allocator)).sizeof();
                ast_lval = try lval_.L_Value.create_select(ast_lval.?, 0, 0, addr_size, addr_type, try _type.expand_type(allocator), null, allocator);
                ast_lval = try lval_.L_Value.create_dereference(ast_lval.?, addr_size, addr_type, try _type.expand_type(allocator), allocator);
            }

            // Do bounds-check
            var length: *lval_.L_Value = undefined;
            if (ast_expanded_type.* == .product and ast_expanded_type.product.was_slice) {
                const offset = try ast_expanded_type.product.get_offset(1, allocator);
                length = try lval_.L_Value.create_select(pre_ast_lval.?, 1, offset, 8, primitives_.int64_type, primitives_.int64_type, null, allocator);
            } else if (ast_expanded_type.* == .product and !ast_expanded_type.product.was_slice) {
                length = try cfg.create_temp_lvalue(primitives_.int_type, allocator);
                const ir = try ir_.IR.createInt(length, ast_expanded_type.product.terms.items.len, ast.getToken().span, allocator);
                cfg.appendInstruction(ir);
            } else {
                unreachable;
            }

            // Surround with L_Value node
            return try lval_.L_Value.create_index(ast_lval.?, rhs.?, length, size, _type, try _type.expand_type(allocator), allocator);
        },
        .select => {
            // Recursively get select's ast L_Value node
            const ast_lval = try lower_AST(cfg, ast.select.lhs, return_label, break_label, continue_label, error_label, errors, allocator);

            // Get the offset into the struct that this select does
            var lhs_expanded_type = try (try ast.select.lhs.typeof(allocator)).expand_type(allocator);
            const offset = if (lhs_expanded_type.* == .product)
                try lhs_expanded_type.product.get_offset(ast.select.pos.?, allocator)
            else
                try lhs_expanded_type.sum.get_offset(ast.select.pos.?, allocator);

            var tag: ?*lval_.L_Value = null;
            if (lhs_expanded_type.* == .sum) {
                // Check that the sum value has the proper tag before a selection
                tag = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                cfg.appendInstruction(try ir_.IR.createGetTag(tag.?, ast_lval.?, ast.getToken().span, allocator));
            }

            // Surround with L_Value node
            const _type = try ast.typeof(allocator);
            const expanded_type = try _type.expand_type(allocator);
            return try lval_.L_Value.create_select(ast_lval.?, ast.select.pos.?, offset, expanded_type.sizeof(), _type, expanded_type, tag, allocator);
        },
        .product => {
            if (try (try ast.product.terms.items[0].typeof(allocator)).typesMatch(primitives_.type_type)) {
                const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
                cfg.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            } else {
                const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
                var ir = try ir_.IR.createLoadStruct(temp, ast.getToken().span, allocator);
                for (ast.product.terms.items) |term| {
                    try ir.data.lval_list.append((try lower_AST(cfg, term, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null);
                }
                cfg.appendInstruction(ir);
                return temp;
            }
        },
        .sum => {
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            cfg.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
            return temp;
        },

        // Fancy Operators
        .addrOf => {
            if (try (try ast.typeof(allocator)).typesMatch(primitives_.type_type)) {
                const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
                cfg.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            } else {
                const expr = try lower_AST(cfg, ast.addrOf.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

                const ir = try ir_.IR.create(.addrOf, temp, expr, null, ast.getToken().span, allocator);
                cfg.appendInstruction(ir);
                return temp;
            }
        },
        .subSlice => {
            const arr = (try lower_AST(cfg, ast.subSlice.super, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
            const lower = (try lower_AST(cfg, ast.subSlice.lower.?, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
            const upper = (try lower_AST(cfg, ast.subSlice.upper.?, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

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
                const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
                const compare = try cfg.create_temp_lvalue(primitives_.bool_type, allocator);
                const ir = try ir_.IR.create(.greater_int, compare, lower, upper, ast.getToken().span, allocator);
                cfg.appendInstruction(ir);
                const branch = try ir_.IR.createBranch(compare, end_label, ast.getToken().span, allocator);
                cfg.appendInstruction(branch);
                cfg.appendInstruction(try ir_.IR.createStackPush(ast.getToken().span, allocator));
                cfg.appendInstruction(try ir_.IR.createPanic("subslice lower bound is greater than upper bound", ast.getToken().span, allocator));
                cfg.appendInstruction(end_label);
            }

            const new_size = try cfg.create_temp_lvalue(primitives_.int_type, allocator);
            const new_size_ir = try ir_.IR.create(.sub_int, new_size, upper, lower, ast.getToken().span, allocator);
            cfg.appendInstruction(new_size_ir);

            const slice_type = try ast.typeof(allocator);
            const data_type = slice_type.product.terms.items[0];
            const size = (try data_type.expand_type(allocator)).sizeof();
            const data_ptr = try lval_.L_Value.create_select(arr, 0, 0, size, data_type, try data_type.expand_type(allocator), null, allocator);

            const new_data_ptr = try cfg.create_temp_lvalue(data_type, allocator);
            const new_data_ptr_ir = try ir_.IR.create(.add_int, new_data_ptr, data_ptr, lower, ast.getToken().span, allocator);
            cfg.appendInstruction(new_data_ptr_ir);

            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            var load_struct = try ir_.IR.createLoadStruct(temp, ast.getToken().span, allocator);
            try load_struct.data.lval_list.append(new_data_ptr);
            try load_struct.data.lval_list.append(new_size);
            cfg.appendInstruction(load_struct);
            return temp;
        },
        .annotation => {
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);
            cfg.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
            return temp;
        },
        .inferredMember => {
            var init: ?*lval_.L_Value = null;
            const pos: i128 = ast.inferredMember.pos.?;
            const proper_term: *ast_.AST = (try ast.typeof(allocator)).sum.terms.items[@as(usize, @intCast(pos))];
            if (ast.inferredMember.init) |_init| {
                init = try lower_AST(cfg, _init, return_label, break_label, continue_label, error_label, errors, allocator);
            } else if (proper_term.annotation.init == null and proper_term.annotation.type.* != .unit_type) {
                errors.addError(errs.Error{ .basic = .{ .span = ast.getToken().span, .msg = "no value provided, and no default value available" } });
                return error.typeError;
            }
            const temp = try cfg.create_temp_lvalue(try ast.typeof(allocator), allocator);

            const ir = try ir_.IR.createUnion(temp, init, ast.inferredMember.pos.?, ast.getToken().span, allocator);
            cfg.appendInstruction(ir);
            return temp;
        },

        // Control-flow expressions
        ._if => {
            // Create the result symbol and IR
            const symbol = try cfg.createTempSymbol(try ast.typeof(allocator), allocator);
            const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // If there's a let, then do it, dumby!
            if (ast._if.let) |let| {
                _ = try lower_AST(cfg, let, return_label, break_label, continue_label, error_label, errors, allocator);
            }

            // Labels used
            const else_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

            // Test lhs, branch
            const condition = (try lower_AST(cfg, ast._if.condition, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
            const branch = try ir_.IR.createBranch(condition, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // lhs was true, recurse to rhs, store in temp
            if (try lower_AST(cfg, ast._if.bodyBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |block_lval| {
                const block_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                var block_copy: *ir_.IR = undefined;
                if (ast._if.elseBlock == null) {
                    // no else block => if is optional, coerce up to `.some <- block`
                    block_copy = try ir_.IR.createUnion(block_copy_lval, block_lval, 1, ast.getToken().span, allocator);
                } else {
                    // regular if-else => copy block
                    block_copy = try ir_.IR.create_simple_copy(block_copy_lval, block_lval, ast.getToken().span, allocator);
                }
                cfg.appendInstruction(block_copy);
            }
            cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));

            // lhs was false, store `false` in temp
            cfg.appendInstruction(else_label);
            if (ast._if.elseBlock) |elseBlock| {
                if (try lower_AST(cfg, elseBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |else_lval| {
                    const else_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    const else_copy = try ir_.IR.create_simple_copy(else_copy_lval, else_lval, ast.getToken().span, allocator);
                    cfg.appendInstruction(else_copy);
                }
                cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
            } else {
                // no else block => if is optional, store null
                const else_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const else_copy = try ir_.IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                cfg.appendInstruction(else_copy);
            }
            cfg.appendInstruction(end_label);
            return temp;
        },
        .match => {
            // Create the result symbol and IR
            const symbol_type = if (ast.match.has_else)
                // Match has an else, type of the mappings should be the type of the match
                try ast.typeof(allocator)
            else
                // Match has no else, type of the mappings should be wrapped in an optional type
                try ast_.AST.create_optional_type(try ast.typeof(allocator), allocator);
            const symbol = try cfg.createTempSymbol(symbol_type, allocator);
            const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // Exit label of match
            const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            // Label jumped to if all tests fail and no `else` mapping
            const none_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            // List of labels to branch to on an unsuccessful test (ie "next pattern")
            var lhs_label_list = std.ArrayList(*ir_.IR).init(allocator);
            defer lhs_label_list.deinit();
            // List of labels to branch to on a successful test (ie "code for the mapping")
            var rhs_label_list = std.ArrayList(*ir_.IR).init(allocator);
            defer rhs_label_list.deinit();
            for (ast.match.mappings.items) |_| {
                try lhs_label_list.append(try ir_.IR.createLabel(cfg, ast.getToken().span, allocator));
                try rhs_label_list.append(try ir_.IR.createLabel(cfg, ast.getToken().span, allocator));
            }
            std.debug.assert(lhs_label_list.items.len == ast.match.mappings.items.len);

            // If there's a let, then do it, dumby!
            if (ast.match.let) |let| {
                _ = try lower_AST(cfg, let, return_label, break_label, continue_label, error_label, errors, allocator);
            }

            const expr = try lower_AST(cfg, ast.match.expr, return_label, break_label, continue_label, error_label, errors, allocator);
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
                    try generate_match_pattern_check(cfg, lhs, expr.?, next_label, return_label, break_label, continue_label, error_label, errors, allocator);
                }
                cfg.appendInstruction(try ir_.IR.createJump(rhs_label_list.items[label_index], mapping.getToken().span, allocator));
                label_index += 1;
            }

            if (!ast.match.has_else) { // All tests failed, no `else` mapping. Store `.none` as result
                cfg.appendInstruction(none_label);
                const else_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const else_copy = try ir_.IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                cfg.appendInstruction(else_copy);
                cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
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
                if (try lower_AST(cfg, mapping.mapping.rhs.?, return_label, break_label, continue_label, error_label, errors, allocator)) |rhs_lval| {
                    const rhs_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    var rhs_copy: *ir_.IR = undefined;
                    if (ast.match.has_else) {
                        rhs_copy = try ir_.IR.create_simple_copy(rhs_copy_lval, rhs_lval, ast.getToken().span, allocator);
                    } else {
                        rhs_copy = try ir_.IR.createUnion(rhs_copy_lval, rhs_lval, 1, ast.getToken().span, allocator);
                    }
                    cfg.appendInstruction(rhs_copy);
                }
                cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                label_index += 1;
            }
            cfg.appendInstruction(end_label);

            return temp;
        },
        ._while => {
            // Create the result symbol and IR
            const symbol = try cfg.createTempSymbol(try ast.typeof(allocator), allocator);
            const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

            // Labels used
            const cond_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const current_continue_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const else_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);
            const end_label = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

            // If there's a let, then do it, dumby!
            if (ast._while.let) |let| {
                _ = try lower_AST(cfg, let, return_label, break_label, continue_label, error_label, errors, allocator);
            }

            // Test condition, branch to either body or else block
            cfg.appendInstruction(cond_label);
            const condition = (try lower_AST(cfg, ast._while.condition, return_label, end_label, current_continue_label, error_label, errors, allocator)) orelse return null;
            const branch = try ir_.IR.createBranch(condition, else_label, ast.getToken().span, allocator);
            cfg.appendInstruction(branch);

            // Body block
            if (try lower_AST(cfg, ast._while.bodyBlock, return_label, end_label, current_continue_label, error_label, errors, allocator)) |block_lval| {
                const block_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                var block_copy: *ir_.IR = undefined;
                if (ast._while.elseBlock == null) {
                    // no else block => while is optional, coerce up to `.some <- block`
                    block_copy = try ir_.IR.createUnion(block_copy_lval, block_lval, 1, ast.getToken().span, allocator);
                } else {
                    // regular while-else => copy block
                    block_copy = try ir_.IR.create_simple_copy(block_copy_lval, block_lval, ast.getToken().span, allocator);
                }
                cfg.appendInstruction(block_copy);
            }

            // Post-condition, jump to condition test
            cfg.appendInstruction(current_continue_label);
            if (ast._while.post) |post| {
                _ = try lower_AST(cfg, post, return_label, end_label, continue_label, error_label, errors, allocator);
            }
            cfg.appendInstruction(try ir_.IR.createJump(cond_label, ast.getToken().span, allocator));

            // Else block
            cfg.appendInstruction(else_label);
            if (ast._while.elseBlock) |elseBlock| {
                if (try lower_AST(cfg, elseBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |else_lval| {
                    const elseCopy = try ir_.IR.create_simple_copy(temp, else_lval, ast.getToken().span, allocator);
                    cfg.appendInstruction(elseCopy);
                }
                cfg.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
            } else {
                // no else block => while is optional, store null
                const else_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const else_copy = try ir_.IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
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
                    try continue_labels.append(try ir_.IR.createLabel(cfg, ast.getToken().span, allocator));
                    try break_labels.append(try ir_.IR.createLabel(cfg, ast.getToken().span, allocator));
                    try return_labels.append(try ir_.IR.createLabel(cfg, ast.getToken().span, allocator));
                }
                for (ast.block.scope.?.errdefers.items) |_| {
                    try error_labels.append(try ir_.IR.createLabel(cfg, ast.getToken().span, allocator));
                }
                const end = try ir_.IR.createLabel(cfg, ast.getToken().span, allocator);

                // These are the labels to go to on each final statement. These are updated to point to different places in the defer chain at the end of this block.
                var current_continue_label = if (continue_label != null) continue_label else end;
                var current_break_label = break_label;
                var current_return_label = return_label;
                var current_error_label = error_label;
                var defer_label_index: usize = 0;
                var errdefer_label_index: usize = 0;

                var temp: ?*lval_.L_Value = null;
                for (ast.block.statements.items) |child| {
                    temp = try lower_AST(cfg, child, current_return_label, current_break_label, current_continue_label, current_error_label, errors, allocator);
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
                    temp = try lower_AST(cfg, final, current_return_label, current_break_label, current_continue_label, current_error_label, errors, allocator);
                } else if (temp) |_temp| {
                    const expanded_temp_type = try _temp.get_type().expand_type(allocator);
                    if (current_error_label != null and expanded_temp_type.* == .sum and expanded_temp_type.sum.was_error) {
                        // Returning error sum, runtime check if error, branch to error path
                        const condition = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                        cfg.appendInstruction(try ir_.IR.createGetTag(condition, _temp, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                        const not_condition = try cfg.create_temp_lvalue(primitives_.bool_type, allocator);
                        cfg.appendInstruction(try ir_.IR.create(.not, not_condition, condition, null, ast.getToken().span, allocator));
                        cfg.appendInstruction(try ir_.IR.createBranch(not_condition, current_error_label, ast.getToken().span, allocator));
                    }
                }

                try generateDefers(cfg, &ast.block.scope.?.defers, &continue_labels, errors, allocator);
                cfg.appendInstruction(try ir_.IR.createJump(end, ast.getToken().span, allocator));

                try generateDefers(cfg, &ast.block.scope.?.defers, &break_labels, errors, allocator);
                cfg.appendInstruction(try ir_.IR.createJump(break_label, ast.getToken().span, allocator));

                try generateDefers(cfg, &ast.block.scope.?.defers, &return_labels, errors, allocator);
                cfg.appendInstruction(try ir_.IR.createJump(return_label, ast.getToken().span, allocator));

                try generateDefers(cfg, &ast.block.scope.?.errdefers, &error_labels, errors, allocator);
                cfg.appendInstruction(try ir_.IR.createJump(error_label, ast.getToken().span, allocator));

                cfg.appendInstruction(end);

                return temp;
            }
        },

        // Control-flow statements
        .decl => {
            const def: ?*lval_.L_Value = try lower_AST(cfg, ast.decl.init, return_label, break_label, continue_label, error_label, errors, allocator);
            if (def == null) {
                return null;
            }
            try generate_pattern(cfg, ast.decl.pattern, try ast.decl.type.expand_type(allocator), def.?, errors, allocator);
            return null;
        },
        .fnDecl => {
            _ = try ast.fnDecl.symbol.?.get_cfg(cfg, cfg.interned_strings, errors, allocator);
            const temp = try cfg.create_temp_lvalue(ast.fnDecl.symbol.?._type, allocator);
            var ir = try ir_.IR.create(.loadSymbol, temp, null, null, ast.getToken().span, allocator);
            ir.data = ir_.Data{ .symbol = ast.fnDecl.symbol.? };
            cfg.appendInstruction(ir);
            return temp;
        },
        ._errdefer, ._defer => {
            return null;
        },
        ._continue => {
            cfg.appendInstruction(try ir_.IR.createJump(continue_label, ast.getToken().span, allocator));
            return null;
        },
        ._unreachable => {
            cfg.appendInstruction(try ir_.IR.createStackPush(ast.getToken().span, allocator));
            cfg.appendInstruction(try ir_.IR.createPanic("reached unreachable code", ast.getToken().span, allocator));
            return null;
        },
        ._break => {
            cfg.appendInstruction(try ir_.IR.createJump(break_label, ast.getToken().span, allocator));
            return null;
        },
        ._return => {
            if (ast._return.expr) |expr| {
                // Copy expr to retval
                const retval = (try lower_AST(cfg, expr, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const retval_lval = try lval_.L_Value.create_unversioned_symbver(cfg.return_symbol, allocator);
                const retval_copy = try ir_.IR.create_simple_copy(retval_lval, retval, ast.getToken().span, allocator);
                cfg.appendInstruction(retval_copy);

                const expanded_expr_type = try (try expr.typeof(allocator)).expand_type(allocator);
                if (expanded_expr_type.* == .sum and expanded_expr_type.sum.was_error) {
                    // Returning error sum, runtime check if error, branch to error path
                    const condition = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
                    cfg.appendInstruction(try ir_.IR.createGetTag(condition, retval, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                    const not_condition = try cfg.create_temp_lvalue(primitives_.bool_type, allocator);
                    cfg.appendInstruction(try ir_.IR.create(.not, not_condition, condition, null, ast.getToken().span, allocator));
                    cfg.appendInstruction(try ir_.IR.createBranch(not_condition, error_label, ast.getToken().span, allocator));
                }
                cfg.appendInstruction(try ir_.IR.createJump(return_label, ast.getToken().span, allocator));
            } else {
                // Jump to return_label
                cfg.appendInstruction(try ir_.IR.createJump(return_label, ast.getToken().span, allocator));
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
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!void {
    const new_lhs = lhs; // try L_Value.create_unversioned_symbver(lhs.symbol, lhs.symbol._type.?, allocator);
    const new_rhs = rhs; // try L_Value.create_unversioned_symbver(rhs.symbol, rhs.symbol._type.?, allocator);
    const temp = try cfg.create_temp_lvalue(primitives_.bool_type, allocator);
    var lhs_type = try lhs.get_type().expand_type(allocator);
    if (lhs_type.* == .product) {
        for (0..lhs_type.product.terms.items.len) |i| {
            const _type = lhs_type.product.terms.items[i];
            const size = (try _type.expand_type(allocator)).sizeof();
            const lhs_select = try lval_.L_Value.create_select(new_lhs, i, try lhs_type.product.get_offset(i, allocator), size, _type, try _type.expand_type(allocator), null, allocator);
            const rhs_select = try lval_.L_Value.create_select(new_rhs, i, try lhs_type.product.get_offset(i, allocator), size, _type, try _type.expand_type(allocator), null, allocator);
            try generate_tuple_equality(cfg, lhs_select, rhs_select, fail_label, errors, allocator);
        }
    } else if (lhs_type.* == .sum) {
        const lhs_tag = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
        const rhs_tag = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
        cfg.appendInstruction(try ir_.IR.createGetTag(lhs_tag, new_lhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(try ir_.IR.createGetTag(rhs_tag, new_rhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(try ir_.IR.create(.equal, temp, lhs_tag, rhs_tag, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(try ir_.IR.createBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
    } else {
        cfg.appendInstruction(try ir_.IR.create(.equal, temp, new_lhs, rhs, lhs.extract_symbver().symbol.span, allocator));
        cfg.appendInstruction(try ir_.IR.createBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
    }
}

fn generate_assign(
    cfg: *cfg_.CFG, // Current control-flow-graph
    lhs: *ast_.AST, // AST node for the LHS of the `=`
    rhs: *lval_.L_Value, // L_Value which holds the value to assign
    return_label: ?*ir_.IR,
    break_label: ?*ir_.IR,
    continue_label: ?*ir_.IR,
    error_label: ?*ir_.IR,
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!?*lval_.L_Value // If assign is to a single symbver, returns the symbver
{
    if (lhs.* == .product) {
        // Recursively call `generate_assign` for each term in the product.
        // product-assigns may be nested, for example:
        //     ((x, y), (a, b)) = get_tuple()
        // So it's important that this is recursive
        var lhs_expanded_type = try (try lhs.typeof(allocator)).expand_type(allocator);
        for (lhs.product.terms.items, 0..) |term, i| {
            const product_lhs = try lower_AST(cfg, term, return_label, break_label, continue_label, error_label, errors, allocator);
            if (product_lhs == null) {
                continue;
            }
            const _type = rhs.get_type().product.terms.items[i];
            const size = (try _type.expand_type(allocator)).sizeof();
            const select = try lval_.L_Value.create_select(rhs, i, try lhs_expanded_type.product.get_offset(i, allocator), size, _type, try _type.expand_type(allocator), null, allocator);
            _ = try generate_assign(cfg, term, select, return_label, break_label, continue_label, error_label, errors, allocator);
        }
        return null;
    } else {
        // Get L_Value tree, create a `copy` IR of L_Value tree and rhs
        const lval = try lower_AST(cfg, lhs, return_label, break_label, continue_label, error_label, errors, allocator);
        var ir = try ir_.IR.create(.copy, null, rhs, null, lhs.getToken().span, allocator);
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
            const symbver = try lval_.L_Value.create_unversioned_symbver(pattern.symbol.symbol, allocator);
            const ir = try ir_.IR.create_simple_copy(symbver, def, pattern.getToken().span, allocator);
            cfg.appendInstruction(ir);
        }
    } else if (pattern.* == .product) {
        for (pattern.product.terms.items, 0..) |term, i| {
            const subscript_type = _type.product.terms.items[i];
            const size = (try subscript_type.expand_type(allocator)).sizeof();
            const offset = try _type.product.get_offset(i, allocator);
            const lval = try lval_.L_Value.create_select(def, i, offset, size, subscript_type, try subscript_type.expand_type(allocator), null, allocator);
            try generate_pattern(cfg, term, subscript_type, lval, errors, allocator);
        }
    } else if (pattern.* == .inject) {
        const lhs_type = try pattern.inject.lhs.typeof(allocator);
        const domain = try validate_.domainof(pattern, lhs_type, errors, allocator);
        const size = (try domain.expand_type(allocator)).sizeof();
        const lval = try lval_.L_Value.create_select(def, pattern.inject.lhs.inferredMember.pos.?, 0, size, domain, try domain.expand_type(allocator), null, allocator);
        try generate_pattern(cfg, pattern.inject.rhs, domain, lval, errors, allocator);
    }
}

/// Generates the code which checks if the pattern matches the match expression
fn generate_match_pattern_check(
    cfg: *cfg_.CFG,
    pattern: ?*ast_.AST,
    expr: *lval_.L_Value,
    next_pattern: *ir_.IR,
    return_label: ?*ir_.IR,
    break_label: ?*ir_.IR,
    continue_label: ?*ir_.IR,
    error_label: ?*ir_.IR,
    errors: *errs.Errors,
    allocator: std.mem.Allocator,
) FlattenASTError!void {
    if (pattern == null) {
        // Implies `else` branch, infallible.
        return;
    }
    const new_expr = expr; // try L_Value.create_unversioned_symbver(expr.symbol, expr.type, allocator);
    switch (pattern.?.*) {
        .int,
        .float,
        ._true,
        ._false,
        .char,
        .string,
        .block,
        => {
            const value = try lower_AST(cfg, pattern.?, return_label, break_label, continue_label, error_label, errors, allocator);
            const condition = try cfg.create_temp_lvalue(primitives_.bool_type, allocator);
            const condition_ir = try ir_.IR.create(.equal, condition, new_expr, value.?, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(condition_ir);
            const branch = try ir_.IR.createBranch(condition, next_pattern, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(branch);
        },
        .symbol => {
            // Infallible check, do not branch to next pattern
        },
        .product => {
            for (pattern.?.product.terms.items, 0..) |term, i| {
                const subscript_type = new_expr.get_type().product.terms.items[i];
                const size = (try subscript_type.expand_type(allocator)).sizeof();
                const pattern_type = try (try pattern.?.typeof(allocator)).expand_type(allocator);
                const offset = try pattern_type.product.get_offset(i, allocator);
                const lval = try lval_.L_Value.create_select(new_expr, i, offset, size, subscript_type, try subscript_type.expand_type(allocator), null, allocator);
                try generate_match_pattern_check(cfg, term, lval, next_pattern, return_label, break_label, continue_label, error_label, errors, allocator);
            }
        },
        .select => {
            // Get tag of pattern
            const sel = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const sel_ir = try ir_.IR.createInt(sel, pattern.?.select.pos.?, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(sel_ir);

            // Get tag of expr
            const tag = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const tag_ir = try ir_.IR.createGetTag(tag, expr, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(tag_ir);

            // Compare them, jump to next pattern if they are not equal
            const neql = try cfg.create_temp_lvalue(primitives_.bool_type, allocator);
            const neql_ir = try ir_.IR.create(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(neql_ir);
            const branch = try ir_.IR.createBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(branch);
        },
        .inferredMember => {
            // Get tag of pattern
            const sel = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const sel_ir = try ir_.IR.createInt(sel, pattern.?.inferredMember.pos.?, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(sel_ir);

            // Get tag of expr
            const tag = try cfg.create_temp_lvalue(primitives_.word64_type, allocator);
            const tag_ir = try ir_.IR.createGetTag(tag, expr, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(tag_ir);

            // Compare them, jump to next pattern if they are not equal
            const neql = try cfg.create_temp_lvalue(primitives_.bool_type, allocator);
            const neql_ir = try ir_.IR.create(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(neql_ir);
            const branch = try ir_.IR.createBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
            cfg.appendInstruction(branch);
        },
        .inject => {
            try generate_match_pattern_check(cfg, pattern.?.inject.lhs, expr, next_pattern, return_label, break_label, continue_label, error_label, errors, allocator);
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
        _ = try lower_AST(cfg, defers.items[i - 1], null, null, null, null, errors, allocator);
    }
}
