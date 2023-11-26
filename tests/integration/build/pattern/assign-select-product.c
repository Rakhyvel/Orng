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
int64_t _737_main(void);

/* Function definitions */
int64_t _737_main(void) {
    int64_t _737_t1;
    int64_t _737_t2;
    int64_t _737_t3;
    struct0 _738_x;
    int64_t _737_t5;
    int64_t _737_t6;
    int64_t _737_t7;
    struct0 _737_t4;
    int64_t _737_t8;
    int64_t _737_$retval;
    _737_t1 = 1;
    _737_t2 = 2;
    _737_t3 = 3;
    _738_x = (struct0) {_737_t1, _737_t2, _737_t3};
    _737_t5 = 60;
    _737_t6 = 23;
    _737_t7 = 200;
    _737_t4 = (struct0) {_737_t5, _737_t6, _737_t7};
    _738_x._1 = _737_t4._0;
    _738_x._2 = _737_t4._1;
    _738_x._0 = _737_t4._2;
    _737_t8 = $sub_int64_t(_738_x._0, _738_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _737_$retval = $add_int64_t(_737_t8, _738_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _737_$retval;
}

int main(void) {
  printf("%ld",_737_main());
  return 0;
}
