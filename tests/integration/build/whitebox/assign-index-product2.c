/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1593_main(void);

/* Function definitions */
int64_t _1593_main(void){
    int64_t _1593_t1;
    int64_t _1593_t2;
    struct struct0 _1594_x;
    int64_t _1593_t4;
    int64_t _1593_t5;
    int64_t _1593_t6;
    int64_t _1593_t7;
    struct struct0 _1593_t3;
    int64_t _1593_t10;
    int64_t _1593_t11;
    int64_t _1593_t14;
    int64_t _1593_t15;
    int64_t _1593_t16;
    int64_t _1593_t17;
    int64_t _1593_t18;
    int64_t _1593_t19;
    int64_t _1593_$retval;
    _1593_t1 = 2;
    _1593_t2 = 324;
    _1594_x = (struct struct0) {_1593_t1, _1593_t2};
    _1593_t4 = 1;
    _1593_t5 = 2;
    _1593_t6 = 0;
    _1593_t7 = 2;
    $bounds_check(_1593_t4, _1593_t5, "tests/integration/whitebox/assign-index-product2.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    $bounds_check(_1593_t6, _1593_t7, "tests/integration/whitebox/assign-index-product2.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    _1593_t3 = (struct struct0) {(*((int64_t*)&_1594_x + _1593_t4)), (*((int64_t*)&_1594_x + _1593_t6))};
    _1593_t10 = 0;
    _1593_t11 = 2;
    $bounds_check(_1593_t10, _1593_t11, "tests/integration/whitebox/assign-index-product2.orng:4:8:\n    (x[0], x[1]) = (x[1], x[0])\n      ^");
    *((int64_t*)&_1594_x + _1593_t10) = _1593_t3._0;
    _1593_t14 = 1;
    _1593_t15 = 2;
    $bounds_check(_1593_t14, _1593_t15, "tests/integration/whitebox/assign-index-product2.orng:4:14:\n    (x[0], x[1]) = (x[1], x[0])\n            ^");
    *((int64_t*)&_1594_x + _1593_t14) = _1593_t3._1;
    _1593_t16 = 0;
    _1593_t17 = 2;
    _1593_t18 = 1;
    _1593_t19 = 2;
    $bounds_check(_1593_t16, _1593_t17, "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    $bounds_check(_1593_t18, _1593_t19, "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    _1593_$retval = $div_int64_t(*((int64_t*)&_1594_x + _1593_t16), *((int64_t*)&_1594_x + _1593_t18), "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    return _1593_$retval;
}

int main(void) {
  printf("%ld",_1593_main());
  return 0;
}
