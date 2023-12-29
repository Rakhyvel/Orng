/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _266_f(int8_t _266_x, int16_t _266_y, int8_t _266_z);
int64_t _263_main(void);

/* Function definitions */
int64_t _266_f(int8_t _266_x, int16_t _266_y, int8_t _266_z){
    int8_t _266_t1;
    uint8_t _266_t3;
    int64_t _266_$retval;
    int16_t _266_t4;
    uint8_t _266_t6;
    int8_t _266_t7;
    uint8_t _266_t9;
    _266_t1 = 20;
    _266_t3 = _266_x==_266_t1;
    if (_266_t3) {
        goto BB293;
    } else {
        goto BB303;
    }
BB293:
    _266_t4 = 40;
    _266_t6 = _266_y==_266_t4;
    if (_266_t6) {
        goto BB296;
    } else {
        goto BB303;
    }
BB303:
    $lines[$line_idx++] = "tests/integration/comptime/padding-param.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB296:
    _266_t7 = 60;
    _266_t9 = _266_z==_266_t7;
    if (_266_t9) {
        goto BB299;
    } else {
        goto BB303;
    }
BB299:
    _266_$retval = 255;
    return _266_$retval;
}

int64_t _263_main(void){
    int64_t _263_$retval;
    _263_$retval = 255;
    return _263_$retval;
}

int main(void) {
  printf("%ld",_263_main());
  return 0;
}
