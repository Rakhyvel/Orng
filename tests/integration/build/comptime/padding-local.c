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
int64_t _129_main(void);
int64_t _131_f(int8_t _131_x,int16_t _131_y,int8_t _131_z);

/* Function definitions */
int64_t _129_main(void) {
    int8_t _130_x;
    int16_t _130_y;
    int8_t _130_z;
    function0 _129_t3;
    int64_t _129_t4;
    int64_t _129_$retval;
    _130_x = 50;
    _130_y = 200;
    _130_z = 6;
    _129_t3 = _131_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _129_t4 = _129_t3(_130_x, _130_y, _130_z);
    $line_idx--;
    _129_$retval = _129_t4;
    return _129_$retval;
}

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
    _131_t3 = 50;
    _131_t5 = _131_x == _131_t3;
    if (_131_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _131_t6 = 200;
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
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_131_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _131_t9 = 6;
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
    _131_$retval = 256;
    return _131_$retval;
}

int main(void) {
  printf("%ld",_129_main());
  return 0;
}
