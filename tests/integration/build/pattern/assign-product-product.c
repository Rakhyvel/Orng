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
int64_t _832_main(void);

/* Function definitions */
int64_t _832_main(void) {
    int64_t _832_t2;
    int64_t _832_t3;
    struct0 _832_t1;
    int64_t _832_t5;
    int64_t _832_t6;
    struct0 _832_t4;
    struct1 _832_t0;
    int64_t _833_x;
    int64_t _833_y;
    int64_t _833_a;
    int64_t _833_b;
    int64_t _832_t9;
    int64_t _832_t10;
    struct0 _832_t8;
    int64_t _832_t12;
    int64_t _832_t13;
    struct0 _832_t11;
    struct1 _832_t7;
    int64_t _832_t16;
    int64_t _832_t17;
    int64_t _832_$retval;
    _832_t2 = 0;
    _832_t3 = 0;
    _832_t1 = (struct0) {_832_t2, _832_t3};
    _832_t5 = 0;
    _832_t6 = 0;
    _832_t4 = (struct0) {_832_t5, _832_t6};
    _832_t0 = (struct1) {_832_t1, _832_t4};
    _833_x = _832_t0._0._0;
    _833_y = _832_t0._0._1;
    _833_a = _832_t0._1._0;
    _833_b = _832_t0._1._1;
    _832_t9 = 1;
    _832_t10 = 40;
    _832_t8 = (struct0) {_832_t9, _832_t10};
    _832_t12 = 2;
    _832_t13 = 2;
    _832_t11 = (struct0) {_832_t12, _832_t13};
    _832_t7 = (struct1) {_832_t8, _832_t11};
    _833_x = _832_t7._0._0;
    _833_y = _832_t7._0._1;
    _833_a = _832_t7._1._0;
    _833_b = _832_t7._1._1;
    _832_t16 = $add_int64_t(_833_x, _833_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _832_t17 = $add_int64_t(_833_a, _833_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _832_$retval = $mult_int64_t(_832_t16, _832_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _832_$retval;
}

int main(void) {
  printf("%ld",_832_main());
  return 0;
}
