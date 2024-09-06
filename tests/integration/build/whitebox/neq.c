/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1959_main(void);


/* Function definitions */
int64_t _1959_main(void){
    int64_t _1960_x;
    int64_t* _1960_y;
    int64_t _1959_t5;
    uint8_t _1959_t7;
    int64_t _1959_t4;
    int64_t _1959_$retval;
    int64_t _1959_t9;
    uint8_t _1959_t10;
    int64_t _1959_t11;
    uint8_t _1959_t12;
    _1960_x = 3;
    _1960_y = &_1960_x;
    _1959_t5 = 5;
    _1959_t7 = *_1960_y==_1959_t5;
    if (_1959_t7) {
        goto BB2151;
    } else {
        goto BB2153;
    }
BB2151:
    _1959_t9 = 4;
    _1959_t10 = _1959_t9>*_1960_y;
    if (_1959_t10) {
        goto BB2153;
    } else {
        goto BB2158;
    }
BB2153:
    _1959_t11 = 3;
    _1959_t12 = *_1960_y>=_1959_t11;
    if (_1959_t12) {
        goto BB2154;
    } else {
        goto BB2158;
    }
BB2158:
    _1959_t4 = 10;
    goto BB2157;
BB2154:
    _1959_t4 = 33;
    goto BB2157;
BB2157:
    _1959_$retval = _1959_t4;
    return _1959_$retval;
}


int main(void) {
  printf("%ld",_1959_main());
  return 0;
}
