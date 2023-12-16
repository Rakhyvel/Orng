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
int64_t _99_main(void);
int64_t _101_f(int8_t _101_x,int16_t _101_y,int8_t _101_z);

/* Function definitions */
int64_t _99_main(void){
    int8_t _100_x;
    int16_t _100_y;
    int8_t _100_z;
    function0 _99_t3;
    int64_t _99_t4;
    int64_t _99_$retval;
    _100_x = 50;
    _100_y = 200;
    _100_z = 6;
    _99_t3 = _101_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _99_t4 = _99_t3(_100_x, _100_y, _100_z);
    $line_idx--;
    _99_$retval = _99_t4;
    return _99_$retval;
}

int64_t _101_f(int8_t _101_x,int16_t _101_y,int8_t _101_z){
    int8_t _101_t3;
    uint8_t _101_t5;
    uint8_t _101_t7;
    int16_t _101_t6;
    uint8_t _101_t8;
    uint8_t _101_t2;
    int8_t _101_t9;
    uint8_t _101_t11;
    uint8_t _101_t10;
    uint8_t _101_t1;
    int64_t _101_$retval;
    _101_t3 = 50;
    _101_t5 = _101_x == _101_t3;
    if (_101_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _101_t6 = 200;
    _101_t8 = _101_y == _101_t6;
    if (_101_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _101_t2 = 0;
    goto BB17;
BB4:
    _101_t7 = 1;
    goto BB5;
BB18:
    _101_t7 = 0;
    goto BB5;
BB17:
    _101_t1 = 0;
    goto BB15;
BB5:
    _101_t2 = _101_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_101_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _101_t9 = 6;
    _101_t11 = _101_z == _101_t9;
    if (_101_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _101_t10 = 1;
    goto BB9;
BB16:
    _101_t10 = 0;
    goto BB9;
BB9:
    _101_t1 = _101_t10;
    goto BB10;
BB10:
    if (_101_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _101_$retval = 256;
    return _101_$retval;
}

int main(void) {
  printf("%ld",_99_main());
  return 0;
}
