/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _499_main(void);
int64_t _501_f(void);
int64_t _503_g(void);


/* Function definitions */
int64_t _499_main(void){
    function0 _499_t0;
    int64_t _499_t1;
    int64_t _499_$retval;
    _499_t0 = (function0) _501_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _499_t1 = _499_t0();
    $line_idx--;
    _499_$retval = _499_t1;
    return _499_$retval;
}

int64_t _501_f(void){
    function0 _501_t0;
    int64_t _501_t1;
    int64_t _501_$retval;
    _501_t0 = (function0) _503_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _501_t1 = _501_t0();
    $line_idx--;
    _501_$retval = _501_t1;
    return _501_$retval;
}

int64_t _503_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_499_main());
  return 0;
}
