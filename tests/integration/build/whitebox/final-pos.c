/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1783_main(void);


/* Function definitions */
int64_t _1783_main(void){
    int64_t _1784_x;
    int64_t _1783_t3;
    uint8_t _1783_t4;
    int64_t _1783_t6;
    uint8_t _1783_t8;
    int64_t _1783_t11;
    int64_t _1783_$retval;
    int64_t _1783_t9;
    _1784_x = 0;
    goto BB1999;
BB1999:
    _1783_t3 = 100;
    _1783_t4 = _1784_x<_1783_t3;
    if (_1783_t4) {
        goto BB2000;
    } else {
        goto BB2005;
    }
BB2000:
    _1783_t6 = 40;
    _1783_t8 = _1784_x==_1783_t6;
    if (_1783_t8) {
        goto BB2003;
    } else {
        goto BB2009;
    }
BB2005:
    _1783_$retval = _1784_x;
    return _1783_$retval;
BB2003:
    _1783_t9 = 1;
    _1784_x = $add_int64_t(_1784_x, _1783_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2005;
BB2009:
    _1783_t11 = 1;
    _1784_x = $add_int64_t(_1784_x, _1783_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1999;
}


int main(void) {
  printf("%ld",_1783_main());
  return 0;
}
