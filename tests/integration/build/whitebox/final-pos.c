/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1898_main(void);


/* Function definitions */
int64_t _1898_main(void){
    int64_t _1899_x;
    int64_t _1898_t3;
    uint8_t _1898_t4;
    int64_t _1898_t6;
    uint8_t _1898_t8;
    int64_t _1898_t11;
    int64_t _1898_$retval;
    int64_t _1898_t9;
    _1899_x = 0;
    goto BB2105;
BB2105:
    _1898_t3 = 100;
    _1898_t4 = _1899_x<_1898_t3;
    if (_1898_t4) {
        goto BB2106;
    } else {
        goto BB2111;
    }
BB2106:
    _1898_t6 = 40;
    _1898_t8 = _1899_x==_1898_t6;
    if (_1898_t8) {
        goto BB2109;
    } else {
        goto BB2115;
    }
BB2111:
    _1898_$retval = _1899_x;
    return _1898_$retval;
BB2109:
    _1898_t9 = 1;
    _1899_x = $add_int64_t(_1899_x, _1898_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2111;
BB2115:
    _1898_t11 = 1;
    _1899_x = $add_int64_t(_1899_x, _1898_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2105;
}


int main(void) {
  printf("%ld",_1898_main());
  return 0;
}
