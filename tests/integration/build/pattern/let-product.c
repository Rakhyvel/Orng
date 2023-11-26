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
int64_t _55_main(void);

/* Function definitions */
int64_t _55_main(void) {
    int64_t _55_t1;
    int64_t _55_t2;
    struct0 _55_t0;
    int64_t _56_x;
    int64_t _56_y;
    int64_t _55_t3;
    int64_t _55_t4;
    int64_t _55_$retval;
    _55_t1 = 5;
    _55_t2 = 30;
    _55_t0 = (struct0) {_55_t1, _55_t2};
    _56_x = _55_t0._0;
    _56_y = _55_t0._1;
    _55_t3 = $mult_int64_t(_56_x, _56_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _55_t4 = 1;
    _55_$retval = $add_int64_t(_55_t3, _55_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _55_$retval;
}

int main(void) {
  printf("%ld",_55_main());
  return 0;
}
