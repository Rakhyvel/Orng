/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1938_main(void);


/* Function definitions */
int64_t _1938_main(void){
    int64_t _1939_x;
    int64_t _1938_t3;
    uint8_t _1938_t4;
    int64_t _1938_t6;
    uint8_t _1938_t8;
    int64_t _1938_t11;
    int64_t _1938_$retval;
    int64_t _1938_t9;
    _1939_x = 0;
    goto BB2113;
BB2113:
    _1938_t3 = 100;
    _1938_t4 = _1939_x<_1938_t3;
    if (_1938_t4) {
        goto BB2114;
    } else {
        goto BB2119;
    }
BB2114:
    _1938_t6 = 40;
    _1938_t8 = _1939_x==_1938_t6;
    if (_1938_t8) {
        goto BB2117;
    } else {
        goto BB2123;
    }
BB2119:
    _1938_$retval = _1939_x;
    return _1938_$retval;
BB2117:
    _1938_t9 = 1;
    _1939_x = $add_int64_t(_1939_x, _1938_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2119;
BB2123:
    _1938_t11 = 1;
    _1939_x = $add_int64_t(_1939_x, _1938_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2113;
}


int main(void) {
  printf("%ld",_1938_main());
  return 0;
}
