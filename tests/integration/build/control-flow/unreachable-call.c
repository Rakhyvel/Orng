/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _170_main(void);
int64_t _172_f(void);
int64_t _174_g(void);

/* Function definitions */
int64_t _170_main(void) {
    function0 _170_t0;
    int64_t _170_t1;
    int64_t _170_$retval;
    _170_t0 = _172_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _170_t1 = _170_t0();
    $line_idx--;
    _170_$retval = _170_t1;
    return _170_$retval;
}

int64_t _172_f(void) {
    function0 _172_t0;
    int64_t _172_t1;
    int64_t _172_$retval;
    _172_t0 = _174_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _172_t1 = _172_t0();
    $line_idx--;
    _172_$retval = _172_t1;
    return _172_$retval;
}

int64_t _174_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_170_main());
  return 0;
}
