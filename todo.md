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
- [x] Error if string (resp. character) reaches EOF before " (resp. ')
- [ ] Write negetive tests for errors
- [ ] Reject invalid character literals

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
- [x] Top level declarations should require a newline
- [ ] Make exponentiation right-associative, higher precedence than `-`
- [ ] Support unicode characters somehow, and escapes with \
- [ ] Somehow parse hexadecimals with apostrophes

### Symbol table
- [x] Create symbol tree from file AST
- [x] Symbol table error on shadowing
    - [x] Implement lookup method for scopes
- [x] Make function decls also have a type
- [x] If symbol init is block, create a scope for it
- [x] Create symbols for function parameters
- [ ] WRITE TESTS! (positive and negative)
    - [ ] Positive, normal flow-through tests
    - [ ] Negative, error tests
- [ ] Symbols should likely know if they're immutable, constant, mutable, or a function (quadchotomy)
- [ ] Find the main function somehow
- [ ] Implement rust-style shadow rules

### Typecheck
- [ ] Typecheck AST and symbol table
- [ ] Symbols are properly type-inferrenced if their type is null
- [ ] Collect a dependency graph of product and sum types

### Misc. tree-walks
- [ ] Rewrite [op]= assignments
- [ ] Identifiers refer to valid, defined symbols
- [ ] Make sure non-mut symbols aren't mut'd

### Errors
- [ ] Add filename to Span, add file map

### IR
- [x] Write IR types
- [ ] Convert function symbol defintitions to IR lists
    - [x] identifier
    - [x] int
    - [x] char
    - [x] float
    - [x] string
    - [x] blocks
    - [x] declarations
    - [ ] assignment
        - [x] ident-assign
        - [x] deref-assign
        - [ ] dot-assign (defer to after tuples)
        - [ ] index-assign (defer to after arrays)
    - [ ] unary operators
        - [x] not
        - [x] -
        - [x] ^
        - [ ] ? (defer to after optionals)
        - [ ] .? (defer to after optionals)
        - [ ] try (defer to after errors)
        - [ ] ! (defer to after errors)
    - [ ] binary operators
        - [x] and
        - [x] or
        - [x] !=
        - [x] ==
        - [x] >
        - [x] <
        - [x] >=
        - [x] <=
        - [x] +
        - [x] -
        - [x] *
        - [x] /
        - [x] %
        - [x] **
        - [ ] <> (fancy call in disguise, rewrite pass?)
        - [ ] .> (fancy call in disguise, rewrite pass?)
        - [ ] . (defer to after tuples)
        - [ ] ++ (defer to after tuples)
        - [ ] -- (defer to after tuples)
        - [ ] index (defer to after arrays)
        - [ ] || (defer to after sum types)
        - [ ] orelse (defer to after optionals)
        - [ ] catch (defer to after errors)
        - [ ] ! (defer to after errors)
    - [x] call
    - [x] addrOf
    - [x] if
    - [x] cond
    - [x] while
    - [ ] defer (defer (lol) to after tree-walk)
    - [ ] return (defer to after defers)
    - [ ] break (defer to after defers)
    - [ ] continue (defer to after defers)
    - [ ] namedArg (maybe this is subsumed by a tree-walk on a call)
    - [ ] inferred members (again, likely subsumed by a tree-walk on a product expression)
    - [ ] annotation (this is just a type)
    - [ ] sliceOf (defer to after arrays)
    - [ ] subSlice (defer to after arrays)
    - [ ] for (defer to after arrays)
    - [ ] fnDecl (defer to partially applied functions)
    - [ ] throw (defer to after errors)
    - [ ] errdefer (defer to after errors)
    - [ ] case (defer to after pattern matching)
- [ ] Write a defaultValue function which generates a default value IR for a given type
- [ ] Do optimizations on the control-flow graph
- [ ] Version symbols

### Codegen
- [ ] Handle all types of IR
- [ ] Be able to print types (requires a type depen graph)
- [ ] Print the retval of a function
    - [ ] (when types are intoduced): if the return type of a function is void, don't do this ^

### Backend
- [ ] Call gcc on the .c file
- [ ] Execute the output file

### Integration Testing
- [ ] Write small integration tests for each "feature" of the language
- [ ] Fuzz tests
    - Generate random (syntactically correct) Orng programs; attempt to compile
        | compiles, no C err => generate new program
        | compiler err       => generate new program
        | compiles, C err    => either bug in compiler, or need a validation check
        | panic              => bug in compiler
    - Do literally a billion fuzz tests


### Time wasting
- [ ] Standardize token, ast, ir *kind* naming convention
- [ ] Alphabetize type imports by the module, then by the type.
- [ ] Standardize the names of parameters, ie:
    - `token` for a Token
    - `ast` for an AST node
    - `def` for the def IR node of a SymbolVersion
    - `ir` for an arbitrary IR node
    - `symbver` for an arbitrary SymbolVersion
    - `maybe_x` for an optional variant of a type

### Fancy features
- [ ] Partially Applied Functions
- [ ] ADTs
- [ ] Optionals
- [ ] Error handling
- [ ] First-class types
- [ ] Refinement types
- [ ] Generic Type Unification
- [ ] Type `class`es
- [ ] Allocators
- [ ] Build System
- [ ] Runtime 'System' type