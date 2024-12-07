/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1958_main(void);


/* Function definitions */
int64_t _1958_main(void){
    int64_t _1959_x;
    int64_t _1958_t3;
    uint8_t _1958_t4;
    int64_t _1958_t6;
    uint8_t _1958_t8;
    int64_t _1958_t11;
    int64_t _1958_$retval;
    int64_t _1958_t9;
    _1959_x = 0;
    goto BB2135;
BB2135:
    _1958_t3 = 100;
    _1958_t4 = _1959_x<_1958_t3;
    if (_1958_t4) {
        goto BB2136;
    } else {
        goto BB2141;
    }
BB2136:
    _1958_t6 = 40;
    _1958_t8 = _1959_x==_1958_t6;
    if (_1958_t8) {
        goto BB2139;
    } else {
        goto BB2145;
    }
BB2141:
    _1958_$retval = _1959_x;
    return _1958_$retval;
BB2139:
    _1958_t9 = 1;
    _1959_x = $add_int64_t(_1959_x, _1958_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2141;
BB2145:
    _1958_t11 = 1;
    _1959_x = $add_int64_t(_1959_x, _1958_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2135;
}


int main(void) {
  printf("%ld",_1958_main());
  return 0;
}
