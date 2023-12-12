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
int64_t _884_main(void);

/* Function definitions */
int64_t _884_main(void) {
    int64_t _884_t2;
    int64_t _884_t3;
    struct0 _884_t1;
    int64_t _884_t5;
    int64_t _884_t6;
    struct0 _884_t4;
    struct1 _884_t0;
    int64_t _885_x;
    int64_t _885_y;
    int64_t _885_a;
    int64_t _885_b;
    int64_t _884_t7;
    int64_t _884_t8;
    int64_t _884_$retval;
    _884_t2 = 100;
    _884_t3 = 20;
    _884_t1 = (struct0) {_884_t2, _884_t3};
    _884_t5 = 20;
    _884_t6 = 2;
    _884_t4 = (struct0) {_884_t5, _884_t6};
    _884_t0 = (struct1) {_884_t1, _884_t4};
    _885_x = _884_t0._0._0;
    _885_y = _884_t0._0._1;
    _885_a = _884_t0._1._0;
    _885_b = _884_t0._1._1;
    _884_t7 = $add_int64_t(_885_x, _885_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _884_t8 = $add_int64_t(_884_t7, _885_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _884_$retval = $add_int64_t(_884_t8, _885_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _884_$retval;
}

int main(void) {
  printf("%ld",_884_main());
  return 0;
}
