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
int64_t _1231_main(void);


/* Function definitions */
int64_t _1231_main(void){
    int64_t _1231_t2;
    int64_t _1231_t3;
    struct struct0 _1231_t1;
    int64_t _1231_t5;
    int64_t _1231_t6;
    struct struct0 _1231_t4;
    struct struct1 _1231_t0;
    int64_t _1232_x;
    int64_t _1232_y;
    int64_t _1232_a;
    int64_t _1232_b;
    int64_t _1231_t8;
    int64_t _1231_t9;
    int64_t _1231_$retval;
    _1231_t2 = 100;
    _1231_t3 = 20;
    _1231_t1 = (struct struct0) {_1231_t2, _1231_t3};
    _1231_t5 = 20;
    _1231_t6 = 2;
    _1231_t4 = (struct struct0) {_1231_t5, _1231_t6};
    _1231_t0 = (struct struct1) {_1231_t1, _1231_t4};
    _1232_x = _1231_t0._0._0;
    _1232_y = _1231_t0._0._1;
    _1232_a = _1231_t0._1._0;
    _1232_b = _1231_t0._1._1;
    _1231_t8 = $add_int64_t(_1232_x, _1232_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1231_t9 = $add_int64_t(_1231_t8, _1232_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1231_$retval = $add_int64_t(_1231_t9, _1232_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1231_$retval;
}


int main(void) {
  printf("%ld",_1231_main());
  return 0;
}
