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
int64_t _255_main(void);
int64_t _257_f(int8_t _257_x,int16_t _257_y,int8_t _257_z);

/* Function definitions */
int64_t _255_main(void){
    int8_t _256_x;
    int16_t _256_y;
    int8_t _256_z;
    function0 _255_t3;
    int64_t _255_t4;
    int64_t _255_$retval;
    _256_x = 50;
    _256_y = 200;
    _256_z = 6;
    _255_t3 = _257_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _255_t4 = _255_t3(_256_x, _256_y, _256_z);
    $line_idx--;
    _255_$retval = _255_t4;
    return _255_$retval;
}

int64_t _257_f(int8_t _257_x,int16_t _257_y,int8_t _257_z){
    int8_t _257_t3;
    uint8_t _257_t5;
    uint8_t _257_t7;
    int16_t _257_t6;
    uint8_t _257_t8;
    uint8_t _257_t2;
    int8_t _257_t9;
    uint8_t _257_t11;
    uint8_t _257_t10;
    uint8_t _257_t1;
    int64_t _257_$retval;
    _257_t3 = 50;
    _257_t5 = _257_x == _257_t3;
    if (_257_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _257_t6 = 200;
    _257_t8 = _257_y == _257_t6;
    if (_257_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _257_t2 = 0;
    goto BB17;
BB4:
    _257_t7 = 1;
    goto BB5;
BB18:
    _257_t7 = 0;
    goto BB5;
BB17:
    _257_t1 = 0;
    goto BB15;
BB5:
    _257_t2 = _257_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_257_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _257_t9 = 6;
    _257_t11 = _257_z == _257_t9;
    if (_257_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _257_t10 = 1;
    goto BB9;
BB16:
    _257_t10 = 0;
    goto BB9;
BB9:
    _257_t1 = _257_t10;
    goto BB10;
BB10:
    if (_257_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _257_$retval = 256;
    return _257_$retval;
}

int main(void) {
  printf("%ld",_255_main());
  return 0;
}
