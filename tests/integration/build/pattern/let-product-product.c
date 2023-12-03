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
int64_t _833_main(void);

/* Function definitions */
int64_t _833_main(void) {
    int64_t _833_t2;
    int64_t _833_t3;
    struct0 _833_t1;
    int64_t _833_t5;
    int64_t _833_t6;
    struct0 _833_t4;
    struct1 _833_t0;
    int64_t _834_x;
    int64_t _834_y;
    int64_t _834_a;
    int64_t _834_b;
    int64_t _833_t7;
    int64_t _833_t8;
    int64_t _833_$retval;
    _833_t2 = 100;
    _833_t3 = 20;
    _833_t1 = (struct0) {_833_t2, _833_t3};
    _833_t5 = 20;
    _833_t6 = 2;
    _833_t4 = (struct0) {_833_t5, _833_t6};
    _833_t0 = (struct1) {_833_t1, _833_t4};
    _834_x = _833_t0._0._0;
    _834_y = _833_t0._0._1;
    _834_a = _833_t0._1._0;
    _834_b = _833_t0._1._1;
    _833_t7 = $add_int64_t(_834_x, _834_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _833_t8 = $add_int64_t(_833_t7, _834_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _833_$retval = $add_int64_t(_833_t8, _834_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _833_$retval;
}

int main(void) {
  printf("%ld",_833_main());
  return 0;
}
