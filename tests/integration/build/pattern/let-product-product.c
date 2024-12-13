/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1286_main(void);


/* Function definitions */
int64_t _1286_main(void){
    int64_t _1286_t2;
    int64_t _1286_t3;
    struct struct0 _1286_t1;
    int64_t _1286_t5;
    int64_t _1286_t6;
    struct struct0 _1286_t4;
    struct struct1 _1286_t0;
    int64_t _1287_x;
    int64_t _1287_y;
    int64_t _1287_a;
    int64_t _1287_b;
    int64_t _1286_t8;
    int64_t _1286_t9;
    int64_t _1286_$retval;
    _1286_t2 = 100;
    _1286_t3 = 20;
    _1286_t1 = (struct struct0) {_1286_t2, _1286_t3};
    _1286_t5 = 20;
    _1286_t6 = 2;
    _1286_t4 = (struct struct0) {_1286_t5, _1286_t6};
    _1286_t0 = (struct struct1) {_1286_t1, _1286_t4};
    _1287_x = _1286_t0._0._0;
    _1287_y = _1286_t0._0._1;
    _1287_a = _1286_t0._1._0;
    _1287_b = _1286_t0._1._1;
    _1286_t8 = $add_int64_t(_1287_x, _1287_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1286_t9 = $add_int64_t(_1286_t8, _1287_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1286_$retval = $add_int64_t(_1286_t9, _1287_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1286_$retval;
}


int main(void) {
  printf("%ld",_1286_main());
  return 0;
}
