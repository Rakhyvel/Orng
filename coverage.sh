#! /bin/bash

rm -rf zig-cache/o
zig test src/parser.zig
kcov kcov-out ./zig-cache/o/*/test