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
int64_t _1162_main(void);

/* Function definitions */
int64_t _1162_main(void){
    int64_t _1162_t2;
    int64_t _1162_t3;
    struct struct0 _1162_t1;
    int64_t _1162_t5;
    int64_t _1162_t6;
    struct struct0 _1162_t4;
    struct struct1 _1162_t0;
    int64_t _1163_x;
    int64_t _1163_y;
    int64_t _1163_a;
    int64_t _1163_b;
    int64_t _1162_t7;
    int64_t _1162_t8;
    int64_t _1162_$retval;
    _1162_t2 = 100;
    _1162_t3 = 20;
    _1162_t1 = (struct struct0) {_1162_t2, _1162_t3};
    _1162_t5 = 20;
    _1162_t6 = 2;
    _1162_t4 = (struct struct0) {_1162_t5, _1162_t6};
    _1162_t0 = (struct struct1) {_1162_t1, _1162_t4};
    _1163_x = _1162_t0._0._0;
    _1163_y = _1162_t0._0._1;
    _1163_a = _1162_t0._1._0;
    _1163_b = _1162_t0._1._1;
    _1162_t7 = $add_int64_t(_1163_x, _1163_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1162_t8 = $add_int64_t(_1162_t7, _1163_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1162_$retval = $add_int64_t(_1162_t8, _1163_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1162_$retval;
}

int main(void) {
  printf("%ld",_1162_main());
  return 0;
}
