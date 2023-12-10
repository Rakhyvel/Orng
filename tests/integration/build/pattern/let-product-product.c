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
int64_t _857_main(void);

/* Function definitions */
int64_t _857_main(void) {
    int64_t _857_t2;
    int64_t _857_t3;
    struct0 _857_t1;
    int64_t _857_t5;
    int64_t _857_t6;
    struct0 _857_t4;
    struct1 _857_t0;
    int64_t _858_x;
    int64_t _858_y;
    int64_t _858_a;
    int64_t _858_b;
    int64_t _857_t7;
    int64_t _857_t8;
    int64_t _857_$retval;
    _857_t2 = 100;
    _857_t3 = 20;
    _857_t1 = (struct0) {_857_t2, _857_t3};
    _857_t5 = 20;
    _857_t6 = 2;
    _857_t4 = (struct0) {_857_t5, _857_t6};
    _857_t0 = (struct1) {_857_t1, _857_t4};
    _858_x = _857_t0._0._0;
    _858_y = _857_t0._0._1;
    _858_a = _857_t0._1._0;
    _858_b = _857_t0._1._1;
    _857_t7 = $add_int64_t(_858_x, _858_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _857_t8 = $add_int64_t(_857_t7, _858_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _857_$retval = $add_int64_t(_857_t8, _858_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _857_$retval;
}

int main(void) {
  printf("%ld",_857_main());
  return 0;
}
