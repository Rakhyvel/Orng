// This file validates a module of ASTs. It primarily is responsible for type-checking.

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

const Validate_Error_Enum = error{TypeError};

const Validate_Args_Thing = enum {
    function,
    method,
    product,

    fn name(self: @This()) []const u8 {
        return @tagName(self);
    }

    fn takes_name(self: @This()) []const u8 {
        return switch (self) {
            .function, .method => "parameter",
            .product => "field",
        };
    }

    fn given_name(self: @This()) []const u8 {
        return switch (self) {
            .function, .method => "argument",
            .product => "value",
        };
    }
};

pub fn validate_module(module: *module_.Module, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!void {
    try validate_scope(module.scope, errors, allocator);
}

pub fn validate_scope(scope: *symbol_.Scope, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!void {
    for (scope.symbols.keys()) |key| {
        const symbol = scope.symbols.get(key).?;
        try validate_symbol(symbol, errors, allocator);
    }
    for (scope.children.items) |child| {
        try validate_scope(child, errors, allocator);
    }
    for (scope.impls.items) |impl| {
        try validate_impl(impl, errors, allocator);
    }
}

pub fn validate_symbol(symbol: *symbol_.Symbol, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!void {
    if (symbol.validation_state == .valid or symbol.validation_state == .validating) {
        return;
    }
    symbol.validation_state = .validating;

    // std.debug.assert(symbol.init.* != .poison);
    // std.debug.print("validating type for: {s}\n", .{symbol.name});
    symbol._type = validate_AST(symbol._type, primitives_.type_type, errors, allocator);
    // std.debug.print("type for: {s}: {}\n", .{ symbol.name, symbol._type });
    if (symbol._type.* != .poison) {
        _ = symbol.assert_valid();
        symbol.expanded_type = symbol._type.expand_type(allocator);
        if (type_is_type_type(symbol.expanded_type.?) and symbol.kind == .let) {
            errors.add_error(errs_.Error{ .basic = .{
                .span = symbol.span,
                .msg = "non-constant variable with `Type` type",
            } });
            symbol.validation_state = .invalid;
            return error.TypeError;
        }
        const expected: ?*ast_.AST = if (symbol.kind == .@"fn" or symbol.kind == .@"comptime") symbol._type.rhs() else symbol._type;
        // std.debug.print("validating init for: {s}\n", .{symbol.name});
        if (symbol.init) |init| {
            // might be null for parameters
            symbol.init = validate_AST(init, expected, errors, allocator);
        }
        // std.debug.print("init for: {s}: {?}\n", .{ symbol.name, symbol.init });
        if (symbol.kind == .trait) {
            try validate_trait(symbol, errors, allocator);
        } else if (symbol.init != null and symbol.init.?.* == .poison) {
            symbol.validation_state = .invalid;
            return error.TypeError;
            // unreachable;
        }
    } else {
        symbol.validation_state = .invalid;
        return error.TypeError;
    }

    // Symbol's name must be capitalized iff its type is Type
    if (symbol.expanded_type != null and !std.mem.eql(u8, symbol.name, "_") and symbol.kind != .trait and symbol.name[0] != '$') {
        if (type_is_type_type(symbol.expanded_type.?) and !is_capitalized(symbol.name)) {
            errors.add_error(errs_.Error{ .symbol_error = .{
                .problem = "of type `Type` must start with an uppercase letter",
                .span = symbol.span,
                .name = symbol.name,
            } });
        } else if (!type_is_type_type(symbol.expanded_type.?) and is_capitalized(symbol.name)) {
            errors.add_error(errs_.Error{ .symbol_error = .{
                .problem = "of type other than `Type` must start with a lowercase letter",
                .span = symbol.span,
                .name = symbol.name,
            } });
        }
    }
}

fn validate_trait(trait: *symbol_.Symbol, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!void {
    var names = std.StringArrayHashMap(*ast_.AST).init(allocator);
    defer names.deinit();
    for (trait.decl.?.children().items) |decl| {
        if (names.get(decl.method_decl.name.token().data)) |other| {
            errors.add_error(errs_.Error{ .duplicate = .{
                .span = decl.token().span,
                .identifier = decl.method_decl.name.token().data,
                .first = other.token().span,
            } });
            return error.TypeError;
        } else {
            names.put(decl.method_decl.name.token().data, decl) catch unreachable;
        }

        for (decl.method_decl._params.items) |param| {
            _ = validate_AST(param.decl.type, primitives_.type_type, errors, allocator);
        }
        _ = validate_AST(decl.method_decl.ret_type, primitives_.type_type, errors, allocator);

        if (decl.method_decl.is_virtual) {
            if (decl.method_decl.c_type.?.refers_to_self()) {
                errors.add_error(errs_.Error{ .trait_virtual_refers_to_self = .{
                    .span = decl.token().span,
                    .method_name = decl.method_decl.name.token().data,
                    .trait_name = trait.name,
                } });
                return error.TypeError;
            }
            trait.decl.?.trait.num_virtual_methods += 1;
        }
    }
}

fn validate_impl(impl: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!void {
    if (impl.impl._type.* == .addr_of) {
        errors.add_error(errs_.Error{ .basic = .{
            .span = impl.impl._type.token().span,
            .msg = "cannot implement method for address types",
        } });
        return error.TypeError;
    }

    impl.impl._type = validate_AST(impl.impl._type, primitives_.type_type, errors, allocator);

    const trait_symbol: *symbol_.Symbol = impl.impl.trait.?.symbol().?;
    const trait_ast = trait_symbol.decl.?;

    // Construct a map of all trait decls
    var trait_decls = std.StringArrayHashMap(*ast_.AST).init(allocator); // Map name -> Method Decl
    defer trait_decls.deinit();
    for (trait_ast.children().items) |decl| {
        trait_decls.put(decl.method_decl.name.token().data, decl) catch unreachable;
    }

    // Subtract trait defs - impl decls
    for (impl.children().items) |def| {
        const def_key = def.method_decl.name.token().data;
        const trait_decl = trait_decls.get(def_key);

        // Check that the trait defines the method
        if (trait_decl == null) {
            errors.add_error(errs_.Error{ .method_not_in_trait = .{
                .method_span = def.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
            } });
            return error.TypeError;
        }

        // Check that receivers match
        if (!receivers_match(def.method_decl.receiver, trait_decl.?.method_decl.receiver)) {
            errors.add_error(errs_.Error{ .impl_receiver_mismatch = .{
                .receiver_span = if (def.method_decl.receiver != null) def.method_decl.receiver.?.token().span else def.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
                .trait_receiver = if (trait_decl.?.method_decl.receiver != null) trait_decl.?.method_decl.receiver.?.receiver.kind else null,
                .impl_receiver = if (def.method_decl.receiver != null) def.method_decl.receiver.?.receiver.kind else null,
            } });
            return error.TypeError;
        }

        // Check that paramter arity matches
        if (def.children().items.len != trait_decl.?.children().items.len) {
            errors.add_error(errs_.Error{ .mismatch_method_param_arity = .{
                .span = def.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
                .trait_arity = trait_decl.?.children().items.len + @intFromBool(trait_decl.?.method_decl.receiver != null),
                .impl_arity = def.children().items.len + @intFromBool(def.method_decl.receiver != null),
            } });
            return error.TypeError;
        }

        // Check that parameters match
        for (def.children().items, trait_decl.?.children().items) |impl_param, trait_param| {
            const impl_type = impl_param.decl.type;
            const trait_type = ast_.AST.convert_self_type(trait_param.decl.type, impl.impl._type, allocator);
            if (!impl_type.types_match(trait_type)) {
                errors.add_error(errs_.Error{ .mismatch_method_type = .{
                    .span = impl_param.decl.type.token().span,
                    .method_name = def.method_decl.name.token().data,
                    .trait_name = trait_ast.token().data,
                    .trait_type = trait_type,
                    .impl_type = impl_type,
                } });
                return error.TypeError;
            }
        }

        // Check that return type matches
        const trait_method_ret_type = ast_.AST.convert_self_type(trait_decl.?.method_decl.ret_type, impl.impl._type, allocator);
        if (!def.method_decl.ret_type.types_match(trait_method_ret_type)) {
            errors.add_error(errs_.Error{ .mismatch_method_type = .{
                .span = def.method_decl.ret_type.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
                .trait_type = trait_method_ret_type,
                .impl_type = def.method_decl.ret_type,
            } });
            return error.TypeError;
        }

        // Copy over the c_type from trait method decl
        def.method_decl.c_type = trait_decl.?.method_decl.c_type;

        // Verify that impl virtuality matches trait virtuality
        if (def.method_decl.is_virtual != trait_decl.?.method_decl.is_virtual) {
            errors.add_error(errs_.Error{ .mismatch_method_virtuality = .{
                .span = def.token().span,
                .method_name = def.method_decl.name.token().data,
                .trait_name = trait_ast.token().data,
                .trait_method_is_virtual = trait_decl.?.method_decl.is_virtual,
                .impl_method_is_virtual = def.method_decl.is_virtual,
            } });
            return error.TypeError;
        }

        if (def.method_decl.is_virtual) {
            impl.impl.num_virtual_methods += 1;
        }

        // Subtract the method from the set
        _ = trait_decls.swapRemove(def_key);
    }

    var errant = false;
    for (trait_decls.keys()) |trait_key| {
        const trait_decl = trait_decls.get(trait_key).?;
        errors.add_error(errs_.Error{ .method_not_in_impl = .{
            .impl_span = impl.token().span,
            .method_span = trait_decl.token().span,
            .method_name = trait_decl.method_decl.name.token().data,
            .trait_name = trait_ast.token().data,
        } });
        errant = true;
    }
    if (errant) {
        return error.TypeError;
    }

    for (impl.children().items, 0..) |def, i| {
        impl.children().items[i] = validate_AST(def, null, errors, allocator);
    }
}

fn receivers_match(a: ?*ast_.AST, b: ?*ast_.AST) bool {
    if (a == null and b != null) {
        return false;
    } else if (a != null and b == null) {
        return false;
    } else if (a == null and b == null) {
        return true;
    } else {
        return a.?.receiver.kind == b.?.receiver.kind;
    }
}

fn type_is_type_type(ast: *ast_.AST) bool {
    if (ast.* == .function) {
        return type_is_type_type_atom(ast.rhs());
    } else {
        return type_is_type_type_atom(ast);
    }
}

fn type_is_type_type_atom(ast: *ast_.AST) bool {
    return ast.* == .identifier and std.mem.eql(u8, ast.token().data, "Type");
}

fn is_capitalized(name: []const u8) bool {
    var should_be_upper = true;
    for (name) |c| {
        if (should_be_upper and !std.ascii.isUpper(c) and c != '$') {
            return false;
        }
        should_be_upper = c == '_';
    }
    return true;
}

/// Errors out if `ast` is not the expected type
/// - `old_expected_type`: Should be null if `ast` can be any type
fn validate_AST(ast: *ast_.AST, old_expected_type: ?*ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) *ast_.AST {
    var expected_type = old_expected_type;
    if (ast.common().validation_state == .validating) {
        // std.debug.print("{}\n", .{ast});
        errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "recursive definition detected" } });
        return ast_.poisoned;
    } else if (ast.common().validation_state == .invalid) {
        return ast_.poisoned;
    } else if (ast.* != .@"comptime" and ast.common().validation_state == .valid) {
        // TODO: Why do we need comptime here?
        return ast.common().validation_state.valid.valid_form;
    }
    // std.debug.print("{}: {?}\n", .{ ast, expected_type });
    ast.common().validation_state = .validating;

    if (expected_type) |_| {
        // expected must be a valid Type type
        std.debug.assert(expected_type.?.* != .poison);
        std.debug.assert(expected_type.?.common().validation_state == .valid);
        var expected_type_type = expected_type.?.typeof(allocator);
        // std.debug.print("typeof({?}) = {}\n", .{ expected, expected_type });
        std.debug.assert(expected_type_type.types_match(primitives_.type_type));

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
        if (expected_type != null and primitives_.type_type.types_match(expected_type.?)) {
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
) error{ InterpreterPanic, TypeError, Overflow, DivideByZero, IRError, SymbolError }!*ast_.AST {
    // std.debug.print("{}: {?}\n", .{ ast, expected });
    switch (ast.*) {
        .poison => return ast,
        .pattern_symbol => return ast,
        .anyptr_type, .unit_type => {
            try type_check(ast.token().span, primitives_.type_type, expected, errors);
            return ast;
        },
        .unit_value => {
            try type_check(ast.token().span, primitives_.unit_type, expected, errors);
            return ast;
        },
        .int => {
            try type_check_int(ast, expected, errors, allocator);
            return ast;
        },
        .float => {
            try type_check_float(ast, expected, errors);
            return ast;
        },
        .char => {
            try type_check(ast.token().span, primitives_.char_type, expected, errors);
            return ast;
        },
        .string => {
            try type_check(ast.token().span, primitives_.string_type, expected, errors);
            return ast;
        },
        .identifier => {
            // look up symbol, that's the type
            const symbol = ast.symbol().?;
            if (symbol.validation_state == .invalid) {
                return error.TypeError;
            }
            try validate_symbol(symbol, errors, allocator);
            try type_check(ast.token().span, symbol._type, expected, errors);
            return ast;
        },
        .true, .false => {
            try type_check(ast.token().span, primitives_.bool_type, expected, errors);
            return ast;
        },
        .not => {
            ast.set_expr(validate_AST(ast.expr(), primitives_.bool_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast.token().span, primitives_.bool_type, expected, errors);
            return ast;
        },
        .negate => {
            ast.set_expr(validate_AST(ast.expr(), expected, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check_arithmetic(ast.token().span, ast.expr().typeof(allocator), errors);
            try type_check(ast.token().span, ast.expr().typeof(allocator), expected, errors);
            return ast;
        },
        .dereference => {
            const expr_span = ast.expr().token().span;
            if (expected != null) {
                const addr_of = ast_.AST.create_addr_of(ast.token(), expected.?, false, std.heap.page_allocator).assert_valid();
                ast.set_expr(validate_AST(ast.expr(), addr_of, errors, allocator));
            } else {
                ast.set_expr(validate_AST(ast.expr(), null, errors, allocator));
            }
            try assert_none_poisoned(ast.expr());
            const expanded_expr_type = ast.expr().typeof(allocator).expand_type(allocator);
            if (expanded_expr_type.* != .addr_of) {
                return throw_wrong_from("address", "dereference", expanded_expr_type, expr_span, errors);
            } else {
                return ast;
            }
        },
        .@"try" => {
            const expr_span = ast.expr().token().span;
            ast.set_expr(validate_AST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(ast.expr());
            var expanded_expr_type = ast.expr().typeof(allocator).expand_type(allocator);
            if (expanded_expr_type.* != .sum_type or expanded_expr_type.sum_type.from != .@"error") {
                return throw_wrong_from("error", "try", expanded_expr_type, expr_span, errors);
            }
            try type_check(ast.token().span, expanded_expr_type.get_ok_type().annotation.type, expected, errors);
            const expanded_function_codomain = ast.symbol().?._type.rhs().expand_type(allocator);
            if (expanded_function_codomain.* != .sum_type or expanded_function_codomain.sum_type.from != .@"error") {
                errors.add_error(errs_.Error{ .basic = .{
                    .span = ast.token().span,
                    .msg = "enclosing function around try expression does not return an error",
                } });
                return ast.enpoison();
            } else {
                // err must match
                const expr_error_type = expanded_expr_type.get_err_type().annotation.type;
                const function_error_type = expanded_function_codomain.get_err_type().annotation.type;
                if (!expr_error_type.types_match(function_error_type)) {
                    return throw_unexpected_type(expr_span, expanded_expr_type, expanded_function_codomain, errors);
                }
            }
            return ast;
        },
        .domain_of => {
            ast.domain_of.sum_type = validate_AST(ast.domain_of.sum_type, primitives_.type_type, errors, allocator);
            try assert_none_poisoned(ast.domain_of.sum_type);
            ast.set_expr(validate_AST(ast.expr(), ast.domain_of.sum_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            return ast.expr().sum_value.domain.?.annotation.type; // Should be filled by sum_value's validate
        },
        .type_of => {
            ast.set_expr(validate_AST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast.token().span, primitives_.type_type, expected, errors);
            return ast.expr().typeof(allocator);
        },
        .default => {
            ast.set_expr(validate_AST(ast.expr(), primitives_.type_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            const ast_type = ast.typeof(allocator);
            try type_check(ast.token().span, ast_type, expected, errors);
            const retval = generate_default(ast_type, ast.expr().token().span, errors, allocator);
            return retval;
        },
        .size_of => {
            ast.set_expr(validate_AST(ast.expr(), primitives_.type_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast.token().span, primitives_.int_type, expected, errors);
            return ast_.AST.create_int(ast.token(), ast.expr().expand_type(allocator).sizeof(), allocator);
        },
        .@"comptime" => {
            if (ast.@"comptime".result != null) {
                return ast.@"comptime".result.?;
            }
            // Validate symbol
            try validate_symbol(ast.symbol().?, errors, allocator); // ast.@"comptime".symbol.? is created during symbol tree expansion
            try assert_none_poisoned(ast.symbol().?._type);
            const ast_type = ast.symbol().?._type.rhs();
            const ret_type = ast_type.expand_type(allocator);
            if (ret_type.types_match(primitives_.void_type)) {
                return throw_unexpected_void_type(ast.expr().token().span, errors);
            }
            try type_check(ast.token().span, ast_type, expected, errors);

            // Get the cfg from the symbol, and embed into the module
            const cfg = try module_.get_cfg(ast.symbol().?, null, &ast.symbol().?.scope.module.?.interned_strings, errors, allocator);
            defer cfg.deinit(); // Remove the cfg so that it isn't output

            const idx = ast.symbol().?.scope.module.?.emplace_cfg(cfg);
            defer ast.symbol().?.scope.module.?.pop_cfg(idx); // Remove the cfg so that it isn't output

            // Create a context and interpret
            var context = interpreter_.Context.init(cfg, &ast.symbol().?.scope.module.?.instructions, ret_type, cfg.offset.?);
            try context.interpret();

            // Extract the retval
            ast.@"comptime".result = context.extract_ast(0, ret_type, allocator);
            return ast.@"comptime".result.?;
        },
        .assign => {
            ast.set_lhs(validate_AST(ast.lhs(), null, errors, allocator));
            const lhs_type = ast.lhs().typeof(allocator);
            try assert_none_poisoned(lhs_type);
            const rhs_expected: ?*ast_.AST = if (ast.lhs().* == .identifier and std.mem.eql(u8, ast.lhs().token().data, "_")) null else lhs_type;
            ast.set_rhs(validate_AST(ast.rhs(), rhs_expected, errors, allocator));
            try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
            try validate_L_Value(ast.lhs(), errors);
            try assert_mutable(ast.lhs(), errors, allocator);
            try type_check(ast.token().span, primitives_.unit_type, expected, errors);
            return ast;
        },
        .@"or", .@"and" => return try binary_operator_closed(ast, primitives_.bool_type, expected, errors, allocator),
        .add, .sub, .mult, .div => {
            // These operators are open, since they allow for polymorphism between their operands.
            const lhs_type = try binary_operator_open(ast, expected, errors, allocator);
            try type_check_arithmetic(ast.token().span, lhs_type, errors);
            try type_check(ast.token().span, lhs_type, expected, errors);
            return ast;
        },
        .mod => {
            const lhs_type = try binary_operator_open(ast, null, errors, allocator);
            try type_check_integral(ast.token().span, lhs_type, errors);
            try type_check(ast.token().span, lhs_type, expected, errors);
            return ast;
        },
        .equal, .not_equal => {
            const lhs_type = try binary_operator_open(ast, null, errors, allocator);
            const expanded_lhs_type = lhs_type.expand_type(allocator);
            if (primitives_.type_type.types_match(expanded_lhs_type)) {
                return type_equality_operation(ast, allocator);
            }
            try type_check_eq(ast.token().span, lhs_type, errors);
            try type_check(ast.token().span, primitives_.bool_type, expected, errors);
            return ast;
        },
        .greater, .lesser, .greater_equal, .lesser_equal => {
            const lhs_type = try binary_operator_open(ast, null, errors, allocator);
            try type_check_ord(ast.token().span, lhs_type, errors);
            try type_check(ast.token().span, primitives_.bool_type, expected, errors);
            return ast;
        },
        .@"catch", .@"orelse" => {
            const lhs_span = ast.lhs().token().span;
            ast.set_lhs(validate_AST(ast.lhs(), null, errors, allocator));
            ast.set_rhs(validate_AST(ast.rhs(), expected, errors, allocator));
            try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
            var expanded_lhs_type = ast.lhs().typeof(allocator).expand_type(allocator);
            try coalesce_operator(expanded_lhs_type, ast, lhs_span, errors);
            try type_check(ast.token().span, expanded_lhs_type.get_nominal_type().annotation.type, expected, errors);
            return ast;
        },
        .call => {
            const lhs_span = ast.lhs().token().span;
            ast.set_lhs(validate_AST(ast.lhs(), null, errors, allocator));
            try assert_none_poisoned(ast.lhs());
            if (ast.lhs().* == .identifier and ast.lhs().identifier.refers_to_template()) {
                const template_symbol = ast.lhs().symbol().?;
                const template_decl = template_symbol.decl.?;
                // ast should remain a call, but the lhs and rhs should change
                // use the const parameters from the rhs to choose which lhs to use, or if a new lhs needs to be stamped out
                const stamped_fn_identifier = try module_.stamp(
                    template_decl,
                    ast.children(),
                    ast.token().span,
                    template_symbol.scope,
                    errors,
                    allocator,
                );
                ast.set_lhs(stamped_fn_identifier);
                remove_const_args(template_decl.template.decl.fn_decl._params, ast.children());
            }
            var lhs_type = ast.lhs().typeof(allocator);
            const expanded_lhs_type = lhs_type.expand_identifier();
            if (ast.lhs().* != .sum_value and expanded_lhs_type.* != .function) {
                return throw_wrong_from(
                    "function",
                    "call",
                    expanded_lhs_type,
                    lhs_span,
                    errors,
                );
            }

            // since sum_values are always compiler constructed, and their type is always a sum-type, this should always hold
            std.debug.assert(ast.lhs().* != .sum_value or expanded_lhs_type.* == .sum_type); // an `implies` operator would be cool btw...

            const domain = if (expanded_lhs_type.* == .function) expanded_lhs_type.lhs() else ast.lhs().sum_value.domain.?;
            const codomain = if (expanded_lhs_type.* == .function) expanded_lhs_type.rhs() else ast.lhs().sum_value.base.?;
            ast.set_children(try default_args(ast.children().*, domain, errors, allocator));
            try validate_args_arity(.function, ast.children(), domain, ast.token().span, errors);
            ast.set_children((try validate_args_type(ast.children(), domain, errors, allocator)).*);
            try type_check(ast.token().span, codomain, expected, errors);
            if (ast.lhs().* == .sum_value) {
                // lhs is a sum value, usurp its init with ast's rhs
                std.debug.assert(ast.children().items.len == 1);
                ast.lhs().sum_value.init = ast.children().items[0];
                return ast.lhs();
            }
            if (expanded_lhs_type.* == .function and
                ast.call.common._expanded_type == null and
                expected != null and
                expected.?.types_match(primitives_.type_type))
            {
                const scope = ast.lhs().symbol().?.scope;
                ast.call.common._expanded_type = try module_.interpret(ast, primitives_.type_type, scope, errors, allocator);
            }
            return ast;
        },
        .index => { // TODO: TOO LONG!
            const lhs_span = ast.lhs().token().span; // Used for error reporting
            if (expected != null and primitives_.type_type.types_match(expected.?)) {
                ast.set_lhs(validate_AST(ast.lhs(), primitives_.type_type, errors, allocator));
            } else {
                ast.set_lhs(validate_AST(ast.lhs(), null, errors, allocator));
            }
            ast.set_rhs(validate_AST(ast.rhs(), primitives_.int_type, errors, allocator));
            try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });

            const lhs_type = ast.lhs().typeof(allocator);
            const expanded_lhs_type = try implicit_dereference(ast, lhs_type.expand_type(allocator), errors, allocator);

            if (lhs_type.types_match(primitives_.type_type) and
                ast.lhs().* == .product and
                ast.rhs().* == .int and ast.lhs().children().items.len > ast.rhs().int.data)
            {
                // Index a product type, resolve immediately
                return ast.lhs().children().items[@as(usize, @intCast(ast.rhs().int.data))];
            } else if (expanded_lhs_type.* != .product) {
                errors.add_error(errs_.Error{ .not_indexable = .{ .span = lhs_span, ._type = expanded_lhs_type } });
                return error.TypeError;
            } else if (expanded_lhs_type.* == .product and
                !expanded_lhs_type.product.was_slice and
                !expanded_lhs_type.product.is_homotypical())
            {
                if (ast.rhs().* != .int) {
                    // rhs is not int, error
                    errors.add_error(errs_.Error{ .basic = .{
                        .span = lhs_span,
                        .msg = "array is not homotypical and index is not compile-time known",
                    } });
                    return ast.enpoison();
                }
                // rhs is compile-time known, change to select
                const field = ast_.AST.create_field(token_.Token.init_simple(""), allocator);
                const select = ast_.AST.create_select(ast.token(), ast.lhs(), field, allocator).assert_valid();
                select.set_pos(@as(usize, @intCast(ast.rhs().int.data)));
                return select;
            } else if (expected != null) {
                if (expanded_lhs_type.* == .product and !expanded_lhs_type.product.was_slice) {
                    try type_check(ast.token().span, expanded_lhs_type.children().items[0], expected, errors);
                } else if (expanded_lhs_type.* == .product and expanded_lhs_type.product.was_slice) {
                    try type_check(ast.token().span, expanded_lhs_type.children().items[0].annotation.type.expr(), expected, errors);
                }
            }
            return ast;
        },
        .select => {
            ast.set_lhs(validate_AST(ast.lhs(), null, errors, allocator));
            try assert_none_poisoned(ast.lhs());
            const lhs_type = ast.lhs().typeof(allocator);
            const expanded_lhs_type = try implicit_dereference(ast, lhs_type.expand_type(allocator), errors, allocator);
            if (expanded_lhs_type.types_match(primitives_.type_type) and ast.lhs().expand_type(allocator).* == .sum_type) {
                // Select on a Type (only valid for a sum type), change to sum value
                const sum_value = ast_.AST.create_sum_value(ast.rhs().token(), allocator);
                sum_value.sum_value.base = ast.lhs();
                return validate_AST(sum_value, expected, errors, allocator);
            } else if (ast.pos() == null) {
                ast.set_pos(try find_select_pos(expanded_lhs_type, ast.rhs().token().data, ast.token().span, errors));
            }

            _ = ast.assert_valid();
            const ast_type = ast.typeof(allocator);
            try type_check(ast.token().span, ast_type, expected, errors);
            return ast;
        },

        .invoke => {
            ast.set_lhs(validate_AST(ast.lhs(), null, errors, allocator));
            try assert_none_poisoned(ast.lhs());
            // true_lhs_type is lhs's type
            const true_lhs_type = ast.lhs().typeof(allocator);
            // method_decl is the method_decl AST of the method being invoked
            var method_decl: ?*ast_.AST = undefined;
            if (true_lhs_type.expand_identifier().* == .dyn_type) {
                // The receiver is a dynamic type
                const trait = true_lhs_type.expand_identifier().expr().symbol().?.decl.?;
                method_decl = trait.trait.find_method(ast.rhs().token().data);
            } else {
                // The receiver is a regular type
                const lhs_type = if (true_lhs_type.* == .addr_of) true_lhs_type.expr() else true_lhs_type;
                method_decl = ast.invoke.scope.?.method_lookup(lhs_type, ast.rhs().token().data);
            }
            if (method_decl == null) {
                errors.add_error(errs_.Error{
                    .type_not_impl_method = .{
                        .span = ast.token().span,
                        .method_name = ast.rhs().token().data,
                        ._type = true_lhs_type, // TODO: Strip away addr_of's
                    },
                });
                return error.TypeError;
            }
            method_decl = validate_AST(method_decl.?, null, errors, allocator);
            try assert_none_poisoned(method_decl);
            ast.invoke.method_decl = method_decl.?;
            const domain: *ast_.AST = method_decl.?.method_decl.domain.?;
            const expanded_true_lhs_type = true_lhs_type.expand_identifier();
            if (method_decl.?.method_decl.receiver != null) {
                const receiver_kind: ?ast_.Receiver_Kind = method_decl.?.method_decl.receiver.?.receiver.kind;
                // Trait method takes a receiver...
                // Prepend invoke lhs to args if there is a receiver
                if (expanded_true_lhs_type.* == .dyn_type or expanded_true_lhs_type.* == .addr_of) {
                    // lhs type is dynamic or an address...
                    if (!expanded_true_lhs_type.mut() and receiver_kind == .mut_addr_of) {
                        // Receiver is immutable when it should be mutable
                        errors.add_error(errs_.Error{ .invoke_receiver_mismatch = .{
                            .lhs_type = true_lhs_type,
                            .method_name = method_decl.?.method_decl.name.token().data,
                            .method_receiver = receiver_kind.?,
                            .receiver_span = ast.lhs().token().span,
                        } });
                        return error.TypeError;
                    }
                    ast.children().insert(0, ast.lhs()) catch unreachable; // prepend lhs to children as a receiver
                } else {
                    // lhs type is not dynamic and not an address
                    const addr_of = ast_.AST.create_addr_of(ast.lhs().token(), ast.lhs(), receiver_kind.? == .mut_addr_of, allocator);
                    ast.children().insert(0, addr_of) catch unreachable; // prepend lhs to children as a receiver
                }
            }
            ast.set_children(try default_args(ast.children().*, domain, errors, allocator));
            try validate_args_arity(.method, ast.children(), domain, ast.token().span, errors);
            ast.set_children((try validate_args_type(ast.children(), domain, errors, allocator)).*);

            _ = ast.assert_valid();
            const ast_type = ast.typeof(allocator);
            try type_check(ast.token().span, ast_type, expected, errors);
            return ast;
        },
        .dyn_type => {
            ast.set_expr(validate_AST(ast.expr(), null, errors, allocator));
            if (ast.expr().* != .identifier) {
                return throw_wrong_from("dyn", "trait", ast, ast.token().span, errors);
            }
            const symbol = ast.expr().symbol();
            if (symbol == null or symbol.?.kind != .trait) {
                return throw_wrong_from("trait", "dyn", ast.expr(), ast.expr().token().span, errors);
            }

            try type_check(ast.token().span, primitives_.type_type, expected, errors);
            return ast;
        },
        .dyn_value => {
            ast.set_expr(validate_AST(ast.expr(), null, errors, allocator));
            ast.dyn_value.dyn_type = validate_AST(ast.dyn_value.dyn_type, primitives_.type_type, errors, allocator);
            const expr_type = ast.expr().typeof(allocator);

            const impl = ast.dyn_value.scope.?.impl_trait_lookup(expr_type, ast.dyn_value.dyn_type.expr().symbol().?);
            if (impl == null) {
                errors.add_error(errs_.Error{ .type_not_impl_trait = .{
                    .span = ast.token().span,
                    .trait_name = ast.dyn_value.dyn_type.expr().symbol().?.name,
                    ._type = expr_type,
                } });
                return error.TypeError;
            }
            ast.dyn_value.impl = impl;

            try type_check(ast.token().span, ast.dyn_value.dyn_type, expected, errors);
            return ast;
        },
        .function => return try binary_operator_closed(ast, primitives_.type_type, expected, errors, allocator),
        .sum_type => {
            for (0..ast.children().items.len) |i| {
                std.debug.assert(ast.children().items[i].* == .annotation); // sums are expanded in expand.zig
                ast.children().items[i] = validate_AST(ast.children().items[i], primitives_.type_type, errors, allocator);
            }
            try assert_none_poisoned(ast.children());
            try type_check(ast.token().span, primitives_.type_type, expected, errors);
            return ast;
        },
        .product => {
            const expanded_expected: ?*ast_.AST = if (expected == null) null else expected.?.expand_type(allocator);
            if (expanded_expected == null or expanded_expected.?.types_match(primitives_.type_type)) {
                // Not expecting anything OR expecting ast to be a product type
                for (0..ast.children().items.len) |i| {
                    ast.children().items[i] = validate_AST(ast.children().items[i], expanded_expected, errors, allocator);
                }
                try assert_none_poisoned(ast.children());
            } else if (expanded_expected != null and expanded_expected.?.* == .product) {
                // Expecting ast to be a product value of some product type
                _ = ast.assert_valid();
                ast.set_children(try default_args(ast.children().*, expanded_expected.?, errors, allocator));
                try validate_args_arity(.product, ast.children(), expanded_expected.?, ast.token().span, errors);
                ast.set_children((try validate_args_type(ast.children(), expanded_expected.?, errors, allocator)).*);
            } else if (expanded_expected == null or !primitives_.unit_type.types_match(expanded_expected.?)) {
                // It's ok to assign this to a unit type, something like `_ = (1, 2, 3)`
                // expecting something that is not a type nor a product is not ok!
                // poison `got`, so that it doesn't print anything for the `got` section, wouldn't make sense anyway
                return throw_unexpected_type(ast.token().span, expected.?, ast_.poisoned, errors);
            }
            return ast;
        },
        .@"union" => {
            // Save spans since lhs and rhs are expanded, need spans for errors
            const lhs_span = ast.lhs().token().span;
            const rhs_span = ast.rhs().token().span;

            const new_ast = try binary_operator_closed(ast, primitives_.type_type, expected, errors, allocator);

            const expanded_lhs = new_ast.lhs().expand_type(allocator);
            const expanded_rhs = new_ast.rhs().expand_type(allocator);
            if (expanded_lhs.* != .sum_type) {
                return throw_wrong_from("sum", "union", expanded_lhs, lhs_span, errors);
            } else if (expanded_rhs.* != .sum_type) {
                return throw_wrong_from("sum", "union", expanded_rhs, rhs_span, errors);
            }

            return try merge_sums(expanded_lhs, expanded_rhs, new_ast.token(), errors, allocator);
        },
        .addr_of => {
            if (expected == null) {
                // Not expecting anything, just validate expr
                ast.set_expr(validate_AST(ast.expr(), null, errors, allocator));
                try assert_none_poisoned(ast.expr());
                try validate_L_Value(ast.expr(), errors);
            } else if (primitives_.type_type.types_match(expected.?)) {
                // Address type, type of this ast must be a type, inner must be a type
                if (ast.expr().* == .identifier) {
                    _ = ast.expr().expand_type(allocator);
                    _ = ast.expr().assert_valid();
                } else {
                    ast.set_expr(validate_AST(ast.expr(), primitives_.type_type, errors, allocator));
                    try assert_none_poisoned(ast.expr());
                }
            } else {
                // Address value, expected must be an address, inner must match with expected's inner
                const expanded_expected = expected.?.expand_type(allocator);
                if (expanded_expected.* == .dyn_type) {
                    return validate_AST(
                        ast_.AST.create_dyn_value(
                            ast.token(),
                            expanded_expected,
                            ast.expr(),
                            ast.addr_of.scope.?,
                            ast.addr_of.mut,
                            allocator,
                        ),
                        expected,
                        errors,
                        allocator,
                    );
                } else if (expanded_expected.* != .addr_of) {
                    // Didn't expect an address type. Validate expr and report error
                    return throw_unexpected_type(ast.token().span, expected.?, ast_.poisoned, errors);
                }
                _ = expanded_expected.expr().expand_type(allocator);

                // Everythings Ok.
                ast.set_expr(validate_AST(ast.expr(), expanded_expected.expr().assert_valid(), errors, allocator));
                try assert_none_poisoned(ast.expr());
                _ = ast.assert_valid();
                if (ast.expr().* != .product) {
                    // Validate that expr is an L-value *only if* expr is not a product
                    // It is possible to take a addr of a product. The address is the address of the temporary
                    // This is mirrored with a slice_of a product.
                    try validate_L_Value(ast.expr(), errors);
                }
                if (ast.addr_of.mut) {
                    try assert_mutable(ast.expr(), errors, allocator);
                }
            }

            return ast;
        },
        .slice_of => {
            ast.set_expr(validate_AST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(ast.expr());
            var expr_type = ast.expr().typeof(allocator);

            // if (expected != null) {
            //     const expanded_expected = expected.?.expand_type(allocator);
            //     if (expanded_expected.* != .product) {
            //         unreachable;
            //     }
            // }

            if (expr_type.* != .unit_type and primitives_.type_type.types_match(expr_type)) {
                // Regular slice type, change to product of data address and length
                const retval = ast_.AST.create_slice_type(ast.expr(), ast.slice_of.kind == .mut, allocator).assert_valid();
                const retval_type = retval.typeof(allocator);
                try type_check(ast.token().span, retval_type, expected, errors);
                return retval;
            } else { // Slice-of value, expected must be an slice, inner must match with expected's inner
                // ast.expr() must be homotypical product type of expected
                if (expr_type.* != .product or !expr_type.product.is_homotypical()) {
                    errors.add_error(errs_.Error{ .basic = .{
                        .span = ast.token().span,
                        .msg = "attempt to take slice-of something that is not an array",
                    } });
                    return ast.enpoison();
                }

                _ = ast.assert_valid();
                const ast_type = ast.typeof(allocator);
                try type_check(ast.token().span, ast_type, expected, errors);

                if (ast.expr().* != .product) {
                    // Validate that expr is an L-value *only if* expr is not a product
                    // It is possible to take a slice of a product. The slice is the sliceof the temporary
                    // This is mirrored with addr_of a product.
                    try validate_L_Value(ast.expr(), errors);
                }
                if (ast.slice_of.kind == .mut) {
                    try assert_mutable(ast.expr(), errors, allocator);
                }
                return ast_.AST.create_slice_value(ast.expr(), ast.slice_of.kind == .mut, expr_type, allocator);
            }
        },
        .array_of => {
            ast.set_expr(validate_AST(ast.expr(), primitives_.type_type, errors, allocator));
            try assert_none_poisoned(ast.expr());
            try type_check(ast.token().span, primitives_.type_type, expected, errors);

            // Array-of type, type of this ast must be a type, inner must be a type
            ast.array_of.len = validate_AST(ast.array_of.len, primitives_.int_type, errors, allocator);
            try assert_none_poisoned(ast.array_of.len);
            var array_length: *ast_.AST = undefined;
            if (ast.array_of.len.* == .int) {
                array_length = ast.array_of.len;
            } else if (ast.array_of.len.* == .identifier and ast.array_of.len.symbol().?.kind == .@"const" and ast.array_of.len.symbol().?.decl.?.decl.init.?.* == .int) {
                array_length = ast.array_of.len.symbol().?.decl.?.decl.init.?;
            } else {
                errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "not integer literal" } });
                return ast.enpoison();
            }
            if (array_length.int.data <= 0) {
                errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "array length is not positive" } });
                return ast.enpoison();
            }
            return ast_.AST.create_array_type(array_length, ast.expr(), allocator);
        },
        .sub_slice => {
            ast.sub_slice.super = validate_AST(ast.sub_slice.super, null, errors, allocator);
            ast.sub_slice.lower = validate_AST(ast.sub_slice.lower.?, null, errors, allocator); // lower and upper should exist
            ast.sub_slice.upper = validate_AST(ast.sub_slice.upper.?, null, errors, allocator); // they are set in expand phase
            try assert_none_poisoned(.{ ast.sub_slice.super, ast.sub_slice.lower, ast.sub_slice.upper });
            const super_type = ast.sub_slice.super.typeof(allocator);
            if (super_type.* != .product or !super_type.product.was_slice) {
                errors.add_error(errs_.Error{ .basic = .{
                    .span = ast.token().span,
                    .msg = "cannot take a sub-slice of something that is not a slice",
                } });
                return error.TypeError;
            }
            return ast;
        },
        .annotation => {
            if (ast.annotation.pattern.* != .pattern_symbol and ast.annotation.pattern.* != .identifier) {
                errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "identifier", .got = ast.annotation.pattern.token() } });
                return error.TypeError;
            }
            ast.annotation.type = validate_AST(ast.annotation.type, primitives_.type_type, errors, allocator);
            try assert_none_poisoned(.{ast.annotation.type});
            if (ast.annotation.init != null) {
                ast.annotation.init = validate_AST(ast.annotation.init.?, ast.annotation.type, errors, allocator);
            }
            try assert_none_poisoned(.{ast.annotation.init});
            try type_check(ast.token().span, primitives_.type_type, expected, errors);
            return ast;
        },
        .sum_value => {
            if (ast.sum_value.base == null and expected == null) {
                errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "cannot infer the sum type" } });
                return error.TypeError;
            } else if (ast.sum_value.base == null) {
                // Infer that the base type is `expected`
                ast.sum_value.base = expected;
            }

            const expanded_base: *ast_.AST = ast.sum_value.base.?.expand_type(allocator);
            if (expanded_base.* != .sum_type) {
                return throw_wrong_from("sum", "sum value", expanded_base, ast.token().span, errors);
            }

            const pos = expanded_base.get_pos(ast.token().data);
            if (pos == null and expanded_base.* == .sum_type) {
                errors.add_error(errs_.Error{ .member_not_in = .{ .span = ast.token().span, .identifier = ast.token().data, .name = "sum", .group = expanded_base } });
                return error.TypeError;
            }
            ast.set_pos(expanded_base.get_pos(ast.token().data));

            ast.sum_value.domain = expanded_base.children().items[ast.pos().?];
            if (ast.sum_value.init == null) {
                // This may be usurped by a .call node
                ast.sum_value.init = ast.sum_value.domain.?.annotation.init orelse
                    try generate_default(ast.sum_value.domain.?.annotation.type, ast.token().span, errors, allocator);
            } else {
                ast.sum_value.init = validate_AST(ast.sum_value.init.?, ast.sum_value.domain.?.annotation.type, errors, allocator);
            }

            return ast;
        },
        .@"if" => { // TODO: TOO LONG!
            if (ast.@"if".let) |let| {
                ast.@"if".let = validate_AST(let, null, errors, allocator);
            }

            ast.@"if".condition = validate_AST(ast.@"if".condition, primitives_.bool_type, errors, allocator);
            try assert_none_poisoned(ast.@"if".condition);

            // expecting a type
            var expected_type: ?*ast_.AST = undefined;
            var expanded_expected: *ast_.AST = undefined;
            var is_result_optional: bool = false;
            if (expected == null) {
                expected_type = null;
            } else {
                expanded_expected = expected.?.expand_type(allocator);
                is_result_optional = expanded_expected.* == .sum_type and
                    expanded_expected.sum_type.from == .optional and
                    !expanded_expected.types_match(primitives_.void_type);
                if (ast.else_block() != null) {
                    expected_type = expected.?;
                } else if (is_result_optional) {
                    expected_type = expanded_expected.get_some_type();
                } else {
                    return throw_unexpected_type(ast.token().span, expected.?, ast_.poisoned, errors);
                }
            }

            if (ast.@"if".condition.* != .false) {
                ast.set_body_block(validate_AST(ast.body_block(), expected_type, errors, allocator));
            }

            if (ast.else_block() != null and ast.@"if".condition.* != .true) {
                ast.set_else_block(validate_AST(ast.else_block().?, expected_type, errors, allocator));
            }

            try assert_none_poisoned(.{ ast.@"if".let, ast.body_block(), ast.else_block() });

            if (ast.@"if".condition.* == .true and ast.else_block() != null) {
                // condition is true and theres an else => return {let; body}
                if (ast.@"if".let != null) {
                    if (ast.body_block().* == .block) {
                        ast.body_block().children().insert(0, ast.@"if".let.?) catch unreachable;
                    } else if (ast.body_block().* == .unit_value) {
                        var statements = std.ArrayList(*ast_.AST).init(allocator);
                        statements.append(ast.@"if".let.?) catch unreachable;
                        const block = ast_.AST.create_block(ast.body_block().token(), statements, null, allocator);
                        block.block.scope = ast.@"if".scope.?;
                        ast.set_body_block(block);
                    }
                }
                return ast.body_block();
            } else if (ast.@"if".condition.* == .true and ast.else_block() == null) {
                // condition is true and theres no else => return {let; some(body)}
                if (ast.@"if".let != null) {
                    if (ast.body_block().* == .block) {
                        ast.body_block().children().insert(0, ast.@"if".let.?) catch unreachable;
                    } else if (ast.body_block().* == .unit_value) {
                        var statements = std.ArrayList(*ast_.AST).init(allocator);
                        statements.append(ast.@"if".let.?) catch unreachable;
                        const block = ast_.AST.create_block(ast.body_block().token(), statements, null, allocator);
                        block.block.scope = ast.@"if".scope.?;
                        ast.set_body_block(block);
                    }
                }
                const opt_type = ast_.AST.create_optional_type(ast.body_block().typeof(allocator), allocator);
                const retval = ast_.AST.create_some_value(opt_type, ast.body_block(), allocator);
                return retval;
            } else if (ast.@"if".condition.* == .false and ast.else_block() != null) {
                // condition is false and theres an else => return {let; else}
                if (ast.@"if".let != null) {
                    if (ast.else_block().?.* == .block) {
                        ast.else_block().?.children().insert(0, ast.@"if".let.?) catch unreachable;
                    } else if (ast.else_block().?.* == .unit_value) {
                        var statements = std.ArrayList(*ast_.AST).init(allocator);
                        statements.append(ast.@"if".let.?) catch unreachable;
                        const block = ast_.AST.create_block(ast.else_block().?.token(), statements, null, allocator);
                        block.block.scope = ast.@"if".scope.?;
                        ast.set_else_block(block);
                    }
                }
                return ast.else_block().?;
            } else if (ast.@"if".condition.* == .false and ast.else_block() == null) {
                var statements = std.ArrayList(*ast_.AST).init(allocator);
                if (ast.@"if".let != null) {
                    statements.append(ast.@"if".let.?) catch unreachable;
                }
                if (ast.body_block().typeof(allocator).types_match(primitives_.void_type)) {
                    // condition is false and theres no else and void type => return {let}
                } else {
                    // condition is false and theres no else => return {let; none()}
                    const opt_type = ast_.AST.create_optional_type(ast.body_block().typeof(allocator), allocator);
                    statements.append(ast_.AST.create_none_value(opt_type, allocator)) catch unreachable;
                }
                const ret_block = ast_.AST.create_block(token_.Token.init_simple("{"), statements, null, allocator);
                ret_block.block.scope = ast.@"if".scope.?.parent.?;
                return ret_block;
            } else {
                // condition is undeterminable at compile-time, return if AST
                return ast;
            }
        },
        .match => {
            if (ast.match.let != null) {
                ast.match.let = validate_AST(ast.match.let.?, null, errors, allocator);
            }
            ast.set_expr(validate_AST(ast.expr(), null, errors, allocator));
            try assert_none_poisoned(.{ ast.match.let, ast.expr() });

            const expanded_expr_type = ast.expr().typeof(allocator).expand_type(allocator);
            try assert_none_poisoned(expanded_expr_type);

            for (0..ast.children().items.len) |i| {
                ast.children().items[i] = validate_AST(ast.children().items[i], expected, errors, allocator);
                try assert_none_poisoned(ast.children().items[i]);
                try assert_pattern_matches(ast.children().items[i].lhs(), expanded_expr_type, errors, allocator);
            }
            try assert_none_poisoned(ast.children());
            try exhaustive_check(expanded_expr_type, ast.children(), ast.token().span, errors, allocator);
            return ast;
        },
        .mapping => {
            // lhs for match mappings must be done elsewhere
            ast.set_rhs(validate_AST(ast.rhs(), expected, errors, allocator));
            try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
            return ast;
        },
        .@"while" => {
            if (ast.@"while".let) |let| {
                ast.@"while".let = validate_AST(let, null, errors, allocator);
            }
            if (ast.@"while".post) |post| {
                ast.@"while".post = validate_AST(post, null, errors, allocator);
            }
            ast.@"while".condition = validate_AST(ast.@"while".condition, primitives_.bool_type, errors, allocator);

            var is_optional_type = false; //< Set if expected is an optional type
            if (expected != null) {
                const expanded_expected = expected.?.expand_type(allocator);
                if (expanded_expected.* == .sum_type and expanded_expected.sum_type.from == .optional) {
                    ast.set_body_block(validate_AST(ast.body_block(), expanded_expected.get_some_type(), errors, allocator));
                    is_optional_type = true;
                }
            }
            if (!is_optional_type) {
                ast.set_body_block(validate_AST(ast.body_block(), expected, errors, allocator));
                if (ast.else_block()) |else_block| {
                    ast.set_else_block(validate_AST(else_block, expected, errors, allocator));
                }
            }
            try assert_none_poisoned(.{ ast.@"while".let, ast.@"while".post, ast.@"while".condition, ast.body_block(), ast.else_block() });
            return ast;
        },
        .block => {
            for (0..ast.children().items.len) |i| {
                const expected_type: ?*ast_.AST = if (ast.block.final == null and i == ast.children().items.len - 1) expected else null;
                ast.children().items[i] = validate_AST(ast.children().items[i], expected_type, errors, allocator);
                const statement = ast.children().items[i];
                // A middle-statement is any but the last statement if there is no final, or any statement if there is a final
                // Middle statements' type must be unit
                const is_middle_statement = if (ast.block.final == null) i < ast.children().items.len - 1 else true;
                if ((statement.* != .fn_decl or statement.fn_decl.name == null) and is_middle_statement) {
                    // Don't worry about fn_decl's, those should be allowed to be "discarded"
                    const expanded_statement_type = statement.typeof(allocator).expand_type(allocator);
                    try middle_statement_check(statement.token().span, expanded_statement_type, errors);
                }
            }
            try assert_none_poisoned(ast.children());
            if (ast.block.final) |final| {
                ast.block.final = validate_AST(final, expected, errors, allocator);
                try assert_none_poisoned(ast.block.final);
            } else {
                _ = ast.assert_valid();
                try type_check(ast.token().span, ast.typeof(allocator), expected, errors);
            }
            return ast;
        },
        .@"break", .@"continue", .@"unreachable" => {
            try void_check(ast.token().span, expected, errors);
            return ast;
        },
        .@"return" => {
            if (ast.@"return"._ret_expr) |expr| {
                ast.@"return"._ret_expr = validate_AST(expr, ast.symbol().?._type.rhs(), errors, allocator);
                try assert_none_poisoned(ast.@"return"._ret_expr);
            } else if (expected != null and (expected.?.expand_type(allocator)).* != .unit_type) {
                return throw_unexpected_type(ast.token().span, expected.?, primitives_.void_type, errors);
            }
            return ast;
        },
        .@"defer", .@"errdefer" => {
            ast.set_statement(validate_AST(ast.statement(), null, errors, allocator));
            try assert_none_poisoned(ast.statement());
            try void_check(ast.token().span, expected, errors);
            return ast;
        },
        .fn_decl => {
            try validate_symbol(ast.symbol().?, errors, allocator);
            try assert_none_poisoned(ast.symbol().?._type);
            if (expected) |_expected| {
                const expanded_expected = _expected.expand_type(allocator);
                const ast_type = ast.typeof(allocator);
                try type_check(ast.token().span, ast_type, expanded_expected, errors);
            }
            return ast;
        },
        .method_decl => {
            std.debug.assert(expected == null); // Why wouldn't it be?
            if (ast.symbol() != null) {
                // Not a trait-method
                try validate_symbol(ast.symbol().?, errors, allocator);
                try assert_none_poisoned(ast.symbol().?._type);
            }
            ast.method_decl.domain = validate_AST(ast.method_decl.domain.?, primitives_.type_type, errors, allocator);
            return ast;
        },
        .template => {
            if (expected != null and !primitives_.unit_type.types_match(expected.?)) {
                errors.add_error(
                    errs_.Error{
                        .basic = .{
                            .span = ast.token().span,
                            .msg = "cannot assign template",
                        },
                    },
                );
                return error.TypeError;
            }
            return ast;
        },
        .decl => {
            ast.decl.type = validate_AST(ast.decl.type, primitives_.type_type, errors, allocator);
            try assert_none_poisoned(ast.decl.type);
            if (ast.decl.init) |init| {
                ast.decl.init = validate_AST(init, ast.decl.type, errors, allocator);
            }
            try assert_none_poisoned(ast.decl.init);
            for (ast.decl.symbols.items) |symbol| {
                try validate_symbol(symbol, errors, allocator);
            }
            try type_check(ast.token().span, primitives_.unit_type, expected, errors);
            return ast;
        },
        else => {
            std.debug.print("validate_AST() unimplemented for {s}\n", .{@tagName(ast.*)});
            unreachable;
        },
    }
}

fn type_check(span: span_.Span, got: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (got.refers_to_block()) {
        // TODO: This seems too simplistic
        errors.add_error(errs_.Error{ .basic = .{ .span = span, .msg = "type cannot be non-const block, consider adding `comptime`" } });
        return error.TypeError;
    }
    if (expected != null and !got.types_match(expected.?)) {
        return throw_unexpected_type(span, expected.?, got, errors);
    }
}

fn void_check(span: span_.Span, expected: ?*ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (expected != null and primitives_.type_type.types_match(expected.?)) {
        return throw_unexpected_type(span, expected.?, primitives_.void_type, errors);
    }
}

/// Checks that a type is equal to unit, throws an error if it is not.
fn middle_statement_check(span: span_.Span, got: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!primitives_.unit_type.types_match(got) and !got.types_match(primitives_.void_type)) {
        return throw_unexpected_type(span, primitives_.unit_type, got, errors);
    }
}

fn type_check_int(
    ast: *ast_.AST,
    expected: ?*ast_.AST, // This should NOT be expanded
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!void {
    const expanded_expected = if (expected != null) expected.?.expand_type(allocator) else null;
    if (expanded_expected != null and !primitives_.unit_type.types_match(expanded_expected.?)) {
        const info = primitives_.info_from_ast(expanded_expected.?);
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
                return error.TypeError;
            }
        } else {
            // This error is thrown because the `expanded_expected` is not an integer primitive type
            return throw_unexpected_type(ast.token().span, expanded_expected.?, primitives_.int_type, errors);
        }
    }
    ast.set_represents(expected orelse primitives_.int_type);
}

fn type_check_float(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (expected != null and !expected.?.can_represent_float()) {
        return throw_unexpected_type(ast.token().span, expected.?, primitives_.float_type, errors);
    }
    ast.set_represents(expected orelse primitives_.float_type);
}

fn type_check_eq(span: span_.Span, got: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_eq_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "equalable", .got = got } });
        return error.TypeError;
    }
}

fn type_check_ord(span: span_.Span, got: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_ord_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "orderable", .got = got } });
        return error.TypeError;
    }
}

fn type_check_arithmetic(span: span_.Span, got: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_num_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "arithmetic", .got = got } });
        return error.TypeError;
    }
}

fn type_check_integral(span: span_.Span, got: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!got.is_int_type()) {
        errors.add_error(errs_.Error{ .expected_builtin_typeclass = .{ .span = span, .expected = "integer", .got = got } });
        return error.TypeError;
    }
}

fn throw_unexpected_type(span: span_.Span, expected: *ast_.AST, got: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum {
    errors.add_error(errs_.Error{ .unexpected_type = .{ .span = span, .expected = expected, .got = got } });
    return error.TypeError;
}

fn throw_unexpected_void_type(span: span_.Span, errors: *errs_.Errors) Validate_Error_Enum {
    errors.add_error(errs_.Error{ .basic = .{ .span = span, .msg = "comptime cannot be type `Void`" } });
    return error.TypeError;
}

fn throw_not_selectable(span: span_.Span, errors: *errs_.Errors) Validate_Error_Enum {
    errors.add_error(errs_.Error{ .basic = .{ .span = span, .msg = "left-hand-side of select is not selectable" } });
    return error.TypeError;
}

fn throw_wrong_from(
    from_name: []const u8,
    operator_name: []const u8,
    got: *ast_.AST,
    span: span_.Span,
    errors: *errs_.Errors,
) Validate_Error_Enum {
    errors.add_error(errs_.Error{ .wrong_from = .{
        .span = span,
        .operator = operator_name,
        .from = from_name,
        .got = got,
    } });
    return error.TypeError;
}

fn assert_none_poisoned(value: anytype) Validate_Error_Enum!void {
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

fn type_equality_operation(ast: *ast_.AST, allocator: std.mem.Allocator) *ast_.AST {
    std.debug.assert(ast.* == .equal or ast.* == .not_equal);
    const true_ast = ast_.AST.create_true(ast.token(), allocator);
    const false_ast = ast_.AST.create_false(ast.token(), allocator);
    if (ast.lhs().types_match(ast.rhs()) and ast.rhs().types_match(ast.lhs())) {
        return if (ast.* == .equal) true_ast else false_ast;
    } else {
        return if (ast.* == .equal) false_ast else true_ast;
    }
}

/// Validates a closed binary operator. Returns the valid form of the binary operator.
fn binary_operator_closed(
    ast: *ast_.AST,
    self_type: *ast_.AST,
    expected: ?*ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!*ast_.AST {
    ast.set_lhs(validate_AST(ast.lhs(), self_type, errors, allocator));
    ast.set_rhs(validate_AST(ast.rhs(), self_type, errors, allocator));
    try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
    try type_check(ast.token().span, self_type, expected, errors);
    return ast;
}

/// Validates an open binary operator. An operator is `open` if it returns a type different from the
/// ones it acts on.
///
/// Returns the type of the validated operator.
fn binary_operator_open(ast: *ast_.AST, expected: ?*ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!*ast_.AST {
    ast.set_lhs(validate_AST(ast.lhs(), expected, errors, allocator));
    const lhs_type = ast.lhs().typeof(allocator);
    try assert_none_poisoned(lhs_type);
    ast.set_rhs(validate_AST(ast.rhs(), lhs_type, errors, allocator));
    try assert_none_poisoned(.{ ast.lhs(), ast.rhs() });
    return lhs_type;
}

fn coalesce_operator(lhs_expanded_type: *ast_.AST, ast: *ast_.AST, span: span_.Span, errors: *errs_.Errors) Validate_Error_Enum!void {
    std.debug.assert(ast.* == .@"orelse" or ast.* == .@"catch");
    const expected_sum_from: ast_.Sum_From = if (ast.* == .@"orelse") .optional else .@"error";
    if (lhs_expanded_type.* != .sum_type or lhs_expanded_type.sum_type.from != expected_sum_from) {
        errors.add_error(errs_.Error{ .wrong_from = .{
            .span = span,
            .operator = @tagName(ast.*),
            .from = @tagName(expected_sum_from),
            .got = lhs_expanded_type,
        } });
        return error.TypeError;
    }
}

// This has to be public for stamps to use it when fleshing out the default args
// This has to be ok to do twice for the same args, because stamps have to do it internally.
pub fn default_args(
    asts: std.ArrayList(*ast_.AST),
    expected: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!std.ArrayList(*ast_.AST) {
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

/// Determines if there are named arguments in an argument list. If there are no arguments, there are
/// no named arguments.
///
/// Throws `error.TypeError` if there is a mix of positional and named arguments.
fn args_are_named(
    asts: std.ArrayList(*ast_.AST), // TODO: This could be replaced with just a slice of ASTs
    errors: *errs_.Errors,
) Validate_Error_Enum!bool {
    if (asts.items.len == 0) {
        return false;
    }

    var has_named_arg = false;
    var has_pos_arg = false;
    for (asts.items) |term| {
        if (term.* == .assign) {
            has_named_arg = true;
        } else {
            has_pos_arg = true;
        }
    }
    std.debug.assert(has_named_arg or has_pos_arg);
    if (has_named_arg and has_pos_arg) {
        const arg_span = asts.items[0].token().span;
        errors.add_error(errs_.Error{ .basic = .{ .span = arg_span, .msg = "mixed positional and named arguments are not allowed" } });
        return error.TypeError;
    } else {
        return has_named_arg;
    }
}

/// Accepts a list of AST arguments, the expected parameter type, and if the ASTs list isn't long enough for the parameters, prepends the
/// default values for each missing argument.
///
/// Returns NoDefault when a default value cannot be created
fn positional_args(
    asts: std.ArrayList(*ast_.AST),
    expected: *ast_.AST,
    allocator: std.mem.Allocator,
) error{NoDefault}!std.ArrayList(*ast_.AST) {
    var filled_args = std.ArrayList(*ast_.AST).init(allocator);
    errdefer filled_args.deinit();

    switch (expected.*) {
        .annotation => {
            if (asts.items.len == 0 and expected.annotation.init != null) {
                // Use expected's init, asts are empty
                filled_args.append(expected.annotation.init.?) catch unreachable;
            } else if (asts.items.len > 0) {
                // Copy asts over to filled_args
                for (asts.items) |item| {
                    filled_args.append(item) catch unreachable;
                }
            } else {
                // empty args, no default init in parameter. No default possible!
                return error.NoDefault;
            }
        },

        .product => {
            for (expected.children().items, 0..) |term, i| {
                // ast is product, append ast's corresponding term
                if (asts.items.len > 1 and i < asts.items.len) {
                    filled_args.append(asts.items[i]) catch unreachable;
                }
                // ast is unit or ast isn't a product and i > 0 or ast is a product and off the edge of ast's terms
                // try to fill with the default
                else if (asts.items.len == 0 or (asts.items.len <= 1 and i > 0) or (asts.items.len > 1 and i >= asts.items.len)) {
                    if (term.* == .annotation and term.annotation.init != null) {
                        filled_args.append(term.annotation.init.?) catch unreachable;
                    } else {
                        return error.NoDefault;
                    }
                }
                // ast is not product, i != 0, append ast as first term
                else {
                    filled_args.append(asts.items[0]) catch unreachable;
                }
            }
        },

        .unit_type, .identifier => filled_args = asts,

        else => {
            std.debug.print("positional_args(): unimplemented for {s}\n", .{@tagName(expected.*)});
            unreachable;
        },
    }
    return filled_args;
}

fn named_args(
    asts: std.ArrayList(*ast_.AST), // TODO: This could be replaced with just a slice of ASTs
    expected: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) error{ TypeError, NoDefault }!std.ArrayList(*ast_.AST) {
    std.debug.assert(asts.items.len > 0);
    // Maps assign.lhs name to assign.rhs
    var arg_name_to_val_map = std.StringArrayHashMap(*ast_.AST).init(allocator);
    defer arg_name_to_val_map.deinit();

    // Associate argument names with their values
    for (asts.items) |term| {
        put_assign(term, &arg_name_to_val_map, errors) catch |err| switch (err) {
            error.TypeError => return error.NoDefault,
            else => return err,
        };
    }

    // Construct positional args in the order specified by `expected`
    var filled_args = std.ArrayList(*ast_.AST).init(allocator);
    errdefer filled_args.deinit();
    switch (expected.*) {
        .annotation => {
            if (arg_name_to_val_map.keys().len > 1) { // Cannot be 0, since that is technically a positional arglist
                errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = asts.items[0].token().span,
                    .takes = 1,
                    .given = arg_name_to_val_map.keys().len,
                    .thing_name = "functionlol",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.NoDefault;
            } else {
                filled_args.append(arg_name_to_val_map.values()[0]) catch unreachable;
            }
        },

        .product => {
            for (expected.children().items) |term| {
                if (term.* != .annotation) {
                    errors.add_error(errs_.Error{ .basic = .{
                        .span = asts.items[0].token().span,
                        .msg = "expected type does not accept named arugments",
                    } });
                    return error.NoDefault;
                }
                const arg = arg_name_to_val_map.get(term.annotation.pattern.token().data);
                if (arg == null) {
                    if (term.annotation.init != null) {
                        filled_args.append(term.annotation.init.?) catch unreachable;
                    } else {
                        // Value is not provided, and there is no default init, ERROR!
                        errors.add_error(errs_.Error{ .mismatch_arity = .{
                            .span = asts.items[0].token().span,
                            .takes = expected.children().items.len,
                            .given = arg_name_to_val_map.keys().len,
                            .thing_name = "type",
                            .takes_name = "value",
                            .given_name = "value",
                        } });
                        return error.NoDefault;
                    }
                } else {
                    filled_args.append(arg.?) catch unreachable;
                }
            }
        },

        else => unreachable,
    }
    return filled_args;
}

/// Validates that the number of arguments matches the number of parameters
pub fn validate_args_arity(
    thing: Validate_Args_Thing,
    args: *std.ArrayList(*ast_.AST), // TODO: This could be replaced with just a slice of ASTs
    expected: *ast_.AST,
    span: span_.Span,
    errors: *errs_.Errors,
) Validate_Error_Enum!void {
    const expected_length = if (expected.* == .unit_type) 0 else if (expected.* == .product) expected.children().items.len else 1;
    if (args.items.len != expected_length) {
        errors.add_error(errs_.Error{ .mismatch_arity = .{
            .span = span,
            .takes = expected_length,
            .given = args.items.len,
            .thing_name = thing.name(),
            .takes_name = thing.takes_name(),
            .given_name = thing.given_name(),
        } });
        return error.TypeError;
    }
}

/// Validates just that each argument's type matches its corresponding parameter's type. Assumes arity is valid.
pub fn validate_args_type(
    args: *std.ArrayList(*ast_.AST), // TODO: This could be replaced with a slice of ASTs
    expected: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!*std.ArrayList(*ast_.AST) {
    const expected_length = if (expected.* == .unit_type) 0 else if (expected.* == .product) expected.children().items.len else 1;

    for (0..expected_length) |i| {
        const param_type = if (expected.* == .product) expected.children().items[i] else expected;
        args.items[i] = validate_AST(args.items[i], param_type, errors, allocator);
    }
    try assert_none_poisoned(args);
    return args;
}

fn remove_const_args(
    params: std.ArrayList(*ast_.AST), // TODO: This could be replaced with a slice of ASTs
    args: *std.ArrayList(*ast_.AST),
) void {
    var param_idx: usize = 0;
    var arg_idx: usize = 0;
    while (param_idx < params.items.len and arg_idx < args.items.len) {
        const param = params.items[param_idx];
        if (param.decl.pattern.pattern_symbol.kind == .@"const") {
            _ = args.orderedRemove(arg_idx);
            arg_idx -%= 1;
        }
        param_idx += 1;
        arg_idx +%= 1;
    }
}

fn put_assign(ast: *ast_.AST, arg_map: *std.StringArrayHashMap(*ast_.AST), errors: *errs_.Errors) Validate_Error_Enum!void {
    if (ast.lhs().* != .sum_value) {
        errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "an inferred member", .got = ast.lhs().token() } });
        return error.TypeError;
    }
    try put_ast_map(ast.rhs(), ast.lhs().sum_value.get_name(), ast.token().span, arg_map, errors);
}

fn merge_sums(
    lhs: *ast_.AST,
    rhs: *ast_.AST,
    token: token_.Token,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!*ast_.AST {
    // List of merged terms for retval sum AST
    var new_terms = std.ArrayList(*ast_.AST).init(allocator);
    // Map of names to AST, used to detect duplicate names when merging
    var names = std.StringArrayHashMap(*ast_.AST).init(allocator);
    defer names.deinit();

    try put_many_annot_map(lhs.children(), &new_terms, &names, errors);
    try put_many_annot_map(rhs.children(), &new_terms, &names, errors);

    const merged_sum = ast_.AST.create_sum_type(token, new_terms, allocator);
    if (lhs.sum_type.from == .@"error" or rhs.sum_type.from == .@"error") {
        merged_sum.sum_type.from = .@"error";
    } else {
        merged_sum.sum_type.from = .none;
    }
    return merged_sum;
}

fn put_many_annot_map(
    asts: *std.ArrayList(*ast_.AST), // TODO: This could be replaced with just a slice of ASTs
    new_terms: *std.ArrayList(*ast_.AST),
    map: *std.StringArrayHashMap(*ast_.AST),
    errors: *errs_.Errors,
) Validate_Error_Enum!void {
    for (asts.items) |term| {
        try put_ast_map(term.annotation.type, term.annotation.pattern.token().data, term.token().span, map, errors);
        new_terms.append(term) catch unreachable;
    }
}

/// Puts an ast into a String->AST map, if a given name isn't already in the map.
fn put_ast_map(
    ast: *ast_.AST,
    name: []const u8,
    span: span_.Span,
    map: *std.StringArrayHashMap(*ast_.AST),
    errors: *errs_.Errors,
) Validate_Error_Enum!void {
    if (map.get(name)) |_| {
        errors.add_error(errs_.Error{ .duplicate = .{
            .span = span,
            .identifier = name,
            .first = null,
        } });
    } else {
        map.put(name, ast) catch unreachable;
    }
}

fn validate_L_Value(ast: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    switch (ast.*) {
        .identifier => {},

        .dereference => if (ast.expr().* != .addr_of) {
            try validate_L_Value(ast.expr(), errors);
        },

        .index, .select => try validate_L_Value(ast.lhs(), errors),

        .product => for (ast.children().items) |term| {
            try validate_L_Value(term, errors);
        },

        else => {
            errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "not an l-value" } });
            return error.TypeError;
        },
    }
}

fn assert_mutable(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!void {
    switch (ast.*) {
        .identifier => {
            const symbol = ast.symbol().?;
            if (!std.mem.eql(u8, symbol.name, "_") and symbol.kind != .mut) {
                errors.add_error(errs_.Error{ .modify_immutable = .{ .identifier = ast.token() } });
                return error.TypeError;
            }
        },

        .dereference => {
            const expr_expanded_type = ast.expr().typeof(allocator).expand_type(allocator);
            try assert_mutable_address(expr_expanded_type, errors);
        },

        .index => {
            const lhs_type = ast.lhs().typeof(allocator);
            if (lhs_type.* == .product and lhs_type.product.was_slice) {
                try assert_mutable_address(lhs_type.children().items[0].annotation.type, errors);
            } else {
                try assert_mutable(ast.lhs(), errors, allocator);
            }
        },

        .product => for (ast.children().items) |term| {
            try assert_mutable(term, errors, allocator);
        },

        .select => try assert_mutable(ast.lhs(), errors, allocator),

        else => unreachable,
    }
}

fn assert_mutable_address(ast: *ast_.AST, errors: *errs_.Errors) Validate_Error_Enum!void {
    if (!ast.addr_of.mut) {
        errors.add_error(errs_.Error{ .basic = .{ .span = ast.token().span, .msg = "cannot modify non-mutable address" } });
        return error.TypeError;
    }
}

fn implicit_dereference(
    ast: *ast_.AST,
    old_lhs_type: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!*ast_.AST {
    var lhs_type = old_lhs_type;
    if (lhs_type.* == .addr_of) {
        ast.set_lhs(validate_AST(ast_.AST.create_dereference(ast.token(), ast.lhs(), allocator), null, errors, allocator));
        lhs_type = ast.lhs().typeof(allocator).expand_type(allocator);
    }
    try assert_none_poisoned(.{ ast.lhs(), lhs_type });
    return lhs_type;
}

fn find_select_pos(_type: *ast_.AST, field: []const u8, span: span_.Span, errors: *errs_.Errors) Validate_Error_Enum!usize {
    if (_type.* != .product and _type.* != .sum_type) {
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
        errors.add_error(errs_.Error{ .member_not_in = .{ .span = span, .identifier = field, .name = "tuple", .group = _type } });
        return error.TypeError;
    }
}

/// Validates that `pattern` is valid given a match's `expr`
fn assert_pattern_matches(
    pattern: *ast_.AST,
    expr_type: *ast_.AST,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!void {
    switch (pattern.*) {
        .unit_value => try type_check(pattern.token().span, primitives_.unit_type, expr_type, errors),
        .int => try type_check_int(pattern, expr_type, errors, allocator),
        .char => try type_check(pattern.token().span, primitives_.char_type, expr_type, errors),
        .string => try type_check(pattern.token().span, primitives_.string_type, expr_type, errors),
        .float => try type_check_float(pattern, expr_type, errors),
        .true, .false => try type_check(pattern.token().span, primitives_.bool_type, expr_type, errors),
        .block => {
            const new_pattern = validate_AST(pattern, expr_type, errors, allocator);
            try assert_none_poisoned(new_pattern);
            try type_check(pattern.token().span, new_pattern.typeof(allocator), expr_type, errors);
        },
        .select, .sum_value => {
            const new_pattern = validate_AST(pattern, expr_type, errors, allocator);
            try assert_none_poisoned(new_pattern);
            pattern.set_pos(new_pattern.pos().?);
            try type_check(pattern.token().span, new_pattern.typeof(allocator), expr_type, errors);
        },
        .product => {
            const expanded_expr_type = expr_type.expand_type(allocator);
            if (expanded_expr_type.* != .product or expanded_expr_type.children().items.len != pattern.children().items.len) {
                return throw_unexpected_type(pattern.token().span, expr_type, pattern.typeof(allocator), errors);
            }
            for (pattern.children().items, expanded_expr_type.children().items) |term, expanded_term| {
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

/// Checks that a match's mappings cover all possible cases
///
/// Currently only checks that all sums are covered.
/// HUGE TODO: Figure out how to do this fr for products
fn exhaustive_check(
    _type: *ast_.AST,
    mappings: *std.ArrayList(*ast_.AST),
    match_span: span_.Span,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,
) Validate_Error_Enum!void {
    if (_type.* == .sum_type) {
        var total_sum_ids = std.ArrayList(usize).init(allocator);
        defer total_sum_ids.deinit();

        // Append all sum IDs to the ids list
        for (_type.children().items, 0..) |_, i| {
            total_sum_ids.append(i) catch unreachable;
        }
        // For each sum ID, remove it if it's covered
        // Yeah I know this sucks. Figure out something better!
        for (mappings.items) |m| {
            exhaustive_check_sub(m.lhs(), &total_sum_ids);
        }
        // If there were any IDs that weren't removed, they weren't covered with a pattern match
        if (total_sum_ids.items.len > 0) {
            var forgotten_sum_variants = std.ArrayList(*ast_.AST).init(std.heap.page_allocator); // Not deallocated, lives until error emission
            for (total_sum_ids.items) |id| {
                forgotten_sum_variants.append(_type.children().items[id]) catch unreachable;
            }
            errors.add_error(errs_.Error{ .non_exhaustive_sum = .{ .span = match_span, .forgotten = forgotten_sum_variants } });
            return error.TypeError;
        }
    }
}

fn exhaustive_check_sub(ast: *ast_.AST, ids: *std.ArrayList(usize)) void {
    switch (ast.*) {
        .select, .sum_value => {
            for (ids.items, 0..) |item, i| {
                if (item == ast.pos().?) {
                    _ = ids.swapRemove(i);
                    break;
                }
            }
        },
        .pattern_symbol => ids.clearRetainingCapacity(),
        else => {},
    }
}

fn generate_default(_type: *ast_.AST, span: span_.Span, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!*ast_.AST {
    return (try generate_default_unvalidated(_type, span, errors, allocator)).assert_valid();
}

fn generate_default_unvalidated(_type: *ast_.AST, span: span_.Span, errors: *errs_.Errors, allocator: std.mem.Allocator) Validate_Error_Enum!*ast_.AST {
    switch (_type.*) {
        .anyptr_type => return _type,
        .identifier => {
            const expanded_type = _type.expand_type(allocator);
            if (expanded_type == _type) {
                const primitive_info = primitives_.info_from_name(_type.token().data);
                if (primitive_info.default_value != null) {
                    return primitive_info.default_value.?;
                } else {
                    errors.add_error(errs_.Error{ .no_default = .{ .span = span, ._type = _type } });
                    return error.TypeError;
                }
            } else {
                return try generate_default(expanded_type, span, errors, allocator);
            }
        },
        .dyn_type, .addr_of, .function => return ast_.AST.create_int(_type.token(), 0, allocator),
        .unit_type => return ast_.AST.create_unit_value(_type.token(), allocator),
        .sum_type => {
            var retval = ast_.AST.create_sum_value(_type.token(), allocator);
            if (_type.sum_type.from == .optional) {
                retval.set_pos(1);
            } else {
                retval.set_pos(0); // if nothing's wrong, then everything's `.ok`!
            }
            retval.sum_value.base = _type;
            const proper_term: *ast_.AST = _type.children().items[0];
            retval.sum_value.init = try generate_default(proper_term, span, errors, allocator);
            return retval;
        },
        .call => {
            return try generate_default(_type.expand_type(allocator), span, errors, allocator);
        },
        .product => {
            var value_terms = std.ArrayList(*ast_.AST).init(allocator);
            errdefer value_terms.deinit();
            for (_type.children().items) |term| {
                const default_term = try generate_default(term, span, errors, allocator);
                value_terms.append(default_term) catch unreachable;
            }
            return ast_.AST.create_product(_type.token(), value_terms, allocator);
        },
        .annotation => if (_type.annotation.init != null) {
            return _type.annotation.init.?;
        } else {
            return generate_default(_type.annotation.type, span, errors, allocator);
        },
        else => {
            std.debug.print("Unimplemented generate_default() for: AST.{s}\n", .{@tagName(_type.*)});
            unreachable;
        },
    }
}
