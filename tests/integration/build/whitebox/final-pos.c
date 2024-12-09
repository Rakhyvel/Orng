/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1963_main(void);


/* Function definitions */
int64_t _1963_main(void){
    int64_t _1964_x;
    int64_t _1963_t3;
    uint8_t _1963_t4;
    int64_t _1963_t6;
    uint8_t _1963_t8;
    int64_t _1963_t11;
    int64_t _1963_$retval;
    int64_t _1963_t9;
    _1964_x = 0;
    goto BB2138;
BB2138:
    _1963_t3 = 100;
    _1963_t4 = _1964_x<_1963_t3;
    if (_1963_t4) {
        goto BB2139;
    } else {
        goto BB2144;
    }
BB2139:
    _1963_t6 = 40;
    _1963_t8 = _1964_x==_1963_t6;
    if (_1963_t8) {
        goto BB2142;
    } else {
        goto BB2148;
    }
BB2144:
    _1963_$retval = _1964_x;
    return _1963_$retval;
BB2142:
    _1963_t9 = 1;
    _1964_x = $add_int64_t(_1964_x, _1963_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2144;
BB2148:
    _1963_t11 = 1;
    _1964_x = $add_int64_t(_1964_x, _1963_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2138;
}


int main(void) {
  printf("%ld",_1963_main());
  return 0;
}
