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
int64_t _764_main(void);

/* Function definitions */
int64_t _764_main(void) {
    int64_t _764_t1;
    int64_t _764_t2;
    struct0 _764_t0;
    int64_t _765_a;
    int64_t _765_b;
    int64_t _764_$retval;
    _764_t1 = 100;
    _764_t2 = 58;
    _764_t0 = (struct0) {_764_t1, _764_t2};
    _765_a = _764_t0._0;
    _765_b = _764_t0._1;
    _764_$retval = $add_int64_t(_765_a, _765_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _764_$retval;
}

int main(void) {
  printf("%ld",_764_main());
  return 0;
}
