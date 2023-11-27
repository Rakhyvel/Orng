### Nits
<!-- These are good first-issues for those looking to contribute -->
- [x] Rename `case` to `match`
- [ ] Find copy-pasted code and tidy it up
- [ ] Standardize token, ast, ir *kind* naming convention
- [ ] Alphabetize type imports by the module, then by the type.
- [ ] Standardize the names of parameters, ie:
    - `const <file>_ = @import("<file>.zig")` for zig files
    - `token` for a Tokens
    - `ast` for an AST nodes
    - `def` for the def IR node of a SymbolVersions
    - `ir` for an arbitrary IR node
    - `symbver` for an arbitrary SymbolVersion
    - `maybe_x` for an optional variant of a type
- [ ] Errors should be given a type name
- [ ] Errors should be capitalized
- [ ] Everything should be snake_case
    - [ ] Token Kinds should be snake_case, prefer not to use abbreviations
- [x] Replace `ast.<union member>.common.token` with `ast.get_token()` for ASTs outside of ast.zig
- [x] Replace `ast.<union member>.common` with `ast.get_common()` for ASTs outside of ast.zig
- [ ] Organize functions declarations in BFS order
- [ ] Order switches on enums to the order they were declared in
    - [ ] Order enums better too
- [ ] Comments on each function and struct field
- [ ] *probably* should only be one struct per file
- [ ] Change some while loops with counter to enhanced for loops
- [ ] See if things *really* need to be marked `pub`
- [ ] Go through files and find TODO comments
- [ ] Maybe have some fields be private, when they make sense
- [x] All inits have a corresponding deinit
- [x] Plot input orng sloc against output c sloc, check to see if there's any outlier, analyze...
- [ ] Find some code not covered and write an integration test for it

### Misc.
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
- [x] Comparison operators should not be chainable
- [x] Parens (and only parens) should be one 'line', like in Python
- [x] Remove `'` from integer and identifier token. Replace with `_` for integers, disallow for identifiers.
- [x] Require named fields/args to have `.`
- [x] Enforce naming convetions
    - [x] Must be snake case
        <!-- `([A-Z]*[a-z0-9]*_)*[A-Z]*[a-z0-9]*`
    - [x] Cannot define names that begin with `_` outside of prelude
    - [x] Types, traits, and functions that return types must be capitalized. Nothing else may be.
- [x] Make modulo not chainable (perhaps even replace it with `mod` and `rem` prelude functions)
- [x] Make it so that calls take in a list, not necessarily a product, so you can do something like this: `f((1, 2, 3))`
- [x] Adopt Go's newline insertion rules
- [x] Allow trailing commas in parenthesis (`, nl )` => `nl )`)
- [x] Create a builtin module which contains info about builtin types
    - [x] Grep for every instance of `Int8` or something, extract that info to a file
- [x] Fix camelCase detector (post-check, either all letters are capped, or just first of block)
- [ ] If a mismatch type error is produced by a control-structure where the only difference is that its optional, suggest adding an `else`
- [ ] Error if a symbol is marked mut when it isn't muted
- [x] 1-tuple, 1-sum
- [x] Equality of products is just equality of all members in a product. Same with slices, strings, etc
    - [x] Addresses are equalable
    - [ ] tuple not-equal
- [ ] "dependency injection" to remove error/allocator arguments
- [ ] "packaging" to remove label arguments, possibly something else too
- [x] Some function call lines are prepended and then popped before function call
- [x] IRs should use L_Values for sources too (its not harder to optimize btw)
- [ ] Figure out how to do lints before GCC does

### Testing
- [x] test.orng should detect which folders are in tests/integration, and create those folders in tests/integration/build, rather than it being hard-coded.
- [x] find out if GCC supports UBSan! enable it
- [x] allow more than one command line argument
- [x] `count` command which just counts the number of .orng files
- [x] Enable coverage for subdirectories of integration

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
    - [x] slice literals
- [x] UTF8
    - [x] Byte type
    - [x] string literals
        > NOT array/slice of characters. UTF8 encoding is variable width, so array/slice of Bytes!
        - [x] Character escapes (`\n`, `\r`, `\t`, `\x<hex byte>`)
        - [x] Error on invalid escapes (this should happen at lex-time)
        - [x] `String` type in prelude, which is an alias for `[]Byte` (immutable byte array)
        - [x] multiline string literals
    - [x] Character literals
        - [x] Character escapes (`\n`, `\r`, `\t`)
        - [x] Error on invalid escapes
        - [x] Error if character literal contains more than one character
- [ ] Sum types
    - [x] `||` for union
    - [x] Optimize `double.orng`: use-def analysis is buggy for selects, select-copy elimination opt isn't working
    - [x] equality on sum type values
    - [ ] consider a different inject syntax, maybe even bite the bullet with a call-like syntax
    - [ ] Builtin-function (?) to get tag name as string from sum
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
        - [ ] Add convenience functions for sums to get the `ok` annotation from an error, instead of indexing the sum directly
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
        - [x] error if function parameter is not used
        - [x] error if the result from a call is not used
    - [x] static index out of bounds
    - [x] dynamic index out of bounds
    - [x] static slice lower <= upper
    - [x] dynamic slice lower <= upper
    - [x] static checked arithmetic (actually easy since optimizer already does these automatically)
    - [x] static union tag check
    - [x] dynaminc union tag check
    - [x] sanitize call stack lines to escape " and \
    - [x] suggest the most similar visible identifier when an unknown identifier is used
    - [x] Make Arithmetic (operators) Great, Allegedly
        - [x] Types on both sides should be equal. Expect proper type (No subtyping!)
            - [x] Most binops need types to be *identical*
            - [x] Comparison operators only need types to be *assignable*
                > `x = 1 + 2 + 3` counterpoint: here there are two `+` operators, one performs identical, the other performs assignable
            - [x] Define representability too for constants
        - [x] Add Int8, Int16, Int32, Int64, Float32, Float64, Byte, Word16, Word32, Word64
        - [x] Add UB checking for signed integer arithmetic
            > {Int8, Int16, Int32, Int64} x {negate, add, sub, mult, div, mod, exponent}
    - [x] Enable the following warnings:
        - [x] `-Wformat=2`
        - [x] `-Werror`
        - [x] `-Wall`
            - [x] variable set but not used
            - [x] `unsigned char*` strings
            - [x] self-comparison optimization
            - [x] mark $panic() as _Noreturn
        - [x] `-Wextra`
        - [x] `-Wpedantic`
        - [x] `-pedantic-errors`
        - [x] `-Wconversion`
        - [x] `-Wsign-conversion`
        - [x] `-Wfloat-conversion`
        - [x] `-Wcast-qual`
        - [x] `-Wlogical-op`
        - [x] `-Wshadow`
        - [x] `-Wmisleading-indentation`
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
    - [ ] local value numbering
    - [ ] partial redundancy elimination
    - [ ] induction variable identification/unrolling (this is a good one if possible)
        - [ ] loop invariant lifting
    - [ ] ! inlining
        > Incredibly important optimization
    - [ ] ? pointer aliasing analysis (should squash most whitebox testing)
    - [ ] Codegen optimizations (less important)
        - [x] if a branch depends on a symbver with a `negate` def IR, plunge `negate` and flip labels
        - [ ] `derefCopy` should elide `*&`s
        - [ ] `printSymbolVersion` should collapse addrOf IR, etc
    - [x] coverage!
    - [x] fuzz with updated `fuzz.ebnf` to force a proper main function
- [ ] compile-time evaluation
    > Validate, IR, Optimize. Don't codegen, interpret!
        > Create the program struct very early on
        > Pass the program struct to validator, as validation may result in comptime code execution
        > Symbol > MIR > Optimization > Offset/slots > LIR (concat to program struct instructions)
        > When interpreting, use the program struct's instructions.
        > Symbols are referenced by their offsets.
        > BB and CFG are referenced by the next instruction, as if they were labels
        > Nothing should change for codegen, codegen uses symbvers and such, still prints out labels
    - [x] `const` is an annotation and symbol modifier
    > When a compile-time expression is evaluated
        - validate expr
        - surround with CFG context
        - convert to IR
        - optimize
        - interpret
    > When a function is needed to run at compile-time, check to see if the function CFG exists.
    - [x] expressions marked `comptime`
        - [x] redo code-gen, pass around writer, not a file, move main functions to modules
        - [x] be able to get expanded type from lvalue
        - [x] rename index field to rhs
    - [ ] eval symbol defs defined as const
    - [ ] eval default inits
    - [ ] eval array sizes
    - [ ] eval type annotations
    - [ ] should be able to index heterogenous tuples with a comptime value
        > Is this undecidable?
    - [ ] various type operations
        - [ ] `typeof` prefix operator which returns type expression of expression
        - [ ] `sizeof`
        - [ ] define `==` and `!=` operators for types, do at comptime. Defined to be `lhs <: rhs and rhs <: lhs`
        - [ ] `default` prefix operator, which takes a type and returns the default value for that type
- [ ] build system (built upon compile-time evaluation)
    > **!IMPORTANT!** Should output .c and .h pair for each .orng file. Track dependencies, and only run gcc on modified files and the files that depend* on modified files, to produce .o files which should be linked.
    - [ ] `build.orng` which contains a `build()` function, like zig
        > specifies the entry function (is this possible?)
        > specifies the orng code to use (is this possible?)
        > sets build modes, like debug, executable, library, etc
            - [ ] **IMPORTANT** indexes need to make their lhs lvalues in IR iff debug mode is off
        > be able to include C source files, and header directories
        > be able to link static and dynamic libraries
    - [ ] import syntax before any definitions `["from" package {"." package}] "import" module ["as" ident]`
        > Packages are directories, mapped in the build file
        > This allows dependencies to be simple
        > Also makes canonical names the norm
        > `module` is the filename in the package without the `.orng`, so file names have to abide by identifier syntax
    - [ ] `::` for module selection
    - [ ] `pub` keyword
    - [ ] `fn main(sys: System)->!()`
        > System contains:
            - args: []String // the command line args
            - stdin: dyn Reader
            - stdout: dyn Writer
            - stderr: dyn Writer
            - global_allocator: dyn Allocator
            - fs: // File System?
            - net: // Socket system?
            - env: // How should environment variables work?
    > How do externs work?
- [ ] type classes / interfaces / traits
    > Do not use for operator overloading!
    - [ ] `lhs<:rhs` operator with lhs being a capture pattern and rhs being a class
    - [ ] allocators
    - [ ] iterators & for loops
        - [ ] multi-loops, ranges like zig
    - [ ] Eq, Ord, Num, Bits, Convertible
    - [ ] derive
    - [ ] dot prepend `.>`
- [ ] function stamping
    > When a function has any constant parameters, stamp out a new version of the function for each unique combination of arguments
    - [ ] first-class types based generics (stamp)
    - [ ] generic type unification
        > Types can begin with `$ident`, where the type of `ident` will be inferred, and defined as a constant parameter
        - [ ] error if an identifier is `$` twice
        - [ ] error if `$` appears anywhere else but a type annotation
    - [ ] `@as` which can do reinterpret casting (maybe different name?)
    - [ ] `id` function in standard
- [ ] refinement types
    > This feature may not be needed, or good
    - [ ] `where` which checks at runtime if a condition is true, panics if it's not
    - [ ] `==>` implies boolean operator might be handy
        > `ast^ == .match ==> mappings_have_rhs(ast)`
    - [ ] `where comptime` checks a condition at compiletime. If a condition is false at compile-time, error

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