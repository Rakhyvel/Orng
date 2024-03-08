/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1790_main(void);


/* Function definitions */
int64_t _1790_main(void){
    int64_t _1791_x;
    int64_t* _1791_y;
    int64_t _1790_t3;
    uint8_t _1790_t5;
    int64_t _1790_t2;
    int64_t _1790_$retval;
    int64_t _1790_t7;
    uint8_t _1790_t8;
    int64_t _1790_t9;
    uint8_t _1790_t10;
    _1791_x = 3;
    _1791_y = &_1791_x;
    _1790_t3 = 5;
    _1790_t5 = *_1791_y==_1790_t3;
    if (_1790_t5) {
        goto BB2044;
    } else {
        goto BB2046;
    }
BB2044:
    _1790_t7 = 4;
    _1790_t8 = _1790_t7>*_1791_y;
    if (_1790_t8) {
        goto BB2046;
    } else {
        goto BB2051;
    }
BB2046:
    _1790_t9 = 3;
    _1790_t10 = *_1791_y>=_1790_t9;
    if (_1790_t10) {
        goto BB2047;
    } else {
        goto BB2051;
    }
BB2051:
    _1790_t2 = 10;
    goto BB2050;
BB2047:
    _1790_t2 = 33;
    goto BB2050;
BB2050:
    _1790_$retval = _1790_t2;
    return _1790_$retval;
}


int main(void) {
  printf("%ld",_1790_main());
  return 0;
}
