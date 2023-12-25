/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1556_main(void);

/* Function definitions */
int64_t _1556_main(void){
    int64_t _1557_x;
    int64_t _1556_t2;
    uint8_t _1556_t3;
    int64_t _1556_t5;
    uint8_t _1556_t7;
    int64_t _1556_$retval;
    int64_t _1556_t10;
    int64_t _1556_t8;
    _1557_x = 0;
    goto BB1884;
BB1884:
    _1556_t2 = 100;
    _1556_t3 = _1557_x<_1556_t2;
    if (_1556_t3) {
        goto BB1885;
    } else {
        goto BB1890;
    }
BB1885:
    _1556_t5 = 40;
    _1556_t7 = _1557_x==_1556_t5;
    if (_1556_t7) {
        goto BB1888;
    } else {
        goto BB1894;
    }
BB1890:
    _1556_$retval = _1557_x;
    return _1556_$retval;
BB1888:
    _1556_t8 = 1;
    _1557_x = $add_int64_t(_1557_x, _1556_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1890;
BB1894:
    _1556_t10 = 1;
    _1557_x = $add_int64_t(_1557_x, _1556_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1884;
}

int main(void) {
  printf("%ld",_1556_main());
  return 0;
}
