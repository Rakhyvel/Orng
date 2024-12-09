/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1992_main(void);


/* Function definitions */
int64_t _1992_main(void){
    int64_t _1993_x;
    int64_t* _1993_y;
    int64_t _1992_t5;
    uint8_t _1992_t7;
    int64_t _1992_t4;
    int64_t _1992_$retval;
    int64_t _1992_t9;
    uint8_t _1992_t10;
    int64_t _1992_t11;
    uint8_t _1992_t12;
    _1993_x = 3;
    _1993_y = &_1993_x;
    _1992_t5 = 5;
    _1992_t7 = *_1993_y==_1992_t5;
    if (_1992_t7) {
        goto BB2182;
    } else {
        goto BB2184;
    }
BB2182:
    _1992_t9 = 4;
    _1992_t10 = _1992_t9>*_1993_y;
    if (_1992_t10) {
        goto BB2184;
    } else {
        goto BB2189;
    }
BB2184:
    _1992_t11 = 3;
    _1992_t12 = *_1993_y>=_1992_t11;
    if (_1992_t12) {
        goto BB2185;
    } else {
        goto BB2189;
    }
BB2189:
    _1992_t4 = 10;
    goto BB2188;
BB2185:
    _1992_t4 = 33;
    goto BB2188;
BB2188:
    _1992_$retval = _1992_t4;
    return _1992_$retval;
}


int main(void) {
  printf("%ld",_1992_main());
  return 0;
}
