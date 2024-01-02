/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1589_main(void);

/* Function definitions */
int64_t _1589_main(void){
    int64_t _1590_x;
    int64_t _1589_t2;
    uint8_t _1589_t3;
    int64_t _1589_t5;
    uint8_t _1589_t7;
    int64_t _1589_$retval;
    int64_t _1589_t10;
    int64_t _1589_t8;
    _1590_x = 0;
    goto BB1863;
BB1863:
    _1589_t2 = 100;
    _1589_t3 = _1590_x<_1589_t2;
    if (_1589_t3) {
        goto BB1864;
    } else {
        goto BB1869;
    }
BB1864:
    _1589_t5 = 40;
    _1589_t7 = _1590_x==_1589_t5;
    if (_1589_t7) {
        goto BB1867;
    } else {
        goto BB1873;
    }
BB1869:
    _1589_$retval = _1590_x;
    return _1589_$retval;
BB1867:
    _1589_t8 = 1;
    _1590_x = $add_int64_t(_1590_x, _1589_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1869;
BB1873:
    _1589_t10 = 1;
    _1590_x = $add_int64_t(_1590_x, _1589_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1863;
}

int main(void) {
  printf("%ld",_1589_main());
  return 0;
}
