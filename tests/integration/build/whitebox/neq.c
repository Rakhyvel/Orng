/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1812_main(void);


/* Function definitions */
int64_t _1812_main(void){
    int64_t _1813_x;
    int64_t* _1813_y;
    int64_t _1812_t5;
    uint8_t _1812_t7;
    int64_t _1812_t4;
    int64_t _1812_$retval;
    int64_t _1812_t9;
    uint8_t _1812_t10;
    int64_t _1812_t11;
    uint8_t _1812_t12;
    _1813_x = 3;
    _1813_y = &_1813_x;
    _1812_t5 = 5;
    _1812_t7 = *_1813_y==_1812_t5;
    if (_1812_t7) {
        goto BB2043;
    } else {
        goto BB2045;
    }
BB2043:
    _1812_t9 = 4;
    _1812_t10 = _1812_t9>*_1813_y;
    if (_1812_t10) {
        goto BB2045;
    } else {
        goto BB2050;
    }
BB2045:
    _1812_t11 = 3;
    _1812_t12 = *_1813_y>=_1812_t11;
    if (_1812_t12) {
        goto BB2046;
    } else {
        goto BB2050;
    }
BB2050:
    _1812_t4 = 10;
    goto BB2049;
BB2046:
    _1812_t4 = 33;
    goto BB2049;
BB2049:
    _1812_$retval = _1812_t4;
    return _1812_$retval;
}


int main(void) {
  printf("%ld",_1812_main());
  return 0;
}
