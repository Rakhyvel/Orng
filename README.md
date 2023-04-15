# The Orng Programming Language
<div align="right"><a href="#"><img src="budi.png" alt="Budi the Orangutan!" align="right" width="30%"></a></div>

> **WARNING**! Orng is still a work in progress!

Orng is a versatile general purpose programming language that gives developers control while still being expressive. It is designed to be both lightweight and simple, making it a great choice for enthusiast programmers.

* Visit [the website (coming soon)](http://ornglang.org) to learn more about Orng.
* Tutorials can be found [here (coming soon)](http://ornglang.orng/tutorials).
* Documentation can be found [here (coming soon)](http://ornglang.orng/docs).

## Installation
```sh
# Orng compiler requires Zig 0.11.0 at the moment
git clone https://github.com/Rakhyvel/Orng.git
cd Orng
zig build
```

## Usage
Once you have installed the Orng compiler, you can start using the language to write your applications. Here's a simple "Hello, World" program in Orng:
```rs
fn main: (sys: System)->!() =
    sys.out.>println("Hello, World!")
```

To run this program, simply save it to a file with a ".orng" extension and then run the following command in the terminal:
```sh
orng run hello.orng
```

## Features
Orng comes with a wide range of features that make it a powerful and flexible programming language, including: 
* **Allocator Memory Model:** Allocators are baked into the core of how Orng operates with memory, which alleviates the sharp corners of manual memory management.
* **Type-Classes:** Type-classes offer a simple, yet powerful way to express ad-hoc polymorphism.
* **First-Class Types:** Types are first class in Orng, which means you can pass types to functions as arguments, and return them from functions. This is how generics are done!
* **Built-In Error Handling:** Orng has built-in support for handling runtime errors in a clean and ergonomic way.
* **Refinement Types:** Orng has support for refinement types, which can add extra predicate-based safety checks to types. 
* **Functional Programming Idioms:** Orng has many functional programming features, which include:
    - Algebraic Data Types
    - Optional types in place of `null` values
    - Immutable-By-Default variables
    - Pattern Matching
    - Generic Type Unification
    - Partially Applied Functions
    - Type Inference
* **Bidirectional C Interop:** Orng compiles to C and can parse C header files, which afford seamless interop with C. Orng code can interact with existing C code, and C code can interact with your Orng code.

<!-- ## Standard Library -->

<!-- ## Examples (do 3) -->
## Examples
### Factorial Function
```rs
// One-liner factorial function!
fn factorial: (n: Int)->Int = if n < 2 {1} else {n * fact(n - 1)}
```
### Fizzbuzz
```rs
const FizzBuzzResult 
    = string: String
    | integer: Int

fn fizzbuzz: (n: Int)->FizzBuzzResult =
    cond
    | n % 15 == 0 => FizzBuzzResult.string("fizzbuzz") 
    //               ^^^^^^^^^^^^^^
    // We can either be explicit with the ADT we use...
    | n % 5 == 0  => .string("buzz") 
    //              ^
    // ... Or we can let it be inferred, if possible
    | n % 3 == 0  => .string("fizz")
    | else        => .integer(n)

fn main: (sys: System)->!() =
    while let i = 0; i < 100; i += 1
        case fizzbuzz(i)
        | .string(s')  => try sys.out.>println("{}", s')
        | .integer(j') => try sys.out.>println("{}", j')
```
### Generic Type Unification
Identifiers may end in a single apostrophe. When unification is done, apostrophe'd identifiers are considered to be free variables, and regular identifiers are terms.
```rs
// Function that works for values of any type `T'` in the `Eq` type-class
fn contains: (haystack: []T', needle: T')->Bool
where T' <: Eq =
    cond 
    | haystack.len == 0     => false
    | haystack[0] == needle => true
    | else                  => contains(haystack[1..], needle)
```


## Contributing
We welcome contributions of all kinds! Bug reports, feature requests, code contributions and documentation updates are always appreciated.

## License
Orng is released under the MIT license. See LICENSE for details.