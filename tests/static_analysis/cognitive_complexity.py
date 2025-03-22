import argparse
from call_graph import parse, longest_call_chain


def main():
    def parse_args():
        parser = argparse.ArgumentParser()
        parser.add_argument("--file", help="file to run cognitive complexity on")
        parser.add_argument("--fn", help="function name to run cognitive complexity on")

        return parser.parse_args()

    args = parse_args()
    complexity = calculate_cognitive_complexity(args.file, args.fn)
    if complexity <= 15:
        print(f"complexity: {complexity} (good!)")
    else:
        print(f"complexity: {complexity} (bad!)")


def calculate_cognitive_complexity(file, fn):
    parser = parse(file)

    token_complexity = calculate_token_cognitive_complexity(parser.functions[fn].tokens)
    call_chain = longest_call_chain(parser.digraph(), fn)
    recursion_complexity = len(call_chain) if call_chain else 0
    print(call_chain)
    return token_complexity + recursion_complexity


def calculate_token_cognitive_complexity(tokens):
    complexity = 0
    nesting = 0
    was_else = False
    for token in tokens:
        if not was_else and token in control_flow_tokens:
            complexity += 1
            if token in nesting_control_flow_tokens:
                complexity += nesting
        elif token == "{":
            nesting += 1
        elif token == "}":
            nesting -= 1
        was_else = token == "else"
    return complexity


control_flow_tokens = [
    "if",
    "else",
    "switch",
    "for",
    "while",
    "catch",
    "or",
    "and",
    "orelse",
    "break",
    "continue",
    "return",
]

nesting_control_flow_tokens = ["if", "switch", "for", "while", "catch"]


if __name__ == "__main__":
    main()
