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
int64_t _865_main(void);

/* Function definitions */
int64_t _865_main(void) {
    int64_t _865_t2;
    int64_t _865_t3;
    struct0 _865_t1;
    int64_t _865_t5;
    int64_t _865_t6;
    struct0 _865_t4;
    struct1 _865_t0;
    int64_t _866_x;
    int64_t _866_y;
    int64_t _866_a;
    int64_t _866_b;
    int64_t _865_t7;
    int64_t _865_t8;
    int64_t _865_$retval;
    _865_t2 = 100;
    _865_t3 = 20;
    _865_t1 = (struct0) {_865_t2, _865_t3};
    _865_t5 = 20;
    _865_t6 = 2;
    _865_t4 = (struct0) {_865_t5, _865_t6};
    _865_t0 = (struct1) {_865_t1, _865_t4};
    _866_x = _865_t0._0._0;
    _866_y = _865_t0._0._1;
    _866_a = _865_t0._1._0;
    _866_b = _865_t0._1._1;
    _865_t7 = $add_int64_t(_866_x, _866_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _865_t8 = $add_int64_t(_865_t7, _866_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _865_$retval = $add_int64_t(_865_t8, _866_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _865_$retval;
}

int main(void) {
  printf("%ld",_865_main());
  return 0;
}
