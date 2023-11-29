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
int64_t _1056_main(void);

/* Function definitions */
int64_t _1056_main(void) {
    int64_t _1056_t1;
    int64_t _1056_t2;
    struct0 _1056_t0;
    int64_t _1057_x;
    int64_t _1057_y;
    int64_t _1056_t3;
    int64_t _1056_$retval;
    _1056_t1 = 3;
    _1056_t2 = 40;
    _1056_t0 = (struct0) {_1056_t1, _1056_t2};
    _1057_x = _1056_t0._0;
    _1057_y = _1056_t0._1;
    _1056_t3 = 100;
    _1057_y = $add_int64_t(_1057_y, _1056_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1056_$retval = $add_int64_t(_1057_x, _1057_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1056_$retval;
}

int main(void) {
  printf("%ld",_1056_main());
  return 0;
}
