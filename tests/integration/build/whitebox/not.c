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
int64_t _1998_main(void);
int64_t _2000_f(uint8_t _2000_b);


/* Function definitions */
int64_t _1998_main(void){
    int64_t _1999_x;
    int64_t* _1999_y;
    function0 _1998_t4;
    int64_t _1998_t6;
    uint8_t _1998_t8;
    uint8_t _1998_t7;
    uint8_t _1998_t9;
    int64_t _1998_t5;
    int64_t _1998_$retval;
    _1999_x = 0;
    _1999_y = &_1999_x;
    _1998_t4 = (function0) _2000_f;
    _1998_t6 = 1;
    _1998_t8 = *_1999_y==_1998_t6;
    if (_1998_t8) {
        goto BB2200;
    } else {
        goto BB2203;
    }
BB2200:
    _1998_t7 = 1;
    goto BB2201;
BB2203:
    _1998_t7 = 0;
    goto BB2201;
BB2201:
    _1998_t9 = !_1998_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1998_t5 = _1998_t4(_1998_t9);
    $line_idx--;
    _1998_$retval = _1998_t5;
    return _1998_$retval;
}

int64_t _2000_f(uint8_t _2000_b){
    uint8_t _2000_t0;
    uint8_t _2000_t1;
    int64_t _2000_t2;
    int64_t _2000_$retval;
    _2000_t0 = !_2000_b;
    _2000_b = _2000_t0;
    _2000_t1 = !_2000_t0;
    _2000_b = _2000_t1;
    if (_2000_t0) {
        goto BB2197;
    } else {
        goto BB2193;
    }
BB2197:
    _2000_t2 = 10;
    goto BB2196;
BB2193:
    _2000_t2 = 31;
    goto BB2196;
BB2196:
    _2000_$retval = _2000_t2;
    return _2000_$retval;
}


int main(void) {
  printf("%ld",_1998_main());
  return 0;
}
