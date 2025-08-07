
<div align="center">
    <a href="#"><img src="docs/budi.png" alt="Budi the Orangutan!" width="30%"></a>
    <h6><em>For When Life Gives You Orngs...</em></h6>
    <h1>Orng Programming Language</h1>
</div>

> **⚠️WARNING**! Orng is still a work in progress! Expect exciting changes and improvements.

## 🍊 What is Orng?

Orng is a versatile systems programming language I've been developing that gives developers control without sacrificing expressiveness. It is designed to be both lightweight and simple, making it a great choice for enthusiasts and professionals alike.

* Visit [the website (coming soon)](http://ornglang.org) to learn more about Orng.
* Tutorials can be found [here (coming soon)](http://ornglang.orng/tutorials).
* Documentation can be found [here (coming soon)](http://ornglang.orng/docs).

## Quick Start
```sh
# Orng compiler requires Zig 0.13.0 at the moment
git clone --recursive https://github.com/Rakhyvel/Orng.git

# Set the Orng Standard Library path environment variable
# For Linux:
export ORNG_STD_PATH="/wherever/you/put/Orng/std"
# For Windows:
$env:ORNG_STD_PATH="/wherever/you/put/Orng/std"

# Build Orng
cd Orng
zig build orng
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
orng run
```

## Standout Features
Orng comes with a wide range of features that make it a powerful and flexible programming language, including:

### First-Class Types
In Orng, types are values. You can pass them to functions, return them, match on them, and construct them programmatically.
```rs
fn make_array_type(const n: Int, const T: Type) -> Type { [n]T }

fn main() {
    let x: template(4, Char) = ('1', '2', '3', '4')
    println("{c} squared is 9", x[3])
}
```
[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/generics)

### Pattern Matching & Destructuring
Pattern matching in Orng lets you elagantly deconstruct complex data structures with a single, readable expression. Forget verbose `if-else` chains and nested conditionals - match on ADTs, extract values, and handle different cases with unprecedented clarity.

```rs
const Person = (name: String, age: Int, job: String)

fn classify_person(person: Person) -> String {
   match person {
       (name, age, "Teacher") if age > 50 => "Veteran Educator"
       (name, _,   "Doctor")              => "Medical professional"
       (_,    age, _)         if age < 18 => "Baby 👶"
   }
}
```

[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/pattern)

### Algebraic Data Types
Algebraic Data Types (ADTs) allow you to define types that can be one of several variants with zero runtime overhead. Represent complex state machines, parse abstract syntax trees, or handle error conditons with a single, compact type definition.

```rs
const Shape = (
    | circle: (radius: Float)
    | rectangle: (width: Float, height: Float)
    | triangle: (base: Float, height: Float))

fn calculate_area(shape: Shape) -> Float {
    match shape {
        .circle(r)         => 3.14 * r * r
        .rectangle(w, h)   => w * h
        .triangle(b, h)    => 0.5 * b * h
    }
}
```

[More](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/sums) [examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/tuples)

### Seamless C Interoperability
Compile to C and parse C header files with ease. Orng bridges the gap between low-level system programming and high-level expressiveness.

[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/build)

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

<!--
### Higher-Kinded Types
Orng supports higher-kinded types, natively.
```rs
fn Vec(const n: Int, const T: Type) -> Type {
    [n]T
}

// Implement add for Vec of any length of any type that also implements Add
impl Add for Vec($n, $T impl Add) {
    const Output: Type = Self

    fn add(self, rhs: Self) -> Self::Output {
        let mut retval: Vec(n, T) = undefiend
        inline for i in 0..n {
            retval[i] = self[i] + rhs[i]
        }
        retval
    }
}

impl Functor for Option($T) {
    fn fmap(self: Option(T), f: T -> $U) -> 
}

test "using + for vecs" {
    let v: Vec(3, Int) = (1, 2, 4)
    let u: Vec(3, Int) = (4, 4, 4)

    let w = u + v

    testing::expect(w == (5, 6, 8))
}
```

### Universal and Existential Quantifiers
The universal quantifier allows you to make assertions about all elements in a product or sum type. This is helpful for generic variadics.
```rs
trait Display {
    fn display(&self, writer: &mut dyn Writer)
}

fn print(const fmt: String, args: (_, ...))
where 
  // all args must be display type
  forall A in @Typeof(args) { A <: Display }
{
    let writer = // ...
    inline for arg in args {
        // Passes type check, since all arg in args implement Display
        arg.>display(writer)
    }
}
```

The existential quantifier is useful for simulating row-polymorphism.
```rs
fn greet(person: (_, ...), out: &mut dyn Writer) 
where
  // There is a field in the product type of `person` called name of type String
  exists T in @typeof(person) { T == (name: String) }
{
    // Passes type check, since there is gauranteed to be a field `name` in person
    Writer::print(out, "Hello, {s}!", person.name)
}
```
-->

[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/traits)

## How to Contribute

Contributions of all kinds are welcome:
- 🐛 Report bugs
- 📝 Improve documentation
- 💡 Suggest features
- 🧑‍💻 Submit pull requests

Check out [CONTRIBUTING.md](https://github.com/Rakhyvel/Orng/blob/main/CONTRIBUTING.md) for more info!

## License
Orng is open-source and released under the MIT License. See `LICENSE` for details.