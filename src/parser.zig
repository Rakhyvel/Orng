const std = @import("std");

const ast = @import("ast.zig");
const layout = @import("layout.zig");
const lexer = @import("lexer.zig");
const main = @import("main.zig");
const _token = @import("token.zig");

const AST = ast.AST;
const ASTData = ast.ASTData;
const String = @import("zig-string/zig-string.zig").String;
const Token = _token.Token;
const TokenKind = _token.TokenKind;

const ParserError = struct {
    msg: String,
    line: i64,
    col: i64,
};

const ParserErrorEnum = error{parserError};

pub const Parser = struct {
    tokens: std.ArrayList(Token),
    errors: std.ArrayList(ParserError),
    cursor: usize,
    errorAllocator: std.mem.Allocator,
    astAllocator: std.mem.Allocator,

    pub fn create(tokens: std.ArrayList(Token), astAllocator: std.mem.Allocator, errorAllocator: std.mem.Allocator) !Parser {
        return .{ //
            .tokens = tokens,
            .errors = std.ArrayList(ParserError).init(errorAllocator),
            .cursor = 0,
            .errorAllocator = errorAllocator,
            .astAllocator = astAllocator,
        };
    }

    pub fn destroy(self: *Parser) void {
        self.errors.deinit();
    }

    fn peek(self: *Parser) Token {
        return self.tokens.items[self.cursor];
    }

    fn nextIsExpr(self: *Parser) bool {
        const nextKind = self.peek().kind;
        return nextKind == .E_MARK //
        or nextKind == .Q_MARK //
        or nextKind == .PERIOD //
        or nextKind == .AMPERSAND //
        or nextKind == .L_PAREN //
        or nextKind == .L_SQUARE //
        or nextKind == .L_BRACE //
        or nextKind == .INDENT //
        or nextKind == .BAR //
        or nextKind == .MINUS //
        or nextKind == .CASE //
        or nextKind == .COND //
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
        or nextKind == .REAL //
        or nextKind == .STRING;
    }

    fn nextIsStatement(self: *Parser) bool {
        const nextKind = self.peek().kind;
        return nextKind == .LET or nextKind == .CONST or nextKind == .DEFER or nextKind == .ERRDEFER or self.nextIsExpr();
    }

    fn accept(self: *Parser, kind: TokenKind) ?Token {
        var token = self.peek();
        if (token.kind == kind) {
            self.cursor += 1;
            return token;
        } else {
            return null;
        }
    }

    fn expect(self: *Parser, kind: TokenKind) ParserErrorEnum!Token {
        if (self.accept(kind)) |token| {
            return token;
        } else {
            const actual = self.peek();
            var error_string = String.init_with_contents(self.errorAllocator, "expected `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(kind) orelse "") catch unreachable;
            error_string.concat("`, got `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(actual.kind) orelse "") catch unreachable;
            error_string.concat("`") catch unreachable;
            self.errors.append(.{ .msg = error_string, .line = actual.line, .col = actual.col }) catch unreachable;
            return ParserErrorEnum.parserError;
            // unreachable;
        }
    }

    pub fn parse(self: *Parser) ParserErrorEnum!std.ArrayList(*AST) {
        var decls = std.ArrayList(*AST).init(self.astAllocator);
        while (self.accept(.NEWLINE)) |_| {}
        while (self.peek().kind != .EOF) {
            decls.append(try self.topLevelDeclaration()) catch unreachable;
            while (self.accept(.NEWLINE)) |_| {}
        }
        _ = try self.expect(.EOF);
        return decls;
    }

    fn topLevelDeclaration(self: *Parser) ParserErrorEnum!*AST {
        if (self.peek().kind == .FN) {
            return try self.fnDeclaration();
        } else if (self.peek().kind == .CONST) {
            return try self.constDeclaration();
        } else {
            const actual = self.peek();
            var error_string = String.init_with_contents(self.errorAllocator, "expected `fn` or `const`, got `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(actual.kind) orelse "") catch unreachable;
            error_string.concat("`") catch unreachable;
            self.errors.append(.{ .msg = error_string, .line = actual.line, .col = actual.col }) catch unreachable;
            return ParserErrorEnum.parserError;
        }
    }

    fn nonFnDeclaration(self: *Parser) ParserErrorEnum!*AST {
        if (self.peek().kind == .LET) {
            return try self.letDeclaration();
        } else if (self.peek().kind == .CONST) {
            return try self.constDeclaration();
        } else {
            const actual = self.peek();
            var error_string = String.init_with_contents(self.errorAllocator, "expected `let` or `const`, got `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(actual.kind) orelse "") catch unreachable;
            error_string.concat("`") catch unreachable;
            self.errors.append(.{ .msg = error_string, .line = actual.line, .col = actual.col }) catch unreachable;
            return ParserErrorEnum.parserError;
        }
    }

    fn constDeclaration(self: *Parser) ParserErrorEnum!*AST {
        _ = try self.expect(.CONST);
        var ident = AST.createIdent(try self.expect(.IDENTIFIER), self.astAllocator);
        var _type: ?*AST = null;

        if (self.accept(.COLON)) |_| {
            _type = try self.arrowExpr();
        }
        _ = try self.expect(.EQUALS);
        var init = try self.expr();

        return AST.createDecl(
            ident.token,
            .CONST,
            ident,
            _type,
            init,
            self.astAllocator,
        );
    }

    fn letDeclaration(self: *Parser) ParserErrorEnum!*AST {
        _ = try self.expect(.LET);
        var maybeMut = self.accept(.MUT);
        var ident = AST.createIdent(try self.expect(.IDENTIFIER), self.astAllocator);
        var _type: ?*AST = null;
        var init: ?*AST = null;

        if (self.accept(.COLON)) |_| {
            _type = try self.arrowExpr();
            if (self.peek().kind == .EQUALS) {
                _ = try self.expect(.EQUALS);
                init = try self.expr();
            }
        } else if (self.accept(.EQUALS)) |_| {
            init = try self.expr();
        } else {
            self.errors.append(.{ .msg = String.init_with_contents(self.errorAllocator, "variable declarations require at least a type or a initial value") catch unreachable, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
        }

        return AST.createDecl(
            ident.token,
            if (maybeMut) |_| .MUT else .LET,
            ident,
            _type,
            init,
            self.astAllocator,
        );
    }

    fn fnDeclaration(self: *Parser) ParserErrorEnum!*AST {
        var introducer = try self.expect(.FN);
        var maybeIdent: ?*AST = null;

        if (self.accept(.IDENTIFIER)) |token| {
            maybeIdent = AST.createIdent(token, self.astAllocator);
            _ = try self.expect(.COLON);
        }
        var params = try self.paramlist();
        _ = try self.expect(.RIGHT_SKINNY_ARROW);
        var retType = try self.arrowExpr();

        var refinement: ?*AST = null;
        if (self.accept(.WHERE)) |_| {
            _ = try self.arrowExpr();
        }

        _ = try self.expect(.EQUALS);
        var init = try self.expr();

        return AST.createFnDecl(
            introducer,
            maybeIdent,
            params,
            retType,
            refinement,
            init,
            self.astAllocator,
        );
    }

    fn paramlist(self: *Parser) ParserErrorEnum!std.ArrayList(*AST) {
        var params = std.ArrayList(*AST).init(self.astAllocator);
        errdefer params.deinit();

        _ = try self.expect(.L_PAREN);
        if (self.peek().kind == .CONST or self.peek().kind == .MUT or self.peek().kind == .IDENTIFIER) {
            params.append(try self.param()) catch unreachable;
            if (self.accept(.COMMA)) |_| {
                params.append(try self.param()) catch unreachable;
            }
        }
        _ = try self.expect(.R_PAREN);

        return params;
    }

    fn param(self: *Parser) ParserErrorEnum!*AST {
        var introducer: ?Token = self.accept(.MUT) orelse self.accept(.CONST);
        var ident = AST.createIdent(try self.expect(.IDENTIFIER), self.astAllocator);
        _ = try self.expect(.COLON);
        var paramType = try self.annotExpr();
        var init: ?*AST = null;
        if (self.accept(.BACK_SLASH)) |_| {
            init = try self.arrowExpr();
        }

        return AST.createDecl(
            ident.token,
            if (introducer) |i| i.kind else .LET,
            ident,
            paramType,
            init,
            self.astAllocator,
        );
    }

    fn statement(self: *Parser) ParserErrorEnum!*AST {
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            return self.nonFnDeclaration();
        } else if (self.accept(.DEFER)) |token| {
            return AST.createDefer(token, try self.expr(), self.astAllocator);
        } else if (self.accept(.ERRDEFER)) |token| {
            return AST.createDefer(token, try self.expr(), self.astAllocator);
        } else {
            var exp = try self.expr();
            if (self.accept(.EQUALS)) |token| {
                return AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else if (self.accept(.PLUS_EQUALS)) |token| {
                return AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn expr(self: *Parser) ParserErrorEnum!*AST {
        if (self.peek().kind == .FN) {
            return self.fnDeclaration();
        } else if (self.peek().kind == .COND) {
            return self.condExpr();
        } else if (self.peek().kind == .CASE) {
            return self.caseExpr();
        } else {
            return self.sumType();
        }
    }

    fn sumType(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.productExpr();
        while (self.accept(.BAR)) |token| {
            exp = AST.createBinop(token, .SUM, exp, try self.annotExpr(), self.astAllocator);
        }
        return exp;
    }

    fn productExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.annotExpr();
        while (self.accept(.COMMA)) |token| {
            exp = AST.createBinop(token, .PRODUCT, exp, try self.annotExpr(), self.astAllocator);
        }
        return exp;
    }

    fn annotExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.arrowExpr();
        if (self.accept(.COLON)) |token| {
            var _type = try self.arrowExpr();
            var predicate: ?*AST = null;
            var init: ?*AST = null;
            if (self.accept(.WHERE)) |_| {
                predicate = try self.arrowExpr();
            }
            if (self.accept(.BACK_SLASH)) |_| {
                init = try self.arrowExpr();
            }
            return AST.createAnnotation(token, exp, _type, predicate, init, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn arrowExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.boolExpr();
        while (self.accept(.RIGHT_SKINNY_ARROW)) |token| {
            exp = AST.createBinop(token, .ARROW, exp, try self.boolExpr(), self.astAllocator);
        }
        return exp;
    }

    fn boolExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.neqExpr();
        while (true) {
            if (self.accept(.AND)) |token| {
                exp = AST.createBinop(token, .AND, exp, try self.neqExpr(), self.astAllocator);
            } else if (self.accept(.OR)) |token| {
                exp = AST.createBinop(token, .OR, exp, try self.neqExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn neqExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.conditionalExpr();
        if (self.accept(.NOT_EQUALS)) |token| {
            return AST.createBinop(token, .NOT_EQUALS, exp, try self.conditionalExpr(), self.astAllocator);
        } else {
            return exp;
        }
    }

    fn conditionalExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.deltaExpr();
        while (true) {
            if (self.accept(.D_EQUALS)) |token| {
                exp = AST.createBinop(token, .EQUALS, exp, try self.deltaExpr(), self.astAllocator);
            } else if (self.accept(.GTR)) |token| {
                exp = AST.createBinop(token, .GREATER_THAN, exp, try self.deltaExpr(), self.astAllocator);
            } else if (self.accept(.LSR)) |token| {
                exp = AST.createBinop(token, .LESSER_THAN, exp, try self.deltaExpr(), self.astAllocator);
            } else if (self.accept(.GTE)) |token| {
                exp = AST.createBinop(token, .GREATER_EQUALS, exp, try self.deltaExpr(), self.astAllocator);
            } else if (self.accept(.LTE)) |token| {
                exp = AST.createBinop(token, .LESSER_EQUALS, exp, try self.deltaExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn deltaExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.coalesceExpr();
        while (true) {
            if (self.accept(.DELTA)) |token| {
                exp = AST.createBinop(token, .DELTA, exp, try self.coalesceExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn coalesceExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.intExpr();
        while (true) {
            if (self.accept(.CATCH)) |token| {
                exp = AST.createBinop(token, .CATCH, exp, try self.intExpr(), self.astAllocator);
            } else if (self.accept(.ORELSE)) |token| {
                exp = AST.createBinop(token, .ORELSE, exp, try self.intExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn intExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.termExpr();
        while (true) {
            if (self.accept(.PLUS)) |token| {
                exp = AST.createBinop(token, .ADD, exp, try self.termExpr(), self.astAllocator);
            } else if (self.accept(.MINUS)) |token| {
                exp = AST.createBinop(token, .ADD, exp, try self.termExpr(), self.astAllocator);
            } else if (self.accept(.D_E_MARK)) |token| {
                exp = AST.createBinop(token, .ADD, exp, try self.termExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn termExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.exponentExpr();
        while (true) {
            if (self.accept(.STAR)) |token| {
                exp = AST.createBinop(token, .MULT, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.SLASH)) |token| {
                exp = AST.createBinop(token, .DIV, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.PERCENT)) |token| {
                exp = AST.createBinop(token, .MOD, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.DIAMOND)) |token| {
                exp = AST.createBinop(token, .COMPOSITION, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.D_PLUS)) |token| {
                exp = AST.createBinop(token, .TUPLE_CONCAT, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.D_MINUS)) |token| {
                exp = AST.createBinop(token, .TUPLE_DIFF, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.D_BAR)) |token| {
                exp = AST.createBinop(token, .SUM_UNION, exp, try self.exponentExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn exponentExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.prefixExpr();
        while (self.accept(.D_STAR)) |token| {
            exp = AST.createBinop(token, .POW, exp, try self.prefixExpr(), self.astAllocator);
        }
        return exp;
    }

    fn prefixExpr(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.E_MARK)) |token| {
            return AST.createUnop(token, .NOT, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.MINUS)) |token| {
            return AST.createUnop(token, .NEG, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.AMPERSAND)) |token| {
            var mut = self.accept(.MUT);
            return AST.createAddr(token, try self.prefixExpr(), mut != null, self.astAllocator);
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
            _ = try self.expect(.R_SQUARE);
            return AST.createSliceOf(token, try self.prefixExpr(), len, sliceKind, self.astAllocator);
        } else if (self.accept(.Q_MARK)) |token| {
            return AST.createUnop(token, .OPTIONAL, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.TRY)) |token| {
            return AST.createUnop(token, .TRY, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.PERIOD)) |token| {
            var ident = AST.createIdent(try self.expect(.IDENTIFIER), self.astAllocator);
            if (self.accept(.LEFT_SKINNY_ARROW)) |_| {
                return AST.createNamedArg(token, ident, try self.prefixExpr(), self.astAllocator);
            } else if (self.peek().kind == .L_PAREN) {
                return AST.createInferredMember(token, ident, try self.parens(), self.astAllocator);
            } else {
                return AST.createInferredMember(token, ident, null, self.astAllocator);
            }
        } else {
            return try self.prependExpr();
        }
    }

    fn prependExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.postfixExpr();
        while (self.accept(.PERIOD_GTR)) |token| {
            exp = AST.createBinop(token, .UFCS, exp, try self.postfixExpr(), self.astAllocator);
        }
        return exp;
    }

    fn postfixExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.factor();
        while (true) {
            if (self.peek().kind == .L_PAREN) {
                exp = AST.createBinop(self.peek(), .CALL, exp, try self.parens(), self.astAllocator);
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
                    exp = AST.createSubSlice(token, exp, first, second, self.astAllocator);
                } else {
                    // Simple index
                    exp = AST.createBinop(token, .INDEX, exp, first.?, self.astAllocator);
                }
                _ = try self.expect(.R_SQUARE);
            } else if (self.accept(.PERIOD)) |token| {
                exp = AST.createBinop(
                    token,
                    .SELECT,
                    exp,
                    AST.createIdent(
                        try self.expect(.IDENTIFIER),
                        self.astAllocator,
                    ),
                    self.astAllocator,
                );
            } else if (self.accept(.PERIOD_Q_MARK)) |token| {
                exp = AST.createUnop(token, .FROM_OPTIONAL, exp, self.astAllocator);
            } else if (self.accept(.CARET)) |token| {
                exp = AST.createUnop(token, .DEREFERENCE, exp, self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn factor(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.IDENTIFIER)) |token| {
            return AST.createIdent(token, self.astAllocator);
        } else if (self.accept(.DECIMAL_INTEGER)) |token| {
            return AST.createInt(token, intFromToken(token, 10), self.astAllocator);
        } else if (self.accept(.HEX_INTEGER)) |token| {
            return AST.createInt(token, intFromToken(token, 16), self.astAllocator);
        } else if (self.accept(.OCT_INTEGER)) |token| {
            return AST.createInt(token, intFromToken(token, 8), self.astAllocator);
        } else if (self.accept(.BIN_INTEGER)) |token| {
            return AST.createInt(token, intFromToken(token, 2), self.astAllocator);
        } else if (self.accept(.REAL)) |token| {
            return AST.createReal(token, std.fmt.parseFloat(f64, token.data) catch 0, self.astAllocator);
        } else if (self.accept(.CHAR)) |token| {
            return AST.createInt(token, token.data[1], self.astAllocator);
        } else if (self.accept(.STRING)) |token| {
            return AST.createString(token, self.astAllocator);
        } else if (self.peek().kind == .INDENT) {
            return try self.indentBlockExpr();
        } else if (self.peek().kind == .L_BRACE) {
            return try self.braceBlockExpr();
        } else if (self.peek().kind == .IF) {
            return try self.ifExpr();
        } else if (self.peek().kind == .WHILE) {
            return try self.whileExpr();
        } else if (self.peek().kind == .FOR) {
            return try self.forExpr();
        } else if (self.accept(.UNREACHABLE)) |token| {
            return AST.createUnreachable(token, self.astAllocator);
        } else if (self.peek().kind == .L_PAREN) {
            return try self.parens();
        } else {
            var error_string = String.init_with_contents(self.errorAllocator, "expected an expression, got `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(self.peek().kind) orelse "") catch unreachable;
            error_string.concat("`") catch unreachable;
            self.errors.append(.{ .msg = error_string, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
            return ParserErrorEnum.parserError;
        }
    }

    fn indentBlockExpr(self: *Parser) ParserErrorEnum!*AST {
        var indent = try self.expect(.INDENT);

        while (self.accept(.NEWLINE)) |_| {}

        var statements = std.ArrayList(*AST).init(self.astAllocator);

        if (self.nextIsStatement()) {
            statements.append(try self.statement()) catch unreachable;
            while (self.accept(.NEWLINE)) |_| {
                while (self.accept(.NEWLINE)) |_| {}
                statements.append(try self.statement()) catch unreachable;
            }
        }

        var final: ?*AST = null;
        if (self.accept(.BREAK)) |token| {
            final = AST.createBreak(token, self.astAllocator);
        } else if (self.accept(.CONTINUE)) |token| {
            final = AST.createContinue(token, self.astAllocator);
        } else if (self.accept(.RETURN)) |token| {
            var exp: ?*AST = null;
            if (self.nextIsExpr()) {
                exp = try self.expr();
            }
            final = AST.createReturn(token, exp, self.astAllocator);
        } else if (self.accept(.THROW)) |token| {
            final = AST.createThrow(token, try self.expr(), self.astAllocator);
        }

        // TODO: Better error messages, if missing newline, hits this expect, which doesn't give much info
        _ = try self.expect(.DEDENT);

        return AST.createBlock(indent, statements, final, self.astAllocator);
    }

    fn braceBlockExpr(self: *Parser) ParserErrorEnum!*AST {
        var indent = try self.expect(.L_BRACE);

        var statements = std.ArrayList(*AST).init(self.astAllocator);

        if (self.nextIsStatement()) {
            statements.append(try self.statement()) catch unreachable;
            while (self.accept(.SEMICOLON)) |_| {
                statements.append(try self.statement()) catch unreachable;
            }
        }

        var final: ?*AST = null;
        if (self.accept(.BREAK)) |token| {
            final = AST.createBreak(token, self.astAllocator);
        } else if (self.accept(.CONTINUE)) |token| {
            final = AST.createContinue(token, self.astAllocator);
        } else if (self.accept(.RETURN)) |token| {
            var exp: ?*AST = null;
            if (self.nextIsExpr()) {
                exp = try self.expr();
            }
            final = AST.createReturn(token, exp, self.astAllocator);
        } else if (self.accept(.THROW)) |token| {
            final = AST.createThrow(token, try self.expr(), self.astAllocator);
        }

        _ = try self.expect(.R_BRACE);

        return AST.createBlock(indent, statements, final, self.astAllocator);
    }

    fn blockExpr(self: *Parser) ParserErrorEnum!*AST {
        if (self.peek().kind == .INDENT) {
            return try self.indentBlockExpr();
        } else if (self.peek().kind == .L_BRACE) {
            return try self.braceBlockExpr();
        } else {
            self.errors.append(.{ .msg = String.init_with_contents(self.errorAllocator, "expected an block") catch unreachable, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
            return ParserErrorEnum.parserError;
        }
    }

    fn ifExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.IF);
        var let: ?*AST = null;
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        var cond = try self.expr();
        var bodyBlock = try self.blockExpr();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.blockExpr();
        }

        return AST.createIf(token, let, cond, bodyBlock, elseBlock, self.astAllocator);
    }

    fn whileExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.WHILE);
        var let: ?*AST = null;
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        var cond = try self.expr();
        var post: ?*AST = null;
        if (self.accept(.SEMICOLON)) |_| {
            post = try self.statement();
        }
        std.debug.print("{s}\n", .{self.peek().data});
        var bodyBlock = try self.blockExpr();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.blockExpr();
        }

        return AST.createWhile(token, let, cond, post, bodyBlock, elseBlock, self.astAllocator);
    }

    fn forExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.FOR);
        var let: ?*AST = null;
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        _ = self.accept(.MUT);
        var elem = AST.createIdent(try self.expect(.IDENTIFIER), self.astAllocator);
        _ = try self.expect(.IN);
        var iterable = try self.expr();
        var bodyBlock = try self.blockExpr();
        var elseBlock: ?*AST = null;
        if (self.accept(.ELSE)) |_| {
            elseBlock = try self.blockExpr();
        }

        return AST.createFor(token, let, elem, iterable, bodyBlock, elseBlock, self.astAllocator);
    }

    fn barClause(self: *Parser) ParserErrorEnum!*AST {
        var lhs = try self.productExpr();
        var rhs: ?*AST = null;

        if (self.accept(.RIGHT_FAT_ARROW)) |_| {
            rhs = try self.expr();
            _ = try self.expect(.SEMICOLON);
        }

        return AST.createMapping(lhs.token, lhs, rhs, self.astAllocator);
    }

    fn barElse(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.ELSE);
        _ = try self.expect(.RIGHT_FAT_ARROW);
        var rhs = try self.expr();

        _ = try self.expect(.SEMICOLON);

        return AST.createMapping(token, null, rhs, self.astAllocator);
    }

    fn barListMiddle(self: *Parser, mappings: *std.ArrayList(*AST)) ParserErrorEnum!void {
        mappings.append(try self.barClause()) catch unreachable;
        if (self.accept(.BAR)) |_| {
            if (self.peek().kind == .ELSE) {
                mappings.append(try self.barElse()) catch unreachable;
            } else if (self.nextIsExpr()) {
                try self.barListMiddle(mappings);
            } else {
                self.errors.append(.{ .msg = String.init_with_contents(self.errorAllocator, "expected an expression after `=>`") catch unreachable, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
            }
        }
    }

    fn barList(self: *Parser, mappings: *std.ArrayList(*AST)) ParserErrorEnum!void {
        _ = try self.expect(.BAR);
        try self.barListMiddle(mappings);
    }

    fn condExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.COND);
        var mappings = std.ArrayList(*AST).init(self.astAllocator);
        try self.barList(&mappings);
        var let: ?*AST = null;

        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }

        return AST.createCond(token, let, mappings, self.astAllocator);
    }

    fn caseExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.CASE);
        var mappings = std.ArrayList(*AST).init(self.astAllocator);
        var let: ?*AST = null;

        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        var exp = try self.productExpr();
        try self.barList(&mappings);

        return AST.createCase(token, let, exp, mappings, self.astAllocator);
    }

    fn parens(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.L_PAREN);
        var exp: ?*AST = null;
        if (self.nextIsExpr()) {
            exp = try self.expr();
        }
        _ = try self.expect(.R_PAREN);

        return exp orelse AST.createUnit(token, self.astAllocator);
    }
};

fn intFromToken(token: Token, radix: i128) i128 {
    var retval: i128 = 0;
    var i: usize = 0;
    while (i < token.data.len) : (i += 1) {
        if (std.ascii.isDigit(token.data[i])) {
            retval *= radix;
            retval += token.data[i] - '0';
        } else if (token.data[i] >= 'A' and token.data[i] <= 'F') {
            retval *= radix;
            retval += token.data[i] - 'A' + 10;
        } else if (token.data[i] >= 'a' and token.data[i] <= 'f') {
            retval *= radix;
            retval += token.data[i] - 'a' + 10;
        }
    }
    return retval;
}
