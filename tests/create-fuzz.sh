#! /bin/bash
# chmod +x tests/create-fuzz.sh

python3.11 src/rdgen/main.py examples --input tests/fuzz/fuzz.ebnf --output tests/fuzz/fuzz.txt --quantity 10000 --limit 1