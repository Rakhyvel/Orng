/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1594_main(void);

/* Function definitions */
int64_t _1594_main(void){
    int64_t _1595_x;
    int64_t _1594_t2;
    uint8_t _1594_t3;
    int64_t _1594_t5;
    uint8_t _1594_t7;
    int64_t _1594_t10;
    int64_t _1594_$retval;
    int64_t _1594_t8;
    _1595_x = 0;
    goto BB1867;
BB1867:
    _1594_t2 = 100;
    _1594_t3 = _1595_x<_1594_t2;
    if (_1594_t3) {
        goto BB1868;
    } else {
        goto BB1873;
    }
BB1868:
    _1594_t5 = 40;
    _1594_t7 = _1595_x==_1594_t5;
    if (_1594_t7) {
        goto BB1871;
    } else {
        goto BB1877;
    }
BB1873:
    _1594_$retval = _1595_x;
    return _1594_$retval;
BB1871:
    _1594_t8 = 1;
    _1595_x = $add_int64_t(_1595_x, _1594_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1873;
BB1877:
    _1594_t10 = 1;
    _1595_x = $add_int64_t(_1595_x, _1594_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1867;
}

int main(void) {
  printf("%ld",_1594_main());
  return 0;
}
