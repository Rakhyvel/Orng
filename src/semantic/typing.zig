//! This file contains the semantic validation logic for types.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const args_ = @import("args.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const errs_ = @import("../util/errors.zig");
const Interpreter_Context = @import("../interpretation/interpreter.zig");
const module_ = @import("../hierarchy/module.zig");
const poison_ = @import("../ast/poison.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const Span = @import("../util/span.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Scope = @import("../symbol/scope.zig");
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const validate_AST = @import("ast_validate.zig").validate_AST;

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

pub fn type_check(span: Span, got: *Type_AST, expected: ?*Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (expected != null and !got.types_match(expected.?)) {
        return throw_unexpected_type(span, expected.?, got, errors);
    }
}

/// Checks that a type is equal to unit, throws an error if it is not.
pub fn middle_statement_check(span: Span, got: *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!prelude_.unit_type.types_match(got) and !got.types_match(prelude_.void_type)) {
        return throw_unexpected_type(span, prelude_.unit_type, got, errors);
    }
}

pub fn type_check_int(
    ast: *ast_.AST,
    expected: ?*Type_AST, // This should NOT be expanded < it is, though...
    errors: *errs_.Errors,
) Validate_Error_Enum!void {
    const expanded_expected = if (expected != null) expected.?.expand_identifier() else null;
    if (expanded_expected != null) { //and !try checked_types_match(prelude_.unit_type, expanded_expected.?, errors)
        const info = prelude_.info_from_ast(expanded_expected.?);
        if (info != null and info.?.bounds != null) {
            if (ast.int.data < info.?.bounds.?.lower or
                ast.int.data > info.?.bounds.?.upper)
            {
                // This error is thrown because the `expanded_expected` is out of bounds of the expected type
                errors.add_error(errs_.Error{ .integer_out_of_bounds = .{
                    .span = ast.token().span,
                    .expected = expected.?,
                    .value = ast.int.data,
                } });
                return error.CompileError;
            }
        } else {
            // This error is thrown because the `expanded_expected` is not an integer primitive type
            return throw_unexpected_type(ast.token().span, expanded_expected.?, prelude_.int_type, errors);
        }
    }
    ast.set_represents(expected orelse prelude_.int_type);
}

pub fn type_check_float(ast: *ast_.AST, expected: ?*Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (expected != null and !expected.?.can_represent_float()) {
        return throw_unexpected_type(ast.token().span, expected.?, prelude_.float_type, errors);
    }
    ast.set_represents(expected orelse prelude_.float_type);
}

pub fn type_check_eq(span: Span, got: *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_eq_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "equalable", .got = got } });
        return error.CompileError;
    }
}

pub fn type_check_ord(span: Span, got: *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_ord_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "orderable", .got = got } });
        return error.CompileError;
    }
}

pub fn type_check_arithmetic(span: Span, got: *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_num_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "arithmetic", .got = got } });
        return error.CompileError;
    }
}

pub fn type_check_integral(span: Span, got: *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_int_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "integer", .got = got } });
        return error.CompileError;
    }
}

pub fn type_check_bits(span: Span, got: *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_bits_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "bits", .got = got } });
        return error.CompileError;
    }
}

pub fn throw_unexpected_type(span: Span, expected: *Type_AST, got: *Type_AST, errors: *errs_.Errors) Validate_Error_Enum {
    errors.add_error(errs_.Error{ .unexpected_type = .{ .span = span, .expected = expected, .got = got } });
    return error.CompileError;
}

pub fn throw_unexpected_void_type(span: Span, errors: *errs_.Errors) Validate_Error_Enum {
    errors.add_error(errs_.Error{ .basic = .{ .span = span, .msg = "comptime cannot be type `Void`" } });
    return error.CompileError;
}

fn throw_not_selectable(_type: *Type_AST, span: Span, errors: *errs_.Errors) Validate_Error_Enum {
    errors.add_error(errs_.Error{ .not_selectable = .{ .span = span, ._type = _type } });
    return error.CompileError;
}

pub fn throw_wrong_from(
    from_name: []const u8,
    operator_name: []const u8,
    got: *Type_AST,
    span: Span,
    errors: *errs_.Errors,
) Validate_Error_Enum {
    errors.add_error(errs_.Error{ .wrong_from = .{
        .span = span,
        .operator = operator_name,
        .from = from_name,
        .got = got,
    } });
    return error.CompileError;
}

/// Validates a closed binary operator. Returns the valid form of the binary operator.
pub fn binary_operator_closed(
    ast: *ast_.AST,
    self_type: *Type_AST,
    expected: ?*Type_AST,
    compiler: *Compiler_Context,
) Validate_Error_Enum!*ast_.AST {
    ast.set_lhs(validate_AST(ast.lhs(), self_type, compiler));
    ast.set_rhs(validate_AST(ast.rhs(), self_type, compiler));
    try poison_.assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
    try type_check(ast.token().span, self_type, expected, &compiler.errors);
    return ast;
}

/// Validates an open binary operator. An operator is `open` if it returns a type different from the
/// ones it acts on.
///
/// Returns the type of the validated operator.
pub fn binary_operator_open(
    ast: *ast_.AST,
    expected: ?*Type_AST,
    compiler: *Compiler_Context,
) Validate_Error_Enum!*Type_AST {
    ast.set_lhs(validate_AST(ast.lhs(), expected, compiler));
    if (ast.lhs().* == .identifier and ast.lhs().symbol().?.refers_to_type()) {
        return error.CompileError;
    }
    const lhs_type = ast.lhs().typeof(compiler.allocator());
    ast.set_rhs(validate_AST(ast.rhs(), lhs_type, compiler));
    try poison_.assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
    return lhs_type;
}

pub fn coalesce_operator(lhs_expanded_type: *Type_AST, ast: *ast_.AST, span: Span, errors: *errs_.Errors) Validate_Error_Enum!void {
    std.debug.assert(ast.* == .@"orelse" or ast.* == .@"catch");
    const expected_sum_from: Type_AST.Sum_From = if (ast.* == .@"orelse") .optional else .@"error";
    if (lhs_expanded_type.* != .enum_type or lhs_expanded_type.enum_type.from != expected_sum_from) {
        errors.add_error(errs_.Error{ .wrong_from = .{
            .span = span,
            .operator = @tagName(ast.*),
            .from = @tagName(expected_sum_from),
            .got = lhs_expanded_type,
        } });
        return error.CompileError;
    }
}

/// Validates just that each argument's type matches its corresponding parameter's type. Assumes arity is valid.
pub fn validate_args_type(
    args: *std.ArrayList(*ast_.AST),
    expected: *Type_AST,
    compiler: *Compiler_Context,
) Validate_Error_Enum!*std.ArrayList(*ast_.AST) {
    const expected_length = if (expected.* == .unit_type) 0 else if (expected.* == .struct_type or expected.* == .tuple_type) expected.children().items.len else 1;

    for (0..expected_length) |i| {
        const param_type = if (expected.* == .struct_type or expected.* == .tuple_type) expected.children().items[i] else expected;
        args.items[i] = validate_AST(args.items[i], param_type, compiler);
    }
    try poison_.assert_none_poisoned(args);
    return args;
}

fn put_many_annot_map(
    asts: *std.ArrayList(*Type_AST),
    new_terms: *std.ArrayList(*Type_AST),
    map: *std.StringArrayHashMap(*Type_AST),
    errors: *errs_.Errors,
) Validate_Error_Enum!void {
    for (asts.items) |term| {
        try args_.put_ast_map(term.annotation.type, term.annotation.pattern.token().data, term.token().span, map, errors);
        new_terms.append(term) catch unreachable;
    }
}

pub fn implicit_dereference(
    ast: *ast_.AST,
    old_lhs_type: *Type_AST,
    compiler: *Compiler_Context,
) Validate_Error_Enum!*Type_AST {
    var lhs_type = old_lhs_type;
    if (lhs_type.* == .addr_of and !lhs_type.addr_of.multiptr) {
        ast.set_lhs(validate_AST(ast_.AST.create_dereference(ast.token(), ast.lhs(), compiler.allocator()), null, compiler));
        lhs_type = ast.lhs().typeof(compiler.allocator()).expand_identifier();
    }
    try poison_.assert_none_poisoned(.{ ast.lhs(), lhs_type });
    return lhs_type;
}

pub fn find_select_pos(_type: *Type_AST, field: []const u8, span: Span, errors: *errs_.Errors) Validate_Error_Enum!usize {
    if (_type.* != .struct_type and _type.* != .enum_type and _type.* != .untagged_sum_type) {
        return throw_not_selectable(_type, span, errors);
    }
    for (_type.children().items, 0..) |term, i| {
        if (term.* != .annotation) {
            return throw_not_selectable(_type, span, errors);
        }
        if (std.mem.eql(u8, term.annotation.pattern.token().data, field)) {
            return i;
        }
    } else {
        errors.add_error(errs_.Error{ .member_not_in_type = .{ .span = span, .identifier = field, .name = "struct", .type = _type } });
        return error.CompileError;
    }
}
