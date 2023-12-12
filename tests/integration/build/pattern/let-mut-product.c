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
int64_t _850_main(void);

/* Function definitions */
int64_t _850_main(void) {
    int64_t _850_t1;
    int64_t _850_t2;
    struct0 _850_t0;
    int64_t _851_x;
    int64_t _851_y;
    int64_t _850_t3;
    int64_t _850_$retval;
    _850_t1 = 3;
    _850_t2 = 40;
    _850_t0 = (struct0) {_850_t1, _850_t2};
    _851_x = _850_t0._0;
    _851_y = _850_t0._1;
    _850_t3 = 100;
    _851_y = $add_int64_t(_851_y, _850_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _850_$retval = $add_int64_t(_851_x, _851_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _850_$retval;
}

int main(void) {
  printf("%ld",_850_main());
  return 0;
}
