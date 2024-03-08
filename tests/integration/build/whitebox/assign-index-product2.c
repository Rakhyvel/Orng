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
int64_t _1732_main(void);


/* Function definitions */
int64_t _1732_main(void){
    int64_t _1732_t1;
    int64_t _1732_t2;
    struct struct0 _1733_x;
    int64_t _1732_t4;
    int64_t _1732_t5;
    int64_t _1732_t6;
    int64_t _1732_t7;
    struct struct0 _1732_t3;
    int64_t _1732_t10;
    int64_t _1732_t11;
    int64_t _1732_t14;
    int64_t _1732_t15;
    int64_t _1732_t16;
    int64_t _1732_t17;
    int64_t _1732_t18;
    int64_t _1732_t19;
    int64_t _1732_$retval;
    _1732_t1 = 2;
    _1732_t2 = 324;
    _1733_x = (struct struct0) {_1732_t1, _1732_t2};
    _1732_t4 = 1;
    _1732_t5 = 2;
    _1732_t6 = 0;
    _1732_t7 = 2;
    $bounds_check(_1732_t4, _1732_t5, "tests/integration/whitebox/assign-index-product2.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    $bounds_check(_1732_t6, _1732_t7, "tests/integration/whitebox/assign-index-product2.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    _1732_t3 = (struct struct0) {(*((int64_t*)&_1733_x + _1732_t4)), (*((int64_t*)&_1733_x + _1732_t6))};
    _1732_t10 = 0;
    _1732_t11 = 2;
    $bounds_check(_1732_t10, _1732_t11, "tests/integration/whitebox/assign-index-product2.orng:4:8:\n    (x[0], x[1]) = (x[1], x[0])\n      ^");
    *((int64_t*)&_1733_x + _1732_t10) = _1732_t3._0;
    _1732_t14 = 1;
    _1732_t15 = 2;
    $bounds_check(_1732_t14, _1732_t15, "tests/integration/whitebox/assign-index-product2.orng:4:14:\n    (x[0], x[1]) = (x[1], x[0])\n            ^");
    *((int64_t*)&_1733_x + _1732_t14) = _1732_t3._1;
    _1732_t16 = 0;
    _1732_t17 = 2;
    _1732_t18 = 1;
    _1732_t19 = 2;
    $bounds_check(_1732_t16, _1732_t17, "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    $bounds_check(_1732_t18, _1732_t19, "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    _1732_$retval = $div_int64_t(*((int64_t*)&_1733_x + _1732_t16), *((int64_t*)&_1733_x + _1732_t18), "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    return _1732_$retval;
}


int main(void) {
  printf("%ld",_1732_main());
  return 0;
}
