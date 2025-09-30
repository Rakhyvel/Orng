
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
fn main() uses core.System {
    @print("Enter your name here: ")

    let name_buf = core.String_Buffer.new()
    defer name_buf.dispose()
    stdin.readln(&name_buf)

    greet(name_buf.str())
}

fn greet(recipient: String) uses .. {
    @println("Hello, {recipient}")
}
```

Run it with:
```sh
orng run
```

## Standout Features
Orng comes with a wide range of features that make it a powerful and flexible programming language, including:

### Algebraic Data Types & Pattern Matching
Algebraic Data Types (ADTs) allow you to define types that can be one of several variants with zero runtime overhead. Pattern matching in Orng lets you elagantly deconstruct those ADTs with a single, readable expression.

```rs
enum Expr {
    num(Int)
    add(&Expr, &Expr)
    mul(&Expr, &Expr)
}

fn eval(e: Expr) -> Int {
    match e {
        Expr.num(n)         => n
        Expr.add(lhs, rhs)  => eval(lhs) + eval(rhs)
        Expr.mul(lhs, rhs)  => eval(lhs) * eval(rhs)
    }
}
```

[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/pattern)

### Generics & Traits
Geerics and traits offer a flexible way to write code for any type.

```rs
trait Ord {
    fn lt(self, other: Self) -> Bool
}

fn max[T: Ord](a: T, b: T) -> T {
    if a.lt(b) { b } else { a }
}

impl Ord for Int {
    fn lt(self, other: Int) -> Bool { self < other }
}

fn main() uses core.System {
    let x = max(10, 20)
    @println("max is {x}")
}
```

### Seamless C Interoperability
Compile to C and parse C header files with ease. Orng bridges the gap between low-level system programming and high-level expressiveness.

[More examples](https://github.com/Rakhyvel/Orng/blob/main/tests/integration/build)

### Arbitrary Compile-Time Execution
Orng has a robust compile-time execution model that allows any function to be ran at compile-time.

```rs
fn compile_regex(pattern: String) -> Regex {
    // normal code: parse, build NFA, determinize, minimize…
}

const number_regex = compile_regex("[0-9]+") // regex compiled at compile-time

fn main() uses core.System {
    if number_regex.matches("12345") {
        @println("Matched a number!")
    }
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