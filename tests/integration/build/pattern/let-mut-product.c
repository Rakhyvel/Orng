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
int64_t _1035_main(void);

/* Function definitions */
int64_t _1035_main(void) {
    int64_t _1035_t1;
    int64_t _1035_t2;
    struct0 _1035_t0;
    int64_t _1036_x;
    int64_t _1036_y;
    int64_t _1035_t3;
    int64_t _1035_$retval;
    _1035_t1 = 3;
    _1035_t2 = 40;
    _1035_t0 = (struct0) {_1035_t1, _1035_t2};
    _1036_x = _1035_t0._0;
    _1036_y = _1035_t0._1;
    _1035_t3 = 100;
    _1036_y = $add_int64_t(_1036_y, _1035_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1035_$retval = $add_int64_t(_1036_x, _1036_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1035_$retval;
}

int main(void) {
  printf("%ld",_1035_main());
  return 0;
}
