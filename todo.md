### Lexer
- [x] Lex out comments
- [x] Go through grammar and find all Token kinds there could be, list them in TokenKind
- [x] Be able to lex out any token type
- [x] Tokens should have spans
- [x] Remove unused token kinds
- [x] Add D_STAR token kind
    - [x] Add D_STAR to binaryOperators
    - [x] Add D_STAR to reprFromTokenKind()
    - [x] Add D_STAR_ASSIGN TokenKind, binaryOperators, reprFromTokenKind
- [x] Write tests
- [x] Add `not` keyword, remove !! operator
- [x] Properly handle allocator errors
- [x] Implement Spans
- [ ] Error if string (resp. character) reaches EOF before " (resp. ')
- [ ] Write negetive tests for errors

### Layout
- [x] Write tests

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
- [x] Parse `not` keyword, change !! to just !
- [x] Parse +=, -=, *=, /=, %=, **=
- [x] Abstract away a better peek() method
- [x] Throw a parse error if there's a null index for an index binop
- [x] Parse `slice[1..]` as a subslice and not a floating point literal
- [x] Properly handle allocator errors in {parser, ast}.zig
- [ ] Write a pretty print and do tests! (positive and negative)
- [ ] Top level declarations should require a newline

### Symbol table
- [x] Create symbol tree from file AST
- [x] Symbol table error on shadowing
    - [x] Implement lookup method for scopes
- [x] Make function decls also have a type
- [x] If symbol init is block, create a scope for it
- [x] Create symbols for function parameters
- [ ] WRITE TESTS! (positive and negative)

### Typecheck
- [ ] Typecheck AST and symbol table

### Validate
- [ ] Do other validations (?)

### Errors
- [ ] Add filename to Span, add file map

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