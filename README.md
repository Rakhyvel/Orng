![Budi the Monkey!](https://github.com/Rakhyvel/Orng/blob/main/budi.png)
###### Budi the Orangutan, mascot of the Orng Programming Language

Orng is a fast, expressive general purpose programming language that compiles to C!

## Planned Features
* A clean, indentation based syntax
* Seamless bidirectional C ABI interop
* Blazingly fast compilation speeds!
* Generic and Alegbraic Data Types
    -   ```rs
        fn LinkedList: (const T: Type)->Type
            = nil
            | node: (data: T, next: &LinkedList)

        // You can then pattern match on ADTs
        fn length: (list: &LinkedList, acc: Int \ 0)->Int =
            case list^
            | nil            => acc
            | node(_, next') => length(next', acc + 1)
        ```
* Refinement types
    - ```rs
      // An int `n` is in the `Evens` type if n % 2 == 0
      const Evens: Type = n: Int where n % 2 == 0
      ```
* Generic type constraints
    - ```rs
      // The type `T'` will be inferred based on the arguments
      fn contains: (haystack: []T', needle: T')->Bool 
      where T' impls Eq =
          for hay in haystack
              if hay == needle
                  return true
          false
      ```

## Installation
```sh
# Orng requires Zig version 0.11.0

git clone https://github.com/Rakhyvel/Orng.git
cd Orng
zig build run
```