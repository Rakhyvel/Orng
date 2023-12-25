def main():
    with open("src/interpreter.zig") as f:
        text = f.read()
        scanner = Scanner(text)
        tokens = scanner.tokenize()
        longest_substr(tokens)


def alnumus(c):
    return c == '_' or c.isalnum()

class Scanner:
    def __init__(self, text):
        self.cursor = 0
        self.text = text

    def eof(self):
        return self.cursor >= len(self.text)

    def curr(self):
        return self.text[self.cursor]
        
    def skip_spaces(self):
        while not self.eof() and self.curr().isspace():
            self.cursor += 1

    def skip_until_newline(self):
        while not self.eof() and not self.curr() == '\n':
            self.cursor += 1

    def tokenize(self):
        open_close = '(){}[]"\''
        tokens = []
        prev_char = self.text[0]
        token = prev_char
        self.cursor += 1
        while not self.eof():
            char = self.curr()
            if alnumus(char) != alnumus(prev_char) or char.isspace() or prev_char in open_close or char in open_close:
                if token.startswith('//'):
                    self.skip_until_newline()
                else:
                    tokens.append(token)
                self.skip_spaces()
                token = self.curr() if not self.eof() else ""
            else:
                token += char
            prev_char = self.curr() if not self.eof() else ""
            self.cursor += 1
        return tokens


def longest_substr(tokens):
    lrs = []
    n = len(tokens)
    prev_p = -1
    for i in range(0, n-1):
        for j in range(i + 1, n):
            x = lcp(tokens[i:n], tokens[j:n])
            if len(x) > 25 and len(x) > len(lrs) and x != lrs:
                lrs = x
                print(x)
        p = (100 * i) // n
        if p > prev_p:
            print(f"{p}%")
            prev_p = p
    print(lrs)


def lcp(s, t):
    n = min(len(s), len(t))
    for i in range(0, n):
        if s[i] != t[i]:
            return s[0:i]
    return s[0:n]


if __name__ == "__main__":
    main()