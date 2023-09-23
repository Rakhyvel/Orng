import subprocess
import datetime


def main():
    res = subprocess.run(["zig", "build", "orng"]).returncode
    if res != 0:
        return
    subprocess.run(["rm", "tests/fuzz/problems.txt"]).returncode

    for i in range(0, 90_000_000): # 90,000,000 should be about 20 hours, enough for a 4HL fella
        now = datetime.datetime.now()
        print("{} {:,}".format(now, i * 10_000))
        subprocess.run(["./tests/create-fuzz.sh"]).returncode
        with open("tests/fuzz/fuzz.txt", "r") as f, open("tests/fuzz/problems.txt", "a") as problem_file:
            for line in f:
                if len(line) < 3:
                    continue # Skip opening and closing lines
                eof_index = line.index("eof")
                trimmed = line[3:eof_index]
                with open("tests/fuzz/fuzz.orng", "w") as w:
                    w.write(trimmed)
                res = subprocess.run(["./zig-out/bin/orng", "tests/fuzz/fuzz.orng", "--fuzz"]).returncode
                if res != 0:
                    problem_file.write(trimmed + "\n")

main()