/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _266_f(int8_t _266_x,int16_t _266_y,int8_t _266_z);
int64_t _263_main(void);

/* Function definitions */
int64_t _266_f(int8_t _266_x,int16_t _266_y,int8_t _266_z){
    int8_t _266_t3;
    uint8_t _266_t5;
    uint8_t _266_t7;
    int16_t _266_t6;
    uint8_t _266_t8;
    uint8_t _266_t2;
    int8_t _266_t9;
    uint8_t _266_t11;
    uint8_t _266_t10;
    uint8_t _266_t1;
    int64_t _266_$retval;
    _266_t3 = 20;
    _266_t5 = _266_x == _266_t3;
    if (_266_t5) {
        goto BB299;
    } else {
        goto BB315;
    }
BB299:
    _266_t6 = 40;
    _266_t8 = _266_y == _266_t6;
    if (_266_t8) {
        goto BB300;
    } else {
        goto BB314;
    }
BB315:
    _266_t2 = 0;
    goto BB313;
BB300:
    _266_t7 = 1;
    goto BB301;
BB314:
    _266_t7 = 0;
    goto BB301;
BB313:
    _266_t1 = 0;
    goto BB311;
BB301:
    _266_t2 = _266_t7;
    goto BB302;
BB311:
    $lines[$line_idx++] = "tests/integration/comptime/padding-param.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB302:
    if (_266_t2) {
        goto BB303;
    } else {
        goto BB313;
    }
BB303:
    _266_t9 = 60;
    _266_t11 = _266_z == _266_t9;
    if (_266_t11) {
        goto BB304;
    } else {
        goto BB312;
    }
BB304:
    _266_t10 = 1;
    goto BB305;
BB312:
    _266_t10 = 0;
    goto BB305;
BB305:
    _266_t1 = _266_t10;
    goto BB306;
BB306:
    if (_266_t1) {
        goto BB307;
    } else {
        goto BB311;
    }
BB307:
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
