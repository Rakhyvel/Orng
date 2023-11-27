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
int64_t _768_main(void);

/* Function definitions */
int64_t _768_main(void) {
    int64_t _768_t1;
    int64_t _768_t2;
    int64_t _768_t3;
    struct0 _769_x;
    int64_t _768_t5;
    int64_t _768_t6;
    int64_t _768_t7;
    struct0 _768_t4;
    int64_t _768_t8;
    int64_t _768_$retval;
    _768_t1 = 1;
    _768_t2 = 2;
    _768_t3 = 3;
    _769_x = (struct0) {_768_t1, _768_t2, _768_t3};
    _768_t5 = 60;
    _768_t6 = 23;
    _768_t7 = 200;
    _768_t4 = (struct0) {_768_t5, _768_t6, _768_t7};
    _769_x._1 = _768_t4._0;
    _769_x._2 = _768_t4._1;
    _769_x._0 = _768_t4._2;
    _768_t8 = $sub_int64_t(_769_x._0, _769_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _768_$retval = $add_int64_t(_768_t8, _769_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _768_$retval;
}

int main(void) {
  printf("%ld",_768_main());
  return 0;
}
