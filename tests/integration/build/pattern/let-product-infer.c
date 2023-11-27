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
int64_t _795_main(void);

/* Function definitions */
int64_t _795_main(void) {
    int64_t _795_t1;
    int64_t _795_t2;
    struct0 _795_t0;
    int64_t _796_a;
    int64_t _796_b;
    int64_t _795_$retval;
    _795_t1 = 100;
    _795_t2 = 58;
    _795_t0 = (struct0) {_795_t1, _795_t2};
    _796_a = _795_t0._0;
    _796_b = _795_t0._1;
    _795_$retval = $add_int64_t(_796_a, _796_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _795_$retval;
}

int main(void) {
  printf("%ld",_795_main());
  return 0;
}
