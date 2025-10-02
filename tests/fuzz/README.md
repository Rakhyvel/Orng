I use Dr. Proebsting's rdgen to create random Orange programs. The grammar for fuzz tests are in `fuzz.ebnf`. Running 
`./tests/test.py fuzz` generates 10,000 random Orange programs from the grammar, and attempts to compile them. Any 
programs that caused the compiler to crash are appended to the `problems.txt` file.