#! /bin/bash
# chmod +x tests/roll-fuzz.sh

set -e

for ((plu=1; plu<=10; plu++)); do
    source tests/create-fuzz.sh
    source tests/run-fuzz.sh
done