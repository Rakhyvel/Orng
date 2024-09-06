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
int64_t _494_main(void);
int64_t _496_f(void);
int64_t _498_g(void);


/* Function definitions */
int64_t _494_main(void){
    function0 _494_t0;
    int64_t _494_t1;
    int64_t _494_$retval;
    _494_t0 = (function0) _496_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _494_t1 = _494_t0();
    $line_idx--;
    _494_$retval = _494_t1;
    return _494_$retval;
}

int64_t _496_f(void){
    function0 _496_t0;
    int64_t _496_t1;
    int64_t _496_$retval;
    _496_t0 = (function0) _498_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _496_t1 = _496_t0();
    $line_idx--;
    _496_$retval = _496_t1;
    return _496_$retval;
}

int64_t _498_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_494_main());
  return 0;
}
