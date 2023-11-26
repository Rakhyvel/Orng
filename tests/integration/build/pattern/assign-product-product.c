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
int64_t _19_main(void);

/* Function definitions */
int64_t _19_main(void) {
    int64_t _19_t2;
    int64_t _19_t3;
    struct0 _19_t1;
    int64_t _19_t5;
    int64_t _19_t6;
    struct0 _19_t4;
    struct1 _19_t0;
    int64_t _20_x;
    int64_t _20_y;
    int64_t _20_a;
    int64_t _20_b;
    int64_t _19_t9;
    int64_t _19_t10;
    struct0 _19_t8;
    int64_t _19_t12;
    int64_t _19_t13;
    struct0 _19_t11;
    struct1 _19_t7;
    int64_t _19_t16;
    int64_t _19_t17;
    int64_t _19_$retval;
    _19_t2 = 0;
    _19_t3 = 0;
    _19_t1 = (struct0) {_19_t2, _19_t3};
    _19_t5 = 0;
    _19_t6 = 0;
    _19_t4 = (struct0) {_19_t5, _19_t6};
    _19_t0 = (struct1) {_19_t1, _19_t4};
    _20_x = _19_t0._0._0;
    _20_y = _19_t0._0._1;
    _20_a = _19_t0._1._0;
    _20_b = _19_t0._1._1;
    _19_t9 = 1;
    _19_t10 = 40;
    _19_t8 = (struct0) {_19_t9, _19_t10};
    _19_t12 = 2;
    _19_t13 = 2;
    _19_t11 = (struct0) {_19_t12, _19_t13};
    _19_t7 = (struct1) {_19_t8, _19_t11};
    _20_x = _19_t7._0._0;
    _20_y = _19_t7._0._1;
    _20_a = _19_t7._1._0;
    _20_b = _19_t7._1._1;
    _19_t16 = $add_int64_t(_20_x, _20_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _19_t17 = $add_int64_t(_20_a, _20_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _19_$retval = $mult_int64_t(_19_t16, _19_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _19_$retval;
}

int main(void) {
  printf("%ld",_19_main());
  return 0;
}
