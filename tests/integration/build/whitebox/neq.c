/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1927_main(void);


/* Function definitions */
int64_t _1927_main(void){
    int64_t _1928_x;
    int64_t* _1928_y;
    int64_t _1927_t5;
    uint8_t _1927_t7;
    int64_t _1927_t4;
    int64_t _1927_$retval;
    int64_t _1927_t9;
    uint8_t _1927_t10;
    int64_t _1927_t11;
    uint8_t _1927_t12;
    _1928_x = 3;
    _1928_y = &_1928_x;
    _1927_t5 = 5;
    _1927_t7 = *_1928_y==_1927_t5;
    if (_1927_t7) {
        goto BB2149;
    } else {
        goto BB2151;
    }
BB2149:
    _1927_t9 = 4;
    _1927_t10 = _1927_t9>*_1928_y;
    if (_1927_t10) {
        goto BB2151;
    } else {
        goto BB2156;
    }
BB2151:
    _1927_t11 = 3;
    _1927_t12 = *_1928_y>=_1927_t11;
    if (_1927_t12) {
        goto BB2152;
    } else {
        goto BB2156;
    }
BB2156:
    _1927_t4 = 10;
    goto BB2155;
BB2152:
    _1927_t4 = 33;
    goto BB2155;
BB2155:
    _1927_$retval = _1927_t4;
    return _1927_$retval;
}


int main(void) {
  printf("%ld",_1927_main());
  return 0;
}
