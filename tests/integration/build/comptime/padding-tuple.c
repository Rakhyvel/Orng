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
int64_t _256_f(struct0 _256_m);
int64_t _252_main(void);

/* Function definitions */
int64_t _256_f(struct0 _256_m) {
    int8_t _256_t3;
    uint8_t _256_t5;
    int64_t _256_t0;
    int32_t _256_t6;
    uint8_t _256_t8;
    int8_t _256_t9;
    uint8_t _256_t11;
    int64_t _256_$retval;
    _256_t3 = 100;
    _256_t5 = _256_m._0 == _256_t3;
    if (_256_t5) {
        goto BB3;
    } else {
        goto BB15;
    }
BB3:
    _256_t6 = 50;
    _256_t8 = _256_m._1 == _256_t6;
    if (_256_t8) {
        goto BB7;
    } else {
        goto BB15;
    }
BB15:
    _256_t0 = 0;
    goto BB14;
BB7:
    _256_t9 = 7;
    _256_t11 = _256_m._2 == _256_t9;
    if (_256_t11) {
        goto BB11;
    } else {
        goto BB15;
    }
BB14:
    _256_$retval = _256_t0;
    return _256_$retval;
BB11:
    _256_t0 = 248;
    goto BB14;
}

int64_t _252_main(void) {
    int64_t _252_$retval;
    _252_$retval = 257;
    return _252_$retval;
}

int main(void) {
  printf("%ld",_252_main());
  return 0;
}
