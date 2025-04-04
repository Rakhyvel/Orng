const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const String = @import("../zig-string/zig-string.zig").String;
const Symbol = @import("../symbol/symbol.zig");
const Token = @import("../lexer/token.zig");

const Self: type = @This();

const Parser_Error_Enum = error{ParseError};

tokens: *std.ArrayList(Token),
cursor: usize,
errors: *errs_.Errors,
allocator: std.mem.Allocator,

pub fn init(errors: *errs_.Errors, allocator: std.mem.Allocator) Self {
    return .{
        .tokens = undefined,
        .cursor = 0,
        .allocator = allocator,
        .errors = errors,
    };
}

fn peek(self: *Self) Token {
    return self.tokens.items[self.cursor];
}

fn peek_kind(self: *Self, kind: Token.Kind) bool {
    return self.peek().kind == kind;
}

fn next_is_expr(self: *Self) bool {
    const next_kind = self.peek().kind;
    return next_kind == .exclamation_mark or
        next_kind == .true or
        next_kind == .false or
        next_kind == .question_mark or
        next_kind == .period or
        next_kind == .ampersand or
        next_kind == .left_parenthesis or
        next_kind == .left_square or
        next_kind == .left_brace or
        next_kind == .bar or
        next_kind == .minus or
        next_kind == .match or
        next_kind == .@"fn" or
        next_kind == .@"for" or
        next_kind == .@"if" or
        next_kind == .@"try" or
        next_kind == .@"comptime" or
        next_kind == .@"unreachable" or
        next_kind == .@"while" or
        next_kind == .identifier or
        next_kind == .bin_int or
        next_kind == .char or
        next_kind == .hex_int or
        next_kind == .dec_int or
        next_kind == .oct_int or
        next_kind == .float or
        next_kind == .string or
        next_kind == .multi_line_string or
        next_kind == .not or
        next_kind == .at_symbol or
        next_kind == .self;
}

fn next_is_control_flow(self: *Self) bool {
    const next_kind = self.peek().kind;
    return next_kind == .@"if" or
        next_kind == .@"while" or
        next_kind == .match or
        next_kind == .@"for" or
        next_kind == .@"comptime" or
        next_kind == .left_brace;
}

fn next_is_statement(self: *Self) bool {
    const next_kind = self.peek().kind;
    return next_kind == .let or
        next_kind == .@"const" or
        next_kind == .@"extern" or
        next_kind == .import or
        next_kind == .cinclude or
        next_kind == .impl or
        next_kind == .trait or
        next_kind == .@"defer" or
        next_kind == .@"errdefer" or
        self.next_is_expr();
}

/// Returns the next token if its kind matches the given kind, otherwise
/// null
fn accept(self: *Self, kind: Token.Kind) ?Token {
    const token = self.peek();
    if (token.kind == kind) {
        self.cursor += 1;
        return token;
    } else {
        return null;
    }
}

/// Returns the token with an expected kind, or throws an error.
fn expect(self: *Self, kind: Token.Kind) Parser_Error_Enum!Token {
    if (self.accept(kind)) |token| {
        return token;
    } else {
        self.errors.add_error(errs_.Error{ .expected2token = .{ .expected = kind, .got = self.peek() } });
        return Parser_Error_Enum.ParseError;
    }
}

/// Parses a token stream a file into a list of declaration ASTs
pub fn run(self: *Self, tokens: *std.ArrayList(Token)) Parser_Error_Enum!*std.ArrayList(*ast_.AST) {
    self.tokens = tokens;
    var decls = self.allocator.create(std.ArrayList(*ast_.AST)) catch unreachable;
    decls.* = std.ArrayList(*ast_.AST).init(self.allocator);
    while (self.accept(.newline)) |_| {}
    while (!self.peek_kind(.EOF)) {
        decls.append(try self.top_level_declaration()) catch unreachable;
        while (self.accept(.newline)) |_| {}
    }
    _ = try self.expect(.EOF);
    return decls;
}

fn top_level_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    if (self.peek_kind(.@"fn")) {
        return try self.fn_declaration();
    } else if (self.peek_kind(.@"const")) {
        var decl: *ast_.AST = try self.const_declaration();
        if (!self.peek_kind(.EOF)) {
            _ = try self.expect(.newline);
        }
        decl.decl._top_level = true;
        return decl;
    } else if (self.peek_kind(.@"extern")) {
        var decl: *ast_.AST = try self.extern_const_declaration();
        if (!self.peek_kind(.EOF)) {
            _ = try self.expect(.newline);
        }
        decl.decl._top_level = true;
        return decl;
    } else if (self.peek_kind(.import)) {
        const import: *ast_.AST = try self.import_declaration();
        if (!self.peek_kind(.EOF)) {
            _ = try self.expect(.newline);
        }
        return import;
    } else if (self.peek_kind(.cinclude)) {
        const cinclude: *ast_.AST = try self.cinclude_declaration();
        if (!self.peek_kind(.EOF)) {
            _ = try self.expect(.newline);
        }
        return cinclude;
    } else if (self.peek_kind(.trait)) {
        return try self.trait_declaration();
    } else if (self.peek_kind(.impl)) {
        return try self.impl_declaration();
    } else {
        self.errors.add_error(errs_.Error{ .expected_basic_token = .{
            .expected = "`fn`, `trait`, `impl`, or `const` here",
            .got = self.peek(),
        } });
        return Parser_Error_Enum.ParseError;
    }
}

fn import_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.import);

    const identifier = try self.expect(.identifier);
    var pattern = ast_.AST.create_pattern_symbol(
        identifier,
        .{ .import = .{ .real_name = identifier.data } },
        identifier.data,
        self.allocator,
    );

    while (self.accept(.double_colon)) |access_token| {
        pattern = ast_.AST.create_access(
            access_token,
            pattern,
            ast_.AST.create_field(try self.expect(.identifier), self.allocator),
            self.allocator,
        );
    }

    return ast_.AST.create_import(
        token,
        pattern,
        self.allocator,
    );
}

fn cinclude_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.cinclude);
    return ast_.AST.create_cinclude(
        token,
        try self.arrow_expr(),
        self.allocator,
    );
}

fn extern_const_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.@"extern");

    var c_name: ?*ast_.AST = null;
    if (self.accept(.left_parenthesis) != null) {
        c_name = try self.arrow_expr();
        _ = try self.expect(.right_parenthesis);
    }

    _ = try self.expect(.@"const");

    const identifier = try self.expect(.identifier);
    const pattern = ast_.AST.create_pattern_symbol(identifier, .{ .@"extern" = .{ .c_name = c_name } }, identifier.data, self.allocator);
    _ = try self.expect(.single_colon);
    const _type: *ast_.AST = try self.arrow_expr();
    var _init: ?*ast_.AST = null;
    if (self.accept(.single_equals)) |_| {
        _init = try self.arrow_expr();
    }

    var retval = ast_.AST.create_decl(
        token,
        pattern,
        _type,
        _init,
        false,
        self.allocator,
    );
    retval.decl.prohibit_defaults = true;
    return retval;
}

fn const_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.@"const");

    const identifier = try self.expect(.identifier);
    const pattern = ast_.AST.create_pattern_symbol(identifier, .@"const", identifier.data, self.allocator);
    var _type: ?*ast_.AST = null;
    var _init: ?*ast_.AST = null;

    if (self.accept(.single_colon)) |_| {
        _type = try self.arrow_expr();
        if (self.peek_kind(.single_equals)) {
            _ = try self.expect(.single_equals);
            _init = try self.arrow_expr();
        }
    } else if (self.accept(.single_equals)) |_| {
        _init = try self.arrow_expr();
    } else {
        self.errors.add_error(errs_.Error{ .basic = .{
            .span = self.peek().span,
            .msg = "variable declarations require at least a type or an intial value",
        } });
        return error.ParseError;
    }

    return ast_.AST.create_decl(
        token,
        pattern,
        _type orelse ast_.AST.create_type_of(token, _init.?, self.allocator), // type inference done here!
        _init orelse ast_.AST.create_default(token, _type.?, self.allocator), // default value generate done here!
        false,
        self.allocator,
    );
}

fn let_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.let);

    const ident = try self.let_pattern_atom();
    var _type: ?*ast_.AST = null;
    var _init: ?*ast_.AST = null;
    var is_undefined = false;

    if (self.accept(.single_colon)) |_| {
        _type = try self.arrow_expr();
        if (self.peek_kind(.single_equals)) {
            _ = try self.expect(.single_equals);
            if (self.accept(.undefined)) |_| {
                is_undefined = true;
            } else {
                _init = try self.arrow_expr();
            }
        }
    } else if (self.accept(.single_equals)) |_| {
        _init = try self.arrow_expr();
    } else {
        self.errors.add_error(errs_.Error{ .basic = .{
            .span = self.peek().span,
            .msg = "variable declarations require at least a type or an intial value",
        } });
        return error.ParseError;
    }

    var decl = ast_.AST.create_decl(
        token,
        ident,
        _type orelse ast_.AST.create_type_of(token, _init.?, self.allocator), // type inference done here!
        _init orelse if (is_undefined) null else ast_.AST.create_default(token, _type.?, self.allocator), // default value generate done here!
        false,
        self.allocator,
    );
    decl.decl.prohibit_defaults = is_undefined;
    return decl;
}

fn let_pattern_atom(self: *Self) Parser_Error_Enum!*ast_.AST {
    if (self.peek_kind(.mut) or self.peek_kind(.@"const") or self.peek_kind(.identifier)) {
        var kind: Symbol.Kind = undefined;
        if (self.accept(.mut) != null) {
            kind = .mut;
        } else if (self.accept(.@"const") != null) {
            kind = .@"const";
        } else {
            kind = .let;
        }
        const identifier = try self.expect(.identifier);
        return ast_.AST.create_pattern_symbol(identifier, kind, identifier.data, self.allocator);
    } else if (self.accept(.left_parenthesis)) |_| {
        const res = try self.let_pattern_product();
        _ = try self.expect(.right_parenthesis);
        return res;
    } else {
        self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "a pattern expression here", .got = self.peek() } });
        return Parser_Error_Enum.ParseError;
    }
}

fn let_pattern_product(self: *Self) Parser_Error_Enum!*ast_.AST {
    const exp = try self.let_pattern_atom();
    var terms: ?std.ArrayList(*ast_.AST) = null;
    var firsttoken_: ?Token = null;
    while (self.accept(.comma)) |token| {
        if (terms == null) {
            terms = std.ArrayList(*ast_.AST).init(self.allocator);
            firsttoken_ = token;
            terms.?.append(exp) catch unreachable;
        }
        terms.?.append(try self.let_pattern_atom()) catch unreachable;
    }
    if (terms) |terms_list| {
        return ast_.AST.create_product(firsttoken_.?, terms_list, self.allocator);
    } else {
        return exp;
    }
}

fn let_pre(self: *Self) Parser_Error_Enum!?*ast_.AST {
    var retval: ?*ast_.AST = null;
    if (self.peek_kind(.let)) {
        retval = try self.let_declaration();
    } else if (self.peek_kind(.@"const")) {
        retval = try self.const_declaration();
    } else if (self.peek_kind(.@"extern")) {
        retval = try self.extern_const_declaration();
    }

    if (retval != null) {
        if (self.peek_kind(.semicolon)) {
            _ = self.expect(.semicolon) catch {};
        } else {
            self.errors.add_error(errs_.Error{ .expected_basic_token = .{
                .expected = "a semicolon here",
                .got = self.peek(),
            } });
            return error.ParseError;
        }
    }
    return retval;
}

fn statement(self: *Self) Parser_Error_Enum!*ast_.AST {
    if (self.peek_kind(.let)) {
        return self.let_declaration();
    } else if (self.peek_kind(.@"const")) {
        return self.const_declaration();
    } else if (self.peek_kind(.@"extern")) {
        return self.extern_const_declaration();
    } else if (self.peek_kind(.trait)) {
        return self.trait_declaration();
    } else if (self.peek_kind(.impl)) {
        return self.impl_declaration();
    } else if (self.accept(.@"defer")) |token| {
        return ast_.AST.create_defer(token, try self.assignment_expr(), self.allocator);
    } else if (self.accept(.@"errdefer")) |token| {
        return ast_.AST.create_errdefer(token, try self.assignment_expr(), self.allocator);
    } else if (self.next_is_expr()) {
        return self.assignment_expr();
    } else {
        self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "a statement here", .got = self.peek() } });
        return Parser_Error_Enum.ParseError;
    }
}

fn parse_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    return self.sum_type();
}

// [|] expr {| expr}
fn sum_type(self: *Self) Parser_Error_Enum!*ast_.AST {
    const prefix_bar: ?Token = self.accept(.bar);
    const exp = try self.product_expr();
    var terms: ?std.ArrayList(*ast_.AST) = null;
    var firsttoken_: ?Token = null;
    if (prefix_bar) |_prefix_bar| {
        terms = std.ArrayList(*ast_.AST).init(self.allocator);
        firsttoken_ = _prefix_bar;
        terms.?.append(exp) catch unreachable;
    }
    while (self.accept(.bar)) |token| {
        if (terms == null) {
            terms = std.ArrayList(*ast_.AST).init(self.allocator);
            firsttoken_ = token;
            terms.?.append(exp) catch unreachable;
        }
        terms.?.append(try self.annotation_expr()) catch unreachable;
    }
    if (terms) |terms_list| {
        return ast_.AST.create_sum_type(firsttoken_.?, terms_list, self.allocator);
    } else {
        return exp;
    }
}

// TODO: Basically identical to sum_type, fix it!
fn product_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    const exp = try self.annotation_expr();
    var terms: ?std.ArrayList(*ast_.AST) = null;
    var firsttoken_: ?Token = null;
    while (self.accept(.comma)) |token| {
        if (terms == null) {
            terms = std.ArrayList(*ast_.AST).init(self.allocator);
            firsttoken_ = token;
            terms.?.append(exp) catch unreachable;
        }
        if (self.peek_kind(.right_parenthesis)) {
            // Trailing comma, break out
            break;
        }
        terms.?.append(try self.annotation_expr()) catch unreachable;
    }
    if (terms) |terms_list| {
        return ast_.AST.create_product(firsttoken_.?, terms_list, self.allocator);
    } else {
        return exp;
    }
}

fn annotation_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    const exp = try self.assignment_expr();
    if (self.accept(.single_colon)) |token| {
        const _type = try self.arrow_expr();
        var predicate: ?*ast_.AST = null;
        var _init: ?*ast_.AST = null;
        if (self.accept(.where)) |_| {
            predicate = try self.arrow_expr();
        }
        if (self.accept(.single_equals)) |_| {
            const pre__init = try self.arrow_expr();
            if (!pre__init.is_comptime_expr()) {
                self.errors.add_error(errs_.Error{ .comptime_known = .{ .span = pre__init.token().span, .what = "default values" } });
                return error.ParseError;
            }
            _init = ast_.AST.create_comptime(token, pre__init, self.allocator);
        }
        return ast_.AST.create_annotation(token, exp, _type, predicate, _init, self.allocator);
    } else {
        return exp;
    }
}

fn assignment_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    const exp = try self.arrow_expr();
    if (self.accept(.single_equals)) |token| {
        return ast_.AST.create_assign(token, exp, try self.arrow_expr(), self.allocator);
    } else if (self.accept(.plus_equals)) |token| {
        return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.arrow_expr(), self.allocator), self.allocator);
    } else if (self.accept(.minus_equals)) |token| {
        return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.arrow_expr(), self.allocator), self.allocator);
    } else if (self.accept(.star_equals)) |token| {
        return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.arrow_expr(), self.allocator), self.allocator);
    } else if (self.accept(.slash_equals)) |token| {
        return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.arrow_expr(), self.allocator), self.allocator);
    } else if (self.accept(.percent_equals)) |token| {
        return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.arrow_expr(), self.allocator), self.allocator);
    } else {
        return exp;
    }
}

fn arrow_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    var exp = try self.bool_expr();
    while (self.accept(.skinny_arrow) orelse self.accept(.variadic)) |token| {
        var variadic = false;
        if (token.kind == .variadic) {
            _ = try self.expect(.skinny_arrow);
            variadic = true;
        }
        exp = ast_.AST.create_function(token, exp, try self.bool_expr(), self.allocator);
        exp.function.variadic = true;
    }
    return exp;
}

fn bool_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    var exp = try self.comparison_expr();
    while (true) {
        if (self.accept(.@"and")) |token| {
            exp = ast_.AST.create_and(token, exp, try self.comparison_expr(), self.allocator);
        } else if (self.accept(.@"or")) |token| {
            exp = ast_.AST.create_or(token, exp, try self.comparison_expr(), self.allocator);
        } else {
            return exp;
        }
    }
}

fn comparison_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    var exp = try self.coalesce_expr();
    if (self.accept(.double_equals)) |token| {
        exp = ast_.AST.create_equal(token, exp, try self.coalesce_expr(), self.allocator);
    } else if (self.accept(.e_mark_equals)) |token| {
        exp = ast_.AST.create_not_equal(token, exp, try self.coalesce_expr(), self.allocator);
    } else if (self.accept(.greater)) |token| {
        exp = ast_.AST.create_greater(token, exp, try self.coalesce_expr(), self.allocator);
    } else if (self.accept(.lesser)) |token| {
        exp = ast_.AST.create_lesser(token, exp, try self.coalesce_expr(), self.allocator);
    } else if (self.accept(.greater_equal)) |token| {
        exp = ast_.AST.create_greater_equal(token, exp, try self.coalesce_expr(), self.allocator);
    } else if (self.accept(.lesser_equal)) |token| {
        exp = ast_.AST.create_lesser_equal(token, exp, try self.coalesce_expr(), self.allocator);
    }
    return exp;
}

fn coalesce_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    var exp = try self.int_expr();
    while (true) {
        if (self.accept(.@"catch")) |token| {
            exp = ast_.AST.create_catch(token, exp, try self.int_expr(), self.allocator);
        } else if (self.accept(.@"orelse")) |token| {
            exp = ast_.AST.create_orelse(token, exp, try self.int_expr(), self.allocator);
        } else {
            return exp;
        }
    }
}

fn int_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    var exp = try self.term_expr();
    while (true) {
        if (self.accept(.plus)) |token| {
            exp = ast_.AST.create_add(token, exp, try self.term_expr(), self.allocator);
        } else if (self.accept(.minus)) |token| {
            exp = ast_.AST.create_sub(token, exp, try self.term_expr(), self.allocator);
        } else if (self.accept(.exclamation_mark)) |_| {
            exp = ast_.AST.create_error_type(exp, try self.term_expr(), self.allocator);
        } else {
            return exp;
        }
    }
}

fn term_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    var exp = try self.prefix_expr();
    while (true) {
        if (self.accept(.star)) |token| {
            exp = ast_.AST.create_mult(token, exp, try self.prefix_expr(), self.allocator);
        } else if (self.accept(.slash)) |token| {
            exp = ast_.AST.create_div(token, exp, try self.prefix_expr(), self.allocator);
        } else if (self.accept(.percent)) |token| {
            exp = ast_.AST.create_mod(token, exp, try self.prefix_expr(), self.allocator);
        } else if (self.accept(.double_bar)) |token| {
            exp = ast_.AST.create_union(token, exp, try self.prefix_expr(), self.allocator);
        } else {
            return exp;
        }
    }
}

fn prefix_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    // FIXME: High Cyclo
    if (self.accept(.not)) |token| {
        return ast_.AST.create_not(token, try self.prefix_expr(), self.allocator);
    } else if (self.accept(.at_symbol)) |_| {
        const token = try self.expect(.identifier);

        const args = try self.call_args();

        // TODO: Would be nice to make a table of this, somehow!
        if (std.mem.eql(u8, token.data, "typeof")) {
            if (args.items.len != 1) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 1,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_type_of(token, args.items[0], self.allocator);
        } else if (std.mem.eql(u8, token.data, "default")) {
            if (args.items.len != 1) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 1,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_default(token, args.items[0], self.allocator);
        } else if (std.mem.eql(u8, token.data, "sizeof")) {
            if (args.items.len != 1) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 1,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_size_of(token, args.items[0], self.allocator);
        } else if (std.mem.eql(u8, token.data, "bit_and")) {
            if (args.items.len < 2) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 2,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_bit_and(token, args, self.allocator);
        } else if (std.mem.eql(u8, token.data, "bit_or")) {
            if (args.items.len < 2) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 2,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_bit_or(token, args, self.allocator);
        } else if (std.mem.eql(u8, token.data, "bit_xor")) {
            if (args.items.len < 2) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 2,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_bit_xor(token, args, self.allocator);
        } else if (std.mem.eql(u8, token.data, "bit_not")) {
            if (args.items.len != 1) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 1,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_bit_not(token, args.items[0], self.allocator);
        } else if (std.mem.eql(u8, token.data, "left_shift")) {
            if (args.items.len != 2) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 2,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_left_shift(token, args.items[0], args.items[1], self.allocator);
        } else if (std.mem.eql(u8, token.data, "right_shift")) {
            if (args.items.len != 2) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 2,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_right_shift(token, args.items[0], args.items[1], self.allocator);
        } else if (std.mem.eql(u8, token.data, "Untagged")) {
            if (args.items.len != 1) {
                self.errors.add_error(errs_.Error{ .mismatch_arity = .{
                    .span = token.span,
                    .takes = 2,
                    .given = args.items.len,
                    .thing_name = "built-in function",
                    .takes_name = "parameter",
                    .given_name = "argument",
                } });
                return error.ParseError;
            }
            return ast_.AST.create_untagged_sum_type(token, args.items[0], self.allocator);
        } else {
            self.errors.add_error(errs_.Error{ .basic = .{ .msg = "unknown built-in function", .span = token.span } }); // TODO: Unique error message that says the builtin function name
            return error.ParseError;
        }
    } else if (self.accept(.minus)) |token| {
        return ast_.AST.create_negate(token, try self.prefix_expr(), self.allocator);
    } else if (self.accept(.ampersand)) |token| {
        const mut = self.accept(.mut);
        if (self.accept(.dyn)) |token2| {
            return ast_.AST.create_dyn_type(
                token2,
                ast_.AST.create_identifier(try self.expect(.identifier), self.allocator),
                mut != null,
                self.allocator,
            );
        } else {
            return ast_.AST.create_addr_of(token, try self.prefix_expr(), mut != null, false, self.allocator);
        }
    } else if (self.accept(.left_square)) |token| {
        var slice_kind: enum { multiptr, array, slice } = undefined;
        var mut = false;
        var len: ?*ast_.AST = null;
        if (self.accept(.star)) |_| {
            slice_kind = .multiptr;
        } else if (self.next_is_expr()) {
            slice_kind = .array;
            len = try self.arrow_expr();
            if (!len.?.is_comptime_expr()) {
                self.errors.add_error(errs_.Error{ .comptime_known = .{ .span = len.?.token().span, .what = "array lengths" } });
                return error.ParseError;
            }
        } else {
            slice_kind = .slice;
        }
        if (self.accept(.mut)) |_| {
            mut = true;
        }
        if (self.peek_kind(.right_square)) {
            _ = self.expect(.right_square) catch {};
        } else {
            self.errors.add_error(errs_.Error{ .missing_close = .{ .expected = .right_square, .got = self.peek(), .open = token } });
            return error.ParseError;
        }
        switch (slice_kind) {
            .multiptr => return ast_.AST.create_addr_of(token, try self.prefix_expr(), mut, true, self.allocator),
            .slice => return ast_.AST.create_slice_of(token, try self.prefix_expr(), mut, self.allocator),
            .array => return ast_.AST.create_array_of(token, try self.prefix_expr(), len.?, self.allocator),
        }
    } else if (self.accept(.question_mark)) |_| {
        return ast_.AST.create_optional_type(try self.prefix_expr(), self.allocator);
    } else if (self.accept(.@"try")) |token| {
        return ast_.AST.create_try(token, try self.postfix_expr(), self.allocator);
    } else {
        return try self.postfix_expr();
    }
}

fn postfix_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    // FIXME: High Cyclo
    var exp = if (self.next_is_control_flow()) try self.control_flow() else try self.factor();
    while (true) {
        if (self.peek_kind(.left_parenthesis)) {
            exp = ast_.AST.create_call(self.peek(), exp, try self.call_args(), self.allocator);
        } else if (self.accept(.left_square)) |token| {
            var first: ?*ast_.AST = null;
            if (self.next_is_expr()) {
                first = try self.assignment_expr();
            }
            if (self.accept(.double_period)) |_| {
                var second: ?*ast_.AST = null;
                if (self.next_is_expr()) {
                    second = try self.assignment_expr();
                }
                exp = ast_.AST.create_sub_slice(token, exp, first, second, self.allocator);
            } else {
                // Simple index
                exp = ast_.AST.create_index(token, exp, first orelse {
                    self.errors.add_error(errs_.Error{ .expected_basic_token = .{
                        .expected = "an expression here",
                        .got = self.peek(),
                    } });
                    return Parser_Error_Enum.ParseError;
                }, self.allocator);
            }
            if (self.peek_kind(.right_square)) {
                _ = self.expect(.right_square) catch {};
            } else {
                self.errors.add_error(errs_.Error{ .missing_close = .{ .expected = .right_square, .got = self.peek(), .open = token } });
                return error.ParseError;
            }
        } else if (self.accept(.period)) |token| {
            exp = ast_.AST.create_select(
                token,
                exp,
                ast_.AST.create_field(try self.expect(.identifier), self.allocator),
                self.allocator,
            );
        } else if (self.accept(.double_colon)) |token| {
            exp = ast_.AST.create_access(
                token,
                exp,
                ast_.AST.create_field(try self.expect(.identifier), self.allocator),
                self.allocator,
            );
        } else if (self.accept(.invoke)) |token| {
            exp = ast_.AST.create_invoke(
                token,
                exp,
                ast_.AST.create_field(try self.expect(.identifier), self.allocator),
                try self.call_args(),
                self.allocator,
            );
        } else if (self.accept(.caret)) |token| {
            exp = ast_.AST.create_dereference(token, exp, self.allocator);
        } else {
            return exp;
        }
    }
}

fn call_args(self: *Self) Parser_Error_Enum!std.ArrayList(*ast_.AST) {
    _ = try self.expect(.left_parenthesis);
    var retval = std.ArrayList(*ast_.AST).init(self.allocator);
    if (!self.peek_kind(.right_parenthesis)) {
        retval.append(try self.assignment_expr()) catch unreachable;
        while (self.accept(.comma)) |_| {
            retval.append(try self.assignment_expr()) catch unreachable;
        }
    }
    _ = try self.expect(.right_parenthesis);
    return retval;
}

fn control_flow(self: *Self) Parser_Error_Enum!*ast_.AST {
    if (self.peek_kind(.@"if")) {
        return try self.if_expr();
    } else if (self.peek_kind(.@"while")) {
        return try self.while_expr();
    } else if (self.peek_kind(.match)) {
        return try self.match_expr();
    } else if (self.peek_kind(.@"for")) {
        return try self.for_expr();
    } else if (self.accept(.@"comptime")) |token| {
        return ast_.AST.create_comptime(token, try self.block_expr(), self.allocator);
    } else {
        return try self.factor();
    }
}

fn factor(self: *Self) Parser_Error_Enum!*ast_.AST {
    if (self.accept(.identifier)) |token| {
        return ast_.AST.create_identifier(token, self.allocator);
    } else if (self.accept(.self)) |token| {
        return ast_.AST.create_identifier(token, self.allocator);
    } else if (self.peek_kind(.@"fn")) {
        return self.fn_declaration();
    } else if (self.accept(.period)) |_| {
        const sum_val = ast_.AST.create_sum_value(try self.expect(.identifier), self.allocator); // member will be inferred
        if (self.accept(.left_parenthesis) != null) {
            if (!self.peek_kind(.right_parenthesis)) {
                sum_val.sum_value.init = try self.assignment_expr();
            }
            _ = try self.expect(.right_parenthesis);
        }
        return sum_val;
    } else if (self.accept(.@"unreachable")) |token| {
        return ast_.AST.create_unreachable(token, self.allocator);
    } else {
        return self.literal();
    }
}

fn literal(self: *Self) Parser_Error_Enum!*ast_.AST {
    // FIXME: High Cyclo
    if (self.accept(.true)) |token| {
        return ast_.AST.create_true(token, self.allocator);
    } else if (self.accept(.false)) |token| {
        return ast_.AST.create_false(token, self.allocator);
    } else if (self.accept(.dec_int)) |token| {
        return ast_.AST.create_int(token, std.fmt.parseInt(i128, token.data, 10) catch return error.ParseError, self.allocator);
    } else if (self.accept(.hex_int)) |token| {
        return ast_.AST.create_int(token, std.fmt.parseInt(i128, token.data[2..], 16) catch return error.ParseError, self.allocator);
    } else if (self.accept(.oct_int)) |token| {
        return ast_.AST.create_int(token, std.fmt.parseInt(i128, token.data[2..], 8) catch return error.ParseError, self.allocator);
    } else if (self.accept(.bin_int)) |token| {
        return ast_.AST.create_int(token, std.fmt.parseInt(i128, token.data[2..], 2) catch return error.ParseError, self.allocator);
    } else if (self.accept(.float)) |token| {
        return ast_.AST.create_float(token, std.fmt.parseFloat(f64, token.data) catch return error.ParseError, self.allocator);
    } else if (self.accept(.char)) |token| {
        return ast_.AST.create_char(token, self.allocator);
    } else if (self.accept(.string)) |token| {
        return ast_.AST.create_string(token, resolve_escapes(token.data[1 .. token.data.len - 1], self.allocator), self.allocator);
    } else if (self.accept(.multi_line_string)) |token| {
        return ast_.AST.create_string(token, token.data, self.allocator);
    } else if (self.peek_kind(.left_brace)) {
        return try self.block_expr();
    } else if (self.peek_kind(.left_parenthesis)) {
        return try self.parens();
    } else {
        self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "an expression here", .got = self.peek() } });
        return Parser_Error_Enum.ParseError;
    }
}

fn block_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    const bracetoken_ = try self.expect(.left_brace);

    var statements = std.ArrayList(*ast_.AST).init(self.allocator);

    while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}

    if (self.peek_kind(.right_brace)) {
        _ = self.expect(.right_brace) catch {};
        return ast_.AST.create_unit_value(bracetoken_, self.allocator);
    }

    while (self.next_is_statement()) {
        statements.append(try self.statement()) catch unreachable;
        if (!self.peek_kind(.semicolon) and !self.peek_kind(.newline) and !self.peek_kind(.right_brace)) {
            self.errors.add_error(errs_.Error{ .expected_basic_token = .{
                .expected = "a semicolon or a newline here",
                .got = self.peek(),
            } });
            return error.ParseError;
        }
        while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}
    }

    while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}

    var final: ?*ast_.AST = null;
    if (self.accept(.@"break")) |token| {
        final = ast_.AST.create_break(token, self.allocator);
        while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}
    } else if (self.accept(.@"continue")) |token| {
        final = ast_.AST.create_continue(token, self.allocator);
        while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}
    } else if (self.accept(.@"return")) |token| {
        var exp: ?*ast_.AST = null;
        if (self.next_is_expr()) {
            exp = try self.assignment_expr();
        }
        final = ast_.AST.create_return(token, exp, self.allocator);
        while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}
    }

    if (self.peek_kind(.right_brace)) {
        _ = self.expect(.right_brace) catch {};
    } else {
        self.errors.add_error(errs_.Error{ .missing_close = .{ .expected = .right_brace, .got = self.peek(), .open = bracetoken_ } });
        return error.ParseError;
    }

    return ast_.AST.create_block(bracetoken_, statements, final, self.allocator);
}

fn if_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.@"if");
    const let: ?*ast_.AST = try self.let_pre();
    const cond = try self.assignment_expr();
    const body_block = try self.factor();
    var else_block: ?*ast_.AST = null;
    if (self.accept(.@"else")) |_| {
        else_block = try self.control_flow();
    }

    return ast_.AST.create_if(token, let, cond, body_block, else_block, self.allocator);
}

fn while_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.@"while");
    const let: ?*ast_.AST = try self.let_pre();
    const cond = try self.assignment_expr();
    var post: ?*ast_.AST = null;
    if (self.accept(.semicolon)) |_| {
        post = try self.statement();
    }
    const body_block = try self.block_expr();
    var else_block: ?*ast_.AST = null;
    if (self.accept(.@"else")) |_| {
        else_block = try self.control_flow();
    }

    return ast_.AST.create_while(token, let, cond, post, body_block, else_block, self.allocator);
}

fn for_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.@"for");
    const let: ?*ast_.AST = try self.let_pre();
    _ = self.accept(.mut);
    const elem = ast_.AST.create_identifier(try self.expect(.identifier), self.allocator);
    _ = try self.expect(.in);
    const iterable = try self.assignment_expr();
    const body_block = try self.block_expr();
    var else_block: ?*ast_.AST = null;
    if (self.accept(.@"else")) |_| {
        else_block = try self.control_flow();
    }

    return ast_.AST.create_for(token, let, elem, iterable, body_block, else_block, self.allocator);
}

fn fn_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    const introducer = try self.expect(.@"fn");
    var maybe_ident: ?*ast_.AST = null;

    if (self.accept(.identifier)) |token| {
        maybe_ident = ast_.AST.create_identifier(token, self.allocator);
    }
    const params = try self.paramlist();
    _ = try self.expect(.skinny_arrow);
    const ret_type = try self.bool_expr();
    const refinement: ?*ast_.AST = null;
    if (self.accept(.where)) |_| {
        _ = try self.arrow_expr();
    }

    const _init = try self.block_expr();

    return ast_.AST.create_fn_decl(
        introducer,
        maybe_ident,
        params,
        ret_type,
        refinement,
        _init,
        self.allocator,
    );
}

fn paramlist(self: *Self) Parser_Error_Enum!std.ArrayList(*ast_.AST) {
    var params = std.ArrayList(*ast_.AST).init(self.allocator);
    errdefer params.deinit();

    const token = try self.expect(.left_parenthesis);
    if (self.peek_kind(.mut) or self.peek_kind(.@"const") or self.peek_kind(.left_parenthesis) or self.peek_kind(.identifier)) {
        params.append(try self.param()) catch unreachable;

        while (self.accept(.comma)) |_| {
            params.append(try self.param()) catch unreachable;
        }
    }
    if (self.peek_kind(.right_parenthesis)) {
        _ = self.expect(.right_parenthesis) catch unreachable;
    } else {
        self.errors.add_error(errs_.Error{ .missing_close = .{ .expected = .right_parenthesis, .got = self.peek(), .open = token } });
        return error.ParseError;
    }

    return params;
}

fn param(self: *Self) Parser_Error_Enum!*ast_.AST {
    var kind: Symbol.Kind = undefined;
    if (self.accept(.mut) != null) {
        kind = .mut;
    } else if (self.accept(.@"const") != null) {
        kind = .@"const";
    } else {
        kind = .let;
    }
    const identifier = try self.expect(.identifier);
    const ident = ast_.AST.create_pattern_symbol(identifier, kind, identifier.data, self.allocator);

    var _type: *ast_.AST = undefined;
    var _init: ?*ast_.AST = null;

    _ = try self.expect(.single_colon);
    _type = try self.arrow_expr();
    // if (_type.* == .call) {
    //     _type = ast_.AST.create_comptime(_type.token(), _type, self.allocator);
    // }
    if (self.peek_kind(.single_equals)) {
        _ = try self.expect(.single_equals);
        _init = try self.arrow_expr();
    }

    return ast_.AST.create_decl(
        ident.token(),
        ident,
        _type,
        _init,
        false,
        self.allocator,
    );
}

fn trait_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    _ = try self.expect(.trait);
    const trait_name: Token = try self.expect(.identifier);
    _ = try self.expect(.left_brace);
    var method_decls = std.ArrayList(*ast_.AST).init(self.allocator);
    errdefer method_decls.deinit();
    var const_decls = std.ArrayList(*ast_.AST).init(self.allocator);
    errdefer const_decls.deinit();

    while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}
    while (self.peek_kind(.@"fn") or self.peek_kind(.virtual) or self.peek_kind(.@"const")) {
        if (self.peek_kind(.@"const")) {
            const_decls.append(try self.const_declaration()) catch unreachable;
        } else {
            method_decls.append(try self.method_declaration()) catch unreachable;
        }
        while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}
    }

    _ = try self.expect(.right_brace);
    return ast_.AST.create_trait(trait_name, method_decls, const_decls, self.allocator);
}

fn impl_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.impl);
    const trait_ident: ?*ast_.AST = if (!self.peek_kind(.@"for")) ast_.AST.create_identifier(try self.expect(.identifier), self.allocator) else null;
    _ = try self.expect(.@"for");
    const _type = try self.arrow_expr();
    _ = try self.expect(.left_brace);
    var method_defs = std.ArrayList(*ast_.AST).init(self.allocator);
    errdefer method_defs.deinit();
    var const_defs = std.ArrayList(*ast_.AST).init(self.allocator);
    errdefer const_defs.deinit();
    const retval = ast_.AST.create_impl(token, trait_ident, _type, method_defs, const_defs, self.allocator);

    while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}
    while (self.peek_kind(.@"fn") or self.peek_kind(.virtual) or self.peek_kind(.@"const")) {
        if (self.peek_kind(.@"const")) {
            const_defs.append(try self.const_declaration()) catch unreachable;
        } else {
            const method = try self.method_definition();
            method.method_decl.impl = retval;
            method_defs.append(method) catch unreachable;
        }
        while (self.accept(.semicolon) orelse self.accept(.newline)) |_| {}
    }
    _ = try self.expect(.right_brace);
    retval.impl.method_defs = method_defs;
    retval.impl.const_defs = const_defs;
    return retval;
}

fn method_declaration(self: *Self) Parser_Error_Enum!*ast_.AST {
    const virtual = self.accept(.virtual);
    const introducer = try self.expect(.@"fn");
    const name: *ast_.AST = ast_.AST.create_identifier(try self.expect(.identifier), self.allocator);

    const params_and_receiver = try self.method_paramlist();
    const params = params_and_receiver.params;
    const _receiver = params_and_receiver.receiver;

    _ = try self.expect(.skinny_arrow);
    const ret_type = try self.bool_expr();

    const refinement: ?*ast_.AST = null;
    if (self.accept(.where)) |_| {
        _ = try self.arrow_expr();
    }

    return ast_.AST.create_method_decl( // TODO: create `method_decl` ast
        introducer,
        name,
        virtual != null,
        _receiver,
        params,
        ret_type,
        refinement,
        null, // Won't have an init!
        self.allocator,
    );
}

fn method_definition(self: *Self) Parser_Error_Enum!*ast_.AST {
    const virtual = self.accept(.virtual);
    const introducer = try self.expect(.@"fn");
    const name: *ast_.AST = ast_.AST.create_identifier(try self.expect(.identifier), self.allocator);

    const params_and_receiver = try self.method_paramlist();
    const params = params_and_receiver.params;
    const _receiver = params_and_receiver.receiver;

    _ = try self.expect(.skinny_arrow);
    const ret_type = try self.bool_expr();

    const refinement: ?*ast_.AST = null;
    if (self.accept(.where)) |_| {
        _ = try self.arrow_expr();
    }

    const _init = try self.block_expr();

    return ast_.AST.create_method_decl( // TODO: create `method_def` ast
        introducer,
        name,
        virtual != null,
        _receiver,
        params,
        ret_type,
        refinement,
        _init,
        self.allocator,
    );
}

fn method_paramlist(self: *Self) Parser_Error_Enum!struct { receiver: ?*ast_.AST, params: std.ArrayList(*ast_.AST) } {
    var params = std.ArrayList(*ast_.AST).init(self.allocator);
    errdefer params.deinit();
    var _receiver: ?*ast_.AST = null;

    const token = try self.expect(.left_parenthesis);
    if (!self.peek_kind(.right_parenthesis)) {
        if (self.peek_kind(.self) or self.peek_kind(.ampersand)) {
            _receiver = try self.receiver();
        } else {
            params.append(try self.param()) catch unreachable;
        }
        while (self.accept(.comma)) |_| {
            params.append(try self.param()) catch unreachable;
        }
    }
    if (self.peek_kind(.right_parenthesis)) {
        _ = self.expect(.right_parenthesis) catch unreachable;
    } else {
        self.errors.add_error(errs_.Error{ .missing_close = .{ .expected = .right_parenthesis, .got = self.peek(), .open = token } });
        return error.ParseError;
    }

    return .{ .receiver = _receiver, .params = params };
}

fn receiver(self: *Self) Parser_Error_Enum!*ast_.AST {
    var kind: ast_.Receiver_Kind = .value;
    if (self.accept(.ampersand)) |_| {
        if (self.accept(.mut)) |_| {
            kind = .mut_addr_of;
        } else {
            kind = .addr_of;
        }
    }
    const token = try self.expect(.self);
    return ast_.AST.create_receiver(token, kind, self.allocator);
}

fn match_expr(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.match);
    var mappings = std.ArrayList(*ast_.AST).init(self.allocator);
    const let: ?*ast_.AST = try self.let_pre();
    const exp = try self.assignment_expr();

    _ = try self.expect(.left_brace);
    while (self.accept(.newline)) |_| {}

    while (!self.peek_kind(.right_brace)) {
        if (self.next_is_expr() or self.peek().kind == .mut) {
            mappings.append(try self.match_mapping()) catch unreachable;
        } else {
            self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "match mapping here", .got = self.peek() } });
            return error.ParseError;
        }
    }
    _ = try self.expect(.right_brace);

    if (mappings.items.len == 0) {
        self.errors.add_error(errs_.Error{ .basic = .{ .span = token.span, .msg = "match has no patterns" } });
        return error.ParseError;
    }

    return ast_.AST.create_match(token, let, exp, mappings, self.allocator);
}

fn match_mapping(self: *Self) Parser_Error_Enum!*ast_.AST {
    var lhs = try self.match_pattern_sum_value();
    _ = try self.expect(.fat_arrow);
    const rhs = try self.assignment_expr();
    if (!self.peek_kind(.right_brace)) {
        _ = try self.expect(.newline);
    }

    return ast_.AST.create_mapping(lhs.token(), lhs, rhs, self.allocator);
}

fn match_pattern_sum_value(self: *Self) Parser_Error_Enum!*ast_.AST {
    const exp = try self.match_pattern_atom();
    if (self.accept(.left_parenthesis)) |_| {
        const retval = ast_.AST.create_sum_value(exp.token(), self.allocator);
        if (exp.* == .select) {
            retval.sum_value.base = exp.lhs();
            retval.common()._token = exp.rhs().token();
        }
        retval.sum_value.init = try self.match_pattern_atom();
        _ = try self.expect(.right_parenthesis);
        return retval;
    } else {
        return exp;
    }
}

fn match_pattern_atom(self: *Self) Parser_Error_Enum!*ast_.AST {
    if (self.accept(.mut)) |_| {
        const identifier = try self.expect(.identifier);
        return ast_.AST.create_pattern_symbol(identifier, .mut, identifier.data, self.allocator);
    } else if (self.accept(.identifier)) |token| {
        if (self.peek_kind(.period)) {
            var exp = ast_.AST.create_identifier(token, self.allocator);
            while (self.accept(.period)) |_| {
                exp = ast_.AST.create_select(
                    token,
                    exp,
                    ast_.AST.create_field(try self.expect(.identifier), self.allocator),
                    self.allocator,
                );
            }
            return exp;
        } else {
            return ast_.AST.create_pattern_symbol(token, .let, token.data, self.allocator);
        }
    } else if (self.accept(.period)) |_| {
        const sum_val = ast_.AST.create_sum_value(try self.expect(.identifier), self.allocator); // member will be inferred
        if (self.accept(.left_parenthesis) != null) {
            if (!self.peek_kind(.right_parenthesis)) {
                sum_val.sum_value.init = try self.match_pattern_product();
            }
            _ = try self.expect(.right_parenthesis);
        }
        return sum_val;
    } else if (self.accept(.left_parenthesis)) |_| {
        const pattern = try self.match_pattern_product();
        _ = try self.expect(.right_parenthesis);
        return pattern;
    } else {
        return self.literal();
    }
}

fn match_pattern_product(self: *Self) Parser_Error_Enum!*ast_.AST {
    const exp = try self.match_pattern_sum_value();
    var terms: ?std.ArrayList(*ast_.AST) = null;
    var firsttoken_: ?Token = null;
    while (self.accept(.comma)) |token| {
        if (terms == null) {
            terms = std.ArrayList(*ast_.AST).init(self.allocator);
            firsttoken_ = token;
            terms.?.append(exp) catch unreachable;
        }
        terms.?.append(try self.match_pattern_sum_value()) catch unreachable;
    }
    if (terms) |terms_list| {
        return ast_.AST.create_product(firsttoken_.?, terms_list, self.allocator);
    } else {
        return exp;
    }
}

fn parens(self: *Self) Parser_Error_Enum!*ast_.AST {
    const token = try self.expect(.left_parenthesis);
    var exp: ?*ast_.AST = null;
    if (self.next_is_expr()) {
        exp = try self.parse_expr();
    }
    if (self.peek_kind(.right_parenthesis)) {
        _ = self.expect(.right_parenthesis) catch {};
    } else {
        self.errors.add_error(errs_.Error{ .missing_close = .{ .expected = .right_parenthesis, .got = self.peek(), .open = token } });
        return error.ParseError;
    }

    return exp orelse ast_.AST.create_unit_type(token, self.allocator);
}

fn resolve_escapes(input: []const u8, allocator: std.mem.Allocator) []const u8 {
    // FIXME: High Cyclo
    var retval = std.ArrayList(u8).init(allocator);
    var escape = false;
    var skip: i8 = 0;
    for (input, 0..) |byte, j| {
        if (skip > 0) {
            skip -= 1;
            continue;
        } else if (escape) {
            escape = false;
            if (byte == 'n') {
                retval.append(0x0A) catch unreachable;
            } else if (byte == 'r') {
                retval.append(0x0D) catch unreachable;
            } else if (byte == 't') {
                retval.append(0x09) catch unreachable;
            } else if (byte == '\\') {
                retval.append(0x5C) catch unreachable;
            } else if (byte == '\'') {
                retval.append(0x27) catch unreachable;
            } else if (byte == '"') {
                retval.append(0x22) catch unreachable;
            } else if (byte == 'x') {
                retval.append(get_nibble(input[j + 1]) * 16 + get_nibble(input[j + 2])) catch unreachable;
                skip = 2;
            } else {
                std.debug.panic("compiler error: unknown escape sequence '{c}'", .{byte});
            }
        } else {
            if (byte == '\\') {
                escape = true;
            } else {
                retval.append(byte) catch unreachable;
            }
        }
    }

    return retval.items;
}

fn get_nibble(c: u8) u8 {
    if ('0' <= c and c <= '9') {
        return c - '0';
    } else if ('a' <= c and c <= 'f') {
        return c - 'a' + 10;
    } else if ('A' <= c and c <= 'F') {
        return c - 'A' + 10;
    } else {
        unreachable;
    }
}
