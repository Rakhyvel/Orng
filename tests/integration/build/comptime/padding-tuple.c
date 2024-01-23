/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int8_t _0;
    int32_t _1;
    int8_t _2;
};

/* Function forward definitions */
int64_t _282_f(struct struct0 _282_m);
int64_t _278_main(void);


/* Function definitions */
int64_t _282_f(struct struct0 _282_m){
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
        goto BB309;
    } else {
        goto BB319;
    }
BB309:
    _282_t4 = 50;
    _282_t6 = _282_m._1==_282_t4;
    if (_282_t6) {
        goto BB312;
    } else {
        goto BB319;
    }
BB319:
    _282_t0 = 0;
    goto BB318;
BB312:
    _282_t7 = 7;
    _282_t9 = _282_m._2==_282_t7;
    if (_282_t9) {
        goto BB315;
    } else {
        goto BB319;
    }
BB318:
    _282_$retval = _282_t0;
    return _282_$retval;
BB315:
    _282_t0 = 248;
    goto BB318;
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
