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
int64_t _1059_main(void);

/* Function definitions */
int64_t _1059_main(void) {
    int64_t _1059_t1;
    int64_t _1059_t2;
    int64_t _1059_t3;
    struct0 _1060_x;
    int64_t _1059_t5;
    int64_t _1059_t6;
    int64_t _1059_t7;
    struct0 _1059_t4;
    int64_t _1059_t8;
    int64_t _1059_$retval;
    _1059_t1 = 1;
    _1059_t2 = 2;
    _1059_t3 = 3;
    _1060_x = (struct0) {_1059_t1, _1059_t2, _1059_t3};
    _1059_t5 = 60;
    _1059_t6 = 23;
    _1059_t7 = 200;
    _1059_t4 = (struct0) {_1059_t5, _1059_t6, _1059_t7};
    _1060_x._1 = _1059_t4._0;
    _1060_x._2 = _1059_t4._1;
    _1060_x._0 = _1059_t4._2;
    _1059_t8 = $sub_int64_t(_1060_x._0, _1060_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _1059_$retval = $add_int64_t(_1059_t8, _1060_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _1059_$retval;
}

int main(void) {
  printf("%ld",_1059_main());
  return 0;
}
