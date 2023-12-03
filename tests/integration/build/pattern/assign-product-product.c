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
int64_t _800_main(void);

/* Function definitions */
int64_t _800_main(void) {
    int64_t _800_t2;
    int64_t _800_t3;
    struct0 _800_t1;
    int64_t _800_t5;
    int64_t _800_t6;
    struct0 _800_t4;
    struct1 _800_t0;
    int64_t _801_x;
    int64_t _801_y;
    int64_t _801_a;
    int64_t _801_b;
    int64_t _800_t9;
    int64_t _800_t10;
    struct0 _800_t8;
    int64_t _800_t12;
    int64_t _800_t13;
    struct0 _800_t11;
    struct1 _800_t7;
    int64_t _800_t16;
    int64_t _800_t17;
    int64_t _800_$retval;
    _800_t2 = 0;
    _800_t3 = 0;
    _800_t1 = (struct0) {_800_t2, _800_t3};
    _800_t5 = 0;
    _800_t6 = 0;
    _800_t4 = (struct0) {_800_t5, _800_t6};
    _800_t0 = (struct1) {_800_t1, _800_t4};
    _801_x = _800_t0._0._0;
    _801_y = _800_t0._0._1;
    _801_a = _800_t0._1._0;
    _801_b = _800_t0._1._1;
    _800_t9 = 1;
    _800_t10 = 40;
    _800_t8 = (struct0) {_800_t9, _800_t10};
    _800_t12 = 2;
    _800_t13 = 2;
    _800_t11 = (struct0) {_800_t12, _800_t13};
    _800_t7 = (struct1) {_800_t8, _800_t11};
    _801_x = _800_t7._0._0;
    _801_y = _800_t7._0._1;
    _801_a = _800_t7._1._0;
    _801_b = _800_t7._1._1;
    _800_t16 = $add_int64_t(_801_x, _801_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _800_t17 = $add_int64_t(_801_a, _801_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _800_$retval = $mult_int64_t(_800_t16, _800_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _800_$retval;
}

int main(void) {
  printf("%ld",_800_main());
  return 0;
}
