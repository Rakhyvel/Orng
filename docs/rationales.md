
# Rationales
> Because it is easy for little monkeys to forget!

## Breadcrumb-ability
Imagine you're working on a large C++ project, and you come across a file that looks something like this:
```c++
#include "file1.hpp"
#include "file2.hpp"
#include "file3.hpp"
// ...
#include "filen.hpp"

void some_class::Foo() {
    bar = baz.qux();
}
```
Okay, now tell me where the definitions for `some_class`, `bar`, `baz`, and `qux` are located? If you're lucky enough to have a fancy editor, you can usualy just ctrl+click to go-to-definition. But if you're not so lucky, there's virtually no other way to figure it out than to grep around. You're also out of luck even with grep, since there is no "waypoint" for definitions. Lastly, class fields in C++ are implicit, so there is no need to use a `this->` before them.

Thus, Orng shall:
    1. make it explicit where definitions come from
    2. make definitions match a simple regular expression
    3. have *no* implicit fields    
The same file above might look something like this in Orng:
```rust
const file1 = import("package-a/file1.orng")
const file2 = import("package-a/file2.orng")
const file3 = import("package-b/file3.orng")
// ...
const filen = import("package-c/filen.orng")

const Some_Struct = file2.Some_Struct

fn foo(self: &mut Some_Struct) -> () {
    self.bar = file1.qux()
}
```
Here it is immediately clear where everything comes from. `Some_Struct` was actually from `file2`. `bar` was actually a field of `Some_Struct`, and `qux` is a function from `file1`. We can also immediately see that `file3` isn't even needed, something that isn't trivial to do in C++.

Also notice that definitions *always* **always** ***always*** either start with an `fn` token for functions, or a `let` token for values. This makes it easy to grep for the definition of a function.

## Injective mapping from syntax to behavior
Probably the biggest gripe I have with languages like C++ is that it's near impossible to tell where side effects happen. Code can throw exceptions out from under you, functions can be called implicitly, there's no way to ctrl+f your way through a file to find where a variable is declared, type conversions are entirely implicit, etc.

Orng shall have a one-to-one correspondance between syntax and behavior. The way to model syntax is with ASTs, and the way to model behavior is through the codegen of an IR. So, for example, a call IR shall only be generated from a call AST. 

This does not necessarily go the other way, though. Through inlining optimizations, a call AST might not actually generate a call IR. I think this is fine.

## No `backtick identifiers`.
I thought it might be a cool idea if backticks could delimit the bounds of identifiers, so that you could have anything as an identifier. Keywords, spaces, symbols, all of it. However, now I am not so sure this is a good idea. Not only would this be rather unreadable, it would be trickier to codegen.

## No partially applied functions
Consider the following code snippet, where `>>` is the 'curry' operator:
```rs
// add is just a binop of Int
fn add: (x: Int, y: Int)->Int = x + y

fn apply: (x: Int, f: Int->Int)->Int = f(x)

fn id: (x: Int)->Int = x

fn main: (_: System)->!() =
    let add_5: Int->Int = 5 >> add
    let app_partial: Int = apply(4, add_5) // => 9
    let app_regular: Int = apply(4, id)    // => 4
```
Now, how would you convert this to C? The function `apply` might take both a partially applied function, and a regular function, both with types `Int->Int`. However, `add_5` ought to store its partially applied argument somewhere, and the C version of `apply` should know whether to call `f` with two arguments or one, whether `f` is partially applied or not.

One way to resolve this is to generate a different version of `apply`. One versions which takes a function pointer, and another which takes a partially applied function type with the arguments baked in. However, this quickly blows up. A function which takes n function parameters now needs 2^n copies of itself, not nice!

Another way is to treat all function pointers as potentially partially applied functions, and pass around structs like this around whenever you pass around function pointers:
```c
#define ARG_SIZE 255
typedef struct {
    void (*call_me_maybe)(void); // Can cast to whichever function type needed
    size_t args;
    uint8_t data[ARG_SIZE];
} callable;
```
However, this has other issues. Now, every single function call has this overhead of `ARG_SIZE` bytes. And if you decide to put `data` on the heap, you now have to worry about when to free `data`, or when to make copies, etc. Not to mention, this adds a tremendous overhead (a paper I found claimed 60x!) to normal function calls.

The final solution is to have the `>>` operator just be a simple function call re-write operator, like it is in most languages that have UFCS, and not have to worry about ANY of these issues.