/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
uint8_t _6_f(int64_t _6_x);

/* Function definitions */
int64_t _1_main(void) {
    uint8_t _1_t1;
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _1_t1 = _6_f(4);
    $line_idx--;
    if (_1_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1_t0 = 184;
    goto BB4;
BB5:
    _1_t0 = 4;
BB4:
    _1_$retval = _1_t0;
    return _1_$retval;
}

uint8_t _6_f(int64_t _6_x) {
    uint8_t _6_$retval;
    uint8_t _6_t8;
    if ($negate_int64_t(_6_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^") == $negate_int64_t(_6_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^")) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _6_t8 = 1;
    goto BB5;
BB8:
    _6_t8 = 0;
BB5:
    _6_$retval = _6_t8;
    return _6_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
