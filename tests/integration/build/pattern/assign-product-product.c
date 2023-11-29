/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _1027_main(void);

/* Function definitions */
int64_t _1027_main(void) {
    int64_t _1027_t2;
    int64_t _1027_t3;
    struct0 _1027_t1;
    int64_t _1027_t5;
    int64_t _1027_t6;
    struct0 _1027_t4;
    struct1 _1027_t0;
    int64_t _1028_x;
    int64_t _1028_y;
    int64_t _1028_a;
    int64_t _1028_b;
    int64_t _1027_t9;
    int64_t _1027_t10;
    struct0 _1027_t8;
    int64_t _1027_t12;
    int64_t _1027_t13;
    struct0 _1027_t11;
    struct1 _1027_t7;
    int64_t _1027_t16;
    int64_t _1027_t17;
    int64_t _1027_$retval;
    _1027_t2 = 0;
    _1027_t3 = 0;
    _1027_t1 = (struct0) {_1027_t2, _1027_t3};
    _1027_t5 = 0;
    _1027_t6 = 0;
    _1027_t4 = (struct0) {_1027_t5, _1027_t6};
    _1027_t0 = (struct1) {_1027_t1, _1027_t4};
    _1028_x = _1027_t0._0._0;
    _1028_y = _1027_t0._0._1;
    _1028_a = _1027_t0._1._0;
    _1028_b = _1027_t0._1._1;
    _1027_t9 = 1;
    _1027_t10 = 40;
    _1027_t8 = (struct0) {_1027_t9, _1027_t10};
    _1027_t12 = 2;
    _1027_t13 = 2;
    _1027_t11 = (struct0) {_1027_t12, _1027_t13};
    _1027_t7 = (struct1) {_1027_t8, _1027_t11};
    _1028_x = _1027_t7._0._0;
    _1028_y = _1027_t7._0._1;
    _1028_a = _1027_t7._1._0;
    _1028_b = _1027_t7._1._1;
    _1027_t16 = $add_int64_t(_1028_x, _1028_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1027_t17 = $add_int64_t(_1028_a, _1028_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1027_$retval = $mult_int64_t(_1027_t16, _1027_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1027_$retval;
}

int main(void) {
  printf("%ld",_1027_main());
  return 0;
}
