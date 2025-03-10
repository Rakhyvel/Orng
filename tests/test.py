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
import platform
import shutil
import subprocess


TEST_DIR = os.path.dirname(os.path.realpath(__file__))
SRC_DIR = os.path.normpath(os.path.join(TEST_DIR, "..", "src"))


def main():
    args = parse_args()

    shutil.rmtree("zig-cache", ignore_errors=True)
    shutil.rmtree("zig-out", ignore_errors=True)
    res = subprocess.run(["zig", "build", "orng-test", "--release=safe", "-Doptimize=Debug"]).returncode
    if res != 0:
        exit(1)

    match args.command:
        case "integration":
            integration(args)
        case "negative":
            negative(args)
        case "all":
            all(args)
        case "modified":
            modified(args)
        case "fuzz":
            fuzz()
        # case "count":
        #     count(args)


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
    create.add_argument("-n", "--no-coverage", action='store_const', default=False, const=True, help="does not perform coverage after negative testing, even if tests pass")

    create = subparsers.add_parser("modified", help="run integration and negative tests, merge code coverage")
    
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
        if platform.system() == "Windows":
            print("test coverage not supported on Windows :(")
            return
        shutil.rmtree("kcov-out", ignore_errors=True)
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
        if platform.system() == "Windows":
            print("test coverage not supported on Windows :(")
            return
        subprocess.run(["kcov", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "negative-coverage"] + files)
        print("kcov ouput written to kcov-out/index.html")
    else:
        print("coverage not done due to failed tests")


def all(args):
    files = collect_files(args, "tests/integration")
    integration_res = subprocess.run(["./zig-out/bin/orng-test", "integration"] + files).returncode
    if not args.no_coverage and platform.system() != "Windows":
        subprocess.run(["kcov", "--clean", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "coverage"] + files)
        
    files = collect_files(args, "tests/negative")
    negative_res = 0
    if not args.no_coverage and platform.system() != "Windows":
        subprocess.run(["kcov", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "negative"] + files)
    else:
        negative_res = subprocess.run(["./zig-out/bin/orng-test", "negative"] + files).returncode

    if negative_res != 0 or integration_res != 0:
        exit(1)


def modified(args):
    files = collect_modified_files(args, "tests/integration")
    integration_res = 0
    if len(files) > 0:
        integration_res = subprocess.run(["./zig-out/bin/orng-test", "integration"] + files).returncode
        if platform.system() != "Windows":
            subprocess.run(["kcov", "--clean", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "coverage"] + files)

    files = collect_modified_files(args, "tests/negative")
    negative_res = 0
    if len(files) > 0:
        if platform.system() != "Windows":
            subprocess.run(["kcov", "--include-path", SRC_DIR, "kcov-out", "./zig-out/bin/orng-test", "negative"] + files)
        else:
            negative_res = subprocess.run(["./zig-out/bin/orng-test", "negative"] + files).returncode

    if negative_res != 0 or integration_res != 0:
        exit(1)

    
def fuzz():
    res = subprocess.run(["zig", "build", "orng"]).returncode
    if res != 0:
        return
    subprocess.run(["rm", "tests/fuzz/problems.txt"]).returncode

    print("Running fuzz tests... inputs that cause compiler crashes will be placed in tests/fuzz/problems.txt")

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
                eof_index = line.index("eof\"")
                trimmed = line[3:eof_index]
                with open("tests/fuzz/fuzz.orng", "w") as w:
                    w.write(trimmed)
                try:
                    res = subprocess.run(["./zig-out/bin/orng", "tests/fuzz/fuzz.orng", "_enable_fuzz_tokens"], timeout=2).returncode
                except subprocess.TimeoutExpired:
                    res = 1
                if res != 0:
                    print("[ FAILED ]\n", trimmed)
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


def collect_modified_files(args, base):
    res = subprocess.run(["git", "diff", "--name-only", "--diff-filter=AM", "origin/main...HEAD"], capture_output=True).stdout.decode('utf-8').split('\n')
    res = list(filter(lambda x: x.startswith(base) and x.endswith('.orng'), res))
    return res


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