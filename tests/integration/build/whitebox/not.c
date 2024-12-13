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
int64_t _2015_main(void);
int64_t _2017_f(uint8_t _2017_b);


/* Function definitions */
int64_t _2015_main(void){
    int64_t _2016_x;
    int64_t* _2016_y;
    function0 _2015_t4;
    int64_t _2015_t6;
    uint8_t _2015_t8;
    uint8_t _2015_t7;
    uint8_t _2015_t9;
    int64_t _2015_t5;
    int64_t _2015_$retval;
    _2016_x = 0;
    _2016_y = &_2016_x;
    _2015_t4 = (function0) _2017_f;
    _2015_t6 = 1;
    _2015_t8 = *_2016_y==_2015_t6;
    if (_2015_t8) {
        goto BB2218;
    } else {
        goto BB2221;
    }
BB2218:
    _2015_t7 = 1;
    goto BB2219;
BB2221:
    _2015_t7 = 0;
    goto BB2219;
BB2219:
    _2015_t9 = !_2015_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _2015_t5 = _2015_t4(_2015_t9);
    $line_idx--;
    _2015_$retval = _2015_t5;
    return _2015_$retval;
}

int64_t _2017_f(uint8_t _2017_b){
    uint8_t _2017_t0;
    uint8_t _2017_t1;
    int64_t _2017_t2;
    int64_t _2017_$retval;
    _2017_t0 = !_2017_b;
    _2017_b = _2017_t0;
    _2017_t1 = !_2017_t0;
    _2017_b = _2017_t1;
    if (_2017_t0) {
        goto BB2215;
    } else {
        goto BB2211;
    }
BB2215:
    _2017_t2 = 10;
    goto BB2214;
BB2211:
    _2017_t2 = 31;
    goto BB2214;
BB2214:
    _2017_$retval = _2017_t2;
    return _2017_$retval;
}


int main(void) {
  printf("%ld",_2015_main());
  return 0;
}
