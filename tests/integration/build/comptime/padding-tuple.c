/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int8_t _0;
        int32_t _1;
        int8_t _2;
} struct0;

/* Function forward definitions */
int64_t _282_f(struct0 _282_m);
int64_t _278_main(void);

/* Function definitions */
int64_t _282_f(struct0 _282_m){
    int8_t _282_t1;
    uint8_t _282_t3;
    int64_t _282_t0;
    int32_t _282_t4;
    uint8_t _282_t6;
    int64_t _282_$retval;
    int8_t _282_t7;
    uint8_t _282_t9;
    _282_t1 = 100;
    _282_t3 = _282_m._0==_282_t1;
    if (_282_t3) {
        goto BB318;
    } else {
        goto BB328;
    }
BB318:
    _282_t4 = 50;
    _282_t6 = _282_m._1==_282_t4;
    if (_282_t6) {
        goto BB321;
    } else {
        goto BB328;
    }
BB328:
    _282_t0 = 0;
    goto BB327;
BB321:
    _282_t7 = 7;
    _282_t9 = _282_m._2==_282_t7;
    if (_282_t9) {
        goto BB324;
    } else {
        goto BB328;
    }
BB327:
    _282_$retval = _282_t0;
    return _282_$retval;
BB324:
    _282_t0 = 248;
    goto BB327;
}

int64_t _278_main(void){
    int64_t _278_$retval;
    _278_$retval = 257;
    return _278_$retval;
}

int main(void) {
  printf("%ld",_278_main());
  return 0;
}
