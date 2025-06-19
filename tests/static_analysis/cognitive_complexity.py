import argparse
from call_graph import parse, longest_call_chain


def main():
    def parse_args():
        parser = argparse.ArgumentParser()
        parser.add_argument("--file", help="file to run cognitive complexity on")
        parser.add_argument("--fn", help="function name to run cognitive complexity on")

        return parser.parse_args()

    args = parse_args()
    calculate_congitive_complexities(args.file, args.fn)


class Complexity:
    def __init__(self, value, nodes, call_graph):
        self.value = value
        self.nodes = []
        self.call_graph = []


def calculate_congitive_complexities(file, maybe_fn=None):
    parser = parse(file)

    fns = [maybe_fn] if maybe_fn else parser.functions
    ratings = []
    for fn in fns:
        (token_complexity, nodes) = calculate_token_cognitive_complexity(parser.functions[fn].tokens)
        call_chain = longest_call_chain(parser.digraph(), fn)
        recursion_complexity = len(call_chain) if call_chain else 0
        total_complexity = token_complexity + recursion_complexity
        ratings.append((fn, (total_complexity, nodes, call_chain)))

    # Sort by complexity and print ratings out
    ratings.sort(key=lambda t: -t[1][0])
    ratings = list(filter(lambda t: t[1][0] >= 15, ratings))
    if len(ratings) == 0:
        print('All good!')
    else:
        for rating in ratings:
            print(f"{rating[0]}: {rating[1][0]}")
            rating[1][1].sort(key=lambda t: (-t[1], t[0].line))
            for node in rating[1][1]:
                print(f"  - {file}:{node[0].line} [{node[1]}]: {node[0].line_text.strip()}")
            print(rating[1][2])


def calculate_token_cognitive_complexity(tokens):
    complexity = 0
    nesting = 0
    was_else = False
    nodes = []
    for token in tokens:
        if not was_else and token.value in control_flow_tokens:
            complexity += 1
            if token.value in nesting_control_flow_tokens:
                complexity += nesting
            nodes.append((token, nesting + 1))
        elif token.value == "{":
            nesting += 1
        elif token.value == "}":
            nesting -= 1
        was_else = token.value == "else"
    return (complexity, nodes)


control_flow_tokens = [
    "if",
    "else",
    "switch",
    "match",
    "for",
    "while",
    "catch",
    "or",
    "and",
    "orelse",
    "try",
    "break",
    "continue",
    "return",
    "loop"
]

nesting_control_flow_tokens = ["if", "switch", "match", "for", "while", "catch", "loop"]


if __name__ == "__main__":
    main()
