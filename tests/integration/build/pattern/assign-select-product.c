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
int64_t _854_main(void);

/* Function definitions */
int64_t _854_main(void) {
    int64_t _854_t1;
    int64_t _854_t2;
    int64_t _854_t3;
    struct0 _855_x;
    int64_t _854_t5;
    int64_t _854_t6;
    int64_t _854_t7;
    struct0 _854_t4;
    int64_t _854_t8;
    int64_t _854_$retval;
    _854_t1 = 1;
    _854_t2 = 2;
    _854_t3 = 3;
    _855_x = (struct0) {_854_t1, _854_t2, _854_t3};
    _854_t5 = 60;
    _854_t6 = 23;
    _854_t7 = 200;
    _854_t4 = (struct0) {_854_t5, _854_t6, _854_t7};
    _855_x._1 = _854_t4._0;
    _855_x._2 = _854_t4._1;
    _855_x._0 = _854_t4._2;
    _854_t8 = $sub_int64_t(_855_x._0, _855_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _854_$retval = $add_int64_t(_854_t8, _855_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _854_$retval;
}

int main(void) {
  printf("%ld",_854_main());
  return 0;
}
