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
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1134_main(void);

/* Function definitions */
int64_t _1134_main(void){
    int64_t _1134_t2;
    int64_t _1134_t3;
    struct struct0 _1134_t1;
    int64_t _1134_t5;
    int64_t _1134_t6;
    struct struct0 _1134_t4;
    struct struct1 _1134_t0;
    int64_t _1135_x;
    int64_t _1135_y;
    int64_t _1135_a;
    int64_t _1135_b;
    int64_t _1134_t9;
    int64_t _1134_t10;
    struct struct0 _1134_t8;
    int64_t _1134_t12;
    int64_t _1134_t13;
    struct struct0 _1134_t11;
    struct struct1 _1134_t7;
    int64_t _1134_t16;
    int64_t _1134_t17;
    int64_t _1134_$retval;
    _1134_t2 = 0;
    _1134_t3 = 0;
    _1134_t1 = (struct struct0) {_1134_t2, _1134_t3};
    _1134_t5 = 0;
    _1134_t6 = 0;
    _1134_t4 = (struct struct0) {_1134_t5, _1134_t6};
    _1134_t0 = (struct struct1) {_1134_t1, _1134_t4};
    _1135_x = _1134_t0._0._0;
    _1135_y = _1134_t0._0._1;
    _1135_a = _1134_t0._1._0;
    _1135_b = _1134_t0._1._1;
    _1134_t9 = 1;
    _1134_t10 = 40;
    _1134_t8 = (struct struct0) {_1134_t9, _1134_t10};
    _1134_t12 = 2;
    _1134_t13 = 2;
    _1134_t11 = (struct struct0) {_1134_t12, _1134_t13};
    _1134_t7 = (struct struct1) {_1134_t8, _1134_t11};
    _1135_x = _1134_t7._0._0;
    _1135_y = _1134_t7._0._1;
    _1135_a = _1134_t7._1._0;
    _1135_b = _1134_t7._1._1;
    _1134_t16 = $add_int64_t(_1135_x, _1135_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1134_t17 = $add_int64_t(_1135_a, _1135_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1134_$retval = $mult_int64_t(_1134_t16, _1134_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1134_$retval;
}

int main(void) {
  printf("%ld",_1134_main());
  return 0;
}
