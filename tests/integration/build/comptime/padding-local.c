/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int8_t _0;
    int16_t _1;
    int8_t _2;
};

typedef int64_t(*function0)(int8_t, int16_t, int8_t);

/* Function forward definitions */
int64_t _282_main(void);
int64_t _284_f(int8_t _284_x, int16_t _284_y, int8_t _284_z);


/* Function definitions */
int64_t _282_main(void){
    int8_t _283_x;
    int16_t _283_y;
    int8_t _283_z;
    function0 _282_t6;
    int64_t _282_t7;
    int64_t _282_$retval;
    _283_x = 50;
    _283_y = 200;
    _283_z = 6;
    _282_t6 = (function0) _284_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _282_t7 = _282_t6(_283_x, _283_y, _283_z);
    $line_idx--;
    _282_$retval = _282_t7;
    return _282_$retval;
}

int64_t _284_f(int8_t _284_x, int16_t _284_y, int8_t _284_z){
    int8_t _284_t1;
    uint8_t _284_t3;
    int64_t _284_$retval;
    int16_t _284_t4;
    uint8_t _284_t6;
    int8_t _284_t7;
    uint8_t _284_t9;
    _284_t1 = 50;
    _284_t3 = _284_x==_284_t1;
    if (_284_t3) {
        goto BB279;
    } else {
        goto BB289;
    }
BB279:
    _284_t4 = 200;
    _284_t6 = _284_y==_284_t4;
    if (_284_t6) {
        goto BB282;
    } else {
        goto BB289;
    }
BB289:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB282:
    _284_t7 = 6;
    _284_t9 = _284_z==_284_t7;
    if (_284_t9) {
        goto BB285;
    } else {
        goto BB289;
    }
BB285:
    _284_$retval = 256;
    return _284_$retval;
}


int main(void) {
  printf("%ld",_282_main());
  return 0;
}
