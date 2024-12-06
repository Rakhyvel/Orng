/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1979_main(void);


/* Function definitions */
int64_t _1979_main(void){
    int64_t _1980_x;
    int64_t* _1980_y;
    int64_t _1979_t5;
    uint8_t _1979_t7;
    int64_t _1979_t4;
    int64_t _1979_$retval;
    int64_t _1979_t9;
    uint8_t _1979_t10;
    int64_t _1979_t11;
    uint8_t _1979_t12;
    _1980_x = 3;
    _1980_y = &_1980_x;
    _1979_t5 = 5;
    _1979_t7 = *_1980_y==_1979_t5;
    if (_1979_t7) {
        goto BB2169;
    } else {
        goto BB2171;
    }
BB2169:
    _1979_t9 = 4;
    _1979_t10 = _1979_t9>*_1980_y;
    if (_1979_t10) {
        goto BB2171;
    } else {
        goto BB2176;
    }
BB2171:
    _1979_t11 = 3;
    _1979_t12 = *_1980_y>=_1979_t11;
    if (_1979_t12) {
        goto BB2172;
    } else {
        goto BB2176;
    }
BB2176:
    _1979_t4 = 10;
    goto BB2175;
BB2172:
    _1979_t4 = 33;
    goto BB2175;
BB2175:
    _1979_$retval = _1979_t4;
    return _1979_$retval;
}


int main(void) {
  printf("%ld",_1979_main());
  return 0;
}
