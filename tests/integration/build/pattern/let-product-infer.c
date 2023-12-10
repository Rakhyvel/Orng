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
int64_t _854_main(void);

/* Function definitions */
int64_t _854_main(void) {
    int64_t _854_t1;
    int64_t _854_t2;
    struct0 _854_t0;
    int64_t _855_a;
    int64_t _855_b;
    int64_t _854_$retval;
    _854_t1 = 100;
    _854_t2 = 58;
    _854_t0 = (struct0) {_854_t1, _854_t2};
    _855_a = _854_t0._0;
    _855_b = _854_t0._1;
    _854_$retval = $add_int64_t(_855_a, _855_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _854_$retval;
}

int main(void) {
  printf("%ld",_854_main());
  return 0;
}
