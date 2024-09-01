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
int64_t _1198_main(void);


/* Function definitions */
int64_t _1198_main(void){
    int64_t _1198_t2;
    int64_t _1198_t3;
    struct struct0 _1198_t1;
    int64_t _1198_t5;
    int64_t _1198_t6;
    struct struct0 _1198_t4;
    struct struct1 _1198_t0;
    int64_t _1199_x;
    int64_t _1199_y;
    int64_t _1199_a;
    int64_t _1199_b;
    int64_t _1198_t10;
    int64_t _1198_t11;
    struct struct0 _1198_t9;
    int64_t _1198_t13;
    int64_t _1198_t14;
    struct struct0 _1198_t12;
    struct struct1 _1198_t8;
    int64_t _1198_t17;
    int64_t _1198_t18;
    int64_t _1198_$retval;
    _1198_t2 = 0;
    _1198_t3 = 0;
    _1198_t1 = (struct struct0) {_1198_t2, _1198_t3};
    _1198_t5 = 0;
    _1198_t6 = 0;
    _1198_t4 = (struct struct0) {_1198_t5, _1198_t6};
    _1198_t0 = (struct struct1) {_1198_t1, _1198_t4};
    _1199_x = _1198_t0._0._0;
    _1199_y = _1198_t0._0._1;
    _1199_a = _1198_t0._1._0;
    _1199_b = _1198_t0._1._1;
    _1198_t10 = 1;
    _1198_t11 = 40;
    _1198_t9 = (struct struct0) {_1198_t10, _1198_t11};
    _1198_t13 = 2;
    _1198_t14 = 2;
    _1198_t12 = (struct struct0) {_1198_t13, _1198_t14};
    _1198_t8 = (struct struct1) {_1198_t9, _1198_t12};
    _1199_x = _1198_t8._0._0;
    _1199_y = _1198_t8._0._1;
    _1199_a = _1198_t8._1._0;
    _1199_b = _1198_t8._1._1;
    _1198_t17 = $add_int64_t(_1199_x, _1199_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1198_t18 = $add_int64_t(_1199_a, _1199_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1198_$retval = $mult_int64_t(_1198_t17, _1198_t18, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1198_$retval;
}


int main(void) {
  printf("%ld",_1198_main());
  return 0;
}
