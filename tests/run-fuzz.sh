#! /bin/bash
# chmod +x tests/run-fuzz.sh

zig build orng-test && ./zig-out/bin/orng-test fuzz