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
int64_t _280_main(void);
int64_t _282_f(int8_t _282_x, int16_t _282_y, int8_t _282_z);


/* Function definitions */
int64_t _280_main(void){
    int8_t _281_x;
    int16_t _281_y;
    int8_t _281_z;
    function0 _280_t6;
    int64_t _280_t7;
    int64_t _280_$retval;
    _281_x = 50;
    _281_y = 200;
    _281_z = 6;
    _280_t6 = (function0) _282_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _280_t7 = _280_t6(_281_x, _281_y, _281_z);
    $line_idx--;
    _280_$retval = _280_t7;
    return _280_$retval;
}

int64_t _282_f(int8_t _282_x, int16_t _282_y, int8_t _282_z){
    int8_t _282_t1;
    uint8_t _282_t3;
    int64_t _282_$retval;
    int16_t _282_t4;
    uint8_t _282_t6;
    int8_t _282_t7;
    uint8_t _282_t9;
    _282_t1 = 50;
    _282_t3 = _282_x==_282_t1;
    if (_282_t3) {
        goto BB277;
    } else {
        goto BB287;
    }
BB277:
    _282_t4 = 200;
    _282_t6 = _282_y==_282_t4;
    if (_282_t6) {
        goto BB280;
    } else {
        goto BB287;
    }
BB287:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB280:
    _282_t7 = 6;
    _282_t9 = _282_z==_282_t7;
    if (_282_t9) {
        goto BB283;
    } else {
        goto BB287;
    }
BB283:
    _282_$retval = 256;
    return _282_$retval;
}


int main(void) {
  printf("%ld",_280_main());
  return 0;
}
