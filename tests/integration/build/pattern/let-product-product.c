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
int64_t _882_main(void);

/* Function definitions */
int64_t _882_main(void) {
    int64_t _882_t2;
    int64_t _882_t3;
    struct0 _882_t1;
    int64_t _882_t5;
    int64_t _882_t6;
    struct0 _882_t4;
    struct1 _882_t0;
    int64_t _883_x;
    int64_t _883_y;
    int64_t _883_a;
    int64_t _883_b;
    int64_t _882_t7;
    int64_t _882_t8;
    int64_t _882_$retval;
    _882_t2 = 100;
    _882_t3 = 20;
    _882_t1 = (struct0) {_882_t2, _882_t3};
    _882_t5 = 20;
    _882_t6 = 2;
    _882_t4 = (struct0) {_882_t5, _882_t6};
    _882_t0 = (struct1) {_882_t1, _882_t4};
    _883_x = _882_t0._0._0;
    _883_y = _882_t0._0._1;
    _883_a = _882_t0._1._0;
    _883_b = _882_t0._1._1;
    _882_t7 = $add_int64_t(_883_x, _883_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _882_t8 = $add_int64_t(_882_t7, _883_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _882_$retval = $add_int64_t(_882_t8, _883_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _882_$retval;
}

int main(void) {
  printf("%ld",_882_main());
  return 0;
}
