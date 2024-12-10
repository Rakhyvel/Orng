/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1978_main(void);


/* Function definitions */
int64_t _1978_main(void){
    int64_t _1979_x;
    int64_t _1978_t3;
    uint8_t _1978_t4;
    int64_t _1978_t6;
    uint8_t _1978_t8;
    int64_t _1978_t11;
    int64_t _1978_$retval;
    int64_t _1978_t9;
    _1979_x = 0;
    goto BB2154;
BB2154:
    _1978_t3 = 100;
    _1978_t4 = _1979_x<_1978_t3;
    if (_1978_t4) {
        goto BB2155;
    } else {
        goto BB2160;
    }
BB2155:
    _1978_t6 = 40;
    _1978_t8 = _1979_x==_1978_t6;
    if (_1978_t8) {
        goto BB2158;
    } else {
        goto BB2164;
    }
BB2160:
    _1978_$retval = _1979_x;
    return _1978_$retval;
BB2158:
    _1978_t9 = 1;
    _1979_x = $add_int64_t(_1979_x, _1978_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2160;
BB2164:
    _1978_t11 = 1;
    _1979_x = $add_int64_t(_1979_x, _1978_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2154;
}


int main(void) {
  printf("%ld",_1978_main());
  return 0;
}
