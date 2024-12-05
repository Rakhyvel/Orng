/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1973_main(void);


/* Function definitions */
int64_t _1973_main(void){
    int64_t _1974_x;
    int64_t* _1974_y;
    int64_t _1973_t5;
    uint8_t _1973_t7;
    int64_t _1973_t4;
    int64_t _1973_$retval;
    int64_t _1973_t9;
    uint8_t _1973_t10;
    int64_t _1973_t11;
    uint8_t _1973_t12;
    _1974_x = 3;
    _1974_y = &_1974_x;
    _1973_t5 = 5;
    _1973_t7 = *_1974_y==_1973_t5;
    if (_1973_t7) {
        goto BB2160;
    } else {
        goto BB2162;
    }
BB2160:
    _1973_t9 = 4;
    _1973_t10 = _1973_t9>*_1974_y;
    if (_1973_t10) {
        goto BB2162;
    } else {
        goto BB2167;
    }
BB2162:
    _1973_t11 = 3;
    _1973_t12 = *_1974_y>=_1973_t11;
    if (_1973_t12) {
        goto BB2163;
    } else {
        goto BB2167;
    }
BB2167:
    _1973_t4 = 10;
    goto BB2166;
BB2163:
    _1973_t4 = 33;
    goto BB2166;
BB2166:
    _1973_$retval = _1973_t4;
    return _1973_$retval;
}


int main(void) {
  printf("%ld",_1973_main());
  return 0;
}
