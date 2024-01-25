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
struct struct0 _354_f(int64_t _354_x);
int64_t _345_main(void);


/* Function definitions */
struct struct0 _354_f(int64_t _354_x){
    int64_t _354_t1;
    uint8_t _354_t3;
    struct struct0 _354_t0;
    int64_t _354_t8;
    uint8_t _354_t10;
    int64_t _354_t4;
    int64_t _354_t5;
    struct struct0 _354_t7;
    struct struct0 _354_$retval;
    _354_t1 = 53;
    _354_t3 = _354_x==_354_t1;
    if (_354_t3) {
        goto BB391;
    } else {
        goto BB395;
    }
BB391:
    _354_t4 = 5;
    _354_t5 = $mult_int64_t(_354_x, _354_t4, "tests/integration/comptime/return-sum.orng:13:16:\n        .ok(x * 5)\n              ^");
    _354_t0 = (struct struct0) {.tag=0, ._0=_354_t5};
    goto BB394;
BB395:
    _354_t8 = 4;
    _354_t10 = _354_x==_354_t8;
    if (_354_t10) {
        goto BB398;
    } else {
        goto BB401;
    }
BB394:
    _354_$retval = _354_t0;
    return _354_$retval;
BB398:
    _354_t7 = (struct struct0) {.tag=1};
    goto BB400;
BB401:
    _354_t7 = (struct struct0) {.tag=2};
    goto BB400;
BB400:
    _354_t0 = _354_t7;
    goto BB394;
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
