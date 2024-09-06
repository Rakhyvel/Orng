/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1891_main(void);


/* Function definitions */
int64_t _1891_main(void){
    int64_t _1892_x;
    int64_t _1891_t3;
    uint8_t _1891_t4;
    int64_t _1891_t6;
    uint8_t _1891_t8;
    int64_t _1891_t11;
    int64_t _1891_$retval;
    int64_t _1891_t9;
    _1892_x = 0;
    goto BB2101;
BB2101:
    _1891_t3 = 100;
    _1891_t4 = _1892_x<_1891_t3;
    if (_1891_t4) {
        goto BB2102;
    } else {
        goto BB2107;
    }
BB2102:
    _1891_t6 = 40;
    _1891_t8 = _1892_x==_1891_t6;
    if (_1891_t8) {
        goto BB2105;
    } else {
        goto BB2111;
    }
BB2107:
    _1891_$retval = _1892_x;
    return _1891_$retval;
BB2105:
    _1891_t9 = 1;
    _1892_x = $add_int64_t(_1892_x, _1891_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2107;
BB2111:
    _1891_t11 = 1;
    _1892_x = $add_int64_t(_1892_x, _1891_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2101;
}


int main(void) {
  printf("%ld",_1891_main());
  return 0;
}
