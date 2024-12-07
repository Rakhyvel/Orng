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
int64_t _1264_main(void);


/* Function definitions */
int64_t _1264_main(void){
    int64_t _1264_t2;
    int64_t _1264_t3;
    struct struct0 _1264_t1;
    int64_t _1264_t5;
    int64_t _1264_t6;
    struct struct0 _1264_t4;
    struct struct1 _1264_t0;
    int64_t _1265_x;
    int64_t _1265_y;
    int64_t _1265_a;
    int64_t _1265_b;
    int64_t _1264_t8;
    int64_t _1264_t9;
    int64_t _1264_$retval;
    _1264_t2 = 100;
    _1264_t3 = 20;
    _1264_t1 = (struct struct0) {_1264_t2, _1264_t3};
    _1264_t5 = 20;
    _1264_t6 = 2;
    _1264_t4 = (struct struct0) {_1264_t5, _1264_t6};
    _1264_t0 = (struct struct1) {_1264_t1, _1264_t4};
    _1265_x = _1264_t0._0._0;
    _1265_y = _1264_t0._0._1;
    _1265_a = _1264_t0._1._0;
    _1265_b = _1264_t0._1._1;
    _1264_t8 = $add_int64_t(_1265_x, _1265_y, "tests/integration/pattern/let-product-product.orng:4:8:\n    x + y + a + b\n      ^");
    _1264_t9 = $add_int64_t(_1264_t8, _1265_a, "tests/integration/pattern/let-product-product.orng:4:12:\n    x + y + a + b\n          ^");
    _1264_$retval = $add_int64_t(_1264_t9, _1265_b, "tests/integration/pattern/let-product-product.orng:4:16:\n    x + y + a + b\n              ^");
    return _1264_$retval;
}


int main(void) {
  printf("%ld",_1264_main());
  return 0;
}
