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
int64_t _1256_main(void);


/* Function definitions */
int64_t _1256_main(void){
    int64_t _1256_t2;
    int64_t _1256_t3;
    struct struct0 _1256_t1;
    int64_t _1256_t5;
    int64_t _1256_t6;
    struct struct0 _1256_t4;
    struct struct1 _1256_t0;
    int64_t _1257_x;
    int64_t _1257_y;
    int64_t _1257_a;
    int64_t _1257_b;
    int64_t _1256_t8;
    int64_t _1256_t9;
    int64_t _1256_$retval;
    _1256_t2 = 100;
    _1256_t3 = 20;
    _1256_t1 = (struct struct0) {_1256_t2, _1256_t3};
    _1256_t5 = 20;
    _1256_t6 = 2;
    _1256_t4 = (struct struct0) {_1256_t5, _1256_t6};
    _1256_t0 = (struct struct1) {_1256_t1, _1256_t4};
    _1257_x = _1256_t0._0._0;
    _1257_y = _1256_t0._0._1;
    _1257_a = _1256_t0._1._0;
    _1257_b = _1256_t0._1._1;
    _1256_t8 = $add_int64_t(_1257_x, _1257_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1256_t9 = $add_int64_t(_1256_t8, _1257_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1256_$retval = $add_int64_t(_1256_t9, _1257_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1256_$retval;
}


int main(void) {
  printf("%ld",_1256_main());
  return 0;
}
