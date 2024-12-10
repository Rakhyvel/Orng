# Contributing to Orng
Thank you for your intetest in contributing to the Orng Programming Language! This document outlines the process for reporting issues and submitting pull requests to ensure everything goes smoothly.

## Reporting Bugs
Help us improve Orng by reporting bugs effectively:

### Bug Report Checklist
* A clear title summarizing the issue
* The version/commit hash you are using
* Your environment detauls (OS, Zig version, etc)
* Steps to reproduce the problem
* Expected vs. actual behavior
* Relevant logs or error messages

### Bug Reporting Process
1. Check existing issues to avoid duplicates
2. Use the [bug reporting template](https://github.com/Rakhyvel/Orng/blob/main/docs/bug-reporting-template.md)
3. Provide minimal reproducible examples when possible


## Submitting Pull Requests

### Prerequisites
- Ensure you have Zig installed (version 0.13.0 or later)
- Ensure you have Python installed (version 3.10.12 or later)

To get your contributions merged efficiently:
1. Open an issue for significant changes to discuss the proposed modification (or feel free to claim an already open one!)
2. Fork the repo
3. Create a new branch with a descriptive name
3. Make your changes
    * Follow the stlye guide (see below)
4. When you are finished:
    * Ensure the compiler builds
    ```bash
    zig build orng
    ```
    * Ensure the compiler can compile the example project
    ```bash
    cd examples
    ../zig-out/bin/orng build
    ```
    * Ensure all integration and negative tests pass
    ```bash
    # To run all tests, run the following command
    ./tests/test.py all
    ```
5. Submit your pull request:
    * Clearly describe **what** your PR does and **why**.
    * Link any related issues.
    * Include any necessary documentation updates
    * Be prepared for code review and potential requested changes

## Style Guide
* Always run `zig fmt` before committing (zls in VSCode makes this easy!)

### Naming
- Use `Snake_Case` for types.
- Use `snake_case` for functions, variables, constants, fields.
- Use `snake_case_` for imports.
- Use `CamelCase` for errors.

### Code Quality
* Write clear, concise comments
* Avoid unnecessary complexity
* Prioritize readability


## Communication Channels
Need help or want to discuss the project?
* Open a discussion in the GitHub Discussions tab
* Create an issue for a specific problem

## Recognition
Contributions are valued! Feel free to add your name to the `docs/CONTRIBUTORS.md` file.

_Last updated: 2024-09-12_