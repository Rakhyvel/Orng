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
int64_t _798_main(void);

/* Function definitions */
int64_t _798_main(void) {
    int64_t _798_t2;
    int64_t _798_t3;
    struct0 _798_t1;
    int64_t _798_t5;
    int64_t _798_t6;
    struct0 _798_t4;
    struct1 _798_t0;
    int64_t _799_x;
    int64_t _799_y;
    int64_t _799_a;
    int64_t _799_b;
    int64_t _798_t7;
    int64_t _798_t8;
    int64_t _798_$retval;
    _798_t2 = 100;
    _798_t3 = 20;
    _798_t1 = (struct0) {_798_t2, _798_t3};
    _798_t5 = 20;
    _798_t6 = 2;
    _798_t4 = (struct0) {_798_t5, _798_t6};
    _798_t0 = (struct1) {_798_t1, _798_t4};
    _799_x = _798_t0._0._0;
    _799_y = _798_t0._0._1;
    _799_a = _798_t0._1._0;
    _799_b = _798_t0._1._1;
    _798_t7 = $add_int64_t(_799_x, _799_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _798_t8 = $add_int64_t(_798_t7, _799_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _798_$retval = $add_int64_t(_798_t8, _799_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _798_$retval;
}

int main(void) {
  printf("%ld",_798_main());
  return 0;
}
