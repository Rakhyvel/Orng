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
    uint64_t tag;
    union {
        int64_t _0;
    };
};

/* Function forward definitions */
struct struct0 _353_f(int64_t _353_x);
int64_t _345_main(void);


/* Function definitions */
struct struct0 _353_f(int64_t _353_x){
    int64_t _353_t1;
    uint8_t _353_t3;
    struct struct0 _353_t0;
    int64_t _353_t8;
    uint8_t _353_t10;
    int64_t _353_t4;
    int64_t _353_t5;
    struct struct0 _353_t7;
    struct struct0 _353_$retval;
    _353_t1 = 53;
    _353_t3 = _353_x==_353_t1;
    if (_353_t3) {
        goto BB384;
    } else {
        goto BB388;
    }
BB384:
    _353_t4 = 5;
    _353_t5 = $mult_int64_t(_353_x, _353_t4, "tests/integration/comptime/return-sum.orng:12:16:\n        .ok(x * 5)\n              ^");
    _353_t0 = (struct struct0) {.tag=0, ._0=_353_t5};
    goto BB387;
BB388:
    _353_t8 = 4;
    _353_t10 = _353_x==_353_t8;
    if (_353_t10) {
        goto BB391;
    } else {
        goto BB394;
    }
BB387:
    _353_$retval = _353_t0;
    return _353_$retval;
BB391:
    _353_t7 = (struct struct0) {.tag=1};
    goto BB393;
BB394:
    _353_t7 = (struct struct0) {.tag=1};
    goto BB393;
BB393:
    _353_t0 = _353_t7;
    goto BB387;
}

int64_t _345_main(void){
    int64_t _345_t1;
    struct struct0 _345_t2;
    int64_t _345_$retval;
    _345_t1 = 265;
    _345_t2 = (struct struct0) {.tag=0, ._0=_345_t1};
    _345_$retval = _345_t2._0;
    return _345_$retval;
}


int main(void) {
  printf("%ld",_345_main());
  return 0;
}
