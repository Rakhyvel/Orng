/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1944_main(void);


/* Function definitions */
int64_t _1944_main(void){
    int64_t _1945_x;
    int64_t _1944_t3;
    uint8_t _1944_t4;
    int64_t _1944_t6;
    uint8_t _1944_t8;
    int64_t _1944_t11;
    int64_t _1944_$retval;
    int64_t _1944_t9;
    _1945_x = 0;
    goto BB2116;
BB2116:
    _1944_t3 = 100;
    _1944_t4 = _1945_x<_1944_t3;
    if (_1944_t4) {
        goto BB2117;
    } else {
        goto BB2122;
    }
BB2117:
    _1944_t6 = 40;
    _1944_t8 = _1945_x==_1944_t6;
    if (_1944_t8) {
        goto BB2120;
    } else {
        goto BB2126;
    }
BB2122:
    _1944_$retval = _1945_x;
    return _1944_$retval;
BB2120:
    _1944_t9 = 1;
    _1945_x = $add_int64_t(_1945_x, _1944_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2122;
BB2126:
    _1944_t11 = 1;
    _1945_x = $add_int64_t(_1945_x, _1944_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2116;
}


int main(void) {
  printf("%ld",_1944_main());
  return 0;
}
