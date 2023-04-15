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
- [ ] Write tests
- [ ] Add `not` keyword, remove !! operator
- [ ] For ambiguous infix/prefix operators, check if there's a space. Space means infix

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
- [x] Write ASTs
    - [ ] Write a pretty print and do tests!
- [ ] Parse +=, -=, *=, /=, %=, **=
- [ ] Parse `not` keyword, change !! to just !
- [ ] Abstract away a better peek() method
- [ ] Remove ASTKind, only have ASTData, it's okay to repeat some structs if needed
- [ ] Make Sum types a flat list rather than a tree
    - [ ] Perhaps do this for all binops, might allow for optimizations later, simplifies associativity
- [ ] Throw a parse error if there's a null index for an index binop
- [ ] Parse `slice[1..]` as a subslice and not a floating point literal

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
- [ ] Execute the output file

### Type inferrence

### Partially Applied Functions

### ADTs

### Optionals

### Error handling

### First-class types

### Refinement types

### Generic Type Unification

### Type classes

### Allocators

## Build System

### Runtime 'System' type