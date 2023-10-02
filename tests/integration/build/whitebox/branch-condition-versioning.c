/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    uint8_t _2_found;
    int64_t _3_n;
    int64_t _1_$retval;
    int64_t _1_t13;
    _2_found = 0;
    _3_n = 0;
BB1:
    if (_3_n < 10) {
        goto BB2;
    } else {
        goto BB14;
    }
BB2:
    if (_2_found) {
        goto BB3;
    } else {
        goto BB5;
    }
BB14:
    if (_2_found) {
        goto BB15;
    } else {
        goto BB19;
    }
BB3:
    _3_n = 100;
BB5:
    if (_3_n == 6) {
        goto BB6;
    } else {
        goto BB10;
    }
BB15:
    _1_t13 = 15;
    goto BB18;
BB19:
    _1_t13 = 4;
    goto BB18;
BB6:
    _2_found = 1;
BB10:
    _3_n = $add_int64_t(_3_n, 1, "tests/integration/whitebox/branch-condition-versioning.orng:4:40:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                      ^");
    goto BB1;
BB18:
    _1_$retval = _1_t13;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
