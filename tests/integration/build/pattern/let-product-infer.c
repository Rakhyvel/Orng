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
int64_t _879_main(void);

/* Function definitions */
int64_t _879_main(void) {
    int64_t _879_t1;
    int64_t _879_t2;
    struct0 _879_t0;
    int64_t _880_a;
    int64_t _880_b;
    int64_t _879_$retval;
    _879_t1 = 100;
    _879_t2 = 58;
    _879_t0 = (struct0) {_879_t1, _879_t2};
    _880_a = _879_t0._0;
    _880_b = _879_t0._1;
    _879_$retval = $add_int64_t(_880_a, _880_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _879_$retval;
}

int main(void) {
  printf("%ld",_879_main());
  return 0;
}
