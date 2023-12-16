/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _110_f(int8_t _110_x,int16_t _110_y,int8_t _110_z);
int64_t _107_main(void);

/* Function definitions */
int64_t _110_f(int8_t _110_x,int16_t _110_y,int8_t _110_z){
    int8_t _110_t3;
    uint8_t _110_t5;
    uint8_t _110_t7;
    int16_t _110_t6;
    uint8_t _110_t8;
    uint8_t _110_t2;
    int8_t _110_t9;
    uint8_t _110_t11;
    uint8_t _110_t10;
    uint8_t _110_t1;
    int64_t _110_$retval;
    _110_t3 = 20;
    _110_t5 = _110_x == _110_t3;
    if (_110_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _110_t6 = 40;
    _110_t8 = _110_y == _110_t6;
    if (_110_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _110_t2 = 0;
    goto BB17;
BB4:
    _110_t7 = 1;
    goto BB5;
BB18:
    _110_t7 = 0;
    goto BB5;
BB17:
    _110_t1 = 0;
    goto BB15;
BB5:
    _110_t2 = _110_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-param.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_110_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _110_t9 = 60;
    _110_t11 = _110_z == _110_t9;
    if (_110_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _110_t10 = 1;
    goto BB9;
BB16:
    _110_t10 = 0;
    goto BB9;
BB9:
    _110_t1 = _110_t10;
    goto BB10;
BB10:
    if (_110_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _110_$retval = 255;
    return _110_$retval;
}

int64_t _107_main(void){
    int64_t _107_$retval;
    _107_$retval = 255;
    return _107_$retval;
}

int main(void) {
  printf("%ld",_107_main());
  return 0;
}
