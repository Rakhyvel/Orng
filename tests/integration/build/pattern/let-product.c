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
int64_t _887_main(void);

/* Function definitions */
int64_t _887_main(void) {
    int64_t _887_t1;
    int64_t _887_t2;
    struct0 _887_t0;
    int64_t _888_x;
    int64_t _888_y;
    int64_t _887_t3;
    int64_t _887_t4;
    int64_t _887_$retval;
    _887_t1 = 5;
    _887_t2 = 30;
    _887_t0 = (struct0) {_887_t1, _887_t2};
    _888_x = _887_t0._0;
    _888_y = _887_t0._1;
    _887_t3 = $mult_int64_t(_888_x, _888_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _887_t4 = 1;
    _887_$retval = $add_int64_t(_887_t3, _887_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _887_$retval;
}

int main(void) {
  printf("%ld",_887_main());
  return 0;
}
