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
int64_t _1117_main(void);

/* Function definitions */
int64_t _1117_main(void){
    int64_t _1117_t2;
    int64_t _1117_t3;
    struct0 _1117_t1;
    int64_t _1117_t5;
    int64_t _1117_t6;
    struct0 _1117_t4;
    struct1 _1117_t0;
    int64_t _1118_x;
    int64_t _1118_y;
    int64_t _1118_a;
    int64_t _1118_b;
    int64_t _1117_t7;
    int64_t _1117_t8;
    int64_t _1117_$retval;
    _1117_t2 = 100;
    _1117_t3 = 20;
    _1117_t1 = (struct0) {_1117_t2, _1117_t3};
    _1117_t5 = 20;
    _1117_t6 = 2;
    _1117_t4 = (struct0) {_1117_t5, _1117_t6};
    _1117_t0 = (struct1) {_1117_t1, _1117_t4};
    _1118_x = _1117_t0._0._0;
    _1118_y = _1117_t0._0._1;
    _1118_a = _1117_t0._1._0;
    _1118_b = _1117_t0._1._1;
    _1117_t7 = $add_int64_t(_1118_x, _1118_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1117_t8 = $add_int64_t(_1117_t7, _1118_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1117_$retval = $add_int64_t(_1117_t8, _1118_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1117_$retval;
}

int main(void) {
  printf("%ld",_1117_main());
  return 0;
}
