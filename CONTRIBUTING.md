# Contributing to Orng
Thank you for your intetest in contributing to the Orng Programming Language! This document outlines the process for reporting issues and submitting pull requests to ensure everything goes smoothly.

## Reporting Bugs
Help us improve by reporting bugs! Please include the following in your bug report:
* A clear title summarizing the issue
* The version/commit hash you are using
* Steps to reproduce the problem
* Expected vs. actual behavior
* Relevant logs or error messages

See the [bug reporting template](https://github.com/Rakhyvel/Orng/blob/main/docs/bug-reporting-template.md).

## Submitting Pull Requests
To get your contributions merged efficiently:
1. Open an issue if the change is significant
2. Fork the repo and work in a branch
3. Follow the stlye guide (see below)
4. When you are finished, ensure the compiler builds, and all integration and negative tests pass.
```bash
# To run all tests, run the following command
./tests/test.py all
```
5. Submit your pull request:
    * Clearly describe **what** your PR does and **why**.
    * Link any related issues.

## Style Guide
### Naming
- Use `Snake_Case` for types, and `snake_case` for everything else (functions, variables, constants, fields).
- Imported modules should 

* Run `zig fmt` before committing (zls in VSCode makes this easy!)

## Communication
If you have a question or need clarification, feel free to reach out and open a discussion in the Discussions tab, or create an issue in the Issues tab.