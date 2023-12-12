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
int64_t _881_main(void);

/* Function definitions */
int64_t _881_main(void) {
    int64_t _881_t1;
    int64_t _881_t2;
    struct0 _881_t0;
    int64_t _882_a;
    int64_t _882_b;
    int64_t _881_$retval;
    _881_t1 = 100;
    _881_t2 = 58;
    _881_t0 = (struct0) {_881_t1, _881_t2};
    _882_a = _881_t0._0;
    _882_b = _881_t0._1;
    _881_$retval = $add_int64_t(_882_a, _882_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _881_$retval;
}

int main(void) {
  printf("%ld",_881_main());
  return 0;
}
