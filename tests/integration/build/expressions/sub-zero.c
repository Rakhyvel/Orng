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
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _880_t2 = _880_t1(_880_t3);
    $line_idx--;
    if (_880_t2) {
        goto BB1075;
    } else {
        goto BB1079;
    }
BB1075:
    _880_t0 = 184;
    goto BB1078;
BB1079:
    _880_t0 = 4;
    goto BB1078;
BB1078:
    _880_$retval = _880_t0;
    return _880_$retval;
}

uint8_t _885_f(int64_t _885_x){
    uint8_t _885_$retval;
    uint8_t _885_t0;
    int64_t _885_t6;
    int64_t _885_t7;
    uint8_t _885_t9;
    goto BB1065;
BB1065:
    _885_t6 = $negate_int64_t(_885_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _885_t7 = $negate_int64_t(_885_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _885_t9 = _885_t6==_885_t7;
    if (_885_t9) {
        goto BB1068;
    } else {
        goto BB1071;
    }
BB1068:
    _885_t0 = 1;
    goto BB1070;
BB1071:
    _885_t0 = 0;
    goto BB1070;
BB1070:
    _885_$retval = _885_t0;
    return _885_$retval;
}


int main(void) {
  printf("%ld",_880_main());
  return 0;
}
