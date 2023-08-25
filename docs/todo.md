### Nits
<!-- These are good first-issues for those looking to contribute -->
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
- [ ] Replace `ast.<union member>.common.token` with `ast.get_token()` for ASTs outside of ast.zig
- [ ] Replace `ast.<union member>.common` with `ast.get_common()` for ASTs outside of ast.zig
- [ ] Organize functions declarations in prefix order
- [ ] Order switches on enums to the order they were declared in
- [ ] Comments on each function and struct field
- [ ] Change some while loops with counter to enhanced for loops
- [ ] Go through files and find TODO comments
- [ ] All inits have a corresponding deinit
- [ ] Plot input orng sloc against output c sloc, check to see if there's any outlier, analyze...
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
- [x] != should actually probably be chainable

### Testing
- [x] test.orng should detect which folders are in tests/integration, and create those folders in tests/integration/build, rather than it being hard-coded.
- [x] find out if GCC supports UBSan! enable it
- [x] allow more than one command line argument

### In-House rdgen
- [ ] Written in Zig
- [ ] Parses an LL(1) grammar
- [ ] Rejects if grammar is not LL(1) ("ambiguity" but not exactly)
- [ ] Generates JSON files of example programs, with identifiers, numbers, etc replaced with random values

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
- [x] tuples
    - [x] type dependency DAG
        > Two product types are C-equivalent if they're field's types match as you go through the struct
        > Then, when you generate them, just do `struct struct_1 {int _1, int _2}`, which would match `(x: Int, y: Int)` and `(Int, Int)`
    - [x] `.` select
    - [x] select and loadStruct optimizations
    - [x] dot-assign
        - [x] validate dot lvalue
    - [x] default fields
    - [x] named fields
        - [x] change grammar to use assignments instead of `<-`. assignments have void type anyway, probably no confusion with `==`
    - [x] pointer to tuple, tuple of pointers, select deref
    - [x] should not be able to mix annot and non-annot tuples
- [x] arrays
    - [x] index
    - [x] index-assign
        - [x] validate index lvalue
    - [x] when deref copy prop op is enabled, pemdas.orng emits type error
- [x] slices
    - [x] `[]` slice from array operator, with variants
    - [x] subslices
    - [x] sublices with inferred lower bound (0)
    - [x] sublices with inferred upper bound (length)
- [ ] UTF8
    - [x] Byte type
    - [ ] string literals
        > NOT array/slice of characters. UTF8 encoding is variable width, so array/slice of Bytes!
        - [x] Character escapes (`\n`, `\r`, `\t`, `\x<hex byte>`)
        - [ ] `\u<unicode code point, hex>`
            > Incredibly non-trivial
        - [x] Error on invalid escapes (this should happen at lex-time)
        - [x] `String` type in prelude, which is an alias for `[]Byte` (immutable byte array)
        > TBD: `String_Buffer` type/module in stdlib which allows for manipulation of mutable strings
    - [ ] Character literals
        - [x] Character escapes (`\n`, `\r`, `\t`)
        - [ ] `\u<unicode code point, hex>`
            > Seems non-trivial
        - [x] Error on invalid escapes
        - [x] Error if character literal contains more than one character
- [x] Sum types
    - [x] `||` for union
    - [x] Optimize `double.orng`: use-def analysis is buggy for selects, select-copy elimination opt isn't working
- [x] optionals
    - [x] `?` constructor
    - [x] remove `fromOptional`
    - [x] `orelse` coalesce
    - [x] control-flow operators return optional if else isn't present
- [ ] errors
    - [x] binary `!`
    - [x] `catch`
    - [x] `errdefer`
    - [x] `try`
    - [ ] inferred errors
        > Investigate. Seems problematic to implement well
    - [x] remove `throw`
- [ ] more compile errors
    - [x] negative tests (coarse grained, just a bunch of files that should fail... for some reason or another. Would be too chaotic to mandate which error or where in source the error should occur)
        - [x] negative tests up to type checking
        - [x] `.poison` AST node which represents apart of the program with errors that should not be re-validated
        - [x] negative tests beyond type checking
        - [x] fix spans being inconsistently off (perhaps make it so that the whole expression is highlighted)
        > 'positive' test cases compile (panics are 'positive'!). 'negative' test cases do not compile!
    - [x] unreachable
        - [x] stack traces
        - [x] go back and add optional `case`, with `| else => unreachable` clauses
    - [x] proper fuzz tests
        > If a program ever compiles, make a log of what the orng program was
        > Fuzz testing will unfortunately crash if compiler crashes (maybe can be de-coupled?), so store latest orng program somewhere too
    - [x] default values
    - [ ] explicit discarding with `_`
    - [ ] static index out of bounds
    - [ ] dynamic index out of bounds
    - [ ] static slice lower > greater
    - [ ] dynamic slice lower > greater
    - [ ] static checked arithmetic
    - [ ] dynamic checked arithmetic
    - [ ] static divide by zero
    - [ ] dynamic divide by zero
    - [ ] static union tag check
    - [ ] dynaminc union tag check
    - [ ] compile-time const check
- [ ] pattern matching
    - [ ] product destructuring
    - [ ] sum-type destructuring
    - [ ] constant-equality checks
        > `let four = 4`
        > `let four, four = (4, 4) // huh...`
    - [ ] self-equality checks
        > `let x', x' = (3, 4) // maybe this causes a panic, like an assert`
        > should likely be shallow equality, otherwise that gets tricky...
    - [ ] `match` statement
- [ ] new optimizations
    - [ ] expand_types should only allocate if anything changes
    - [ ] identity optimizations (adding 0, multiplying by 1, etc..)
    - [x] avoid struct copies on select
    - [ ] local value numbering
    - [ ] partial redundancy elimination
    - [ ] redundancy elimination
    - [ ] induction variable identification/unrolling (this is a good one if possible)
    - [ ] better select optimizations
    - [ ] ? pointer aliasing analysis (should squash most whitebox testing)
        > At the *very* least, add a flag to symbols to see if they're aliased with & at all
    - [ ] ! inlining
    - [ ] ? loop invariant lifting
    - [ ] temporary combining (basically register allocation) (do this one last!)
- [ ] function programming stuff
    - [x] immutability
    - [ ] composition using `<>`
    - [ ] prepend `>>`
    - [ ] optional prepend `?>`
- [ ] compile-time evaluation
    - [ ] `comptime` expression, evaluated at compile time
        - [ ] block
        - [ ] if
        - [ ] case
        - [ ] decl
    - [ ] `const` should actually likely be a type modifier
        > Should it actually? `const T` can represent all the values that `T` can, there's just an extra contraint that those values be known at compile-time. Idk if that's really a type.
    - [ ] array sizes are evaluated at compile-time
    - [ ] first-class types based generics
    - [ ] if a function has all `const` arguments, evaluate at compile-time 
    - [ ] `typeof` prefix operator which returns type expression of expression
    - [ ] define `==` and `!=` operators for types, do at comptime
    - [ ] `default` prefix operator, which takes a type and returns the default value for that type
- [ ] build system (built upon compile-time evaluation)
    > Should be stateless, gosh dangit!
    > Read about philosophy of other build systems, what do users want/need to build Orng programs?
        > `orng build ?.orng` command takes in a file `?.orng` that has a `build` constant, which has fields for 
        > `fn import(const path:String) -> (tuple of definitions in module)`
        > `fn package(path: const String) -> (tuple of modules in package)`
        > `fn extern(name: const String, T: Type) -> T`
        > `fn extern_type(name: const String, backing: Type = ()) -> Type`
        > `fn c_include(path: const String) -> (a tuple of the definitions)`
    - [ ] `pub` keyword
    - [ ] Specifies the entry function somehow
    - [ ] entry function takes a record of IO function pointers
    - [ ] run a C compiler on the output
    - [ ] be able to parse C headers
    - [ ] be able to include C source files before generated C file
    - [ ] be able to link static and dynamic libraries
    > How do 'packages' work? How **SHOULD** they work?
    - [ ] Optionally execute output executable after compiling
    - [ ] Externs
    - [ ] Prelude with:
        - [ ] Each primitive type as an extern type
        - [ ] `is_null()`
    > How to do exponentiation without libc?
    - [ ] debug mode which enables checks for UB
- [ ] refinement types
    - [ ] `where` should only check for things at runtime, unless specified with `where const`
- [ ] generic type unification
    > Identifiers that end in a `'` are considered free
    - [ ] error if an identifier contains a `'` in the middle of itself
- [ ] type classes / interfaces / traits
    - [ ] allocators
    - [ ] iterators & for loops
        - [ ] multi-loops, ranges like zig
    - [ ] Eq, Ord, Num, Bits, Convertible
        - [ ] Inlining will hopefully remove vtable lookups for things like integer math, which would stink!
    - [ ] derive
    - [ ] dot prepend `.>`