//! This file contains logic for validating an AST.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const args_ = @import("args.zig");
const cfg_builder_ = @import("../ir/cfg_builder.zig");
const Compiler_Context = @import("../hierarchy/compiler.zig");
const defaults_ = @import("defaults.zig");
const errs_ = @import("../util/errors.zig");
const interpret = @import("interpret.zig").interpret;
const Interpreter_Context = @import("../interpretation/interpreter.zig");
const module_ = @import("../hierarchy/module.zig");
const poison_ = @import("../ast/poison.zig");
const prelude_ = @import("../hierarchy/prelude.zig");
const Span = @import("../util/span.zig");
const stamp = @import("stamp.zig").stamp;
const Token = @import("../lexer/token.zig");
const typing_ = @import("typing.zig");
const validate_symbol_ = @import("symbol_validate.zig");
const validate_pattern_ = @import("pattern_validate.zig");
const Type_AST = @import("../types/type.zig").Type_AST;
const type_validate_ = @import("../types/type_validate.zig");

const Validate_Error_Enum = error{ LexerError, ParseError, CompileError };

/// Recursively validates an AST, returning a valid AST if successful, or the poisoned AST if not.
///
/// Interpretation occurs during the validation of comptime AST nodes. Module compilation is possible during this phase
/// as well, when validating the build script.
///
/// ### Parameters
/// - `ast`: The AST to validate.
/// - `old_expected_type`: Should be null if `ast` can be any type
/// - `compiler`: The compiler instance.
pub fn validate_AST(ast: *ast_.AST, old_expected_type: ?*Type_AST, compiler: *Compiler_Context) *ast_.AST {
    // TODO: Bit long
    var expected_type = old_expected_type;
    if (ast.common().validation_state == .validating) {
        // std.debug.print("{}\n", .{ast});
        compiler.errors.add_error(errs_.Error{ .recursive_definition = .{
            .span = ast.token().span,
            .symbol_name = null,
        } });
        return poison_.poisoned;
    } else if (ast.common().validation_state == .invalid) {
        return poison_.poisoned;
    } else if (
    // ast.* != .@"comptime" and
    ast.common().validation_state == .valid) {
        // TODO: Why do we need comptime here?
        return ast.common().validation_state.valid.valid_form;
    }
    // std.debug.print("{}: {?}\n", .{ ast, expected_type });
    ast.common().validation_state = .validating;

    if (expected_type != null and expected_type.?.* == .poison) {
        expected_type = null;
    }

    if (expected_type) |_| {
        // std.debug.assert(expected_type.?.common().validation_state == .valid); // expected type isn't determined to be valid
        // const expected_type_type = expected_type.?.typeof(compiler.allocator());
        // std.debug.print("typeof({?}) = {}\n", .{ expected_type, expected_type_type });
        // const expected_type_is_type = typing_.checked_types_match(expected_type_type, prelude_.type_type, &compiler.errors) catch return ast.enpoison();
        // std.debug.assert(expected_type_is_type); // expected type isn't of type Type

        const expanded = expected_type.?.expand_identifier();
        if (expected_type.?.* == .type_of) {
            expected_type.?.* = expanded.*;
        }
        if (expected_type.?.* == .annotation) {
            expected_type = expected_type.?.child();
        }
        if (expected_type.?.* == .access) {
            expected_type = expected_type.?.symbol().?.init_typedef();
        }
    }

    var retval = validate_AST_internal(ast, expected_type, compiler) catch {
        return ast.enpoison();
    };

    if (retval.* == .poison) {
        return ast.enpoison();
    } else {
        // _ = retval.typeof(compiler.allocator()).expand_identifier();
        ast.common().validation_state = ast_.AST_Validation_State{ .valid = .{ .valid_form = retval } };
        retval.common().validation_state = ast_.AST_Validation_State{ .valid = .{ .valid_form = retval } };
        return retval;
    }
}

fn validate_AST_internal(
    ast: *ast_.AST,
    expected: ?*Type_AST,
    compiler: *Compiler_Context,
) Validate_Error_Enum!*ast_.AST {
    // TODO: Ugh this function is too long
    // std.debug.print("{}: {?}\n", .{ ast, expected });
    switch (ast.*) {
        // Nop, always "valid"
        .poison,
        .module,
        // Pattern symbols, traits, and impls are validated elsewhere, the AST doesn't need to be re-validated.
        .pattern_symbol,
        .trait,
        .impl,
        .@"enum",
        .@"struct",
        .type_alias,
        => return ast,
        // .anyptr_type, .unit_type => {
        //     try typing_.type_check(ast.token().span, prelude_.type_type, expected, &compiler.errors);
        //     return ast;
        // },
        .unit_value => {
            try typing_.type_check(ast.token().span, prelude_.unit_type, expected, &compiler.errors);
            return ast;
        },
        .int => {
            if (expected != null and !prelude_.unit_type.types_match(expected.?)) {
                try typing_.type_check_int(ast, expected, &compiler.errors, compiler.allocator());
            }
            return ast;
        },
        .float => {
            try typing_.type_check_float(ast, expected, &compiler.errors);
            return ast;
        },
        .char => {
            try typing_.type_check(ast.token().span, prelude_.char_type, expected, &compiler.errors);
            return ast;
        },
        .string => {
            try typing_.type_check(ast.token().span, prelude_.string_type, expected, &compiler.errors);
            return ast;
        },
        .identifier => {
            // look up symbol, that's the type
            const symbol = ast.symbol().?;
            if (symbol.validation_state == .invalid) {
                return error.CompileError;
            }
            try validate_symbol_.validate(symbol, compiler);
            if (symbol.refers_to_type()) {
                if (expected != null) {
                    compiler.errors.add_error(errs_.Error{ .unexpected_type_type = .{ .expected = expected, .span = ast.token().span } });
                    return ast.enpoison();
                }
            } else {
                try typing_.type_check(ast.token().span, symbol.type(), expected, &compiler.errors);
            }
            return ast;
        },
        .access => {
            ast.set_lhs(validate_AST(ast.lhs(), null, compiler));
            try poison_.assert_none_poisoned(ast.lhs());

            // look up symbol, that's the type
            const symbol = ast.symbol().?;
            if (symbol.validation_state == .invalid) {
                return error.CompileError;
            }
            try validate_symbol_.validate(symbol, compiler);
            if (symbol.refers_to_type()) {
                if (expected != null) {
                    compiler.errors.add_error(errs_.Error{ .unexpected_type_type = .{ .expected = expected, .span = ast.token().span } });
                    return ast.enpoison();
                }
            } else {
                _ = ast.assert_ast_valid();
                const ast_type = ast.typeof(compiler.allocator());
                try typing_.type_check(ast.token().span, ast_type, expected, &compiler.errors);
            }
            return ast;
        },
        .true, .false => {
            try typing_.type_check(ast.token().span, prelude_.bool_type, expected, &compiler.errors);
            return ast;
        },
        .not => {
            ast.set_expr(validate_AST(ast.expr(), prelude_.bool_type, compiler));
            try poison_.assert_none_poisoned(ast.expr());
            try typing_.type_check(ast.token().span, prelude_.bool_type, expected, &compiler.errors);
            return ast;
        },
        .negate => {
            ast.set_expr(validate_AST(ast.expr(), expected, compiler));
            try poison_.assert_none_poisoned(ast.expr());
            try typing_.type_check_arithmetic(ast.token().span, ast.expr().typeof(compiler.allocator()), &compiler.errors);
            try typing_.type_check(ast.token().span, ast.expr().typeof(compiler.allocator()), expected, &compiler.errors);
            return ast;
        },
        .dereference => {
            const expr_span = ast.expr().token().span;
            if (expected != null) {
                const addr_of = Type_AST.create_addr_of(ast.token(), expected.?, false, false, compiler.allocator());
                ast.set_expr(validate_AST(ast.expr(), addr_of, compiler));
            } else {
                ast.set_expr(validate_AST(ast.expr(), null, compiler));
            }
            try poison_.assert_none_poisoned(ast.expr());
            const expanded_expr_type = ast.expr().typeof(compiler.allocator()).expand_identifier();
            if (expanded_expr_type.* != .addr_of) {
                return typing_.throw_wrong_from("address", "dereference", expanded_expr_type, expr_span, &compiler.errors);
            } else {
                return ast;
            }
        },
        .@"try" => {
            const expr_span = ast.expr().token().span;
            ast.set_expr(validate_AST(ast.expr(), null, compiler));
            try poison_.assert_none_poisoned(ast.expr());
            var expanded_expr_type = ast.expr().typeof(compiler.allocator()).expand_identifier();
            if (expanded_expr_type.* != .sum_type or expanded_expr_type.sum_type.from != .@"error") {
                return typing_.throw_wrong_from("error", "try", expanded_expr_type, expr_span, &compiler.errors);
            }
            try typing_.type_check(ast.token().span, expanded_expr_type.get_ok_type().child(), expected, &compiler.errors);
            const expanded_function_codomain = ast.symbol().?.type().rhs().expand_identifier();
            if (expanded_function_codomain.* != .sum_type or expanded_function_codomain.sum_type.from != .@"error") {
                compiler.errors.add_error(errs_.Error{ .basic = .{
                    .span = ast.token().span,
                    .msg = "enclosing function around try expression does not return an error",
                } });
                return ast.enpoison();
            } else {
                // err must match
                const expr_error_type = expanded_expr_type.get_err_type().child();
                const function_error_type = expanded_function_codomain.get_err_type().child();
                if (!expr_error_type.types_match(function_error_type)) {
                    return typing_.throw_unexpected_type(expr_span, expanded_expr_type, expanded_function_codomain, &compiler.errors);
                }
            }
            return ast;
        },
        // .domain_of => {
        //     ast.domain_of.sum_type = validate_AST(ast.domain_of.sum_type, prelude_.type_type, compiler);
        //     try poison_.assert_none_poisoned(ast.domain_of.sum_type);
        //     ast.set_expr(validate_AST(ast.expr(), ast.domain_of.sum_type, compiler));
        //     try poison_.assert_none_poisoned(ast.expr());
        //     return ast.expr().sum_value.domain.?.child(); // Should be filled by sum_value's validate
        // },
        // .type_of => {
        //     ast.set_expr(validate_AST(ast.expr(), null, compiler));
        //     try poison_.assert_none_poisoned(ast.expr());
        //     try typing_.type_check(ast.token().span, prelude_.type_type, expected, &compiler.errors);
        //     return ast.expr().typeof(compiler.allocator());
        // },
        .default => {
            // ast.set_expr(validate_AST(ast.expr(), prelude_.type_type, compiler));
            // try poison_.assert_none_poisoned(ast.expr());
            const ast_type = ast.typeof(compiler.allocator());
            try typing_.type_check(ast.token().span, ast_type, expected, &compiler.errors);
            const retval = defaults_.generate_default(ast_type.expand_identifier(), ast.default._type.token().span, &compiler.errors, compiler.allocator());
            return retval;
        },
        .size_of => {
            // ast.set_expr(validate_AST(ast.expr(), prelude_.type_type, compiler));
            // try poison_.assert_none_poisoned(ast.expr());
            try typing_.type_check(ast.token().span, prelude_.int_type, expected, &compiler.errors);
            return ast_.AST.create_int(ast.token(), ast.size_of._type.expand_identifier().sizeof(), compiler.allocator());
        },
        // .@"comptime" => {
        //     if (ast.@"comptime".result != null) {
        //         return ast.@"comptime".result.?;
        //     }
        //     ast.set_expr(validate_AST(ast.expr(), expected, compiler));
        //     const ast_type = ast.expr().typeof(compiler.allocator());
        //     const expanded_ast_type = ast_type.expand_identifier();
        //     if (try typing_.checked_types_match(expanded_ast_type, prelude_.void_type, &compiler.errors)) {
        //         return typing_.throw_unexpected_void_type(ast.expr().token().span, &compiler.errors);
        //     }
        //     try typing_.type_check(ast.token().span, expanded_ast_type, expected, &compiler.errors);

        //     var expanded_expected = expected;
        //     if (expected != null and expected.?.* == .type_of) {
        //         expanded_expected = expected.?.expand_identifier();
        //     }
        //     ast.@"comptime".result = try interpret(ast.expr(), expanded_expected orelse expanded_ast_type, ast.scope().?, compiler);
        //     return ast.@"comptime".result.?;
        // },
        .assign => {
            try validate_L_Value(ast.lhs(), &compiler.errors);
            ast.set_lhs(validate_AST(ast.lhs(), null, compiler));
            const lhs_type = ast.lhs().typeof(compiler.allocator());
            try poison_.assert_none_poisoned(lhs_type);
            const rhs_expected: ?*Type_AST = if (ast.lhs().* == .identifier and std.mem.eql(u8, ast.lhs().token().data, "_")) null else lhs_type;
            ast.set_rhs(validate_AST(ast.rhs(), rhs_expected, compiler));
            try poison_.assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
            try assert_mutable(ast.lhs(), &compiler.errors, compiler.allocator());
            try typing_.type_check(ast.token().span, prelude_.unit_type, expected, &compiler.errors);
            return ast;
        },
        .@"or", .@"and" => return try typing_.binary_operator_closed(ast, prelude_.bool_type, expected, compiler),
        .add, .sub, .mult, .div => {
            // These operators are open, since they allow for polymorphism between their operands.
            const lhs_type = try typing_.binary_operator_open(ast, expected, compiler);
            const expanded_lhs_type = lhs_type.expand_identifier();
            const expanded_expected: ?*Type_AST = if (expected == null) null else expected.?.expand_identifier();
            try typing_.type_check_arithmetic(ast.token().span, expanded_lhs_type, &compiler.errors);
            try typing_.type_check(ast.token().span, expanded_lhs_type, expanded_expected, &compiler.errors);
            return ast;
        },
        .mod => {
            const lhs_type = try typing_.binary_operator_open(ast, null, compiler);
            try typing_.type_check_integral(ast.token().span, lhs_type, &compiler.errors);
            try typing_.type_check(ast.token().span, lhs_type, expected, &compiler.errors);
            return ast;
        },
        .equal, .not_equal => {
            const lhs_type = try typing_.binary_operator_open(ast, null, compiler);
            // const expanded_lhs_type = lhs_type.expand_identifier();
            // if (try prelude_.type_type.types_match(expanded_lhs_type)) {
            //     return try typing_.type_equality_operation(ast, &compiler.errors, compiler.allocator());
            // }
            try typing_.type_check_eq(ast.token().span, lhs_type, &compiler.errors);
            try typing_.type_check(ast.token().span, prelude_.bool_type, expected, &compiler.errors);
            return ast;
        },
        .greater, .lesser, .greater_equal, .lesser_equal => {
            const lhs_type = try typing_.binary_operator_open(ast, null, compiler);
            try typing_.type_check_ord(ast.token().span, lhs_type, &compiler.errors);
            try typing_.type_check(ast.token().span, prelude_.bool_type, expected, &compiler.errors);
            return ast;
        },
        .@"catch", .@"orelse" => {
            const lhs_span = ast.lhs().token().span;
            ast.set_lhs(validate_AST(ast.lhs(), null, compiler));
            ast.set_rhs(validate_AST(ast.rhs(), expected, compiler));
            try poison_.assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
            var expanded_lhs_type = ast.lhs().typeof(compiler.allocator()).expand_identifier();
            try typing_.coalesce_operator(expanded_lhs_type, ast, lhs_span, &compiler.errors);
            try typing_.type_check(ast.token().span, expanded_lhs_type.get_nominal_type().child(), expected, &compiler.errors);
            return ast;
        },
        .bit_and, .bit_or, .bit_xor => {
            for (0..ast.children().items.len) |i| {
                ast.children().items[i] = validate_AST(ast.children().items[i], expected, compiler);
                try poison_.assert_none_poisoned(ast.children().items[i]);
                const arg_type = ast.children().items[i].typeof(compiler.allocator());
                try typing_.type_check_bits(ast.token().span, arg_type, &compiler.errors);
                try typing_.type_check(ast.token().span, arg_type, expected, &compiler.errors);
            }
            return ast;
        },
        .bit_not => {
            ast.set_expr(validate_AST(ast.expr(), expected, compiler));
            try poison_.assert_none_poisoned(ast.expr());
            try typing_.type_check_bits(ast.token().span, ast.expr().typeof(compiler.allocator()), &compiler.errors);
            try typing_.type_check(ast.token().span, ast.expr().typeof(compiler.allocator()), expected, &compiler.errors);
            return ast;
        },
        .left_shift, .right_shift => {
            ast.set_lhs(validate_AST(ast.lhs(), expected, compiler));
            ast.set_rhs(validate_AST(ast.rhs(), expected, compiler));
            const lhs_type = ast.typeof(compiler.allocator());
            try typing_.type_check_bits(ast.token().span, lhs_type, &compiler.errors);
            try typing_.type_check(ast.token().span, lhs_type, expected, &compiler.errors);
            return ast;
        },
        .call => {
            const lhs_span = ast.lhs().token().span;
            ast.set_lhs(validate_AST(ast.lhs(), null, compiler));
            try poison_.assert_none_poisoned(ast.lhs());

            var lhs_type = ast.lhs().typeof(compiler.allocator());
            const expanded_lhs_type = lhs_type.expand_identifier();
            if (ast.lhs().* != .sum_value and expanded_lhs_type.* != .function) {
                return typing_.throw_wrong_from(
                    "function",
                    "call",
                    expanded_lhs_type,
                    lhs_span,
                    &compiler.errors,
                );
            }

            // since sum_values are always compiler constructed, and their type is always a sum-type, this should always hold
            std.debug.assert(ast.lhs().* != .sum_value or expanded_lhs_type.* == .sum_type); // (an `implies` operator would be cool btw...)

            const domain = if (expanded_lhs_type.* == .function) expanded_lhs_type.lhs() else ast.lhs().sum_value.domain.?;
            const codomain = if (expanded_lhs_type.* == .function) expanded_lhs_type.rhs() else ast.lhs().sum_value.base.?;
            const variadic = expanded_lhs_type.* == .function and expanded_lhs_type.function.variadic;
            ast.set_children(try args_.default_args(.function, ast.children().*, ast.token().span, domain, &compiler.errors, compiler.allocator()));
            try args_.validate_args_arity(.function, ast.children(), domain, variadic, ast.token().span, &compiler.errors);
            ast.set_children((try typing_.validate_args_type(ast.children(), domain, compiler)).*);
            try typing_.type_check(ast.token().span, codomain, expected, &compiler.errors);
            if (ast.lhs().* == .sum_value) {
                // lhs is a sum value, usurp its init with ast's rhs
                std.debug.assert(ast.children().items.len == 1);
                ast.lhs().sum_value.init = ast.children().items[0];
                return ast.lhs();
            }

            return ast;
        },
        .index => {
            const lhs_span = ast.lhs().token().span; // Used for error reporting
            // if (expected != null and try prelude_.type_type.types_match(expected.?)) {
            //     ast.set_lhs(validate_AST(ast.lhs(), prelude_.type_type, compiler));
            // } else
            {
                ast.set_lhs(validate_AST(ast.lhs(), null, compiler));
            }
            ast.set_rhs(validate_AST(ast.rhs(), prelude_.int_type, compiler));
            try poison_.assert_none_poisoned(.{ ast.lhs(), ast.rhs() });

            const lhs_type = ast.lhs().typeof(compiler.allocator());
            const expanded_lhs_type = try typing_.implicit_dereference(ast, lhs_type.expand_identifier(), compiler);

            // if (try lhs_type.types_match(prelude_.type_type) and
            //     ast.lhs().* == .product and
            //     ast.rhs().* == .int and ast.lhs().children().items.len > ast.rhs().int.data)
            // {
            //     // Index a product type, resolve immediately
            //     return ast.lhs().children().items[@as(usize, @intCast(ast.rhs().int.data))];
            // } else
            if (expanded_lhs_type.* != .product and expanded_lhs_type.* != .array_of and !(expanded_lhs_type.* == .addr_of and expanded_lhs_type.addr_of.multiptr)) {
                compiler.errors.add_error(errs_.Error{ .not_indexable = .{ .span = lhs_span, ._type = expanded_lhs_type } });
                return error.CompileError;
            } else if (expanded_lhs_type.* == .product and
                !expanded_lhs_type.product.was_slice and
                !expanded_lhs_type.product.is_homotypical())
            {
                if (ast.rhs().* != .int) {
                    // rhs is not int, error
                    compiler.errors.add_error(errs_.Error{ .basic = .{
                        .span = lhs_span,
                        .msg = "array is not homotypical and index is not compile-time known",
                    } });
                    return ast.enpoison();
                }
                // rhs is compile-time known, change to select
                const field = ast_.AST.create_field(Token.init_simple(""), compiler.allocator());
                const select = ast_.AST.create_select(ast.token(), ast.lhs(), field, compiler.allocator()).assert_ast_valid();
                select.set_pos(@as(usize, @intCast(ast.rhs().int.data)));
                return select;
            } else if (expected != null) {
                if (expanded_lhs_type.* == .product and !expanded_lhs_type.product.was_slice) {
                    try typing_.type_check(ast.token().span, expanded_lhs_type.children().items[0], expected, &compiler.errors);
                } else if (expanded_lhs_type.* == .product and expanded_lhs_type.product.was_slice) {
                    try typing_.type_check(ast.token().span, expanded_lhs_type.children().items[0].child().child(), expected, &compiler.errors);
                }
            }
            return ast;
        },
        .select => {
            ast.set_lhs(validate_AST(ast.lhs(), null, compiler));
            try poison_.assert_none_poisoned(ast.lhs());
            const lhs_type = ast.lhs().typeof(compiler.allocator());
            const expanded_lhs_type = try typing_.implicit_dereference(ast, lhs_type.expand_identifier(), compiler);
            // if (try expanded_lhs_type.types_match(prelude_.type_type) and ast.lhs().expand_identifier().* == .sum_type) {
            //     // Select on a Type (only valid for a sum type), change to sum value
            //     const sum_value = ast_.AST.create_sum_value(ast.rhs().token(), compiler.allocator());
            //     sum_value.sum_value.base = ast.lhs();
            //     return validate_AST(sum_value, expected, compiler);
            // } else
            const expanded_expected = get_expanded_expected(expected, compiler.allocator());
            if (expanded_lhs_type.* == .array_of and std.mem.eql(u8, "length", ast.rhs().token().data)) {
                try typing_.type_check(ast.token().span, prelude_.int_type, expanded_expected, &compiler.errors);
                return expanded_lhs_type.array_of.len.assert_ast_valid();
            } else if (ast.pos() == null) {
                ast.set_pos(try typing_.find_select_pos(expanded_lhs_type, ast.rhs().token().data, ast.token().span, &compiler.errors));
            }

            _ = ast.assert_ast_valid();
            const ast_type = ast.typeof(compiler.allocator());
            try typing_.type_check(ast.token().span, ast_type, expected, &compiler.errors);
            return ast;
        },

        .invoke => {
            ast.set_lhs(validate_AST(ast.lhs(), null, compiler));
            try poison_.assert_none_poisoned(ast.lhs());
            // true_lhs_type is lhs's type
            const true_lhs_type = ast.lhs().typeof(compiler.allocator());
            // method_decl is the method_decl AST of the method being invoked
            var method_decl: ?*ast_.AST = undefined;
            if (true_lhs_type.expand_identifier().* == .dyn_type) {
                // The receiver is a dynamic type
                const trait = true_lhs_type.expand_identifier().expr().symbol().?.decl.?;
                method_decl = trait.trait.find_method(ast.rhs().token().data);
            } else {
                // The receiver is a regular type. STRIP AWAY ADDRs!
                const lhs_type = if (true_lhs_type.* == .addr_of) true_lhs_type.child() else true_lhs_type;
                method_decl = try ast.scope().?.lookup_impl_member(lhs_type, ast.rhs().token().data, compiler);
            }
            if (method_decl == null) {
                compiler.errors.add_error(errs_.Error{
                    .type_not_impl_method = .{
                        .span = ast.token().span,
                        .method_name = ast.rhs().token().data,
                        ._type = true_lhs_type, // TODO: Strip away addr_of's
                    },
                });
                return error.CompileError;
            }
            method_decl = validate_AST(method_decl.?, null, compiler);
            try poison_.assert_none_poisoned(method_decl);
            ast.invoke.method_decl = method_decl.?;
            const domain: *Type_AST = method_decl.?.method_decl.domain.?;
            const expanded_true_lhs_type = true_lhs_type.expand_identifier();
            if (method_decl.?.method_decl.receiver != null) {
                const receiver_kind: ?ast_.Receiver_Kind = method_decl.?.method_decl.receiver.?.receiver.kind;
                // Trait method takes a receiver...
                // Prepend invoke lhs to args if there is a receiver
                if (expanded_true_lhs_type.* == .dyn_type or expanded_true_lhs_type.* == .addr_of) {
                    // lhs type is dynamic or an address...
                    if (!expanded_true_lhs_type.mut() and receiver_kind == .mut_addr_of) {
                        // Receiver is immutable when it should be mutable
                        compiler.errors.add_error(errs_.Error{ .invoke_receiver_mismatch = .{
                            .lhs_type = true_lhs_type,
                            .method_name = method_decl.?.method_decl.name.token().data,
                            .method_receiver = receiver_kind.?,
                            .receiver_span = ast.lhs().token().span,
                        } });
                        return error.CompileError;
                    }
                    ast.children().insert(0, ast.lhs()) catch unreachable; // prepend lhs to children as a receiver
                } else {
                    // lhs type is not dynamic and not an address
                    const addr_of = ast_.AST.create_addr_of(ast.lhs().token(), ast.lhs(), receiver_kind.? == .mut_addr_of, false, compiler.allocator());
                    ast.children().insert(0, addr_of) catch unreachable; // prepend lhs to children as a receiver
                }
            }
            ast.set_children(try args_.default_args(.method, ast.children().*, ast.token().span, domain, &compiler.errors, compiler.allocator()));
            try args_.validate_args_arity(.method, ast.children(), domain, false, ast.token().span, &compiler.errors);
            ast.set_children((try typing_.validate_args_type(ast.children(), domain, compiler)).*);

            _ = ast.assert_ast_valid();
            const ast_type = ast.typeof(compiler.allocator());
            try typing_.type_check(ast.token().span, ast_type, expected, &compiler.errors);
            return ast;
        },
        // .dyn_type => {
        //     ast.set_expr(validate_AST(ast.expr(), null, compiler));
        //     if (ast.expr().* != .identifier) {
        //         return typing_.throw_wrong_from("dyn", "trait", ast, ast.token().span, &compiler.errors);
        //     }
        //     const symbol = ast.expr().symbol();
        //     if (symbol == null or symbol.?.kind != .trait) {
        //         return typing_.throw_wrong_from("trait", "dyn", ast.expr(), ast.expr().token().span, &compiler.errors);
        //     }

        //     try typing_.type_check(ast.token().span, prelude_.type_type, expected, &compiler.errors);
        //     return ast;
        // },
        .dyn_value => {
            ast.set_expr(validate_AST(ast.expr(), null, compiler));
            // ast.dyn_value.dyn_type = validate_AST(ast.dyn_value.dyn_type, prelude_.type_type, compiler);
            const expr_type = ast.expr().typeof(compiler.allocator());

            const impl = ast.scope().?.impl_trait_lookup(expr_type, ast.dyn_value.dyn_type.child().symbol().?);
            if (impl.ast == null) {
                compiler.errors.add_error(errs_.Error{ .type_not_impl_trait = .{
                    .span = ast.token().span,
                    .trait_name = ast.dyn_value.dyn_type.child().symbol().?.name,
                    ._type = expr_type,
                } });
                return error.CompileError;
            }
            ast.dyn_value.impl = impl.ast;

            try typing_.type_check(ast.token().span, ast.dyn_value.dyn_type, expected, &compiler.errors);
            return ast;
        },
        // .function => return try typing_.binary_operator_closed(ast, prelude_.type_type, expected, compiler),
        // .sum_type => {
        //     for (0..ast.children().items.len) |i| {
        //         std.debug.assert(ast.children().items[i].* == .annotation); // sums are expanded in expand.zig
        //         ast.children().items[i] = validate_AST(ast.children().items[i], prelude_.type_type, compiler);
        //     }
        //     try poison_.assert_none_poisoned(ast.children());
        //     try typing_.type_check(ast.token().span, prelude_.type_type, expected, &compiler.errors);
        //     return ast;
        // },
        // .untagged_sum_type => {
        //     ast.set_expr(validate_AST(ast.expr(), prelude_.type_type, compiler).expand_identifier());
        //     try poison_.assert_none_poisoned(ast.expr());
        //     if (ast.expr().* != .sum_type) {
        //         compiler.errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "not a sum type" } });
        //         return ast.enpoison();
        //     }
        //     try typing_.type_check(ast.token().span, ast.expr().typeof(compiler.allocator()), expected, &compiler.errors);
        //     return ast;
        // },
        .product => {
            const expanded_expected: ?*Type_AST = if (expected == null) null else expected.?.expand_identifier();
            if (expanded_expected == null) {
                // Not expecting anything
                for (0..ast.children().items.len) |i| {
                    ast.children().items[i] = validate_AST(ast.children().items[i], expanded_expected, compiler);
                }
                try poison_.assert_none_poisoned(ast.children());
            } else if (expanded_expected != null and expanded_expected.?.* == .product) {
                // Expecting ast to be a product value of some product type
                _ = ast.assert_ast_valid();
                ast.set_children(try args_.default_args(.product, ast.children().*, ast.token().span, expanded_expected.?, &compiler.errors, compiler.allocator()));
                try args_.validate_args_arity(.product, ast.children(), expanded_expected.?, false, ast.token().span, &compiler.errors);
                ast.set_children((try typing_.validate_args_type(ast.children(), expanded_expected.?, compiler)).*);
                ast.common()._type = expected.?;
            } else if (expanded_expected == null) {
                return typing_.throw_unexpected_type(ast.token().span, expected.?, poison_.poisoned_type, &compiler.errors);
            } else if (!prelude_.unit_type.types_match(expanded_expected.?)) {
                // It's ok to assign this to a unit type, something like `_ = (1, 2, 3)`
                // expecting something that is not a type nor a product is not ok!
                // poison `got`, so that it doesn't print anything for the `got` section, wouldn't make sense anyway
                return typing_.throw_unexpected_type(ast.token().span, expected.?, ast.typeof(compiler.allocator()), &compiler.errors);
            }
            return ast;
        },
        .array_value => {
            const expanded_expanded = get_expanded_expected(expected, compiler.allocator());
            if (expanded_expanded != null and expanded_expanded.?.* != .array_of) {
                return typing_.throw_wrong_from("array", "array value", expanded_expanded.?, ast.token().span, &compiler.errors);
            }
            const elem_type = if (expanded_expanded == null) null else expanded_expanded.?.array_of._child;
            ast.children().items[0] = validate_AST(ast.children().items[0], elem_type, compiler);
            const first_type = ast.children().items[0].typeof(compiler.allocator());
            for (ast.children().items[1..], 1..) |child, i| {
                ast.children().items[i] = validate_AST(child, first_type, compiler);
            }
            try poison_.assert_none_poisoned(ast.children().items);
            return ast;
        },
        // .@"union" => {
        //     // Save spans since lhs and rhs are expanded, need spans for &compiler.errors
        //     const lhs_span = ast.lhs().token().span;
        //     const rhs_span = ast.rhs().token().span;

        //     const new_ast = try typing_.binary_operator_closed(ast, prelude_.type_type, expected, compiler);

        //     const expanded_lhs = new_ast.lhs().expand_identifier();
        //     const expanded_rhs = new_ast.rhs().expand_identifier();
        //     if (expanded_lhs.* != .sum_type) {
        //         return typing_.throw_wrong_from("sum", "union", expanded_lhs, lhs_span, &compiler.errors);
        //     } else if (expanded_rhs.* != .sum_type) {
        //         return typing_.throw_wrong_from("sum", "union", expanded_rhs, rhs_span, &compiler.errors);
        //     }

        //     return try typing_.merge_sums(expanded_lhs, expanded_rhs, new_ast.token(), &compiler.errors, compiler.allocator());
        // },
        .addr_of => {
            // FIXME: High cyclo
            if (expected == null) {
                // Not expecting anything, just validate expr
                ast.set_expr(validate_AST(ast.expr(), null, compiler));
                try poison_.assert_none_poisoned(ast.expr());
                try validate_L_Value(ast.expr(), &compiler.errors);
            }
            // else if (try prelude_.type_type.types_match(expected.?)) {
            //     // Address type, type of this ast must be a type, inner must be a type
            //     if (ast.expr().* == .identifier) {
            //         _ = ast.expr().expand_identifier();
            //         const span = ast.expr().token().span;
            //         const got = ast.expr().typeof(compiler.allocator());
            //         if (got.* != .type_of) {
            //             if (!try got.types_match(prelude_.type_type, &compiler.errors)) {
            //                 return typing_.throw_unexpected_type(span, prelude_.type_type, got, &compiler.errors);
            //             }
            //         }
            //         _ = ast.expr().assert_ast_valid();
            //     } else {
            //         ast.set_expr(validate_AST(ast.expr(), prelude_.type_type, compiler));
            //         try poison_.assert_none_poisoned(ast.expr());
            //     }
            // }
            else {
                // Address value, expected must be an address, inner must match with expected's inner
                const expanded_expected = expected.?.expand_identifier();
                if (expanded_expected.* == .dyn_type) {
                    return validate_AST(
                        ast_.AST.create_dyn_value(
                            ast.token(),
                            expanded_expected,
                            ast.expr(),
                            ast.scope().?,
                            ast.addr_of.mut,
                            compiler.allocator(),
                        ),
                        expected,
                        compiler,
                    );
                } else if (expanded_expected.* != .addr_of) {
                    // Didn't expect an address type. Validate expr and report error
                    return typing_.throw_unexpected_type(ast.token().span, expected.?, poison_.poisoned_type, &compiler.errors);
                }
                _ = expanded_expected.child().expand_identifier();

                // Everythings Ok.
                ast.set_expr(validate_AST(ast.expr(), expanded_expected.child(), compiler));
                try poison_.assert_none_poisoned(ast.expr());
                _ = ast.assert_ast_valid();
                if (ast.expr().* != .product) {
                    // Validate that expr is an L-value *only if* expr is not a product
                    // It is possible to take a addr of a product. The address is the address of the temporary
                    // This is mirrored with a slice_of a product.
                    try validate_L_Value(ast.expr(), &compiler.errors);
                }
                if (ast.addr_of.mut) {
                    try assert_mutable(ast.expr(), &compiler.errors, compiler.allocator());
                }
            }

            return ast;
        },
        .slice_of => {
            ast.set_expr(validate_AST(ast.expr(), null, compiler));
            try poison_.assert_none_poisoned(ast.expr());
            const expr_type = ast.expr().typeof(compiler.allocator());

            // ast.expr() must be homotypical product type of expected
            if (expr_type.* != .array_of) {
                compiler.errors.add_error(errs_.Error{ .basic = .{
                    .span = ast.token().span,
                    .msg = "attempt to take slice-of something that is not an array",
                } });
                return ast.enpoison();
            }

            _ = ast.assert_ast_valid();
            const ast_type = ast.typeof(compiler.allocator());
            try typing_.type_check(ast.token().span, ast_type, expected, &compiler.errors);

            if (ast.expr().* != .array_value) {
                // Validate that expr is an L-value *only if* expr is not a array
                // It is possible to take a slice of a product. The slice is the sliceof the temporary
                // This is mirrored with addr_of a product.
                try validate_L_Value(ast.expr(), &compiler.errors);
            }
            if (ast.slice_of.mut) {
                try assert_mutable(ast.expr(), &compiler.errors, compiler.allocator());
            }
            return ast_.AST.create_slice_value(ast.expr(), ast.slice_of.mut, expr_type, compiler.allocator());
        },
        // .array_of => {
        //     ast.set_expr(validate_AST(ast.expr(), prelude_.type_type, compiler));
        //     try poison_.assert_none_poisoned(ast.expr());
        //     try typing_.type_check(ast.token().span, prelude_.type_type, expected, &compiler.errors);

        //     // Array-of type, type of this ast must be a type, inner must be a type
        //     ast.array_of.len = validate_AST(ast.array_of.len, prelude_.int_type, compiler);
        //     try poison_.assert_none_poisoned(ast.array_of.len);
        //     var array_length: *ast_.AST = undefined;
        //     if (ast.array_of.len.* == .int) {
        //         array_length = ast.array_of.len;
        //     } else if (ast.array_of.len.* == .identifier and ast.array_of.len.symbol().?.kind == .@"const" and ast.array_of.len.symbol().?.decl.?.decl.init.?.* == .int) {
        //         array_length = ast.array_of.len.symbol().?.decl.?.decl.init.?;
        //     } else {
        //         compiler.errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "not integer literal" } });
        //         return ast.enpoison();
        //     }
        //     if (array_length.int.data <= 0) {
        //         compiler.errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "array length is not positive" } });
        //         return ast.enpoison();
        //     }
        //     return ast_.AST.create_array_type(array_length.int.data, ast.expr(), compiler.allocator());
        // },
        .sub_slice => {
            ast.sub_slice.super = validate_AST(ast.sub_slice.super, null, compiler);
            ast.sub_slice.lower = validate_AST(ast.sub_slice.lower.?, null, compiler); // lower and upper should exist
            ast.sub_slice.upper = validate_AST(ast.sub_slice.upper.?, null, compiler); // they are set in expand phase
            try poison_.assert_none_poisoned(.{ ast.sub_slice.super, ast.sub_slice.lower, ast.sub_slice.upper });
            const super_type = ast.sub_slice.super.typeof(compiler.allocator());
            if (super_type.* != .product or !super_type.product.was_slice) {
                compiler.errors.add_error(errs_.Error{ .basic = .{
                    .span = ast.token().span,
                    .msg = "cannot take a sub-slice of something that is not a slice",
                } });
                return error.CompileError;
            }
            return ast;
        },
        // .annotation => {
        //     if (ast.annotation.pattern.* != .pattern_symbol and ast.annotation.pattern.* != .identifier) {
        //         compiler.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "identifier", .got = ast.annotation.pattern.token() } });
        //         return error.CompileError;
        //     }
        //     ast.child() = validate_AST(ast.child(), prelude_.type_type, compiler);
        //     try poison_.assert_none_poisoned(.{ast.child()});
        //     if (ast.annotation.init != null) {
        //         ast.annotation.init = validate_AST(ast.annotation.init.?, ast.child(), compiler);
        //     }
        //     try poison_.assert_none_poisoned(.{ast.annotation.init});
        //     try typing_.type_check(ast.token().span, prelude_.type_type, expected, &compiler.errors);
        //     return ast;
        // },
        .sum_value => {
            if (ast.sum_value.base == null and expected == null) {
                compiler.errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "cannot infer type for initializer" } });
                return error.CompileError;
            } else if (ast.sum_value.base == null) {
                // Infer that the base type is `expected`
                ast.sum_value.base = expected;
            }

            const expanded_base: *Type_AST = ast.sum_value.base.?.expand_identifier();
            if (expanded_base.* != .sum_type) {
                return typing_.throw_wrong_from("sum", "sum value", expanded_base, ast.token().span, &compiler.errors);
            }

            const pos = expanded_base.get_pos(ast.token().data);
            if (pos == null and expanded_base.* == .sum_type) {
                compiler.errors.add_error(errs_.Error{ .member_not_in = .{ .span = ast.token().span, .identifier = ast.token().data, .name = "sum", .group = expanded_base } });
                return error.CompileError;
            }
            ast.set_pos(expanded_base.get_pos(ast.token().data));

            ast.sum_value.domain = expanded_base.children().items[ast.pos().?];
            if (ast.sum_value.init == null) {
                // This may be usurped by a .call node
                ast.sum_value.init = ast.sum_value.domain.?.annotation.init orelse
                    try defaults_.generate_default(ast.sum_value.domain.?.child(), ast.token().span, &compiler.errors, compiler.allocator());
            } else {
                ast.sum_value.init = validate_AST(ast.sum_value.init.?, ast.sum_value.domain.?.child(), compiler);
            }

            return ast;
        },
        .@"if" => {
            // FIXME: High cyclo
            if (ast.@"if".let) |let| {
                ast.@"if".let = validate_AST(let, null, compiler);
            }

            ast.@"if".condition = validate_AST(ast.@"if".condition, prelude_.bool_type, compiler);
            try poison_.assert_none_poisoned(ast.@"if".condition);

            // expecting a type
            var expected_type: ?*Type_AST = undefined;
            var expanded_expected: *Type_AST = undefined;
            var is_result_optional: bool = false;
            if (expected == null) {
                expected_type = null;
            } else {
                expanded_expected = expected.?.expand_identifier();
                is_result_optional = expanded_expected.* == .sum_type and
                    expanded_expected.sum_type.from == .optional and
                    !expanded_expected.types_match(prelude_.void_type);
                if (ast.else_block() != null) {
                    expected_type = expected.?;
                } else if (is_result_optional) {
                    expected_type = expanded_expected.get_some_type();
                } else {
                    return typing_.throw_unexpected_type(ast.token().span, expected.?, poison_.poisoned_type, &compiler.errors);
                }
            }

            if (ast.@"if".condition.* != .false) {
                ast.set_body_block(validate_AST(ast.body_block(), expected_type, compiler));
            }

            if (ast.else_block() != null and ast.@"if".condition.* != .true) {
                ast.set_else_block(validate_AST(ast.else_block().?, expected_type, compiler));
            }

            try poison_.assert_none_poisoned(.{ ast.@"if".let, ast.body_block(), ast.else_block() });

            if (ast.@"if".condition.* == .true and ast.else_block() != null) {
                // condition is true and theres an else => return {let; body}
                inset_let_into_if(ast, compiler.allocator());
                return ast.body_block();
            } else if (ast.@"if".condition.* == .true and ast.else_block() == null) {
                // condition is true and theres no else => return {let; some(body)}
                inset_let_into_if(ast, compiler.allocator());
                const opt_type = Type_AST.create_optional_type(ast.body_block().typeof(compiler.allocator()), compiler.allocator());
                const retval = ast_.AST.create_some_value(opt_type, ast.body_block(), compiler.allocator());
                return retval;
            } else if (ast.@"if".condition.* == .false and ast.else_block() != null) {
                // condition is false and theres an else => return {let; else}
                if (ast.@"if".let != null) {
                    if (ast.else_block().?.* == .block) {
                        ast.else_block().?.children().insert(0, ast.@"if".let.?) catch unreachable;
                    } else if (ast.else_block().?.* == .unit_value) {
                        var statements = std.ArrayList(*ast_.AST).init(compiler.allocator());
                        statements.append(ast.@"if".let.?) catch unreachable;
                        const block = ast_.AST.create_block(ast.else_block().?.token(), statements, null, compiler.allocator());
                        block.set_scope(ast.scope());
                        ast.set_else_block(block);
                    }
                }
                return ast.else_block().?;
            } else if (ast.@"if".condition.* == .false and ast.else_block() == null) {
                var statements = std.ArrayList(*ast_.AST).init(compiler.allocator());
                if (ast.@"if".let != null) {
                    statements.append(ast.@"if".let.?) catch unreachable;
                }
                if (ast.body_block().typeof(compiler.allocator()).types_match(prelude_.void_type)) {
                    // condition is false and theres no else and void type => return {let}
                } else {
                    // condition is false and theres no else => return {let; none()}
                    const opt_type = Type_AST.create_optional_type(ast.body_block().typeof(compiler.allocator()), compiler.allocator());
                    statements.append(ast_.AST.create_none_value(opt_type, compiler.allocator())) catch unreachable;
                }
                const ret_block = ast_.AST.create_block(Token.init_simple("{"), statements, null, compiler.allocator());
                ret_block.set_scope(ast.scope().?.parent.?);
                return ret_block;
            } else {
                // condition is undeterminable at compile-time, return if AST
                return ast;
            }
        },
        .match => {
            if (ast.match.let != null) {
                ast.match.let = validate_AST(ast.match.let.?, null, compiler);
            }
            ast.set_expr(validate_AST(ast.expr(), null, compiler));
            try poison_.assert_none_poisoned(.{ ast.match.let, ast.expr() });

            const expanded_expr_type = ast.expr().typeof(compiler.allocator()).expand_identifier();
            try poison_.assert_none_poisoned(expanded_expr_type);

            for (0..ast.children().items.len) |i| {
                ast.children().items[i] = validate_AST(ast.children().items[i], expected, compiler);
                try poison_.assert_none_poisoned(ast.children().items[i]);
                try validate_pattern_.assert_pattern_matches(ast.children().items[i].lhs(), expanded_expr_type, compiler);
            }
            try poison_.assert_none_poisoned(ast.children());

            try validate_pattern_.exhaustive_check(expanded_expr_type, ast.children(), ast.token().span, &compiler.errors, compiler.allocator());

            return ast;
        },
        .mapping => {
            // lhs for match mappings must be done elsewhere
            ast.set_rhs(validate_AST(ast.rhs(), expected, compiler));
            try poison_.assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
            return ast;
        },
        .@"while" => {
            if (ast.@"while".let) |let| {
                ast.@"while".let = validate_AST(let, null, compiler);
            }
            if (ast.@"while".post) |post| {
                ast.@"while".post = validate_AST(post, null, compiler);
            }
            ast.@"while".condition = validate_AST(ast.@"while".condition, prelude_.bool_type, compiler);

            var is_optional_type = false; //< Set if expected is an optional type
            if (expected != null) {
                const expanded_expected = expected.?.expand_identifier();
                if (expanded_expected.* == .sum_type and expanded_expected.sum_type.from == .optional) {
                    ast.set_body_block(validate_AST(ast.body_block(), expanded_expected.get_some_type(), compiler));
                    is_optional_type = true;
                }
            }
            if (!is_optional_type) {
                ast.set_body_block(validate_AST(ast.body_block(), expected, compiler));
                if (ast.else_block()) |else_block| {
                    ast.set_else_block(validate_AST(else_block, expected, compiler));
                }
            }
            try poison_.assert_none_poisoned(.{ ast.@"while".let, ast.@"while".post, ast.@"while".condition, ast.body_block(), ast.else_block() });
            return ast;
        },
        .block => {
            for (0..ast.children().items.len) |i| {
                const expected_type: ?*Type_AST = if (ast.block.final == null and i == ast.children().items.len - 1) expected else null;
                ast.children().items[i] = validate_AST(ast.children().items[i], expected_type, compiler);
                const statement = ast.children().items[i];
                // A middle-statement is any but the last statement if there is no final, or any statement if there is a final
                // Middle statements' type must be unit
                const is_middle_statement = if (ast.block.final == null) i < ast.children().items.len - 1 else true;
                if ((statement.* != .fn_decl or statement.fn_decl.name == null) and is_middle_statement) {
                    // Don't worry about fn_decl's, those should be allowed to be "discarded"
                    const expanded_statement_type = statement.typeof(compiler.allocator()).expand_identifier();
                    try typing_.middle_statement_check(statement.token().span, expanded_statement_type, &compiler.errors);
                }
            }
            try poison_.assert_none_poisoned(ast.children());
            if (ast.block.final) |final| {
                ast.block.final = validate_AST(final, expected, compiler);
                try poison_.assert_none_poisoned(ast.block.final);
            } else {
                _ = ast.assert_ast_valid();
                try typing_.type_check(ast.token().span, ast.typeof(compiler.allocator()), expected, &compiler.errors);
            }
            return ast;
        },
        .@"break", .@"continue", .@"unreachable" => {
            return ast;
        },
        .@"return" => {
            if (ast.@"return"._ret_expr) |expr| {
                ast.@"return"._ret_expr = validate_AST(expr, ast.symbol().?.type().rhs(), compiler);
                try poison_.assert_none_poisoned(ast.@"return"._ret_expr);
            } else if (expected != null and (expected.?.expand_identifier()).* != .unit_type) {
                return typing_.throw_unexpected_type(ast.token().span, expected.?, prelude_.void_type, &compiler.errors);
            }
            return ast;
        },
        .@"defer", .@"errdefer" => {
            ast.set_statement(validate_AST(ast.statement(), null, compiler));
            try poison_.assert_none_poisoned(ast.statement());
            return ast;
        },
        .fn_decl => {
            try validate_symbol_.validate(ast.symbol().?, compiler);
            if (expected) |_expected| {
                const expanded_expected = _expected.expand_identifier();
                const ast_type = ast.typeof(compiler.allocator());
                try typing_.type_check(ast.token().span, ast_type, expanded_expected, &compiler.errors);
            }
            return ast;
        },
        .method_decl => {
            std.debug.assert(expected == null); // Why wouldn't it be?
            if (ast.symbol() != null) {
                // Not a trait-method
                try validate_symbol_.validate(ast.symbol().?, compiler);
            }
            // ast.method_decl.domain = validate_AST(ast.method_decl.domain.?, prelude_.type_type, compiler);
            return ast;
        },
        .template => {
            if (expected != null and !prelude_.unit_type.types_match(expected.?)) {
                compiler.errors.add_error(
                    errs_.Error{
                        .basic = .{
                            .span = ast.token().span,
                            .msg = "cannot assign template",
                        },
                    },
                );
                return error.CompileError;
            }
            return ast;
        },
        .decl => {
            // ast.decl.type = validate_AST(ast.decl.type, prelude_.type_type, compiler);
            try poison_.assert_none_poisoned(ast.decl.type);
            if (ast.decl.init) |init| {
                ast.decl.init = validate_AST(init, ast.decl.type, compiler);
            }
            try poison_.assert_none_poisoned(ast.decl.init);
            try validate_symbol_.validate(ast.decl.name.symbol().?, compiler);
            try typing_.type_check(ast.token().span, prelude_.unit_type, expected, &compiler.errors);
            return ast;
        },
        .binding => {
            try type_validate_.validate(ast.binding.type, &compiler.errors);
            if (ast.binding.init) |init| {
                ast.binding.init = validate_AST(init, ast.binding.type, compiler);
            }
            for (ast.binding.decls.items) |decl| {
                try validate_symbol_.validate(decl.decl.name.symbol().?, compiler);
            }
            try validate_pattern_.assert_pattern_matches(ast.binding.pattern, ast.binding.type, compiler);
            try typing_.type_check(ast.token().span, prelude_.unit_type, expected, &compiler.errors);
            return ast;
        },
        else => std.debug.panic("compiler error: validate_AST() unimplemented for {s}", .{@tagName(ast.*)}),
    }
}

fn inset_let_into_if(ast: *ast_.AST, allocator: std.mem.Allocator) void {
    if (ast.@"if".let != null) {
        if (ast.body_block().* == .block) {
            ast.body_block().children().insert(0, ast.@"if".let.?) catch unreachable;
        } else if (ast.body_block().* == .unit_value) {
            var statements = std.ArrayList(*ast_.AST).init(allocator);
            statements.append(ast.@"if".let.?) catch unreachable;
            const block = ast_.AST.create_block(ast.body_block().token(), statements, null, allocator);
            block.set_scope(ast.scope());
            ast.set_body_block(block);
        }
    }
}

fn remove_const_args(
    params: std.ArrayList(*ast_.AST),
    args: *std.ArrayList(*ast_.AST),
) void {
    var param_idx: usize = 0;
    var arg_idx: usize = 0;
    while (param_idx < params.items.len and arg_idx < args.items.len) {
        const param = params.items[param_idx];
        if (param.decl.name.pattern_symbol.kind == .@"const") {
            _ = args.orderedRemove(arg_idx);
            arg_idx -%= 1;
        }
        param_idx += 1;
        arg_idx +%= 1;
    }
}

fn validate_L_Value(ast: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    switch (ast.*) {
        .select, .identifier, .array_value => {},

        .dereference => if (ast.expr().* != .addr_of) {
            try validate_L_Value(ast.expr(), errors);
        },

        .index => try validate_L_Value(ast.lhs(), errors),

        .product => for (ast.children().items) |term| {
            try validate_L_Value(term, errors);
        },

        else => {
            errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "not an l-value" } });
            return error.CompileError;
        },
    }
}

fn assert_mutable(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!void {
    switch (ast.*) {
        .identifier => {
            const symbol = ast.symbol().?;
            if (!std.mem.eql(u8, symbol.name, "_") and symbol.kind != .mut) {
                errors.add_error(errs_.Error{ .modify_immutable = .{ .identifier = ast.token() } });
                return error.CompileError;
            }
        },

        .dereference => {
            const expr_expanded_type = ast.expr().typeof(allocator).expand_identifier();
            try assert_mutable_address(expr_expanded_type, errors);
        },

        .index => {
            const lhs_type = ast.lhs().typeof(allocator);
            if (lhs_type.* == .product and lhs_type.product.was_slice) {
                try assert_mutable_address(lhs_type.children().items[0].child(), errors);
            } else if (lhs_type.* == .addr_of and lhs_type.addr_of.multiptr) {
                try assert_mutable_address(lhs_type, errors);
            } else {
                try assert_mutable(ast.lhs(), errors, allocator);
            }
        },

        .product => for (ast.children().items) |term| {
            try assert_mutable(term, errors, allocator);
        },

        .select => try assert_mutable(ast.lhs(), errors, allocator),

        else => {},
    }
}

fn assert_mutable_address(ast: *Type_AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!ast.addr_of.mut) {
        errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "cannot modify non-mutable address" } });
        return error.CompileError;
    }
}

fn get_expanded_expected(expected: ?*Type_AST, allocator: std.mem.Allocator) ?*Type_AST {
    _ = allocator;
    return if (expected == null) null else expected.?.expand_identifier();
}
