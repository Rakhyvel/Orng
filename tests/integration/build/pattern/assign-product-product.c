/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1129_main(void);

/* Function definitions */
int64_t _1129_main(void){
    int64_t _1129_t2;
    int64_t _1129_t3;
    struct struct0 _1129_t1;
    int64_t _1129_t5;
    int64_t _1129_t6;
    struct struct0 _1129_t4;
    struct struct1 _1129_t0;
    int64_t _1130_x;
    int64_t _1130_y;
    int64_t _1130_a;
    int64_t _1130_b;
    int64_t _1129_t9;
    int64_t _1129_t10;
    struct struct0 _1129_t8;
    int64_t _1129_t12;
    int64_t _1129_t13;
    struct struct0 _1129_t11;
    struct struct1 _1129_t7;
    int64_t _1129_t16;
    int64_t _1129_t17;
    int64_t _1129_$retval;
    _1129_t2 = 0;
    _1129_t3 = 0;
    _1129_t1 = (struct struct0) {_1129_t2, _1129_t3};
    _1129_t5 = 0;
    _1129_t6 = 0;
    _1129_t4 = (struct struct0) {_1129_t5, _1129_t6};
    _1129_t0 = (struct struct1) {_1129_t1, _1129_t4};
    _1130_x = _1129_t0._0._0;
    _1130_y = _1129_t0._0._1;
    _1130_a = _1129_t0._1._0;
    _1130_b = _1129_t0._1._1;
    _1129_t9 = 1;
    _1129_t10 = 40;
    _1129_t8 = (struct struct0) {_1129_t9, _1129_t10};
    _1129_t12 = 2;
    _1129_t13 = 2;
    _1129_t11 = (struct struct0) {_1129_t12, _1129_t13};
    _1129_t7 = (struct struct1) {_1129_t8, _1129_t11};
    _1130_x = _1129_t7._0._0;
    _1130_y = _1129_t7._0._1;
    _1130_a = _1129_t7._1._0;
    _1130_b = _1129_t7._1._1;
    _1129_t16 = $add_int64_t(_1130_x, _1130_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1129_t17 = $add_int64_t(_1130_a, _1130_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1129_$retval = $mult_int64_t(_1129_t16, _1129_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1129_$retval;
}

int main(void) {
  printf("%ld",_1129_main());
  return 0;
}
