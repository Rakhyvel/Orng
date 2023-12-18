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
int64_t _1309_main(void);

/* Function definitions */
int64_t _1309_main(void){
    int64_t _1309_t2;
    int64_t _1309_t3;
    struct0 _1309_t1;
    int64_t _1309_t5;
    int64_t _1309_t6;
    struct0 _1309_t4;
    struct1 _1309_t0;
    int64_t _1310_x;
    int64_t _1310_y;
    int64_t _1310_a;
    int64_t _1310_b;
    int64_t _1309_t9;
    int64_t _1309_t10;
    struct0 _1309_t8;
    int64_t _1309_t12;
    int64_t _1309_t13;
    struct0 _1309_t11;
    struct1 _1309_t7;
    int64_t _1309_t16;
    int64_t _1309_t17;
    int64_t _1309_$retval;
    _1309_t2 = 0;
    _1309_t3 = 0;
    _1309_t1 = (struct0) {_1309_t2, _1309_t3};
    _1309_t5 = 0;
    _1309_t6 = 0;
    _1309_t4 = (struct0) {_1309_t5, _1309_t6};
    _1309_t0 = (struct1) {_1309_t1, _1309_t4};
    _1310_x = _1309_t0._0._0;
    _1310_y = _1309_t0._0._1;
    _1310_a = _1309_t0._1._0;
    _1310_b = _1309_t0._1._1;
    _1309_t9 = 1;
    _1309_t10 = 40;
    _1309_t8 = (struct0) {_1309_t9, _1309_t10};
    _1309_t12 = 2;
    _1309_t13 = 2;
    _1309_t11 = (struct0) {_1309_t12, _1309_t13};
    _1309_t7 = (struct1) {_1309_t8, _1309_t11};
    _1310_x = _1309_t7._0._0;
    _1310_y = _1309_t7._0._1;
    _1310_a = _1309_t7._1._0;
    _1310_b = _1309_t7._1._1;
    _1309_t16 = $add_int64_t(_1310_x, _1310_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1309_t17 = $add_int64_t(_1310_a, _1310_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1309_$retval = $mult_int64_t(_1309_t16, _1309_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1309_$retval;
}

int main(void) {
  printf("%ld",_1309_main());
  return 0;
}
