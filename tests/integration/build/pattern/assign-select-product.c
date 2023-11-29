/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _849_main(void);

/* Function definitions */
int64_t _849_main(void) {
    int64_t _849_t1;
    int64_t _849_t2;
    int64_t _849_t3;
    struct0 _850_x;
    int64_t _849_t5;
    int64_t _849_t6;
    int64_t _849_t7;
    struct0 _849_t4;
    int64_t _849_t8;
    int64_t _849_$retval;
    _849_t1 = 1;
    _849_t2 = 2;
    _849_t3 = 3;
    _850_x = (struct0) {_849_t1, _849_t2, _849_t3};
    _849_t5 = 60;
    _849_t6 = 23;
    _849_t7 = 200;
    _849_t4 = (struct0) {_849_t5, _849_t6, _849_t7};
    _850_x._1 = _849_t4._0;
    _850_x._2 = _849_t4._1;
    _850_x._0 = _849_t4._2;
    _849_t8 = $sub_int64_t(_850_x._0, _850_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _849_$retval = $add_int64_t(_849_t8, _850_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _849_$retval;
}

int main(void) {
  printf("%ld",_849_main());
  return 0;
}
