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
    _281_t5 = _281_m._0==_281_t3;
    if (_281_t5) {
        goto BB328;
    } else {
        goto BB340;
    }
BB328:
    _281_t6 = 50;
    _281_t8 = _281_m._1==_281_t6;
    if (_281_t8) {
        goto BB332;
    } else {
        goto BB340;
    }
BB340:
    _281_t0 = 0;
    goto BB339;
BB332:
    _281_t9 = 7;
    _281_t11 = _281_m._2==_281_t9;
    if (_281_t11) {
        goto BB336;
    } else {
        goto BB340;
    }
BB339:
    _281_$retval = _281_t0;
    return _281_$retval;
BB336:
    _281_t0 = 248;
    goto BB339;
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
