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
int64_t _340_main(void);
int64_t _342_f(int8_t _342_x,int16_t _342_y,int8_t _342_z);

/* Function definitions */
int64_t _340_main(void){
    int8_t _341_x;
    int16_t _341_y;
    int8_t _341_z;
    function0 _340_t3;
    int64_t _340_t4;
    int64_t _340_$retval;
    _341_x = 50;
    _341_y = 200;
    _341_z = 6;
    _340_t3 = _342_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _340_t4 = _340_t3(_341_x, _341_y, _341_z);
    $line_idx--;
    _340_$retval = _340_t4;
    return _340_$retval;
}

int64_t _342_f(int8_t _342_x,int16_t _342_y,int8_t _342_z){
    int8_t _342_t3;
    uint8_t _342_t5;
    uint8_t _342_t7;
    int16_t _342_t6;
    uint8_t _342_t8;
    uint8_t _342_t2;
    int8_t _342_t9;
    uint8_t _342_t11;
    uint8_t _342_t10;
    uint8_t _342_t1;
    int64_t _342_$retval;
    _342_t3 = 50;
    _342_t5 = _342_x == _342_t3;
    if (_342_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _342_t6 = 200;
    _342_t8 = _342_y == _342_t6;
    if (_342_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _342_t2 = 0;
    goto BB17;
BB4:
    _342_t7 = 1;
    goto BB5;
BB18:
    _342_t7 = 0;
    goto BB5;
BB17:
    _342_t1 = 0;
    goto BB15;
BB5:
    _342_t2 = _342_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_342_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _342_t9 = 6;
    _342_t11 = _342_z == _342_t9;
    if (_342_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _342_t10 = 1;
    goto BB9;
BB16:
    _342_t10 = 0;
    goto BB9;
BB9:
    _342_t1 = _342_t10;
    goto BB10;
BB10:
    if (_342_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _342_$retval = 256;
    return _342_$retval;
}

int main(void) {
  printf("%ld",_340_main());
  return 0;
}
