/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _239_main(void);
int64_t _241_f(void);
int64_t _243_g(void);

/* Function definitions */
int64_t _239_main(void) {
    function0 _239_t0;
    int64_t _239_t1;
    int64_t _239_$retval;
    _239_t0 = _241_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _239_t1 = _239_t0();
    $line_idx--;
    _239_$retval = _239_t1;
    return _239_$retval;
}

int64_t _241_f(void) {
    function0 _241_t0;
    int64_t _241_t1;
    int64_t _241_$retval;
    _241_t0 = _243_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _241_t1 = _241_t0();
    $line_idx--;
    _241_$retval = _241_t1;
    return _241_$retval;
}

int64_t _243_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_239_main());
  return 0;
}
