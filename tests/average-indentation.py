#! /bin/python3.10

import os

TEST_DIR = os.path.dirname(os.path.realpath(__file__))
SRC_DIR = os.path.normpath(os.path.join(TEST_DIR, "..", "src"))

def main():
    filenames = read_files(SRC_DIR)
    indentation_list = []
    for filename in filenames:
        with open(filename, "r") as fd:
            lines = fd.readlines()
            median_indentation(lines, indentation_list)
    indentation_list.sort()
    print(indentation_list[len(indentation_list) // 2])


# Get the list of all files and directories
def read_files(dir):
    files = []
    dir_list = os.listdir(dir)
    for file_name in dir_list:
        if not os.path.isdir(os.path.join(dir, file_name)):
            files.append(os.path.join(dir, file_name))
    return files

def median_indentation(lines, indentation_list):
    for line in lines:
        if len(line) < 0:
            continue
        if len(line.strip()) == 0:
            continue
        indentation_list.append(len(line) - len(line.lstrip()))



if __name__ == "__main__":
    main()