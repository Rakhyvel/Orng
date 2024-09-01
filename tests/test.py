#! /bin/python3.10
# chmod +x tests/test.py

"""
Unified test script.
usage: test.py {integration, negative, fuzz, count}

commands:
    integration - Runs integration tests, runs kcov on integration tests if test pass.
        --test (-t)         - List of either files or directories to run tests on. Duplicates are allowed, and
                              only tested once.
        --no-coverage (-n)  - Do not run coverage after testing, even if all tests pass.
        --count (-c)        - Recursively count the number of Orng integration test files in the directories 
                              given.

    negative    - Runs negative tests, runs kcov on integration tests if test pass.
        --test (-t)         - List of either files or directories to run tests on. Duplicates are allowed, and
                              only tested once.
        --no-coverage (-n)  - Do not run coverage after testing, even if all tests pass.
        --count (-c)        - Recursively count the number of Orng integration test files in the directories 
                              given.

    fuzz        - Runs fuzz tests.
"""

import argparse
import datetime
import os
import shutil
import subprocess


TEST_DIR = os.path.dirname(os.path.realpath(__file__))
SRC_DIR = os.path.normpath(os.path.join(TEST_DIR, "..", "src"))


def main():
    args = parse_args()

    subprocess.run(["rm", "-rf", "zig-cache", "zig-out"])
    res = subprocess.run(["zig", "build", "orng-test"]).returncode
    if res != 0:
        return

    match args.command:
        case "integration":
            integration(args)
        case "negative":
            negative(args)
        case "all":
            all(args)
        case "fuzz":
            fuzz()
        case "count":
            count(args)


def parse_args():
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest="command", required=True)

    create = subparsers.add_parser("integration", help="run integration tests")
    create.add_argument("-t", "--test", nargs="*", help="list of one or more files/directories of integration tests to run")
    create.add_argument("-n", "--no-coverage", action='store_const', default=False, const=True, help="does not perform coverage after integration testing, even if tests pass")
    create.add_argument("-c", "--count", nargs="*", help="recursively counts the number of integration test files in the directories specified")

    create = subparsers.add_parser("negative", help="run negative tests")
    create.add_argument("-t", "--test", nargs="*", help="list of one or more files/directories of negative tests to run")
    create.add_argument("-n", "--no-coverage", action='store_const', default=False, const=True, help="does not perform coverage after negative testing, even if tests pass")
    create.add_argument("-c", "--count", nargs="*", help="recursively counts the number of negative test files in the directories specified")

    create = subparsers.add_parser("all", help="run integration and negative tests, merge code coverage")
    create.add_argument("-t", "--test", nargs="*", help="list of one or more files/directories of negative tests to run")
    create.add_argument("-c", "--count", nargs="*", help="recursively counts the number of negative test files in the directories specified")
    
    create = subparsers.add_parser("fuzz", help="create fuzz and run fuzz tests")

    return parser.parse_args()


def integration(args):
    files = collect_files(args, "tests/integration")

    if args.count:
        print("Number of integration test files: ", len(files))
        return
    
    res = subprocess.run(["./zig-out/bin/orng-test", "integration"] + files).returncode

    if args.no_coverage:
        return
    elif res == 0:
        shutil.rmtree("kcov-out")
        subprocess.run(["kcov", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "coverage"] + files)
        print("kcov ouput written to kcov-out/index.html")
    else:
        print("coverage not done due to failed tests")


def negative(args):
    files = collect_files(args, "tests/negative")

    if args.count:
        print("Number of negative test files: ", len(files))
        return

    res = subprocess.run(["./zig-out/bin/orng-test", "negative"] + files).returncode
    
    if args.no_coverage:
        return
    elif res == 0:
        subprocess.run(["kcov", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "negative-coverage"] + files)
        print("kcov ouput written to kcov-out/index.html")
    else:
        print("coverage not done due to failed tests")


def all(args):
    files = collect_files(args, "tests/integration")
    res = subprocess.run(["./zig-out/bin/orng-test", "integration"] + files).returncode
    if res != 0:
        return
    subprocess.run(["kcov", "--clean", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "coverage"] + files)
        
    files = collect_files(args, "tests/negative")
    subprocess.run(["kcov", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "negative"] + files)

    
def fuzz():
    res = subprocess.run(["zig", "build", "orng", "-target x86_64-linux-gnu "]).returncode
    if res != 0:
        return
    subprocess.run(["rm", "tests/fuzz/problems.txt"]).returncode

    for i in range(0, 90_000_000): # 90,000,000 should be about 20 hours, enough for a 4HL fella
        now = datetime.datetime.now()
        print("{} {:,}".format(now, i * 10_000))
        res = subprocess.run(["python3.11", "src/rdgen/main.py", "examples", "--input", "tests/fuzz/fuzz.ebnf", "--output", "tests/fuzz/fuzz.txt", "--quantity", "10000", "--limit", "3"]).returncode
        if res != 0:
            return
        with open("tests/fuzz/fuzz.txt", "r") as f, open("tests/fuzz/problems.txt", "a") as problem_file:
            for line in f:
                if len(line) <3:
                    continue # Skip opening and closing lines
                eof_index = line.index("eof")
                trimmed = line[3:eof_index]
                with open("tests/fuzz/fuzz.orng", "w") as w:
                    w.write(trimmed)
                res = subprocess.run(["./zig-out/bin/orng", "tests/fuzz/fuzz.orng", "--fuzz"]).returncode
                if res != 0:
                    problem_file.write(trimmed + "\n")


def collect_files(args, base):
    # Extract paths in the args.test list, if there are any
    # Prepend with base
    if args.test and len(args.test) > 0 and args.test[0] != '.': # If the user enters `-t .`, treat that as a test of the whole directory
        full_path = [os.path.join(base, path) for path in args.test]
    elif args.count:
        full_path = [os.path.join(base, path) for path in args.count]
    else:
        full_path = [base]

    # Collect all .orng files recursively in any directories
    files = []
    for path in full_path:
        files += collect_files_recursive(path)
    return list(dict.fromkeys(files))


def collect_files_recursive(root_filename):
    files = []
    if os.path.isdir(root_filename):
        dir_list = os.listdir(root_filename)
    elif root_filename.endswith(".orng"):
        return [root_filename]
    else:
        return []

    for file_name in dir_list:
        root_and_filename = os.path.join(root_filename, file_name)
        if os.path.isdir(root_and_filename):
            # Directory
            files += collect_files_recursive(root_and_filename)
        elif root_and_filename.endswith(".orng"):
            # File
            files.append(root_and_filename)
    files.sort()
    return files



if __name__ == "__main__":
    main()