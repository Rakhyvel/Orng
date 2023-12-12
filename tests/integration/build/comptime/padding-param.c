/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _56_f(int8_t _56_x,int16_t _56_y,int8_t _56_z);
int64_t _54_main(void);

/* Function definitions */
int64_t _56_f(int8_t _56_x,int16_t _56_y,int8_t _56_z) {
    int8_t _56_t3;
    uint8_t _56_t5;
    uint8_t _56_t7;
    int16_t _56_t6;
    uint8_t _56_t8;
    uint8_t _56_t2;
    int8_t _56_t9;
    uint8_t _56_t11;
    uint8_t _56_t10;
    uint8_t _56_t1;
    int64_t _56_$retval;
    _56_t3 = 20;
    _56_t5 = _56_x == _56_t3;
    if (_56_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _56_t6 = 40;
    _56_t8 = _56_y == _56_t6;
    if (_56_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _56_t2 = 0;
    goto BB17;
BB4:
    _56_t7 = 1;
    goto BB5;
BB18:
    _56_t7 = 0;
    goto BB5;
BB17:
    _56_t1 = 0;
    goto BB15;
BB5:
    _56_t2 = _56_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-param.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_56_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _56_t9 = 60;
    _56_t11 = _56_z == _56_t9;
    if (_56_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _56_t10 = 1;
    goto BB9;
BB16:
    _56_t10 = 0;
    goto BB9;
BB9:
    _56_t1 = _56_t10;
    goto BB10;
BB10:
    if (_56_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _56_$retval = 255;
    return _56_$retval;
}

int64_t _54_main(void) {
    int64_t _54_$retval;
    _54_$retval = 255;
    return _54_$retval;
}

int main(void) {
  printf("%ld",_54_main());
  return 0;
}
