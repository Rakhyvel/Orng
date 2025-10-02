# tests/

Here you will find integration and negative tests. The `integration/` directory contains example Orange code, and is a good place to get a feel for the language. 

## Testing Ideology

> What you don't test, breaks.

Orange development has three testing strategies:
- __Integration tests__: ensure that valid programs compile, and produce expected behavior and output.
- __Negative tests__: ensure that invalid programs do not compile and are apropriately rejected.
- __Fuzz tests__: ensure that the compiler never crashes under strange input.

These three tests act as a pincer for the compiler, and ensure that all correct programs compile successfully, that all incorrect programs are reported as errant, and that the compiler never crashes. Together, they provide a comprehensive safety net that preserves the compiler's reliability and robustness in all scenarios.
