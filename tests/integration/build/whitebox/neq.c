/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1952_main(void);


/* Function definitions */
int64_t _1952_main(void){
    int64_t _1953_x;
    int64_t* _1953_y;
    int64_t _1952_t5;
    uint8_t _1952_t7;
    int64_t _1952_t4;
    int64_t _1952_$retval;
    int64_t _1952_t9;
    uint8_t _1952_t10;
    int64_t _1952_t11;
    uint8_t _1952_t12;
    _1953_x = 3;
    _1953_y = &_1953_x;
    _1952_t5 = 5;
    _1952_t7 = *_1953_y==_1952_t5;
    if (_1952_t7) {
        goto BB2149;
    } else {
        goto BB2151;
    }
BB2149:
    _1952_t9 = 4;
    _1952_t10 = _1952_t9>*_1953_y;
    if (_1952_t10) {
        goto BB2151;
    } else {
        goto BB2156;
    }
BB2151:
    _1952_t11 = 3;
    _1952_t12 = *_1953_y>=_1952_t11;
    if (_1952_t12) {
        goto BB2152;
    } else {
        goto BB2156;
    }
BB2156:
    _1952_t4 = 10;
    goto BB2155;
BB2152:
    _1952_t4 = 33;
    goto BB2155;
BB2155:
    _1952_$retval = _1952_t4;
    return _1952_$retval;
}


int main(void) {
  printf("%ld",_1952_main());
  return 0;
}
