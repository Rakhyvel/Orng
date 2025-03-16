import argparse
from zig_scanner import Scanner, alnumus
import networkx as nx


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
            parser = Parser(Scanner(file_text).tokenize())
            parser.parse(filename)

    print(longest_call_chain(parser.digraph(), "resolve_qualified_name"))


def parse(filename):
    with open(filename) as f:
        file_text = f.read() + "\n"
        parser = Parser(Scanner(file_text).tokenize())
        parser.parse(filename)
    return parser


class Function:
    def __init__(self, filename):
        self.filename = filename
        self.children = set()
        self.tokens = []


class Parser:
    def __init__(self, tokens):
        self.cursor = 0
        self.tokens = tokens
        self.functions = dict()  # function name -> [functions called]
        self.dupes = set()

    def accept(self, token) -> str | None:
        if self.tokens[self.cursor] == token:
            return self.pop()
        else:
            return None

    def expect(self, token) -> str:
        if self.tokens[self.cursor] == token:
            return self.pop()
        else:
            raise ValueError(f"expected {token}, got {self.peek()}")

    def peek(self, offset=0):
        return self.tokens[self.cursor + offset]

    def pop(self):
        retval = self.tokens[self.cursor]
        self.cursor += 1
        return retval

    def parse(self, filename):
        while self.cursor < len(self.tokens):
            if self.peek() == "fn" and is_identifier(self.peek(1)):
                self.parse_function(filename)
            elif self.cursor < len(self.tokens):
                self.pop()

    def parse_function(self, filename):
        self.expect("fn")

        function_name = self.peek()

        if function_name not in self.functions and function_name not in ignore_calls:
            self.functions[function_name] = Function(filename)
        else:
            self.dupes.add(function_name)

        # find the begining of the function
        while self.pop() != "{":
            pass

        fn_token_start = self.cursor

        brace_depth = 1

        while brace_depth > 0:
            fn_token_end = self.cursor
            if self.peek() == "{":
                brace_depth += 1
            elif self.peek() == "}":
                brace_depth -= 1
            if is_identifier(self.peek()) and self.peek(1) == "(":
                callee_name = self.peek()
                # idx = -1
                # while self.peek(idx) == '.':
                #     callee_name = self.peek(idx - 1) + '.' + callee_name
                #     idx -= 2
                if (
                    callee_name not in ignore_calls
                    and function_name not in ignore_calls
                ):
                    self.functions[function_name].children.add(callee_name)
            self.pop()

        if function_name in self.functions:
            self.functions[function_name].tokens = self.tokens[
                fn_token_start:fn_token_end
            ]

    def digraph(self):
        call_graph = nx.DiGraph()
        edge_list = []
        for function_name in self.functions.keys():
            for called in self.functions[function_name].children:
                edge_list.append((called, function_name))
        call_graph.add_edges_from(edge_list)
        return call_graph

    def print_call_graph(self):
        for function_name in self.functions.keys():
            print(f"{function_name}: {self.functions[function_name].children}")


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
