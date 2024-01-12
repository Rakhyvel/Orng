/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1604_main(void);

/* Function definitions */
int64_t _1604_main(void){
    int64_t _1605_x;
    int64_t _1604_t2;
    uint8_t _1604_t3;
    int64_t _1604_t5;
    uint8_t _1604_t7;
    int64_t _1604_t10;
    int64_t _1604_$retval;
    int64_t _1604_t8;
    _1605_x = 0;
    goto BB1879;
BB1879:
    _1604_t2 = 100;
    _1604_t3 = _1605_x<_1604_t2;
    if (_1604_t3) {
        goto BB1880;
    } else {
        goto BB1885;
    }
BB1880:
    _1604_t5 = 40;
    _1604_t7 = _1605_x==_1604_t5;
    if (_1604_t7) {
        goto BB1883;
    } else {
        goto BB1889;
    }
BB1885:
    _1604_$retval = _1605_x;
    return _1604_$retval;
BB1883:
    _1604_t8 = 1;
    _1605_x = $add_int64_t(_1605_x, _1604_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1885;
BB1889:
    _1604_t10 = 1;
    _1605_x = $add_int64_t(_1605_x, _1604_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1879;
}

int main(void) {
  printf("%ld",_1604_main());
  return 0;
}
