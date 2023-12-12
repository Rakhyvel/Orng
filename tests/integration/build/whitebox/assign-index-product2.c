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
} struct0;

/* Function forward definitions */
int64_t _1200_main(void);

/* Function definitions */
int64_t _1200_main(void) {
    int64_t _1200_t1;
    int64_t _1200_t2;
    struct0 _1201_x;
    int64_t _1200_t4;
    int64_t _1200_t5;
    struct0 _1200_t3;
    int64_t _1200_t7;
    int64_t _1200_t9;
    int64_t _1200_t10;
    int64_t _1200_t11;
    int64_t _1200_$retval;
    _1200_t1 = 2;
    _1200_t2 = 324;
    _1201_x = (struct0) {_1200_t1, _1200_t2};
    _1200_t4 = 1;
    _1200_t5 = 0;
    _1200_t3 = (struct0) {(*((int64_t*)&_1201_x + _1200_t4)), (*((int64_t*)&_1201_x + _1200_t5))};
    _1200_t7 = 0;
    *((int64_t*)&_1201_x + _1200_t7) = _1200_t3._0;
    _1200_t9 = 1;
    *((int64_t*)&_1201_x + _1200_t9) = _1200_t3._1;
    _1200_t10 = 0;
    _1200_t11 = 1;
    _1200_$retval = $div_int64_t(*((int64_t*)&_1201_x + _1200_t10), *((int64_t*)&_1201_x + _1200_t11), "tests/integration/whitebox/assign-index-product2.orng:5:11:\n    x[0] / x[1]\n         ^");
    return _1200_$retval;
}

int main(void) {
  printf("%ld",_1200_main());
  return 0;
}
