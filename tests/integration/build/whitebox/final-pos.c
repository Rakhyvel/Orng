/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1817_main(void);


/* Function definitions */
int64_t _1817_main(void){
    int64_t _1818_x;
    int64_t _1817_t3;
    uint8_t _1817_t4;
    int64_t _1817_t6;
    uint8_t _1817_t8;
    int64_t _1817_t11;
    int64_t _1817_$retval;
    int64_t _1817_t9;
    _1818_x = 0;
    goto BB2052;
BB2052:
    _1817_t3 = 100;
    _1817_t4 = _1818_x<_1817_t3;
    if (_1817_t4) {
        goto BB2053;
    } else {
        goto BB2058;
    }
BB2053:
    _1817_t6 = 40;
    _1817_t8 = _1818_x==_1817_t6;
    if (_1817_t8) {
        goto BB2056;
    } else {
        goto BB2062;
    }
BB2058:
    _1817_$retval = _1818_x;
    return _1817_$retval;
BB2056:
    _1817_t9 = 1;
    _1818_x = $add_int64_t(_1818_x, _1817_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2058;
BB2062:
    _1817_t11 = 1;
    _1818_x = $add_int64_t(_1818_x, _1817_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2052;
}


int main(void) {
  printf("%ld",_1817_main());
  return 0;
}
