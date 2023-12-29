const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const token_ = @import("token.zig");

const ParserErrorEnum = error{
    ParseError, // For general parsing errors. Error is logged in errors.zig.errors. Likely
    NotCompileTimeKnown,
    InvalidCharacter, // If parsing a float goes wrong. Likely
    Overflow, // If parsing an integer goes wrong. Unlikely
};

pub const Parser = struct {
    tokens: *std.ArrayList(token_.Token),
    cursor: usize,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,

    pub fn init(tokens: *std.ArrayList(token_.Token), errors: *errs_.Errors, allocator: std.mem.Allocator) Parser {
        return .{
            .tokens = tokens,
            .cursor = 0,
            .allocator = allocator,
            .errors = errors,
        };
    }

    fn peek(self: *Parser) token_.Token {
        return self.tokens.items[self.cursor];
    }

    fn peek_kind(self: *Parser, kind: token_.TokenKind) bool {
        return self.peek().kind == kind;
    }

    fn next_is_expr(self: *Parser) bool {
        const nextKind = self.peek().kind;
        return nextKind == .exclamation_mark or
            nextKind == .true or
            nextKind == .false or
            nextKind == .question_mark or
            nextKind == .period or
            nextKind == .ampersand or
            nextKind == .left_parenthesis or
            nextKind == .left_square or
            nextKind == .left_brace or
            nextKind == .bar or
            nextKind == .minus or
            nextKind == .match or
            nextKind == .@"fn" or
            nextKind == .@"for" or
            nextKind == .@"if" or
            nextKind == .@"try" or
            nextKind == .@"comptime" or
            nextKind == .@"unreachable" or
            nextKind == .@"while" or
            nextKind == .identifier or
            nextKind == .bin_int or
            nextKind == .char or
            nextKind == .hex_int or
            nextKind == .dec_int or
            nextKind == .oct_int or
            nextKind == .float or
            nextKind == .string or
            nextKind == .multi_line_string or
            nextKind == .not or
            nextKind == .at_symbol;
    }

    fn next_is_statement(self: *Parser) bool {
        const nextKind = self.peek().kind;
        return nextKind == .let or nextKind == .@"defer" or nextKind == .@"errdefer" or self.next_is_expr();
    }

    /// Returns the next token if its kind matches the given kind, otherwise
    /// null
    fn accept(self: *Parser, kind: token_.TokenKind) ?token_.Token {
        const token = self.peek();
        if (token.kind == kind) {
            self.cursor += 1;
            return token;
        } else {
            return null;
        }
    }

    /// Returns the token with an expected kind, or throws an error.
    fn expect(self: *Parser, kind: token_.TokenKind) ParserErrorEnum!token_.Token {
        if (self.accept(kind)) |token| {
            return token;
        } else {
            self.errors.add_error(errs_.Error{ .expected2token = .{ .expected = kind, .got = self.peek() } });
            return ParserErrorEnum.ParseError;
        }
    }

    /// Parses a token stream a file into a list of declaration ASTs
    pub fn parse(self: *Parser) ParserErrorEnum!std.ArrayList(*ast_.AST) {
        var decls = std.ArrayList(*ast_.AST).init(self.allocator);
        while (self.accept(.newline)) |_| {}
        while (!self.peek_kind(.EOF)) {
            decls.append(try self.top_level_declaration()) catch unreachable;
            while (self.accept(.newline)) |_| {}
        }
        _ = try self.expect(.EOF);
        return decls;
    }

    fn top_level_declaration(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.peek_kind(.@"fn")) {
            return try self.fn_declaration();
        } else if (self.peek_kind(.let)) {
            var decl: *ast_.AST = try self.let_declaration();
            if (!self.peek_kind(.EOF)) {
                _ = try self.expect(.newline);
            }
            decl.decl.top_level = true;
            return decl;
        } else {
            self.errors.add_error(errs_.Error{ .expected_basic_token = .{
                .expected = "`fn` or `let` declaration in the top level",
                .got = self.peek(),
            } });
            return ParserErrorEnum.ParseError;
        }
    }

    fn let_declaration(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.let);

        const ident = try self.let_pattern_atom();
        var _type: ?*ast_.AST = null;
        var _init: ?*ast_.AST = null;

        if (self.accept(.colon)) |_| {
            _type = try self.inject_expr();
            if (self.peek_kind(.single_equals)) {
                _ = try self.expect(.single_equals);
                _init = try self.inject_expr();
            }
        } else if (self.accept(.single_equals)) |_| {
            _init = try self.inject_expr();
        } else {
            self.errors.add_error(errs_.Error{ .basic = .{
                .span = self.peek().span,
                .msg = "variable declarations require at least a type or an intial value",
            } });
            return error.ParseError;
        }

        return ast_.AST.create_decl(
            token,
            ident,
            _type orelse ast_.AST.create_type_of(token, _init.?, self.allocator), // type inference done here!
            _init orelse ast_.AST.create_default(token, _type.?, self.allocator), // default value generate done here!
            self.allocator,
        );
    }

    fn let_pattern_atom(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.peek_kind(.mut) or self.peek_kind(.@"const") or self.peek_kind(.identifier)) {
            var kind: symbol_.SymbolKind = undefined;
            if (self.accept(.mut) != null) {
                kind = .mut;
            } else if (self.accept(.@"const") != null) {
                kind = .@"const";
            } else {
                kind = .let;
            }
            const identifier = try self.expect(.identifier);
            return ast_.AST.create_symbol(identifier, kind, identifier.data, self.allocator);
        } else if (self.accept(.left_parenthesis)) |_| {
            const res = try self.let_pattern_product();
            _ = try self.expect(.right_parenthesis);
            return res;
        } else {
            self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "a pattern after `let`", .got = self.peek() } });
            return ParserErrorEnum.ParseError;
        }
    }

    fn let_pattern_product(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.let_pattern_atom();
        var terms: ?std.ArrayList(*ast_.AST) = null;
        var firsttoken_: ?token_.Token = null;
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

    fn let_pre(self: *Parser) ParserErrorEnum!?*ast_.AST {
        var retval: ?*ast_.AST = null;
        if (self.peek_kind(.let)) {
            retval = try self.let_declaration();
            if (self.peek_kind(.semicolon)) {
                _ = self.expect(.semicolon) catch {};
            } else {
                self.errors.add_error(errs_.Error{ .expected_basic_token = .{
                    .expected = "a semicolon separating declaration and condition",
                    .got = self.peek(),
                } });
                return error.ParseError;
            }
        }
        return retval;
    }

    fn statement(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.peek_kind(.let)) {
            return self.let_declaration();
        } else if (self.accept(.@"defer")) |token| {
            return ast_.AST.create_defer(token, try self.expr(), self.allocator);
        } else if (self.accept(.@"errdefer")) |token| {
            return ast_.AST.create_errdefer(token, try self.expr(), self.allocator);
        } else if (self.next_is_expr()) {
            return self.assignment_expr();
        } else {
            self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "a statement", .got = self.peek() } });
            return ParserErrorEnum.ParseError;
        }
    }

    fn expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        return self.sum_type();
    }

    fn sum_type(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.product_expr();
        var terms: ?std.ArrayList(*ast_.AST) = null;
        var firsttoken_: ?token_.Token = null;
        while (self.accept(.bar)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*ast_.AST).init(self.allocator);
                firsttoken_ = token;
                terms.?.append(exp) catch unreachable;
            }
            if (self.peek_kind(.right_parenthesis)) {
                // Trailing bar, break out
                break;
            }
            terms.?.append(try self.annotation_expr()) catch unreachable;
        }
        if (terms) |terms_list| {
            return ast_.AST.create_sum(firsttoken_.?, terms_list, self.allocator);
        } else {
            return exp;
        }
    }

    fn product_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.annotation_expr();
        var terms: ?std.ArrayList(*ast_.AST) = null;
        var firsttoken_: ?token_.Token = null;
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

    fn annotation_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.assignment_expr();
        if (self.accept(.colon)) |token| {
            const _type = try self.inject_expr();
            var predicate: ?*ast_.AST = null;
            var _init: ?*ast_.AST = null;
            if (self.accept(.where)) |_| {
                predicate = try self.inject_expr();
            }
            if (self.accept(.single_equals)) |_| {
                const pre__init = try self.inject_expr();
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

    fn assignment_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.inject_expr();
        if (self.accept(.single_equals)) |token| {
            if (exp.* == .identifier and std.mem.eql(u8, exp.token().data, "_")) {
                // TODO: With new pattern matching is this needed?
                return ast_.AST.create_discard(token, try self.inject_expr(), self.allocator);
            } else {
                return ast_.AST.create_assign(token, exp, try self.inject_expr(), self.allocator);
            }
        } else if (self.accept(.plus_equals)) |token| {
            return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else if (self.accept(.minus_equals)) |token| {
            return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else if (self.accept(.star_equals)) |token| {
            return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else if (self.accept(.slash_equals)) |token| {
            return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else if (self.accept(.percent_equals)) |token| {
            return ast_.AST.create_assign(token, exp, ast_.AST.create_binop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else {
            return exp;
        }
    }

    fn inject_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.arrow_expr();
        if (self.accept(.left_skinny_arrow)) |token| {
            return ast_.AST.create_inject(token, exp, try self.arrow_expr(), self.allocator);
        }
        return exp;
    }

    fn arrow_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.bool_expr();
        while (self.accept(.right_skinny_arrow)) |token| {
            exp = ast_.AST.create_function(token, exp, try self.bool_expr(), self.allocator);
        }
        return exp;
    }

    fn bool_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
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

    fn comparison_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
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

    fn coalesce_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
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

    fn int_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
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

    fn term_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
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

    fn prefix_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.accept(.not)) |token| {
            return ast_.AST.create_not(token, try self.prefix_expr(), self.allocator);
        } else if (self.accept(.@"comptime")) |token| {
            return ast_.AST.create_comptime(token, try self.invoke_expr(), self.allocator);
        } else if (self.accept(.at_symbol)) |_| {
            if (self.accept(.typeof)) |token| {
                _ = try self.expect(.left_parenthesis);
                const exp = try self.annotation_expr();
                _ = try self.expect(.right_parenthesis);
                return ast_.AST.create_type_of(token, exp, self.allocator);
            } else if (self.accept(.default)) |token| {
                _ = try self.expect(.left_parenthesis);
                const exp = try self.annotation_expr();
                _ = try self.expect(.right_parenthesis);
                return ast_.AST.create_default(token, exp, self.allocator);
            } else if (self.accept(.sizeof)) |token| {
                _ = try self.expect(.left_parenthesis);
                const exp = try self.annotation_expr();
                _ = try self.expect(.right_parenthesis);
                return ast_.AST.create_size_of(token, exp, self.allocator);
            } else {
                self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "a built-in function", .got = self.peek() } });
                return error.ParseError;
            }
        } else if (self.accept(.minus)) |token| {
            return ast_.AST.create_negate(token, try self.prefix_expr(), self.allocator);
        } else if (self.accept(.ampersand)) |token| {
            const mut = self.accept(.mut);
            return ast_.AST.create_addr_of(token, try self.prefix_expr(), mut != null, self.allocator);
        } else if (self.accept(.left_square)) |token| {
            var sliceKind: ast_.Slice_Kind = undefined;
            var len: ?*ast_.AST = null;
            if (self.accept(.mut)) |_| {
                sliceKind = .mut;
            } else if (self.accept(.star)) |_| {
                sliceKind = .multiptr;
            } else if (self.next_is_expr()) {
                sliceKind = .array;
                len = try self.inject_expr();
                if (!len.?.is_comptime_expr()) {
                    self.errors.add_error(errs_.Error{ .comptime_known = .{ .span = len.?.token().span, .what = "array lengths" } });
                    return error.NotCompileTimeKnown;
                }
            } else {
                sliceKind = .slice;
            }
            if (self.peek_kind(.right_square)) {
                _ = self.expect(.right_square) catch {};
            } else {
                self.errors.add_error(errs_.Error{ .missing_close = .{ .expected = .right_square, .got = self.peek(), .open = token } });
                return error.ParseError;
            }
            if (sliceKind == .array) {
                return ast_.AST.create_array_of(token, try self.prefix_expr(), len.?, self.allocator);
            } else {
                return ast_.AST.create_slice_of(token, try self.prefix_expr(), sliceKind, self.allocator);
            }
        } else if (self.accept(.question_mark)) |_| {
            return ast_.AST.create_optional_type(try self.invoke_expr(), self.allocator);
        } else if (self.accept(.@"try")) |token| {
            return ast_.AST.create_try(token, try self.invoke_expr(), self.allocator);
        } else {
            return try self.invoke_expr();
        }
    }

    fn invoke_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.postfix_expr();
        while (self.accept(.invoke)) |token| {
            exp = ast_.AST.create_invoke(token, exp, try self.postfix_expr(), self.allocator);
        }
        return exp;
    }

    fn postfix_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.control_flow();
        while (true) {
            if (self.peek_kind(.left_parenthesis)) {
                exp = ast_.AST.create_call(self.peek(), exp, try self.call_args(), self.allocator);
            } else if (self.accept(.left_square)) |token| {
                var first: ?*ast_.AST = null;
                if (self.next_is_expr()) {
                    first = try self.expr();
                }
                if (self.accept(.double_period)) |_| {
                    var second: ?*ast_.AST = null;
                    if (self.next_is_expr()) {
                        second = try self.expr();
                    }
                    exp = ast_.AST.create_sub_slice(token, exp, first, second, self.allocator);
                } else {
                    // Simple index
                    exp = ast_.AST.create_index(token, exp, first orelse {
                        self.errors.add_error(errs_.Error{ .expected_basic_token = .{
                            .expected = "an expression within index",
                            .got = self.peek(),
                        } });
                        return ParserErrorEnum.ParseError;
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
            } else if (self.accept(.caret)) |token| {
                exp = ast_.AST.create_dereference(token, exp, self.allocator);
            } else {
                return exp;
            }
        }
    }

    fn call_args(self: *Parser) ParserErrorEnum!std.ArrayList(*ast_.AST) {
        _ = try self.expect(.left_parenthesis);
        var retval = std.ArrayList(*ast_.AST).init(self.allocator);
        if (!self.peek_kind(.right_parenthesis)) {
            retval.append(try self.annotation_expr()) catch unreachable;
            while (self.accept(.comma)) |_| {
                retval.append(try self.annotation_expr()) catch unreachable;
            }
        }
        _ = try self.expect(.right_parenthesis);
        return retval;
    }

    fn control_flow(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.peek_kind(.@"if")) {
            return try self.if_expr();
        } else if (self.peek_kind(.@"while")) {
            return try self.while_expr();
        } else if (self.peek_kind(.match)) {
            return try self.match_expr();
        } else if (self.peek_kind(.@"for")) {
            return try self.for_expr();
        } else {
            return try self.factor();
        }
    }

    fn factor(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.accept(.identifier)) |token| {
            return ast_.AST.create_identifier(token, self.allocator);
        } else if (self.peek_kind(.@"fn")) {
            return self.fn_declaration();
        } else {
            return self.literal();
        }
    }

    fn literal(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.accept(.true)) |token| {
            return ast_.AST.create_true(token, self.allocator);
        } else if (self.accept(.false)) |token| {
            return ast_.AST.create_false(token, self.allocator);
        } else if (self.accept(.dec_int)) |token| {
            return ast_.AST.create_int(token, try std.fmt.parseInt(i128, token.data, 10), self.allocator);
        } else if (self.accept(.hex_int)) |token| {
            return ast_.AST.create_int(token, try std.fmt.parseInt(i128, token.data[2..], 16), self.allocator);
        } else if (self.accept(.oct_int)) |token| {
            return ast_.AST.create_int(token, try std.fmt.parseInt(i128, token.data[2..], 8), self.allocator);
        } else if (self.accept(.bin_int)) |token| {
            return ast_.AST.create_int(token, try std.fmt.parseInt(i128, token.data[2..], 2), self.allocator);
        } else if (self.accept(.float)) |token| {
            return ast_.AST.create_float(token, try std.fmt.parseFloat(f64, token.data), self.allocator);
        } else if (self.accept(.char)) |token| {
            return ast_.AST.create_char(token, self.allocator);
        } else if (self.accept(.string)) |token| {
            return ast_.AST.create_string(token, resolve_escapes(token.data[1 .. token.data.len - 1], self.allocator), self.allocator);
        } else if (self.accept(.multi_line_string)) |token| {
            return ast_.AST.create_string(token, token.data, self.allocator);
        } else if (self.peek_kind(.left_brace)) {
            return try self.block_expr();
        } else if (self.accept(.period)) |token| {
            const field = ast_.AST.create_field(try self.expect(.identifier), self.allocator);
            return ast_.AST.create_inferred_member(token, field, self.allocator);
        } else if (self.accept(.@"unreachable")) |token| {
            return ast_.AST.create_unreachable(token, self.allocator);
        } else if (self.peek_kind(.left_parenthesis)) {
            return try self.parens();
        } else {
            self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "an expression", .got = self.peek() } });
            return ParserErrorEnum.ParseError;
        }
    }

    fn block_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
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
                    .expected = "a semicolon or a newline after statement",
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
                exp = try self.expr();
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

    fn if_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.@"if");
        const let: ?*ast_.AST = try self.let_pre();
        const cond = try self.expr();
        const bodyBlock = try self.factor();
        var else_block: ?*ast_.AST = null;
        if (self.accept(.@"else")) |_| {
            else_block = try self.control_flow();
        }

        return ast_.AST.create_if(token, let, cond, bodyBlock, else_block, self.allocator);
    }

    fn while_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.@"while");
        const let: ?*ast_.AST = try self.let_pre();
        const cond = try self.expr();
        var post: ?*ast_.AST = null;
        if (self.accept(.semicolon)) |_| {
            post = try self.statement();
        }
        const bodyBlock = try self.block_expr();
        var else_block: ?*ast_.AST = null;
        if (self.accept(.@"else")) |_| {
            else_block = try self.control_flow();
        }

        return ast_.AST.create_while(token, let, cond, post, bodyBlock, else_block, self.allocator);
    }

    fn for_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.@"for");
        const let: ?*ast_.AST = try self.let_pre();
        _ = self.accept(.mut);
        const elem = ast_.AST.create_identifier(try self.expect(.identifier), self.allocator);
        _ = try self.expect(.in);
        const iterable = try self.expr();
        const bodyBlock = try self.block_expr();
        var else_block: ?*ast_.AST = null;
        if (self.accept(.@"else")) |_| {
            else_block = try self.control_flow();
        }

        return ast_.AST.create_for(token, let, elem, iterable, bodyBlock, else_block, self.allocator);
    }

    fn fn_declaration(self: *Parser) ParserErrorEnum!*ast_.AST {
        const introducer = try self.expect(.@"fn");
        var maybeIdent: ?*ast_.AST = null;

        if (self.accept(.identifier)) |token| {
            maybeIdent = ast_.AST.create_identifier(token, self.allocator);
        }
        const params = try self.paramlist();
        _ = try self.expect(.right_skinny_arrow);
        const inferred_errortoken_ = self.accept(.exclamation_mark);
        var ret_type = try self.bool_expr();
        if (inferred_errortoken_ != null) {
            ret_type = ast_.AST.create_inferred_error(inferred_errortoken_.?, ret_type, self.allocator);
        }

        const refinement: ?*ast_.AST = null;
        if (self.accept(.where)) |_| {
            _ = try self.inject_expr();
        }

        const _init = try self.block_expr();

        return ast_.AST.create_fn_decl(
            introducer,
            maybeIdent,
            params,
            ret_type,
            refinement,
            _init,
            false,
            self.allocator,
        );
    }

    fn paramlist(self: *Parser) ParserErrorEnum!std.ArrayList(*ast_.AST) {
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

    fn param(self: *Parser) ParserErrorEnum!*ast_.AST {
        var ident = try self.let_pattern_atom();
        var _type: *ast_.AST = undefined;
        var _init: ?*ast_.AST = null;

        _ = try self.expect(.colon);
        _type = try self.inject_expr();
        if (self.peek_kind(.single_equals)) {
            _ = try self.expect(.single_equals);
            _init = try self.inject_expr();
        }

        return ast_.AST.create_decl(
            ident.token(),
            ident,
            _type,
            _init orelse ast_.AST.create_default(_type.token(), _type, self.allocator),
            self.allocator,
        );
    }

    fn match_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.match);
        var mappings = std.ArrayList(*ast_.AST).init(self.allocator);
        const let: ?*ast_.AST = try self.let_pre();
        const exp = try self.expr();

        _ = try self.expect(.left_brace);
        while (self.accept(.newline)) |_| {}

        var has_else = false;
        while (!self.peek_kind(.right_brace)) {
            if (self.peek_kind(.@"else")) {
                mappings.append(try self.match_else()) catch unreachable;
                has_else = true;
                break;
            } else if (self.next_is_expr()) {
                mappings.append(try self.match_mapping()) catch unreachable;
            } else {
                self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "`else` or match mapping", .got = self.peek() } });
                return error.ParseError;
            }
        }
        _ = try self.expect(.right_brace);

        if (mappings.items.len == 0) {
            self.errors.add_error(errs_.Error{ .basic = .{ .span = token.span, .msg = "match has no patterns" } });
            return error.ParseError;
        }

        return ast_.AST.create_match(token, let, exp, mappings, has_else, self.allocator);
    }

    fn match_mapping(self: *Parser) ParserErrorEnum!*ast_.AST {
        var lhs = try self.match_pattern_inject();
        _ = try self.expect(.right_fat_arrow);
        const rhs = try self.expr();
        if (!self.peek_kind(.right_brace)) {
            _ = try self.expect(.newline);
        }

        return ast_.AST.create_mapping(lhs.token(), lhs, rhs, self.allocator);
    }

    fn match_else(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.@"else");
        if (self.peek_kind(.right_fat_arrow)) {
            _ = self.expect(.right_fat_arrow) catch {};
        } else {
            self.errors.add_error(errs_.Error{ .expected_basic_token = .{ .expected = "`=>` after `else`", .got = self.peek() } });
            return error.ParseError;
        }
        const rhs = try self.expr();
        if (!self.peek_kind(.right_brace)) {
            _ = try self.expect(.newline);
        }

        return ast_.AST.create_mapping(token, null, rhs, self.allocator);
    }

    fn match_pattern_product(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.match_pattern_inject();
        var terms: ?std.ArrayList(*ast_.AST) = null;
        var firsttoken_: ?token_.Token = null;
        while (self.accept(.comma)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*ast_.AST).init(self.allocator);
                firsttoken_ = token;
                terms.?.append(exp) catch unreachable;
            }
            terms.?.append(try self.match_pattern_inject()) catch unreachable;
        }
        if (terms) |terms_list| {
            return ast_.AST.create_product(firsttoken_.?, terms_list, self.allocator);
        } else {
            return exp;
        }
    }

    fn match_pattern_inject(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.match_pattern_atom();
        if (self.accept(.left_skinny_arrow)) |token| {
            const rhs = try self.match_pattern_atom();
            return ast_.AST.create_inject(token, exp, rhs, self.allocator);
        } else {
            return exp;
        }
    }

    fn match_pattern_atom(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.accept(.mut)) |_| {
            const identifier = try self.expect(.identifier);
            return ast_.AST.create_symbol(identifier, .mut, identifier.data, self.allocator);
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
                return ast_.AST.create_symbol(token, .let, token.data, self.allocator);
            }
        } else if (self.accept(.left_parenthesis)) |_| {
            const pattern = try self.match_pattern_product();
            _ = try self.expect(.right_parenthesis);
            return pattern;
        } else {
            return self.literal();
        }
    }

    fn parens(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.left_parenthesis);
        var exp: ?*ast_.AST = null;
        if (self.next_is_expr()) {
            exp = try self.expr();
        }
        if (self.peek_kind(.right_parenthesis)) {
            _ = self.expect(.right_parenthesis) catch {};
        } else {
            self.errors.add_error(errs_.Error{ .missing_close = .{ .expected = .right_parenthesis, .got = self.peek(), .open = token } });
            return error.ParseError;
        }

        return exp orelse ast_.AST.create_unit_type(token, self.allocator);
    }
};

fn resolve_escapes(input: []const u8, allocator: std.mem.Allocator) []const u8 {
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
                std.debug.print("Unknown escape sequence '{c}'\n", .{byte});
                unreachable;
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
