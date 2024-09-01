/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1872_main(void);


/* Function definitions */
int64_t _1872_main(void){
    int64_t _1873_x;
    int64_t _1872_t3;
    uint8_t _1872_t4;
    int64_t _1872_t6;
    uint8_t _1872_t8;
    int64_t _1872_t11;
    int64_t _1872_$retval;
    int64_t _1872_t9;
    _1873_x = 0;
    goto BB2080;
BB2080:
    _1872_t3 = 100;
    _1872_t4 = _1873_x<_1872_t3;
    if (_1872_t4) {
        goto BB2081;
    } else {
        goto BB2086;
    }
BB2081:
    _1872_t6 = 40;
    _1872_t8 = _1873_x==_1872_t6;
    if (_1872_t8) {
        goto BB2084;
    } else {
        goto BB2090;
    }
BB2086:
    _1872_$retval = _1873_x;
    return _1872_$retval;
BB2084:
    _1872_t9 = 1;
    _1873_x = $add_int64_t(_1873_x, _1872_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2086;
BB2090:
    _1872_t11 = 1;
    _1873_x = $add_int64_t(_1873_x, _1872_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2080;
}


int main(void) {
  printf("%ld",_1872_main());
  return 0;
}
