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
int64_t _16_main(void);

/* Function definitions */
int64_t _16_main(void) {
    int64_t _16_t1;
    int64_t _16_t2;
    struct0 _16_t0;
    int64_t _17_x;
    int64_t _17_y;
    int64_t _16_t4;
    int64_t _16_t6;
    struct1 _16_t3;
    int64_t _16_$retval;
    _16_t1 = 0;
    _16_t2 = 0;
    _16_t0 = (struct0) {_16_t1, _16_t2};
    _17_x = _16_t0._0;
    _17_y = _16_t0._1;
    _16_t4 = 5;
    _16_t6 = 33;
    _16_t3 = (struct1) {_16_t4, _16_t6};
    _17_x = _16_t3._0;
    _17_y = _16_t3._2;
    _16_$retval = $mult_int64_t(_17_x, _17_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _16_$retval;
}

int main(void) {
  printf("%ld",_16_main());
  return 0;
}
