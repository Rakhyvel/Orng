#! /bin/bash
# chmod +x tests/run-negative.sh

set -e

zig build orng-test

if [ "$#" -lt 1 ]
then
    ./zig-out/bin/orng-test negative
    kcov kcov-out ./zig-out/bin/orng-test -- negative-coverage
else
    ./zig-out/bin/orng-test negative "$@"
fi