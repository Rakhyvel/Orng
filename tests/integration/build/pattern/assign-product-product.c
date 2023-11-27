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
int64_t _765_main(void);

/* Function definitions */
int64_t _765_main(void) {
    int64_t _765_t2;
    int64_t _765_t3;
    struct0 _765_t1;
    int64_t _765_t5;
    int64_t _765_t6;
    struct0 _765_t4;
    struct1 _765_t0;
    int64_t _766_x;
    int64_t _766_y;
    int64_t _766_a;
    int64_t _766_b;
    int64_t _765_t9;
    int64_t _765_t10;
    struct0 _765_t8;
    int64_t _765_t12;
    int64_t _765_t13;
    struct0 _765_t11;
    struct1 _765_t7;
    int64_t _765_t16;
    int64_t _765_t17;
    int64_t _765_$retval;
    _765_t2 = 0;
    _765_t3 = 0;
    _765_t1 = (struct0) {_765_t2, _765_t3};
    _765_t5 = 0;
    _765_t6 = 0;
    _765_t4 = (struct0) {_765_t5, _765_t6};
    _765_t0 = (struct1) {_765_t1, _765_t4};
    _766_x = _765_t0._0._0;
    _766_y = _765_t0._0._1;
    _766_a = _765_t0._1._0;
    _766_b = _765_t0._1._1;
    _765_t9 = 1;
    _765_t10 = 40;
    _765_t8 = (struct0) {_765_t9, _765_t10};
    _765_t12 = 2;
    _765_t13 = 2;
    _765_t11 = (struct0) {_765_t12, _765_t13};
    _765_t7 = (struct1) {_765_t8, _765_t11};
    _766_x = _765_t7._0._0;
    _766_y = _765_t7._0._1;
    _766_a = _765_t7._1._0;
    _766_b = _765_t7._1._1;
    _765_t16 = $add_int64_t(_766_x, _766_y, "tests/integration/pattern/assign-product-product.orng:5:9:\n    (x + y) * (a + b)\n       ^");
    _765_t17 = $add_int64_t(_766_a, _766_b, "tests/integration/pattern/assign-product-product.orng:5:19:\n    (x + y) * (a + b)\n                 ^");
    _765_$retval = $mult_int64_t(_765_t16, _765_t17, "tests/integration/pattern/assign-product-product.orng:5:14:\n    (x + y) * (a + b)\n            ^");
    return _765_$retval;
}

int main(void) {
  printf("%ld",_765_main());
  return 0;
}
