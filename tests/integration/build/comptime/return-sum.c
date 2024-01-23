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
struct struct0 _328_f(int64_t _328_x);
int64_t _320_main(void);


/* Function definitions */
struct struct0 _328_f(int64_t _328_x){
    int64_t _328_t1;
    uint8_t _328_t3;
    struct struct0 _328_t0;
    int64_t _328_t8;
    uint8_t _328_t10;
    int64_t _328_t4;
    int64_t _328_t5;
    struct struct0 _328_t7;
    struct struct0 _328_$retval;
    _328_t1 = 53;
    _328_t3 = _328_x==_328_t1;
    if (_328_t3) {
        goto BB371;
    } else {
        goto BB375;
    }
BB371:
    _328_t4 = 5;
    _328_t5 = $mult_int64_t(_328_x, _328_t4, "tests/integration/comptime/return-sum.orng:13:16:\n        .ok(x * 5)\n              ^");
    _328_t0 = (struct struct0) {.tag=0, ._0=_328_t5};
    goto BB374;
BB375:
    _328_t8 = 4;
    _328_t10 = _328_x==_328_t8;
    if (_328_t10) {
        goto BB378;
    } else {
        goto BB381;
    }
BB374:
    _328_$retval = _328_t0;
    return _328_$retval;
BB378:
    _328_t7 = (struct struct0) {.tag=1};
    goto BB380;
BB381:
    _328_t7 = (struct struct0) {.tag=2};
    goto BB380;
BB380:
    _328_t0 = _328_t7;
    goto BB374;
}

int64_t _320_main(void){
    int64_t _320_t1;
    struct struct0 _320_t2;
    int64_t _320_$retval;
    _320_t1 = 265;
    _320_t2 = (struct struct0) {.tag=0, ._0=_320_t1};
    _320_$retval = _320_t2._0;
    return _320_$retval;
}


int main(void) {
  printf("%ld",_320_main());
  return 0;
}
