import argparse
import os
from zig_scanner import Scanner
from call_graph import Parser as Call_Parser
from import_graph import Parser as Import_Parser

import networkx as nx


def main():
    args = parse_args()

    graph = dict()
    import_graph = nx.DiGraph()
    for filename in args.files:
        if os.path.isdir(filename):
            continue
        if not filename.endswith(".zig"):
            continue

        with open(filename) as f:
            file_text = f.read() + "\n"
            scanner = Scanner(file_text)
            tokens = scanner.tokenize()

            call_parser = Call_Parser(tokens)
            call_parser.parse(filename)
            for function_name in call_parser.functions.keys():
                # assert function_name not in graph, f"{function_name}"
                if function_name not in graph:
                    graph[function_name] = set()
                graph[function_name] = graph[function_name].union(
                    call_parser.functions[function_name].children
                )

            import_parser = Import_Parser(tokens, filename)
            import_parser.parse()
            import_graph.add_edges_from(import_parser.edge_list())

    # Convert to a DiGraph
    G = nx.DiGraph()
    for node, neighbors in graph.items():
        for neighbor in neighbors:
            G.add_edge(node, neighbor)

    # Find SCCs
    sccs = list(nx.strongly_connected_components(G))
    sccs_sorted = sorted(sccs, key=len, reverse=False)

    sccs = list(nx.strongly_connected_components(import_graph))
    sccs_sorted = sorted(sccs, key=len, reverse=False)

    for scc in sccs_sorted:
        print(scc)


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--files", nargs="*", help="list of files to build call graph on"
    )

    return parser.parse_args()


if __name__ == "__main__":
    main()
