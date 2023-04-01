<!-- ## Syntax
- No parens around if, while, case
- low boilerplate for things that dont need it
- transformation rules similar to Haskell
- expressional type system -->
# Introduction
Orng is a performant, ergonomic programming language with the following features:
- Dead-simple and lightweight feature set
- Fast, cached compilation
- Support for algebraic data types, pattern matching

|    |    |
|----|----|
| Go | No enums |
| Rust | Unergonomic |
| C | No stacktraces! |
| Zig | No documentation, literally unuseable |
| Haskell | Performance unpredictability |

| Julia | Maybe not too bad actually, idk its used for more math stuff not data structure transformations |
| Nim | Idk, maybe, we'll see |
| OCaml | Maybe, but then I'd have to learn another language |
| Odin | Toy project, but seems promising |

| Java | On the JVM |
| Kotlin | On the JVM |
| Scala | JVM |
| Elixir | BEAM |
| Groovy | JVM |
| Prolog | Likely slow |
| Python | Interpreted |
| JavaScript | Interpreted |
| Ruby | Interpreted |
| Clojure | Interpreted, JVM |
| C# | .NET |
| F# | .NET |
| Visual Basic .NET | No |
| Fortran | No |
| Assembly | No |
| Perl | No |
| Pascal/Delphi | BAD |
| PHP | BAD |
| C++ | Bad |
| Blade | Toy project |

# Basic Syntax
## Comments
Comments in Orng start with `//`, and end at the end of the line. There are no block comments. Comments are ignored by the compiler before tokenization is done.
```rs
// This is a comment!
```
## Keywords

## Identifiers
Identifiers start with either a letter or an underscore, can contain letters, underscores, and digits, and can optionally end with apostrophes (see Pattern Matching). Identifiers cannot be keywords, unless surrounded with a  `` ` ` `` pair. 
```hs
this_is_an_identifier

thisIsIdentifier2

_ident3'
```
## Integers and Floats
Numbers start with a digit, contain one or more digits, and may optionally contain a decimal point. Number literals represent mathematically ideal numbers, and thus can be coerced to any numeric type granted that the number fits in the type's range.

Number literals can contain apostrophes anywhere as separators, so long as the literal starts and ends with a digit. 
```c++
// An "integer"
1000

// An "integer" with separator
1'000

// A number with a separator and a decimal point
1'000.0
```
### Hexadecimal Integers
Hexadecimal integer literals begin with the prefix `0x`. They can contain digits `0` to `9`, a mix of uppercase or lowercase letters from `A` to `F`, and separators.
```rs
// A huge hexadecimal integer
0xABCEF01234567890
```
### Octal Integers
Octal integer literals begin with the prefix `0o`. They can contain digits `0` to `7` and inner separators.
```rs
// An octal integer
0o1234567
```
### Binary Integers
Binary integer literals begin with the prefix `0b`. They can contain digits `0` and `1` and inner separators.
```rs
// A binary integer
0b01001111
```
## Character Literals
Character literals start and end with a `'` character. They represent the UTF-8 character between the `'` marks.
```rs
'🍊' // The character '🍊'

'\'' // The apostrophe, escaped
'\n' // A new-line character
```
<!-- TODO: enumerate escapes -->
## String Literals
String literals start and end with a `"` character. They represent a UTF-8 encoded string.
```rs
"Hello, Orng!" // A string

"Hello, \"Orng\"!\n" // Another string
```
<!-- TODO: enumerate escapes -->

# Declarations
## Declaring a Variable With `let`
Variables can be declared using the `let` keyword. Variable declarations can include a type and an intial value. At least the type or the initial value must be present. If the type is not present, it is infered from the initial value. If the initial value is not present, it is set to the default value for the type.
```rs
// Declaration with type and initial value
let x: Int = 10

// Declaration with just type, initialized to default value
let y: Int

// Declaration with just initial value, type is infered
let z = 0

// The following causes an error. Need at least type or initial value!
let a
```
Variables declared with the `let` keyword are immutable. Their values cannot be changed after the are declared.
## Declaring a Variable With `let mut`
You can also declare a variable with `let mut`, which declares a mutable variable.
```rs
// Declaration with type and initial value
let mut x: Int = 10

// Declaration with just type, initialized to default value
let mut y: Int

// Declaration with just initial value, type is infered
let mut z = 0

// The following causes an error. Need at least type or initial value!
let mut a
```
Variables declared with `let mut` are mutable, so they can be assigned to after they have been declared using the assignment (`=`) statement.
```rs
// Initially set x to be 10
let mut x: Int = 10

// Reassign x to be 15
x = 15
```
## Declaring a Constant With `const`
Compile-time constants are declared using the `const` keyword. 
```rs
// Declaration with type and initial value
const x: Int = 10

// Declaration with just type, initialized to default value
const y: Int

// Declaration with just initial value, type is infered
const z = 0

// The following causes an error. Need at least type or initial value!
const a
```

Constants defined with the `const` keyword must be initialized with values known at compile-time. Their values cannot be reassigned.
```rs
// The following causes an error.
// The return value of userInput() cannot be known at compile-time!
const name = userInput("give me your name")
```

Constants are order-independent, and can be used before they are defined, so long as they are visible.
```rs
// Here we're using `msg` before the line it's defined. That's fine!
println(msg)

const msg = "This is fine!"
```
## Pattern Matching
## Shadowing
Shadowing occurs when two identifiers with the same name are visible in the same location. Shadowing is prohibited in Orng.

# Sequencing
## Blocks
Blocks sequence zero or more statements. They can be declared inline using `{` `}` with statements are separated with `;`, or with indentation with statements separated with newlines. It is not permitted to mix `;` and newlines to separate statements.
```rs
// The following are equivalent

{let x = 4; x += 5; let y = x - 5}

    // Increase in identation
    let x = 4
    x += 4
    y = x - 5
// Decrease in indentation
```
Blocks return the last value evaluated in the block.
```rs
// The following block takes a character from the console
// Converts it to ascii and stores the result in user_ascii
let user_ascii = {let c: Char = console.readKey(); intFromChar(c)}
```
## The `defer` Operator
The defer statement defers the execution of the right-hand statement until after the scope exits. It immediately returns the value of the left-hand-side expression.
```rs
fn deferTest: ()->() = 
    // Allocate an int on the heap, free it at the end of this scope
    let x: &Int = new(Int) 
    defer free(x)

    // Do stuff with x here

    // Here, x will be freed after we're done using it
```
Defers are run in reverse order that they are encountered.
```rs
fn deferTest: ()->() =
    let x: &Int = new(Int) 
    defer free(x)
    let y: &Int = new(Int) 
    defer free(y)

    // do something with x and y

    // first y is freed
    // then  x is freed
```

# Decision Making
## The `if` Operator
<!-- no-else -->
The `if` operator is used to execute blocks of code only if a boolean condition is met.
```rs
// This will always print
println("You have a computer.")

if osIsWindows
    // This will only run if `osIsWindows` is `true`
    println("Your computer's operating system is Windows.")
```
<!-- else -->
You can give an optional `else` block for an `if` operator. The `else` block is executed when the condition is false.
```rs
if osIsWindows
    println("This will only run if `osIsWindows` is `true`")
else
    println("This will only run if `osIsWindows` is `false`")
```
<!-- gives value -->
The `if` operator is indeed an operator, and can be evaluated as an expression.
```rs
let x: Int = userInput()
let abs_val_of_x = if x < 0 {-x} else {x}
```
<!-- gives optional when no-else -->
If no `else` clause is given, the type of the `if` operator is an optional type (see Optional Types).
```rs
let x: Float = userInput()
let reciprocal: ?Float = if x != 0 {1.0 / x}
```
<!-- let, let mut, const -->
## The `cond` Operator
<!-- no-else -->
<!-- else -->
<!-- gives value -->
<!-- gives optional when no-else -->
<!-- let, let mut, const -->
## The `case` Operator
<!-- no-else -->
<!-- else -->
<!-- gives value -->
<!-- gives optional when no-else -->
<!-- let, let mut, const -->

# Loops
## The `while` Operator
<!-- no-else -->
<!-- else -->
<!-- gives value -->
<!-- gives optional when no-else -->
<!-- let, let mut, const -->
## The `for` ... `in` Operator
<!-- no-else -->
<!-- else -->
<!-- gives value -->
<!-- gives optional when no-else -->
<!-- let, let mut, const -->
## The `break` Statement
## The `continue` Statement

# Functions
## Function Type Syntax
Functions are first class in Orng. A function type can be created using the `->` operator.
```
```
## Defining a Named Function With `fn`
### `mut` Parameters
### Functions Need To Return A Value Through All Control Paths
## Defining an Anonymous Function
## Default Arguments
## The `return` Keyword
## Calling a Function
### The `.>` Operator
## Defining Inner Functions
## Casting Rules
## Default Value
## Subtype Rules
## Function Composition
## Functions Executed At Compile Time
## The `async/await` Keywords

# Primitive Data Types
## Integer Types
## Floating-Point Types
## Char Types
## Bool Types
## Named Types
## Abstract Types

# Tuple Types
## Tuple Type Syntax
### Positional Tuple Type Syntax
### Named Tuple Type Syntax
## The `()` Type
## Value Syntax
### Positional Tuple Value Syntax
### Named Tuple Value Syntax
## Indexing Tuple Fields
## Accessing Named Tuple Fields
## Equality Comparison
## Cycles
## Casting Rules
### Default Field Values
### Overriding Default Field Values
## Subtype Rules
## Tuple Type Concatenation
## Tuple Value Concatenation

# Array Types
## Array Type Syntax
## Array Literals
## Accessing Array Elements
## Accessing Array Length
## Iterating Through Arrays Using `for`
## Equality Comparison
## Multi Dimensional Arrays
## Casting Rules
## Default Value
## Subtype Rules
## Compiletime Array Value Concatenation

# Address Types
## Address Type Syntax
## `&` Operator
## `.*` Opererator
## Equality Comparison
## Address of an Address
## Address of a Tuple
## Casting Rules
## Default Value
## Subtype Rules
## `&mut` Addresses

# Slice Types
## Slice Type Syntax
## Making a Slice From an Array
## Making a Slice From a Slice
## Indexing Slice Elements
Accessing the elements in a slice can be done with square brackets.
```
fn get_from_slice:(slice:[]String, index:Int)->() = slice[index]
```
In debug mode, indexing a slice is bounds checked at runtime. *This check is not performed for release mode.*
## Accessing Slice Length
## Iterating Through Slices Using `for`
## Equality Comparison
## Multi Dimensional Slices
## Casting Rules
## Default Value
## Subtype Rules
## Compiletime Slice Concatenation
## `[mut]` Slices

# Sum Types
## Sum Type Syntax
## Creating Sum Type Values
## Equality Comparison
## Casting Rules
## Default Value
## Subtype Rules
## Base Type Inference
## Using Sum Types as Enums
## Using Sum Types as Tagged Unions

# `where` Types
## `where` Type Syntax
## Equality Comparison
## Casting Rules
## Default Value
## Subtype Rules

# Error Data Types
## Error Type Syntax
## The `throw` Statement
## The `try` Operator
## The `catch` Operator
## Infered Error Set
## Casting Rules
## Default Value
## Subtype Rules
## Stack Traces
## The `unreachable` Expression

# Optionals Data Types
Optional types represent the idea that data may or may not be present.
## Optional Type Syntax
Optional types are created with the `?` prefix token.
```
let maybeAnInt:?Int = 4
```
The optional type syntax is semantically the same as using an atom set:
```
fn Maybe:(T:Type)->Type = :none () | :some T

Maybe(Int) == ?Int   // true
```
## Coercion Rules
The coercion rules follow from the rules from atom types. You may coerce a value to an optional type.
```
// The following are equivalent
let maybeAChar1:?Char = :some(Char) 'd'
let maybeAChar2:?Char = 'd'
```
## The `null` Keyword
The `null` keyword is a shortcut for the `:none()()` atom value. It can be used when a value is missing.
```
// The following are equivalent
let maybeAReal1:?Real = :none()()
let maybeAReal2:?Real = null
```
You can check if an optional value is present by comparing it to `null`.
```
fn does_this_value_exist:(value:?Int) = 
    if x != null {
        println "yes"
    } else {
        println "no"
    }
```
## The `orelse` Keyword
The orelse keyword unwraps the value of an optional if it is `:some`, or evaluates to the right hand side of the expression if it is `:none`.
```
let maybeAnInt1:?Int = 4
let maybeAnInt2:?Int = null

maybeAnInt1 orlese 5    // evaluates to 4 because `maybeAnInt1` is not null
maybeAnInt2 orelse 5    // evaluates to 5 because 'maybeAnInt2' is null
```
## The `.?` Operator
The `.?` operator is a shortcut for `orelse unreachable`. It is used when you want to assert that a value does exist and unwrap its value.
```
let x:?Int = 4
let y:?Int = null

x.? // evaluates to 4 since `x` is not null
y.? // panics, since `y` is null
```
## Casting Rules
Values of some optional type `?A` maybe be casted to a type `?B` if and only if the type `A` may be casted to the type `B`.
## Default Value
The default value of an optional is `null`. This follows from the fact that optionals are just atom sets.
## Subtype Rules
For two optional types `?A` and `?B`, `?A <: ?B` if and only if `A <: B`.

# Interface Types

# Building
- Little setup required to begin a new project
- Package is just a folder with `.orng` files in it
- Can build and run with one single command
- `import` function which finds either `.orng` files or packages and imports them as a tuple
- Imported files act as modules, folders as packages
- There is a `main:std.System throws->()` function in one of the files
- `build.orng` file in the package with a `build:std.Builder->()` function which builds the project
- Only `const` and `fn` declarations are allowed in the top-level

<!-- formatter -->
<!-- documentation generator -->
<!-- test library -->
<!-- build-system -->
<!-- tutorials for everything, documentation for everything, VS code lang server -->

<!-- std.string which contains stuff for working with/formatting strings -->
<!-- std.debug which has assert stuff, todo() and logging -->
<!-- collections -->
<!-- std.functional with filter, map, reduce -->
<!-- std.net with TCP and UDP stuff -->
<!-- std.system with everything that has to do with real-world side-effects -->