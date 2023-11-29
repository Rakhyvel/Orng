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
int64_t _1075_main(void);

/* Function definitions */
int64_t _1075_main(void) {
    int64_t _1075_t2;
    int64_t _1075_t3;
    struct0 _1075_t1;
    int64_t _1075_t5;
    int64_t _1075_t6;
    struct0 _1075_t4;
    struct1 _1075_t0;
    int64_t _1076_x;
    int64_t _1076_y;
    int64_t _1076_a;
    int64_t _1076_b;
    int64_t _1075_t7;
    int64_t _1075_t8;
    int64_t _1075_$retval;
    _1075_t2 = 100;
    _1075_t3 = 20;
    _1075_t1 = (struct0) {_1075_t2, _1075_t3};
    _1075_t5 = 20;
    _1075_t6 = 2;
    _1075_t4 = (struct0) {_1075_t5, _1075_t6};
    _1075_t0 = (struct1) {_1075_t1, _1075_t4};
    _1076_x = _1075_t0._0._0;
    _1076_y = _1075_t0._0._1;
    _1076_a = _1075_t0._1._0;
    _1076_b = _1075_t0._1._1;
    _1075_t7 = $add_int64_t(_1076_x, _1076_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1075_t8 = $add_int64_t(_1075_t7, _1076_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1075_$retval = $add_int64_t(_1075_t8, _1076_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1075_$retval;
}

int main(void) {
  printf("%ld",_1075_main());
  return 0;
}
