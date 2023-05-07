### Nits
- [ ] Rename `case` to `match`
- [ ] Standardize token, ast, ir *kind* naming convention
- [ ] Alphabetize type imports by the module, then by the type.
- [ ] Standardize the names of parameters, ie:
    - `token` for a Token
    - `ast` for an AST node
    - `def` for the def IR node of a SymbolVersion
    - `ir` for an arbitrary IR node
    - `symbver` for an arbitrary SymbolVersion
    - `maybe_x` for an optional variant of a type
- [ ] Errors should be capitalized, I guess


### Pipeline
- [ ] Errors should print lines
    - [x] Errors print to stderr instead of debug
    - [ ] Lexer fills lines array
    - [ ] Errors print line, caret
    - [ ] AST `printType` prints to stderr instead of debug
- [ ] `use backticks to make any text an identifier`
- [ ] Symbols def before use tree-walk
- [ ] lhs of assignment is lvalue validation tree-walk
- [ ] type inferrence, typeof, type checking
    - [ ] `typeof` prefix operator which returns type expression of expression
    - [ ] define `==` and `!=` operators for types, do at runtime
- [ ] default value to definitions without
    - [ ] `default` prefix operator, which takes a type and returns the default value for that type
- [ ] expect types to be `Type` type
- [ ] count defers in block tree-walk
- [ ] rewrite [op]= assignments
- [ ] symbol versioning/phi nodes
- [ ] immutability checking
- [ ] build system
    > Should be stateless, gosh dangit!
    > Read about philosophy of other build systems, what do users want/need to build Orng programs?
        > Maybe Orng programs don't require a build script, they can just do `import` and it's all good
            > Packages may need to include c-files/libraries. This should be documented somewhere. A *simple* build file is acceptable.
        > `import:(const path:String)`
        > `package:(const path:String)`
        > `extern:(const name: String, const T: Type)->T`
        > `externType:(const name: String, const backing: Type = ())->Type`
        > `cInclude:(const path: String)->(a tuple of the definitions)`
    - [ ] Specifies the entry function somehow
    - [ ] entry function takes a record of IO function pointers
    - [ ] run a C compiler on the output
    - [ ] be able to parse C headers
    - [ ] be able to include C source files before generated C file
    - [ ] be able to link static and dynamic libraries
    > How do 'packages' work? How **SHOULD** they work?
    - [ ] Optionally execute output executable after compiling
    - [ ] Externs
        > 'Primitive types' are just extern types defined in prelude
    > How to do exponentiation without libc?

### Features
- [ ] `defer`
- [ ] `continue`/`break`/`return`
- [ ] function calls
    - [ ] named arguments/fields
    - [ ] default parameters
    - [ ] nested functions/anon functions
- [ ] addresses
- [ ] tuples
    - [ ] type dependency DAG
        > Two product types are C-equivalent if they're field's types match as you go through the struct
        > Then, when you generate them, just do `struct struct_1 {int _1, int _2}`, which would match `(x: Int, y: Int)` and `(Int, Int)`
    - [ ] `.` select
    - [ ] dot-assign
    - [ ] `++` for concat
    - [ ] `--` for diff (?)
- [ ] arrays
    - [ ] index
    - [ ] index-assign
- [ ] slices
    - [ ] `[]` slice from array operator, with variants
    - [ ] subslices
    - [ ] array from slice? (like a dereference?)
        > How would the size work? It has to be compile-time known
- [ ] UTF8
    - [ ] string literals
        > NOT array/slice of characters. UTF8 encoding is variable width, so array/slice of Bytes!
        - [ ] Character escapes (`\n`, `\r`, `\t`, `\u<32 bit number literal>`)
        - [ ] Error on invalid escapes
    - [ ] Character literals
        - [ ] Character escapes (`\n`, `\r`, `\t`, `\u<32 bit number literal>`)
        - [ ] Error on invalid escapes
- [ ] Sum types
    - [ ] `||` for union
- [ ] optionals
    - `?` constructor
    - `.?` (or `some`?) value from optional
        > It's useful to have the error unwrap and optional unwrap be the same fixity
    - `orelse` coalesce
- [ ] errors
    - `catch`
    - `try`
    - `throw`
    - `errdefer`
    - inferred errors, error coerce
- [ ] unreachable
- [ ] optimization
    - [ ] Common sub expression elimination (AST)
    - [ ] Code motion (AST)
    - [ ] Unrolling (AST -> IR)
    - [ ] Constant fold (AST & IR)
    - [ ] Dead code elimination (IR)
        - [ ] Use-def analysis
    - [ ] Inlining (CFG)
    - [ ] Peephole (LIR/asm/C)
- [ ] pattern matching
    - [ ] product destructuring
    - [ ] sum-type destructuring
    - [ ] constant-equality checks
        > `let four = 4`
        > `let four, four = (4, 4) // huh...`
    - [ ] self-equality checks
        > `let x', x' = (3, 4) // maybe this causes a panic, like an assert`
        > should likely be shallow equality, otherwise that gets tricky...
    - [ ] `match` statement (rename from case)
- [ ] function programming stuff
    - [ ] composition
    - [ ] `|>` operator
    - [ ] `.>` operator
    - [ ] partial function application
- [ ] compile-time evaluation
    - [ ] first-class types based generics
    - [ ] if a function has all `const` arguments, evaluate at compile-time
- [ ] refinement types
- [ ] generic type unification
    > Identifiers that end in a `'` are considered free
    - [ ] error if an identifier contains a `'` in the middle of itself
- [ ] type classes / interfaces / traits
    - [ ] allocators
    - [ ] iterators & for loops
    - [ ] Eq, Ord, Num, Bits
    - [ ] derive