import argparse
import os
import re
import subprocess
import sys
import xml.etree.ElementTree as ET

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', '--src_files', nargs="*", help="list of modified files")
    parser.add_argument('-b', '--base_ref', nargs=1, help="the base ref")
    return parser.parse_args()

def parse_coverage(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()

    coverage_data = {}

    for package in root.findall(".//package"):
        for class_elem in package.findall(".//class"):
            filename = class_elem.get("filename")
            lines = class_elem.find("lines")

            if filename and lines is not None:
                coverage_data['src/' + filename] = {
                    int(line.get("number")): int(line.get("hits")) > 0
                    for line in lines.findall("line")
                }

    return coverage_data

def print_span_and_source(span):
    [filename, line] = span.split(':')
    with open(filename) as f:
        lines = f.readlines()
        print(f"{span}\n  {lines[int(line) - 1]}", end="")

def check_coverage(src_files, base_ref):
    if not src_files:
        print("No modified source files, skipping coverage check.")
        sys.exit(0)

    # Open, read, and parse the XML file
    cov_xml_path = subprocess.run(["find", ".", "-iname", "cov.xml"], capture_output=True).stdout.decode('utf-8').strip()
    coverage_data = parse_coverage(cov_xml_path)

    uncovered_lines = []
    
    # Check each source file
    for src_file in src_files:
        try:
            # Get modified lines using git diff
            diff_output = subprocess.run(["git", "diff", "--unified=0", base_ref[0], "--", src_file], capture_output=True, text=True).stdout
            modified_lines = []
            for line in diff_output.split("\n"):
                match = re.match(r"@@ -\d+(?:,\d+)? \+(\d+)(?:,(\d+))? @@", line)
                if match:
                    start_line = int(match.group(1))
                    num_lines = int(match.group(2)) if match.group(2) else 1
                    modified_lines.extend(range(start_line, start_line + num_lines))
            
            # Check if modified lines are covered
            for line in modified_lines:
                if line in coverage_data[src_file] and not coverage_data[src_file][line]:
                    uncovered_lines.append(f"{src_file}:{line}")
                    
        except subprocess.CalledProcessError as e:
            print(f"Error processing file {src_file}: {e}")
            sys.exit(1)
    
    # Report uncovered lines
    if uncovered_lines:
        print("ERROR: The following modified lines are not covered by tests:")
        for span in uncovered_lines:
            print_span_and_source(span)
        sys.exit(1)
    
    sys.exit(0)

if __name__ == "__main__":
    args = parse_args()
    check_coverage(args.src_files, args.base_ref)