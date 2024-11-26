
<div align="center">
    <a href="#"><img src="docs/budi.png" alt="Budi the Orangutan!" width="30%"></a>
    <h6><em>For When Live Gives You Orngs...</em></h6>
    <h1>Orng Programming Language</h1>
</div>

> **⚠️WARNING**! Orng is still a work in progress! Expect exciting changes and improvements.

## 🍊 What is Orng?

Orng is a versatile systems programming language that gives developers control without sacrificing expressiveness. It is designed to be both lightweight and simple, making it a great choice for enthusiasts and professionals alike.

* Visit [the website (coming soon)](http://ornglang.org) to learn more about Orng.
* Tutorials can be found [here (coming soon)](http://ornglang.orng/tutorials).
* Documentation can be found [here (coming soon)](http://ornglang.orng/docs).

## 🚀 Quick Start
```sh
# Orng compiler requires Zig 0.13.0 at the moment
git clone https://github.com/Rakhyvel/Orng.git
cd Orng
zig build
```

A fancy hello-world example
```rs
fn main(sys: System) -> !() {
    greet("Orng! 🍊", sys.stdout) catch unreachable
}

fn greet(recipient: String, out: $T impl Writer) -> T::Error!() {
    try out.>println("Hello, {s}", recipient)
}
```

Run it with:
```sh
orng run hello.orng
```

## ✨ Standout Features
Orng comes with a wide range of features that make it a powerful and flexible programming language, including:

### First-Class Types
In Orng, types are first class citizens. Pass types as function arguments, return them from functions, and create powerful generic abstractions.

[Example](https://github.com/Rakhyvel/Orng/blob/main/examples/type-unification.orng)

### Parametric Effect System
Say goodbye to hidden side effects! Orng forbids global variables and requires all objects to be explicitly passed as parameters. This includes allocators, file writers, network sockets, making your program's behavior transparent and predictable.

[Example](https://github.com/Rakhyvel/Orng/blob/main/examples/type-unification.orng)

### Traits 
Traits offer a flexible way to define behavior that can be attatched to any type. Instead of deep inheritance hierarchies, Orng lets you extend types with new capabilities through simple composable traits.

[Example](https://github.com/Rakhyvel/Orng/blob/main/examples/type-unification.orng)

### Algebraic Data Types
Algebraic Data Types (ADTs) allow you to define types that can be one of several variants with zero runtime overhead. Represent complex state machines, parse abstract syntax trees, or handle error conditons with a single, compact type definition.

[Example](https://github.com/Rakhyvel/Orng/blob/main/examples/type-unification.orng)

### Pattern Matching & Destructuring
Pattern matching in Orng lets you elagantly deconstruct complex data structures with a single, readable expression. Forget verbose `if-else` chains and nested conditionals - match on ADTs, extract values, and handle different cases with unprecedented clarity.

[Example](https://github.com/Rakhyvel/Orng/blob/main/examples/type-unification.orng)

### Seamless C Interoperability
Compile to C and parse C header files with ease. Orng bridges the gap between low-level system programming and high-level expressiveness.

[Example](https://github.com/Rakhyvel/Orng/blob/main/examples/type-unification.orng)

## 🤝 Get Involved

We're passionate about building a community around Orng. Contributions of all kinds are welcome:
- 🐛 Report bugs
- 📝 Improve documentation
- 💡 Suggest features
- 🧑‍💻 Submit pull requests

## 📄 License
Orng is open-source and released under the MIT License. See `LICENSE` for details.