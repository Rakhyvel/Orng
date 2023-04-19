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
            self.errors.addError(Error{ .expected2Token = .{ .span = self.peek().span, .expected = kind, .got = self.peek().kind } });
            return ParserErrorEnum.parserError;
            // unreachable;
        }
    }

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
            return try self.constDeclaration();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .span = self.peek().span, .expected = "`fn` or `const`", .got = self.peek().kind } });
            return ParserErrorEnum.parserError;
        }
    }

    fn nonFnDeclaration(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.LET)) {
            return try self.letDeclaration();
        } else if (self.peekKind(.CONST)) {
            return try self.constDeclaration();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .span = self.peek().span, .expected = "`let` or `const`", .got = self.peek().kind } });
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
        if (!self.peekKind(.EOF)) {
            _ = try self.expect(.NEWLINE);
        }

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
            self.errors.addError(Error{ .basic = .{ .span = self.peek().span, .msg = "variable declarations require at least a type or an intial value" } });
        }

        return try AST.createDecl(
            if (maybeMut) |mut| mut else definitelyLet,
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
            maybeIdent = try AST.createIdentifier(token, self.astAllocator);
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

        return try AST.createFnDecl(
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
        if (self.peekKind(.CONST) or self.peekKind(.MUT) or self.peekKind(.IDENTIFIER)) {
            try params.append(try self.param());
            if (self.accept(.COMMA)) |_| {
                try params.append(try self.param());
            }
        }
        _ = try self.expect(.R_PAREN);

        return params;
    }

    fn param(self: *Parser) ParserErrorEnum!*AST {
        var introducer: ?Token = self.accept(.MUT) orelse self.accept(.CONST);
        var ident = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
        _ = try self.expect(.COLON);
        var paramType = try self.annotExpr();
        var init: ?*AST = null;
        if (self.accept(.BACK_SLASH)) |_| {
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

    fn statement(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            return self.nonFnDeclaration();
        } else if (self.accept(.DEFER)) |token| {
            return try AST.createDefer(token, try self.expr(), self.astAllocator);
        } else if (self.accept(.ERRDEFER)) |token| {
            return try AST.createDefer(token, try self.expr(), self.astAllocator);
        } else {
            var exp = try self.expr();
            if (self.accept(.EQUALS)) |token| {
                return try AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else if (self.accept(.PLUS_EQUALS)) |token| {
                return try AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else if (self.accept(.MINUS_EQUALS)) |token| {
                return try AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else if (self.accept(.STAR_EQUALS)) |token| {
                return try AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else if (self.accept(.SLASH_EQUALS)) |token| {
                return try AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else if (self.accept(.PERCENT_EQUALS)) |token| {
                return try AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else if (self.accept(.D_STAR_EQUALS)) |token| {
                return try AST.createAssign(token, exp, try self.expr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn expr(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.FN)) {
            return self.fnDeclaration();
        } else if (self.peekKind(.COND)) {
            return self.condExpr();
        } else if (self.peekKind(.CASE)) {
            return self.caseExpr();
        } else {
            return self.sumType();
        }
    }

    fn sumType(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.productExpr();
        while (self.accept(.BAR)) |token| {
            exp = try AST.createBinop(token, exp, try self.annotExpr(), self.astAllocator);
        }
        return exp;
    }

    fn productExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.annotExpr();
        while (self.accept(.COMMA)) |token| {
            exp = try AST.createBinop(token, exp, try self.annotExpr(), self.astAllocator);
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
            return try AST.createAnnotation(token, exp, _type, predicate, init, self.astAllocator);
        } else {
            return exp;
        }
    }

    fn arrowExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.boolExpr();
        while (self.accept(.RIGHT_SKINNY_ARROW)) |token| {
            exp = try AST.createBinop(token, exp, try self.boolExpr(), self.astAllocator);
        }
        return exp;
    }

    fn boolExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.neqExpr();
        while (true) {
            if (self.accept(.AND)) |token| {
                exp = try AST.createBinop(token, exp, try self.neqExpr(), self.astAllocator);
            } else if (self.accept(.OR)) |token| {
                exp = try AST.createBinop(token, exp, try self.neqExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn neqExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.conditionalExpr();
        if (self.accept(.NOT_EQUALS)) |token| {
            return try AST.createBinop(token, exp, try self.conditionalExpr(), self.astAllocator);
        } else {
            return exp;
        }
    }

    fn conditionalExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.deltaExpr();
        while (true) {
            if (self.accept(.D_EQUALS)) |token| {
                exp = try AST.createBinop(token, exp, try self.deltaExpr(), self.astAllocator);
            } else if (self.accept(.GTR)) |token| {
                exp = try AST.createBinop(token, exp, try self.deltaExpr(), self.astAllocator);
            } else if (self.accept(.LSR)) |token| {
                exp = try AST.createBinop(token, exp, try self.deltaExpr(), self.astAllocator);
            } else if (self.accept(.GTE)) |token| {
                exp = try AST.createBinop(token, exp, try self.deltaExpr(), self.astAllocator);
            } else if (self.accept(.LTE)) |token| {
                exp = try AST.createBinop(token, exp, try self.deltaExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn deltaExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.coalesceExpr();
        while (true) {
            if (self.accept(.DELTA)) |token| {
                exp = try AST.createBinop(token, exp, try self.coalesceExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn coalesceExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.intExpr();
        while (true) {
            if (self.accept(.CATCH)) |token| {
                exp = try AST.createBinop(token, exp, try self.intExpr(), self.astAllocator);
            } else if (self.accept(.ORELSE)) |token| {
                exp = try AST.createBinop(token, exp, try self.intExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn intExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.termExpr();
        while (true) {
            if (self.accept(.PLUS)) |token| {
                exp = try AST.createBinop(token, exp, try self.termExpr(), self.astAllocator);
            } else if (self.accept(.MINUS)) |token| {
                exp = try AST.createBinop(token, exp, try self.termExpr(), self.astAllocator);
            } else if (self.accept(.E_MARK)) |token| {
                exp = try AST.createBinop(token, exp, try self.termExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn termExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.exponentExpr();
        while (true) {
            if (self.accept(.STAR)) |token| {
                exp = try AST.createBinop(token, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.SLASH)) |token| {
                exp = try AST.createBinop(token, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.PERCENT)) |token| {
                exp = try AST.createBinop(token, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.DIAMOND)) |token| {
                exp = try AST.createBinop(token, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.D_PLUS)) |token| {
                exp = try AST.createBinop(token, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.D_MINUS)) |token| {
                exp = try AST.createBinop(token, exp, try self.exponentExpr(), self.astAllocator);
            } else if (self.accept(.D_BAR)) |token| {
                exp = try AST.createBinop(token, exp, try self.exponentExpr(), self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn exponentExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.prefixExpr();
        while (self.accept(.D_STAR)) |token| {
            exp = try AST.createBinop(token, exp, try self.prefixExpr(), self.astAllocator);
        }
        return exp;
    }

    fn prefixExpr(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.NOT)) |token| {
            return try AST.createUnop(token, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.E_MARK)) |token| {
            return try AST.createUnop(token, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.MINUS)) |token| {
            return try AST.createUnop(token, try self.prependExpr(), self.astAllocator);
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
            _ = try self.expect(.R_SQUARE);
            return try AST.createSliceOf(token, try self.prefixExpr(), len, sliceKind, self.astAllocator);
        } else if (self.accept(.Q_MARK)) |token| {
            return try AST.createUnop(token, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.TRY)) |token| {
            return try AST.createUnop(token, try self.prependExpr(), self.astAllocator);
        } else if (self.accept(.PERIOD)) |token| {
            var ident = try AST.createIdentifier(try self.expect(.IDENTIFIER), self.astAllocator);
            if (self.accept(.LEFT_SKINNY_ARROW)) |_| {
                return try AST.createNamedArg(token, ident, try self.prefixExpr(), self.astAllocator);
            } else if (self.peekKind(.L_PAREN)) {
                return try AST.createInferredMember(token, ident, try self.parens(), self.astAllocator);
            } else {
                return try AST.createInferredMember(token, ident, null, self.astAllocator);
            }
        } else {
            return try self.prependExpr();
        }
    }

    fn prependExpr(self: *Parser) ParserErrorEnum!*AST {
        var exp = try self.postfixExpr();
        while (self.accept(.PERIOD_GTR)) |token| {
            exp = try AST.createBinop(token, exp, try self.postfixExpr(), self.astAllocator);
        }
        return exp;
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
                    exp = try AST.createBinop(token, exp, first orelse {
                        self.errors.addError(Error{ .expectedBasicToken = .{ .span = self.peek().span, .expected = "a block", .got = self.peek().kind } });
                        return ParserErrorEnum.parserError;
                    }, self.astAllocator);
                }
                _ = try self.expect(.R_SQUARE);
            } else if (self.accept(.PERIOD)) |token| {
                exp = try AST.createBinop(
                    token,
                    exp,
                    try AST.createIdentifier(
                        try self.expect(.IDENTIFIER),
                        self.astAllocator,
                    ),
                    self.astAllocator,
                );
            } else if (self.accept(.PERIOD_Q_MARK)) |token| {
                exp = try AST.createUnop(token, exp, self.astAllocator);
            } else if (self.accept(.CARET)) |token| {
                exp = try AST.createUnop(token, exp, self.astAllocator);
            } else {
                return exp;
            }
        }
    }

    fn factor(self: *Parser) ParserErrorEnum!*AST {
        if (self.accept(.IDENTIFIER)) |token| {
            return try AST.createIdentifier(token, self.astAllocator);
        } else if (self.accept(.DECIMAL_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data, 10), self.astAllocator);
        } else if (self.accept(.HEX_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data, 16), self.astAllocator);
        } else if (self.accept(.OCT_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data, 8), self.astAllocator);
        } else if (self.accept(.BIN_INTEGER)) |token| {
            return try AST.createInt(token, try std.fmt.parseInt(i128, token.data, 2), self.astAllocator);
        } else if (self.accept(.REAL)) |token| {
            return try AST.createFloat(token, try std.fmt.parseFloat(f64, token.data), self.astAllocator);
        } else if (self.accept(.CHAR)) |token| {
            return try AST.createInt(token, token.data[1], self.astAllocator);
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
        } else if (self.accept(.UNREACHABLE)) |token| {
            return try AST.createUnreachable(token, self.astAllocator);
        } else if (self.peekKind(.L_PAREN)) {
            return try self.parens();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .span = self.peek().span, .expected = "an expression", .got = self.peek().kind } });
            return ParserErrorEnum.parserError;
        }
    }

    fn indentBlockExpr(self: *Parser) ParserErrorEnum!*AST {
        var indent = try self.expect(.INDENT);

        while (self.accept(.NEWLINE)) |_| {}

        var statements = std.ArrayList(*AST).init(self.astAllocator);

        if (self.nextIsStatement()) {
            try statements.append(try self.statement());
            while (self.accept(.NEWLINE)) |_| {
                while (self.accept(.NEWLINE)) |_| {}
                try statements.append(try self.statement());
            }
        }

        var final: ?*AST = null;
        if (self.accept(.BREAK)) |token| {
            final = try AST.createBreak(token, self.astAllocator);
        } else if (self.accept(.CONTINUE)) |token| {
            final = try AST.createContinue(token, self.astAllocator);
        } else if (self.accept(.RETURN)) |token| {
            var exp: ?*AST = null;
            if (self.nextIsExpr()) {
                exp = try self.expr();
            }
            final = try AST.createReturn(token, exp, self.astAllocator);
        } else if (self.accept(.THROW)) |token| {
            final = try AST.createThrow(token, try self.expr(), self.astAllocator);
        }

        // TODO: Better error messages, if missing newline, hits this expect, which doesn't give much info
        _ = try self.expect(.DEDENT);

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
        } else if (self.accept(.CONTINUE)) |token| {
            final = try AST.createContinue(token, self.astAllocator);
        } else if (self.accept(.RETURN)) |token| {
            var exp: ?*AST = null;
            if (self.nextIsExpr()) {
                exp = try self.expr();
            }
            final = try AST.createReturn(token, exp, self.astAllocator);
        } else if (self.accept(.THROW)) |token| {
            final = try AST.createThrow(token, try self.expr(), self.astAllocator);
        }

        _ = try self.expect(.R_BRACE);

        return try AST.createBlock(indent, statements, final, self.astAllocator);
    }

    fn blockExpr(self: *Parser) ParserErrorEnum!*AST {
        if (self.peekKind(.INDENT)) {
            return try self.indentBlockExpr();
        } else if (self.peekKind(.L_BRACE)) {
            return try self.braceBlockExpr();
        } else {
            self.errors.addError(Error{ .expectedBasicToken = .{ .span = self.peek().span, .expected = "a block", .got = self.peek().kind } });
            return ParserErrorEnum.parserError;
        }
    }

    fn ifExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.IF);
        var let: ?*AST = null;
        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
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

    fn barClause(self: *Parser) ParserErrorEnum!*AST {
        var lhs = try self.productExpr();
        var rhs: ?*AST = null;

        if (self.accept(.RIGHT_FAT_ARROW)) |_| {
            rhs = try self.expr();
            _ = try self.expect(.SEMICOLON);
        }

        return try AST.createMapping(lhs.getToken(), lhs, rhs, self.astAllocator);
    }

    fn barElse(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.ELSE);
        _ = try self.expect(.RIGHT_FAT_ARROW);
        var rhs = try self.expr();

        _ = try self.expect(.SEMICOLON);

        return try AST.createMapping(token, null, rhs, self.astAllocator);
    }

    fn barListMiddle(self: *Parser, mappings: *std.ArrayList(*AST)) ParserErrorEnum!void {
        try mappings.append(try self.barClause());
        if (self.accept(.BAR)) |_| {
            if (self.peekKind(.ELSE)) {
                try mappings.append(try self.barElse());
            } else if (self.nextIsExpr()) {
                try self.barListMiddle(mappings);
            } else {
                self.errors.addError(Error{ .expectedBasicToken = .{ .span = self.peek().span, .expected = "an expression after `=>`", .got = self.peek().kind } });
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

        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }

        return try AST.createCond(token, let, mappings, self.astAllocator);
    }

    fn caseExpr(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.CASE);
        var mappings = std.ArrayList(*AST).init(self.astAllocator);
        var let: ?*AST = null;

        if (self.peekKind(.CONST) or self.peekKind(.LET)) {
            let = try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        var exp = try self.productExpr();
        try self.barList(&mappings);

        return try AST.createCase(token, let, exp, mappings, self.astAllocator);
    }

    fn parens(self: *Parser) ParserErrorEnum!*AST {
        var token = try self.expect(.L_PAREN);
        var exp: ?*AST = null;
        if (self.nextIsExpr()) {
            exp = try self.expr();
        }
        _ = try self.expect(.R_PAREN);

        return exp orelse try AST.createUnit(token, self.astAllocator);
    }
};

//////////////////////
// TESTS BEGIN HERE //
//////////////////////

test "parse-const" {
    const layout = @import("layout.zig");
    const lexer = @import("lexer.zig");

    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    // contents |> lexer |> layout |> parser
    const contents = "//comment\n//comment\nconst x: Int = 4";
    var tokens = try lexer.getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();
    try layout.doLayout(&tokens);
    var astAllocator = std.heap.ArenaAllocator.init(std.testing.allocator);
    defer astAllocator.deinit();
    var parser = try Parser.create(&tokens, &errors, astAllocator.allocator());

    var program_ast = try parser.parse();
    var out_string = String.init(std.testing.allocator);
    defer out_string.deinit();
    try program_ast.items[0].serialize(&out_string);

    try std.testing.expectEqualStrings( //
        "AST.decl{token: Token{data: 'const'}, " //
    ++ "pattern: AST.identifier{token: Token{data: 'x'}}, " //
    ++ "type: AST.identifier{token: Token{data: 'Int'}}, " //
    ++ "init: AST.int{token: Token{data: '4'}, data: 4}}", out_string.str());
}

test "parse-fn" {
    const layout = @import("layout.zig");
    const lexer = @import("lexer.zig");

    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    // contents |> lexer |> layout |> parser
    const contents = "fn f: (x: Int)->Int = 4";
    var tokens = try lexer.getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();
    try layout.doLayout(&tokens);
    var astAllocator = std.heap.ArenaAllocator.init(std.testing.allocator);
    defer astAllocator.deinit();
    var parser = try Parser.create(&tokens, &errors, astAllocator.allocator());

    var program_ast = try parser.parse();
    var out_string = String.init(std.testing.allocator);
    defer out_string.deinit();
    try program_ast.items[0].serialize(&out_string);

    try std.testing.expectEqualStrings( //
        "AST.fnDecl{" //
    ++ "token: Token{data: 'fn'}, " //
    ++ "name: AST.identifier{token: Token{data: 'f'}}, " //
    ++ "params: [AST.decl{token: Token{data: 'let'}, pattern: AST.identifier{token: Token{data: 'x'}}, type: AST.identifier{token: Token{data: 'Int'}}, init: null}], " //
    ++ "retType: AST.identifier{token: Token{data: 'Int'}}, " //
    ++ "refinement: null, " //
    ++ "init: AST.int{token: Token{data: '4'}, data: 4}}", out_string.str());
}

test "parse-anon-fn" {
    const layout = @import("layout.zig");
    const lexer = @import("lexer.zig");

    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    // contents |> lexer |> layout |> parser
    const contents = "const test = fn ()-> Int = 4";
    var tokens = try lexer.getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();
    try layout.doLayout(&tokens);
    var astAllocator = std.heap.ArenaAllocator.init(std.testing.allocator);
    defer astAllocator.deinit();
    var parser = try Parser.create(&tokens, &errors, astAllocator.allocator());

    var program_ast = try parser.parse();
    var out_string = String.init(std.testing.allocator);
    defer out_string.deinit();
    try program_ast.items[0].decl.init.?.serialize(&out_string);

    try std.testing.expectEqualStrings( //
        "AST.fnDecl{" //
    ++ "token: Token{data: 'fn'}, " //
    ++ "name: null, " //
    ++ "params: [], " //
    ++ "retType: AST.identifier{token: Token{data: 'Int'}}, " //
    ++ "refinement: null, " //
    ++ "init: AST.int{token: Token{data: '4'}, data: 4}}", out_string.str());
}

test "parse-cond" {
    const layout = @import("layout.zig");
    const lexer = @import("lexer.zig");

    var errors = errs.Errors.init(std.testing.allocator);
    defer errors.deinit();
    // contents |> lexer |> layout |> parser
    const contents = "const test = cond | y | x => 4; | else => 4;";
    var tokens = try lexer.getTokens(contents, &errors, std.testing.allocator);
    defer tokens.deinit();
    try layout.doLayout(&tokens);
    var astAllocator = std.heap.ArenaAllocator.init(std.testing.allocator);
    defer astAllocator.deinit();
    var parser = try Parser.create(&tokens, &errors, astAllocator.allocator());

    var program_ast = try parser.parse();
    var out_string = String.init(std.testing.allocator);
    defer out_string.deinit();
    try program_ast.items[0].decl.init.?.serialize(&out_string);

    // zig fmt: off
    try std.testing.expectEqualStrings(
    "AST.cond{"
    ++ "token: Token{data: 'cond'}, "
    ++ "let: null, "
    ++ "mappings: ["
        ++ "AST.mapping{token: Token{data: 'y'}, lhs: AST.identifier{token: Token{data: 'y'}}, rhs: null}, "
        ++ "AST.mapping{token: Token{data: 'x'}, lhs: AST.identifier{token: Token{data: 'x'}}, rhs: AST.int{token: Token{data: '4'}, data: 4}}, "
        ++ "AST.mapping{token: Token{data: 'else'}, lhs: null, rhs: AST.int{token: Token{data: '4'}, data: 4}}" 
        ++ "]" 
    ++ "}",out_string.str());
    // zig fmt: on
}
