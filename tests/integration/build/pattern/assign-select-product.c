/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1137_main(void);

/* Function definitions */
int64_t _1137_main(void){
    int64_t _1137_t1;
    int64_t _1137_t2;
    int64_t _1137_t3;
    struct struct0 _1138_x;
    int64_t _1137_t5;
    int64_t _1137_t6;
    int64_t _1137_t7;
    struct struct0 _1137_t4;
    int64_t _1137_t8;
    int64_t _1137_$retval;
    _1137_t1 = 1;
    _1137_t2 = 2;
    _1137_t3 = 3;
    _1138_x = (struct struct0) {_1137_t1, _1137_t2, _1137_t3};
    _1137_t5 = 60;
    _1137_t6 = 23;
    _1137_t7 = 200;
    _1137_t4 = (struct struct0) {_1137_t5, _1137_t6, _1137_t7};
    _1138_x._1 = _1137_t4._0;
    _1138_x._2 = _1137_t4._1;
    _1138_x._0 = _1137_t4._2;
    _1137_t8 = $sub_int64_t(_1138_x._0, _1138_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _1137_$retval = $add_int64_t(_1137_t8, _1138_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _1137_$retval;
}

int main(void) {
  printf("%ld",_1137_main());
  return 0;
}
