# `tests/integration/`
This directory contains integration test cases, and their outputs. For a test `tests/integration/x.orng`, it's output C file will be located in `tests/integration/build/x.c`.

To run integration tests, execute `./tests/run-integrations.sh` in a Unix shell. This will run each test, and display which fail and which pass. If all tests pass, kcov coverage is generated at `kcov-out/`. If you pass a sub-directory to `tests/run-integrations.sh`, it will only run tests within that sub-directory, and if you pass a filename it will only run that one test case.