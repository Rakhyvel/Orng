#! /bin/bash
# chmod +x tests/run-integration.sh

zig build orng-test && ./zig-out/bin/orng-test integration && kcov kcov-out ./zig-out/bin/orng-test -- coverage