/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _258_main(void);
int64_t _260_f(void);
int64_t _262_g(void);

/* Function definitions */
int64_t _258_main(void) {
    function0 _258_t0;
    int64_t _258_t1;
    int64_t _258_$retval;
    _258_t0 = _260_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _258_t1 = _258_t0();
    $line_idx--;
    _258_$retval = _258_t1;
    return _258_$retval;
}

int64_t _260_f(void) {
    function0 _260_t0;
    int64_t _260_t1;
    int64_t _260_$retval;
    _260_t0 = _262_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _260_t1 = _260_t0();
    $line_idx--;
    _260_$retval = _260_t1;
    return _260_$retval;
}

int64_t _262_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_258_main());
  return 0;
}
