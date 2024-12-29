#! /bin/python3.10
# chmod +x tests/dag-walker.py

import re

# den som går på DAGarna
#
# This script is used for whitebox path coverage testing, to generate all possible non-trivial paths through the code. 
# The `data` string describes the code under test as a DAG of nodes, and walks over the DAG emitting each possible path 
# from the begining of the program to each possible end (hence, DAG-walker).
#
# Use the regex: ` if | for | try | and | or | orelse | catch ` to search for all control 
# flow keywords. Then, use those to construct nodes. Use "+" to indicate successful termination of the code, and "-" to
# represent errant termination.
#
# Then, run the script. It'll spit out a text file of every possible path through the program. Some paths will be
# impossible in ways that the script couldn't possible know about from just reading a DAG, so you'll need to cull those.
#
# node format:
# "name of from-node" -> "name of to-node" [label=whatever];
data = """
"template is memoized for this pass-through" -> "+" [label=true];
"template is memoized for this pass-through" -> "arity" [label=false];

"arity" -> "const arity1" [label=0];
"arity" -> "has const parameter" [label=1];
"arity" -> "has const parameter" [label=n];

"const arity1" -> "const arity2" [label=0];
"const arity1" -> "const arity2" [label=1];
"const arity1" -> "const arity2" [label=n];

"has const parameter" -> "const arity1" [label=true];
"has const parameter" -> "const arity1" [label=false];

"const arity2" -> "+" [label=0];
"const arity2" -> "+" [label=1];
"const arity2" -> "+" [label=n];
"""


class Nodes_List:
    def __init__(self):
        self.nodes = []

    def add_node(self, name):
        for node in self.nodes:
            if node.name == name:
                return node
        else:
            retval = Node(name)
            self.nodes.append(retval)
            return retval


class Node:
    def __init__(self, name):
        self.name = name
        self.children = []

    def add_child(self, other_name, conn_type):
        self.children.append((other_name, conn_type))

    def output(self, fd, string):
        for child in self.children:
            (to_node, conn_type) = child
            my_string = string + f"({self.name}: {conn_type}),  "
            to_node.output(fd, my_string)
        if len(self.children) == 0:
            fd.write(string + f"{self.name}\n")


def main():
    node_list = Nodes_List()
    lines = data.split("\n")
    for line in lines:
        stripped = line.strip()
        tokens = re.split(" -> | \[label\=|];", stripped)
        if len(tokens) < 3:
            continue
        (from_name, to_name, conn_type) = (tokens[0], tokens[1], tokens[2])
        from_node = node_list.add_node(from_name)
        to_node = node_list.add_node(to_name)
        from_node.add_child(to_node, conn_type)

    with open("out.txt", "w") as fd:
        node_list.nodes[0].output(fd, "")

main()