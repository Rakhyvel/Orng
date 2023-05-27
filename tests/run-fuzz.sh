#! /bin/bash
# chmod +x tests/run-fuzz.sh

set -ev

zig build orng-test
./zig-out/bin/orng-test fuzz