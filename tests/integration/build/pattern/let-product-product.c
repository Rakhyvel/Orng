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
int64_t _767_main(void);

/* Function definitions */
int64_t _767_main(void) {
    int64_t _767_t2;
    int64_t _767_t3;
    struct0 _767_t1;
    int64_t _767_t5;
    int64_t _767_t6;
    struct0 _767_t4;
    struct1 _767_t0;
    int64_t _768_x;
    int64_t _768_y;
    int64_t _768_a;
    int64_t _768_b;
    int64_t _767_t7;
    int64_t _767_t8;
    int64_t _767_$retval;
    _767_t2 = 100;
    _767_t3 = 20;
    _767_t1 = (struct0) {_767_t2, _767_t3};
    _767_t5 = 20;
    _767_t6 = 2;
    _767_t4 = (struct0) {_767_t5, _767_t6};
    _767_t0 = (struct1) {_767_t1, _767_t4};
    _768_x = _767_t0._0._0;
    _768_y = _767_t0._0._1;
    _768_a = _767_t0._1._0;
    _768_b = _767_t0._1._1;
    _767_t7 = $add_int64_t(_768_x, _768_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _767_t8 = $add_int64_t(_767_t7, _768_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _767_$retval = $add_int64_t(_767_t8, _768_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _767_$retval;
}

int main(void) {
  printf("%ld",_767_main());
  return 0;
}
