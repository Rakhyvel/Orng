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

typedef struct {
    int64_t _0;
    int64_t _2;
} struct1;

/* Function forward definitions */
int64_t _762_main(void);

/* Function definitions */
int64_t _762_main(void) {
    int64_t _762_t1;
    int64_t _762_t2;
    struct0 _762_t0;
    int64_t _763_x;
    int64_t _763_y;
    int64_t _762_t4;
    int64_t _762_t6;
    struct1 _762_t3;
    int64_t _762_$retval;
    _762_t1 = 0;
    _762_t2 = 0;
    _762_t0 = (struct0) {_762_t1, _762_t2};
    _763_x = _762_t0._0;
    _763_y = _762_t0._1;
    _762_t4 = 5;
    _762_t6 = 33;
    _762_t3 = (struct1) {_762_t4, _762_t6};
    _763_x = _762_t3._0;
    _763_y = _762_t3._2;
    _762_$retval = $mult_int64_t(_763_x, _763_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _762_$retval;
}

int main(void) {
  printf("%ld",_762_main());
  return 0;
}
