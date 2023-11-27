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
int64_t _801_main(void);

/* Function definitions */
int64_t _801_main(void) {
    int64_t _801_t1;
    int64_t _801_t2;
    struct0 _801_t0;
    int64_t _802_x;
    int64_t _802_y;
    int64_t _801_t3;
    int64_t _801_t4;
    int64_t _801_$retval;
    _801_t1 = 5;
    _801_t2 = 30;
    _801_t0 = (struct0) {_801_t1, _801_t2};
    _802_x = _801_t0._0;
    _802_y = _801_t0._1;
    _801_t3 = $mult_int64_t(_802_x, _802_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _801_t4 = 1;
    _801_$retval = $add_int64_t(_801_t3, _801_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _801_$retval;
}

int main(void) {
  printf("%ld",_801_main());
  return 0;
}
