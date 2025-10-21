class Token:
    def __init__(self, lines: list[str], value: str, col: int, line: int):
        self.value = value
        self.col = col
        self.line = line
        self.line_text = lines[line - 1]


def remove_comments(text: str) -> str:
    ret = ""
    in_comment = False
    for i in range(0, len(text) - 2):
        if in_comment:
            if text[i] == "\n":
                in_comment = False
        elif text[i] == "/" and text[i + 1] == "/":
            in_comment = True
        else:
            ret += text[i]
    ret += text[len(text) - 2 :]
    return ret


class Scanner:
    def __init__(self, text: str):
        self.cursor = 0
        self.text = text
        self.line = 1
        self.col = 1
        self.lines = self.text.split("\n")

    def eof(self) -> bool:
        return self.cursor >= len(self.text)

    def curr(self) -> str:
        return self.text[self.cursor]

    def curr_or_empty(self) -> None | str:
        return self.curr() if not self.eof() else None

    def skip_while(self, filter):
        while not self.eof() and filter(self.curr()):
            if self.curr() == "\n":
                self.line += 1
            self.cursor += 1

    def is_escaped(self, s: str) -> bool:
        count = 0
        for c in reversed(s):
            if c == "\\":
                count += 1
            else:
                break
        return count % 2 == 1

    def tokenize(self) -> list[Token]:
        open_close: str = "(){}[]"
        tokens: list[Token] = []
        prev_char: str | None = self.text[0]
        token = Token(self.lines, prev_char, self.col, self.line)
        self.cursor += 1
        prev_token_was_dot: bool = False
        while not self.eof():
            char: str = self.curr()

            if token.value[0] in {'"', "'"}:
                token.value += char
                if char == token.value[0] and not self.is_escaped(token.value):
                    tokens.append(token)
                    self.skip_while(lambda x: x.isspace() or x == token.value[0])
                    token = Token(
                        self.lines, self.curr_or_empty() or "", self.col, self.line
                    )
            elif (
                alnumus(char) != alnumus(prev_char)
                or char.isspace()
                or (prev_char and prev_char in open_close)
                or char in open_close
                or char == '"'
                or char == "'"
            ):
                if token.value.startswith("//"):
                    self.skip_while(lambda x: self.curr() != "\n")
                elif (
                    all([alnumus(x) for x in token.value])
                    and token.value not in keywords
                    and not prev_token_was_dot
                ):
                    tokens.append(token)
                else:
                    prev_token_was_dot = "." in token.value or token.value == "fn"
                    tokens.append(token)
                self.skip_while(lambda x: x.isspace())
                token = Token(
                    self.lines, self.curr_or_empty() or "", self.col, self.line
                )
            else:
                token.value += char

            prev_char = self.curr_or_empty()
            self.cursor += 1
        return tokens


def alnumus(c):
    return c == "_" or c.isalnum() or c == "@"


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
