/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _287_f(int8_t _287_x, int16_t _287_y, int8_t _287_z);
int64_t _283_main(void);


/* Function definitions */
int64_t _287_f(int8_t _287_x, int16_t _287_y, int8_t _287_z){
    int8_t _287_t1;
    uint8_t _287_t3;
    int64_t _287_$retval;
    int16_t _287_t4;
    uint8_t _287_t6;
    int8_t _287_t7;
    uint8_t _287_t9;
    _287_t1 = 20;
    _287_t3 = _287_x==_287_t1;
    if (_287_t3) {
        goto BB293;
    } else {
        goto BB303;
    }
BB293:
    _287_t4 = 40;
    _287_t6 = _287_y==_287_t4;
    if (_287_t6) {
        goto BB296;
    } else {
        goto BB303;
    }
BB303:
    $lines[$line_idx++] = "tests/integration/comptime/padding-param.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB296:
    _287_t7 = 60;
    _287_t9 = _287_z==_287_t7;
    if (_287_t9) {
        goto BB299;
    } else {
        goto BB303;
    }
BB299:
    _287_$retval = 255;
    return _287_$retval;
}

int64_t _283_main(void){
    int64_t _283_$retval;
    _283_$retval = 255;
    return _283_$retval;
}


int main(void) {
  printf("%ld",_283_main());
  return 0;
}
