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
int64_t _125_f(struct0 _125_m);
int64_t _121_main(void);

/* Function definitions */
int64_t _125_f(struct0 _125_m){
    int8_t _125_t3;
    uint8_t _125_t5;
    int64_t _125_t0;
    int32_t _125_t6;
    uint8_t _125_t8;
    int8_t _125_t9;
    uint8_t _125_t11;
    int64_t _125_$retval;
    _125_t3 = 100;
    _125_t5 = _125_m._0 == _125_t3;
    if (_125_t5) {
        goto BB3;
    } else {
        goto BB15;
    }
BB3:
    _125_t6 = 50;
    _125_t8 = _125_m._1 == _125_t6;
    if (_125_t8) {
        goto BB7;
    } else {
        goto BB15;
    }
BB15:
    _125_t0 = 0;
    goto BB14;
BB7:
    _125_t9 = 7;
    _125_t11 = _125_m._2 == _125_t9;
    if (_125_t11) {
        goto BB11;
    } else {
        goto BB15;
    }
BB14:
    _125_$retval = _125_t0;
    return _125_$retval;
BB11:
    _125_t0 = 248;
    goto BB14;
}

int64_t _121_main(void){
    int64_t _121_$retval;
    _121_$retval = 257;
    return _121_$retval;
}

int main(void) {
  printf("%ld",_121_main());
  return 0;
}
