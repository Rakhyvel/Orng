/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _333_main(void);
int64_t _335_f(void);
int64_t _337_g(void);

/* Function definitions */
int64_t _333_main(void) {
    function0 _333_t0;
    int64_t _333_t1;
    int64_t _333_$retval;
    _333_t0 = _335_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _333_t1 = _333_t0();
    $line_idx--;
    _333_$retval = _333_t1;
    return _333_$retval;
}

int64_t _335_f(void) {
    function0 _335_t0;
    int64_t _335_t1;
    int64_t _335_$retval;
    _335_t0 = _337_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _335_t1 = _335_t0();
    $line_idx--;
    _335_$retval = _335_t1;
    return _335_$retval;
}

int64_t _337_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_333_main());
  return 0;
}
