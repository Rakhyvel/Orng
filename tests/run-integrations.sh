#! /bin/bash
# chmod +x tests/run-integration.sh

set -e

zig build orng-test

if [ "$#" -lt 1 ]
then
    ./zig-out/bin/orng-test integration
    kcov kcov-out ./zig-out/bin/orng-test -- coverage
else
    ./zig-out/bin/orng-test integration "$@"
fi