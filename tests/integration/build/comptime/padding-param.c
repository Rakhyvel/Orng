/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _241_f(int8_t _241_x,int16_t _241_y,int8_t _241_z);
int64_t _238_main(void);

/* Function definitions */
int64_t _241_f(int8_t _241_x,int16_t _241_y,int8_t _241_z) {
    int8_t _241_t3;
    uint8_t _241_t5;
    uint8_t _241_t7;
    int16_t _241_t6;
    uint8_t _241_t8;
    uint8_t _241_t2;
    int8_t _241_t9;
    uint8_t _241_t11;
    uint8_t _241_t10;
    uint8_t _241_t1;
    int64_t _241_$retval;
    _241_t3 = 20;
    _241_t5 = _241_x == _241_t3;
    if (_241_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _241_t6 = 40;
    _241_t8 = _241_y == _241_t6;
    if (_241_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _241_t2 = 0;
    goto BB17;
BB4:
    _241_t7 = 1;
    goto BB5;
BB18:
    _241_t7 = 0;
    goto BB5;
BB17:
    _241_t1 = 0;
    goto BB15;
BB5:
    _241_t2 = _241_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-param.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_241_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _241_t9 = 60;
    _241_t11 = _241_z == _241_t9;
    if (_241_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _241_t10 = 1;
    goto BB9;
BB16:
    _241_t10 = 0;
    goto BB9;
BB9:
    _241_t1 = _241_t10;
    goto BB10;
BB10:
    if (_241_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _241_$retval = 255;
    return _241_$retval;
}

int64_t _238_main(void) {
    int64_t _238_$retval;
    _238_$retval = 255;
    return _238_$retval;
}

int main(void) {
  printf("%ld",_238_main());
  return 0;
}
