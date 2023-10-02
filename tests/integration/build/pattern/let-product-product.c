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
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    struct0 _1_t1;
    struct0 _1_t4;
    struct1 _1_t0;
    int64_t _2_x;
    int64_t _2_y;
    int64_t _2_a;
    int64_t _2_b;
    int64_t _1_$retval;
    _1_t1 = (struct0) {100, 20};
    _1_t4 = (struct0) {20, 2};
    _1_t0 = (struct1) {_1_t1, _1_t4};
    _2_x = _1_t0._0._0;
    _2_y = _1_t0._0._1;
    _2_a = _1_t0._1._0;
    _2_b = _1_t0._1._1;
    _1_$retval = $add_int64_t($add_int64_t($add_int64_t(_2_x, _2_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^"), _2_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^"), _2_b, "tests/integration/pattern/let-product-product.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
