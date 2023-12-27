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
    int8_t _281_t1;
    uint8_t _281_t3;
    int64_t _281_t0;
    int32_t _281_t4;
    uint8_t _281_t6;
    int64_t _281_$retval;
    int8_t _281_t7;
    uint8_t _281_t9;
    _281_t1 = 100;
    _281_t3 = _281_m._0==_281_t1;
    if (_281_t3) {
        goto BB318;
    } else {
        goto BB328;
    }
BB318:
    _281_t4 = 50;
    _281_t6 = _281_m._1==_281_t4;
    if (_281_t6) {
        goto BB321;
    } else {
        goto BB328;
    }
BB328:
    _281_t0 = 0;
    goto BB327;
BB321:
    _281_t7 = 7;
    _281_t9 = _281_m._2==_281_t7;
    if (_281_t9) {
        goto BB324;
    } else {
        goto BB328;
    }
BB327:
    _281_$retval = _281_t0;
    return _281_$retval;
BB324:
    _281_t0 = 248;
    goto BB327;
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
