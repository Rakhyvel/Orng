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
int64_t _1162_main(void);


/* Function definitions */
int64_t _1162_main(void){
    int64_t _1162_t1;
    int64_t _1162_t2;
    int64_t _1162_t3;
    struct struct0 _1163_x;
    int64_t _1162_t6;
    int64_t _1162_t7;
    int64_t _1162_t8;
    struct struct0 _1162_t5;
    int64_t _1162_t9;
    int64_t _1162_$retval;
    _1162_t1 = 1;
    _1162_t2 = 2;
    _1162_t3 = 3;
    _1163_x = (struct struct0) {_1162_t1, _1162_t2, _1162_t3};
    _1162_t6 = 60;
    _1162_t7 = 23;
    _1162_t8 = 200;
    _1162_t5 = (struct struct0) {_1162_t6, _1162_t7, _1162_t8};
    _1163_x._1 = _1162_t5._0;
    _1163_x._2 = _1162_t5._1;
    _1163_x._0 = _1162_t5._2;
    _1162_t9 = $sub_int64_t(_1163_x._0, _1163_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _1162_$retval = $add_int64_t(_1162_t9, _1163_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _1162_$retval;
}


int main(void) {
  printf("%ld",_1162_main());
  return 0;
}
