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
int64_t _516_main(void);
int64_t _518_f(void);
int64_t _520_g(void);


/* Function definitions */
int64_t _516_main(void){
    function0 _516_t0;
    int64_t _516_t1;
    int64_t _516_$retval;
    _516_t0 = (function0) _518_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _516_t1 = _516_t0();
    $line_idx--;
    _516_$retval = _516_t1;
    return _516_$retval;
}

int64_t _518_f(void){
    function0 _518_t0;
    int64_t _518_t1;
    int64_t _518_$retval;
    _518_t0 = (function0) _520_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _518_t1 = _518_t0();
    $line_idx--;
    _518_$retval = _518_t1;
    return _518_$retval;
}

int64_t _520_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_516_main());
  return 0;
}
