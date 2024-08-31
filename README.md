
<div align="center">
    <a href="#"><img src="docs/budi.png" alt="Budi the Orangutan!" width="30%"></a>
    <h6>For When Live Gives You Orngs...</h6>
    <h1>Orng Programming Language</h1>
</div>

> **WARNING**! Orng is still a work in progress!

Orng is a versatile general purpose programming language that gives developers control while still being expressive. It is designed to be both lightweight and simple, making it a great choice for enthusiast programmers.

* Visit [the website (coming soon)](http://ornglang.org) to learn more about Orng.
* Tutorials can be found [here (coming soon)](http://ornglang.orng/tutorials).
* Documentation can be found [here (coming soon)](http://ornglang.orng/docs).

## Installation
```sh
# Orng compiler requires Zig 0.13.0 at the moment
git clone https://github.com/Rakhyvel/Orng.git
cd Orng
zig build
```

## Usage
Once you have installed the Orng compiler, you can start using the language to write your applications. Here's a "Hello, World" program in Orng:
```rs
fn main(sys: System) -> !() {
    greet("Orng! 🍊", sys.stdout)
}

fn greet(recipient: String, out: dyn Writer) -> !() {
    try out.>println("Hello, {s}", recipient)
}
```

To run this program, simply save it to a file with a ".orng" extension and then run the following command in the terminal:
```sh
orng run hello.orng
```

## Features
Orng comes with a wide range of features that make it a powerful and flexible programming language, including:
* **First-Class Types:** Types are first class in Orng, which means you can pass types to functions as arguments, and return them from functions. This is how generics are done!
* **Parametric Effect System:** Objects capable of side-effects, such as allocators, file writers, network sockets, etc, must be passed in as parameters to functions. This allows side-effects to be effortlessly tracked by what a function takes in as its parameters.
* **Traits:** Traits offer a simple, yet powerful way to express ad-hoc polymorphism.
* **Functional Programming Idioms:** Orng has many functional programming features, which include:
    - Algebraic Data Types
    - Pattern Matching
    - Optional types, in place of `null` values
    - Error types, for runtime error handling
    - Immutable-By-Default variables
* **Bidirectional C Interop:** Orng compiles to C and can parse C header files, which afford seamless interop with C. Orng code can interact with existing C code, and C code can interact with your Orng code.

<!-- ## Standard Library -->

<!-- ## Examples (do 3) -->
## Examples
### Factorial Function
```rs
// A factorial function!
fn factorial(n: Int) -> Int {
    if n < 2 {1} else {n * factorial(n - 1)}
}
```
Lets break that down so we can understand how Orng works.
```rs
fn factorial                      // Define a new function called `factorial`.
    (n: Int) -> Int {             // The type of `factorial` is a function, 
                                  //     which takes an integer called `n` and 
                                  //     returns an integer.
    if n < 2 {1}                  // The result of calling factorial is either 
                                  //     `1` if `n < 2`,
      else {n * factorial(n - 1)}}// Otherwise is `n * factorial(n-1)`.
```
### Traits
```rs
import debug from std

// Define a trait `Speak` with a method `speak`, which returns a String
trait Speak {
    fn speak(self) -> String
}

// Define two types, `Dog` and `Cat`
let const Dog: Type = (name: String, bones_consumed: Int)
let const Cat: Type = (name: String, lives_left: Int)

// Implement `Speak` for `Dog`
impl Speak for Dog {
    fn speak(self) -> String {
        "bark!"
    }
}

// Implement `Speak` for `Cat`
impl Speak for Cat {
    fn speak(self) -> String {
        "meow!"
    }
}

fn main(sys: System) -> !() {
    let my_dog: Dog = ("fido", 34)
    let my_cat: Cat = ("garfield", 8)

    make_animal_speak(&dyn my_dog)
    make_animal_speak(&dyn my_cat)
}

// This function takes in an address of a value of a type which implements Speak
fn make_animal_speak(animal: &dyn Speak) -> () {
    debug::println("{s}", animal.>speak())
}
```
### Fizzbuzz - ADTs and Pattern Matching
```rs
// Define an Algebraic Data Type (ADT), similar to tagged unions
// `FizzBuzzResult` can either hold a String, or an Int
const FizzBuzzResult = (string: String | integer: Int)

fn fizzbuzz(n: Int) -> FizzBuzzResult {
    match 0 {
        {n % 15} => FizzBuzzResult.string("fizzbuzz") 
        //          ^^^^^^^^^^^^^^
        // We can either be explicit with the ADT we use...

        {n % 5}  => .string("buzz") 
        //         ^
        // ... Or we can let it be inferred, if possible.

        {n % 3}  => .string("fizz")

        _        => .integer(n)
    }
}

fn main(sys: System) -> !() {
    while let i = 0; i < 100; i += 1 {
        // Can pattern match on ADTs! Again, can let which ADT be inferred if possible
        match fizzbuzz(i) {
            .string(s)  => try sys.stdout.>println("{}", s)
            .integer(j) => try sys.stdout.>println("{}", j)
        }
    }
}
```
### Generic Type Unification
Parameter types identifiers that begin with `$` are considered free. This method of ad-hoc polymorphism is more readable than other methods, such as overloaded functions, as each function name has one unique definition.
```rs
// Define a simple, generic array list type
fn List(const T: Type) -> Type {
    (
        items: []T,
        length: Int,
        alloc: dyn Allocator
    )
}

// Define generic functions that act on instances of List
fn append(list: List($T), element: T) -> !() {
    if list.items.length >= list.length {
        // ... expand the list's capacity
    }
    list.items[list.length] = element
    list.length += 1
}

fn get(list: List($T), index: Int) -> T {
    list.items[index]
}
```


## Contributing
We welcome contributions of all kinds! Bug reports, feature requests, code contributions and documentation updates are always appreciated.

Take a look at the `Nits` section under `todo.md` for some entry-level PR ideas.

## License
Orng is released under the MIT license. See LICENSE for details.