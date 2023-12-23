const std = @import("std");
const ast_ = @import("ast.zig");
const errs_ = @import("errors.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const token_ = @import("token.zig");

const ParserErrorEnum = error{
    parseError, // For general parsing errors. Error is logged in errors.zig.errors. Likely
    not_comptime_known,
    InvalidCharacter, // If parsing a float goes wrong. Likely
    Overflow, // If parsing an integer goes wrong. Unlikely
};

pub const Parser = struct {
    tokens: *std.ArrayList(token_.Token),
    cursor: usize,
    errors: *errs_.Errors,
    allocator: std.mem.Allocator,

    pub fn init(tokens: *std.ArrayList(token_.Token), errors: *errs_.Errors, allocator: std.mem.Allocator) Parser {
        return .{ //
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
        return nextKind == .E_MARK //
        or nextKind == .TRUE //
        or nextKind == .FALSE //
        or nextKind == .Q_MARK //
        or nextKind == .PERIOD //
        or nextKind == .AMPERSAND //
        or nextKind == .L_PAREN //
        or nextKind == .L_SQUARE //
        or nextKind == .L_BRACE //
        or nextKind == .BAR //
        or nextKind == .MINUS //
        or nextKind == .MATCH //
        or nextKind == .CASE //
        or nextKind == .FN //
        or nextKind == .FOR //
        or nextKind == .IF //
        or nextKind == .TRY //
        or nextKind == .COMPTIME //
        or nextKind == .UNREACHABLE //
        or nextKind == .WHILE //
        or nextKind == .IDENTIFIER //
        or nextKind == .BIN_INTEGER //
        or nextKind == .CHAR //
        or nextKind == .HEX_INTEGER //
        or nextKind == .DECIMAL_INTEGER //
        or nextKind == .OCT_INTEGER //
        or nextKind == .FLOAT //
        or nextKind == .STRING //
        or nextKind == .MULTI_LINE //
        or nextKind == .NOT or
            nextKind == .AT;
    }

    fn next_is_statement(self: *Parser) bool {
        const nextKind = self.peek().kind;
        return nextKind == .LET or nextKind == .DEFER or nextKind == .ERRDEFER or self.next_is_expr();
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
            self.errors.addError(errs_.Error{ .expected2Token = .{ .expected = kind, .got = self.peek() } });
            return ParserErrorEnum.parseError;
        }
    }

    /// Parses a token stream a file into a list of declaration ASTs
    pub fn parse(self: *Parser) ParserErrorEnum!std.ArrayList(*ast_.AST) {
        var decls = std.ArrayList(*ast_.AST).init(self.allocator);
        while (self.accept(.NEWLINE)) |_| {}
        while (!self.peek_kind(.EOF)) {
            decls.append(try self.top_level_declaration()) catch unreachable;
            while (self.accept(.NEWLINE)) |_| {}
        }
        _ = try self.expect(.EOF);
        return decls;
    }

    fn top_level_declaration(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.peek_kind(.FN)) {
            return try self.fn_declaration();
        } else if (self.peek_kind(.LET)) {
            var decl: *ast_.AST = try self.let_declaration();
            if (!self.peek_kind(.EOF)) {
                _ = try self.expect(.NEWLINE);
            }
            decl.decl.top_level = true;
            return decl;
        } else {
            self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "`fn` or `let` declaration in the top level", .got = self.peek() } });
            return ParserErrorEnum.parseError;
        }
    }

    fn let_declaration(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.LET);

        const ident = try self.let_pattern_atom();
        var _type: ?*ast_.AST = null;
        var _init: ?*ast_.AST = null;

        if (self.accept(.COLON)) |_| {
            _type = try self.inject_expr();
            if (self.peek_kind(.EQUALS)) {
                _ = try self.expect(.EQUALS);
                _init = try self.inject_expr();
            }
        } else if (self.accept(.EQUALS)) |_| {
            _init = try self.inject_expr();
        } else {
            self.errors.addError(errs_.Error{ .basic = .{ .span = self.peek().span, .msg = "variable declarations require at least a type or an intial value" } });
            return error.parseError;
        }

        return ast_.AST.createDecl(
            token,
            ident,
            _type orelse ast_.AST.createTypeOf(token, _init.?, self.allocator), // type inference done here!
            _init orelse ast_.AST.createDefault(token, _type.?, self.allocator), // default value generate done here!
            self.allocator,
        );
    }

    fn let_pattern_atom(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.peek_kind(.MUT) or self.peek_kind(.CONST) or self.peek_kind(.IDENTIFIER)) {
            var kind: symbol_.SymbolKind = undefined;
            if (self.accept(.MUT) != null) {
                kind = .mut;
            } else if (self.accept(.CONST) != null) {
                kind = ._const;
            } else {
                kind = .let;
            }
            const identifier = try self.expect(.IDENTIFIER);
            return ast_.AST.createSymbol(identifier, kind, identifier.data, self.allocator);
        } else if (self.accept(.L_PAREN)) |_| {
            const res = try self.let_pattern_product();
            _ = try self.expect(.R_PAREN);
            return res;
        } else {
            self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "a pattern after `let`", .got = self.peek() } });
            return ParserErrorEnum.parseError;
        }
    }

    fn let_pattern_product(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.let_pattern_atom();
        var terms: ?std.ArrayList(*ast_.AST) = null;
        var firsttoken_: ?token_.Token = null;
        while (self.accept(.COMMA)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*ast_.AST).init(self.allocator);
                firsttoken_ = token;
                terms.?.append(exp) catch unreachable;
            }
            terms.?.append(try self.let_pattern_atom()) catch unreachable;
        }
        if (terms) |terms_list| {
            return ast_.AST.createProduct(firsttoken_.?, terms_list, self.allocator);
        } else {
            return exp;
        }
    }

    fn statement(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.peek_kind(.LET)) {
            return self.let_declaration();
        } else if (self.accept(.DEFER)) |token| {
            return ast_.AST.createDefer(token, try self.expr(), self.allocator);
        } else if (self.accept(.ERRDEFER)) |token| {
            return ast_.AST.createErrDefer(token, try self.expr(), self.allocator);
        } else if (self.next_is_expr()) {
            return self.assignment_expr();
        } else {
            self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "a statement", .got = self.peek() } });
            return ParserErrorEnum.parseError;
        }
    }

    fn expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        return self.sum_type();
    }

    fn sum_type(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.product_expr();
        var terms: ?std.ArrayList(*ast_.AST) = null;
        var firsttoken_: ?token_.Token = null;
        while (self.accept(.BAR)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*ast_.AST).init(self.allocator);
                firsttoken_ = token;
                terms.?.append(exp) catch unreachable;
            }
            if (self.peek_kind(.R_PAREN)) {
                // Trailing bar, break out
                break;
            }
            terms.?.append(try self.annotation_expr()) catch unreachable;
        }
        if (terms) |terms_list| {
            return ast_.AST.createSum(firsttoken_.?, terms_list, self.allocator);
        } else {
            return exp;
        }
    }

    fn product_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.annotation_expr();
        var terms: ?std.ArrayList(*ast_.AST) = null;
        var firsttoken_: ?token_.Token = null;
        while (self.accept(.COMMA)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*ast_.AST).init(self.allocator);
                firsttoken_ = token;
                terms.?.append(exp) catch unreachable;
            }
            if (self.peek_kind(.R_PAREN)) {
                // Trailing comma, break out
                break;
            }
            terms.?.append(try self.annotation_expr()) catch unreachable;
        }
        if (terms) |terms_list| {
            return ast_.AST.createProduct(firsttoken_.?, terms_list, self.allocator);
        } else {
            return exp;
        }
    }

    fn annotation_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.assignment_expr();
        if (self.accept(.COLON)) |token| {
            const _type = try self.inject_expr();
            var predicate: ?*ast_.AST = null;
            var _init: ?*ast_.AST = null;
            if (self.accept(.WHERE)) |_| {
                predicate = try self.inject_expr();
            }
            if (self.accept(.EQUALS)) |_| {
                const pre__init = try self.inject_expr();
                if (!pre__init.is_comptime_expr()) {
                    self.errors.addError(errs_.Error{ .comptime_known = .{ .span = pre__init.token().span, .what = "default values" } });
                    return error.parseError;
                }
                _init = ast_.AST.createComptime(token, pre__init, self.allocator);
            }
            return ast_.AST.createAnnotation(token, exp, _type, predicate, _init, self.allocator);
        } else {
            return exp;
        }
    }

    fn assignment_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.inject_expr();
        if (self.accept(.EQUALS)) |token| {
            if (exp.* == .identifier and std.mem.eql(u8, exp.token().data, "_")) {
                // TODO: With new pattern matching is this needed?
                return ast_.AST.createDiscard(token, try self.inject_expr(), self.allocator);
            } else {
                return ast_.AST.createAssign(token, exp, try self.inject_expr(), self.allocator);
            }
        } else if (self.accept(.PLUS_EQUALS)) |token| {
            return ast_.AST.createAssign(token, exp, ast_.AST.createBinop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else if (self.accept(.MINUS_EQUALS)) |token| {
            return ast_.AST.createAssign(token, exp, ast_.AST.createBinop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else if (self.accept(.STAR_EQUALS)) |token| {
            return ast_.AST.createAssign(token, exp, ast_.AST.createBinop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else if (self.accept(.SLASH_EQUALS)) |token| {
            return ast_.AST.createAssign(token, exp, ast_.AST.createBinop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else if (self.accept(.PERCENT_EQUALS)) |token| {
            return ast_.AST.createAssign(token, exp, ast_.AST.createBinop(token, exp, try self.inject_expr(), self.allocator), self.allocator);
        } else {
            return exp;
        }
    }

    fn inject_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.arrow_expr();
        if (self.accept(.LEFT_SKINNY_ARROW)) |token| {
            return ast_.AST.createInject(token, exp, try self.arrow_expr(), self.allocator);
        }
        return exp;
    }

    fn arrow_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.bool_expr();
        while (self.accept(.RIGHT_SKINNY_ARROW)) |token| {
            exp = ast_.AST.createFunction(token, exp, try self.bool_expr(), self.allocator);
        }
        return exp;
    }

    fn bool_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.comparison_expr();
        while (true) {
            if (self.accept(.AND)) |token| {
                exp = ast_.AST.createAnd(token, exp, try self.comparison_expr(), self.allocator);
            } else if (self.accept(.OR)) |token| {
                exp = ast_.AST.createOr(token, exp, try self.comparison_expr(), self.allocator);
            } else {
                return exp;
            }
        }
    }

    fn comparison_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.coalesce_expr();
        if (self.accept(.D_EQUALS)) |token| {
            exp = ast_.AST.createEqual(token, exp, try self.coalesce_expr(), self.allocator);
        } else if (self.accept(.NOT_EQUALS)) |token| {
            exp = ast_.AST.createNotEqual(token, exp, try self.coalesce_expr(), self.allocator);
        } else if (self.accept(.GTR)) |token| {
            exp = ast_.AST.createGreater(token, exp, try self.coalesce_expr(), self.allocator);
        } else if (self.accept(.LSR)) |token| {
            exp = ast_.AST.createLesser(token, exp, try self.coalesce_expr(), self.allocator);
        } else if (self.accept(.GTE)) |token| {
            exp = ast_.AST.createGreaterEqual(token, exp, try self.coalesce_expr(), self.allocator);
        } else if (self.accept(.LTE)) |token| {
            exp = ast_.AST.createLesserEqual(token, exp, try self.coalesce_expr(), self.allocator);
        }
        return exp;
    }

    fn coalesce_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.int_expr();
        while (true) {
            if (self.accept(.CATCH)) |token| {
                exp = ast_.AST.createCatch(token, exp, try self.int_expr(), self.allocator);
            } else if (self.accept(.ORELSE)) |token| {
                exp = ast_.AST.createOrelse(token, exp, try self.int_expr(), self.allocator);
            } else {
                return exp;
            }
        }
    }

    fn int_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.term_expr();
        while (true) {
            if (self.accept(.PLUS)) |token| {
                exp = ast_.AST.createAdd(token, exp, try self.term_expr(), self.allocator);
            } else if (self.accept(.MINUS)) |token| {
                exp = ast_.AST.createSub(token, exp, try self.term_expr(), self.allocator);
            } else if (self.accept(.E_MARK)) |_| {
                exp = ast_.AST.create_error_type(exp, try self.term_expr(), self.allocator);
            } else {
                return exp;
            }
        }
    }

    fn term_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.prefix_expr();
        while (true) {
            if (self.accept(.STAR)) |token| {
                exp = ast_.AST.createMult(token, exp, try self.prefix_expr(), self.allocator);
            } else if (self.accept(.SLASH)) |token| {
                exp = ast_.AST.createDiv(token, exp, try self.prefix_expr(), self.allocator);
            } else if (self.accept(.PERCENT)) |token| {
                exp = ast_.AST.createMod(token, exp, try self.prefix_expr(), self.allocator);
            } else if (self.accept(.D_BAR)) |token| {
                exp = ast_.AST.createUnion(token, exp, try self.prefix_expr(), self.allocator);
            } else {
                return exp;
            }
        }
    }

    fn prefix_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.accept(.NOT)) |token| {
            return ast_.AST.createNot(token, try self.prefix_expr(), self.allocator);
        } else if (self.accept(.COMPTIME)) |token| {
            return ast_.AST.createComptime(token, try self.invoke_expr(), self.allocator);
        } else if (self.accept(.AT)) |_| {
            if (self.accept(.TYPEOF)) |token| {
                _ = try self.expect(.L_PAREN);
                const exp = try self.annotation_expr();
                _ = try self.expect(.R_PAREN);
                return ast_.AST.createTypeOf(token, exp, self.allocator);
            } else if (self.accept(.DEFAULT)) |token| {
                _ = try self.expect(.L_PAREN);
                const exp = try self.annotation_expr();
                _ = try self.expect(.R_PAREN);
                return ast_.AST.createDefault(token, exp, self.allocator);
            } else if (self.accept(.SIZEOF)) |token| {
                _ = try self.expect(.L_PAREN);
                const exp = try self.annotation_expr();
                _ = try self.expect(.R_PAREN);
                return ast_.AST.createSizeOf(token, exp, self.allocator);
            } else {
                self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "a built-in function", .got = self.peek() } });
                return error.parseError;
            }
        } else if (self.accept(.MINUS)) |token| {
            return ast_.AST.createNegate(token, try self.prefix_expr(), self.allocator);
        } else if (self.accept(.AMPERSAND)) |token| {
            const mut = self.accept(.MUT);
            return ast_.AST.createAddrOf(token, try self.prefix_expr(), mut != null, self.allocator);
        } else if (self.accept(.L_SQUARE)) |token| {
            var sliceKind: ast_.SliceKind = undefined;
            var len: ?*ast_.AST = null;
            if (self.accept(.MUT)) |_| {
                sliceKind = .MUT;
            } else if (self.accept(.STAR)) |_| {
                sliceKind = .MULTIPTR;
            } else if (self.next_is_expr()) {
                sliceKind = .ARRAY;
                len = try self.inject_expr();
                if (!len.?.is_comptime_expr()) {
                    self.errors.addError(errs_.Error{ .comptime_known = .{ .span = len.?.token().span, .what = "array lengths" } });
                    return error.not_comptime_known;
                }
            } else {
                sliceKind = .SLICE;
            }
            if (self.peek_kind(.R_SQUARE)) {
                _ = self.expect(.R_SQUARE) catch {};
            } else {
                self.errors.addError(errs_.Error{ .missing_close = .{ .expected = .R_SQUARE, .got = self.peek(), .open = token } });
                return error.parseError;
            }
            if (sliceKind == .ARRAY) {
                return ast_.AST.createArrayOf(token, try self.prefix_expr(), len.?, self.allocator);
            } else {
                return ast_.AST.createSliceOf(token, try self.prefix_expr(), sliceKind, self.allocator);
            }
        } else if (self.accept(.Q_MARK)) |_| {
            return ast_.AST.create_optional_type(try self.invoke_expr(), self.allocator);
        } else if (self.accept(.TRY)) |token| {
            return ast_.AST.createTry(token, try self.invoke_expr(), self.allocator);
        } else {
            return try self.invoke_expr();
        }
    }

    fn invoke_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.postfix_expr();
        while (self.accept(.INVOKE)) |token| {
            exp = ast_.AST.createInvoke(token, exp, try self.postfix_expr(), self.allocator);
        }
        return exp;
    }

    fn postfix_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        var exp = try self.control_flow();
        while (true) {
            if (self.peek_kind(.L_PAREN)) {
                exp = ast_.AST.createCall(self.peek(), exp, try self.call_args(), self.allocator);
            } else if (self.accept(.L_SQUARE)) |token| {
                var first: ?*ast_.AST = null;
                if (self.next_is_expr()) {
                    first = try self.expr();
                }
                if (self.accept(.D_PERIOD)) |_| {
                    var second: ?*ast_.AST = null;
                    if (self.next_is_expr()) {
                        second = try self.expr();
                    }
                    exp = ast_.AST.createSubSlice(token, exp, first, second, self.allocator);
                } else {
                    // Simple index
                    exp = ast_.AST.createIndex(token, exp, first orelse {
                        self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "an expression within index", .got = self.peek() } });
                        return ParserErrorEnum.parseError;
                    }, self.allocator);
                }
                if (self.peek_kind(.R_SQUARE)) {
                    _ = self.expect(.R_SQUARE) catch {};
                } else {
                    self.errors.addError(errs_.Error{ .missing_close = .{ .expected = .R_SQUARE, .got = self.peek(), .open = token } });
                    return error.parseError;
                }
            } else if (self.accept(.PERIOD)) |token| {
                exp = ast_.AST.createSelect(
                    token,
                    exp,
                    ast_.AST.createField(try self.expect(.IDENTIFIER), self.allocator),
                    self.allocator,
                );
            } else if (self.accept(.CARET)) |token| {
                exp = ast_.AST.createDereference(token, exp, self.allocator);
            } else {
                return exp;
            }
        }
    }

    fn call_args(self: *Parser) ParserErrorEnum!std.ArrayList(*ast_.AST) {
        _ = try self.expect(.L_PAREN);
        var retval = std.ArrayList(*ast_.AST).init(self.allocator);
        if (!self.peek_kind(.R_PAREN)) {
            retval.append(try self.annotation_expr()) catch unreachable;
            while (self.accept(.COMMA)) |_| {
                retval.append(try self.annotation_expr()) catch unreachable;
            }
        }
        _ = try self.expect(.R_PAREN);
        return retval;
    }

    fn control_flow(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.peek_kind(.IF)) {
            return try self.if_expr();
        } else if (self.peek_kind(.WHILE)) {
            return try self.while_expr();
        } else if (self.peek_kind(.MATCH)) {
            return try self.match_expr();
        } else if (self.peek_kind(.FOR)) {
            return try self.for_expr();
        } else {
            return try self.factor();
        }
    }

    fn factor(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.accept(.IDENTIFIER)) |token| {
            return ast_.AST.createIdentifier(token, self.allocator);
        } else if (self.accept(.TRUE)) |token| {
            return ast_.AST.createTrue(token, self.allocator);
        } else if (self.accept(.FALSE)) |token| {
            return ast_.AST.createFalse(token, self.allocator);
        } else if (self.accept(.DECIMAL_INTEGER)) |token| {
            return ast_.AST.createInt(token, try std.fmt.parseInt(i128, token.data, 10), self.allocator);
        } else if (self.accept(.HEX_INTEGER)) |token| {
            return ast_.AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 16), self.allocator);
        } else if (self.accept(.OCT_INTEGER)) |token| {
            return ast_.AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 8), self.allocator);
        } else if (self.accept(.BIN_INTEGER)) |token| {
            return ast_.AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 2), self.allocator);
        } else if (self.accept(.FLOAT)) |token| {
            return ast_.AST.createFloat(token, try std.fmt.parseFloat(f64, token.data), self.allocator);
        } else if (self.accept(.CHAR)) |token| {
            return ast_.AST.createChar(token, self.allocator);
        } else if (self.accept(.STRING)) |token| {
            return ast_.AST.createString(token, resolve_escapes(token.data[1 .. token.data.len - 1], self.allocator), self.allocator);
        } else if (self.accept(.MULTI_LINE)) |token| {
            return ast_.AST.createString(token, token.data, self.allocator);
        } else if (self.peek_kind(.L_BRACE)) {
            return try self.block_expr();
        } else if (self.peek_kind(.FN)) {
            return self.fn_declaration();
        } else if (self.accept(.PERIOD)) |token| {
            const field = ast_.AST.createField(try self.expect(.IDENTIFIER), self.allocator);
            return ast_.AST.createInferredMember(token, field, self.allocator);
        } else if (self.accept(.UNREACHABLE)) |token| {
            return ast_.AST.createUnreachable(token, self.allocator);
        } else if (self.peek_kind(.L_PAREN)) {
            return try self.parens();
        } else {
            self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "an expression", .got = self.peek() } });
            return ParserErrorEnum.parseError;
        }
    }

    fn block_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const bracetoken_ = try self.expect(.L_BRACE);

        var statements = std.ArrayList(*ast_.AST).init(self.allocator);

        while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}

        if (self.peek_kind(.R_BRACE)) {
            _ = self.expect(.R_BRACE) catch {};
            return ast_.AST.createUnitValue(bracetoken_, self.allocator);
        }

        while (self.next_is_statement()) {
            statements.append(try self.statement()) catch unreachable;
            if (!self.peek_kind(.SEMICOLON) and !self.peek_kind(.NEWLINE) and !self.peek_kind(.R_BRACE)) {
                self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "a semicolon or a newline after statement", .got = self.peek() } });
                return error.parseError;
            }
            while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}
        }

        while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}

        var final: ?*ast_.AST = null;
        if (self.accept(.BREAK)) |token| {
            final = ast_.AST.createBreak(token, self.allocator);
            while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}
        } else if (self.accept(.CONTINUE)) |token| {
            final = ast_.AST.createContinue(token, self.allocator);
            while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}
        } else if (self.accept(.RETURN)) |token| {
            var exp: ?*ast_.AST = null;
            if (self.next_is_expr()) {
                exp = try self.expr();
            }
            final = ast_.AST.createReturn(token, exp, self.allocator);
            while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}
        }

        if (self.peek_kind(.R_BRACE)) {
            _ = self.expect(.R_BRACE) catch {};
        } else {
            self.errors.addError(errs_.Error{ .missing_close = .{ .expected = .R_BRACE, .got = self.peek(), .open = bracetoken_ } });
            return error.parseError;
        }

        return ast_.AST.createBlock(bracetoken_, statements, final, self.allocator);
    }

    fn if_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.IF);
        var let: ?*ast_.AST = null;
        if (self.peek_kind(.LET)) {
            let = try self.let_declaration();
            if (self.peek_kind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek() } });
                return error.parseError;
            }
        }
        const cond = try self.expr();
        const bodyBlock = try self.factor();
        var elseBlock: ?*ast_.AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.control_flow();
        }

        return ast_.AST.createIf(token, let, cond, bodyBlock, elseBlock, self.allocator);
    }

    fn while_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.WHILE);
        var let: ?*ast_.AST = null;
        if (self.peek_kind(.LET)) {
            let = try self.let_declaration();
            if (self.peek_kind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek() } });
                return error.parseError;
            }
        }
        const cond = try self.expr();
        var post: ?*ast_.AST = null;
        if (self.accept(.SEMICOLON)) |_| {
            post = try self.statement();
        }
        const bodyBlock = try self.block_expr();
        var elseBlock: ?*ast_.AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.control_flow();
        }

        return ast_.AST.createWhile(token, let, cond, post, bodyBlock, elseBlock, self.allocator);
    }

    fn for_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.FOR);
        var let: ?*ast_.AST = null;
        if (self.peek_kind(.LET)) {
            let = try self.let_declaration();
            _ = try self.expect(.SEMICOLON);
        }
        _ = self.accept(.MUT);
        const elem = ast_.AST.createIdentifier(try self.expect(.IDENTIFIER), self.allocator);
        _ = try self.expect(.IN);
        const iterable = try self.expr();
        const bodyBlock = try self.block_expr();
        var elseBlock: ?*ast_.AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.control_flow();
        }

        return ast_.AST.createFor(token, let, elem, iterable, bodyBlock, elseBlock, self.allocator);
    }

    fn fn_declaration(self: *Parser) ParserErrorEnum!*ast_.AST {
        const introducer = try self.expect(.FN);
        var maybeIdent: ?*ast_.AST = null;

        if (self.accept(.IDENTIFIER)) |token| {
            maybeIdent = ast_.AST.createIdentifier(token, self.allocator);
        }
        const params = try self.paramlist();
        _ = try self.expect(.RIGHT_SKINNY_ARROW);
        const inferred_errortoken_ = self.accept(.E_MARK);
        var retType = try self.bool_expr();
        if (inferred_errortoken_ != null) {
            retType = ast_.AST.createInferredError(inferred_errortoken_.?, retType, self.allocator);
        }

        const refinement: ?*ast_.AST = null;
        if (self.accept(.WHERE)) |_| {
            _ = try self.inject_expr();
        }

        const _init = try self.block_expr();

        return ast_.AST.createFnDecl(
            introducer,
            maybeIdent,
            params,
            retType,
            refinement,
            _init,
            false,
            self.allocator,
        );
    }

    fn paramlist(self: *Parser) ParserErrorEnum!std.ArrayList(*ast_.AST) {
        var params = std.ArrayList(*ast_.AST).init(self.allocator);
        errdefer params.deinit();

        const token = try self.expect(.L_PAREN);
        if (self.peek_kind(.MUT) or self.peek_kind(.CONST) or self.peek_kind(.L_PAREN) or self.peek_kind(.IDENTIFIER)) {
            params.append(try self.param()) catch unreachable;
            while (self.accept(.COMMA)) |_| {
                params.append(try self.param()) catch unreachable;
            }
        }
        if (self.peek_kind(.R_PAREN)) {
            _ = self.expect(.R_PAREN) catch unreachable;
        } else {
            self.errors.addError(errs_.Error{ .missing_close = .{ .expected = .R_PAREN, .got = self.peek(), .open = token } });
            return error.parseError;
        }

        return params;
    }

    fn param(self: *Parser) ParserErrorEnum!*ast_.AST {
        var ident = try self.let_pattern_atom();
        var _type: *ast_.AST = undefined;
        var _init: ?*ast_.AST = null;

        _ = try self.expect(.COLON);
        _type = try self.inject_expr();
        if (self.peek_kind(.EQUALS)) {
            _ = try self.expect(.EQUALS);
            _init = try self.inject_expr();
        }

        return ast_.AST.createDecl(
            ident.token(),
            ident,
            _type,
            _init orelse ast_.AST.createDefault(_type.token(), _type, self.allocator),
            self.allocator,
        );
    }

    fn match_expr(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.MATCH);
        var mappings = std.ArrayList(*ast_.AST).init(self.allocator);
        var let: ?*ast_.AST = null;

        if (self.peek_kind(.LET)) {
            let = try self.let_declaration();
            if (self.peek_kind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek() } });
                return error.parseError;
            }
        }
        const exp = try self.expr();

        _ = try self.expect(.L_BRACE);
        while (self.accept(.NEWLINE)) |_| {}

        var has_else = false;
        while (!self.peek_kind(.R_BRACE)) {
            if (self.peek_kind(.ELSE)) {
                mappings.append(try self.match_else()) catch unreachable;
                has_else = true;
                break;
            } else if (self.next_is_expr()) {
                mappings.append(try self.match_mapping()) catch unreachable;
            } else {
                self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "`else` or match mapping", .got = self.peek() } });
                return error.parseError;
            }
        }
        _ = try self.expect(.R_BRACE);

        return ast_.AST.createMatch(token, let, exp, mappings, has_else, self.allocator);
    }

    fn match_mapping(self: *Parser) ParserErrorEnum!*ast_.AST {
        var lhs = try self.match_pattern_inject();
        _ = try self.expect(.RIGHT_FAT_ARROW);
        const rhs = try self.expr();
        if (!self.peek_kind(.R_BRACE)) {
            _ = try self.expect(.NEWLINE);
        }

        return ast_.AST.createMapping(lhs.token(), lhs, rhs, self.allocator);
    }

    fn match_else(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.ELSE);
        if (self.peek_kind(.RIGHT_FAT_ARROW)) {
            _ = self.expect(.RIGHT_FAT_ARROW) catch {};
        } else {
            self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "`=>` after `else`", .got = self.peek() } });
            return error.parseError;
        }
        const rhs = try self.expr();
        if (!self.peek_kind(.R_BRACE)) {
            _ = try self.expect(.NEWLINE);
        }

        return ast_.AST.createMapping(token, null, rhs, self.allocator);
    }

    fn match_pattern_product(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.match_pattern_inject();
        var terms: ?std.ArrayList(*ast_.AST) = null;
        var firsttoken_: ?token_.Token = null;
        while (self.accept(.COMMA)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*ast_.AST).init(self.allocator);
                firsttoken_ = token;
                terms.?.append(exp) catch unreachable;
            }
            terms.?.append(try self.match_pattern_inject()) catch unreachable;
        }
        if (terms) |terms_list| {
            return ast_.AST.createProduct(firsttoken_.?, terms_list, self.allocator);
        } else {
            return exp;
        }
    }

    fn match_pattern_inject(self: *Parser) ParserErrorEnum!*ast_.AST {
        const exp = try self.match_pattern_atom();
        if (self.accept(.LEFT_SKINNY_ARROW)) |token| {
            const rhs = try self.match_pattern_atom();
            return ast_.AST.createInject(token, exp, rhs, self.allocator);
        } else {
            return exp;
        }
    }

    fn match_pattern_atom(self: *Parser) ParserErrorEnum!*ast_.AST {
        if (self.accept(.MUT)) |_| {
            const identifier = try self.expect(.IDENTIFIER);
            return ast_.AST.createSymbol(identifier, .mut, identifier.data, self.allocator);
        } else if (self.accept(.IDENTIFIER)) |token| {
            if (self.peek_kind(.PERIOD)) {
                var exp = ast_.AST.createIdentifier(token, self.allocator);
                while (self.accept(.PERIOD)) |_| {
                    exp = ast_.AST.createSelect(
                        token,
                        exp,
                        ast_.AST.createField(try self.expect(.IDENTIFIER), self.allocator),
                        self.allocator,
                    );
                }
                return exp;
            } else {
                return ast_.AST.createSymbol(token, .let, token.data, self.allocator);
            }
        } else if (self.accept(.TRUE)) |token| {
            return ast_.AST.createTrue(token, self.allocator);
        } else if (self.accept(.FALSE)) |token| {
            return ast_.AST.createFalse(token, self.allocator);
        } else if (self.accept(.DECIMAL_INTEGER)) |token| {
            return ast_.AST.createInt(token, try std.fmt.parseInt(i128, token.data, 10), self.allocator);
        } else if (self.accept(.HEX_INTEGER)) |token| {
            return ast_.AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 16), self.allocator);
        } else if (self.accept(.OCT_INTEGER)) |token| {
            return ast_.AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 8), self.allocator);
        } else if (self.accept(.BIN_INTEGER)) |token| {
            return ast_.AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 2), self.allocator);
        } else if (self.accept(.FLOAT)) |token| {
            return ast_.AST.createFloat(token, try std.fmt.parseFloat(f64, token.data), self.allocator);
        } else if (self.accept(.CHAR)) |token| {
            return ast_.AST.createChar(token, self.allocator);
        } else if (self.accept(.STRING)) |token| {
            return ast_.AST.createString(token, resolve_escapes(token.data[1 .. token.data.len - 1], self.allocator), self.allocator);
        } else if (self.accept(.MULTI_LINE)) |token| {
            return ast_.AST.createString(token, token.data, self.allocator);
        } else if (self.peek_kind(.L_BRACE)) {
            return try self.block_expr();
        } else if (self.accept(.PERIOD)) |token| {
            const ident = ast_.AST.createField(try self.expect(.IDENTIFIER), self.allocator);
            return ast_.AST.createInferredMember(token, ident, self.allocator);
        } else if (self.accept(.L_PAREN)) |_| {
            const pattern = try self.match_pattern_product();
            _ = try self.expect(.R_PAREN);
            return pattern;
        } else {
            self.errors.addError(errs_.Error{ .expectedBasicToken = .{ .expected = "a pattern", .got = self.peek() } });
            return ParserErrorEnum.parseError;
        }
    }

    fn parens(self: *Parser) ParserErrorEnum!*ast_.AST {
        const token = try self.expect(.L_PAREN);
        var exp: ?*ast_.AST = null;
        if (self.next_is_expr()) {
            exp = try self.expr();
        }
        if (self.peek_kind(.R_PAREN)) {
            _ = self.expect(.R_PAREN) catch {};
        } else {
            self.errors.addError(errs_.Error{ .missing_close = .{ .expected = .R_PAREN, .got = self.peek(), .open = token } });
            return error.parseError;
        }

        return exp orelse ast_.AST.createUnitType(token, self.allocator);
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
