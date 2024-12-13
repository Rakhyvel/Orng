/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1256_main(void);


/* Function definitions */
int64_t _1256_main(void){
    int64_t _1256_t1;
    int64_t _1256_t2;
    int64_t _1256_t3;
    struct struct0 _1257_x;
    int64_t _1256_t6;
    int64_t _1256_t7;
    int64_t _1256_t8;
    struct struct0 _1256_t5;
    int64_t _1256_t9;
    int64_t _1256_$retval;
    _1256_t1 = 1;
    _1256_t2 = 2;
    _1256_t3 = 3;
    _1257_x = (struct struct0) {_1256_t1, _1256_t2, _1256_t3};
    _1256_t6 = 60;
    _1256_t7 = 23;
    _1256_t8 = 200;
    _1256_t5 = (struct struct0) {_1256_t6, _1256_t7, _1256_t8};
    _1257_x._1 = _1256_t5._0;
    _1257_x._2 = _1256_t5._1;
    _1257_x._0 = _1256_t5._2;
    _1256_t9 = $sub_int64_t(_1257_x._0, _1257_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _1256_$retval = $add_int64_t(_1256_t9, _1257_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _1256_$retval;
}


int main(void) {
  printf("%ld",_1256_main());
  return 0;
}
