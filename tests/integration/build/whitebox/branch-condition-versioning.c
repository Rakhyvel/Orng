/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1102_main(void);

/* Function definitions */
int64_t _1102_main(void) {
    uint8_t _1103_found;
    int64_t _1104_n;
    int64_t _1102_t3;
    uint8_t _1102_t4;
    uint8_t _1102_t9;
    int64_t _1102_t8;
    uint8_t _1102_t10;
    int64_t _1102_t14;
    int64_t _1102_t12;
    int64_t _1102_$retval;
    _1103_found = 0;
    _1104_n = 0;
    goto BB1;
BB1:
    _1102_t3 = 10;
    _1102_t4 = _1104_n < _1102_t3;
    if (_1102_t4) {
        goto BB2;
    } else {
        goto BB17;
    }
BB2:
    if (_1103_found) {
        goto BB3;
    } else {
        goto BB5;
    }
BB17:
    if (_1103_found) {
        goto BB18;
    } else {
        goto BB22;
    }
BB3:
    _1104_n = 100;
    goto BB5;
BB5:
    _1102_t8 = 6;
    _1102_t10 = _1104_n == _1102_t8;
    if (_1102_t10) {
        goto BB6;
    } else {
        goto BB14;
    }
BB18:
    _1102_t14 = 15;
    goto BB21;
BB22:
    _1102_t14 = 4;
    goto BB21;
BB6:
    _1102_t9 = 1;
    goto BB7;
BB14:
    _1102_t9 = 0;
    goto BB7;
BB21:
    _1102_$retval = _1102_t14;
    return _1102_$retval;
BB7:
    if (_1102_t9) {
        goto BB8;
    } else {
        goto BB12;
    }
BB8:
    _1103_found = 1;
    goto BB12;
BB12:
    _1102_t12 = 1;
    _1104_n = $add_int64_t(_1104_n, _1102_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_1102_main());
  return 0;
}
