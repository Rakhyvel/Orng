class Scanner:
    def __init__(self, text):
        self.cursor = 0
        self.text = text

    def eof(self):
        return self.cursor >= len(self.text)

    def curr(self):
        return self.text[self.cursor]
    
    def curr_or_empty(self):
        return self.curr() if not self.eof() else ""

    def skip_while(self, filter):
        while not self.eof() and filter(self.curr()):
            self.cursor += 1

    def tokenize(self):
        open_close = "(){}[]"
        tokens = []
        prev_char = self.text[0]
        token = prev_char
        self.cursor += 1
        prev_token_was_dot = False
        while not self.eof():
            char = self.curr()
            
            if token[0] in {'"', "'"}:
                token += char
                if char == token[0]:
                    tokens.append(token)
                    self.skip_while(lambda x: x.isspace() or x == token[0])
                    token = self.curr_or_empty()
            elif (
                alnumus(char) != alnumus(prev_char)
                or char.isspace()
                or prev_char in open_close
                or char in open_close
                or char == '"'
            ):
                if token.startswith("//") :
                    self.skip_while(lambda x: self.curr() != "\n")
                elif all([alnumus(x) for x in token]) and token not in keywords and not prev_token_was_dot:
                    tokens.append(token)
                else:
                    prev_token_was_dot = '.' in token or token == 'fn'
                    tokens.append(token)
                self.skip_while(lambda x: x.isspace())
                token = self.curr_or_empty()
            else:
                token += char
            
            prev_char = self.curr_or_empty()
            self.cursor += 1
        # print(tokens)
        return tokens


def alnumus(c):
    return c == "_" or c.isalnum() or c == '@'


keywords = [ 
    "fn",
    "if",
    "while",
    "for",
    "switch",
    "else",
    "break",
    "continue",
    "and",
    "or",
    "unreachable",
    "return",
    "pub",
    "const",
    "struct",
    "union",
    "true",
    "false",
    "try",
    "null",
    "catch",
    "orelse",
    "inline",
    "usingnamespace",
    "defer",
    "var",
    "comptime",
    "extern",
    "enum",
    "undefined",
]