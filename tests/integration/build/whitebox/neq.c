/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1862_main(void);


/* Function definitions */
int64_t _1862_main(void){
    int64_t _1863_x;
    int64_t* _1863_y;
    int64_t _1862_t5;
    uint8_t _1862_t7;
    int64_t _1862_t4;
    int64_t _1862_$retval;
    int64_t _1862_t9;
    uint8_t _1862_t10;
    int64_t _1862_t11;
    uint8_t _1862_t12;
    _1863_x = 3;
    _1863_y = &_1863_x;
    _1862_t5 = 5;
    _1862_t7 = *_1863_y==_1862_t5;
    if (_1862_t7) {
        goto BB2076;
    } else {
        goto BB2078;
    }
BB2076:
    _1862_t9 = 4;
    _1862_t10 = _1862_t9>*_1863_y;
    if (_1862_t10) {
        goto BB2078;
    } else {
        goto BB2083;
    }
BB2078:
    _1862_t11 = 3;
    _1862_t12 = *_1863_y>=_1862_t11;
    if (_1862_t12) {
        goto BB2079;
    } else {
        goto BB2083;
    }
BB2083:
    _1862_t4 = 10;
    goto BB2082;
BB2079:
    _1862_t4 = 33;
    goto BB2082;
BB2082:
    _1862_$retval = _1862_t4;
    return _1862_$retval;
}


int main(void) {
  printf("%ld",_1862_main());
  return 0;
}
