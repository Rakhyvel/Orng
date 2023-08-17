const std = @import("std");

const ast = @import("ast.zig");
const errs = @import("errors.zig");
const main = @import("main.zig");
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

    fn peekKind(self: *Parser, kind: TokenKind) bool {
        return self.peek().kind == kind;
    }

    fn nextIsExpr(self: *Parser) bool {
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
        or nextKind == .INDENT //
        or nextKind == .BAR //
        or nextKind == .MINUS //
        or nextKind == .MATCH //
        or nextKind == .CASE //
        or nextKind == .FN //
        or nextKind == .FOR //
        or nextKind == .IF //
        or nextKind == .TRY //
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
        or nextKind == .NOT;
    }

    fn nextIsStatement(self: *Parser) bool {
        const nextKind = self.peek().kind;
        return nextKind == .LET or nextKind == .CONST or nextKind == .DEFER or nextKind == .ERRDEFER or self.nextIsExpr();
    }

    /// Returns the next token if its kind matches the given kind, otherwise
    /// null
    fn accept(self: *Parser, kind: TokenKind) ?Token {
        var token = self.peek();
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
            self.errors.addError(Error{ .expected2Token = .{ .expected = kind, .got = self.peek(), .stage = .parsing } });
            return ParserErrorEnum.parserError;
        }
    }

    /// Parses a token stream a file into a list of declaration ASTs
    pub fn parse(self: *Parser) ParserErrorEnum!std.ArrayList(*AST) {
        var decls = std.ArrayList(*AST).init(self.astAllocator);
        while (self.accept(.NEWLINE)) |_| {}
        while (!self.peekKind(.EOF)) {
            try decls.append(try self.topLevelDeclaration());
            while (self.accept(.NEWLINE)) |_| {}
        }
        _ = try self.expect(.EOF);
        return decls;
    }

    fn topLevelDeclaration(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.FN)) {
            return try self.fnDeclaration();
        } else if (self.peekKind(.CONST)) {
            var decl = try self.constDeclaration();
            if (!self.peekKind(.EOF)) {
                _ = try self.expect(.NEWLINE);
            }
            return decl;
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "`fn` or `const` declaration in the top level", .got = self.peek(), .stage = .parsing } });
            return ParserErrorEnum.parserError;
        }
    }

    fn nonFnDeclaration(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.LET)) {
            return try self.letDeclaration();
        } else if (self.peekKind(.CONST)) {
            return try self.constDeclaration();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "`let` or `const`", .got = self.peek(), .stage = .parsing } });
            return ParserErrorEnum.parserError;
        }
    }

    fn constDeclaration(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.CONST);
        var ident = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
        var _type: ?*AST = null;

        if (self.accept(.COLON)) |_| {
            _type = try self.arrowExpr();
        }
        _ = try self.expect(.EQUALS);
        var init = try self.expr();

        return try AST.createDecl(
            token,
            ident,
            _type,
            init,
            self.astAllocator,
        );
    }

    fn letDeclaration(self: *Parser) ParserErrorEnum!*AST {
        var definitelyLet = try self.expect(.LET);
        var maybeMut = self.accept(.MUT);
        var ident = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
        var _type: ?*AST = null;
        var init: ?*AST = null;

        if (self.accept(.COLON)) |_| {
            _type = try self.arrowExpr();
            if (self.peekKind(.EQUALS)) {
                _ = try self.expect(.EQUALS);
                init = try self.expr();
            }
        } else if (self.accept(.EQUALS)) |_| {
            init = try self.expr();
        } else {
            self.errors.addError(Error{ .basic = .{ .span = self.peek().span, .msg = "variable declarations require at least a type or an intial value", .stage = .parsing } });
            return error.parserError;
        }

        return try AST.createDecl(
            if (maybeMut) |mut| mut else definitelyLet,
            ident,
            _type,
            init,
            self.astAllocator,
        );
    }

    fn statement(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            return self.nonFnDeclaration();
        } else if (self.accept(.DEFER)) |token| {
            return try AST.createDefer(token, try self.statement(), self.astAllocator);
        } else if (self.accept(.ERRDEFER)) |token| {
            return try AST.createErrDefer(token, try self.statement(), self.astAllocator);
        } else {
            return self.expr();
        }
    }

    fn expr(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.CASE) or self.peekKind(.MATCH)) {
            return self.caseMatchExpr();
        } else {
            return self.sumType();
        }
    }

    fn sumType(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.productExpr();
        var terms: ?std.ArrayList(*AST) = null;
        var first_token: ?Token = null;
        while (self.accept(.BAR)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*AST).init(self.astAllocator);
                first_token = token;
                try terms.?.append(exp);
            }
            try terms.?.append(try self.annotExpr());
        }
        if (terms) |terms_list| {
            return try AST.createSum(first_token.?, terms_list, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn productExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.annotExpr();
        var terms: ?std.ArrayList(*AST) = null;
        var first_token: ?Token = null;
        while (self.accept(.COMMA)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*AST).init(self.astAllocator);
                first_token = token;
                try terms.?.append(exp);
            }
            try terms.?.append(try self.annotExpr());
        }
        if (terms) |terms_list| {
            return AST.createProduct(first_token.?, terms_list, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn annotExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.assignExpr();
        if (self.accept(.COLON)) |token| {
            var _type = try self.arrowExpr();
            var predicate: ?*AST = null;
            var init: ?*AST = null;
            if (self.accept(.WHERE)) |_| {
                predicate = try self.arrowExpr();
            }
            if (self.accept(.EQUALS)) |_| {
                init = try self.arrowExpr();
            }
            return try AST.createAnnotation(token, exp, _type, predicate, init, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn assignExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.arrowExpr();
        if (self.accept(.EQUALS)) |token| {
            return try AST.createAssign(token, exp, try self.assignExpr(), self.astAllocator);
        } else if (self.accept(.PLUS_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.assignExpr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.MINUS_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.assignExpr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.STAR_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.assignExpr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.SLASH_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.assignExpr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.PERCENT_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.assignExpr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.D_STAR_EQUALS)) |token| {
            return try AST.createAssign(token, exp, try AST.createBinop(token, exp, try self.assignExpr(), self.astAllocator), self.astAllocator);
        } else if (self.accept(.LEFT_SKINNY_ARROW)) |token| {
            return try AST.createInject(token, exp, try self.assignExpr(), self.astAllocator);
        } else {
            return exp;
        }
    }

    fn arrowExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.boolExpr();
        while (self.accept(.RIGHT_SKINNY_ARROW)) |token| {
            exp = try AST.createFunction(token, exp, try self.boolExpr(), self.astAllocator);
        }
        return exp;
    }

    fn boolExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.conditionalExpr();
        while (true) {
            if (self.accept(.AND)) |token| {
                exp = try AST.createAnd(token, exp, try self.conditionalExpr(), self.astAllocator);
            } else if (self.accept(.OR)) |token| {
                exp = try AST.createOr(token, exp, try self.conditionalExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn conditionalExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.deltaExpr();
        var tokens: ?std.ArrayList(Token) = null;
        var exprs: ?std.ArrayList(*AST) = null;
        while (self.accept(.D_EQUALS) orelse self.accept(.NOT_EQUALS) orelse self.accept(.GTR) orelse self.accept(.LSR) orelse self.accept(.GTE) orelse self.accept(.LTE)) |token| {
            if (tokens == null) {
                tokens = std.ArrayList(Token).init(self.astAllocator);
                exprs = std.ArrayList(*AST).init(self.astAllocator);
                try exprs.?.append(exp);
            }
            try tokens.?.append(token);
            try exprs.?.append(try self.deltaExpr());
        } else {
            if (tokens == null) {
                return exp;
            } else {
                return try AST.createConditional(tokens.?, exprs.?, self.astAllocator);
            }
        }
    }

    fn deltaExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.coalesceExpr();
        while (true) {
            if (self.accept(.DELTA)) |token| {
                exp = try AST.createDelta(token, exp, try self.coalesceExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn coalesceExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.intExpr();
        while (true) {
            if (self.accept(.CATCH)) |token| {
                exp = try AST.createCatch(token, exp, try self.intExpr(), self.astAllocator);
            } else if (self.accept(.ORELSE)) |token| {
                exp = try AST.createOrelse(token, exp, try self.intExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn intExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.termExpr();
        while (true) {
            if (self.accept(.PLUS)) |token| {
                exp = try AST.createAdd(token, exp, try self.termExpr(), self.astAllocator);
            } else if (self.accept(.MINUS)) |token| {
                exp = try AST.createSub(token, exp, try self.termExpr(), self.astAllocator);
            } else if (self.accept(.E_MARK)) |token| {
                exp = try AST.createError(token, exp, try self.termExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn termExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.prefixExpr();
        while (true) {
            if (self.accept(.STAR)) |token| {
                exp = try AST.createMult(token, exp, try self.prefixExpr(), self.astAllocator);
            } else if (self.accept(.SLASH)) |token| {
                exp = try AST.createDiv(token, exp, try self.prefixExpr(), self.astAllocator);
            } else if (self.accept(.PERCENT)) |token| {
                exp = try AST.createMod(token, exp, try self.prefixExpr(), self.astAllocator);
            } else if (self.accept(.DIAMOND)) |token| {
                exp = try AST.createComposition(token, exp, try self.prefixExpr(), self.astAllocator);
            } else if (self.accept(.D_BAR)) |token| {
                exp = try AST.createUnion(token, exp, try self.prefixExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn prefixExpr(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.NOT)) |token| {
            return try AST.createNot(token, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.MINUS)) |token| {
            return try AST.createNegate(token, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.AMPERSAND)) |token| {
            var mut = self.accept(.MUT);
            return try AST.createAddrOf(token, try self.prefixExpr(), mut != null, self.astAllocator);
        } else if (self.accept(.L_SQUARE)) |token| {
            var sliceKind: ast.SliceKind = undefined;
            var len: ?*AST = null;
            if (self.accept(.MUT)) |_| {
                sliceKind = .MUT;
            } else if (self.accept(.STAR)) |_| {
                sliceKind = .MULTIPTR;
            } else if (self.nextIsExpr()) {
                sliceKind = .ARRAY;
                len = try self.expr();
            } else {
                sliceKind = .SLICE;
            }
            if (self.peekKind(.R_SQUARE)) {
                _ = self.expect(.R_SQUARE) catch {};
            } else {
                self.errors.addError(Error{ .missing_close = .{ .expected = .R_SQUARE, .got = self.peek(), .open = token, .stage = .parsing } });
                return error.parserError;
            }
            return try AST.createSliceOf(token, try self.prefixExpr(), len, sliceKind, self.astAllocator);
        } else if (self.accept(.Q_MARK)) |token| {
            return try AST.createOptional(token, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.TRY)) |token| {
            return try AST.createTry(token, try self.prependExpr(), self.astAllocator);
        } else {
            return try self.prependExpr();
        }
    }

    fn prependExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.exponentExpr();
        while (self.accept(.PERIOD_GTR)) |token| {
            exp = try AST.createPrepend(token, exp, try self.exponentExpr(), self.astAllocator);
        }
        return exp;
    }

    fn exponentExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.postfixExpr();
        var terms: ?std.ArrayList(*AST) = null;
        var first_token: ?Token = null;
        while (self.accept(.D_STAR)) |token| {
            if (terms == null) {
                terms = std.ArrayList(*AST).init(self.astAllocator);
                first_token = token;
                try terms.?.append(exp);
            }
            try terms.?.append(try self.postfixExpr());
        }
        if (terms) |terms_list| {
            return AST.createExponent(first_token.?, terms_list, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn postfixExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.factor();
        while (true) {
            if (self.peekKind(.L_PAREN)) {
                exp = try AST.createCall(self.peek(), exp, try self.parens(), self.astAllocator);
            } else if (self.accept(.L_SQUARE)) |token| {
                var first: ?*AST = null;
                if (self.nextIsExpr()) {
                    first = try self.expr();
                }
                if (self.accept(.D_PERIOD)) |_| {
                    var second: ?*AST = null;
                    if (self.nextIsExpr()) {
                        second = try self.expr();
                    }
                    exp = try AST.createSubSlice(token, exp, first, second, self.astAllocator);
                } else {
                    // Simple index
                    exp = try AST.createIndex(token, exp, first orelse {
                        self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "an expression within index", .got = self.peek(), .stage = .parsing } });
                        return ParserErrorEnum.parserError;
                    }, self.astAllocator);
                }
                if (self.peekKind(.R_SQUARE)) {
                    _ = self.expect(.R_SQUARE) catch {};
                } else {
                    self.errors.addError(Error{ .missing_close = .{ .expected = .R_SQUARE, .got = self.peek(), .open = token, .stage = .parsing } });
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

    fn factor(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.IDENTIFIER)) |token| {
            return try AST.createIdentifier(token, self.astAllocator);
        } else if (self.accept(.TRUE)) |token| {
            return try AST.createTrue(token, self.astAllocator);
        } else if (self.accept(.FALSE)) |token| {
            return try AST.createFalse(token, self.astAllocator);
        } else if (self.accept(.DECIMAL_INTEGER)) |token| {
            var apostropheAllocator = std.heap.ArenaAllocator.init(self.astAllocator);
            defer apostropheAllocator.deinit();
            var stripped = try stripApostrophes(token.data, apostropheAllocator.allocator());
            return try AST.createInt(token, try std.fmt.parseInt(i128, stripped, 10), self.astAllocator);
        } else if (self.accept(.HEX_INTEGER)) |token| {
            var apostropheAllocator = std.heap.ArenaAllocator.init(self.astAllocator);
            defer apostropheAllocator.deinit();
            var stripped = try stripApostrophes(token.data, apostropheAllocator.allocator());
            return try AST.createInt(token, try std.fmt.parseInt(i128, stripped[2..], 16), self.astAllocator);
        } else if (self.accept(.OCT_INTEGER)) |token| {
            var apostropheAllocator = std.heap.ArenaAllocator.init(self.astAllocator);
            defer apostropheAllocator.deinit();
            var stripped = try stripApostrophes(token.data, apostropheAllocator.allocator());
            return try AST.createInt(token, try std.fmt.parseInt(i128, stripped[2..], 8), self.astAllocator);
        } else if (self.accept(.BIN_INTEGER)) |token| {
            var apostropheAllocator = std.heap.ArenaAllocator.init(self.astAllocator);
            defer apostropheAllocator.deinit();
            var stripped = try stripApostrophes(token.data, apostropheAllocator.allocator());
            return try AST.createInt(token, try std.fmt.parseInt(i128, stripped[2..], 2), self.astAllocator);
        } else if (self.accept(.FLOAT)) |token| {
            var apostropheAllocator = std.heap.ArenaAllocator.init(self.astAllocator);
            defer apostropheAllocator.deinit();
            var stripped = try stripApostrophes(token.data, apostropheAllocator.allocator());
            return try AST.createFloat(token, try std.fmt.parseFloat(f64, stripped), self.astAllocator);
        } else if (self.accept(.CHAR)) |token| {
            return try AST.createChar(token, self.astAllocator);
        } else if (self.accept(.STRING)) |token| {
            return try AST.createString(token, self.astAllocator);
        } else if (self.peekKind(.INDENT)) {
            return try self.indentBlockExpr();
        } else if (self.peekKind(.L_BRACE)) {
            return try self.braceBlockExpr();
        } else if (self.peekKind(.IF)) {
            return try self.ifExpr();
        } else if (self.peekKind(.WHILE)) {
            return try self.whileExpr();
        } else if (self.peekKind(.FOR)) {
            return try self.forExpr();
        } else if (self.peekKind(.FN)) {
            return self.fnDeclaration();
        } else if (self.accept(.PERIOD)) |token| {
            var ident = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
            return try AST.createInferredMember(token, ident, self.astAllocator);
        } else if (self.accept(.UNREACHABLE)) |token| {
            return try AST.createUnreachable(token, self.astAllocator);
        } else if (self.peekKind(.L_PAREN)) {
            return try self.parens();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "an expression", .got = self.peek(), .stage = .parsing } });
            return ParserErrorEnum.parserError;
        }
    }

    fn indentBlockExpr(self: *Parser) ParserErrorEnum!*AST {
        var indent = try self.expect(.INDENT);

        while (self.accept(.NEWLINE)) |_| {}

        var statements = std.ArrayList(*AST).init(self.astAllocator);

        while (self.nextIsStatement()) {
            try statements.append(try self.statement());
            if (self.peekKind(.NEWLINE)) {
                _ = self.expect(.NEWLINE) catch {};
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a newline after statement", .got = self.peek(), .stage = .parsing } });
                return error.parserError;
            }
            while (self.accept(.NEWLINE)) |_| {}
        }

        var final: ?*AST = null;
        if (self.accept(.BREAK)) |token| {
            final = try AST.createBreak(token, self.astAllocator);
            while (self.accept(.NEWLINE)) |_| {}
        } else if (self.accept(.CONTINUE)) |token| {
            final = try AST.createContinue(token, self.astAllocator);
            while (self.accept(.NEWLINE)) |_| {}
        } else if (self.accept(.RETURN)) |token| {
            var exp: ?*AST = null;
            if (self.nextIsExpr()) {
                exp = try self.expr();
            }
            final = try AST.createReturn(token, exp, self.astAllocator);
            while (self.accept(.NEWLINE)) |_| {}
        }

        if (self.peekKind(.DEDENT)) {
            _ = self.expect(.DEDENT) catch {};
        } else {
            self.errors.addError(Error{ .missing_close = .{ .expected = .DEDENT, .got = self.peek(), .open = indent, .stage = .parsing } });
            return error.parserError;
        }

        return try AST.createBlock(indent, statements, final, self.astAllocator);
    }

    fn braceBlockExpr(self: *Parser) ParserErrorEnum!*AST {
        var indent = try self.expect(.L_BRACE);

        var statements = std.ArrayList(*AST).init(self.astAllocator);

        if (self.nextIsStatement()) {
            try statements.append(try self.statement());
            while (self.accept(.SEMICOLON)) |_| {
                try statements.append(try self.statement());
            }
        }

        var final: ?*AST = null;
        if (self.accept(.BREAK)) |token| {
            final = try AST.createBreak(token, self.astAllocator);
            while (self.accept(.SEMICOLON)) |_| {}
        } else if (self.accept(.CONTINUE)) |token| {
            final = try AST.createContinue(token, self.astAllocator);
            while (self.accept(.SEMICOLON)) |_| {}
        } else if (self.accept(.RETURN)) |token| {
            var exp: ?*AST = null;
            if (self.nextIsExpr()) {
                exp = try self.expr();
            }
            final = try AST.createReturn(token, exp, self.astAllocator);
            while (self.accept(.SEMICOLON)) |_| {}
        }

        if (self.peekKind(.R_BRACE)) {
            _ = self.expect(.R_BRACE) catch {};
        } else {
            self.errors.addError(Error{ .missing_close = .{ .expected = .R_BRACE, .got = self.peek(), .open = indent, .stage = .parsing } });
            return error.parserError;
        }

        return try AST.createBlock(indent, statements, final, self.astAllocator);
    }

    fn blockExpr(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.INDENT)) {
            return try self.indentBlockExpr();
        } else if (self.peekKind(.L_BRACE)) {
            return try self.braceBlockExpr();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a block", .got = self.peek(), .stage = .parsing } });
            return error.parserError;
        }
    }

    fn ifExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.IF);
        var let: ?*AST = null;
        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            let = try self.nonFnDeclaration();
            if (self.peekKind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek(), .stage = .parsing } });
                return error.parserError;
            }
        }
        var cond = try self.expr();
        var bodyBlock = try self.blockExpr();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.blockExpr();
        }

        return try AST.createIf(token, let, cond, bodyBlock, elseBlock, self.astAllocator);
    }

    fn whileExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.WHILE);
        var let: ?*AST = null;
        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            let = try self.nonFnDeclaration();
            if (self.peekKind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek(), .stage = .parsing } });
                return error.parserError;
            }
        }
        var cond = try self.expr();
        var post: ?*AST = null;
        if (self.accept(.SEMICOLON)) |_| {
            post = try self.statement();
        }
        var bodyBlock = try self.blockExpr();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.blockExpr();
        }

        return try AST.createWhile(token, let, cond, post, bodyBlock, elseBlock, self.astAllocator);
    }

    fn forExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.FOR);
        var let: ?*AST = null;
        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        _ = self.accept(.MUT);
        var elem = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
        _ = try self.expect(.IN);
        var iterable = try self.expr();
        var bodyBlock = try self.blockExpr();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.blockExpr();
        }

        return try AST.createFor(token, let, elem, iterable, bodyBlock, elseBlock, self.astAllocator);
    }

    fn fnDeclaration(self: *Parser) ParserErrorEnum!*AST {
        var introducer = try self.expect(.FN);
        var maybeIdent: ?*AST = null;

        if (self.accept(.IDENTIFIER)) |token| {
            maybeIdent = try AST.createIdentifier(token, self.astAllocator);
        }
        var params = try self.paramlist();
        _ = try self.expect(.RIGHT_SKINNY_ARROW);
        // var infer_token = self.accept(.E_MARK);
        // _ = infer_token;
        var retType = try self.arrowExpr();

        var refinement: ?*AST = null;
        if (self.accept(.WHERE)) |_| {
            _ = try self.arrowExpr();
        }

        var init = try self.blockExpr();

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

        var token = try self.expect(.L_PAREN);
        if (self.peekKind(.CONST) or self.peekKind(.MUT) or self.peekKind(.IDENTIFIER)) {
            try params.append(try self.param());
            if (self.accept(.COMMA)) |_| {
                try params.append(try self.param());
            }
        }
        if (self.peekKind(.R_PAREN)) {
            _ = self.expect(.R_PAREN) catch {};
        } else {
            self.errors.addError(Error{ .missing_close = .{ .expected = .R_PAREN, .got = self.peek(), .open = token, .stage = .parsing } });
            return error.parserError;
        }

        return params;
    }

    fn param(self: *Parser) ParserErrorEnum!*AST {
        var introducer: ?Token = self.accept(.MUT) orelse self.accept(.CONST);
        var ident = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
        _ = try self.expect(.COLON);
        var paramType = try self.arrowExpr();
        var init: ?*AST = null;
        if (self.accept(.EQUALS)) |_| {
            init = try self.arrowExpr();
        }

        return try AST.createDecl(
            if (introducer) |i| i else .{ .kind = .LET, .data = "let", .span = ident.getToken().span },
            ident,
            paramType,
            init,
            self.astAllocator,
        );
    }

    fn barClause(self: *Parser, kind: ast.MappingKind) ParserErrorEnum!*AST {
        var lhs = try self.annotExpr();
        var rhs: ?*AST = null;

        if (self.accept(.RIGHT_FAT_ARROW)) |_| {
            rhs = try self.annotExpr();
        }

        return try AST.createMapping(lhs.getToken(), kind, lhs, rhs, self.astAllocator);
    }

    fn barElse(self: *Parser, kind: ast.MappingKind) ParserErrorEnum!*AST {
        var token = try self.expect(.ELSE);
        if (self.peekKind(.RIGHT_FAT_ARROW)) {
            _ = self.expect(.RIGHT_FAT_ARROW) catch {};
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "`=>` after `else`", .got = self.peek(), .stage = .parsing } });
            return error.parserError;
        }
        var rhs = try self.annotExpr();

        return try AST.createMapping(token, kind, null, rhs, self.astAllocator);
    }

    /// returns whether the bar list has an else
    fn barListMiddle(self: *Parser, mappings: *std.ArrayList(*AST), kind: ast.MappingKind) ParserErrorEnum!bool {
        try mappings.append(try self.barClause(kind));
        if (self.accept(.BAR)) |_| {
            if (self.peekKind(.ELSE)) {
                try mappings.append(try self.barElse(kind));
                return true;
            } else if (self.nextIsExpr()) {
                return try self.barListMiddle(mappings, kind);
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "an expression after `|`", .got = self.peek(), .stage = .parsing } });
                return error.parserError;
            }
        } else {
            return false;
        }
    }

    fn barList(self: *Parser, mappings: *std.ArrayList(*AST), kind: ast.MappingKind) ParserErrorEnum!bool {
        _ = try self.expect(.BAR);
        return try self.barListMiddle(mappings, kind);
    }

    fn caseExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.CASE);
        var mappings = std.ArrayList(*AST).init(self.astAllocator);

        var let: ?*AST = null;
        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            let = try self.nonFnDeclaration();
            if (self.peekKind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek(), .stage = .parsing } });
                return error.parserError;
            } // Has to be here, otherwise the init expr of the let confuses the case's |'s with a sum expr
        }

        var has_else = try self.barList(&mappings, .case);

        return try AST.createCase(token, let, mappings, has_else, self.astAllocator);
    }

    fn matchExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.MATCH);
        var mappings = std.ArrayList(*AST).init(self.astAllocator);
        var let: ?*AST = null;

        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            let = try self.nonFnDeclaration();
            if (self.peekKind(.SEMICOLON)) {
                _ = self.expect(.SEMICOLON) catch {};
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a semicolon separating declaration and condition", .got = self.peek(), .stage = .parsing } });
                return error.parserError;
            }
        }
        var exp = try self.productExpr();
        _ = try self.barList(&mappings, .match);

        return try AST.createMatch(token, let, exp, mappings, self.astAllocator);
    }

    fn caseMatchExpr(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.CASE)) {
            return try self.caseExpr();
        } else if (self.peekKind(.MATCH)) {
            return try self.matchExpr();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .expected = "a block", .got = self.peek(), .stage = .parsing } });
            return ParserErrorEnum.parserError;
        }
    }

    fn parens(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.L_PAREN);
        var exp: ?*AST = null;
        if (self.nextIsExpr()) {
            exp = try self.expr();
        }
        if (self.peekKind(.R_PAREN)) {
            _ = self.expect(.R_PAREN) catch {};
        } else {
            self.errors.addError(Error{ .missing_close = .{ .expected = .R_PAREN, .got = self.peek(), .open = token, .stage = .parsing } });
            return error.parserError;
        }

        return exp orelse try AST.createUnit(token, self.astAllocator);
    }
};

/// This function takes an input array of unsigned 8-bit integers (`input`) and
/// an allocator and returns a new array on the allocator with the apostrophes
/// removed.
///
/// Used to remove apostrophes from number literals before they are parsed by
/// std.fmt parse functions, which cannot handle apostophes.
fn stripApostrophes(input: []const u8, allocator: std.mem.Allocator) ![]const u8 {
    var retval = String.init(allocator);
    defer retval.deinit();
    for (input) |c| {
        if (c != '\'') {
            var c1: [1]u8 = undefined;
            c1[0] = c;
            try retval.insert(&c1, retval.size);
        }
    }
    return (try retval.toOwned()).?;
}
