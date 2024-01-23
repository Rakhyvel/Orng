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
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1149_main(void);


/* Function definitions */
int64_t _1149_main(void){
    int64_t _1149_t2;
    int64_t _1149_t3;
    struct struct0 _1149_t1;
    int64_t _1149_t5;
    int64_t _1149_t6;
    struct struct0 _1149_t4;
    struct struct1 _1149_t0;
    int64_t _1150_x;
    int64_t _1150_y;
    int64_t _1150_a;
    int64_t _1150_b;
    int64_t _1149_t9;
    int64_t _1149_t10;
    struct struct0 _1149_t8;
    int64_t _1149_t12;
    int64_t _1149_t13;
    struct struct0 _1149_t11;
    struct struct1 _1149_t7;
    int64_t _1149_t16;
    int64_t _1149_t17;
    int64_t _1149_$retval;
    _1149_t2 = 0;
    _1149_t3 = 0;
    _1149_t1 = (struct struct0) {_1149_t2, _1149_t3};
    _1149_t5 = 0;
    _1149_t6 = 0;
    _1149_t4 = (struct struct0) {_1149_t5, _1149_t6};
    _1149_t0 = (struct struct1) {_1149_t1, _1149_t4};
    _1150_x = _1149_t0._0._0;
    _1150_y = _1149_t0._0._1;
    _1150_a = _1149_t0._1._0;
    _1150_b = _1149_t0._1._1;
    _1149_t9 = 1;
    _1149_t10 = 40;
    _1149_t8 = (struct struct0) {_1149_t9, _1149_t10};
    _1149_t12 = 2;
    _1149_t13 = 2;
    _1149_t11 = (struct struct0) {_1149_t12, _1149_t13};
    _1149_t7 = (struct struct1) {_1149_t8, _1149_t11};
    _1150_x = _1149_t7._0._0;
    _1150_y = _1149_t7._0._1;
    _1150_a = _1149_t7._1._0;
    _1150_b = _1149_t7._1._1;
    _1149_t16 = $add_int64_t(_1150_x, _1150_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1149_t17 = $add_int64_t(_1150_a, _1150_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1149_$retval = $mult_int64_t(_1149_t16, _1149_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1149_$retval;
}


int main(void) {
  printf("%ld",_1149_main());
  return 0;
}
