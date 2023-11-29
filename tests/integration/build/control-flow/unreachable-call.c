/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _354_main(void);
int64_t _356_f(void);
int64_t _358_g(void);

/* Function definitions */
int64_t _354_main(void) {
    function0 _354_t0;
    int64_t _354_t1;
    int64_t _354_$retval;
    _354_t0 = _356_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _354_t1 = _354_t0();
    $line_idx--;
    _354_$retval = _354_t1;
    return _354_$retval;
}

int64_t _356_f(void) {
    function0 _356_t0;
    int64_t _356_t1;
    int64_t _356_$retval;
    _356_t0 = _358_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _356_t1 = _356_t0();
    $line_idx--;
    _356_$retval = _356_t1;
    return _356_$retval;
}

int64_t _358_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_354_main());
  return 0;
}
