/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _267_f(int8_t _267_x, int16_t _267_y, int8_t _267_z);
int64_t _264_main(void);

/* Function definitions */
int64_t _267_f(int8_t _267_x, int16_t _267_y, int8_t _267_z){
    int8_t _267_t1;
    uint8_t _267_t3;
    int64_t _267_$retval;
    int16_t _267_t4;
    uint8_t _267_t6;
    int8_t _267_t7;
    uint8_t _267_t9;
    _267_t1 = 20;
    _267_t3 = _267_x==_267_t1;
    if (_267_t3) {
        goto BB293;
    } else {
        goto BB303;
    }
BB293:
    _267_t4 = 40;
    _267_t6 = _267_y==_267_t4;
    if (_267_t6) {
        goto BB296;
    } else {
        goto BB303;
    }
BB303:
    $lines[$line_idx++] = "tests/integration/comptime/padding-param.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB296:
    _267_t7 = 60;
    _267_t9 = _267_z==_267_t7;
    if (_267_t9) {
        goto BB299;
    } else {
        goto BB303;
    }
BB299:
    _267_$retval = 255;
    return _267_$retval;
}

int64_t _264_main(void){
    int64_t _264_$retval;
    _264_$retval = 255;
    return _264_$retval;
}

int main(void) {
  printf("%ld",_264_main());
  return 0;
}
