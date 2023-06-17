### Nits
- [x] Rename `case` to `match`
- [ ] Find copy-pasted code and tidy it up
- [ ] Standardize token, ast, ir *kind* naming convention
- [ ] Alphabetize type imports by the module, then by the type.
- [ ] Standardize the names of parameters, ie:
    - `token` for a Token
    - `ast` for an AST node
    - `def` for the def IR node of a SymbolVersion
    - `ir` for an arbitrary IR node
    - `symbver` for an arbitrary SymbolVersion
    - `maybe_x` for an optional variant of a type
- [ ] Errors should be capitalized
- [ ] Everything should be snake_case
- [ ] Replace `.common` with `.getCommon` for ASTs outside of ast.zig
- [ ] Organize functions declarations in prefix order
- [ ] Order switches on enums to the order they were declared in
- [ ] Comments on each function and struct field
- [ ] Change some while loops to enhanced for dyadic loops
- [ ] All inits have a corresponding deinit
- [ ] Find some code not covered and write an integration test for it

### Pipeline
- [x] Errors should print lines
    - [x] Errors print to stderr instead of debug
    - [x] Lexer fills lines array
    - [x] Errors print line, caret
    - [x] AST `printType` prints to stderr instead of debug
- [x] Symbols def before use tree-walk
- [x] `cond` has at least one mapping with a rhs
- [x] lhs of assignment is lvalue validation tree-walk
- [x] expect types to be `Type` type
- [x] type inferrence, typeof, type checking
    - [x] typeOf function
        - [x] generic `_type` field for ASTs, typeOf checks if it is null, if it is, constructs the type, sets the field. otherwise returns field
- [x] immutability checking
- [x] Redo symbol versions, should probably just be symbols
- [x] rewrite [op]= assignments

### Features
- [x] addresses
    - [x] addr-of operator
    - [x] dereference operator
        - [x] validate address type
        - [x] lvalue
    - [x] codegen pointer types
    - [x] deref copy
    - [x] `&mut` and validation (also find a way to validate assigning to mut symbols, though that's technically different)
- [x] basic optimizations
    - [x] version symbols
    - [x] Constant fold
    - [x] Dead code elimination
    - [x] If a BB is just a branch on a phi parameter, and the argument is a known value, branch to whichever BB would have been branched to  
- [x] `defer`
    - [x] count defers in block tree-walk
- [x] `continue`/`break`/`return`
- [x] function calls
    - [x] parameters
    - [x] anon functions
    - [x] nested functions
    - [x] mut function parameters
    - [x] function call arity/type validation
    - [x] collect function types in program struct, generate typedefs
    - [x] default parameters
    - [x] named arguments
- [ ] tuples
    - [x] type dependency DAG
        > Two product types are C-equivalent if they're field's types match as you go through the struct
        > Then, when you generate them, just do `struct struct_1 {int _1, int _2}`, which would match `(x: Int, y: Int)` and `(Int, Int)`
    - [x] `.` select
    - [x] select and loadStruct optimizations
    - [x] dot-assign
        - [x] validate dot lvalue
    - [x] default fields
    - [x] named fields
        - [ ] change grammar to use assignments instead of `<-`. assignments have void type anyway, probably no confusion with `==`
    - [x] pointer to tuple, tuple of pointers, select deref
    - [x] should not be able to mix annot and non-annot tuples
    - [ ] `++` for concat
    - [ ] `--` for diff (?)
- [ ] arrays
    - [ ] index
    - [ ] index-assign
        - [ ] validate index lvalue
- [ ] slices
    - [ ] `[]` slice from array operator, with variants
    - [ ] subslices
    - [ ] array from slice? (like a dereference?)
        > How would the size work? It has to be compile-time known
    > It would be neat if slices had a capacity, so they could be used like lists
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
    - [ ] `?` constructor
    - [ ] `.?` (or `some`?) value from optional
        > It's useful to have the error unwrap and optional unwrap be the same fixity
    - [ ] `orelse` coalesce
    - [ ] control-flow operators return optional if else isn't present
- [ ] errors
    - `catch`
    - `.!`
    - `throw` (maybe remove!)
    - `errdefer`
    - inferred errors, error coerce
- [ ] unreachable
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
- [ ] new optimizations
    - [ ] identity optimizations (adding 0, multiplying by 1, etc..)
    - [ ] pointer aliasing analysis
    - [ ] avoid struct copies on select
    - [ ] temporary combining (basically register allocation)
    - [ ] local value numbering
    - [ ] partial redundancy elimination
    - [ ] redundancy elimination
    - [ ] induction variable identification/unrolling
    - [ ] loop invariant lifting
    - [ ] inlining
- [ ] function programming stuff
    - [ ] `|>` operator
    - [x] immutability
    - [ ] composition using `<>`
    - [ ] partial function application `>>`
- [ ] compile-time evaluation
    - [ ] `comptime` expression, evaluated at compile time
    - [ ] array sizes are evaluated at compile-time
    - [ ] first-class types based generics
    - [ ] if a function has all `const` arguments, evaluate at compile-time 
    - [ ] `typeof` prefix operator which returns type expression of expression
    - [ ] define `==` and `!=` operators for types, do at comptime
    - [ ] `default` prefix operator, which takes a type and returns the default value for that type
- [ ] build system (built upon compile-time evaluation)
    > Should be stateless, gosh dangit!
    > Read about philosophy of other build systems, what do users want/need to build Orng programs?
        > Maybe Orng programs don't require a build script, they can just do `import` and it's all good
            > Packages may need to include c-files/libraries. This should be documented somewhere. A *simple* build file is acceptable.
        > `import:(const path:String)`
        > `package:(const path:String)`
        > `extern:(const name: String, const T: Type)->T`
        > `extern_type:(const name: String, const backing: Type = ())->Type`
        > `c_include:(const path: String)->(a tuple of the definitions)`
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
- [ ] refinement types
- [ ] generic type unification
    > Identifiers that end in a `'` are considered free
    - [ ] error if an identifier contains a `'` in the middle of itself
- [ ] type classes / interfaces / traits
    - [ ] allocators
    - [ ] iterators & for loops
        - [ ] multi-loops, ranges like zig
    - [ ] Eq, Ord, Num, Bits
    - [ ] derive

### Rationales
- Can't do `backtick identifiers`, because it's difficult to generate them out to C. You could have a map in each scope from the backtick name to a generated name. I just don't think its worth it at the moment.