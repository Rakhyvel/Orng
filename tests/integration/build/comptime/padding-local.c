/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int8_t _0;
    int16_t _1;
    int8_t _2;
} struct1;

typedef int64_t(*function0)(int8_t, int16_t, int8_t);

/* Function forward definitions */
int64_t _241_main(void);
int64_t _243_f(int8_t _243_x,int16_t _243_y,int8_t _243_z);

/* Function definitions */
int64_t _241_main(void){
    int8_t _242_x;
    int16_t _242_y;
    int8_t _242_z;
    function0 _241_t3;
    int64_t _241_t4;
    int64_t _241_$retval;
    _242_x = 50;
    _242_y = 200;
    _242_z = 6;
    _241_t3 = _243_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _241_t4 = _241_t3(_242_x, _242_y, _242_z);
    $line_idx--;
    _241_$retval = _241_t4;
    return _241_$retval;
}

int64_t _243_f(int8_t _243_x,int16_t _243_y,int8_t _243_z){
    int8_t _243_t3;
    uint8_t _243_t5;
    uint8_t _243_t7;
    int16_t _243_t6;
    uint8_t _243_t8;
    uint8_t _243_t2;
    int8_t _243_t9;
    uint8_t _243_t11;
    uint8_t _243_t10;
    uint8_t _243_t1;
    int64_t _243_$retval;
    _243_t3 = 50;
    _243_t5 = _243_x == _243_t3;
    if (_243_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _243_t6 = 200;
    _243_t8 = _243_y == _243_t6;
    if (_243_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _243_t2 = 0;
    goto BB17;
BB4:
    _243_t7 = 1;
    goto BB5;
BB18:
    _243_t7 = 0;
    goto BB5;
BB17:
    _243_t1 = 0;
    goto BB15;
BB5:
    _243_t2 = _243_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_243_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _243_t9 = 6;
    _243_t11 = _243_z == _243_t9;
    if (_243_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _243_t10 = 1;
    goto BB9;
BB16:
    _243_t10 = 0;
    goto BB9;
BB9:
    _243_t1 = _243_t10;
    goto BB10;
BB10:
    if (_243_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _243_$retval = 256;
    return _243_$retval;
}

int main(void) {
  printf("%ld",_241_main());
  return 0;
}
