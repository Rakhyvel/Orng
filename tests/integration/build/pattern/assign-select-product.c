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
int64_t _827_main(void);

/* Function definitions */
int64_t _827_main(void) {
    int64_t _827_t1;
    int64_t _827_t2;
    int64_t _827_t3;
    struct0 _828_x;
    int64_t _827_t5;
    int64_t _827_t6;
    int64_t _827_t7;
    struct0 _827_t4;
    int64_t _827_t8;
    int64_t _827_$retval;
    _827_t1 = 1;
    _827_t2 = 2;
    _827_t3 = 3;
    _828_x = (struct0) {_827_t1, _827_t2, _827_t3};
    _827_t5 = 60;
    _827_t6 = 23;
    _827_t7 = 200;
    _827_t4 = (struct0) {_827_t5, _827_t6, _827_t7};
    _828_x._1 = _827_t4._0;
    _828_x._2 = _827_t4._1;
    _828_x._0 = _827_t4._2;
    _827_t8 = $sub_int64_t(_828_x._0, _828_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _827_$retval = $add_int64_t(_827_t8, _828_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _827_$retval;
}

int main(void) {
  printf("%ld",_827_main());
  return 0;
}
