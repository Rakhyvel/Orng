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
int64_t _1069_main(void);

/* Function definitions */
int64_t _1069_main(void){
    int64_t _1069_t2;
    int64_t _1069_t3;
    struct0 _1069_t1;
    int64_t _1069_t5;
    int64_t _1069_t6;
    struct0 _1069_t4;
    struct1 _1069_t0;
    int64_t _1070_x;
    int64_t _1070_y;
    int64_t _1070_a;
    int64_t _1070_b;
    int64_t _1069_t9;
    int64_t _1069_t10;
    struct0 _1069_t8;
    int64_t _1069_t12;
    int64_t _1069_t13;
    struct0 _1069_t11;
    struct1 _1069_t7;
    int64_t _1069_t16;
    int64_t _1069_t17;
    int64_t _1069_$retval;
    _1069_t2 = 0;
    _1069_t3 = 0;
    _1069_t1 = (struct0) {_1069_t2, _1069_t3};
    _1069_t5 = 0;
    _1069_t6 = 0;
    _1069_t4 = (struct0) {_1069_t5, _1069_t6};
    _1069_t0 = (struct1) {_1069_t1, _1069_t4};
    _1070_x = _1069_t0._0._0;
    _1070_y = _1069_t0._0._1;
    _1070_a = _1069_t0._1._0;
    _1070_b = _1069_t0._1._1;
    _1069_t9 = 1;
    _1069_t10 = 40;
    _1069_t8 = (struct0) {_1069_t9, _1069_t10};
    _1069_t12 = 2;
    _1069_t13 = 2;
    _1069_t11 = (struct0) {_1069_t12, _1069_t13};
    _1069_t7 = (struct1) {_1069_t8, _1069_t11};
    _1070_x = _1069_t7._0._0;
    _1070_y = _1069_t7._0._1;
    _1070_a = _1069_t7._1._0;
    _1070_b = _1069_t7._1._1;
    _1069_t16 = $add_int64_t(_1070_x, _1070_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _1069_t17 = $add_int64_t(_1070_a, _1070_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _1069_$retval = $mult_int64_t(_1069_t16, _1069_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _1069_$retval;
}

int main(void) {
  printf("%ld",_1069_main());
  return 0;
}
