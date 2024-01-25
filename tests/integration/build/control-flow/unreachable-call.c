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
int64_t _495_main(void);
int64_t _497_f(void);
int64_t _499_g(void);


/* Function definitions */
int64_t _495_main(void){
    function0 _495_t0;
    int64_t _495_t1;
    int64_t _495_$retval;
    _495_t0 = _497_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _495_t1 = _495_t0();
    $line_idx--;
    _495_$retval = _495_t1;
    return _495_$retval;
}

int64_t _497_f(void){
    function0 _497_t0;
    int64_t _497_t1;
    int64_t _497_$retval;
    _497_t0 = _499_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _497_t1 = _497_t0();
    $line_idx--;
    _497_$retval = _497_t1;
    return _497_$retval;
}

int64_t _499_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_495_main());
  return 0;
}
