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
int64_t _281_f(struct0 _281_m);
int64_t _277_main(void);

/* Function definitions */
int64_t _281_f(struct0 _281_m){
    int8_t _281_t3;
    uint8_t _281_t5;
    int64_t _281_t0;
    int32_t _281_t6;
    uint8_t _281_t8;
    int8_t _281_t9;
    uint8_t _281_t11;
    int64_t _281_$retval;
    _281_t3 = 100;
    _281_t5 = _281_m._0 == _281_t3;
    if (_281_t5) {
        goto BB3;
    } else {
        goto BB15;
    }
BB3:
    _281_t6 = 50;
    _281_t8 = _281_m._1 == _281_t6;
    if (_281_t8) {
        goto BB7;
    } else {
        goto BB15;
    }
BB15:
    _281_t0 = 0;
    goto BB14;
BB7:
    _281_t9 = 7;
    _281_t11 = _281_m._2 == _281_t9;
    if (_281_t11) {
        goto BB11;
    } else {
        goto BB15;
    }
BB14:
    _281_$retval = _281_t0;
    return _281_$retval;
BB11:
    _281_t0 = 248;
    goto BB14;
}

int64_t _277_main(void){
    int64_t _277_$retval;
    _277_$retval = 257;
    return _277_$retval;
}

int main(void) {
  printf("%ld",_277_main());
  return 0;
}
