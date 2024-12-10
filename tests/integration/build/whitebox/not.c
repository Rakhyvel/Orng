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
int64_t _2013_main(void);
int64_t _2015_f(uint8_t _2015_b);


/* Function definitions */
int64_t _2013_main(void){
    int64_t _2014_x;
    int64_t* _2014_y;
    function0 _2013_t4;
    int64_t _2013_t6;
    uint8_t _2013_t8;
    uint8_t _2013_t7;
    uint8_t _2013_t9;
    int64_t _2013_t5;
    int64_t _2013_$retval;
    _2014_x = 0;
    _2014_y = &_2014_x;
    _2013_t4 = (function0) _2015_f;
    _2013_t6 = 1;
    _2013_t8 = *_2014_y==_2013_t6;
    if (_2013_t8) {
        goto BB2216;
    } else {
        goto BB2219;
    }
BB2216:
    _2013_t7 = 1;
    goto BB2217;
BB2219:
    _2013_t7 = 0;
    goto BB2217;
BB2217:
    _2013_t9 = !_2013_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _2013_t5 = _2013_t4(_2013_t9);
    $line_idx--;
    _2013_$retval = _2013_t5;
    return _2013_$retval;
}

int64_t _2015_f(uint8_t _2015_b){
    uint8_t _2015_t0;
    uint8_t _2015_t1;
    int64_t _2015_t2;
    int64_t _2015_$retval;
    _2015_t0 = !_2015_b;
    _2015_b = _2015_t0;
    _2015_t1 = !_2015_t0;
    _2015_b = _2015_t1;
    if (_2015_t0) {
        goto BB2213;
    } else {
        goto BB2209;
    }
BB2213:
    _2015_t2 = 10;
    goto BB2212;
BB2209:
    _2015_t2 = 31;
    goto BB2212;
BB2212:
    _2015_$retval = _2015_t2;
    return _2015_$retval;
}


int main(void) {
  printf("%ld",_2013_main());
  return 0;
}
