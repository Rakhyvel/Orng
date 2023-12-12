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
int64_t _835_main(void);

/* Function definitions */
int64_t _835_main(void) {
    int64_t _835_t1;
    int64_t _835_t2;
    int64_t _835_t3;
    struct0 _836_x;
    int64_t _835_t5;
    int64_t _835_t6;
    int64_t _835_t7;
    struct0 _835_t4;
    int64_t _835_t8;
    int64_t _835_$retval;
    _835_t1 = 1;
    _835_t2 = 2;
    _835_t3 = 3;
    _836_x = (struct0) {_835_t1, _835_t2, _835_t3};
    _835_t5 = 60;
    _835_t6 = 23;
    _835_t7 = 200;
    _835_t4 = (struct0) {_835_t5, _835_t6, _835_t7};
    _836_x._1 = _835_t4._0;
    _836_x._2 = _835_t4._1;
    _836_x._0 = _835_t4._2;
    _835_t8 = $sub_int64_t(_836_x._0, _836_x._1, "tests/integration/pattern/assign-select-product.orng:5:10:\n    x.a - x.b + x.c\n        ^");
    _835_$retval = $add_int64_t(_835_t8, _836_x._2, "tests/integration/pattern/assign-select-product.orng:5:16:\n    x.a - x.b + x.c\n              ^");
    return _835_$retval;
}

int main(void) {
  printf("%ld",_835_main());
  return 0;
}
