/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    uint8_t _2_found;
    int64_t _3_n;
    int64_t _1_t14;
    int64_t _1_$retval;
    _2_found = 0;
    _3_n = 0;
BB1:
    if (_3_n < 10) {
        goto BB2;
    } else {
        goto BB17;
    }
BB2:
    if (_2_found) {
        goto BB3;
    } else {
        goto BB5;
    }
BB17:
    if (_2_found) {
        goto BB18;
    } else {
        goto BB22;
    }
BB3:
    _3_n = 100;
BB5:
    if (_3_n == 6) {
        goto BB8;
    } else {
        goto BB12;
    }
BB18:
    _1_t14 = 15;
    goto BB21;
BB22:
    _1_t14 = 4;
    goto BB21;
BB8:
    _2_found = 1;
BB12:
    _3_n = $add_int64_t(_3_n, 1, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1;
BB21:
    _1_$retval = _1_t14;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
