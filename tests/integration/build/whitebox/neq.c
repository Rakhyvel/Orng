/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1848_main(void);


/* Function definitions */
int64_t _1848_main(void){
    int64_t _1849_x;
    int64_t* _1849_y;
    int64_t _1848_t5;
    uint8_t _1848_t7;
    int64_t _1848_t4;
    int64_t _1848_$retval;
    int64_t _1848_t9;
    uint8_t _1848_t10;
    int64_t _1848_t11;
    uint8_t _1848_t12;
    _1849_x = 3;
    _1849_y = &_1849_x;
    _1848_t5 = 5;
    _1848_t7 = *_1849_y==_1848_t5;
    if (_1848_t7) {
        goto BB2066;
    } else {
        goto BB2068;
    }
BB2066:
    _1848_t9 = 4;
    _1848_t10 = _1848_t9>*_1849_y;
    if (_1848_t10) {
        goto BB2068;
    } else {
        goto BB2073;
    }
BB2068:
    _1848_t11 = 3;
    _1848_t12 = *_1849_y>=_1848_t11;
    if (_1848_t12) {
        goto BB2069;
    } else {
        goto BB2073;
    }
BB2073:
    _1848_t4 = 10;
    goto BB2072;
BB2069:
    _1848_t4 = 33;
    goto BB2072;
BB2072:
    _1848_$retval = _1848_t4;
    return _1848_$retval;
}


int main(void) {
  printf("%ld",_1848_main());
  return 0;
}
