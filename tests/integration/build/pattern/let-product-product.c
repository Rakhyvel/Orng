/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1167_main(void);

/* Function definitions */
int64_t _1167_main(void){
    int64_t _1167_t2;
    int64_t _1167_t3;
    struct struct0 _1167_t1;
    int64_t _1167_t5;
    int64_t _1167_t6;
    struct struct0 _1167_t4;
    struct struct1 _1167_t0;
    int64_t _1168_x;
    int64_t _1168_y;
    int64_t _1168_a;
    int64_t _1168_b;
    int64_t _1167_t7;
    int64_t _1167_t8;
    int64_t _1167_$retval;
    _1167_t2 = 100;
    _1167_t3 = 20;
    _1167_t1 = (struct struct0) {_1167_t2, _1167_t3};
    _1167_t5 = 20;
    _1167_t6 = 2;
    _1167_t4 = (struct struct0) {_1167_t5, _1167_t6};
    _1167_t0 = (struct struct1) {_1167_t1, _1167_t4};
    _1168_x = _1167_t0._0._0;
    _1168_y = _1167_t0._0._1;
    _1168_a = _1167_t0._1._0;
    _1168_b = _1167_t0._1._1;
    _1167_t7 = $add_int64_t(_1168_x, _1168_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1167_t8 = $add_int64_t(_1167_t7, _1168_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1167_$retval = $add_int64_t(_1167_t8, _1168_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1167_$retval;
}

int main(void) {
  printf("%ld",_1167_main());
  return 0;
}
