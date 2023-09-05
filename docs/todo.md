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
- [x] Replace `ast.<union member>.common.token` with `ast.get_token()` for ASTs outside of ast.zig
- [x] Replace `ast.<union member>.common` with `ast.get_common()` for ASTs outside of ast.zig
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
- [ ] Ignore empty files all together
- [ ] exclude files or directories with a prefix `~`

### In-House rdgen
- [ ] Written in Zig
- [ ] Parses an LL(1) grammar
- [ ] Rejects if grammar is not LL(1) ("ambiguity" but not exactly)
- [ ] Generates JSON files of example programs, with identifiers, numbers, etc replaced with random values

### Language Features
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
- [x] more compile errors
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
    - [x] explicit discarding with `_`
        - [x] error if discard when it's used
    - [x] static index out of bounds
    - [x] dynamic index out of bounds
    - [x] static slice lower <= upper
    - [x] dynamic slice lower <= upper
    - [x] static checked arithmetic (actually easy since optimizer already does these automatically)
    - [x] static union tag check
    - [x] dynaminc union tag check
- [ ] pattern matching
    - [x] `let` product destructuring
        - [x] `mut` applies before symbols
        - [x] Identifiers define new symbols, having a name repeat is a redefinition error
        - [x] recursive pattern matching
        - [x] `_` to ignore
            - [x] error if `_` is marked as `mut` or `const`
    - [x] assign product destructuring
        ```
        let (mut x, mut y): (Int, Int) = {4, 5}
        (x, y) = {y, x}
        ```
        - [x] `_` to ignore
    - [ ] `match` expression
        - [x] Value matching
            > expr equals value
            - [x] compile-time check that value is same type as expr
        - [ ] Block values
        - [x] Symbol capture
            > infallible match, declare symbol before rhs
        - [x] Product destructuring
            > all of terms match
            - [x] check product arity at compile-time, must match
        - [x] Sum destructuring
            > tag of expr matches tag of pattern
            - [x] check that expr is of the same sum type at compile-time
        - [ ] Inferred members
        - [ ] Injection
            > lhs sum matches, rhs pattern matches
            - [ ] validate injection is valid for type, of course
        - [ ] `_` to ignore value 
        - [ ] Error (warning?) if match is not total (can maybe do for sums, but is undecidable for general values of course)
- [ ] new optimizations
    - [ ] measure source-to-output ratio
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
        > OR: be able to tell that, say, src1 symbver is not updated between it's last update and now. Tough to do with BBs I think
    - [ ] ! inlining
    - [ ] ? loop invariant lifting
    - [ ] temporary combining (basically register allocation) (do this one last!)
- [ ] function programming stuff
    - [x] immutability
    - [ ] composition using `<>`
    - [ ] prepend `>>`
    - [ ] optional prepend `?>`
- [ ] compile-time evaluation
    - [ ] `const` is an annotation and symbol modifier
    - [ ] eval type annotations
    - [ ] eval default inits
    - [ ] eval symbol defs defined as const
    - [ ] expressions marked `comptime`
        - [ ] block
        - [ ] if
        - [ ] case
        - [ ] decl
        - [ ] defer
    - [ ] eval array sizes
    - [ ] first-class types based generics (stamp)
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
        - [ ] **IMPORTANT** indexes need to make their lhs lvalues in IR iff debug mode is off
- [ ] refinement types
    - [ ] `where` which checks at runtime if a condition is true, panics if it's not
    - [ ] `==>` implies boolean operator might be handy
        > `ast^ == .match ==> mappings_have_rhs(ast)`
    - [ ] `where comptime` checks a condition at compiletime. If a condition is false at compile-time, error
- [ ] generic type unification
    > Identifiers that end in a `'` are considered free
    - [ ] error if an identifier contains a `'` in the middle of itself
    - [ ] error if identifier is defined with `let` or `match` with apostrophe
- [ ] type classes / interfaces / traits
    - [ ] `lhs<:rhs` operator with lhs being a capture pattern and rhs being a class
    - [ ] allocators
    - [ ] iterators & for loops
        - [ ] multi-loops, ranges like zig
    - [ ] Eq, Ord, Num, Bits, Convertible
        - [ ] Inlining will hopefully remove vtable lookups for things like integer math, which would stink!
        - [ ] Default for arithmetic should be checked arithmetic
            > Each numeric type knows it's limits, so it makes more sense to implement checking in the trait
    - [ ] derive
    - [ ] dot prepend `.>`
    - [ ] `id` function in prelude
    - [ ] wrap and saturate math operators (not too important tbh)

### Standard Library
- [ ] Collections
    - [ ] List
        - [ ] `map`, `filter`, `reduce`
    - [ ] HashMap
- [ ] IO
- [ ] Debug (?)
- [ ] Memory
- [ ] Strings
    - [ ] Ascii and Unicode stuff
- [ ] Testing
- [ ] Process
- [ ] Threads

### Language Server
- [ ] Highlighting
    - [ ] Goto definition
    - [ ] Show types
- [ ] Formatter
    - [ ] Takes in code and formats it
- [ ] Linter
    - [ ] Warn if line is too long (140, after being whitespace stripped, not including comments, is excessive)
    - [ ] Warn about code such as `y, x = x, y` which is parsed as `y, (x = x), y`
        > Warn when non-unit expressions are in the middle of a block?
- [ ] Documentation generator
    - [ ] `///` Comment blocks are documentation
    - [ ] `\<attribute>` to mark attributes
    - [ ] error if attributes aren't documented or if they are but aren't present in the function