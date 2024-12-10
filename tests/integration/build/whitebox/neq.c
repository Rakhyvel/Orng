/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2007_main(void);


/* Function definitions */
int64_t _2007_main(void){
    int64_t _2008_x;
    int64_t* _2008_y;
    int64_t _2007_t5;
    uint8_t _2007_t7;
    int64_t _2007_t4;
    int64_t _2007_$retval;
    int64_t _2007_t9;
    uint8_t _2007_t10;
    int64_t _2007_t11;
    uint8_t _2007_t12;
    _2008_x = 3;
    _2008_y = &_2008_x;
    _2007_t5 = 5;
    _2007_t7 = *_2008_y==_2007_t5;
    if (_2007_t7) {
        goto BB2198;
    } else {
        goto BB2200;
    }
BB2198:
    _2007_t9 = 4;
    _2007_t10 = _2007_t9>*_2008_y;
    if (_2007_t10) {
        goto BB2200;
    } else {
        goto BB2205;
    }
BB2200:
    _2007_t11 = 3;
    _2007_t12 = *_2008_y>=_2007_t11;
    if (_2007_t12) {
        goto BB2201;
    } else {
        goto BB2205;
    }
BB2205:
    _2007_t4 = 10;
    goto BB2204;
BB2201:
    _2007_t4 = 33;
    goto BB2204;
BB2204:
    _2007_$retval = _2007_t4;
    return _2007_$retval;
}


int main(void) {
  printf("%ld",_2007_main());
  return 0;
}
