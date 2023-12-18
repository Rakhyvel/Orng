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
int64_t _1303_main(void);

/* Function definitions */
int64_t _1303_main(void){
    int64_t _1303_t2;
    int64_t _1303_t3;
    struct0 _1303_t1;
    int64_t _1303_t5;
    int64_t _1303_t6;
    struct0 _1303_t4;
    struct1 _1303_t0;
    int64_t _1304_x;
    int64_t _1304_y;
    int64_t _1304_a;
    int64_t _1304_b;
    int64_t _1303_t9;
    int64_t _1303_t10;
    struct0 _1303_t8;
    int64_t _1303_t12;
    int64_t _1303_t13;
    struct0 _1303_t11;
    struct1 _1303_t7;
    int64_t _1303_t16;
    int64_t _1303_t17;
    int64_t _1303_$retval;
    _1303_t2 = 0;
    _1303_t3 = 0;
    _1303_t1 = (struct0) {_1303_t2, _1303_t3};
    _1303_t5 = 0;
    _1303_t6 = 0;
    _1303_t4 = (struct0) {_1303_t5, _1303_t6};
    _1303_t0 = (struct1) {_1303_t1, _1303_t4};
    _1304_x = _1303_t0._0._0;
    _1304_y = _1303_t0._0._1;
    _1304_a = _1303_t0._1._0;
    _1304_b = _1303_t0._1._1;
    _1303_t9 = 1;
    _1303_t10 = 40;
    _1303_t8 = (struct0) {_1303_t9, _1303_t10};
    _1303_t12 = 2;
    _1303_t13 = 2;
    _1303_t11 = (struct0) {_1303_t12, _1303_t13};
    _1303_t7 = (struct1) {_1303_t8, _1303_t11};
    _1304_x = _1303_t7._0._0;
    _1304_y = _1303_t7._0._1;
    _1304_a = _1303_t7._1._0;
    _1304_b = _1303_t7._1._1;
    _1303_t16 = $add_int64_t(_1304_x, _1304_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1303_t17 = $add_int64_t(_1304_a, _1304_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1303_$retval = $mult_int64_t(_1303_t16, _1303_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1303_$retval;
}

int main(void) {
  printf("%ld",_1303_main());
  return 0;
}
