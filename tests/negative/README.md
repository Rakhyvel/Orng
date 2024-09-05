# `tests/negative/`

These test files test the compilers error reporting functionality. The Orng programs in this folder should not compile. If they do not compile, the test passes, if they do compile, the test fails.

Compiler error messages should be informative. Orng is a fairly conventional programming language, so most error messages do not need to be overly verbose for common programming language idioms. However, some features of the language may be counter-intuitive to other programmers, and so customized error messages should be made to be helpful to those picking up on the language.

## How to effectively write negative tests
1. Write a negative test case that _fails_ (the code compiles)
    * __HINT__: If you write a test case that you expect to compile, and it doesn't, add it to integration tests!
1. Change the test minimally to get the error you're looking for
1. Re-run, make sure it fails where you want it