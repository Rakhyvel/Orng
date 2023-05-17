#! /bin/bash
# chmod +x tests/run-integration.sh

if [ "$#" -ne 1 ]
  then
    zig build orng-test && ./zig-out/bin/orng-test integration && kcov kcov-out ./zig-out/bin/orng-test -- coverage
fi

if [ "$#" -eq 1 ]
  then
    zig build orng-test && ./zig-out/bin/orng-test integration $1
fi