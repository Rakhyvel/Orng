/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1857_main(void);


/* Function definitions */
int64_t _1857_main(void){
    int64_t _1858_x;
    int64_t* _1858_y;
    int64_t _1857_t5;
    uint8_t _1857_t7;
    int64_t _1857_t4;
    int64_t _1857_$retval;
    int64_t _1857_t9;
    uint8_t _1857_t10;
    int64_t _1857_t11;
    uint8_t _1857_t12;
    _1858_x = 3;
    _1858_y = &_1858_x;
    _1857_t5 = 5;
    _1857_t7 = *_1858_y==_1857_t5;
    if (_1857_t7) {
        goto BB2072;
    } else {
        goto BB2074;
    }
BB2072:
    _1857_t9 = 4;
    _1857_t10 = _1857_t9>*_1858_y;
    if (_1857_t10) {
        goto BB2074;
    } else {
        goto BB2079;
    }
BB2074:
    _1857_t11 = 3;
    _1857_t12 = *_1858_y>=_1857_t11;
    if (_1857_t12) {
        goto BB2075;
    } else {
        goto BB2079;
    }
BB2079:
    _1857_t4 = 10;
    goto BB2078;
BB2075:
    _1857_t4 = 33;
    goto BB2078;
BB2078:
    _1857_$retval = _1857_t4;
    return _1857_$retval;
}


int main(void) {
  printf("%ld",_1857_main());
  return 0;
}
