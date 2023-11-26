/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _29_main(void);

/* Function definitions */
int64_t _29_main(void) {
    int64_t _30_x;
    int64_t _29_t2;
    uint8_t _29_t3;
    int64_t _29_t5;
    uint8_t _29_t7;
    uint8_t _29_t6;
    int64_t _29_t8;
    int64_t _29_t10;
    int64_t _29_$retval;
    _30_x = 0;
    goto BB1;
BB1:
    _29_t2 = 100;
    _29_t3 = _30_x < _29_t2;
    if (_29_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _29_t5 = 40;
    _29_t7 = _30_x == _29_t5;
    if (_29_t7) {
        goto BB3;
    } else {
        goto BB12;
    }
BB7:
    _29_$retval = _30_x;
    return _29_$retval;
BB3:
    _29_t6 = 1;
    goto BB4;
BB12:
    _29_t6 = 0;
    goto BB4;
BB4:
    if (_29_t6) {
        goto BB5;
    } else {
        goto BB11;
    }
BB5:
    _29_t8 = 1;
    _30_x = $add_int64_t(_30_x, _29_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB7;
BB11:
    _29_t10 = 1;
    _30_x = $add_int64_t(_30_x, _29_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_29_main());
  return 0;
}
