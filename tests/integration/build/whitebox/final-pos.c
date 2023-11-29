/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1280_main(void);

/* Function definitions */
int64_t _1280_main(void) {
    int64_t _1281_x;
    int64_t _1280_t2;
    uint8_t _1280_t3;
    int64_t _1280_t5;
    uint8_t _1280_t7;
    int64_t _1280_t10;
    int64_t _1280_$retval;
    int64_t _1280_t8;
    _1281_x = 0;
    goto BB1;
BB1:
    _1280_t2 = 100;
    _1280_t3 = _1281_x < _1280_t2;
    if (_1280_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1280_t5 = 40;
    _1280_t7 = _1281_x == _1280_t5;
    if (_1280_t7) {
        goto BB5;
    } else {
        goto BB11;
    }
BB7:
    _1280_$retval = _1281_x;
    return _1280_$retval;
BB5:
    _1280_t8 = 1;
    _1281_x = $add_int64_t(_1281_x, _1280_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB7;
BB11:
    _1280_t10 = 1;
    _1281_x = $add_int64_t(_1281_x, _1280_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_1280_main());
  return 0;
}
