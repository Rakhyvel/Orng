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
int64_t _829_main(void);

/* Function definitions */
int64_t _829_main(void) {
    int64_t _829_t1;
    int64_t _829_t2;
    struct0 _829_t0;
    int64_t _830_x;
    int64_t _830_y;
    int64_t _829_t4;
    int64_t _829_t6;
    struct1 _829_t3;
    int64_t _829_$retval;
    _829_t1 = 0;
    _829_t2 = 0;
    _829_t0 = (struct0) {_829_t1, _829_t2};
    _830_x = _829_t0._0;
    _830_y = _829_t0._1;
    _829_t4 = 5;
    _829_t6 = 33;
    _829_t3 = (struct1) {_829_t4, _829_t6};
    _830_x = _829_t3._0;
    _830_y = _829_t3._2;
    _829_$retval = $mult_int64_t(_830_x, _830_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _829_$retval;
}

int main(void) {
  printf("%ld",_829_main());
  return 0;
}
