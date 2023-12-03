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
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _812_main(void);

/* Function definitions */
int64_t _812_main(void) {
    int64_t _812_t1;
    int64_t _812_t2;
    int64_t _812_t3;
    struct0 _812_t0;
    int64_t _813_a;
    int64_t _813_c;
    int64_t _812_$retval;
    _812_t1 = 100;
    _812_t2 = 300;
    _812_t3 = 56;
    _812_t0 = (struct0) {_812_t1, _812_t2, _812_t3};
    _813_a = _812_t0._0;
    _813_c = _812_t0._2;
    _812_$retval = $add_int64_t(_813_a, _813_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _812_$retval;
}

int main(void) {
  printf("%ld",_812_main());
  return 0;
}
