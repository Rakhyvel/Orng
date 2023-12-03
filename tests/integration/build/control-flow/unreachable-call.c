/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _231_main(void);
int64_t _233_f(void);
int64_t _235_g(void);

/* Function definitions */
int64_t _231_main(void) {
    function0 _231_t0;
    int64_t _231_t1;
    int64_t _231_$retval;
    _231_t0 = _233_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _231_t1 = _231_t0();
    $line_idx--;
    _231_$retval = _231_t1;
    return _231_$retval;
}

int64_t _233_f(void) {
    function0 _233_t0;
    int64_t _233_t1;
    int64_t _233_$retval;
    _233_t0 = _235_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _233_t1 = _233_t0();
    $line_idx--;
    _233_$retval = _233_t1;
    return _233_$retval;
}

int64_t _235_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_231_main());
  return 0;
}
