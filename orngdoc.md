# Orng
Orng is a strongly, statically typed data-oriented genereal-purpose programming language. It is designed to replace C for game and application programming.
## Installation


## Hello World Example
### Setting Up a New Package
### Compilation


## Basic Syntax
### Comments
Comments in Orng start with `//`, and end at the end of the line. There are no block comments. Comments are ignored by the compiler before tokenization is done.
```
// This is a comment!
```
### Tokens
### Interchangable Semicolons & Newlines
Semicolons in Orng are prohibited, unless to put more than one statement on a single line. You can think of statements as being separated by either a newline or a semicolon, but not both and not neither.
```
// myFunc1 is equivalent to myFunc2.
fn myFunc1:()->() = {
    stmt1 // Statements separated by newlines
    stmt2
    stmt3
}

// Statements separated by semicolons
fn myFunc2:()->() = {stmt1; stmt2; stmt3}
```
### Identifiers
Identifiers start with a letter or an underscore, and can contain letters, numbers, underscores and can optionally end a single quote.
```
anIdentifier
an_identifier2
anotherIdentifier'
```
### Keywords & Prelude Constants
The following are keywords in Orng, and may not be used as identifiers. In general, there is a 1:1 correlation between keywords and control-flow and definitions.
```rs
and
async
await
break
case
catch
const
continue
else
if
invalidate
invalidates
fn
for
let
mut
or
orelse
return
Self
throw
throws
try
This
Type
unreachable
while
```
The following are constants/functions defined in the standard Orng prelude. Because of Orng's shadowing rules, these also cannot be used as user-defined identifiers.
```
bit_and
bit_or
bit_xor
bit_not
box
Bool
clone
c_import
Char
false
free
import
Int
Int8
Int16
Int32
Int64
null
new
Real
Real32
Real64
String
true
```
### Escaping Identifiers
### Whitespace


## Variables
### Variable Definitions
### Variable Declaration
### Type Inference
### `let` and `let mut` and `const`
### Lvalues and Rvalues


## Literals
### Integer Literals
### Hexadecimal Literals
### Binary Literals
### Octal Literals
### Floating-point Literals
### Character Constants
### String Literals


## Operators
### Arithmetic Operators
### Relational Operators
### Logical Operators
### Assignment Operators
### Misc Operators
<!-- include <> as a function composition operator -->


## Blocks
### Blocks As Expressions
### Defer
### Errdefer


## Decision Making
### The `if` Operator
An `if` statement can be constructed using the `if` token, a condition, and a block. The block is executed *if* (and only if) the condition is true.
```rs
let x = 4
if x == 4
    println("x is four")
```
An `if` statement is an expression and produces a value. The value is an optional type (discussed later). When the block is executed, the value of the `if` is the value of the block. When the block is not executed, the value of the `if` is `null`.
```rs
let x = if true {0}     // x is 0
let y = if false {0}    // y is null
```
If the condition of an `if` statement can be determined to always be `false` (resp. `true`), the body will be removed (resp. inlined).
```rs
if build.os == Windows()
    // Code that only works on Windows
```
### The `if`/`else` Operator
An `if` statement can optionally be followed by an `else` token and a block. If the condition of the if is true, the first block is executed. Otherwise if the condition is false, the else block is executed.
```rs
let x = 4
if x == 5
    println "x is 5" // Never ran since x isn't 5
else
    println "x isn't 5" // Printed since x isn't 5
```
An `if`/`else` statement is an expression and can produce a value. The value is either the result of the first block, or the result of the else block, depending on whichever one is executed.
```rs
let x = -4
let absValueOfX = if x > 0 {x} else {-x}
```
If the types of the two blocks are not the same, the resultant type is a union type of the two types.
```rs
let x = -4
let res:Int|Char = if x > 0 {x} else {'d'}    
```
Union types are discussed later.
#### The `if let`/`if let mut`/`if const` Pattern
A common pattern in Orng is the `if let` and `if let mut` pattern before the condition of the `if`. This allow you to define a constant or variable at the begining of the if-statement. The variable is only visible inside the body of the `if` and `else` body.
```rs
if let success = SDL_Init(SDL_INIT_EVERYTHING); success == SDL_FALSE
    std.sys.exit(1) // Unsuccessful, quit
    return
```
The `if let mut` allows for the variable to be modified inside the `if` block.
```rs
// Receiving a message from a TCP connection wrapper
let socket = connect()
let myIP = 0x7F000001
if let mut message = recv(socket); message.destination != myIP
    // Forward this message on
    forward(message)
else 
    // Keep this message for myself
    parse(message)
```
The `if const` allows a constant to be defined which is only in scope inside the `if` body.
```rs
let y = 4
if const x = BUILD_VERSION; x == y
    // const x is visible here
else 
    // const x is visible here
```
### The `cond` Operator
The cond operator allows for multiple values to be selected depending on if given conditions are true.
```rs
let x:Int
    | x == 0 = println("x is even")
    | x == 1 = println("x is odd")
    | x == 2 = println("x is even")
    | x == 3 = println("x is odd")
    | x == 4 = println("x is even")
    // etc...
```
Conditions are checked in the order they are specified.
```rs
let _ 
    | true = println("This branch will overshadow the others")
    | true = println("This branch will never be executed!")
    | true = println("Neither will this one!")
```
Conditions can be chained such that if any of them are true, the code is executed.
```rs
let x = user_input()
cond
| x % 2 == 0
| x % 5 == 0 => println("divisible by a 2 or 5")
| x % 3 == 0
| x % 7 == 0 => println("divisible by 3 or 7")
```
The last branch in a `cond` list may start with `\` and contain no condition. The code will be executed if none of the previous conditions were true.
```rs
let x = user_input()
cond
| x % 15 => println("fizzbuzz")
| x % 3  => println("fizz")
| x % 5  => println("buzz")
\ => println("{}", x)
```
#### The `cond let`/`cond let mut`/`cond const` Pattern
### The `case` Operator
#### The `case let`/`case let mut`/`case const` Pattern


## Loops
### The `while` Loop
#### The `while let`/`while let mut`/`while const` idiom
### The `for` Loop
#### The mutable `for mut` Loop
(*For _ in _ loop?*)
### Loop Control Statements
#### The `break` Keyword
#### The `continue` Keyword


## The `unreachable` Keyword
The unreachable keyword throws a panic if it is ever executed. It is used to assert that control flow is unreachable.
<!-- TODO: talk about panics, debug, release mode -->
```
if false {
    unreachable // Serious problem if this part of the code is ever reached!
}
```


## Scope Rules & Program Structure
### Local Variables
### Blocks
### Shadowing
### File Structure (No Forward Declarations!)
### Importing Other Orng Files (No Header Files)
### Importing C Header Files
### Files as Namespaces
### Build Function and Builder
#### Linking Static Libraries
### Debug vs Release


## Primitive Data Types
### Integer Types
### Floating-Point Types
### Char Types
### Bool Types
### The `()` Type


## `Type` Types
Types are first-and-a-half class in Orng. They can be passed as arguments to functions, stored in variables, and there are many operators for working with types. However, types cannot last through compilation. Variables of the type `Type` must be compile-time constant.
### Type Definitions
You can define types just like any other constant.
```
const LongerMoreComplicatedNameForAnInteger = Int
```
Since all types must be compile-time constant, `Type` constants cannot be left undefined.
```
const MyType:Type   // Error! No value given for constant
```
### Generics
<!-- TODO: Talk about the new and improved form of generics -->
<!-- fn get_default(x: T')->T' = default(T') -->
Generic types can be made with functions that return a `Type`. 
```
fn ArrayList:(T:Type)->Type = (
    data:[]T,
    capacity:Int
)
```
#### The `This` Type Keyword
<!-- TODO: is This needed? -->
Consider the following type definition for a linked list node:
```
fn LinkedList:(T:Type)->Type = (
    data:T
    next:?&LinkedList T  // Error here! Infinite loop!
)
```
The type doens't contain cycles (which is good), but the recursive call to `LinkedList T` causes an infinite loop at compiletime. There is no obvious way to get around this. For these scenarios, we use the `This` type. The `This` type is a special type designed to be used by type functions. It is replaced by the type returned by the function.
```
fn LinkedList:(T:Type)->Type = (
    data:T
    next:?&This // Filled in with LinkedList(T), for whatever value that is, after the function exits
)
```
Type functions that use the `This` type must be cycle free. The following code contains a cycle. Cycles are discussed later.
```
const MyType:(const n:Int)->() = This^n // Cycle, cannot resolve this type
```
### Type Reflection Tuple
**TODO!**


## Tuple Types
### Tuple Type Syntax
#### Positional Tuple Type Syntax
Positional tuples are a list of types separated by commas.
```
// A tuple of 3 real numbers
const MyTuple:Type = (Real, Real, Real)
```
#### Named Tuple Type Syntax
Tuple elements can be given names by prefixing the type with a name and a colon.
```
// A tuple of 3 real numbers, each element having a name
const MyTuple:Type = (x:Real, y:Real, z:Real)
```
If a tuple is named, all elements in the tuple must be given names.
### The `()` Type
The `()` type is a tuple with no fields. The `()` type represents the idea of a value not existing. The `()` type has a size of 0 bytes. The only value for the type `()` is `()`.
```
let x:() = ()
```
### Value Syntax
#### Positional Tuple Value Syntax
A tuple value is a list of values separated by commas.
```
let myCoords = (0.4, 101.3, -30.5)
```
The parenthesis are optional, but are recommended.
```
// The following is equivalent to the tuple above:
let myCoords = 0.4, 101.3, -30.5
```
#### Named Tuple Value Syntax
Tuple values can be given names if the tuple type was named. The names can appear in any order. A name cannot be given more than once. If a tuple is named, all values in the tuple must be named.
```
const Point = (x:Real, y:Real, z:Real)

let myCoords = (.z=-30.5, .x=0.4, .y=101.3)
```
### Indexing Tuple Fields
The fields of both positional and named tuples can be accessed using square brackets with the index of the field. Indexing starts at 0. Indexes do not need to be compile-time constant.
```
const PositionalPoint = (Real, Real, Real)
let posPoint:PositionalPoint = (1, 2, 3)
posPoint[0] // 1
posPoint[1] // 2
posPoint[2] // 3

const NamedPoint = (x:Real, y:Real, z:Real)
let namedPoint:NamedPoint = (1, 2, 3)
namedPoint[0] // 1
namedPoint[1] // 2
namedPoint[2] // 3
```
### Accessing Named Tuples Fields
The fields of a named tuple can be accessed using the `.` operator and the name of the field.
```
const Point = (x:Real, y:Real, z:Real)
let myPoint:Point = (1, 2, 3)
myPoint.x // 1
myPoint.y // 2
myPoint.z // 3
```
### Equality Comparison
Two tuple values are equal when all their fields are equal.
```
let pointA = (1, 2, 3)
let pointB = (1, 2, 3)

pointA == pointB // true
```
Two tuple values are inequal when any of their fields are inequal.
### Cycles
Tuples cannot indirectly contain themselves. This can arise when a tuple contains a field of its own type, or if a tuple contains a field of a type that contains the original tuple, etc.
```
const BadTuple = (x:BadTuple, y:BadTuple)   // Error! Cycle in tuple type definition

const CycleA = (CycleB, Int)    // Error! 3-cycle in tuple definitions
const CycleB = (CycleC, Int)
const CycleC = (CycleA, Int)
```
To fix a cycle, use an address of a tuple instead.
```
// Okay! No cycles
const BadTuple = (x:&BadTuple, y:&BadTuple)

// Okay! No cycles
const CycleA = (&CycleB, Int)
const CycleB = (&CycleC, Int)
const CycleC = (&CycleA, Int)
```
### Casting Rules
Tuple values cannot be cast to non-tuple types, nor to tuples of different arity.
#### Defualt Field Values
If not all the fields of a tuple type are specified in a tuple value, they are filled in with the default value of the missing fields's type.
```
const Point = (x:Real, y:Real, z:Real)

let myCoords:Point = (4, 5)   // The `z` coordinate is defaulted to 0.0
```
This only works if the tuple type is expected. For example:
```
const Point = (x:Real, y:Real, z:Real)

// Here we do not specify that `myCoords` is of type `Point`
let myCoords = (4, 5)
// This is still legal code, but now `myCoords` is of type `(Real, Real)`, not `(Real, Real, Real)`.
```
#### Overriding Default Field Values
<!-- Deprecate -->
You can override the default field values by using the `=` token when defining the tuple type.
```
const Point = (x:Real=-1, y:Real=-1, z:Real=-1)

let myCoords:Point  // No value given, default of (-1, -1, -1) is used
```
Overriden default field values must be comptime time constant.
```
let someVal:Int = input("Integer from user input: ")
const Point = (x:Int=someVal, y:Int=someVal) // Error! someVal is not compile time constant and so cannot be used as a default value!
```
### Subtype Rules
<!-- Remove subtypes, use Go type equivalence -->
For two tuple types `(A_1, ... A_n)` and `(B_1, ... B_n)`, `(A_1, ... A_n) <: (B_1, ... B_n)` when `A_i <: B_i` for `i in 1..n`. 

Tuple subtyping is NOT associative. For example:
```
const MyTuple1 = (Real, Real, Real, Real)
const MyTuple2 = ((Real, Real), (Real, Real))

// These two types are not subtypes, even though their data layout is the same
MyTuple1 <: MyTuple2 // false
MyTuple2 <: MyTuple1 // false
```
### Tuple Type Concatenation
Tuple types can be concatenated with the `++` operator. If the tuples are named, no names in the tuple may be the same. The two types must either be both named tuple types or both positional tuple types.
```
const Point = (Real, Real)
const DoublePoint = Point ++ Point  // == (Real, Real, Real, Real)
```
### Tuple Value Concatenation
Tuple values can be concatenated with the `++` operator. The resulting value is the two values concatenoated. The resulting type of the value is the type of the two tuple values concatenated as described above.
```
const Point = (Real, Real)
const DoublePoint = Point ++ Point

let myPoint = (4, 5)
let yourPoint = (5, 6)
let ourPoint:DoublePoint = myPoint ++ yourPoint // (4, 5, 5, 6)
```


## Functions
### Function Type Syntax
### Defining a Named Function With `fn`
#### Functions Need To Return A Value Through All Control Paths
### Defining an Anonymous Function
### Default Arguments
### Variable Arguments
### The `return` Keyword
### Calling a Function
#### The `.>` Operator
The `.>` or "delta" operator takes the value to the left of the `.>` and places it as the first argument of the function call to the right.
```
const Vector = (x:Real, y:Real)

fn add:(a:Vector, b:Vector)->Vector = (a.x + b.x, a.y + b.y)
fn magnitude:(a:Vector):Real = sqrt(a.x^2 + a.x^2) 

let myVector:Vector = (3, 4)
let yourVector:Vector = (5, 6)
let magnitudeOfSum:Real = myVector 
                   .> add(yourVector)
                   .> magnitude()
```
### Equality Comparison
### Defining Inner Functions
### Casting Rules
### Default Value
### Subtype Rules
### Function Composition
### Functions Executed At Compile Time
### The `async/await` Keywords


## Array Types
### Array Type Syntax
### Array Literals
### Accessing Array Elements
### Accessing Array Length
### Iterating Through Arrays Using `for`
### Equality Comparison
### Multi Dimensional Arrays
### Casting Rules
### Default Value
### Subtype Rules
### Compiletime Array Value Concatenation


## Address Types
### Address Type Syntax
### `&` Operator
### `.*` Opererator
### Equality Comparison
### Address of an Address
### Address of a Tuple
Accessing/indexing the fields of an address of a tuple is syntactically no different from accessing/indexing the fields of a regular tuple.
```
const Point = (x:Real, y:Real)
let point = (4, 5)
let addrPoint = &point

point.x == addrPoint.x   // true
point[1] == addrPoint[1] // true
```
### Casting Rules
### Default Value
### Subtype Rules
### `&mut` Addresses
A `&mut` address can have the data at the address changed, whereas a regular `&` address cannot.
```
fn set_int_to_zero:(addr1:&mut Int, addr2:&Int)->() = {
    addr1.* = 0 // Ok
    addr2.* = 0 // Error! Cannot write to immutable address
}
```


## Slice Types
### Slice Type Syntax
### Making a Slice From an Array
### Making a Slice From a Slice
### Indexing Slice Elements
Accessing the elements in a slice can be done with square brackets.
```
fn get_from_slice:(slice:[]String, index:Int)->() = slice[index]
```
In debug mode, indexing a slice is bounds checked at runtime. *This check is not performed for release mode.*
### Accessing Slice Length
### Iterating Through Slices Using `for`
### Equality Comparison
### Multi Dimensional Slices
### Casting Rules
### Default Value
### Subtype Rules
### Compiletime Slice Concatenation
### `[mut]` Slices


## `String` Types
### `std.string.from:(chars:&Char)->String`
### Appending Characters to Strings
### Concatenating Strings
#### Compiletime Concatenation With `++`
#### Runtime Concatenation
### TODO: Implement good string library, and write documentation for std lib


## Atom Types
Atoms are ways to wrap nominal type equivalence around Orng's structural type equivalence system.
### Atom Type Syntax
Atom types are created as follows:
```
":" (atom-name) (atom-inner-type)
```
### Creating Atom Values
Atom values can be created by using call syntax on the atom type.
```
let myPos = :point(Real, Real)(3, 4)
let myVel = :vector(Real, Real)(10, -3)

// Techinally, both the rectangle definitions are structurally equivalent, but because of atoms they are _correctly_ considered different types
const Point = :point(x:Real, y:Real)
const Rect1 = :rect1(topRightCorner:Point, bottomLeftCorner:Point)
const Rect2 = :rect2(topLeftCorner:Point, bottomRightCorner:Point)

// Structurally these two rects are equivalent, but semantically they are not, which is good and useful! 
let myRect1:Rect1 = Rect1 Point(3, 4), Point(5, 6)
let myRect2:Rect2 = Rect2 Point(3, 4), Point(5, 6)
myRect1 == myRect2  // Type error! Rect1 is not compatible with Rect2
```
### Atom Type Union
Atom types can be unioned together with the `||` operator.
```
const Point = :point(x:Real, y:Real)
const Rect1 = :rect1(topRightCorner:Point, bottomLeftCorner:Point)
const Rect2 = :rect2(topLeftCorner:Point, bottomRightCorner:Point)

const AnyRect = Rect1 || Rect2

let myRect1:AnyRect = Rect1 Point(3, 4), Point(5, 6)
let myRect2:AnyRect = Rect2 Point(3, 4), Point(5, 6)
myRect1 == myRect2  // Type checks, evaualtes to false because the atom type tags are not the same
```
### Accessing Atom Type Union Fields
Atom type unions can be accessed with the dot operator. When doing so, the domain type of the atom is infered.
```
const Suit = :spades() || :hearts() || :diamonds() || :clubs()

let myCardSuit:Suit = Suit.spades ()
let lol:Suit = Suit.spades()
lol.spades // Nothing
```
### Accessing Atom Value Inner Value
The inner value of an atom value can be retrieved with the dot operator and the name of the atom.
```
const SomeAtoms = :a Int || :b Int

let myAtom = SomeAtoms.a 5
let atomVal = myAtom.a
```
### Value Coercion
You may coerce the value up to an atom union when the inner types of the atoms in the union are distinct.
```
const SomeAtoms = :atomA Int || :atomB Char

let myAtom: SomeAtoms = 4  
// ...Which is equivalent to...
let myAtom2: SomeAtoms = #atomA Int 4
```
### Atom Value Equality
Two atom values are equivalent when their atom type tags are equal **and** their inner values are equal. It is not a type error if the types tags are inequal, the comparison is just false.
```
const SomeAtoms = :a Int || :b Int

const someA = SomeAtoms.a 5
const someB = SomeAtoms.b 5
someA == someB // False, because of differing atom tags
```
### Casting Rules
### Default Value of Atom Type
The default value of a union of atoms is the default value of the inner type of the first atom in the union.
```
const SomeAtoms = :a Int || :b Char
default SomeAtoms == 0
```
### Subtype Rules
For two atoms set types `A` and `B`, `A <: B` if and only if for all atoms `:a A'` in `A`, there is an atom `:a B'` in `B` such that `A' <: B'`.
```
const Point = :point(x:Real, y:Real)
const Vertex = :point(x:Real, x:Real) || :point3(x:Real, y:Real, z:Real)
const Vector = :vector(x:Real, y:Real)

assert Point <: Vertex == true
assert Vertex <: Point == false

assert Point <: Vector == false
assert Vector  <: Point == false
assert Point == Vector == false
```
Two atom types are equal when they are subtypes of each other.
### Using Atom Sets as Enums
Atoms can be used to simulate enums by using atoms with void inner types. For example:
```
const BuildFlag = :release_fast() 
               || :release_safe() 
               || :debug()

fn get_build_description:(flag:BuildFlag)->String = 
switch typeof flag {
    BuildFlag.release_fast() => "release build with full optimizations"
    BuildFlag.release_safe() => "release build with some memory and type safety checks"
    BuildFlag.debug()        => "debug build with full memory and type safety checks"
}
```
### Using Atom Sets as Tagged Unions
Atoms can be used to simulate tagged unions, since atoms can hold heterogenous data. For example:
```
fn Tree:(T:Type)->Type = :leaf T
                      || :node(left:&Tree(T), right:&Tree(T))

fn postfix_traverse:(node:&Tree String)->() = 
    switch typeof node {
        Tree(String).leaf => println node.leaf
        Tree(String).node => {
            postfix_traverse node.left
            postfix_traverse node.right
        }
    }
```


## Error Data Types
### Error Type Syntax
### Coercion Rules
### `try` Keyword
### `catch` Keyword
### Infered Error Set
### Casting Rules
### Default Value
### Subtype Rules


## Optionals Data Types
Optional types represent the idea that data may or may not be present.
### Optional Type Syntax
Optional types are created with the `?` prefix token.
```
let maybeAnInt:?Int = 4
```
The optional type syntax is semantically the same as using an atom set:
```
fn Maybe:(T:Type)->Type = :none () | :some T

Maybe(Int) == ?Int   // true
```
### Coercion Rules
The coercion rules follow from the rules from atom types. You may coerce a value to an optional type.
```
// The following are equivalent
let maybeAChar1:?Char = :some(Char) 'd'
let maybeAChar2:?Char = 'd'
```
### The `null` Keyword
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
### The `orelse` Keyword
The orelse keyword unwraps the value of an optional if it is `:some`, or evaluates to the right hand side of the expression if it is `:none`.
```
let maybeAnInt1:?Int = 4
let maybeAnInt2:?Int = null

maybeAnInt1 orlese 5    // evaluates to 4 because `maybeAnInt1` is not null
maybeAnInt2 orelse 5    // evaluates to 5 because 'maybeAnInt2' is null
```
### The `.?` Operator
The `.?` operator is a shortcut for `orelse unreachable`. It is used when you want to assert that a value does exist and unwrap its value.
```
let x:?Int = 4
let y:?Int = null

x.? // evaluates to 4 since `x` is not null
y.? // panics, since `y` is null
```
### Casting Rules
Values of some optional type `?A` maybe be casted to a type `?B` if and only if the type `A` may be casted to the type `B`.
### Default Value
The default value of an optional is `null`. This follows from the fact that optionals are just atom sets.
### Subtype Rules
For two optional types `?A` and `?B`, `?A <: ?B` if and only if `A <: B`.


## Interfaces
### Defining Interfaces
Interfaces are simply tuples of one or more named function-typed fields on either the type `&Self` or `&mut Self`. The `Self` type is the generic implementing type.
```
const Shape = (
    area:&Self->Real
    perimeter:&Self->Real
)

fn Iterator:(T:Type)->Type = next:&mut Self->?T
```
#### Subinterfaces
Subinterfaces are created using the `++` keyword.
```
const Person = name:Self->String

const Student = Person ++ school_name:Self->String

const Programmer = Person ++ favorite_language:Self->String
```
### The `impl` Operator
The `impl` operator takes in a list of interfaces, a base type, and a list of function definitions. The resulting type is the base type that implements the functions in the way given.
```
const Shape = (
    area:&Self->Real
    perimeter:&Self->Real
)
const Show = (
    show:&Self->String
)

const Rectangle = 
    impl Shape, Show for (width:Real, height:Real) {
        fn area:(self:&Rectangle)->Real = self.data:Rectangle.width * self.data:Rectangle.height

        fn perimeter:(self:&Rectangle)->Real = 2 * (self.width + self.height)

        fn show:(self:&Rectangle)->String = std.string.format("{}x{} rectangle", (self.width, self.height))
    }
``` 
### Calling Functions of an Interface Using `.`
Functions of an interface can be called by using the `.` operator and the function name. The first parameter is implicitly given to the function.
```
const Shape = (
    area:&Self->Real
    perimeter:&Self->Real
)

const Rectangle = 
    impl Shape for (width:Real, height:Real) {
        fn area:(self:&Rectangle)->Real = self.data:Rectangle.width * self.data:Rectangle.height

        fn perimeter:(self:&Rectangle)->Real = 2 * (self.width + self.height)
    }

let rectangle:Rectangle = (20, 20)
rectangle.area ()       // = 400
rectangle.perimeter ()  // = 80
```
### Coercion To Base Type
You can implicitly coerce from base to derived type and from derived to base type.
```
const Shape = (
    area:&Self->Real
    perimeter:&Self->Real
)

const Rectangle = 
    impl Shape for (width:Real, height:Real) {
        fn area:(self:&Rectangle)->Real = self.data:Rectangle.width * self.data:Rectangle.height

        fn perimeter:(self:&Rectangle)->Real = 2 * (self.width + self.height)
    }

let rectangle:Rectangle = (20, 20)  // Implicitly converting from base type to derived type
let tuple:Real^2 = rectangle        // Implicitly converting from derived type to base type
```
### Coercion To Interface Type
You can implicitly coerce from a derived type to an interface type, but not the other way around implicitly.
```
const Shape = (
    area:&Self->Real
    perimeter:&Self->Real
)

const Rectangle = 
    impl Shape for (width:Real, height:Real) {
        fn area:(self:&Rectangle)->Real = self.data:Rectangle.width * self.data:Rectangle.height

        fn perimeter:(self:&Rectangle)->Real = 2 * (self.width + self.height)
    }

let rectangle:Rectangle = (20, 20)

fn add_area_and_perimeter:(shape:Shape)->Real = shape.area() + shape.perimeter()

// Implicitly coerce Rectangle to Shape
add_area_and_perimeter rectangle    // = 480
```
### Casting Rules
You can explicitly cast a value of an interface type to a derived type which implements that interface.
```
const Shape = (
    area:&Self->Real
    perimeter:&Self->Real
)

const Rectangle = 
    impl Shape for (width:Real, height:Real) {
        fn area:(self:&Rectangle)->Real = self.data:Rectangle.width * self.data:Rectangle.height

        fn perimeter:(self:&Rectangle)->Real = 2 * (self.width + self.height)
    }

let rectangle:Rectangle = (20, 20)

fn add_area_and_perimeter:(shape:Shape)->Real = {
    let probablyRect:Rectangle = shape:Rectangle // Explicitly cast shape as a Rectangle
    probablyRect.width * probablyRect.height + 2 * (probablyRect.width + probablyRect.height)
}
```
### Default Value
The default value of an derived type is the default value of the inner base type. The default value of an interface type is a vtable with 0x0 function addresses.
### Subtype Rules
For a type `A` and a derived type `B` of `A`, `A == B`. For any interface type `I` that `B` derives, `I <: B`.
### Some Built-In Interfaces
#### Allocators
Allocators are an interface which allow you to allocate memory. The allocator interface is defined in the Orng prelude as follows:
```
const Allocator = (
    alloc:(self:&mut Self, bytes:Int)->?&Any
    realloc:(self:&mut Self, addr:&Any, bytes:Int)->!&Any
    free:(self:&mut Self, addr:&Any)->()
)
```



(*End lang doc, begin compiler/std lib doc and tutorial*)
## Input & Output
### The Standard Files
### The MEMORY SAFE `read_lines` and `write_line` Functions
### The `std.debug.log`, `std.debug.warn`, and `std.debug.err` Functions


## File I/O
### Opening Files
### Closing a File
### Writing a File
### Reading a File
### Binary I/O Functions


## Memory Management
### The `new:(T:Type, init:T=default T)->&T` Function
### The `free(&$T)` Function
### The `realloc` Function


## Command Line Arguments