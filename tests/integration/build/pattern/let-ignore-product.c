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
int64_t _31_main(void);

/* Function definitions */
int64_t _31_main(void) {
    int64_t _31_t1;
    int64_t _31_t2;
    int64_t _31_t3;
    struct0 _31_t0;
    int64_t _32_a;
    int64_t _32_c;
    int64_t _31_$retval;
    _31_t1 = 100;
    _31_t2 = 300;
    _31_t3 = 56;
    _31_t0 = (struct0) {_31_t1, _31_t2, _31_t3};
    _32_a = _31_t0._0;
    _32_c = _31_t0._2;
    _31_$retval = $add_int64_t(_32_a, _32_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _31_$retval;
}

int main(void) {
  printf("%ld",_31_main());
  return 0;
}
