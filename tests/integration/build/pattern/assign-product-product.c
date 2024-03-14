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
int64_t _1179_main(void);


/* Function definitions */
int64_t _1179_main(void){
    int64_t _1179_t2;
    int64_t _1179_t3;
    struct struct0 _1179_t1;
    int64_t _1179_t5;
    int64_t _1179_t6;
    struct struct0 _1179_t4;
    struct struct1 _1179_t0;
    int64_t _1180_x;
    int64_t _1180_y;
    int64_t _1180_a;
    int64_t _1180_b;
    int64_t _1179_t10;
    int64_t _1179_t11;
    struct struct0 _1179_t9;
    int64_t _1179_t13;
    int64_t _1179_t14;
    struct struct0 _1179_t12;
    struct struct1 _1179_t8;
    int64_t _1179_t17;
    int64_t _1179_t18;
    int64_t _1179_$retval;
    _1179_t2 = 0;
    _1179_t3 = 0;
    _1179_t1 = (struct struct0) {_1179_t2, _1179_t3};
    _1179_t5 = 0;
    _1179_t6 = 0;
    _1179_t4 = (struct struct0) {_1179_t5, _1179_t6};
    _1179_t0 = (struct struct1) {_1179_t1, _1179_t4};
    _1180_x = _1179_t0._0._0;
    _1180_y = _1179_t0._0._1;
    _1180_a = _1179_t0._1._0;
    _1180_b = _1179_t0._1._1;
    _1179_t10 = 1;
    _1179_t11 = 40;
    _1179_t9 = (struct struct0) {_1179_t10, _1179_t11};
    _1179_t13 = 2;
    _1179_t14 = 2;
    _1179_t12 = (struct struct0) {_1179_t13, _1179_t14};
    _1179_t8 = (struct struct1) {_1179_t9, _1179_t12};
    _1180_x = _1179_t8._0._0;
    _1180_y = _1179_t8._0._1;
    _1180_a = _1179_t8._1._0;
    _1180_b = _1179_t8._1._1;
    _1179_t17 = $add_int64_t(_1180_x, _1180_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1179_t18 = $add_int64_t(_1180_a, _1180_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1179_$retval = $mult_int64_t(_1179_t17, _1179_t18, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1179_$retval;
}


int main(void) {
  printf("%ld",_1179_main());
  return 0;
}
