import argparse
import os
import subprocess
import sys

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', '--src_files', nargs="*", help="list of modified files")
    parser.add_argument('-b', '--base_ref', nargs=1, help="the base ref")
    return parser.parse_args()

def check_coverage(src_files, base_ref):
    if not src_files:
        print("No modified source files, skipping coverage check.")
        sys.exit(0)
    
    # Get covered lines from kcov output
    covered_lines = set()
    try:
        # Use subprocess.run to execute grep command
        grep_process = subprocess.run(
            ["grep", "-rohE", "src/[^:]+:[0-9]+", "kcov-out/"],
            capture_output=True,
            text=True
        )
        
        for line in grep_process.stdout.splitlines():
            line_num = line.split(':')[1]
            covered_lines.add(line_num)
    except subprocess.CalledProcessError:
        # Handle case where grep finds no matches
        pass

    uncovered_lines = []
    
    # Check each source file
    for src_file in src_files:
        try:
            # Get modified lines using git diff
            diff_process = subprocess.run(
                ["git", "diff", "-U0", f"origin/{base_ref}", "--", src_file],
                capture_output=True,
                text=True
            )
            
            # Extract line numbers from git diff output
            modified_lines = []
            for line in diff_process.stdout.splitlines():
                if line.startswith('+'):
                    # Extract numbers from the line
                    nums = [n for n in line.split() if n.isdigit()]
                    modified_lines.extend(nums)
            
            print(modified_lines)
            
            # Check if modified lines are covered
            for line in modified_lines:
                if line not in covered_lines:
                    uncovered_lines.append(f"{src_file}:{line}")
                    
        except subprocess.CalledProcessError as e:
            print(f"Error processing file {src_file}: {e}")
            sys.exit(1)
    
    # Report uncovered lines
    if uncovered_lines:
        print("ERROR: The following modified lines are not covered by tests:")
        for line in uncovered_lines:
            print(line)
        sys.exit(1)
    
    sys.exit(0)

if __name__ == "__main__":
    args = parse_args()
    check_coverage(args.src_files, args.base_ref)