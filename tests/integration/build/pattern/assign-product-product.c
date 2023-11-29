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
int64_t _844_main(void);

/* Function definitions */
int64_t _844_main(void) {
    int64_t _844_t2;
    int64_t _844_t3;
    struct0 _844_t1;
    int64_t _844_t5;
    int64_t _844_t6;
    struct0 _844_t4;
    struct1 _844_t0;
    int64_t _845_x;
    int64_t _845_y;
    int64_t _845_a;
    int64_t _845_b;
    int64_t _844_t9;
    int64_t _844_t10;
    struct0 _844_t8;
    int64_t _844_t12;
    int64_t _844_t13;
    struct0 _844_t11;
    struct1 _844_t7;
    int64_t _844_t16;
    int64_t _844_t17;
    int64_t _844_$retval;
    _844_t2 = 0;
    _844_t3 = 0;
    _844_t1 = (struct0) {_844_t2, _844_t3};
    _844_t5 = 0;
    _844_t6 = 0;
    _844_t4 = (struct0) {_844_t5, _844_t6};
    _844_t0 = (struct1) {_844_t1, _844_t4};
    _845_x = _844_t0._0._0;
    _845_y = _844_t0._0._1;
    _845_a = _844_t0._1._0;
    _845_b = _844_t0._1._1;
    _844_t9 = 1;
    _844_t10 = 40;
    _844_t8 = (struct0) {_844_t9, _844_t10};
    _844_t12 = 2;
    _844_t13 = 2;
    _844_t11 = (struct0) {_844_t12, _844_t13};
    _844_t7 = (struct1) {_844_t8, _844_t11};
    _845_x = _844_t7._0._0;
    _845_y = _844_t7._0._1;
    _845_a = _844_t7._1._0;
    _845_b = _844_t7._1._1;
    _844_t16 = $add_int64_t(_845_x, _845_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _844_t17 = $add_int64_t(_845_a, _845_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _844_$retval = $mult_int64_t(_844_t16, _844_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _844_$retval;
}

int main(void) {
  printf("%ld",_844_main());
  return 0;
}
