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
int64_t _1072_main(void);

/* Function definitions */
int64_t _1072_main(void) {
    int64_t _1072_t1;
    int64_t _1072_t2;
    struct0 _1072_t0;
    int64_t _1073_a;
    int64_t _1073_b;
    int64_t _1072_$retval;
    _1072_t1 = 100;
    _1072_t2 = 58;
    _1072_t0 = (struct0) {_1072_t1, _1072_t2};
    _1073_a = _1072_t0._0;
    _1073_b = _1072_t0._1;
    _1072_$retval = $add_int64_t(_1073_a, _1073_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1072_$retval;
}

int main(void) {
  printf("%ld",_1072_main());
  return 0;
}
