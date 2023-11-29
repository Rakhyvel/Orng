const std = @import("std");

const ast = @import("ast.zig");
const errs = @import("errors.zig");
const symbols = @import("symbol.zig");
const _token = @import("token.zig");

const AST = ast.AST;
const Error = errs.Error;
const String = @import("zig-string/zig-string.zig").String;
const Token = _token.Token;
const TokenKind = _token.TokenKind;

const ParserErrorEnum = error{
    parserError, // For general parsing errors. Error is logged in errors.zig.errors. Likely
    InvalidCharacter, // If parsing a float goes wrong. Likely
    Overflow, // If parsing an integer goes wrong. Unlikely
    InvalidRange, // When inserting into a string, possible if bug

    OutOfMemory, // Often when appending to an ArrayList, unlikely
};

pub const Parser = struct {
    tokens: *std.ArrayList(Token),
    cursor: usize,
    astAllocator: std.mem.Allocator,
    errors: *errs.Errors,

    pub fn create(tokens: *std.ArrayList(Token), errors: *errs.Errors, astAllocator: std.mem.Allocator) !Parser {
        return .{ //
            .tokens = tokens,
            .cursor = 0,
            .astAllocator = astAllocator,
            .errors = errors,
        };
    }

    fn peek(self: *Parser) Token {
        return self.tokens.items[self.cursor];
    }

    fn peek_kind(self: *Parser, kind: TokenKind) bool {
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
        or nextKind == .NOT;
    }

    fn next_is_statement(self: *Parser) bool {
        const nextKind = self.peek().kind;
        return nextKind == .LET or nextKind == .DEFER or nextKind == .ERRDEFER or self.next_is_expr();
    }

    /// Returns the next token if its kind matches the given kind, otherwise
    /// null
    fn accept(self: *Parser, kind: TokenKind) ?Token {
        const token = self.peek();
        if (token.kind == kind) {
            self.cursor += 1;
            return token;
        } else {
            return null;
        }
    }

    /// Returns the token with an expected kind, or throws an error.
    fn expect(self: *Parser, kind: TokenKind) ParserErrorEnum!Token {
        if (self.accept(kind)) |token| {
            return token;
        } else {
            self.errors.addError(Error{ .expected2Token = .{ .expected = kind, .got = self.peek() } });
            return ParserErrorEnum.parserError;
        }
    }

    /// Parses a token stream a file into a list of declaration ASTs
    pub fn parse(self: *Parser) ParserErrorEnum!std.ArrayList(*AST) {
        var decls = std.ArrayList(*AST).init(self.astAllocator);
        while (self.accept(.NEWLINE)) |_| {}
        while (!self.peek_kind(.EOF)) {
            try decls.append(try self.top_level_declaration());
            while (self.accept(.NEWLINE)) |_| {}
        }
        _ = try self.expect(.EOF);
        return decls;
    }

    fn top_level_declaration(self: *Parser) ParserErrorEnum!*AST {
        if (self.peek_kind(.FN)) {
            return try self.fn_declaration();
        } else if (self.peek_kind(.LET)) {
            var decl: *AST = try self.let_declaration();
            if (!self.peek_kind(.EOF)) {
                _ = try self.expect(.NEWLINE);
            }
            decl.decl.top_level = true;
            return decl;
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "`fn` or `let` declaration in the top level", .got = self.peek() } });
            return ParserErrorEnum.parserError;
        }
    }

    fn let_declaration(self: *Parser) ParserErrorEnum!*AST {
        const token = try self.expect(.LET);

        const ident = try self.let_pattern_atom();
        var _type: ?*AST = null;
        var init: ?*AST = null;

        if (self.accept(.COLON)) |_| {
            _type = try self.inject_expr();
            if (self.peek_kind(.EQUALS)) {
                _ = try self.expect(.EQUALS);
                init = try self.inject_expr();
            }
        } else if (self.accept(.EQUALS)) |_| {
            init = try self.inject_expr();
        } else {
            self.errors.addError(Error{ .basic = .{ .span = self.peek().span, .msg = "variable declarations require at least a type or an intial value" } });
            return error.parserError;
        }

        return try AST.createDecl(
            token,
            ident,
            _type,
            init,
            self.astAllocator,
        );
    }

    fn let_pattern_atom(self: *Parser) ParserErrorEnum!*AST {
        if (self.peek_kind(.MUT) or self.peek_kind(.CONST) or self.peek_kind(.IDENTIFIER)) {
            var kind: symbols.SymbolKind = undefined;
            if (self.accept(.MUT) != null) {
                kind = .mut;
            } else if (self.accept(.CONST) != null) {
                kind = ._const;
            } else {
                kind = .let;
            }
            const identifier = try self.expect(.IDENTIFIER);
            return try AST.createSymbol(identifier, kind, identifier.data, self.astAllocator);
        } else if (self.accept(.L_PAREN)) |_| {
            const res = try self.let_pattern_product();
            _ = try self.expect(.R_PAREN);
            return res;
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a pattern after `let`", .got = self.peek() } });
            return ParserErrorEnum.parserError;
        }
    }

    fn let_pattern_product(self: *Parser) ParserErrorEnum!*AST {
        const exp = try self.let_pattern_atom();
        var terms: ?std.ArrayList(*AST) = null;
        var first_token: ?Token = null;
        while (self.accept(.COMMA)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*AST).init(self.astAllocator);
                first_token = token;
                try terms.?.append(exp);
            }
            try terms.?.append(try self.let_pattern_atom());
        }
        if (terms) |terms_list| {
            return AST.createProduct(first_token.?, terms_list, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn statement(self: *Parser) ParserErrorEnum!*AST {
        if (self.peek_kind(.LET)) {
            return self.let_declaration();
        } else if (self.accept(.DEFER)) |token| {
            return try AST.createDefer(token, try self.expr(), self.astAllocator);
        } else if (self.accept(.ERRDEFER)) |token| {
            return try AST.createErrDefer(token, try self.expr(), self.astAllocator);
        } else if (self.next_is_expr()) {
            return self.assignment_expr();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a statement", .got = self.peek() } });
            return ParserErrorEnum.parserError;
        }
    }

    fn expr(self: *Parser) ParserErrorEnum!*AST {
        return self.sum_type();
    }

    fn sum_type(self: *Parser) ParserErrorEnum!*AST {
        const exp = try self.product_expr();
        var terms: ?std.ArrayList(*AST) = null;
        var first_token: ?Token = null;
        while (self.accept(.BAR)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*AST).init(self.astAllocator);
                first_token = token;
                try terms.?.append(exp);
            }
            if (self.peek_kind(.R_PAREN)) {
                // Trailing bar, break out
                break;
            }
            try terms.?.append(try self.annotation_expr());
        }
        if (terms) |terms_list| {
            return try AST.createSum(first_token.?, terms_list, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn product_expr(self: *Parser) ParserErrorEnum!*AST {
        const exp = try self.annotation_expr();
        var terms: ?std.ArrayList(*AST) = null;
        var first_token: ?Token = null;
        while (self.accept(.COMMA)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*AST).init(self.astAllocator);
                first_token = token;
                try terms.?.append(exp);
            }
            if (self.peek_kind(.R_PAREN)) {
                // Trailing comma, break out
                break;
            }
            try terms.?.append(try self.annotation_expr());
        }
        if (terms) |terms_list| {
            return AST.createProduct(first_token.?, terms_list, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn annotation_expr(self: *Parser) ParserErrorEnum!*AST {
        const exp = try self.assignment_expr();
        if (self.accept(.COLON)) |token| {
            const _type = try self.inject_expr();
            var predicate: ?*AST = null;
            var init: ?*AST = null;
            if (self.accept(.WHERE)) |_| {
                predicate = try self.inject_expr();
            }
            if (self.accept(.EQUALS)) |_| {
                init = try AST.createComptime(token, try self.inject_expr(), self.astAllocator);
            }
            return try AST.createAnnotation(token, exp, _type, predicate, init, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn assignment_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.inject_expr();
        if (self.accept(.EQUALS)) |token| {
            if (exp.* == .identifier and std.mem.eql(u8, exp.getToken().data, "_")) {
                // TODO: With new pattern matching is this needed?
                return try AST.createDiscard(token, try self.inject_expr(), self.astAllocator);
            } else {
                return try AST.createAssign(token, exp, try self.inject_expr(), self.astAllocator);
            }
        } else if (self.accept(.PLUS_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.inject_expr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.MINUS_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.inject_expr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.STAR_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.inject_expr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.SLASH_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.inject_expr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.PERCENT_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.inject_expr(), self.astAllocator), self.astAllocator);
        } else {
            return exp;
        }
    }

    fn inject_expr(self: *Parser) ParserErrorEnum!*AST {
        const exp = try self.arrow_expr();
        if (self.accept(.LEFT_SKINNY_ARROW)) |token| {
            return try AST.createInject(token, exp, try self.arrow_expr(), self.astAllocator);
        }
        return exp;
    }

    fn arrow_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.bool_expr();
        while (self.accept(.RIGHT_SKINNY_ARROW)) |token| {
            exp = try AST.createFunction(token, exp, try self.bool_expr(), self.astAllocator);
        }
        return exp;
    }

    fn bool_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.comparison_expr();
        while (true) {
            if (self.accept(.AND)) |token| {
                exp = try AST.createAnd(token, exp, try self.comparison_expr(), self.astAllocator);
            } else if (self.accept(.OR)) |token| {
                exp = try AST.createOr(token, exp, try self.comparison_expr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn comparison_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.coalesce_expr();
        if (self.accept(.D_EQUALS)) |token| {
            exp = try AST.createEqual(token, exp, try self.coalesce_expr(), self.astAllocator);
        } else if (self.accept(.NOT_EQUALS)) |token| {
            exp = try AST.createNotEqual(token, exp, try self.coalesce_expr(), self.astAllocator);
        } else if (self.accept(.GTR)) |token| {
            exp = try AST.createGreater(token, exp, try self.coalesce_expr(), self.astAllocator);
        } else if (self.accept(.LSR)) |token| {
            exp = try AST.createLesser(token, exp, try self.coalesce_expr(), self.astAllocator);
        } else if (self.accept(.GTE)) |token| {
            exp = try AST.createGreaterEqual(token, exp, try self.coalesce_expr(), self.astAllocator);
        } else if (self.accept(.LTE)) |token| {
            exp = try AST.createLesserEqual(token, exp, try self.coalesce_expr(), self.astAllocator);
        }
        return exp;
    }

    fn coalesce_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.int_expr();
        while (true) {
            if (self.accept(.CATCH)) |token| {
                exp = try AST.createCatch(token, exp, try self.int_expr(), self.astAllocator);
            } else if (self.accept(.ORELSE)) |token| {
                exp = try AST.createOrelse(token, exp, try self.int_expr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn int_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.term_expr();
        while (true) {
            if (self.accept(.PLUS)) |token| {
                exp = try AST.createAdd(token, exp, try self.term_expr(), self.astAllocator);
            } else if (self.accept(.MINUS)) |token| {
                exp = try AST.createSub(token, exp, try self.term_expr(), self.astAllocator);
            } else if (self.accept(.E_MARK)) |_| {
                exp = try AST.create_error_type(exp, try self.term_expr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn term_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.prefix_expr();
        while (true) {
            if (self.accept(.STAR)) |token| {
                exp = try AST.createMult(token, exp, try self.prefix_expr(), self.astAllocator);
            } else if (self.accept(.SLASH)) |token| {
                exp = try AST.createDiv(token, exp, try self.prefix_expr(), self.astAllocator);
            } else if (self.accept(.PERCENT)) |token| {
                exp = try AST.createMod(token, exp, try self.prefix_expr(), self.astAllocator);
            } else if (self.accept(.D_BAR)) |token| {
                exp = try AST.createUnion(token, exp, try self.prefix_expr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn prefix_expr(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.NOT)) |token| {
            return try AST.createNot(token, try self.invoke_expr(), self.astAllocator);
        } else if (self.accept(.COMPTIME)) |token| {
            return try AST.createComptime(token, try self.invoke_expr(), self.astAllocator);
        } else if (self.accept(.MINUS)) |token| {
            return try AST.createNegate(token, try self.invoke_expr(), self.astAllocator);
        } else if (self.accept(.AMPERSAND)) |token| {
            const mut = self.accept(.MUT);
            return try AST.createAddrOf(token, try self.prefix_expr(), mut != null, self.astAllocator);
        } else if (self.accept(.L_SQUARE)) |token| {
            var sliceKind: ast.SliceKind = undefined;
            var len: ?*AST = null;
            if (self.accept(.MUT)) |_| {
                sliceKind = .MUT;
            } else if (self.accept(.STAR)) |_| {
                sliceKind = .MULTIPTR;
            } else if (self.next_is_expr()) {
                sliceKind = .ARRAY;
                len = try AST.createComptime(token, try self.expr(), self.astAllocator);
            } else {
                sliceKind = .SLICE;
            }
            if (self.peek_kind(.R_SQUARE)) {
                _ = self.expect(.R_SQUARE) catch {};
            } else {
                self.errors.addError(Error{ .missing_close = .{ .expected = .R_SQUARE, .got = self.peek(), .open = token } });
                return error.parserError;
            }
            return try AST.createSliceOf(token, try self.prefix_expr(), len, sliceKind, self.astAllocator);
        } else if (self.accept(.Q_MARK)) |_| {
            return try AST.create_optional_type(try self.invoke_expr(), self.astAllocator);
        } else if (self.accept(.TRY)) |token| {
            return try AST.createTry(token, try self.invoke_expr(), self.astAllocator);
        } else {
            return try self.invoke_expr();
        }
    }

    fn invoke_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.postfix_expr();
        while (self.accept(.INVOKE)) |token| {
            exp = try AST.createInvoke(token, exp, try self.postfix_expr(), self.astAllocator);
        }
        return exp;
    }

    fn postfix_expr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.control_flow();
        while (true) {
            if (self.peek_kind(.L_PAREN)) {
                exp = try AST.createCall(self.peek(), exp, try self.call_args(), self.astAllocator);
            } else if (self.accept(.L_SQUARE)) |token| {
                var first: ?*AST = null;
                if (self.next_is_expr()) {
                    first = try self.expr();
                }
                if (self.accept(.D_PERIOD)) |_| {
                    var second: ?*AST = null;
                    if (self.next_is_expr()) {
                        second = try self.expr();
                    }
                    exp = try AST.createSubSlice(token, exp, first, second, self.astAllocator);
                } else {
                    // Simple index
                    exp = try AST.createIndex(token, exp, first orelse {
                        self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "an expression within index", .got = self.peek() } });
                        return ParserErrorEnum.parserError;
                    }, self.astAllocator);
                }
                if (self.peek_kind(.R_SQUARE)) {
                    _ = self.expect(.R_SQUARE) catch {};
                } else {
                    self.errors.addError(Error{ .missing_close = .{ .expected = .R_SQUARE, .got = self.peek(), .open = token } });
                    return error.parserError;
                }
            } else if (self.accept(.PERIOD)) |token| {
                exp = try AST.createSelect(
                    token,
                    exp,
                    try AST.createIdentifier(
                        try self.expect(.IDENTIFIER),
                        self.astAllocator,
                    ),
                    self.astAllocator,
                );
            } else if (self.accept(.CARET)) |token| {
                exp = try AST.createDereference(token, exp, self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn call_args(self: *Parser) ParserErrorEnum!std.ArrayList(*AST) {
        _ = try self.expect(.L_PAREN);
        var retval = std.ArrayList(*AST).init(self.astAllocator);
        if (!self.peek_kind(.R_PAREN)) {
            try retval.append(try self.annotation_expr());
            while (self.accept(.COMMA)) |_| {
                try retval.append(try self.annotation_expr());
            }
        }
        _ = try self.expect(.R_PAREN);
        return retval;
    }

    fn control_flow(self: *Parser) ParserErrorEnum!*AST {
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

    fn factor(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.IDENTIFIER)) |token| {
            return try AST.createIdentifier(token, self.astAllocator);
        } else if (self.accept(.TRUE)) |token| {
            return try AST.createTrue(token, self.astAllocator);
        } else if (self.accept(.FALSE)) |token| {
            return try AST.createFalse(token, self.astAllocator);
        } else if (self.accept(.DECIMAL_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data, 10), self.astAllocator);
        } else if (self.accept(.HEX_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 16), self.astAllocator);
        } else if (self.accept(.OCT_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 8), self.astAllocator);
        } else if (self.accept(.BIN_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 2), self.astAllocator);
        } else if (self.accept(.FLOAT)) |token| {
            return try AST.createFloat(token, try std.fmt.parseFloat(f64, token.data), self.astAllocator);
        } else if (self.accept(.CHAR)) |token| {
            return try AST.createChar(token, self.astAllocator);
        } else if (self.accept(.STRING)) |token| {
            return try AST.createString(token, try resolve_escapes(token.data[1 .. token.data.len - 1], self.astAllocator), self.astAllocator);
        } else if (self.accept(.MULTI_LINE)) |token| {
            return try AST.createString(token, token.data, self.astAllocator);
        } else if (self.peek_kind(.L_BRACE)) {
            return try self.block_expr();
        } else if (self.peek_kind(.FN)) {
            return self.fn_declaration();
        } else if (self.accept(.PERIOD)) |token| {
            const ident = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
            return try AST.createInferredMember(token, ident, self.astAllocator);
        } else if (self.accept(.UNREACHABLE)) |token| {
            return try AST.createUnreachable(token, self.astAllocator);
        } else if (self.peek_kind(.L_PAREN)) {
            return try self.parens();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "an expression", .got = self.peek() } });
            return ParserErrorEnum.parserError;
        }
    }

    fn block_expr(self: *Parser) ParserErrorEnum!*AST {
        const brace_token = try self.expect(.L_BRACE);

        var statements = std.ArrayList(*AST).init(self.astAllocator);

        while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}

        while (self.next_is_statement()) {
            try statements.append(try self.statement());
            if (!self.peek_kind(.SEMICOLON) and !self.peek_kind(.NEWLINE) and !self.peek_kind(.R_BRACE)) {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a semicolon or a newline after statement", .got = self.peek() } });
                return error.parserError;
            }
            while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}
        }

        while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}

        var final: ?*AST = null;
        if (self.accept(.BREAK)) |token| {
            final = try AST.createBreak(token, self.astAllocator);
            while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}
        } else if (self.accept(.CONTINUE)) |token| {
            final = try AST.createContinue(token, self.astAllocator);
            while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}
        } else if (self.accept(.RETURN)) |token| {
            var exp: ?*AST = null;
            if (self.next_is_expr()) {
                exp = try self.expr();
            }
            final = try AST.createReturn(token, exp, self.astAllocator);
            while (self.accept(.SEMICOLON) orelse self.accept(.NEWLINE)) |_| {}
        }

        if (self.peek_kind(.R_BRACE)) {
            _ = self.expect(.R_BRACE) catch {};
        } else {
            self.errors.addError(Error{ .missing_close = .{ .expected = .R_BRACE, .got = self.peek(), .open = brace_token } });
            return error.parserError;
        }

        return try AST.createBlock(brace_token, statements, final, self.astAllocator);
    }

    fn if_expr(self: *Parser) ParserErrorEnum!*AST {
        const token = try self.expect(.IF);
        var let: ?*AST = null;
        if (self.peek_kind(.LET)) {
            let = try self.let_declaration();
            if (self.peek_kind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek() } });
                return error.parserError;
            }
        }
        const cond = try self.expr();
        const bodyBlock = try self.factor();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.control_flow();
        }

        return try AST.createIf(token, let, cond, bodyBlock, elseBlock, self.astAllocator);
    }

    fn while_expr(self: *Parser) ParserErrorEnum!*AST {
        const token = try self.expect(.WHILE);
        var let: ?*AST = null;
        if (self.peek_kind(.LET)) {
            let = try self.let_declaration();
            if (self.peek_kind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek() } });
                return error.parserError;
            }
        }
        const cond = try self.expr();
        var post: ?*AST = null;
        if (self.accept(.SEMICOLON)) |_| {
            post = try self.statement();
        }
        const bodyBlock = try self.block_expr();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.control_flow();
        }

        return try AST.createWhile(token, let, cond, post, bodyBlock, elseBlock, self.astAllocator);
    }

    fn for_expr(self: *Parser) ParserErrorEnum!*AST {
        const token = try self.expect(.FOR);
        var let: ?*AST = null;
        if (self.peek_kind(.LET)) {
            let = try self.let_declaration();
            _ = try self.expect(.SEMICOLON);
        }
        _ = self.accept(.MUT);
        const elem = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
        _ = try self.expect(.IN);
        const iterable = try self.expr();
        const bodyBlock = try self.block_expr();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.control_flow();
        }

        return try AST.createFor(token, let, elem, iterable, bodyBlock, elseBlock, self.astAllocator);
    }

    fn fn_declaration(self: *Parser) ParserErrorEnum!*AST {
        const introducer = try self.expect(.FN);
        var maybeIdent: ?*AST = null;

        if (self.accept(.IDENTIFIER)) |token| {
            maybeIdent = try AST.createIdentifier(token, self.astAllocator);
        }
        const params = try self.paramlist();
        _ = try self.expect(.RIGHT_SKINNY_ARROW);
        const inferred_error_token = self.accept(.E_MARK);
        var retType = try self.bool_expr();
        if (inferred_error_token != null) {
            retType = try AST.createInferredError(inferred_error_token.?, retType, self.astAllocator);
        }

        const refinement: ?*AST = null;
        if (self.accept(.WHERE)) |_| {
            _ = try self.inject_expr();
        }

        const init = try self.block_expr();

        return try AST.createFnDecl(
            introducer,
            maybeIdent,
            params,
            retType,
            refinement,
            init,
            false,
            self.astAllocator,
        );
    }

    fn paramlist(self: *Parser) ParserErrorEnum!std.ArrayList(*AST) {
        var params = std.ArrayList(*AST).init(self.astAllocator);
        errdefer params.deinit();

        const token = try self.expect(.L_PAREN);
        if (self.peek_kind(.MUT) or self.peek_kind(.CONST) or self.peek_kind(.L_PAREN) or self.peek_kind(.IDENTIFIER)) {
            try params.append(try self.param());
            while (self.accept(.COMMA)) |_| {
                try params.append(try self.param());
            }
        }
        if (self.peek_kind(.R_PAREN)) {
            _ = self.expect(.R_PAREN) catch {};
        } else {
            self.errors.addError(Error{ .missing_close = .{ .expected = .R_PAREN, .got = self.peek(), .open = token } });
            return error.parserError;
        }

        return params;
    }

    fn param(self: *Parser) ParserErrorEnum!*AST {
        var ident = try self.let_pattern_atom();
        var _type: ?*AST = null;
        var init: ?*AST = null;

        _ = try self.expect(.COLON);
        _type = try self.inject_expr();
        if (self.peek_kind(.EQUALS)) {
            _ = try self.expect(.EQUALS);
            init = try self.inject_expr();
        }

        return try AST.createDecl(
            ident.getToken(),
            ident,
            _type,
            init,
            self.astAllocator,
        );
    }

    fn match_expr(self: *Parser) ParserErrorEnum!*AST {
        const token = try self.expect(.MATCH);
        var mappings = std.ArrayList(*AST).init(self.astAllocator);
        var let: ?*AST = null;

        if (self.peek_kind(.LET)) {
            let = try self.let_declaration();
            if (self.peek_kind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek() } });
                return error.parserError;
            }
        }
        const exp = try self.expr();

        _ = try self.expect(.L_BRACE);
        while (self.accept(.NEWLINE)) |_| {}

        var has_else = false;
        while (!self.peek_kind(.R_BRACE)) {
            if (self.peek_kind(.ELSE)) {
                try mappings.append(try self.match_else());
                has_else = true;
                break;
            } else if (self.next_is_expr()) {
                try mappings.append(try self.match_mapping());
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "`else` or match mapping", .got = self.peek() } });
                return error.parserError;
            }
        }
        _ = try self.expect(.R_BRACE);

        return try AST.createMatch(token, let, exp, mappings, has_else, self.astAllocator);
    }

    fn match_mapping(self: *Parser) ParserErrorEnum!*AST {
        var lhs = try self.match_pattern_inject();
        _ = try self.expect(.RIGHT_FAT_ARROW);
        const rhs = try self.expr();
        if (!self.peek_kind(.R_BRACE)) {
            _ = try self.expect(.NEWLINE);
        }

        return try AST.createMapping(lhs.getToken(), lhs, rhs, self.astAllocator);
    }

    fn match_else(self: *Parser) ParserErrorEnum!*AST {
        const token = try self.expect(.ELSE);
        if (self.peek_kind(.RIGHT_FAT_ARROW)) {
            _ = self.expect(.RIGHT_FAT_ARROW) catch {};
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "`=>` after `else`", .got = self.peek() } });
            return error.parserError;
        }
        const rhs = try self.expr();
        if (!self.peek_kind(.R_BRACE)) {
            _ = try self.expect(.NEWLINE);
        }

        return try AST.createMapping(token, null, rhs, self.astAllocator);
    }

    fn match_pattern_product(self: *Parser) ParserErrorEnum!*AST {
        const exp = try self.match_pattern_inject();
        var terms: ?std.ArrayList(*AST) = null;
        var first_token: ?Token = null;
        while (self.accept(.COMMA)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*AST).init(self.astAllocator);
                first_token = token;
                try terms.?.append(exp);
            }
            try terms.?.append(try self.match_pattern_inject());
        }
        if (terms) |terms_list| {
            return AST.createProduct(first_token.?, terms_list, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn match_pattern_inject(self: *Parser) ParserErrorEnum!*AST {
        const exp = try self.match_pattern_atom();
        if (self.accept(.LEFT_SKINNY_ARROW)) |token| {
            const rhs = try self.match_pattern_atom();
            return AST.createInject(token, exp, rhs, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn match_pattern_atom(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.MUT)) |_| {
            const identifier = try self.expect(.IDENTIFIER);
            return try AST.createSymbol(identifier, .mut, identifier.data, self.astAllocator);
        } else if (self.accept(.IDENTIFIER)) |token| {
            if (self.peek_kind(.PERIOD)) {
                var exp = try AST.createIdentifier(token, self.astAllocator);
                while (self.accept(.PERIOD)) |_| {
                    exp = try AST.createSelect(
                        token,
                        exp,
                        try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator),
                        self.astAllocator,
                    );
                }
                return exp;
            } else {
                return try AST.createSymbol(token, .let, token.data, self.astAllocator);
            }
        } else if (self.accept(.TRUE)) |token| {
            return try AST.createTrue(token, self.astAllocator);
        } else if (self.accept(.FALSE)) |token| {
            return try AST.createFalse(token, self.astAllocator);
        } else if (self.accept(.DECIMAL_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data, 10), self.astAllocator);
        } else if (self.accept(.HEX_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 16), self.astAllocator);
        } else if (self.accept(.OCT_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 8), self.astAllocator);
        } else if (self.accept(.BIN_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data[2..], 2), self.astAllocator);
        } else if (self.accept(.FLOAT)) |token| {
            return try AST.createFloat(token, try std.fmt.parseFloat(f64, token.data), self.astAllocator);
        } else if (self.accept(.CHAR)) |token| {
            return try AST.createChar(token, self.astAllocator);
        } else if (self.accept(.STRING)) |token| {
            return try AST.createString(token, try resolve_escapes(token.data[1 .. token.data.len - 1], self.astAllocator), self.astAllocator);
        } else if (self.accept(.MULTI_LINE)) |token| {
            return try AST.createString(token, token.data, self.astAllocator);
        } else if (self.peek_kind(.L_BRACE)) {
            return try self.block_expr();
        } else if (self.accept(.PERIOD)) |token| {
            const ident = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
            return try AST.createInferredMember(token, ident, self.astAllocator);
        } else if (self.accept(.L_PAREN)) |_| {
            const pattern = try self.match_pattern_product();
            _ = try self.expect(.R_PAREN);
            return pattern;
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a pattern", .got = self.peek() } });
            return ParserErrorEnum.parserError;
        }
    }

    fn parens(self: *Parser) ParserErrorEnum!*AST {
        const token = try self.expect(.L_PAREN);
        var exp: ?*AST = null;
        if (self.next_is_expr()) {
            exp = try self.expr();
        }
        if (self.peek_kind(.R_PAREN)) {
            _ = self.expect(.R_PAREN) catch {};
        } else {
            self.errors.addError(Error{ .missing_close = .{ .expected = .R_PAREN, .got = self.peek(), .open = token } });
            return error.parserError;
        }

        return exp orelse try AST.createUnit(token, self.astAllocator);
    }
};

fn resolve_escapes(input: []const u8, allocator: std.mem.Allocator) ![]const u8 {
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
                try retval.append(0x0A);
            } else if (byte == 'r') {
                try retval.append(0x0D);
            } else if (byte == 't') {
                try retval.append(0x09);
            } else if (byte == '\\') {
                try retval.append(0x5C);
            } else if (byte == '\'') {
                try retval.append(0x27);
            } else if (byte == '"') {
                try retval.append(0x22);
            } else if (byte == 'x') {
                try retval.append(get_nibble(input[j + 1]) * 16 + get_nibble(input[j + 2]));
                skip = 2;
            } else {
                std.debug.print("Unknown escape sequence '{c}'\n", .{byte});
                unreachable;
            }
        } else {
            if (byte == '\\') {
                escape = true;
            } else {
                try retval.append(byte);
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
