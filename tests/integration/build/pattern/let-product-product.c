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
int64_t _1187_main(void);


/* Function definitions */
int64_t _1187_main(void){
    int64_t _1187_t2;
    int64_t _1187_t3;
    struct struct0 _1187_t1;
    int64_t _1187_t5;
    int64_t _1187_t6;
    struct struct0 _1187_t4;
    struct struct1 _1187_t0;
    int64_t _1188_x;
    int64_t _1188_y;
    int64_t _1188_a;
    int64_t _1188_b;
    int64_t _1187_t8;
    int64_t _1187_t9;
    int64_t _1187_$retval;
    _1187_t2 = 100;
    _1187_t3 = 20;
    _1187_t1 = (struct struct0) {_1187_t2, _1187_t3};
    _1187_t5 = 20;
    _1187_t6 = 2;
    _1187_t4 = (struct struct0) {_1187_t5, _1187_t6};
    _1187_t0 = (struct struct1) {_1187_t1, _1187_t4};
    _1188_x = _1187_t0._0._0;
    _1188_y = _1187_t0._0._1;
    _1188_a = _1187_t0._1._0;
    _1188_b = _1187_t0._1._1;
    _1187_t8 = $add_int64_t(_1188_x, _1188_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1187_t9 = $add_int64_t(_1187_t8, _1188_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1187_$retval = $add_int64_t(_1187_t9, _1188_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1187_$retval;
}


int main(void) {
  printf("%ld",_1187_main());
  return 0;
}
