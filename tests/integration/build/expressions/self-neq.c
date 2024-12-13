/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _880_main(void);
uint8_t _885_f(int64_t _885_x);


/* Function definitions */
int64_t _880_main(void){
    function0 _880_t1;
    int64_t _880_t3;
    uint8_t _880_t2;
    int64_t _880_t0;
    int64_t _880_$retval;
    _880_t1 = (function0) _885_f;
    _880_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _880_t2 = _880_t1(_880_t3);
    $line_idx--;
    if (_880_t2) {
        goto BB1061;
    } else {
        goto BB1065;
    }
BB1061:
    _880_t0 = 0;
    goto BB1064;
BB1065:
    _880_t0 = 223;
    goto BB1064;
BB1064:
    _880_$retval = _880_t0;
    return _880_$retval;
}

uint8_t _885_f(int64_t _885_x){
    uint8_t _885_$retval;
    (void)_885_x;
    goto BB1056;
BB1056:
    _885_$retval = 0;
    return _885_$retval;
}


int main(void) {
  printf("%ld",_880_main());
  return 0;
}
