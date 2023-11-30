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
int64_t _1029_main(void);

/* Function definitions */
int64_t _1029_main(void) {
    int64_t _1029_t2;
    int64_t _1029_t3;
    struct0 _1029_t1;
    int64_t _1029_t5;
    int64_t _1029_t6;
    struct0 _1029_t4;
    struct1 _1029_t0;
    int64_t _1030_x;
    int64_t _1030_y;
    int64_t _1030_a;
    int64_t _1030_b;
    int64_t _1029_t9;
    int64_t _1029_t10;
    struct0 _1029_t8;
    int64_t _1029_t12;
    int64_t _1029_t13;
    struct0 _1029_t11;
    struct1 _1029_t7;
    int64_t _1029_t16;
    int64_t _1029_t17;
    int64_t _1029_$retval;
    _1029_t2 = 0;
    _1029_t3 = 0;
    _1029_t1 = (struct0) {_1029_t2, _1029_t3};
    _1029_t5 = 0;
    _1029_t6 = 0;
    _1029_t4 = (struct0) {_1029_t5, _1029_t6};
    _1029_t0 = (struct1) {_1029_t1, _1029_t4};
    _1030_x = _1029_t0._0._0;
    _1030_y = _1029_t0._0._1;
    _1030_a = _1029_t0._1._0;
    _1030_b = _1029_t0._1._1;
    _1029_t9 = 1;
    _1029_t10 = 40;
    _1029_t8 = (struct0) {_1029_t9, _1029_t10};
    _1029_t12 = 2;
    _1029_t13 = 2;
    _1029_t11 = (struct0) {_1029_t12, _1029_t13};
    _1029_t7 = (struct1) {_1029_t8, _1029_t11};
    _1030_x = _1029_t7._0._0;
    _1030_y = _1029_t7._0._1;
    _1030_a = _1029_t7._1._0;
    _1030_b = _1029_t7._1._1;
    _1029_t16 = $add_int64_t(_1030_x, _1030_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1029_t17 = $add_int64_t(_1030_a, _1030_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1029_$retval = $mult_int64_t(_1029_t16, _1029_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1029_$retval;
}

int main(void) {
  printf("%ld",_1029_main());
  return 0;
}
