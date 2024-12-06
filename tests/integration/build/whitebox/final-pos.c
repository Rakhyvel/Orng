/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1950_main(void);


/* Function definitions */
int64_t _1950_main(void){
    int64_t _1951_x;
    int64_t _1950_t3;
    uint8_t _1950_t4;
    int64_t _1950_t6;
    uint8_t _1950_t8;
    int64_t _1950_t11;
    int64_t _1950_$retval;
    int64_t _1950_t9;
    _1951_x = 0;
    goto BB2125;
BB2125:
    _1950_t3 = 100;
    _1950_t4 = _1951_x<_1950_t3;
    if (_1950_t4) {
        goto BB2126;
    } else {
        goto BB2131;
    }
BB2126:
    _1950_t6 = 40;
    _1950_t8 = _1951_x==_1950_t6;
    if (_1950_t8) {
        goto BB2129;
    } else {
        goto BB2135;
    }
BB2131:
    _1950_$retval = _1951_x;
    return _1950_$retval;
BB2129:
    _1950_t9 = 1;
    _1951_x = $add_int64_t(_1951_x, _1950_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2131;
BB2135:
    _1950_t11 = 1;
    _1951_x = $add_int64_t(_1951_x, _1950_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2125;
}


int main(void) {
  printf("%ld",_1950_main());
  return 0;
}
