/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1957_main(void);


/* Function definitions */
int64_t _1957_main(void){
    int64_t _1958_x;
    int64_t* _1958_y;
    int64_t _1957_t5;
    uint8_t _1957_t7;
    int64_t _1957_t4;
    int64_t _1957_$retval;
    int64_t _1957_t9;
    uint8_t _1957_t10;
    int64_t _1957_t11;
    uint8_t _1957_t12;
    _1958_x = 3;
    _1958_y = &_1958_x;
    _1957_t5 = 5;
    _1957_t7 = *_1958_y==_1957_t5;
    if (_1957_t7) {
        goto BB2149;
    } else {
        goto BB2151;
    }
BB2149:
    _1957_t9 = 4;
    _1957_t10 = _1957_t9>*_1958_y;
    if (_1957_t10) {
        goto BB2151;
    } else {
        goto BB2156;
    }
BB2151:
    _1957_t11 = 3;
    _1957_t12 = *_1958_y>=_1957_t11;
    if (_1957_t12) {
        goto BB2152;
    } else {
        goto BB2156;
    }
BB2156:
    _1957_t4 = 10;
    goto BB2155;
BB2152:
    _1957_t4 = 33;
    goto BB2155;
BB2155:
    _1957_$retval = _1957_t4;
    return _1957_$retval;
}


int main(void) {
  printf("%ld",_1957_main());
  return 0;
}
