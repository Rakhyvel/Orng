# The Orng Programming Language
<a href="#"><img src="budi.png" align="right" width="200"></a>
<div><a href="#"><img src="bumper.png"></a></div>

Orng is a versatile general purpose programming language that gives developers control while still being expressive. It is designed to be both lightweight and simple, making it a great choice for enthusiast programmers.

## Installation
```sh
# Orng compiler requires Zig 0.11.0 at the moment
git clone https://github.com/Rakhyvel/Orng.git
cd Orng
zig build run -- <path to your main .orng file>
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
* **Simple Syntax:** Orng has a clean and intuitive syntax that is easy to learn, and more importantly easy to read.
* **Seamless C ABI Interoperability:** Orng compiles directly to C, which affords it birectional interop with C. You can call existing C functions from Orng, and C functions can call Orng functions.
* **Refinement Types:** Orng has support for refinement types, which allows users to ergonomically put additional sanity checks on their types.
* **Algebraic Data Types and Pattern Matching:** Orng has support for sum-of-product types, and pattern matching on their constructors.
* **First-Class Types:** Types are first class in Orng, which means you can pass types to functions as arguments, and return them from functions.

## Contributing
We welcome contributions of all kinds! Bug reports, feature requests, code contributions and documentation updates are more than welcome.

## License
Orng is released under the MIT license. See LICENSE for details.