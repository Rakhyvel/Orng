/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _356_main(void);
int64_t _358_f(void);
int64_t _360_g(void);

/* Function definitions */
int64_t _356_main(void) {
    function0 _356_t0;
    int64_t _356_t1;
    int64_t _356_$retval;
    _356_t0 = _358_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _356_t1 = _356_t0();
    $line_idx--;
    _356_$retval = _356_t1;
    return _356_$retval;
}

int64_t _358_f(void) {
    function0 _358_t0;
    int64_t _358_t1;
    int64_t _358_$retval;
    _358_t0 = _360_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _358_t1 = _358_t0();
    $line_idx--;
    _358_$retval = _358_t1;
    return _358_$retval;
}

int64_t _360_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_356_main());
  return 0;
}
