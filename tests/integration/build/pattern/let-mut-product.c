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
int64_t _842_main(void);

/* Function definitions */
int64_t _842_main(void) {
    int64_t _842_t1;
    int64_t _842_t2;
    struct0 _842_t0;
    int64_t _843_x;
    int64_t _843_y;
    int64_t _842_t3;
    int64_t _842_$retval;
    _842_t1 = 3;
    _842_t2 = 40;
    _842_t0 = (struct0) {_842_t1, _842_t2};
    _843_x = _842_t0._0;
    _843_y = _842_t0._1;
    _842_t3 = 100;
    _843_y = $add_int64_t(_843_y, _842_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _842_$retval = $add_int64_t(_843_x, _843_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _842_$retval;
}

int main(void) {
  printf("%ld",_842_main());
  return 0;
}
