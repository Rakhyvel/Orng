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
int64_t _1262_main(void);

/* Function definitions */
int64_t _1262_main(void){
    int64_t _1262_t2;
    int64_t _1262_t3;
    struct0 _1262_t1;
    int64_t _1262_t5;
    int64_t _1262_t6;
    struct0 _1262_t4;
    struct1 _1262_t0;
    int64_t _1263_x;
    int64_t _1263_y;
    int64_t _1263_a;
    int64_t _1263_b;
    int64_t _1262_t7;
    int64_t _1262_t8;
    int64_t _1262_$retval;
    _1262_t2 = 100;
    _1262_t3 = 20;
    _1262_t1 = (struct0) {_1262_t2, _1262_t3};
    _1262_t5 = 20;
    _1262_t6 = 2;
    _1262_t4 = (struct0) {_1262_t5, _1262_t6};
    _1262_t0 = (struct1) {_1262_t1, _1262_t4};
    _1263_x = _1262_t0._0._0;
    _1263_y = _1262_t0._0._1;
    _1263_a = _1262_t0._1._0;
    _1263_b = _1262_t0._1._1;
    _1262_t7 = $add_int64_t(_1263_x, _1263_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1262_t8 = $add_int64_t(_1262_t7, _1263_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1262_$retval = $add_int64_t(_1262_t8, _1263_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1262_$retval;
}

int main(void) {
  printf("%ld",_1262_main());
  return 0;
}
