/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1933_main(void);


/* Function definitions */
int64_t _1933_main(void){
    int64_t _1934_x;
    int64_t _1933_t3;
    uint8_t _1933_t4;
    int64_t _1933_t6;
    uint8_t _1933_t8;
    int64_t _1933_t11;
    int64_t _1933_$retval;
    int64_t _1933_t9;
    _1934_x = 0;
    goto BB2109;
BB2109:
    _1933_t3 = 100;
    _1933_t4 = _1934_x<_1933_t3;
    if (_1933_t4) {
        goto BB2110;
    } else {
        goto BB2115;
    }
BB2110:
    _1933_t6 = 40;
    _1933_t8 = _1934_x==_1933_t6;
    if (_1933_t8) {
        goto BB2113;
    } else {
        goto BB2119;
    }
BB2115:
    _1933_$retval = _1934_x;
    return _1933_$retval;
BB2113:
    _1933_t9 = 1;
    _1934_x = $add_int64_t(_1934_x, _1933_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2115;
BB2119:
    _1933_t11 = 1;
    _1934_x = $add_int64_t(_1934_x, _1933_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2109;
}


int main(void) {
  printf("%ld",_1933_main());
  return 0;
}
