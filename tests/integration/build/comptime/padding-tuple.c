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
int64_t _366_f(struct0 _366_m);
int64_t _362_main(void);

/* Function definitions */
int64_t _366_f(struct0 _366_m){
    int8_t _366_t3;
    uint8_t _366_t5;
    int64_t _366_t0;
    int32_t _366_t6;
    uint8_t _366_t8;
    int8_t _366_t9;
    uint8_t _366_t11;
    int64_t _366_$retval;
    _366_t3 = 100;
    _366_t5 = _366_m._0 == _366_t3;
    if (_366_t5) {
        goto BB3;
    } else {
        goto BB15;
    }
BB3:
    _366_t6 = 50;
    _366_t8 = _366_m._1 == _366_t6;
    if (_366_t8) {
        goto BB7;
    } else {
        goto BB15;
    }
BB15:
    _366_t0 = 0;
    goto BB14;
BB7:
    _366_t9 = 7;
    _366_t11 = _366_m._2 == _366_t9;
    if (_366_t11) {
        goto BB11;
    } else {
        goto BB15;
    }
BB14:
    _366_$retval = _366_t0;
    return _366_$retval;
BB11:
    _366_t0 = 248;
    goto BB14;
}

int64_t _362_main(void){
    int64_t _362_$retval;
    _362_$retval = 257;
    return _362_$retval;
}

int main(void) {
  printf("%ld",_362_main());
  return 0;
}
