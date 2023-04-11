![Budi the Monkey!](https://github.com/Rakhyvel/Orng/blob/main/budi.png)
###### Budi the Orangutan, mascot of the Orng Programming Language

Orng is a fast, expressive general purpose programming language that compiles to C!

## Planned Features
* A clean, indentation based syntax
* Seamless bidirectional C ABI interop
* Blazingly fast compilation speeds!
### Generic and Alegbraic Data Types
```rs
fn LinkedList: (const T: Type)->Type
    = nil
    | node: (data: T, next: &LinkedList)
    
    // You can then pattern match on ADTs
    fn length: (list: &LinkedList, acc: Int \ 0)->Int =
        case list^
        | nil            => acc
        | node(_, next') => length(next', acc + 1)
```
### Refinement types
```rs
// An int `n` is in the `Evens` type if n % 2 == 0
const Evens: Type = n: Int where n % 2 == 0
```
### Generic type constraints
```rs
// The type `T'` will be inferred based on the arguments
fn contains: (haystack: []T', needle: T')->Bool 
where T' impls Eq =
    for hay in haystack
        if hay == needle
            return true
    false

contains([1, 2, 3], 5) // false
contains(['a', 'b', 'c'], 'b') // true
```
### Type-class based ad-hoc polymorphism
```rs
// Define two types, Square and Circle
const Square = width: Float, height: Float
const Circle = radius: Float

// List of definitions that a type must define to be in the class `Shape`
class Shape
    area: Self->Float
    perimeter: Self->Float

// Implementing the `Shape` class for `Square`
impl Shape for Square
    fn area: (self: Shape)->Float = self.width * self.height

    fn perimeter: (self: Shape)->Float = 2 * (self.width + self.height)

// Implementing the `Shape` class for `Circle`
impl Shape for Circle
    fn area: (self: Circle)->Float = 3.1415 * self.radius ** 2

    fn perimeter: (self: Circle)->Float = 3.1415 * 2 * self.radius

// Using the `Circle` and `Square` types
fn function: ()->() =
    let square:Square = (.width <- 10, .height <- 30)
    let circle:Circle = (.radius <- 20)

    std.debug.println("{}", square.>area()) // 300
    std.debug.println("{}", circle.>perimeter()) // 125.66
```
### Built-in support for error handling
```rs
const PossibleErrors
    = fileNotFound: (filename: String)
    | parseError: (expected: Token, got: Token, line: Int, col: Int)
    | hardDriveOnFire: (temperature: Float)

fn fallibleFunction: (filename: String)->PossibleErrors!SyntaxTree =
    let file = if not fileExists(filename)
        throw PossibleErrors.fileNotFound(filename)
    else
        open(filename)
    
    let contents = read(file) catch ""
    let syntaxTree = try parse(contents)
    return syntaxTree
```

## Installation
```sh
# Orng requires Zig version 0.11.0

git clone https://github.com/Rakhyvel/Orng.git
cd Orng
zig build run
```