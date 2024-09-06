/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1920_main(void);


/* Function definitions */
int64_t _1920_main(void){
    int64_t _1921_x;
    int64_t* _1921_y;
    int64_t _1920_t5;
    uint8_t _1920_t7;
    int64_t _1920_t4;
    int64_t _1920_$retval;
    int64_t _1920_t9;
    uint8_t _1920_t10;
    int64_t _1920_t11;
    uint8_t _1920_t12;
    _1921_x = 3;
    _1921_y = &_1921_x;
    _1920_t5 = 5;
    _1920_t7 = *_1921_y==_1920_t5;
    if (_1920_t7) {
        goto BB2145;
    } else {
        goto BB2147;
    }
BB2145:
    _1920_t9 = 4;
    _1920_t10 = _1920_t9>*_1921_y;
    if (_1920_t10) {
        goto BB2147;
    } else {
        goto BB2152;
    }
BB2147:
    _1920_t11 = 3;
    _1920_t12 = *_1921_y>=_1920_t11;
    if (_1920_t12) {
        goto BB2148;
    } else {
        goto BB2152;
    }
BB2152:
    _1920_t4 = 10;
    goto BB2151;
BB2148:
    _1920_t4 = 33;
    goto BB2151;
BB2151:
    _1920_$retval = _1920_t4;
    return _1920_$retval;
}


int main(void) {
  printf("%ld",_1920_main());
  return 0;
}
