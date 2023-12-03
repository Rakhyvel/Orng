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
int64_t _818_main(void);

/* Function definitions */
int64_t _818_main(void) {
    int64_t _818_t1;
    int64_t _818_t2;
    struct0 _818_t0;
    int64_t _819_x;
    int64_t _819_y;
    int64_t _818_t3;
    int64_t _818_$retval;
    _818_t1 = 3;
    _818_t2 = 40;
    _818_t0 = (struct0) {_818_t1, _818_t2};
    _819_x = _818_t0._0;
    _819_y = _818_t0._1;
    _818_t3 = 100;
    _819_y = $add_int64_t(_819_y, _818_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _818_$retval = $add_int64_t(_819_x, _819_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _818_$retval;
}

int main(void) {
  printf("%ld",_818_main());
  return 0;
}
