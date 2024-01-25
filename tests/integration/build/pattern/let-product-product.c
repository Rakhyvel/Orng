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
int64_t _1209_main(void);


/* Function definitions */
int64_t _1209_main(void){
    int64_t _1209_t2;
    int64_t _1209_t3;
    struct struct0 _1209_t1;
    int64_t _1209_t5;
    int64_t _1209_t6;
    struct struct0 _1209_t4;
    struct struct1 _1209_t0;
    int64_t _1210_x;
    int64_t _1210_y;
    int64_t _1210_a;
    int64_t _1210_b;
    int64_t _1209_t7;
    int64_t _1209_t8;
    int64_t _1209_$retval;
    _1209_t2 = 100;
    _1209_t3 = 20;
    _1209_t1 = (struct struct0) {_1209_t2, _1209_t3};
    _1209_t5 = 20;
    _1209_t6 = 2;
    _1209_t4 = (struct struct0) {_1209_t5, _1209_t6};
    _1209_t0 = (struct struct1) {_1209_t1, _1209_t4};
    _1210_x = _1209_t0._0._0;
    _1210_y = _1209_t0._0._1;
    _1210_a = _1209_t0._1._0;
    _1210_b = _1209_t0._1._1;
    _1209_t7 = $add_int64_t(_1210_x, _1210_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1209_t8 = $add_int64_t(_1209_t7, _1210_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1209_$retval = $add_int64_t(_1209_t8, _1210_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1209_$retval;
}


int main(void) {
  printf("%ld",_1209_main());
  return 0;
}
