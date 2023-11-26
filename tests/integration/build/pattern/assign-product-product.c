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
int64_t _734_main(void);

/* Function definitions */
int64_t _734_main(void) {
    int64_t _734_t2;
    int64_t _734_t3;
    struct0 _734_t1;
    int64_t _734_t5;
    int64_t _734_t6;
    struct0 _734_t4;
    struct1 _734_t0;
    int64_t _735_x;
    int64_t _735_y;
    int64_t _735_a;
    int64_t _735_b;
    int64_t _734_t9;
    int64_t _734_t10;
    struct0 _734_t8;
    int64_t _734_t12;
    int64_t _734_t13;
    struct0 _734_t11;
    struct1 _734_t7;
    int64_t _734_t16;
    int64_t _734_t17;
    int64_t _734_$retval;
    _734_t2 = 0;
    _734_t3 = 0;
    _734_t1 = (struct0) {_734_t2, _734_t3};
    _734_t5 = 0;
    _734_t6 = 0;
    _734_t4 = (struct0) {_734_t5, _734_t6};
    _734_t0 = (struct1) {_734_t1, _734_t4};
    _735_x = _734_t0._0._0;
    _735_y = _734_t0._0._1;
    _735_a = _734_t0._1._0;
    _735_b = _734_t0._1._1;
    _734_t9 = 1;
    _734_t10 = 40;
    _734_t8 = (struct0) {_734_t9, _734_t10};
    _734_t12 = 2;
    _734_t13 = 2;
    _734_t11 = (struct0) {_734_t12, _734_t13};
    _734_t7 = (struct1) {_734_t8, _734_t11};
    _735_x = _734_t7._0._0;
    _735_y = _734_t7._0._1;
    _735_a = _734_t7._1._0;
    _735_b = _734_t7._1._1;
    _734_t16 = $add_int64_t(_735_x, _735_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _734_t17 = $add_int64_t(_735_a, _735_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _734_$retval = $mult_int64_t(_734_t16, _734_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _734_$retval;
}

int main(void) {
  printf("%ld",_734_main());
  return 0;
}
