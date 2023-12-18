/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1835_main(void);

/* Function definitions */
int64_t _1835_main(void){
    int64_t _1836_x;
    int64_t _1835_t2;
    uint8_t _1835_t3;
    int64_t _1835_t5;
    uint8_t _1835_t7;
    int64_t _1835_t10;
    int64_t _1835_$retval;
    int64_t _1835_t8;
    _1836_x = 0;
    goto BB1;
BB1:
    _1835_t2 = 100;
    _1835_t3 = _1836_x < _1835_t2;
    if (_1835_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1835_t5 = 40;
    _1835_t7 = _1836_x == _1835_t5;
    if (_1835_t7) {
        goto BB5;
    } else {
        goto BB11;
    }
BB7:
    _1835_$retval = _1836_x;
    return _1835_$retval;
BB5:
    _1835_t8 = 1;
    _1836_x = $add_int64_t(_1836_x, _1835_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB7;
BB11:
    _1835_t10 = 1;
    _1836_x = $add_int64_t(_1836_x, _1835_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_1835_main());
  return 0;
}
