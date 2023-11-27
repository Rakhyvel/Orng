/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _201_main(void);
int64_t _203_f(void);
int64_t _205_g(void);

/* Function definitions */
int64_t _201_main(void) {
    function0 _201_t0;
    int64_t _201_t1;
    int64_t _201_$retval;
    _201_t0 = _203_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _201_t1 = _201_t0();
    $line_idx--;
    _201_$retval = _201_t1;
    return _201_$retval;
}

int64_t _203_f(void) {
    function0 _203_t0;
    int64_t _203_t1;
    int64_t _203_$retval;
    _203_t0 = _205_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _203_t1 = _203_t0();
    $line_idx--;
    _203_$retval = _203_t1;
    return _203_$retval;
}

int64_t _205_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_201_main());
  return 0;
}
