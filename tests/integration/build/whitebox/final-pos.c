/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1833_main(void);


/* Function definitions */
int64_t _1833_main(void){
    int64_t _1834_x;
    int64_t _1833_t3;
    uint8_t _1833_t4;
    int64_t _1833_t6;
    uint8_t _1833_t8;
    int64_t _1833_t11;
    int64_t _1833_$retval;
    int64_t _1833_t9;
    _1834_x = 0;
    goto BB2032;
BB2032:
    _1833_t3 = 100;
    _1833_t4 = _1834_x<_1833_t3;
    if (_1833_t4) {
        goto BB2033;
    } else {
        goto BB2038;
    }
BB2033:
    _1833_t6 = 40;
    _1833_t8 = _1834_x==_1833_t6;
    if (_1833_t8) {
        goto BB2036;
    } else {
        goto BB2042;
    }
BB2038:
    _1833_$retval = _1834_x;
    return _1833_$retval;
BB2036:
    _1833_t9 = 1;
    _1834_x = $add_int64_t(_1834_x, _1833_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2038;
BB2042:
    _1833_t11 = 1;
    _1834_x = $add_int64_t(_1834_x, _1833_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2032;
}


int main(void) {
  printf("%ld",_1833_main());
  return 0;
}
