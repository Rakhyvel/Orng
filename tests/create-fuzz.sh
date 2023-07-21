#! /bin/bash
# chmod +x tests/create-fuzz.sh

python3.10 ../rdgen/main.py examples --input tests/fuzz/fuzz.ebnf --output tests/fuzz/fuzz.txt --quantity 10000 --limit 5