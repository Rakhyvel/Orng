/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1819_main(void);


/* Function definitions */
int64_t _1819_main(void){
    int64_t _1820_x;
    int64_t _1819_t3;
    uint8_t _1819_t4;
    int64_t _1819_t6;
    uint8_t _1819_t8;
    int64_t _1819_t11;
    int64_t _1819_$retval;
    int64_t _1819_t9;
    _1820_x = 0;
    goto BB2022;
BB2022:
    _1819_t3 = 100;
    _1819_t4 = _1820_x<_1819_t3;
    if (_1819_t4) {
        goto BB2023;
    } else {
        goto BB2028;
    }
BB2023:
    _1819_t6 = 40;
    _1819_t8 = _1820_x==_1819_t6;
    if (_1819_t8) {
        goto BB2026;
    } else {
        goto BB2032;
    }
BB2028:
    _1819_$retval = _1820_x;
    return _1819_$retval;
BB2026:
    _1819_t9 = 1;
    _1820_x = $add_int64_t(_1820_x, _1819_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2028;
BB2032:
    _1819_t11 = 1;
    _1820_x = $add_int64_t(_1820_x, _1819_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2022;
}


int main(void) {
  printf("%ld",_1819_main());
  return 0;
}
