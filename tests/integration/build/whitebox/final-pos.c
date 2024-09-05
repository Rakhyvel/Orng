/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1883_main(void);


/* Function definitions */
int64_t _1883_main(void){
    int64_t _1884_x;
    int64_t _1883_t3;
    uint8_t _1883_t4;
    int64_t _1883_t6;
    uint8_t _1883_t8;
    int64_t _1883_t11;
    int64_t _1883_$retval;
    int64_t _1883_t9;
    _1884_x = 0;
    goto BB2090;
BB2090:
    _1883_t3 = 100;
    _1883_t4 = _1884_x<_1883_t3;
    if (_1883_t4) {
        goto BB2091;
    } else {
        goto BB2096;
    }
BB2091:
    _1883_t6 = 40;
    _1883_t8 = _1884_x==_1883_t6;
    if (_1883_t8) {
        goto BB2094;
    } else {
        goto BB2100;
    }
BB2096:
    _1883_$retval = _1884_x;
    return _1883_$retval;
BB2094:
    _1883_t9 = 1;
    _1884_x = $add_int64_t(_1884_x, _1883_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2096;
BB2100:
    _1883_t11 = 1;
    _1884_x = $add_int64_t(_1884_x, _1883_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2090;
}


int main(void) {
  printf("%ld",_1883_main());
  return 0;
}
