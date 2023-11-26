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
int64_t _49_main(void);

/* Function definitions */
int64_t _49_main(void) {
    int64_t _49_t1;
    int64_t _49_t2;
    struct0 _49_t0;
    int64_t _50_a;
    int64_t _50_b;
    int64_t _49_$retval;
    _49_t1 = 100;
    _49_t2 = 58;
    _49_t0 = (struct0) {_49_t1, _49_t2};
    _50_a = _49_t0._0;
    _50_b = _49_t0._1;
    _49_$retval = $add_int64_t(_50_a, _50_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _49_$retval;
}

int main(void) {
  printf("%ld",_49_main());
  return 0;
}
