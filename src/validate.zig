const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const interpreter_ = @import("interpreter.zig");
const module_ = @import("module.zig");
const primitives_ = @import("primitives.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const token_ = @import("token.zig");

pub fn validate_module(module: *module_.Module, errors: *errs_.Errors, allocator: std.mem.Allocator) !void { // TODO: Uninfer error
    try validate_scope(module.scope, errors, allocator);
}

fn validate_scope(scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) !void { // TODO: Uninfer error
    for (scope.symbols.keys()) |key| {
        const symbol = scope.symbols.get(key).?;
        try validateSymbol(symbol, errors, allocator);
    }
    for (scope.children.items) |child| {
        try validate_scope(child, errors, allocator);
    }
}

fn validateSymbol(symbol: *symbol_.Symbol, errors: *errs_.Errors, allocator: std.mem.Allocator) error{TypeError}!void {
    if (symbol.validation_state == .valid or symbol.validation_state == .validating) {
        return;
    }
    symbol.validation_state = .validating;

    std.debug.assert(symbol.init.* != .poison);
    // std.debug.print("{s}: {} = {}\n", .{ symbol.name, symbol._type, symbol.init });
    symbol._type = validateAST(symbol._type, primitives_.type_type, errors, allocator);
    if (symbol._type.* != .poison) {
        _ = symbol.assert_valid();
        symbol.expanded_type = symbol._type.expand_type(allocator);
        const expected = if (symbol.kind == .@"fn" or symbol.kind == .@"comptime") symbol._type.rhs() else symbol._type;
        symbol.init = validateAST(symbol.init, expected, errors, allocator);
        if (symbol.init.* == .poison) {
            symbol.validation_state = .invalid;
            return error.TypeError;
            // unreachable;
        } else if ((symbol.kind == .@"fn" or symbol.kind == .@"comptime") and symbol._type.rhs().* == .inferred_error) {
            const terms = symbol._type.rhs().children().*;
            symbol._type.rhs().* = ast_.AST{ .sum = .{ .common = symbol._type.rhs().common().*, ._terms = terms, .from = .@"error" } };
        }
    } else {
        symbol.validation_state = .invalid;
        return error.TypeError;
    }

    // Symbol's name must be capitalized iff its type is Type
    if (symbol.expanded_type != null and !std.mem.eql(u8, symbol.name, "_")) {
        if (type_is_type_type(symbol.expanded_type.?) and !is_capitalized(symbol.name)) {
            errors.addError(errs_.Error{ .symbol_error = .{
                .problem = "of type `Type` must start with an uppercase letter",
                .span = symbol.span,
                .name = symbol.name,
            } });
        } else if (!type_is_type_type(symbol.expanded_type.?) and is_capitalized(symbol.name)) {
            errors.addError(errs_.Error{ .symbol_error = .{
                .problem = "of type other than `Type` must start with a lowercase letter",
                .span = symbol.span,
                .name = symbol.name,
            } });
        }
    }
}

fn type_is_type_type(ast: *ast_.AST) bool {
    return ast.* == .identifier and std.mem.eql(u8, ast.token().data, "Type");
}

fn is_capitalized(name: []const u8) bool {
    return std.ascii.isUpper(name[0]);
}

/// Errors out if `ast` is not the expected type
/// @param expected Should be null if `ast` can be any type
fn validateAST(ast: *ast_.AST, old_expected_type: ?*ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) *ast_.AST {
    var expected_type = old_expected_type;
    if (ast.common().validation_state == .validating) {
        errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "recursive definition detected" } });
        return ast_.poisoned;
    } else if (ast.common().validation_state == .invalid) {
        return ast_.poisoned;
    } else if (ast.common().validation_state == .valid) {
        return ast.common().validation_state.valid.valid_form;
    }
    // std.debug.print("{}: {?}\n", .{ ast, expected });
    ast.common().validation_state = .validating;

    if (expected_type) |_| {
        // expected must be a valid Type type
        std.debug.assert(expected_type.?.* != .poison);
        std.debug.assert(expected_type.?.common().validation_state == .valid);
        var type_expected = expected_type.?.typeof(allocator);
        // std.debug.print("typeof({?}) = {}\n", .{ expected, expected_type });
        std.debug.assert(type_expected.typesMatch(primitives_.type_type));

        if (expected_type.?.* == .annotation) {
            expected_type = expected_type.?.annotation.type;
        }
    }

    var retval = validate_AST_internal(ast, expected_type, errors, allocator) catch {
        return ast.enpoison();
    };

    if (retval.* == .poison) {
        return ast.enpoison();
    } else {
        // Might as well memoize expanded_type
        if (expected_type != null and primitives_.type_type.typesMatch(expected_type.?)) {
            _ = retval.expand_type(allocator);
        }

        ast.common().validation_state = ast_.AST_Validation_State{ .valid = .{ .valid_form = retval } };
        retval.common().validation_state = ast_.AST_Validation_State{ .valid = .{ .valid_form = retval } };
        return retval;
    }
}

fn validate_AST_internal(
    ast: *ast_.AST,
    expected: ?*ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) error{ InterpreterPanic, TypeError, NotAnLValue }!*ast_.AST {
    // std.debug.print("{}\n", .{ast});
    switch (ast.*) {
        .poison => return ast,
        .unit_type => {
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .unit_value => {
            try type_check(ast, primitives_.unit_type, expected, errors);
            return ast;
        },

        .int => {
            try type_check_int(ast, expected, errors);
            return ast;
        },

        .float => {
            try type_check_float(ast, expected, errors);
            return ast;
        },

        .char => {
            try type_check(ast, primitives_.char_type, expected, errors);
            return ast;
        },

        .string => {
            try type_check(ast, primitives_.string_type, expected, errors);
            return ast;
        },

        .identifier => {
            // look up symbol, that's the type
            var symbol = ast.symbol().?;
            if (symbol.validation_state == .invalid) {
                return ast.enpoison();
            }
            try validateSymbol(symbol, errors, allocator);
            if (symbol.validation_state != .valid or symbol._type.common().validation_state != .valid) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "recursive definition detected" } });
                return ast.enpoison();
            }
            try type_check(ast, symbol._type, expected, errors);
            return ast;
        },

        ._true, ._false => {
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },

        .not => {
            ast.set_expr(validateAST(ast.expr(), primitives_.bool_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .negate => {
            ast.set_expr(validateAST(ast.expr(), expected, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check_arithmetic(ast, ast.expr().typeof(allocator), errors);
            try type_check(ast, ast.expr().typeof(allocator), expected, errors);
            return ast;
        },
        .dereference => {
            if (expected != null) {
                const addr_of = ast_.AST.createAddrOf(ast.token(), expected.?, false, std.heap.page_allocator).assert_valid();
                ast.set_expr(validateAST(ast.expr(), addr_of, errors, allocator));
            } else {
                ast.set_expr(validateAST(ast.expr(), null, errors, allocator));
            }
            try assert_none_poisoned(ast.expr());
            const expr_type = ast.expr().typeof(allocator);
            const expanded_expr_type = expr_type.expand_type(allocator);
            if (expanded_expr_type.* != .addrOf) {
                // TODO: Got?
                errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "expected an address" } });
                return ast.enpoison();
            } else {
                return ast;
            }
        },
        ._try => {
            const expr_span = ast.expr().token().span;
            ast.set_expr(validateAST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(ast.expr());
            var expr_expanded_type = ast.expr().typeof(allocator).expand_type(allocator);
            if (expr_expanded_type.* != .sum or expr_expanded_type.sum.from != .@"error") {
                // expr is not even an error type
                // TODO: What type is it?
                errors.addError(errs_.Error{ .basic = .{ .span = expr_span, .msg = "not an error expression" } });
                return ast.enpoison();
            }
            try type_check(ast, expr_expanded_type.get_ok_type().annotation.type, expected, errors);
            const expanded_function_return = ast.symbol().?._type.rhs().expand_type(allocator);
            if (expanded_function_return.* == .inferred_error) {
                // This checks that the `ok` fields match, for free!
                for (expr_expanded_type.children().items) |term| {
                    try add_term(expanded_function_return, term, errors);
                }
            } else if (expanded_function_return.* != .sum or expanded_function_return.sum.from != .@"error") {
                errors.addError(errs_.Error{ .basic = .{
                    .span = ast.token().span,
                    .msg = "enclosing function around try expression does not return an error",
                } });
                return ast.enpoison();
            } else if (!expr_expanded_type.children().items[1].annotation.type.typesMatch(expanded_function_return.children().items[1].annotation.type)) {
                // MASSIVE TODO: Check ALL sum terms, not just the first one
                // expr error union's `.err` member is not a compatible type with the function's error type
                return throw_unexpected_type(expr_span, expr_expanded_type, expanded_function_return, errors);
            }
            return ast;
        },
        .discard => {
            ast.set_expr(validateAST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast, primitives_.unit_type, expected, errors);
            return ast;
        },
        .domainOf => {
            ast.domainOf.sum_expr = validateAST(ast.domainOf.sum_expr, primitives_.type_type, errors, allocator);
            try assert_none_poisoned(ast.domainOf.sum_expr);
            return try domainof(ast.expr(), ast.domainOf.sum_expr, errors, allocator);
        },
        ._typeOf => {
            ast.set_expr(validateAST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast.expr().typeof(allocator);
        },
        .default => {
            ast.set_expr(validateAST(ast.expr(), primitives_.type_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            const ast_type = ast.typeof(allocator);
            try type_check(ast, ast_type, expected, errors);
            return generate_default(ast_type, errors, allocator);
        },
        .sizeOf => {
            ast.set_expr(validateAST(ast.expr(), primitives_.type_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast, primitives_.int_type, expected, errors);
            return ast_.AST.createInt(ast.token(), ast.expr().expand_type(allocator).sizeof(), allocator);
        },
        ._comptime => {
            // Validate symbol
            try validateSymbol(ast.symbol().?, errors, allocator); // ast._comptime.symbol.? is created during symbol tree expansion
            try assert_none_poisoned(ast.symbol().?._type);
            try type_check(ast, ast.symbol().?._type.rhs(), expected, errors);

            // Get the cfg from the symbol, and embed into the module
            const cfg = try module_.get_cfg(ast.symbol().?, null, &ast.symbol().?.scope.module.?.interned_strings, errors, allocator);
            defer cfg.deinit(); // Remove the cfg so that it isn't output

            const idx = ast.symbol().?.scope.module.?.append_instructions(cfg);
            defer ast.symbol().?.scope.module.?.pop_cfg(idx); // Remove the cfg so that it isn't output

            // Create a context and interpret
            const ret_type = ast.symbol().?._type.rhs().expand_type(allocator);
            var context = interpreter_.Context.init(cfg, &ast.symbol().?.scope.module.?.instructions, ret_type, cfg.offset.?);
            try context.interpret();

            // Extract the retval
            return context.extract_ast(0, ret_type, allocator);
        },
        .assign => {
            _ = try binary_operator(ast, null, errors, allocator);
            try validateLValue(ast.lhs(), errors);
            try assertMutable(ast.lhs(), errors, allocator);
            try type_check(ast, primitives_.unit_type, expected, errors);
            return ast;
        },
        ._or, ._and => return try binary_operator_closed(ast, primitives_.bool_type, expected, errors, allocator),
        .add, .sub, .mult, .div => {
            const lhs_type = try binary_operator(ast, expected, errors, allocator);
            try type_check_arithmetic(ast, lhs_type, errors);
            try type_check(ast, lhs_type, expected, errors);
            return ast;
        },
        .mod => {
            const lhs_type = try binary_operator(ast, null, errors, allocator);
            try type_check_integral(ast, lhs_type, errors);
            try type_check(ast, lhs_type, expected, errors);
            return ast;
        },
        .equal, .not_equal => {
            const lhs_type = try binary_operator(ast, null, errors, allocator);
            const expanded_lhs_type = lhs_type.expand_type(allocator);
            if (primitives_.type_type.typesMatch(expanded_lhs_type)) {
                return type_equality_operation(ast, allocator);
            }
            try type_check_eq(ast, lhs_type, errors);
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .greater, .lesser, .greater_equal, .lesser_equal => {
            const lhs_type = try binary_operator(ast, null, errors, allocator);
            try type_check_ord(ast, lhs_type, errors);
            try type_check(ast, primitives_.bool_type, expected, errors);
            return ast;
        },
        .@"catch", .@"orelse" => {
            ast.set_lhs(validateAST(ast.lhs(), null, errors, allocator));
            ast.set_rhs(validateAST(ast.rhs(), expected, errors, allocator));
            try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
            var lhs_expanded_type = ast.lhs().typeof(allocator).expand_type(allocator);
            try coalesce_operator(lhs_expanded_type, ast, errors);
            try type_check(ast, lhs_expanded_type.get_nominal_type().annotation.type, expected, errors);
            return ast;
        },
        .call => {
            ast.set_lhs(validateAST(ast.lhs(), null, errors, allocator));
            try assert_none_poisoned(ast.lhs());
            var lhs_type = ast.lhs().typeof(allocator);
            const expanded_lhs_type = lhs_type.expand_identifier();
            if (expanded_lhs_type.* != .function) {
                // TODO: Emit expanded_lhs_type for user
                errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "call is not to a function" } });
                return ast.enpoison();
            }
            ast.set_children(try default_args(ast.children().*, expanded_lhs_type.lhs(), errors, allocator));
            ast.set_children(try validate_args(ast.children().*, expanded_lhs_type.lhs(), ast.token().span, errors, allocator)); // TODO: Is this compatible with product?
            try type_check(ast, expanded_lhs_type.rhs(), expected, errors);
            return ast;
        },
        .index => { // TODO: TOO LONG!
            const lhs_span = ast.lhs().token().span; // Used for error reporting
            if (expected != null and primitives_.type_type.typesMatch(expected.?)) {
                ast.set_lhs(validateAST(ast.lhs(), primitives_.type_type, errors, allocator));
            } else {
                ast.set_lhs(validateAST(ast.lhs(), null, errors, allocator));
            }
            ast.set_rhs(validateAST(ast.rhs(), primitives_.int_type, errors, allocator));
            try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });

            const lhs_type = ast.lhs().typeof(allocator);
            var lhs_expanded_type = lhs_type.expand_type(allocator);
            lhs_expanded_type = try implicit_dereference(ast, lhs_expanded_type, errors, allocator);

            if (lhs_type.typesMatch(primitives_.type_type) and
                ast.lhs().* == .product and
                ast.rhs().* == .int and ast.lhs().children().items.len > ast.rhs().int.data)
            {
                // Index a product type, resolve immediately
                // TODO: Perhaps add a pattern-index type that's only used by patterns, gauranteed to be infallible
                return ast.lhs().children().items[@as(usize, @intCast(ast.rhs().int.data))];
            } else if (lhs_expanded_type.* != .product) {
                errors.addError(errs_.Error{ .not_indexable = .{ .span = lhs_span, ._type = lhs_expanded_type } });
                return error.TypeError;
            } else if (lhs_expanded_type.* == .product and
                !lhs_expanded_type.product.was_slice and
                !lhs_expanded_type.product.is_homotypical())
            {
                if (ast.rhs().* == .int) {
                    // rhs is compile-time known, change to select
                    const field = ast_.AST.createIdentifier(token_.Token.init("homotypical index", .identifier, "", "", 0, 0), allocator);
                    var select = ast_.AST.createSelect(ast.token(), ast.lhs(), field, allocator).assert_valid();
                    select.set_pos(@as(usize, @intCast(ast.rhs().int.data)));
                    return select;
                } else {
                    // rhs is not int, error
                    errors.addError(errs_.Error{ .basic = .{
                        .span = lhs_span,
                        .msg = "array is not homotypical and index is not compile-time known",
                    } });
                    return ast.enpoison();
                }
            } else if (expected != null) {
                if (lhs_expanded_type.* == .product and !lhs_expanded_type.product.was_slice) {
                    try type_check(ast, lhs_expanded_type.children().items[0], expected, errors);
                } else if (lhs_expanded_type.* == .product and lhs_expanded_type.product.was_slice) {
                    try type_check(ast, lhs_expanded_type.children().items[0].annotation.type.expr(), expected, errors);
                }
            }
            return ast;
        },
        .select => {
            ast.set_lhs(validateAST(ast.lhs(), null, errors, allocator));
            try assert_none_poisoned(ast.lhs());
            var lhs_type = ast.lhs().typeof(allocator);
            const select_lhs_type = try implicit_dereference(ast, lhs_type.expand_type(allocator), errors, allocator);
            if (select_lhs_type.typesMatch(primitives_.type_type) and ast.lhs().expand_type(allocator).* == .sum) {
                // Select on a Type (only valid for a sum type), change to inferred-member
                const inferred_member = ast_.AST.createInferredMember(ast.token(), ast.rhs(), allocator);
                return validateAST(inferred_member, ast.lhs(), errors, allocator);
            } else if (ast.pos() == null) {
                ast.set_pos(try find_select_pos(select_lhs_type, ast.rhs().token().data, ast.token().span, errors));
            }

            _ = ast.assert_valid();
            const ast_type = ast.typeof(allocator);
            try type_check(ast, ast_type, expected, errors);
            return ast;
        },
        .function => return try binary_operator_closed(ast, primitives_.type_type, expected, errors, allocator),
        .sum => {
            for (0..ast.children().items.len) |i| {
                std.debug.assert(ast.children().items[i].* == .annotation); // sums are expanded in sum-expand.zig
                ast.children().items[i] = validateAST(ast.children().items[i], primitives_.type_type, errors, allocator);
            }
            try assert_none_poisoned(ast.children());
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .inferred_error => {
            // Inferred errors are expanded after the node is validated. They should only have one term, the `ok` term
            std.debug.assert(ast.children().items.len == 1);
            ast.children().items[0] = validateAST(ast.children().items[0], primitives_.type_type, errors, allocator);
            try assert_none_poisoned(ast.children().items[0]);
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .inject => {
            if (expected != null and expected.?.* == .inferred_error) {
                ast.lhs().inferredMember.init = validateAST(ast.rhs(), null, errors, allocator);
                ast.set_lhs(validateAST(ast.lhs(), expected, errors, allocator));
                ast.lhs().inferredMember.base = expected;
                try assert_none_poisoned(ast.lhs().inferredMember.base);
                _ = ast.assert_valid();
                return ast.lhs();
            } else {
                const domain = try domainof(ast, expected, errors, allocator);
                try assert_none_poisoned(domain);
                ast.lhs().inferredMember.init = validateAST(ast.rhs(), domain, errors, allocator);
                try assert_none_poisoned(ast.lhs().inferredMember.init.?);
                _ = ast.assert_valid();
                return ast.lhs();
            }
        },

        .product => {
            var expanded_expected: ?*ast_.AST = if (expected == null) null else expected.?.expand_type(allocator);
            if (expanded_expected == null or expanded_expected.?.typesMatch(primitives_.type_type)) {
                // Not expecting anything OR expecting ast to be a product type
                for (0..ast.children().items.len) |i| {
                    ast.children().items[i] = validateAST(ast.children().items[i], expanded_expected, errors, allocator);
                }
            } else if (expanded_expected != null and expanded_expected.?.* == .product) {
                // Expecting ast to be a product value of some product type
                _ = ast.assert_valid();
                ast.set_children(try default_args(ast.children().*, expanded_expected.?, errors, allocator));
                if (expanded_expected.?.children().items.len != ast.children().items.len) {
                    errors.addError(errs_.Error{ .mismatch_tuple_arity = .{
                        .span = ast.token().span,
                        .takes = expanded_expected.?.children().items.len,
                        .given = ast.children().items.len,
                    } });
                    return error.TypeError;
                }
                for (0.., expanded_expected.?.children().items) |i, expected_term| { // Ok, this is cool!
                    ast.children().items[i] = validateAST(ast.children().items[i], expected_term, errors, allocator);
                }
            } else {
                // expecting something that is not a type nor a product!
                // poison `got`, so that it doesn't print anything for the `got` section, wouldn't make sense anyway
                return throw_unexpected_type(ast.token().span, expected.?, ast_.poisoned, errors);
            }
            try assert_none_poisoned(ast.children());
            return ast;
        },
        ._union => {
            // Save spans since lhs and rhs are expanded, need spans for errors
            const lhs_span = ast.lhs().token().span;
            const rhs_span = ast.rhs().token().span;

            var new_ast = try binary_operator_closed(ast, primitives_.type_type, expected, errors, allocator);

            const expand_lhs = new_ast.lhs().expand_type(allocator);
            const expand_rhs = new_ast.rhs().expand_type(allocator);
            if (expand_lhs.* != .sum) {
                errors.addError(errs_.Error{ .basic = .{ .span = lhs_span, .msg = "left hand side of union is not a sum type" } });
                return error.TypeError;
            } else if (expand_rhs.* != .sum) {
                errors.addError(errs_.Error{ .basic = .{ .span = rhs_span, .msg = "right hand side of union is not a sum type" } });
                return error.TypeError;
            }

            return try merge_sums(expand_lhs, expand_rhs, new_ast.token(), errors, allocator);
        },
        .addrOf => {
            if (expected == null) {
                // Not expecting anything, just validate expr
                ast.set_expr(validateAST(ast.expr(), null, errors, allocator));
                try assert_none_poisoned(ast.expr());
                try validateLValue(ast.expr(), errors);
            } else if (primitives_.type_type.typesMatch(expected.?)) {
                // Address type, type of this ast must be a type, inner must be a type
                ast.set_expr(validateAST(ast.expr(), primitives_.type_type, errors, allocator));
                try assert_none_poisoned(ast.expr());
            } else {
                // Address value, expected must be an address, inner must match with expected's inner
                const expanded_expected = expected.?.expand_type(allocator); // Call is memoized
                if (expanded_expected.* != .addrOf) {
                    // Didn't expect an address type. Validate expr and report error
                    return throw_unexpected_type(ast.token().span, expected.?, ast_.poisoned, errors);
                }

                // Everythings Ok.
                ast.set_expr(validateAST(ast.expr(), expanded_expected.expr(), errors, allocator));
                try assert_none_poisoned(ast.expr());
                _ = ast.assert_valid();
                if (ast.expr().* != .product) {
                    // Validate that expr is an L-value *only if* expr is not a product
                    // It is possible to take a addr of a product. The address is the address of the temporary
                    // This is mirrored with a slice_of a product.
                    try validateLValue(ast.expr(), errors);
                }
                if (ast.addrOf.mut) {
                    try assertMutable(ast.expr(), errors, allocator);
                }
            }

            return ast;
        },
        .sliceOf => {
            ast.set_expr(validateAST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(ast.expr());
            var expr_type = ast.expr().typeof(allocator);

            if (expr_type.* != .unit_type and primitives_.type_type.typesMatch(expr_type)) {
                // Regular slice type, change to product of data address and length
                return ast_.AST.create_slice_type(ast.expr(), ast.sliceOf.kind == .mut, allocator);
            } else { // Slice-of value, expected must be an slice, inner must match with expected's inner
                // ast.expr() must be homotypical product type of expected
                if (expr_type.* != .product or !expr_type.product.is_homotypical()) {
                    errors.addError(errs_.Error{ .basic = .{
                        .span = ast.token().span,
                        .msg = "attempt to take slice-of something that is not an array",
                    } });
                    return ast.enpoison();
                }

                _ = ast.assert_valid();
                const ast_type = ast.typeof(allocator);
                try type_check(ast, ast_type, expected, errors);

                if (ast.expr().* != .product) {
                    // Validate that expr is an L-value *only if* expr is not a product
                    // It is possible to take a slice of a product. The slice is the sliceof the temporary
                    // This is mirrored with addr_of a product.
                    try validateLValue(ast.expr(), errors);
                }
                if (ast.sliceOf.kind == .mut) {
                    try assertMutable(ast.expr(), errors, allocator);
                }
                return ast_.AST.create_slice_value(ast.expr(), ast.sliceOf.kind == .mut, expr_type, allocator);
            }
        },
        .arrayOf => {
            ast.set_expr(validateAST(ast.expr(), primitives_.type_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast, primitives_.type_type, expected, errors);

            // Array-of type, type of this ast must be a type, inner must be a type
            ast.arrayOf.len = validateAST(ast.arrayOf.len, primitives_.int_type, errors, allocator);
            try assert_none_poisoned(ast.arrayOf.len);
            if (ast.arrayOf.len.* != .int) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "not integer literal" } });
                return ast.enpoison();
            }
            if (ast.arrayOf.len.int.data <= 0) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "array length is negative" } });
                return ast.enpoison();
            }
            return ast_.AST.create_array_type(ast.arrayOf.len, ast.expr(), allocator);
        },
        .subSlice => {
            ast.subSlice.super = validateAST(ast.subSlice.super, null, errors, allocator);
            ast.subSlice.lower = validateAST(ast.subSlice.lower.?, null, errors, allocator); // lower and upper should exist
            ast.subSlice.upper = validateAST(ast.subSlice.upper.?, null, errors, allocator); // they are set in expand phase
            try assert_none_poisoned(.{ ast.subSlice.super, ast.subSlice.lower, ast.subSlice.upper });
            const super_type = ast.subSlice.super.typeof(allocator);
            if (super_type.* != .product or !super_type.product.was_slice) {
                errors.addError(errs_.Error{ .basic = .{
                    .span = ast.token().span,
                    .msg = "cannot take a sub-slice of something that is not a slice",
                } });
                return error.TypeError;
            }
            return ast;
        },
        .annotation => {
            ast.annotation.type = validateAST(ast.annotation.type, primitives_.type_type, errors, allocator);
            try assert_none_poisoned(.{ast.annotation.type});
            if (ast.annotation.init != null) {
                ast.annotation.init = validateAST(ast.annotation.init.?, ast.annotation.type, errors, allocator);
            }
            try assert_none_poisoned(.{ast.annotation.init});
            try type_check(ast, primitives_.type_type, expected, errors);
            return ast;
        },
        .inferredMember => { // TODO: TOO LONG!
            var expected_expanded: *ast_.AST = undefined;
            if (expected != null) {
                expected_expanded = expected.?.expand_type(allocator);
            }

            if (expected == null) {
                errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "cannot infer the sum type" } });
                return ast.enpoison();
            } else if (expected_expanded.* == .inferred_error) {
                ast.inferredMember.base = expected;
                ast.set_pos(expected_expanded.get_pos(ast.inferredMember.ident.token().data));
                if (ast.pos() == null) {
                    // Wasn't in inferred error set, put in inferred error set
                    const annot_type = if (ast.inferredMember.init == null)
                        primitives_.unit_type
                    else
                        ast.inferredMember.init.?.typeof(allocator);
                    const name = ast_.AST.createIdentifier(ast.inferredMember.ident.token(), allocator);
                    const annot = ast_.AST.createAnnotation(ast.token(), name, annot_type, null, null, allocator);
                    expected_expanded.children().append(annot) catch unreachable;
                    ast.set_pos(expected_expanded.children().items.len - 1);
                }
                return ast;
            } else if (expected_expanded.* != .sum) {
                return throw_unexpected_type(ast.token().span, expected.?, ast_.poisoned, errors);
            } else {
                ast.inferredMember.base = expected;
                ast.set_pos(expected_expanded.get_pos(ast.inferredMember.ident.token().data) orelse {
                    errors.addError(errs_.Error{ .member_not_in = .{
                        .span = ast.token().span,
                        .identifier = ast.inferredMember.ident.token().data,
                        .group_name = "sum",
                    } });
                    return ast.enpoison();
                });
                const proper_term: *ast_.AST = expected_expanded.children().items[ast.pos().?];
                if (proper_term.annotation.init) |_init| {
                    ast.inferredMember.init = _init; // This will be overriden by an inject expression's rhs
                } else {
                    ast.inferredMember.init = try generate_default(proper_term, errors, allocator);
                }
                return ast;
            }
        },
        ._if => { // TODO: TOO LONG!
            if (ast._if.let) |let| {
                ast._if.let = validateAST(let, null, errors, allocator);
            }

            ast._if.condition = validateAST(ast._if.condition, primitives_.bool_type, errors, allocator);
            try assert_none_poisoned(ast._if.condition);

            // expecting a type
            var expected_type: ?*ast_.AST = undefined;
            var expected_expanded: *ast_.AST = undefined;
            if (expected == null) {
                expected_type = null;
            } else {
                expected_expanded = expected.?.expand_type(allocator);
                const is_expected_optional = expected_expanded.* == .sum and expected_expanded.sum.from == .optional;
                if (ast._if.elseBlock != null) {
                    expected_type = expected.?;
                } else if (is_expected_optional) {
                    expected_type = expected_expanded.get_some_type();
                } else {
                    return throw_unexpected_type(ast.token().span, expected.?, ast_.poisoned, errors);
                }
            }

            if (ast._if.condition.* != ._false) {
                ast._if.bodyBlock = validateAST(ast._if.bodyBlock, expected_type, errors, allocator);
            }

            if (ast._if.elseBlock != null and ast._if.condition.* != ._true) {
                ast._if.elseBlock = validateAST(ast._if.elseBlock.?, expected_type, errors, allocator);
            }

            try assert_none_poisoned(.{ ast._if.let, ast._if.bodyBlock, ast._if.elseBlock });

            if (ast._if.condition.* == ._true and ast._if.elseBlock != null) {
                // condition is true and theres an else => return {let; body}
                if (ast._if.let != null) {
                    ast._if.bodyBlock.children().insert(0, ast._if.let.?) catch unreachable;
                }
                return ast._if.bodyBlock;
            } else if (ast._if.condition.* == ._true and ast._if.elseBlock == null) {
                // condition is true and theres no else => return {let; some(body)}
                if (ast._if.let != null) {
                    ast._if.bodyBlock.children().insert(0, ast._if.let.?) catch unreachable;
                }
                const opt_type = ast_.AST.create_optional_type(ast._if.bodyBlock.typeof(allocator), allocator);
                return ast_.AST.create_some_value(opt_type, ast._if.bodyBlock, allocator);
            } else if (ast._if.condition.* == ._false and ast._if.elseBlock != null) {
                // condition is false and theres an else => return {let; else}
                if (ast._if.let != null) {
                    ast._if.elseBlock.?.children().insert(0, ast._if.let.?) catch unreachable;
                }
                return ast._if.elseBlock.?;
            } else if (ast._if.condition.* == ._false and ast._if.elseBlock == null) {
                // condition is false and theres no else => return {let; none()}
                const opt_type = ast_.AST.create_optional_type(ast._if.bodyBlock.typeof(allocator), allocator);
                var statements = std.ArrayList(*ast_.AST).init(allocator);
                if (ast._if.let != null) {
                    statements.append(ast._if.let.?) catch unreachable;
                }
                statements.append(ast_.AST.create_none_value(opt_type, allocator)) catch unreachable;
                const ret_block = ast_.AST.createBlock(token_.Token.init_simple("{"), statements, null, allocator);
                ret_block.block.scope = ast._if.scope.?.parent.?;
                return ret_block;
            } else {
                // condition is undeterminable at compile-time, return if AST
                return ast;
            }
        },
        .match => { // TODO: TOO LONG!
            if (ast.match.let != null) {
                ast.match.let = validateAST(ast.match.let.?, null, errors, allocator);
            }
            ast.set_expr(validateAST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(.{ ast.match.let, ast.expr() });

            const expr_type_expanded = ast.expr().typeof(allocator).expand_type(allocator);
            try assert_none_poisoned(expr_type_expanded);

            var expected_expanded = if (expected != null) expected.?.expand_type(allocator) else null;
            for (0..ast.children().items.len) |i| {
                if (expected == null or ast.match.has_else) {
                    // either not expecting anything, OR match has `else` => validate regular expected type
                    ast.children().items[i] = validateAST(ast.children().items[i], expected, errors, allocator);
                } else if (expected_expanded != null and expected_expanded.?.* == .sum and expected_expanded.?.sum.from == .optional) {
                    // match has no `else`, expecting an optional type => validate mappings w/ base of optional expected type
                    ast.children().items[i] = validateAST(ast.children().items[i], expected_expanded.?.get_some_type(), errors, allocator);
                } else {
                    // match has no else, not expecting an optional type => type error
                    // TODO: Include all that ^ in the error message (without having to asser_valid()!), because this is kinda confusing
                    // TODO: Matches should have to be exhaustive, so they would never return none :-)
                    return throw_unexpected_type(ast.token().span, expected.?, ast_.poisoned, errors);
                }
                if (ast.children().items[i].mapping_lhs()) |lhs| {
                    try assert_pattern_matches(lhs, expr_type_expanded, errors, allocator);
                }
            }
            try assert_none_poisoned(ast.children());
            try exhaustive_check(expr_type_expanded, ast.children(), ast.token().span, errors, allocator);
            return ast;
        },
        .mapping => {
            // lhs for match mappings must be done elsewhere
            ast.set_rhs(validateAST(ast.rhs(), expected, errors, allocator));
            try assert_none_poisoned(.{ ast.mapping_lhs(), ast.rhs() });
            return ast;
        },
        ._while => {
            if (ast._while.let) |let| {
                ast._while.let = validateAST(let, null, errors, allocator);
            }
            if (ast._while.post) |post| {
                ast._while.post = validateAST(post, null, errors, allocator);
            }
            ast._while.condition = validateAST(ast._while.condition, primitives_.bool_type, errors, allocator);

            var optional_type = false; //< Set if expected is an optional type
            if (expected != null) {
                var expected_expanded = expected.?.expand_type(allocator);
                if (expected_expanded.* == .sum and expected_expanded.sum.from == .optional) {
                    ast._while.bodyBlock = validateAST(ast._while.bodyBlock, expected_expanded.get_some_type(), errors, allocator);
                    optional_type = true;
                }
            }
            if (!optional_type) {
                ast._while.bodyBlock = validateAST(ast._while.bodyBlock, expected, errors, allocator);
                if (ast._while.elseBlock) |elseBlock| {
                    ast._while.elseBlock = validateAST(elseBlock, expected, errors, allocator);
                }
            }
            try assert_none_poisoned(.{ ast._while.let, ast._while.post, ast._while.condition, ast._while.bodyBlock, ast._while.elseBlock });
            return ast;
        },
        .block => {
            for (0..ast.children().items.len) |i| {
                const expect_type: ?*ast_.AST = if (ast.block.final == null and i == ast.children().items.len - 1) expected else null;
                ast.children().items[i] = validateAST(ast.children().items[i], expect_type, errors, allocator);
            }
            try assert_none_poisoned(ast.children());
            if (ast.block.final) |final| {
                ast.block.final = validateAST(final, expected, errors, allocator);
                try assert_none_poisoned(ast.block.final);
            } else {
                _ = ast.assert_valid();
                try type_check(ast, ast.typeof(allocator), expected, errors);
            }
            return ast;
        },

        ._break, ._continue, ._unreachable => {
            try void_check(ast, expected, errors);
            return ast;
        },
        ._return => {
            if (ast._return._ret_expr) |expr| {
                ast._return._ret_expr = validateAST(expr, ast.symbol().?._type.rhs(), errors, allocator);
                try assert_none_poisoned(ast._return._ret_expr);
            } else if (expected != null and (expected.?.expand_type(allocator)).* != .unit_type) {
                return throw_unexpected_type(ast.token().span, expected.?, primitives_.void_type, errors);
            }
            return ast;
        },
        ._defer, ._errdefer => {
            ast.set_statement(validateAST(ast.statement(), null, errors, allocator));
            try assert_none_poisoned(ast.statement());
            try void_check(ast, expected, errors);
            return ast;
        },
        .fnDecl => {
            try validateSymbol(ast.symbol().?, errors, allocator);
            try assert_none_poisoned(ast.symbol().?._type);
            if (expected) |_expected| {
                const expected_expanded = _expected.expand_type(allocator);
                const self_type = ast.typeof(allocator);
                try type_check(ast, self_type, expected_expanded, errors);
            }
            return ast;
        },
        .decl => {
            ast.decl.type = validateAST(ast.decl.type, primitives_.type_type, errors, allocator);
            try assert_none_poisoned(ast.decl.type);
            ast.decl.init = validateAST(ast.decl.init, ast.decl.type, errors, allocator);
            try assert_none_poisoned(ast.decl.init);
            for (ast.decl.symbols.items) |symbol| {
                try validateSymbol(symbol, errors, allocator);
            }
            try type_check(ast, primitives_.unit_type, expected, errors);
            return ast;
        },
        else => {
            std.debug.print("validateAST() unimplemented for {s}\n", .{@tagName(ast.*)});
            unreachable;
        },
    }
}

fn type_check(ast: *ast_.AST, got: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (expected != null and !got.typesMatch(expected.?)) {
        return throw_unexpected_type(ast.token().span, expected.?, got, errors);
    }
}

fn void_check(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (expected != null and primitives_.type_type.typesMatch(expected.?)) {
        // TODO: This check won't be necessary after first-class-types, as values will need to be known at compile-time.
        return throw_unexpected_type(ast.token().span, expected.?, primitives_.void_type, errors);
    }
}

fn type_check_int(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (expected != null and !expected.?.can_represent_integer(ast.int.data)) {
        // TODO: Add emit a separate error if not representable because the value doesn't fit, vs because it's not an integer primitive type at all
        return throw_unexpected_type(ast.token().span, expected.?, primitives_.int_type, errors);
    }
    ast.set_represents(expected orelse primitives_.int_type);
}

fn type_check_float(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (expected != null and !expected.?.can_represent_float()) {
        return throw_unexpected_type(ast.token().span, expected.?, primitives_.float_type, errors);
    }
    ast.set_represents(expected orelse primitives_.float_type);
}

fn type_check_eq(ast: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (!got.is_eq_type()) {
        errors.addError(errs_.Error{ .expected_builtin_typeclass = .{ .span = ast.token().span, .expected = "equalable", .got = got } });
        return error.TypeError;
    }
}

fn type_check_ord(ast: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (!got.is_ord_type()) {
        errors.addError(errs_.Error{ .expected_builtin_typeclass = .{ .span = ast.token().span, .expected = "orderable", .got = got } });
        return error.TypeError;
    }
}

fn type_check_arithmetic(ast: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (!got.is_num_type()) {
        errors.addError(errs_.Error{ .expected_builtin_typeclass = .{ .span = ast.token().span, .expected = "arithmetic", .got = got } });
        return error.TypeError;
    }
}

fn type_check_integral(ast: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (!got.is_int_type()) {
        errors.addError(errs_.Error{ .expected_builtin_typeclass = .{ .span = ast.token().span, .expected = "integral", .got = got } });
        return error.TypeError;
    }
}

fn throw_unexpected_type(span: span_.Span, expected: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) error{TypeError} {
    errors.addError(errs_.Error{ .unexpected_type = .{ .span = span, .expected = expected, .got = got } });
    return error.TypeError;
}

fn throw_not_selectable(span: span_.Span, errors: *errs_.Errors) error{TypeError} {
    errors.addError(errs_.Error{ .basic = .{ .span = span, .msg = "left-hand-side of select is not selectable" } });
    return error.TypeError;
}

fn assert_none_poisoned(value: anytype) !void { // TODO: Uninfer error
    // This entire function is cursed...
    const T = @TypeOf(value);
    if (T == *std.ArrayList(*ast_.AST)) {
        for (value.items) |ast| {
            if (ast.* == .poison) {
                return error.TypeError;
            }
        }
    } else switch (@typeInfo(T)) {
        .Struct => |info| {
            inline for (info.fields) |f| {
                try assert_none_poisoned(@field(value, f.name));
            }
        },
        .Optional => if (value != null and value.?.* == .poison) return error.TypeError,
        .Pointer => if (value.* == .poison) return error.TypeError,
        else => {},
    }
}

fn type_equality_operation(ast: *ast_.AST, allocator: std.mem.Allocator) !*ast_.AST { // TODO: Uninfer error
    std.debug.assert(ast.* == .equal or ast.* == .not_equal);
    const _true = ast_.AST.createTrue(ast.token(), allocator);
    const _false = ast_.AST.createFalse(ast.token(), allocator);
    if (ast.lhs().typesMatch(ast.rhs()) and ast.rhs().typesMatch(ast.lhs())) {
        return if (ast.* == .equal) _true else _false;
    } else {
        return if (ast.* == .equal) _false else _true;
    }
}

/// Validates a polymorphic binary operator
fn binary_operator(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST { // TODO: Uninfer error
    ast.set_lhs(validateAST(ast.lhs(), expected, errors, allocator));
    const lhs_type = ast.lhs().typeof(allocator);
    try assert_none_poisoned(lhs_type);
    ast.set_rhs(validateAST(ast.rhs(), lhs_type, errors, allocator));
    try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
    return lhs_type;
}

/// Validates a closed binary operator
fn binary_operator_closed(
    ast: *ast_.AST,
    self_type: *ast_.AST,
    expected: ?*ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !*ast_.AST { // TODO: Uninfer error
    ast.set_lhs(validateAST(ast.lhs(), self_type, errors, allocator));
    ast.set_rhs(validateAST(ast.rhs(), self_type, errors, allocator));
    try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
    try type_check(ast, self_type, expected, errors);
    return ast;
}

fn coalesce_operator(lhs_expanded_type: *ast_.AST, ast: *ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    std.debug.assert(ast.* == .@"orelse" or ast.* == .@"catch");
    const expected: ast_.Sum_From = if (ast.* == .@"orelse") .optional else .@"error";
    if (lhs_expanded_type.* != .sum or lhs_expanded_type.sum.from != expected) {
        // TODO: What type is it?
        errors.addError(errs_.Error{ .wrong_coalesce_from = .{
            .span = ast.lhs().token().span,
            .operator = @tagName(ast.*),
            .from = @tagName(expected),
        } });
        return error.TypeError;
    }
}

fn default_args(
    asts: std.ArrayList(*ast_.AST),
    expected: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !std.ArrayList(*ast_.AST) { // TODO: Uninfer error
    if (try args_are_named(asts, errors)) {
        return named_args(asts, expected, errors, allocator) catch |err| switch (err) {
            error.NoDefault => asts,
            error.TypeError => error.TypeError,
        };
    } else {
        return positional_args(asts, expected, allocator) catch |err| switch (err) {
            error.NoDefault => asts,
        };
    }
}

fn args_are_named(asts: std.ArrayList(*ast_.AST), errors: *errs_.Errors) !bool { // TODO: Uninfer error
    if (asts.items.len == 0) {
        return false;
    }

    var seen_named = false;
    var seen_pos = false;
    for (asts.items) |term| {
        if (term.* == .assign) {
            seen_named = true;
        } else {
            seen_pos = true;
        }
    }
    std.debug.assert(seen_named or seen_pos);
    if (seen_named and seen_pos) {
        errors.addError(errs_.Error{ .basic = .{
            .span = asts.items[0].token().span,
            .msg = "mixed positional and named arguments are not allowed",
        } });
        return error.TypeError;
    } else {
        return seen_named;
    }
}

fn positional_args(asts: std.ArrayList(*ast_.AST), expected: *ast_.AST, allocator: std.mem.Allocator) !std.ArrayList(*ast_.AST) { // TODO: Uninfer error
    var retval = std.ArrayList(*ast_.AST).init(allocator);
    errdefer retval.deinit();

    switch (expected.*) {
        .annotation => {
            if (asts.items.len == 0 and expected.annotation.init != null) {
                retval.append(expected.annotation.init.?) catch unreachable;
            } else if (asts.items.len > 0) {
                for (asts.items) |item| {
                    retval.append(item) catch unreachable;
                }
            } else {
                return error.NoDefault;
            }
        },

        .product => {
            for (expected.children().items, 0..) |term, i| {
                // ast is product, append ast's corresponding term
                if (asts.items.len > 1 and i < asts.items.len) {
                    retval.append(asts.items[i]) catch unreachable;
                }
                // ast is unit or ast isn't a product and i > 0 or ast is a product and off the edge of ast's terms
                // try to fill with the default
                else if (asts.items.len == 0 or (asts.items.len <= 1 and i > 0) or (asts.items.len > 1 and i >= asts.items.len)) {
                    if (term.* == .annotation and term.annotation.init != null) {
                        retval.append(term.annotation.init.?) catch unreachable;
                    } else {
                        return error.NoDefault;
                    }
                }
                // ast is not product, i != 0, append ast as first term
                else {
                    retval.append(asts.items[0]) catch unreachable;
                }
            }
        },

        .unit_type, .identifier => retval = asts,

        else => {
            std.debug.print("unimplemented for {s}\n", .{@tagName(expected.*)});
            unreachable;
        },
    }
    return retval;
}

fn named_args(
    asts: std.ArrayList(*ast_.AST),
    expected: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !std.ArrayList(*ast_.AST) { // TODO: Uninfer error
    std.debug.assert(asts.items.len > 0);
    // Maps assign.lhs name to assign.rhs
    var arg_map = std.StringArrayHashMap(*ast_.AST).init(allocator);
    defer arg_map.deinit();

    // Associate argument names with their values
    if (asts.items.len == 1) {
        putAssign(asts.items[0], &arg_map, errors) catch |err| switch (err) {
            error.TypeError => return error.NoDefault,
            else => return err,
        };
    } else {
        for (asts.items) |term| {
            putAssign(term, &arg_map, errors) catch |err| switch (err) {
                error.TypeError => return error.NoDefault,
                else => return err,
            };
        }
    }

    // Construct positional args in the order specified by `expected`
    var retval = std.ArrayList(*ast_.AST).init(allocator);
    errdefer retval.deinit();
    var new_expected = expected;
    if (expected.* == .annotation and (expected.annotation.type.expand_type(allocator)).* == .product) {
        new_expected = expected.annotation.type.expand_type(allocator);
    }
    switch (new_expected.*) {
        .annotation => {
            if (arg_map.keys().len != 1) { // Cannot be 0, since that is technically a positional arglist
                errors.addError(errs_.Error{ .basic = .{
                    .span = asts.items[0].token().span,
                    .msg = "too many arguments/fields specifed",
                } });
                // return error.NoDefault;
                unreachable;
            } else {
                retval.append(arg_map.values()[0]) catch unreachable;
            }
        },

        .product => {
            for (new_expected.children().items) |term| {
                if (term.* != .annotation) {
                    errors.addError(errs_.Error{ .basic = .{
                        .span = asts.items[0].token().span,
                        .msg = "expected type does not accept named arugments",
                    } });
                    return error.NoDefault;
                }
                const arg = arg_map.get(term.annotation.pattern.token().data);
                if (arg == null) {
                    if (term.annotation.init != null) {
                        retval.append(term.annotation.init.?) catch unreachable;
                    } else {
                        errors.addError(errs_.Error{ .basic = .{
                            .span = asts.items[0].token().span,
                            .msg = "not all arguments are specified",
                        } });
                        return error.NoDefault;
                    }
                } else {
                    retval.append(arg.?) catch unreachable;
                }
            }
        },

        else => unreachable,
    }
    return retval;
}

fn validate_args(
    args: std.ArrayList(*ast_.AST),
    expected: *ast_.AST,
    span: span_.Span,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !std.ArrayList(*ast_.AST) { // TODO: Uninfer error
    var new_args = std.ArrayList(*ast_.AST).init(allocator);
    errdefer new_args.deinit();
    var changed = false;
    var poisoned = false;
    if (expected.* == .unit_type) {
        if (args.items.len > 0) {
            errors.addError(errs_.Error{ .mismatch_call_arity = .{ .span = span, .takes = 0, .given = args.items.len } });
            return error.TypeError;
        }
    } else if (expected.* == .product) {
        if (args.items.len != expected.children().items.len) {
            errors.addError(errs_.Error{ .mismatch_call_arity = .{
                .span = span,
                .takes = expected.children().items.len,
                .given = args.items.len,
            } });
            return error.TypeError;
        }
        for (expected.children().items, args.items) |param_type, arg| {
            const new_arg = validateAST(arg, param_type, errors, allocator);
            changed = changed or new_arg != arg;
            new_args.append(new_arg) catch unreachable;
            if (new_arg.* == .poison) {
                poisoned = true;
            }
        }
    } else {
        if (args.items.len != 1) {
            errors.addError(errs_.Error{ .mismatch_call_arity = .{ .span = span, .takes = 1, .given = args.items.len } });
            return error.TypeError;
        }

        args.items[0] = validateAST(args.items[0], expected, errors, allocator);
    }
    if (poisoned) {
        return error.TypeError;
    } else if (changed) {
        return new_args;
    } else {
        new_args.deinit();
        return args;
    }
}

fn putAssign(ast: *ast_.AST, arg_map: *std.StringArrayHashMap(*ast_.AST), errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (ast.lhs().* != .inferredMember) {
        errors.addError(errs_.Error{ .expected_basic_token = .{ .expected = "an inferred member", .got = ast.lhs().token() } });
        return error.TypeError;
    }
    try put_ast_map(ast.rhs(), ast.lhs().inferredMember.ident.token().data, ast.token().span, arg_map, errors);
}

fn merge_sums(lhs: *ast_.AST, rhs: *ast_.AST, token: token_.Token, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST { // TODO: Uninfer error
    var new_terms = std.ArrayList(*ast_.AST).init(allocator);
    var names = std.StringArrayHashMap(*ast_.AST).init(allocator);
    defer names.deinit();

    try put_many_annot_map(lhs.children(), &new_terms, &names, errors);
    try put_many_annot_map(rhs.children(), &new_terms, &names, errors);

    const retval = ast_.AST.createSum(token, new_terms, allocator);
    retval.sum.from = lhs.sum.from; // TODO: Assert that lhs from and rhs from are the same (or at least aren't optional and error)
    return retval;
}

fn put_many_annot_map(
    asts: *std.ArrayList(*ast_.AST),
    new_terms: *std.ArrayList(*ast_.AST),
    map: *std.StringArrayHashMap(*ast_.AST),
    errors: *errs_.Errors,
) !void { // TODO: Uninfer error
    for (asts.items) |term| {
        try put_ast_map(term.annotation.type, term.annotation.pattern.token().data, term.token().span, map, errors);
        new_terms.append(term) catch unreachable;
    }
}

/// Puts an ast into a String->AST map, if a given name isn't already in the map.
fn put_ast_map(ast: *ast_.AST, name: []const u8, span: span_.Span, map: *std.StringArrayHashMap(*ast_.AST), errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (map.get(name)) |_| {
        // TODO: What is the name?
        errors.addError(errs_.Error{ .basic = .{ .span = span, .msg = "duplicate identifier" } });
        return error.TypeError;
    } else {
        map.put(name, ast) catch unreachable;
    }
}

fn validateLValue(ast: *ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    switch (ast.*) {
        .identifier => {},

        .dereference => if (ast.expr().* != .addrOf) {
            try validateLValue(ast.expr(), errors);
        },

        .index, .select => try validateLValue(ast.lhs(), errors),

        .product => for (ast.children().items) |term| {
            try validateLValue(term, errors);
        },

        else => {
            errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "not an l-value" } });
            return error.TypeError;
        },
    }
}

fn assertMutable(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !void { // TODO: Uninfer error
    switch (ast.*) {
        .identifier => {
            const symbol = ast.symbol().?;
            if (!std.mem.eql(u8, symbol.name, "_") and symbol.kind != .mut) {
                errors.addError(errs_.Error{ .modify_immutable = .{ .identifier = ast.token() } });
                return error.TypeError;
            }
        },

        .dereference => try assert_mutable_address(ast.expr().typeof(allocator), errors),

        .index => {
            const lhs_type = ast.lhs().typeof(allocator);
            if (lhs_type.* == .product and lhs_type.product.was_slice) {
                try assert_mutable_address(lhs_type.children().items[0].annotation.type, errors);
            } else {
                try assertMutable(ast.lhs(), errors, allocator);
            }
        },

        .product => for (ast.children().items) |term| {
            try assertMutable(term, errors, allocator);
        },

        .select => try assertMutable(ast.lhs(), errors, allocator),

        else => unreachable,
    }
}

fn assert_mutable_address(ast: *ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    if (!ast.addrOf.mut) {
        errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "cannot modify non-mutable address" } });
        return error.TypeError;
    }
}

fn implicit_dereference(ast: *ast_.AST, old_lhs_type: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST { // TODO: Uninfer error
    var lhs_type = old_lhs_type;
    if (lhs_type.* == .addrOf) {
        ast.set_lhs(validateAST(ast_.AST.createDereference(ast.token(), ast.lhs(), allocator), null, errors, allocator));
        lhs_type = ast.lhs().typeof(allocator).expand_type(allocator);
    }
    try assert_none_poisoned(.{ ast.lhs(), lhs_type });
    return lhs_type;
}

fn find_select_pos(_type: *ast_.AST, field: []const u8, span: span_.Span, errors: *errs_.Errors) !usize { // TODO: Uninfer error
    if (_type.* != .product and _type.* != .sum and _type.* != .inferred_error) {
        return throw_not_selectable(span, errors);
    }
    for (_type.children().items, 0..) |term, i| {
        if (term.* != .annotation) {
            return throw_not_selectable(span, errors);
        }
        if (std.mem.eql(u8, term.annotation.pattern.token().data, field)) {
            return i;
        }
    } else {
        errors.addError(errs_.Error{ .member_not_in = .{ .span = span, .identifier = field, .group_name = "tuple" } });
        return error.TypeError;
    }
}

/// Validates that `pattern` is valid given a match's `expr`
fn assert_pattern_matches(pattern: *ast_.AST, expr_type: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !void { // TODO: Uninfer error
    switch (pattern.*) {
        .unit_value => try type_check(pattern, primitives_.unit_type, expr_type, errors),
        .int => try type_check_int(pattern, expr_type, errors),
        .char => try type_check(pattern, primitives_.char_type, expr_type, errors),
        .string => try type_check(pattern, primitives_.string_type, expr_type, errors),
        .float => try type_check_float(pattern, expr_type, errors),
        ._true, ._false => try type_check(pattern, primitives_.bool_type, expr_type, errors),
        .block => {
            const new_pattern = validateAST(pattern, expr_type, errors, allocator);
            try assert_none_poisoned(new_pattern);
            try type_check(pattern, new_pattern.typeof(allocator), expr_type, errors);
        },
        .select, .inferredMember => {
            var new_pattern = validateAST(pattern, expr_type, errors, allocator);
            try assert_none_poisoned(new_pattern);
            pattern.set_pos(new_pattern.pos().?);
            try type_check(pattern, new_pattern.typeof(allocator), expr_type, errors);
        },
        .inject => {
            const domain = try domainof(pattern, expr_type, errors, allocator);
            try assert_none_poisoned(domain);
            pattern.inject.domain = domain;
            try assert_pattern_matches(pattern.rhs(), domain, errors, allocator);
        },
        .product => {
            const expanded_expr = expr_type.expand_type(allocator);
            if (expanded_expr.* != .product or expanded_expr.children().items.len != pattern.children().items.len) {
                return throw_unexpected_type(pattern.token().span, expr_type, pattern.typeof(allocator), errors);
            }
            for (pattern.children().items, expanded_expr.children().items) |term, expanded_term| {
                try assert_pattern_matches(term, expanded_term, errors, allocator);
            }
        },
        .pattern_symbol => {},
        else => {
            std.debug.print("unimplemented assert_pattern_matches() for {s}\n", .{@tagName(pattern.*)});
            unreachable;
        },
    }
    _ = pattern.assert_valid();
}

fn exhaustive_check(
    _type: *ast_.AST,
    mappings: *std.ArrayList(*ast_.AST),
    match_span: span_.Span,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) !void { // TODO: Uninfer error
    if (_type.* == .sum) {
        var ids = std.ArrayList(usize).init(allocator);
        defer ids.deinit();

        for (_type.children().items, 0..) |_, i| {
            ids.append(i) catch unreachable;
        }
        for (mappings.items) |m| {
            if (m.mapping_lhs() == null) {
                continue;
            }
            exhaustive_check_sub(m.mapping_lhs().?, &ids);
        }
        if (ids.items.len > 0) {
            var forgotten = std.ArrayList(*ast_.AST).init(std.heap.page_allocator); // Not deallocated, lives until error emission
            for (ids.items) |id| {
                forgotten.append(_type.children().items[id]) catch unreachable;
            }
            errors.addError(errs_.Error{ .non_exhaustive_sum = .{ .span = match_span, .forgotten = forgotten } });
            return error.TypeError;
        }
    }
}

fn exhaustive_check_sub(ast: *ast_.AST, ids: *std.ArrayList(usize)) void {
    switch (ast.*) {
        .select, .inferredMember => {
            for (ids.items, 0..) |item, i| {
                if (item == ast.pos().?) {
                    _ = ids.swapRemove(i);
                    break;
                }
            }
        },
        .inject => exhaustive_check_sub(ast.lhs(), ids),
        .pattern_symbol => ids.clearRetainingCapacity(),
        else => {},
    }
}

/// Adds a term to an inferred error
fn add_term(ast: *ast_.AST, addend: *ast_.AST, errors: *errs_.Errors) !void { // TODO: Uninfer error
    std.debug.assert(addend.* == .annotation);
    for (ast.children().items) |term| {
        if (std.mem.eql(u8, term.annotation.pattern.token().data, addend.annotation.pattern.token().data)) {
            if (!term.annotation.type.typesMatch(term)) {
                errors.addError(errs_.Error{ .sum_duplicate = .{
                    .span = ast.token().span,
                    .identifier = term.annotation.pattern.token().data,
                    .first = term.token().span,
                } });
                return error.TypeError;
            } else {
                // Duplicate found, types match. OK!
                return;
            }
        }
    }
    // No duplicate found, add to inferred error set
    ast.children().append(addend) catch unreachable;
}

fn generate_default(_type: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST { // TODO: Uninfer error
    return (try generate_default_unvalidated(_type, errors, allocator)).assert_valid();
}

fn generate_default_unvalidated(_type: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) error{TypeError}!*ast_.AST {
    switch (_type.*) {
        .identifier => {
            const expanded_type = _type.expand_type(allocator);
            if (expanded_type == _type) {
                const primitive_info = primitives_.get(_type.token().data);
                if (primitive_info.default_value != null) {
                    return primitive_info.default_value.?;
                } else {
                    errors.addError(errs_.Error{ .no_default = .{ .span = _type.token().span, ._type = _type } });
                    return error.TypeError;
                }
            } else {
                return try generate_default(expanded_type, errors, allocator);
            }
        },
        .addrOf, .function => return ast_.AST.createInt(_type.token(), 0, allocator),
        .unit_type => return ast_.AST.createUnitValue(_type.token(), allocator),
        .sum => {
            const identifier = ast_.AST.createIdentifier(token_.Token.init("default lmao", .identifier, "", "", 0, 0), allocator);
            var retval = ast_.AST.createInferredMember(_type.token(), identifier, allocator);
            if (_type.sum.from == .optional) {
                retval.set_pos(1);
            } else {
                retval.set_pos(0);
            }
            retval.inferredMember.base = _type;
            const proper_term: *ast_.AST = _type.children().items[0];
            retval.inferredMember.init = try generate_default(proper_term, errors, allocator);
            return retval;
        },
        .product => {
            var value_terms = std.ArrayList(*ast_.AST).init(allocator);
            errdefer value_terms.deinit();
            for (_type.children().items) |term| {
                const default_term = try generate_default(term, errors, allocator);
                value_terms.append(default_term) catch unreachable;
            }
            return ast_.AST.createProduct(_type.token(), value_terms, allocator);
        },
        .annotation => if (_type.annotation.init != null) {
            return _type.annotation.init.?;
        } else {
            return generate_default(_type.annotation.type, errors, allocator);
        },
        else => {
            std.debug.print("Unimplemented generate_default() for: AST.{s}\n", .{@tagName(_type.*)});
            unreachable;
        },
    }
}

// Takes in an inject AST (pattern or expr) of the form `lhs <- rhs` and returns the type that `rhs` should be.
// Also validates the inject ast_.AST. Thus, if `lhs` is an inferred member, it will find out the sum type it belongs to.
fn domainof(ast: *ast_.AST, sum_type: ?*ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) !*ast_.AST { // TODO: Uninfer error
    if (ast.lhs().* == .inferredMember) {
        // Pass sum_type so that base can be inferred call
        ast.set_lhs(validateAST(ast.lhs(), sum_type, errors, allocator));
    } else {
        ast.set_lhs(validateAST(ast.lhs(), null, errors, allocator));
    }
    try assert_none_poisoned(ast.lhs());
    var lhs_type = ast.lhs().typeof(allocator);
    const expanded_lhs_type = lhs_type.expand_type(allocator);
    if (expanded_lhs_type.* == .sum and ast.lhs().* == .inferredMember) {
        if (sum_type != null and !sum_type.?.typesMatch(lhs_type)) {
            return throw_unexpected_type(ast.token().span, sum_type.?, ast.lhs().inferredMember.base.?, errors);
        }
        const pos: usize = ast.lhs().pos().?;
        const proper_term: *ast_.AST = (ast.lhs().typeof(allocator)).children().items[pos];
        return proper_term.annotation.type;
    } else {
        errors.addError(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "inject is not to a sum" } });
        return ast_.poisoned;
    }
}
