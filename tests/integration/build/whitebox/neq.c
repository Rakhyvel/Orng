/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1824_main(void);


/* Function definitions */
int64_t _1824_main(void){
    int64_t _1825_x;
    int64_t* _1825_y;
    int64_t _1824_t5;
    uint8_t _1824_t7;
    int64_t _1824_t4;
    int64_t _1824_$retval;
    int64_t _1824_t9;
    uint8_t _1824_t10;
    int64_t _1824_t11;
    uint8_t _1824_t12;
    _1825_x = 3;
    _1825_y = &_1825_x;
    _1824_t5 = 5;
    _1824_t7 = *_1825_y==_1824_t5;
    if (_1824_t7) {
        goto BB2049;
    } else {
        goto BB2051;
    }
BB2049:
    _1824_t9 = 4;
    _1824_t10 = _1824_t9>*_1825_y;
    if (_1824_t10) {
        goto BB2051;
    } else {
        goto BB2056;
    }
BB2051:
    _1824_t11 = 3;
    _1824_t12 = *_1825_y>=_1824_t11;
    if (_1824_t12) {
        goto BB2052;
    } else {
        goto BB2056;
    }
BB2056:
    _1824_t4 = 10;
    goto BB2055;
BB2052:
    _1824_t4 = 33;
    goto BB2055;
BB2055:
    _1824_$retval = _1824_t4;
    return _1824_$retval;
}


int main(void) {
  printf("%ld",_1824_main());
  return 0;
}
