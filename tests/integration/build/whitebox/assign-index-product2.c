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
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1754_main(void);


/* Function definitions */
int64_t _1754_main(void){
    int64_t _1754_t1;
    int64_t _1754_t2;
    struct struct0 _1755_x;
    int64_t _1754_t5;
    int64_t _1754_t6;
    int64_t _1754_t7;
    int64_t _1754_t8;
    struct struct0 _1754_t4;
    int64_t _1754_t11;
    int64_t _1754_t12;
    int64_t _1754_t15;
    int64_t _1754_t16;
    int64_t _1754_t17;
    int64_t _1754_t18;
    int64_t _1754_t19;
    int64_t _1754_t20;
    int64_t _1754_$retval;
    _1754_t1 = 2;
    _1754_t2 = 324;
    _1755_x = (struct struct0) {_1754_t1, _1754_t2};
    _1754_t5 = 1;
    _1754_t6 = 2;
    _1754_t7 = 0;
    _1754_t8 = 2;
    $bounds_check(_1754_t5, _1754_t6, "tests/integration/whitebox/assign-index-product2.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    $bounds_check(_1754_t7, _1754_t8, "tests/integration/whitebox/assign-index-product2.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    _1754_t4 = (struct struct0) {(*((int64_t*)&_1755_x + _1754_t5)), (*((int64_t*)&_1755_x + _1754_t7))};
    _1754_t11 = 0;
    _1754_t12 = 2;
    $bounds_check(_1754_t11, _1754_t12, "tests/integration/whitebox/assign-index-product2.orng:4:8:\n    (x[0], x[1]) = (x[1], x[0])\n      ^");
    *((int64_t*)&_1755_x + _1754_t11) = _1754_t4._0;
    _1754_t15 = 1;
    _1754_t16 = 2;
    $bounds_check(_1754_t15, _1754_t16, "tests/integration/whitebox/assign-index-product2.orng:4:14:\n    (x[0], x[1]) = (x[1], x[0])\n            ^");
    *((int64_t*)&_1755_x + _1754_t15) = _1754_t4._1;
    _1754_t17 = 0;
    _1754_t18 = 2;
    _1754_t19 = 1;
    _1754_t20 = 2;
    $bounds_check(_1754_t17, _1754_t18, "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    $bounds_check(_1754_t19, _1754_t20, "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    _1754_$retval = $div_int64_t(*((int64_t*)&_1755_x + _1754_t17), *((int64_t*)&_1755_x + _1754_t19), "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    return _1754_$retval;
}


int main(void) {
  printf("%ld",_1754_main());
  return 0;
}
