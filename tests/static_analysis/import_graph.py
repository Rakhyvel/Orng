import argparse
from zig_scanner import Token, Scanner, alnumus
import networkx as nx
import os


def main():
    def parse_args():
        parser = argparse.ArgumentParser()
        parser.add_argument(
            "--files", nargs="*", help="list of files to build call graph on"
        )

        return parser.parse_args()

    args = parse_args()

    for filename in args.files:
        with open(filename) as f:
            file_text = f.read() + "\n"
            parser = Parser(Scanner(file_text).tokenize(), filename)
            parser.parse()


def parse(filename):
    with open(filename) as f:
        file_text = f.read() + "\n"
        parser = Parser(Scanner(file_text).tokenize(), filename)
        parser.parse()
    return parser


class Parser:
    def __init__(self, tokens, filename):
        self.cursor = 0
        self.tokens = tokens
        self.filename = filename
        self.imports = []
        self.dupes = set()

    def accept(self, token) -> Token | None:
        if self.tokens[self.cursor] == token:
            return self.pop()
        else:
            return None

    def expect(self, value) -> Token:
        if self.tokens[self.cursor].value == value:
            return self.pop()
        else:
            raise ValueError(f"expected {value}, got {self.peek()}")

    def peek(self, offset=0) -> Token:
        return self.tokens[self.cursor + offset]

    def pop(self) -> Token:
        retval = self.tokens[self.cursor]
        self.cursor += 1
        return retval

    def parse(self):
        while self.cursor < len(self.tokens):
            if self.peek().value == "@import":
                self.pop()  # import
                self.pop()  # (
                name = self.pop().value.strip('"')
                if name == "std" or name == "builtin":
                    continue
                path = os.path.normpath(
                    os.path.join(os.path.dirname(self.filename), name)
                )
                self.imports.append(path)
            elif self.cursor < len(self.tokens):
                self.pop()

    def edge_list(self):
        edge_list = []
        for import_name in self.imports:
            edge_list.append((self.filename, import_name))
        return edge_list


def is_identifier(token):
    return all([alnumus(x) for x in token])


ignore_calls = [
    "if",
    "for",
    "switch",
    "while",
    "and",
    "or",
    "fn",
    "union",
    "enum",
    "prefix",
    "postfix",
    "prefix_type",
    "allocator",
    "@tagName",
    "@This",
    "@hasDecl",
    "@TypeOf",
    "@compilerError",
    "@field",
    "@embedFile",
    "@intCast",
    "@as",
    "Managed",
    "parseInt",
    "panic",
    "append",
    "concant",
    "eql",
    "assert",
    "init_with_contents",
    "isAbsolute",
    "alloc",
    "str",
    "init",
    "deinit",
    "free",
    "adaptToNewApi",
    "SetConsoleOutputCP",
    "isUpper",
    "comptimePrint",
    "appendSlice",
    "orderedRemove",
    "utf8ByteSequenceLength",
    "print",
    "createFileAbsolute",
    "StringArrayHashMap",
    "join",
    "writeAll",
    "@intFromBool",
    "keys",
    "put",
    "flat",
]


def longest_call_chain(call_graph, start_function):
    longest_cycle = None
    for cycle in nx.simple_cycles(call_graph):
        if start_function in cycle:
            if longest_cycle is None or len(cycle) > len(longest_cycle):
                longest_cycle = cycle
    return longest_cycle


if __name__ == "__main__":
    main()
