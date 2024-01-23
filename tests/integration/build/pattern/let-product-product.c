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
int64_t _1182_main(void);


/* Function definitions */
int64_t _1182_main(void){
    int64_t _1182_t2;
    int64_t _1182_t3;
    struct struct0 _1182_t1;
    int64_t _1182_t5;
    int64_t _1182_t6;
    struct struct0 _1182_t4;
    struct struct1 _1182_t0;
    int64_t _1183_x;
    int64_t _1183_y;
    int64_t _1183_a;
    int64_t _1183_b;
    int64_t _1182_t7;
    int64_t _1182_t8;
    int64_t _1182_$retval;
    _1182_t2 = 100;
    _1182_t3 = 20;
    _1182_t1 = (struct struct0) {_1182_t2, _1182_t3};
    _1182_t5 = 20;
    _1182_t6 = 2;
    _1182_t4 = (struct struct0) {_1182_t5, _1182_t6};
    _1182_t0 = (struct struct1) {_1182_t1, _1182_t4};
    _1183_x = _1182_t0._0._0;
    _1183_y = _1182_t0._0._1;
    _1183_a = _1182_t0._1._0;
    _1183_b = _1182_t0._1._1;
    _1182_t7 = $add_int64_t(_1183_x, _1183_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1182_t8 = $add_int64_t(_1182_t7, _1183_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1182_$retval = $add_int64_t(_1182_t8, _1183_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1182_$retval;
}


int main(void) {
  printf("%ld",_1182_main());
  return 0;
}
