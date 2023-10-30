This is a rough outline of how data flows through the different modules of the compiler, and how it's transformed.

module file source text ->
[lexer]       -> Stream of tokens ->
[layout]      -> Laid out stream of tokens ->
[parser]      -> AST ->
[symbol-tree] -> (AST, Symbol Tree) -> // Module name resolution is done here. Recursively parse module files when needed
[type-check]  -> (Typed AST, Symbol Tree) -> // All validations must be boiled down to type checks. Type decoration is done here.
[lower]       -> (CFG, Symbol Tree) ->
[optimizer]   -> (Optimized CFG, Symbol Tree) ->
[offset]      -> (Optimized CFG, Symbol Tree+offsets) ->
[module]      -> (Emplaced IR instructions, Symbol Tree+offsets).

After this process is done, the module is entirely compiled. Many modules together make up a program, which can be interpreted or codegen'd.