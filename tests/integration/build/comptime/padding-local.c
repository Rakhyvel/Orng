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
int64_t _230_main(void);
int64_t _232_f(int8_t _232_x,int16_t _232_y,int8_t _232_z);

/* Function definitions */
int64_t _230_main(void){
    int8_t _231_x;
    int16_t _231_y;
    int8_t _231_z;
    function0 _230_t3;
    int64_t _230_t4;
    int64_t _230_$retval;
    _231_x = 50;
    _231_y = 200;
    _231_z = 6;
    _230_t3 = _232_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _230_t4 = _230_t3(_231_x, _231_y, _231_z);
    $line_idx--;
    _230_$retval = _230_t4;
    return _230_$retval;
}

int64_t _232_f(int8_t _232_x,int16_t _232_y,int8_t _232_z){
    int8_t _232_t3;
    uint8_t _232_t5;
    uint8_t _232_t7;
    int16_t _232_t6;
    uint8_t _232_t8;
    uint8_t _232_t2;
    int8_t _232_t9;
    uint8_t _232_t11;
    uint8_t _232_t10;
    uint8_t _232_t1;
    int64_t _232_$retval;
    _232_t3 = 50;
    _232_t5 = _232_x == _232_t3;
    if (_232_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _232_t6 = 200;
    _232_t8 = _232_y == _232_t6;
    if (_232_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _232_t2 = 0;
    goto BB17;
BB4:
    _232_t7 = 1;
    goto BB5;
BB18:
    _232_t7 = 0;
    goto BB5;
BB17:
    _232_t1 = 0;
    goto BB15;
BB5:
    _232_t2 = _232_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_232_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _232_t9 = 6;
    _232_t11 = _232_z == _232_t9;
    if (_232_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _232_t10 = 1;
    goto BB9;
BB16:
    _232_t10 = 0;
    goto BB9;
BB9:
    _232_t1 = _232_t10;
    goto BB10;
BB10:
    if (_232_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _232_$retval = 256;
    return _232_$retval;
}

int main(void) {
  printf("%ld",_230_main());
  return 0;
}
