/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1993_main(void);
int64_t _1995_f(uint8_t _1995_b);


/* Function definitions */
int64_t _1993_main(void){
    int64_t _1994_x;
    int64_t* _1994_y;
    function0 _1993_t4;
    int64_t _1993_t6;
    uint8_t _1993_t8;
    uint8_t _1993_t7;
    uint8_t _1993_t9;
    int64_t _1993_t5;
    int64_t _1993_$retval;
    _1994_x = 0;
    _1994_y = &_1994_x;
    _1993_t4 = (function0) _1995_f;
    _1993_t6 = 1;
    _1993_t8 = *_1994_y==_1993_t6;
    if (_1993_t8) {
        goto BB2197;
    } else {
        goto BB2200;
    }
BB2197:
    _1993_t7 = 1;
    goto BB2198;
BB2200:
    _1993_t7 = 0;
    goto BB2198;
BB2198:
    _1993_t9 = !_1993_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1993_t5 = _1993_t4(_1993_t9);
    $line_idx--;
    _1993_$retval = _1993_t5;
    return _1993_$retval;
}

int64_t _1995_f(uint8_t _1995_b){
    uint8_t _1995_t0;
    uint8_t _1995_t1;
    int64_t _1995_t2;
    int64_t _1995_$retval;
    _1995_t0 = !_1995_b;
    _1995_b = _1995_t0;
    _1995_t1 = !_1995_t0;
    _1995_b = _1995_t1;
    if (_1995_t0) {
        goto BB2194;
    } else {
        goto BB2190;
    }
BB2194:
    _1995_t2 = 10;
    goto BB2193;
BB2190:
    _1995_t2 = 31;
    goto BB2193;
BB2193:
    _1995_$retval = _1995_t2;
    return _1995_$retval;
}


int main(void) {
  printf("%ld",_1993_main());
  return 0;
}
