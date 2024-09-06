/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1962_main(void);


/* Function definitions */
int64_t _1962_main(void){
    int64_t _1963_x;
    int64_t* _1963_y;
    int64_t _1962_t5;
    uint8_t _1962_t7;
    int64_t _1962_t4;
    int64_t _1962_$retval;
    int64_t _1962_t9;
    uint8_t _1962_t10;
    int64_t _1962_t11;
    uint8_t _1962_t12;
    _1963_x = 3;
    _1963_y = &_1963_x;
    _1962_t5 = 5;
    _1962_t7 = *_1963_y==_1962_t5;
    if (_1962_t7) {
        goto BB2153;
    } else {
        goto BB2155;
    }
BB2153:
    _1962_t9 = 4;
    _1962_t10 = _1962_t9>*_1963_y;
    if (_1962_t10) {
        goto BB2155;
    } else {
        goto BB2160;
    }
BB2155:
    _1962_t11 = 3;
    _1962_t12 = *_1963_y>=_1962_t11;
    if (_1962_t12) {
        goto BB2156;
    } else {
        goto BB2160;
    }
BB2160:
    _1962_t4 = 10;
    goto BB2159;
BB2156:
    _1962_t4 = 33;
    goto BB2159;
BB2159:
    _1962_$retval = _1962_t4;
    return _1962_$retval;
}


int main(void) {
  printf("%ld",_1962_main());
  return 0;
}
