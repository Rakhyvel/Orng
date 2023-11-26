/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _131_main(void);

/* Function definitions */
int64_t _131_main(void) {
    uint8_t _131_t4;
    uint8_t _131_t3;
    int64_t _131_t0;
    int64_t _131_$retval;
    uint8_t _131_t9;
    int64_t _131_t6;
    uint8_t _131_t14;
    uint8_t _131_t15;
    _131_t4 = 0;
    if (_131_t4) {
        goto BB1;
    } else {
        goto BB19;
    }
BB1:
    _131_t3 = 1;
    goto BB2;
BB19:
    _131_t3 = 0;
    goto BB2;
BB2:
    if (_131_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _131_t0 = 6;
    goto BB6;
BB7:
    _131_t9 = 1;
    if (_131_t9) {
        goto BB8;
    } else {
        goto BB11;
    }
BB6:
    _131_$retval = _131_t0;
    return _131_$retval;
BB8:
    _131_t6 = 10;
    goto BB10;
BB11:
    _131_t15 = 0;
    if (_131_t15) {
        goto BB12;
    } else {
        goto BB18;
    }
BB10:
    _131_t0 = _131_t6;
    goto BB6;
BB12:
    _131_t14 = 1;
    goto BB13;
BB18:
    _131_t14 = 0;
    goto BB13;
BB13:
    if (_131_t14) {
        goto BB14;
    } else {
        goto BB17;
    }
BB14:
    _131_t6 = 25;
    goto BB10;
BB17:
    $lines[$line_idx++] = "tests/integration/control-flow/if-else-if.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_131_main());
  return 0;
}
