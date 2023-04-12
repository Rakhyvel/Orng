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
* **Simple Syntax:** Orng has a clean and intuitive syntax that is easy to learn, and more importantly easy to read.
* **Seamless C ABI Interoperability:** Orng compiles directly to C, which affords it birectional interop with C. You can call existing C functions from Orng, and C functions can call Orng functions.
* **Refinement Types:** Orng has support for refinement types, which allows users to ergonomically put additional sanity checks on their types.
* **Algebraic Data Types and Pattern Matching:** Orng has support for sum-of-product types, and pattern matching on their constructors.
* **First-Class Types:** Types are first class in Orng, which means you can pass types to functions as arguments, and return them from functions.

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
```
### Interacting with C Files (SDL2)
```rs
// Orng will parse the SDL.h header file and allow us to use `sdl` as if it
// were an Orng module
const c = cImport("SDL.h")

const std = import("std")

const PossibleErrors 
    = SDLInitializationFailed: (what: String, why: [*]Word8)
    | _

fn main: (sys: System)->PossibleErrors!() =
    // Initialize SDL here, throw an error if it fails
    if (c.SDL_Init(sdl.SDL_INIT_VIDEO) < 0)
        throw PossibleErrors.SDLInitializationFailed("SDL_Init", c.SDL_GetError())
    defer c.SDL_Quit() // Ran when this defer goes out of scope

    // Initialize an SDL window here, throw error if it fails
    let screen = c.SDL_CreateWindow
        ( "My Window"
        , c.SDL_WINDOWPOS_UNDEFINED
        , c.SDL_WINDOWPOS_UNDEFINED
        , 300
        , 73
        , c.SDL_WINDOW_OPENGL
        ) orelse.
            throw PossibleErrors.SDLInitializationFailed("SDL_CreateWindow", c.SDL_GetError())
    defer c.SDL_DestroyWindow(screen)

    // Initialize an SDL renderer here, throw error if it fails
    let renderer = c.SDL_CreateRenderer(screen, -1, 0) orelse
        throw PossibleErrors.SDLInitializationFailed("SDL_CreateRenderer", c.SDL_GetError())
    
    // Enter main game loop
    while let mut quit = false; not quit
        while let mut event: c.SDL_Event; c.SDL_PollEvent(&event) != 0
            case event.type
                c.SDL_QUIT => {quit = true}
                else       => {}
        _ = renderer |> c.SDL_RenderClear()
        // do game stuff here
        c.SDL_RenderPresent(renderer)
        c.SDL_Delay(17)

```

## Contributing
We welcome contributions of all kinds! Bug reports, feature requests, code contributions and documentation updates are always appreciated.

## License
Orng is released under the MIT license. See LICENSE for details.