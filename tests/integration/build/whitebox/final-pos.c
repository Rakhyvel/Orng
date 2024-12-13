/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1980_main(void);


/* Function definitions */
int64_t _1980_main(void){
    int64_t _1981_x;
    int64_t _1980_t3;
    uint8_t _1980_t4;
    int64_t _1980_t6;
    uint8_t _1980_t8;
    int64_t _1980_t11;
    int64_t _1980_$retval;
    int64_t _1980_t9;
    _1981_x = 0;
    goto BB2156;
BB2156:
    _1980_t3 = 100;
    _1980_t4 = _1981_x<_1980_t3;
    if (_1980_t4) {
        goto BB2157;
    } else {
        goto BB2162;
    }
BB2157:
    _1980_t6 = 40;
    _1980_t8 = _1981_x==_1980_t6;
    if (_1980_t8) {
        goto BB2160;
    } else {
        goto BB2166;
    }
BB2162:
    _1980_$retval = _1981_x;
    return _1980_$retval;
BB2160:
    _1980_t9 = 1;
    _1981_x = $add_int64_t(_1981_x, _1980_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2162;
BB2166:
    _1980_t11 = 1;
    _1981_x = $add_int64_t(_1981_x, _1980_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2156;
}


int main(void) {
  printf("%ld",_1980_main());
  return 0;
}
