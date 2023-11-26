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
int64_t _37_main(void);

/* Function definitions */
int64_t _37_main(void) {
    int64_t _37_t1;
    int64_t _37_t2;
    struct0 _37_t0;
    int64_t _38_x;
    int64_t _38_y;
    int64_t _37_t3;
    int64_t _37_$retval;
    _37_t1 = 3;
    _37_t2 = 40;
    _37_t0 = (struct0) {_37_t1, _37_t2};
    _38_x = _37_t0._0;
    _38_y = _37_t0._1;
    _37_t3 = 100;
    _38_y = $add_int64_t(_38_y, _37_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _37_$retval = $add_int64_t(_38_x, _38_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _37_$retval;
}

int main(void) {
  printf("%ld",_37_main());
  return 0;
}
