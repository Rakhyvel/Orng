/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1967_main(void);


/* Function definitions */
int64_t _1967_main(void){
    int64_t _1968_x;
    int64_t* _1968_y;
    int64_t _1967_t5;
    uint8_t _1967_t7;
    int64_t _1967_t4;
    int64_t _1967_$retval;
    int64_t _1967_t9;
    uint8_t _1967_t10;
    int64_t _1967_t11;
    uint8_t _1967_t12;
    _1968_x = 3;
    _1968_y = &_1968_x;
    _1967_t5 = 5;
    _1967_t7 = *_1968_y==_1967_t5;
    if (_1967_t7) {
        goto BB2157;
    } else {
        goto BB2159;
    }
BB2157:
    _1967_t9 = 4;
    _1967_t10 = _1967_t9>*_1968_y;
    if (_1967_t10) {
        goto BB2159;
    } else {
        goto BB2164;
    }
BB2159:
    _1967_t11 = 3;
    _1967_t12 = *_1968_y>=_1967_t11;
    if (_1967_t12) {
        goto BB2160;
    } else {
        goto BB2164;
    }
BB2164:
    _1967_t4 = 10;
    goto BB2163;
BB2160:
    _1967_t4 = 33;
    goto BB2163;
BB2163:
    _1967_$retval = _1967_t4;
    return _1967_$retval;
}


int main(void) {
  printf("%ld",_1967_main());
  return 0;
}
