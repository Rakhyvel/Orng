## Standard Refactoring Checks:
(It would be nice if these could be automated!)
1. Early returns/breaks/continues are fine, so long as they're visible to the natural end of the function/loop
1. The declaration of `var`s and mutable objects should be visible to when they go out of scope
1. No magic numbers, use `(?!<uif)[2-9][0-9]*` to search
    * `0` and `1` are fine
1. No global variables
1. Run `similarities.py`, there should not be any repeated blocks of code
1. Use LCOM4 on structs and files, split up if there are two distinct graphs