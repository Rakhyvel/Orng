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
int64_t _770_main(void);

/* Function definitions */
int64_t _770_main(void) {
    int64_t _770_t1;
    int64_t _770_t2;
    struct0 _770_t0;
    int64_t _771_x;
    int64_t _771_y;
    int64_t _770_t3;
    int64_t _770_t4;
    int64_t _770_$retval;
    _770_t1 = 5;
    _770_t2 = 30;
    _770_t0 = (struct0) {_770_t1, _770_t2};
    _771_x = _770_t0._0;
    _771_y = _770_t0._1;
    _770_t3 = $mult_int64_t(_771_x, _771_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _770_t4 = 1;
    _770_$retval = $add_int64_t(_770_t3, _770_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _770_$retval;
}

int main(void) {
  printf("%ld",_770_main());
  return 0;
}
