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
int64_t _836_main(void);

/* Function definitions */
int64_t _836_main(void) {
    int64_t _836_t1;
    int64_t _836_t2;
    struct0 _836_t0;
    int64_t _837_x;
    int64_t _837_y;
    int64_t _836_t3;
    int64_t _836_t4;
    int64_t _836_$retval;
    _836_t1 = 5;
    _836_t2 = 30;
    _836_t0 = (struct0) {_836_t1, _836_t2};
    _837_x = _836_t0._0;
    _837_y = _836_t0._1;
    _836_t3 = $mult_int64_t(_837_x, _837_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _836_t4 = 1;
    _836_$retval = $add_int64_t(_836_t3, _836_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _836_$retval;
}

int main(void) {
  printf("%ld",_836_main());
  return 0;
}
