/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1846_main(void);


/* Function definitions */
int64_t _1846_main(void){
    int64_t _1847_x;
    int64_t* _1847_y;
    int64_t _1846_t5;
    uint8_t _1846_t7;
    int64_t _1846_t4;
    int64_t _1846_$retval;
    int64_t _1846_t9;
    uint8_t _1846_t10;
    int64_t _1846_t11;
    uint8_t _1846_t12;
    _1847_x = 3;
    _1847_y = &_1847_x;
    _1846_t5 = 5;
    _1846_t7 = *_1847_y==_1846_t5;
    if (_1846_t7) {
        goto BB2096;
    } else {
        goto BB2098;
    }
BB2096:
    _1846_t9 = 4;
    _1846_t10 = _1846_t9>*_1847_y;
    if (_1846_t10) {
        goto BB2098;
    } else {
        goto BB2103;
    }
BB2098:
    _1846_t11 = 3;
    _1846_t12 = *_1847_y>=_1846_t11;
    if (_1846_t12) {
        goto BB2099;
    } else {
        goto BB2103;
    }
BB2103:
    _1846_t4 = 10;
    goto BB2102;
BB2099:
    _1846_t4 = 33;
    goto BB2102;
BB2102:
    _1846_$retval = _1846_t4;
    return _1846_$retval;
}


int main(void) {
  printf("%ld",_1846_main());
  return 0;
}
