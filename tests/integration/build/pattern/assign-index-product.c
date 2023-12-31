/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

struct struct1 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1117_main(void);

/* Function definitions */
int64_t _1117_main(void){
    int64_t _1117_t1;
    int64_t _1117_t2;
    int64_t _1117_t3;
    struct struct0 _1118_x;
    int64_t _1117_t5;
    int64_t _1117_t6;
    int64_t _1117_t7;
    int64_t _1117_t8;
    struct struct1 _1117_t4;
    int64_t _1117_t11;
    int64_t _1117_t12;
    int64_t _1117_t15;
    int64_t _1117_t16;
    int64_t _1117_t18;
    int64_t _1117_t19;
    int64_t _1117_t20;
    int64_t _1117_t21;
    uint8_t _1117_t22;
    int64_t _1117_$retval;
    _1117_t1 = 0;
    _1117_t2 = 1;
    _1117_t3 = 2;
    _1118_x = (struct struct0) {_1117_t1, _1117_t2, _1117_t3};
    _1117_t5 = 1;
    _1117_t6 = 3;
    _1117_t7 = 0;
    _1117_t8 = 3;
    $bounds_check(_1117_t5, _1117_t6, "tests/integration/pattern/assign-index-product.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    $bounds_check(_1117_t7, _1117_t8, "tests/integration/pattern/assign-index-product.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    _1117_t4 = (struct struct1) {(*((int64_t*)&_1118_x + _1117_t5)), (*((int64_t*)&_1118_x + _1117_t7))};
    _1117_t11 = 0;
    _1117_t12 = 3;
    $bounds_check(_1117_t11, _1117_t12, "tests/integration/pattern/assign-index-product.orng:4:8:\n    (x[0], x[1]) = (x[1], x[0])\n      ^");
    *((int64_t*)&_1118_x + _1117_t11) = _1117_t4._0;
    _1117_t15 = 1;
    _1117_t16 = 3;
    $bounds_check(_1117_t15, _1117_t16, "tests/integration/pattern/assign-index-product.orng:4:14:\n    (x[0], x[1]) = (x[1], x[0])\n            ^");
    *((int64_t*)&_1118_x + _1117_t15) = _1117_t4._1;
    _1117_t18 = 0;
    _1117_t19 = 3;
    _1117_t20 = 1;
    _1117_t21 = 3;
    $bounds_check(_1117_t18, _1117_t19, "tests/integration/pattern/assign-index-product.orng:5:14:\n    if x[0] > x[1] {\n            ^");
    $bounds_check(_1117_t20, _1117_t21, "tests/integration/pattern/assign-index-product.orng:5:14:\n    if x[0] > x[1] {\n            ^");
    _1117_t22 = *((int64_t*)&_1118_x + _1117_t18)>*((int64_t*)&_1118_x + _1117_t20);
    if (_1117_t22) {
        goto BB1325;
    } else {
        goto BB1329;
    }
BB1325:
    _1117_$retval = 162;
    return _1117_$retval;
BB1329:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1117_main());
  return 0;
}
