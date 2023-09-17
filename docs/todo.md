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
- [ ] Errors should be given a type name
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

### Small fixes
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
- [ ] Comparison operators should not be chainable
- [x] Parens (and only parens) should be one 'line', like in Python

### Testing
- [x] test.orng should detect which folders are in tests/integration, and create those folders in tests/integration/build, rather than it being hard-coded.
- [x] find out if GCC supports UBSan! enable it
- [x] allow more than one command line argument
- [ ] Ignore empty files all together
- [ ] exclude files or directories with a prefix `~`
- [ ] `count` instruction which just counts the number of .orng files

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
        - [ ] 
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
    - [x] explicit discarding with `_`
        - [x] error if discard when it's used
    - [x] static index out of bounds
    - [x] dynamic index out of bounds
    - [x] static slice lower <= upper
    - [x] dynamic slice lower <= upper
    - [x] static checked arithmetic (actually easy since optimizer already does these automatically)
    - [x] static union tag check
    - [x] dynaminc union tag check
    - [ ] sanitize call stack lines to escape " and \
    - [ ] suggest the most similar visible identifier when an unknown identifier is used
    - [ ] Make Arithmetic (operators) Great, Allegedly
        - [ ] Types on both sides should be equal. Expect proper type (No subtyping!)
            - [ ] Most binops need types to be *identical*
            - [ ] Comparison operators only need types to be *assignable*
            - [ ] Define representability too for constants
        - [ ] Define for Int8...Int64, Float32, Float64, Byte...Word64
        - [ ] Add UB checking
- [x] pattern matching
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
    - [x] `match` expression
        - [x] Value matching
            > expr equals value
            - [x] compile-time check that value is same type as expr
        - [x] Block values
        - [x] Symbol capture
            > infallible match, declare symbol before rhs
        - [x] Product destructuring
            > all of terms match
            - [x] check product arity at compile-time, must match
        - [x] Sum destructuring
            > tag of expr matches tag of pattern
            - [x] check that expr is of the same sum type at compile-time
        - [x] Inferred members
        - [x] Injection
            > lhs sum matches, rhs pattern matches
            - [x] validate injection is valid for type, of course
            - [x] fix injection cruft with domainOf
        - [x] Fix syntax with nested matches
        - [x] `_` to ignore value 
        - [x] Error if match is not total
- [ ] new optimizations
    - [x] measure source-to-output ratio
    - [x] string literals should be indexed at compile-time, dont do runtime check
    - [x] remove ifndefs
    - [x] don't generate section comments if the section is empty
    - [x] don't generate the label for a basic block if a CFG only has one basic block
    - [x] If a temporary is only used once, just inline it's definition with where it's used
        > Will require parens if the surrounding def precedence is higher
    - [x] Panics shouldn't jump, call to panic function instead of just for loop
    - [x] Try and print lvaues better
        - [x] `*&x` is just `x`
        - [x] Perhaps do precedence stuff too. Too many parenthesis!
        - [x] `+0` in lvalue for indexing is kinda dumb
    - [x] expand_types should only allocate if anything changes
    - [x] set retval to poison, don't just return from validateAST
    - [x] identity optimizations (adding 0, multiplying by 1, etc..)
        > These aren't always reduced, especially if the other side is variable
    - [x] multiplying by 0, 1 mod x
    - [x] avoid struct copies on select
    - [x] output BB breadth-first, use a queue, do not use recursion
        - [x] don't `goto` BB if it's the next one in the queue
    - [x] replace `x != 0` with `x`, `x == 0` with `!x`
    - [x] copy propagate `loadSymbol` IR
    - [x] instead of checking if def is null, do `what is the most recent definition in this bb`
        > *might* be able to add a list of predecessors to BBs, check list of BBs for defs too, if they agree on a value
        > Currently theres a discontinuity with how the IR works and how codegen works.
        > IR is in SSA form, whereas C is flattened so that all symbvers of a same symbol share a same variable
        > This is the preferable way to gen C code, but it leads to tricky situations one must be careful of
    - [x] better select optimizations
    - [ ] local value numbering (?)
    - [ ] partial redundancy elimination
    - [ ] induction variable identification/unrolling (this is a good one if possible)
        - [ ] loop invariant lifting
    - [ ] ! inlining
        > Incredibly important optimization
    - [ ] ? pointer aliasing analysis (should squash most whitebox testing)
        > At the *very* least, add a flag to symbols to see if they're aliased with & at all
        > OR: be able to tell that, say, src1 symbver is not updated between it's last update and now. Tough to do with BBs I think
    - [ ] Codegen optimizations (less important)
        - [x] if a branch depends on a symbver with a `negate` def IR, plunge `negate` and flip labels
        - [ ] `derefCopy` should elide `*&`s
        - [ ] `printSymbolVersion` should collapse addrOf IR, etc
        - [ ] register allocation (but only if it's easy)
    - [ ] fuzz with updated `fuzz.ebnf` to force a proper main function
- [ ] function programming stuff
    - [x] immutability
    - [ ] composition using `<>`
    - [ ] prepend `>>`
    - [ ] optional prepend `?>`
- [ ] compile-time evaluation
    > Switch to Karta just to get a feel for interpreters
    > Validate, IR, Optimize. Don't codegen, interpret!
    - [x] `const` is an annotation and symbol modifier
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
    - [ ] should be able to index heterogenous tuples with a comptime value
        > Is this undecidable?
    - [ ] first-class types based generics (stamp)
    - [ ] `typeof` prefix operator which returns type expression of expression
    - [ ] define `==` and `!=` operators for types, do at comptime
    - [ ] `default` prefix operator, which takes a type and returns the default value for that type
    - [ ] 
- [ ] build system (built upon compile-time evaluation)
    - [ ] **!IMPORTANT!** Should output .c and .h pair for each .orng file. Track dependencies, and only run gcc on modified files and the files that depend* on modified files, to produce .o files which should be linked.
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
    - [ ] Option to generate header and source file
    - [ ] Options to add C system headers and regular header directories
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
    > Do not use for operator overloading!
    - [ ] `lhs<:rhs` operator with lhs being a capture pattern and rhs being a class
    - [ ] allocators
    - [ ] iterators & for loops
        - [ ] multi-loops, ranges like zig
    - [ ] Eq, Ord, Num, Bits, Convertible
    - [ ] derive
    - [ ] dot prepend `.>`
    - [ ] `id` function in prelude

### Standard Library
- [ ] Collections
    - [ ] List
        - [ ] `map`, `filter`, `reduce`
    - [ ] HashMap
- [ ] IO
- [ ] Debug (?)
- [ ] Memory
- [ ] Strings
    - [ ] String Buffer
    - [ ] Ascii and Unicode stuff
- [ ] Testing
- [ ] Process
- [ ] Threads

### Language Server
- [ ] Highlighting
- [ ] Goto definition
- [ ] Show types when you hover
- [ ] Show types when they're inferred
- [ ] Show error messages
- [ ] Formatter
    - [ ] Takes in code and formats it
- [ ] Linter
    - [ ] Warn if line is too long (140, after being whitespace stripped, not including comments, is excessive)
    - [ ] Warn about code such as `y, x = x, y` which is parsed as `y, (x = x), y`
        > Warn when non-unit expressions are in the middle of a block?
    - [ ] Warn if identifier is not in the right style
- [ ] Documentation generator
    - [ ] `///` Comment blocks are documentation
    - [ ] `\<attribute>` to mark attributes
    - [ ] error if attributes aren't documented or if they are but aren't present in the function

### Wishlist
- [ ] Make matches have to be exhaustive over all product types too. Make it UB to not match. Don't return optional value for matches
    > Generate all possible values (treat Ints and Floats as unit)
    > Feed values to patterns in order (ignore {block} patterns). 
    > If a pattern accepts, mark pattern, next value. 
    > If no patterns accept, value is witness of a value not matched by match, emit error.
    > After, if a pattern is not marked, it is a useless pattern, emit error.
    > Just not sure on the details. How are values represented? How are they generated? How are they accepted?
    > There's a better way to do this with matrices, but I didn't understand the papers.