
from scanner import Scanner
class Parser:
    def __init__(self, scanner: Scanner):
        self.scanner = scanner

    def error(self, msg: str):
        raise Exception(msg + " at " + str(self.scanner.peek()))

    def parse(self):
        self._program()
        self.scanner.match("EOF")
    # program -> top_level_declaration { top_level_declaration }
    def _program(self):
        self._top_level_declaration()
        while self.scanner.peek().kind in {'const', 'fn'}:
            self._top_level_declaration()
    # top_level_declaration -> fn_declaration | const_declaration
    def _top_level_declaration(self):
        if self.scanner.peek().kind in {'fn'}:
            self._fn_declaration()
        elif self.scanner.peek().kind in {'const'}:
            self._const_declaration()
        else:
            self.error('syntax error')
    # param -> [ "mut" | "const" ] expr
    def _param(self):
        if self.scanner.peek().kind in {'const', 'mut'}:
            if self.scanner.peek().kind in {'mut'}:
                self.scanner.match('mut')
            elif self.scanner.peek().kind in {'const'}:
                self.scanner.match('const')
            else:
                self.error('syntax error')
        self._expr()
    # fn_declaration -> "fn" [ ident ":" ] "(" [ param ] ")" { "throws" [ boolExpr ] | "invalidates" boolExpr } "->" arrowExpr [ "where" arrowExpr ] "=" expr
    def _fn_declaration(self):
        self.scanner.match('fn')
        if self.scanner.peek().kind in {'ident'}:
            self.scanner.match('ident')
            self.scanner.match(':')
        self.scanner.match('(')
        if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'const', 'fn', 'for', 'if', 'mut', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
            self._param()
        self.scanner.match(')')
        while self.scanner.peek().kind in {'invalidates', 'throws'}:
            if self.scanner.peek().kind in {'throws'}:
                self.scanner.match('throws')
                if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
                    self._boolExpr()
            elif self.scanner.peek().kind in {'invalidates'}:
                self.scanner.match('invalidates')
                self._boolExpr()
            else:
                self.error('syntax error')
        self.scanner.match('->')
        self._arrowExpr()
        if self.scanner.peek().kind in {'where'}:
            self.scanner.match('where')
            self._arrowExpr()
        self.scanner.match('=')
        self._expr()
    # non_fn_declaration -> let_declaration | const_declaration
    def _non_fn_declaration(self):
        if self.scanner.peek().kind in {'let'}:
            self._let_declaration()
        elif self.scanner.peek().kind in {'const'}:
            self._const_declaration()
        else:
            self.error('syntax error')
    # let_declaration -> "let" [ "mut" ] ident ( ":" expr [ "=" expr ] | "=" expr )
    def _let_declaration(self):
        self.scanner.match('let')
        if self.scanner.peek().kind in {'mut'}:
            self.scanner.match('mut')
        self.scanner.match('ident')
        if self.scanner.peek().kind in {':'}:
            self.scanner.match(':')
            self._expr()
            if self.scanner.peek().kind in {'='}:
                self.scanner.match('=')
                self._expr()
        elif self.scanner.peek().kind in {'='}:
            self.scanner.match('=')
            self._expr()
        else:
            self.error('syntax error')
    # const_declaration -> "const" ident [ ":" expr ] "=" expr
    def _const_declaration(self):
        self.scanner.match('const')
        self.scanner.match('ident')
        if self.scanner.peek().kind in {':'}:
            self.scanner.match(':')
            self._expr()
        self.scanner.match('=')
        self._expr()
    # statement -> non_fn_declaration | "defer" expr | "errdefer" expr | "invalidate" expr | "validate" expr | expr [ ( "=" | "+=" | "-=" | "*=" | "/=" | "%=" | "<<=" | ">>=" ) expr ]
    def _statement(self):
        if self.scanner.peek().kind in {'const', 'let'}:
            self._non_fn_declaration()
        elif self.scanner.peek().kind in {'defer'}:
            self.scanner.match('defer')
            self._expr()
        elif self.scanner.peek().kind in {'errdefer'}:
            self.scanner.match('errdefer')
            self._expr()
        elif self.scanner.peek().kind in {'invalidate'}:
            self.scanner.match('invalidate')
            self._expr()
        elif self.scanner.peek().kind in {'validate'}:
            self.scanner.match('validate')
            self._expr()
        elif self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'fn', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
            self._expr()
            if self.scanner.peek().kind in {'%=', '*=', '+=', '-=', '/=', '<<=', '=', '>>='}:
                if self.scanner.peek().kind in {'='}:
                    self.scanner.match('=')
                elif self.scanner.peek().kind in {'+='}:
                    self.scanner.match('+=')
                elif self.scanner.peek().kind in {'-='}:
                    self.scanner.match('-=')
                elif self.scanner.peek().kind in {'*='}:
                    self.scanner.match('*=')
                elif self.scanner.peek().kind in {'/='}:
                    self.scanner.match('/=')
                elif self.scanner.peek().kind in {'%='}:
                    self.scanner.match('%=')
                elif self.scanner.peek().kind in {'<<='}:
                    self.scanner.match('<<=')
                elif self.scanner.peek().kind in {'>>='}:
                    self.scanner.match('>>=')
                else:
                    self.error('syntax error')
                self._expr()
        else:
            self.error('syntax error')
    # expr -> commaExpr [ ":" commaExpr [ "where" commaExpr ] ] | fn_declaration
    def _expr(self):
        if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
            self._commaExpr()
            if self.scanner.peek().kind in {':'}:
                self.scanner.match(':')
                self._commaExpr()
                if self.scanner.peek().kind in {'where'}:
                    self.scanner.match('where')
                    self._commaExpr()
        elif self.scanner.peek().kind in {'fn'}:
            self._fn_declaration()
        else:
            self.error('syntax error')
    # commaExpr -> arrowExpr { "," arrowExpr }
    def _commaExpr(self):
        self._arrowExpr()
        while self.scanner.peek().kind in {','}:
            self.scanner.match(',')
            self._arrowExpr()
    # arrowExpr -> boolExpr { [ "throws" [ boolExpr ] | "invalidates" boolExpr ] "->" boolExpr }
    def _arrowExpr(self):
        self._boolExpr()
        while self.scanner.peek().kind in {'invalidates', 'throws'}:
            if self.scanner.peek().kind in {'invalidates', 'throws'}:
                if self.scanner.peek().kind in {'throws'}:
                    self.scanner.match('throws')
                    if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
                        self._boolExpr()
                elif self.scanner.peek().kind in {'invalidates'}:
                    self.scanner.match('invalidates')
                    self._boolExpr()
                else:
                    self.error('syntax error')
            self.scanner.match('->')
            self._boolExpr()
    # gaurdExpr -> "cond" condExpr | "case" caseExpr | unionExpr
    def _gaurdExpr(self):
        if self.scanner.peek().kind in {'cond'}:
            self.scanner.match('cond')
            self._condExpr()
        elif self.scanner.peek().kind in {'case'}:
            self.scanner.match('case')
            self._caseExpr()
        elif self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
            self._unionExpr()
        else:
            self.error('syntax error')
    # unionExpr -> tupleAppendExpr { "|" tupleAppendExpr }
    def _unionExpr(self):
        self._tupleAppendExpr()
        while self.scanner.peek().kind in {'|'}:
            self.scanner.match('|')
            self._tupleAppendExpr()
    # tupleAppendExpr -> boolExpr { ( "++" | "--" ) boolExpr }
    def _tupleAppendExpr(self):
        self._boolExpr()
        while self.scanner.peek().kind in {'++', '--'}:
            if self.scanner.peek().kind in {'++'}:
                self.scanner.match('++')
            elif self.scanner.peek().kind in {'--'}:
                self.scanner.match('--')
            else:
                self.error('syntax error')
            self._boolExpr()
    # boolExpr -> neqExpr { ( "and" | "or" ) neqExpr }
    def _boolExpr(self):
        self._neqExpr()
        while self.scanner.peek().kind in {'and', 'or'}:
            if self.scanner.peek().kind in {'and'}:
                self.scanner.match('and')
            elif self.scanner.peek().kind in {'or'}:
                self.scanner.match('or')
            else:
                self.error('syntax error')
            self._neqExpr()
    # neqExpr -> conditionalExpr [ "!=" conditionalExpr ]
    def _neqExpr(self):
        self._conditionalExpr()
        if self.scanner.peek().kind in {'!='}:
            self.scanner.match('!=')
            self._conditionalExpr()
    # conditionalExpr -> shiftExpr { ( "==" | "<" | "<=" | ">" | ">=" ) shiftExpr }
    def _conditionalExpr(self):
        self._shiftExpr()
        while self.scanner.peek().kind in {'<', '<=', '==', '>', '>='}:
            if self.scanner.peek().kind in {'=='}:
                self.scanner.match('==')
            elif self.scanner.peek().kind in {'<'}:
                self.scanner.match('<')
            elif self.scanner.peek().kind in {'<='}:
                self.scanner.match('<=')
            elif self.scanner.peek().kind in {'>'}:
                self.scanner.match('>')
            elif self.scanner.peek().kind in {'>='}:
                self.scanner.match('>=')
            else:
                self.error('syntax error')
            self._shiftExpr()
    # coalesceExpr -> shiftExpr { "orelse" | "catch" }
    def _coalesceExpr(self):
        self._shiftExpr()
        while self.scanner.peek().kind in {'catch', 'orelse'}:
            if self.scanner.peek().kind in {'orelse'}:
                self.scanner.match('orelse')
            elif self.scanner.peek().kind in {'catch'}:
                self.scanner.match('catch')
            else:
                self.error('syntax error')
    # shiftExpr -> intExpr { ( "<<" | ">>" ) intExpr }
    def _shiftExpr(self):
        self._intExpr()
        while self.scanner.peek().kind in {'<<', '>>'}:
            if self.scanner.peek().kind in {'<<'}:
                self.scanner.match('<<')
            elif self.scanner.peek().kind in {'>>'}:
                self.scanner.match('>>')
            else:
                self.error('syntax error')
            self._intExpr()
    # intExpr -> termExpr { ( "+" | "-" ) termExpr }
    def _intExpr(self):
        self._termExpr()
        while self.scanner.peek().kind in {'+', '-'}:
            if self.scanner.peek().kind in {'+'}:
                self.scanner.match('+')
            elif self.scanner.peek().kind in {'-'}:
                self.scanner.match('-')
            else:
                self.error('syntax error')
            self._termExpr()
    # termExpr -> prefixExpr { ( "*" | "/" | "%" | "<>" ) prefixExpr }
    def _termExpr(self):
        self._prefixExpr()
        while self.scanner.peek().kind in {'%', '*', '/', '<>'}:
            if self.scanner.peek().kind in {'*'}:
                self.scanner.match('*')
            elif self.scanner.peek().kind in {'/'}:
                self.scanner.match('/')
            elif self.scanner.peek().kind in {'%'}:
                self.scanner.match('%')
            elif self.scanner.peek().kind in {'<>'}:
                self.scanner.match('<>')
            else:
                self.error('syntax error')
            self._prefixExpr()
    # prefixExpr -> "!" prependExpr | "-" prependExpr | "&" [ "mut" ] prefixExpr | "[" [ "mut" | expr | "*" ] "]" prefixExpr | "?" prependExpr | "try" prependExpr | prependExpr
    def _prefixExpr(self):
        if self.scanner.peek().kind in {'!'}:
            self.scanner.match('!')
            self._prependExpr()
        elif self.scanner.peek().kind in {'-'}:
            self.scanner.match('-')
            self._prependExpr()
        elif self.scanner.peek().kind in {'&'}:
            self.scanner.match('&')
            if self.scanner.peek().kind in {'mut'}:
                self.scanner.match('mut')
            self._prefixExpr()
        elif self.scanner.peek().kind in {'['}:
            self.scanner.match('[')
            if self.scanner.peek().kind in {'!', '&', '(', '*', '-', '?', '[', 'fn', 'for', 'if', 'mut', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
                if self.scanner.peek().kind in {'mut'}:
                    self.scanner.match('mut')
                elif self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'fn', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
                    self._expr()
                elif self.scanner.peek().kind in {'*'}:
                    self.scanner.match('*')
                else:
                    self.error('syntax error')
            self.scanner.match(']')
            self._prefixExpr()
        elif self.scanner.peek().kind in {'?'}:
            self.scanner.match('?')
            self._prependExpr()
        elif self.scanner.peek().kind in {'try'}:
            self.scanner.match('try')
            self._prependExpr()
        elif self.scanner.peek().kind in {'(', 'for', 'if', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
            self._prependExpr()
        else:
            self.error('syntax error')
    # prependExpr -> postfixExpr { ".>" postfixExpr }
    def _prependExpr(self):
        self._postfixExpr()
        while self.scanner.peek().kind in {'.>'}:
            self.scanner.match('.>')
            self._postfixExpr()
    # postfixExpr -> factor { parens | "[" [ expr ] [ ".." [ expr ] ] "]" | "." ident | ".?" | "^" }
    def _postfixExpr(self):
        self._factor()
        while self.scanner.peek().kind in {'(', '.', '.?', '[', '^'}:
            if self.scanner.peek().kind in {'('}:
                self._parens()
            elif self.scanner.peek().kind in {'['}:
                self.scanner.match('[')
                if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'fn', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
                    self._expr()
                if self.scanner.peek().kind in {'..'}:
                    self.scanner.match('..')
                    if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'fn', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
                        self._expr()
                self.scanner.match(']')
            elif self.scanner.peek().kind in {'.'}:
                self.scanner.match('.')
                self.scanner.match('ident')
            elif self.scanner.peek().kind in {'.?'}:
                self.scanner.match('.?')
            elif self.scanner.peek().kind in {'^'}:
                self.scanner.match('^')
            else:
                self.error('syntax error')
    # factor -> ident | int | hex | octal | bin | real | char | string | "{" blockExpr | "if" ifExpr | "while" whileExpr | "for" forExpr | "unreachable" | parens
    def _factor(self):
        if self.scanner.peek().kind in {'ident'}:
            self.scanner.match('ident')
        elif self.scanner.peek().kind in {'int'}:
            self.scanner.match('int')
        elif self.scanner.peek().kind in {'hex'}:
            self.scanner.match('hex')
        elif self.scanner.peek().kind in {'octal'}:
            self.scanner.match('octal')
        elif self.scanner.peek().kind in {'bin'}:
            self.scanner.match('bin')
        elif self.scanner.peek().kind in {'real'}:
            self.scanner.match('real')
        elif self.scanner.peek().kind in {'char'}:
            self.scanner.match('char')
        elif self.scanner.peek().kind in {'string'}:
            self.scanner.match('string')
        elif self.scanner.peek().kind in {'{'}:
            self.scanner.match('{')
            self._blockExpr()
        elif self.scanner.peek().kind in {'if'}:
            self.scanner.match('if')
            self._ifExpr()
        elif self.scanner.peek().kind in {'while'}:
            self.scanner.match('while')
            self._whileExpr()
        elif self.scanner.peek().kind in {'for'}:
            self.scanner.match('for')
            self._forExpr()
        elif self.scanner.peek().kind in {'unreachable'}:
            self.scanner.match('unreachable')
        elif self.scanner.peek().kind in {'('}:
            self._parens()
        else:
            self.error('syntax error')
    # blockExpr -> [ statement { ";" statement } ] [ "throw" expr | "return" [ expr ] | "continue" | "break" ] "}"
    def _blockExpr(self):
        if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'const', 'defer', 'errdefer', 'fn', 'for', 'if', 'invalidate', 'let', 'try', 'unreachable', 'validate', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
            self._statement()
            while self.scanner.peek().kind in {';'}:
                self.scanner.match(';')
                self._statement()
        if self.scanner.peek().kind in {'break', 'continue', 'return', 'throw'}:
            if self.scanner.peek().kind in {'throw'}:
                self.scanner.match('throw')
                self._expr()
            elif self.scanner.peek().kind in {'return'}:
                self.scanner.match('return')
                if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'fn', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
                    self._expr()
            elif self.scanner.peek().kind in {'continue'}:
                self.scanner.match('continue')
            elif self.scanner.peek().kind in {'break'}:
                self.scanner.match('break')
            else:
                self.error('syntax error')
        self.scanner.match('}')
    # ifExpr -> [ non_fn_declaration ";" ] expr "{" blockExpr [ "else" "{" blockExpr ]
    def _ifExpr(self):
        if self.scanner.peek().kind in {'const', 'let'}:
            self._non_fn_declaration()
            self.scanner.match(';')
        self._expr()
        self.scanner.match('{')
        self._blockExpr()
        if self.scanner.peek().kind in {'else'}:
            self.scanner.match('else')
            self.scanner.match('{')
            self._blockExpr()
    # whileExpr -> [ non_fn_declaration ";" ] expr [ ";" statement ] "{" blockExpr [ "else" "{" blockExpr ]
    def _whileExpr(self):
        if self.scanner.peek().kind in {'const', 'let'}:
            self._non_fn_declaration()
            self.scanner.match(';')
        self._expr()
        if self.scanner.peek().kind in {';'}:
            self.scanner.match(';')
            self._statement()
        self.scanner.match('{')
        self._blockExpr()
        if self.scanner.peek().kind in {'else'}:
            self.scanner.match('else')
            self.scanner.match('{')
            self._blockExpr()
    # forExpr -> [ "mut" ] ident "in" expr "{" blockExpr [ "else" "{" blockExpr ]
    def _forExpr(self):
        if self.scanner.peek().kind in {'mut'}:
            self.scanner.match('mut')
        self.scanner.match('ident')
        self.scanner.match('in')
        self._expr()
        self.scanner.match('{')
        self._blockExpr()
        if self.scanner.peek().kind in {'else'}:
            self.scanner.match('else')
            self.scanner.match('{')
            self._blockExpr()
    # barClause -> boolExpr [ "=>" boolExpr ";" ]
    def _barClause(self):
        self._boolExpr()
        if self.scanner.peek().kind in {'=>'}:
            self.scanner.match('=>')
            self._boolExpr()
            self.scanner.match(';')
    # barElse -> "else" "=>" boolExpr ";"
    def _barElse(self):
        self.scanner.match('else')
        self.scanner.match('=>')
        self._boolExpr()
        self.scanner.match(';')
    # barList -> "|" barClause [ "|" ( barElse | barList ) ]
    def _barList(self):
        self.scanner.match('|')
        self._barClause()
        if self.scanner.peek().kind in {'|'}:
            self.scanner.match('|')
            if self.scanner.peek().kind in {'else'}:
                self._barElse()
            elif self.scanner.peek().kind in {'|'}:
                self._barList()
            else:
                self.error('syntax error')
    # condExpr -> [ non_fn_declaration ";" ] barList
    def _condExpr(self):
        if self.scanner.peek().kind in {'const', 'let'}:
            self._non_fn_declaration()
            self.scanner.match(';')
        self._barList()
    # caseExpr -> [ non_fn_declaration ";" ] boolExpr barList
    def _caseExpr(self):
        if self.scanner.peek().kind in {'const', 'let'}:
            self._non_fn_declaration()
            self.scanner.match(';')
        self._boolExpr()
        self._barList()
    # parens -> "(" ( expr | named_arg ) ")"
    def _parens(self):
        self.scanner.match('(')
        if self.scanner.peek().kind in {'!', '&', '(', '-', '?', '[', 'fn', 'for', 'if', 'try', 'unreachable', 'while', '{', 'bin', 'char', 'hex', 'ident', 'int', 'octal', 'real', 'string'}:
            self._expr()
        elif self.scanner.peek().kind in {'.'}:
            self._named_arg()
        else:
            self.error('syntax error')
        self.scanner.match(')')
    # named_arg -> "." ident "=" expr
    def _named_arg(self):
        self.scanner.match('.')
        self.scanner.match('ident')
        self.scanner.match('=')
        self._expr()
