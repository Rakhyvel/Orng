/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1930_main(void);


/* Function definitions */
int64_t _1930_main(void){
    int64_t _1931_x;
    int64_t _1930_t3;
    uint8_t _1930_t4;
    int64_t _1930_t6;
    uint8_t _1930_t8;
    int64_t _1930_t11;
    int64_t _1930_$retval;
    int64_t _1930_t9;
    _1931_x = 0;
    goto BB2107;
BB2107:
    _1930_t3 = 100;
    _1930_t4 = _1931_x<_1930_t3;
    if (_1930_t4) {
        goto BB2108;
    } else {
        goto BB2113;
    }
BB2108:
    _1930_t6 = 40;
    _1930_t8 = _1931_x==_1930_t6;
    if (_1930_t8) {
        goto BB2111;
    } else {
        goto BB2117;
    }
BB2113:
    _1930_$retval = _1931_x;
    return _1930_$retval;
BB2111:
    _1930_t9 = 1;
    _1931_x = $add_int64_t(_1931_x, _1930_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2113;
BB2117:
    _1930_t11 = 1;
    _1931_x = $add_int64_t(_1931_x, _1930_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2107;
}


int main(void) {
  printf("%ld",_1930_main());
  return 0;
}
