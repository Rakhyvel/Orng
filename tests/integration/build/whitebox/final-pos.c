/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1795_main(void);


/* Function definitions */
int64_t _1795_main(void){
    int64_t _1796_x;
    int64_t _1795_t3;
    uint8_t _1795_t4;
    int64_t _1795_t6;
    uint8_t _1795_t8;
    int64_t _1795_t11;
    int64_t _1795_$retval;
    int64_t _1795_t9;
    _1796_x = 0;
    goto BB2005;
BB2005:
    _1795_t3 = 100;
    _1795_t4 = _1796_x<_1795_t3;
    if (_1795_t4) {
        goto BB2006;
    } else {
        goto BB2011;
    }
BB2006:
    _1795_t6 = 40;
    _1795_t8 = _1796_x==_1795_t6;
    if (_1795_t8) {
        goto BB2009;
    } else {
        goto BB2015;
    }
BB2011:
    _1795_$retval = _1796_x;
    return _1795_$retval;
BB2009:
    _1795_t9 = 1;
    _1796_x = $add_int64_t(_1796_x, _1795_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2011;
BB2015:
    _1795_t11 = 1;
    _1796_x = $add_int64_t(_1796_x, _1795_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2005;
}


int main(void) {
  printf("%ld",_1795_main());
  return 0;
}
