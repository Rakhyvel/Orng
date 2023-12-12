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
int64_t _46_main(void);
int64_t _48_f(int8_t _48_x,int16_t _48_y,int8_t _48_z);

/* Function definitions */
int64_t _46_main(void) {
    int8_t _47_x;
    int16_t _47_y;
    int8_t _47_z;
    function0 _46_t3;
    int64_t _46_t4;
    int64_t _46_$retval;
    _47_x = 50;
    _47_y = 200;
    _47_z = 6;
    _46_t3 = _48_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _46_t4 = _46_t3(_47_x, _47_y, _47_z);
    $line_idx--;
    _46_$retval = _46_t4;
    return _46_$retval;
}

int64_t _48_f(int8_t _48_x,int16_t _48_y,int8_t _48_z) {
    int8_t _48_t3;
    uint8_t _48_t5;
    uint8_t _48_t7;
    int16_t _48_t6;
    uint8_t _48_t8;
    uint8_t _48_t2;
    int8_t _48_t9;
    uint8_t _48_t11;
    uint8_t _48_t10;
    uint8_t _48_t1;
    int64_t _48_$retval;
    _48_t3 = 50;
    _48_t5 = _48_x == _48_t3;
    if (_48_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _48_t6 = 200;
    _48_t8 = _48_y == _48_t6;
    if (_48_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _48_t2 = 0;
    goto BB17;
BB4:
    _48_t7 = 1;
    goto BB5;
BB18:
    _48_t7 = 0;
    goto BB5;
BB17:
    _48_t1 = 0;
    goto BB15;
BB5:
    _48_t2 = _48_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_48_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _48_t9 = 6;
    _48_t11 = _48_z == _48_t9;
    if (_48_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _48_t10 = 1;
    goto BB9;
BB16:
    _48_t10 = 0;
    goto BB9;
BB9:
    _48_t1 = _48_t10;
    goto BB10;
BB10:
    if (_48_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _48_$retval = 256;
    return _48_$retval;
}

int main(void) {
  printf("%ld",_46_main());
  return 0;
}
