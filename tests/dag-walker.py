import re


# den som går på DAGarna


data = """
    "expr isnt sum type" -> "-" [label=true];
    "expr isnt sum type" -> "expr sum isnt error" [label=false];

    "expr sum isnt error" -> "-" [label=true];
    "expr sum isnt error" -> "function doesnt return sum" [label=false];

    "function doesnt return sum" -> "-" [label=true];
    "function doesnt return sum" -> "function doesnt return error" [label=false];

    "function doesnt return error" -> "-" [label=true];
    "function doesnt return error" -> "error terms" [label=false];

    "error terms" -> "+" [label=0];
    "error terms" -> "terms dont match function" [label=n];

    "terms dont match function" -> "-" [label=true];
    "terms dont match function" -> "+" [label=false];
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