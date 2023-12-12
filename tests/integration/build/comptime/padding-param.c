/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _131_f(int8_t _131_x,int16_t _131_y,int8_t _131_z);
int64_t _129_main(void);

/* Function definitions */
int64_t _131_f(int8_t _131_x,int16_t _131_y,int8_t _131_z) {
    int8_t _131_t3;
    uint8_t _131_t5;
    uint8_t _131_t7;
    int16_t _131_t6;
    uint8_t _131_t8;
    uint8_t _131_t2;
    int8_t _131_t9;
    uint8_t _131_t11;
    uint8_t _131_t10;
    uint8_t _131_t1;
    int64_t _131_$retval;
    _131_t3 = 20;
    _131_t5 = _131_x == _131_t3;
    if (_131_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _131_t6 = 40;
    _131_t8 = _131_y == _131_t6;
    if (_131_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _131_t2 = 0;
    goto BB17;
BB4:
    _131_t7 = 1;
    goto BB5;
BB18:
    _131_t7 = 0;
    goto BB5;
BB17:
    _131_t1 = 0;
    goto BB15;
BB5:
    _131_t2 = _131_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-param.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_131_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _131_t9 = 60;
    _131_t11 = _131_z == _131_t9;
    if (_131_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _131_t10 = 1;
    goto BB9;
BB16:
    _131_t10 = 0;
    goto BB9;
BB9:
    _131_t1 = _131_t10;
    goto BB10;
BB10:
    if (_131_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _131_$retval = 255;
    return _131_$retval;
}

int64_t _129_main(void) {
    int64_t _129_$retval;
    _129_$retval = 255;
    return _129_$retval;
}

int main(void) {
  printf("%ld",_129_main());
  return 0;
}
