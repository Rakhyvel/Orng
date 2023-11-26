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
int64_t _52_main(void);

/* Function definitions */
int64_t _52_main(void) {
    int64_t _52_t2;
    int64_t _52_t3;
    struct0 _52_t1;
    int64_t _52_t5;
    int64_t _52_t6;
    struct0 _52_t4;
    struct1 _52_t0;
    int64_t _53_x;
    int64_t _53_y;
    int64_t _53_a;
    int64_t _53_b;
    int64_t _52_t7;
    int64_t _52_t8;
    int64_t _52_$retval;
    _52_t2 = 100;
    _52_t3 = 20;
    _52_t1 = (struct0) {_52_t2, _52_t3};
    _52_t5 = 20;
    _52_t6 = 2;
    _52_t4 = (struct0) {_52_t5, _52_t6};
    _52_t0 = (struct1) {_52_t1, _52_t4};
    _53_x = _52_t0._0._0;
    _53_y = _52_t0._0._1;
    _53_a = _52_t0._1._0;
    _53_b = _52_t0._1._1;
    _52_t7 = $add_int64_t(_53_x, _53_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _52_t8 = $add_int64_t(_52_t7, _53_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _52_$retval = $add_int64_t(_52_t8, _53_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _52_$retval;
}

int main(void) {
  printf("%ld",_52_main());
  return 0;
}
