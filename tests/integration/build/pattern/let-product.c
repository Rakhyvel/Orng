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
int64_t _860_main(void);

/* Function definitions */
int64_t _860_main(void) {
    int64_t _860_t1;
    int64_t _860_t2;
    struct0 _860_t0;
    int64_t _861_x;
    int64_t _861_y;
    int64_t _860_t3;
    int64_t _860_t4;
    int64_t _860_$retval;
    _860_t1 = 5;
    _860_t2 = 30;
    _860_t0 = (struct0) {_860_t1, _860_t2};
    _861_x = _860_t0._0;
    _861_y = _860_t0._1;
    _860_t3 = $mult_int64_t(_861_x, _861_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _860_t4 = 1;
    _860_$retval = $add_int64_t(_860_t3, _860_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _860_$retval;
}

int main(void) {
  printf("%ld",_860_main());
  return 0;
}
