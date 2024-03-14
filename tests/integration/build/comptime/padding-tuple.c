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
int64_t _303_f(struct struct0 _303_m);
int64_t _298_main(void);


/* Function definitions */
int64_t _303_f(struct struct0 _303_m){
    int8_t _303_t1;
    uint8_t _303_t3;
    int64_t _303_t0;
    int32_t _303_t4;
    uint8_t _303_t6;
    int64_t _303_$retval;
    int8_t _303_t7;
    uint8_t _303_t9;
    _303_t1 = 100;
    _303_t3 = _303_m._0==_303_t1;
    if (_303_t3) {
        goto BB319;
    } else {
        goto BB329;
    }
BB319:
    _303_t4 = 50;
    _303_t6 = _303_m._1==_303_t4;
    if (_303_t6) {
        goto BB322;
    } else {
        goto BB329;
    }
BB329:
    _303_t0 = 0;
    goto BB328;
BB322:
    _303_t7 = 7;
    _303_t9 = _303_m._2==_303_t7;
    if (_303_t9) {
        goto BB325;
    } else {
        goto BB329;
    }
BB328:
    _303_$retval = _303_t0;
    return _303_$retval;
BB325:
    _303_t0 = 248;
    goto BB328;
}

int64_t _298_main(void){
    int64_t _298_$retval;
    _298_$retval = 257;
    return _298_$retval;
}


int main(void) {
  printf("%ld",_298_main());
  return 0;
}
