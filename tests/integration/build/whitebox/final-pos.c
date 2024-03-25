/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1828_main(void);


/* Function definitions */
int64_t _1828_main(void){
    int64_t _1829_x;
    int64_t _1828_t3;
    uint8_t _1828_t4;
    int64_t _1828_t6;
    uint8_t _1828_t8;
    int64_t _1828_t11;
    int64_t _1828_$retval;
    int64_t _1828_t9;
    _1829_x = 0;
    goto BB2028;
BB2028:
    _1828_t3 = 100;
    _1828_t4 = _1829_x<_1828_t3;
    if (_1828_t4) {
        goto BB2029;
    } else {
        goto BB2034;
    }
BB2029:
    _1828_t6 = 40;
    _1828_t8 = _1829_x==_1828_t6;
    if (_1828_t8) {
        goto BB2032;
    } else {
        goto BB2038;
    }
BB2034:
    _1828_$retval = _1829_x;
    return _1828_$retval;
BB2032:
    _1828_t9 = 1;
    _1829_x = $add_int64_t(_1829_x, _1828_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2034;
BB2038:
    _1828_t11 = 1;
    _1829_x = $add_int64_t(_1829_x, _1828_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2028;
}


int main(void) {
  printf("%ld",_1828_main());
  return 0;
}
