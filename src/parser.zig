const std = @import("std");
const lexer = @import("lexer.zig");
const _token = @import("token.zig");
const main = @import("main.zig");

const Token = _token.Token;
const TokenKind = _token.TokenKind;
const String = @import("zig-string/zig-string.zig").String;

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
    allocator: std.mem.Allocator,

    pub fn create(contents: []const u8, allocator: std.mem.Allocator) !Parser {
        var tokens = try lexer.getTokens(contents, allocator);
        if (main.PRINT_TOKENS) {
            for (tokens.items) |*token| {
                token.pprint();
            }
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
        or nextKind == .BAR //
        or nextKind == .MINUS //
        or nextKind == .Q_MARK //
        or nextKind == .L_SQUARE //
        or nextKind == .CASE //
        or nextKind == .COND //
        or nextKind == .CONST //
        or nextKind == .PERIOD //
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

    fn expect(self: *Parser, kind: TokenKind) ParserErrorEnum!Token {
        if (self.accept(kind)) |token| {
            return token;
        } else {
            const actual = self.peek();
            var error_string = String.init_with_contents(self.allocator, "expected `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(kind) orelse "") catch unreachable;
            error_string.concat("`, got `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(actual.kind) orelse "") catch unreachable;
            error_string.concat("`") catch unreachable;
            self.errors.append(.{ .msg = error_string, .line = actual.line, .col = actual.col }) catch unreachable;
            return ParserErrorEnum.parserError;
        }
    }

    pub fn parse(self: *Parser) ParserErrorEnum!void {
        try program(self);
        _ = try self.expect(.EOF);
    }

    fn program(self: *Parser) ParserErrorEnum!void {
        while (self.accept(.WHITESPACE)) |_| {}
        while (self.peek().kind == .CONST or self.peek().kind == .FN) {
            try self.topLevelDeclaration();
            while (self.accept(.WHITESPACE)) |_| {}
        }
    }

    fn topLevelDeclaration(self: *Parser) ParserErrorEnum!void {
        if (self.peek().kind == .FN) {
            try self.fnDeclaration();
        } else if (self.peek().kind == .CONST) {
            try self.constDeclaration();
        } else {
            self.errors.append(.{ .msg = String.init_with_contents(self.allocator, "expected a top-level declaration") catch unreachable, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
        }
    }

    fn nonFnDeclaration(self: *Parser) ParserErrorEnum!void {
        if (self.peek().kind == .LET) {
            try self.letDeclaration();
        } else if (self.peek().kind == .CONST) {
            try self.constDeclaration();
        } else {
            self.errors.append(.{ .msg = String.init_with_contents(self.allocator, "expected a variable or constant declaration") catch unreachable, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
        }
    }

    fn constDeclaration(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.CONST);
        _ = try self.expect(.IDENTIFIER);
        if (self.accept(.COLON)) |_| {
            try self.expr();
        }
        _ = try self.expect(.EQUALS);
        try self.expr();
    }

    fn letDeclaration(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.LET);
        _ = self.accept(.MUT);
        _ = try self.expect(.IDENTIFIER);
        if (self.accept(.COLON)) |_| {
            try self.expr();
            if (self.peek().kind == .EQUALS) {
                _ = try self.expect(.EQUALS);
                try self.expr();
            }
        } else if (self.accept(.EQUALS)) |_| {
            try self.expr();
        } else {
            self.errors.append(.{ .msg = String.init_with_contents(self.allocator, "variable declarations require at least a type or a initial value") catch unreachable, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
        }
    }

    fn fnDeclaration(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.FN);
        if (self.accept(.IDENTIFIER)) |_| {
            _ = try self.expect(.COLON);
        }
        try self.paramlist();
        if (self.accept(.INVALIDATES)) |_| {
            try self.boolExpr();
        }
        _ = try self.expect(.SKINNY_ARROW);
        try self.arrowExpr();
        if (self.accept(.WHERE)) |_| {
            try self.boolExpr();
        }
        _ = try self.expect(.EQUALS);
        std.debug.print("after `=` : {s}\n", .{self.peek().data});
        try self.expr();
    }

    fn paramlist(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.L_PAREN);
        if (self.peek().kind == .CONST or self.peek().kind == .MUT or self.peek().kind == .IDENTIFIER) {
            try self.param();
            if (self.accept(.COMMA)) |_| {
                try self.param();
            }
        }
        _ = try self.expect(.R_PAREN);
    }

    fn param(self: *Parser) ParserErrorEnum!void {
        _ = self.accept(.MUT) orelse self.accept(.CONST);
        _ = try self.expect(.IDENTIFIER);
        _ = try self.expect(.COLON);
        try self.annotExpr();
    }

    fn statement(self: *Parser) ParserErrorEnum!void {
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            try self.nonFnDeclaration();
        } else if (self.accept(.DEFER)) |_| {
            try self.expr();
        } else if (self.accept(.ERRDEFER)) |_| {
            try self.expr();
        } else if (self.accept(.INVALIDATE)) |_| {
            try self.expr();
        } else if (self.accept(.VALIDATE)) |_| {
            try self.expr();
        } else {
            try self.expr();
            if (self.accept(.EQUALS) //
            orelse self.accept(.PLUS_EQUALS) //
            orelse self.accept(.MINUS_EQUALS) //
            orelse self.accept(.STAR_EQUALS) //
            orelse self.accept(.SLASH_EQUALS) //
            orelse self.accept(.PERCENT_EQUALS) //
            orelse self.accept(.D_LSR_EQUALS) //
            orelse self.accept(.D_GTR_EQUALS)) |_| {
                try self.expr();
            }
        }
    }

    fn expr(self: *Parser) ParserErrorEnum!void {
        if (self.peek().kind == .FN) {
            try self.fnDeclaration();
        } else {
            try self.sumType();
        }
    }

    fn sumType(self: *Parser) ParserErrorEnum!void {
        if (self.accept(.COND)) |_| {
            try self.condExpr();
        } else if (self.accept(.CASE)) |_| {
            try self.caseExpr();
        } else if (self.accept(.BAR)) |_| {
            try self.adtType();
            while (self.accept(.WHITESPACE)) |_| {}
            while (self.accept(.BAR)) |_| {
                try self.adtType();
                while (self.accept(.WHITESPACE)) |_| {}
            }
        } else {
            try self.productExpr();
        }
    }

    fn adtType(self: *Parser) ParserErrorEnum!void {
        _ = self.accept(.IDENTIFIER);
        if (self.accept(.COLON)) |_| {
            try self.productExpr();
        }
    }

    fn productExpr(self: *Parser) ParserErrorEnum!void {
        try self.annotExpr();
        while (self.accept(.COMMA)) |_| {
            while (self.accept(.WHITESPACE)) |_| {}
            try self.annotExpr();
        }
    }

    fn annotExpr(self: *Parser) ParserErrorEnum!void {
        try self.arrowExpr();
        if (self.accept(.COLON)) |_| {
            try self.arrowExpr();
            if (self.accept(.WHERE)) |_| {
                try self.boolExpr();
            }
        }
    }

    fn arrowExpr(self: *Parser) ParserErrorEnum!void {
        try self.boolExpr();
        while (self.accept(.SKINNY_ARROW)) |_| {
            try self.boolExpr();
        }
    }

    fn boolExpr(self: *Parser) ParserErrorEnum!void {
        try self.neqExpr();
        while (true) {
            if (self.accept(.AND)) |_| {
                try self.neqExpr();
            } else if (self.accept(.OR)) |_| {
                try self.neqExpr();
            } else {
                break;
            }
        }
    }

    fn neqExpr(self: *Parser) ParserErrorEnum!void {
        try self.conditionalExpr();
        if (self.accept(.NOT_EQUALS)) |_| {
            try self.conditionalExpr();
        }
    }

    fn conditionalExpr(self: *Parser) ParserErrorEnum!void {
        try self.coalesceExpr();
        while (true) {
            if (self.accept(.D_EQUALS)) |_| {
                try self.coalesceExpr();
            } else if (self.accept(.GTR)) |_| {
                try self.coalesceExpr();
            } else if (self.accept(.LSR)) |_| {
                try self.coalesceExpr();
            } else if (self.accept(.GTE)) |_| {
                try self.coalesceExpr();
            } else if (self.accept(.LTE)) |_| {
                try self.coalesceExpr();
            } else {
                break;
            }
        }
    }

    fn coalesceExpr(self: *Parser) ParserErrorEnum!void {
        try self.intExpr();
        while (true) {
            if (self.accept(.CATCH)) |_| {
                try self.intExpr();
            } else if (self.accept(.ORELSE)) |_| {
                try self.intExpr();
            } else {
                break;
            }
        }
    }

    fn intExpr(self: *Parser) ParserErrorEnum!void {
        try self.termExpr();
        while (true) {
            if (self.accept(.PLUS)) |_| {
                try self.termExpr();
            } else if (self.accept(.MINUS)) |_| {
                try self.termExpr();
            } else if (self.accept(.D_E_MARK)) |_| {
                try self.termExpr();
            } else {
                break;
            }
        }
    }

    fn termExpr(self: *Parser) ParserErrorEnum!void {
        try self.prefixExpr();
        while (true) {
            if (self.accept(.STAR)) |_| {
                try self.prefixExpr();
            } else if (self.accept(.SLASH)) |_| {
                try self.prefixExpr();
            } else if (self.accept(.PERCENT)) |_| {
                try self.prefixExpr();
            } else if (self.accept(.DIAMOND)) |_| {
                try self.prefixExpr();
            } else if (self.accept(.D_PLUS)) |_| {
                try self.prefixExpr();
            } else if (self.accept(.D_MINUS)) |_| {
                try self.prefixExpr();
            } else if (self.accept(.D_BAR)) |_| {
                try self.prefixExpr();
            } else {
                break;
            }
        }
    }

    fn prefixExpr(self: *Parser) ParserErrorEnum!void {
        if (self.accept(.E_MARK)) |_| {
            try self.prependExpr();
        } else if (self.accept(.MINUS)) |_| {
            try self.prependExpr();
        } else if (self.accept(.AMPERSAND)) |_| {
            _ = self.accept(.MUT);
            try self.prefixExpr();
        } else if (self.accept(.L_SQUARE)) |_| {
            if (self.accept(.MUT)) |_| {
                //
            } else if (self.accept(.STAR)) |_| {
                //
            } else {
                try self.expr();
            }
            _ = try self.expect(.R_SQUARE);
            try self.prefixExpr();
        } else if (self.accept(.Q_MARK)) |_| {
            try self.prependExpr();
        } else if (self.accept(.TRY)) |_| {
            try self.prependExpr();
        } else if (self.accept(.PERIOD)) |_| {
            _ = try self.expect(.IDENTIFIER);
            if (self.accept(.BACK_SKINNY_ARROW)) |_| {
                try self.prefixExpr();
            }
        } else {
            try self.prependExpr();
        }
    }

    fn prependExpr(self: *Parser) ParserErrorEnum!void {
        try self.postfixExpr();
        while (self.accept(.PERIOD_GTR)) |_| {
            try self.postfixExpr();
        }
    }

    fn postfixExpr(self: *Parser) ParserErrorEnum!void {
        try self.factor();
        while (true) {
            if (self.peek().kind == .L_PAREN) {
                try self.parens();
            } else if (self.accept(.L_SQUARE)) |_| {
                if (self.nextIsExpr()) {
                    try self.expr();
                }
                if (self.accept(.D_PERIOD)) |_| {
                    if (self.nextIsExpr()) {
                        try self.expr();
                    }
                }
                _ = try self.expect(.R_SQUARE);
            } else if (self.accept(.PERIOD)) |_| {
                _ = try self.expect(.IDENTIFIER);
            } else if (self.accept(.PERIOD_Q_MARK)) |_| {
                //
            } else if (self.accept(.CARET)) |_| {
                //
            } else {
                break;
            }
        }
    }

    fn factor(self: *Parser) ParserErrorEnum!void {
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
            try self.indentBlockExpr();
        } else if (self.peek().kind == .L_BRACE) {
            try self.braceBlockExpr();
        } else if (self.peek().kind == .IF) {
            try self.ifExpr();
        } else if (self.peek().kind == .WHILE) {
            try self.whileExpr();
        } else if (self.peek().kind == .FOR) {
            try self.forExpr();
        } else if (self.accept(.UNREACHABLE)) |_| {
            //
        } else if (self.peek().kind == .L_PAREN) {
            try self.parens();
        } else {
            var error_string = String.init_with_contents(self.allocator, "expected an expression, got `") catch unreachable;
            error_string.concat(_token.reprFromTokenKind(self.peek().kind) orelse "") catch unreachable;
            error_string.concat("`") catch unreachable;
            self.errors.append(.{ .msg = error_string, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
        }
    }

    fn indentBlockExpr(self: *Parser) ParserErrorEnum!void {
        var start_token_len = (try self.expect(.WHITESPACE)).data.len;
        std.debug.print("{s} {}\n", .{ "entered block, sir", start_token_len });

        while (self.nextIsStatement()) {
            try self.statement();
            if (self.peek().kind == .WHITESPACE and self.peek().data.len < start_token_len) {
                // peek at whitespace, break if its indentation lesser
                return;
            }
        }

        if (self.accept(.BREAK)) |_| {
            //
        } else if (self.accept(.CONTINUE)) |_| {
            //
        } else if (self.accept(.RETURN)) |_| {
            if (self.nextIsExpr()) {
                try self.expr();
            }
        }

        // expect a dedent whitespace with lesser indentation, consume if its equal?
        if (self.peek().kind != .EOF) {
            var end_token = self.peek();
            if (end_token.kind != .WHITESPACE) {
                // This is actually an error about unreachable code, right?
                const actual = self.peek();
                var error_string = String.init_with_contents(self.allocator, "expected lesser indentation, got `") catch unreachable;
                error_string.concat(_token.reprFromTokenKind(actual.kind) orelse "") catch unreachable;
                error_string.concat("`") catch unreachable;
                self.errors.append(.{ .msg = error_string, .line = actual.line, .col = actual.col }) catch unreachable;
                return ParserErrorEnum.parserError;
            }
            if (end_token.data.len < start_token_len) {
                std.debug.print("{s} {}\n", .{ "exited block, sir", end_token.data.len });
                _ = self.accept(.WHITESPACE);
            }
        }
    }

    fn braceBlockExpr(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.L_BRACE);
        if (self.nextIsStatement()) {
            try self.statement();
            while (self.accept(.SEMICOLON)) |_| {
                try self.statement();
            }
        }

        if (self.accept(.BREAK)) |_| {
            //
        } else if (self.accept(.CONTINUE)) |_| {
            //
        } else if (self.accept(.RETURN)) |_| {
            if (self.nextIsExpr()) {
                try self.expr();
            }
        }
        _ = try self.expect(.R_BRACE);
    }

    fn blockExpr(self: *Parser) ParserErrorEnum!void {
        if (self.peek().kind == .WHITESPACE) {
            try self.indentBlockExpr();
        } else if (self.peek().kind == .L_BRACE) {
            try self.braceBlockExpr();
        }
    }

    fn ifExpr(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.IF);
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        try self.expr();
        try self.blockExpr();
        if (self.accept(.ELSE)) |_| {
            try self.blockExpr();
        }
    }

    fn whileExpr(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.WHILE);
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        try self.expr();
        if (self.accept(.SEMICOLON)) |_| {
            try self.statement();
        }
        try self.blockExpr();
        if (self.accept(.ELSE)) |_| {
            try self.blockExpr();
        }
    }

    fn forExpr(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.FOR);
        _ = self.accept(.MUT);
        _ = try self.expect(.IDENTIFIER);
        _ = try self.expect(.IN);
        try self.expr();
        try self.blockExpr();
        if (self.accept(.ELSE)) |_| {
            try self.blockExpr();
        }
    }

    fn barClause(self: *Parser) ParserErrorEnum!void {
        try self.productExpr();
        if (self.accept(.FAT_ARROW)) |_| {
            try self.expr();
            _ = try self.expect(.SEMICOLON);
        }
    }

    fn barElse(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.ELSE);
        _ = try self.expect(.FAT_ARROW);
        try self.expr();
        _ = try self.expect(.SEMICOLON);
    }

    fn barListMiddle(self: *Parser) ParserErrorEnum!void {
        try self.barClause();
        if (self.accept(.BAR)) |_| {
            if (self.accept(.ELSE)) |_| {
                try self.barElse();
            } else if (self.nextIsExpr()) {
                try self.productExpr();
            } else {
                self.errors.append(.{ .msg = String.init_with_contents(self.allocator, "expected an expression after `=>`") catch unreachable, .line = self.peek().line, .col = self.peek().col }) catch unreachable;
            }
        }
    }

    fn barList(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.BAR);
        try self.barListMiddle();
    }

    fn condExpr(self: *Parser) ParserErrorEnum!void {
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        try self.barList();
    }

    fn caseExpr(self: *Parser) ParserErrorEnum!void {
        if (self.peek().kind == .CONST or self.peek().kind == .LET) {
            try self.nonFnDeclaration();
            _ = try self.expect(.SEMICOLON);
        }
        try self.productExpr();
        try self.barList();
    }

    fn parens(self: *Parser) ParserErrorEnum!void {
        _ = try self.expect(.L_PAREN);
        while (self.accept(.WHITESPACE)) |_| {}
        if (self.nextIsExpr()) {
            try self.expr();
        }
        while (self.accept(.WHITESPACE)) |_| {}
        _ = try self.expect(.R_PAREN);
    }
};
