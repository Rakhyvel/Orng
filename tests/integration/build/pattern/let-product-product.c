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
int64_t _1077_main(void);

/* Function definitions */
int64_t _1077_main(void) {
    int64_t _1077_t2;
    int64_t _1077_t3;
    struct0 _1077_t1;
    int64_t _1077_t5;
    int64_t _1077_t6;
    struct0 _1077_t4;
    struct1 _1077_t0;
    int64_t _1078_x;
    int64_t _1078_y;
    int64_t _1078_a;
    int64_t _1078_b;
    int64_t _1077_t7;
    int64_t _1077_t8;
    int64_t _1077_$retval;
    _1077_t2 = 100;
    _1077_t3 = 20;
    _1077_t1 = (struct0) {_1077_t2, _1077_t3};
    _1077_t5 = 20;
    _1077_t6 = 2;
    _1077_t4 = (struct0) {_1077_t5, _1077_t6};
    _1077_t0 = (struct1) {_1077_t1, _1077_t4};
    _1078_x = _1077_t0._0._0;
    _1078_y = _1077_t0._0._1;
    _1078_a = _1077_t0._1._0;
    _1078_b = _1077_t0._1._1;
    _1077_t7 = $add_int64_t(_1078_x, _1078_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1077_t8 = $add_int64_t(_1077_t7, _1078_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1077_$retval = $add_int64_t(_1077_t8, _1078_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1077_$retval;
}

int main(void) {
  printf("%ld",_1077_main());
  return 0;
}
