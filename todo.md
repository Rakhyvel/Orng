### Scanner
- [x] Lex out comments
- [x] Go through grammar and find all Token kinds there could be, list them in TokenKind
- [x] Be able to lex out any token type
- [x] Tokens should have spans
- [x] Remove unused token kinds
- [x] Add D_STAR token kind
    - [x] Add D_STAR to binaryOperators
    - [x] Add D_STAR to reprFromTokenKind()
    - [x] Add D_STAR_ASSIGN TokenKind, binaryOperators, reprFromTokenKind

### Parser
- [x] Write recursive descent parser
- [x] Add error handling, with token spans (line AND col)
    - [ ] Print out in the file where the error was (may need a hashmap of a list of slices into the file contents for each line)
- [x] Parse ADTs (and also go through parsing again)
- [x] Parse function composition (`<>`)
- [x] Parse indent blocks
    - [x] Figure out how to not consume newline after ADT expr
- [x] Parse delta (`|>`)
- [x] Parse exponentiation
    - [x] Add parsing function
    - [x] Make sure to do an ASTKind too
- [ ] Write ASTs

### Symbol table
- [ ] Create symbol tree from file AST

### Typecheck
- [ ] Typecheck AST and symbol table

### Validate
- [ ] Do other validations (?)

### IR
- [ ] Write IR types
- [ ] Convert function symbol defintitions to IR lists
- [ ] Convert IR lists to control-flow graph with symbol versions
- [ ] Do optimizations on the control-flow graph

### Codegen
- [ ] Write the IR out to an output .c file

### Backend
- [ ] Call gcc on the .c file