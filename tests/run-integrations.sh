#! /bin/bash

zig build inttest && ./zig-out/bin/integration-test && kcov kcov-out ./zig-out/bin/integration-test -- lol