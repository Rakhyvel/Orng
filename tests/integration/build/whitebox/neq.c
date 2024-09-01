/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1901_main(void);


/* Function definitions */
int64_t _1901_main(void){
    int64_t _1902_x;
    int64_t* _1902_y;
    int64_t _1901_t5;
    uint8_t _1901_t7;
    int64_t _1901_t4;
    int64_t _1901_$retval;
    int64_t _1901_t9;
    uint8_t _1901_t10;
    int64_t _1901_t11;
    uint8_t _1901_t12;
    _1902_x = 3;
    _1902_y = &_1902_x;
    _1901_t5 = 5;
    _1901_t7 = *_1902_y==_1901_t5;
    if (_1901_t7) {
        goto BB2124;
    } else {
        goto BB2126;
    }
BB2124:
    _1901_t9 = 4;
    _1901_t10 = _1901_t9>*_1902_y;
    if (_1901_t10) {
        goto BB2126;
    } else {
        goto BB2131;
    }
BB2126:
    _1901_t11 = 3;
    _1901_t12 = *_1902_y>=_1901_t11;
    if (_1901_t12) {
        goto BB2127;
    } else {
        goto BB2131;
    }
BB2131:
    _1901_t4 = 10;
    goto BB2130;
BB2127:
    _1901_t4 = 33;
    goto BB2130;
BB2130:
    _1901_$retval = _1901_t4;
    return _1901_$retval;
}


int main(void) {
  printf("%ld",_1901_main());
  return 0;
}
