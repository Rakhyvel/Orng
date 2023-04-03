const std = @import("std");
const lexer = @import("lexer.zig");
const _token = @import("token.zig");

const Token = _token.Token;
const TokenKind = _token.TokenKind;
const String = @import("zig-string/zig-string.zig").String;

const ParserError = struct {
    msg: String,
    line: i64,
};

pub const Parser = struct {
    tokens: std.ArrayList(Token),
    errors: std.ArrayList(ParserError),
    cursor: usize,
    allocator: std.mem.Allocator,

    pub fn create(contents: []const u8, allocator: std.mem.Allocator) !Parser {
        var tokens = try lexer.getTokens(contents, allocator);
        for (tokens.items) |*token| {
            std.debug.print("{s}\n", .{token.repr()});
        }
        return .{ .tokens = tokens, .errors = std.ArrayList(ParserError).init(allocator), .cursor = 0, .allocator = allocator };
    }

    fn peek(self: *Parser) Token {
        return self.tokens.items[self.cursor];
    }

    fn nextIsExpr(self: *Parser) bool {
        const nextKind = self.peek().kind;
        return nextKind == .E_MARK //
        or nextKind == .AMPERSAND //
        or nextKind == .L_PAREN //
        or nextKind == .MINUS //
        or nextKind == .Q_MARK //
        or nextKind == .L_SQUARE //
        or nextKind == .WHITESPACE //
        or nextKind == .CASE //
        or nextKind == .COND //
        or nextKind == .CONST //
        or nextKind == .FN //
        or nextKind == .FOR //
        or nextKind == .IF //
        or nextKind == .TRY //
        or nextKind == .UNREACHABLE //
        or nextKind == .WHILE //
        or nextKind == .IDENTIFIER //
        or nextKind == .L_BRACE //
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

    fn expect(self: *Parser, kind: TokenKind) ?Token {
        if (self.accept(kind)) |token| {
            return token;
        } else {
            const actual = self.peek();
            var error_string = String.init_with_contents(self.allocator, "expected `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(kind) orelse "") catch unreachable;
            error_string.concat("`, got `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(actual.kind) orelse "") catch unreachable;
            error_string.concat("`") catch unreachable;
            self.errors.append(.{ .msg = error_string, .line = actual.line }) catch unreachable;
            return null;
        }
    }

    pub fn parse(self: *Parser) void {
        program(self);
        _ = self.expect(.EOF);
    }

    fn program(self: *Parser) void {
        while (self.accept(.WHITESPACE)) |_| {}
        while (self.peek().kind == .CONST or self.peek().kind == .FN) {
            self.topLevelDeclaration();
            while (self.accept(.WHITESPACE)) |_| {}
        }
    }

    fn topLevelDeclaration(self: *Parser) void {
        if (self.peek().kind == .FN) {
            self.fnDeclaration();
        } else if (self.peek().kind == .CONST) {
            self.constDeclaration();
        } else {
            self.errors.append(.{ .msg = String.init_with_contents(self.allocator, "expected a top-level declaration") catch unreachable, .line = self.peek().line }) catch unreachable;
        }
    }

    fn nonFnDeclaration(self: *Parser) void {
        if (self.peek().kind == .LET) {
            self.letDeclaration();
        } else if (self.peek().kind == .CONST) {
            self.constDeclaration();
        } else {
            self.errors.append(.{ .msg = String.init_with_contents(self.allocator, "expected a variable or constant declaration") catch unreachable, .line = self.peek().line }) catch unreachable;
        }
    }

    fn constDeclaration(self: *Parser) void {
        _ = self.expect(.CONST);
        _ = self.expect(.IDENTIFIER);
        if (self.accept(.COLON)) |_| {
            self.expr();
        }
        _ = self.expect(.EQUALS);
        self.expr();
    }

    fn letDeclaration(self: *Parser) void {
        _ = self.expect(.LET);
        _ = self.accept(.MUT);
        _ = self.expect(.IDENTIFIER);
        if (self.accept(.COLON)) |_| {
            self.expr();
            if (self.peek().kind == .EQUALS) {
                _ = self.expect(.EQUALS);
                self.expr();
            }
        } else if (self.accept(.EQUALS)) |_| {
            self.expr();
        } else {
            self.errors.append(.{ .msg = String.init_with_contents(self.allocator, "variable declarations require at least a type or a initial value") catch unreachable, .line = self.peek().line }) catch unreachable;
        }
    }

    fn fnDeclaration(self: *Parser) void {
        _ = self.expect(.FN);
        if (self.accept(.IDENTIFIER)) |_| {
            _ = self.expect(.COLON);
        }
        self.paramlist();
        if (self.accept(.INVALIDATES)) |_| {
            _ = self.boolExpr();
        }
        _ = self.expect(.SKINNY_ARROW);
        self.arrowExpr();
        if (self.accept(.WHERE)) |_| {
            _ = self.boolExpr();
        }
        _ = self.expect(.EQUALS);
        self.expr();
    }

    fn paramlist(self: *Parser) void {
        _ = self.expect(.L_PAREN);
        self.param();
        if (self.accept(.COMMA)) |_| {
            self.param();
        }
        _ = self.expect(.R_PAREN);
    }

    fn param(self: *Parser) void {
        _ = self.accept(.MUT) orelse self.accept(.CONST);
        _ = self.expect(.IDENTIFIER);
        _ = self.expect(.COLON);
        self.annotExpr();
    }

    fn statement(self: *Parser) void {
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            self.nonFnDeclaration();
        } else if (self.accept(.DEFER)) |_| {
            self.expr();
        } else if (self.accept(.ERRDEFER)) |_| {
            self.expr();
        } else if (self.accept(.INVALIDATE)) |_| {
            self.expr();
        } else if (self.accept(.VALIDATE)) |_| {
            self.expr();
        } else {
            self.expr();
            if (self.accept(.EQUALS) //
            orelse self.accept(.PLUS_EQUALS) //
            orelse self.accept(.MINUS_EQUALS) //
            orelse self.accept(.STAR_EQUALS) //
            orelse self.accept(.SLASH_EQUALS) //
            orelse self.accept(.PERCENT_EQUALS) //
            orelse self.accept(.D_LSR_EQUALS) //
            orelse self.accept(.D_GTR_EQUALS)) |_| {
                self.expr();
            }
        }
    }

    fn expr(self: *Parser) void {
        if (self.peek().kind == .FN) {
            self.fnDeclaration();
        } else {
            self.commaExpr();
        }
    }

    fn commaExpr(self: *Parser) void {
        self.annotExpr();
        while (self.accept(.COMMA)) |_| {
            while (self.accept(.WHITESPACE)) |_| {}
            self.annotExpr();
        }
    }

    fn annotExpr(self: *Parser) void {
        self.arrowExpr();
        if (self.accept(.COLON)) |_| {
            self.arrowExpr();
            if (self.accept(.WHERE)) |_| {
                self.boolExpr();
            }
        }
    }

    fn arrowExpr(self: *Parser) void {
        self.gaurdExpr();
        while (self.accept(.SKINNY_ARROW)) |_| {
            self.gaurdExpr();
        }
    }

    fn gaurdExpr(self: *Parser) void {
        if (self.accept(.COND)) |_| {
            self.condExpr();
        } else if (self.accept(.CASE)) |_| {
            self.caseExpr();
        } else {
            self.errorUnionExpr();
        }
    }

    fn errorUnionExpr(self: *Parser) void {
        self.unionExpr();
        while (self.accept(.E_MARK)) |_| {
            self.unionExpr();
        }
    }

    fn unionExpr(self: *Parser) void {
        self.tupleAppendExpr();
        while (self.accept(.BAR)) |_| {
            self.tupleAppendExpr();
        }
    }

    fn tupleAppendExpr(self: *Parser) void {
        self.boolExpr();
        while (true) {
            if (self.accept(.D_PLUS)) |_| {
                self.boolExpr();
            } else if (self.accept(.D_MINUS)) |_| {
                self.boolExpr();
            } else {
                break;
            }
        }
    }

    fn boolExpr(self: *Parser) void {
        self.neqExpr();
        while (true) {
            if (self.accept(.AND)) |_| {
                self.neqExpr();
            } else if (self.accept(.OR)) |_| {
                self.neqExpr();
            } else {
                break;
            }
        }
    }

    fn neqExpr(self: *Parser) void {
        self.conditionalExpr();
        if (self.accept(.NOT_EQUALS)) |_| {
            self.conditionalExpr();
        }
    }

    fn conditionalExpr(self: *Parser) void {
        self.coalesceExpr();
        while (true) {
            if (self.accept(.D_EQUALS)) |_| {
                self.coalesceExpr();
            } else if (self.accept(.GTR)) |_| {
                self.coalesceExpr();
            } else if (self.accept(.LSR)) |_| {
                self.coalesceExpr();
            } else if (self.accept(.GTE)) |_| {
                self.coalesceExpr();
            } else if (self.accept(.LTE)) |_| {
                self.coalesceExpr();
            } else {
                break;
            }
        }
    }

    fn coalesceExpr(self: *Parser) void {
        self.shiftExpr();
        while (true) {
            if (self.accept(.CATCH)) |_| {
                self.shiftExpr();
            } else if (self.accept(.ORELSE)) |_| {
                self.shiftExpr();
            } else {
                break;
            }
        }
    }

    fn shiftExpr(self: *Parser) void {
        self.intExpr();
        while (true) {
            if (self.accept(.LEFT_SHIFT)) |_| {
                self.intExpr();
            } else if (self.accept(.RIGHT_SHIFT)) |_| {
                self.intExpr();
            } else {
                break;
            }
        }
    }

    fn intExpr(self: *Parser) void {
        self.termExpr();
        while (true) {
            if (self.accept(.PLUS)) |_| {
                self.termExpr();
            } else if (self.accept(.MINUS)) |_| {
                self.termExpr();
            } else {
                break;
            }
        }
    }

    fn termExpr(self: *Parser) void {
        self.prefixExpr();
        while (true) {
            if (self.accept(.STAR)) |_| {
                self.prefixExpr();
            } else if (self.accept(.SLASH)) |_| {
                self.prefixExpr();
            } else if (self.accept(.PERCENT)) |_| {
                self.prefixExpr();
            } else {
                break;
            }
        }
    }

    fn prefixExpr(self: *Parser) void {
        if (self.accept(.E_MARK)) |_| {
            self.prependExpr();
        } else if (self.accept(.MINUS)) |_| {
            self.prependExpr();
        } else if (self.accept(.AMPERSAND)) |_| {
            _ = self.accept(.MUT);
            self.prefixExpr();
        } else if (self.accept(.L_SQUARE)) |_| {
            if (self.accept(.MUT)) |_| {
                //
            } else if (self.accept(.STAR)) |_| {
                //
            } else {
                self.expr();
            }
            _ = self.expect(.R_SQUARE);
            self.prefixExpr();
        } else if (self.accept(.Q_MARK)) |_| {
            self.prependExpr();
        } else if (self.accept(.TRY)) |_| {
            self.prependExpr();
        } else {
            self.prependExpr();
        }
    }

    fn prependExpr(self: *Parser) void {
        self.postfixExpr();
        while (self.accept(.PERIOD_GTR)) |_| {
            self.postfixExpr();
        }
    }

    fn postfixExpr(self: *Parser) void {
        self.factor();
        while (true) {
            if (self.peek().kind == .L_PAREN) {
                self.parens();
            } else if (self.accept(.L_SQUARE)) |_| {
                if (self.nextIsExpr()) {
                    self.expr();
                }
                if (self.accept(.D_PERIOD)) |_| {
                    if (self.nextIsExpr()) {
                        self.expr();
                    }
                }
                _ = self.expect(.R_SQUARE);
            } else if (self.accept(.PERIOD)) |_| {
                _ = self.expect(.IDENTIFIER);
            } else if (self.accept(.PERIOD_Q_MARK)) |_| {
                //
            } else if (self.accept(.CARET)) |_| {
                //
            } else {
                break;
            }
        }
    }

    fn factor(self: *Parser) void {
        if (self.accept(.IDENTIFIER)) |_| {
            //
        } else if (self.accept(.DECIMAL_INTEGER)) |_| {
            //
        } else if (self.accept(.HEX_INTEGER)) |_| {
            //
        } else if (self.accept(.OCT_INTEGER)) |_| {
            //
        } else if (self.accept(.BIN_INTEGER)) |_| {
            //
        } else if (self.accept(.REAL)) |_| {
            //
        } else if (self.accept(.CHAR)) |_| {
            //
        } else if (self.accept(.STRING)) |_| {
            //
        } else if (self.peek().kind == .WHITESPACE) {
            self.indentBlockExpr();
        } else if (self.peek().kind == .L_BRACE) {
            self.braceBlockExpr();
        } else if (self.peek().kind == .IF) {
            self.ifExpr();
        } else if (self.peek().kind == .WHILE) {
            self.whileExpr();
        } else if (self.peek().kind == .FOR) {
            self.forExpr();
        } else if (self.accept(.UNREACHABLE)) |_| {
            //
        } else if (self.peek().kind == .L_PAREN) {
            self.parens();
        } else {
            var error_string = String.init_with_contents(self.allocator, "expected an expression, got `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(self.peek().kind) orelse "") catch unreachable;
            error_string.concat("`") catch unreachable;
            self.errors.append(.{ .msg = error_string, .line = self.peek().line }) catch unreachable;
        }
    }

    fn indentBlockExpr(self: *Parser) void {
        _ = self.expect(.WHITESPACE); // TODO: Calculate whitespace
        if (self.nextIsStatement()) {
            self.statement();
            while (self.accept(.WHITESPACE)) |_| {
                // peek at whitespace, break if its IDENTIFIERation lesser
                self.statement();
            }
        }

        if (self.accept(.BREAK)) |_| {
            //
        } else if (self.accept(.CONTINUE)) |_| {
            //
        } else if (self.accept(.RETURN)) |_| {
            if (self.nextIsExpr()) {
                self.expr();
            }
        }
        // expect a dedent whitespace with lesser indentation, but do not consume
    }

    fn braceBlockExpr(self: *Parser) void {
        _ = self.expect(.L_BRACE);
        if (self.nextIsStatement()) {
            self.statement();
            while (self.accept(.SEMICOLON)) |_| {
                self.statement();
            }
        }

        if (self.accept(.BREAK)) |_| {
            //
        } else if (self.accept(.CONTINUE)) |_| {
            //
        } else if (self.accept(.RETURN)) |_| {
            if (self.nextIsExpr()) {
                self.expr();
            }
        }
        _ = self.expect(.R_BRACE);
    }

    fn blockExpr(self: *Parser) void {
        if (self.peek().kind == .WHITESPACE) {
            self.indentBlockExpr();
        } else if (self.peek().kind == .L_BRACE) {
            self.braceBlockExpr();
        }
    }

    fn ifExpr(self: *Parser) void {
        _ = self.expect(.IF);
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            self.nonFnDeclaration();
            _ = self.expect(.SEMICOLON);
        }
        self.expr();
        self.blockExpr();
        if (self.accept(.ELSE)) |_| {
            self.blockExpr();
        }
    }

    fn whileExpr(self: *Parser) void {
        _ = self.expect(.WHILE);
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            self.nonFnDeclaration();
            _ = self.expect(.SEMICOLON);
        }
        self.expr();
        if (self.accept(.SEMICOLON)) |_| {
            self.statement();
        }
        self.blockExpr();
        if (self.accept(.ELSE)) |_| {
            self.blockExpr();
        }
    }

    fn forExpr(self: *Parser) void {
        _ = self.expect(.FOR);
        _ = self.accept(.MUT);
        _ = self.expect(.IDENTIFIER);
        _ = self.expect(.IN);
        self.expr();
        self.blockExpr();
        if (self.accept(.ELSE)) |_| {
            self.blockExpr();
        }
    }

    fn barClause(self: *Parser) void {
        self.boolExpr();
        if (self.accept(.FAT_ARROW)) |_| {
            self.boolExpr();
            _ = self.expect(.SEMICOLON);
        }
    }

    fn barElse(self: *Parser) void {
        _ = self.expect(.ELSE);
        _ = self.expect(.FAT_ARROW);
        self.boolExpr();
        _ = self.expect(.SEMICOLON);
    }

    fn barListMiddle(self: *Parser) void {
        self.barClause();
        if (self.accept(.BAR)) |_| {
            if (self.accept(.ELSE)) |_| {
                self.barElse();
            } else if (self.nextIsExpr()) {
                self.boolExpr();
            } else {
                self.errors.append(.{ .msg = String.init_with_contents(self.allocator, "expected an expression after `=>`") catch unreachable, .line = self.peek().line }) catch unreachable;
            }
        }
    }

    fn barList(self: *Parser) void {
        _ = self.expect(.BAR);
        self.barListMiddle();
    }

    fn condExpr(self: *Parser) void {
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            self.nonFnDeclaration();
            _ = self.expect(.SEMICOLON);
        }
        self.barList();
    }

    fn caseExpr(self: *Parser) void {
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            self.nonFnDeclaration();
            _ = self.expect(.SEMICOLON);
        }
        self.boolExpr();
        self.barList();
    }

    fn parens(self: *Parser) void {
        _ = self.expect(.L_PAREN);
        while (self.accept(.WHITESPACE)) |_| {}

        if (self.peek().kind == .PERIOD) {
            self.inferedDot();
        } else if (self.nextIsExpr()) {
            self.expr();
        }
        while (self.accept(.WHITESPACE)) |_| {}
        _ = self.expect(.R_PAREN);
    }

    fn inferedDot(self: *Parser) void {
        _ = self.expect(.PERIOD);
        _ = self.expect(.IDENTIFIER);
        _ = self.expect(.EQUALS);
        self.expr();
    }
};
