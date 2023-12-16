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
int64_t _267_f(struct0 _267_m);
int64_t _263_main(void);

/* Function definitions */
int64_t _267_f(struct0 _267_m){
    int8_t _267_t3;
    uint8_t _267_t5;
    int64_t _267_t0;
    int32_t _267_t6;
    uint8_t _267_t8;
    int8_t _267_t9;
    uint8_t _267_t11;
    int64_t _267_$retval;
    _267_t3 = 100;
    _267_t5 = _267_m._0 == _267_t3;
    if (_267_t5) {
        goto BB3;
    } else {
        goto BB15;
    }
BB3:
    _267_t6 = 50;
    _267_t8 = _267_m._1 == _267_t6;
    if (_267_t8) {
        goto BB7;
    } else {
        goto BB15;
    }
BB15:
    _267_t0 = 0;
    goto BB14;
BB7:
    _267_t9 = 7;
    _267_t11 = _267_m._2 == _267_t9;
    if (_267_t11) {
        goto BB11;
    } else {
        goto BB15;
    }
BB14:
    _267_$retval = _267_t0;
    return _267_$retval;
BB11:
    _267_t0 = 248;
    goto BB14;
}

int64_t _263_main(void){
    int64_t _263_$retval;
    _263_$retval = 257;
    return _263_$retval;
}

int main(void) {
  printf("%ld",_263_main());
  return 0;
}
