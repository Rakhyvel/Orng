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
int64_t _824_main(void);

/* Function definitions */
int64_t _824_main(void) {
    int64_t _824_t2;
    int64_t _824_t3;
    struct0 _824_t1;
    int64_t _824_t5;
    int64_t _824_t6;
    struct0 _824_t4;
    struct1 _824_t0;
    int64_t _825_x;
    int64_t _825_y;
    int64_t _825_a;
    int64_t _825_b;
    int64_t _824_t9;
    int64_t _824_t10;
    struct0 _824_t8;
    int64_t _824_t12;
    int64_t _824_t13;
    struct0 _824_t11;
    struct1 _824_t7;
    int64_t _824_t16;
    int64_t _824_t17;
    int64_t _824_$retval;
    _824_t2 = 0;
    _824_t3 = 0;
    _824_t1 = (struct0) {_824_t2, _824_t3};
    _824_t5 = 0;
    _824_t6 = 0;
    _824_t4 = (struct0) {_824_t5, _824_t6};
    _824_t0 = (struct1) {_824_t1, _824_t4};
    _825_x = _824_t0._0._0;
    _825_y = _824_t0._0._1;
    _825_a = _824_t0._1._0;
    _825_b = _824_t0._1._1;
    _824_t9 = 1;
    _824_t10 = 40;
    _824_t8 = (struct0) {_824_t9, _824_t10};
    _824_t12 = 2;
    _824_t13 = 2;
    _824_t11 = (struct0) {_824_t12, _824_t13};
    _824_t7 = (struct1) {_824_t8, _824_t11};
    _825_x = _824_t7._0._0;
    _825_y = _824_t7._0._1;
    _825_a = _824_t7._1._0;
    _825_b = _824_t7._1._1;
    _824_t16 = $add_int64_t(_825_x, _825_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _824_t17 = $add_int64_t(_825_a, _825_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _824_$retval = $mult_int64_t(_824_t16, _824_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _824_$retval;
}

int main(void) {
  printf("%ld",_824_main());
  return 0;
}
