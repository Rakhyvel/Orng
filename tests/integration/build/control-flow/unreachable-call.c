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
int64_t _502_main(void);
int64_t _504_f(void);
int64_t _506_g(void);


/* Function definitions */
int64_t _502_main(void){
    function0 _502_t0;
    int64_t _502_t1;
    int64_t _502_$retval;
    _502_t0 = (function0) _504_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _502_t1 = _502_t0();
    $line_idx--;
    _502_$retval = _502_t1;
    return _502_$retval;
}

int64_t _504_f(void){
    function0 _504_t0;
    int64_t _504_t1;
    int64_t _504_$retval;
    _504_t0 = (function0) _506_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _504_t1 = _504_t0();
    $line_idx--;
    _504_$retval = _504_t1;
    return _504_$retval;
}

int64_t _506_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_502_main());
  return 0;
}
