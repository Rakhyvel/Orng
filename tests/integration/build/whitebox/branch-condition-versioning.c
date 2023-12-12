/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1222_main(void);

/* Function definitions */
int64_t _1222_main(void) {
    uint8_t _1223_found;
    int64_t _1224_n;
    int64_t _1222_t3;
    uint8_t _1222_t4;
    int64_t _1222_t12;
    int64_t _1222_t8;
    uint8_t _1222_t10;
    int64_t _1222_t14;
    int64_t _1222_$retval;
    _1223_found = 0;
    _1224_n = 0;
    goto BB1;
BB1:
    _1222_t3 = 10;
    _1222_t4 = _1224_n < _1222_t3;
    if (_1222_t4) {
        goto BB2;
    } else {
        goto BB17;
    }
BB2:
    if (_1223_found) {
        goto BB3;
    } else {
        goto BB5;
    }
BB17:
    if (_1223_found) {
        goto BB18;
    } else {
        goto BB22;
    }
BB3:
    _1224_n = 100;
    goto BB5;
BB5:
    _1222_t8 = 6;
    _1222_t10 = _1224_n == _1222_t8;
    if (_1222_t10) {
        goto BB8;
    } else {
        goto BB12;
    }
BB18:
    _1222_t14 = 15;
    goto BB21;
BB22:
    _1222_t14 = 4;
    goto BB21;
BB8:
    _1223_found = 1;
    goto BB12;
BB12:
    _1222_t12 = 1;
    _1224_n = $add_int64_t(_1224_n, _1222_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1;
BB21:
    _1222_$retval = _1222_t14;
    return _1222_$retval;
}

int main(void) {
  printf("%ld",_1222_main());
  return 0;
}
