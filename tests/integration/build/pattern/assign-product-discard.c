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
int64_t _731_main(void);

/* Function definitions */
int64_t _731_main(void) {
    int64_t _731_t1;
    int64_t _731_t2;
    struct0 _731_t0;
    int64_t _732_x;
    int64_t _732_y;
    int64_t _731_t4;
    int64_t _731_t6;
    struct1 _731_t3;
    int64_t _731_$retval;
    _731_t1 = 0;
    _731_t2 = 0;
    _731_t0 = (struct0) {_731_t1, _731_t2};
    _732_x = _731_t0._0;
    _732_y = _731_t0._1;
    _731_t4 = 5;
    _731_t6 = 33;
    _731_t3 = (struct1) {_731_t4, _731_t6};
    _732_x = _731_t3._0;
    _732_y = _731_t3._2;
    _731_$retval = $mult_int64_t(_732_x, _732_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _731_$retval;
}

int main(void) {
  printf("%ld",_731_main());
  return 0;
}
