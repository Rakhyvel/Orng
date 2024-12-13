/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2009_main(void);


/* Function definitions */
int64_t _2009_main(void){
    int64_t _2010_x;
    int64_t* _2010_y;
    int64_t _2009_t5;
    uint8_t _2009_t7;
    int64_t _2009_t4;
    int64_t _2009_$retval;
    int64_t _2009_t9;
    uint8_t _2009_t10;
    int64_t _2009_t11;
    uint8_t _2009_t12;
    _2010_x = 3;
    _2010_y = &_2010_x;
    _2009_t5 = 5;
    _2009_t7 = *_2010_y==_2009_t5;
    if (_2009_t7) {
        goto BB2200;
    } else {
        goto BB2202;
    }
BB2200:
    _2009_t9 = 4;
    _2009_t10 = _2009_t9>*_2010_y;
    if (_2009_t10) {
        goto BB2202;
    } else {
        goto BB2207;
    }
BB2202:
    _2009_t11 = 3;
    _2009_t12 = *_2010_y>=_2009_t11;
    if (_2009_t12) {
        goto BB2203;
    } else {
        goto BB2207;
    }
BB2207:
    _2009_t4 = 10;
    goto BB2206;
BB2203:
    _2009_t4 = 33;
    goto BB2206;
BB2206:
    _2009_$retval = _2009_t4;
    return _2009_$retval;
}


int main(void) {
  printf("%ld",_2009_main());
  return 0;
}
