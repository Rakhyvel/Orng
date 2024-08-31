/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
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
int64_t _1150_main(void);


/* Function definitions */
int64_t _1150_main(void){
    int64_t _1150_t1;
    int64_t _1150_t2;
    int64_t _1150_t3;
    struct struct0 _1151_x;
    int64_t _1150_t6;
    int64_t _1150_t7;
    int64_t _1150_t8;
    int64_t _1150_t9;
    struct struct1 _1150_t5;
    int64_t _1150_t12;
    int64_t _1150_t13;
    int64_t _1150_t16;
    int64_t _1150_t17;
    int64_t _1150_t19;
    int64_t _1150_t20;
    int64_t _1150_t21;
    int64_t _1150_t22;
    uint8_t _1150_t23;
    int64_t _1150_$retval;
    _1150_t1 = 0;
    _1150_t2 = 1;
    _1150_t3 = 2;
    _1151_x = (struct struct0) {_1150_t1, _1150_t2, _1150_t3};
    _1150_t6 = 1;
    _1150_t7 = 3;
    _1150_t8 = 0;
    _1150_t9 = 3;
    $bounds_check(_1150_t6, _1150_t7, "tests/integration/pattern/assign-index-product.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    $bounds_check(_1150_t8, _1150_t9, "tests/integration/pattern/assign-index-product.orng:4:26:\n    (x[0], x[1]) = (x[1], x[0])\n                        ^");
    _1150_t5 = (struct struct1) {(*((int64_t*)&_1151_x + _1150_t6)), (*((int64_t*)&_1151_x + _1150_t8))};
    _1150_t12 = 0;
    _1150_t13 = 3;
    $bounds_check(_1150_t12, _1150_t13, "tests/integration/pattern/assign-index-product.orng:4:8:\n    (x[0], x[1]) = (x[1], x[0])\n      ^");
    *((int64_t*)&_1151_x + _1150_t12) = _1150_t5._0;
    _1150_t16 = 1;
    _1150_t17 = 3;
    $bounds_check(_1150_t16, _1150_t17, "tests/integration/pattern/assign-index-product.orng:4:14:\n    (x[0], x[1]) = (x[1], x[0])\n            ^");
    *((int64_t*)&_1151_x + _1150_t16) = _1150_t5._1;
    _1150_t19 = 0;
    _1150_t20 = 3;
    _1150_t21 = 1;
    _1150_t22 = 3;
    $bounds_check(_1150_t19, _1150_t20, "tests/integration/pattern/assign-index-product.orng:5:14:\n    if x[0] > x[1] {\n            ^");
    $bounds_check(_1150_t21, _1150_t22, "tests/integration/pattern/assign-index-product.orng:5:14:\n    if x[0] > x[1] {\n            ^");
    _1150_t23 = *((int64_t*)&_1151_x + _1150_t19)>*((int64_t*)&_1151_x + _1150_t21);
    if (_1150_t23) {
        goto BB1310;
    } else {
        goto BB1314;
    }
BB1310:
    _1150_$retval = 162;
    return _1150_$retval;
BB1314:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1150_main());
  return 0;
}
