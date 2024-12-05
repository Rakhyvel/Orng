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
int64_t _1217_main(void);


/* Function definitions */
int64_t _1217_main(void){
    int64_t _1217_t2;
    int64_t _1217_t3;
    struct struct0 _1217_t1;
    int64_t _1217_t5;
    int64_t _1217_t6;
    struct struct0 _1217_t4;
    struct struct1 _1217_t0;
    int64_t _1218_x;
    int64_t _1218_y;
    int64_t _1218_a;
    int64_t _1218_b;
    int64_t _1217_t10;
    int64_t _1217_t11;
    struct struct0 _1217_t9;
    int64_t _1217_t13;
    int64_t _1217_t14;
    struct struct0 _1217_t12;
    struct struct1 _1217_t8;
    int64_t _1217_t17;
    int64_t _1217_t18;
    int64_t _1217_$retval;
    _1217_t2 = 0;
    _1217_t3 = 0;
    _1217_t1 = (struct struct0) {_1217_t2, _1217_t3};
    _1217_t5 = 0;
    _1217_t6 = 0;
    _1217_t4 = (struct struct0) {_1217_t5, _1217_t6};
    _1217_t0 = (struct struct1) {_1217_t1, _1217_t4};
    _1218_x = _1217_t0._0._0;
    _1218_y = _1217_t0._0._1;
    _1218_a = _1217_t0._1._0;
    _1218_b = _1217_t0._1._1;
    _1217_t10 = 1;
    _1217_t11 = 40;
    _1217_t9 = (struct struct0) {_1217_t10, _1217_t11};
    _1217_t13 = 2;
    _1217_t14 = 2;
    _1217_t12 = (struct struct0) {_1217_t13, _1217_t14};
    _1217_t8 = (struct struct1) {_1217_t9, _1217_t12};
    _1218_x = _1217_t8._0._0;
    _1218_y = _1217_t8._0._1;
    _1218_a = _1217_t8._1._0;
    _1218_b = _1217_t8._1._1;
    _1217_t17 = $add_int64_t(_1218_x, _1218_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1217_t18 = $add_int64_t(_1218_a, _1218_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1217_$retval = $mult_int64_t(_1217_t17, _1217_t18, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1217_$retval;
}


int main(void) {
  printf("%ld",_1217_main());
  return 0;
}
