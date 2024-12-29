import argparse
import os

import networkx as nx
from networkx.algorithms.community import greedy_modularity_communities

def main():
    args = parse_args()

    total_dict = dict()
    # print(args.files)
    for filename in args.files:
        if os.path.isdir(filename):
            continue
        with open(filename) as f:
            file_text = f.read() + '\n'
            parser = Parser(Scanner(file_text).tokenize())
            parser.parse(filename)

            for function_name in parser.functions.keys():
                assert function_name not in total_dict, f"{function_name}"
                total_dict[function_name] = parser.functions[function_name]

    # sccs = find_sccs(parser.functions)
    # for scc in sccs:
    #     if len(scc) > 1:
    #         print(scc)
    communities = detect_communities(total_dict)
    print("Detected Communities:")
    for i, community in enumerate(communities, start=1):
        if len(community) < 0:
            continue
        file_set = set()
        for function in community:
            if function in total_dict: file_set.add(total_dict[function].filename)
        def function_filter(function): return function in total_dict and total_dict[function].filename == 'src/walker.zig'
        new_community = list(filter(function_filter, community))
        if len(new_community) <= 0:
            continue
        print(f"community {i}: {file_set}\n{new_community}\n")
    # parser.print_call_graph()



def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--files", nargs='*', help="list of files to build call graph on")

    return parser.parse_args()


def alnumus(c):
    return c == "_" or c.isalnum() or c == '@'


def is_identifier(token):
    return all([alnumus(x) for x in token])

    
keywords = [ # TODO: Add these to a text file, and read it in
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

from typing import List, Dict

def find_sccs(graph: Dict[str, List[str]]) -> List[List[str]]:
    """
    Identify strongly connected components (SCCs) in a directed graph.

    :param graph: A dictionary where keys are node names and values are lists of connected nodes.
    :return: A list of SCCs, each represented as a list of nodes.
    """
    index = 0  # Global index counter
    stack = []  # Stack to maintain the current path in the graph
    indices = {}  # Node to index mapping
    lowlink = {}  # Node to lowlink value mapping
    on_stack = set()  # Set to check if a node is on the stack
    sccs = []  # List to store the SCCs

    def strongconnect(node: str):
        nonlocal index
        indices[node] = index
        lowlink[node] = index
        index += 1
        stack.append(node)
        on_stack.add(node)

        # Explore all neighbors of the current node
        for neighbor in graph.get(node, []):
            if neighbor not in indices:
                # Neighbor not visited, recurse on it
                strongconnect(neighbor)
                lowlink[node] = min(lowlink[node], lowlink[neighbor])
            elif neighbor in on_stack:
                # Update lowlink for nodes on the stack
                lowlink[node] = min(lowlink[node], indices[neighbor])

        # If the current node is a root node, pop the stack to form an SCC
        if lowlink[node] == indices[node]:
            scc = []
            while True:
                current = stack.pop()
                on_stack.remove(current)
                scc.append(current)
                if current == node:
                    break
            sccs.append(scc)

    # Start the algorithm for each node in the graph
    for node in graph:
        if node not in indices:
            strongconnect(node)

    return sccs

def detect_communities(graph_dict):
    """
    Detects communities in a graph using modularity optimization.

    Parameters:
        graph_dict (dict): A dictionary mapping node names to a list of adjacent nodes.

    Returns:
        list: A list of sets, where each set contains the nodes in a community.
    """
    # Create a NetworkX graph from the dictionary
    G = nx.Graph()
    for node, neighbors in graph_dict.items():
        for neighbor in neighbors.children:
            G.add_edge(node, neighbor)

    # Use greedy modularity communities to detect communities
    communities = greedy_modularity_communities(G)

    # Convert the result to a list of sets
    return [set(community) for community in communities]

ignore_calls = ['if', 'for', 'switch', 'while', '@hasDecl', '@memcpy', 'ArrayList', 'AutoArrayHashMap', 
    'StringArrayHashMap', 'and', 'or', 'basename', 'bufferedReader', 'close', '@TypeOf', '@field', '@hasField', 
    '@intFromBool', '@intFromEnum', '@tagName', '@typeInfo', 'assert', 'print', '@alignCast', '@as', '@divTrunc', 
    '@intCast', '@intFromFloat', '@ptrCast', '@ptrFromInt', '@sizeOf', '@enumFromInt', 'append', 'eql', 'parseFloat', 
    'parseInt', 'fetchPut', 'openFile', 'openFileAbsolute', 'orderedRemove', 'readAllArrayList', 'toOwnedSlice', 
    'milliTimestamp', 'toOwned', 'writeByte', 'getLast', 'outputColor', 'isAlphanumeric', 'isDigit', 'isLower', 
    'isUpper', 'isWhitespace', 'utf8CountCodepoints', 'writeAll', 'getStdOut', 'initWithAllocator', 
    'clearRetainingCapacity', 'swapRemove', 'createFile', 'fn', 'union', 'enum', 'requires', 'some', 'exit', 'next', 
    'func', 'printf', 'test_file', 'cwd', 'concat', 'dirname', 'find', 'join', 'put', 'reader', 'realpath', 'stat',
    'destroy', 'free', 'insert', 'len', 'return', 'str', 'writer', 'create', 'new', 'pprint', 'init', 'postfix', 
    'format', 'prefix', 'pprint', 'deinit', 'new', 'main', 'init_with_contents']

class Function:
    def __init__(self, filename):
        self.filename = filename
        self.children = set()

class Parser:
    def __init__(self, tokens):
        self.cursor = 0
        self.tokens = tokens
        self.functions = dict() # function name -> [functions called]
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
            if self.peek() == 'fn' and is_identifier(self.peek(1)):
                self.parse_function(filename)
            if self.cursor < len(self.tokens): 
                self.pop()

    def parse_function(self, filename):
        self.expect('fn')
        
        function_name = self.peek()

        # print(f'function_name: {function_name}')

        if function_name not in self.functions and function_name not in ignore_calls:
            self.functions[function_name] = Function(filename)
        else:
            self.dupes.add(function_name)

        while self.pop() != '{': pass # find the begining of the function

        brace_depth = 1

        while brace_depth > 0:
            if self.peek() == '{':
                brace_depth += 1
            elif self.peek() == '}':
                brace_depth -= 1

            if is_identifier(self.peek()) and self.peek(1) == '(':
                callee_name = self.peek()
                # idx = -1
                # while self.peek(idx) == '.':
                #     callee_name = self.peek(idx - 1) + '.' + callee_name
                #     idx -= 2
                if callee_name not in ignore_calls and function_name not in ignore_calls:
                    self.functions[function_name].children.add(callee_name)
            self.pop()

    # def print_call_graph(self):
    #     for function_name in self.functions.keys():
    #         for callee_name in self.functions[function_name]:
    #             # print(f'{function_name} -> {callee_name};')
    #             pass


if __name__ == '__main__':
    main()