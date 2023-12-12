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
int64_t _851_main(void);

/* Function definitions */
int64_t _851_main(void) {
    int64_t _851_t2;
    int64_t _851_t3;
    struct0 _851_t1;
    int64_t _851_t5;
    int64_t _851_t6;
    struct0 _851_t4;
    struct1 _851_t0;
    int64_t _852_x;
    int64_t _852_y;
    int64_t _852_a;
    int64_t _852_b;
    int64_t _851_t9;
    int64_t _851_t10;
    struct0 _851_t8;
    int64_t _851_t12;
    int64_t _851_t13;
    struct0 _851_t11;
    struct1 _851_t7;
    int64_t _851_t16;
    int64_t _851_t17;
    int64_t _851_$retval;
    _851_t2 = 0;
    _851_t3 = 0;
    _851_t1 = (struct0) {_851_t2, _851_t3};
    _851_t5 = 0;
    _851_t6 = 0;
    _851_t4 = (struct0) {_851_t5, _851_t6};
    _851_t0 = (struct1) {_851_t1, _851_t4};
    _852_x = _851_t0._0._0;
    _852_y = _851_t0._0._1;
    _852_a = _851_t0._1._0;
    _852_b = _851_t0._1._1;
    _851_t9 = 1;
    _851_t10 = 40;
    _851_t8 = (struct0) {_851_t9, _851_t10};
    _851_t12 = 2;
    _851_t13 = 2;
    _851_t11 = (struct0) {_851_t12, _851_t13};
    _851_t7 = (struct1) {_851_t8, _851_t11};
    _852_x = _851_t7._0._0;
    _852_y = _851_t7._0._1;
    _852_a = _851_t7._1._0;
    _852_b = _851_t7._1._1;
    _851_t16 = $add_int64_t(_852_x, _852_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _851_t17 = $add_int64_t(_852_a, _852_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _851_$retval = $mult_int64_t(_851_t16, _851_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _851_$retval;
}

int main(void) {
  printf("%ld",_851_main());
  return 0;
}
