
<div align="center">
    <a href="#"><img src="docs/budi.png" alt="Budi the Orangutan!" width="30%"></a>
    <h6><em>For When Live Gives You Orngs...</em></h6>
    <h1>Orng Programming Language</h1>
</div>

> **⚠️WARNING**! Orng is still a work in progress! Expect exciting changes and improvements.

## 🍊 What is Orng?

Orng is a versatile systems programming language I've been developing that gives developers control without sacrificing expressiveness. It is designed to be both lightweight and simple, making it a great choice for enthusiasts and professionals alike.

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

A fancy hello-world example:
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

```rs
fn make_array_type(const n: Int, const T: Type) -> Type { [n]T }

fn main() {
    let x: template(4, Char) = ('1', '2', '3', '4')
    println("{c} squared is 9", x[3])
}
```
[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/generics)

### Parametric Effect System
Say goodbye to hidden side effects! Orng forbids global variables and requires all objects to be explicitly passed as parameters, making your program's behavior transparent and predictable.

```rs
// We can tell this function doesn't do anything dangerous
fn something_harmless(x: T) { /* ... */ }

// We can tell this function probably mutates it's arguments
fn maybe_mutate(x: &mut T) { /* ... */ }

// We can tell this function probably allocates memory
fn maybe_alloc(alloc: impl Allocator) { /* ... */ }

// We can tell this function probably does stuff with IO
fn maybe_write(reader: impl Reader, writer: impl Writer) { /* ... */ }
```

### Traits 
Traits offer a flexible way to define behavior that can be attatched to any type. Instead of deep inheritance hierarchies, Orng lets you extend types with new capabilities through simple composable traits.

```rs
trait Counter {
    fn increment(&mut self) -> Int
    fn total(&self) -> Int
    fn reset(&mut self) -> ()
}

impl Counter for (count: Int, max: Int) {
    fn increment(&mut self) -> Int {
        self.count = (self.count + 1) % self.max
        self.count
    }
    
    fn total(&self) -> Int { self.count }
    
    fn reset(&mut self) -> () { self.count = 0 }
}

fn main(sys: System) -> !() {
    let mut counter = (0, 5)
    try sys.stdout.>println("{d}", counter.>increment())  // Prints 1
    try sys.stdout.>println("{d}", counter.>increment())  // Prints 2
}
```

[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/traits)

### Algebraic Data Types
Algebraic Data Types (ADTs) allow you to define types that can be one of several variants with zero runtime overhead. Represent complex state machines, parse abstract syntax trees, or handle error conditons with a single, compact type definition.

```rs
const Shape = (
    circle: (radius: Float) | 
    rectangle: (width: Float, height: Float) | 
    triangle: (base: Float, height: Float)
)

fn calculate_area(shape: Shape) -> Float {
    match shape {
        .circle(r)         => 3.14 * r * r
        .rectangle(w, h)   => w * h
        .triangle(b, h)    => 0.5 * b * h
    }
}
```

[More](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/sums) [examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/tuples)

### Pattern Matching & Destructuring
Pattern matching in Orng lets you elagantly deconstruct complex data structures with a single, readable expression. Forget verbose `if-else` chains and nested conditionals - match on ADTs, extract values, and handle different cases with unprecedented clarity.

```rs
const Person = (name: String, age: Int, job: String)

fn classify_person(person: Person) -> String {
   match person {
       (name, age, "Teacher") when age > 50 => "Veteran Educator"
       (name, _,   "Doctor")                => "Medical professional"
       (_,    age, _)         when age < 18 => "Baby 👶"
   }
}
```

[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/pattern)

### Seamless C Interoperability
Compile to C and parse C header files with ease. Orng bridges the gap between low-level system programming and high-level expressiveness.

[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/build)

## 🤝 Get Involved

Contributions of all kinds are welcome:
- 🐛 Report bugs
- 📝 Improve documentation
- 💡 Suggest features
- 🧑‍💻 Submit pull requests

Check out [CONTRIBUTING.md](https://github.com/Rakhyvel/Orng/blob/main/CONTRIBUTING.md) for more info!

## 📄 License
Orng is open-source and released under the MIT License. See `LICENSE` for details.